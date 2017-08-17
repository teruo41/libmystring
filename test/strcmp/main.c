#include <stdio.h>
#include <string.h>

int main ()
{
  printf("strcmp(\"a\",\"\"))     = %2d\n", strcmp("a",""));
  printf("strcmp(\"\",\"a\"))     = %2d\n", strcmp("","a"));
  printf("strcmp(\"abc\",\"ABC\") = %2d\n", strcmp("abc","ABC"));
  printf("strcmp(\"ABC\",\"abc\") = %2d\n", strcmp("ABC","abc"));
  printf("strcmp(\"ABC\",\"ABC\") = %2d\n", strcmp("ABC","ABC"));

  if (strcmp("a", "") != 1)
    return 1;

  if (strcmp("","a") != -1)
    return 1;

  if (strcmp("abc","ABC") != 1)
    return 1;

  if (strcmp("ABC","abc") != -1)
    return 1;

  if (strcmp("ABC","ABC") != 0)
    return 1;

  return 0;
}
