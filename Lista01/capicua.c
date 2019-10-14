#include <stdio.h>

int main(){
    int u, d, c, m, result, i, n;
    int v[n];

    scanf("%d", &n);

    for (i=0; i<n; i++){
      scanf("%d", &v[i]);
    }

    for (i=0; i<n; i++){
      if (v[i] > 999) {
        u = v[i] / 1000 ;   
        d = (v[i]/ 100) - ( u * 10 ) ; 
        c = (v[i]/10) - (d *10)  - (u * 100); 
        m = v[i] - (u *1000) - (d * 100) - (c * 10);
        result = (m* 1000) + (c*100) + (d*10) + u;
      } else if (v[i] > 99 &&  v[i] < 1000 ) {
        u = v[i]/ 100 ;   
        d = (v[i]/10) - (u *10);
        c = v[i] - (d * 10) - (u * 100);
        result = (c*100) + (d*10) + u;
      } else if (v[i] > 9 || v[i] < 100){ 
        u =  (v[i]/10) ;
        d =  v[i] - (u * 10);
        result =  (d*10) + u;
      }

      if (result == v[i]) {
        printf("yes ");
      } else {  
        printf("no ");
      }
    
    }
    return 0;
}
