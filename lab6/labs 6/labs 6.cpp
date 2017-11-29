#include "stdafx.h"
#include <stdlib.h>

typedef struct Country
{
	char name[100];
	int population = 0;
	int area = 0;
}c;

void printCountry(Country arg1)
{
	printf("name: %s\n", arg1.name);
	printf("population = %d\n", arg1.population);
	printf("area = %d\n", arg1.area);

}

void PrintCountry(c c)
{
	printf("%s : ", c.name);
	printf("%d : ", c.population);
	printf("%d.\n", c.area);
}

Country CountryFromString(char * string)
{
	Country b;
	int i = 0;
	char * t = string;
	
	while (*t != ';')
	{
		b.name[i] = *t;
		*t++; 
		 i++;
	}
	b.name[i] = '\0';

	*t++;
	i = 0;

	char population[20];

	while (*t != ';')
	{
		population[i] = *t;
		*t++;
		 i++;
	}
	population[i] = '\0';
	b.population = atoi(population);

	*t++;
	i = 0;

	char area[20];

	while (*t != '\n')
	{
		area[i] = *t;
		*t++;
		 i++;
	}
	area[i] = '\0';
	b.area = atoi(area);

	*t++;
	i = 0;

	return b;
}
int main()
{
	int i = 0, index = 0;
	float density = 0;// minDens = 0;

	FILE * f;
	f = fopen("D:\\maksmen\\count.txt", "rt");
	if (f == NULL)
	{
		printf("huevo");
		_gettch();
		return 0;
	}

	char string[100];
	Country * country = (Country*)malloc(sizeof(Country) * 1);

	for (int i = 0; i < 3; i++)
	{
		fgets(string, 100, f);
		Country cntr = CountryFromString(string);
		country[i] = cntr;
	}

	int minDens = country[i].population / country[i].area;

	for (i = 1; i < 3; i++)
	{
		density = country[i].population / country[i].area;

		if (density < minDens)
		{
			minDens = density;
			index = i;
		}
	}

	printCountry(country[index]);

	free(country);
	fclose(f);
	_gettch();
    return 0;
}

