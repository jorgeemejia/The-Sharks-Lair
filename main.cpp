#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <vector>

bool GameOver;
const int width = 30;
const int height = 10;
int x;
int y;
int score;
std::vector<int> mines_x;
std::vector<int> mines_y;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

bool level_complete; 

////MAYBE
// have a bool, obs_printed
// set it to false, once all have been printed, make it true
// put all that in the else if
// that way you can have the else just have " "


void TitleScreen()
{
  //Big font, patorjk

// for (int x = 0; x < 5; x++)
// {


std::cout << "   _____ _                _    _       _           _       " << std::endl;
std::cout << "  / ____| |              | |  ( )     | |         (_)      " << std::endl;
std::cout << " | (___ | |__   __ _ _ __| | _|/ ___  | |     __ _ _ _ __  " << std::endl;
std::cout << "  \\___ \\| '_ \\ / _` | '__| |/ / / __| | |    / _` | | '__| " << std::endl;
std::cout << "  ____) | | | | (_| | |  |   <  \\__ \\ | |___| (_| | | |    " << std::endl;
std::cout << " |_____/|_| |_|\\__,_|_|  |_|\\_\\ |___/ |______\\__,_|_|_|    " << std::endl;
                                                          
                                                          


}


void Setup()
{
  dir = STOP;
  x = width/2;
  y = height - 1;
  score = 0;
  GameOver = false;
}

void LevelOneScreen()
{ 
std::cout <<"  _                    _    ____                      "<< std::endl;
std::cout <<" | |                  | |  / __ \\                    "<< std::endl;
std::cout <<" | |     _____   _____| | | |  | |_ __   ___          "<< std::endl;
std::cout <<" | |    / _ \\ \\ / / _ \\ | | |  | | '_ \\ / _ \\    "<< std::endl;
std::cout <<" | |___|  __/\\ V /  __/ | | |__| | | | |  __/        "<< std::endl;
std::cout <<" |______\\___| \\_/ \\___|_|  \\____/|_| |_|\\___|    "<< std::endl;
                                             
}


void LevelOne()
{

// int x[2] = {2, 4};
// int y[2] = {2, 4};

// mines_x.insert(mines_x.end(), std::begin(x), std::end(x));
// mines_y.insert(mines_y.end(), std::begin(y), std::end(y));
mines_x.push_back(3);
mines_y.push_back(3);

//just do a for loop with rand getting numbers and pushbacking them into vector.


}

void LevelTwoScreen()
{

std::cout << " _                    _   _______                 " << std::endl;
std::cout << " | |                  | | |__   __|               " << std::endl;
std::cout << " | |     _____   _____| |    | |_      _____      " << std::endl;
std::cout << " | |    / _ \\ \\ / / _ \\ |    | \\ \\ /\\ / / _ \\     " << std::endl;
std::cout << " | |___|  __/\\ V /  __/ |    | |\\ V  V / (_) |    " << std::endl;
std::cout << " |______\\___| \\_/ \\___|_|    |_| \\_/\\_/ \\___/     " << std::endl;
                                              


}



void LevelTwo()
{

mines_x.push_back(6);
mines_y.push_back(6);

}

void LevelThreeScreen()
{

std::cout << "   _                    _   _______ _                      " << std::endl;
std::cout << "  | |                  | | |__   __| |                     " << std::endl; 
std::cout << "  | |     _____   _____| |    | |  | |__  _ __ ___  ___    " << std::endl;
std::cout << "  | |    / _ \\ \\ / / _ \\ |    | |  | '_ \\| '__/ _ \\/ _ \\   " << std::endl;
std::cout << "  | |___|  __/\\ V /  __/ |    | |  | | | | | |  __/  __/   " << std::endl;
std::cout << "  |______\\___| \\_/ \\___|_|    |_|  |_| |_|_|  \\___|\\___|   " << std::endl;
                                                       
}

void LevelThree()
{
mines_x.push_back(15);
mines_y.push_back(3);
}



void Draw()
{

  system("cls");


  for (int w = 0; w < width; w++)
  {
     std::cout << "-";
  }
  std::cout << std::endl;
///////////////////////////////////////////////
  for (int h = 0; h < height; h++)
  {
      for (int w = 0; w < width; w++)
      {
          if (w == 0 || w == width -1)
          {
              std::cout << '|';
          }
          else if(h == y && w == x)
          {
              std::cout << "#";
          }
          else
          {
               bool last_mine = false;
               for(int i = 0; i < 8; i++)
               {
                 if(mines_x[i] == w && mines_y[i] == h) 
                 {
                   std::cout << 'O';
                   last_mine = true;
                 } 
               }
               if (!last_mine)
               {
                std::cout << " ";
               }
          }
      
      
      
      //////////////END OF ELSE
      }
      std::cout << std::endl;
  }
  
/////////////////////////////////////////////
  for (int w = 0; w < width; w++)
  {
     std::cout << "-";
  }
  std::cout << std::endl;

  std::cout << "\tLEVEL:" << score << std::endl;



}

void Input()
{
  if(_kbhit())
  {
    switch(_getch())
    {
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = RIGHT;
        break;
      case 'w':
        dir = UP;
        break;
      case 's':
        dir = DOWN;
        break;
      case 'x':
        GameOver = true;
        break;
        ///Search "kbhit arrow keys"
    }
  }
}

void Logic()
{
  switch(dir)
  {
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


  for(int i = 0; i < 8; i++)
  {
    if(x == mines_x[i] && y == mines_y[i])
    {
      GameOver = true;
    }
  }
  if(x == 0 || x == width - 1)
  {
    GameOver = true;
  }
  if (y == 0)
  {
    score = score + 100;
    x = width/2;
    y = height - 1;

  }
  // if( score == 100)
  // {
  //   LevelTwo();
  // }


}





int main()
{
system("cls");
TitleScreen();
sleep(1);

Setup();
system("cls");
LevelOneScreen();
sleep(1);
LevelOne();

while(!GameOver && score != 100)
{   

    Draw();
    Input();
    Logic();
    sleep(9/10);
    //sleep(1);
}
if (!GameOver)
{
system("cls");
LevelTwoScreen();
sleep(1);
LevelTwo();
}

while(!GameOver && score != 200)
{
    Draw();
    Input();
    Logic();
    sleep(9/10);
}

if (!GameOver)
{
system("cls");
LevelThreeScreen();
sleep(1);
LevelThree();
}

while(!GameOver && score != 300)
{   

    Draw();
    Input();
    Logic();
    sleep(9/10);
    //sleep(1);
}



return 0;
}



