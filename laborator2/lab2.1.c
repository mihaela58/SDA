#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stiva[10001];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            stiva[++top] = ch;
        } else {
            if (top < 0)
                return false;

            char ultim = stiva[top--];

            if ((ch == ')' && ultim != '(') ||
                (ch == ']' && ultim != '[') ||
                (ch == '}' && ultim != '{')) {
                return false;
            }
        }
    }

    return top == -1;
}

int main() {
    char test1[] = "()[]{}";
    char test2[] = "(]";
    char test3[] = "{[()]}";

    printf("%s -> %s\n", test1, isValid(test1) ? "true" : "false");
    printf("%s -> %s\n", test2, isValid(test2) ? "true" : "false");
    printf("%s -> %s\n", test3, isValid(test3) ? "true" : "false");

    return 0;
}