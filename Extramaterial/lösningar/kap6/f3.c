  /* I källkodsfilen f3.c */ 
  extern char rad[]; 
  extern int  nasta; 
  extern void fel(char text[]);
  int bokstav(void) 
  { 
     if ('a' <= rad[nasta] && rad[nasta] <= 'z') { 
        nasta++; 
        return 1 ; 
     } 
     else {
        return 0;
     }
  } 
  int siffra(void) 
  { 
     if ('0' <= rad[nasta] && rad[nasta] <= '9') { 
        nasta++; 
        return 1; 
     } 
     else {
        return 0; 
     }
  } 
  int identifierare(void) 
  { 
     if (bokstav()) { 
        while (bokstav() || siffra()) 
           ; 
        return 1; 
     } 
     else {
        return 0; 
     }
  } 
  int konstant(void) 
  { 
     if (siffra()) { 
        while (siffra()) 
           ; 
        return 1; 
     } 
     else {
        return 0; 
     }
  } 
  int operand(void) 
  { 
     if (identifierare() || konstant()) { 
        return 1; 
     }
     else { 
        fel("Felaktig operand"); 
        return 0 ; 
     } 
  } 
  int operator(void) 
  { 
     switch (rad[nasta]) { 
        case '+': case '-': case '*': case '/': 
           nasta++; 
           return 1; 
        default:  
           fel("Felaktig operator"); 
           return 0; 
     }
  } 
  void ta_bort_blanka(void) 
  { 
     while (rad[nasta] == ' ' || rad[nasta] == '\t') {
        nasta++; 
     }
  }
  int uttryck(void) 
  { 
     ta_bort_blanka(); 
     if(operand())  { 
        ta_bort_blanka(); 
        if (rad[nasta] == '\0') { 
           return 1; 
        }
        else { 
           ta_bort_blanka(); 
           return operator() && uttryck(); 
        } 
     } 
     else {
        return 0;
     }
  }

