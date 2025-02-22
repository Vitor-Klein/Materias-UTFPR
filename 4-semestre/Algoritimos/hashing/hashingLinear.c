#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

int hashArray[SIZE];

int hashCode(int key)
{
  return key % SIZE;
}

bool insert(int key)
{
  int hashIndex = hashCode(key);

  for (int i = 0; i < SIZE; i++)
  {
    if (hashArray[hashIndex] == EMPTY || hashArray[hashIndex] == DELETED)
    {
      hashArray[hashIndex] = key;
      return true;
    }

    hashIndex = (hashIndex + 1) % SIZE;
  }

  return false; // Tabela está cheia
}

bool search(int key)
{
  int hashIndex = hashCode(key);

  for (int i = 0; i < SIZE; i++)
  {
    if (hashArray[hashIndex] == key)
    {
      return true;
    }
    else if (hashArray[hashIndex] == EMPTY)
    {
      return false;
    }

    hashIndex = (hashIndex + 1) % SIZE;
  }

  return false;
}

bool delete(int key)
{
  int hashIndex = hashCode(key);

  for (int i = 0; i < SIZE; i++)
  {
    if (hashArray[hashIndex] == key)
    {
      hashArray[hashIndex] = DELETED;
      return true;
    }
    else if (hashArray[hashIndex] == EMPTY)
    {
      return false;
    }

    hashIndex = (hashIndex + 1) % SIZE;
  }

  return false;
}

void display()
{
  for (int i = 0; i < SIZE; i++)
  {
    if (hashArray[i] != EMPTY && hashArray[i] != DELETED)
    {
      printf(" %d", hashArray[i]);
    }
    else
    {
      printf(" ~~ ");
    }
  }
  printf("\n");
}

int main()
{
  for (int i = 0; i < SIZE; i++)
  {
    hashArray[i] = EMPTY;
  }

  insert(16);
  insert(23);
  insert(41);
  insert(21);
  insert(25);
  insert(39);
  insert(11);
  display();
  delete (41);
  delete (23);
  delete (25);
  display();
  if (search(11))
    printf("\nachou\n");
  else
    printf("\nnao achou\n");
  insert(34);

  display();

  return 0;
}
