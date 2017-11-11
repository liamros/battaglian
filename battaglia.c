#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gio[5][10], pc[5][10], i, j, k = 1;

int sottomarino(int gio[][10], int i, int j, int k);
int incrociatore(int gio[][10], int i, int j, int k);
int corazzata(int gio[][10], int i, int j, int k);

int incrociatorePC(int g[][10], int i, int j, int k);
int corazzataPC(int g[][10], int i, int j, int k);

int main ()
{
	while(k!=4)
	{
		printf("\nPosizione nave da %d posizioni\n\n", k);
		printf("Inserisci riga (da 1 a 5) = ");
		scanf("%d", &i);	
		printf("Inserisci colonna (da 1 a 10) = ");
		scanf("%d", &j);	
		if (i < 1 || i > 5 || j < 1 || j > 10) continue;
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
	k = 1;
	while(k != 4)
	{
		srand(time(NULL));
		i = rand() % 5 + 1;
		j = rand() % 10 + 1;
		switch(k)
		{
			case 1 :
			k = sottomarino(pc, i, j, k);
			break;

			case 2 :
			k = incrociatorePC(pc, i, j, k);
			break;

			case 3 :
			k = corazzataPC(pc, i, j, k);
			break;
		}
	}
	for(int i = 1; i < 6; i++)
	{
		for(int j = 1; j<11; j++)
			printf("%d ", gio[i][j]);	
		putchar('\n');
	}
	putchar('\n');
	for(int i = 1; i < 6; i++)
	{
		for(int j = 1; j<11; j++)
			printf("%d ", pc[i][j]);	
		putchar('\n');
	}

}




int sottomarino(int gio[][10], int i, int j, int k)
{
	gio[i][j] = k;
	k++;
	return k;
}




int incrociatore(int gio[][10], int i, int j, int k)
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






int corazzata(int gio[][10], int i, int j, int k)
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





int incrociatorePC(int gio[][10], int i, int j, int k)
{
	if (gio[i][j] != 0)
	{
		return k;
	}
	int x;
	errore : x = 0;
	srand(time(NULL));
	x = rand() % 4 + 1;
	if(x == 1 && gio[i][j] == 0 && gio[i][j-1] == 0)
	{
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
	}
		else if(x == 2 && gio[i][j] == 0 && gio[i][j+1] == 0)
		{			
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
		}
			else if(x == 3 && gio[i][j] == 0 && gio[i+1][j] == 0)
			{
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
			}
				else if(x == 4 && gio[i][j] == 0 && gio[i-1][j] == 0)
				{
					gio[i][j] = k;
					i--;
					gio[i][j] = k;
				}
					else
					{
						goto errore;
					}
	k++;
	return k;
}




int corazzataPC(int gio[][10], int i, int j, int k)
{
	if (gio[i][j] != 0)
	{
		return k;
	}
	int x;
	errore : x = 0;
	srand(time(NULL));
	x = rand() % 4 + 1;
	if(x == 1 && gio[i][j] == 0 && gio[i][j-1] == 0 && gio[i][j-2] == 0)
	{
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
	}
		else if(x == 2 && gio[i][j] == 0 && gio[i][j+1] == 0 && gio[i][j+2] == 0)
		{			
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
		}
			else if(x == 3 && gio[i][j] == 0 && gio[i+1][j] == 0 && gio[i+2][j] == 0)
			{
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
			}
				else if(x == 4 && gio[i][j] == 0 && gio[i-1][j] == 0 && gio[i-2][j] == 0)
				{
					gio[i][j] = k;	
					i--;
					gio[i][j] = k;
					i--;
					gio[i][j] = k;
				}
					else
					{
						goto errore;
					}
	k++;
	return k;
}

