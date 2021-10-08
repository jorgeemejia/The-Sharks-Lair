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




void Setup()
{
  dir = STOP;
  x = width/2;
  y = height - 1;
  score = 0;
  GameOver = false;
}

void LevelOne()
{

mines_x.push_back(4);
mines_y.push_back(2);

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

  std::cout << "\tSCORE:" << score << std::endl;



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

  }


}





int main()
{

Setup();
LevelOne();

while(!GameOver)
{   

    Draw();
    Input();
    Logic();
    sleep(9/10);
    //sleep(1);
}



return 0;
}