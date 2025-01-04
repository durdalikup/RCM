#include <stdio.h>
#include <string.h>



//Tanýmlamalar 

char maintenancelist[5][70]={
"Motor Yagi ve Yag Filtresi Degisimi(1350TL)",
"Suspansiyon ve Fren Sistemi Kontrolu(2000TL)",
"Motor Bakimi(2450TL)",
"Far, Aydinlatma ve Elektrik Sistemi Kontrolu(1150TL)",
"Egzoz Sistemi Kontrolu(2200TL)"
};

int amount[5];
int userchoice[5][5];

char telno[5][20];
char id[5][15];
char password[5][15];
char ad[5][15];
char soyad[5][15];
char plaka[5][15];
char model[5][15];
char marka[5][15];
char adres[5][200];
int randevu[12][31];
int kullaniciay[5][12]={0};
int kullanicigun[5][31]={0};
int kullanicigenelbakim[5];
int kullaniciodeme[5];
int userconfirmation[5];

int confirmation=0 , appofirmation=0,adminconfirm=0;
int usercounter = 0;
int genelbakim=0,lokalbakim=0;
int enteredmonth=0;
int enteredday=0;
char enteredpass[15];
char enteredid[15];

int paymentconfirm=0;
int condition = 1;
int i=0, j=0, x=0, r=1 , y=0;
int choose=0;
int user=0;

//fonksiyon prototipleri

void userappointment();
void payment();
void maintenance();
void appointment();
void userprofile();
void singup();
void login();
void adminlogin();
void kullaniciyazdir();
void kullanici_arac();
void kullaniciadres();
void kullanicibakim();

int main() {
	
	
	

	while(1)
	{
		r=1;
		while(r)
		{	
		
			// Giriþ ekraný 
			printf("\n**************************************************************\n");
			printf("\n\n[1]Kayit Ol\n");
			printf("[2]Giris Yap\n");
			printf("[3]Admin Olarak Giris Yap\n");
			printf("Seciminiz:");
			
			scanf("%d",&choose);
			
			switch(choose)
			{
				case 1:singup();
					break;
				
				case 2:login();
					break;
					
				case 3:adminlogin();
					break;
			
				default : printf("Gecersiz giris yaptiniz\n");
					break;
						
			}		
			
			
		}
		
		if(adminconfirm==1)
		{
			r=1;
			while(r)
			{	
				// Adminin kullandýðý menu
				kuldosyayazdir();
				
				printf("\n**************************************************************\n");
				printf("\n\n*****ADMIN MENU****\n\n");
				printf("[1]Kullanici Bilgileri\n");
				printf("[2]Kullanicilarin randevu bilgileri\n");
				printf("[3]Kullanicilarin arac bilgileri\n");
				printf("[4]Kullanicilarin adres ve odeme bilgleri\n");
				printf("[5]Kullanicilarin arac bakim bilgileri\n");
				printf("[6]Cikis Yap\n");
				printf("Seciminiz:");
				scanf("%d",&choose);
				
				
				switch(choose)
				{
					case 1:kullaniciyazdir();
						break;
					
					case 2:appointment_date();
						break;
						
					case 3:kullanici_arac();
						break;
					
					case 4:kullaniciadres();
						break;
					
					case 5:kullanicibakim();
						break;
							
					case 6:
						r=0;
						adminconfirm=0;
						break;
						
					default:printf("Gecersiz giris yaptiniz\n");
						break;
						
				}
				
				
				
			}
		}
		else
		{
			r=1;
			while(r)
			{	
				
				//Kullanýcýlarýn kullandýðý menu
				printf("\n**************************************************************\n");
				
				printf("\n\n*****MENU*****\n\n");
				printf("[1]Kullanici bilgileri\n");
				printf("[2]Randevu tarihi secimi\n");
				printf("[3]Arac bakim secim ekrani\n");
				printf("[4]Odeme ekrani\n");
				printf("[5]Mevcut randevularim\n");
				printf("[6]Cikis yap\n");
				printf("Seciminiz:");
				scanf("%d",&choose);
				
				switch(choose)
				{
					case 1:userprofile();
						break;
					case 2:appointment();
						break;
					case 3:maintenance();
						break;
					case 4:payment();
						break;
					case 5:userappointment();
						break;
					case 6:
						r=0;
						break;
						
					default:printf("Gecersiz giris yaptiniz");
						break;
				}	
			}
		}
		
		
	}

	
	

	
    return 0;
}


