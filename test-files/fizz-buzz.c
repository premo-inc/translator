#include <stdio.h>

int main(void) {
  for (int i = 1; i < 100; ++i) {
    char c = '.';
    if (i % 15 == 0) {
      c = '!';
    } else if (i % 3 == 0) {
      c = 'f';
    } else if (i % 5 == 0) {
      c = 'z';
    }
    putchar(c);
  }
  putchar('\n');

  return 0;
}
