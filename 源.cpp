//ͷ�ļ���
#include<graphics.h>		//ͼ�ο�
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//ȫ������
#define PI 3.1415926		//pi
IMAGE backimg1;			//����ͼ							���ֽ��ַ���Ī��
IMAGE backimg2;
IMAGE balltable;			//����
IMAGE choiceimg1;			//ѡ���ز� ��ʼ��Ϸ
IMAGE choiceimg2;			//��Ϸ����
IMAGE choiceimg3;			//���¿�ʼ
IMAGE choiceimg4;			//������ҳ
IMAGE fen1;				//����
IMAGE fen2;
IMAGE power1;			//����
IMAGE power2;
IMAGE power3;
IMAGE ballhole1;			//��
IMAGE ballhole2;
IMAGE ballhole3;
IMAGE ballhole4;
IMAGE ballhole5;
IMAGE ballhole6;
IMAGE ballhole7;
IMAGE ballhole8;
IMAGE ballhole9;
IMAGE ball1;			//��
IMAGE ball2;
IMAGE ball3;
IMAGE ball4;
IMAGE ball5;
IMAGE ball6;
IMAGE ball7;
IMAGE ball8;
IMAGE ball9;
char score1[10];		//��ҷ�		//��������Ϊ��Ϸ����ı���
char score2[10];		//���Է�
int s1, s2;			//����
int i;
int dx, dy;			//�����
double degree;			//�Ƕ�
double cot;			//1.0
int spotx, spoty;		//���ߵ�����ꡣ
int power;			//���Ĵ�С
int countball;			//��Ĵ���
time_t tstart;		//��ó�ʼʱ��
time_t tend;
struct MyStruct				//�����λ������ �ṹ��
{
	int x;
	int y;
	bool exist;
};
MyStruct ball[11];		//��ĳ�ʼλ��
MyStruct hole[11];			//��λ��

//����������
void game_console();		//��Ϸ��ӭ����		
void game_rules();			//�������
void game_play();			//��Ϸ����paly
void game_play_Initia();	//��ʼ������
void loadpictures();		//�����ز�
void moveball();		//����ƶ�
void judge();		//�ж���Ӯ

//������
int main()
{
	SetConsoleTitle("̨��С��Ϸ");	//���ڱ���
	initgraph(900, 600);		//���ڴ�С
	setbkmode(TRANSPARENT);			//͸��
	loadpictures();			//�زĺ���
	game_console();			//���뻶ӭ���溯��
	return 0;
}

void loadpictures()			//�����ز�
{
	loadimage(&backimg1, "./images/001.jpg", 900, 600);			//�����ز�ͼƬ 
	loadimage(&backimg2, "./images/004.jpg", 900, 600);
	loadimage(&balltable, "./images/005.jpg", 750, 400);
	loadimage(&choiceimg1, "./images/002.jpg", 230, 70);
	loadimage(&choiceimg2, "./images/003.jpg", 230, 70);
	loadimage(&choiceimg3, "./images/006.jpg", 230, 70);
	loadimage(&choiceimg4, "./images/007.jpg", 230, 70);
	loadimage(&fen1, "./images/��1.jpg", 60, 175);
	loadimage(&fen2, "./images/��2.jpg", 60, 175);
	loadimage(&power1, "./images/��1.jpg", 175, 50);
	loadimage(&power2, "./images/��2.jpg", 175, 50);
	loadimage(&power3, "./images/��3.jpg", 175, 50);
	loadimage(&ballhole9, "./images/��9.gif", 25, 25);			//����������ͼ
	loadimage(&ballhole1, "./images/��1.gif", 25, 25);
	loadimage(&ballhole2, "./images/��2.gif", 25, 25);
	loadimage(&ballhole3, "./images/��3.gif", 25, 25);
	loadimage(&ballhole4, "./images/��4.gif", 25, 25);
	loadimage(&ballhole5, "./images/��5.gif", 25, 25);
	loadimage(&ballhole6, "./images/��6.gif", 25, 25);
	loadimage(&ballhole7, "./images/��7.gif", 25, 25);
	loadimage(&ballhole8, "./images/��8.gif", 25, 25);
	loadimage(&ball9, "./images/��9.gif", 20, 20);
	loadimage(&ball1, "./images/��1.gif", 20, 20);
	loadimage(&ball2, "./images/��2.gif", 20, 20);
	loadimage(&ball3, "./images/��3.gif", 20, 20);
	loadimage(&ball4, "./images/��4.gif", 20, 20);
	loadimage(&ball5, "./images/��5.gif", 20, 20);
	loadimage(&ball6, "./images/��6.gif", 20, 20);
	loadimage(&ball7, "./images/��7.gif", 20, 20);
	loadimage(&ball8, "./images/��8.gif", 20, 20);
}

