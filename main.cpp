#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

enum direction { 
    STOP = 0, LEFT, RIGHT, UP, DOWN
};
class Game { 
    protected : 
        int width;
        int height;
        int score;
        bool isGameOver;
        direction Dir;
    
    public : 
        Game() {
            this->width = 70;
            this->height = 20;
            this->score = 0;
            this->isGameOver = false;
            this->Dir = STOP;
        }
};

class Snake : protected Game {
    protected : 
        int snakeX, snakeY;
        int *Tail_X;
        int *Tail_Y;
        int Tail_Length;
        
    public : 
        Snake() {
            this->snakeX = this->width / 2;
            this->snakeY = this->height / 2;
            Tail_X = new int[100];
            Tail_Y = new int[100];
            Tail_Length = 0;
        }
    
};

class Fruit : protected Snake { 
    protected : 
        int fruitX, fruitY;
    
    public : 
        Fruit() { 
            this->fruitX = rand() % (this->width-1);
            this->fruitY = rand() % (this->height-1);
        }
        
};   

class Main : protected Fruit {
    public : 
        void Main_Board(string name) { 
            system("cls");
            
            for(int i=0; i<this->width+2; i++) {
                cout << "-";
            } cout << endl;
            
            for(int i=1; i<height; i++) {
                for(int j=0; j<=width+1; j++) {
                    if(j == 0 || j == width+1) {
                        cout << "|";
                    } else if(j == snakeX && i == snakeY) {
                        cout << "O";
                    } else if(j == fruitX && i == fruitY) {
                        cout << "@";
                    } else {
                        bool find = false;
                        for(int k=0; k<Tail_Length; k++) {
                            if(Tail_X[k] == j && Tail_Y[k] == i) {
                                cout << "o";
                                find = true;
                            }
                        }
                        if(!find) cout << " ";
                    }
                }
                cout << endl;
            }
            for(int i=0; i<=width+1; i++) {
                cout << "-";
            }
            cout << endl << endl;
            cout << name << "'s Score : " << this->score <<endl;
        }
        
        void Update_Game(){
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

            if(snakeX >= width || snakeX <= 0 || snakeY >= height || snakeY <= 0) {
                isGameOver = true;
            }

            for(int i=0; i<Tail_Length; i++) {
                if(Tail_X[i] == snakeX && Tail_Y[i] == snakeY) {
                    isGameOver = true;
                }
            }

            if(snakeX == fruitX && snakeY == fruitY) {
                score += 10;
                Tail_Length++;

                bool find;

                do {
                    find = true;

                    fruitX = rand() % (width-1);
                    fruitY = rand() % (height-1);

                    if (snakeX == fruitX && snakeY == fruitY) {
                        find = false;
                    }

                    for(int i=0; i<Tail_Length; i++) {
                        if(Tail_X[i] == fruitX && Tail_Y[i] == fruitY) {
                            find = false;
                            break;
                        }
                    }
                } while(!find);
            }
        }
        
        void Input() { 
            if(_kbhit()) {
                char ch = _getch();
                if(ch == 'a' && Dir != RIGHT) {
                    Dir = LEFT;
                } else if(ch == 's' && Dir != UP) {
                    Dir = DOWN;
                } else if(ch == 'w' && Dir != DOWN) {
                    Dir = UP;
                } else if(ch == 'd' && Dir != LEFT) {
                    Dir = RIGHT;
                } else if(ch == 27) {
                    isGameOver = true;
                }
            }
        }
        
        bool isOver() {
            return this->isGameOver;
        }
};


int main() {
    
    string name;
    cout << "Enter your Name : ";
    cin >> name;

    int diff = 0;
    cout << endl;
    cout << "Difficulty Levels : " << endl;
    cout << "1. Easy\n2. Medium\n3. Hard\n\n";
    cout << "NOTE : If You Press Key Other than 1, 2 or 3 then Difficulty Will Set Automatically to Medium..\n";
    cout << "Set Difficulty Level : ";
    cin >> diff;
    
    if (diff == 3) {
        diff = 100;
    } else if(diff == 2) {
        diff = 150;
    } else if(diff == 1) {
        diff = 200;
    } else {
        diff = 150;
    }

    int play = 0;

    do {
        Main game;
    
        while(!game.isOver()){
        
            game.Main_Board(name);
            game.Input();
            game.Update_Game();
        
            Sleep(diff);
        }
        
        system("cls");

        cout << "\n\n\n\n\n                                   ";
        cout << "G A M E  O V E R  ! ! ! \n\n\n\n\n";

        cout << "\n\nDo You Want To Play Again..?\n\n";
        cout << "NOTE : If You Press Key Other Than 0 or 1 Then Computer will treat it as 0..\n";
        cout << "Enter 1 For \"YES\" and 0 For \"NO\" : ";

        cin >> play;

    } while(play == 1);

    cout << "\n\n\n\n\nOkay, Byee...\n\n\n\n\n";

    return 0;
}
