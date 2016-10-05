#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[13] = "TEST";
char str2[13] = "";

int slen( char *s ){
  int len = 0;
  while (*s) {
    s++;
    len++;
  }
  return len;
}

char * scpy( char *dest, char *source )  {
  int len = slen(source);
  int count = len;
  while(count) {
    dest[len - count] = source[len - count];
    count--;
  }
  dest[len] = 0;
  return dest;
}

char * sncpy( char *dest, char *source, int n) {
  dest += n;
  while ( n>0 ) {
    *dest = *(source + n);
     dest--;
     n--;
  }
  return dest;
}

char * sncat( char *dest, char *source, int n ) {
  return sncpy(dest + slen(dest), source, n) - slen(dest);
}

char * scat( char *dest, char *source ) {
  return sncpy(dest + slen(dest), source, slen(source)) - slen(dest);

}

int scmp( char *s1, char *s2 ) {
  if (!(*s1 || *s2)) {
    return 0;
  }
  else if (*s1 < *s2) {
    return -1;
  }
  else if (*s1 > *s2) {
    return 1;
  }
  else{
    return scmp(++s1, ++s2);
  }
}

char * schr( char *s, char c ) {
  while (c!=*s && *s){
    s++;
  }
  if (!*s) {
    return NULL;
  }
  else { 
    return s;
  }
}

int main(){
  printf("Before applying functions:\n");
  char s1[6] = "HELLO";
  char s2[0] = "";
  printf("s1 = %s, length = %d\n", s1, slen(s1));
  printf("s2 = %s, length = %d\n", s2, slen(s2));
  printf("\n");
  printf("Test regular functions:\n");
  char s3[6] = "HELLO";
  char s4[0] = "";
  char s5[4] = "MAN";
  scpy(s4, s3);
  printf("Copy s3 to s4: s4 = %s, length = %d\n", s4, slen(s4));
  scat(s4, s5);
  //
  printf("Cat 'Man' to s4: s4 = %sMAN, length = %d\n", s4, slen(s4)+3); 
  printf("s3 = %s, length = %d\n", s3, slen(s3));
  printf("\n" );
  printf("Test strcmp\n" );
  char s6[3] = "ab";
  char s7[4] = "abc";
  printf("compare ab to abc: %d\n", scmp(s6, s7)*99);
  printf("compare abc to ab: %d\n", scmp(s7, s6)*99);
  printf("compare abc to ab: %d\n", scmp(s7, s7));
  printf("\n" );
  printf("Testing strchr\n" );
  char s8[9] = "HELLO123";
  printf("Looking for e in Hellow123: [%d] \n\n", schr(s8, 100));
  printf("Testing strstr\n" );
  char s9[4] = "ELL";
  printf("Looking for ELL in HELLOW123: [%d] \n", strstr(s8, s9) );
  return 0;
}
