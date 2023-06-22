#include <stdio.h>
//1220505050 Abdulkadir Kýlýç Diziyi toplamý eþit alt kümelere bölme örneði; 
/*Bu program, kullanýcýdan  dizi ve eleman sayýsýný alýr. Daha sonra, dizinin elemanlarýný okuyarak toplamlarýný hesaplar.
Eðer dizi toplamý tek sayý ise, alt kümeler eþit olamaz ve program  direkt sonlanýr.
Dizi toplamý çift sayý ise, alt kümelerin toplamlarýnýn eþit olup olmadýðýný kontrol eden `altKumelerToplamEsitMi` fonksiyonunu çaðýrýr.
Bu fonksiyon, dizinin her bir elemanýný sýrayla alarak alt kümelerin toplamlarýný hesaplar ve bu toplamlarýn eþit olup olmadýðýný kontrol eder.
Program, alt kümelerin toplamlarý eþitse, dizinin elemanlarýný alt kümeler þeklinde yazar.
Bu yazdýrma iþlemi, `altKumelerToplamEsitMi` fonksiyonu içinde yapýlýr ve çaðrýlýr.*/


// Alt kümelerin toplamlarý eþit mi?
int altKumelerToplamEsitMi(int dizi[], int elemanSayisi, int index, int toplam, int hedefToplam) {
   // Tüm alt kümelerin toplamý hedefToplam'a eþit olduðunda iþlem tamamlanýr
   if (hedefToplam == 0) {
      return 1;
   }

   // Tüm dizinin elemanlarýný kontrol et
   if (index >= elemanSayisi) {
      return 0;
   }

   // Mevcut elemanýn dahil edilmesiyle devam et
   int sonuc = altKumelerToplamEsitMi(dizi, elemanSayisi, index + 1, toplam + dizi[index], hedefToplam - dizi[index]);

   // Mevcut elemaný dahil etmeden devam et
   if (!sonuc) {
      sonuc = altKumelerToplamEsitMi(dizi, elemanSayisi, index + 1, toplam, hedefToplam);
   }

   // Eðer alt kümeler eþit olarak bölünebildiyse, mevcut elemaný iþaretlemek için -1 ata
   if (sonuc) {
      dizi[index] = -1;
   }

   return sonuc;
}

int main() {
   int dizi[100], elemanSayisi, i, toplam = 0;

   printf("Dizi boyutunu giriniz: ");
   scanf("%d", &elemanSayisi);

   printf("Dizi elemanlarini giriniz: ");
   for (i = 0; i < elemanSayisi; i++) {
      scanf("%d", &dizi[i]);
      toplam += dizi[i];
   }

   // Dizi elemanlarýný alt kümeler halinde bölme iþlemi
   if (toplam % 2 == 0 && altKumelerToplamEsitMi(dizi, elemanSayisi, 0, 0, toplam / 2)) {
      printf("Dizi elemanlarinin alt kumeleri esit olarak bolunebilir:\n");

      for (i = 0; i < elemanSayisi; i++) {
         if (dizi[i] == -1) {
            continue;
         }
         printf("%d ", dizi[i]);
      }
      printf("\n");
   }
   else {
      printf("Dizi elemanlarinin alt kumeleri esit olarak bolunemez\n");
   }

   return 0;
}



