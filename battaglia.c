#include <stdio.h>

int gio[13][13], pc[13][13], i, j, k;

int navig(int gio[][13], int i, int j, int k);

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
//	while(k!=4)
//	{
		printf("Posizione nave da 3 posizioni\n");
		printf("Inserisci riga (da 1 a 12) = ");
		scanf("%d", &i);	
		printf("Inserisci colonna (da 1 a 12) = ");
		scanf("%d", &j);	
		k = navig(gio, i, j, k);
//	}
}

int navig(int gio[][13], int i, int j, int k)
{
	char x;
	errore : x = 0;
	printf("Posizionare la nave verso su (S), giù (G), destra (d), o sinistra (s)? ");
	scanf("%c", &x);
	if (x != 'S' && x != 'G' && x != 'd' && x != 's')
		goto errore;
	if (x == 'S' && j-3 > 0)
	{
		gio[i][j] = 3;
		j--;
		gio[i][j] = 3;
		j--;
		gio[i][j] = 3;
	}
		else if (x == 'G' && j+3 < 13)
		{
			gio[i][j] = 3;
			j++;
			gio[i][j] = 3;
			j++;
			gio[i][j] = 3;
		}
			else if (x == 'd' && i+3 < 13)
			{
				gio[i][j] = 3;
				i++;
				gio[i][j] = 3;
				i++;
				gio[i][j] = 3;
			}
				else if (x == 's' && i-3 > 0)
				{
					gio[i][j] = 3;
					i--;
					gio[i][j] = 3;
					i--;
					gio[i][j] = 3;
				}
				else
				{
				printf("Impossibile\n");
				goto errore;
				}
	return k++;
}
