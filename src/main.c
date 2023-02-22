#include <stdio.h>

int main() {
  int text;
  text = getchar();
  while (text != EOF) {
    if (text == '\n') {
      text = '\n';
    } else {
      putchar(text);
      text = getchar();
    }
  }
  return 0;
}