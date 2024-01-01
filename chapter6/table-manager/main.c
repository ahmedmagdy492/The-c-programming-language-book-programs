#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "extract_word.h"
#define NWORD 100

int main(int argc, char** argv) {
  if(argc == 2) {
    char word[NWORD], name[NWORD];
    struct nlist* defn = NULL;
    int in_micro_proc = 0, name_set = 0;
    
    while(extract_next_word(argv[1], word) != NULL) {
      if(word[0] == '#') {
	in_micro_proc = 1;
      }
      else if(in_micro_proc && !name_set) {
	memset(name, 0, NWORD);
	strncpy(name, word, strlen(word));
	name_set = 1;
      }
      else if(in_micro_proc && name_set) {
	install(name, word);
	struct nlist* assigned_name = lookup(name);
	switch(assigned_name->utype) {
	case INT:
	  printf("Type int:\n");
	  printf("installing %s => %d\n", name, assigned_name->defn.ival);
	  break;
	case FLOAT:
	  printf("Type float:\n");
	  printf("installing %s => %2f\n", name, assigned_name->defn.fval);
	  break;
	case CHARPTR:
	  printf("Char ptr type:\n");
	  printf("installing %s => %s\n", name, assigned_name->defn.sval);
	  break;
	default:
	  printf("Invalid type detected\n");
	}
	in_micro_proc = 0;
	name_set = 0;
      }
    }
  }
  else {
    printf("Usage: %s <str>\n", argv[0]);
    return 1;
  }

  return 0;
}
