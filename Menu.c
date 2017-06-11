// Aggeliki Felimega

#include <stdlib.h>
#include "Menu.h"



struct InfoMenu {
	char* 	  Name; 	   // το όνομα του εστιατορίου
	MenuNodePtr Start;	   // Δείκτης στον πρώτο κόμβο του πρώτου επιπέδου
	MenuNodePtr Current;   // Δείκτης στον τρέχοντα κόμβο
	MenuNodePtr CutToPaste;// Δείκτης στον κόμβο προς μεταφορά σε άλλη θέση
};

typedef struct MenuNode {
	MenuNodePtr Prev, Next, Up, Down;
	TStoixeiouMenu Data;
}MenuNode;


InfoMenuPtr menou_dimioyrgia(char *name, MenuNodePtr head)
{
	InfoMenuPtr InfoMenu;
	InfoMenu = malloc(sizeof(InfoMenu));
	head = malloc(sizeof(MenuNode));
	head->Prev = NULL;
	head->Next = NULL;
	head->Up = NULL;
	head->Down = NULL;
	InfoMenu->CutToPaste = NULL;
	InfoMenu->Start = head;
	InfoMenu->Current = head;
	InfoMenu->Name = name;
	return InfoMenu;
}

int menou_kenh_kathgoria(const InfoMenuPtr InfoMenu)
{
	return ( InfoMenu->Start->Next == NULL );
}

void menou_eisagwgi_komvou(InfoMenuPtr *InfoMenu, TStoixeiouMenu stoixeio, int *error)
{
	*error=0;
	MenuNodePtr prosorinos; /*Deixnei ton neo kombo pou prokeitai na eisax8ei*/
	prosorinos = malloc(sizeof(MenuNode));
	if ( prosorinos == NULL )
	{   *error=1;
		return;
	}
	TSSetValue(&(prosorinos->Data), stoixeio);
	prosorinos->Next = (*InfoMenu)->Current->Next;
	prosorinos->Prev = (*InfoMenu)->Current;
	prosorinos->Down = NULL;
	prosorinos->Up =  (*InfoMenu)->Current;
	if(prosorinos->Next!=NULL)
		prosorinos->Next->Prev = prosorinos;
	(*InfoMenu)->Current->Next = prosorinos;
	(*InfoMenu)->Current = prosorinos;
		  	
}

void menou_ektypose_periexomeno(InfoMenuPtr InfoMenu, MenuNodePtr head, int *error)
{
	*error = 0;
	if(head == NULL)
    	*error=1;
    else
    	TSPrintValue(InfoMenu->Current->Data);
    return;
}

void menou_allagh_periexomenoy(InfoMenuPtr *InfoMenu, MenuNodePtr head, TStoixeiouMenu stoixeio, int *error)
{
	*error = 0;
	if(head == NULL )
		*error=1; 
	else
		TSSetValue(&(*InfoMenu)->Current->Data, stoixeio);
}

void menou_epomenos(InfoMenuPtr *InfoMenu, MenuNodePtr p,  int *error)
{
	*error = 0;
	if((*InfoMenu)->Current->Next!=NULL)
		(*InfoMenu)->Current= (*InfoMenu)->Current->Next ;
	else
         *error=1;
}

void menou_prohgoymenos(InfoMenuPtr *InfoMenu, MenuNodePtr p,  int *error)
{
	*error = 0;
	if((*InfoMenu)->Current->Prev!=NULL) {
		(*InfoMenu)->Current= (*InfoMenu)->Current->Prev ;
	}	
	else
         *error=1;	
}


void menou_metakinhsh_meta(InfoMenuPtr *InfoMenu, int *error)
{
	*error=0;
	MenuNodePtr prosorinos; /*Deixnei ton neo kombo pou prokeitai na eisax8ei*/
	prosorinos = malloc(sizeof(MenuNode));
	if ((*InfoMenu)->Current->Next == NULL) *error=1;
	else
	{
		prosorinos = (*InfoMenu)->Current->Next;
		prosorinos->Prev = (*InfoMenu)->Current->Prev;
		(*InfoMenu)->Current->Prev = prosorinos;
		if(prosorinos->Next != NULL)
			(*InfoMenu)->Current->Next = prosorinos->Next;
		prosorinos->Next = (*InfoMenu)->Current;
		free(prosorinos);		
	}
}

