#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  FILE *file;
  int i, j = 0;
  
  if (argc != 2 || !(file = fopen(argv[1], "wb")))
  {
    fputs("Usage: encdos <output file>\n", stderr);
    exit(1);
  }

  for (; (i = fgetc(stdin)) != EOF; j = i)
  {
    if (i == '\n' && j != '\r')
      fputc('\r', file);

    fputc(i, file);
  }

  fclose(file);
  return(0);
}
  
