#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

int main(void)
{
  // --- version 1
  int fd = open("alphabet.txt", O_RDONLY, S_IRUSR | S_IWUSR);
  if (fd == -1)
  {
    std::cerr << "Erreur : " << strerror(errno) << std::endl;
  }

  std::cout << "Caractere par caractere : " << std::endl;
  close(fd);

  // -- version 2
  fd = open("alphabet.txt", O_RDONLY, S_IRUSR | S_IWUSR);
  if (fd == -1)
  {
    std::cerr << "Erreur : " << strerror(errno) << std::endl;
  }

  std::cout << "Chaine: " << std::endl;

  close(fd);

  // --- version 3
  fd = open("alphabet.txt", O_RDONLY, S_IRUSR | S_IWUSR);
  if (fd == -1)
  {
    std::cerr << "Erreur : " << strerror(errno) << std::endl;
  }

  std::cout << "String: " << std::endl;
  close(fd);

  // --- version 4 - cout remplacé par écriture sur sortie standard
  std::cout << "Avec write - chaine" << std::endl;

  // Question 5 - Tac
  std::cout << "Tac" << std::endl;

  return 0;
}
