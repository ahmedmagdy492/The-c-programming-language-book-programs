#pragma once

#define NKEY (sizeof keywords / sizeof(struct keyword_count))

struct keyword_count {
  char* word;
  int count;
} keywords[] = {
  { "auto", 0 },
  { "case", 0 },
  { "char", 0 },
  { "double", 0 },
  { "else", 0 },
  { "float", 0 },
  { "if", 0 },
  { "int", 0 },
  { "long", 0 },
  { "unsigned", 0 },
  { "voltaile", 0 },
  { "void", 0 }
};
