#include <stdio.h>
#include <string.h>

#define MAX 100
#define URL_LEN 100

typedef struct {
    char items[MAX][URL_LEN];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(const Stack *s) {
    return s->top == -1;
}

int isFull(const Stack *s) {
    return s->top == MAX - 1;
}

int push(Stack *s, const char page[]) {
    if (isFull(s)) {
        printf("Navigation history is full!\n");
        return 0;
    }

    s->top++;
    snprintf(s->items[s->top], URL_LEN, "%s", page);
    return 1;
}

int pop(Stack *s, char page[]) {
    if (isEmpty(s)) {
        return 0;
    }

    snprintf(page, URL_LEN, "%s", s->items[s->top]);
    s->top--;
    return 1;
}

void clearStack(Stack *s) {
    init(s);
}

int main(void) {
    Stack backStack, forwardStack;
    char currentPage[URL_LEN] = "home";
    char input[URL_LEN];
    int choice;

    init(&backStack);
    init(&forwardStack);

    while (1) {
        printf("\nCurrent Page: %s\n", currentPage);
        printf("1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter URL/page name (no spaces): ");
                if (scanf("%99s", input) != 1) {
                    printf("Could not read page name.\n");
                    return 1;
                }

                if (push(&backStack, currentPage)) {
                    snprintf(currentPage, URL_LEN, "%s", input);
                    clearStack(&forwardStack);
                }
                break;

            case 2:
                if (!isEmpty(&backStack)) {
                    if (push(&forwardStack, currentPage)) {
                        pop(&backStack, currentPage);
                    }
                } else {
                    printf("No pages in back history!\n");
                }
                break;

            case 3:
                if (!isEmpty(&forwardStack)) {
                    if (push(&backStack, currentPage)) {
                        pop(&forwardStack, currentPage);
                    }
                } else {
                    printf("No pages in forward history!\n");
                }
                break;

            case 4:
                printf("Exiting browser navigation simulation.\n");
                return 0;

            default:
                printf("Invalid choice! Please select 1 to 4.\n");
        }
    }
}
