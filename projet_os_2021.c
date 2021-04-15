#include <stdio.h>        /* Pour printf, fprintf, perror */
#include <stdlib.h>       /* Pour exit, EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h>       /* Pour fork */
#include <sys/types.h>    /* Pour pid_t */

/*int main(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++)
        {
            // argv[i] is the argument at index i
        }
         printf("Nom du fichier => %s", argv[0]);
}*/

----------------------------------------------------------------------------

int main() {
  int fils(int i) {
  printf("Je suis le fils %d et mon PID est %d\n", i, getpid());
  exit(EXIT_SUCCESS);
  }
  int i;
  pid_t pid;

  for(i = 1; i <= 5; i++) {
    /* Creation d'un fils */
    pid = fork();
    if(pid == -1) {
      printf(stderr, "Erreur lors de la creation du fils %d\n", i);
      perror("Erreur ");
      exit(EXIT_FAILURE);
    }
    else if(pid == 0) {
      /* Je suis dans le fils */
      fils(i);
    }
  }

  printf("Pere : j'ai cree mes 5 fils...\n");
  sleep(2);
  printf("Pere : je termine mon execution.\n");

  return EXIT_SUCCESS;
}
