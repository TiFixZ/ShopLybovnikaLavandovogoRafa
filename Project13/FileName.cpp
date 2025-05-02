#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

#if defined(max)
#undef max
#endif

int usersize = 2;
int UserID = 0;
bool isadmin = false, isOpen = true;
std::string* LoginArr = new std::string[usersize]{ "Ava", "UserID1" };
std::string* PassArr = new std::string[usersize]{ "5671008600", "DefPass" };
double *sellsArr = new double[usersize] {0.0, 0.0};


int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
double* priceArr = new double[size];
int* countArr = new int[size];

int sizeCheck = 1;
double cashbox = 0;
double eIncome = 0;
double cashIncome = 0;
std::string* nameArrCheck = new std::string[sizeCheck];
double* priceArrCheck = new double[sizeCheck];
int* countArrCkeck = new int[sizeCheck];
double* totalArrCheck = new double[sizeCheck];

void Start();
bool Login();
void Getline(std::string &stringName);
void CreateStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
void RefillProduct();
void RemoveProduct();
void ChangePrice();
void ChangeStorage();
void Error();
void AddNewProduct();
void RenameProduct();
void DeleteProduct();
void ChangeStaff();
void ShowEmployee();
void AddNewEmployee();
void DeleteEmployee();
void EditEmployee();
void LybovnikLavandovogoRafa();
void Selling();
void IncreaseCheckArr();
void PrintCheck();
void ResetCheck();
void ShowIncome();
void IncreaseStorage();
bool Exit();

int GetID(int mode = 0);
bool IsNumber(std::string &number);

template<typename ArrType>
void FillArr(ArrType staticArr[], ArrType dynamicArr[]);

int main()
{
	Start(); 



	delete[] LoginArr;
	delete[] PassArr;
	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;
	delete[] sellsArr;
	delete[] nameArrCheck;
	delete[] priceArrCheck;
	delete[] countArrCkeck;
	return 0;
}

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	isOpen = true;
	std::cout << "\n\n\t\t\t TProd \n\n";
	std::cout << "Добро пожаловать, начинаю открытие смены!\n";
	Sleep(1000);
	system("cls");
	while (isOpen)
	{
		if (Login())
		{
			if (isadmin == true)
			{
				std::string choose;
				while (true)
				{
					std::cout << "1 - Использовать готовый склад\n2 - Создать свой склад\nВвод: ";
					Getline(choose);
					if (choose == "1")
					{
						CreateStorage();
						cashbox = rand() % 9499 + 16384;
						ShowAdminMenu();
						break;
					}
					else if (choose == "2")
					{
						LybovnikLavandovogoRafa();
						cashbox = rand() % 9499 + 16384;
						break;
					}
					else
					{
						std::system("cls");
						std::cout << "Ошибка ввода\n\n";
					}
				}
			}
			else
			{
				CreateStorage();
				ShowUserMenu();
			}
		}
		else
		{
			std::cerr << "Login Err\n";
		}
	}

	system("cls");
	std::cout << "Наличные в кассе: " << cashbox << "\n\nПрибыль за наличные: " << cashIncome << "\nПрибыль за безналичные: " << eIncome << "\n\nИтоговая прибыль за смену: " << cashIncome + eIncome << "\n\n\n";
	for (int i = 0; i < usersize; i++)
	{
		std::cout << "Продажи пользователя: " << LoginArr[i] << ": " << sellsArr[i] << "\n";
	}
	std::cout << "\n\n\n";
	system("pause");
	system("cls");
	std::cout << "\n\n\tСмена закрыта\n\n";
}

bool Login()
{
	std::string login, pass;
	
	while (true)
	{
		std::cout << "Введите логин: ";
		Getline(login);
		std::cout << "Введите пароль: ";
		Getline(pass);
		if (login == LoginArr[0] && pass == PassArr[0])
		{
			isadmin = true;
			UserID = 0;
			std::cout << "Пользователь: " << LoginArr[0] << " - Добро пожаловать!\nСтатус: Админ\n\n";
			return true;
		}
		
		for (int i = 1; i < usersize; i++)
		{
			if (login == LoginArr[i] && pass == PassArr[i])
			{
				isadmin = false;
				UserID = i;
				std::cout << "Пользователь: " << LoginArr[i] << " - Добро пожаловать!\nСтатус: Продавец\n\n";
				return true;
			}

		}
		std::system("cls");
		std::cout << "Неправильный Логин или Пароль\n";
	}
}

