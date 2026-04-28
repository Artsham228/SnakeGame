#include <windows.h>
#include "Header.h"

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

