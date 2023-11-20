#define MAX_MEM 1000

static char arr[MAX_MEM];
static char* ptr = arr;

char* alloc(int n) {
  if((arr+MAX_MEM - ptr) >= n) {
    ptr += n;
    return ptr-n;
  }

  return NULL;
}

void afree(char* p) {
  if(p != NULL && p >= arr && p < (arr+MAX_MEM)) {
    ptr = p;
  }
}
