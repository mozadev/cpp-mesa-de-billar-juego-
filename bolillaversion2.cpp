#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<list>
#include<stdlib.h>

using namespace std;

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
	int tronera;
public:

	void pintar();
	void borrar();
	void mover();
	void desaparecer();

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


void Bolilla::desaparecer()
{
	if (tronera==0)
	{
		borrar();
		gotoxy(x, y);printf("  **  ");
		Sleep(200);
		borrar();
		gotoxy(x, y);printf(" * ** *  ");
		Sleep(200);
	}
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
		if (tecla == IZQUIERDA && x > 3)
		{
			x--;
		
		}
		if (tecla == DERECHA && x+6<70)x++;
		if (tecla == ARRIBA && y>4 )y--;
		if (tecla == ABAJO && y+1<20)y++; 
		pintar();

	}
}

class  Tiro {

	int x, y;
public:
	Tiro(int _x, int _y) : x(_x), y(_y) {}
	void mover();


};

void Tiro::mover() {
	gotoxy(x, y);printf("   ");
	if (y > 4) y--;
	gotoxy(x, y);printf("  * ");

}


class bolillas2
{
	int x,  y;
public:
	bolillas2(int _x, int _y ) : x(_x), y(_y) {}
	void pintar(int x);
	void mover();
};

void bolillas2::pintar(int c) {
	gotoxy(x, y);printf("%c", c);

}

void bolillas2::mover() {
	gotoxy(x, y);printf(" ");
	y=rand();
	if (y>32)
	{
		x = rand() % 70 + 4;
		y = 4;
	}
	
}



int main() {

	ocultarCursor();
	pintar_limites();
	Bolilla N(35, 19);
	N.pintar();
	
	bolillas2 bol2(15, 8);
	bol2.pintar(50);
	bolillas2 bol3(30, 6);
	bol3.pintar(51);
	bolillas2 bol4(40, 7);
	bol4.pintar(52);
	bolillas2 bol5(50, 8);
	bol5.pintar(53);
	bolillas2 bol6(45, 15);
	bol6.pintar(54);
	bolillas2 bol7(60, 10);
	bol7.pintar(55);
	bolillas2 bol8(10, 4);
	bol8.pintar(56);
	bolillas2 bol9(15, 14);
	bol9.pintar(57);




	/*int x = 10, y = 10;
	gotoxy(x, y);printf("*");*/

	list<Tiro*>bolillas;  // arreglo donde guardamos a un puntero de la clase tiros

	bool gameover = false;
	while (!gameover) {

		/*
			if (kbhit()) {
			char tecla = _getch();
			if(tecla==)

		}
		
		*/
	






		N.mover();  
		Sleep(30);
	}
	return 0;

}


