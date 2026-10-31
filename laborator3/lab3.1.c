#include <stdio.h>

int numberOfSteps(int num) {
    int steps = 0;
    while (num > 0) {
        if (num % 2 == 0)
            num /= 2;
        else
            num -= 1;
        steps++;
    }
    return steps;
}

int main() {
    int num;
    printf("Introdu numarul: ");
    scanf("%d", &num);

    printf("Numar de pasi: %d\n", numberOfSteps(num));
    return 0;
}