#pragma once

//属于PVM的玩家类头文件
#include <iostream>
#include <string>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include <fstream>


using namespace std;

class Players {
private:
	int number;
	string num;
	string name;
	string password;
	long long money = 100;
public:
	const void SetMoney(long long money) {
		this->money = money;
	}
	const long long Money() const {
		return money;
	} //程序获取金币数量
	const string Name() {
		return name;
	} //程序获取昵称

	const string Password() const{
		return password;
	} //程序获取密码

	const string Num() const{
		return num;
	} //程序获取UID

	const void Register() {
		string UID, temp;
		ofstream outFile("UID.dll", ios_base::app); //打开UID文件，并将输出定义为outFile，并且追加写入
		ifstream file("UID.dll"); //打开UID文件，并将输入定义为file
		while (getline(file, temp)) {
			if (temp.size() == 1) break;
			else UID = temp;
		}
		for (int i = 9; i >= 0; i--) {
			if (UID[i] == '9') UID[i] = '0';
			else {
				UID[i]++;
				break;
			}
		}
		num = UID;
		outFile << num << endl;
		cout << "你的UID为：" << num << endl;
		file.close();
		outFile.close();
		cout << "按Enter键继续。。。";
		char z;
		x: z = _getch();
		if (z != '\r') goto x;
		string Password, a;
		const int maxLength = 16;
		int i;
		b:Password.clear();
		i = 0;
		system("cls");
		cout << "请输入密码（最少8位，最多16位）：";
		while (i < maxLength) {
			char ch = _getch();  // 使用_getch()读取字符，但不显示在屏幕上
			if (ch == '\r') {  // 如果按下回车键，则结束输入
				break;
			}
			else if (ch == '\b') {  // 如果按下退格键，则回退一个字符
				if (i > 0) {
					cout << "\b \b";  // 回退光标并覆盖之前的星号
					Password.pop_back();
					i--;
				}
			}
			else {
				Password += ch;
				cout << "*";
			}
			i++;
		}
		Password += '\0';
		a.clear();
		i = 0;
		cout << endl << "请确认密码：";
		while (i < maxLength) {
			char ch = _getch();  // 使用_getch()读取字符，但不显示在屏幕上
			if (ch == '\r') {  // 如果按下回车键，则结束输入
				break;
			}
			else if (ch == '\b') {  // 如果按下退格键，则回退一个字符
				if (i > 0) {
					cout << "\b \b";  // 回退光标并覆盖之前的星号
					a.pop_back();
					i--;
				}
				else continue;
			}
			else {
				a += ch;
				cout << "*";
			}
			i++;
		}
		a += '\0';
		if (a == Password) {
			password = Password; //赋值给密码
			Password.pop_back();
			ofstream out("PASSWORD.dll", ios::app);
			out << Password << endl;
			out.close();
		}
		else if (a.size() < 8) {
			system("cls"); //清屏
			cout << endl << "密码位数不足8位，请重新输入！" << endl;
			goto b; //为了方便，使用跳转
		}
		else {
			system("cls"); //清屏
			cout << endl << "确认密码错误，请重新输入！" << endl;
			goto b; //为了方便，使用跳转
		}
		system("cls");
		cout << "请输入昵称：";
		string Name;
		getline(cin, Name);
		name = Name;
		ofstream outfile("NAME.dll", ios_base::app); //打开名字文件，并将输出定义为outfile，并且追加写入
		outfile << name << endl;
		outfile.close();
		return;
	} //注册时获取玩家的密码和昵称，并保存

	const void Get(int i, int a) {
		if (i == 1) {
			int c = 0; //相当于一个bool值，用0来代表没有找到，用1来代表找到了
			string Num; //用户输入的UID
			cout << "请输入你的UID：";
			cin >> Num;
			ifstream file("UID.dll"); //打开UID文件，并将输入定义为file
			string line; //临时字符串，用来输入文件中的对应UID并与输入的UID进行比对
			int b = 0; //查找的次数，随后去密码文件中寻找对应的密码
			while (getline(file, line)) {
				b++; //次数加1
				if (line == Num) {
					num = line; //将num(UID)设置为找到的UID，方便在后续个人中心中使用
					c = 1;
					break;
				}
			}
			file.close(); //关闭文件
			if (c == 1) {
				system("cls");
				Get(2, b); //递归，获取输入的密码
			}
			else {
				system("cls");
				cout << "无此UID！请重新输入！" << endl;
				Get(1, 0); //递归，重新获取UID
			}
		}
		else if (i == 2) {
			number = a;
			string Password; //临时密码
			ifstream file("PASSWORD.dll"); //打开密码文件，并将输入定义为file
			string line;
			for (int i = 0; i < a; i++) {
				getline(file, line);
			}
			password = line;
			cout << "请输入密码：";
			while (true) {
				char ch = _getch();  // 使用_getch()读取字符，但不显示在屏幕上
				if (ch == '\r') {  // 如果按下回车键，则结束输入
					break;
				}
				else if (ch == '\b') {  // 如果按下退格键，则回退一个字符
					if (i > 0) {
						cout << "\b \b";  // 回退光标并覆盖之前的星号
						Password.pop_back();
					}
					else continue;
				}
				else {
					Password += ch;
					cout << "*";
				}
			}
			if (password == Password) return;
			else {
				system("cls");
				cout << "密码错误，请重新输入！" << endl;
				Get(2, a); //递归，重新输入密码
			}
		}
		string n;
		ifstream in("NAME.dll");
		for (int i = 0; i < number; i++) in >> n;
		name = n;
		return;
	}//登录时获取并比对输入的UID和密码
	const void save() {
		string a = "./saves/";
		a += num;
		a += ".dll";
		ofstream out(a);
		out << num << endl;
		out << password << endl;
		out << name << endl;
		out << money << endl;
		out.close();
	}
}; //玩家类