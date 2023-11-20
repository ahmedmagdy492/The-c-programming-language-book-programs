#pragma once

static char months_days[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static inline int is_leap(int y) {
  return (y % 4) == 0;
}

void convert_doy_to_dom(int doy, int y, int* m, int* dom) {
  int index = is_leap(y), i, d = doy;

  if(index && doy > 365)
    return;

  if(!index && doy > 364)
    return;

  if(doy < 1)
    return;
    

  for(i = 0;d > 0; ++i) {
    d -= months_days[index][i];
  }

  *m = i-1;

  for(i = 0; i < *m; ++i) {
    doy -= months_days[index][i];
  }

  *dom = doy;
}

void convert_dom_to_doy(int dom, int m, int y, int *doy) {
  int i, total = 0, leap = is_leap(y);

  if(m > 12 || m < 1)
    return;

  if(dom > months_days[leap][m])
    return;

  if(dom < 1)
    return;
  
  for(i = 0; i < m; ++i) {
    total += months_days[leap][i];
  }
  *doy = total + dom;
}
