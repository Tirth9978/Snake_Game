#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std ;


const int width = 70;
const int height = 20;

int snakeX, snakeY;

int fruitX, fruitY;

int score ;

int Tail_X[100],Tail_Y[100];

int Tail_Length;
     
bool isGameOver;

enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

direction Dir;

void Game_Start(){
     isGameOver = 0;
     Dir = STOP;
     snakeX = width / 2;
     snakeY = height / 2;
     fruitX = rand() % width;       
     fruitY = rand() % height;
     score = 0;
}


void Main_Board() {
    system("cls");
     
    for(int i=0; i<width+2; i++){
        cout << "-";
    } cout << endl;
     
    for(int i=1; i<height; i++) {
        for(int j=0; j<=width+1; j++) {
            if(j == 0 || j == width+1) cout << "|";
            else if(i == snakeY && j ==  snakeX) cout << "0";
            else if(i == fruitY && j == fruitX) cout<< "*";
            else {
                bool find = 0;
                for(int k=0;k<Tail_Length;k++) {
                    if(Tail_X[k] == j && Tail_Y[k] == i){
                        cout << "o";
                        find = 1;
                    }
                }
                if (!find)cout << " ";
            }
        }
        cout << endl;
    }
    for(int i=0; i<width+2; i++) cout << "-" ;
    cout << endl;
    cout << "Score : " << score << endl;
}

void Update_Game() { 
    int preX = Tail_X[0];
    int preY = Tail_Y[0];

    int preXX, preYY;

    Tail_X[0] = snakeX;
    Tail_Y[0] = snakeY;

    for(int i=1; i<Tail_Length; i++) {
        preXX = Tail_X[i];
        preYY = Tail_Y[i];

        Tail_X[i] = preX;
        Tail_Y[i] = preY;

        preX = preXX;
        preY = preYY;
    }

    if(Dir == LEFT) {
        snakeX--;
    } else if(Dir == RIGHT) {
        snakeX++;
    } else if(Dir == UP) {
        snakeY--;
    } else {
        snakeY++;
    } 

    if(snakeX >= width || snakeX <= 0 || snakeY >= height || snakeY <= 0){
        isGameOver = true;
    }
    
    for(int i=0; i<Tail_Length; i++){
        if(Tail_X[i] == snakeX && Tail_Y[i] == snakeY) {
            isGameOver = true;
        }
    }   

    // if(snakeX == fruitX && snakeY == fruitY){
    //     score+=10;
    //     Tail_Length++;
    //     bool find;
        
    //     do { 
    //         find = true;
    //         fruitX = rand() % width;
    //         fruitY = rand() % height;
            
    //         if (snakeX == fruitX && snakeY == fruitY){
    //             find = false;
    //         }
    //         for(int i=0; i<Tail_Length; i++){
    //             if (Tail_X[i] == fruitX && Tail_Y[i] == fruitX){
    //                 find = false;
    //                 break;
    //             }
    //         }

    //     } while(!find);
    // }
    if (snakeX == fruitX && snakeY == fruitY) {
        score += 10;
        Tail_Length++;
        bool find;

        do {
            find = true;
            fruitX = rand() % (width-1);
            fruitY = rand() % (height-1);

            // Check if fruit overlaps with the snake's head
            if (snakeX == fruitX && snakeY == fruitY) {
                find = false;
            }

            // Check if fruit overlaps with the snake's tail
            for (int i = 0; i < Tail_Length; i++) {
                if (Tail_X[i] == fruitX && Tail_Y[i] == fruitY) {
                    find = false;
                    break;
                }
            }
        } while (!find);
    }

}

void Input() {
    if(_kbhit()) {
        char key = _getch();
        if(key == 'a') {
            Dir = LEFT;
        } else if(key == 's') {
            Dir = DOWN;
        } else if(key == 'd') {
            Dir = RIGHT;
        } else if(key == 'w') {
            Dir = UP;
        } else if (key == 27){
            isGameOver = true;
        }
    }
    
}

int main() {
    string name;
    cout << "Enter your Name : ";
    cin >> name;

    int diff = 0;
    cout << "Set Difficulty: ";
    cin >> diff;

    if (diff == 3) {
        diff = 50;
    } else if(diff == 2) {
        diff = 100;
    } else if(diff == 1) {
        diff = 150;
    } else {
        diff = 100;
    }

    Game_Start();
   
    while(!isGameOver) {
        Main_Board();
        Input();
        Update_Game();
        Sleep(diff);
    }
    
    return 0;
}