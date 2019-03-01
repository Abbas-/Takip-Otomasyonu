

#pragma region kütüphaneler
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> //gerek olmayabilir
#pragma endregion

#pragma region Structlar




struct siginmaci
{
	int siginmaci_no;
	char ad[20];
	char soyad[20];
	char dogum_tarihi[20];
	char dogum_yeri[20];
	char cinsiyet[20];
	char uyruk[20];
	char meslek[20];
	char egitim_durumu[20];
	char telefon[20];
	char yerlestirildigi_adres[20];
	char geldigi_sehir[20];
	char gelis_tarihi[20];
	char eposta[40];
	/*char kayitTipi;*/

};
struct siginmaci siginan;
void Listem(struct  siginmaci siginan);

struct adminci
{
	char tc[12];
	char ad[20];
	char soyad[20];
	char tel[20];
	char adres[25];
	char eposta[50];
	char kullanici_adi[15];
	char sifre[20];
	char yetki_turu;

}admin;
void Listem2(adminci admin);
#pragma endregion

#pragma region fonksiyonTanitimi



void adminGiris();
void sifreDegistir();   
void anaMenu1();  
void anaMenu2();  
void anaMenu3();  
void siginmaciEkle(); 
void siginmaciSil(); 
void siginmaciGuncelle();
void siginmaciArama();
void siginmaciListele();
void memurEkle();      
void memurSil();
void memurListele();
void kullanıcıSil();
void kullaniciListele();
void Listem(struct siginmaci siginan);
void Listem2(adminci admin);
void animasyon();
#pragma endregion

