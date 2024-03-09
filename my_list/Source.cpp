#include <iostream>
#include "TList.h"
#include "TPolinom.h"
#include "TMonom.h"
#include<vector>

TPolinom Polinomoperation(std::string& operation, std::vector<TPolinom>& polyVector)
{
	size_t pos = operation.find_first_of("+-*="); // Ищем позицию любого из символов "+", "-", "*", "="

	if (pos != std::string::npos && pos > 0 && pos < operation.size() - 1)
	{
		char operationChar = operation[pos]; // Получаем символ операции
		int index1;
		int index2;
		if (operation[pos + 1] == '=')
		{
			operationChar = '=';
			pos++;
			index1 = std::stoi(operation.substr(1, pos - 2)) - 1;
			index2 = std::stoi(operation.substr(pos + 1, operation.size())) - 1;
		}
		else
		{
			index1 = std::stoi(operation.substr(1, pos - 1)) - 1;
			index2 = std::stoi(operation.substr(pos + 1, operation.size())) - 1;

		}

		TPolinom result;
		// Извлекаем индексы из строки операции


		if (index1 >= 0 && index1 < polyVector.size() && index2 >= 0 && index2 < polyVector.size())
		{

			switch (operationChar)
			{

			case '+':
				//result = P1 + P2;
				return polyVector[index1] + polyVector[index2];
			case '-':
				//result = P1 - P2;
				return polyVector[index1] - polyVector[index2];
			case '*':
				//result = P1 * P2;
				return polyVector[index1] * polyVector[index2];
			case '=':
				//result = P1 += P2;
				return polyVector[index1] += polyVector[index2];
			default:
				std::cout << "Unsupported operation." << std::endl;
				//f = 1;
			}
		}
		else
		{
			std::cout << "Invalid polynomial index." << std::endl;
			//f = 1;
		}
	}
	else
	{
		std::cout << "Invalid operation format." << std::endl;
		//f = 1;
	}

	return TPolinom(); // Возвращаем пустой полином, если операция не выполнена успешно
}
int main()
{
	std::string a = "2x^1y^1z^1";
	std::string b = "3x^1y^1z^1";
	std::string ab = " 1*2";
	TPolinom p1(a),p2(b);
	//std::cout << p1;
	std::vector<TPolinom> V;
	V.push_back(p1);
	V.push_back(p2);
	V.push_back(p2);
	 TPolinom res=Polinomoperation(ab, V);
	std::cout<<res<<std::endl;
	std::cout<<V.size();

}
