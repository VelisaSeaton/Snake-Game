#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80

using namespace std;
bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup(){
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    srand(time(0));
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw(){
    system("cls"); //system("clear"); - Linux
    for (int i = 0; i < width+2; i ++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
                cout << " ";
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width+2; i ++)
        cout << "#";
    cout << endl << endl;
    cout << "Score:" << score << endl <<endl;
    cout << "Use the arrow keys to move";
}
void Input(){
    if (_kbhit()){
        switch(_getch()){
        case KEY_LEFT:
            dir = LEFT;
            break;
        case KEY_RIGHT:
            dir = RIGHT;
            break;
        case KEY_UP:
            dir = UP;
            break;
        case KEY_DOWN:
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic(){
    switch(dir){
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
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true;
    if (x == fruitX && y == fruitY){
        score +=10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(20);
    }
   return 0;
}
