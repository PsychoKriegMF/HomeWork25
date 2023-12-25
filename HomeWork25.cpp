#include <iostream>
#include <string>

template <typename T>
bool palindrom(T variable); 
template <typename T>
int search_char(T str);
std::string new_str(std::string str, char sym);



int main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251>null");
		
	std::cout << "\tЗадача 1.Строка из найденых символов.\n";
	std::string str;
	std::cout << "Введите текст ->";
	std::getline(std::cin, str);
	std::cout << "Введите символ который будем искать -> ";
	char sym;
	std::cin >> sym;
	std::string str1;
	for (int i = 0; i < str.length(); i++)
		if (sym == str[i])
			str1 += sym;
	std::cout <<"Новая строка из найденых совпадений: " << str1 << std::endl;	

	std::cout << "\n\tЗадача 2.Палиндром.\n";
	std::cin.ignore();
	std::string str2;
	std::cout << "Введите значение -> ";
	getline(std::cin, str2);
	palindrom(str2);
	if (palindrom(str2))
		std::cout << "Переменная " << str2 << " является палиндромом!";
	else
		std::cout << "Переменная " << str2 << " не является палиндромом!";
	std::cout << std::endl;
	
	std::cout << "\n\tЗадача 3.Подсчёт символов.\n";
	std::string str3;
	std::cout << "Введите строку -> ";
	getline(std::cin, str3);		
	std::cout << "В введенном тексте кол-во символов = " << search_char(str3) << std::endl;
	
	std::cout << "\n\tЗадача 4.Возврат подстроки.\n";
	char symbol;
	std::string str4;
	std::cout << "Введите строку -> ";
	getline(std::cin, str4);
	std::cout << "Введите символ с которого вернем строку -> ";
	std::cin >> symbol;
	std::cout << new_str(str4,symbol);
	
	
	return 0;
}

template <typename T>
bool palindrom(T variable) {
	std::string tmp = variable;
	bool answer = true;
	
	for (int i = 0; i < tmp.length(); i++) // единый регистр
		tmp[i] = std::tolower(tmp[i]);

	for (int i = 0; i < tmp.length() / 2; i++) // проверяем на полиндром
		if (tmp[i] != tmp[tmp.length() - i - 1])	
		answer = false;
	return answer;


}

template <typename T>
int search_char(T str) {
	int counter = 0;
	const int csym = 5;
	static const char sym[csym]{
		'!',
		'?',
		'.',
		' ',
		','
	};
	for (int i = 0; i < str.length(); i++)
		for(int j = 0; j < csym; j++ )
			if (str[i] == sym[j])	
				counter++;
	return counter;
}

std::string new_str(std::string str, char sym) {	
	for (int i = 0; i < str.length(); i++)
		if(str[i] == sym)
			return str.substr(str.rfind(sym));
	str.erase();
	return str;
}
