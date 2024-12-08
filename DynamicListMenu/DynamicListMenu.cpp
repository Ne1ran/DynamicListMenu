#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char delimiter = ' ';

struct FlashDrive
{
	string name;
	int capacity;
	int frequency;
	FlashDrive* next;
	FlashDrive* previous;

	FlashDrive(string name, int capacity, int frequency) : name(name), capacity(capacity), frequency(frequency), next(nullptr), previous(nullptr) {}
};

class DoubleLinkedArray {
private:
	FlashDrive* first;
	FlashDrive* last;

public:
	DoubleLinkedArray() : first(nullptr), last(nullptr) {} // Инициализация

	// Добавление элемента в список. Получаем на вход данные
	void append(string name, int capacity, int frequency) {
		FlashDrive* flashDrive = new FlashDrive(name, capacity, frequency); // Создаем структуру
		if (last) { // Если последний элемент есть, то добавляем новый как последний.
			last->next = flashDrive;
			flashDrive->previous = last;
			last = flashDrive;
		}
		else { // Если его нет, то первый=последний=добавленный, т.е. в массиве ничего не было.
			first = last = flashDrive;
		}
	}

	// Вывод всех элементов списка
	void display() {
		FlashDrive* current = first;
		while (current != nullptr) {
			std::cout << current->name << " " << current->capacity << " " << current->frequency << std::endl;
			current = current->next;
		}
	}

	bool hasAnyElement() {
		FlashDrive* firstElement = first;
		return firstElement != nullptr;
	}
};

DoubleLinkedArray flashArray;

// Да, я использую динамический массив в работе по созданию динамического массива.
// Это больше нужно для упрощения работы и возможности ввода разных данных, т.к. я не хочу хардкодить данные для ввода.
// Обычная реализация метода Split из более высокоуровневых языков (C#, Java)
std::vector<std::string> split(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	for (char ch : str) {
		if (ch == delimiter) {
			if (!token.empty()) {
				tokens.push_back(token);
				token.clear();
			}
		}
		else {
			token += ch;
		}
	}

	if (!token.empty()) {
		tokens.push_back(token);
	}

	return tokens;
}


void dataInput() {

	cout << " ___________________________________________________" << endl;
	cout << "|Введите данные для заполнения. Пример - Флеш 12 100|" << endl;
	cout << "|___________________________________________________|" << endl;
	cout << "|                     0 - выход                     |" << endl;
	cout << "|___________________________________________________|" << endl;

	while (true)
	{
		string command;
		getline(cin, command);

		if (command == "0") {
			break;
		}

		std::vector<std::string> words = split(command, delimiter);

		if (words.size() == 0) {
			continue;
		}

		if (words.size() < 3) {
			cout << "В введенной записи нет всех значений." << endl;
			continue;
		}

		try
		{
			string flashName = words[0];
			int flashCapacity = stoi(words[1]);
			int flashFrequency = stoi(words[2]);
			flashArray.append(flashName, flashCapacity, flashFrequency);
			cout << "Данные успешно введены. Ввод продолжается..." << endl;
		}
		catch (const std::exception&)
		{
			cout << "Ошибка при вводе данных." << endl;
		}
	}

	cout << "Операция ввода завершилась! Продолжаю считывать команды!" << endl;
}

void dataOutput() {
	if (!flashArray.hasAnyElement()) {
		cout << "Нет никаких элементов для вывода. Введите их." << endl;
		return;
	}

	flashArray.display();
}

void appendData() {

	cout << " _______________________________________________________" << endl;
	cout << "|Ожидаю данные о флеш-накопителе... Пример - Флеш 12 100|" << endl;
	cout << "|_______________________________________________________|" << endl;
	cout << "|                     0 - отмена                        |" << endl;
	cout << "|_______________________________________________________|" << endl;

	bool working = true;
	while (working) {
		string command;
		getline(cin, command);

		if (command == "0") {
			working = false;
			cout << "Выходим..." << endl;
			break;
		}

		std::vector<std::string> words = split(command, delimiter);

		if (words.size() == 0) {
			continue;
		}

		if (words.size() < 3) {
			cout << "В введенной записи нет всех значений." << endl;
			continue;
		}

		try
		{
			string flashName = words[0];
			int flashCapacity = stoi(words[1]);
			int flashFrequency = stoi(words[2]);
			flashArray.append(flashName, flashCapacity, flashFrequency);
			working = false;
			cout << "Данные введены. Напишите следующую команду для работы!" << endl;
		}
		catch (const std::exception&)
		{
			cout << "Ошибка при вводе данных." << endl;
		}
	}
}

void main() {
	setlocale(0, "Russian");

	cout << "Предметная область программы - 'Флэш-накопители'." << endl;

	cout << " ________________________________________________________" << endl;
	cout << "|Вас приветствует программа - мастер флешек              |" << endl;
	cout << "|________________________________________________________|" << endl;

	bool working = true;

	while (working)
	{
		cout << " ________________________________________________________" << endl;
		cout << "|0 - выход| 1 - ввод | 2 - вывод | 4 - добавление в конец|" << endl;
		cout << "|_________|__________|___________|_______________________|" << endl;

		char command;
		cin >> command;
		switch (command)
		{
		case '0': {
			working = false;
			break;
		}
		case '1': {
			dataInput();
			break;
		}
		case '2': {
			dataOutput();
			break;
		}
		case '4': {
			appendData();
			break;
		}
		default:
			cout << "Такой команды не существует!" << endl;
			break;
		}
	}

	cout << "Вы завершили работу!" << endl;
	system("pause");
}