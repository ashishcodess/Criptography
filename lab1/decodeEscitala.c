#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int read_content(int fd, void *c, int size){
    int ret = read(fd, c, size);
    return ret;
}

int open_content(char *fileName, int flags){
    int fd = open(fileName , flags);
    return fd;
}

int write_content(int fd , void *c , int size){
    int ret = write(fd , c , size);
    return ret;
}
int main(int argc, char *argv[]){
    if(argc < 2 ){
        char buff[80];
        sprintf(buff, "Please enter ./decode_escítala and then rows\n");
        write(1, buff, strlen(buff));
    }

    struct stat st;
    stat("download.escitala", &st);
    int size = st.st_size;
    printf("size is : %d\n", size);
    int msgCoded = open_content("download.escitala" , O_RDONLY);
    
    int rows , columns;
    rows = atoi(argv[1]);


    float div = size/(float)rows;
    int perfect = (int) div;

    if(perfect == div){
        columns = perfect;
    }    
    else{
        columns = perfect +1;
    }
    // printf("columns are: %d\n", columns);
    
    char coded[size];
    int r = read_content(msgCoded ,coded , size);
    printf("first element : %c\n", coded[10074]);
    
    int counter = 0; // Contador para irme de 00 a 0size de matrix_coded;
    char matrix_decoded[columns][rows];
    
    for(int i = 0; i < columns ; ++i ){
        for(int j = 0; j < rows ; ++j){
            matrix_decoded[j][i] = coded[counter];
            ++counter;
        }
    }

    int fd1 = open("decoded_escitalo.txt", O_CREAT | O_RDWR);
    write_content(fd1 , matrix_decoded, size);
}