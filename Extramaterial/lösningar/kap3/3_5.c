/* 3_5.c */

#include <stdio.h> 

int main()
{
  int ch;

  printf("Skriv in text. Avsluta med EOF:\n");
  while((ch = getchar()) != EOF) {
    if (ch == 0x86)
      ch = 0xE5;
    if (ch == 0x84)
      ch = 0xE4;
    if (ch == 0x94)
      ch = 0xF6;
    if (ch == 0x8F)
      ch = 0xC5;
    if (ch == 0x8E)
      ch = 0xC4;
    if (ch == 0x99)
      ch = 0xD6;
    putchar(ch);
  }
}