void main()
{
    animasyon();           // void animasyon fonksiyonunu çağırıyor...
	adminGiris();
	_getch();
}
void adminGiris()
{
	system("Color 3F");
	char secim;
	char kullanici[20];  //kullanıcı adı için 20karakter tanımladık
	char sifre[20];      //şifre  için 20karakter tanımladık


	for (;;)
	{
		_flushall();        // RAM'i temizleme için kullanılır
		system("CLS");
		printf("--------------------------> SİGİNMACİ TAKİP SİSTEMİ <---------------------------\n");
		printf("==============GIRIS===============\n");
		printf("||	1.PATRON	           ||\n");
		printf("||	2.SİGİNMACİ MEMURU     ||\n");
		printf("||	3.GOZLEMCİ	           ||\n");
		printf("||	0.Cikis		           ||\n");
		printf("==================================\n");
		printf("Giris yapmak icin birini seciniz: ");
		secim = _getche(); // birden çok karakter yazabilmesi için getche
		if (secim == '1')
		{
			system("CLS");       // ekranı temizleme görevi yapıyor
			printf("Kullanici Adi:");
			gets_s(kullanici); 
			if (strcmp(kullanici,"")==0) //iki tane stirng alıyo eşit ise 0 döndürüyor.
			{
				system("CLS");
				printf("\nBos Girdiniz!");
				_getch();
				
			}
			else
			{
				printf("Sifre:");
				for (int i = 0; i < 30; i++){              //şifreyi yıldız yaptırmak için kullandığımız döngü yapısıdır
					char a = _getche();
					if (a != '\r' && a != '\b'){           // aynı şeyi diğer kullanıcılar için de kullandık
						sifre[i] = a;
						printf("\b*");
					}
					else{
						sifre[i] = '\0';
						break;
					}
				}
				printf("\n");

				if (strcmp(sifre, "") == 0) //iki tane stirng alıyo eşit ise 0 döndürüyor.
				{
					system("CLS");
					printf("\nBos Girdiniz!");
					_getch();
				}
				else
				{
					errno_t err; // dosya hatası düzeltme için kullanıldı
					FILE *dosya;
					err = fopen_s(&dosya, "kullanici.txt", "r+");   //kullanıcı txt dosyasında okuma yaptırdık
					if (err != 0)                    // 0 a eşit değilse dosyaya bağlantı sağlamaz
					{
						printf("Dosya Acilamadi!!");
					}
					else
					{


						while (fscanf(dosya, "%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%c\n", admin.tc, admin.ad, admin.soyad, admin.tel, admin.adres, admin.eposta, admin.kullanici_adi, admin.sifre, &admin.yetki_turu) != EOF)
						{
							if ((strcmp(admin.kullanici_adi, kullanici) == 0) && (strcmp(admin.sifre, sifre) == 0) && (admin.yetki_turu == 'p')) // karşılaştırma yaptırır
							{
								fclose(dosya);
								anaMenu1(); //ana menü 1 e döndürüyor
							}
						}
						system("CLS");
						fclose(dosya);
						printf("Aradiginiz Kayit Bulunamadi!");
						_getch();
					}
				}

			}
		}
		else if (secim == '2')
		{
			system("CLS");
			printf("Kullanici Adi:");
			gets_s(kullanici);  // scanf_s ile de alabilirdik.
			if (strcmp(kullanici, "") == 0) //iki tane stirng alıyo eşit ise 0 döndürüyor.
			{
				system("CLS");
				printf("\nBos Girdiniz!");
				_getch();

			}
			else
			{
				printf("Sifre:");
				for (int i = 0; i < 30; i++){
					char a = _getche();
					if (a != '\r' && a != '\b'){
						sifre[i] = a;
						printf("\b*");
					}
					else{
						sifre[i] = '\0';
						break;
					}
				}
				printf("\n");
				if (strcmp(sifre, "") == 0) //iki tane stirng alıyo eşit ise 0 döndürüyor.
				{
					system("CLS");
					printf("\nBos Girdiniz!");
					_getch();
				}
				else
				{
					errno_t err;
					FILE *dosya;
					err = fopen_s(&dosya, "kullanici.txt", "r+");    // dosyada okuma işlemini yaptırıyor
					if (err != 0)
					{
						printf("Dosya Acilamadi!!");
					}
					else
					{


						while (fscanf(dosya, "%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%c\n", admin.tc, admin.ad, admin.soyad, admin.tel, admin.adres, admin.eposta, admin.kullanici_adi, admin.sifre, &admin.yetki_turu) != EOF)
						{
							if ((strcmp(admin.kullanici_adi, kullanici) == 0) && (strcmp(admin.sifre, sifre) == 0) && (admin.yetki_turu == 'm')) // yine karşılatırma yapıyor iki stringi  memur için
							{
								anaMenu2();
							}
						}
						system("CLS");
						printf("Aradiginiz Kayit Bulunamadi!");
						_getch();
					}
				}

			}
		}

		
		else if (secim == '3')
		{
			system("CLS");
			printf("Kullanici Adi:");
			gets_s(kullanici);
			if (strcmp(kullanici, "") == 0) //iki tane stirng alıyo eşit ise 0 döndürüyor.
			{
				system("CLS");
				printf("\nBos Girdiniz!");
				_getch();

			}
			else
			{
				printf("Sifre:");
				for (int i = 0; i < 30; i++){
					char a = _getche();
					if (a != '\r' && a != '\b'){
						sifre[i] = a;
						printf("\b*");
					}
					else{
						sifre[i] = '\0';
						break;
					}
				}
				printf("\n");
				if (strcmp(sifre, "") == 0) //iki tane stirng alıyo eşit ise 0 döndürüyor.
				{
					system("CLS");
					printf("\nBos Girdiniz!");
					_getch();
				}
				else
				{
					errno_t err;
					FILE *dosya;
					err = fopen_s(&dosya, "kullanici.txt", "r+");
					if (err != 0)
					{
						printf("Dosya Acilamadi!!");
					}
					else
					{


						while (fscanf(dosya, "%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%c\n", admin.tc, admin.ad, admin.soyad, admin.tel, admin.adres, admin.eposta, admin.kullanici_adi, admin.sifre, &admin.yetki_turu) != EOF)
						{
							if ((strcmp(admin.kullanici_adi, kullanici) == 0) && (strcmp(admin.sifre, sifre) == 0) && (admin.yetki_turu == 'g'))
							{
								anaMenu3();
							}
						}
						system("CLS");
						printf("Aradiginiz Kayit Bulunamadi!");
						_getch();
					}
				}

			}
		}
		else if (secim == '0')
		{
			exit(0);
		}
		else
		{
			system("CLS");
			printf("Lutfen dogru secim yapiniz");
			_getch();
		}
			
	}
}
void sifreDegistir()
{
	FILE *dosya;             //dosya yapısını tanımladık sadece void de tanımlayıp burda her seferinde tanılamayabilirdik
	int secenek;
	char ArananAd[20];
	char ArananSoyad[20];
	char yazilacakSifre[20];

	if ((dosya = fopen("kullanici.txt", "r+")) == NULL)  // dosyada kontrol yapıyor...
	{
		printf("Dosya Acilamadi!!\n");
	}
	else{  // eğer dosya açılırsa

		printf("Kullanici Adinizi giriniz :");
		scanf("%s", ArananAd);
		printf("Sifrenizi giriniz :");
		scanf("%s", ArananSoyad);
		int satirSayisi = 0;
		while (fscanf(dosya, "%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", admin.tc, admin.ad, admin.soyad,
			admin.tel, admin.adres, admin.eposta, admin.kullanici_adi, yazilacakSifre) != EOF) // tarama işlemi yapıyor her yerde olduğu gibi...
		{
			satirSayisi++;
			if (strcmp(ArananAd, admin.kullanici_adi) == 0 && strcmp(ArananSoyad, admin.sifre) == 0){

				printf("Yeni Sifreyi Giriniz:");
				scanf("%s", yazilacakSifre);
				fseek(dosya, 191 * (satirSayisi - 1), SEEK_SET); // 191 satırsayıları bir eksiği ve tab'lar toplamıdır..

				fprintf(dosya, "%-11s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-24s\t\t%-49s\t\t%-14s\t\t%-19s\n", admin.tc, admin.ad, admin.soyad,
					admin.tel, admin.adres, admin.eposta, admin.kullanici_adi, yazilacakSifre);   //örneğin %-19s en sola yapıştırmak için o bilgiyi
				fclose(dosya);
				printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
				
			}

		}



	}


}
void anaMenu1()
{
	system("Color 1B");
	char secim;
	for (;;)
	{
		system("CLS");
		printf("===PATRON  ISLEMLERI===\n");
		printf("PATRONSUN!!! \n\n");
		printf("1-->Siginmaci Ekle\n");
		printf("2-->Siginmaci Sil\n");
		printf("3-->Siginmaci Guncelle\n");
		printf("4-->Siginmaci Arama\n");
		printf("5-->Siginmaci Listele\n");
		printf("6-->Memur Ekle\n");
		printf("7-->Memur Sil\n");
		printf("8-->Memur Listele\n");
		printf("9-->Sifre Degistir\n");
		printf("+-->kullanici sil\n");
		printf("*-->Kullanici Listele\n");// ek özellik katıldı
		printf("0-->Cikis Yap\n");
		printf("Seciminiz:");
		secim = _getche();
		if (secim == '1')
		{
			siginmaciEkle();
		}
		else if (secim == '2')
		{
			siginmaciSil();
		}
		else if (secim == '3')
		{
			siginmaciGuncelle();

		}
		else if (secim == '4')
		{
			siginmaciArama();
		}
		else if (secim == '5')
		{
			siginmaciListele();

		}
		else if (secim == '6')
		{
			memurEkle();
		}
		else if (secim == '7')
		{
			memurSil();
		}
		else if (secim == '8')
		{
			memurListele();
		}
		else if (secim == '9')
		{
			sifreDegistir();
		}
		else if (secim == '0')
		{
			_flushall();
			adminGiris();
		}
		else if (secim == '+')
		{
			_flushall();
			kullanıcıSil();
		}
		else if (secim == '*')
		{
			_flushall(); // ram i temizlemek için kullanıldı
			kullaniciListele();
		}
		
		else
		{
			system("CLS");
			printf("Lutfen dogru secim yapiniz");
			_getch();
		}

	}
}
void anaMenu2()
{
	system("Color 1B");
	char secim;
	for (;;)
	{
		system("CLS");
		printf("===MEMUR İSLEMLERİ===\n");
		printf("Memursun!!! \n\n");
		printf("||1--->Siginmaci Ekle\n");
		printf("||2--->Siginmaci Sil\n");
		printf("||3--->Siginmaci Guncelle\n");
		printf("||4--->Siginmaci Arama\n");
		printf("||5--->Siginmaci Listele\n");
		printf("||9--->Sifre Degistir\n");
		printf("||0--->Cikis Yap\n");
		secim = _getche();
		if (secim == '1')
		{
			siginmaciEkle();
		}
		else if (secim == '2')
		{
			siginmaciSil();
		}
		else if (secim == '3')
		{
			siginmaciGuncelle();

		}
		else if (secim == '4')
		{
			siginmaciArama();
		}
		else if (secim == '5')
		{
			siginmaciListele();

		}
		else if (secim == '9')
		{
			sifreDegistir();
		}
		else if (secim == '0')
		{
			_flushall();
			adminGiris();
		}
		else
		{
			system("CLS");
			printf("Lutfen dogru secim yapiniz");
			_getch();
		}

	}
}
void anaMenu3()
{
	system("Color 1B");
	char secim;
	for (;;)
	{
		system("CLS");
		printf("===GOZLEMCİ İSLEMLERİ===\n");
		printf("Gozlemcisin!!!\n\n"); 
		printf("||4--->Siginmaci Arama\n");
		printf("||5--->Siginmaci Listele\n");
		printf("||9--->Sifre Degistir\n");
		printf("||0--->Cikis Yap\n");
		secim = _getche();
		
	    if (secim == '4')
		{
			siginmaciArama();
		}
		else if (secim == '5')
		{
			siginmaciListele();
		}
		else if (secim == '9')
		{
			sifreDegistir();
		}
		else if (secim == '0')
		{
			_flushall();
			adminGiris();
		}
		else
		{
			system("CLS");
			printf("Lutfen dogru secim yapiniz");
			_getch();
		}

	}
} 
void siginmaciEkle()
{
	FILE *dosya;
	errno_t err;
	err = fopen_s(&dosya, "siginmaci.txt", "r+"); //ikinci bir dosya olan siginmaci kulladık ve okuttuk

	if (err != 0)
	{
		printf("Dosya Acilamadi!!");
	}
	else
	{
		int count = 1;// sayacı ilk baş bir aldık..
		while (fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\n",
			&siginan.siginmaci_no, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
			&siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
			siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta) != EOF)
		{

			if (siginan.siginmaci_no == NULL) //boş değerde break yapar
			{
				count = 1;
				break;
			}
			else
			{
				count = ++(siginan.siginmaci_no); //değilse  ilk başta olan sığınmacı numarasını artırır
			}

		}
		system("CLS");
#pragma region AdAlgoritması


		bool dogruAd = false;        //false ise do ya girer       boolean yöntemi kolaylık sağlıyoralttaki ad soyad vb. algoritmalardada kullandık bunu
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Adini Giriniz:");
			gets_s(siginan.ad);
			if (strcmp(siginan.ad, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruAd = true;
				int karakterDogrulamaSayisi = 0;
				char adKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',             //kontroller yapıldı sadece harf girilebilir
					'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',
					'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
					'|', '`', 'é', '"', '<' };
				for (int i = 0; i < strlen(siginan.ad); i++){
					for (int j = 0; j < 39; j++)
					{
						if (siginan.ad[i] == adKontrol[j])
						{
							dogruAd = false;
							break;
						}
					}
				}
			}



		} while (dogruAd == false);

