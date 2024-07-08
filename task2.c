#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd1, fd2;
    char *buff;

    fd1 = open("foo", O_RDONLY);
    fd2 = open("hi", O_WRONLY | O_CREAT);

    while(read(fd1, buff, 1) > 0){
        write(fd2, buff, 1);
    }
}