//Kullanýcýlarýn bilgilerini dosyada saklamak için fonksiyon
void kuldosyayazdir()
{
	FILE *fptr;
	fptr=fopen("C:\\Users\\Durdali\\OneDrive\\Masaüstü\\RCM\\\\kullanicidata.txt","w");
	if(fptr==NULL)
	{
		printf("File open unsuccessful\n");
	}
	else 
	{
		
			
		for (i=0;i<usercounter;i++)
		{	
			fprintf(fptr,"\n\n========================================================\n\n");
			
			fprintf(fptr,"%d . KULLANICININ BILGILERI \n\n\n",i+1);
		
			fprintf(fptr,"Kullanici %d;\nad:%s \nsoyad:%s \ntel no:%s \n\n",i+1, ad[i],soyad[i],telno[i]);
			fprintf(fptr,"\n\n*********************************************************\n\n");
			
			fprintf(fptr,"\n%d. kullanicinin randevu aldigi aracin:\n\n",i+1);
			fprintf(fptr,"markasi: %s \nmodeli: %s \nplakasi: %s \n",marka[i],model[i],plaka[i]);
			
			fprintf(fptr,"\n\n*********************************************************\n\n");
			
			if(kullanicigenelbakim[i]==1)
			{
				fprintf(fptr,"\n%d. kullanicinin arac bakimi:\n\n**Genel Bakim\n",i+1);
			}
			else 
			{
				fprintf(fptr,"\n%d. kullanicinin arac bakimi:\n\n",i+1);
				for(j=0;j<5;j++)
				{
					if(userchoice[i][j]==1)
					{
						fprintf(fptr,"**%s\n",maintenancelist[j]);
					}
				}
			}
			
			fprintf(fptr,"\n\n*********************************************************\n\n");
			
			fprintf(fptr,"\n%d. kullanicinin adres ve odeme bilgileri:\n\n",i+1);
			fprintf(fptr,"adres: %s\n",adres[i]);
			if(kullaniciodeme[i]==1)
			{
				fprintf(fptr,"\nkullanici odemesini online olarak gerceklestirmistir.\n");
			}
			else
			{
				fprintf(fptr,"\ntutar: %d",amount[i]);
			}
			
			fprintf(fptr,"\n\n*********************************************************\n\n");
			
			for(j=0;j<12;j++)
			{
				if(kullaniciay[i][j]==1)
				{
						for(y=0;y<31;y++)
						{
							if(kullanicigun[i][y]==1)
							{
									fprintf(fptr,"%d. kullanicinin: \n%d. ayin %d. gunu arac bakim randevusu vardir.\n\n",i+1,j+1,y+1);
									break;
							}
						}
						
				break;	
				}
			}
			
			fprintf(fptr,"\n\n*********************************************************\n\n");
		}
		
			
    }
	
	
	fclose(fptr);
}






// Admine tüm kullanýcýlarýn hangi arac bakýmýný sectiði bilgisini yazdýran fonksiyon
void kullanicibakim()
{	
	printf("\n**************************************************************\n");	

	printf("\nKULLANICILARIN ARAC BAKIM BILGILERI\n\n");
	
	for(i=0;i<usercounter;i++)
	{
		if(kullanicigenelbakim[i]==1)
		{
			printf("\n%d. kullanicinin arac bakimi:\n\n**Genel Bakim\n",i+1);
		}
		else 
		{
			printf("\n%d. kullanicinin arac bakimi:\n\n",i+1);
			for(j=0;j<5;j++)
			{
				if(userchoice[i][j]==1)
				{
					printf("**%s\n",maintenancelist[j]);
				}
			}
			
			
		}
	}
	
	
	
}

