#include <stdio.h>
#define DEBUG 1
#define SYSTEM "BSD"

#if SYSTEM == WIN32
#define HDR <windows.h>
#elif SYSTEM == BSD
#define HDR <unistd.h>
#endif

#include HDR

int main() {
  int i = 0;

  for(i = 0;i < 1200; ++i) {
#if defined(DEBUG)
    printf("Debug: ");
#endif
    printf("%d\n", i);
  }
}
