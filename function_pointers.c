#include <stdlib.h>
#include <string.h>
#include <stdio.h>

float my_func (int x, int y) {
    float z = (float) x / y;
    return z;
}

void divide(int a, int b, float (*my_func_ptr) (int, int)) {
    float c = my_func_ptr(a,b);
    printf("Divided %d by %d to get %.4f\n", a, b, c);
}

int main() {

    // declare & initialize fuction pointer
    float (*my_func_ptr) (int, int);
    my_func_ptr = my_func;

    // call function using callback
    divide(2, 3, my_func_ptr);

    return(0);
}