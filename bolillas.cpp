#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


void gotoxy(int x , int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void ocultarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = TRUE;

	SetConsoleCursorInfo(hCon, &cci);
}

void pintar_limites() {
	for (int i = 2; i < 70; i++)
	{
		gotoxy(i, 3);printf("%c", 205);
		gotoxy(i, 20);printf("%c", 205);

	}

	for (int i = 4; i < 20; i++)
	{
		gotoxy(2, i);printf("%c", 186);
		gotoxy(70, i);printf("%c", 186);

	}
	gotoxy(2, 3);printf("%c", 219);
	gotoxy(35, 3);printf("%c", 219);
	gotoxy(2, 20);printf("%c", 219);
	gotoxy(70, 3);printf("%c", 219);
	gotoxy(35, 20);printf("%c", 219);
	gotoxy(70, 20);printf("%c", 219);
}

class Bolilla
{
	int x, y;
public:

	void pintar();
	void borrar();
	void mover();

	Bolilla(int _x, int _y);
	

private:

};


Bolilla::Bolilla(int _x, int _y) {
	x = _x;
	y = _y;

}

void Bolilla::pintar()
{
	gotoxy(x, y);printf(" %c", 49);
}





void Bolilla::borrar()
{
	gotoxy(x, y);printf("     ");
}

void Bolilla::mover()
{

	if (_kbhit())
	{
		char tecla = _getch();
		borrar();
		if (tecla == IZQUIERDA && x>3)x--;
		if (tecla == DERECHA && x+6<70)x++;
		if (tecla == ARRIBA && y>4 )y--;
		if (tecla == ABAJO && y+1<20)y++; 
		pintar();

	}
}




int main() {

	ocultarCursor();
	pintar_limites();
	Bolilla N(7, 7);
	N.pintar();
	
	/*int x = 10, y = 10;
	gotoxy(x, y);printf("*");*/

	bool gameover = false;
	while (!gameover) {

		N.mover();  
		Sleep(30);
	}
	return 0;

}


