#include <stdio.h>

int main() {
    char text;
    text = getchar();
    while (text != '\n') {
        putchar(text);
        text = getchar();
    }
    return 0;
}