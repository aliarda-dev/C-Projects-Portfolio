#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Ogrenci Not Uygulamasi -(Ogrenci Notunun 0 Girilemeyecegi Varsayilmaktadir)-
typedef struct{


    char ogrenciAd[15];
    char ogrenciSoyad[20];

}ogrenciIsim;

typedef struct{

    int ogrenciNotu;

    ogrenciIsim ogrenciAS;


}ogrenciBilgi;


void menu();
void notGoruntule(int,ogrenciBilgi*);
void notGir(int,ogrenciBilgi*);


int main(void){

    int ogrenciSayi,secim;
    char buffer[10];

    FILE *fptr;

    printf("Mevcut ogrenci sayinizi tuslayiniz: ");
    fgets(buffer,sizeof(buffer),stdin);  //Buradan sonraki tum secimlerde fgets kullanma sebebimiz structlar ile beraber ayni kodda kullanildiginda crash veriyor olmasi
    ogrenciSayi=atoi(buffer);

    ogrenciBilgi* ogrenci=(ogrenciBilgi*)calloc(ogrenciSayi,sizeof(ogrenciBilgi)); //Calloc ile struct icindeki tum variablerin icini 0 veya null yapiyoruz

    for(int i=0;i<ogrenciSayi;i++){

        printf("\n%d. sirada girmek istediginiz ogrencinin ismi: ",i+1);
        fgets(ogrenci[i].ogrenciAS.ogrenciAd,sizeof(ogrenci[i].ogrenciAS.ogrenciAd),stdin);
        ogrenci[i].ogrenciAS.ogrenciAd[strcspn(ogrenci[i].ogrenciAS.ogrenciAd,"\n")]='\0'; //Burasi menude duzenin bozulmamasi icin fgets input alirken \n ekliyor, \n'i nulla ceviriyoruz


        printf("%d. sirada girmek istediginiz ogrencinin soyismi: ",i+1);
        fgets(ogrenci[i].ogrenciAS.ogrenciSoyad,sizeof(ogrenci[i].ogrenciAS.ogrenciSoyad),stdin);
        ogrenci[i].ogrenciAS.ogrenciSoyad[strcspn(ogrenci[i].ogrenciAS.ogrenciSoyad,"\n")]='\0';
    }

    do{

        menu();

        fgets(buffer,sizeof(buffer),stdin);
        secim=atoi(buffer);



        switch(secim){

            case 1: notGir(ogrenciSayi,ogrenci);
            break;

            case 2: notGoruntule(ogrenciSayi,ogrenci);
            break;

            case 3: notGir(ogrenciSayi,ogrenci);
            break;

            case 4: break;
            


            default: {

                printf("\n\nHatali tuslama yaptiniz lutfen tekrar deneyiniz!\n\n");
                continue;
            }

        }






    }while(secim!=4);


    fptr=fopen("data.txt","w");  //Burasi da data dosyamiz ad soyad ve sinav notunun bilgisayarimiza kayit edilecegi yer 

    for(int i=0;i<ogrenciSayi;i++){
        fprintf(fptr,"%s %s ----> %d\n",ogrenci[i].ogrenciAS.ogrenciAd,ogrenci[i].ogrenciAS.ogrenciSoyad,ogrenci[i].ogrenciNotu);
    }

    fclose(fptr);






free(ogrenci);

}



void menu(){

    printf("\n\n------------------------\n");
    printf("*                      *\n");
    printf("*          MENU        *\n");
    printf("*                      *\n");
    printf("*      1- Not Gir      *\n");
    printf("*   2- Not Goruntule   *\n");
    printf("*   3- Not Guncelle    *\n");
    printf("*   4-     Cikis       *\n");
    printf("*                      *\n");
    printf("------------------------\n\n");

}



void notGir(int ogrenciSayi,ogrenciBilgi* ogrenci){

    int secim;
    char gecici[10];

    printf("\n\n-----------------------\n");
    printf("     Ogrenci Seciniz    \n");
    
    for(int i=0;i<ogrenciSayi;i++){

        printf("%d- %s %s\n",i+1,ogrenci[i].ogrenciAS.ogrenciAd,ogrenci[i].ogrenciAS.ogrenciSoyad);

    }
    printf("-----------------------\n");

    fgets(gecici,sizeof(gecici),stdin);
    secim=atoi(gecici);

    printf("\n\n%s %s isimli ogrencinin notunu giriniz: ",ogrenci[secim-1].ogrenciAS.ogrenciAd,ogrenci[secim-1].ogrenciAS.ogrenciSoyad);
    fgets(gecici,sizeof(gecici),stdin);
    ogrenci[secim-1].ogrenciNotu=atoi(gecici);

    printf("\n\nNot Basarili Bir Sekilde Kaydedildi Menuye Aktariliyorsunuz...\n\n");


}


void notGoruntule(int ogrenciSayi,ogrenciBilgi* ogrenci){

    int secim;
    char gecici[10];

    printf("\n\n-----------------------\n");
    printf("     Ogrenci Seciniz    \n");
    
    for(int i=0;i<ogrenciSayi;i++){

        printf("%d- %s %s\n",i+1,ogrenci[i].ogrenciAS.ogrenciAd,ogrenci[i].ogrenciAS.ogrenciSoyad);

    }
    printf("-----------------------\n");

    fgets(gecici,sizeof(gecici),stdin);
    secim=atoi(gecici);

    if(ogrenci[secim-1].ogrenciNotu==0){
        printf("\n\nSectiginiz ogrencinin kayitli notu bulunmamaktadir!! Menuye Yonlendiriliyorsunuz\n\n");
        return ;
    }

    printf("\n%s %s isimli ogrencinin notu : %d",ogrenci[secim-1].ogrenciAS.ogrenciAd,ogrenci[secim-1].ogrenciAS.ogrenciSoyad,ogrenci[secim-1].ogrenciNotu);
    printf("\n\nMenuye Aktariliyorsunuz...\n\n");



}
