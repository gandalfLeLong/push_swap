# push_swap

A highly efficient sorting project that challenges you to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

---

### 💡 Key Features
* **Two-Stack Sorting:** Manipulates two stacks (A and B) using specific operations: `sa`, `pb`, `ra`, `rra`, etc.
* **Algorithm Optimization:** Focuses on minimizing instruction counts for small sets (3-5 numbers) and large sets (100-500 numbers).
* **Memory Integrity:** Built with a custom Libft and rigorously tested for memory leaks using AddressSanitizer.
* **Input Validation:** Robust parsing to handle non-numeric input, duplicates, and integer overflows.

---

### 🛠️ Compilation & Usage

This project uses a **Makefile** that also manages the compilation of the internal **Libft** library.

| Rule | Description |
| :--- | :--- |
| `make` | Compiles the `push_swap` executable. |
| `make debug` | Compiles with `-fsanitize=address` and debug symbols for troubleshooting. |
| `make clean` | Removes object files for both the project and Libft. |
| `make fclean` | Removes all object files and the `push_swap` binary. |
| `make re` | Performs a clean re-compilation of everything. |
| `make gotham` | Hidden rules to display ASCII art in the terminal. |

**To run the program:**
Run the executable with a list of integers as arguments:
```bash
./push_swap 3 2 5 1 4
