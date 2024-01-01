#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#define HASH_SIZE 1000

#define INVALID_TYPE -1
#define INT 1
#define FLOAT 2
#define CHARPTR 3

union tag {
  int ival;
  float fval;
  char* sval;
};

struct nlist {
  char *name;
  int utype;
  union tag defn;
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

static int get_type(char* val, union tag* tag) {
  if(isdigit(*val) && strstr(val, ".") != NULL) {
    tag->fval = strtof(val, NULL);
    return FLOAT;
  }
  else if(isalpha(*val)) {
    memcpy(tag->sval, val, strlen(val));
    return CHARPTR;
  }
  else if(isdigit(*val)) {
    tag->ival = strtoll(val, NULL, 10);
    return INT;
  }

  return INVALID_TYPE;
}

void undef(char* name) {
  uint32_t index = hash(name);
  struct nlist *cur = hashtab[index], *prev = NULL;

  while(cur != NULL) {
    if(strcmp(cur->name, name) == 0) {
      prev->next = cur->next;
      free(cur->name);
      free(cur->defn.sval);
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
    block->defn.sval = (char*)malloc(sizeof(char)*strlen(t)+1);
    memcpy(block->name, s, strlen(s));
    block->utype = get_type(t, &block->defn);
    block->next = hashtab[index];
    hashtab[index] = block;
  }
  else {
    free(block->defn.sval);
  }

  return block;
}
