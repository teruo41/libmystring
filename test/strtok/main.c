#include <string.h>
#include <stdio.h>

int main()
{
  char str[80] = "This is - www.tutorialspoint.com - website";
  const char s[2] = "-";
  char *token;

  /* get the first token */
  token = strtok(str, s);

  /* walk through other tokens */
  char *ans[3];
  char ans0[80] = "This is ";
  char ans1[80] = " www.tutorialspoint.com ";
  char ans2[80] = " website";
  ans[0] = ans0;
  ans[1] = ans1;
  ans[2] = ans2;

  int i = 0, j;
  int fault = 0;
  while( token != NULL ) 
  {
    printf( " %s\n", token );

    for (j=0;j<strlen(token)+1;j++)
      if (token[j] != ans[i][j])
        fault = 1;

    token = strtok(NULL, s);
    i++;
  }

  char str2[80] = "This is - www.tutorialspoint.com - website\n";

  /* get the first token */
  token = strtok(str2, s);

  /* walk through other tokens */
  char *ans3[4];
  char ans4[80] = "This is ";
  char ans5[80] = " www.tutorialspoint.com ";
  char ans6[80] = " website\n";
  ans3[0] = ans4;
  ans3[1] = ans5;
  ans3[2] = ans6;

  i = 0;
  while( token != NULL ) 
  {
    printf( " %s\n", token );

    for (j=0;j<strlen(token)+1;j++)
      if (token[j] != ans3[i][j])
        fault = 1;

    token = strtok(NULL, s);
    i++;
  }

  char str3[80] = "-tmat\tmodel/hmm/hub4/transition_matrices";
  const char s2[4] = " \t\n";

  /* get the first token */
  token = strtok(str3, s2);

  /* walk through other tokens */
  char *ans7[6];
  char ans8[80] = "-tmat";
  char ans9[80] = "model/hmm/hub4/transition_matrices";
  char ans10[80] = "-";
  char ans11[80] = "www.tutorialspoint.com";
  char ans12[80] = "-";
  char ans13[80] = "website";
  ans7[0] = ans8;
  ans7[1] = ans9;
  ans7[2] = ans10;
  ans7[3] = ans11;
  ans7[4] = ans12;
  ans7[5] = ans13;

  i = 0;
  while( token != NULL ) 
  {
    printf( " %s\n", token );

    for (j=0;j<strlen(token)+1;j++)
      if (token[j] != ans7[i][j])
        fault = 1;

    token = strtok(NULL, s2);
    i++;
  }

  FILE *fp;
  if ((fp = fopen("args.an4", "r")) == NULL) {
    fault++;
  } else {
    char argline[1000];
    char *targ;

    while (fgets(argline, 1000, fp) != NULL) {
      if ((targ = strtok(argline, " \t\n")) != NULL)
        printf("%s", targ);
      else
        continue;
      while ((targ = strtok(NULL, " \t\n")) != NULL)
        printf(":%s", targ);
      printf("\n");
    }
  }

  if (fault == 1)
    return 1;
  else
    return 0;
}