#pragma endregion

#pragma region SoyadAlgoritması


		bool dogruSoyad = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin soyadini Giriniz:");
			gets_s(siginan.soyad);
			if (strcmp(siginan.soyad, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruSoyad = true;
				int karakterDogrulamaSayisi = 0;
				char soyadKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',
					'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',     //kontroller yapıldı
					'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
					'|', '`', 'é', '"', '<' };
				for (int i = 0; i < strlen(siginan.soyad); i++){
					for (int j = 0; j < 39; j++)
					{
						if (siginan.soyad[i] == soyadKontrol[j])
						{
							dogruSoyad = false;
							break;
						}
					}
				}
			}


		} while (dogruSoyad == false);

#pragma endregion

#pragma region DogumTarihiAlgoritmasi
		bool dogruDT = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Dogum Tarihini Giriniz(aralara nokta konulacak):");
			gets_s(siginan.dogum_tarihi);
			if (strcmp(siginan.dogum_tarihi, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruDT = true;
				int karakterDogrulamaSayisi = 0;
				char DTKontrol[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.' };
				for (int i = 0; i < strlen(siginan.dogum_tarihi); i++){
					for (int j = 0; j < 11; j++)
					{
						if (siginan.dogum_tarihi[i] == DTKontrol[j]){
							karakterDogrulamaSayisi++;
							break;
						}
					}
				}
				if (karakterDogrulamaSayisi != strlen(siginan.dogum_tarihi))
					dogruDT = false;
			}



		} while (dogruDT == false);
#pragma endregion

#pragma region DogumYeriAlgoritması


		bool dogruDY = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Dogum Yerini Giriniz:");
			gets_s(siginan.dogum_yeri);
			if (strcmp(siginan.dogum_yeri, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruDY = true;
				int karakterDogrulamaSayisi = 0;
				char DYKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',
					'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',
					'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
					'|', '`', 'é', '"', '<' };
				for (int i = 0; i < strlen(siginan.dogum_yeri); i++){
					for (int j = 0; j < 39; j++)
					{
						if (siginan.dogum_yeri[i] == DYKontrol[j])
						{
							dogruDY = false;
							break;
						}
					}
				}
			}


		} while (dogruDY == false);

#pragma endregion

#pragma region Cinsiyet

		
		for (;;)
		{
			system("CLS");
			char secim;
			printf("Cinsiyet Secin\n1-Erkek\n2-Kadin\nSecim:");
			secim = _getche();
			if (secim == '1')
			{
				strcpy(siginan.cinsiyet,"E");
				break;
			}
			else if (secim == '2')
			{
				strcpy(siginan.cinsiyet,"K");
				break;
			}
			else
			{
				system("CLS");
				printf("Dogru Secim yapiniz.");
				_getch();
			}

		}
#pragma endregion  


#pragma region UyrukAlgoritması


		bool dogruUyruk = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Uyrugunu Giriniz:");
			gets_s(siginan.uyruk);
			if (strcmp(siginan.uyruk, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruUyruk = true;
				int karakterDogrulamaSayisi = 0;
				char uyrukKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',
					'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',
					'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
					'|', '`', 'é', '"', '<' };
				for (int i = 0; i < strlen(siginan.uyruk); i++){
					for (int j = 0; j < 39; j++)
					{
						if (siginan.uyruk[i] == uyrukKontrol[j])
						{
							dogruUyruk = false;
							break;
						}
					}
				}
			}


		} while (dogruUyruk == false);

#pragma endregion

#pragma region MeslekAlgoritması


		bool dogruMeslek = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Meslegini Giriniz:");
			gets_s(siginan.meslek);
			if (strcmp(siginan.meslek, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruMeslek = true;
				int karakterDogrulamaSayisi = 0;
				char meslekKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',
					'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',
					'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
					'|', '`', 'é', '"', '<' };
				for (int i = 0; i < strlen(siginan.meslek); i++){
					for (int j = 0; j < 39; j++)
					{
						if (siginan.meslek[i] == meslekKontrol[j])
						{
							dogruMeslek = false;
							break;
						}
					}
				}
			}


		} while (dogruMeslek == false);

#pragma endregion

