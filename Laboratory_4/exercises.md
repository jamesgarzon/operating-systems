## exercises
1. ¿Cuáles son los argumentos de la función pthread_create? ¿Para qué sirven?
- `Thread`: Ubicación donde el ID del nuevo hilo creado debería estar almacenado.
  - `attr`: Son los atributos del hilo que será creado, si el atributo es `null`, el hilo será creado con los atributos por defecto.
  - `start`: Es la función principal para el hilo; el hilo empieza a ejecutar el codigo de usuario en esta dirección.
  - `arg`: Parametro pasado al inicio.


2. ¿Cómo es la salida en pantalla? ¿Cuál es la razón para este tipo de salida?
