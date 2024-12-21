  /* I källkodsfilen f2.c */ 
  #include <stdio.h> 
  char rad[100] = ""; 
  int  nasta = 0; 

  int las_rad(void)  /* läser en rad, ger 0 vid EOF */ 
  { 
     int c, i; 
     if ((c = getchar()) == EOF) {
        return 0;
     }
     else { 
        i = 0; 
        while (c != '\n' && c != EOF) { 
           rad[i++] = c; 
           c = getchar(); 
        } 
        rad[i] = '\0'; 
        nasta = 0; 
        return 1; 
     } 
  } 

  void fel(char text[]) /* skriver ut felmeddelande */ 
  { 
     int i; 
     for (i = 0; i < nasta ; i++) { /* skriv blanka */ 
        putchar(' ');
     }
     printf("!\n%s\n", text);       /* markera felet */ 
  }