void Getline(std::string& stringName)
{
	getline(std::cin, stringName, '\n');
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::string name[staticSize]
	{
		"Монтаж видео (Базовый)", "Монтаж видео (Продвинутый)", "Монтаж видео (Максимальный)",
		"Motion Design (Базовый)", "Motion Design (Продвинутый)", "Motion Design (Максимальный)",
		"VFX Design (Базовый)", "VFX Design (Продвинутый)", "VFX Design (Максимальный)", "Полный набор"
	};
	double price[staticSize]{ 99.98, 299.98, 799.98, 199.98, 399.98, 999.98, 449.98, 1049.98, 2499.98, 4599.98 };
	int count[staticSize]{ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	FillArr(id, idArr);
	FillArr(name, nameArr);
	FillArr(count, countArr);
	FillArr(price, priceArr);

}

void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1) Начать продажу\n";
		std::cout << "2) Показать склад\n";
		std::cout << "3) Пополнить услуг\n";
		std::cout << "4) Списание услуг\n";
		std::cout << "5) Изменение цены\n";
		std::cout << "6) Изменение склада\n";
		std::cout << "7) Изменение персонала\n";
		std::cout << "8) Отчёт о прибыли\n";
		std::cout << "9) Контроль над скидками (Потом сделаю для себя)\n";
		std::cout << "0) Закрыть смену\n";
		std::cout << "Ввод: ";
		Getline(choose);
		if (choose == "1")
		{
			system("cls");
			Selling();
		}
		else if (choose == "2")
		{
			system("cls");
			ShowStorage();
		}
		else if (choose == "3")
		{
			system("cls");
			RefillProduct();
		}
		else if (choose == "4")
		{
			system("cls");
			RemoveProduct();
		}
		else if (choose == "5")
		{
			system("cls");
			ChangePrice();
		}
		else if (choose == "6")
		{
			system("cls");
			ChangeStorage();
		}
		else if (choose == "7")
		{
			system("cls");
			ChangeStaff();
		}
		else if (choose == "8")
		{
			system("cls");

		}
		else if (choose == "0")
		{
			system("cls");
			bool exit = Exit();
				if (Exit())
				{
					std::cout << "Выход\n";
					Sleep(500);
					system("cls");
					break;
				}
		}
		else
		{
			system("cls");
			std::cout << "\n\nОшибка ввода\n\n";
		}

	}
}

void ShowUserMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1) Начать продажу\n";
		std::cout << "2) Показать склад\n";
		std::cout << "3) Пополнить услуг\n";
		std::cout << "4) Списание услуг\n";
		std::cout << "5) Отчёт о прибыли\n";
		std::cout << "0) Закрыть смену\n";
		std::cout << "Ввод: ";
		Getline(choose);
		if (choose == "1")
		{
			system("cls");
			Selling();
		}
		else if (choose == "2")
		{
			system("cls");
			ShowStorage();
		}
		else if (choose == "3")
		{
			system("cls");
			RefillProduct();
		}
		else if (choose == "4")
		{
			system("cls");
			RemoveProduct();
		}
		else if (choose == "5")
		{
			system("cls");
			ShowIncome();
		}
		else if (choose == "0")
		{
			system("cls");
			bool exit = Exit();
			if (Exit())
			{
				std::cout << "Выход\n";
				Sleep(500);
				system("cls");
				break;
			}
		}
		else
		{
			system("cls");
			std::cout << "\n\nОшибка ввода\n\n";
		}

	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left <<  std::setw(25) << "Название услуги\t" << "\t" << "Цена(За минуту)\t" << "Кол-во(Минут)\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\t" << "\t    " << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название услуги\t" << "Цена(За минуту)\t" << "Доступно минут\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название услуги\t" << "Цена(За минуту)\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название услуги\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
}