#pragma region EgitimDurumuAlgoritması


		bool dogruED = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Egitim Durumunu Giriniz:");
			gets_s(siginan.egitim_durumu);
			if (strcmp(siginan.egitim_durumu, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruED = true;
				int karakterDogrulamaSayisi = 0;
				char EDKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',
					'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',
					'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
					'|', '`', 'é', '"', '<' };
				for (int i = 0; i < strlen(siginan.egitim_durumu); i++){
					for (int j = 0; j < 39; j++)
					{
						if (siginan.egitim_durumu[i] == EDKontrol[j])
						{
							dogruED = false;
							break;
						}
					}
				}
			}


		} while (dogruED == false);

#pragma endregion

#pragma region TelAlgoritması


		bool dogruTel = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Tel No'yu Giriniz (+901234567890):");
			gets_s(siginan.telefon);
			if (strcmp(siginan.telefon,"") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruTel = true;
				int karakterDogrulamaSayisi = 0;
				char telKontrol[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '+' };
				for (int i = 0; i < strlen(siginan.telefon); i++){
					for (int j = 0; j < 11; j++)
					{
						if (siginan.telefon[i] == telKontrol[j]){
							karakterDogrulamaSayisi++;
							break;
						}
					}
				}
				if (karakterDogrulamaSayisi != 13 || siginan.telefon[0] != '+') // +90 mantığı için yaptım
					
					dogruTel = false;
			}



		} while (dogruTel == false);

#pragma endregion

		system("CLS");
		printf("Lutfen Kullanicinin Adresini Giriniz:");
		gets_s(siginan.yerlestirildigi_adres);

#pragma region SehirAlgoritması


		bool dogruSehir = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Geldigi Sehri Giriniz:");
			gets_s(siginan.geldigi_sehir);
			if (strcmp(siginan.geldigi_sehir, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruSehir = true;
				int karakterDogrulamaSayisi = 0;
				char sehirKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',
					'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',
					'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
					'|', '`', 'é', '"', '<' };
				for (int i = 0; i < strlen(siginan.geldigi_sehir); i++){
					for (int j = 0; j < 39; j++)
					{
						if (siginan.geldigi_sehir[i] == sehirKontrol[j])
						{
							dogruSehir = false;
							break;
						}
					}
				}
			}


		} while (dogruSehir == false);

#pragma endregion

#pragma region GelisTarihiAlgoritmasi
		bool dogruGT = false;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Gelis Tarihini Giriniz(aralara nokta konulacak):");
			gets_s(siginan.gelis_tarihi);
			if (strcmp(siginan.gelis_tarihi, "") == 0)
			{
				system("CLS");
				printf("Bos girdiniz!");
				_getch();
			}
			else
			{
				dogruGT = true;
				int karakterDogrulamaSayisi = 0;
				char GTKontrol[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.' };
				for (int i = 0; i < strlen(siginan.gelis_tarihi); i++){
					for (int j = 0; j < 11; j++)
					{
						if (siginan.gelis_tarihi[i] == GTKontrol[j]){
							karakterDogrulamaSayisi++;
							break;
						}
					}
				}
				if (karakterDogrulamaSayisi != strlen(siginan.gelis_tarihi))
					dogruGT = false;

			}

		} while (dogruGT == false);
#pragma endregion
#pragma region e posta




		for (;;)
		{
			system("CLS");
			char secim;
			printf("e-posta Adresi var mi?\n1-Var\n2-Yok\nSecim:");
			secim = _getche();
			if (secim == '1')
			{

				system("CLS");
				printf("\n");
				printf("Lutfen Kullanicinin e-posta adresini Giriniz(orn:a@b.com):");
				gets_s(siginan.eposta);
				break;
			}
			else if (secim == '2')
			{
				strcpy(siginan.eposta,"yok");
				//siginan.eposta[0] = 'Y';
				//siginan.eposta[1] = 'o';
				//siginan.eposta[2] = 'k';
				//siginan.eposta[3] = '\0';
				break;
			}
			else
			{
				system("CLS");
				printf("Lutfen dogru secim yapiniz.");
				_getch();
			}

		}

