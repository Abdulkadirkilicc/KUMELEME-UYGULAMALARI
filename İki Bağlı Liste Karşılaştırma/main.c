#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1220505050 Abdulkadir K�l��  Ba�l� liste olarak tan�mlanm�� iki kelimeyi kar��la�t�ran uygulama �rne�i;

/*Bu programda, ilk �nce kullan�c�dan iki ba�l� liste i�in eleman say�lar� al�n�r.
Daha sonra, elemanlar� kullan�c�dan al�nan verilerle olu�turulur ve ba�l� listeye eklenir. 
Son olarak, her iki ba�l� liste de yazd�r�l�r ve elemanlar� kar��la�t�r�lmak �zere `listeKarsilastir` fonksiyonu �a�r�l�r ve listeleri kar��la�t�r�r.*/
// Ba�l� liste Struct d���m� tan�mlad�k
typedef struct dugum {
    char veri[20];
    struct dugum* sonraki;
} Dugum;

// Yeni d���m ekleme fonksiyonu  tan�mlad�k
void dugumEkle(Dugum** bas, char* veri) {
    // Yeni d���m olu�turma
    Dugum* yeniDugum = (Dugum*)malloc(sizeof(Dugum));
    strcpy(yeniDugum->veri, veri);
    yeniDugum->sonraki = NULL;
    // Ba�l� listenin sonuna ekleme
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

// Ba�l� listeyi yazd�rma fonksiyonu
void listeYazdir(Dugum* bas) {
    Dugum* suanki = bas;
    while (suanki != NULL) {
        printf("%s ", suanki->veri);
        suanki = suanki->sonraki;
    }
    printf("\n");
}

// �ki ba�l� listenin elemanlar�n� kar��la�t�rma fonksiyonu
int listeKarsilastir(Dugum* bas1, Dugum* bas2) {
    Dugum* suanki1 = bas1;
    Dugum* suanki2 = bas2;
    while (suanki1 != NULL && suanki2 != NULL) {
        // Elemanlar ayn� de�ilse, kar��la�t�rma sonlan�r
        if (strcmp(suanki1->veri, suanki2->veri) != 0) {
            return 0;
        }
        suanki1 = suanki1->sonraki;
        suanki2 = suanki2->sonraki;
    }
    // �ki liste de ayn� uzunlukta de�ilse, kar��la�t�rma sonlan�r
    if (suanki1 != NULL || suanki2 != NULL) {
        return 0;
    }
    // �ki liste de ayn� elemanlara sahipse, kar��la�t�rma ba�ar�l�d�r
    return 1;
}

int main() {
    Dugum* bas1 = NULL;
    Dugum* bas2 = NULL;
    char veri[20];
    int i, n;
    // �lk ba�l� liste olu�turma
    printf("Ilk bagli listenin eleman sayisini giriniz: ");
    scanf("%d", &n);
    printf("Lutfen elemanlari giriniz:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", veri);
        dugumEkle(&bas1, veri);
    }
    // �kinci ba�l� liste olu�turma
	printf("Ikinci bagli listenin eleman sayisini giriniz: ");
	scanf("%d", &n);
	printf("Lutfen elemanlari giriniz:\n");
	for (i = 0; i < n; i++) {
    scanf("%s", veri);
    dugumEkle(&bas2, veri);
	}
	// �ki ba�l� listenin elemanlar�n� yazd�rma
	printf("Ilk bagli listenin elemanlari: ");
	listeYazdir(bas1);
	printf("Ikinci bagli listenin elemanlari: ");
	listeYazdir(bas2);
	// �ki ba�l� listenin elemanlar�n� kar��la�t�rma
	if (listeKarsilastir(bas1, bas2)) {
    printf("Iki liste de ayni elemanlara sahip.\n");
	} else {
    printf("Iki liste farkli elemanlara sahip.\n");
	}
	return 0;
	}
