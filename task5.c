#include <stdio.h>
#include <semaphore.h>

sem_t mutex, wrt;
int rcount, data;

void reader(int f){
    sem_wait(&mutex);
    rcount++;
    if (rcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("Data read by the reader %d is %d\n", f, data);
    sem_wait(&mutex);
    rcount--;
    if(rcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);
}

void writer(int f){
    sem_wait(&wrt);
    data++;
    printf("Data writen by the writer %d is %d\n", f, data);
    sem_post(&wrt);
}

int main(){
    int choice, f;
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    printf("1. Reader\n2. Writer\n3. Quit\n");
    while (1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the reader number: ");
                scanf("%d", &f);
                reader(f);
                break;
            case 2:
                printf("Enter the writer number: ");
                scanf("%d", &f);
                writer(f);
                break;
            case 3:
                return 0;
        }
    }
}
