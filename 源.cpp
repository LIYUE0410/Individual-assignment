#include<stdio.h>
#include<conio.h> 
#include<stdlib.h>
#include<graphics.h>
#include<stdbool.h>

IMAGE img[6];
int level = 0;
int map[3][8][8] =
{
   {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 3, 1, 1, 1, 1},
	{1, 1, 3, 0, 1, 1, 3, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 4, 4, 4, 0, 0, 1},
	{1, 1, 1, 0, 4, 3, 1, 1},
	{1, 1, 1, 5, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
   },
   {
	{0, 1, 1, 0, 0, 1, 1, 0},
	{1, 0, 3, 1, 1, 3, 0, 1},
	{1, 0, 0, 4, 0, 0, 0, 1},
	{1, 0, 0, 5, 4, 0, 0, 1},
	{1, 0, 0, 4, 4, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 3, 3, 1, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0}
   },
   {
	{0, 1, 1, 1, 0, 0, 0, 0},
	{1, 3, 0, 3, 1, 0, 0, 0},
	{1, 0, 4, 0, 0, 1, 0, 0},
	{1, 0, 4, 0, 5, 0, 1, 0},
	{0, 1, 0, 0, 0, 4, 0, 1},
	{0, 0, 1, 0, 0, 4, 0, 1},
	{0, 0, 0, 1, 3, 0, 3, 1},
	{0, 0, 0, 0, 1, 1, 1, 0}
   },
};

void drawpic()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int x = 64 * j;
			int y = 64 * i;

			switch (map[level][i][j])
			{
			case 0://Road            路
				//printf("  ");
				putimage(x, y, &img[0]);
				break;
			case 1://Wall            墙
				//printf("■■");
				putimage(x, y, &img[1]);
				break;
			case 3://Destination     目的地
				//printf("☆");
				putimage(x, y, &img[2]);
				break;
			case 4://Box             箱子
				//printf("★");
				putimage(x, y, &img[3]);
				break;
			case 5://Character       人物
			case 8:
				//printf(" ♂");
				putimage(x, y, &img[4]);
				break;
			case 7://Box Destination 箱子的目的地
				//printf(" ●");
				putimage(x, y, &img[5]);
				break;

			}
		}
		printf("\n");
	}
}


void keyEvent()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[level][i][j] == 5 || map[level][i][j] == 8) 
			{
				break;
			}
		}
		if (map[level][i][j] == 5 || map[level][i][j] == 8)
		{
			break;
		}
	}
	char userKey = _getch();
	switch (userKey) //↑72  ↓80  ←75  →77
	{
	case'w'://↑
	case'W':
	case 72:
		//人物移动CharacterMove//
		if (map[level][i - 1][j] == 0 || map[level][i - 1][j] == 3)
		{
			map[level][i - 1][j] += 5;
			map[level][i][j] -= 5;
		}
		//推箱子PushBox//
		if (map[level][i - 1][j] == 4 || map[level][i - 1][j] == 7)
		{
			if (map[level][i - 2][j] == 0 || map[level][i - 2][j] == 3)
			{
				map[level][i - 2][j] += 4;
				map[level][i - 1][j] -= 4;
				map[level][i - 1][j] += 5;
				map[level][i][j] -= 5;
			}
		}
		break;
	case's'://↓
	case'S':
	case 80:
		//人物移动CharacterMove//
		if (map[level][i + 1][j] == 0 || map[level][i + 1][j] == 3)
		{
			map[level][i + 1][j] += 5;
			map[level][i][j] -= 5;
		}
		//推箱子PushBox//
		if (map[level][i + 1][j] == 4 || map[level][i + 1][j] == 7)
		{
			if (map[level][i + 2][j] == 0 || map[level][i + 2][j] == 3)
			{
				map[level][i + 2][j] += 4;
				map[level][i + 1][j] -= 4;
				map[level][i + 1][j] += 5;
				map[level][i][j] -= 5;
			}
		}
		break;
	case'a'://←
	case'A':
	case 75:
		//人物移动CharacterMove//
		if (map[level][i][j - 1] == 0 || map[level][i][j - 1] == 3)
		{
			map[level][i][j - 1] += 5;
			map[level][i][j] -= 5;
		}
		//推箱子PushBox//
		if (map[level][i][j - 1] == 4 || map[level][i][j - 1] == 7)
		{
			if (map[level][i][j - 2] == 0 || map[level][i][j - 2] == 3)
			{
				map[level][i][j - 2] += 4;
				map[level][i][j - 1] -= 4;
				map[level][i][j - 1] += 5;
				map[level][i][j] -= 5;
			}
		}
		break;
	case'd'://→
	case'D':
	case 77:
		//人物移动CharacterMove//
		if (map[level][i][j + 1] == 0 || map[level][i][j + 1] == 3)
		{
			map[level][i][j + 1] += 5;
			map[level][i][j] -= 5;
		}
		//推箱子PushBox//
		if (map[level][i][j + 1] == 4 || map[level][i][j + 1] == 7)
		{
			if (map[level][i][j + 2] == 0 || map[level][i][j + 2] == 3)
			{
				map[level][i][j + 2] += 4;
				map[level][i][j + 1] -= 4;
				map[level][i][j + 1] += 5;
				map[level][i][j] -= 5;
			}
		}
		break;


	}
}

void Introduct()
{
	printf("\n");
	printf("==================>다음은 게임 및 게임 규칙 소개입니다<====================");
	printf("\n");
	printf("\n");
	printf("     고양이가 모든 물고기를 얻을 수 있도록 도와주시면 통관할 수 있습니다.");
	printf("\n");
	printf("               'w' 's' 'a' 'd'로 고양이의 이동을 통제합니다.");
	printf("\n");
	printf("             게임을 진행할 때 영어 자판을 사용해 주시기 바랍니다! "); 
	printf("\n");
	printf("  각각 4마리의 물고기를 잡고 원하는 버튼을 누르면 다음 관문으로 넘어갑니다.");
	printf("\n");
	printf("\n");
	printf("=================> Enter 키를 눌러서 게임을 시작합니다...<=================");
	printf("\n");
	
}


bool jude()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[level][i][j] == 4)
			{
				return false;
			}
		}
	}
	return true;
}


int main()
{

	Introduct();
	_getch();


	loadimage(&img[0], L"0.png");
	loadimage(&img[1], L"1.png");
	loadimage(&img[2], L"3.png");
	loadimage(&img[3], L"4.png");
	loadimage(&img[4], L"5.png");
	loadimage(&img[5], L"7.png");

	initgraph(64*8, 64*8);


	

	while (1)
	{
		system("cls");
		drawpic();
		
		if (jude())
		{
			level++;
			if (level > 2)
			{
				printf("\n");
				printf("~~~ 고양이가 물고기를 잡을 수 있도록 도와주셔서 감사합니다!~~~ ");
				printf("\n");
				printf("~~~ 통관을 축하합니다! ~~~");
				
				_getch();
				break;
			}
		}
		keyEvent();
	}
	
	_getch();
	closegraph();
	return 0;
}
