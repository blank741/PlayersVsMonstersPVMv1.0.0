//PVMv1.0.0头文件

#include <iostream>
#include <string>
#include <cstdio>
#include <conio.h>
#include <Windows.h>

using namespace std;

void cf5() { cout << endl; }	//换行并刷新缓冲区

void end() {
	cout << "感谢您对本游戏以及CG工作室的支持，再见！" << endl;
	cout << "按任意键关闭窗口。。。";
	char a;
	a = _getch();
	exit(0);
}	//退出时的输出以及结束

int all_start() {
	cout << endl;
	cout << "                 欢迎来到PVM！                             " << endl;
	cout << "           本游戏作者Ethan！由CG工作室出品！               " << endl;
	cout << "  适度游戏益脑，沉迷游戏伤身。认准正版游戏，抵制垃圾游戏！ " << endl;
	cout << "               CG工作室蒸蒸日上！                          " << endl;
	for (int i = 0; i < 5; i++) cf5();
	cout << "            1）登录  2）注册  3）退出                      " << endl;
	char key;
	key = _getch();
	if (key == '1') {
		system("cls");
		return 1;
	}
	if (key == '2') {
		system("cls");
		return 2;
	}
	if (key == '3') {
		system("cls");
		end();
		return 0;
	}
}	//刚启动时的登录界面输出

