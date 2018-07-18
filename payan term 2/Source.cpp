#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include<time.h>
#include<chrono>
using namespace std;
using namespace chrono;
char a = 178, b = (177);
void color(int number)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, number);
}

void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
	}
}
void jadval()
{
	color(7);
	for (int i = 20; i <= 76; i += 7)
	{
		for (int j = 3; j <= 35; j++)
		{
			gotoxy(i, j);
			cout << char(a);
		}
	}
	for (int j = 3; j <= 35; j += 4)
	{
		for (int i = 20; i <= 76; i++)
		{
			gotoxy(i, j);
			cout << char(a);
		}
	}
	for (int i = 28; i <= 76; i += 14)
	{
		for (int j = 4; j <= 35; j+=8)
		{
			gotoxy(i, j);
			color(255);
			cout << "      ";
			gotoxy(i, j+1);
			color(255);
			cout << "      ";
			gotoxy(i, j + 2);
			color(255);
			cout << "      ";
		}
	}
	for (int i = 21; i <= 76; i += 14)
	{
		for (int j = 8; j <= 35; j += 8)
		{
			gotoxy(i, j);
			color(255);
			cout << "      ";
			gotoxy(i, j + 1);
			color(255);
			cout << "      ";
			gotoxy(i, j + 2);
			color(255);
			cout << "      ";
		}
	}
}
void Matrix(int d[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0 && j % 2 == 0)
				d[i][j] = 1;
			else if (i % 2 == 1 && j % 2 == 1)
				d[i][j] = 1;
			else
				d[i][j] = 0;
		}
	}
}
void mohre(int d[][8])
{
	color(11);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (d[i][j] == 1)
			{
				int x = 20 + (((i)* 7) + (7 / 2));
				int y = 3 + (((j)* 4) + (4 / 2));
				gotoxy(x, y);
				cout << char(b) << char(b);
			}
		}
	}
}
int getY(int y)
{
	y = 3 + (((y)* 4) + (4 / 2));
	return y;
}
int getX(int x)
{
	x = 20 + (((x)* 7) + (7 / 2));
	return x;
}

