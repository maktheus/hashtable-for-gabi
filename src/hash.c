#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    char *key;
    char *bairro;
    char *logradouro;
    char *cep;
    struct node *next;
};

struct hashmap{
    //set null
    struct node *array[100];
};



int hash(char *key){
    int hash = 0;
    for(int i = 0; i < strlen(key); i++){
        hash += key[i];
    }
    return hash % 100;
}

struct node *createNode(char *key,char *cep, char *bairro, char *logradouro){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->bairro = bairro;
    newNode->logradouro = logradouro;
    newNode->cep = cep;
    newNode->next = NULL;
    return newNode;
}


void insert(struct hashmap *map,  char *cep, char *bairro, char *logradouro){
    int index = hash(cep);
    if(map->array[index] == NULL){
        map->array[index] = createNode(cep, cep, bairro, logradouro);
    }else{
        struct node *temp = map->array[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = createNode(cep, cep, bairro, logradouro);
    }
}

struct node *get(struct hashmap *map, char *cep){
    int index = hash(cep);
    struct node *temp = map->array[index];
    while(temp != NULL){
        if(strcmp(temp->cep, cep) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void removeNode(struct hashmap *map, char *cep){
    int index = hash(cep);
    struct node *temp = map->array[index];
    struct node *prev = NULL;
    while(temp != NULL){
        if(strcmp(temp->cep, cep) == 0){
            if(prev == NULL){
                map->array[index] = temp->next;
            }else{
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void update(struct hashmap *map, char *cep, char *bairro, char *logradouro){
    int index = hash(cep);
    struct node *temp = map->array[index];
    while(temp != NULL){
        if(strcmp(temp->cep, cep) == 0){
            temp->bairro = bairro;
            temp->logradouro = logradouro;
            return;
        }
        temp = temp->next;
    }
}

void printNode(struct node *node){
    if(node == NULL){
        printf("No node found\n");
    }else{
        printf("Key: %s\n", node->key);
        printf("Bairro: %s\n", node->bairro);
        printf("Logradouro: %s\n", node->logradouro);
        printf("Cep: %s\n", node->cep);
    }
}


void printMap(struct hashmap *map){
    for(int i = 0; i < 100; i++){
        struct node *temp = map->array[i];
        while(temp != NULL){
            printf("Index: %d\n", i);
            printNode(temp);
            temp = temp->next;
        }
    }
}





