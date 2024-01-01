#include <stdint.h>

#define HASH_SIZE 1000

struct nlist {
  char *name;
  char *defn;
  struct nlist* next;
};

static struct nlist* hashtab[HASH_SIZE];

static int hash(char* s) {
  uint32_t hashvalue;

  for(hashvalue = 0; *s != '\0'; ++s) {
    hashvalue = *s + 31 * hashvalue;
  }

  return hashvalue % HASH_SIZE;
}

struct nlist* lookup(char* s) {
  uint32_t index = hash(s);
  struct nlist* ptr = hashtab[index];

  while(ptr != NULL) {
    if(strcmp(ptr->name, s) == 0) {
      return ptr;
    }
    ptr = ptr->next;
  }

  return NULL;
}

void undef(char* name) {
  uint32_t index = hash(name);
  struct nlist *cur = hashtab[index], *prev = NULL;

  while(cur != NULL) {
    if(strcmp(cur->name, name) == 0) {
      prev->next = cur->next;
      free(cur->name);
      free(cur->defn);
      free(cur);
    }
    prev = cur;
    cur = cur->next;
  }
}

struct nlist* install(char* s, char* t) {
  uint32_t index = hash(s);
  struct nlist* block, *ptr;
  
  if((ptr = lookup(s)) == NULL) {
    block = (struct nlist*)malloc(sizeof(struct nlist));
    memset(block, 0, sizeof(block));
    block->name = (char*)malloc(sizeof(char)*strlen(s)+1);
    block->defn = (char*)malloc(sizeof(char)*strlen(t)+1);
    memcpy(block->name, s, strlen(s));
    memcpy(block->defn, t, strlen(t));
    block->next = hashtab[index];
    hashtab[index] = block;
  }
  else {
    free(block->defn);
  }
  if((block->defn = strdup(t)) == NULL)
    return NULL;

  return block;
}