void RefillProduct()
{
	std::string choose, chooseCount;
	int id = 0, count = 0;
	while (true)
	{
		system("cls");
		std::cout << "Пополнить услугу?\n1) Да\n2) Выход\nВвод: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			system("cls");
			while (true)
			{
				std::cout << "Введите кол-во минут для пополнения: ";
				Getline(chooseCount);
				system("cls");
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count >= 0 && count <= 50 && countArr[id - 1] < 50)
					{
						system("cls");
						countArr[id - 1] += count;
						std::cout << "Минут успешно пополнен\n";
						Sleep(800);
						system("cls");
						break;
					}
					else
					{
						std::cout << "\n\nНекорректное кол-во\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
			Sleep(1000);
		}
	}
}

void RemoveProduct()
{
	std::string choose, chooseCount;
	int id = 0, count = 0;
	while (true)
	{
		system("cls");
		std::cout << "Списать минут услуги?\n1) Да\n2) Выход\nВвод: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			system("cls");
			while (true)
			{
				std::cout << "Введите кол-во минут для списания: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count >= 0 && count <= countArr[id - 1])
					{
						system("cls");
						countArr[id - 1] -= count;
						std::cout << "Минуты успешно списан\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n\nНекорректное кол-во\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
			Sleep(1000);
		}
	}
}

void ChangePrice()
{
	std::string choose, choosePrice;
	int id = 0;
	double price = 0;
	while (true)
	{
		system("cls");
		std::cout << "Изменить цену?\n1) Да\n2) Выход\nВвод: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			ShowStorage(2);
			id = GetID();
			while (true)
			{
				system("cls");
				std::cout << "Введите новую цену: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price >= 0 && price <= 999999)
					{
						priceArr[id - 1] = price;
						std::cout << "Цена изменена\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n\nНекорректная цена\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
			Sleep(1000);
		}
	}
}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Добавить новую услугу\n2 - Редактировать название\n3 - Удалить услугу\n0 - Выход\nВвод: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			AddNewProduct();
		}
		else if (choose == "2")
		{
			RenameProduct();
		}
		else if (choose == "3")
		{
			if (size > 1)
			{
				DeleteProduct();
			}
			else
			{
				std::cout << "Остался последний товар! Удаление запрещено\n\n";
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			Error();
		}
	}
}

void Error()
{
	std::cout << "\n\nОшибка ввода\n\n";
}

void AddNewProduct()
{
	++size;

	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	double* priceArrTemp = new double[size];
	int* countArrTemp = new int[size];

	for (int i = 0; i < size - 1; i++)
	{
		idArrTemp[i] = idArr[i];
		nameArrTemp[i] = nameArr[i];
		priceArrTemp[i] = priceArr[i];
		countArrTemp[i] = countArr[i];
	}

	std::string choose;

	idArrTemp[size - 1] = size;

	while (true)
	{
		system("cls");
		std::cout << "Введите название нового товара: ";
		Getline(choose);
		if (choose.size() <= 20 && choose.size() >= 3)
		{
			nameArrTemp[size - 1] = choose;
			break;
		}
		else
		{
			std::cout << "Ошибка длинны названия\n";
			Sleep(1000);
		}
	}

	int count = 0;

	while (true)
	{
		system("cls");
		std::cout << "Введите кол-во минут нового товара: ";
		Getline(choose);
		if (IsNumber(choose))
		{
			count = std::stoi(choose);
			if (count >= 0 && count <= 50)
			{
				countArrTemp[size - 1] = count;
				std::cout << "Минут успешно пополнен\n";
				Sleep(800);
				break;
			}
			else
			{
				std::cout << "\n\nНекорректное кол-во   MAX = 50\n\n";
			}
		}
		else
		{
			Error();
			Sleep(1000);
		}
	}
	
	double price = 0;

	while (true)
	{
		system("cls");
		std::cout << "Введите цену новой услуги: ";
		Getline(choose);
		if (IsNumber(choose))
		{
			price = std::stod(choose);
			if (price >= 0 && price <= 999999)
			{
				priceArrTemp[size - 1] = price;
				std::cout << "Цена успешно установленна\n";
				Sleep(800);
				break;
			}
			else
			{
				std::cout << "\n\nНекорректная цена   MAX = 999999\n\n";
				Sleep(1000);
			}
		}
		else
		{
			Error();
			Sleep(1000);
		}
	}

	std::swap(idArr, idArrTemp);
	std::swap(nameArr, nameArrTemp);
	std::swap(priceArr, priceArrTemp);
	std::swap(countArr, countArrTemp);

	system("cls");

	std::cout << "ID\t" << std::left << std::setw(25) << "Название услуги\t" << "\t" << "Цена(За минуту)\t" << "Кол-во(Минут)\n";
	std::cout << idArr[size - 1] << "\t" << std::left << std::setw(25) << nameArr[size - 1] << "\t" << priceArr[size - 1] << "\t" << countArr[size - 1] << "\n";
	std::cout << "\n\n";

	system("pause");

	delete[] idArrTemp;
	delete[] nameArrTemp;
	delete[] priceArrTemp;
	delete[] countArrTemp;
}