void game_console()			//��Ϸ����
{
	putimage(0, 0, &backimg1);			//����ͼƬ�ز�
	putimage(320, 150, &choiceimg1);
	putimage(320, 350, &choiceimg2);
	setcolor(BLACK);			//������ɫ
	settextstyle(70, 0, "�����п�");
	outtextxy(230, 250, "̨ �� С �� Ϸ");
	settextstyle(30, 0, "΢���ź�");		//������ʽ
	MOUSEMSG m;		//���������Ϣ
	while (1) {		
		FlushMouseMsgBuffer();
		m = GetMouseMsg();		//��ȡ�����Ϣ
		if (m.uMsg == WM_LBUTTONDOWN)			//����������
		{
			if (m.x >= 320 && m.x <= 550 && m.y >= 150 && m.y <= 220)		//��ʼ��Ϸ��λ��
			{
				game_play();
				break;				//��ֹ��ͻ
			}
			if (m.x >= 320 && m.x <= 550 && m.y >= 350 && m.y <= 420)		//����ѡ���λ��
			{
				game_rules();
				break;
			}
		}
	}
}

void game_play()			//��Ϸ��ʼ
{
	game_play_Initia();		//��ʼ������
	cleardevice();			// ����
	putimage(0, 0, &balltable);			//�ز�ͼ		��ʼ���ز�
	putimage(50, 500, &choiceimg3);			
	putimage(400, 500, &choiceimg4);
	putimage(800, 15, &fen1);
	putimage(800, 235, &fen2);
	putimage(200, 182, &ball1);
	putimage(580, 58, &ballhole1);
	putimage(580, 88, &ballhole2);
	putimage(580, 118, &ballhole3);
	putimage(580, 148, &ballhole4);
	putimage(580, 178, &ballhole5);
	putimage(580, 208, &ballhole6);
	putimage(580, 238, &ballhole7);
	putimage(580, 268, &ballhole8);
	putimage(580, 298, &ballhole9);
	putimage(25, 425, &power1);
	putimage(300, 425, &power2);
	putimage(575, 425, &power3);
	outtextxy(810, 115, "000");			//��ʾ�÷�
	outtextxy(810, 335, "000");
	Sleep(300);
	while (1) {			//���ϸ���
		cleardevice();			//����
		putimage(0, 0, &balltable);			//�ز�ͼ
		putimage(50, 500, &choiceimg3);
		putimage(400, 500, &choiceimg4);
		putimage(800, 15, &fen1);
		putimage(800, 235, &fen2);
		putimage(25, 425, &power1);
		putimage(300, 425, &power2);
		putimage(575, 425, &power3);
		putimage(hole[1].x, hole[1].y, &ballhole1);
		putimage(hole[2].x, hole[2].y, &ballhole2);
		putimage(hole[3].x, hole[3].y, &ballhole3);
		putimage(hole[4].x, hole[4].y, &ballhole4);
		putimage(hole[5].x, hole[5].y, &ballhole5);
		putimage(hole[6].x, hole[6].y, &ballhole6);
		putimage(hole[7].x, hole[7].y, &ballhole7);
		putimage(hole[8].x, hole[8].y, &ballhole8);
		putimage(hole[9].x, hole[9].y, &ballhole9);
		sprintf_s(score1, "%03d", s1);			//�÷�תΪ�ַ���
		sprintf_s(score2, "%03d", s2);
		outtextxy(810, 115, score1);			//��ʾ�÷�
		outtextxy(810, 335, score2);
		if (ball[countball].exist==0) {			//�������Ѿ�û�����ˣ�������һ����
			countball++;
			switch (countball) {
			case 1:putimage(200, 182, &ball1); break;
			case 2:putimage(200, 182, &ball2); break;
			case 3:putimage(200, 182, &ball3); break;
			case 4:putimage(200, 182, &ball4); break;
			case 5:putimage(200, 182, &ball5); break;
			case 6:putimage(200, 182, &ball6); break;
			case 7:putimage(200, 182, &ball7); break;
			case 8:putimage(200, 182, &ball8); break;
			case 9:putimage(200, 182, &ball9); break;
			default:break;
			}
		}
		else {					//�����������򣬱�������λ��
			switch (countball) {
			case 1:putimage(ball[countball].x, ball[countball].y, &ball1); break;
			case 2:putimage(ball[countball].x, ball[countball].y, &ball2); break;
			case 3:putimage(ball[countball].x, ball[countball].y, &ball3); break;
			case 4:putimage(ball[countball].x, ball[countball].y, &ball4); break;
			case 5:putimage(ball[countball].x, ball[countball].y, &ball5); break;
			case 6:putimage(ball[countball].x, ball[countball].y, &ball6); break;
			case 7:putimage(ball[countball].x, ball[countball].y, &ball7); break;
			case 8:putimage(ball[countball].x, ball[countball].y, &ball8); break;
			case 9:putimage(ball[countball].x, ball[countball].y, &ball9); break;
			default:break;
			}
		}
		tend = time(NULL);
		if (tend - tstart >= 1) {
			tstart = tend;
			for (i = 1; i <= 9; i++) {					//��λ�ñ仯
				if (hole[i].y == 58) hole[i].y = 298;
				else hole[i].y -= 30;
			}
		}
		POINT m;			//�����
		GetCursorPos(&m);
		HWND hwnd = GetHWnd();			//���
		ScreenToClient(hwnd, &m);		//תΪ��Ļ����
		if (m.x >= 44 && m.x <= 710 && m.y >= 39 && m.y <= 358)			//������
		{
			dx = m.x - ball[countball].x;		//�󻡶�
			dy = m.y - ball[countball].y;
			degree = atan((cot * m.y - cot * ball[countball].y) / (cot * m.x - cot * ball[countball].x));
			if (dx == 0 && dy > 0)	degree = PI / 2;
			if (dx == 0 && dy < 0) degree = -(PI / 2);
			if (dy == 0 && dx > 0) degree = 0;
			if (dy == 0 && dx < 0) degree = PI;
			if (dx < 0) degree = PI + degree;
			spotx = ball[countball].x+8;
			spoty = ball[countball].y-6;
			for (i = 1; i <= 10; i++)
			{
				outtextxy(spotx, spoty, "��"); 
				spotx += 10 * cos(degree);
				spoty += 10 * sin(degree);
			}
		}
		if (GetKeyState(VK_LBUTTON) < 0)		//�������
		{
			if (m.x >= 25 && m.x <= 200 && m.y >= 425 && m.y <= 475) power = 1;		//���ȴ�С
			if (m.x >= 300 && m.x <= 475 && m.y >= 425 && m.y <= 475) power = 2;
			if (m.x >= 575 && m.x <= 750 && m.y >= 425 && m.y <= 475) power = 3;
			if (m.x >= 44 && m.x <= 710 && m.y >= 39 && m.y <= 358)
			{
				moveball();		//���ƶ�
				if (ball[countball].exist == 1) s2 += 10;	//���Ե÷�
				if (ball[9].exist == 0)	judge();	//��û�� �ж���Ӯ
			}
			if (m.x >= 50 && m.x <= 280 && m.y >= 500 && m.y <= 570)		//������Ϸ��λ��
			{
				game_play();
				break;				//��ֹ��ͻ
			}
			if (m.x >= 400 && m.x <= 630 && m.y >= 500 && m.y <= 570)		//������ҳ��λ��
			{
				game_console();
				break;
			}
		}
		Sleep(100);
	}
}

