#include <stdio.h>

#define min(x, y) ((x > y) ? y : x)
#define max(x, y) ((x > y) ? x : y)

struct point {
  int x;
  int y;
};

struct rect {
  struct point left;
  struct point bottom;
};

struct point makepoint(int, int);
struct point addpoints(struct point, struct point);
int ptinrect(struct rect, struct point);
struct rect canonicalrect(struct rect);

int main(void) {
  struct rect screen;
  screen.left = makepoint(12, 22);
  screen.bottom = makepoint(55, 55);
  struct point pt = { 44, 44 };

  /*int result = ptinrect(screen, pt);

  if(result)
    printf("point (%d, %d) is in rect\n", pt.x, pt.y);
  else
    printf("not in rect\n");*/

  struct point *pp;
  struct point origin;
  pp = &origin;
  printf("x = %d, y = %d\n", (*pp).x, (*pp).y);

  return 0;
}

struct point makepoint(int x, int y) {
  struct point pt = { x, y};
  return pt;
}

struct point addpoints(struct point pt1, struct point pt2) {
  pt1.x += pt2.x;
  pt1.y += pt2.y;

  return pt1;
}

int ptinrect(struct rect rec, struct point pt) {
  return pt.x >= rec.left.x && pt.x < rec.bottom.x
    && pt.y >= rec.left.y && pt.y < rec.bottom.y;
}

struct rect canonicalrect(struct rect r) {
  r.left.x = min(r.left.x, r.bottom.x);
  r.left.y = min(r.left.y, r.bottom.y);
  r.bottom.x = max(r.left.x, r.bottom.x);
  r.bottom.y = max(r.left.y, r.bottom.y);

  return r;
}
