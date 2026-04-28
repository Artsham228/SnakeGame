#pragma once
extern bool GameOver;
extern const int width;
extern const int height;
extern int x, y, fruitX, fruitY, score, speed;
extern int tailX[100], tailY[100];
extern int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

extern eDirection dir;

void Setup();
void Draw();
void Input();
void Logic();