// Admine Kullanýcýlarýn ödemeleri ve adresleri hakkýnda bilgi veren fonksiyon 
void kullaniciadres()
{
	printf("\n**************************************************************\n");
	
	printf("\nKULLANICILARIN ADRES VE ODEME BILGILERI\n\n");
	
	for(i=0;i<usercounter;i++)
	{
		printf("\n%d. kullanicinin adres ve odeme bilgileri:\n\n",i+1);
		printf("adres: %s\n",adres[i]);
		if(kullaniciodeme[i]==1)
		{
			printf("\nkullanici odemesini online olarak gerceklestirmistir.\n");
		}
		else
		{
			printf("\ntutar: %d",amount[i]);
		}
		
	}
	
}

// Admine kullanýcýlarýn araclarý hakýnda bilgi veren fonskiyon
void kullanici_arac()
{
	printf("\n**************************************************************\n");
	
	printf("\nKULLANICILARIN ARAC MODEL, MARKA VE PLAKA BILGILERI\n");
	
	for(i=0;i<usercounter;i++)
	{
		printf("\n%d. kullanicinin randevu aldigi aracin:\n\n",i+1);
		printf("markasi: %s \nmodeli: %s \nplakasi: %s \n",marka[i],model[i],plaka[i]);
		
	}
	
	return;
}

// Admin için kullanýcýlarýn randevu tarihini gösteren fonksiyon
void appointment_date()
{
	printf("\n**************************************************************\n");
	
	printf("KULLANICILARIN RANDEVU BILGILERI\n\n");
	
	for(i=0;i<usercounter;i++)
	{
		for(j=0;j<12;j++)
		{
			if(kullaniciay[i][j]==1)
			{
					for(y=0;y<31;y++)
					{
						if(kullanicigun[i][y]==1)
						{
								printf("%d. kullanicinin: \n%d. ayin %d. gunu arac bakim randevusu vardir.\n\n",i+1,j+1,y+1);
								break;
						}
					}
					
			break;	
			}
		}
		
	}
	
	return;	
}

// Kullanýcýnýn mevcut randevusu hakkýnda bilgi veren fonksiyon
void userappointment()
{
	printf("\n**************************************************************\n");
	
	if(paymentconfirm==1)
	{
		printf("\n\nMEVCUT ARAC BAKIMLARINIZ\n");
	
		if(kullanicigenelbakim[user]==1)
		{
			printf("**Genel Bakim");
		}
		else
		{
			for(i=0;i<5;i++)
			{
				if(userchoice[user][i]==1)
				{
					printf("**%s\n",maintenancelist[i]);
				}
				
			}
		}
		printf("\nRANDEVU TARIHINIZ\n");
		if(appofirmation==1)
		{
			printf("%d. ayin %d. gunu arac bakim randevunuz vardir.",enteredmonth,enteredday);
		}
	}
	else 
	{
		printf("\nSayfa, odeme ekranini onaylandiktan sonra gorunecektir\n");
	}
	
	
	return;
}

