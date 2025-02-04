#include <iostream>
#include <vector>
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

        if (ch == 27) {
            if (getchar() == '[') {
                switch (getchar()) {
                    case 'A': ch = 'w'; break;  // Up Arrow
                    case 'B': ch = 's'; break;  // Down Arrow
                    case 'C': ch = 'd'; break;  // Right Arrow
                    case 'D': ch = 'a'; break;  // Left Arrow
                }
            }
        }

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
        vector<pair<int, int>> obstacles;
    
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

        ~Snake() {
            delete[] Tail_X;
            delete[] Tail_Y;
        }
    
};

// From Snake Class
class Fruit : protected Snake { 
    protected : 
        int fruitX, fruitY;
        bool specialFruit;
    public : 
        //Third time, this will be called
        Fruit() { 
            generateFruit();
        }

        void generateFruit() {
            this->fruitX = 1 + rand() % (this->width - 2);
            this->fruitY = 1 + rand() % (this->height - 2);
            this->specialFruit = (bool)(rand() % 10 == 0);
        }
};   

/*
It is the main body of the Game.
In this we have Main_Board ,Update_Game,Input mathods .
*/
class Main : protected Fruit {
    private :
        vector<pair<int, int>> obstacles;
        int frameCount = 0;
        bool obstaclesEnable = false;

    public :

        void GenerateObstacles() {
            if(!obstaclesEnable) {
                return;
            }

            obstacles.clear();  // Reset old obstacles
            int numObstacles = 5 + ((score - 50) / 20) * 3;

            for (int i = 0; i < numObstacles; i++) {
                int obsX, obsY;
                bool valid;
                do {
                    valid = true;
                    obsX = 2 + rand() % (width - 2);
                    obsY = 2 + rand() % (height - 2);

                    if (obsX == snakeX && obsY == snakeY) {
                        valid = false;
                    }
                    if (obsX == fruitX && obsY == fruitY) {
                        valid = false;
                    }

                    for (auto t : obstacles) {
                        if (t.first == obsX && t.second == obsY) valid = false;
                    }

                } while (!valid);

                obstacles.push_back({obsX, obsY});
            }
        }

        void Main_Board(string name) { 
            system(CLEAR);

            cout << "\n\n";
            
            for(int i=0; i<this->width+2; i++) {
                cout << "-";
            } cout << "\n";
            
            for(int i=1; i<height; i++) {
                for(int j=0; j<=width+1; j++) {
                    if(j == 0 || j == width+1) {
                        cout << "|";
                    } else if(j == snakeX && i == snakeY) {
                        cout << "O";
                    } else if(j == fruitX && i == fruitY) {
                        if(specialFruit) {
                            cout << "$";
                        } else {
                            cout << "@";
                        }
                    } else {
                        bool find = false;
                        for(int k=0; k<Tail_Length; k++) {
                            if(Tail_X[k] == j && Tail_Y[k] == i) {
                                cout << "o";
                                find = true;
                            }
                        }
                        if(!find) {
                            bool isObstacle = false;
                            for (auto obs : obstacles) {
                                if (obs.first == j && obs.second == i) {
                                    cout << "#";  // Draw obstacle
                                    isObstacle = true;
                                    break;
                                }
                            }
                            if (!isObstacle) cout << " ";
                        }
                    }
                }
                if(i == 2) cout << "       ---------- Legend ----------";
                if(i == 4) cout << "       @ = Normal Fruit (5 points)";
                if(i == 5) cout << "       $ = Special Fruit (20 points)";
                if(i == 6) cout << "       # = Obstacles (Be Safe!)";
                if(i == 7) cout << "       O = Snake Head | o = Snake Tail";
                if(i == 10) cout << "       ---------- Controls ----------";
                if(i == 12) cout << "       W / A / S / D or Arrow Keys = Move";
                if(i == 13) cout << "       P = Pause | R = Resume";
                if(i == 14) cout << "       X = Reset | ESC = Exit";

                if(i == 18) cout << "       " << name << "'s Score : " << this->score;

                cout << endl;
            }

            for(int i=0; i<=width+1; i++) {
                cout << "-";
            }
            cout << "\n\n";

        }
        
