#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <math.h>

int main() {

  int* numbers;
  int i=0;
  int total = 0;
  int n_entries = 0;
  char file_name[] = "vec_10_3_a.txt";
  int base = 0;
  int exponent = 0;
  char baseText[5];
  char exponentText[5];

  FILE *in_file;

  in_file = fopen(file_name, "r+");

  sscanf(file_name,  "vec_%[^_] _%[^_]", baseText, exponentText);
  base = atoi(baseText);
  exponent = atoi(exponentText);
  n_entries = pow(base, exponent);

  numbers = malloc (sizeof (int)*n_entries);
  printf("n_entries: %d\n", n_entries);

  while (fscanf(in_file, "%d", &numbers[i])  != EOF){
    i++;
  }

  for (i = 0; i < n_entries; i++) {
    total += numbers[i];
  }

  printf("\n Total: %d\n", total);

  return 0;
}
