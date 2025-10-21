#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

int width = 20, height = 20 ;
int x,y;
int fruitX, fruitY;
int score;
int gameOver;
int tailX[100], tailY[100];
int nTail;

enum eDirection 
{
    STOP=0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum eDirection dir;

void setup();
void draw();
void input();
void logic();


int main()
{
    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(100);
    }
}



void setup()
{

}

void draw()
{

}

void input()
{

}

void logic()
{

}
