/*Problem:
Convert a given decimal number into its binary equivalent using a stack.

Approach:
Divide the number repeatedly by 2 and push each remainder onto a stack.
Pop all elements from the stack to obtain the binary number in correct order.*/

#include <stdio.h>

int main() {
    int n, stack[32], top = -1;

    printf("Enter decimal number: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Binary: 0");
        return 0;
    }

    while (n > 0) {
        stack[++top] = n % 2;
        n /= 2;
    }

    printf("Binary: ");
    while (top >= 0)
        printf("%d", stack[top--]);

    return 0;
}