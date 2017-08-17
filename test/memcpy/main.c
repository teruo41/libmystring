#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  const char src[50] = "http://www.tutorialspoint.com";
  char dest[50];

  printf("Before memcpy dest = %s\n", dest);
  memcpy(dest, src, strlen(src)+1);
  printf("After memcpy dest = %s\n", dest);

  // check result
  int i;
  for (i=0; i<strlen(src)+1; i++)
    if (src[i] != dest[i])
      return(1);

  return(0);
}
