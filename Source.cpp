//TEAM MEMBER :
//SAAD ASHRAF(21F - 9167)
//AHMAD SHAYAN(21F - 9135)
//ABDUL MUTAAL(21F - 9166)
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<string>
#include "TextEditor.h"
#include<cstring>
using namespace std;
int main(){
	system("color 7C");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t TEXT EDITOR WITH AUTOMATED SUGGESTIONS" << endl;
	Sleep(5000);
	cout << "\t\t\t";
	for (int s = 1; s < 5; s++) {
		Sleep(500);
		cout << ".................";
	}
	system("cls");
	system("color 7C");
	TextEditor TE("D.txt");
	TE.Editing();
	return 0;
}