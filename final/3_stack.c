#include<stdio.h>
#include <stdlib.h>
#include <string.h>
# define size 5
int top=-1;
int stk[size];
void insert(){
    if(top==size-1){
        printf("stack is overslow");
    }
    else{
        int i;
        top++;
        printf("insert element to the stack: \n");
        scanf("%d",&i);
        stk[top]=i;

    }
    // printf("%d",stk[top]);
}
void delete(){
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        printf("the poped element is %d \n",stk[top--]);
        // top--;
    }
}
void display(){
  if(top==-1){
    printf("stack is empty \n");
  }
  else{
      for(int i=top;i>=0;i--){
        printf("| %d |\n",stk[i]);
    }
  }
}


    int main(){
        // int w=0;
        while(1){
        int chos;
    printf("-------STACK OPERATION---------\n");
    printf("1 push \n2 pop  \n3 Display \n 4Exit\n ");
    printf("\nEnter your choice :") ;
    scanf("%d",&chos);
    switch(chos){
        case 1: insert(); break;
        case 2: delete();break;
        case 3: display();break;
        case 4: exit(0);break;
        default: printf("Invallid choice "); break;
    }
        }


    return 0;
}