#pragma endregion
		fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
			count, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
			siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
			siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
		system("CLS");
		printf("Kayit yapildi");
		_getch();
		fclose(dosya);
		anaMenu1();

	}



} // yapıldı
void siginmaciSil()
{
	FILE *dosya;
	char silinecekAd[30];
	char silinecekSoyad[30];

	char sil[20] = "";

	if ((dosya = fopen("siginmaci.txt", "r+")) == NULL)        //DOSYA AÇILMIYORSA
	{
		printf("Dosya Acilamadi!!");
	}

	printf("Silmek Istediginiz Kisinin Adi :");
	scanf("%s", silinecekAd);
	printf("Silmek Istediginiz Kisinin Soyadi :");
	scanf("%s", silinecekSoyad);
	int satirSayisi = 0;
	while (fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",  &siginan.siginmaci_no, siginan.ad,
		siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
		siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu,
		siginan.telefon, siginan.yerlestirildigi_adres, siginan.geldigi_sehir,
		siginan.gelis_tarihi, siginan.eposta) != EOF)
	{
		satirSayisi++;
		if (strcmp(silinecekAd, siginan.ad) == 0 && strcmp(silinecekSoyad, siginan.soyad) == 0) // karşılaştırma
		{

			fseek(dosya, 303 * (satirSayisi - 1), SEEK_SET);

			fprintf(dosya, "%s\t\t%-5s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n", "", "", "",
				"", "", "",
				"", "", "", "",
				"", "", "",
				"", "");       // bos stringleri tanımladık bu "" ile

			fclose(dosya);

			printf("\n\nSILME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
			_getch();

		}
	}
} 
void siginmaciGuncelle()
{
	FILE *dosya;
	int secenek;
	char ArananAd[20];
	char ArananSoyad[20];
	char ArananSehir[20];
	char ArananUyruk[20];
	char ArananMeslek[20];
	char ArananYerlestirildigi[20];

	char bosString[20];
	char yazilacakBilgi[30]; //yeni bir char açtık yazılacak bilgiler için
	char yazilacakEposta[40];


	if ((dosya = fopen("siginmaci.txt", "r+")) == NULL)        //DOSYA AÇILMIYORSA
	{
		printf("Dosya Acilamadi!!");
	}

	else{  // DOSYA ACILIRSA

		printf("Guncellemek Istediginiz Kisinin Adi :");
		scanf("%s", ArananAd);
		printf("Guncellemek Istediginiz Kisinin Soyadi :");
		scanf("%s", ArananSoyad);
		int satirSayisi = 0;
		while (fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",  &siginan.siginmaci_no, siginan.ad,
			siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
			siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu,
			siginan.telefon, siginan.yerlestirildigi_adres, siginan.geldigi_sehir,
			siginan.gelis_tarihi, siginan.eposta) != EOF)
		{
			satirSayisi++;
			if (strcmp(ArananAd, siginan.ad) == 0 && strcmp(ArananSoyad, siginan.soyad) == 0 ) // karşılaştırma
			{
				printf("Guncellemek Istidiginiz bilgiyi seciniz :\n");
				printf("1-Ad\n");
				printf("2-Soyad\n");
				printf("3-Dogum Tarihi\n");
				printf("4-Dogum Yeri\n");
				printf("5-Cinsiyet\n");
				printf("6-Uyruk\n");
				printf("7-Meslek\n");
				printf("8-Egitim Durumu\n");
				printf("9-Telefon\n");
				printf("10-Yerlestildigi Il\n");
				printf("11-Geldigi Sehir\n");
				printf("12-Gelis Tarihi\n");
				printf("13-E-Posta\n");
				printf("Guncellemek Istediginiz Bilginin Numarasini Giriniz:");
				scanf("%d", &secenek);

				switch (secenek)
				{
				case 1:
				{
						  printf("Yeni Adi Giriniz:");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, yazilacakBilgi, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							  siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						  fclose(dosya);

						  printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						  break;
				}
				case 2:
				{
						  printf("Yeni Soyadi Giriniz :");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, siginan.ad,yazilacakBilgi,siginan.dogum_tarihi,siginan.dogum_yeri,
							  siginan.cinsiyet,siginan.uyruk,siginan.meslek,siginan.egitim_durumu,siginan.telefon,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir,siginan.gelis_tarihi,siginan.eposta);
						  fclose(dosya);
						  printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						  break;
				}
				case 3:
				{
						  printf("Yeni Dogum Tarihi :");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, siginan.ad, siginan.soyad, yazilacakBilgi, siginan.dogum_yeri,
							  siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						  fclose(dosya);

						  break;
				}
				case 4:
				{
						  printf("Yeni Dogum Yeri :");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, yazilacakBilgi,
							  siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						  fclose(dosya);

						  printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						  break;
				}
				case 5:
				{
						  printf("Yeni Cinsiyet :");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							  yazilacakBilgi, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						  fclose(dosya);

						  printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						  break;
				}
				case 6:
				{
						  printf("Yeni Uyruk :");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							  siginan.cinsiyet, yazilacakBilgi, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						  fclose(dosya);

						  printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						  break;
				}
				case 7:
				{
						  printf("Yeni Meslek :");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);
						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							  siginan.cinsiyet, siginan.uyruk, yazilacakBilgi, siginan.egitim_durumu, siginan.telefon,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						  fclose(dosya);

						  printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						  break;
				}
				case 8:
				{
						  printf("Yeni Egitim Durumu :");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							  siginan.cinsiyet, siginan.uyruk, siginan.meslek, yazilacakBilgi, siginan.telefon,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						  fclose(dosya);

						  printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						  break;
				}
				case 9:
				{
						  printf("Yeni Telefon:");
						  scanf("%s", yazilacakBilgi);
						  fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						  fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							  1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							  siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, yazilacakBilgi,
							  siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						  fclose(dosya);

						  printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						  break;
				}
				case 10:
				{
						   printf("Yeni Yerlestirildigi Il :");
						   scanf("%s", yazilacakBilgi);
						   fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						   fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							   1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							   siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							   yazilacakBilgi, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
						   fclose(dosya);

						   printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						   break;
				}
				case 11:
				{
						   printf("Yeni Geldigi Sehir :");
						   scanf("%s", yazilacakBilgi);
						   fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET); // sıgınmacı no  dan dolayı

						   fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							   1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							   siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							   siginan.yerlestirildigi_adres, yazilacakBilgi, siginan.gelis_tarihi, siginan.eposta);
						   fclose(dosya);
						   printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						   break;
				}
				case 12:
				{
						   printf("Yeni Gelis Tarihi :");
						   scanf("%s", yazilacakBilgi);
						   fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						   fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							   1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							   siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							   siginan.yerlestirildigi_adres, siginan.geldigi_sehir, yazilacakBilgi, siginan.eposta);
						   fclose(dosya);

						   printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						   break;
				}
				case 13:
				{
						   printf("Yeni E-posta :");
						   scanf("%s", yazilacakEposta);
						   fseek(dosya, 323 * (satirSayisi - 1), SEEK_SET);

						   fprintf(dosya, "%5d\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-39s\n",
							   1, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
							   siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
							   siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, yazilacakBilgi);

						   fclose(dosya);

						   printf("\n\nGUNCELLEME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
						   break;
				}


				default:
					printf("Yanlis Secim Yaptiniz!!");
					break;
				}
				_getch();

				break;
			}
		}

	}

	//fclose(dosya);

}		
void siginmaciArama(){

	//Yerleştirildiği ile, geldiği şehre, uyruğa, mesleğe, ada, soyada
	FILE *dosya;
	int secenek;
	char ArananAd[30];
	char ArananSoyad[30];
	char ArananSehir[15];
	char ArananUyruk[15];
	char ArananMeslek[15];
	char ArananYerlestirildigi[20];

	
	if ((dosya = fopen("siginmaci.txt", "r")) == NULL) // okuma işlemi yapıldı
	{
		printf("Dosya Acilamadi!!");
	}

	system("CLS");
	printf("\n1.Ada Gore\n");
	printf("2.Soyada Gore\n");
	printf("3.Geldigi Sehre Gore\n");
	printf("4.Uyruga Gore\n");
	printf("5.Meslege Gore\n");
	printf("6.Yelestigi Ile Gore\n");
	printf("\n\nLutfen Hangi Baslikta Arama Yapmak Istediginizi Seciniz:");
	scanf("%d", &secenek);

	printf("\n");
	int sonucSayisi = 0;
	switch (secenek)
	{
	case 1:

		printf("Lutfen Aramak Istediginiz Kisinin Adini Giriniz:");
		scanf("%s", ArananAd);

		while (!feof(dosya)) // arama yaptırma 
		{
			fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",&siginan.siginmaci_no, siginan.ad,
				siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
				siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu,
				siginan.telefon, siginan.yerlestirildigi_adres, siginan.geldigi_sehir,
				siginan.gelis_tarihi, siginan.eposta);

			if (strcmp(ArananAd, siginan.ad) == 0) // buldugu zaman gerceklestir
			{
				
				printf("%s %s",siginan.ad,siginan.soyad); // sadece ada ve soyada göre istenildiği için yaptık
					sonucSayisi++;
					printf("\n\n%d kadar kişi bulundu",sonucSayisi);
				
			}


		}
		if (sonucSayisi == 0){

			printf("Aradiginiz Kisi Bulanamadi!\n\a");
		}
		_getch();
		fclose(dosya);
		break;


	case 2:
		printf("Lutfen Aramak Istediginiz Kisinin Soyadini Giriniz:");
		scanf("%s", ArananSoyad);

		while (!feof(dosya))
		{
			fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", &siginan.siginmaci_no, siginan.ad,
				siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
				siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu,
				siginan.telefon, siginan.yerlestirildigi_adres, siginan.geldigi_sehir,
				siginan.gelis_tarihi, siginan.eposta);
			if (strcmp(ArananSoyad, siginan.soyad) == 0) // strcmp(s1,s2) iki string eşitse 0 esit  s1>s2 => 1 , s2>s1 =>-1 döndürür
			{
				
				printf("%s %s", siginan.ad, siginan.soyad);  
					sonucSayisi++;
					printf("\n\n%d kadar kişi bulundu", sonucSayisi);
			}
		}


		if (sonucSayisi == 0){

			printf("Aradiginiz Kisi Bulanamadi!\n\a");
		}
		_getch();

		fclose(dosya);

		break;

	case 3:
		printf("\n\nLutfen Aramak Istediginiz Kisinin Geldigi Sehri Giriniz:");
		scanf("%s", ArananSehir);

		while (!feof(dosya))
		{
			fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", &siginan.siginmaci_no, siginan.ad,
				siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
				siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu,
				siginan.telefon, siginan.yerlestirildigi_adres, siginan.geldigi_sehir,
				siginan.gelis_tarihi, siginan.eposta);
			if (strcmp(ArananSehir, siginan.geldigi_sehir) == 0)
			{
				
				printf("%s %s", siginan.ad, siginan.soyad);
					sonucSayisi++;
					printf("\n\n%d kadar kişi bulundu", sonucSayisi);
				
			}
		}
		if (sonucSayisi == 0){

			printf("Aradiginiz Kisi Bulanamadi!\n\a");
		}
		_getch();

		fclose(dosya);


		break;


	case 4:
		printf("Lutfen Aramak Istediginiz Kisinin Uyruk Bilgisini Giriniz:");
		scanf("%s", ArananUyruk);

		while (!feof(dosya))
		{
			fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",  &siginan.siginmaci_no, siginan.ad,
				siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
				siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu,
				siginan.telefon, siginan.yerlestirildigi_adres, siginan.geldigi_sehir,
				siginan.gelis_tarihi, siginan.eposta);
			if (strcmp(ArananUyruk, siginan.uyruk) == 0)
			{
				
				printf("%s %s", siginan.ad, siginan.soyad);
					sonucSayisi++;
					printf("\n\n%d kadar kişi bulundu", sonucSayisi);
				
			}
		}
		if (sonucSayisi == 0){

			printf("Aradiginiz Kisi Bulanamadi!\n\a");
		}
		_getch();

		fclose(dosya);

		break;

	case 5:
		printf("Lutfen Aramak Istediginiz Kisinin Meslegini Giriniz:");
		scanf("%s", ArananMeslek);

		while (!feof(dosya))
		{
			fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", &siginan.siginmaci_no, siginan.ad,
				siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
				siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu,
				siginan.telefon, siginan.yerlestirildigi_adres, siginan.geldigi_sehir,
				siginan.gelis_tarihi, siginan.eposta);
			if (strcmp(ArananMeslek, siginan.meslek) == 0)
			{
				
				printf("%s %s", siginan.ad, siginan.soyad);
					sonucSayisi++;
					printf("\n\n%d kadar kişi bulundu", sonucSayisi);
			}

		}
		if (sonucSayisi == 0){

			printf("Aradiginiz Kisi Bulanamadi!\n\a");
		}

		_getch();

		fclose(dosya);

		break;

	case 6:
		printf("Lutfen Aramak Istediginiz Ili Giriniz:");
		scanf("%s", ArananYerlestirildigi);

		while (!feof(dosya))
		{
			fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", &siginan.siginmaci_no, siginan.ad,
				siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
				siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu,
				siginan.telefon, siginan.yerlestirildigi_adres, siginan.geldigi_sehir,
				siginan.gelis_tarihi, siginan.eposta);
			if (strcmp(ArananYerlestirildigi, siginan.yerlestirildigi_adres) == 0)
			{
				
				printf("%s %s", siginan.ad, siginan.soyad);
					sonucSayisi++;
					printf("\n\n%d kadar kişi bulundu", sonucSayisi);
				
			}

		}

		if (sonucSayisi == 0){

			printf("Aradiginiz Kisi Bulanamadi!\n\a");
		}
		_getch();

		fclose(dosya);

		break;

	default:
		printf("Yanlis bir secim yaptiniz\n");
		_getch();
		break;

	}

	fclose(dosya);


}
void siginmaciListele()
{
	system("CLS");
	FILE *dosya;
	errno_t err;
	err = fopen_s(&dosya, "siginmaci.txt", "r+");
	if (err != 0)
	{
		printf("Dosya Acilamadi!!");
	}
	else
	{
		int count = 1;
		while ( !feof(dosya))
		{
			fscanf(dosya, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%c\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\n",
				&siginan.siginmaci_no, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
				&siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
				siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
			printf("\n\n%d nolu Siginmaci\nAd:%s\nSoyad:%s\nDogum Tarihi:%s\nDogum Yeri:%s\nCinsiyet:%c\nUyruk:%s\nMeslek:%s\nEgitim Durumu:%s\nTelefon:%s\nYerlestirildigi Adres:%s\nGeldigi Sehir:%s\nGelis Tarihi:%s\nEposta:%s\n\n",
				siginan.siginmaci_no, siginan.ad, siginan.soyad, siginan.dogum_tarihi, siginan.dogum_yeri,
				siginan.cinsiyet, siginan.uyruk, siginan.meslek, siginan.egitim_durumu, siginan.telefon,
				siginan.yerlestirildigi_adres, siginan.geldigi_sehir, siginan.gelis_tarihi, siginan.eposta);
			count++;
			_getch();
		}
		printf("Toplam %d adet Siginmaci bulundu", count - 1); //kaç kişi girildiyse bir eksiği çıkacaktır
		_getch();
		fclose(dosya);
		anaMenu1();
	}

}
void memurEkle()
{
	FILE *dosya;
	errno_t err;
	err = fopen_s(&dosya, "kullanici.txt", "a");
	if (err != 0)
	{
		printf("Dosya Acilamadi!!");
	}
	else
	{


#pragma region KimlikAlgoritmasi
		bool dogruTc;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin TC Kimlik Numarasini Giriniz:");
			gets_s(admin.tc);
			dogruTc = true;
			int karakterDogrulamaSayisi = 0;
			char tcKontrol[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
			for (int i = 0; i < 11; i++){
				for (int j = 0; j < 10; j++)
				{
					if (admin.tc[i] == tcKontrol[j]){
						karakterDogrulamaSayisi++;
						break;
					}
				}
			}
			if (karakterDogrulamaSayisi != 11)
				dogruTc = false;



		} while (dogruTc == false);
#pragma endregion

#pragma region AdAlgoritması


		bool dogruAd;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Adini Giriniz:");
			gets_s(admin.ad);
			dogruAd = true;
			int karakterDogrulamaSayisi = 0;
			char adKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',
				'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',
				'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
				'|', '`', 'é', '"', '<' };
			for (int i = 0; i < strlen(admin.ad); i++){
				for (int j = 0; j < 39; j++)
				{
					if (admin.ad[i] == adKontrol[j])
					{
						dogruAd = false;
						break;
					}
				}
			}


		} while (dogruAd == false);

#pragma endregion

#pragma region SoyadAlgoritması



		bool dogruSoyad;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Soyadini Giriniz:");
			gets_s(admin.soyad);
			dogruSoyad = true;
			int karakterDogrulamaSayisi = 0;
			char soyadKontrol[39] = { '1', '2', '3', '4', '5', '6', '7', '8',
				'9', '0', '*', '!', '^', '+', '%', '&', '/', '(', ')', '=', '?',
				'_', '-', ':', ';', '>', '£', '#', '$', '½', '{', '[', ']', '}',
				'|', '`', 'é', '"', '<' };
			for (int i = 0; i < strlen(admin.soyad); i++){
				for (int j = 0; j < 39; j++)
				{
					if (admin.soyad[i] == soyadKontrol[j])
					{
						dogruSoyad = false;
						break;
					}
				}
			}


		} while (dogruSoyad == false);