bool upRight(int x, int y, int d[][8])
{
	color(11);
	if (x + 2>8 || y - 2<0)
		return false;
	if (d[x + 1][y - 1] == 0)
		return false;
	if (d[x + 2][y - 2] == 1)
		return false;
	if (d[x][y] == 0)
		return false;

	gotoxy(getX(x), getY(y));

	cout << "  ";
	gotoxy(getX(x + 1), getY(y - 1));
	cout << "  ";
	gotoxy(getX(x + 2), getY(y - 2));
	cout << b << b;
	return true;
}
bool upLeft(int x, int y, int d[][8])
{
	color(11);
	if (x - 2<0 || y - 2<0)
		return false;
	if (d[x - 1][y - 1] == 0)
		return false;
	if (d[x - 2][y - 2] == 1)
		return false;
	if (d[x][y] == 0)
		return false;
	gotoxy(getX(x), getY(y));
	cout << "  ";
	gotoxy(getX(x - 1), getY(y - 1));
	cout << "  ";
	gotoxy(getX(x - 2), getY(y - 2));
	cout << b << b;
	return true;
}
bool DownRight(int x, int y, int d[][8])
{
	color(11);
	if (x + 2>8 || y + 2>8)
		return false;
	if (d[x + 1][y + 1] == 0)
		return false;
	if (d[x + 2][y + 2] == 1)
		return false;
	if (d[x][y] == 0)
		return false;
	gotoxy(getX(x), getY(y));
	cout << "  ";
	gotoxy(getX(x + 1), getY(y + 1));
	cout << "  ";
	gotoxy(getX(x + 2), getY(y + 2));
	cout << b << b;
	return true;
}
bool DownLeft(int x, int y, int d[][8])
{
	color(11);
	if (x - 2<0 || y + 2<0)
		return false;
	if (d[x - 1][y + 1] == 0)
		return false;
	if (d[x - 2][y + 2] == 1)
		return false;
	if (d[x][y] == 0)
		return false;
	gotoxy(getX(x), getY(y));
	cout << "  ";
	gotoxy(getX(x - 1), getY(y + 1));
	cout << "  ";
	gotoxy(getX(x - 2), getY(y + 2));
	cout << b << b;
	return true;

}
bool Lose(int d[][8])
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (d[i][j] == 1)
			{
				sum++;
				if (i + 2<8 && j - 2 >= 0)
				{
					if (d[i + 1][j - 1] == 1 && d[i + 2][j - 2] == 0)
						return false;
				}
				if (i - 2 >= 0 && j - 2 >= 0)
				{
					if (d[i - 1][j - 1] == 1 && d[i - 2][j - 2] == 0)
						return false;
				}
				if (i + 2<8 && j + 2<8)
				{
					if (d[i + 1][j + 1] == 1 && d[i + 2][j + 2] == 0)
						return false;
				}
				if (i - 2 >= 0 && j + 2<8)
				{
					if (d[i - 1][j + 1] == 1 && d[i - 2][j + 2] == 0)
						return false;
				}
			}
		}
	}
	if (sum == 32)
		return false;
	return true;
}
int menu()
{
	char ch;
	int select = 1;
	system("cls");
	while (1)
	{
		if (select == 1)
			color(11);
		else
			color(15);
		gotoxy(58, 8);
		cout << "New Game";
		if (select == 2)
			color(11);
		else
			color(15);
		gotoxy(58, 10);
		cout << "Load Game";
		if (select == 3)
			color(11);
		else
			color(15);
		gotoxy(58, 12);
		cout << "High Scores";
		if (select == 4)
			color(11);
		else
			color(15);
		gotoxy(58, 14);
		cout << "About the game";
		if (select == 5)
			color(11);
		else
			color(15);
		gotoxy(58, 16);
		cout << "Exit";
		ch = _getch();
		switch (ch)
		{
		case 72:
			select--;
			if (select == 0)
				select = 5;
			break;
		case 80:
			select++;
			if (select == 6)
				select = 1;
			break;
		case 13:
			return select;
		}
	}
}
int point(int d[][8])
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (d[i][j] == 1)
				sum++;
	return 32 - sum;
}
int main()
{
	int d[8][8], c[50][3], r = 0, aval[2], w, ss = 0;
	int X, Y;
	bool lose = false;
	int f = 0;
	string ca[6];
	int R, V[6][2];
	while (true)
	{
		ss = 0;
		w = menu();
		system("cls");
		if (w == 5)
			break;
		if (w == 4)
		{
			gotoxy(58, 12);
			cout << "Reza Masrori";
			lose = true;
			system("pause>0");
		}
		else if (w == 3)
		{
			ifstream out3("in2.txt", ios::in);
			out3 >> R;
			for (int i = 0; i < R; i++)
				out3 >> ca[i] >> V[i][0] >> V[i][1];
			system("cls");
			gotoxy(20, 5);
			cout << "Name";
			gotoxy(40, 5);
			cout << "Point";
			gotoxy(50, 5);
			cout << "time";
			for (int i = 0; i < R; i++)
			{
				gotoxy(20, 7 + i);
				cout << ca[i];
				gotoxy(40, 7 + i);
				cout << V[i][0];
				gotoxy(50, 7 + i);
				cout << V[i][1];
			}
			system("pause>0");
		}
		else if (w == 2)
		{
			int I;
			ifstream out("in.txt", ios::in);
			out >> I;
			for (int i = 0; i<8 && I == 1; i++)
				for (int j = 0; j<8; j++)
					out >> d[i][j];
			out.close();
			if (I == 1)
			{
				ifstream out1("in1.txt", ios::in);
				out1 >> ss >> r >> aval[0] >> aval[1];
				for (int i = 0; i < r; i++)
					out1 >> c[i][0] >> c[i][1] >> c[i][2];
				out1.close();
				mohre(d);
				jadval();
				f = 1;
				X = c[r - 1][0];
				Y = c[r - 1][1];
				if (r <= 0)
					f = 0;
			}
			else
			{
				w = 3;
				lose = true;
			}
		}
		else if (w == 1)
		{
			Matrix(d);
			mohre(d);
			jadval();
			lose = false;
			f = 0;
			r = 0;
			X = -1;
		}
		auto start = high_resolution_clock::now();
		char ch = _getch();
		int x = 7, y = 7;
		int aa = 7, bb = 7;
		aa = getX(x);
		bb = getY(y);
		while (!lose)
		{
			color(0);
			ch = _getch();
			if (ch == 'w'||ch=='W')
			{
				y--;
				if (y<0)
					y = 7;
				aa = getX(x);
				bb = getY(y);
				gotoxy(aa, bb);
			}
			else if(ch==27)
			{
				lose=true;
				w=3;
			}

			else if (ch == 'a'||ch=='A')
			{
				x--;
				if (x<0)
					x = 7;
				aa = getX(x);
				bb = getY(y);
				gotoxy(aa, bb);
			}
			else if (ch == 's'||ch=='S')
			{
				y++;
				if (y>7)
					y = 0;
				aa = getX(x);
				bb = getY(y);
				gotoxy(aa, bb);
			}
			else if (ch == 'd'||ch =='D')
			{
				x++;
				if (x>7)
					x = 0;
				aa = getX(x);
				bb = getY(y);
				gotoxy(aa, bb);
			}
			else if ((ch == 'q'||ch=='Q')&& f == 0 && d[x][y] == 1)
			{
				aval[0] = x;
				aval[1] = y;
				d[x][y] = 0;
				aa = getX(x);
				bb = getY(y);
				gotoxy(aa, bb);
				cout << "  ";
				f = 1;
				r = 0;
			}
			else if ((ch == 'e'||ch=='E')&&d[x][y] == 1&&f==1)
			{
				if (X != -1&&d[X][Y]==1)
				{
					gotoxy(getX(X), getY(Y));
					color(11);
					cout << b << b;
				}
				X = x;
				Y = y;
				gotoxy(getX(X), getY(Y));
				color(14);
				cout << b << b;
			}
			else if ((ch == 'r' || ch == 'R') && f == 0)
			{
				srand(time(NULL));
				int i,I;
				i = rand() % 4;
				srand(time(NULL));
				I= rand() % 8;
				i = i * 2;
				if (I % 2 != 0)
					i++;
				aval[0] = I;
				aval[1] = i;
				d[I][i] = 0;
				aa = getX(I);
				bb = getY(i);
				gotoxy(aa, bb);
				cout << "  ";
				x = I;
				y = i;
				X = x;
				Y = y;
				f = 1;
				r = 0;
			}
			else if ((ch == 'z'||ch=='Z')&&d[x][y] == 0)
			{
				bool t = false;
				if (X + 2 == x && Y - 2 == y)
				{
					t = upRight(X, Y, d);
					if (t)
					{
						d[X][Y] = 0;
						d[X + 1][Y - 1] = 0;
						c[r][2] = 1;
					}
				}
				else if (X - 2 == x && Y - 2 == y)
				{
					t = upLeft(X, Y, d);
					if (t)
					{
						d[X][Y] = 0;
						d[X - 1][Y - 1] = 0;
						c[r][2] = 2;
					}
				}
				else if (X + 2 == x && Y + 2 == y)
				{
					t = DownRight(X, Y, d);
					if (t)
					{
						d[X][Y] = 0;
						d[X + 1][Y + 1] = 0;
						c[r][2] = 3;
					}
				}
				else if (X - 2 == x && Y + 2 == y)
				{
					t = DownLeft(X, Y, d);
					if (t)
					{
						d[X][Y] = 0;
						d[X - 1][Y + 1] = 0;
						c[r][2] = 4;
					}
				}
				if (t)
				{
					d[x][y] = 1;
					c[r][0] = X;
					c[r][1] = Y;
					r++;
				}
			}
			else if ((ch == 'u' || ch == 'U') && r>0)
			{
				color(11);
				gotoxy(getX(X), getY(Y));
				cout << b << b;
				color(14);
				r--;
				gotoxy(getX(c[r][0]), getY(c[r][1]));
				cout << b << b;
				d[c[r][0]][c[r][1]] = 1;
				color(11);
				if (c[r][2] == 1)
				{
					gotoxy(getX(c[r][0] + 1), getY(c[r][1] - 1));
					cout << b << b;
					d[c[r][0] + 1][c[r][1] - 1] = 1;
					gotoxy(getX(c[r][0] + 2), getY(c[r][1] - 2));
					cout << "  ";
					d[c[r][0] + 2][c[r][1] - 2] = 0;
				}
				else if (c[r][2] == 2)
				{
					gotoxy(getX(c[r][0] - 1), getY(c[r][1] - 1));
					cout << b << b;
					d[c[r][0] - 1][c[r][1] - 1] = 1;
					gotoxy(getX(c[r][0] - 2), getY(c[r][1] - 2));
					cout << "  ";
					d[c[r][0] - 2][c[r][1] - 2] = 0;
				}
				else if (c[r][2] == 3)
				{
					gotoxy(getX(c[r][0] + 1), getY(c[r][1] + 1));
					cout << b << b;
					d[c[r][0] + 1][c[r][1] + 1] = 1;
					gotoxy(getX(c[r][0] + 2), getY(c[r][1] + 2));
					cout << "  ";
					d[c[r][0] + 2][c[r][1] + 2] = 0;
				}
				else if (c[r][2] == 4)
				{
					gotoxy(getX(c[r][0] - 1), getY(c[r][1] + 1));
					cout << b << b;
					d[c[r][0] - 1][c[r][1] + 1] = 1;
					gotoxy(getX(c[r][0] - 2), getY(c[r][1] + 2));
					cout << "  ";
					d[c[r][0] - 2][c[r][1] + 2] = 0;
				}
				x = c[r][0];
				y = c[r][1];
				X = c[r][0];
				Y = c[r][1];
				gotoxy(getX(c[r][0]), getY(c[r][1]));
			}
			else if ((ch == 'u' || ch == 'U') && r == 0)
			{
				color(11);
				gotoxy(getX(X), getY(Y));
				cout << b << b;
				color(11);
				gotoxy(getX(aval[0]), getY(aval[1]));
				cout << b << b;
				d[aval[0]][aval[1]] = 1;
				f = 0;
				x = aval[0];
				y = aval[1];
				X = aval[0];
				Y = aval[1];
				r--;
			}
			lose = Lose(d);
			if(w==3)
				lose=true;
			ofstream in("in.txt", ios::out);
			in << 1 << " ";
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
					in << d[i][j] << " ";
				in << endl;
			}
			in.close();
			auto end = high_resolution_clock::now();
			int sc = duration_cast<seconds>(end - start).count();
			sc = sc + ss;
			ofstream in1("in1.txt", ios::out);
			in1 << sc << " " << r << " " << aval[0] << " " << aval[1] << " ";
			for (int i = 0; i < r; i++)
				in1 << c[i][0] << " " << c[i][1] << " " << c[i][2] << " ";
			in1.close();
		}
		if (w == 1 || w == 2)
		{
			ofstream in3("in.txt", ios::out);
			in3 << 0 << " ";
			in3.close();
			ofstream in4("in1.txt", ios::out);
			in4.close();
			auto end = high_resolution_clock::now();
			gotoxy(getX(0), getY(9));
			cout << "Game end in time: ";
			cout << duration_cast<seconds>(end - start).count() + ss;
			cout << " second";
			gotoxy(getX(0), getY(10));
			cout << "Enter Name: ";
			cin >> ca[0];
			ifstream out2("in2.txt", ios::in);
			out2 >> R;
			R++;
			for (int i = 1; i < R; i++)
				out2 >> ca[i] >> V[i][0] >> V[i][1];
			out2.close();
			gotoxy(getX(0), getY(11));
			cout << "point: ";
			V[0][0] = point(d);
			cout << V[0][0];
			V[0][1] = duration_cast<seconds>(end - start).count() + ss;
			for (int i = 1; i <R; i++)
			{
				if (V[i - 1][0] < V[i][0])
				{
					swap(V[i - 1][0], V[i][0]);
					swap(V[i - 1][1], V[i][1]);
					swap(ca[i - 1], ca[i]);
				}
				else if (V[i - 1][0] == V[i][0] && V[i - 1][1] > V[i][1])
				{
					swap(V[i - 1][0], V[i][0]);
					swap(V[i - 1][1], V[i][1]);
					swap(ca[i - 1], ca[i]);
				}
			}
			if (R == 6)
				R = 5;
			ofstream in2("in2.txt", ios::out);
			in2 << R << " ";
			for (int i = 0; i < R; i++)
				in2 << ca[i] << " " << V[i][0] << " " << V[i][1] << " ";
			in2.close();
		}
	}
}