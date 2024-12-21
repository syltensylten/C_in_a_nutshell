void printb(unsigned long int k, int p)
{
  if (p>0 || k>0) {
     printb(k/2, p-1);
     printf("%lu", k%2);
  }
}