#pragma endregion

#pragma region TelAlgoritması


		bool dogruTel;
		do{
			system("CLS");
			printf("\n");
			printf("Lutfen Kullanicinin Tel No'yu Giriniz:");
			gets_s(admin.tel);
			dogruTel = true;
			int karakterDogrulamaSayisi = 0;
			char telKontrol[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '+' };
			for (int i = 0; i < 11; i++){
				for (int j = 0; j < 11; j++)
				{
					if (admin.tc[i] == telKontrol[j]){
						karakterDogrulamaSayisi++;
						break;
					}
				}
			}
			if (karakterDogrulamaSayisi != 11)
				dogruTel = false;



		} while (dogruTel == false);

#pragma endregion

		system("CLS");
		printf("Lutfen kullanicinin adresini giriniz:");
		gets_s(admin.adres);
		system("CLS");
		printf("Lutfen kullanicinin eposta adresini giriniz:");
		gets_s(admin.eposta);
		system("CLS");
		printf("Lutfen kullanicinin kullanici adini giriniz:");
		gets_s(admin.kullanici_adi);
		system("CLS");
		printf("Lutfen kullanicinin sifresini giriniz:");
		gets_s(admin.sifre);
		for (;;)
		{
			system("CLS");
			printf("1-Patron\n2-Memur\n3-Gozlemci\nYetki Turu:");
			char secim = _getche();
			if (secim == '1')
			{
				fprintf(dosya, "\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tp", admin.tc,
					admin.ad, admin.soyad, admin.tel, admin.adres, admin.eposta,
					admin.kullanici_adi, admin.sifre);
				break;
			}
			else if (secim == '2')
			{
				fprintf(dosya, "\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tm", admin.tc,
					admin.ad, admin.soyad, admin.tel, admin.adres, admin.eposta,
					admin.kullanici_adi, admin.sifre);
				break;
			}
			else if (secim == '3')
			{
				fprintf(dosya, "\n%-11s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-24s\t\t%s\t\t%-49s\t\t%-14s\t\tg", admin.tc,
					admin.ad, admin.soyad, admin.tel, admin.adres, admin.eposta,
					admin.kullanici_adi, admin.sifre);
				break;
			}
			else
			{
				system("CLS");
				printf("Lutfen dogru secim yapiniz");
				_getch();
			}
		}
	}
	system("CLS");
	printf("Tebrikler, kayit basariyla eklendi.");
	_getch();
	fclose(dosya);
	anaMenu1();

	

	


}
void memurSil()
{
	FILE *dosya;
	char AranilanAd[20];
	char AranilanSoyad[20];
	char sil[] = "";
	char silinecekİsim[20];
	if ((dosya = fopen("kullanici.txt", "r+")) == NULL)  //Kontrol yapısı
	{
		printf("Dosya Acilamadi!!\n");
	}

	else{
		int satirSayisi = 0;
		printf("Silmek istediginiz Kullanicinin Adinini giriniz :");
		scanf("%s", AranilanAd);
		printf("Silmek istediginiz Kullanicinin Sifresini giriniz :");
		scanf("%s", AranilanSoyad);
		while (fscanf(dosya, "%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", admin.tc, admin.ad, admin.soyad,
			admin.tel, admin.adres, admin.eposta, admin.kullanici_adi, admin.sifre) != EOF)
		{
			satirSayisi++;
			if (strcmp(AranilanAd, admin.ad) == 0 && strcmp(AranilanSoyad, admin.soyad) == 0){

				fseek(dosya, 196 * (satirSayisi - 1), SEEK_SET);

				fprintf(dosya, "%-11s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-24s\t\t%-49s\t\t%-14s\t\t%-19s\n", "", "", "", "",
					"", "", "", "", "");
				fclose(dosya);
				printf("\n\nSILME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
				_getch();
			}
		}



	}







}
void memurListele()
{
	system("CLS");
	FILE *dosya;
	errno_t err;
	err = fopen_s(&dosya, "kullanici.txt", "r");
	if (err != 0)
	{
		printf("Dosya Acilamadi!!");
	}
	else
	{
		int count = 1;
		while (fscanf(dosya, "%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%c\n", admin.tc, admin.ad, admin.soyad, admin.tel,
			admin.adres, admin.eposta, admin.kullanici_adi, admin.sifre, &admin.yetki_turu) != EOF)
		{
			if (strcmp(admin.ad,"s"))
			{


				printf("\n\n%d.nci Kullanici\nTC:%s\nAd:%s\nSoyad:%s\nTel:%s\nAdres:%s\nEposta:%s\nKullanici Adi:%s\nSifre:%s\nYetki Turu:%c\n\n",
					count, admin.tc, admin.ad, admin.soyad, admin.tel,
					admin.adres, admin.eposta, admin.kullanici_adi, admin.sifre, admin.yetki_turu);
				count++;
			}
		}
		printf("Toplam %d adet memur bulundu", count - 1);
		_getch();
		fclose(dosya);
		anaMenu1();
	}
}
void kullanıcıSil()
{
	FILE *dosya;
	char ArananAd[20];
	char ArananSoyad[20];
	char sil[] = "";
	if ((dosya = fopen("kullanici.txt", "r+")) == NULL)  //Kontrol yapısı
	{
		printf("Dosya Acilamadi!!\n");
	}

	else{
		int satirSayisi = 0;
		printf("Silmek istediginiz Kullanicinin Adinini giriniz :");
		gets_s( ArananAd);
		printf("Silmek istediginiz Kullanicinin soyadini giriniz :");
		gets_s(ArananSoyad);
		while (fscanf(dosya, "%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",admin.tc, admin.ad, admin.soyad,
			admin.tel, admin.adres, admin.eposta, admin.kullanici_adi, admin.sifre) != EOF)
		{
			satirSayisi++;
			if (strcmp(ArananAd, admin.ad) == 0 && strcmp(ArananSoyad, admin.soyad) == 0){

				fseek(dosya, 196 * (satirSayisi - 1), SEEK_SET);

				fprintf(dosya, "%-11s\t\t%-19s\t\t%-19s\t\t%-19s\t\t%-24s\t\t%-49s\t\t%-14s\t\t%-19s\n", "s", "s", "s", "s",
					"s", "s", "s", "s", "s");
				fclose(dosya);
				printf("\n\nSILME ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR.");
				_getch();
			}
		}



	}
}

void kullaniciListele(){
	

	FILE *dosya;          //sadece admin tarfından görülen fonksiyondur ek yapılmıştır

	if ((dosya = fopen("kullanici.txt", "r")) == NULL)  //Kontrol yapısı
	{
		printf("Dosya Acilamadi!!\n");
	}
	else{
		while (fscanf(dosya, "%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",  admin.tc, admin.ad, admin.soyad,
			admin.tel, admin.adres, admin.eposta, admin.kullanici_adi, admin.sifre) != EOF)

		{
			
				Listem2(admin);  // struct göndererek işlemi yaptırdık
			

		}
		_getch();
		printf("Devam etmek icin bir tusa basiniz ");
		fclose(dosya);
	}
}

void Listem(struct  siginmaci siginan){
	/*SIĞINMACILARIN BİLGİLERİNİ GÖSTERİR*/
	printf("No \t\t\t: %d\n", siginan.siginmaci_no);
	printf("Ad \t\t\t: %s\n", siginan.ad);
	printf("Soyad \t\t\t: %s\n", siginan.soyad);
	printf("Dogum Tarihi \t\t: %s\n", siginan.dogum_tarihi);
	printf("Dogum Yeri \t\t: %s\n", siginan.dogum_yeri);
	printf("Cinsiyet \t\t: %s\n", siginan.cinsiyet);
	printf("Uyruk \t\t\t: %s\n", siginan.uyruk);
	printf("Meslek \t\t\t: %s\n", siginan.meslek);
	printf("Egitim Durumu \t\t: %s\n", siginan.egitim_durumu);
	printf("Cep Numarasi \t\t: %s\n", siginan.telefon);
	printf("Yerlestirildigi Adres \t: %s\n", siginan.yerlestirildigi_adres);
	printf("Geldigi Sehir \t\t: %s\n", siginan.geldigi_sehir);
	printf("Gelis Tarihi \t\t: %s\n", siginan.gelis_tarihi);
	printf("E-Mail Adresi \t\t: %s\n", siginan.eposta);
	printf("*****************************************************\n");

}

void Listem2(struct adminci admin){
	/*adminIN BİLGİLERİNİ İÇERİR*/
	char yetkiler[20];
	
	if (admin.yetki_turu == 'a')
		strcpy(yetkiler, "Admin");
	else if (admin.yetki_turu == 'm')
		strcpy(yetkiler, "Memur");
	else if (admin.yetki_turu == 'k')
		strcpy(yetkiler, "gözlemci");

	printf("Kullanici Yetkisi\t: %s\n", yetkiler);
	printf("Kullanci Adi \t\t: %s\n", admin.kullanici_adi);
	printf("TC \t\t\t: %s\n", admin.tc);
	printf("Ad \t\t\t: %s\n", admin.ad);
	printf("Soyad \t\t\t: %s\n", admin.soyad);
	printf("Telefon \t\t: %s\n", admin.tel);
	printf("E-posta \t\t: %s\n", admin.eposta);
	printf("Il \t\t\t: %s\n", admin.adres);
	printf("*****************************************************\n");

}
void animasyon()
{
	system("Color 0C");


	printf("               /$$               /$$       /$$                \n"); Sleep(300);
	printf("              | $$              | $$      |__/                \n\a"); Sleep(300);
	printf("             /$$$$$$    /$$$$$$ | $$   /$$ /$$  /$$$$$$       \n"); Sleep(300);
	printf("            |_  $$_/   |____  $$| $$  /$$/| $$ /$$__  $$      \n\a"); Sleep(300);
	printf("              | $$      /$$$$$$$| $$$$$$/ | $$| $$  \ $$      \n"); Sleep(300);
	printf("              | $$ /$$ /$$__  $$| $$_  $$ | $$| $$  | $$      \n\a"); Sleep(300);
	printf("              |  $$$$/|  $$$$$$$| $$ \  $$| $$| $$$$$$$/      \n"); Sleep(300);
	printf("               \___/   \_______/|__/  \__/|__/| $$____/       \n\a"); Sleep(300);
	printf("                                              | $$            \n"); Sleep(300);
	printf("                                              | $$            \n\a"); Sleep(300);
	printf("                                              |__/            \n"); Sleep(300);
	printf("           /$$             /$$                             /$$\n\a"); Sleep(300);
	printf("          |__/            | $$                            |__/\n"); Sleep(300);
	printf("  /$$$$$$$ /$$  /$$$$$$$ /$$$$$$    /$$$$$$  /$$$$$$/$$$$  /$$\n\a"); Sleep(300);
	printf(" /$$_____/| $$ /$$_____/|_  $$_/   /$$__  $$| $$_  $$_  $$| $$\n"); Sleep(300);
	printf("|  $$$$$$ | $$|  $$$$$$   | $$    | $$$$$$$$| $$ \ $$ \ $$| $$\n\a"); Sleep(300);
	printf(" \____  $$| $$ \____  $$  | $$ /$$| $$_____/| $$ | $$ | $$| $$\n"); Sleep(300);
	printf(" /$$$$$$$/| $$ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$ | $$ | $$| $$\n\a"); Sleep(300);
	printf("|_______/ |__/|_______/    \___/   \_______/|__/ |__/ |__/|__/\n"); Sleep(300);

	_getch();
	
}