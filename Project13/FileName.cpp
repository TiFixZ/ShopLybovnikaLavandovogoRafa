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
bool isadmin = false;
std::string* LoginArr = new std::string[usersize]{ "a", "UserID1" };
std::string* PassArr = new std::string[usersize]{ "a", "DefPass" };
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

std::string* loyaltyCodes = nullptr;
double* loyaltyDiscounts = nullptr;
int sizeLoyalty = 0;

int* idDiscountsArr = nullptr;
double* idDiscountValues = nullptr;
int sizeIdDiscounts = 0;

std::string* loyaltyCardArr = nullptr;
double* loyaltyCardDiscountArr = nullptr;
int loyaltyCardArrSize = 0;

int* idDiscountArr = nullptr;
double* idDiscountPercentArr = nullptr;
int idDiscountArrSize = 0;

void Start();
bool Login();
void Getline(std::string &stringName);
void CreateStorage();
void ShowAdminMenu();
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
void LichnoYaSchitayChtoZaEtoNadoDatTOPCoini();

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
	std::cout << "\n\n\t\t\t TProd \n\n";
	if (Login())
	{
		if (isadmin == true)
		{
			std::string choose;
			while (true)
			{
				std::cout << "1 - ������������ ������� �����\n2 - ������� ���� �����\n����: ";
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
					std::cout << "������ �����\n\n";
				}
			}
		}
		else
		{
			CreateStorage();
		}
	}
	else
	{
		std::cerr << "Login Err\n";
	}
}

