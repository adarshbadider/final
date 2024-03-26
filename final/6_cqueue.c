#include<stdio.h>
#include<stdio.h>
#define size 5
int queue[size];
int front=-1;
int rare=-1;
void exit();
void insert(){
    int c=1;
    int x;
    if(front==-1 && rare==-1){
        
        printf("enter %d th element:",c);
        c=c+1;
        scanf("%d",&x);
        front=rare=0;
        queue[rare]=x;
    }
    else if((rare+1)%size==front){
        printf("queue is full");
    }
    else{
        printf("enter %d th element:",c);
        c=c+1;
        scanf("%d",&x);
        rare=(rare+1)%size;
        queue[rare]=x;

    }
}
void display(){
    if(front==-1 && rare==-1){
        printf("queue is empty");
    }
    else {
        printf("the queue is :\n");
        for(int i = front; ; i = (i + 1) % size) {
            printf("%d \n", queue[i]);
            if (i == rare) // Break the loop when the last element is reached
                break;
        }
    }
}

void delete(){
    if(front==-1 && rare==-1){
        printf("the queue is empty");
    }
    else if(rare==front){
        rare=front=-1;
    }
    else{
        printf("the dequeue element is %d",queue[front]);
        front=(front+1)%size;
    }
}

    int main(){
        int ch;
        while(1){
        printf("------QUEUE OPERETION------\n");
        printf("1 to insert\n2 to delete\n3 to display\n4 exit\n");
        printf("enter your choice :");
        scanf("%d",&ch);
        switch(ch){
        case 1 :insert();  break;
        case 2 :delete();  break;
        case 3 :display(); break;
        case 4 :exit(0);   break;
        default: printf("invallid choice"); break;
    }
    }
    
    return 0;
}