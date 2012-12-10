#include <iostream>
#include <sstream>
#include <algorithm>
#include <Windows.h>
#include <stdio.h>
#include "stdafx.h"

int StartX[100];
int StartY[100];

int Streams = 0;

int StreamStatus[100];

int Buff;

COORD Cord;

HANDLE Handle;

int ScreenX = 75;
int ScreenY = 24;

int Delay[100];
int OriDelay[100];

int Tale[100];

char Letter;

char Letters[28] = "abcdefghijklmnopqrstuvwxyz";

using namespace std;

void type_text(const string& text, const int& speed)
{
  for (size_t i = 0; i < text.size(); i++)
	{
		cout << text[i] << flush;
		_sleep(speed);
	}
}

int Modulus(int iN, int iMod)
{
	int iQ = (iN/iMod);
	return iN - (iQ*iMod);
}

char GetChar(int iGenerator, char cBase, int iRange)
{
	return(cBase + Modulus(iGenerator, iRange));
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleTitle(L"Do you know your ABC's? :D");
	string answer = "";
	string abc = "abcdefghijklmnopqrstuvwxyz";
	string abc2;
	string wait;
	int index = 0;
	
	while (answer != "N" | answer != "Y" | answer != "NO" | answer != "YES" | answer != "MATRIX")
	{
		cout << "Do you know your ABC's? ( Y / N )" << endl;
		cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
		if (answer == "N" | answer == "NO")
		{
			system("cls");
			break;
		}
		if (answer == "Y" | answer == "YES")
		{
			break;
		}
		if (answer == "MATRIX")
		{
			system("cls");
			break;
		}
	}

	if (answer == "N" | answer == "NO")
	{
		while (answer != "Y" | answer != "YES")
		{

			system("cls");
			while (index < 27)
			{
				abc2 = abc.substr(0, index++);
				cout << abc2 << endl;
				_sleep(100);
			}

			while (index > 0)
			{
				abc = abc2.substr(0, index--);
				cout << abc << endl;
				_sleep(100);
			}

			abc = "abcdefghijklmnopqrstuvwxyz";
	     	type_text("\nNow you know your ABC's next time won't you sing with me? :D\n", 50);
			while (answer != "Y" | answer != "N" | answer != "YES" | answer != "NO")
			{
				type_text("Do you want to do it again? ( Y / N )\n", 20);
				cin >> answer;
				transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
				if (answer == "Y" | answer == "YES")
				{
					system("cls");
					break;
				}
				if (answer == "N" | answer == "NO")
				{
					break;
				}
			}
			if (answer == "N" | answer == "NO")
			{
				break;
			}
		}

	}
	if (answer == "Y" | answer == "YES")
	{
		system("cls");
		while (answer != "Y" | answer != "N" | answer != "YES" | answer != "NO")
		{
			cout << "Do you want a custom one?" << endl;
			cin >> answer;
			transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
			if (answer == "Y" | answer == "YES")
			{
				break;
			}
			if (answer == "N" | answer == "NO")
			{
				break;
			}
		}
		if (answer == "Y" | answer == "YES")
		{
			while (answer != "N" & answer != "NO")
			{
				system("cls");
				string custom = "";
				string custom2;
				cout << "Enter the text you want" << endl;
				cin.ignore();
				getline(cin, custom);
				system("cls");
				int length = custom.length();
				while (index < length + 1)
				{
					custom2 = custom.substr(0, index++);
					cout << custom2 << endl;
					_sleep(100);
				}

				while (index > 0)
				{
					custom = custom2.substr(0, index--);
					cout << custom << endl;
					_sleep(100);			
				}
				cout << endl;
				while (answer != "Y" | answer != "N" | answer != "YES" | answer != "NO")
				{
					type_text("Would you like to do another one? ( Y / N )\n", 40);
					cin >> answer;
					transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
					if (answer == "Y" |answer == "YES")
					{
						break;
					}
					if (answer == "N" | answer == "NO")
					{
						break;
					}
				}
			}

		}
		if (answer == "N" | answer == "NO")
		{
			system("cls");
			cout << "Well then fuck off!\n" << endl;
		}
	}
	if (answer == "MATRIX")
	{
		SetConsoleTitle(L"The Matrix");
		keybd_event (VK_MENU, 0x38, 0, 0);
		keybd_event (VK_RETURN, 0x1c, 0, 0);
		keybd_event (VK_RETURN, 0X1c, KEYEVENTF_KEYUP, 0);
		keybd_event (VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	
		Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
		while(!GetAsyncKeyState(VK_ESCAPE))
		{
	
			for(Buff = 0; Buff < 100; Buff++)
			if(!StreamStatus[Buff])
			if(Streams < 100)
			{
			StreamStatus[Buff] = 1;	
			Streams++;   
			StartX[Buff] = rand() % ScreenX;
			StartY[Buff] = 0;
			Delay[Buff] = rand() % 5;
			OriDelay[Buff] = Delay[Buff];
			Tale[Buff] = 10 + rand() % 15;
			break;
		}
	
		for(Buff = 0; Buff < 100; Buff++)
		if(StreamStatus[Buff])
		{
			if(Delay[Buff]) Delay[Buff]--;
			else
			{
				StartY[Buff]++;
				Delay[Buff] = OriDelay[Buff];
				if(StartY[Buff] > ScreenY+Tale[Buff]) 
				{
				StreamStatus[Buff] = 0;
				Streams--;
				}
			}
		}
	
		for(Buff = 0; Buff < 100; Buff++)
		if(StreamStatus[Buff])
		{
			Cord.X = StartX[Buff];
			Cord.Y = StartY[Buff] - Tale[Buff];
			SetConsoleCursorPosition(Handle, Cord);
			printf(" ");
			if(!(StartY[Buff] > ScreenY))
			{
				SetConsoleTextAttribute(Handle, FOREGROUND_GREEN);
				Cord.X = StartX[Buff];
				Cord.Y = StartY[Buff]-1;
				SetConsoleCursorPosition(Handle, Cord);
				Letter = Letters[rand() % 27];
				printf(&Letter);
				SetConsoleTextAttribute(Handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Cord.X = StartX[Buff];
				Cord.Y = StartY[Buff];
				SetConsoleCursorPosition(Handle, Cord);
				Letter = Letters[rand() % 27];
				printf(&Letter);
			}
		}
		Sleep(20);
		}
	}
	system("PAUSE");
	return 0;
}

