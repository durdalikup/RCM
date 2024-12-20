#include <stdio.h>
#include <string.h>

char id[5][15];
char password[5][15];
int usercounter = 0;
char enteredpass[15];
char enteredid[15];
int condition = 1;
int i=0, j=0, x=0,r=1;
int choose=0;


int main() {

	while(r==1)
	{
		printf("[1]Sign Up\n");
		printf("[2]Sign In\n");
		printf("[3]Admin Sign in\n");
		printf("[4]Kullanici yazdir\n");
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
			
			case 4:kullaniciyazdir();
				break;
				
			default : printf("Gecersiz giris yaptiniz\n");
				break;
					
		}		
		
		
	}
	
	printf("\n****Kullanici ekrani****\n");

    return 0;
}



void singup()
{

	 while (1) 
		{
	        printf("Yeni kullanici adi:\n");
	        scanf("%s", id[usercounter]);
			
	        // Kullanýcý adýný doðrulama
	        
	        for ( i = 0; i < usercounter; i++) 
			{
	            if (strcmp(id[usercounter], id[i]) == 0)
				{
	                printf("Bu kullanici adi zaten alinmis. Lutfen baska bir kullanici adi giriniz.\n");
	                condition = 0;
	                break;
	            }
	        }
	        
	        if (condition == 1) 
			{
	            printf("Kullanici adi kaydedildi.\n");
	           
	        }
	        
	        printf("Yeni kullanici sifresi:\n");
	        scanf("%s", password[usercounter]);
	        
	        for ( i = 0; i < usercounter; i++) 
			{
	            if (strcmp(password[usercounter], password[i]) == 0)
				{
	                printf("Bu sifre zaten alinmis. Lutfen baska sifre giriniz.\n");
	                condition = 0;
	                break;
	            }
	        }
	        
	        if (condition == 1) 
			{
	            printf("Kullanici adi ve sifre kaydedildi.\n");
	            usercounter++;
	           break;
	        }
	        
	    }
	

    return;		
}

void login()
{
	printf("\n****Giris ekrani****\n");
	
    printf("\nkullanici adi:\n");
    scanf("%s", &enteredid);
    
	printf("Sifre:\n");
    scanf("%s", &enteredpass);
    
    condition = 0; 
    
    for ( i = 0; i < usercounter; i++) 
	{
        if (strcmp(enteredid, id[i]) == 0) 
		{
            printf("Correct user name\n");
			break;
        }
    }
    
    for ( i = 0; i < usercounter; i++) 
	{
        if (strcmp(enteredpass, password[i]) == 0) 
		{
            printf("Correct password\n");
            condition = 1;
			r=0; 
            break;
        }
    }
	
    if (condition == 0) 
	{
        printf("Wrong\n");
    }
	
	return;
}

void adminlogin()
{
	printf("admin giris ekrani\n");
	
	return;
}

void kullaniciyazdir()
{
	
	for ( i = 0; i < usercounter; i++) 
	{
	    printf("Kullanici %d; ID: %s PASSWORD: %s \n", i + 1, id[i],password[i]);
	}
	

	return;
}