void game_rules()			//�÷ֹ���
{
	cleardevice();			//����
	putimage(0, 0, &backimg2);
	putimage(100, 450, &choiceimg1);
	putimage(500, 450, &choiceimg4);
	outtextxy(50, 50, "1.�Ÿ���ɫ�򶴣��ſŶ�Ӧ��ɫ����С�Ĳ���");
	outtextxy(50, 85, "2.ÿ����Ϸ��ʼʱ�����̶�λ������һ�Ų�������һ��Ƶ���ƶ�λ�ã�");
	outtextxy(50, 120, "	�����Ҫ���������Ӧ��ɫ���򶴡�");
	outtextxy(50, 155, "3.ÿ����һ�������̶�λ������һ�Ų��򣬾ſ���ȫ�붴����Ϸ������");
	outtextxy(50, 190, "4.��ҵ÷ֹ��򣺻���һ����ʱ����10�֡�");
	outtextxy(50, 225, "5.���Ե÷ֹ������δ������ʱ����10�֡�");
	outtextxy(50, 260, "6.��Ϸ����ʱ���÷ָ��߻�ʤ��");
	outtextxy(50, 295, "PS������ǰ��Ҫѡ�����ȴ�С��");
	outtextxy(50, 330, "���Ĵ�С�����֣���Ϸ��ʼʱ��Ĭ��Ϊ��һ��");
	MOUSEMSG m;		//���������Ϣ
	while (1) {		
		FlushMouseMsgBuffer();
		m = GetMouseMsg();		//��ȡ�����Ϣ
		if (m.uMsg == WM_LBUTTONDOWN)			//����������
		{
			if (m.x >= 100 && m.x <= 330 && m.y >= 450 && m.y <= 520)		//��ʼ��Ϸ��λ��
			{
				game_play();
				break;
			}
			if (m.x >= 500 && m.x <= 730 && m.y >= 450 && m.y <= 520)		//������ҳ��λ��
			{
				game_console();
				break;
			}
		}
	}
}

