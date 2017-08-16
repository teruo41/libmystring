#include <stdio.h>

void* __mymemcpy (void *_d, const void *_s, size_t len)
{
  char* s = (char*)_s;
  char* d = (char*)_d;

  int i;
  for (i=0; i<len; i++)
    d[i] = s[i];

  return _d;
}

void* __mymemset (void *_d, int _ch, size_t len)
{
  char *d = (char*)_d;

  int i;
  for (i=0; i<len; i++)
    d[i] = _ch;

  return _d;
}

int __mystrcmp(const char* s1, const char* s2)
{
  const unsigned char *p1 = ( const unsigned char * )s1;
  const unsigned char *p2 = ( const unsigned char * )s2;

  while ( *p1 && *p1 == *p2 ) ++p1, ++p2;

  return ( *p1 > *p2 ) - ( *p2  > *p1 );
}

char* strtok(char *str, const char* delim) {
  static char* _buffer;
  if(str != NULL) _buffer = str;
  if(_buffer[0] == '\0') return NULL;

  char *ret = _buffer, *b;
  const char *d;

  for(b = _buffer; *b !='\0'; b++) {
    for(d = delim; *d != '\0'; d++) {
      if(*b == *d) {
        *b = '\0';
        _buffer = b+1;

        // skip the beginning delimiters
        if(b == ret) { 
          ret++; 
          continue; 
        }
        return ret;
      }
    }
  }
  
  _buffer = b;
  return ret;
}
