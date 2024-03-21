#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

  int nbFils;
  pid_t pid_fils;
  int i=0;

  if (argc!=2) {
    fprintf(stderr, "Usage : %s <nbFils>\n", argv[0] );
    exit(1);
  }

  nbFils=atoi(argv[1]);

  while(i<nbFils) {
    int retour;
    pid_fils=fork();
    if (pid_fils==-1) {
      exit(1);
    }

    if (pid_fils==0) {
      printf("Je suis fils%i pid %d\n",i, getpid());
    }

    while(pid_fils=wait(&retour)!=-1){
      printf("Mon fils %d a retourné %d\n",pid_fils,WEXITSTATUS(retour));
    }
    i--;
  }

  exit(0);
  return 0;

}
