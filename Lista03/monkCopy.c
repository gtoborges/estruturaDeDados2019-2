#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
  int i, j, t, count, len;
  scanf("%d", &t);
  char str[100000];
  
  for(i=0; i<t; i++) {
    scanf("%s\n", str);
    len = strlen(str);
    count = 0;
    for(j=0; j<len; j++) {
      str[j] = tolower(str[j]);
      if(str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u') {
        count++;
      }
    }
      
    printf("%d\n", count);
  }
  
  return 0;
}