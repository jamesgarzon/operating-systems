#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
// Struct to pass params to the thread
struct threadParam {
  int *vec1;
  int *vec2;
  int start;
  int end;
  int total;
};

void* multiply(void* parametros){
  struct threadParam* p = (struct threadParam*) parametros;
  int *vec1 = p->vec1;
  int *vec2 = p->vec2;
  int start = p->start;
  int end = p->end;
  for (int i = start; i < end; i++) {
    p->total += vec1[i]*vec2[i];
  }
  printf("custom total: %d\n", p->total);
   return NULL;
}
int main(int argc, char *argv[]) {

  if( argc != 4 ) {
     printf("Error con el numero de argumentos\n");
     return 0;
  }

  int n_threads = atoi(argv[3]);
  char *file_name1 = argv[1];
  char *file_name2 = argv[2];
  int* vec1;
  int* vec2;
  int i=0;
  int n_entries = 0;
  // char file_name1[] = "vec_10_8_a.txt";
  // char file_name2[] = "vec_10_8_b.txt";
  int base = 0;
  int exponent = 0;
  char baseText[5];
  char exponentText[5];
  int total = 0;


  FILE *in_file1;
  FILE *in_file2;

  in_file1 = fopen(file_name1, "r+");
  in_file2 = fopen(file_name2, "r+");

  sscanf(file_name1,  "vec_%[^_] _%[^_]", baseText, exponentText);
  sscanf(file_name2,  "vec_%[^_] _%[^_]", baseText, exponentText);

  base = atoi(baseText);
  exponent = atoi(exponentText);
  n_entries = pow(base, exponent);

  vec1 = malloc (sizeof (int)*n_entries);
  vec2 = malloc (sizeof (int)*n_entries);

  while (fscanf(in_file1, "%d", &vec1[i])  != EOF){
    i++;
  }

  i=0;
  while (fscanf(in_file2, "%d", &vec2[i])  != EOF){
    i++;
  }

  pthread_t id_threads[n_threads];
  struct threadParam threads_params[n_threads];
  struct timeval start, end;

    gettimeofday(&start, NULL);

  for (i = 0; i < n_threads; i++) {
    (threads_params[i]).vec1 = vec1;
    (threads_params[i]).vec2 = vec2;
    (threads_params[i]).start = i * (n_entries/n_threads);
    (threads_params[i]).end = (i + 1) * (n_entries/n_threads);
    (threads_params[i]).total = 0;
    pthread_create(&(id_threads[i]), NULL, &multiply, &(threads_params[i]));
  }

  for ( i = 0; i < n_threads; i++) {
    pthread_join (id_threads[i], NULL);
  }

  for ( i = 0; i < n_threads; i++) {
    total += threads_params[i].total;
  }
  gettimeofday(&end, NULL);
  unsigned int t = end.tv_usec - start.tv_usec;
  printf("Time:%lf\n", (double)t / 1000);
  printf("\n Total: %d\n", total);


  return 0;
}
