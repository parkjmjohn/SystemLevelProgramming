/*The prime factors of 13195 are 5, 7, 13 and 29.

  What is the largest prime factor of the number 600851475143  ? */

#include <stdio.h> 
#include <stdlib.h> 

int main(){ 
  int ret =0;
  int count = 2;
  long i = 600851475143;

  while (i != 1) {
    if (i % count == 0) {
      while (i % count==0) {
	i = i / count;
      }
      ret = count;
    }
    count++;
  }
  printf ("%d\n", ret);
  return 0;
}
