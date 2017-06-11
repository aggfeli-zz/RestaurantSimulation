// Aggeliki Felimega

#include "TyposStoixeiouMenu.h"


void TSSetValue(TStoixeiouMenu *Lhs, TStoixeiouMenu Rhs)
{  
	strncpy(Lhs->name, Rhs.name, SIZE);  
	Lhs->Category = Rhs.Category;
	if (Lhs->Category == 0)
		Lhs->Price = Rhs.Price;
}

void TSReadValue(TStoixeiouMenu * V)
{    
	printf("Dwste to onoma toy piatou h' ths kathgorias kai 1 an einai kathgoria h' 0 an eiden einai\n");
	scanf("%19s %d", &(V->name), &(V->Category));
	if(V->Category == 0)
	{
		printf("Dwste thn timh tou piatou\n");
		scanf("%f", &(V->Price));
		getchar();
	}
}

void TSPrintValue(TStoixeiouMenu V)
{   
	if(V.Category == 1)
		printf("%s \n", V.name);
	else
		printf("\t%s %.2f \n", V.name, V.Price);
}
