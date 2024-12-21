unsigned int siff_sum(unsigned int tal) 
{
  unsigned int sum = 0;
  while(tal > 0) {
    sum = sum + tal % 10;   /* lägg till den sista siffran */
    tal = tal / 10;
  }
  return sum;
}

    