void RenameProduct()
{
	std::string choose;
	int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);
		id = GetID();
		std::cout << "Введите новое название для услуги: ";
		Getline(choose);
		if (choose.size() <= 20 && choose.size() >= 3)
		{
			nameArr[id - 1] = choose;
			std::cout << "Название измененено\n\n";
			Sleep(1000);
			system("cls");
			break;
		}
		else
		{
			std::cout << "Ошибка длинны названия\n";
			Sleep(1000);
		}
	}
}

void DeleteProduct()
{
	system("cls");
	ShowStorage();
	int id = GetID();
	--size;

	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	double* priceArrTemp = new double[size];
	int* countArrTemp = new int[size];

	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = idArr[i];
	}

	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (j != id - 1)
		{
			nameArrTemp[i] = nameArr[j];
			priceArrTemp[i] = priceArr[j];
			countArrTemp[i] = countArr[j];
		}
		else
		{
			j++;
			nameArrTemp[i] = nameArr[j];
			priceArrTemp[i] = priceArr[j];
			countArrTemp[i] = countArr[j];
		}
	}

	system("cls");
	std::cout << "Услуга удалена\n";
	std::cout << "ID\t" << std::left << std::setw(25) << "Название услуги\t" << "\t" << "Цена(За минуту)\t" << "Кол-во(Минут)\n";
	std::cout << idArr[id - 1] << "\t" << std::left << std::setw(25) << nameArr[id - 1] << "\t" << priceArr[id - 1] << "\t" << "\t    " << countArr[id - 1] << "\n";
	std::cout << "\n\n";
	system("pause");

	std::swap(idArr, idArrTemp);
	std::swap(nameArr, nameArrTemp);
	std::swap(priceArr, priceArrTemp);
	std::swap(countArr, countArrTemp);



	delete[] idArrTemp;
	delete[] nameArrTemp;
	delete[] priceArrTemp;
	delete[] countArrTemp;
}

void ChangeStaff()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Посмотреть список сотрудников\n2 - Добавить нового сотрудника\n3 - Редактировать сотрудника\n4 - Уволить сотрудника\n0 - Выход\nВвод: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			ShowEmployee();
		}
		else if (choose == "2")
		{
			AddNewEmployee();
		}
		else if (choose == "3")
		{
			EditEmployee();
		}
		else if (choose == "4")
		{
			if (usersize > 2)
			{
				DeleteEmployee();
			}
			else
			{
				std::cout << "Остался последний сотрудник! Удаление запрещено\n\n";
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			Error();
		}
	}
}

void ShowEmployee()
{
	std::cout << "№\t" << std::left << std::setw(15) << "Логин сотрудника\t" << "\t" << "Пароль\t" << "Продажи\n";
	for (int i = 1; i < usersize; i++)
	{
		std::cout << i << "\t" << std::left << std::setw(25) << LoginArr[i] << "\t" << PassArr[i] << "\t" << "\t    " << sellsArr[i] << "\n";
	}
	std::cout << "\n\n";
}