void game_play_Initia()
{		
	s1 = 0;
	s2 = 0;
	degree = 0;			
	power = 1;		
	countball = 1;	
	cot = 1.0;
	tstart = time(NULL);
	ball[0] = { 0,0,1 };
	ball[1] = { 200,182,1 };
	ball[2] = { 200,182,1 };
	ball[3] = { 200,182,1 };
	ball[4] = { 200,182,1 };
	ball[5] = { 200,182,1 };
	ball[6] = { 200,182,1 };
	ball[7] = { 200,182,1 };
	ball[8] = { 200,182,1 };
	ball[9] = { 200,182,1 };
	hole[0] = { 0,0,1 };
	hole[1] = { 580,58,1 };
	hole[2] = { 580,88,1 };
	hole[3] = { 580,118,1 };
	hole[4] = { 580,148,1 };
	hole[5] = { 580,178,1 };
	hole[6] = { 580,208,1 };
	hole[7] = { 580,238,1 };
	hole[8] = { 580,268,1 };
	hole[9] = { 580,298,1 };
}

void moveball()
{
	time_t mid = time(NULL);		//�������˶���ʱ��
	time_t te = time(NULL);
	int s;
	while (1) {
		if (te - mid >= 4) return;		//ʱ�䵽�� ����
		if (ball[countball].x <= 45)	//���� ���ȱ仯������
		{
			ball[countball].x = 46;
			degree = PI - degree;
		}
		if (ball[countball].x >= 687)
		{
			ball[countball].x = 686;
			degree = PI - degree;
		}
		if (ball[countball].y <= 40)
		{
			ball[countball].y = 41;
			degree = -degree;
		}
		if (ball[countball].y >= 337)
		{
			ball[countball].y = 336;
			degree = -degree;
		}
		if (power == 1) {
			ball[countball].x += 9 * cos(degree);
			ball[countball].y += 9 * sin(degree);
		}
		if (power == 2) {
			ball[countball].x += 12 * cos(degree);
			ball[countball].y += 12 * sin(degree);
		}
		if (power == 3) {
			ball[countball].x += 14 * cos(degree);
			ball[countball].y += 14 * sin(degree);
		}
		cleardevice();
		putimage(0, 0, &balltable);
		putimage(50, 500, &choiceimg3);
		putimage(400, 500, &choiceimg4);
		putimage(800, 15, &fen1);
		putimage(800, 235, &fen2);
		putimage(hole[1].x, hole[1].y, &ballhole1);
		putimage(hole[2].x, hole[2].y, &ballhole2);
		putimage(hole[3].x, hole[3].y, &ballhole3);
		putimage(hole[4].x, hole[4].y, &ballhole4);
		putimage(hole[5].x, hole[5].y, &ballhole5);
		putimage(hole[6].x, hole[6].y, &ballhole6);
		putimage(hole[7].x, hole[7].y, &ballhole7);
		putimage(hole[8].x, hole[8].y, &ballhole8);
		putimage(hole[9].x, hole[9].y, &ballhole9);
		outtextxy(810, 115, score1);
		outtextxy(810, 335, score2);
		switch (countball) {
		case 1:putimage(ball[countball].x, ball[countball].y, &ball1); break;
		case 2:putimage(ball[countball].x, ball[countball].y, &ball2); break;
		case 3:putimage(ball[countball].x, ball[countball].y, &ball3); break;
		case 4:putimage(ball[countball].x, ball[countball].y, &ball4); break;
		case 5:putimage(ball[countball].x, ball[countball].y, &ball5); break;
		case 6:putimage(ball[countball].x, ball[countball].y, &ball6); break;
		case 7:putimage(ball[countball].x, ball[countball].y, &ball7); break;
		case 8:putimage(ball[countball].x, ball[countball].y, &ball8); break;
		case 9:putimage(ball[countball].x, ball[countball].y, &ball9); break;
		default:break;
		}
		if (ball[countball].x >= 567 && ball[countball].x <= 597) {	//������÷֣�����
			s = hole[countball].y - ball[countball].y;
			if (s <= 12 && s >= -12) {
				s1 += 10;
				ball[countball].exist = 0;
				return;
			}
		}
		tend = time(NULL);
		if (tend - tstart >= 1) {
			tstart = tend;
			for (i = 1; i <= 9; i++) {
				if (hole[i].y == 58) hole[i].y = 298;
				else hole[i].y -= 30;
			}
		}
		te = time(NULL);
		if (power == 1)	Sleep(70);
		if (power == 2) Sleep(60);
		if (power == 3) Sleep(40);
	}
}

void judge()
{
	settextstyle(70, 20, "�����п�");
	setcolor(RED);
	if (s1 > s2) outtextxy(230, 160, "�� �� �� ʤ��");
	if (s1 < s2) outtextxy(230, 160, "�� �� �� ʤ��");
	if (s1 == s2) outtextxy(230, 160, "�� ϲ ƽ �֣�");
	setcolor(BLACK);		//�ص�֮ǰ����ɫ
	settextstyle(30, 0, "΢���ź�");	
	MOUSEMSG m;		
	while (1) {
		FlushMouseMsgBuffer();
		m = GetMouseMsg();		
		if (m.uMsg == WM_LBUTTONDOWN)			
		{
			if (m.x >= 50 && m.x <= 280 && m.y >= 500 && m.y <= 570)		
			{
				game_play();
				break;				
			}
			if (m.x >= 400 && m.x <= 630 && m.y >= 500 && m.y <= 570)		
			{
				game_console();
				break;
			}
		}
	}
}