void menou_metakinhsh_prin(InfoMenuPtr *InfoMenu, int *error)
{
	*error=0;
	MenuNodePtr prosorinos; 
	prosorinos = malloc(sizeof(MenuNode));
	if ((*InfoMenu)->Current->Prev == NULL ) *error=1;
	else
	{
		prosorinos = (*InfoMenu)->Current->Prev;
		prosorinos->Next = (*InfoMenu)->Current->Next;
		(*InfoMenu)->Current->Next = prosorinos;
		if(prosorinos->Next != NULL)
			(*InfoMenu)->Current->Prev = prosorinos->Prev;
		prosorinos->Prev = (*InfoMenu)->Current;
		free(prosorinos);
	}	
}


void menou_eisagogh_kathgoria(InfoMenuPtr *InfoMenu, TStoixeiouMenu stoixeio, MenuNodePtr *head, MenuNodePtr *p, int *error)
{
	*error=0;
	MenuNodePtr prosorinos; /*Deixnei ton neo kombo pou prokeitai na eisax8ei*/
	prosorinos = malloc(sizeof(MenuNode));
	if ( (*p) == NULL )
	{   *error=1;
		return;
	}
	if((*InfoMenu)->Current == (*head))
		*error=1;
	else
	{
		TSSetValue(&((*p)->Data), stoixeio);
		(*head)->Up = (*InfoMenu)->Current;
		(*head)->Prev = NULL;
		(*head)->Next = (*p);
		(*head)->Down = NULL;
		(*p)->Up = (*InfoMenu)->Current;
		(*p)->Down = NULL;
		(*p)->Prev = NULL;
		(*p)->Next = NULL;
		if((*p)->Next!=NULL)
			(*p)->Next->Prev = (*p);
		(*InfoMenu)->Current->Down = (*head);
	}
}

void menou_metakinhsh_panw(InfoMenuPtr *InfoMenu, MenuNodePtr p,MenuNodePtr head, int *error)
{
	*error=0;
	if((*InfoMenu)->Current->Up != NULL && (*InfoMenu)->Current == head)
		(*InfoMenu)->Current = head->Up;
	else if((*InfoMenu)->Current->Up != NULL && (*InfoMenu)->Current == p)
		(*InfoMenu)->Current = p->Up;
	else
		*error=1;
}

void menou_metakinhsh_katw(InfoMenuPtr *InfoMenu, MenuNodePtr p,MenuNodePtr head, int *error)
{
	*error=0;
	if((*InfoMenu)->Current->Down != NULL)
	{
		(*InfoMenu)->Current = (*InfoMenu)->Current->Down;
	}
	else
		*error=1;	
}



void recursive_ekt(InfoMenuPtr *InfoMenu, MenuNodePtr *temp, MenuNodePtr head)
{
	MenuNodePtr prosorinos;
	prosorinos = malloc(sizeof(MenuNode));
	if((*temp)->Down != NULL)
		recursive_ekt(InfoMenu,&(*temp)->Down, head);
	else{
		prosorinos = (*temp);
		(*temp) = (*temp)->Next;
		if(prosorinos != head)
			TSPrintValue(prosorinos->Data);
	}
}

void menou_ektypvse_kathgoria(InfoMenuPtr *InfoMenu, MenuNodePtr head, MenuNodePtr p,int *error)
{
	*error=0;
	MenuNodePtr prosorinos; /*Vohthitikos kombos */
	prosorinos = malloc(sizeof(MenuNode));
	(*InfoMenu)->Current = (*InfoMenu)->Start->Next;
    while((*InfoMenu)->Current != NULL){
    	TSPrintValue((*InfoMenu)->Current->Data);
    	if ((*InfoMenu)->Current->Down != NULL){
			prosorinos = (*InfoMenu)->Current->Down;
			do{
				recursive_ekt(InfoMenu, &prosorinos, head);
			}while(prosorinos != NULL);
		}
    	(*InfoMenu)->Current = (*InfoMenu)->Current->Next;
    }
	(*InfoMenu)->Current = (*InfoMenu)->Start;
}


