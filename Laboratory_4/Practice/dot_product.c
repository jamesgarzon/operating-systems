#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <math.h>

int main() {

  int* vec1;
  int* vec2;
  int i=0;
  int total = 0;
  int n_entries = 0;
  char file_name1[] = "vec_10_3_a.txt";
  char file_name2[] = "vec_10_3_b.txt";
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

  for (i = 0; i < n_entries; i++) {
    total += vec1[i]*vec2[i];
  }

  printf("\n Total: %d\n", total);

  return 0;
}
