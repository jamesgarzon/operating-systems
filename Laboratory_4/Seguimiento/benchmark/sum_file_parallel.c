#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>

// Esta estructura sirve para pasar parámetros al hilo
struct parametro_hilo {
  int *numbers;
  int start;
  int end;
  int total;
};

int total1 = 0;
// int total2 = 0;

void* sum(void* parametros){
  struct parametro_hilo* p = (struct parametro_hilo*) parametros;
  // int *numbers = p->numbers;
  int start = p->start;
  int end = p->end;

  for (int i = start; i < end; i++) {
    // printf("lalala\n");
    total1 += p->numbers[i];
  }
  //  for (int i = 0; i < p->contador; i++) {
  //    fputc(p->caracter, stderr);
  //  }
   return NULL;
}

int main() {

  int* numbers;
  int ch;
  int i=0;
  // int total = 0;
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

  ////////////

  pthread_t id_hilo_1;
  pthread_t id_hilo_2;
  struct parametro_hilo hilo_1_param;
  struct parametro_hilo hilo_2_param;

  hilo_1_param.numbers = numbers;
  hilo_1_param.start = 0;
  hilo_1_param.end = n_entries/2;
  hilo_1_param.total = 0;
  pthread_create(&id_hilo_1, NULL, &sum, &hilo_1_param);

  hilo_2_param.numbers = numbers;
  hilo_2_param.start = n_entries/2;
  hilo_2_param.end = n_entries;
  hilo_2_param.total = 0;
  pthread_create(&id_hilo_2, NULL, &sum, &hilo_2_param);

  pthread_join (id_hilo_1, NULL);
  pthread_join (id_hilo_2, NULL);
  ///////////

  // printf("Total: %d\n", hilo_1_param.total + hilo_2_param.total);
  printf("total: %d\n", total1);
  // for (i = 0; i < n_entries; i++) {
  //   // printf("%d\n", numbers[i]);
  //   total += numbers[i];
  // }

  return 0;
}
