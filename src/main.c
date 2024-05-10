#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hash.h"

void printMenu(){
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Atualizar\n");
    printf("4 - Imprimir\n");
    printf("5 - Sair\n");
}
void readFromTxt(struct hashmap *map, char *filename){
    FILE *file = fopen(filename, "r");
    char cep[10], bairro[100], logradouro[100];
    while(fscanf(file, "%s %s %s", cep, bairro, logradouro) != EOF){
        if(cep[0] == '\0' || bairro[0] == '\0' || logradouro[0] == '\0'){
            break;
        }
        insert(map, cep, bairro, logradouro);
    }
    fclose(file);
}

int main(int argc, char *argv[]){
    char* path="";
    struct hashmap *map = (struct hashmap *)malloc(sizeof(struct hashmap));
    if(argc == 1){
        printf("Digite o caminho do arquivo: ");
        scanf("%s", path);
    }

    if(argc > 1){
        path = argv[1];
    }	

    readFromTxt(map, path); 

    int op;
    char cep[10], bairro[100], logradouro[100];
    while(1){
        printMenu();
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite o cep: ");
                scanf("%s", cep);
                printf("Digite o bairro: ");
                scanf("%s", bairro);
                printf("Digite o logradouro: ");
                scanf("%s", logradouro);
                insert(map, cep, bairro, logradouro);
                break;
            case 2:
                printf("Digite o cep: ");
                scanf("%s", cep);
                removeNode(map, cep);
                break;
            case 3:
                printf("Digite o cep: ");
                scanf("%s", cep);
                printf("Digite o bairro: ");
                scanf("%s", bairro);
                printf("Digite o logradouro: ");
                scanf("%s", logradouro);
                update(map, cep, bairro, logradouro);
                break;
            case 4:
                printMap(map);
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}