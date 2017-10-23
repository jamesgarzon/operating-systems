#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <math.h>

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
   return NULL;
}

int main() {

  int* vec1;
  int* vec2;
  int i=0;
  int n_entries = 0;
  char file_name1[] = "vec_10_1_a.txt";
  char file_name2[] = "vec_10_1_b.txt";
  int base = 0;
  int exponent = 0;
  char baseText[5];
  char exponentText[5];

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

//////////////////
  pthread_t id_thread_1;
  pthread_t id_thread_2;
  struct threadParam thread_1_param;
  struct threadParam thread_2_param;

  thread_1_param.vec1 = vec1;
  thread_1_param.vec2 = vec2;
  thread_1_param.start = 0;
  thread_1_param.end = n_entries/2;
  thread_1_param.total = 0;
  pthread_create(&id_thread_1, NULL, &multiply, &thread_1_param);

  thread_2_param.vec1 = vec1;
  thread_2_param.vec2 = vec2;
  thread_2_param.start = n_entries/2;
  thread_2_param.end = n_entries;
  thread_2_param.total = 0;

  pthread_create(&id_thread_2, NULL, &multiply, &thread_2_param);

  pthread_join (id_thread_1, NULL);
  pthread_join (id_thread_2, NULL);
  printf("\n Total1: %d\n", thread_1_param.total);
  printf("\n Total2: %d\n", thread_2_param.total);
  printf("\n Grand Total: %d\n", thread_1_param.total +thread_2_param.total);


  return 0;
}
