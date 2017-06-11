// Aggeliki Felimega

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "TyposStoixeiouMenu.h"

void print_options(void)
{
	printf("\n");
	printf("0. Exit\n");
	printf("1. Create menou\n");
	printf("2. Kenh kathgoria\n");
	printf("3. Eisagogh kombou\n");
	printf("4. Ektypwse periexomeno\n");
	printf("5. Allagh periexomeno\n");
	printf("6. Metakinhsh ston epomeno kombo\n");
	printf("7. Metakinhsh ston prohgoumeno kombo\n");
	printf("8. Antallagh 8eshs me ton epomeno kombo\n");
	printf("9. Antallagh 8eshs me ton prohgoymeno kombo\n");
	printf("10. Eisagogh kathgorias\n");
	printf("11. Metakinhsh ston panw kombo\n");
	printf("12. Metakinhsh ston katw kombo\n");
	printf("13. Ektypwse kathgoria\n");
	printf("14. Diagrafh kombou\n");
	printf("15. Diagrafh olwn\n");
	printf("16. Apokoph kombou\n");
	printf("17. Epikollhsh kombou\n");
	printf("18. Katastrofh menu\n");
	printf("19. Allagh apo kafeteria se estiatorio h' to antistrofo\n");
	printf("Enter your input (0-19): ");
}

