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
    chdir("A");
    chdir("B");
    chdir("C");
    int flagLink = unlink("1.txt");
    if(flagLink == 0){
        std::cout << "hard link was deleted"<<std::endl;
    }
    int flagSymLink = unlink("2.txt");
    if(flagSymLink == 0){
        std::cout << "symlink was deleted"<<std::endl;
    }
    int flagFile = remove("3.txt");
    if(flagFile== 0){
        std::cout << "3.txt was deleted"<<std::endl;
    }
    chdir("../");
    int flag = rmdir("C");
    if(flag == 0){
        std::cout << "/C was deleted"<<std::endl;
    }
    flagFile = remove("D/4.txt");
    if(flagFile== 0){
        std::cout << "4.txt was deleted"<<std::endl;
    }
    flagFile = remove("D/5.txt");
    if(flagFile== 0){
        std::cout << "5.txt was deleted"<<std::endl;
    }
    flag = rmdir("D");
    if(flag == 0){
        std::cout << "/D was deleted"<<std::endl;
    }
    chdir("../");
    flag = rmdir("B");
    if(flag == 0){
        std::cout << "/B was deleted"<<std::endl;
    }
    chdir("../");
    flag = rmdir("A");
    if(flag == 0){
        std::cout << "/A was deleted"<<std::endl;
    }
}