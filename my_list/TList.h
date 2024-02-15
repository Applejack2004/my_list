#pragma once
#include <iostream>
#include <algorithm>
template <class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; }
};
template <class T>
class TList
{
protected:
	TNode<T>* pFirst, * pLast, * pStop, * pCurr, * pPr;
	int pos, len;
public:
	TList()
	{
		pFirst = nullptr; pLast = nullptr; pStop = nullptr; pCurr = nullptr; pPr = nullptr;
		pos = -1;
		len = 0;
	}; //Конструктор по умолчанию
	void Reset()//переставляет pCurr на начало
	{
		pCurr = pFirst;
		pPr = pStop;
		pos = 0;

	}
	void GoNext()// передвигает pCurr на следующий элемент
	{
		if (pCurr != pStop)
		{
			pPr = pCurr;
			pCurr = pCurr->pNext;
			pos++;

		}
		else
		{
			std::throw "Error,List is empty.";
		}
	}
	bool IsEnd()//Проверка на тоЮ прошли ли до конца контейнера
	{
		return (pStop == pCurr);
	}
	void DelList()//метод для очищения списка
	{
		TNode<T>* tmp;
		while (pFirst != pStop)
		{
			tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	~TList() { DelList(); }; //Деструктор
	TList(const TList<T>& list_object)//Конструктор копирования
	{
		TNode<T>* tmp = list_object.pFirst, * curr;

		while (tmp != list_object.pStop)
		{
			curr = new TNode<T>;
			curr->value = tmp->value;
			if (pFirst == pStop)
			{
				pFirst = curr;
				pLast = curr;
			}
			else
			{
				pLast->pNext = curr;
				pLast = curr;
			}

			tmp = tmp->pNext;
		}
		len = list_object.len;
		pCurr = pFirst;
		pPr = pStop;
	}
	void InsCurr(T _val)
	{
		if (len == 0)
		{
			InsFirst(_val);
		}
		if (pCurr == pFirst)
		{
			InsFirst(_val);
		}
		if (pCurr == pStop && pPr = pLast)
		{
			InsLast(_val);

		}
		else
		{

			TNode<T>* tmp = new TNode<T>;
			tmp->value = _val;
			pPr->pNext = tmp;
			tmp->pNext = pCurr;
			pPr = tmp;
			len++;
			pos++;
		}
	}

	void InsFirst(const T& _val)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->value = _val;
		tmp->pNext = pFirst;//////
		pFirst = tmp;
	}

};


