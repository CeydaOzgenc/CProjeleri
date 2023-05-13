#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Veriler{
    char plaka[10];
    char model[15];
    char renk[15];
};
struct Veriler veri[1000];
int islem,sinir=5,sa[1000],dk[1000],sn[1000];
time_t t;
struct tm *zmn;
void AracEkle(){
    time(&t);
    zmn = localtime(&t);
    sa[sinir]=zmn->tm_hour;
    dk[sinir]=zmn->tm_min;
    sn[sinir]=zmn->tm_sec;
    printf("************************* \n\t ARAC EKLE \t\n*************************\n     PLAKA :   ");
    scanf("%s",&veri[sinir].plaka);
    printf("\n     MODEL :   ");
    scanf("%s",&veri[sinir].model);
    printf("\n     RENK  :   ");
    scanf("%s",&veri[sinir].renk);
    printf("\n     SAAT  :   %d:%d:%d\r\n*************************\n",sa[sinir], dk[sinir], sn[sinir]);
    sinir++;
}
void AraclariListele(){
    printf("*************************************************************** \n\t\t\      ARACLARI LISTELE \t\n***************************************************************\n      PLAKA\t     MODEL\t     RENK\t     SAAT\n*************************************************************** \n");
    for(int i=0;i<sinir;i++){
        printf("\n      %s\t     %s\t     %s\t     %d:%d:%d\n",veri[i].plaka,veri[i].model,veri[i].renk,sa[i], dk[i], sn[i]);
    }
    printf("*************************************************************** \n");
}
void Islem(){
    printf("ARAC EKLE : 1 - ARACLARI LISTELE : 2 - CIKIS : 3 \nYUKARIDAN ISLEM NUMARANIZI GIRIN \t     : ");
    scanf("%d",&islem);
    switch(islem){
        case 1: if(sinir<1000){AracEkle();}else{printf("\nArac kapasiteniz dolmustur!!\n\n");} break;
        case 2: AraclariListele(); break;
        case 3: exit(EXIT_SUCCESS); break;
        default : printf("\nIsleminiz hatali lutfen tekrar deneyin!!\n\n"); break;
    }
    Islem();
}
int main(){
    strcpy(veri[0].plaka,"35CDO303"); strcpy(veri[0].model,"MERCEDES"); strcpy(veri[0].renk,"KIRMIZI"); sa[0]=12;  dk[0]=30; sn[0]=15;
    strcpy(veri[1].plaka,"35SDR997"); strcpy(veri[1].model,"BMM"); strcpy(veri[1].renk,"SIYAH"); sa[1]=12;  dk[1]=30; sn[1]=15;
    strcpy(veri[2].plaka,"34SM3592"); strcpy(veri[2].model,"AUDI"); strcpy(veri[2].renk,"SARI"); sa[2]=12;  dk[2]=30; sn[2]=15;
    strcpy(veri[3].plaka,"45SC9897"); strcpy(veri[3].model,"FERRAR"); strcpy(veri[3].renk,"MAVI"); sa[3]=12;  dk[3]=30; sn[3]=15;
    strcpy(veri[4].plaka,"25SS9290"); strcpy(veri[4].model,"JEEP"); strcpy(veri[4].renk,"GRI"); sa[4]=12;  dk[4]=30; sn[4]=15;
    AraclariListele();
    Islem();
}
