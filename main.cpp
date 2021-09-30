#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <thread>
#include <chrono>

bool GameOver;
const int width = 30;
const int height = 10;
int x;
int y;
int score;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
  dir = STOP;
  x = width/2;
  y = height - 1;
  score = 0;
  GameOver = false;
}

void Draw()
{

  system("cls");

  for (int w = 0; w < width; w++)
  {
     std::cout << "-";
  }
  std::cout << std::endl;
///////////////////////////////////////
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
              std::cout << " ";
          }
      }
      std::cout << std::endl;
  }
  

  for (int w = 0; w < width; w++)
  {
     std::cout << "-";
  }
  std::cout << std::endl;



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
}





int main()
{

Setup();

while(!GameOver)
{   
    Draw();
    Input();
    Logic();
    sleep(1/2);
}



return 0;
}