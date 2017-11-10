#include <stdio.h>

int gio[13][13], pc[13][13], i, j, k = 1, v;

int navig(int gio[][13], int i, int j, int k, int verifica);

int main ()
{
	while(k!=4)
	{
		printf("Posizione nave da %d posizioni\n\n", k);
		printf("Inserisci riga (da 1 a 12) = ");
		scanf("%d", &i);	
		printf("Inserisci colonna (da 1 a 12) = ");
		scanf("%d", &j);	
		k = navig(gio, i, j, k, v);
		v++;					//v necessaria in navig
	}
	for(int i = 1; i < 13; i++)
	{
		for(int j = 1; j<13; j++)
			printf("%d ", gio[i][j]);	
		putchar('\n');
	}
}

int navig(int gio[][13], int i, int j, int k, int v)
{
	char x;
	int const c = i, r = j; 	//sono necessarie altrimenti gli if cambiano ad ogni iterazione 
	errore : x = 0;
	printf("Posizionare la nave verso su (S), giù (G), destra (d), o sinistra (s)? ");
	scanf("%c", &x);
	putchar('\n');
	if (x != 'S' && x != 'G' && x != 'd' && x != 's')
		goto errore;
	for (int t = 0; t < k; t++)	//indica quante posiz occupano le navi
	{
		if (x == 's' && r-v > 0)  //r sostituisce j, perchè j avrà effetti collaterali
		{
			gio[i][j] = k;
			j--;
		}
			else if (x == 'd' && r+v < 13)	//la v verifica se la nave esce dalla mappa
			{				//e varia in base al tipo di nave	
				gio[i][j] = k;
				j++;
			}
				else if (x == 'G' && c+v < 13)
				{
					gio[i][j] = k;
					i++;
				}
					else if (x == 'S' && c-v > 0)
					{
						gio[i][j] = k;
						i--;
					}
					else
					{
					printf("Impossibile\n\n");
					goto errore;
					}
	}
	k++;
	return k;
}
