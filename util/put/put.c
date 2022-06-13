#include "put.h"

char* getDivider(){
    char* _line = malloc(sizeof(char) * 255);
    for(register int i = 0; i < 150; i++){
        _line[i] = '-';
    }
    _line[255] = '\0';
    return _line;
}

void showCustomBlockingMessage(char *msg)
{
  printf("%s\n", msg);
  getchar();
  getchar();
}

void showBlockingMessage()
{
  printf("%s", PRESS_ANY_KEY_TO_CONTINUE);
  getchar();
  getchar();
}
