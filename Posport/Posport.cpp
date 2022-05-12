// Створіть клас Passport (паспорт), який буде містити паспортну інформацію про громадянина України.
//За допомогою механізму успадкування, реалізуйте клас ForeignPassport(закордонний паспорт) похідний від Passport.
//Нагадаємо, що закордонний паспорт містить крім  паспортних даних, також дані про візи, номер закордонного паспорта.
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Passport
{
protected:	
	string full_Name;//ПІБ
	string gender;//стать
	string dateOfIssue;//дата видачі
	string birthday;//дата народження
	string nationality;//громадянство
	int doc=0;//документ номер
	string record;//запис номер
	string dayOfExpiry;//дійссний до
	int authority=0;//орган що видав
	int RNTRC=0;//Реєстраційний номер облікової картки платника податків
	string placeOfBirth;//місце народженя	
public:
	Passport() {}//конструтор без параметрів

	void input() {//метод вводу
		cout << "Введіть ПІБ громадянина : " << endl;
		getline(cin, full_Name); 	
		cout << endl;

		cout << "Введіть стать : " << endl;
		getline(cin, gender); 
		cout << endl;

		cout << "Введіть дату видачі паспорта : " << endl;
		cin >> dateOfIssue; cin.ignore(100, '\n');//ігноруєм розрив рядка інакше наступна фраза не введеться а перекина далі
		cout << endl;

		cout << "Введіть дату закінчення терміу дії паспорта : " << endl;
		cin >> record; cin.ignore(100, '\n');//ігноруєм розрив рядка інакше наступна фраза не введеться а перекина далі
		cout << endl;

		cout << "Введіть дату народженя громадянина : " << endl;
		cin >> birthday; cin.ignore(100, '\n');//ігноруєм розрив рядка інакше наступна фраза не введеться а перекина далі
		cout << endl;

		cout << "Введіть громадянство : " << endl;
		getline(cin, nationality); 
		cout << endl;

		cout << "Введіть номер паспорта : " << endl;//вводяться числа
		cin >> doc;
		cout << endl;

		cout << "Введіть запис № : " << endl;
		cin >> record; cin.ignore(100, '\n');//ігноруєм розрив рядка інакше наступна фраза не введеться а перекина далі
		cout << endl;

		cout << "Введіть реєстраційний номер облікової картки платника податків : " << endl;//вводяться числа
		cin >> RNTRC;
		cout << endl;

		cout << "Введіть орган що видав :" << endl;//вводяться числа наприкла 09834
		cin >> authority; cin.ignore(32767, '\n');//використовуємо cin.ignore для видалення пробілу з пам'яті
		cout << endl;

		cout << "Введіть місце народження : " << endl;
		getline(cin, placeOfBirth);
		cout << endl;
	}
	void output() {//метод виводу
		cout << "ПІБ : " << full_Name << endl;
		cout << "Стать : " << gender << endl;
		cout << "Дата народження : " << birthday << endl;
		cout << "nationality : " << birthday << endl;
		cout << "Запис № : " << record << endl;
		cout << "Докумет № : " << doc << endl;
		cout << "Дійсний до : " << dayOfExpiry << endl;
		cout << "Дата видачі : " << dateOfIssue << endl;
		cout << "Орган що видав : " << authority << endl;
		cout << "РНОКПП : " << RNTRC << endl;
		cout << "Місце народження : " << placeOfBirth << endl;
	}

	~Passport(){}//деструктор
};

class ForeignPassport:public Passport
{
private: string visa;//данні візи
	   string countryCod;//код країни
public:
	ForeignPassport(){}//конструтор без параметрів

	void input() {//метод вводу
		Passport::input(); //викликаєм із класу паспорт метод вводу 
		cout << "Введіть дані про візу(-и) : "<< endl;
		getline(cin, visa); cout << endl;
		
		cout << "Введіть код країни : " << endl;
		getline(cin, countryCod); cout << endl;
	}
	void output() {//метод виводу
		Passport::output();//викликаєм із класу паспорт метод виводу
		cout << "Данні візи : " << visa << endl;
		cout << "Код країни : " << countryCod << endl;
	}

	~ForeignPassport(){}//деструктор
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введіть паспортні данні громадянина " << endl;
	ForeignPassport first;//створюєм обєкт класу закордонний паспорт .....
	first.input();
	first.output();
}