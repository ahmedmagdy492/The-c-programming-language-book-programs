
#define MAX_LEN 100

int arr[MAX_LEN] = {0};

static int hash(char* s) {
  int index = 0;
  
  while(*s != '\0') {
    index += *s;
    ++s;
  }

  return (index % MAX_LEN);
}

int has_key(char* key) {
  if(arr[hash(key)] == 0)
    return 0;
  return 1;
}

int get(char* key) {
  return arr[hash(key)];
}

void set(char* key, int value) {
  arr[hash(key)] = value;
}
