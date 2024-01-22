#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Student {
	string name;
	int age = 0;
	int course = 0;
	int marks[100];
	int marks_count = 0;
};
double get_mark(Student& s) {
	double dl = 0;
	for (int i = 0; i < s.marks_count; ++i) {
		dl += s.marks[i];
	}
	dl /= s.marks_count;
	return dl;
}
static vector<string> name_student;
void fillStudent(Student& s) {
	cout << endl;
	cout << "Введите имя: ";
	do {
		getline(cin, s.name);
		if (s.name[0] != '\0'){
			name_student.push_back(s.name);
		}
	} while (s.name[0] == '\0');
	cout << "Введите возраст: ";
	cin >> s.age;
	cout << "Введите количество оценок: ";
	cin >> s.marks_count;
	for (int i = 0; i < s.marks_count; ++i) {
		cout << "Введите оценок "<<i+1<<": ";
		cin >> s.marks[i];
	}
	cout << endl;
}
void printStudent(Student& s) {
	cout << endl;
	cout << "Имя: " << s.name<<endl;
	cout << "возраст: " << s.age<<endl;
	cout << "оценок " << s.marks_count<<endl;
	cout << "Оценки: ";
	for (int i = 0; i < s.marks_count; ++i) {
		cout << s.marks[i]<<" ";
	}
	cout << endl;
}
int main() {
	system("chcp 1251");
	int s_counter = 2;
	Student group[100];
	for (int i = 0; i < s_counter; ++i) {
		fillStudent(group[i]);
	}
	for (int i = 0; i < s_counter; ++i) {
		printStudent(group[i]);
	}
	cout << endl;
	for (int i = 0; i < s_counter; ++i) {
		cout << "Итоговая оценка у :\t"<<name_student[i]<<" ";
		cout << get_mark(group[i]) << "\n";
	}
	return 0;
}