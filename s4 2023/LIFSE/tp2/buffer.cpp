#include <iostream>
#include <string>

int main(){
    std::string maChaine = "abcdefghij";
    char tab[11]; 
    for(int i=0;i<maChaine.length();i++){
        tab[i]=maChaine[i];
    }
    std::string MonStr;
    for(int i=0;i<maChaine.length();i++){
        MonStr+=maChaine[i];
    }
    char big_tab[21];
    for(int i=0;i<20;i++){
        big_tab[i]='-';
    }
    big_tab[21]='\0';
    std::cout<<"tab="<<tab<<std::endl;
    std::cout<<"tab[2] = "<< tab[2]<<std::endl;
    std::cout<<"MonStr="<<MonStr<<std::endl;
    std::cout<<"MonStr[2] = "<< MonStr[2]<<std::endl;
    std::cout<<"big_tab="<<big_tab<<std::endl;

     std::cout<<"pr\x8Asentation..."<<std::endl;
     std::cout<<"pr\x88sentation..."<<std::endl;
     std::cout<<"pr\xAAsentation..."<<std::endl;
     std::cout<<"pr\xBFsentation..."<<std::endl;
     std::cout<<"pr\0sentation..."<<std::endl;
     std::cout<<"présentation..."<<std::endl;
     std::cout<<'\x8A'<<std::endl;
    
    return 0;
    

}