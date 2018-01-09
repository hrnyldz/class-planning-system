#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100


struct Ogr
{
    char Ogrenci_Ad[20];
    char Ogrenci_Soyad[20];
    char Ogrenci_Numara[8];
    int  Ogrenci_kayits;
    char Ogrenci_ogrtur[2];
    struct Ogr *next;

};


int main()
{
    time_t basla,son;
    time(&basla);
    //basla=time(NULL);
    printf("Ogrenci kayit sistemine hosgeldiniz...:)\n");
    int toplam_ogrsay;
    int I_ogrsayi=0;
    int II_ogrsayi=0;
    FILE *dosya;
    dosya = fopen("kirklik.txt","r");
    struct Ogr *dugum;
    dugum=malloc(sizeof(struct Ogr));

    struct Ogr *dugum_temp;
    dugum_temp=dugum;
    char satir[100];

    int p=0;
       while(fgets(satir,100,dosya)!= NULL)
        {
            //ilk satiri almamak için i=1 ve sonralari icin okuma
            if(p>=1)
            {   dugum_temp->next=malloc(sizeof(struct Ogr)); // ilk eleman döngü d???nda olu?turuldu?u için önce atama yap?l?p sonra haf?zadan yer al?n?yor.
                sscanf(satir, "%s %s %s %d %s",dugum_temp->Ogrenci_Numara, dugum_temp->Ogrenci_Ad, dugum_temp->Ogrenci_Soyad, &dugum_temp->Ogrenci_kayits, dugum_temp->Ogrenci_ogrtur);
                dugum_temp=dugum_temp->next;
            }
            p++;
        }
        dugum_temp=NULL;
        toplam_ogrsay=p-1;
        printf("Dosya %d ogrenci bilgisi icermektedir.\n",toplam_ogrsay);
        dugum_temp=dugum;    //link list'imiz tek yönlü oldu?u için i?lemlerden sonra yede?imizin yine ilk eleman? göstermesini sa?lar?z.

        time_t baslaOgrSil,sonOgrSil;
        time(&baslaOgrSil);

        struct Ogr *dugum_temp_temp;
        dugum_temp_temp=dugum;
        while(dugum_temp->next->next!=NULL)   //Bu döngüdeki amaç en son fazladan al?nnan 2 eleman?n silinmesi.
        {
            int sayi=0;// sayi degiskeni sayac görevi ustlenir
            while(strcmp((dugum_temp->Ogrenci_Ad),(dugum_temp->next->Ogrenci_Ad))==0 && strcmp((dugum_temp->Ogrenci_Soyad),(dugum_temp->next->Ogrenci_Soyad))==0)
            {
                struct Ogr *temp;
                temp=dugum_temp->next->next;
                free(dugum_temp->next);
                dugum_temp->next=temp;
                sayi++;
            }


            while(dugum_temp_temp->next!=NULL && sayi!=0)
            {

                if(dugum_temp_temp->Ogrenci_kayits > dugum_temp->Ogrenci_kayits)
                {
                    dugum_temp_temp->Ogrenci_kayits-=sayi;
                }
                dugum_temp_temp=dugum_temp_temp->next;
            }
            if(sayi!=0)
            {
                printf("%s %s %d defa kaydedilmistir!\n",dugum_temp->Ogrenci_Ad,dugum_temp->Ogrenci_Soyad,sayi+1);
            }
            toplam_ogrsay-=sayi;
            dugum_temp_temp=dugum;
            dugum_temp=dugum_temp->next;

        }

        time(&sonOgrSil);

        printf("Dosya guncellenmistir.Ayny kayitlar silinmistir.\n");
        printf("Dosya %d ogrenci bilgisi icermektedir.\n",toplam_ogrsay);

        free(dugum_temp->next);
        dugum_temp=NULL;
        free(dugum_temp);   //Son iki eleman silindi.
        dugum_temp=dugum;
        dugum_temp_temp=dugum;
        while(dugum_temp->next!=NULL)
        {
            if(strcmp(dugum_temp->Ogrenci_Numara,"-")==0)
            {
                char gecicidizi[4];
                sprintf(gecicidizi,"%d",dugum_temp->Ogrenci_kayits);

                //Iogr->next=NULL;
                 if(strcmp(dugum_temp->Ogrenci_ogrtur,"II")==0)
                {
                    if(dugum_temp->Ogrenci_kayits<10){
                     strcpy(dugum_temp->Ogrenci_Numara,"170200");
                     strcat(dugum_temp->Ogrenci_Numara,gecicidizi);
                    }
                    else if (dugum_temp->Ogrenci_kayits<100&&dugum_temp->Ogrenci_kayits>=10){
                     strcpy(dugum_temp->Ogrenci_Numara,"17020");
                     strcat(dugum_temp->Ogrenci_Numara,gecicidizi);
                    }
                    else if (dugum_temp->Ogrenci_kayits>=100){
                     strcpy(dugum_temp->Ogrenci_Numara,"1702");
                     strcat(dugum_temp->Ogrenci_Numara,gecicidizi);
                    }

                    II_ogrsayi++;


                }
                else if(strcmp(dugum_temp->Ogrenci_ogrtur,"I")==0)
                {
                    if(dugum_temp->Ogrenci_kayits<10){
                     strcpy(dugum_temp->Ogrenci_Numara,"170100");
                     strcat(dugum_temp->Ogrenci_Numara,gecicidizi);
                    }
                    else if (dugum_temp->Ogrenci_kayits<100&&dugum_temp->Ogrenci_kayits>=10){
                     strcpy(dugum_temp->Ogrenci_Numara,"17010");
                     strcat(dugum_temp->Ogrenci_Numara,gecicidizi);
                    }
                    else if(dugum_temp->Ogrenci_kayits>=100){
                     strcpy(dugum_temp->Ogrenci_Numara,"1701");
                     strcat(dugum_temp->Ogrenci_Numara,gecicidizi);
                    }

                    I_ogrsayi++;

                }
            }
            dugum_temp=dugum_temp->next;
        }
        dugum_temp=dugum;


        while(dugum_temp->next->next!=NULL)
        {
            dugum_temp_temp=dugum;
            while(dugum_temp_temp->next->next!=NULL)
            {

                if(strcmp(dugum_temp_temp->Ogrenci_Numara,dugum_temp_temp->next->Ogrenci_Numara)>0)
                {
                    char dizi[20];
                                                    //char Ogrenci_Numara[8];
                    strcpy(dizi,dugum_temp_temp->Ogrenci_Numara);
                    strcpy(dugum_temp_temp->Ogrenci_Numara,dugum_temp_temp->next->Ogrenci_Numara);
                    strcpy(dugum_temp_temp->next->Ogrenci_Numara,dizi);

                                                    //char Ogrenci_Ad[20];
                    strcpy(dizi,dugum_temp_temp->Ogrenci_Ad);
                    strcpy(dugum_temp_temp->Ogrenci_Ad,dugum_temp_temp->next->Ogrenci_Ad);
                    strcpy(dugum_temp_temp->next->Ogrenci_Ad,dizi);

                                                        //char Ogrenci_Soyad[20];
                    strcpy(dizi,dugum_temp_temp->Ogrenci_Soyad);
                    strcpy(dugum_temp_temp->Ogrenci_Soyad,dugum_temp_temp->next->Ogrenci_Soyad);
                    strcpy(dugum_temp_temp->next->Ogrenci_Soyad,dizi);

                                                        //char Ogrenci_ogrtur[2];
                    strcpy(dizi,dugum_temp_temp->Ogrenci_ogrtur);
                    strcpy(dugum_temp_temp->Ogrenci_ogrtur,dugum_temp_temp->next->Ogrenci_ogrtur);
                    strcpy(dugum_temp_temp->next->Ogrenci_ogrtur,dizi);

                                                        //int Ogrenci_kayits;
                    int k_dizi=dugum_temp_temp->Ogrenci_kayits;
                    dugum_temp_temp->Ogrenci_kayits=dugum_temp_temp->next->Ogrenci_kayits;
                    dugum_temp_temp->next->Ogrenci_kayits=k_dizi;
                }
                dugum_temp_temp=dugum_temp_temp->next;

            }
            dugum_temp=dugum_temp->next;
        }

        dugum_temp=dugum;
        dugum_temp_temp=dugum;
 while(dugum_temp->next!=NULL)
    {
        printf("\nOgrenci_Numara=%s\nOgrenci_Ad=%s\nOgrenci_Soyad=%s\nOgrenci_Kayit_Sirasi=%d\nOgrenci_Ogretim_Turu=%s\n", dugum_temp->Ogrenci_Numara, dugum_temp->Ogrenci_Ad, dugum_temp->Ogrenci_Soyad, dugum_temp->Ogrenci_kayits, dugum_temp->Ogrenci_ogrtur);

        dugum_temp=dugum_temp->next;
    }

time_t baslaSinif,sonSinif;
time(&baslaSinif);

int toplam_kapasite=0;
    int j;
    int sinif_sayisi;
    int kapasite_dizi[N];
    int x;
    if(I_ogrsayi>II_ogrsayi)
        x=I_ogrsayi;
    else
        x=II_ogrsayi;
    do{
        printf("->Sinif sayisini giriniz.\n");
    scanf("%d",&sinif_sayisi);
    for(j=0;j<sinif_sayisi;j++){
        printf("-%d. sinif sayisini giriniz.\n",j+1);
        scanf("%d",&kapasite_dizi[j]);
        toplam_kapasite+=kapasite_dizi[j];
    }

    }while(toplam_kapasite<x);

    int  sira;

    time(&sonSinif);

int i;
    for( i=0; i<sinif_sayisi-1;i++){
        for( j=i+1; j<sinif_sayisi; j++){
            if(kapasite_dizi[i] < kapasite_dizi[j]){
                sira = kapasite_dizi[i]; // Dizi[i] yi kaybetmemek için gecicide tutuyoruz
                kapasite_dizi[i] = kapasite_dizi[j]; //dizi[i] yi dizi[i] den daha kücük olan dizi[j] kaydediyoruz
                kapasite_dizi[j] = sira; // Dizi[j] ye ise dizi[i] degerini kaydediyoruz. Bu degeri gecicide saklamystyk
            }
        }
    }
    printf("1.Ogretim ogrenci sayisi : %d  ",I_ogrsayi);
    printf("2.Ogretim ogrenci sayisi : %d\n",II_ogrsayi);
int I_say=I_ogrsayi;
int II_say=II_ogrsayi;
printf("Siralanmis dizi:");

for(i=0;i<sinif_sayisi;i++){
printf("%d ",kapasite_dizi[i]);

}
int doldurulan_siniflar_I[sinif_sayisi];
printf("\nEn az sinif dagilimi :I.Ogretim ");

for(i=0;i<sinif_sayisi;i++){
    doldurulan_siniflar_I[i]=0;
    if(I_ogrsayi>=kapasite_dizi[i]){
        doldurulan_siniflar_I[i]=kapasite_dizi[i];
        I_ogrsayi=I_ogrsayi-doldurulan_siniflar_I[i];

    }
    else if(I_ogrsayi<kapasite_dizi[i]){
    doldurulan_siniflar_I[i]=I_ogrsayi;
    I_ogrsayi=I_ogrsayi-doldurulan_siniflar_I[i];

}
    else if(I_ogrsayi<0){
        doldurulan_siniflar_I[i]=0;
    }
    else
        break;
}

for(i=0;i<sinif_sayisi;i++){
printf("%d ",doldurulan_siniflar_I[i]);
}
int doldurulan_siniflar_II[sinif_sayisi];
for(i=0;i<sinif_sayisi;i++){
    doldurulan_siniflar_II[i]=0;
    if(II_ogrsayi>=kapasite_dizi[i]){
        doldurulan_siniflar_II[i]=kapasite_dizi[i];
        II_ogrsayi=II_ogrsayi-doldurulan_siniflar_II[i];

    }
    else if(II_ogrsayi<kapasite_dizi[i]){
    doldurulan_siniflar_II[i]=II_ogrsayi;
    II_ogrsayi=II_ogrsayi-doldurulan_siniflar_II[i];

}
    else if(II_ogrsayi<0){
        doldurulan_siniflar_II[i]=0;
    }
    else
        break;
}
printf("II.Ogretim : ");
for(i=0;i<sinif_sayisi;i++){
printf("%d ",doldurulan_siniflar_II[i]);
}

/**yazma*/
//**enaz dagylym*/
int k=1;
char data[200];
char buffer[32];
char q[10];
FILE *file;
int degisken;
dugum_temp=dugum;

for(i=0;i<sinif_sayisi;i++){
    snprintf(buffer,sizeof(char)*32,"I.Ogretim %i.Sinif Enaz.txt",k);
    file=fopen(buffer,"wb");
    degisken=doldurulan_siniflar_I[i];

    if(degisken!=0){
            for(j=0;j<=degisken;j++){
                    if(strcmp(dugum_temp->Ogrenci_ogrtur,"I")==0){
                        strcpy(data,"");
                        strcat(data,dugum_temp->Ogrenci_Numara);
                        strcat(data," ");
                        strcat(data,dugum_temp->Ogrenci_Ad);
                        strcat(data," ");
                        strcat(data,dugum_temp->Ogrenci_Soyad);
                        strcat(data," ");
                        sprintf(q, "%d", dugum_temp->Ogrenci_kayits);
                        strcat(data,q);
                        strcat(data," ");
                        strcat(data,dugum_temp->Ogrenci_ogrtur);
                        strcat(data,"\n");
                        fwrite(data,1,strlen(data),file);
                    }
                    else{
                        j--;
                    }
                    dugum_temp=dugum_temp->next;
            }

    }

k++;
}



k=1;
strcpy(data,"");
strcpy(buffer,"");
strcpy(q,"");
dugum_temp=dugum;

degisken=0;
for(i=0;i<sinif_sayisi;i++){
    snprintf(buffer,sizeof(char)*32,"II.Ogretim%i.Sinif Enaz.txt",k);
    file=fopen(buffer,"wb");
    degisken=doldurulan_siniflar_II[i];
    if(degisken!=0 ){
        for(j=0;j<=degisken;j++){
            if(!strcmp(dugum_temp->Ogrenci_ogrtur,"II")){
                strcpy(data,"");
                strcat(data,dugum_temp->Ogrenci_Numara);
                strcat(data," ");
                strcat(data,dugum_temp->Ogrenci_Ad);
                strcat(data," ");
                strcat(data,dugum_temp->Ogrenci_Soyad);
                strcat(data," ");
                sprintf(q, "%d", dugum_temp->Ogrenci_kayits);
                strcat(data,q);
                strcat(data," ");
                strcat(data,dugum_temp->Ogrenci_ogrtur);
                strcat(data,"\n");
                fwrite(data,1,strlen(data),file);
            }
            else{
                j--;
            }
            dugum_temp=dugum_temp->next;
        }

    }
k++;
}
/**esit dagylym*/

//kapasiteler

int sayac=0;
int ortalama=(I_say/sinif_sayisi);
int doldurulan_siniflar_I_esit[sinif_sayisi];
for(i=0;i<sinif_sayisi;i++){
    if(kapasite_dizi[i]<ortalama){
        doldurulan_siniflar_I_esit[i]=kapasite_dizi[i];
        I_say-=kapasite_dizi[i];
        sayac++;
    }
    else
        doldurulan_siniflar_I_esit[i]=0;
}


while(I_say>0){
   for(i=0;i<sinif_sayisi-sayac;i++){
    if(kapasite_dizi[i]>=doldurulan_siniflar_I[i]){
        doldurulan_siniflar_I_esit[i]++;
    }
    I_say--;
}

}
printf("\nEsit dagilim I Ogretim:");
for(i=0;i<sinif_sayisi;i++)
printf(" %d",doldurulan_siniflar_I_esit[i]);





sayac=0;
ortalama=(II_say/sinif_sayisi);
int doldurulan_siniflar_II_esit[sinif_sayisi];
for(i=0;i<sinif_sayisi;i++){
    if(kapasite_dizi[i]<ortalama){
        doldurulan_siniflar_II_esit[i]=kapasite_dizi[i];
        II_say-=kapasite_dizi[i];
        sayac++;
    }
    else
        doldurulan_siniflar_II_esit[i]=0;
}


while(II_say>0){
   for(i=0;i<sinif_sayisi-sayac;i++){
    if(kapasite_dizi[i]>=doldurulan_siniflar_I[i]){
        doldurulan_siniflar_II_esit[i]++;
    }
    II_say--;
}

}
printf("  II Ogretim:");
for(i=0;i<sinif_sayisi;i++)
    printf(" %d",doldurulan_siniflar_II_esit[i]);

k=1;
strcpy(data,"");
strcpy(buffer,"");
strcpy(q,"");
dugum_temp=dugum;

for(i=sinif_sayisi-1;i>=0;i--){
    snprintf(buffer,sizeof(char)*32,"I.Ogretim%i.Sinif Esit.txt",k);
    file=fopen(buffer,"wb");
    degisken=doldurulan_siniflar_I_esit[i];
    if(degisken!=0 ){
        for(j=0;j<=degisken;j++){
            if(strcmp(dugum_temp->Ogrenci_ogrtur,"II")==0){

                    strcpy(data,"");
                    strcat(data,dugum_temp->Ogrenci_Numara);
                    strcat(data," ");
                    strcat(data,dugum_temp->Ogrenci_Ad);
                    strcat(data," ");
                    strcat(data,dugum_temp->Ogrenci_Soyad);
                    strcat(data," ");
                    sprintf(q, "%d", dugum_temp->Ogrenci_kayits);
                    strcat(data,q);
                    strcat(data," ");
                    strcat(data,dugum_temp->Ogrenci_ogrtur);
                    strcat(data,"\n");
                    fwrite(data,1,strlen(data),file);
    }
                else{
                j--;
            }
            dugum_temp=dugum_temp->next;


            }
    }
k++;
}
k=1;
strcpy(data,"");
strcpy(buffer,"");
strcpy(q,"");
dugum_temp=dugum;

for(i=sinif_sayisi-1;i>=0;i--){
    snprintf(buffer,sizeof(char)*32,"II.Ogretim%i.Sinif Esit.txt",k);
    file=fopen(buffer,"wb");
    degisken=doldurulan_siniflar_II_esit[i];
    if(degisken!=0 ){
            for(j=0;j<=degisken;j++){
                if(strcmp(dugum_temp->Ogrenci_ogrtur,"II")==0){

                    strcpy(data,"");
                    strcat(data,dugum_temp->Ogrenci_Numara);
                    strcat(data," ");
                    strcat(data,dugum_temp->Ogrenci_Ad);
                    strcat(data," ");
                    strcat(data,dugum_temp->Ogrenci_Soyad);
                    strcat(data," ");
                    sprintf(q, "%d", dugum_temp->Ogrenci_kayits);
                    strcat(data,q);
                    strcat(data," ");
                    strcat(data,dugum_temp->Ogrenci_ogrtur);
                    strcat(data,"\n");
                    fwrite(data,1,strlen(data),file);
    }
                else{
                j--;
            }
            dugum_temp=dugum_temp->next;
            }
    }
k++;
}



time(&son);
//son=time(NULL);
printf("\nSilme calisma zamani: %6lf saniyedir.",difftime(sonOgrSil,baslaOgrSil));
printf("\nSinif calisma zamani: %6lf saniyedir.",difftime(sonSinif,baslaSinif));
printf("\nProgramin calisma zamani: %6lf saniyedir.",difftime(son,basla));


    fclose(file);

    fclose(dosya);


    return 0;
}
