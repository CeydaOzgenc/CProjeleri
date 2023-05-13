#include <stdio.h>
#include <stdlib.h>
int HP=100,Puzunluk,*Euzunluk,Esayi;
void engel(){
    Esayi=2+rand()%3;
    Euzunluk=(int *)malloc(sizeof(int)*Esayi);
    for(int i=1;i<Esayi+1;i++){
        if(Euzunluk[i-1]!=Euzunluk[i]){
            Euzunluk[i-1]=5+rand()%(Puzunluk-5);
        }
        else{
            i--;
        }
    }
    sirala();
}
void sirala(){
    int bak;
    for (int x=1;x<Esayi;x++){
        for (int y=1;y<Esayi;y++){
            if(Euzunluk[y-1]>Euzunluk[y]){
                bak=Euzunluk[y-1];
                Euzunluk[y-1]=Euzunluk[y];
                Euzunluk[y]=bak;
            }
        }
    }
    asal();
}
void asal(){
    FILE *data = fopen("Log.txt","w+");
    int say;
    for(int i=0;i<Esayi;i++){
        say=0;
        for(int j=2;j<=Euzunluk[i];j++){
            if(Euzunluk[i]%j==0 && HP%j==0){
                say++;
            }
        }
        yazdir(data,i,say);
    }
}
void yazdir(FILE *data,int bil,int bak){
    if(bil==0){
        fprintf(data,"Yarisma Basladi !!!\n");
        fprintf(data,"Yarismaci HP = %d\n",HP);
    }
    fprintf(data,"Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n",Euzunluk[bil]);
    if(bak==0){fprintf(data,"%d. metrede bir engel var. %d ve %d aralarinda asaldir.\n",Euzunluk[bil],HP,Euzunluk[bil]);}
    else{fprintf(data,"%d. metrede bir engel var. %d ve %d aralarinda asal degildir.\n",Euzunluk[bil],HP,Euzunluk[bil]);}
    if(bak==0){HP-=Euzunluk[bil];}
    oyunsonuc(data,bil);
}
void oyunsonuc(FILE *data,int i){
    fprintf(data,"Yarismaci HP = %d\n",HP);
    if(HP<=0){
        fprintf(data,"Uzgunum !!! Yarismayi tamamlayamadin.");
        fclose(data);
    }
    else if(i==Esayi-1){
        fprintf(data,"Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n",Puzunluk);
        fprintf(data,"Tabrikler !!! Yarismayi %d HP ile bitirdiniz.",HP);
    }
}
int main()
{
    srand(time(NULL));
    Puzunluk=50+rand()%50;
    engel();
}
