#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	FILE *fileOp;
	fileOp = fopen("filework.txt", "r");
	if (fileOp == NULL)
		printf("Error");
	else {
		int numCech; 
		cout << "Enter the number of the desired workshop : ";
		cin >> numCech;
		char str[256];
		int i = 0;
		while (!feof(fileOp)) {
			fgets(str, 256, fileOp);
			if (str[strlen(str) - 2] == ' ') {
				if (str[strlen(str) - 1] == numCech) {
					cout << str;
				}
			}
			else {
				if (str[strlen(str) - 2] == numCech) {
					cout << str[strlen(str) - 2];

				}

			}
		}
		fclose(fileOp);
	}
	return 0;
}

