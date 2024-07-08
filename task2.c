#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd1, fd2;
    char buf[1024];
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0644);

    while (read(fd1, buf, 1024) > 0){
        write(fd2, buf, 1024);
    }
}
