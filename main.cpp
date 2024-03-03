#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<math.h>
#include<cstring>

int main(){
    int flagA = mkdir("A", S_IRWXU);
    int flagB = -1, flagC = -1, flagD = -1;
    if(flagA == 0){
        chdir("A");
        std::cout << "/A was created" << std::endl;
        flagB = mkdir("B", S_IRWXU);
        if(flagB == 0){
            chdir("B");
            std::cout << "/B was created" << std::endl;
            flagC = mkdir("C", S_IRWXU);
            flagD = mkdir("D", S_IRWXU);
        }
    }
    if(flagC == 0){
        std::cout << "/C was created" << std::endl;
        int fd = open("C/3.txt", O_CREAT | O_WRONLY, S_IRWXU);
        char array[256];
        for(int i = 0; i < sizeof(array); i++){
            array[i] = '0' + rand()%8;
        }
        int elem = write(fd, array, sizeof(array));
        if(elem != -1){
            std::cout << "data was written in C/3.txt" << std::endl;
        }
        close(fd);
        int flagLink = link("C/3.txt", "C/1.txt");
        int flagSymlink = symlink("C/3.txt", "C/2.txt");
        if(flagSymlink == 0 && flagLink == 0){
            std::cout << "hard link and symlink was created" << std::endl;
        }
    }
    if(flagD == 0){
        std::cout << "/D was created" << std:: endl;
        int fd1 = open("D/4.txt", O_CREAT | O_WRONLY, S_IRWXU);
        char array1[256];
        for(int i = 0; i < sizeof(array1); i++){
            array1[i] = '0';
        }
        int elem1 = write(fd1, array1, sizeof(array1));
        if(elem1 != -1){
            std::cout << "data was written in D/4.txt" << std::endl;
        }
        close(fd1);
        int fd2 = open("D/5.txt", O_CREAT | O_WRONLY, S_IRWXU);
        char array2[256];
        for(int i = 0; i < sizeof(array1); i++){
            array2[i] = '1';
        }
        int elem2 = write(fd2, array2, sizeof(array2));
        if(elem2 != -1){
            std::cout << "data was written in D/5.txt" << std::endl;
        }
        close(fd2);
    }
}