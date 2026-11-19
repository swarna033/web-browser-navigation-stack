# Web Browser Navigation Stack

A beginner-friendly C project that simulates the **Back** and **Forward** navigation features of a web browser using the Stack data structure.

## Project overview

The program maintains two stacks:

- **Back Stack:** Stores previously visited pages.
- **Forward Stack:** Stores pages that can be revisited after moving backward.

The project follows the **Last-In, First-Out (LIFO)** principle.

## Features

- Visit a new page by entering a page name or URL.
- Move to the previous page using Back.
- Return to a page using Forward.
- Clear forward history when a new page is visited.
- Display a message when Back or Forward history is empty.
- Exit the navigation simulation.

## Data structures and operations

| Item | Purpose |
|---|---|
| Stack | Stores page navigation history |
| Push | Adds a page to a stack |
| Pop | Removes and returns the top page |
| Back Stack | Keeps previously visited pages |
| Forward Stack | Keeps pages available after Back |
| LIFO | Last In, First Out |

## Modules

1. User interaction and menu
2. Back stack management
3. Forward stack management
4. Stack operations (`push`, `pop`, `isEmpty`, `isFull`)
5. Current page management

## Requirements

- A C compiler such as GCC
- A terminal or command prompt

## How to compile and run

### Windows (GCC / MinGW)

Open a terminal in this project folder and run:

```bash
gcc browser_navigation.c -o browser_navigation
browser_navigation.exe
```

### Linux / macOS

```bash
gcc browser_navigation.c -o browser_navigation
./browser_navigation
```

## Example run

```text
Current Page: home
1. Visit New Page
2. Back
3. Forward
4. Exit
Enter choice: 1
Enter URL/page name (no spaces): youtube

Current Page: youtube
1. Visit New Page
2. Back
3. Forward
4. Exit
Enter choice: 2

Current Page: home
1. Visit New Page
2. Back
3. Forward
4. Exit
Enter choice: 3

Current Page: youtube
```

## How navigation works

- **Visit:** Push the current page into the Back Stack, set the entered page as current, and clear the Forward Stack.
- **Back:** Push the current page into the Forward Stack, then pop the Back Stack to get the previous page.
- **Forward:** Push the current page into the Back Stack, then pop the Forward Stack to get the next page.

## Limitations

This is a console-based simulation for learning stack operations. It does not connect to the internet or render actual web pages.

## Project reference

This implementation is based on the academic project *Web Browser Navigation Stack*, which demonstrates browser-style Back and Forward navigation using two stacks.
