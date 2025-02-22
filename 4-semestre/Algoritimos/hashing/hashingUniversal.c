#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define PRIME 31

typedef struct Node
{
  int key;
  struct Node *next;
} Node;

Node *hashTable[SIZE];

int a, b;

void initHashTable()
{
  for (int i = 0; i < SIZE; i++)
  {
    hashTable[i] = NULL;
  }

  a = rand() % PRIME + 1;
  b = rand() % PRIME;
}

int universalHash(int key)
{
  return ((a * key + b) % PRIME) % SIZE;
}

void insert(int key)
{
  int index = universalHash(key);

  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->next = NULL;

  if (hashTable[index] == NULL)
  {
    hashTable[index] = newNode;
  }
  else
  {
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
  }
}

bool search(int key)
{
  int index = universalHash(key);
  Node *temp = hashTable[index];

  while (temp != NULL)
  {
    if (temp->key == key)
    {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

bool deleteKey(int key)
{
  int index = universalHash(key);
  Node *temp = hashTable[index];
  Node *prev = NULL;

  while (temp != NULL)
  {
    if (temp->key == key)
    {
      if (prev == NULL)
      {

        hashTable[index] = temp->next;
      }
      else
      {

        prev->next = temp->next;
      }
      free(temp);
      return true;
    }
    prev = temp;
    temp = temp->next;
  }
  return false;
}

void display()
{
  for (int i = 0; i < SIZE; i++)
  {
    printf("Index %d: ", i);
    Node *temp = hashTable[i];
    while (temp != NULL)
    {
      printf("%d -> ", temp->key);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main()
{
  initHashTable();

  insert(10);
  insert(20);
  insert(15);
  insert(7);
  insert(30);

  printf("Tabela hash após inserções:\n");
  display();

  printf("\nBusca pela chave 15: %s\n", search(15) ? "Encontrada" : "Não encontrada");

  deleteKey(15);
  printf("\nTabela hash após remover a chave 15:\n");
  display();

  return 0;
}
