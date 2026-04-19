#include <stdio.h>

int main() {
    int score = 0;
    int answer;

    printf("=== Simple Quiz Game ===\n");

    // Question 1
    printf("\n1. What is the capital of India?\n");
    printf("1) Mumbai\n2) Delhi\n3) Kolkata\n4) Chennai\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! Correct answer is Delhi.\n");
    }

    // Question 2
    printf("\n2. Which language is used for C programming?\n");
    printf("1) English\n2) Machine Language\n3) Programming Language\n4) Assembly\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! Correct answer is Programming Language.\n");
    }

    // Question 3
    printf("\n3. What is 5 + 3?\n");
    printf("1) 6\n2) 7\n3) 8\n4) 9\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! Correct answer is 8.\n");
    }

    // Final Score
    printf("\n=== Quiz Finished ===\n");
    printf("Your Score: %d / 3\n", score);

    return 0;
}