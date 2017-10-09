#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>

int main() {

  int* numbers;
  int ch;
  int i=0;
  int total = 0;
  FILE *in_file;
  char* file_name = "vec_10_1_a.txt";
  int n_entries = 0;

  in_file = fopen(file_name, "r+"); //Open file

  // Get the number of lines
  while(!feof(in_file)){
    ch = fgetc(in_file);
    if(ch == '\n'){
      n_entries++;
    }
  }

  //  Sets the file position to the beginning of the file
  rewind(in_file);

  numbers = malloc (sizeof (int)*n_entries);
  printf("n_entries: %d\n", n_entries);

  while (fscanf(in_file, "%d", &numbers[i])  != EOF){
    i++;
  }

  for (i = 0; i < n_entries; i++) {
    // printf("%d\n", numbers[i]);
    total += numbers[i];
  }

  printf("\n Total: %d\n", total);

  return 0;
}
