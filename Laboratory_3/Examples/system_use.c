#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int valor_retornado;
  printf("ID del proceso: %d\n", (int)getpid());
  printf("ID del proceso padre: %d\n", (int)getppid());
  valor_retornado = system("cal");
  valor_retornado = system("ls -l");
  return valor_retornado;
}
