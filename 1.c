#include<stdio.h>
#include<Windows.h>
#include<float.h>
#include <stdlib.h>
#include<time.h>
#include<stdint.h>
DWORD WINAPI timea();
int DianJiShiChang;
int main(void);
int timea(void);
int zhuantai;
int main(void)
{
	for (;;)
	{
		static long double Chink;//1,2,3用的Sleep值
		static int Model;//主选择
		static int model;//4中选择
		static int ChiShu;//4中计数
		static int DianJiChiShu;//4计数
		static int Alpha;
		long double length = 1;
		system("color 0C");
		printf("欢迎使用连点器4.3.1\n");
		struct tm* newtime;
		char tmpbuf[128];
		time_t lt1;
		time(&lt1);
#pragma warning(suppress :4996)
		newtime = localtime(&lt1);
		strftime(tmpbuf, 128, "Today is %A, day %d of %B in the year %Y.\n", newtime); 
		printf(tmpbuf);
		for (size_t i = 0; i < length; length++)
		{


			printf("\n 请输入您想要的模式代码\n\f \n1为普通\n2为2连击\n3为3连击\n4为其他模式\n5为清屏\n6为版本信息\n7为退出\n");
			scanf_s("%d", &Model);
			if (Model == 1)
			{
				printf("请输入每次点击间隔（毫秒）\n");
				scanf_s("%Lf", &Chink);
				printf("以以下速度开始=%lf ms/下\n", Chink);
				printf("按F5以开始\n\n按F6返回");
				while (1)
					if (GetAsyncKeyState(VK_F5))
					{
						while (2)
						{
							mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
							Sleep(Chink);
							if (GetAsyncKeyState(VK_F6))
							{
								break;
							}
						}
					}
					else if (GetAsyncKeyState(VK_F6))
					{
						break;
					}
			}
			else if (Model == 2)
			{
				printf("请输入每两次点击间隔（毫秒）\n");
				scanf_s("%lf", &Chink);
				printf("以以下速度开始=%lf ms/2下\n", Chink);
				printf("按F5以开始\n\n按F6返回");
				while (1)
				{
					if (GetAsyncKeyState(VK_F5))
					{
						while (2)
						{
							mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
							mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
							Sleep(Chink);
							if (GetAsyncKeyState(VK_F6))
							{
								break;
							}
						}
					}
					else if (GetAsyncKeyState(VK_F6))
					{
						break;
					}
				}

			}
			else if (Model == 3)
			{
				printf("请输入每两次点击间隔（毫秒）\n");
				scanf_s("%Lf", &Chink);
				printf("按F5以开始\n\n按F6返回");
				while (1)
					if (GetAsyncKeyState(VK_F5))
					{
						while (2)
						{
							mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
							mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
							mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
							Sleep(Chink);
							if (GetAsyncKeyState(VK_F6))
							{
								break;
							}
						}
					}
					else if (GetAsyncKeyState(VK_F6))
					{
						break;
					}
			}
			else if (Model == 4)
			{
				printf("输入以选择\n1为RGB连击\n2为计数\n3为性能\n4为精确点击(alpha)\n");
				ChiShu = 0;
				scanf_s("%d", &model);
				if (model == 1)
				{
					printf("RGB模式开启\n按F5启动\n双击F6返回\n");
					while (1)
					{
						if (GetAsyncKeyState(VK_F5))
						{
							while (2)
							{
								system("color 0A");
								system("color 0B");
								system("color 0C");
								system("color 0D");
								system("color 0E");
								mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
								if (GetAsyncKeyState(VK_F6))
								{
									system("color 0C");
									printf("请再次按下F6\n");
									break;
									break;
								}
							}
						}
						else if (GetAsyncKeyState(VK_F6))
						{
							break;
						}
					}
				}
				else if (model == 2)
				{
					printf("计数模式开始\n按F5启动\n按F6退出并查看连击次数\n");
					while (7)
					{
						if (GetAsyncKeyState(VK_F5))
						{
							while (8)
							{
								mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
								++ChiShu;
								if (GetAsyncKeyState(VK_F6))
								{
									printf("点击次数=%d", ChiShu);
									printf("\n\f再按一次F6退出\n");
									break;
								}
							}
						}
						else if (GetAsyncKeyState(VK_F6))
						{
							printf("点击次数=%d", ChiShu);
							printf("\n");
							break;
						}
					}
				}
				else if (model == 3)
				{
					printf("性能模式\n按F5开始\n按F6退出\n");
					while (5)
					{
						if (GetAsyncKeyState(VK_F5))
						{
							while (9)
							{
								mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
								if (GetAsyncKeyState(VK_F6))
								{
									printf("\n\n性能模式退出");
									break;
								}
							}

						}
						else if (GetAsyncKeyState(VK_F6))
						{
							break;
						}
					}
				}
				else if (model == 4)
				{
					printf("请输入点击次数\n");
					scanf_s("%d", &DianJiChiShu);
					Sleep(500);
					printf("\n点击开始\n");
					for (size_t gen = 0; gen < DianJiChiShu; gen++)
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					}
					printf("点击完成，按a返回\n");
					if (GetAsyncKeyState('A'))
					{
						return 0;
					}

				}
				else if (model == 5)
				{
					printf("请输入点击时长（单位/秒）\n");
					scanf_s("%d",&DianJiShiChang);
					DianJiShiChang = DianJiShiChang*1000;
					printf("在5秒后开始\n");
					Sleep(5000);
					CreateThread(NULL, NULL, timea, NULL, 0, NULL);
					zhuantai = DianJiShiChang;
					for (;;)
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
						if (zhuantai <= 0)
						{
							break;
							CloseHandle(NULL, NULL, timea, NULL, 0, NULL);
						}
					}
				}
				else
				{
					printf("请重新输入\n");
					break;
				}
			}
			else if (Model == 5)
			{
			system("cls");
			printf(tmpbuf);
			continue;
			}
			else if (Model == 6)
			{
			printf("版本4.3.1\n");
			Sleep(2000);
			printf("发布时间2020.5.22\n");
			Sleep(2000);
			printf("基于visual studio 2019\n");
			Sleep(3000);
			continue;
			 }
			else if (Model == 7)
			{
				return 0;
			}
			else if (model ==! 0)
			{
			break;
			 }
			else
			{
				printf("\n请重新输入\n");
				getchar("%d", &Model);
				break;
			}
		}
	}

DWORD WINAPI timea()
{
	for (;;)
	{
		if (zhuantai > 0)
		{
			Sleep(1);
			zhuantai--;
			printf("%d", zhuantai);
		}
		else
		{
			zhuantai=0;
			return(0);
		}
	}
}
