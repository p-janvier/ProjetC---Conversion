#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Binary -> Decimal
int bintodec(char *val)
{
	int resultat = 0;

	for(int i=0; i<strlen(val);i++)
	{
		int toint = *(val+i);
		if(toint==49) // Si 1
		{
			resultat+=(1<<(strlen(val)-(i+1)));
		}
	}
	return resultat;
}


//Hexadecimal -> Decimal
int hexatodec(char *val)
{
	int resultat = 0;

	for (int i = 0; i <= strlen(val) - 1; i++)
	{
		int temp;
		char nombre = val[strlen(val) - 1 - i];
		if (nombre >= '0' && nombre <= '9')
			temp = nombre - '0';
		if (nombre >= 'A' && nombre <= 'F')
			temp = nombre - 'A' + 10;
		if (nombre >= 'a' && nombre <= 'f')
			temp = nombre - 'a' + 10;
		resultat += temp << (4 * i);
	}
    return resultat;
}


//Decimal -> Hexadecimal
char *dectohexa(unsigned int val)
{
    char *resultat, resteLettre;
    int resteChiffre, i=0;
    resultat = malloc(sizeof(val)*sizeof(char));

    while (val != 0)
    {
        resteChiffre = val % 16;
        val = val / 16;
        switch (resteChiffre)
        {
            case 10:
                resteLettre = 'A';
                break;

            case 11:
                resteLettre = 'B';
                break;

            case 12:
                resteLettre = 'C';
                break;

            case 13:
                resteLettre = 'D';
                break;

            case 14:
                resteLettre = 'E';
                break;

            case 15:
                resteLettre = 'F';
                break;

            default:
                resteLettre = resteChiffre +'0';
                break;
        }
        resultat[i] = resteLettre;
        i++;
    }
    return resultat;
}


//Decimal -> Binary V1
char *dectobin_v1(unsigned int val)
{
    int max_power, i=1, nombre = val;

    while((nombre - i) > 0) {
        i *= 2;
    }

    char *resultat = malloc(32);
    int count = 0;

    if(nombre - i != 0)
    {
        max_power = i/2;
        while(nombre > 0)
        {
            if (nombre-max_power >= 0)
            {
                resultat[count] = '1';
                nombre -= max_power;
            }
            else
            {
                resultat[count] = '0';
            }
            max_power /= 2;
            count++;
        }
    }
    else
    {
        max_power = i;
        resultat[count] = '1';
        while(max_power != 0)
        {
            count++;
            resultat[count] = '0';
            max_power /= 2;
        }
    }
    resultat[count] = '\0';
    return resultat;
}


//Decimal -> Binary V2
char *dectobin_v2(unsigned int val){
	char *res = malloc(3 * sizeof(char));
	char *resultat = malloc(3 * sizeof(char));
	int a = val, b = 0, i = 0, j = 0;

	while(a > 0) 
    {
		b = a / 2;
		if(a % 2 == 0)
			res[i] = '0';
		else
			res[i] = '1';
		a = b;
		i++;
	}

	for (int i = strlen(res) - 1; i >= 0; i--)
    {
	  resultat[j] = res[i];
	  j++;
	}
	resultat[j] = '\0';
	return resultat;
}


//Decimal -> Binary V3
char *dectobin_v3(unsigned int val){
	char *res = malloc(3 * sizeof(char));
	char *resultat = malloc(3 * sizeof(char));
	int a = val, bin = 0, i = 0, j = 0;

	while (val != 0) 
    {
		int a = val % 2;
		if (a == 1)
			res[i] = '1';
		 else
			res[i] = '0';

		i++;
		val = val >> 1;
	}

	for (int i = strlen(res) - 1; i >= 0; i--)
    {
		  resultat[j] = res[i];
		  j++;
		}
		resultat[j] = '\0';
	return resultat;

}


//Decimal -> Hexadecimal V2
char *dectohexa_v2(unsigned int val){
	char *res = malloc(3 * sizeof(char));
	char *resultat = malloc(3 * sizeof(char));
	int i = 0, b = 0, j = 0;

	while (val != 0) 
    {
		int a = val % 16;
		if (a < 10) {
			res[i] = a + 48;
			i++;
		} else {
			res[i] = a + 55;
			i++;
		}
		val = val >> 4;
	}

	for (int i = strlen(res) - 1; i >= 0; i--)
    {
	  resultat[j] = res[i];
	  j++;
	}
	resultat[j] = '\0';
	return resultat;
}