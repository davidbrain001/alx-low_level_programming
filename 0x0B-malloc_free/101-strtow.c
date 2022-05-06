#include "main.h"

/**
 * strtow - splits a string into words
 * @str: string of words to be split
 * Return: double pointer to strings
 */

void main()
{
  int i;
  int myargc = 1;
  char *myargv[256];
  char buff[100];
  int len = 0;
  char string[256];
  int j = 0;

  printf("Enter text: ");
  gets(buff);

  for(i = 0; buff[i] != '\0'; i++){
    len++;
  }

  for(i = 0; i < len; i++)
    {
      if(buff[i]!=' ' && buff[i+1]==' ')
        {
	  myargc++;
        }
    }
  printf("myargc %d\n",myargc);
  **for(i = 0; i < len; i++){
    if(buff[i] != ' '){
      string[j++] = buff[i];
    }
    if(buff[i] != ' ' && buff[i] == ' '){
      string[j++] = '\0';
      j = 0;
    }
    if(buff[i] == '\0'){
      break;
    }
  }**
     for(i = 0; i < myargc - 1; i++){
       myargv[i] = string;
       printf("argv[%d]\t%s\n", i, myargv[i]);
     }
}