        void Update_Game(int diff, int wallsEnable){

            frameCount++;

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

            if(wallsEnable) {
                if(snakeX >= width || snakeX <= 0 || snakeY >= height || snakeY <= 0) {
                    isGameOver = true;
                }   
            } else {
                if(snakeX >= width) {
                    snakeX = 1;
                }
                else if(snakeX <= 0) {
                    snakeX = width - 1;
                }
                else if(snakeY >= height) {
                    snakeY = 1;
                }
                else if(snakeY <= 0) {
                    snakeY = height - 1;
                }
            }

            if (score >= 50 && !obstaclesEnable) {
                obstaclesEnable = true;
                GenerateObstacles();
            }

            if (obstaclesEnable && frameCount % 100 == 0) {
                GenerateObstacles();
            }

            for (auto obs : obstacles) {
                if (snakeX == obs.first && snakeY == obs.second) {
                    isGameOver = true;  // Snake dies if it hits an obstacle
                }
            }

            for(int i=0; i<Tail_Length; i++) {
                if(Tail_X[i] == snakeX && Tail_Y[i] == snakeY) {
                    isGameOver = true;
                }
            }
            
            if(snakeX == fruitX && snakeY == fruitY) {
                if(specialFruit) {
                    score += 20;
                } else {
                    score += 5;
                }
                Tail_Length++;

                bool find;

                do {
                    find = true;

                    generateFruit();

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

            if(score % 25 == 0) {
                diff -= 10;  // Increase Speed
            }
        }
        
        void Input() { 
            if(_kbhit()) {
                char ch = _getch();

                if(ch == 27) {
                    isGameOver = true;
                    return;
                }

                if (ch == 'p') {  // Pause the game
                    cout << "\n\n\t\tGame Paused..!! Press 'r' to Resume...\n\n";
                    while (true) {
                        if (_kbhit() && _getch() == 'r') {
                            cout << "Game Resumed!\n";
                            break;
                        }
                    }
                    return;
                }

                if(ch == 'x') {
                    this->Reset();
                    return;
                }

                if(ch == 'a' || ch == 75) {
                    if(Dir != RIGHT) Dir = LEFT;
                } else if(ch == 's' || ch == 80) {
                    if(Dir != UP) Dir = DOWN;
                } else if(ch == 'w' || ch == 72) {
                    if(Dir != DOWN) Dir = UP;
                } else if(ch == 'd' || ch == 77) {
                    if(Dir != LEFT) Dir = RIGHT;
                }
            }
        }

        void Reset() {
            this->score = 0;
            this->isGameOver = false;
            this->Dir = STOP;
            this->snakeX = width / 2;
            this->snakeY = height / 2;
            Tail_Length = 0;

            // Generate new fruit
            fruitX = rand() % (width-1);
            fruitY = rand() % (height-1);
            specialFruit = (rand() % 10 == 0);
        }
        
        bool isOver() {
            return this->isGameOver;
        }
};

void animation(string name) {
    system(CLEAR);
    cout << "\n\n\n";
    cout << "          *************************************************************************\n\n";
    cout << "                                      S N A K E  G A M E\n\n";
    cout << "                                      Get Ready, " << name << "..!!\n\n";
    cout << "          *************************************************************************\n\n\n\n\n\n\n";

    cout << "                                    L O A D I N G ";
    
    for (int i = 0; i < 5; i++) {
        cout << "." << flush;
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

    system(CLEAR);

    cout << "\n\n\n";
    cout << "          **************************************************************************************\n\n";
    cout << "                                 W E L C O M E  T O  S N A K E  G A M E ! !\n\n";
    cout << "          **************************************************************************************\n\n\n\n";
    
    string name;
    cout << "\n\nEnter your Name : ";
    getline(cin, name);

    // Set Difficuly of the game.
    int diff = 0;
    cout << "\n\n";
    cout << "Difficulty Levels : " << endl;
    cout << "1. Easy\n2. Medium\n3. Hard\n\n";
    cout << "NOTE : If You Press Key Other than 1, 2 or 3 then Difficulty Will Set Automatically to Medium..\n\n";
    cout << "Set Difficulty Level : ";
    cin >> diff;
    
    if (diff == 3) {
        diff = 90;
    } else if(diff == 2) {
        diff = 140;
    } else if(diff == 1) {
        diff = 190;
    } else {
        diff = 140;
    }

    srand(time(NULL));

    int play = 0;
    // this is the do-while loop for if you want to play again the game 
    do {

        // system(CLEAR);
        
        cout <<"\n\n";

        int wallsEnable = 1;
        cout << "Do You Want To Enable The Walls..?\n\n";
        cout << "NOTE : if Walls are Enable then if you touch the walls, The game is Over..\n";
        cout << "If You Press other than 1 or 0 then it will take 1 and walls are enabled automatically..\n\n";
        cout << "Press 1 for Walls Enable and 0 for not enable : ";
        cin >> wallsEnable;

        animation(name); 

        Main game;
        // main part of methods calling 
        while(!game.isOver()){
            // Frontend of the game board
            game.Main_Board(name);
            // Keys press  
            game.Input();
            // Backend Part of the game 
            game.Update_Game(diff, wallsEnable);

            #if defined(_WIN32) || defined(_WIN64)
                Sleep(max(50, diff));
            #else
                usleep(max(50, diff) * 900);
            #endif

        }
        
        system(CLEAR);

        cout << "\n\n\n";
        cout << R"(
                              _____                         ____                 
                             / ____|                       / __ \                
                            | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ 
                            | | |_ |/ _` | '_ ` _ \ / _ \ | |  | \ \ / / _ \ '__|
                            | |__| | (_| | | | | | |  __/ | |__| |\ V /  __/ |   
                             \_____|\__,_|_| |_| |_|\___|  \____/  \_/ \___|_|   
        )" << "\n\n\n\n\n";

        cout << "                                        ";
        cout << "G A M E  O V E R  ! ! ! \n\n\n\n\n";

        cout << "\n\nDo You Want To Play Again..?\n\n";
        cout << "NOTE : If You Press Key Other Than 0 or 1 Then Computer will treat it as 0..\n";
        cout << "Enter 1 For \"YES\" and 0 For \"NO\" : ";

        cin >> play;

    } while(play == 1);

    cout << "\n\n\n\n\nOkay, Byee...  ";
    cout << "Thank You " << name << " For Playing Our Game..!!\n\n\n\n";

    return 0;
}