void AddNewEmployee()
{
	++usersize;

	std::string* loginArrTemp = new std::string[usersize];
	std::string* passArrTemp = new std::string[usersize];
	double* sellsArrTemp = new double[usersize];

	for (int i = 0; i < usersize - 1; i++)
	{
		loginArrTemp[i] = LoginArr[i];
		passArrTemp[i] = PassArr[i];
		sellsArrTemp[i] = sellsArr[i];
	}

	std::string choose;

	sellsArrTemp[usersize - 1] = 0.0;

	while (true)
	{
		system("cls");
		std::cout << "Введите логин нового сотрудника: ";
		Getline(choose);
		if (choose.size() <= 20 && choose.size() >= 3)
		{
			loginArrTemp[usersize - 1] = choose;
			break;
		}
		else
		{
			std::cout << "Ошибка длинны названия\n";
			Sleep(1000);
		}
	}

	while (true)
	{
		system("cls");
		std::cout << "Введите пароль нового сотрудника: ";
		Getline(choose);
		if (choose.size() <= 20 && choose.size() >= 3)
		{
			passArrTemp[usersize - 1] = choose;
			break;
		}
		else
		{
			std::cout << "Ошибка длинны названия\n";
			Sleep(1000);
		}
	}

	std::swap(LoginArr, loginArrTemp);
	std::swap(PassArr, passArrTemp);
	std::swap(sellsArr, sellsArrTemp);

	system("cls");

	std::cout << "Сотрудник / пользователь уволен\n";
	std::cout << "№\t" << std::left << std::setw(15) << "Логин сотрудника\t" << "\t" << "Пароль\t\t" << "Продажи\n";
		std::cout << usersize << "\t" << std::left << std::setw(25) << LoginArr[usersize - 1] << "\t" << PassArr[usersize - 1] << "\t" << "\t    " << sellsArr[usersize - 1] << "\n";
	std::cout << "\n\n";

	system("pause");

	delete[] loginArrTemp;
	delete[] passArrTemp;
	delete[] sellsArrTemp;
}

void DeleteEmployee()
{
	system("cls");
	ShowEmployee();
	int id = GetID(1);
	--usersize;

	std::string* loginArrTemp = new std::string[usersize];
	std::string* passArrTemp = new std::string[usersize];
	double* sellsArrTemp = new double[usersize];

	for (int i = 1, j = 1; i < usersize; i++, j++)
	{
		if (j != id)
		{
			loginArrTemp[i] = LoginArr[j];
			passArrTemp[i] = PassArr[j];
			sellsArrTemp[i] = sellsArr[j];
		}
		else
		{
			j++;
			loginArrTemp[i] = LoginArr[j];
			passArrTemp[i] = PassArr[j];
			sellsArrTemp[i] = sellsArr[j];
		}
	}

	system("cls");
	std::cout << "Сотрудник / пользователь уволен\n";
	std::cout << "№\t" << std::left << std::setw(15) << "Логин сотрудника\t" << "\t" << "Пароль\t\t" << "Продажи\n";
	std::cout << id << "\t" << std::left << std::setw(25) << LoginArr[id] << "\t" << PassArr[id] << "\t" << "\t    " << sellsArr[id] << "\n";
	std::cout << "\n\n";
	system("pause");

	std::swap(loginArrTemp, LoginArr);
	std::swap(passArrTemp, PassArr);
	std::swap(sellsArrTemp, sellsArr);



	delete[] loginArrTemp;
	delete[] passArrTemp;
	delete[] sellsArrTemp;
}

void EditEmployee()
{
	std::string choose;
	ShowEmployee();
	int id = GetID(1);
	std::cout << "Выберите пункт для редактирования\n1 - Логин\n2 - Пароль\nВвод: ";
	Getline(choose);
	if (choose == "1")
	{
		while (true)
		{
			system("cls");
			std::cout << "Введите новый логин: ";
			Getline(choose);
			if (choose.size() <= 20 && choose.size() >= 3)
			{
				LoginArr[usersize - 1] = choose;
				std::cout << "Логин успешно изменён\n";
				Sleep(1000);
				break;
			}
			else
			{
				std::cout << "Ошибка длинны названия\n";
				Sleep(1000);
			}
		}
	}
	else if (choose == "2")
	{
		while (true)
		{
			system("cls");
			std::cout << "Введите новый пароль: ";
			Getline(choose);
			if (choose.size() <= 20 && choose.size() >= 3)
			{
				PassArr[usersize - 1] = choose;
				std::cout << "Пароль успешно изменён\n";
				Sleep(1000);
				break;
			}
			else
			{
				std::cout << "Ошибка длинны названия\n";
				Sleep(1000);
			}
		}
	}
	else
	{
		Error();
	}
}