bool Login()
{
	std::string login, pass;
	
	while (true)
	{
		std::cout << "������� �����: ";
		Getline(login);
		std::cout << "������� ������: ";
		Getline(pass);
		if (login == LoginArr[0] && pass == PassArr[0])
		{
			isadmin = true;
			UserID = 0;
			std::cout << "������������: " << LoginArr[0] << " - ����� ����������!\n������: �����\n\n";
			return true;
		}
		
		for (int i = 1; i < usersize; i++)
		{
			if (login == LoginArr[i] && pass == PassArr[i])
			{
				isadmin = false;
				UserID = i;
				std::cout << "������������: " << LoginArr[i] << " - ����� ����������!\n������: ��������\n\n";
				return true;
			}

		}
		std::system("cls");
		std::cout << "������������ ����� ��� ������\n";
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
		"������ ����� (�������)", "������ ����� (�����������)", "������ ����� (������������)",
		"Motion Design (�������)", "Motion Design (�����������)", "Motion Design (������������)",
		"VFX Design (�������)", "VFX Design (�����������)", "VFX Design (������������)", "������ �����"
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
		std::cout << "1) ������ �������\n";
		std::cout << "2) �������� �����\n";
		std::cout << "3) ��������� �����\n";
		std::cout << "4) �������� �����\n";
		std::cout << "5) ��������� ����\n";
		std::cout << "6) ��������� ������\n";
		std::cout << "7) ��������� ���������\n";
		std::cout << "8) ����� � �������\n";
		std::cout << "9) �������� ��� ��������\n";
		std::cout << "0) ������� �����\n";
		std::cout << "����: ";
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
		else if (choose == "9")
		{
			system("cls");
			LichnoYaSchitayChtoZaEtoNadoDatTOPCoini();
		}
		else if (choose == "0")
		{
			system("cls");

		}
		else
		{
			system("cls");
			std::cout << "\n\n������ �����\n\n";
		}

	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left <<  std::setw(25) << "�������� ������\t" << "\t" << "����(�� ������)\t" << "���-��(�����)\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\t" << "\t    " << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t" << "����(�� ������)\t" << "�������� �����\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t" << "����(�� ������)\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t" << "\n";
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
		std::cout << "��������� ������?\n1) ��\n2) �����\n����: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			system("cls");
			while (true)
			{
				std::cout << "������� ���-�� ����� ��� ����������: ";
				Getline(chooseCount);
				system("cls");
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count >= 0 && count <= 50 && countArr[id - 1] < 50)
					{
						system("cls");
						countArr[id - 1] += count;
						std::cout << "����� ������� ��������\n";
						Sleep(800);
						system("cls");
						break;
					}
					else
					{
						std::cout << "\n\n������������ ���-��\n\n";
					}
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
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
		std::cout << "������� ����� ������?\n1) ��\n2) �����\n����: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			system("cls");
			while (true)
			{
				std::cout << "������� ���-�� ����� ��� ��������: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count >= 0 && count <= countArr[id - 1])
					{
						system("cls");
						countArr[id - 1] -= count;
						std::cout << "������ ������� ������\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n\n������������ ���-��\n\n";
					}
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
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
		std::cout << "�������� ����?\n1) ��\n2) �����\n����: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			ShowStorage(2);
			id = GetID();
			while (true)
			{
				system("cls");
				std::cout << "������� ����� ����: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price >= 0 && price <= 999999)
					{
						priceArr[id - 1] = price;
						std::cout << "���� ��������\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n\n������������ ����\n\n";
					}
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
			Sleep(1000);
		}
	}
}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - �������� ����� ������\n2 - ������������� ��������\n3 - ������� ������\n0 - �����\n����: ";
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
				std::cout << "������� ��������� �����! �������� ���������\n\n";
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
	std::cout << "\n\n������ �����\n\n";
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
		std::cout << "������� �������� ������ ������: ";
		Getline(choose);
		if (choose.size() <= 20 && choose.size() >= 3)
		{
			nameArrTemp[size - 1] = choose;
			break;
		}
		else
		{
			std::cout << "������ ������ ��������\n";
			Sleep(1000);
		}
	}

	int count = 0;

	while (true)
	{
		system("cls");
		std::cout << "������� ���-�� ����� ������ ������: ";
		Getline(choose);
		if (IsNumber(choose))
		{
			count = std::stoi(choose);
			if (count >= 0 && count <= 50)
			{
				countArrTemp[size - 1] = count;
				std::cout << "����� ������� ��������\n";
				Sleep(800);
				break;
			}
			else
			{
				std::cout << "\n\n������������ ���-��   MAX = 50\n\n";
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
		std::cout << "������� ���� ����� ������: ";
		Getline(choose);
		if (IsNumber(choose))
		{
			price = std::stod(choose);
			if (price >= 0 && price <= 999999)
			{
				priceArrTemp[size - 1] = price;
				std::cout << "���� ������� ������������\n";
				Sleep(800);
				break;
			}
			else
			{
				std::cout << "\n\n������������ ����   MAX = 999999\n\n";
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

	std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t" << "\t" << "����(�� ������)\t" << "���-��(�����)\n";
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
		std::cout << "������� ����� �������� ��� ������: ";
		Getline(choose);
		if (choose.size() <= 20 && choose.size() >= 3)
		{
			nameArr[id - 1] = choose;
			std::cout << "�������� ����������\n\n";
			Sleep(1000);
			system("cls");
			break;
		}
		else
		{
			std::cout << "������ ������ ��������\n";
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
	std::cout << "������ �������\n";
	std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t" << "\t" << "����(�� ������)\t" << "���-��(�����)\n";
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
		std::cout << "1 - ���������� ������ �����������\n2 - �������� ������ ����������\n3 - ������������� ����������\n4 - ������� ����������\n0 - �����\n����: ";
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
				std::cout << "������� ��������� ���������! �������� ���������\n\n";
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
	std::cout << "�\t" << std::left << std::setw(15) << "����� ����������\t" << "\t" << "������\t" << "�������\n";
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
		std::cout << "������� ����� ������ ����������: ";
		Getline(choose);
		if (choose.size() <= 20 && choose.size() >= 3)
		{
			loginArrTemp[usersize - 1] = choose;
			break;
		}
		else
		{
			std::cout << "������ ������ ��������\n";
			Sleep(1000);
		}
	}

	while (true)
	{
		system("cls");
		std::cout << "������� ������ ������ ����������: ";
		Getline(choose);
		if (choose.size() <= 20 && choose.size() >= 3)
		{
			passArrTemp[usersize - 1] = choose;
			break;
		}
		else
		{
			std::cout << "������ ������ ��������\n";
			Sleep(1000);
		}
	}

	std::swap(LoginArr, loginArrTemp);
	std::swap(PassArr, passArrTemp);
	std::swap(sellsArr, sellsArrTemp);

	system("cls");

	std::cout << "��������� / ������������ ������\n";
	std::cout << "�\t" << std::left << std::setw(15) << "����� ����������\t" << "\t" << "������\t\t" << "�������\n";
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
	std::cout << "��������� / ������������ ������\n";
	std::cout << "�\t" << std::left << std::setw(15) << "����� ����������\t" << "\t" << "������\t\t" << "�������\n";
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
	std::cout << "�������� ����� ��� ��������������\n1 - �����\n2 - ������\n����: ";
	Getline(choose);
	if (choose == "1")
	{
		while (true)
		{
			system("cls");
			std::cout << "������� ����� �����: ";
			Getline(choose);
			if (choose.size() <= 20 && choose.size() >= 3)
			{
				LoginArr[usersize - 1] = choose;
				std::cout << "����� ������� ������\n";
				Sleep(1000);
				break;
			}
			else
			{
				std::cout << "������ ������ ��������\n";
				Sleep(1000);
			}
		}
	}
	else if (choose == "2")
	{
		while (true)
		{
			system("cls");
			std::cout << "������� ����� ������: ";
			Getline(choose);
			if (choose.size() <= 20 && choose.size() >= 3)
			{
				PassArr[usersize - 1] = choose;
				std::cout << "������ ������� ������\n";
				Sleep(1000);
				break;
			}
			else
			{
				std::cout << "������ ������ ��������\n";
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
	std::cout << "�������� ������ ��� �������� � �� ����������\n\n";

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
		std::cout << "������� ���-�� �����: " << size << "\n\n";
		std::cout << "�������� ������?\n1 - ��\n2 - ���, � �������� ����������� ����\n����: ";
		Getline(choose);

		if (choose != "1")
			break;

		idArr[size] = size + 1;

		while (true)
		{
			system("cls");
			std::cout << "������� �������� ������ (3-20 ��������): ";
			Getline(nameArr[size]);
			if (nameArr[size].size() >= 3 && nameArr[size].size() <= 20)
				break;

			std::cout << "������ ����� ��������\n";
			Sleep(1000);
		}

		std::string priceStr;
		while (true)
		{
			system("cls");
			std::cout << "������� ���� �� ������: ";
			Getline(priceStr);
			if (IsNumber(priceStr))
			{
				priceArr[size] = std::stod(priceStr);
				if (priceArr[size] >= 0 && priceArr[size] <= 999999)
					break;
			}
			std::cout << "������������ ����. !!!!!�� �������� ����������� ����!!!!!\n";
			Sleep(1000);
		}

		std::string countStr;
		while (true)
		{
			system("cls");
			std::cout << "������� ���-�� ����� (1-50): ";
			Getline(countStr);
			if (IsNumber(countStr))
			{
				countArr[size] = std::stoi(countStr);
				if (countArr[size] >= 0 && countArr[size] <= 50)
					break;
			}
			std::cout << "������������ ���-�� �����\n";
			Sleep(1000);
		}

		size++;

		system("cls");
		std::cout << "������ ���������\n";
		ShowStorage();
		system("pause");
	}

	system("cls");
	std::cout << "����� ���������� �����!\n";
	ShowStorage();
	system("pause");
}

void Selling()
{
	std::string choose;
	int id = 0, count = 0;
	bool isFirst = true, isBuy = true, isSold = false;
	double totalSum = 0, cash = 0;
	bool idDiscountApplied[100] = {false};
	bool loyaltyDiscountApplied = false;

	ResetCheck();

	while (isBuy)
	{
		system("cls");
		ShowStorage();
		id = GetID();

		while (true)
		{
			std::cout << "������� ���-�� ����� ������ ��� �������: ";
			Getline(choose);
			if (IsNumber(choose))
			{
				count = std::stoi(choose);
				if (count > countArr[id - 1] || count < 1)
				{
					std::cout << "\n\n������������ ���-��\n\n";
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

		idDiscountApplied[id] = true;

		while (true)
		{
			std::cout << "������ ��� ���� ������?\n1 - ��\n2 - ���\n����: ";
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

	while (!isSold)
	{
		system("cls");
		PrintCheck();

		for (int i = 0; i < idDiscountArrSize; i++)
		{
			if (idDiscountApplied[idDiscountArr[i]])
			{
				std::cout << "������ �� ������� ������ � ID " << idDiscountArr[i] << ": -" << idDiscountPercentArr[i] * 100 << "%\n";
				totalSum *= (1.0 - idDiscountPercentArr[i]);
			}
		}

		std::cout << "\n\n���� ����� ����������?\n1 - ��\n2 - ���\n����: ";
		Getline(choose);

		if (choose == "1" && !loyaltyDiscountApplied)
		{
			std::cout << "������� ��� �����: ";
			Getline(choose);

			bool found = false;
			for (int i = 0; i < loyaltyCardArrSize; i++)
			{
				if (choose == loyaltyCardArr[i])
				{
					std::cout << "\n����� ������������! ��� ������ " << loyaltyCardDiscountArr[i] * 100 << "%\n";
					totalSum *= (1.0 - loyaltyCardDiscountArr[i]);
					loyaltyDiscountApplied = true;
					found = true;
					Sleep(1000);
					break;
				}
			}

			if (!found)
			{
				std::cout << "\n�������� ��� �����(\n";
				Sleep(1000);
			}
		}
		else if (choose == "1" && loyaltyDiscountApplied)
		{
			std::cout << "\n������ �� ����� ��� ���������!\n";
			Sleep(1000);
		}
		else
		{
			Error();
		}
		 
		std::cout << "\n\t\t\t\t\t���� � ������: " << totalSum << "\n\n�������� ������ ������\n1 - ��������\n2 - �����������\n����: ";
		Getline(choose);

		if (choose == "1")
		{
			while (true)
			{
				std::cout << "������� ����� ��������: ";
				Getline(choose);
				if (IsNumber(choose))
				{
					cash = std::stod(choose);
					if (cash < totalSum)
					{
						std::cout << "\n\n������������ �������!\n\n";
					}
					else
					{
						std::cout << "������ ������ �������\n���� �����: " << cash - totalSum << "\n\n";
						cashbox += totalSum;
						cashIncome += totalSum;
						sellsArr[UserID] += totalSum;
						isSold = true;
						Sleep(1000);
						break;
					}
				}
				else
				{
					Error();
					Sleep(1000);
				}
			}
		}
		else if (choose == "2")
		{
			while (true)
			{
				std::cout << "����������, ��������� �����\n\n";
				system("pause");
				if (rand() % 10 <= 2)
				{
					for (int i = 0; i < 5; i++)
					{
						std::cout << i + 1 << " ";
						Sleep(850);
					}
					std::cout << "\n\n������ ����������. ��������� �������!\n\n";
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
					std::cout << "������ ������ �������!\n\n";
					eIncome += totalSum;
					sellsArr[UserID] += totalSum;
					isSold = true;
					Sleep(1000);
					break;
				}
			}
		}
		else
		{
			Error();
		}
	}
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
	std::cout << "�\t" << std::left << std::setw(25) << "�������� ������\t" << "\t" << "����(�� ������)\t" << "���-��(�����)\t" << "�����:\n";
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
	std::cout << "�������� � �����: " << cashbox << "\n\n������� �� ��������: " << cashIncome << "\n������� �� �����������: " << eIncome << "\n\n�������� ������� �� �����: " << cashIncome + eIncome << "\n���� �������: " << sellsArr[UserID] << "\n\n\n";
	system("pause");
}

void IncreaseStorage()
{
	const int expandBy = 10; //������� �� ������������ ChatGPT
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

void InitDiscounts()
{
	loyaltyCodes = nullptr;
	loyaltyDiscounts = nullptr;
	sizeLoyalty = 0;

	idDiscountsArr = nullptr;
	idDiscountValues = nullptr;
	sizeIdDiscounts = 0;
}

void AddLoyaltyCard(std::string code, double discount)
{
	std::string* newCodes = new std::string[sizeLoyalty + 1];
	double* newDiscounts = new double[sizeLoyalty + 1];

	for (int i = 0; i < sizeLoyalty; i++)
	{
		newCodes[i] = loyaltyCodes[i];
		newDiscounts[i] = loyaltyDiscounts[i];
	}

	newCodes[loyaltyCardArrSize] = code;
	newDiscounts[sizeLoyalty] = discount;

	delete[] loyaltyCodes;
	delete[] loyaltyDiscounts;

	loyaltyCodes = newCodes;
	loyaltyDiscounts = newDiscounts;
	sizeLoyalty++;
}

void DeleteLoyaltyCard(std::string code)
{
	int index = -1;
	for (int i = 0; i < sizeLoyalty; i++)
	{
		if (loyaltyCodes[i] == code)
		{
			index = i;
			break;
		}
	}
	if (index == -1) return;

	std::string* newCodes = new std::string[sizeLoyalty - 1];
	double* newDiscounts = new double[sizeLoyalty - 1];

	for (int i = 0, j = 0; i < sizeLoyalty; i++)
	{
		if (i != index)
		{
			newCodes[j] = loyaltyCodes[i];
			newDiscounts[j] = loyaltyDiscounts[i];
			j++;
		}
	}

	delete[] loyaltyCodes;
	delete[] loyaltyDiscounts;

	loyaltyCodes = newCodes;
	loyaltyDiscounts = newDiscounts;
	sizeLoyalty--;
}

void EditLoyaltyCard(std::string oldCode, std::string newCode, double newDiscount)
{
	for (int i = 0; i < sizeLoyalty; i++)
	{
		if (loyaltyCodes[i] == oldCode)
		{
			loyaltyCodes[i] = newCode;
			loyaltyDiscounts[i] = newDiscount;
			return;
		}
	}
}

void AddIDDiscount(int id, double discount)
{
	int* newIds = new int[sizeIdDiscounts + 1];
	double* newDiscounts = new double[sizeIdDiscounts + 1];

	for (int i = 0; i < sizeIdDiscounts; i++)
	{
		newIds[i] = idDiscountsArr[i];
		newDiscounts[i] = idDiscountValues[i];
	}

	newIds[sizeIdDiscounts] = id;
	newDiscounts[sizeIdDiscounts] = discount;

	delete[] idDiscountsArr;
	delete[] idDiscountValues;

	idDiscountsArr = newIds;
	idDiscountValues = newDiscounts;
	sizeIdDiscounts++;
}

void DeleteIDDiscount(int id)
{
	int index = -1;
	for (int i = 0; i < sizeIdDiscounts; i++)
	{
		if (idDiscountsArr[i] == id)
		{
			index = i;
			break;
		}
	}
	if (index == -1) return;

	int* newIds = new int[sizeIdDiscounts - 1];
	double* newDiscounts = new double[sizeIdDiscounts - 1];

	for (int i = 0, j = 0; i < sizeIdDiscounts; i++)
	{
		if (i != index)
		{
			newIds[j] = idDiscountsArr[i];
			newDiscounts[j] = idDiscountValues[i];
			j++;
		}
	}

	delete[] idDiscountsArr;
	delete[] idDiscountValues;

	idDiscountsArr = newIds;
	idDiscountValues = newDiscounts;
	sizeIdDiscounts--;
}

void EditIDDiscount(int id, int newId, double newDiscount)
{
	for (int i = 0; i < sizeIdDiscounts; i++)
	{
		if (idDiscountsArr[i] == id)
		{
			idDiscountsArr[i] = newId;
			idDiscountValues[i] = newDiscount;
			return;
		}
	}
}

void LichnoYaSchitayChtoZaEtoNadoDatTOPCoini()
{
	std::string choose;

	while (true)
	{
		system("cls");
		std::cout << "I am a Lover of Lavender Rafa without a personal life\n";
		std::cout << "1 - �������� ����� ����������\n";
		std::cout << "2 - �������� ����� ����������\n";
		std::cout << "3 - ������� ����� ����������\n";
		std::cout << "4 - �������� ������ �� ID ������\n";
		std::cout << "5 - �������� ������ �� ID ������\n";
		std::cout << "6 - ������� ������ �� ID ������\n";
		std::cout << "7 - �����\n";
		std::cout << "��� �����: ";
		Getline(choose);

		if (choose == "1")
		{
			std::string code;
			std::string discStr;
			double discount = 0;
			std::cout << "������� ��� �����: ";
			Getline(code);
			std::cout << "������� ������ (0.05 ��� 5%): ";
			Getline(discStr);
			if (IsNumber(discStr))
			{
				discount = std::stod(discStr);
				AddLoyaltyCard(code, discount);
				std::cout << "\n����� ���������\n";
				Sleep(1000);
			}
			else
			{
				Error();
			}
		}
		else if (choose == "2")
		{
			std::string oldCode, newCode, discStr;
			double discount = 0;
			std::cout << "������� ������� ��� �����: ";
			Getline(oldCode);
			std::cout << "������� ����� ��� �����: ";
			Getline(newCode);
			std::cout << "������� ����� ������: ";
			Getline(discStr);
			if (IsNumber(discStr))
			{
				discount = std::stod(discStr);
				EditLoyaltyCard(oldCode, newCode, discount);
				std::cout << "\n����� ��������\n";
				Sleep(1000);
			}
			else
			{
				Error();
			}
		}
		else if (choose == "3")
		{
			std::string code;
			std::cout << "������� ��� ����� ��� ��������: ";
			Getline(code);
			DeleteLoyaltyCard(code);
			std::cout << "\n����� �������!\n";
			Sleep(1000);
		}
		else if (choose == "4")
		{
			std::string idStr, discStr;
			int id = 0;
			double discount = 0;
			ShowStorage();
			std::cout << "������� ID ������: ";
			Getline(idStr);
			std::cout << "������� ������ (0.02 ��� 2%): ";
			Getline(discStr);
			if (IsNumber(idStr) && IsNumber(discStr))
			{
				id = std::stoi(idStr);
				discount = std::stod(discStr);
				AddIDDiscount(id, discount);
				std::cout << "\n������ ���������!\n";
				Sleep(1000);
			}
			else
			{
				Error();
			}
		}
		else if (choose == "5")
		{
			std::string idStr, newIdStr, discStr;
			int id = 0, newId = 0;
			double discount = 0;
			std::cout << "������� ������� ID ������: ";
			Getline(idStr);
			std::cout << "������� ����� ID ������: ";
			ShowStorage();
			Getline(newIdStr);
			std::cout << "������� ����� ������: ";
			Getline(discStr);
			if (IsNumber(idStr) && IsNumber(newIdStr) && IsNumber(discStr))
			{
				id = std::stoi(idStr);
				newId = std::stoi(newIdStr);
				discount = std::stod(discStr);
				EditIDDiscount(id, newId, discount);
				std::cout << "\n������ ��������!\n";
				Sleep(1000);
			}
			else
			{
				Error();
			}
		}
		else if (choose == "6")
		{
			std::string idStr;
			int id = 0;
			std::cout << "������� ID ������ ��� �������� ������: ";
			Getline(idStr);
			if (IsNumber(idStr))
			{
				id = std::stoi(idStr);
				DeleteIDDiscount(id);
				std::cout << "\n������ �������!\n";
				Sleep(1000);
			}
			else
			{
				Error();
			}
		}
		else if (choose == "7")
		{
			break;
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
		std::cout << "������� ID: ";
		Getline(stringID);
		if (IsNumber(stringID))
		{
			result = std::stoi(stringID);
			if (currentSize == usersize && result <= 0)
			{
				std::cout << "������ ����� ID\n\n";
				continue;
			}
			if (result > 0 && result <= currentSize)
			{
				return result;
			}
			else
			{
				std::cout << "\n\n������ �����\n\n";
			}
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
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
