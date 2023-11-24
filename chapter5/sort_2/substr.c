
void substr(char* s, char* out, int start, int end) {
  int i = start, j = 0;

  for(; i <= end; ++i) {
    out[j++] = s[i];
  }

  out[j] = '\0';
}