void LybovnikLavandovogoRafa()
{
	system("cls");
	std::cout << "Создание склада для пиндосов и их любовников\n\n";

	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;

	size = 0;
	idArr = nullptr;
	nameArr = nullptr;
	priceArr = nullptr;
	countArr = nullptr;

	std::string choose;
	while (true)
	{
		if (idArr == nullptr)
		{
			idArr = new int[10];
			nameArr = new std::string[10];
			priceArr = new double[10];
			countArr = new int[10];
		}
		else if (size % 10 == 0)
		{
			IncreaseStorage();
		}

		system("cls");
		std::cout << "Текущее кол-во услуг: " << size << "\n\n";
		std::cout << "Добавить услугу?\n1 - Да\n2 - Нет, я любовник лавандового рафа\nВвод: ";
		Getline(choose);

		if (choose != "1")
			break;

		idArr[size] = size + 1;

		while (true)
		{
			system("cls");
			std::cout << "Введите название услуги (3-20 символов): ";
			Getline(nameArr[size]);
			if (nameArr[size].size() >= 3 && nameArr[size].size() <= 20)
				break;

			std::cout << "Ошибка длины названия\n";
			Sleep(1000);
		}

		std::string priceStr;
		while (true)
		{
			system("cls");
			std::cout << "Введите цену за минуту: ";
			Getline(priceStr);
			if (IsNumber(priceStr))
			{
				priceArr[size] = std::stod(priceStr);
				if (priceArr[size] >= 0 && priceArr[size] <= 999999)
					break;
			}
			std::cout << "Некорректная цена. !!!!!Ты любовник Лавандового Рафа!!!!!\n";
			Sleep(1000);
		}

		std::string countStr;
		while (true)
		{
			system("cls");
			std::cout << "Введите кол-во минут (1-50): ";
			Getline(countStr);
			if (IsNumber(countStr))
			{
				countArr[size] = std::stoi(countStr);
				if (countArr[size] >= 0 && countArr[size] <= 50)
					break;
			}
			std::cout << "Некорректное кол-во минут\n";
			Sleep(1000);
		}

		size++;

		system("cls");
		std::cout << "Услуга добавлена\n";
		ShowStorage();
		system("pause");
	}

	system("cls");
	std::cout << "Склад любовников готов!\n";
	ShowStorage();
	system("pause");
	ShowAdminMenu();
}

