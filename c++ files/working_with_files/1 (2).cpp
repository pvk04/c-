/*
Создать файл, содержащий сведения о сдаче студентами сессии. Структура записи: номер группы, фамилия студента, оценки по пяти экзаменам и пяти зачетам (зачет – незачет). 
На экран вывести:
фамилии неуспевающих студентов с указанием номера группы и количества задолженностей;
средний балл, полученный каждым студентом группы Х (вводится с клавиатуры), и всей группой в целом.
*/
#include <iostream>
#include <windows.h>
#include <fstream>
//#include <stdlib.h>
using namespace std;
int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

ifstream out("сессия.txt");
ifstream out1("сессия1.txt");

char buf[255];
int n,i,kolvo,debts,count_in_group = 0;
float GPA,overall_GPA = 0;
string line;
string groupX;
string check_input = "";
bool check = true;
struct student{
	char nGroup[3];
	char name[20];
	int arrGrade[5];
	string arrCredit[5];
};
struct student1{
	string nGroup;
	string surname;
	int arrGrade[5];
	string arrCredit[5];
};
// Использовать ли готовый файл?
cout << "Если хотите использовать готовые записи нажмите Y: ";
cin >> check_input;
if(check_input == "Y" or check_input == "y"){
	cout << "Вы используете готовый файл" << endl; 
	kolvo =10;	

}
else{
	
ofstream in ("сессия1.txt");
//Ввод числа записей
cout << "Введите кол-во записей: ";
cin >> kolvo;

student students[kolvo];

//Ввод студентов с помощью консоли

for (n=0; n<kolvo ; n++){
	cout << "Введите номер группы: " << endl;
	cin >> students[n].nGroup;
		
	cout << "Введите фамилию: "<< endl;
	cin >> students[n].name;
	
	cout << "Введите оценки по 5 экзаменам: "<< endl;
	for(i =0; i<5; i++){
		cin >> students[n].arrGrade[i];
	}
	cout << "Введите данные по 5 зачетам(true,false): " << endl;
	for(i =0; i<5; i++){
		cin >> students[n].arrCredit[i];
	}
	
	cout << "Запись введена"<< endl;	
}
// Запись студентов в файл
if (in.is_open())
    {
	for (n=0; n<kolvo ; n++){
		
		in << students[n].nGroup << endl;
		in << students[n].name << endl;
		for(i =0; i<5; i++){
			in <<  students[n].arrGrade[i] << endl;
		}
		for(i =0; i<5; i++){
			in <<students[n].arrCredit[i] << endl;
		}
	}
}
in.close();	

}
student1 students1[kolvo];

// Берём записи из файла
// Если выбрали готовый файл
if(check_input == "Y" or check_input == "y"){
	out1.close(); 
if (out.is_open())
{
	for (n=0; n<kolvo ; n++){
		getline(out, students1[n].nGroup);
		getline(out, students1[n].surname);
		for(i =0; i<5; i++){
			getline(out, line);
			strcpy(buf,line.c_str());
			students1[n].arrGrade[i] = atoi(buf);
		}
		for(i =0; i<5; i++){
			getline(out, students1[n].arrCredit[i]);
		}
	}
out.close(); 
}
}
// Если заполняли новый
else{
	out.close(); 
	if (out1.is_open())
{
	for (n=0; n<kolvo ; n++){
		getline(out1, students1[n].nGroup);
		getline(out1, students1[n].surname);
		for(i =0; i<5; i++){
			getline(out1, line);
			strcpy(buf,line.c_str());
			students1[n].arrGrade[i] = atoi(buf);
		}
		for(i =0; i<5; i++){
			getline(out1, students1[n].arrCredit[i]);
		}
	}
out1.close(); 
}
}


cout << "Задолжности" << endl;
for (n=0; n<kolvo ; n++){
	for(i=0; i<5;i++){
		if(students1[n].arrCredit[i] == "false"){
			debts+=1;
			check = false;
		}
	}
	if(debts>0){
		cout << "Имя: "<<students1[n].surname<< endl;
		cout << "Номер группы: "<<students1[n].nGroup <<endl;
		cout << "Кол-во задолжностей: " << debts << endl;
		debts = 0;
	}
}
if(check == true){
	cout << "Задолжностей нет" << endl;
}


cout << "\nСредний балл группы" << endl; 
cout << "Введите номер группы у которой хотите узнать средний балл: ";
cin >> groupX;
for (n=0; n<kolvo ; n++){
	if(students1[n].nGroup == groupX){
		GPA = 0;
		count_in_group+=1;
		for(i=0; i<5;i++){
			GPA+=students1[n].arrGrade[i];	
		}
		GPA = GPA/5;
		overall_GPA +=GPA;
		cout << "Средний балл студента " << students1[n].surname <<": "<< GPA << endl;
	}
}
if(overall_GPA >0){
	cout << "Средний балл группы " << groupX << ": "<< overall_GPA / count_in_group<<endl;
	overall_GPA = 0;
	count_in_group = 0;
}
else{
	cout << "О этой группе нет информации"<< endl;
}


return 0;
}


