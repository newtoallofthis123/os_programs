#include <stdio.h>

int mutex = 1, empty = 3, full = 0, x = 0;

int wait(int s){
    while (s <= 0);
    return (--s);
}

int signal(int s){
    return (++s);
}

void producer(){
    empty = wait(empty);
    mutex = wait(mutex);
    x++;
    printf("Producer produces the item %d\n", x);
    mutex = signal(mutex);
    full = signal(full);
}

void consume(){
    full = wait(full);
    mutex = wait(mutex);
    printf("Consumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
    empty = signal(empty);
}

int main(){
    int choice;
    printf("1. Producer\n2. Consumer\n3. Quit\n");
    while (1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full\n");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consume();
                else
                    printf("Buffer is empty\n");
                break;
            case 3:
                return 0;
        }
    }
}
