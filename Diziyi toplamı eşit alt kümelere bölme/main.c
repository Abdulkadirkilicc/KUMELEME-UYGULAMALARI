#include <stdio.h>
//1220505050 Abdulkadir K�l�� Diziyi toplam� e�it alt k�melere b�lme �rne�i; 
/*Bu program, kullan�c�dan  dizi ve eleman say�s�n� al�r. Daha sonra, dizinin elemanlar�n� okuyarak toplamlar�n� hesaplar.
E�er dizi toplam� tek say� ise, alt k�meler e�it olamaz ve program  direkt sonlan�r.
Dizi toplam� �ift say� ise, alt k�melerin toplamlar�n�n e�it olup olmad���n� kontrol eden `altKumelerToplamEsitMi` fonksiyonunu �a��r�r.
Bu fonksiyon, dizinin her bir eleman�n� s�rayla alarak alt k�melerin toplamlar�n� hesaplar ve bu toplamlar�n e�it olup olmad���n� kontrol eder.
Program, alt k�melerin toplamlar� e�itse, dizinin elemanlar�n� alt k�meler �eklinde yazar.
Bu yazd�rma i�lemi, `altKumelerToplamEsitMi` fonksiyonu i�inde yap�l�r ve �a�r�l�r.*/


// Alt k�melerin toplamlar� e�it mi?
int altKumelerToplamEsitMi(int dizi[], int elemanSayisi, int index, int toplam, int hedefToplam) {
   // T�m alt k�melerin toplam� hedefToplam'a e�it oldu�unda i�lem tamamlan�r
   if (hedefToplam == 0) {
      return 1;
   }

   // T�m dizinin elemanlar�n� kontrol et
   if (index >= elemanSayisi) {
      return 0;
   }

   // Mevcut eleman�n dahil edilmesiyle devam et
   int sonuc = altKumelerToplamEsitMi(dizi, elemanSayisi, index + 1, toplam + dizi[index], hedefToplam - dizi[index]);

   // Mevcut eleman� dahil etmeden devam et
   if (!sonuc) {
      sonuc = altKumelerToplamEsitMi(dizi, elemanSayisi, index + 1, toplam, hedefToplam);
   }

   // E�er alt k�meler e�it olarak b�l�nebildiyse, mevcut eleman� i�aretlemek i�in -1 ata
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

   // Dizi elemanlar�n� alt k�meler halinde b�lme i�lemi
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



