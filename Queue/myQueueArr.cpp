#include<iostream>
#include<Windows.h>
#include<iomanip>
#include "myQueueArr.h"
using namespace std;
/**
* @brief					: Bu fonksiyon kuyruk constructordir.
* @param kuyruk_bas				: Kuyrugun basini tutar.
* @param kuyruk_son				: Kuyrugun sonunu tutar.
* @param hasta_sayisi				: Kuyruktaki eleman sayisini tutar.
* @param erkek					: Kuyruktaki erkek sayisini tutan sayactir.
* @param kadin					: Kuyruktaki kadin sayisi tutan sayactir.
* @param toplam_hasta_sayısı			: Kuyruktaki toplam hasta sayisini tutan sayactir.
* @param muayene				: Muayene amacli gelen hasta sayisini tutmak icin kullanilan sayactir.
* @param tahlil					: Tahlil amacli gelen hasta sayisini tutmak icin kullanilan sayactir.
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
	return(hasta_sayisi == sıraGenisligi);
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
			if (kuyruk_son > sıraGenisligi - 1)
			{
				cout << "Hasta Kabul işlemleri dolmuştur...!!!" << endl;
				break;
			}

			cout << i + 1 << ". hastanın adını giriniz: ";
			cin >> kuyruk[kuyruk_son].name;

			cout << i + 1 << ". hastanın hangi amaçla geldiğini belirtiniz ([M]-Muayene [T]-Tahlil gösterme):";
			cin >> kuyruk[kuyruk_son].amac;

			cout << i + 1 << ". hastanın yaşını giriniz: ";
			cin >> kuyruk[kuyruk_son].yas;

			cout << i + 1 << ".hastanın cinsiyetini giriniz [E]/[K] :";
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
		cout << "Işleminiz gerçekleştirilmiştir" << endl;
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
		cout << "Listeniz boştur ..." << endl;
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

		//işi biten kuyruktan cıkar.
		cout << kuyruk[0].name << " isimli hastanın işlemleri bitmiş olup kuyruktan çıkarılmıştır" << endl;
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
		cout << left << setw(35) << "Hastanın Adı";
		cout << left << setw(35) << "Hastanın Yaşı";
		cout << left << setw(35) << "Hastanın Cinsiyeti";
		cout << left << setw(35) << "Hastanın Amacı ";
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
		cout << "Hasta Kadın oranı : %" << ortalama;
	}
}
/**
* @brief				: Bu fonksiyon kuyruktaki hastalarin yas ortalamasini yazdirir.
*/
void Queue::hasta_yas_ortalamasi() {
	if (kuyruk_bos())
	{
		cout << "Kuyrukta hasta kalmamıştır !!!\n\n ";
	}
	else
	{
		float yasOrt = 0;
		for (int i = 0; i < hasta_sayisi; i++)
		{
			yasOrt += kuyruk[i].yas;
		}
		yasOrt = (float)yasOrt / hasta_sayisi;
		cout << "Kuyruktaki hastaların yaş ortalaması:" << yasOrt << endl;
	}
}
/**
* @brief				: Bu fonksiyon hastalarin hastaneye gelme sebeblerine göre sayilarini yazdirir.
*/
void Queue::tahlil_muayene_sayisi()
{
	cout << "Muayene olmak için bekleyen hasta sayısı :" << muayene << endl;
	cout << "Tahlillerini göstermek için gelen hasta sayısı:" << tahlil;
}
/**
* @brief				: Bu fonksiyon hastanenin gunluk kazancini hesaplar.
*/
void Queue::hastanenin_gunluk_kazanci() const
{
	int ücret = 0;
	cout << "Hastanede tedavi sırasi alan her hastanın giriş ücreti 300 TL (Her şey dahil) " << endl;
	ücret = toplam_hasta_sayisi * 300;
	cout << "Hastanenin günlük kazancı : " << ücret;
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
		cout << "[1]-Sıraya hasta ekle\n";
		cout << "[2]-Sıradan hasta silme \n";
		cout << "[3]-Sırayı listele \n";
		cout << "[4]-Sıradaki yaş ortalaması \n";
		cout << "[5]-Kuyruktaki kadın / erkek sayısı \n";
		cout << "[6]-Hastaların geliş sebebine göre sayısı \n";
		cout << "[7]-Hastanenin günlük kazancı \n";
		cout << "[8]-Çıkıs \n";
		cout << "\n Seçim yapınız: ";
		cin >> secim;
		cout << endl;
		if (cin.fail())
		{
			cout << "Hatalı bir giris yaptınız...";
			Sleep(999);
			cin.clear();
			cin.ignore(10, '\n');
			system("cls");
		}
		else if (secim < 0 || secim>9)
		{
			cout << "Hatalı bir giris yaptınız....";
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
* @param secim				: Menudeden secilen islem turudur.
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
