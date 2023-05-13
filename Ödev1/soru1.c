#include <stdio.h>
#include <stdlib.h>
int main(){
    int sayilar[10],sayilarTek[10],sayilarCift[10],tek=0,cift=0;
    int *sayilarPtr=&sayilar,*sayilarTekPtr=&sayilarTek,*sayilarCiftPtr=&sayilarCift;
    srand(time(NULL));
    for(int i=0; i<10;i++){
        sayilarPtr[i]=1+rand()%100;
        if(sayilar[i]%2==0){
           sayilarCiftPtr[cift]=sayilarPtr[i];
           cift++;
        }
        else{
           sayilarTekPtr[tek]=sayilarPtr[i];
           tek++;
        }
    }
    printf("\n CIFT SAYILAR \t TEK SAYILAR");
    for(int a=0;a<10;a++){
        if(a<cift){
            printf("\n %d",sayilarCiftPtr[a]);
        }
        else{printf("\n");}
        if(a<tek){
            printf("\t\t %d",sayilarTekPtr[a]);
        }
    }
}
