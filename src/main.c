#include <stdio.h>

int main()
{
	//Test function bintodec()
	char tableau[32];
    printf("Entrez une valeur binaire à convertir en décimal : ");
    scanf("%s", tableau);
    printf("Sa valeur décimal est %d.\n\n",bintodec(tableau));


	//Test function hexatodec()
	char table[32];
    printf("Entrez une valeur hexadécimal à convertir en décimal : ");
    scanf("%s", table);
    printf("Sa valeur décimal est %d.\n\n",hexatodec(table));


	//Test function dectohexa()
	int val;
    printf("Entrez un nombre décimal à convertir en hexadécimal : ");
    scanf("%d", &val); 
    char *tabl = dectohexa(val);
    int sizetabl = sizeof(tabl)-1;
    for (int i = sizetabl; i >= 0; i--)
    {
        printf("%c",tabl[i]);
    }
	printf(" est sa valeur hexadécimal.\n\n");


	//Test function dectobin_v1()
	int valeur;
	printf("Entrez un nombre décimal à convertir en binaire : ");
    scanf("%d", &valeur); 
	char *tab = dectobin_v1(valeur);
	printf("Sa valeur en binaire est %s.\n\n", tab);


	//Test function dectobin_v2()
	int vall;
	printf("Entrez un nombre décimal à convertir en binaire : ");
    scanf("%d", &vall); 
	char *tabb = dectobin_v2(vall);
	printf("Sa valeur en binaire est %s.\n\n", tabb);


	//Test function dectobin_v3()
	int v;
	printf("Entrez un nombre décimal à convertir en binaire : ");
    scanf("%d", &v); 
	char *t = dectobin_v3(v);
	printf("Sa valeur en binaire est %s.\n\n", t); 


	//Test function dectohexa_v2()
	int valeurs;
    printf("Entrez un nombre décimal à convertir en hexadécimal : ");
    scanf("%d", &valeurs); 
    char *tables = dectohexa_v2(valeurs);
	printf("Sa valeur hexadécimal est %s.\n\n", tables);
	

	return (0);
}