int main(int argc, char *argv[]) {
	InfoMenuPtr 	FoodMenu = NULL,
					CafeMenu = NULL,
					CurrentMenu = NULL;
	MenuNodePtr menu, head;
	TStoixeiouMenu x;
	int option, error = 0;
	char buf[100];
	char name[100];
	do {
		option = -1;
		while (option < 0 || option > 19) {
			print_options();
			fgets(buf, sizeof(buf), stdin);
			sscanf(buf, "%d", &option);
		}
		switch (option) {
		case 1:
			printf("Dwste to onoma\n");
			scanf("%s", name);
			CurrentMenu = menou_dimioyrgia(name,head);	
			getchar();
			printf("\nMenou Dimioyrgh8hke!\n");
			break;
		case 2:
			if(CurrentMenu == NULL) 
			{
				printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n"); 
				break;
			}
			if (menou_kenh_kathgoria(CurrentMenu) == 1)
				printf("\nMenou empty!\n");
			else
				printf("\nMenou not empty!\n");
			break;
		case 3:
			if(CurrentMenu == NULL) 
			 	printf("\nDen uparxei menu  na eisax8oun dedomena !\n");             
            else
            {
            	TSReadValue(&x);
				menou_eisagwgi_komvou(&CurrentMenu, x, &error);
            }
			if(error)
	           printf("\nError! Adynamia desmeyshs mnhmhs(malloc)!\n");
            else
	           printf("\nTo stoixeio eishx8h!\n");
	        getchar();
			break;
		case 4:
			if(CurrentMenu == NULL) 
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");             
            else
				menou_ektypose_periexomeno(CurrentMenu, head, &error);
			if(error)
	           printf("\nError! \n");
            else
	           printf("\nH ektypwsh egine!\n");
			break;
		case 5:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");             
             else
             {
             	TSReadValue(&x);
             	menou_allagh_periexomenoy(&CurrentMenu, head, x, &error);
             }
             if(error)
	         	printf("\nError! \n");
             else
	            printf("\nH allagh egine!\n");
             getchar();
			break;
		case 6:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");
			else             
            	menou_epomenos(&CurrentMenu, menu, &error);
             if(error==1)
	           printf("\n O deikths  paramenei ston trexonta/den iparxei epomenos !\n");
	        else
         	   printf("\nO dromeas metakinh8hke ston epomeno kombo!\n");
			break;
		case 7:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");             
             else
			 	menou_prohgoymenos(&CurrentMenu, menu, &error);
             if(error==1)
	           printf("\n O deikths  paramenei ston trexonta/den iparxei prohgoymenos !\n");
	        else
         	   printf("\nO dromeas metakinh8hke ston prohgoymeno kombo!\n");
			break;
		case 8:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");             
             else
			 	menou_metakinhsh_meta(&CurrentMenu, &error);
             if(error == 1)
	           printf("\n H anatallagh meta den egine !\n");
	        else
         	   printf("\nH anatallagh meta egine!\n");
			break;
		case 9:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");             
             else
			 	menou_metakinhsh_prin(&CurrentMenu, &error);
             if(error == 1)
	           printf("\n H antallagh prin den egine !\n");
	        else
         	   printf("\nH antallagh prin egine!\n");
			break;
		case 10:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");             
            else
            {
            	TSReadValue(&x);             
             	menou_eisagogh_kathgoria(&CurrentMenu, x, &head, &menu, &error);
            }
             if(error == 1)
	           printf("\n H eisagwgh kathgorias den egine !\n");
	        else
         	   printf("\nH eisagwgh kathgorias egine!\n");
			break;
		case 11:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");             
             else
			 	menou_metakinhsh_panw(&CurrentMenu, menu,head ,&error);
             if(error==1)
	           printf("\n O deikths  paramenei ston trexonta/den iparxei panw !\n");
	        else
         	   printf("\nO dromeas metakinh8hke ston panw kombo!\n");
			break;
		case 12:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n");             
             else
			 	menou_metakinhsh_katw(&CurrentMenu, menu, head, &error);
             if(error==1)
	           printf("\n O deikths  paramenei ston trexonta/den iparxei katw !\n");
	        else
         	   printf("\nO dromeas metakinh8hke ston katw kombo!\n");
			break;
		case 13:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ektypothoun ta periexomena tou !\n"); 
			else
				menou_ektypvse_kathgoria(&CurrentMenu, head, menu, &error);
			if(error == 1)
	           printf("\n Sfalma sthn ektupwsh !\n");
	        else
         	   printf("\nH ektupwsh egine!\n");
			break;
		case 14:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na diagrafei o kombos !\n"); 
			else
				menou_diagrafh(&CurrentMenu, &error);
			if(error==1)
	           printf("\n Sfalma sthn diagrafh kombou !\n");
	        else
         	   printf("\nH diagrafh kombou egine!\n");			
			break;
		case 15:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na diagrafei o kombos !\n"); 
			else
				 menou_diagrafh_olwn(&CurrentMenu, &head, &error);
			if(error==1)
	           printf("\n Sfalma sthn diagrafh kombou !\n");
	        else
         	   printf("\nH diagrafh kombou egine!\n");			
			break;
		case 16:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na diagrafei o kombos !\n"); 
			else
				menou_apokoph(&CurrentMenu, head, &error);
			if(error==1)
	           printf("\n Sfalma sthn apokoph kombou !\n");
	        else
         	   printf("\nH apokoph kombou egine!\n");			
			break;
		case 17:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na ginei epikollhsh kombou !\n"); 
			else
				menou_epikollhsh(&CurrentMenu, &error);
			if(error==1)
	           printf("\n Sfalma sthn epikollhsh kombou !\n");
	        else
         	   printf("\nH epikollhsh kombou egine!\n");			
			break;
		case 18:
			if(CurrentMenu == NULL)
			 	printf("\nDen uparxei menu  gia na katastrafei !\n"); 
			else
				menou_katastrofh(&CurrentMenu, head, &error);
			if(error==1)
	           printf("\n Sfalma sthn katastrofh menu!\n");
	        else
         	   printf("\nH katastrofh menu egine!\n");		
			break;
		case 19:
			printf("Dwste 1 an thelete gia kafeteria h' allo gia estiatorio\n");
			scanf("%d", &option);
			if(option == 1) CurrentMenu = CafeMenu;
			else CurrentMenu = FoodMenu;
			getchar();	
			break;
		}
	}
	while (option);

	
	return 0;
}
