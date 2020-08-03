#include <iostream>
#include<string>
using namespace std;
/**
* @brief					: Class yapisi olusturulur ve icine gerekli fonksiyonlar yazilir.Ek olarak class icine bir struct olusturdum ve girilen bilgileri hafizada tuttum.
* @param kuyruk_bas			: Kuyrugun basini tutar.
* @param kuyruk_son			: Kuyrugun sonunu tutar.
* @param hasta_sayisi		: Kuyruktaki eleman sayisini tutar.
* @param erkek				: Kuyruktaki erkek sayisini tutan sayactir.
* @param kadin				: Kuyruktaki kadin sayisi tutan sayactir.
* @param toplam_hasta_sayýsý: Kuyruktaki toplam hasta sayisini tutan sayactir.
* @param muayene			: Muayene amacli gelen hasta sayisini tutmak icin kullanilan sayactir.
* @param tahlil				: Tahlil amacli gelen hasta sayisini tutmak icin kullanilan sayactir.
*/

class Queue {

public:

	Queue();
	/**
	* @brief				: Kuyruk yapisinin dolu olup olmadigini kontrol eder.
	*/
	bool kuyruk_dolu();
	/**
	* @brief				: Kuyruk yapisinin bos olup olmadigini kontrol eder.
	*/
	bool kuyruk_bos();
	/**
	* @brief				: Bu fonksiyon kuyruk yapisina hasta ekler.
	*/
	void hasta_ekle();
	/**
	* @brief				: Bu fonksiyon kuyruk yapisindan hasta siler.
	*/
	void hasta_sil();
	/**
	* @brief				: Bu fonksiyon kuyruktaki hastalari listeler.
	*/
	void hastalari_listele();
	/**
	* @brief				: Bu fonksiyon kuyruktaki hastalarin kiz-erkek sayisini ve oranlarini yazdirir.
	*/
	void hasta_yas_ortalamasi();
	/**
	* @brief				: Bu fonksiyon kuyruktaki hastalarin yas ortalamasini yazdirir.
	*/
	void hasta_erkek_kadin_orani();
	/**
	* @brief				: Bu fonksiyon hastalarin hastaneye gelme sebeblerine göre sayilarini yazdirir.
	*/
	void tahlil_muayene_sayisi();
	/**
	* @brief				: Menu fonksiyonudur.
	*/
	void hastanenin_gunluk_kazanci()const;
	/**
	* @brief				: Menu fonksiyonudur.
	*/
	void menu();
	/**
	* @brief				: Menudeki secimlere gore islem yapar.
	* @param secim			: Menudeden secilen islem turudur.
	*/
	void secenekler(int);
private:

	int sýraGenisligi = 8;//kuyruk boyutunu	
	int kuyruk_bas;
	int kuyruk_son;
	int hasta_sayisi;
	int erkek;
	int kadin;
	int muayene;
	int tahlil;
	int toplam_hasta_sayisi;
	/**
	* @brief				: Bu struct yapisi hastalarin bilgilerini saklar.
	*/
	struct hasta
	{
		string name;
		char amac;
		char cinsiyet;
		int yas;
	};
	hasta* kuyruk = new  hasta[sýraGenisligi];//Dinamic hafiza kullanarak yer ayirdim.	 
};