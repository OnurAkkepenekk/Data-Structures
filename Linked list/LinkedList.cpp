#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
using namespace std;
/**
* @author		Onur Akkepenek --> e-mail: akkepenek38@gmail.com
* @date			20 Ekim 2019 Pazar
* @brief		Bu kod parcacigi,tek yonlu bagli liste temelli ve ilgili veri yapisini fonksiyonlarin test uygulamasi niteligindedir.
*/
void secimMenu(int secim);
void sonaEkle(int sayi);
void basaEkle(int sayi);
void arayaekle(int sayi, int index);
void elemanSilme(int sayi);
int elemanSay�s�();
void b�l();
void Menu();
void secimMenu(int secim);
void cokluSil(int index, int adet);
void listeyiYaz();
struct node* newElement();
// Dugumleri tutacagimiz struct yapisi.
typedef struct node
{
	int value;
	struct node* pnext;

}element;
//Ba�lang�� d���m�(head) ve ge�ici de�i�kenler(temp) olu�turuyoruz(GLOBAL).
struct node* head = NULL;
struct node* temp;
struct node* temp1;
struct node* temp2;
struct node* temp3;
//Yeni dugum olusturur ve return eder.
struct node* newElement()
{
	struct node* newNode = new struct node;
	return newNode;
}
/**
* @brief				: Bu fonksiyon girilen sayi degerini bagli listenin sonuna ekler.
* @param int sayi		: Sona eklenecek sayinin degeri.
*/
void sonaEkle(int sayi)
{
	struct node* newNode = newElement();
	newNode->value = sayi;
	newNode->pnext = NULL;
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		temp = head;
		while (temp->pnext != NULL)
		{
			temp = temp->pnext;
		}
		temp->pnext = newNode;
	}
}
/**
* @brief				: Bu fonksiyon araya ekle fonksiyonunda basa eleman eklemeyi saglar.
* @param int sayi		: Basa eklenecek sayinin degeri.
*/
void basaEkle(int sayi)
{
	struct node* element = newElement();
	element->value = sayi;
	temp = head;
	element->pnext = temp;
	head = element;
}
/**
* @brief				: Bu fonksiyon istenen pozisyon degerine gore listenin uygun kismina sayiyi yerlestirilecektir.
* @param sayi			: Eklenecek sayinin degeridir.
* @param index			: Eklenilmesi istenen pozisyon degeridir.
*/
void arayaekle(int sayi, int index) {
	int counter = 0, counter1;
	struct node* arayaAt = newElement();
	arayaAt->value = sayi;
	counter1 = elemanSay�s�();
	temp = head;
	if (head == NULL)
	{
		cout << "Liste bo� araya ekleme yap�lamad�..." << endl;
	}
	else if (index - 1 == 0 || index == 0)
	{
		basaEkle(sayi);
	}
	else if (index > counter1)
	{
		cout << " \n Liste boyutunu a�t�n�z araya eklenemedi" << endl;
	}
	else
	{
		while (temp != NULL)//eklenecek indexe kadar ilerliyor ve ulastiginda donguyu kirip ekleme islemi yapiyor.
		{
			if (counter + 2 == index) {
				break;
			}
			temp = temp->pnext;
			counter++;
		}
		struct node* temp3;
		temp3 = temp->pnext;
		temp->pnext = arayaAt;
		arayaAt->pnext = temp3;
	}
}
/**
* @brief				: Bu fonksiyon istenen sayiyi listeden silmemizi saglar.
* @param sayi			: Listeden silinecek sayinin degeri.
*/
void elemanSilme(int sayi)
{
	struct node** pp = &head;
	int counter = 0;
	while (*pp)
	{
		struct node* kay�t = *pp;//Sayi bulunursa *pp ye adresi kaydedip elemani siler.
		if (kay�t->value == sayi)
		{
			*pp = kay�t->pnext;
			delete (kay�t);
			counter++;
		}
		else//hareket ettirir.
		{
			pp = &(kay�t->pnext);
		}
	}
	if (counter == 0)//Listede elemanin olup olmadigini kontrol ettim.
	{
		cout << "Silmek istedi�iniz sayi listede yoktur..." << endl;
	}
}
/**
* @brief				: Bu fonksiyon istenen pozisyon istenen pozisyondan itibaren adet sayisi kadar sayiyi listeden siler.
* @param adet			: Silinmesi istenen sayi adeti.
* @param index			: Silmeye baslanmasi istenen kisim.
*/
void cokluSil(int index, int adet)
{
	int counter;
	counter = elemanSay�s�();
	temp = head;
	if (head == NULL)
	{
		cout << "\n Liste bo�...";
	}
	else if (index > counter || index < 0)
	{
		cout << " \n Yetersiz eleman say�s�" << endl;
	}
	else
	{
		for (int i = 0; i < index - 2 && temp != NULL; i++)//indexin gosterdigi yeri kaydettim
		{
			temp = temp->pnext;
		}
		temp1 = temp;
		for (int i = 0; i < adet + 1 && temp != NULL; i++)//adet say�s� kadar nextledim
		{
			temp = temp->pnext;
		}
		temp1->pnext = temp;//1. k�s�mla 2. k�s�m� baglayip aradaki elemanlar� c�kard�m.
	}
}
/**
* @brief				: Bu fonksiyon istenen bagdan itibaren listeyi ikiye boler ve istenen kismin kullanilmasini saglar.
*/
void b�l() {
	int i = 0, parcalama, secim, elemansay�s�;
	struct node* birinci_parca = newElement();
	struct node* ikinci_parca = newElement();

	cout << "Ka��nc� ba�dan b�l�ns�n ?";
	cin >> parcalama;
	cout << "Birinci K�s�m ";
	temp = head;

	for (int i = 0; i < parcalama; i++)
	{
		birinci_parca = temp;
		temp = temp->pnext;
		cout << birinci_parca->value << " ";
	}
	temp1 = birinci_parca->pnext;
	temp2 = birinci_parca->pnext;
	cout << endl;
	cout << "�kinci k�s�m ";

	for (int i = 0; temp != NULL; i++)
	{
		ikinci_parca = temp;
		cout << ikinci_parca->value << " ";
		temp = temp->pnext;
	}
	cout << endl;
	cout << "Hangi k�s�m kullan�ls�n :";
	cin >> secim;
	elemansay�s� = elemanSay�s�();

	int secim1_bas = parcalama + 1;//silinmeye baslanan ilk eleman
	int secim1_son = elemansay�s� - secim1_bas + 1;//silinen son eleman�n yeri 

	if (secim == 1)
	{
		cokluSil(secim1_bas, secim1_son);

	}
	else if (secim == 2)
	{
		for (int i = 0; i < parcalama; i++)
		{
			struct node* temp2 = head;//tem2 yi olarak listede gezdirdim
			head = head->pnext;
			delete(temp2);
		}
	}
}
/**
* @brief				: Bu fonksiyon listede bulunan eleman sayisini hesaplar.
*/
int elemanSay�s�()
{
	int sayac = 0;
	temp = head;
	while (temp != NULL)
	{
		temp = temp->pnext;
		sayac++;
	}
	return sayac;
}
/**
* @brief				: Bu fonksiyon menuyu ekrana yazdirir.
*/
void Menu()
{
	int secim;
	while (1)
	{
		system("color A");
		cout << "                ANA MEN�                 ";
		cout << "\n---------------------------------------" << endl;
		cout << "[1]-Listenin Sonuna Ekleme \n";
		cout << "[2]-Araya Eleman Ekleme \n";
		cout << "[3]-Elemani Silme \n";
		cout << "[4]-Belirli bir noktadan itibaren �oklu sil \n";
		cout << "[5]-B�l \n";
		cout << "[6]-Listele \n";
		cout << "[7]-Say \n";
		cout << "[8]-��k�s \n";
		cout << "\n Se�im yap�n�z: ";
		cin >> secim;
		if (cin.fail())
		{
			cout << "Hatal� bir giris yapt�n�z...";
			Sleep(999);
			cin.clear();
			cin.ignore(10, '\n');
			system("cls");
		}
		else if (secim < 0 || secim >= 9)
		{
			cout << "Hatal� bir giris yapt�n�z....";
			Sleep(999);
			cin.clear();
			cin.ignore(10, '\n');
			system("cls");
		}
		else
		{
			system("cls");
			secimMenu(secim);
			cout << endl;
			cout << " Ana men�ye d�n�l�yor ... " << endl;
			Sleep(3000);
			system("cls");
		}
	}
}
/**
* @brief				: Bu fonksiyon yapilan secimlere gore islemler yapar.
* @param secim			: Yapilmak istenen islem seklidir.
*/
void secimMenu(int secim)
{
	int secim1, adet, index, sayi, sayac, parcalama;
	switch (secim)
	{
	case 1:
		cout << "\n Ka� tane sayi ekleyeceksiniz :";
		cin >> secim1;
		for (int i = 0; i < secim1; i++)
		{
			cout << i + 1 << ".Say�y� giriniz :";
			cin >> sayi;

			sonaEkle(sayi);
		}
		break;
	case 2:
		cout << "Eklemek istedi�iniz say�y� giriniz:";
		cin >> sayi;
		cout << "Hangi pozisyona eklemek istiyorsunuz :";
		cin >> index;
		arayaekle(sayi, index);
		break;
	case 3:
		cout << "Silmek istedi�iniz eleman� giriniz :";
		cin >> sayi;
		elemanSilme(sayi);
		break;
	case 4:
		cout << "Hangi pozisyondan itibaren silmeye ba�lans�n:";
		cin >> index;
		cout << "Ka� adet silinsin :";
		cin >> adet;
		cokluSil(index, adet);
		break;
	case 5:
		b�l();
		break;
	case 6:
		listeyiYaz();
		break;
	case 7:
		sayac = elemanSay�s�();
		cout << "Eleman say�s�= " << sayac;
		break;
	case 8:
		system("pause");
		exit(0);
		break;
	}
}
/**
* @brief				: Bu fonksiyon listenin elemanlarini ekrana yazdirir.
*/
void listeyiYaz()
{
	if (head == NULL)
	{
		cout << "\nListe bos...";
	}
	else
	{
		temp = head;
		while (temp->pnext != NULL)
		{
			cout << temp->value << " ";
			temp = temp->pnext;
		}
		cout << temp->value;
		cout << "\n";
	}
}
void main()
{
	setlocale(LC_ALL, "Turkish");
	Menu();
	system("pause");
}