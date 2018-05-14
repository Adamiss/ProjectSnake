/*Rigopoulou Georgia
AM: 2024201100069
tst11069@uop.gr

Vakoufaris Adam
AM: 2024200900056
tst09056@uop.gr
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>


//dilwsi sunartisewn
int* check_akeraiwn();
char* tablo_dots(char **tablo, int arithmos_grammwn, int arithmos_stilwn);		//dunamikos pinakas
char* easy(char **tablo, int arithmos_grammwn, int arithmos_stilwn);
int**levels(int arithmos_grammwn, int arithmos_stilwn, int ebodia, char **tablo, int pu, int megethos, int score);
char *kiniseis(int pu);
int powerup(int pu, int epilogi_pu);
char * ektupwsi(int arithmos_stilwn, int arithmos_grammwn, char** tablo);
int snake(int *thesi_fidiou);
char count_food(int arxiko);
int score(int food, int pu);
char** efarmogi_pu(char** tablo, int** sudetagmenes, int epilogi_pu, int thesi_fidiou, int megethos, int score);
int efarmogi_pu2(int epilogi_pu, int megethos, int score);

int main()
{

	//dilwsi metablitwn
	int arithmos_grammwn, arithmos_stilwn, i, j, ebodia, pu;
	int *pinakas_akeraiwn;
	char letter;
	char** tablo;
	int** sudetagmenes;
	int score = 0;
	int megethos = 3;


	printf("\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Welcome..! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\nGive the dimensions of the dashboard.\n\n");

	pinakas_akeraiwn = check_akeraiwn();

	arithmos_grammwn = pinakas_akeraiwn[0];
	arithmos_stilwn = pinakas_akeraiwn[1];

	//dunamikh desmeush mnhmhs
	tablo = (char**)malloc((arithmos_stilwn + 2) * sizeof(char *));

	for (i = 0; i<(arithmos_stilwn + 2); i++)
	{
		tablo[i] = (char *)malloc((arithmos_grammwn + 2) * sizeof(char));
	}


	tablo_dots(tablo, arithmos_grammwn, arithmos_stilwn);

	//epilogh duskolias
	printf("\n\nChoose level:\n		------------------------\n		|Press 'E/e' for Easy  |\n		|Press 'M/m' for Medium|\n 		|Press 'H/h' for Hard  |\n		|Press 'X/x' for Quit  |\n");
	printf("          	------------------------\n");
	scanf_s("%c", &letter);

	if ((letter == 'E') || (letter == 'e'))
	{
		printf("\n		EASY GAME \n\n", letter);
		ebodia = (arithmos_stilwn*arithmos_grammwn)*0.05;
		pu = 2;

		sudetagmenes = levels(arithmos_grammwn, arithmos_stilwn, ebodia, tablo, pu, megethos, score);		//sudetagmenes einai pianakas opou kratame tis times
		fflush(stdin);                 //ka8arizei to "enter"

	}

	else if (letter == 'M' || letter == 'm')
	{
		printf("\n	MEDIUM GAME \n\n", letter);
		ebodia = (arithmos_stilwn*arithmos_grammwn)*0.1;
		pu = 1;
		sudetagmenes = levels(arithmos_grammwn, arithmos_stilwn, ebodia, tablo, pu, megethos, score);		//sudetagmenes einai pianakas opou kratame tis times
		fflush(stdin);                 //ka8arizei to "enter"

	}
	else if (letter == 'H' || letter == 'h')
	{
		printf("\n	HARD GAME \n\n", letter);
		ebodia = (arithmos_stilwn*arithmos_grammwn)*0.15;
		pu = 0;
		sudetagmenes = levels(arithmos_grammwn, arithmos_stilwn, ebodia, tablo, pu, megethos, score);		//sudetagmenes einai pianakas opou kratame tis times
		fflush(stdin);                 //ka8arizei to "enter"
	}
	else if (letter == 'Q' || letter == 'q')
	{
		printf("\n	QUIT GAME \n\n", letter);
		return 0;
	}
	else
	{
		printf("\n	You din't choose level.", letter);
		return 0;
	}

	//!!!!!!!!!!!!!!!!!!!!!apeleu8erwsh mnimis
	for (i = 0; i<(arithmos_stilwn + 2); i++)
	{
		free(tablo[i]);
	}
	free(tablo);

	return 0;
}




//------------------------------------------------------------------SUNARTHSEIS-----------------------------------------------------------------------------


//==================	SCORE ========================================
int score(int food, int pu)
{
	int score, p = 0;

	score = food * 100;
	if (pu == 1 || pu == 0)
		score = score + 50;

	printf("\n\n       Score %d\n\n", score);

	return 0;
}


//==================	NEXT LEVEL, megalwma tablo========================================

void next_level(int arithmos_grammwn, int arithmos_stilwn, int ebodia, int pu, int megethos, int score) {

	char** 	tablo;
	int** sudetagmenes;
	int i, j;


	printf("\n~~~~~~~~~~~~~~~~~~NEXT LEVEL~~~~~~~~~~~~~~~~~~~\n\n\n");

	//dunamikh desmeush mnhmhs
	tablo = (char**)malloc((arithmos_stilwn + 2) * sizeof(char *));

	for (i = 0; i<(arithmos_stilwn + 2); i++)
	{
		tablo[i] = (char *)malloc((arithmos_grammwn + 2) * sizeof(char));
	}

	tablo_dots(tablo, arithmos_grammwn, arithmos_stilwn);

	sudetagmenes = levels(arithmos_grammwn, arithmos_stilwn, ebodia, tablo, pu, megethos, score);

}


//==================	metritis faghtou ascii-int========================================

char count_food(int arxiko)
{
	int i;
	char food_char;

	for (i = 0; i<9; i++) {
		food_char = (49 + arxiko);
	}

	return food_char;
}

//==================	EMFANISI TABLO ========================================

char* ektupwsi(int arithmos_stilwn, int arithmos_grammwn, char** tablo)
{
	int i, j;

	printf("\n\n\n\n");
	for (i = 0; i<(arithmos_stilwn + 2); i++) {
		for (j = 0; j<(arithmos_grammwn + 2); j++) {
			printf("%c  ", tablo[i][j]);
		}
		printf("\n");
	}



	return 0;
}
//==================	EFARMOGI PU2   ========================================

int efarmogi_pu2(int epilogi_pu, int megethos, int score)
{
	epilogi_pu = 2;
	if (epilogi_pu == 1)
	{
		score = score + 1500;
		return score;
	}
	else if (epilogi_pu == 2)
	{
		megethos = megethos - 2;
		return megethos;
	}
	return 0;
}




//==================	EFARMOGI PU   ========================================

char** efarmogi_pu(char** tablo, int** sudetagmenes, int epilogi_pu, int thesi_fidiou, int megethos, int score)
{

	if (epilogi_pu == 3)
	{
		tablo[sudetagmenes[0][0]][sudetagmenes[1][0]] = '.';
		tablo[sudetagmenes[0][1]][sudetagmenes[1][1]] = '.';
	}
	return tablo;
}

//==================	POWERUPS   ========================================
int powerup(int pu, int epilogi_pu)
{

	int p, i, food = 0;

	if (epilogi_pu == 1)
	{
		printf("\n	Epelexes na kerdiseis podous.\n");
		return epilogi_pu;
	}
	else if (epilogi_pu == 2)
	{
		printf("\n	Epelexes na meiwthei to mikos tou fidiou.\n");
		return epilogi_pu;

	}
	else if (epilogi_pu == 3)
	{
		printf("\n	Epelexes na afairethoun duo tetragwna apo ta edodia.\n");
		return epilogi_pu;

	}

	return pu;
}



//==================	ELEGXOS EGKUROTHTAS TWN KINISEWN   ========================================

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!an einai la8os na xana dinei times!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
char *kiniseis(int pu)
{
	char string[100];
	int count_letters = 0, gramma, number, k = 1, p;
	char kin_fidiou[2];


	while (k == 1) {
		k = 0;
		printf("\n Give your move(s):");
		gets(string);
		//printf( "\n,string[0]=%c",string[0]);
		//printf( "\n string[1]=%c",string[0]);
		fflush(stdin);                 //ka8arizei to "enter"
		while (string[count_letters] != '\0')
		{
			count_letters++;
		}
		if (string[0] == 'X' || string[0] == 'x' || string[1] == 'X' || string[1] == 'x')
		{
			printf("End Game\n");
			kin_fidiou[0] = string[0];
			return kin_fidiou;
		}
		if (string[0] == 'P' || string[0] == 'p')
		{

			kin_fidiou[0] = string[0];
			return kin_fidiou;
		}
		if ((count_letters % 2) != 0)			//gia na einai sigoura gramma k ari8mos , ara 8elw zugo ari8mo edolwn
		{
			printf("\n monos ari8mos kinisewn\n:");
			count_letters = 0;
			k = 1;
		}
		if (count_letters<0 || count_letters>2)
		{
			printf("\n polles kiniseis\n:");
			count_letters = 0;
			k = 1;
		}

		if (string[0] != 'U' && string[0] != 'u' && string[0] != 'D' && string[0] != 'd'&& string[0] != 'L'&& string[0] != 'l'&& string[0] != 'R'&& string[0] != 'r' && string[0] != 'P'&& string[0] != 'p')
		{
			printf("\n LA8OS gramma\n");
			count_letters = 0;
			k = 1;

		}
		if (string[1] != '0' && string[1] != '1' && string[1] != '2' && string[1] != '3' && string[1] != '4'&& string[1] != '5' && string[1] != '6' && string[1] != '7' && string[1] != '8' && string[1] != '9')
		{
			printf("\n LA8OS ARI8MOS\n");
			k = 1;
		}
	}
	kin_fidiou[0] = string[0];
	kin_fidiou[1] = string[1];

	return kin_fidiou;
}


//==================	LEVELS   ========================================

int**levels(int arithmos_grammwn, int arithmos_stilwn, int ebodia, char **tablo, int pu, int megethos, int score)
{
	srand((unsigned)time(NULL));
	int* tuxaiotita(int arithmos_grammwn, int arithmos_stilwn);	//dilwsi ths sunartisis pou 8a kalesw
	int i, j, k, mk, ex, ey, epilogi_ebodiou, snake_ex, snake_ey, stili, grammi, choose, food_ex, food_ey, r, a, powerup_ex, powerup_ey, arrayPu_x[2], arrayPu_y[2], epilogi_pu;
	int** sudetagmenes;
	int ** pithana_ebodia;
	double ex_1, ey_1, snake_ex_1, snake_ey_1, epilogi_ebodiou_1, choose_1, food_ex_1, food_ey_1, rd, powerup_ex_1, powerup_ey_1, epilogi_pu_1;
	int count = 0, new_level = 0, arxiko = 0;
	bool  test2 = false;
	char *kin_fidiou, food_char;
	int thesi_fidiou[300][2];
	//int megethos = 3; //arxiko megethos fidiou
	bool test4 = false;
	int food;
	int tempx, tempy;

	if (ebodia<1)						//epd ton dilwsa int dinei akeraio me stroggulopoihsh pros ta karw
		ebodia = 1;						//gia na xekinaei me 1 ebodio ka8e paixnidi

	stili = 2;							//h stili tha nai pada 2  (x,y)
	grammi = (ebodia);						//h grammi einai osa ta ebodia


											//dunamiki desmeush gia tin apothikeush sudetagemwn
	sudetagmenes = (int **)malloc(2 * sizeof(int *));
	for (i = 0; i<2; i++)
	{
		sudetagmenes[i] = (int *)malloc(grammi * sizeof(int));
	}

	//dunamiki desmeush gia tin apothikeush pi8anwn ebodiwn
	pithana_ebodia = (int **)malloc(2 * sizeof(int *));
	for (i = 0; i<2; i++)
	{
		pithana_ebodia[i] = (int *)malloc((ebodia * 4) * sizeof(int));
	}

	epilogi_ebodiou_1 = (double)rand() / ((double)RAND_MAX + 1);
	epilogi_ebodiou_1 = epilogi_ebodiou_1*arithmos_stilwn + 2;						//dinei apotelesma 2-ari8mo grammwn (gt o pinakas mas einai+1grammi)
	ex = (int)epilogi_ebodiou_1;
	sudetagmenes[0][0] = ex;
	ey_1 = (double)rand() / ((double)RAND_MAX + 1);
	ey_1 = ey_1*(arithmos_grammwn)+2;					//dinei apotelesma 2-ari8mo grammwn (gt o pinakas mas einai+1grammi)
	ey = (int)ey_1;
	sudetagmenes[1][0] = ey;
	j = 0;
	tablo[ex][ey] = '#';
	// printf("to %d ebodio exei: EX=%d EY=%d  \n",j+1, sudetagmenes[0][0] , sudetagmenes[1][0]);


	for (j = 1; j<grammi; j++)										//gemizei ton pinaka sudetagmenwn me tuxaies times ex,ey
	{
		mk = (j - 1) * 4;				//mk einai oi grammes twn pi8anwn ebodiwn

		pithana_ebodia[0][mk] = ex;			//ex sta8ero , ey allazei
		pithana_ebodia[1][mk] = ey - 1;

		mk++;
		pithana_ebodia[0][mk] = ex;
		pithana_ebodia[1][mk] = ey + 1;

		mk++;

		pithana_ebodia[1][mk] = ey;			//ey sta8ero ,ex allazei
		pithana_ebodia[0][mk] = ex - 1;


		mk++;
		pithana_ebodia[1][mk] = ey;
		pithana_ebodia[0][mk] = ex + 1;


		while (test2 == false)
		{
			epilogi_ebodiou_1 = (double)rand() / ((double)RAND_MAX + 1);
			epilogi_ebodiou_1 = epilogi_ebodiou_1*mk;						//dinei apotelesma 0-3
			epilogi_ebodiou = (int)epilogi_ebodiou_1;

			//printf("\nepilogi ebodiou:%d\n",epilogi_ebodiou);
			test2 = true;

			ey = pithana_ebodia[1][epilogi_ebodiou];
			ex = pithana_ebodia[0][epilogi_ebodiou];

			//  printf("\nmesa sth while test2: EX=%d EY=%d  \n", ex ,ey);

			if ((pithana_ebodia[0][epilogi_ebodiou] <= (arithmos_stilwn + 1)) && (pithana_ebodia[1][epilogi_ebodiou] <= (arithmos_grammwn + 1)))
			{
				if (tablo[ex][ey] == '.')
				{
					test2 = true;
					sudetagmenes[0][j] = ex;
					sudetagmenes[1][j] = ey;
					tablo[ex][ey] = '#';
				}
				else if (tablo[ex][ey] != '.')
				{
					test2 = false;
				}
			}
			else		//xepernaei ta oria
			{
				test2 = false;
			}
		}//telos while
		test2 = false;
	}


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ E L E G X O S ARXIKOU FIDIOU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	test2 = false;
	int tempax, tempay;

	while (test2 == false)
	{
		snake_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
		snake_ex_1 = snake_ex_1*(arithmos_stilwn - 4) + 4;						//xekinaei apo to 3(opws fainetai st pinaka,gia na xei peri8wrio t fidi)
		snake_ex = (int)snake_ex_1;

		snake_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
		snake_ey_1 = snake_ey_1*(arithmos_grammwn - 4) + 4;						//periorizetai gia to arxiko mege8os tou fidiou
		snake_ey = (int)snake_ey_1;

		//  printf("\n8ESH FIDIOU: EX=%d EY=%d  \n", snake_ex ,snake_ey);
		if (tablo[snake_ex][snake_ey] == '.')
		{
			thesi_fidiou[0][0] = snake_ex;
			thesi_fidiou[0][1] = snake_ey;
			tablo[snake_ex][snake_ey] = 'O';
			test2 = true;
		}
	}//telos while(test2==false)

	bool test3;
	int x;

	for (x = 1; x<megethos; x++)
	{
		// printf("mpike gia %d apo %d \n", x, megethos);
		test3 = false;
		while (test3 == false)
		{
			rd = (double)rand() / ((double)RAND_MAX + 1);
			rd = rd * 4 + 1;
			r = (int)rd;
			//  printf("dialeskse to %d  ",r);

			if (r == 1)
			{
				tempax = thesi_fidiou[x - 1][0] - 1;
				tempay = thesi_fidiou[x - 1][1];
				if (tempax<2)
				{
					tempax = arithmos_grammwn - 1;
				}
				if (tablo[tempax][tempay] == '.')
				{
					thesi_fidiou[x][0] = tempax;
					thesi_fidiou[x][1] = tempay;
					test3 = true;
				}
				else
				{
					test3 = false;
				}

			}
			else if (r == 2)
			{
				tempax = thesi_fidiou[x - 1][0] + 1;
				tempay = thesi_fidiou[x - 1][1];
				if (tempax>arithmos_grammwn - 1)
				{
					tempax = 2;
				}
				if (tablo[tempax][tempay] == '.')
				{
					thesi_fidiou[x][0] = tempax;
					thesi_fidiou[x][1] = tempay;
					test3 = true;
				}
				else
				{
					test3 = false;
				}

			}
			else if (r == 3)
			{
				tempax = thesi_fidiou[x - 1][0];
				tempay = thesi_fidiou[x - 1][1] - 1;
				if (tempay<2)
				{
					tempay = arithmos_stilwn - 1;
				}
				if (tablo[tempax][tempay] == '.')
				{
					thesi_fidiou[x][0] = tempax;
					thesi_fidiou[x][1] = tempay;
					test3 = true;
				}
				else
				{
					test3 = false;
				}
			}
			else if (r == 4)
			{
				tempax = thesi_fidiou[x - 1][0];
				tempay = thesi_fidiou[x - 1][1] + 1;
				if (tempay>arithmos_stilwn - 1)
				{
					tempay = 2;
				}
				if (tablo[tempax][tempay] == '.')
				{
					thesi_fidiou[x][0] = tempax;
					thesi_fidiou[x][1] = tempay;
					test3 = true;
				}
				else
				{
					test3 = false;
				}
			}
			// printf("i oura %d pigainei sti thesi X: %d Y: %d \n",x+1,tempax,tempay);
		}//while test3
	}


	for (x = 1; x <= megethos - 1; x++)
	{
		tablo[thesi_fidiou[x][0]][thesi_fidiou[x][1]] = 'X';
	}

	ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ E  L  E  G  X  O  S       F    O    O     D ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	i = 1;
	food_char = 1;
	bool test1;

	test1 = false;
	while (test1 == false)
	{
		food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
		food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
		food_ex = (int)food_ex_1;

		food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
		food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
		food_ey = (int)food_ey_1;
		//printf("\n8ESH FAGHTOY: EX=%d EY=%d  \n", food_ex ,food_ey);

		if ((food_ex <= (arithmos_stilwn + 1)) && (food_ey <= (arithmos_grammwn + 1)))
		{
			if (tablo[food_ex][food_ey] == '.')
			{
				test1 = true;
				tablo[food_ex][food_ey] = count_food(arxiko);
				ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
			}
			else if (tablo[food_ex][food_ey] != '.')
			{
				test1 = false;
			}
		}
		else
		{
			test1 = false;
		}
		ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
	}//telos while

	 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ topo8ethsh ebodiwn~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	for (j = 0; j<grammi; j++) {
		//printf("To %do empodio einai : ", j+1);
		for (i = 0; i<2; i++) {
			if (i == 0)
				ex = sudetagmenes[i][j];
			else
				ey = sudetagmenes[i][j];
			//printf("%d ", sudetagmenes[i][j]);	//mono gia nw ta shmeia se morfi pinaka
		}
		printf("\n");
	}
	printf("\n\n\n");
	ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
	food = 0;


	fflush(stdin);                 //ka8arizei to "enter"

	char kinisi_gramma, kinisi_arithmos;
	int temp_x, temp_y, temp1x, temp1y, temp2x, temp2y, c, fores_epanalipsis, z, ca = 0, zwes = 3;
	bool test5;

	test4 = false;

	do
	{
		kin_fidiou = kiniseis(pu);
		kinisi_gramma = kin_fidiou[0];
		kinisi_arithmos = kin_fidiou[1];
		fores_epanalipsis = kinisi_arithmos - '0';				//o char ari8mos ginetai int

		if (kinisi_gramma == 'u' || kinisi_gramma == 'U')			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ elexos kinhsewn
		{

			for (i = 1; i <= fores_epanalipsis; i++)
			{
				if (thesi_fidiou[0][0] - 1<2)					//elegxos gia to perasma tou fidiou apo th mia meria sthn allh
				{
					temp_x = arithmos_stilwn + 2;
					temp_y = thesi_fidiou[0][1];
				}
				else
				{				  //s  g
					temp_x = thesi_fidiou[0][0];
					temp_y = thesi_fidiou[0][1];
				}

				tablo[thesi_fidiou[megethos - 1][0]][thesi_fidiou[megethos - 1][1]] = '.';

				temp2x = thesi_fidiou[0][0];
				temp2y = thesi_fidiou[0][1];

				thesi_fidiou[0][0] = temp_x - 1;
				thesi_fidiou[0][1] = temp_y;


				for (j = 1; j<megethos; j++)
				{
					temp1x = temp2x;
					temp1y = temp2y;

					temp2x = thesi_fidiou[j][0];
					temp2y = thesi_fidiou[j][1];

					thesi_fidiou[j][0] = temp1x;
					thesi_fidiou[j][1] = temp1y;

					tablo[thesi_fidiou[j][0]][thesi_fidiou[j][1]] = 'X';
				}

				if (tablo[temp_x - 1][temp_y] == '#')
				{
					zwes--;
					if (zwes == 0)
					{
						return 0;
					}
					printf("\nsou apomenoun %d zwes. \n", zwes);

				}

				if (tablo[temp_x - 1][temp_y] == '@')		//prepei na emfanizetai k gia pu=1 wste na blepei tis epiloges
				{

					epilogi_pu_1 = (double)rand() / ((double)RAND_MAX + 1);			//tuxaia epilogi gia to powerup
					epilogi_pu_1 = epilogi_pu_1 * 3 + 1;
					epilogi_pu = (int)epilogi_pu_1;
					//printf("epilogi:%d",epilogi_pu);
					powerup(pu, epilogi_pu);
					if (epilogi_pu == 1)
					{
						score = score + efarmogi_pu2(epilogi_pu, megethos, score);
						printf("\n\n			SCORE:%d\n\n", score);
					}
					if (epilogi_pu == 2)
					{
						tablo[thesi_fidiou[megethos - 1][0]][thesi_fidiou[megethos - 1][1]] = '.';
						tablo[thesi_fidiou[megethos - 2][0]][thesi_fidiou[megethos - 2][1]] = '.';
						megethos = efarmogi_pu2(epilogi_pu, megethos, score);
					}
					if (epilogi_pu == 3)
					{
						efarmogi_pu(tablo, sudetagmenes, epilogi_pu, thesi_fidiou[300][2], megethos, score);
					}

					ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
				}

				if (tablo[temp_x - 1][temp_y] == '1' || tablo[temp_x - 1][temp_y] == '2' || tablo[temp_x - 1][temp_y] == '3' || tablo[temp_x - 1][temp_y] == '4' || tablo[temp_x - 1][temp_y] == '5')
				{
					test2 = false;
					// printf("\nmpike stin IF gia to fagito gia %d , apo %d\n", i,food);
					while (test2 == false)
					{
						//printf("\nmpike sti WHILE gia to fagito\n");
						food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
						food_ex = (int)food_ex_1;

						food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
						food_ey = (int)food_ey_1;
						// printf("\n8ESH FAGHTOY: EX=%d EY=%d  \n", food_ex ,food_ey);
						fflush(stdin);											     //ka8arizei to "enter"


						if ((food_ex <= (arithmos_stilwn + 1)) && (food_ey <= (arithmos_grammwn + 1)))
						{

							if (tablo[food_ex][food_ey] == '.')
							{
								test2 = true;
								ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);

							}
							else if (tablo[food_ex][food_ey] != '.')
							{
								test2 = false;
							}
						}

						ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
					}//telos while

					ca++;//metritis
					score = score + (ca * 100);
					printf("\n\n			SCORE:%d\n\n", score);

					test5 = false;
					while (ca<5 && test5 == false)
					{
						food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
						food_ex = (int)food_ex_1;

						food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
						food_ey = (int)food_ey_1;

						if (tablo[food_ex][food_ey] == '.')
						{
							tablo[food_ex][food_ey] = 49 + ca;
							ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);

							food = tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] - '0';
							fflush(stdin);                 //ka8arizei to "enter"
														   // printf("/n/n/n/nefage to fagito %d\n\n", food);
							test5 = true;
						}
						else
						{
							test5 = false;
						}

					}

					for (z = 1; z <= food; z++)
					{
						fflush(stdin);                 //ka8arizei to "enter"

													   // printf("\nmpike sti FOR gia na megalwsei apo z=%d se food=%d \n",z, food);
						test4 = false;
						while (test4 == false)
						{
							fflush(stdin);                 //ka8arizei to "enter"
							rd = (double)rand() / ((double)RAND_MAX + 1);
							rd = rd * 4 + 1;
							r = (int)rd;

							if (r == 1)
							{
								// printf("\n\n\nmesa stin if r==1");
								tempx = thesi_fidiou[megethos - 1][0] - 1;
								tempy = thesi_fidiou[megethos - 1][1];
								//printf("\ntempx=%d", tempx);
								// printf("\ntempx=%d", tempx);
								if (tempx<2)
								{
									//printf("\n\n tempx<2");
									tempx = arithmos_stilwn + 1;
									// printf("\n tempy=%d", tempy);
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 2)
							{
								//printf("\n\n\nmesa stin if r==2");
								tempx = thesi_fidiou[megethos - 1][0] + 1;
								tempy = thesi_fidiou[megethos - 1][1];
								//printf("\ntempx=%d", tempx);
								//printf("\ntempy=%d", tempy);
								if (tempx>arithmos_stilwn + 1)
								{
									tempx = 2;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 3)
							{
								//printf("\n\n\nmesa stin if r==3");
								tempx = thesi_fidiou[megethos - 1][0];
								tempy = thesi_fidiou[megethos - 1][1] - 1;
								//printf("\ntempx=%d", tempx);
								//printf("\ntempy=%d", tempy);
								if (tempy<2)
								{
									tempy = arithmos_grammwn;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 4)
							{
								//printf("\n\n\nmesa stin if r==4");
								tempx = thesi_fidiou[megethos - 1][0];
								tempy = thesi_fidiou[megethos - 1][1] + 1;
								//	printf("\ntempx=%d", tempx);  
								//	printf("\ntempy=%d", tempy);
								if (tempy>arithmos_grammwn + 1)
								{
									tempy = 2;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
						}
						megethos = megethos + 1;
						//printf("to megehtos tou fidiou egine %d" , megethos);
					}

				}//telos if , gia ta 1,2,3,4

				if (tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] == 'X')
				{
					printf("\n\nExases. epeses panw sto swma sou\n");
					return 0;
				}

				tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] = 'O';
				ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
				printf("\n\n			SCORE:%d\n\n", score);
			}
		}
		if (kinisi_gramma == 'd' || kinisi_gramma == 'D')
		{
			for (i = 1; i <= fores_epanalipsis; i++)
			{
				if (thesi_fidiou[0][0] + 1>arithmos_stilwn + 1)					//elegxos gia to perasma tou fidiou apo th mia meria sthn allh
				{
					temp_x = 1;
					temp_y = thesi_fidiou[0][1];
				}
				else
				{						//s  g
					temp_x = thesi_fidiou[0][0];
					temp_y = thesi_fidiou[0][1];
				}
				tablo[thesi_fidiou[megethos - 1][0]][thesi_fidiou[megethos - 1][1]] = '.';

				temp2x = thesi_fidiou[0][0];
				temp2y = thesi_fidiou[0][1];

				thesi_fidiou[0][0] = temp_x + 1;
				thesi_fidiou[0][1] = temp_y;

				for (j = 1; j<megethos; j++)
				{
					temp1x = temp2x;
					temp1y = temp2y;

					temp2x = thesi_fidiou[j][0];
					temp2y = thesi_fidiou[j][1];

					thesi_fidiou[j][0] = temp1x;
					thesi_fidiou[j][1] = temp1y;

					tablo[thesi_fidiou[j][0]][thesi_fidiou[j][1]] = 'X';
				}

				if (tablo[temp_x + 1][temp_y] == '#')
				{
					zwes--;
					if (zwes == 0)
					{
						return 0;
					}
					printf("\n Sou apomenoun %d zwes.\n", zwes);
				}
				if (tablo[temp_x + 1][temp_y] == '@')		//prepei na emfanizetai k gia pu=1 wste na blepei tis epiloges
				{

					epilogi_pu_1 = (double)rand() / ((double)RAND_MAX + 1);			//tuxaia epilogi gia to powerup
					epilogi_pu_1 = epilogi_pu_1 * 3 + 1;
					epilogi_pu = (int)epilogi_pu_1;
					//printf("epilogi:%d",epilogi_pu);
					powerup(pu, epilogi_pu);
					if (epilogi_pu == 1) {
						score = score + efarmogi_pu2(epilogi_pu, megethos, score);
						printf("\n\n			SCORE:%d\n\n", score);
					}
					if (epilogi_pu == 2)
					{
						tablo[thesi_fidiou[megethos - 1][0]][thesi_fidiou[megethos - 1][1]] = '.';
						tablo[thesi_fidiou[megethos - 2][0]][thesi_fidiou[megethos - 2][1]] = '.';
						megethos = efarmogi_pu2(epilogi_pu, megethos, score);
					}
					if (epilogi_pu == 3)
					{
						efarmogi_pu(tablo, sudetagmenes, epilogi_pu, thesi_fidiou[300][2], megethos, score);
					}
					ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
				}

				if (tablo[temp_x + 1][temp_y] == '1' || tablo[temp_x + 1][temp_y] == '2' || tablo[temp_x + 1][temp_y] == '3' || tablo[temp_x + 1][temp_y] == '4' || tablo[temp_x + 1][temp_y] == '5')
				{
					test2 = false;
					while (test2 == false)
					{
						food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
						food_ex = (int)food_ex_1;

						food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
						food_ey = (int)food_ey_1;

						// printf("\n8ESH FAGHTOY: EX=%d EY=%d  \n", food_ex ,food_ey);
						if ((food_ex <= (arithmos_stilwn + 1)) && (food_ey <= (arithmos_grammwn + 1)))
						{
							if (tablo[food_ex][food_ey] == '.' && tablo[food_ex][food_ey] != 'X')
							{
								test2 = true;
								ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
							}
							else if (tablo[food_ex][food_ey] != '.')
							{
								test2 = false;
							}
						}
						ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
					}//telos while
					ca++;//metritis

					score = score + (ca * 100);
					printf("\n\n			SCORE:%d\n\n", score);

					test5 = false;
					while (ca<5 && test5 == false)
					{
						food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
						food_ex = (int)food_ex_1;

						food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
						food_ey = (int)food_ey_1;

						if (tablo[food_ex][food_ey] == '.')
						{
							tablo[food_ex][food_ey] = 49 + ca;
							ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
							food = tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] - '0';
							//  printf("/n/n/n/nefage to fagito %d\n\n", food);
							test5 = true;
						}
						else
						{
							test5 = false;
						}
					}

					for (z = 1; z <= food; z++)
					{
						//printf("\nmpike sti FOR gia na megalwsei apo %d se %d \n",z, food);
						test4 = false;
						printf("kanei to test4 = false");
						while (test4 == false)
						{
							rd = (double)rand() / ((double)RAND_MAX + 1);
							rd = rd * 4 + 1;
							r = (int)rd;
							// printf("dialekse to %d \n",r);
							if (r == 1)
							{
								tempx = thesi_fidiou[megethos - 1][0] - 1;
								tempy = thesi_fidiou[megethos - 1][1];
								if (tempx<2)
								{
									tempx = arithmos_stilwn + 1;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 2)
							{
								tempx = thesi_fidiou[megethos - 1][0] + 1;
								tempy = thesi_fidiou[megethos - 1][1];
								if (tempx>arithmos_stilwn + 1)
								{
									tempx = 2;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 3)
							{
								tempx = thesi_fidiou[megethos - 1][0];
								tempy = thesi_fidiou[megethos - 1][1] - 1;
								if (tempy<2)
								{
									tempy = arithmos_grammwn + 1;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 4)
							{
								tempx = thesi_fidiou[megethos - 1][0];
								tempy = thesi_fidiou[megethos - 1][1] + 1;
								if (tempy>arithmos_grammwn + 1)
								{
									tempy = 2;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
						}
						megethos = megethos + 1;
						//  printf("to megehtos tou fidiou egine %d" , megethos);
					}
				}

				if (tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] == 'X')
				{
					printf("\n\nExases. epeses panw sto swma sou\n");
					return 0;
				}
				tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] = 'O'; //trwei to prwto faghto
				ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
				printf("\n\n			SCORE:%d\n\n", score);
			}
		}
		else if (kinisi_gramma == 'l' || kinisi_gramma == 'L')
		{
			for (i = 1; i <= fores_epanalipsis; i++)
			{
				if (thesi_fidiou[0][1] - 1<2)					//elegxos gia to perasma tou fidiou apo th mia meria sthn allh
				{
					temp_x = thesi_fidiou[0][0];
					temp_y = arithmos_grammwn + 2;
				}
				else
				{			//s  g
					temp_x = thesi_fidiou[0][0];
					temp_y = thesi_fidiou[0][1];
				}
				tablo[thesi_fidiou[megethos - 1][0]][thesi_fidiou[megethos - 1][1]] = '.';
				temp2x = thesi_fidiou[0][0];
				temp2y = thesi_fidiou[0][1];

				thesi_fidiou[0][0] = temp_x;
				thesi_fidiou[0][1] = temp_y - 1;

				for (j = 1; j<megethos; j++)
				{
					temp1x = temp2x;
					temp1y = temp2y;

					temp2x = thesi_fidiou[j][0];
					temp2y = thesi_fidiou[j][1];

					thesi_fidiou[j][0] = temp1x;
					thesi_fidiou[j][1] = temp1y;
					tablo[thesi_fidiou[j][0]][thesi_fidiou[j][1]] = 'X';
				}
				if (tablo[temp_x][temp_y - 1] == '#')
				{
					zwes--;
					if (zwes == 0)
					{
						return 0;
					}
					printf("\nsou apomenoun %d zwes.\n", zwes);
				}
				if (tablo[temp_x][temp_y - 1] == '@') {		//prepei na emfanizetai k gia pu=1 wste na blepei tis epiloges


					epilogi_pu_1 = (double)rand() / ((double)RAND_MAX + 1);			//tuxaia epilogi gia to powerup
					epilogi_pu_1 = epilogi_pu_1 * 3 + 1;
					epilogi_pu = (int)epilogi_pu_1;
					//printf("epilogi:%d",epilogi_pu);

					powerup(pu, epilogi_pu);
					if (epilogi_pu == 1) {
						score = score + efarmogi_pu2(epilogi_pu, megethos, score);
						printf("\n\n			SCORE:%d\n\n", score);
					}
					if (epilogi_pu == 2)
					{
						tablo[thesi_fidiou[megethos - 1][0]][thesi_fidiou[megethos - 1][1]] = '.';
						tablo[thesi_fidiou[megethos - 2][0]][thesi_fidiou[megethos - 2][1]] = '.';
						megethos = efarmogi_pu2(epilogi_pu, megethos, score);
					}
					if (epilogi_pu == 3)
					{
						efarmogi_pu(tablo, sudetagmenes, epilogi_pu, thesi_fidiou[300][2], megethos, score);
					}
					ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
				}
				if (tablo[temp_x][temp_y - 1] == '1' || tablo[temp_x][temp_y - 1] == '2' || tablo[temp_x][temp_y - 1] == '3' || tablo[temp_x][temp_y - 1] == '4' || tablo[temp_x][temp_y - 1] == '5')
				{
					test2 = false;
					while (test2 == false)
					{
						food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
						food_ex = (int)food_ex_1;

						food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
						food_ey = (int)food_ey_1;
						// printf("\n8ESH FAGHTOY: EX=%d EY=%d  \n", food_ex ,food_ey);
						if ((food_ex <= (arithmos_stilwn + 1)) && (food_ey <= (arithmos_grammwn + 1)))
						{
							if (tablo[food_ex][food_ey] == '.' && tablo[food_ex][food_ey] != 'X')
							{
								test2 = true;
								ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
							}
							else if (tablo[food_ex][food_ey] != '.')
							{
								test2 = false;
							}
						}
						ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
					}//telos while
					ca++;//metritis
					score = score + (ca * 100);
					printf("\n\n			SCORE:%d\n\n", score);
					test5 = false;
					while (ca<5 && test5 == false)
					{
						food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
						food_ex = (int)food_ex_1;

						food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
						food_ey = (int)food_ey_1;

						if (tablo[food_ex][food_ey] == '.')
						{
							tablo[food_ex][food_ey] = 49 + ca;
							ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
							food = tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] - '0';
							// printf("/n/n/n/nefage to fagito %d\n\n", food);
							test5 = true;
						}
						else
						{
							test5 = false;
						}
					}

					for (z = 1; z <= food; z++)
					{
						test4 = false;
						while (test4 == false)
						{
							rd = (double)rand() / ((double)RAND_MAX + 1);
							rd = rd * 4 + 1;
							r = (int)rd;

							if (r == 1)
							{
								tempx = thesi_fidiou[megethos - 1][0] - 1;
								tempy = thesi_fidiou[megethos - 1][1];
								if (tempx<2)
								{
									tempx = arithmos_stilwn + 1;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}

							else if (r == 2)
							{
								tempx = thesi_fidiou[megethos - 1][0] + 1;
								tempy = thesi_fidiou[megethos - 1][1];
								if (tempx>arithmos_stilwn + 1)
								{
									tempx = 2;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 3)
							{
								tempx = thesi_fidiou[megethos - 1][0];
								tempy = thesi_fidiou[megethos - 1][1] - 1;
								if (tempy<2)
								{
									tempy = arithmos_grammwn + 1;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 4)
							{
								tempx = thesi_fidiou[megethos - 1][0];
								tempy = thesi_fidiou[megethos - 1][1] + 1;
								if (tempy>arithmos_grammwn + 1)
								{
									tempy = 2;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
						}
						megethos = megethos + 1;
						//  printf("to megehtos tou fidiou egine %d" , megethos);
					}
				}

				if (tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] == 'X')
				{
					printf("\n\nExases. epeses panw sto swma sou\n");
					return 0;
				}
				tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] = 'O';
				ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
				printf("\n\n			SCORE:%d\n\n", score);
			}

		}
		else if (kinisi_gramma == 'r' || kinisi_gramma == 'R')
		{

			for (i = 1; i <= fores_epanalipsis; i++)
			{
				if (thesi_fidiou[0][1] + 1>arithmos_grammwn + 1)					//elegxos gia to perasma tou fidiou apo th mia meria sthn allh
				{
					temp_x = thesi_fidiou[0][0];
					temp_y = 1;
				}
				else
				{			//s  g
					temp_x = thesi_fidiou[0][0];
					temp_y = thesi_fidiou[0][1];
				}

				tablo[thesi_fidiou[megethos - 1][0]][thesi_fidiou[megethos - 1][1]] = '.';
				temp2x = thesi_fidiou[0][0];
				temp2y = thesi_fidiou[0][1];

				thesi_fidiou[0][0] = temp_x;
				thesi_fidiou[0][1] = temp_y + 1;

				for (j = 1; j<megethos; j++)
				{
					temp1x = temp2x;
					temp1y = temp2y;

					temp2x = thesi_fidiou[j][0];
					temp2y = thesi_fidiou[j][1];

					thesi_fidiou[j][0] = temp1x;
					thesi_fidiou[j][1] = temp1y;
					tablo[thesi_fidiou[j][0]][thesi_fidiou[j][1]] = 'X';
				}

				if (tablo[temp_x][temp_y + 1] == '#')
				{
					zwes--;
					if (zwes == 0) {
						return 0;
					}
					printf("\nsou apomenoun %d zwes.\n", zwes);
				}


				if (tablo[temp_x][temp_y + 1] == '1' || tablo[temp_x][temp_y + 1] == '2' || tablo[temp_x][temp_y + 1] == '3' || tablo[temp_x][temp_y + 1] == '4' || tablo[temp_x][temp_y + 1] == '5')
				{
					test2 = false;

					while (test2 == false)
					{
						food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
						food_ex = (int)food_ex_1;

						food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
						food_ey = (int)food_ey_1;
						// printf("\n8ESH FAGHTOY: EX=%d EY=%d  \n", food_ex ,food_ey);

						if ((food_ex <= (arithmos_stilwn + 1)) && (food_ey <= (arithmos_grammwn + 1)))
						{
							if (tablo[food_ex][food_ey] == '.' && tablo[food_ex][food_ey] != 'X')
							{
								test2 = true;
								ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
							}
							else if (tablo[food_ex][food_ey] != '.')
							{
								test2 = false;
							}
						}
						ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
					}//telos while
					ca++;//metritis
					score = score + (ca * 100);
					printf("\n\n			SCORE:%d\n\n", score);

					test5 = false;
					while (ca<5 && test5 == false)
					{
						food_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ex_1 = food_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
						food_ex = (int)food_ex_1;

						food_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
						food_ey_1 = food_ey_1*(arithmos_grammwn)+2;
						food_ey = (int)food_ey_1;

						if (tablo[food_ex][food_ey] == '.')
						{
							tablo[food_ex][food_ey] = 49 + ca;
							ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
							food = tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] - '0';
							//printf("/n/n/n/nefage to fagito %d\n\n", food);
							test5 = true;
						}
						else
						{
							test5 = false;
						}
					}
					for (z = 1; z <= food; z++)
					{
						// printf("\nmpike sti FOR gia na megalwsei apo %d se %d \n",z, food);
						test4 = false;
						while (test4 == false)
						{
							rd = (double)rand() / ((double)RAND_MAX + 1);
							rd = rd * 4 + 1;
							r = (int)rd;
							// printf("dialekse to %d \n",r);
							if (r == 1)
							{
								tempx = thesi_fidiou[megethos - 1][0] - 1;
								tempy = thesi_fidiou[megethos - 1][1];
								if (tempx<2)
								{
									tempx = arithmos_stilwn + 1;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 2)
							{
								tempx = thesi_fidiou[megethos - 1][0] + 1;
								tempy = thesi_fidiou[megethos - 1][1];
								if (tempx>arithmos_stilwn + 1)
								{
									tempx = 2;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 3)
							{
								tempx = thesi_fidiou[megethos - 1][0];
								tempy = thesi_fidiou[megethos - 1][1] - 1;
								if (tempy<2)
								{
									tempy = arithmos_grammwn + 1;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
							else if (r == 4)
							{
								tempx = thesi_fidiou[megethos - 1][0];
								tempy = thesi_fidiou[megethos - 1][1] + 1;
								if (tempy>arithmos_grammwn + 1)
								{
									tempy = 2;
								}
								if (tablo[tempx][tempy] != '.')
								{
									test4 = false;
								}
								else
								{
									test4 = true;
									thesi_fidiou[megethos][0] = tempx;
									thesi_fidiou[megethos][1] = tempy;
									tablo[tempx][tempy] = 'X';
								}
							}
						}
						megethos = megethos + 1;
						// printf("to megehtos tou fidiou egine %d" , megethos);

					}
				}
				if (tablo[temp_x][temp_y + 1] == '@')		//prepei na emfanizetai k gia pu=1 wste na blepei tis epiloges
				{

					epilogi_pu_1 = (double)rand() / ((double)RAND_MAX + 1);			//tuxaia epilogi gia to powerup
					epilogi_pu_1 = epilogi_pu_1 * 3 + 1;
					epilogi_pu = (int)epilogi_pu_1;
					//printf("epilogi:%d",epilogi_pu);
					powerup(pu, epilogi_pu);
					if (epilogi_pu == 1) {
						score = score + efarmogi_pu2(epilogi_pu, megethos, score);
						printf("\n\n			SCORE:%d\n\n", score);
					}
					if (epilogi_pu == 2)
					{
						tablo[thesi_fidiou[megethos - 1][0]][thesi_fidiou[megethos - 1][1]] = '.';
						tablo[thesi_fidiou[megethos - 2][0]][thesi_fidiou[megethos - 2][1]] = '.';
						megethos = efarmogi_pu2(epilogi_pu, megethos, score);
						printf("\n\n\nmegethos %d", megethos);
					}
					if (epilogi_pu == 3)
					{
						efarmogi_pu(tablo, sudetagmenes, epilogi_pu, thesi_fidiou[300][2], megethos, score);
					}
					ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
				}
				if (tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] == 'X')
				{
					printf("\n\nExases. epeses panw sto swma sou\n");
					return 0;
				}


				tablo[thesi_fidiou[0][0]][thesi_fidiou[0][1]] = 'O';
				ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
				printf("\n\n			SCORE:%d\n\n", score);

			}//telos for
		}
		else if (kinisi_gramma == 'X' || kinisi_gramma == 'x')
		{
			printf("\n EXIT GAME.\n");
			zwes = 0;
		}
		else if (kinisi_gramma == 'P' || kinisi_gramma == 'p')				//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ E  L  E  G  X  O  S      POWERUP ~~~~~~~~~~~~		
		{
			i = 0;

			test2 = false;
			while (test2 == false)
			{
				if (pu<1)
				{
					printf("\n De dikaiousai alla powerUps.Ta powerups einai: %d", pu);
					break;
				}
				if (pu == 1 && tablo[powerup_ex][powerup_ey] == '@')
				{
					printf("\n Den efages to prwto powerup. De dikaiousai akoma deutero.");
					break;
				}
				if (pu == 1 && tablo[powerup_ex][powerup_ey] == 'O')
				{
					powerup(pu, epilogi_pu);
				}
				powerup_ex_1 = (double)rand() / ((double)RAND_MAX + 1);
				powerup_ex_1 = powerup_ex_1*(arithmos_stilwn)+2;						//gia eisodo 10X10 dinei times 2-11
				powerup_ex = (int)powerup_ex_1;

				powerup_ey_1 = (double)rand() / ((double)RAND_MAX + 1);
				powerup_ey_1 = powerup_ey_1*(arithmos_grammwn)+2;
				powerup_ey = (int)powerup_ey_1;

				if ((powerup_ex <= (arithmos_stilwn + 1)) && (powerup_ey <= (arithmos_grammwn + 1)))
				{
					if (tablo[powerup_ex][powerup_ey] == '.')
					{
						test2 = true;
						tablo[powerup_ex][powerup_ey] = '@';
						pu--;
						ektupwsi(arithmos_stilwn, arithmos_grammwn, tablo);
					}
					else if (tablo[powerup_ex][powerup_ey] != '.')
					{
						test2 = false;
					}
				}
				printf("\n Exeis %d powerups", pu);
			}//telos while
		}//telos else-if
		if (ca >= 5)		//dior8wma sun8hkhs			 klisi next level
		{

			arithmos_grammwn = arithmos_grammwn + 2;
			arithmos_stilwn = arithmos_stilwn + 2;
			new_level++;		//kainouro lev
			next_level(arithmos_grammwn, arithmos_stilwn, ebodia, pu, megethos, score);
			break;
		}
	}while (zwes != 0);


	//apodesmeush mnimis
	for (i = 0; i<2; i++)
	{
		free(sudetagmenes[i]);
	}
	//apodesmeusi
	for (i = 0; i<2; i++)
	{
		free(pithana_ebodia[i]);
	}
	return 0;
}



//================== tablo_dots (emfanish tablo me ari8mish)========================================

char* tablo_dots(char **tablo, int arithmos_grammwn, int arithmos_stilwn)		//na bgalw ta printf gia na mhn emfaizei ton pinaka sketo!!!!!!!
{
	int i, j, count_grammi, count_stili;
	int** aritmisi;
	int k = 1;
	int l = 1;

	for (i = 0; i<(arithmos_stilwn + 2); i++)
		for (j = 0; j<(arithmos_grammwn + 2); j++)
			tablo[i][j] = '.';

	tablo[1][0] = ' '; //kinisi
	tablo[1][1] = ' ';
	k = 0;
	for (i = 0; i<1; i++) {						//orizodia ari8misi
		for (j = 0; j<(arithmos_grammwn + 2); j++) {
			tablo[i][j] = (49 + k - 2);
			k++;
		}
	}

	tablo[0][0] = ' ';
	tablo[0][1] = ' ';
	for (i = 1; i<2; i++)							//grammes -
		for (j = 0; j<(arithmos_grammwn + 2); j++)
			tablo[i][j] = '-';

	k = 0;
	for (i = 1; (i<arithmos_stilwn + 2); i++) {		//stiles ari8misi
		for (j = 0; j<1; j++) {
			tablo[i][j] = (49 + k - 1);
			k++;
		}
	}

	tablo[1][0] = ' ';
	tablo[1][1] = ' ';

	for (i = 0; (i<arithmos_stilwn + 2); i++)		//stiles |
		for (j = 1; j<2; j++)
			tablo[i][j] = '|';

	return *tablo;
}


//======================elegxos eisodou twn akeraiwn========================

int* check_akeraiwn()
{
	int arithmos_grammwn, arithmos_stilwn, pinakas_akeraiwn[2];
	char term;


	do {
		printf("Columns:");
		while (scanf_s("%d%c", &arithmos_grammwn, &term) != 2 || term != '\n')
		{

			printf("Failure. Give an integer for row!\nRows:");
			if (scanf_s("%d%c", &arithmos_grammwn, &term) != 2 || term != '\n')
				scanf_s("%d", &arithmos_grammwn);
		}
		printf("   Rows:");
		while (scanf_s("%d%c", &arithmos_stilwn, &term) != 2 || term != '\n')
		{
			printf("Failure. Give an integer for column!\nColumns: ");
			if (scanf_s("%d%c", &arithmos_stilwn, &term) != 2 || term != '\n')
				scanf_s("%d", &arithmos_stilwn);
		}
	} while (arithmos_grammwn*arithmos_stilwn<14); //gia na borei na paixei sto easy ,na xwraei to fidaki ka8ws megalwnei -10 koutakia) + 1 gia ebodia +2 bonus
	printf("\n Your dashboard is: %dx%d\n\n", arithmos_grammwn, arithmos_stilwn);

	pinakas_akeraiwn[0] = arithmos_grammwn;
	pinakas_akeraiwn[1] = arithmos_stilwn;

	return pinakas_akeraiwn;	//ta bazw se pinaka wste na krataw tis 2 times

}