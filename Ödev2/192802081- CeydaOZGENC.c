#include <stdio.h>
#include <stdlib.h>
int *matris,stn,str,bul;
void Dinamik(){
    printf("Matris satir boyutunu giriniz : ");
    scanf("%d", &str);
    printf("Matris sutun boyutunu giriniz : ");
    scanf("%d", &stn);
    matris=(int *)malloc(sizeof(int)*(stn*str));
    Eleman();
}
void Eleman(){
    srand(time(NULL));
    int tut=0;
    for(int i=0;i<(stn*str);i++){
        matris[i]=5+rand()%40000;
    }
    for (int x=1;x<(stn*str);x++){
        for (int y=1;y<(stn*str);y++){
            if(matris[y-1]>matris[y]){
                tut=matris[y-1];
                matris[y-1]=matris[y];
                matris[y]=tut;
            }
        }
    }
    Transpoze();
}
void Transpoze(){
    int z;
    FILE *data,*database;
    data=fopen("transpoze.txt","w+");
    database=fopen("kaprekar.txt","w+");
    fprintf(data," Matris\n\n");
    for(int x=0; x<str;x++){
        for(int y=0;y<stn;y++){
            fprintf(data," %d ",matris[y+z]);
        }
        fprintf(data,"\n");
        z=z+stn;
    }
    fprintf(data,"\n\n Transpoze\n\n");
    for(int i=0;i<stn;i++){
        for(int j=0;j<(stn*str);j++){
            if(j%stn==i){
                Kaprekar(matris[j],database);
                fprintf(data," %d ",matris[j]);
            }
        }
        fprintf(data,"\n");
    }
    fclose(data);
    fclose(database);
    printf("\nYazdirma islemi tamamlandi!");
    if(bul==0)printf("\nKaprekar sayisi yok!");
}
void Kaprekar(int transpoze,FILE *database){
    int kaprekar,uzunluk=1,ayir=1;
    kaprekar=transpoze*transpoze;
    uzunluk=0;
    for(int x=1000000000;x>=1;x/=10){
        if(kaprekar>x)uzunluk++;
        if(uzunluk%2==0 && uzunluk!=0) ayir*=10;
    }
    if((transpoze==(kaprekar/ayir)+(kaprekar%ayir) || transpoze==(kaprekar/(ayir*10))+(kaprekar%(ayir*10))) && kaprekar%ayir!=0){
        fprintf(database,"%d\n",transpoze);
        bul++;
    }
    else{
        for(int y=0;y<uzunluk/2;y++){
            if((kaprekar/ayir)%10==0){
                if(transpoze==(kaprekar/ayir)+(kaprekar%ayir) && kaprekar%ayir!=0){
                    fprintf(database,"%d\n",transpoze);
                    bul++;
                }
            }
        }
    }
}
int main()
{
    Dinamik();
}
