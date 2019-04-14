//Tsotras Stefanos icsd13189
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FNAME "test.txt"

typedef struct node{
    char *data;
    struct node *right;
    struct node *left;
}node;

node *head;

node *addNode(node *head,char *data);
node *Search(node *head,char *data);
void display(node *temp);
int readLine(FILE *file,int *wordcount,int linecount);

int main(){

FILE* file;
int wordcount = 0;
int linecount=0;

//ANOIGMA ARXEIOU
file = fopen(FNAME , "r");

if (file != NULL) {
    //DIAVASMA GRAMMH GRAMMH
    while(readLine(file,&wordcount,linecount) == 1){
        linecount++;
    }
    if (ferror(file)) {
        printf("Error!\n\n");
    }
    fclose(file);
}
else{
    printf("Error!\n\n");
}


display(head);
printf("\nLines : %d , Words : %d\n",linecount,wordcount);

}


int readLine(FILE *file,int *wordcount,int linecount){

    char word[256];
    int index=0;
    char c;

    //OSO DEN VRISKEI "ENTER"-ALLAGH GRAMMHS
    //DIAVAZEI XARAKTHRA APTO ARXEIO
    while((c=getc(file)) != '\n'){

        //AN DEN EINAI KATI APO TA PARAKATW
        if(c != ' ' && c != ',' && c != '.' && c != ':' && c != '!' && c != '?' && c != '<' && c != '>' && c != '/'){
            //PROSTHETEI TON XARAKTHRA STO STRING
            word[index] = c;
            index++;
        }
        else{
            //OTAN VREI KENO H SHMEIA STIKSHS
            //DHLWNEI TO TELOS TOU STRING
            word[index] = '\0';
            //ADD STO DENTRO
            head = addNode(head,word);
            //MHDENISMOS TOU STRING
            word[0] = '\0';
            index=0;
            *wordcount = *wordcount + 1;
        }
        //EPISTREFEI 0 GIA NA TELIWSEI H WHILE STHN MAIN
        //OTAN VREI TO TELOS TOU ARXEIOU
        if(c == EOF){
            return 0;
        }

    }
    return 1;
}


node* Search(node *head,char *data){

    //AN H LISTA EINAI ADEIA H
    //OTAN VREI THN LEKSH EPISTREFEI TON KOMVO
    if ((head==NULL) || (head->data=data)){
        return head;
    }

    //PSAXNEI STO DEKSI PAIDI
    else if(head->data<data){
        return Search(head->right,data);
    }

    //PSAXNEI STO ARISTERO
    else if(head->data>data){
        return Search(head->left,data);
    }
}


node *addNode(node *head,char *data){

    //DHMIOURGIA KOMVOU
    if(head==NULL){
        node *current;
        current=(node*)malloc(sizeof(node));
        current->data=data;
        current->left=NULL;
        current->right=NULL;
    }

    //FTIAXNEI KOMVO STO ARISTERO PAIDI
    else if(data<head->data){
        head->left = addNode(head->left,data);
    }

    //FTIAXNEI KOMVO STO DEKSI PAIDI
    else if(data>head->data){
        head->right=addNode(head->right,data);
    }

    return head;
}


void display(node *temp) {
    //DIASXISH KAI EMFANISH DENTROU
    if (temp != NULL) {
        display(temp->left);
        printf("%s", temp->data);
        display(temp->right);
    }
}

