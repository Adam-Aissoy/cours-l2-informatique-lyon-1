#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
  unsigned char uc1, uc2, uc3; signed char sc1, sc2, sc3;
  unsigned short ui1, ui2, ui3; signed short si1, si2, si3;
  printf("\n Taille de char : %lu octets \n\n",sizeof(char));
  uc1 = 200 ; uc2 = 60 ; uc3 = uc1 + uc2 ;
  printf("(unsigned char) uc1 = %d, uc2 = %d, uc1+uc2 = %d \n",uc1, uc2, uc3) ;
  sc1 = 100 ; sc2 = 60 ; sc3 = sc1+sc2 ;
  printf("(signed char) sc1 = %d, sc2 = %d, sc1+sc2 = %d \n",sc1, sc2, sc3) ;
  sc1 = -100 ; sc2 = -60 ; sc3 = sc1+sc2 ;
  printf("(signed char) sc1 = %d, sc2 = %d, sc1+sc2 = %d \n",sc1, sc2, sc3) ;
  printf("\n Taille de short : %lu octets\n\n",sizeof(short));
  ui1 = 6000 ; ui2 = 60000 ; ui3 = ui1+ui2 ;
  printf("(unsigned short) ui1 = %d, ui2 = %d, ui1+ui2 = %d \n",ui1, ui2, ui3) ;
  si1 = -10000 ; si2 = -30000 ; si3 = si1+si2 ;
  printf("(signed short) si1 = %d, si2 = %d, si1+si2 = %d \n",si1, si2, si3) ;
  return 0;
}
