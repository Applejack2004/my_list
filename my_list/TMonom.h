#pragma once
#include <iostream>
class TMonom
{
public:
	double Coef;
	int index;
	TMonom(double _coef, int _index)
	{
		Coef = _coef;
		index = _index;
	}
	// Оператор сравнения ==
	bool operator==(const TMonom& other) const {
		return (Coef == other.Coef && index == other.index);
	}
	// Оператор сравнения !=
	bool operator!=(const TMonom& other) const {
		return !(*this == other);
	}
	// Оператор сравнения <
	bool operator<(const TMonom& other) const {
		if (index < other.index)
		{
			return true;
		}
		else
		{
			if (index == other.index)
			{
				return Coef < other.Coef;
			}
			else
			{
				return false;
			}
		}
	}
	// Оператор сравнения >
	bool operator>(const TMonom& other) const {
		return !(*this < other);
	}

	// Оператор ввода
	friend std::istream& operator>>(std::istream& cin, TMonom& monom) {
		cin >> monom.Coef >> monom.index;
		return cin;
	}

	// Оператор вывода
	friend std::ostream& operator<<(std::ostream& cout, const TMonom& monom) {
		int degx = monom.index / 100;
		int degy = monom.index / 10;
		int degz = monom.index % 10;
		cout << monom.Coef << "*X^(" << degx << ")Y^(" << degy << ")Z^(" << degz << ")";
		return cout;
	}
};

