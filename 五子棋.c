#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define N 15

int chessboard[N + 1][N + 1] = {0};//���̸���ֵ

int whoseTurn = 0;//����˳������Ϊplayer1,ż��Ϊplay2

void initGame()
{
  char c;
  printf("welcome to play game (Y/n):");
  c = getchar();
  if(c != 'y' && c != 'Y')
    exit(0);
  system("cls");
  printChessboard();//��ӡ����
}
void printChessboard()
{
  int i = 0;
  int j = 0;

  for(i = 0; i <= N; i++)
  {
    for(j = 0; j <= N; j++)
    {
      if(i == 0)//��ʾ�к�
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("%3d",j);
      }
      else if(j == 0)//��ʾ�к�
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("%3d",i);
      }
      else if(chessboard[i][j] == 1)//XΪplayer1������
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//����������ɫΪ��ɫ
        printf("  X");
      }
      else if(chessboard[i][j] == 2)//OΪplayer2������
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14 );//����������ɫΪ��ɫ
        printf("  @");
      }
      else
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//������ɫΪ��ɫ
        printf("  *");//�������ӵ�λ��
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
//�����������
  if(whoseTurn % 2 == 1)
  {
    printf("player1��������λ�ã���ʽΪ�к�+�ո�+�к�");
    scanf("%d %d",&i,&j);
    if(chessboard[i][j] == 0)
      chessboard[i][j] = 1;
    else
    {
      printf("�ظ����ӣ�");
      whoseTurn--;
    }
  }
  else
  {
    printf("player2��������λ�ã���ʽΪ�к�+�ո�+�к�");
    scanf("%d %d",&i,&j);
    if(chessboard[i][j] == 0)
      chessboard[i][j] = 2;
    else
      whoseTurn--;
  }
  //������´�ӡ����
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
int judge(int x, int y)//�ж��Ƿ�����5��
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
    initGame();//��Ϸ��ӭ����

    while(1)
    {
      whoseTurn++;//������Ҵ���
      playChess();//ִ�����Ӳ���
    }

  }
  return 0;
}