void Selling()
{
	std::string choose;
	int id = 0, count = 0;
	bool isFirst = true, isBuy = true, isSold = false;
	bool hasID1 = false;
	double totalSum = 0, cash = 0;
	ResetCheck();

	while (isBuy)
	{
		system("cls");
		ShowStorage();
		id = GetID();

		if (id == 1)
		{
			hasID1 = true;
		}

		if (hasID1)
		{
			totalSum *= 0.98;
		}

		while (true)
		{
			std::cout << "Введите кол-во минут услуги для покупки: ";
			Getline(choose);
			if (IsNumber(choose))
			{
				count = std::stoi(choose);
				if (count > countArr[id - 1] || count < 1)
				{
					std::cout << "\n\nНекорректное кол-во\n\n";
				}
				else
				{
					break;
				}
			}
			else
			{
				Error();
			}
		}

		if (isFirst)
		{
			nameArrCheck[sizeCheck - 1] = nameArr[id - 1];
			countArrCkeck[sizeCheck - 1] = count;
			priceArrCheck[sizeCheck - 1] = priceArr[id - 1];
			totalArrCheck[sizeCheck - 1] = count * priceArr[id - 1];
			countArr[id - 1] -= count;
			totalSum += count * priceArr[id - 1];
			isFirst = false;
		}
		else
		{
			IncreaseCheckArr();
			nameArrCheck[sizeCheck - 1] = nameArr[id - 1];
			countArrCkeck[sizeCheck - 1] = count;
			priceArrCheck[sizeCheck - 1] = priceArr[id - 1];
			totalArrCheck[sizeCheck - 1] = count * priceArr[id - 1];
			countArr[id - 1] -= count;
			totalSum += count * priceArr[id - 1];
		}

		while (true)
		{
			std::cout << "Купить ещё одну услугу?\n1 - Да\n2 - В попе дыра\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				break;
			}
			else if (choose == "2")
			{
				isBuy = false;
				break;
			}
			else
			{
				Error();
			}
		}
	}

	system("cls");
	PrintCheck();
	std::cout << "\t\t\t\t\tИтог к оплате: " << totalSum << "\n\n";

	std::cout << "Есть карта лояльности?\n1 - Да\n2 - Нет\nВвод: ";
	Getline(choose);

	if (choose == "1")
	{
		std::cout << "Введите код карты: ";
		Getline(choose);

		if (choose == "777ImSigma777")
		{
			std::cout << "\nКарта подтверждена! Вам скидка 5%\n";
			totalSum *= 0.95;
			Sleep(1000);
		}
		else if (choose == "FaritChtoZaLevEtoTigr")
		{
			std::cout << "\nКарта подтверждена! Вам скидка 99%\n";
			totalSum *= 0.01;
			Sleep(1000);
		}
		else
		{
			std::cout << "\nНеверный код карты. Скидка не предоставлена.\n";
			Sleep(1000);
		}
	}

	while (isSold == false)
	{
		system("cls");
		PrintCheck();
		std::cout << "\t\t\t\t\tИтог к оплате: " << totalSum << "\n\nВыберите способ оплаты\n1 - Наличные\n2 - Безналичные\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			while (true)
			{
				std::cout << "Введите кол-во наличных: ";
				Getline(choose);
				if (IsNumber(choose))
				{
					cash = std::stod(choose);
					if (cash <= 0 || cash < totalSum)
					{
						std::cout << "\n\nНищий\n\n";
					}
					else if (cash - totalSum < cashbox)
					{
						std::cout << "\n\nТеперь я нищий(\n\n";
					}
					else
					{
						std::cout << "Ваши " << cash << "\nОплата прошла успешно\nВаша сдача: " << cash - totalSum << "\n\n";
						cashbox += cash - (cash - totalSum);
						cashIncome += totalSum;
						sellsArr[UserID] += totalSum;
					}
					Sleep(1000);
					break;
				}
				else
				{
					Error();
					Sleep(1000);
				}
			}
			if (isSold)
			{
				break;
			}
		}
		else if (choose == "2")
		{
			while (true)
			{
				std::cout << "Пожалуйста, приложите свою карту\n\n";
				system("pause");
				if (rand() % 10 <= 2)
				{
					for (int i = 0; i < 5; i++)
					{
						std::cout << i + 1 << " ";
						Sleep(850);
					}
					std::cout << "\n\nОшибка соединения. Повторите попытку!\n\n";
					Sleep(1300);
					system("cls");
				}
				else
				{
					for (int i = 0; i < 5; i++)
					{
						std::cout << i + 1 << " ";
						Sleep(850);
					}
					std::cout << "Оплата прошла успешно!\n\n";
					eIncome += totalSum;
					sellsArr[UserID] += totalSum;
					break;
				}
			}
			break;
		}
		else
		{
			Error();
		}
	}
	Sleep(1500);
}

void IncreaseCheckArr()
{
	++sizeCheck;
	std::string* nameArrCheckTemp = new std::string[sizeCheck];
	double* priceArrCheckTemp = new double[sizeCheck];
	int* countArrCkeckTemp = new int[sizeCheck];
	double* totalArrCheckTemp = new double[sizeCheck];

	for (int i = 0; i < sizeCheck; i++)
	{
		nameArrCheckTemp[i] = nameArrCheck[i];
		priceArrCheckTemp[i] = priceArrCheck[i];
		countArrCkeckTemp[i] = countArrCkeck[i];
		totalArrCheckTemp[i] = totalArrCheck[i];
	}

	std::swap(nameArrCheck, nameArrCheckTemp);
	std::swap(priceArrCheck, priceArrCheckTemp);
	std::swap(countArrCkeck, countArrCkeckTemp);
	std::swap(totalArrCheck, totalArrCheckTemp);

	delete[] nameArrCheckTemp;
	delete[] priceArrCheckTemp;
	delete[] countArrCkeckTemp;
	delete[] totalArrCheckTemp;
}