// Ödeme ekraný fonksiyonu
void payment()
{	
	char cardno[16];
	char expiration[5];
	char securitycode[3];
	int secim=0;
	int sec=0;
	paymentconfirm=0;
	printf("\n**************************************************************\n");
	
	printf("\n****ODEME EKRANI****\n");

	
	
	
	if( genelbakim==1 || lokalbakim==1 )
	{
		
		if(amount!=0)
		{	
		
			printf("\n\nAracinizin adresinizden alinmasini mi istesiniz yoksa en yakin tesise kendiniz mi ulastirmak istersiniz\n");
			printf("(Aracinizin adresten alimi sepetinize ektsra ucret uygulayacaktir.)\n\n");
			printf("\n[1]Adresimden alinsin(+300 TL)\n");
			printf("[2]Tesise kendim ulastirabilirim\n");
			printf("Seciminiz:");
			scanf("%d",&secim);
			
			if(secim==1)
			{
				printf("\n\nLutfen aracin alinacak oldugu adresi giriniz.\n");
				scanf(" %[^\n]", adres[user]);
				amount[user]+=300;
				sec=1;
				
			}
			else if(secim==2)
			{
				printf("\n\nOdemenizi isterseniz tesiste istersenizde online olarak yapabilirsiniz.\n( Herhangi bir ucretlendirme ile karsilasmayacaksiniz. )");
				printf("\n[1]Online");
				printf("\n[2]Tesiste");
				printf("\nSeciminiz:");
				scanf("%d",&sec);
			
			}
			
			if(sec==1)
			{
				printf("\n\nOdeme islemini gerceklestirmek icin gerekli bilgileri doldurunuz.\n");
				printf("\nOdemeniz gereken tutar: %d\n",amount[user]);
				printf("\n\n\n16 haneli kart numaraniz:");
				scanf("%s",&cardno);
				
				if(strlen(cardno)==16)
				{
					printf("SKT:");
					scanf("%s",&expiration);
					if(strlen(expiration)==5)
					{
						printf("CVC/CVV:");
						scanf("%s",&securitycode);
						if(strlen(securitycode)==3)
						{
							printf("\n\nOdemeniz basarili bir sekilde gerceklesmistir.Bizi tercih ettiginiz icin tesekkurler :)\n ");
							amount[user]=0;
							genelbakim=0;
							lokalbakim=0;
							paymentconfirm=1;
							kullaniciodeme[user]=1;
						}
						else
						{
							printf("\nGecersiz giris yaptýnýz");
							
						}
					}
					else
					{
						printf("\nGecersiz giris yaptýnýz");
						
					}
					
				}
				else
				{
					printf("\nGecersiz giris yaptýnýz");
				}
			}
			else if(sec==2)
			{
				printf("\n\n\nOdemenizi tesiste gerceklestirebilirsiniz. Bizi tercih ettiginiz icin tesekurler :)\n\n");
				genelbakim=0;
				lokalbakim=0;
				paymentconfirm=1;
			}
			else
			{
				printf("\nGecersiz giris yaptýnýz\n");
			}
				
		}
		else 
		{
			printf("\nHerhangi bir odemeniz bulunmamaktadir.\n");
		}
	}
	else 
	{
		printf("\nHerhangi bir odemeniz bulunmamaktadir.\n");
	}
	
	return;	
}

// Arac bakýmýnýn seçilmesini saðlayan fonksiyon 
void maintenance()
{	
	
	int sec=0;
	int secim=0;
	
	printf("\n**************************************************************\n");
	
	printf("\n****ARAC BAKIMI SECIM EKRANI****\n");
	
	if(appofirmation==1)
	{
		printf("\nBakimini yaptirmak istediginiz bakimin secili oldugu numarayi giriniz\n");
		printf("[1]Genel Bakim\n");
		printf("[2]Lokal Parca Bakimi\n");
		printf("Seciminiz:");
		scanf("%d",&secim);
		
		switch(secim)
		{
			case 1:
				printf("\nBilgilendirme:\n***Genel Bakimi sectiniz\n");
				printf("***Genel Bakim ocretlendirmesi 7000 TL dir.\n\nSeciminizi onayliyor musunuz?\n");
				printf("[1]Evet\n[2]Hayir");
				printf("\nSeciminiz:");
				scanf("%d",&secim);
				
				if(secim==1)
				{
					genelbakim=1;
					kullanicigenelbakim[user]=1;
					amount[user]=7000;
					for(i=0;i<5;i++)
					{
						userchoice[user][i]=0;
					}
					printf("\nSeciminiz onaylanmistir.\n");
					printf("**Mevcut Sepet Tutari:%d TL dir.\n",amount[user]);
					printf("\nOdeme islemini gerceklestirebilirisiniz");
				}
				else if (secim==2)
				{
					printf("\nSeciminiz onaylanmamistir.\nMenuden seciminizi tekrardan gerceklestirebilirsiniz");
				}
				else
				{
					printf("\n***Gecersiz giris");
				}
				
				break;
				
			case 2:	
				
				printf("\nBilgilendirme:\n***Lokal Parca Bakimini sectiniz\n");
				printf("**Karsiniza cikan secenekleri onaylamak icin [1], reddetmek icin [2] girdisini giriniz.\n");
				
				for(i=0;i<5;i++)
				{
					/*
					{
					"Motor Yagi ve Yag Filtresi Degisimi(1350TL)",
					"Suspansiyon ve Fren Sistemi Kontrolu(2000TL)",
					"Motor Bakimi(2450TL)",
					"Far, Aydinlatma ve Elektrik Sistemi Kontrolu(1150TL)",
					"Egzoz Sistemi Kontrolu(2200TL)"
					}
					*/
					printf("\nYaptirmak istediginiz bakim :%s \n",maintenancelist[i]);
					printf("[1]Evet\n[2]Hayir\n");
					printf("seciminiz:");
					scanf("%d",&sec);
					
					if(sec==1)
					{
						printf("\n**Seciminiz sepete eklenmistir.\n");
						userchoice[user][i]=1;
						if(i==0)
						{
							amount[user]+=1350;
						}
						else if(i==1)
						{
							amount[user]+=2000;
						}
						else if(i==2)
						{
							amount[user]+=2450;
						}
						else if(i==3)
						{
							amount[user]+=1150;
						}
						else if(i==4)
						{
							amount[user]+=2200;
						}
						printf("**Mevcut Sepet Tutari:%d TL dir.\n",amount[user]);
						genelbakim=0;
						lokalbakim=1;
						kullanicigenelbakim[user]=0;
					}
					
					else if(sec==2)
					{
						printf("\n**Seciminiz sepete eklenmemistir.\n");
						userchoice[user][i]=0;	
					}
					
					else 
					{
						printf("\n**Gecersiz giris yaptiniz.\nSecimi reddetmis olarak kabul edilecktir.\n");
					}	
							
				}
				
				break;
				
			default:
				printf("Gecersiz giris yaptiniz.");
				break;
				
		}
	}
	else
	{
		printf("Lutfen arac bakim secimi yapabilmek icin randevu tarihi aliniz\n");
	}
	
	
	
}

