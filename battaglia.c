#include <stdio.h>		
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int gio[6][11], pc[6][11], i, j, k = 1, v;
char ag[6][11], bp[6][11], z = 'O';

int sottomarino(int gio[][11], int i, int j, int k);
int incrociatore(int gio[][11], int i, int j, int k);
int corazzata(int gio[][11], int i, int j, int k);

int incrociatorePC(int g[][11], int i, int j, int k);
int corazzataPC(int g[][11], int i, int j, int k);

int attacco(int g[][11], char graficap[][11], int i, int j, int contatore);
int attaccoPC(int g[][11], char grafica[][11], int i, int j, int contatore);

void grafica(char graficag[][11], char graficap[][11], char z);
void grafica2(char graficag[][11], char graficap[][11]);

int main ()
{
	while(k!=4)
	{
		printf("\nPosizione nave da %d posizioni\n\n", k);
		printf("Inserisci riga (da 1 a 5) = ");
		scanf("%d", &i);	
		printf("Inserisci colonna (da 1 a 10) = ");
		scanf("%d", &j);	
		if (i < 1 || i > 5 || j < 1 || j > 10) 
			continue;
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

	grafica(ag, bp, z);

	k = 0;

	while(k != 6 && v != 6)
	{
		k = attacco(pc, bp, i, j, k);

		if (k == 50)
			break;

		v = attaccoPC(gio, ag, i, j, v);

		sleep(1);
		grafica2(ag, bp);
		usleep(100 * 1000);
		printf("Il tuo avversario ti ha colpito %d volte\nTu lo hai colpito %d volte\n\n", v, k);
	}
	sleep(1);	
	k == 6 ? printf("\n\nHAI VINTO!\n\n") : printf("\n\nHai perso...\n\n");
	return 0;
}




int sottomarino(int gio[][11], int i, int j, int k)
{
	gio[i][j] = k;
	k++;
	return k;
}




int incrociatore(int gio[][11], int i, int j, int k)
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
	if(x == 's' && j-1 > 0 && gio[i][j] == 0 && gio[i][j-1] == 0)		//la k varia in base al tipo di nave
	{
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
	}
		else if(x == 'd' && j+1 < 11 && gio[i][j] == 0 && gio[i][j+1] == 0)
		{			
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
		}
			else if(x == 'G' && i+1 < 6 && gio[i][j] == 0 && gio[i+1][j] == 0)
			{
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
			}
				else if(x == 'S' && i-1> 0 && gio[i][j] == 0 && gio[i-1][j] == 0)
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






int corazzata(int gio[][11], int i, int j, int k)
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
		else if(x == 'd' && j+2 < 11 && gio[i][j] == 0 && gio[i][j+1] == 0 && gio[i][j+2] == 0)
		{			
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
		}
			else if(x == 'G' && i+2 < 6 && gio[i][j] == 0 && gio[i+1][j] == 0 && gio[i+2][j] == 0)
			{
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
			}
				else if(x == 'S' && i-2 > 0 && gio[i][j] == 0 && gio[i-1][j] == 0 && gio[i-2][j] == 0)
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





int incrociatorePC(int gio[][11], int i, int j, int k)
{
	if (gio[i][j] != 0)
	{
		return k;
	}
	int x;
	errore : x = 0;
	srand(time(NULL));
	x = rand() % 4 + 1;
	if(x == 1 && j-1 > 0 && gio[i][j] == 0 && gio[i][j-1] == 0)
	{
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
	}
		else if(x == 2 && j+1 < 11 && gio[i][j] == 0 && gio[i][j+1] == 0)
		{			
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
		}
			else if(x == 3 && i+1 < 6 && gio[i][j] == 0 && gio[i+1][j] == 0)
			{
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
			}
				else if(x == 4 && i-1 > 0 && gio[i][j] == 0 && gio[i-1][j] == 0)
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




int corazzataPC(int gio[][11], int i, int j, int k)
{
	if (gio[i][j] != 0)
	{
		return k;
	}
	int x;
	errore : x = 0;
	srand(time(NULL));
	x = rand() % 4 + 1;
	if(x == 1 && j-2 > 0 && gio[i][j] == 0 && gio[i][j-1] == 0 && gio[i][j-2] == 0)
	{
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
		j--;
		gio[i][j] = k;
	}
		else if(x == 2 && j+2 < 11 && gio[i][j] == 0 && gio[i][j+1] == 0 && gio[i][j+2] == 0)
		{			
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
			j++;
			gio[i][j] = k;  
		}
			else if(x == 3 && i+2 < 6 && gio[i][j] == 0 && gio[i+1][j] == 0 && gio[i+2][j] == 0)
			{
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
				i++;
				gio[i][j] = k;
			}
				else if(x == 4 && i-2 > 0 && gio[i][j] == 0 && gio[i-1][j] == 0 && gio[i-2][j] == 0)
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




int attacco(int gio[][11], char bp[][11], int i, int j, int k)
{
	char z = ' ';
	char m = '#';
	errore : printf("Inserisci coordinate di attacco\n");
	printf("Riga (1 a 5) = ");
	scanf("%d", &i);	
	printf("Colonna (1 a 10) = ");
	scanf("%d", &j);
	putchar('\n');
	sleep(1);
	if (i < 1 || i > 5 || j < 1 || j > 10)
	{
		k = 50;
		return k;
	}
	if (gio[i][j] == 20 || gio[i][j] == 100)
	{
		printf("NEGATIVO! ABBIAMO GIÀ SPARATO LÌ\n\n");
		goto errore;
	}
	if (gio[i][j] != 1 && gio[i][j] != 2 && gio[i][j] != 3)
	{
		printf("BERSAGLIO MANCATO!\n\n");
		gio[i][j] = 20;
		bp[i][j] = z;
		return k;
	}
	if (gio[i][j] == 1)
	{
		printf("CENTRO! BERSAGLIO COLPITO!\n\n");
		gio[i][j] = 100;
		bp[i][j] = m;
		k++;
		return k;
	}
	if (gio[i][j] == 2)
	{
		printf("CENTRO! BERSAGLIO COLPITO!\n\n");
		gio[i][j] = 100;
		bp[i][j] = m;
		k++;
		return k;
	}
	if (gio[i][j] == 3)
	{
		printf("CENTRO! BERSAGLIO COLPITO!\n\n");
		gio[i][j] = 100;
		bp[i][j] = m;
		k++;
		return k;
	}
}




int attaccoPC(int gio[][11], char ag[][11], int i, int j, int k)
{
	char z = ' ';
	char m = '#';
	errore : i = rand() % 5 + 1;
	j = rand() % 10 + 1;
	if (gio[i][j] == 20 || gio[i][j] == 100)
		goto errore;
	sleep(1);
	if (gio[i][j] != 1 && gio[i][j] != 2 && gio[i][j] != 3)
	{
		printf("CI HANNO MANCATO!\n\n");
		gio[i][j] = 20;
		ag[i][j] = z;
		return k;
	}
	if (gio[i][j] == 1)
	{
		printf("CODICE ROSSO CI HANNO COLPITO!\n\n");
		gio[i][j] = 100;
		ag[i][j] = m;
		k++;
		return k;
	}
	if (gio[i][j] == 2)
	{
		printf("CODICE ROSSO CI HANNO COLPITO!\n\n");
		gio[i][j] = 100;
		ag[i][j] = m;
		k++;
		return k;
	}
	if (gio[i][j] == 3)
	{
		printf("CODICE ROSSO CI HANNO COLPITO!\n\n");
		gio[i][j] = 100;
		ag[i][j] = m;
		k++;
		return k;
	}
}




void grafica(char ag[][11], char bp[][11], char z)
{	
	for(int i = 1; i < 6; i++)
		for(int j = 1; j < 11; j++)
		{
			ag[i][j] = z;
			bp[i][j] = z;
		}
	printf("\nTU\n\n");

	for(int i = 1; i < 6; i++)
	{
		for(int j = 1; j<11; j++)
			printf("%c ", ag[i][j]);	
		putchar('\n');
		usleep(100 * 1000);
	}
	putchar('\n');
	printf("\nAVVERSARIO\n\n");
	for(int i = 1; i < 6; i++)
	{
		for(int j = 1; j<11; j++)
			printf("%c ", bp[i][j]);	
		putchar('\n');
		usleep(100 * 1000);
	}
	putchar('\n');
}




void grafica2(char ag[][11], char bp[][11])
{
	printf("\nTU\n\n");
	for(int i = 1; i < 6; i++)
	{
		for(int j = 1; j<11; j++)
			printf("%c ", ag[i][j]);
		usleep(100 * 1000);	
		putchar('\n');
	}

	putchar('\n');
	printf("\nAVVERSARIO\n\n");
	for(int i = 1; i < 6; i++)
	{
		for(int j = 1; j<11; j++)
			printf("%c ", bp[i][j]);	
		usleep(100 * 1000);
		putchar('\n');
	}
	putchar('\n');
}