void PrintCheck()
{
	std::cout << "№\t" << std::left << std::setw(25) << "Название услуги\t" << "\t" << "Цена(За минуту)\t" << "Кол-во(Минут)\t" << "Итого:\n";
	for (int i = 0; i < sizeCheck; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t" << priceArrCheck[i] << "\t" << "\t    " << countArrCkeck[i] << "\n" << totalArrCheck << "\n";
	}
	std::cout << "\n\n";
}

void ResetCheck()
{
	sizeCheck = 1;
	delete[] nameArrCheck;
	delete[] priceArrCheck;
	delete[] countArrCkeck;
	delete[] totalArrCheck;

	nameArrCheck = new std::string[sizeCheck];
	priceArrCheck = new double[sizeCheck];
	countArrCkeck = new int[sizeCheck];
	totalArrCheck = new double[sizeCheck];
}

void ShowIncome()
{
	system("cls");
	std::cout << "Наличные в кассе: " << cashbox << "\n\nПрибыль за наличные: " << cashIncome << "\nПрибыль за безналичные: " << eIncome << "\n\nИтоговая прибыль за смену: " << cashIncome + eIncome << "\nВаши продажи: " << sellsArr[UserID] << "\n\n\n";
	system("pause");
}

void IncreaseStorage()
{
	const int expandBy = 10;
	int* newIdArr = new int[size + expandBy];
	std::string* newNameArr = new std::string[size + expandBy];
	double* newPriceArr = new double[size + expandBy];
	int* newCountArr = new int[size + expandBy];

	for (int i = 0; i < size; ++i)
	{
		newIdArr[i] = idArr[i];
		newNameArr[i] = nameArr[i];
		newPriceArr[i] = priceArr[i];
		newCountArr[i] = countArr[i];
	}

	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;

	idArr = newIdArr;
	nameArr = newNameArr;
	priceArr = newPriceArr;
	countArr = newCountArr;
}

bool Exit()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Выход из аккаунта\n2 - Закрыть смену\n0 - Отмена\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			std::cout << "Спасибо за работу\n";
			return true;
		}
		else if (choose == "2")
		{
			system("cls");
			std::cout << "Введите пароль администратора для завершения смены: ";
			Getline(choose);
			if (choose == PassArr[0])
			{
				isOpen = false;
				Sleep(700);
				std::cout << "Успех\n";
				Sleep(700);
				return true;
			}
			else
			{
				Error();
				Sleep(700);
			}
		}
		else if (choose == "0")
		{
			std::cout << "Отмена выхода\n\n";
			Sleep(500);
			return false;
		}
		else
		{
			Error();
		}
	}
}

int GetID(int mode)
{
	std::string stringID;
	int result = 0; 
	int currentSize = 0;
	if (mode == 0)
	{
		currentSize = size;
	}
	else if (mode == 1)
	{
		currentSize = usersize;
	}

	while (true)
	{
		std::cout << "Введите ID: ";
		Getline(stringID);
		if (IsNumber(stringID))
		{
			result = std::stoi(stringID);
			if (currentSize == usersize && result <= 0)
			{
				std::cout << "Ошибка ввода ID\n\n";
				continue;
			}
			if (result > 0 && result <= currentSize)
			{
				return result;
			}
			else
			{
				std::cout << "\n\nОшибка ввода\n\n";
			}
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}

	}
}

bool IsNumber(std::string &number)
{
	if (number.size() <= 0 || number.size() >= 10)
	{
		return false;
	}
	for (int i = 0; i < number.size(); i++)
	{
		if (!std::isdigit((unsigned char)number[i]))
		{
			return false;
		}
	}
	return true;
}

template<typename ArrType>
void FillArr(ArrType staticArr[], ArrType dynamicArr[])
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