// Randevu ekraný fonksiyonu
void appointment()
{	
	int secim=0;
	
	//programdaki kullanýcý giriþi olmadýðý için herhangi bir güne dolu bilgisi 
	randevu[0][0]=1;
	
	printf("\n**************************************************************\n");
	
	printf("\n****RANDEVU EKRANI****\n\n");
	
	if(userconfirmation[user]==1)
	{
		printf("Arac Plaka(araya bosluk koymadan giriniz):");
		scanf("%s",&plaka[user]);
		
		printf("randevu almak istediginiz aracin markasini giriniz:");
		scanf("%s",marka[user]);
		
		printf("randevu almak istediginiz aracin modelini giriniz:");
		scanf("%s",model[user]);
		
		printf("\nRandevu tarihi icin randevu almak istediginiz ayin sayi karsiligini giriniz(1-12):");
		scanf("%d",&enteredmonth);
		
		if(enteredmonth<=12)
		{
			printf("\nRandevu tarihi icin randevu almak istediginiz gunun sayi karsiligini giriniz(1-31):");
			scanf("%d",&enteredday);
			
			if(enteredday<=31)
			{
				if(randevu[enteredmonth-1][enteredday-1]==0)
				{
					printf("\nSectiginiz gunde herhangi bir randevu olusturulmamistir.\nSeciminizi onayliyor musunuz?\n[1]Evet\n[2]Hayir\nSeciminiz:");
					scanf("%d",&secim);
					if(secim==1)
					{
						randevu[enteredmonth-1][enteredday-1]=1;
						printf("\nSeciminiz onaylanmistir. \n");
						appofirmation=1;
						kullaniciay[user][enteredmonth-1]=1;
						kullanicigun[user][enteredday-1]=1;
						
					}
					else  
					{
						printf("\nRandevunuz olusturulmamistir.\n");
						
					}
				}
				else 
				{
					printf("Sectiginiz gunde baþka bir randevu olusturulmustur.Lutfen baska bir randevu tarihi seciniz.");
				}
			}
			
			
		}
		else
		{
			printf("\nGecersiz giris yaptiniz\n");
		}
		
	}
	else 
	{
		printf("\nLutfen randevu tarihi almadan once kisisel bilgileriniz doldurunuz\n");
	}
	
	
}

