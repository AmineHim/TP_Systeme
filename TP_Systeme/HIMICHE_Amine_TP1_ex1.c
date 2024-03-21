#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void afficherInfo(void);

int main(int argc, char const *argv[]) {

  int pcirconstance;
  pid_t pid_fork;

  pid_fork=fork();
  if (pid_fork==-1)/* échec du fork */{
    exit(EXIT_FAILURE);}

  else if (pid_fork){  /* Code exécuté par le père */
    while ((pid_fork=wait(&pcirconstance))!=-1) {
      printf("Le code retour du fils est : %d\n", WEXITSTATUS(pcirconstance));
    }
    printf("Le processus pere se termine son code de retour est : %d\n\n", EXIT_SUCCESS);}

  else{  /* Code exécuté par le fils */
    printf("\nInformation :\n\n");
    afficherInfo();
    printf("le processus fils se termine son code de retour est : %d\n", EXIT_SUCCESS);}

  return 0;

}

void afficherInfo(void){
  printf("####################################################\n\n");
  printf("l’identificateur du processus courant est : %d\n",getpid());
  printf("l’identificateur du processus père du processus courant est : %d\n", getppid());
  printf("l’identificateur du groupe (pgrp) de processus auquel appartientle processus courant est : %d\n", *getlogin());
  printf("l’identificateur de l’utilisateur (uid) propriétaire du processus courant est : %d\n", getuid());
  printf("l’identificateur du groupe d’utilisateurs (gid) du propriétaire duprocessus courant est : %d\n",getgid() );
  printf("\n####################################################\n\n");
}
