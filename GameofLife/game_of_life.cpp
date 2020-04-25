#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	int a = (rand() % 100) + 1;
	if (a<=25)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int game_of_life::broj_susjeda(int x, int y)
{
	int counter = 0;

	for (int i = x-1; i <= x+1; ++i)
	{

		for (int j = y-1; j <= y+1; ++j)
		{

			if (i<0 || j<0 ||i>REDAKA || j>STUPACA)
			{
				continue;
			}

			else if (i==x && j==y)
			{
				continue;
			}


			else if (_generacija[i][j])
			{
				counter++;
			}

		}

	}

	return counter;
	
}

char game_of_life::Znak(bool stanje)
{
	if (stanje)
	{
		return '0';
	}
	else
	{
		return '-';
	}
}

void game_of_life::zamjena()
{

	for (int i = 0; i < REDAKA; i++)
	{

		for (int j = 0; j < STUPACA; j++)
		{

			_generacija[i][j] = _sljedeca_generacija[i][j];

		}

	}

}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++)
	{

		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
			
		}

	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{

			int susjedi = broj_susjeda(i,j);

			if (_generacija[i][j]&&(susjedi==2 || susjedi==3))
			{
				_sljedeca_generacija[i][j] = 1;
			}

			 else if (_generacija[i][j]&&(susjedi<2 || susjedi>3))
			{
				_sljedeca_generacija[i][j] = 0;
			}
	 

			 else  if (!_generacija[i][j] && (susjedi==3))
			{
				_sljedeca_generacija[i][j] = 1;
			}


			 else  
			{
				_sljedeca_generacija[i][j] = 0;
			}

			 
			 
			 

		}


	}

	zamjena();

}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{

		for (int j = 0; j < STUPACA; j++)
		{
			cout << Znak(_generacija[i][j]);
		}
		cout << endl;
	}

}
