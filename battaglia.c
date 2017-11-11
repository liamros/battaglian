#include <stdio.h>

int gio[13][13], pc[13][13], i, j, k = 1, v;

int sottomarino(int gio[][13], int i, int j, int k);
int incrociatore(int gio[][13], int i, int j, int k);
int corazzata(int gio[][13], int i, int j, int k);

int main ()
{
	while(k!=4)
	{
		printf("\nPosizione nave da %d posizioni\n\n", k);
		printf("Inserisci riga (da 1 a 12) = ");
		scanf("%d", &i);	
		printf("Inserisci colonna (da 1 a 12) = ");
		scanf("%d", &j);	
		if (i < 1 || i > 12 || j < 1 || j > 12) continue;
		switch(k)
		{
			case 1 :
			k = sottomarino(gio, i, j, k);
			break;

			case 2 :
			k = incrociatore(gio, i, j, k);
			break;

			case 3 :
			k = corazzata(gio, i, j, k);
			break;
		}
	}
	for(int i = 1; i < 13; i++)
	{
		for(int j = 1; j<13; j++)
			printf("%d ", gio[i][j]);	
		putchar('\n');
	}
}




int sottomarino(int gio[][13], int i, int j, int k)
{
	gio[i][j] = k;
	k++;
	return k;
}




int incrociatore(int gio[][13], int i, int j, int k)
{
	if (gio[i][j] != 0)
	{
		printf("\nPosizione occupata da un'altra nave, sceglierne un'altra\n\n");
		return k;
	}
	char x;
	errore : x = 0;
	printf("Posizionare la nave verso su (S), giù (G), destra (d), o sinistra (s)? ");
	scanf("\n%c", &x);
	if(x == 's' && gio[i][j] == 0 && gio[i][j-1] == 0)		//la k varia in base al tipo di nave
	{
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
	}
		else if(x == 'd' && gio[i][j] == 0 && gio[i][j+1] == 0)
		{			
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
		}
			else if(x == 'G' && gio[i][j] == 0 && gio[i+1][j] == 0)
			{
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
			}
				else if(x == 'S' && gio[i][j] == 0 && gio[i-1][j] == 0)
				{
					gio[i][j] = k;		//gli if controllano il carattere e se le navi si sovrappongono
					i--;
					gio[i][j] = k;
				}
					else
					{
						printf("Impossibile\n\n");
						goto errore;
					}
	k++;
	return k;
}






int corazzata(int gio[][13], int i, int j, int k)
{
	if (gio[i][j] != 0)
	{
		printf("\nPosizione occupata da un'altra nave, sceglierne un'altra\n\n");
		return k;
	}
	char x;
	errore : x = 0;
	printf("Posizionare la nave verso su (S), giù (G), destra (d), o sinistra (s)? ");
	scanf("\n%c", &x);
	if(x == 's' && gio[i][j] == 0 && gio[i][j-1] == 0 && gio[i][j-2] == 0)
	{
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
	}
		else if(x == 'd' && gio[i][j] == 0 && gio[i][j+1] == 0 && gio[i][j+2] == 0)
		{			
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
		}
			else if(x == 'G' && gio[i][j] == 0 && gio[i+1][j] == 0 && gio[i+2][j] == 0)
			{
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
			}
				else if(x == 'S' && gio[i][j] == 0 && gio[i-1][j] == 0 && gio[i-2][j] == 0)
				{
					gio[i][j] = k;	
					i--;
					gio[i][j] = k;
					i--;
					gio[i][j] = k;
				}
					else
					{
						printf("Impossibile\n\n");
						goto errore;
					}
	k++;
	return k;
}
