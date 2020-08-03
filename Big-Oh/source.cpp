/**
* @author onur akkepenek --> e-mail: akkepenek38@gmail.com
* @date 11 Ekim 2019 Cumartesi
* @brief bu kod parçacýgý , bir sýnýfta verilen bir odevin puanlarýnýn ve istatistiklerinin listelenmesi,
gerektiðinde yanlýs girilen bir notun degistirilmesi simulasyonudur.
*/
#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<locale.h>
#include<conio.h>
#include <windows.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include <stdlib.h>
#include<ctime>
using namespace std;
/**
* @brief	: Ogrencileri bir düzen icinde tutmak icin olusturulan dinamik bir structtýr.
* @see main	: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
typedef struct student {
	string name;
	int id;
	int grade;
}student;
/**
* @brief				: Bu fonksiyon random olarak harfleri alarak bir ogrenci isim blogu olustur ve struct icinde kayitta tutulur.
* @param *student		: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
* @see main				: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void isimAtama(struct student* student, int& studentNumber)
{
	int random;
	char Alphabet[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z','a','e','i','o','u','y' };
	srand(time(NULL));

	for (int i = 0; i < studentNumber; i++)
	{
		string  name = "";
		random = rand() % 5 + 3;
		for (int j = 0; j < random; j++)
		{
			name = name + Alphabet[rand() % 26];
		}
		student[i].name = name;
	}
}
/**
* @brief				: Bu fonksiyon random olarak ogrenci numarasini olusturur ve struct icinde kayitta tutulur.
* @param	*student	: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
* @see main				: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void idAtama(struct student* student, int& studentNumber)
{
	int j = 1;
	for (int i = 0; i < studentNumber; i++)
	{
		if (i == 0) {
			student[i].id = rand() % 9999999;
		}
		else
		{
			student[i].id = student[0].id + j;// sistematik olarak öðrenci numaralarýna +1 ekler.
			j++;
		}
	}
}
/**
* @brief				: Bu fonksiyon her ogrenciye random olarak bir not atar ve structta tutulur.
* @param	*student	: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
* @see main				: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void notAtama(struct student* student, int& studentNumber) {
	for (int i = 0; i < studentNumber; i++)
	{
		student[i].grade = rand() % 100 + 1;
	}
}
/**
* @brief				: Bu fonksiyon pointer struct içinde yer alan ogrencilerden min ve max notu alan ögrencileri yazdirir.
* @param	*student	: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
* @see main				: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void MinMaxYazdirma(struct student* student, int& studentNumber)
{
	int min, max;
	max = student[0].grade;
	min = student[0].grade;
	for (int i = 1; i < studentNumber; i++)
	{

		if (student[i].grade < min)
		{
			min = student[i].grade;

		}
		if (student[i].grade > max)
		{
			max = student[i].grade;

		}

	}
	for (int i = 0; i < studentNumber; i++)
	{
		if (student[i].grade == min)
		{
			cout << "Minimum deðer : " << min << " ( " << student[i].id << " numaralý " << "," << student[i].name << " isimli öðrenci )" << endl;
		}

	}
	for (int i = 0; i < studentNumber; i++)
	{
		if (student[i].grade == max)
		{
			cout << "Maxsimum deðer: " << max << " ( " << student[i].id << " numaralý " << "," << student[i].name << " isimli öðrenci )" << endl;
		}

	}


}
/**
* @brief				: Bu fonksiyon pointer struct icinde yer alan ogrencilerin ortalamasini dondurur.
* @param *student		: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
* @return				: Ortalama bilgisi.
*/
float Ortalama(struct student* student, int& studentNumber) {
	float average;
	int sum = 0;
	for (int i = 0; i < studentNumber; i++)
	{
		sum += student[i].grade;
	}
	average = (float)sum / studentNumber;

	return average;
}
/**
* @brief				: Bu fonksiyon yanlis girilen yanlis bir notun degistirilmesini saglar.
* @param student		: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
*/
void DegisimMenusu(struct student* student, int& studentNumber)
{
	int newNo, counter = 0;
	int newGrade;
	cout << "Ögrenci id giriniz :";
	cin >> newNo;

	for (int i = 0; i < studentNumber; i++)
	{
		if (student[i].id == newNo)
		{
			counter++;
			cout << student[i].id << "( " << student[i].name << " )" << "ögrencisi için yeni notu ( " << student[i].grade << " )giriniz:";
			cin >> newGrade;
			if (cin.fail())
			{
				cout << "Geçersiz bir not girdiniz !!!" << endl;
				system("pause");
				exit(0);
			}
			else
			{
				student[i].grade = newGrade;

			}

		}
		if (newNo == 0 || newNo < 0)//Sayý istenen yerde harf veya - bir deðer girildiði taktirde uyarý veren kod bloðu.
		{
			cout << "Lütfen sayý giriniz !!!!!! " << endl;
			system("Pause");
			exit(0);

		}
	}
	if (counter == 0)
	{
		cout << "Yanlýþ bir id girdiniz !!" << endl;
		cout << "Tekrar id giriniz :";
		DegisimMenusu(student, studentNumber);
	}
}
/**
* @brief				: Bu fonksiyon ogrenci bilgilerini ekrana yazdirir.
* @param student		: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
*/
void listelemeMenusu(struct student* student, int& studentNumber) {

	int i;
	cout << left << setw(35) << "Öðrenci ID";
	cout << left << setw(35) << "Öðrenci Ýsmi";
	cout << left << setw(35) << "Öðrenci Notu";
	cout << endl;
	cout << left << setw(35) << "-------------";
	cout << left << setw(35) << "-------------";
	cout << left << setw(35) << "-------------";
	cout << endl;

	for (i = 0; i < studentNumber; i++)
	{
		cout << left << setw(35) << student[i].id;
		cout << left << setw(35) << student[i].name;
		cout << left << setw(35) << student[i].grade;
		cout << endl;
	}
}
/**
* @brief				: Bu fonksiyon ogrencilerin notlarini buyukten kucuge siralar.
* @param student		: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
*/
void Siralama(struct student* student, int& studentNumber) {
	for (int i = 0; i < studentNumber - 1; i++)
	{
		for (int j = 0; j < studentNumber - i - 1; j++)
		{
			if (student[j + 1].grade > student[j].grade)
			{
				swap(student[j + 1], student[j]);
			}
		}
	}
}
/**
* @brief				: Bu fonksiyon istenen k. en buyuk degeri ekrana yazdirir.
* @param student		: Struct olarak alinan  ogrenci objesidir
* @param studentNumber	: Ogrenci sayisidir.
*/
void K_enBuyuk(struct student* student, int& studentNumber) {

	int k_index;
	Siralama(student, studentNumber);

	while (true)
	{
		cout << "k deðerini giriniz :";
		cin >> k_index;

		if (k_index <= studentNumber)
		{
			for (int i = 0; i < studentNumber; i++)
			{
				if (student[k_index - 1].grade == student[i].grade)
				{
					cout << "Azalan sýralamadaki " << k_index << ". not -> " << student[i].grade << " ( " << student[i].id << " , " << student[i].name << " isimli öðrenci )" << endl;
				}
			}
			break;
		}
		else {
			cout << "Yeterli öðrenci mevcudu yoktur lütfen sýnýf mevcudunu kontrol ediniz" << endl;
		}
	}
}
/**
* @brief				: Bu fonksiyon alinan notlarin min max ortalama ve k.en buyuk degerin bulunmasini saglar .
* @param *student		: Struct olarak alinan  ogrenci objesidir.
* @param studentNumber	: Ogrenci sayisidir.
*/
void istatislikMenusu(struct student* student, int& studentNumber) {

	float temp;
	char seçim1;
	cout << "[1] m: min/mak/ort \n[2] k: k. en büyük \n" << "Seçim yapýnýz:";
	cin >> seçim1;
	if (seçim1 == 'm' || seçim1 == 'M')// max-min 
	{
		MinMaxYazdirma(student, studentNumber);
		temp = Ortalama(student, studentNumber);
		cout << "Ortalama :" << temp << endl;
	}
	else if (seçim1 == 'k' || seçim1 == 'K')// k.en buyuk deger
	{
		K_enBuyuk(student, studentNumber);
	}
	else if (cin.fail())
	{
		cout << "Yanliþ giriþ.Seçenekleri kontrol ediniz " << endl;
		system("pause");
		exit(0);
	}
}
/**
* @brief				: Bu fonksiyon ekrana ana menuyu yazdiran ve secim yapmamizi saglayan kod parcacigidir .
* @param *student		: Struct olarak alinan  ogrenci objesidir.
* @see main				: fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void anaMenu(struct student* student, int& studentNumber)
{
	char secim;
	do {
		system("color A");
		cout << "Secim giriniz (Listele[l/L] / Deðiþtir[d/D] / Istatistik[i/I]): ";
		cin >> secim;
		cout << endl;

		if (secim == 'L' || secim == 'l')
		{
			listelemeMenusu(student, studentNumber);
		}
		else if (secim == 'D' || secim == 'd')
		{
			DegisimMenusu(student, studentNumber);
		}
		else if (secim == 'Ý' || secim == 'i')
		{
			istatislikMenusu(student, studentNumber);
		}
		else if (secim == 'Q' || secim == 'q')
		{
			exit(0);
		}
		else
		{
			cout << "Hatalý iþlem yaptýnýz yeniden baþlatýnýz !!!" << endl;
			anaMenu(student, studentNumber);
		}
	} while (secim != 'Q' || secim != 'q');
}
void main()
{
	setlocale(LC_ALL, "Turkish");
	int number;
	cout << endl;
	cout << "Öðrenci sayýsýný giriniz: ";
	cin >> number;
	if (number == 0 || number < 0)
	{
		cout << "Hata Lütfen pozitif bir sayý giriniz !!!!" << endl;
		cout << "Sistemi tekrar baþlatýnýz!!!" << endl;
	}
	else
	{
		struct student* student = new struct student[number];// dinamic memory
		isimAtama(student, number);
		idAtama(student, number);
		notAtama(student, number);
		anaMenu(student, number);
	}
	system("pause");
}
