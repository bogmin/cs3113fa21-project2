#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//this code is not fully functional. I apologize. I've been struggling a bit mentally lately here, and even with
//the extension was not able to finish. The plan here was to have a function that read each instruction, then executed
//them using the necessary function. From there, each fit type would be called.

typedef struct block {
    int memory;     //how much memory it takes up
    int memStart;   //starting location of memory
    struct block *next;
    char process[]; //process name; treat this like the key
} block;

struct block *head = NULL;
struct block *current = NULL;

char instruction[50]; //holds the instruction/values to be assigned/listed/etc.

//struct block* memStore[200];        //array to hold the various memory blocks
int requests = 0;   //number of requests for blocks
int totalMem;   //total amount of memory assigned at read

void insertFirst(char process[], int memory, int memStart){ //insert at start of LL
    struct block *link = (struct block*) malloc(sizeof(struct block));
    link->memStart = memStart;
    link->memory = memory;
    strcpy(link->process, process);

    link->next = head;
    head = link;
}

int length() {  //find length of LL
    int length = 0;
    struct block *count;

    for (count = head; current != NULL; current = current->next){
        length++;
    }
    return length;
}

struct block* find (char key[]) {   //find LL by key
    struct block* current = head;
    if(head == NULL){
        return NULL;
    }

    while (strcmp(current->process,key) != 0){
        if(current->next == NULL){
            return NULL;
        }
        else {
            current = current->next;
        }
    }
    return current;
}

struct block* delete(char key[]){    //delete block from LL
    struct block* current = head;
    struct block* previous = NULL;

    if (head == NULL){
        return NULL;
    }

    while (strcmp(current->process,key) != 0){
        if(current->next == NULL){
            return NULL;
        }
        else {
            previous = current;
            current = current->next;
        }
    }

    if (current == head){
        head = head->next;
    }
    else {
        previous->next = current->next;
    }
    return current;
}

void bestfit(){ //best fit method

}

void firstfit(){        //first fit method

}

void worstfit(){    //worst fit method

}

void nextfit(){ //next fit method

}

void request(char requestBlock[]){    //request a new block; use insert
    char requestHolder[6];
    char processName[5];
    int memory;
}

void release(){ //release a block; call delete

}

void listAvailable(){

}

void listAssigned(){

}

/*void find(){

}*/

int numberRequests(){ //to get number of blocks
   /* if(instruction[0] == 'R' && instruction[2] == 'Q'){
        requests++;
    }*/
    requests++;
    return requests;
}

void readInstruct(char instruction[]){  //read and execute instructions
    if(instruction[0] == 'R' && instruction[2] == 'Q'){
        numberRequests();
        request(instruction);
    }
}

int main(int argc, char **argv) {

    char selector[8];
    scanf("%s", selector);
    scanf("%d", &totalMem);

    FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin; //read in file given as argv[1] or read stdin
    if (!fp){
        fprintf(stderr, "file open failed '%s'\n",argv[1]);
    }

    int i = 0;

    while(fgets(instruction, sizeof(instruction), fp) != NULL){ //fgets reads instructions, then puts them in instructArray
        readInstruct(instruction);
    }

    if(selector[0] == 'N'){
        nextfit();
    }

    else if(selector[0] == 'W'){
        worstfit();
    }

    else if (selector[0] == 'B'){
        bestfit();
    }

    else if(selector[0] == 'F'){
        firstfit();
    }

    else{
        printf("Invalid Format");
    }
}
