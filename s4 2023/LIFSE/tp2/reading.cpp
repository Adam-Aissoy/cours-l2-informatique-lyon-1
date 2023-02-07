#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {

  char tab[11];
  tab[0] = 'a';
  tab[1] = 'b';
  tab[2] = 'c';
  tab[3] = 'd';
  tab[4] = 'e';
  tab[5] = 'f';
  tab[6] = 'g';
  tab[7] = 'h';
  tab[8] = 'i';
  tab[9] = 'j';
  tab[10] = '\0';

  // premier open :
  // pas les droits pour lire le fichier directement.
  // chmod à faire
  int fd = open("premier_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0);
  if (fd == -1)
  {
    std::cerr << "Erreur : " << strerror(errno) << std::endl;
    exit(1);
  }

  // Ecriture caractère par caractère

  // second open :
  // donne les droits pour lire directement le fichier
  int fd2 = open("premier_test2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  if (fd2 == -1)
  {
    std::cerr << "Erreur : " << strerror(errno) << std::endl;
    exit(1);
  }

  // Ecriture caractère par caractère
  
  return 0;
}

