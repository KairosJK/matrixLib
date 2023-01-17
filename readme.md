# matrixLib

a small c library for linear algebra and the related

## 🧠 Design

This library was made with the goal of using simple algorithms to aid in the solving of simple to intermediate linear algebra problems/calculations. They are not optimized, mostly being used for my linear algebra class homework + some c practice.

## How to install
As of now, I havent standardized or scripted the full installation process, but there are a few options for compilation:

`make staticlib`: makes a static `libmatrix.a` file

`make dynamiclib`: makes a dynamic `libmatrix.so` file

You probably would want to copy these to wherever your libraries are souced (ie. `/usr/lib`). Other script rules include:

`make testbin`: produces all test binaries sourced from `tests/`

`make clean`: remove all test binaries, object files, libraries, and valgrind cores

## ⚙️ Examples
```c
#include <stdio.h>
#include "matrixlib.h"

int main(void) {

    // init matrix objects from file
    matrix a = matrix_io_read_file(fopen("tests/data/test_3x3_1.csv", "r"));
    matrix b = matrix_io_read_file(fopen("tests/data/test_3x3_2.csv", "r"));

    // addition
    matrix a_plus_b = matrix_add(a, b);

    // transpose
    matrix transpose_a = matrix_transpose(a);

    // print to stdout row by row
    matrix_io_print(a_plus_b);

    // free objects
    matrix_free(&a_plus_b);
    matrix_free(&transpose_a);
    matrix_free(&a);
    matrix_free(&b);

    return EXIT_SUCCESS;
}
```
## 👤 Authored by 

Jonathan Kocevar

## 📝 License

This project is licensed under the terms of the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).