void menou_diagrafh(InfoMenuPtr *InfoMenu,int *error)
{
	*error=0;
	MenuNodePtr prosorinos; /*Deixnei ton kombo pou prokeitai na diagrafei*/
	prosorinos = malloc(sizeof(MenuNode));
	if((*InfoMenu)->Current->Next == NULL || prosorinos->Down !=NULL)
		*error=1;
	else
	{
		prosorinos = (*InfoMenu)->Current->Next;
		if(prosorinos->Next != NULL){
			(*InfoMenu)->Current->Next = prosorinos->Next;
			prosorinos->Next->Prev = (*InfoMenu)->Current->Next;
		}
		else
			(*InfoMenu)->Current->Next = NULL;
		free(prosorinos);
	}
}



void recursive(MenuNodePtr *temp)
{
	MenuNodePtr prosorinos;
	prosorinos = malloc(sizeof(MenuNode));
	if((*temp)->Down != NULL){
		recursive(&(*temp)->Down);
	}
	else{
		prosorinos = (*temp);
		(*temp) = (*temp)->Next;
		free(prosorinos);
	}
}

void menou_diagrafh_olwn(InfoMenuPtr *InfoMenu, MenuNodePtr *head, int *error)
{
	*error=0;
	MenuNodePtr prosorinos, deik; /*Deixnei ton kombo pou prokeitai na diagrafei*/
	prosorinos = malloc(sizeof(MenuNode));
	deik = malloc(sizeof(MenuNode));
	prosorinos = (*InfoMenu)->Current;
	deik = (*InfoMenu)->Current;
	if ((*InfoMenu)->Current->Down != NULL){
		deik = (*InfoMenu)->Current->Down;
		do{
			recursive(&deik);
		}while((*InfoMenu)->Current->Down == NULL);
	}
	(*InfoMenu)->Current = prosorinos;
	(*InfoMenu)->Current->Down = NULL;
}

void menou_apokoph(InfoMenuPtr *InfoMenu, MenuNodePtr head, int *error)
{
	*error=0;
	MenuNodePtr prosorinos; /*Deixnei ton kombo pou prokeitai na diagrafei*/
	prosorinos = malloc(sizeof(MenuNode));
	prosorinos = (*InfoMenu)->Current;
	if(prosorinos == head)
		*error=1;
	else
	{
		if(prosorinos->Next != NULL)
		{
			prosorinos->Prev->Next = prosorinos->Next;
			prosorinos->Next->Prev = prosorinos->Prev;
			(*InfoMenu)->CutToPaste = prosorinos;
		}
		else
		{
			prosorinos->Prev->Next = NULL;
			(*InfoMenu)->CutToPaste = prosorinos;
		}	
	}
	(*InfoMenu)->Current = prosorinos->Prev;
}

void menou_epikollhsh(InfoMenuPtr *InfoMenu, int *error)
{
	*error=0;
	MenuNodePtr prosorinos; /*Deixnei ton kombo pou prokeitai na diagrafei*/
	prosorinos = malloc(sizeof(MenuNode));
	if((*InfoMenu)->Current->Next == NULL)
	{
		(*InfoMenu)->Current->Next = (*InfoMenu)->CutToPaste;
		(*InfoMenu)->CutToPaste = NULL;
		(*InfoMenu)->Current = (*InfoMenu)->Current->Next;
	}
	else if((*InfoMenu)->Current->Next != NULL)
	{
		prosorinos = (*InfoMenu)->Current->Next;
		(*InfoMenu)->Current->Next = (*InfoMenu)->CutToPaste;
		(*InfoMenu)->Current = (*InfoMenu)->Current->Next;
		(*InfoMenu)->Current->Next = prosorinos;
		(*InfoMenu)->CutToPaste = NULL;
	}
	else
		*error=1;

}

void menou_katastrofh(InfoMenuPtr *InfoMenu, MenuNodePtr head, int *error)
{
    (*InfoMenu)->Current = (*InfoMenu)->Start->Next;
    while((*InfoMenu)->Current != NULL){
    	menou_diagrafh_olwn(InfoMenu, &head, error);
    	(*InfoMenu)->Current = (*InfoMenu)->Current->Next;
    }
	(*InfoMenu)->Start = NULL;
	(*InfoMenu) = NULL;
    free(*InfoMenu);
    
}


