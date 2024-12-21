int rel_prim(unsigned int i, unsigned int j) 
{
  unsigned int k;
  for (k=2; k<=i && k<=j; k++) {
    if (i%k == 0 && j%k == 0)
      return 0;
  }
  return 1;
}
