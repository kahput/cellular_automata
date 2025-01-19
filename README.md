# Cellular Automata

A simple cellular automata implemented in C using Raylib for graphics. Based on a coding challenge by [The Coding Train](https://www.youtube.com/watch?v=Ggxt06qSAe4).

![Screenshot](images/screenshot.png)

## Prerequisites

*   **Raylib:** You need to have the Raylib library installed on your system.
*   **C Compiler:** GCC is required to compile the code.
*   **Make:**  The build process is managed using Makefiles.

## Build Instructions (Linux Only)

1. **Clone the repository (or download the source files):**

    ```bash
    git clone <your_repository_url>  # If you have a repository
    cd cellular_automata
    ```

2. **Build the project using Make:**

    ```bash
    make build
    ```

    This command will compile the source code and create the executable in the `bin` directory.

## Run Instructions

2. **Run the executable:**

    ```bash
    make run
    ```

    This command will execute the compiled program located in the `bin` directory.

## Platform Compatibility

This project has only been built and tested on **Linux** only. While the core C code is platform-independent, the build system relies on Makefiles.

    
