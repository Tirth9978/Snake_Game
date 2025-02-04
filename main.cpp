#include <iostream>
#include <cstdlib>
#include <ctime>

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
    #include <windows.h>
    #define CLEAR "cls"
    
#else 
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #define CLEAR "clear"

    int _kbhit() {
        struct termios oldt, newt;
        int ch;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if (ch != EOF) {
            ungetc(ch, stdin);
            return 1;
        }
        return 0;
    }

    int _getch() {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

#endif

using namespace std;


// ENUM Part
enum direction { 
    STOP = 0, LEFT, RIGHT, UP, DOWN
};

/*
We have used encapsulation to make our variables private and ensure data security. Additionally, we have implemented inheritance to establish relationships between classes.

At the starting point, all constructors will be called, initializing and allocating the necessary resources for the game.
*/

// Main game base
class Game { 
    // Here in Encapsulation, we Protect variable members . 
    protected : 
        int width;
        int height;
        int score;
        bool isGameOver;
        direction Dir;
    
    public : 
        /*
        First of all this will be called After creation of class
        */

        Game() {
            this->width = 70;
            this->height = 20;
            this->score = 0;
            this->isGameOver = false;
            this->Dir = STOP;
        }
};

// This is the class inherited from Game class
class Snake :protected Game {
    protected : 
        int snakeX, snakeY;
        int *Tail_X;
        int *Tail_Y;
        int Tail_Length;
    public : 
        /*
        Second time this will be called
        */
        Snake() {
            this->snakeX = this->width / 2;
            this->snakeY = this->height / 2;
            // Dynamic allocation of tail of shake 
            Tail_X = new int[100];
            Tail_Y = new int[100];
            Tail_Length = 0;
        }
    
};

// From Snake Class
class Fruit : protected Snake { 
    protected : 
        int fruitX, fruitY;
    
    public : 
        //Third time, this will be called
        Fruit() { 
            srand(time(NULL));
            this->fruitX = rand() % (this->width-1);
            this->fruitY = rand() % (this->height-1);
        }
        
};   

/*
It is the main body of the Game.
In this we have Main_Board ,Update_Game,Input mathods .
*/
class Main : protected Fruit {
    public : 
        void Main_Board(string name) { 
            system(CLEAR);
            
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

            if(Dir == STOP) {
                return;
            }

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

void animation(string name) {
    system(CLEAR);
    cout << "\n\n\n";
    cout << "          ****************************************\n\n";
    cout << "                       S N A K E  G A M E\n\n";
    cout << "                         Welcome, " << name << "\n\n";
    cout << "          ****************************************\n\n\n";

    cout << "                     L O A D I N G";
    for (int i = 0; i < 5; i++) {
        cout << ".";
        #if defined(_WIN32) || defined(_WIN64)
            Sleep(600);
        #else
            usleep(650 * 1000);
        #endif
    }
    system(CLEAR);
}

/*
main function of this cpp file. 
*/
int main() {
    
    string name;
    cout << "Enter your Name : ";
    getline(cin, name);

    animation(name);

    // Set Difficuly of the game.
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

    srand(time(NULL));

    int play = 0;
    // this is the do-while loop for if you want to play again the game 
    do {
        Main game;
        // main part of methods calling 
        while(!game.isOver()){
            // Frontend of the game board
            game.Main_Board(name);
            // Keys press  
            game.Input();
            // Backend Part of the game 
            game.Update_Game();


            #if defined(_WIN32) || defined(_WIN64)
                Sleep(diff);
            #else
                usleep(diff * 900);
            #endif

        }
        
        system(CLEAR);

        cout << "\n\n\n\n\n                                   ";
        cout << "G A M E  O V E R  ! ! ! \n\n\n\n\n";

        cout << "\n\nDo You Want To Play Again..?\n\n";
        cout << "NOTE : If You Press Key Other Than 0 or 1 Then Computer will treat it as 0..\n";
        cout << "Enter 1 For \"YES\" and 0 For \"NO\" : ";

        cin >> play;

    } while(play == 1);

    cout << "\n\n\n\n\nOkay, Byee...  ";
    cout << "Thank You " << name << "\n\n\n\n\n\n";

    return 0;
}
