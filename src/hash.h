#ifndef HASHMAP_H
#define HASHMAP_H

struct node {
    char *key;
    char *bairro;
    char *logradouro;
    char *cep;
    struct node *next;
};

struct hashmap {
    struct node *array[100];
};


struct node *createNode(char *key, char *cep, char *bairro, char *logradouro);
void insert(struct hashmap *map, char *cep, char *bairro, char *logradouro);
void removeNode(struct hashmap *map, char *cep);
void update(struct hashmap *map, char *cep, char *bairro, char *logradouro);
void printNode(struct node *node);
void printMap(struct hashmap *map);

#endif /* HASHMAP_H */
