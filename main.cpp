#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "titlescreens.h"


bool GameOver;
const int width = 30;
const int height = 10;
int x;
int y;
int score;
std::vector<int> mines_x;
std::vector<int> mines_y;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN,};
eDirection dir;
int difficulty_multiplier = 10;
bool level_complete; 

void Setup()
{
  dir = STOP;
  x = width/2;  ///15, 9
  y = height - 1;
  score = 0;
  GameOver = false;
}

void LevelOne()
{
  srand((unsigned int)time(NULL));
  for (int x = 0; x < difficulty_multiplier; x++)
  {
    int mine_x = rand () % (width - 1) + 1;
    int mine_y = rand () % (height - 3)  + 1;

    mines_x.push_back(mine_x);
    mines_y.push_back(mine_y);
  }
}

void LevelTwo()
{
  srand((unsigned int)time(NULL));
  for (int x = 0; x < difficulty_multiplier; x++)
  {
    int mine_x = rand () % (width - 1) + 1;
    int mine_y = rand () % (height - 3)  + 1;

    mines_x.push_back(mine_x);
    mines_y.push_back(mine_y);

  }
}

void LevelThree()
{
  srand(time(NULL));
  for (int x = 0; x < difficulty_multiplier; x++)
  {
    int mine_x = rand () % (width - 1) + 1;
    int mine_y = rand () % (height - 3)  + 1;

    mines_x.push_back(mine_x);
    mines_y.push_back(mine_y);
  }
}

void Draw()
{

  system("cls");

  for (int w = 0; w < width; w++)
  {
    std::cout << "-";
  }
  std::cout << std::endl;
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
        for(int i = 0; i < 30; i++)
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
    }
    std::cout << std::endl;
  }

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


  for(int i = 0; i < 30; i++)
  {
    if(x == mines_x[i] && y == mines_y[i])
    {
      GameOver = true;
    }
  }
  if(x == 0 || x == width - 1 || y > height)
  {
    GameOver = true;
  }
  if (y < 0)
  {
    score = score + 100;
    x = width/2;
    y = height - 1;
  }

  if (GameOver)
  {
    system("cls");
    GameOverScreen();
  }
  if (score == 300)
  {
    system("cls");
    YouWinScreen();
  }
}


int main()
{
  system("cls");
  TitleScreen();
  sleep(2);

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
  }
  if (!GameOver)
  {
    system("cls");
    LevelTwoScreen();
    sleep(1);
    LevelTwo();
  }

  dir = STOP;

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

  dir = STOP;

  while(!GameOver && score != 300)
  {    
    Draw();
    Input();
    Logic();
    sleep(9/10);
  }

return 0;
}



