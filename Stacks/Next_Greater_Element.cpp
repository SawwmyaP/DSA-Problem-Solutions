/*Problem:
For each element in an array, find the next greater element to its right.
If none exists, print -1.

Approach:
Traverse the array and use a stack to store indices of elements.
Whenever a greater element is found, pop from the stack and assign it as the next greater element.*/

#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n], nge[n], stack[n], top = -1;

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        while (top != -1 && a[i] > a[stack[top]]) {
            nge[stack[top--]] = a[i];
        }
        stack[++top] = i;
    }

    while (top != -1)
        nge[stack[top--]] = -1;

    printf("Next Greater Elements:\n");
    for (i = 0; i < n; i++)
        printf("%d -> %d\n", a[i], nge[i]);

    return 0;
}