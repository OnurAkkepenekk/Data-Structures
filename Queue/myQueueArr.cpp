#include<iostream>
#include<Windows.h>
#include<iomanip>
#include "myQueueArr.h"
using namespace std;
/**
* @brief					: Bu fonksiyon kuyruk constructordir.
* @param kuyruk_bas			: Kuyrugun basini tutar.
* @param kuyruk_son			: Kuyrugun sonunu tutar.
* @param hasta_sayisi		: Kuyruktaki eleman sayisini tutar.
* @param erkek				: Kuyruktaki erkek sayisini tutan sayactir.
* @param kadin				: Kuyruktaki kadin sayisi tutan sayactir.
* @param toplam_hasta_say�s�: Kuyruktaki toplam hasta sayisini tutan sayactir.
* @param muayene			: Muayene amacli gelen hasta sayisini tutmak icin kullanilan sayactir.
* @param tahlil				: Tahlil amacli gelen hasta sayisini tutmak icin kullanilan sayactir.
*/

Queue::Queue()//kuyruk constructor
{

	kuyruk_bas = 0;
	kuyruk_son = 0;
	hasta_sayisi = 0;
	erkek = 0;
	kadin = 0;
	toplam_hasta_sayisi = 0;
	muayene = 0;
	tahlil = 0;
}
/**
* @brief				: Kuyruk yapisinin bos olup olmadigini kontrol eder.
*/
bool Queue::kuyruk_bos()
{
	return(kuyruk_son == 0 && hasta_sayisi == 0);
}
/**
* @brief				: Bu fonksiyon kuyruk yapisinin dolu olup olmadigini kontrol eder.
*/
bool Queue::kuyruk_dolu() {
	return(hasta_sayisi == s�raGenisligi);
}
/**
* @brief				: Bu fonksiyon kuyruk yapisina hasta ekler.
*/
void Queue::hasta_ekle() {
	if (kuyruk_dolu())
	{
		cout << endl;
		cout << "Kuyruk dolu..." << endl;
	}
	else
	{
		int adet;
		cout << "Ka� adet eklensin :";
		cin >> adet;

		for (int i = 0; i < adet; i++)
		{
			if (kuyruk_son > s�raGenisligi - 1)
			{
				cout << "Hasta Kabul i�lemleri dolmu�tur...!!!" << endl;
				break;
			}

			cout << i + 1 << ". hastan�n ad�n� giriniz: ";
			cin >> kuyruk[kuyruk_son].name;

			cout << i + 1 << ". hastan�n hangi ama�la geldi�ini belirtiniz ([M]-Muayene [T]-Tahlil g�sterme):";
			cin >> kuyruk[kuyruk_son].amac;

			cout << i + 1 << ". hastan�n ya��n� giriniz: ";
			cin >> kuyruk[kuyruk_son].yas;

			cout << i + 1 << ".hastan�n cinsiyetini giriniz [E]/[K] :";
			cin >> kuyruk[kuyruk_son].cinsiyet;

			//kadin erkek sayisini saydirdim.
			if (kuyruk[kuyruk_son].cinsiyet == 'e' || kuyruk[kuyruk_son].cinsiyet == 'E')
			{
				erkek++;
			}
			if (kuyruk[kuyruk_son].cinsiyet == 'K' || kuyruk[kuyruk_son].cinsiyet == 'k')
			{
				kadin++;
			}
			//muayene veya tahlil sonucu gosterme durumunu saydirdim.
			if (kuyruk[kuyruk_son].amac == 'm' || kuyruk[kuyruk_son].amac == 'M') {
				muayene++;
			}
			if (kuyruk[kuyruk_son].amac == 'T' || kuyruk[kuyruk_son].amac == 't') {
				tahlil++;
			}
			toplam_hasta_sayisi++;
			hasta_sayisi++;
			kuyruk_son++;
		}
		cout << "I�leminiz ger�ekle�tirilmi�tir" << endl;
	}
}
/**
* @brief				: Bu fonksiyon kuyruk yapisindan hasta siler.
*/
void Queue::hasta_sil()
{
	if (kuyruk_bos())
	{
		cout << endl << endl;
		cout << "Listeniz bo�tur ..." << endl;
	}
	else
	{
		if (kuyruk[0].cinsiyet == 'e' || kuyruk[0].cinsiyet == 'E')
		{
			erkek--;
		}
		if (kuyruk[0].cinsiyet == 'k' || kuyruk[0].cinsiyet == 'K')
		{
			kadin--;
		}

		if (kuyruk[0].amac == 'M' || kuyruk[0].amac == 'm') {
			muayene--;
		}
		if (kuyruk[0].amac == 'T' || kuyruk[0].amac == 't') {
			tahlil--;
		}

		//i�i biten kuyruktan c�kar.
		cout << kuyruk[0].name << " isimli hastan�n i�lemleri bitmi� olup kuyruktan ��kar�lm��t�r" << endl;
		for (int i = 0; i < kuyruk_son - 1; i++)
		{
			kuyruk[i] = kuyruk[i + 1];
		}
		hasta_sayisi--;
		kuyruk_son--;
	}
}
/**
* @brief				: Bu fonksiyon kuyruktaki hastalari listeler.
*/
void Queue::hastalari_listele() {

	if (hasta_sayisi == 0)
	{
		cout << "ListeBos" << endl;
	}
	else {
		cout << left << setw(35) << "Hastan�n Ad�";
		cout << left << setw(35) << "Hastan�n Ya��";
		cout << left << setw(35) << "Hastan�n Cinsiyeti";
		cout << left << setw(35) << "Hastan�n Amac� ";
		cout << endl;
		cout << left << setw(35) << "-------------";
		cout << left << setw(35) << "-------------";
		cout << left << setw(35) << "-------------";
		cout << left << setw(35) << "-------------";
		cout << endl;

		for (int i = 0; i < hasta_sayisi; i++)
		{
			cout << left << setw(35) << kuyruk[i].name;
			cout << left << setw(35) << kuyruk[i].yas;
			cout << left << setw(35) << kuyruk[i].cinsiyet;
			cout << left << setw(35) << kuyruk[i].amac;
			cout << endl;
		}
	}
}
/**
* @brief				: Bu fonksiyon kuyruktaki hastalarin kiz-erkek sayisini ve oranlarini yazdirir.
*/
void Queue::hasta_erkek_kadin_orani() {

	float ortalama;

	cout << "Hasta kadin sayisi:" << kadin << endl;
	cout << "Hasta erkek sayisi:" << erkek << endl;
	if (!kuyruk_bos()) {
		ortalama = (float)(erkek * 100) / hasta_sayisi;
		cout << "Hasta Erkek orani: %" << ortalama << endl;
		ortalama = (float)(kadin * 100) / hasta_sayisi;
		cout << "Hasta Kad�n oran� : %" << ortalama;
	}
}
/**
* @brief				: Bu fonksiyon kuyruktaki hastalarin yas ortalamasini yazdirir.
*/
void Queue::hasta_yas_ortalamasi() {
	if (kuyruk_bos())
	{
		cout << "Kuyrukta hasta kalmam��t�r !!!\n\n ";
	}
	else
	{
		float yasOrt = 0;
		for (int i = 0; i < hasta_sayisi; i++)
		{
			yasOrt += kuyruk[i].yas;
		}
		yasOrt = (float)yasOrt / hasta_sayisi;
		cout << "Kuyruktaki hastalar�n ya� ortalamas�:" << yasOrt << endl;
	}
}
/**
* @brief				: Bu fonksiyon hastalarin hastaneye gelme sebeblerine g�re sayilarini yazdirir.
*/
void Queue::tahlil_muayene_sayisi()
{
	cout << "Muayene olmak i�in bekleyen hasta say�s� :" << muayene << endl;
	cout << "Tahlillerini g�stermek i�in gelen hasta say�s�:" << tahlil;
}
/**
* @brief				: Bu fonksiyon hastanenin gunluk kazancini hesaplar.
*/
void Queue::hastanenin_gunluk_kazanci() const
{
	int �cret = 0;
	cout << "Hastanede tedavi s�rasi alan her hastan�n giri� �creti 300 TL (Her �ey dahil) " << endl;
	�cret = toplam_hasta_sayisi * 300;
	cout << "Hastanenin g�nl�k kazanc� : " << �cret;
}
/**
* @brief				: Menu fonksiyonudur.
*/
void Queue::menu() {
	int secim;
	do
	{
		cout << endl;
		system("color A");
		cout << "                ANA MEN�                 ";
		cout << "\n---------------------------------------" << endl;
		cout << "[1]-S�raya hasta ekle\n";
		cout << "[2]-S�radan hasta silme \n";
		cout << "[3]-S�ray� listele \n";
		cout << "[4]-S�radaki ya� ortalamas� \n";
		cout << "[5]-Kuyruktaki kad�n / erkek say�s� \n";
		cout << "[6]-Hastalar�n geli� sebebine g�re say�s� \n";
		cout << "[7]-Hastanenin g�nl�k kazanc� \n";
		cout << "[8]-��k�s \n";
		cout << "\n Se�im yap�n�z: ";
		cin >> secim;
		cout << endl;
		if (cin.fail())
		{
			cout << "Hatal� bir giris yapt�n�z...";
			Sleep(999);
			cin.clear();
			cin.ignore(10, '\n');
			system("cls");
		}
		else if (secim < 0 || secim>9)
		{
			cout << "Hatal� bir giris yapt�n�z....";
			Sleep(999);
			cin.clear();
			cin.ignore(10, '\n');
			system("cls");
		}
		else
		{
			secenekler(secim);
			Sleep(1000);
			system("cls");
		}
	} while (1);

}
/**
* @brief				: Menudeki secimlere gore islem yapar.
* @param secim			: Menudeden secilen islem turudur.
*/
void Queue::secenekler(int secim)
{
	switch (secim)
	{
	case 1:
		hasta_ekle();
		break;
	case 2:hasta_sil();
		break;
	case 3:hastalari_listele();
		break;
	case 4:hasta_yas_ortalamasi();
		break;
	case 5:hasta_erkek_kadin_orani();
		break;
	case 6:tahlil_muayene_sayisi();
		break;
	case 7:hastanenin_gunluk_kazanci();
		break;
	case 8:
		system("pause");
		exit(0);
	}
}
