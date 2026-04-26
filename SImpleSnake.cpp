#include <iostream>
#include <conio.h>
#include <windows.h>
bool GameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score,speed;
int tailX[100], tailY[100];
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN };
eDirection dir;
void Setup()
{
	GameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	speed = 100;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width+2; i++)
		std::cout << '#';
	std::cout << std::endl;
	for (int i=0;i<height;i++)
	{
		for (int j=0;j<width;j++)
		{
			if (j == 0)
			{
				std::cout << '#';
			}
			if (i==y&&j==x)
			{
				std::cout << 'O';
			}
			else if (i==fruitY&&j==fruitX)
			{
				std::cout << 'F';

			}
			else
			{
				bool print = false;

				for (int k =0;k<nTail;k++)
				{
				if (tailX[k]==j&&tailY[k]==i)
				{
					std::cout << 'o';
					print = true;
				}
				
			}
				if (!print)
					std::cout << ' ';
			}
			if (j==width-1)
			{
				std::cout << '#';
			}
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < width+2; i++)
		std::cout << '#';
	std::cout << std::endl;
	std::cout << "Score: " << score;
};

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;

			break;
		case 's':
			dir = DOWN;

			break;
		case 'd':
			dir = RIGHT;

			break;
		case 'x':
			GameOver = true;

			break;
		}
	}
};
void Logic()
{
	int prevTailX = tailX[0];
	int prevTailY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i=1;i<nTail;i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevTailX;
		tailY[i] = prevTailY;
		prevTailX = prev2X;
		prevTailY = prev2Y;
	}
	if (x==fruitX&&y==fruitY)
	{
		score += 10;
		nTail++;
		speed -= 2;
		
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
			break;
	}
	/*if (x>=width||x<0||y<0||y>=height)
	{
		GameOver = true;
	}*/
	if (x >= width)x = 0; else if (x < 0)x = width - 1;
	if (y >= height)y = 0; else if (y < 0)y = height - 1;
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			GameOver = true;
		}
	}
};



int main()
{
	Setup();
	while (!GameOver)
	{
		Input();
		Logic();
		Draw();
		Sleep(speed);
	}
}

