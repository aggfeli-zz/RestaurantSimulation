// Aggeliki Felimega

#ifndef __TSMENU__
#define __TSMENU__
#include <stdio.h>
#include <string.h>
#define SIZE 20


typedef struct Komvos {
	char name[SIZE]; 	// Name of Category or Plate
	int Category;	// 0 if Plate, 1 if Category
	float Price;	// Valid only if Plate
} TStoixeiouMenu;

void TSSetValue(TStoixeiouMenu *Lhs, TStoixeiouMenu Rhs); // Lhs = Rhs

void TSPrintValue(TStoixeiouMenu V);

void TSReadValue(TStoixeiouMenu * V);

#endif
