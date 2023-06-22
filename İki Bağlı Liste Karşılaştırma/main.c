#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1220505050 Abdulkadir Kýlýç  Baðlý liste olarak tanýmlanmýþ iki kelimeyi karþýlaþtýran uygulama örneði;

/*Bu programda, ilk önce kullanýcýdan iki baðlý liste için eleman sayýlarý alýnýr.
Daha sonra, elemanlarý kullanýcýdan alýnan verilerle oluþturulur ve baðlý listeye eklenir. 
Son olarak, her iki baðlý liste de yazdýrýlýr ve elemanlarý karþýlaþtýrýlmak üzere `listeKarsilastir` fonksiyonu çaðrýlýr ve listeleri karþýlaþtýrýr.*/
// Baðlý liste Struct düðümü tanýmladýk
typedef struct dugum {
    char veri[20];
    struct dugum* sonraki;
} Dugum;

// Yeni düðüm ekleme fonksiyonu  tanýmladýk
void dugumEkle(Dugum** bas, char* veri) {
    // Yeni düðüm oluþturma
    Dugum* yeniDugum = (Dugum*)malloc(sizeof(Dugum));
    strcpy(yeniDugum->veri, veri);
    yeniDugum->sonraki = NULL;
    // Baðlý listenin sonuna ekleme
    if (*bas == NULL) {
        *bas = yeniDugum;
    } else {
        Dugum* suanki = *bas;
        while (suanki->sonraki != NULL) {
            suanki = suanki->sonraki;
        }
        suanki->sonraki = yeniDugum;
    }
}

// Baðlý listeyi yazdýrma fonksiyonu
void listeYazdir(Dugum* bas) {
    Dugum* suanki = bas;
    while (suanki != NULL) {
        printf("%s ", suanki->veri);
        suanki = suanki->sonraki;
    }
    printf("\n");
}

// Ýki baðlý listenin elemanlarýný karþýlaþtýrma fonksiyonu
int listeKarsilastir(Dugum* bas1, Dugum* bas2) {
    Dugum* suanki1 = bas1;
    Dugum* suanki2 = bas2;
    while (suanki1 != NULL && suanki2 != NULL) {
        // Elemanlar ayný deðilse, karþýlaþtýrma sonlanýr
        if (strcmp(suanki1->veri, suanki2->veri) != 0) {
            return 0;
        }
        suanki1 = suanki1->sonraki;
        suanki2 = suanki2->sonraki;
    }
    // Ýki liste de ayný uzunlukta deðilse, karþýlaþtýrma sonlanýr
    if (suanki1 != NULL || suanki2 != NULL) {
        return 0;
    }
    // Ýki liste de ayný elemanlara sahipse, karþýlaþtýrma baþarýlýdýr
    return 1;
}

int main() {
    Dugum* bas1 = NULL;
    Dugum* bas2 = NULL;
    char veri[20];
    int i, n;
    // Ýlk baðlý liste oluþturma
    printf("Ilk bagli listenin eleman sayisini giriniz: ");
    scanf("%d", &n);
    printf("Lutfen elemanlari giriniz:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", veri);
        dugumEkle(&bas1, veri);
    }
    // Ýkinci baðlý liste oluþturma
	printf("Ikinci bagli listenin eleman sayisini giriniz: ");
	scanf("%d", &n);
	printf("Lutfen elemanlari giriniz:\n");
	for (i = 0; i < n; i++) {
    scanf("%s", veri);
    dugumEkle(&bas2, veri);
	}
	// Ýki baðlý listenin elemanlarýný yazdýrma
	printf("Ilk bagli listenin elemanlari: ");
	listeYazdir(bas1);
	printf("Ikinci bagli listenin elemanlari: ");
	listeYazdir(bas2);
	// Ýki baðlý listenin elemanlarýný karþýlaþtýrma
	if (listeKarsilastir(bas1, bas2)) {
    printf("Iki liste de ayni elemanlara sahip.\n");
	} else {
    printf("Iki liste farkli elemanlara sahip.\n");
	}
	return 0;
	}
