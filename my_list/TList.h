#pragma once
#include <iostream>
#include <algorithm>
template <class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
	TNode() { pNext = nullptr;  }
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
	inline virtual void Reset()//переставляет pCurr на начало
	{
		pCurr = pFirst;
		pPr = pStop;
		pos = 0;

	}
	inline virtual void GoNext()// передвигает pCurr на следующий элемент
	{
		if (pCurr != pStop)
		{
			pPr = pCurr;
			pCurr = pCurr->pNext;
			pos++;

		}
		else
		{
			throw "This List is empty or current is not detected!";
		}
	}
	inline virtual bool IsEnd()//Проверка на тоЮ прошли ли до конца контейнера
	{
		return (pStop == pCurr);
	}
	virtual void DelList()//метод для очищения списка
	{
		TNode<T>* tmp;
		while (pFirst != pStop)
		{
			tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		len = 0;
		pos = -1;
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
		Reset();
	}
	inline void InsCurr(T _val)
	{
		if (len == 0)
		{
			InsFirst(_val);
		}
		else
		{
			if (pCurr == pFirst)
			{
				InsFirst(_val);
			}
			else
			{ 
			  if (pCurr == pStop && pPr == pLast)
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
		}
	}

 virtual void InsFirst(const T& _val)
	{
		if (pFirst == pStop)
		{
			TNode<T>* tmp = new TNode<T>;
			tmp->value = _val;
			tmp->pNext = pFirst;//////
			pFirst = tmp;
			pLast = tmp;
			len++;
		}
		else
		{
			TNode<T>* tmp = new TNode<T>;
			tmp->value = _val;
			tmp->pNext = pFirst;//////
			pFirst = tmp;
			len++;
		}
	
	}
	virtual T Get_pos_value(int ind)
	{
		if (ind >= len && ind < 0)
		{
			throw "Bad index";
		}
		Reset();
		
		while ( ind != pos)
		{
			GoNext();

		}
		return (pCurr->value);
	}
	inline virtual void InsLast(const T& _val)
	{
		if (pFirst == pStop)
		{
			InsFirst(_val);
		}
		else
		{
			TNode<T>* tmp = new TNode<T>;
			tmp->value = _val;
			pLast->pNext = tmp;
			pLast = tmp;
			tmp->pNext = pStop;
			len++;
		}
	}
	void Set_val(T item)
	{
		pCurr->value = item;
	}
	T Get_First()
	{
		return pFirst->value;
	}
	virtual  T GetCurrentItem()
	{
		if (pCurr == pStop)
		{
			throw "error";

		}
		return pCurr->value;
	}
	T Get_Last()
	{
		return pLast->value;
	}
	T Get_pos()
	{
		return pos;
	}
	T Get_length()
	{
		return len;
	}
	bool Is_Empty()
	{
		return (pFirst == pStop);
	}
	inline virtual void DelCurr()
	{
		if (pCurr == pFirst)
		{
			DelFirst();
		}
		else

		{
			if (pCurr == pLast)
			{
				TNode<T>* tmp = pCurr;
				pCurr = pCurr->pNext;
				pPr->pNext = pCurr;
				pLast = pPr;
				delete tmp;
				len--;

			}
			else
			{
				if (pCurr != pStop)
				{

					TNode<T>* tmp = pCurr;
					pCurr = pCurr->pNext;
					pPr->pNext = pCurr;
					delete tmp;
					len--;

				}
				else
				{
					throw "Error";
				}
			}
		}

	}
	 inline virtual void DelFirst()
	{
		if (pFirst != pStop)
		{
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			len--;
		}
		else
		{
			throw "This List is empty!";

		}
	}
	inline TList<T>& operator=(const TList<T>& list_object)
	{
		if (list_object.pFirst == nullptr)
		{
			DelList();
		}
		else
		{
			DelList();
			TNode<T>* tmp = list_object.pFirst, * curr;
			while (tmp != nullptr)
			{
				curr = new TNode<T>;
				curr->value = tmp->value;
				if (pFirst == nullptr)
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
			
			Reset();
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const TList<T>& list) {
		TList<T> copyList = list;
		copyList.Reset();

		while (!copyList.IsEnd()) 
		{
			T value = copyList.Get_pos_value(copyList.Get_pos());
			out << value << " ";
			copyList.GoNext();
		}

		return out;

	}
	friend std::istream& operator>>(std::istream& in, TList<T>& list) {
		T value;
		in >> value;
		list.InsCurr(value); // Предположим, что InsCurr добавляет элемент в текущую позицию списка
		return in;
	}

	inline void setPos(int _pos)
	{
		if (_pos < 0 || _pos >= len)
		{
			throw "В списке нет такой позиции!";
		}
        Reset();
		for (int i = 0; i < _pos; ++i)
		{
			GoNext();
		}
	}

};



