#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main(){

  int n, i, j, cont, casos;
  char palavra[1000];

  scanf("%d", &casos);

  int res[casos];

  getchar();
  for(i=0; i<casos; i++){
    
    fgets(palavra, 1000, stdin);

    cont = 0;
    for(j=0; j<strlen(palavra); j++){
      
      palavra[j] = tolower(palavra[j]);

      if(palavra[j] == 'a' || palavra[j] == 'e' || palavra[j] == 'i' || palavra[j] == 'o' || palavra[j] == 'u'){
        cont++;
      }
    }

    res[i] = cont;
  }

  for(i=0; i<casos; i++){
    printf("%d\n", res[i]);
  }
 
  return 0;
}