#include <stdio.h>
//1220505050 Abdulkadir Kýlýç
/* bu kod, dizinin eleman sayýsýna ve elemanlarýna göre bir 2 üzeri n alt küme kombinasyonu oluþturarak her iki alt kümenin toplamlarýný hesaplar ve toplamlar eþitse "Evet, ikiye bölünebilir" mesajýný yazdýrýr.
 eþit deðilse, "Hayýr, ikiye bölünemez" mesajýný yazdýrýr.*/
int main() {
    int n, i, j, say1, say2, etiket = 0;
    printf("Dizinin eleman sayisini girin: ");
    scanf("%d", &n);

    int dizi[n];
    printf("Dizinin elemanlarini girin:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &dizi[i]);
    }

    for(i = 0; i < (1 << n); i++) {
        say1 = 0;
        say2 = 0;
        for(j = 0; j < n; j++) {
            if(i & (1 << j)) {
                say1 += dizi[j];
            } else {
                say2 += dizi[j];
            }
        }
        if(say1 == say2) {
            etiket = 1;
            printf("Evet, ikiye bolunebilir\n");
            break;
        }
    }
    if(etiket == 0) {
        printf("Hayir, ikiye bolunemez\n");
    }

    return 0;
}

