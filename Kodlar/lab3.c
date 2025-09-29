#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data;
    struct Node *next;

};

struct Queue{

    struct Node *front;
    struct Node *rear;

};

void display(struct Queue *q);
struct Queue* insert(struct Queue *q,int value);
struct Queue* delete_front(struct Queue *q);
struct Queue* delete_rear(struct Queue *q);
int peek_front(struct Queue *q);
int peek_rear(struct Queue *q);

int main(){

    struct Queue *myQueue=(struct Queue *)malloc(sizeof(struct Queue));
    struct Queue *copyMyQueue=(struct Queue *)malloc(sizeof(struct Queue));
    myQueue->front=NULL;myQueue->rear=NULL;copyMyQueue->front=NULL;copyMyQueue->rear=NULL;
    int number,stepNumber,sum=0,orderFront=1,orderRear=0;

    scanf("%d",&number);

    while (number!=-1){

        myQueue=insert(myQueue,number);
        copyMyQueue=insert(copyMyQueue,number);
        orderRear++;
        scanf("%d",&number);

    }

    scanf("%d",&stepNumber);

    for (int i=0;i<stepNumber;i++){

        int front = peek_front(myQueue);
        delete_front(myQueue);
        int rear = peek_rear(myQueue);
        delete_rear(myQueue);

        if (front >= rear){
            sum+=front;
        }
        else{
            sum+=rear;
        }

    }

    printf("%d\n",sum);

    for (int i=0;i<stepNumber;i++){

        int front = peek_front(copyMyQueue);
        delete_front(copyMyQueue);
        int rear = peek_rear(copyMyQueue);
        delete_rear(copyMyQueue);

        if (front >= rear){
            printf("%d %d\n",front,orderFront);
        }
        else{
            printf("%d %d\n",rear,orderRear);
        }
        
        orderFront++;
        orderRear--;

    }

    return 0;
}

void display(struct Queue *q){

    struct Node *ptr=q->front;

    if (ptr==NULL){

        printf("QUEUE IS EMPTY\n");

    }
    else{

        while(ptr!=q->rear){

            printf("%d ",ptr->data);
            ptr=ptr->next;

        }
        printf("%d \n",ptr->data);

    }

}

struct Queue* insert(struct Queue *q,int value){

    struct Node *newNode;

    newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->next=NULL;

    if (q->front==NULL){

        q->front=newNode;
        q->rear=newNode;

    }
    else{

        q->rear->next=newNode;
        q->rear=newNode;

    }

    return q;
}

struct Queue* delete_front(struct Queue *q){

    struct Node *ptr=q->front;

    if (q==NULL){

        printf("UNDERFLOW\n");

    }
    else{

        q->front=q->front->next;
        free(ptr);

    }

    return q;
}

struct Queue* delete_rear(struct Queue *q){

    struct Node *ptr=q->rear;

    if (q->front==NULL){

        printf("UNDERFLOW\n");

    }
    else{

        struct Node *myPtr;

        myPtr=q->front;
        while (myPtr->next != q->rear){

            myPtr=myPtr->next;

        }

        q->rear=myPtr;

        free(ptr);

    }

    return q;
}

int peek_front(struct Queue *q){

    if (q->front==NULL){

        printf("QUEUE IS EMPTY\n");
        return -1;

    }
    else{

        return q->front->data;

    }

}

int peek_rear(struct Queue *q){

    if (q->rear==NULL){

        printf("QUEUE IS EMPTY\n");
        return -1;

    }
    else{

        return q->rear->data;

    }

}