#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define N 15

int chessboard[N + 1][N + 1] = {0};//棋盘赋初值

int whoseTurn = 0;//下棋顺序，奇数为player1,偶数为play2

void initGame()
{
  char c;
  printf("welcome to play game (Y/n):");
  c = getchar();
  if(c != 'y' && c != 'Y')
    exit(0);
  system("cls");
  printChessboard();//打印棋盘
}
void printChessboard()
{
  int i = 0;
  int j = 0;

  for(i = 0; i <= N; i++)
  {
    for(j = 0; j <= N; j++)
    {
      if(i == 0)//显示列号
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("%3d",j);
      }
      else if(j == 0)//显示行号
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("%3d",i);
      }
      else if(chessboard[i][j] == 1)//X为player1的棋子
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//更改棋子颜色为红色
        printf("  X");
      }
      else if(chessboard[i][j] == 2)//O为player2的棋子
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14 );//更改棋子颜色为黄色
        printf("  @");
      }
      else
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//棋盘颜色为白色
        printf("  *");//无人落子的位置
      }
    }
    printf("\n");
  }
}
void playChess()
{
  int i = 0;
  int j = 0;
  int winner = 0;
//玩家轮流落子
  if(whoseTurn % 2 == 1)
  {
    printf("player1输入棋子位置，格式为行号+空格+行号");
    scanf("%d %d",&i,&j);
    if(chessboard[i][j] == 0)
      chessboard[i][j] = 1;
    else
    {
      printf("重复落子！");
      whoseTurn--;
    }
  }
  else
  {
    printf("player2输入棋子位置，格式为行号+空格+列号");
    scanf("%d %d",&i,&j);
    if(chessboard[i][j] == 0)
      chessboard[i][j] = 2;
    else
      whoseTurn--;
  }
  //清空重新打印棋盘
  system("cls");
  printChessboard();

  if(judge(i, j))
  {
    if(whoseTurn % 2 == 1)
    {
      printf("player1 win\n");
      exit(0);
    }
    else
  {
      printf("player2 win\n");
      exit(0);
  }
  }
}
int judge(int x, int y)//判断是否连成5个
{
  int i = 0;
  int j = 0;
  int k = 0;
  const int step[4][2] = {{-1,0},{0,-1},{1,1},{1,0}};
  const int d[2] = {-1,1};
  int count = 1;
  for(i = 0;i < 4;i++)
  {
    for(j = 0; j < 2; j++)
      for(k = 1; k <= 4; k++)
      {
        int row = x + k * d[j] * step[i][0];
        int col = y + k * d[j] * step[i][1];
        if(row >= 1 && row <= N && col>=1 && col <= N && chessboard[x][y] == chessboard[row][col])
          count += 1;
        else
          break;
      }
      if(count >= 5)
        return 1;
  }
  return 0;
}
int main()
{
  while(1)
  {
    initGame();//游戏欢迎界面

    while(1)
    {
      whoseTurn++;//交替玩家次序
      playChess();//执行落子操作
    }

  }
  return 0;
}
