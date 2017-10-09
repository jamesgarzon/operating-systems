#include <pthread.h>
#include <stdio.h>

// Esta estructura sirve para pasar parámetros al hilo
struct parametro_hilo {
  // Parametro 1: caracter a imprimir
  char caracter;
  // Parametro 2: Número de veces que desea imprimir
  int contador;
};

void* imprimir_caracter(void* parametros){
  struct parametro_hilo* p = (struct parametro_hilo*) parametros;
   for (int i = 0; i < p->contador; i++) {
     fputc(p->caracter, stderr);
   }
   return NULL;
}


int main() {
  pthread_t id_hilo_1;
  pthread_t id_hilo_2;
  struct parametro_hilo hilo_1_param;
  struct parametro_hilo hilo_2_param;

  hilo_1_param.caracter = 'x';
  hilo_1_param.contador = 30000;
  pthread_create(&id_hilo_1, NULL, &imprimir_caracter, &hilo_1_param);

  hilo_2_param.caracter = 'o';
  hilo_2_param.contador = 20000;
  pthread_create(&id_hilo_2, NULL, &imprimir_caracter, &hilo_2_param);

  pthread_join (id_hilo_1, NULL);
  pthread_join (id_hilo_2, NULL);

  return 0;
}
