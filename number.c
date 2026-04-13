#include <stdio.h>

int main() {
    int num, temp, digit, sum = 0, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Even or Odd
    if (num % 2 == 0)
        printf("Even number\n");
    else
        printf("Odd number\n");

    // Positive, Negative or Zero
    if (num > 0)
        printf("Positive number\n");
    else if (num < 0)
        printf("Negative number\n");
    else
        printf("Zero\n");

    // Sum of digits and reverse
    temp = num;
    while (temp != 0) {
        digit = temp % 10;
        sum += digit;
        reverse = reverse * 10 + digit;
        temp = temp / 10;
    }

    printf("Sum of digits = %d\n", sum);

    // Palindrome check
    if (num == reverse)
        printf("Palindrome number\n");
    else
        printf("Not a palindrome\n");

    return 0;
}