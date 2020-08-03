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
* @param toplam_hasta_sayýsý: Kuyruktaki toplam hasta sayisini tutan sayactir.
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
	return(hasta_sayisi == sýraGenisligi);
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
		cout << "Kaç adet eklensin :";
		cin >> adet;

		for (int i = 0; i < adet; i++)
		{
			if (kuyruk_son > sýraGenisligi - 1)
			{
				cout << "Hasta Kabul iþlemleri dolmuþtur...!!!" << endl;
				break;
			}

			cout << i + 1 << ". hastanýn adýný giriniz: ";
			cin >> kuyruk[kuyruk_son].name;

			cout << i + 1 << ". hastanýn hangi amaçla geldiðini belirtiniz ([M]-Muayene [T]-Tahlil gösterme):";
			cin >> kuyruk[kuyruk_son].amac;

			cout << i + 1 << ". hastanýn yaþýný giriniz: ";
			cin >> kuyruk[kuyruk_son].yas;

			cout << i + 1 << ".hastanýn cinsiyetini giriniz [E]/[K] :";
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
		cout << "Iþleminiz gerçekleþtirilmiþtir" << endl;
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
		cout << "Listeniz boþtur ..." << endl;
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

		//iþi biten kuyruktan cýkar.
		cout << kuyruk[0].name << " isimli hastanýn iþlemleri bitmiþ olup kuyruktan çýkarýlmýþtýr" << endl;
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
		cout << left << setw(35) << "Hastanýn Adý";
		cout << left << setw(35) << "Hastanýn Yaþý";
		cout << left << setw(35) << "Hastanýn Cinsiyeti";
		cout << left << setw(35) << "Hastanýn Amacý ";
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
		cout << "Hasta Kadýn oraný : %" << ortalama;
	}
}
/**
* @brief				: Bu fonksiyon kuyruktaki hastalarin yas ortalamasini yazdirir.
*/
void Queue::hasta_yas_ortalamasi() {
	if (kuyruk_bos())
	{
		cout << "Kuyrukta hasta kalmamýþtýr !!!\n\n ";
	}
	else
	{
		float yasOrt = 0;
		for (int i = 0; i < hasta_sayisi; i++)
		{
			yasOrt += kuyruk[i].yas;
		}
		yasOrt = (float)yasOrt / hasta_sayisi;
		cout << "Kuyruktaki hastalarýn yaþ ortalamasý:" << yasOrt << endl;
	}
}
/**
* @brief				: Bu fonksiyon hastalarin hastaneye gelme sebeblerine göre sayilarini yazdirir.
*/
void Queue::tahlil_muayene_sayisi()
{
	cout << "Muayene olmak için bekleyen hasta sayýsý :" << muayene << endl;
	cout << "Tahlillerini göstermek için gelen hasta sayýsý:" << tahlil;
}
/**
* @brief				: Bu fonksiyon hastanenin gunluk kazancini hesaplar.
*/
void Queue::hastanenin_gunluk_kazanci() const
{
	int ücret = 0;
	cout << "Hastanede tedavi sýrasi alan her hastanýn giriþ ücreti 300 TL (Her þey dahil) " << endl;
	ücret = toplam_hasta_sayisi * 300;
	cout << "Hastanenin günlük kazancý : " << ücret;
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
		cout << "                ANA MENÜ                 ";
		cout << "\n---------------------------------------" << endl;
		cout << "[1]-Sýraya hasta ekle\n";
		cout << "[2]-Sýradan hasta silme \n";
		cout << "[3]-Sýrayý listele \n";
		cout << "[4]-Sýradaki yaþ ortalamasý \n";
		cout << "[5]-Kuyruktaki kadýn / erkek sayýsý \n";
		cout << "[6]-Hastalarýn geliþ sebebine göre sayýsý \n";
		cout << "[7]-Hastanenin günlük kazancý \n";
		cout << "[8]-Çýkýs \n";
		cout << "\n Seçim yapýnýz: ";
		cin >> secim;
		cout << endl;
		if (cin.fail())
		{
			cout << "Hatalý bir giris yaptýnýz...";
			Sleep(999);
			cin.clear();
			cin.ignore(10, '\n');
			system("cls");
		}
		else if (secim < 0 || secim>9)
		{
			cout << "Hatalý bir giris yaptýnýz....";
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
