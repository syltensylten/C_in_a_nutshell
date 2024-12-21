#include <stdio.h>

void mygets(char s[], unsigned int max) {
  int i;
  fgets(s, max, stdin);
  for (i=0; s[i] != '\n' && s[i] != '\0' ; i++)
    ;
  if (s[i] == '\n') {
    s[i] = '\0';
  }
}

  