// Kullanýcý bilgilerinin girilmesini saðlayan fonksiyon
void userprofile()
{	
	printf("\n**************************************************************\n");
	
	if(userconfirmation[user]!=1)
	{
		printf("\n****KULLANICI EKRANI****\n");
		printf("\nRandevuya devam etmek icin gerekli bilgileri doldurunuz\n\n");
		printf("Ad:");
		scanf("%s",&ad[user]);
		
		printf("Soyad:");
		scanf("%s",&soyad[user]);
		
		printf("Telefon numarasi:");
		scanf("%s",&telno[user]);
		
		if( ad[user]!=NULL && soyad[user]!=NULL && telno[user]!=NULL )
		{
			userconfirmation[user]=1;
		}
		
		
	}
	else
	{
		printf("\nKullanici bilgilerini zaten girmistir.\n");
	}
	

	return;
}

// Kayýt ekraný fonksiyonu
void singup()
{	
	printf("\n**************************************************************\n");
	
	 while (1) 
		{
			condition=1;
	        printf("\n\nYeni kullanici adi:");
	        scanf("%s", id[usercounter]);
			
	        // Kullanýcý adýný doðrulama
	        
	        for ( i = 0; i < usercounter; i++) 
			{
	            if (strcmp(id[usercounter], id[i]) == 0)
				{
	                printf("\n\nBu kullanici adi zaten alinmis. Lutfen baska bir kullanici adi giriniz.\n");
	                condition = 0;
	                break;
	            }
	        }
	        
	        if (condition == 1) 
			{
	            printf("\nKullanici adi kaydedildi.\n");
	           
	        }
	        else 
	        {
	        	break;
			}
	        
	        printf("\nYeni kullanici sifresi:");
	        scanf("%s", password[usercounter]);
	        
	        for ( i = 0; i < usercounter; i++) 
			{
	            if (strcmp(password[usercounter], password[i]) == 0)
				{
	                printf("\n\nBu sifre zaten alinmis. Lutfen baska sifre giriniz.\n");
	                condition = 0;
	                break;
	            }
	        }
	        
	        if (condition == 1) 
			{
	            printf("\nKullanici adi ve sifre kaydedildi.\n");
	            usercounter++;
	           break;
	        }
	        
	    }
	

    return;		
}

// Giris ekraný fonksiyonu
void login()
{
	printf("\n**************************************************************\n");
	printf("\n****GIRIS EKRANI****\n");
	
    printf("\nKullanici adi:");
    scanf("%s", &enteredid);
    
	printf("Sifre:");
    scanf("%s", &enteredpass);
    
    condition = 0; 
    
    for ( i = 0; i < usercounter; i++) 
	{
        if (strcmp(enteredid, id[i]) == 0 && strcmp(enteredpass, password[i]) == 0 ) 
		{
            printf("Kullanici adi ve sifre dogru\n");
            condition = 1;
            user=i;
            r=0;
    	}
    	
    }
    
    if (condition == 0) 
	{
        printf("Yanlis kullanici adi veya sifre \n");
        
        
    }
    

	
	return;
}

// Admin giriþini kontrol eden fonksiyon
void adminlogin()
{
	char adminid[15]={"admin123"};
	char adminpass[15]={"hello"};
	char admid[15];
	char admpass[15];
	printf("\n**************************************************************\n");
	printf("\n\n****ADMIN GIRIS EKRANI****\n\n");
	printf("admin kullanici adi:");
	scanf("%s",&admid);
	
	printf("admin sifre:");
	scanf("%s",&admpass);
	
	if( strcmp(admid,adminid)==0 && strcmp(adminpass,admpass)==0)
	{
		printf("\nAdmin girisi basariyla gerceklesti\n");
		adminconfirm=1;
		r=0;
		
	}
	else
	{
		printf("Yanlis kullanici adi veya sifre\n");
	}
	
	return ;
}

//Kullanýcýlarýn bilgilerini yazdýran fonksiyon
void kullaniciyazdir()
{


	for ( i = 0; i < usercounter; i++) 
	{
	    printf("\nKullanici %d; ad: %s soyad: %s tel no: %s \n", i + 1, ad[i],soyad[i],telno[i]);
	}
	

 return;
}


