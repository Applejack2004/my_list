#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string> 

class TPolinom:public THeadList<TMonom>
{
public:
	TPolinom() :THeadList<TMonom>::THeadList()
	{
		TMonom monom(1,0);
		pHead->value = monom;

	}
	TPolinom(int monoms[][2], int km)
	{
		TMonom  pMonom (0, -1);
		pHead->value=pMonom;
		for (int i = 0; i < km; i++)
		{
			TMonom monom((double)monoms[i][0], monoms[i][1]);
			InsLast(monom);
		}
	}
	TPolinom(TPolinom& q)
	{
		TMonom h(0, -1);
		pHead->value = h;
		for (q.Reset(); !q.IsEnd(); q.GoNext())
		{
			TMonom monom = q.GetCurrentItem();
			InsLast(monom); 
		}
	}
	TPolinom& operator =(TPolinom& q)
	{
		DelList();
		TMonom h(0, -1);
		pHead->value = h;
		for (q.Reset(); !q.IsEnd(); q.GoNext())
		{
			TMonom monom = q.GetCurrentItem();
			InsLast(monom);
		}
		return *this;
	}
	void AddMonom(TMonom& m)
	{
		Reset();
		while (m < pCurr->value)
		{
			GoNext();

		}
		if (pCurr->value == m)
		{
			pCurr->value.Coef += m.Coef;
			if (pCurr->value.Coef == 0)
			{
				DelCurr();

			}
		}
		else
		{
			InsCurr(m);
		}
	}
	TPolinom operator+(TPolinom& q)
	{
		TPolinom result(q);
		Reset(); result.Reset();

		while (!IsEnd())
		{
			if (result.pCurr->value > pCurr->value)
			{
				result.GoNext();
			}
			else if (result.pCurr->value < pCurr->value)
			{
				result.InsCurr(pCurr->value);
				GoNext();
			}
			else
			{
				result.pCurr->value.Coef += pCurr->value.Coef;
				if (result.pCurr->value.Coef == 0)
				{
					result.DelCurr();
					GoNext();
				}
				else
				{
					result.GoNext();
					GoNext();
				}
			}
		}
		return result;
	}
	TPolinom operator*(double coef)
	{
		TPolinom result(*this);
		for (result.Reset(); !result.IsEnd(); result.GoNext())
		{
			TMonom currmonom = GetCurrentItem();
			currmonom.Coef *= coef;
			result.Set_val(currmonom);
		}
	}
	TPolinom operator-(TPolinom& q)
	{
		TPolinom result(q);
		result = result * (-1);
		result = (*this) + result;
		return result;
	}
	TPolinom(std::string str)
	{
		int i = 0;
		while (i < str.length())
		{
			if (str[i] == ' ' || str[i] == '+')
			{
				continue;
			}
			std::string coef;
			for (; std::isdigit(str[i]) || str[i] == ' ' || str[i] == ',' || str[i] == '-'; i++)
			{
				if (str[i] == ' ') continue;
				coef.push_back(str[i]);
			}
			std::string degx;
			if (str[i] == 'x')
			{
				i += 2;
				while (isdigit(str[i]))
				{
					degx.push_back(str[i]);
					i++;
				}
			}
			std::string degy;
			if (str[i] == 'y')
			{
				i += 2;
				while (isdigit(str[i]))
				{
					degy.push_back(str[i]);
					i++;
				}
			}
			std::string degz;
			if (str[i] == 'z')
			{
				i += 2;
				while (isdigit(str[i]))
				{
					degz.push_back(str[i]);
					i++;
				}
			}
			double _coef = 1;
			int deg = 0;
			std::string degpolinom;
			if (!coef.empty())
			{
				_coef = std::stod(coef);
			}
			else
			{
				throw "Error:Bad polinom!";
			}
			if ((!degx.empty()) && (!degy.empty()) && (!degz.empty()))
			{
				degpolinom = degx + degy + degz;
				deg = std::stoi(degpolinom);
				AddMonom(TMonom(_coef, deg));
			}
		}

	}
	TPolinom MultMonom(TMonom monom)
	{
		TPolinom result;
		for (Reset(); !IsEnd(); GoNext())
		{
			TMonom res = GetCurrentItem();
			res.Coef *= monom.Coef;
			int degx = (res.index / 100) + (monom.index / 100);
			int degy = (res.index / 10)+(monom.index / 10);
			int degz =(res.index % 10)+(monom.index % 10);
			if (degx > 9 || degy > 9 || degz > 9)
			{
				throw " we cant multiply plynoms with deg>9!!!";
			}
			else
			{
				res.index = degx * 100 + degy * 10 + degz;
			}
			result.AddMonom(res);
			
		}
		return result;

	}
	TPolinom operator*(TPolinom& q)
	{
		TPolinom result;
		for (q.Reset(); !q.IsEnd(); q.GoNext())
		{
			result = result + MultMonom(q.GetCurrentItem());
		}
		return result;
	}
	bool Monom_compare( TMonom& monom2)
	{
		return (GetCurrentItem() > monom2);
	}
	//void sortpolinome()
	//{
	//	if 
	//
	//}
};

