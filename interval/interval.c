#include <stdio.h>
int main ( void ){

int h,m,s,ms;
int h2,m2,s2,ms2;


    printf("%s\n","Zadejte cas t1:");
    if (scanf("%d : %d : %d , %d", &h, &m, &s, &ms) != 4 || h >=24 || m >= 60 || s >= 60 || ms >= 1000 || h <0 || m < 0 || s < 0 || ms < 0){
         printf("%s\n","Nespravny vstup.");
        return 1;
    }
    

    printf("%s\n","Zadejte cas t2:");
    if(scanf("%d : %d : %d , %d", &h2, &m2, &s2, &ms2) != 4 || h2 >= 24 ||  m2 >= 60 || s2 >= 60 || ms2 >= 1000 || h2 <0 || m2 < 0 || s2 < 0 || ms2 < 0){
        printf("%s\n","Nespravny vstup.");
        return 1;
    }


    if(h > h2 || ((h==h2) && (m > m2)) || ( (h==h2) && (m == m2) && (s > s2) ) || ((h==h2) && (m == m2) && (s == s2) && (ms > ms2) ) ){
        printf("%s\n","Nespravny vstup.");
        return 1;
    }

    if (ms > ms2){
        ms = 1000 - (ms - ms2);
        s = s+1;
    }
    else{
        ms = (ms2-ms);
    }

    if (s > s2){
        s = 60 - (s-s2);
        m = m+1;
    }
    else{
        s = (s2-s);
    }

    if (m > m2){
        m = 60 - (m - m2);
        h = h+1;
    }
    else{
        m = (m2-m);
    }
    
    h = (h2-h);
  

   
    printf("%s: %2d:%02d:%02d,%03d\n", "Doba", h,m,s,ms);
}

