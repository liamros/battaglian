#include <stdio.h>

int gio[13][13], pc[13][13];

int main ()
{
	for(int i = 1; i < 13; i++)           //assegna 0 a tutte le posiz
	{
		for(int j = 1; j<13; j++)
		{
			gio[i][j] = 0;
			pc[i][j] = 0;
		}
	}
}
