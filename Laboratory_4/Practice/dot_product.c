#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>

int main( int argc, char *argv[]) {

  if( argc != 3 ) {
     printf("Error con la cantidad de argumentos\n");
     return 0;
  }
  printf("%s\n", argv[1]);
  printf("%s\n", argv[2]);
  int* vec1;
  int* vec2;
  int i=0;
  int total = 0;
  int n_entries = 0;
  char *file_name1 = argv[1];
  char *file_name2 = argv[2];
  int base = 0;
  int exponent = 0;
  char baseText[5];
  char exponentText[5];

  FILE *in_file1;
  FILE *in_file2;

  in_file1 = fopen(file_name1, "r+");
  in_file2 = fopen(file_name2, "r+");

  sscanf(file_name1,  "vec_%[^_] _%[^_]", baseText, exponentText);
  base = atoi(baseText);
  exponent = atoi(exponentText);
  n_entries = pow(base, exponent);

  vec1 = malloc (sizeof (int)*n_entries);
  printf("n_entries: %d\n", n_entries);

  while (fscanf(in_file1, "%d", &vec1[i])  != EOF){
    i++;
  }

  sscanf(file_name2,  "vec_%[^_] _%[^_]", baseText, exponentText);
  base = atoi(baseText);
  exponent = atoi(exponentText);
  n_entries = pow(base, exponent);
  vec2 = malloc (sizeof (int)*n_entries);


  printf("n_entries: %d\n", n_entries);
  i=0;
  while (fscanf(in_file2, "%d", &vec2[i])  != EOF){
    i++;
  }
  struct timeval start, end;
  gettimeofday(&start, NULL);
  for (i = 0; i < n_entries; i++) {
    total += vec1[i]*vec2[i];
  }

  gettimeofday(&end, NULL);
  unsigned int t = end.tv_usec - start.tv_usec;
  printf("Time elapsed:%lf\n", (double)t / 1000);

  printf("\n Total: %d\n", total);

  return 0;
}
