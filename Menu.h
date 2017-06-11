// Aggeliki Felimega

#ifndef __MENU__
#define __MENU__

#include "TyposStoixeiouMenu.h"

typedef struct InfoMenu *InfoMenuPtr; // Ο Τύπος δείκτη σε Πληροφοριακό Κόμβο Μενού

typedef struct MenuNode *MenuNodePtr; // Ο τύπος δείκτη σε κόμβο

InfoMenuPtr menou_dimioyrgia(char *name, MenuNodePtr head);

int menou_kenh_kathgoria(const InfoMenuPtr InfoMenu);

void menou_eisagwgi_komvou(InfoMenuPtr *InfoMenu, TStoixeiouMenu stoixeio, int *error);

void menou_ektypose_periexomeno(InfoMenuPtr InfoMenu, MenuNodePtr head, int *error);

void menou_allagh_periexomenoy(InfoMenuPtr *InfoMenu, MenuNodePtr head, TStoixeiouMenu stoixeio, int *error);

void menou_epomenos(InfoMenuPtr *InfoMenu, MenuNodePtr p,  int *error);

void menou_prohgoymenos(InfoMenuPtr *InfoMenu, MenuNodePtr p,  int *error);

void menou_metakinhsh_meta(InfoMenuPtr *InfoMenu, int *error);

void menou_metakinhsh_prin(InfoMenuPtr *InfoMenu, int *error);

void menou_eisagogh_kathgoria(InfoMenuPtr *InfoMenu, TStoixeiouMenu stoixeio, MenuNodePtr *head,MenuNodePtr *p, int *error);

void menou_metakinhsh_panw(InfoMenuPtr *InfoMenu, MenuNodePtr p,MenuNodePtr head, int *error);

void menou_metakinhsh_katw(InfoMenuPtr *InfoMenu, MenuNodePtr p,MenuNodePtr head, int *error);

void menou_ektypvse_kathgoria(InfoMenuPtr *InfoMenu, MenuNodePtr head, MenuNodePtr p,int *error);

void menou_diagrafh(InfoMenuPtr *InfoMenu,int *error);

void menou_diagrafh_olwn(InfoMenuPtr *InfoMenu, MenuNodePtr *head,int *error);

void menou_apokoph(InfoMenuPtr *InfoMenu, MenuNodePtr head, int *error);

void menou_epikollhsh(InfoMenuPtr *InfoMenu, int *error);

void menou_katastrofh(InfoMenuPtr *InfoMenu, MenuNodePtr head, int *error);

#endif
