/* 6_4.c */

#include  <stdio.h> 

#define  MIN  0
#define  MAX 12


int nfak(int n)
{ 
   if (n<=0) { 
      return 1; 
   }
   else {
      return n * nfak(n - 1); 
   }
}


int binkoeff(int n, int k)
{
  return nfak(n) / (nfak(k)*nfak(n-k));
}

/* Test */
int main()
{
  int n, k;

  printf("BINOMIALKOEFFICIENTEN F�R 2 TAL\n");
  printf("Grundf�ruts�ttning:  0 <= k <= n\n");
  printf("Ange n-v�rde (%d <= n <= %2d): ", MIN ,MAX);
  scanf("%u", &n);
  printf("Ange k-v�rde (%d <= k <= %2u): ", MIN ,n);
  scanf("%u", &k);
  printf("Binomialkoefficienten f�r n = %u och k = %u", n, k);
  printf("  =>  %d\n", binkoeff(n, k));
}

