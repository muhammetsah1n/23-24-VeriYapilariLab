#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char *s1,char *s2);
char* my_strcpy(char *s1,char *s2);
struct node *insertElement(struct node *tree, char name[], int phoneNumber);
void in_order_traversal(struct node *tree);
int my_strlen(char str[]);
int compare_n_characters(char str1[],char str2[],int n);
int find_matched(struct node *tree,char *characters);

struct node{

    struct node *left;
    char name[100];
    int phoneNumber;
    struct node *right;

};

int main(){

    struct node *tree=NULL;
    char name[100],characters[100];
    int phoneNumber,counter;

    while (1){

        scanf("%s",name);
        if (my_strcmp(name,"-1")==0){
            break;
        }
        scanf("%d",&phoneNumber);

        tree=insertElement(tree,name,phoneNumber);

    }

    while (1){

        scanf("%s",characters);
        counter=find_matched(tree,characters);

        if (my_strcmp(characters,"-1")==0 || counter==1){

            break;

        }

        else if (counter==0){

            printf("nobody\n");

            break;
        }

    }

    return 0;
}

int my_strcmp(char *s1,char *s2){

    int i;

    for (i=0; s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0' ;i++);

    if (s1[i]=='\0' && s2[i]=='\0'){
        return 0;
    }
    else if(s1[i]>s2[i]){
        return 1;
    }
    else{
        return -1;
    }

}

char* my_strcpy(char *s1,char *s2){

    int i=0;

    while (s2[i]!='\0'){

        s1[i]=s2[i];
        i++;

    }

    s1[i]='\0';
    
    return s1;

}

struct node *insertElement(struct node *tree, char name[], int phoneNumber){

    if(tree==NULL){

        struct node *newNode;
        newNode=(struct node*)malloc(sizeof(struct node));
        my_strcpy(newNode->name,name);
        newNode->phoneNumber=phoneNumber;
        newNode->left=NULL;
        newNode->right=NULL;

        tree=newNode;

    }
    else{

        if (my_strcmp(name,tree->name)==-1){
            tree->left=insertElement(tree->left,name,phoneNumber);
        }
        else{
            tree->right=insertElement(tree->right,name,phoneNumber);
        }

    }

    return tree;
}

void in_order_traversal(struct node *tree){

    if (tree != NULL){

        in_order_traversal(tree->left);
        printf("%s\n",tree->name);
        in_order_traversal(tree->right);

    }

}

int compare_n_characters(char str1[],char str2[],int n){

    int i;

    for(i=0; str1[i]==str2[i] && str1[i]!='\0' && str2[i]!='\0' && i<n ;i++);

    if(i==n){
        return 1;
    }
    else{
        return -1;
    }

}

int my_strlen(char str[]){

    int i=0,size=0;

    while (str[i]!='\0'){
        size++;
        i++;
    }

    return size;

}

int find_matched(struct node *tree,char *characters){

    int counter=0;

    if (tree != NULL){

        counter+=find_matched(tree->left,characters);

        if (compare_n_characters(tree->name,characters,my_strlen(characters))==1){

            printf("%s\n",tree->name);
            counter++;

        }

        counter+=find_matched(tree->right,characters);

    }

    return counter;

}