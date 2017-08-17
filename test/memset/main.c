#include <stdio.h>
#include <string.h>

int main ()
{
  char str[50] = "This is string.h library function";
  puts(str);

  memset(str,'$',7);
  puts(str);

  // check result
  char ans[50] = "$$$$$$$ string.h library function";
  int i;
  for (i=0; i<strlen(str)+1; i++)
    if (str[i] != ans[i])
      return 1;

  return 0;
}
