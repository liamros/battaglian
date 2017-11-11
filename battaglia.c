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
		putchar('\n');
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
	if (v == 0)
	{
		gio[i][j] = k;
		k++;
		return k;
	}
	char x;
	int const r = i, c = j; 	//sono necessarie altrimenti gli if cambiano ad ogni iterazione 
	errore : x = 0;
	printf("Posizionare la nave verso su (S), giù (G), destra (d), o sinistra (s)? ");
	scanf("%c", &x);
	putchar('\n');
	if (x != 'S' && x != 'G' && x != 'd' && x != 's')
		goto errore;
	for (int t = 0; t < k; t++)	//indica quante posiz occupano le navi
	{
		if((x == 's' && c-v > 0) && ((v == 1 && gio[r][c-1] == 0) || (v == 2 && gio[r][c-1] == 0 && gio[r][c-2] == 0)))
		{
			gio[i][j] = k;  //r sostituisce j, perchè j avrà effetti collaterali
			j--;
		}
		else if((x == 'd' && c+v < 13) && ((v == 1 && gio[r][c+1] == 0) || (v == 2 && gio[r][c+1] == 0 && gio[r][c+2] == 0)))
		{				//la v verifica se la nave esce dalla mappa
			gio[i][j] = k;  	//e varia in base al tipo di nave	
			j++;
		}
		else if((x == 'G' && r+v < 13) && ((v == 1 && gio[r+1][c] == 0) || (v == 2 && gio[r+1][c] == 0 && gio[r+2][c] == 0)))
		{
			gio[i][j] = k;
			i++;
		}
		else if((x == 'S' && r-v > 0) && ((v == 1 && gio[r-1][c] == 0) || (v == 2 && gio[r-1][c] == 0 && gio[r-2][c] == 0)))
		{
			gio[i][j] = k;		//gli if controllano il carattere e se le navi si sovrappongono
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
