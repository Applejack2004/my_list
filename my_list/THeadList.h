#pragma once
#include "TList.h"


template <class T>
class THeadList:public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList()
	{
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pStop = pFirst = pPr = pCurr = pLast = pHead;
		pos = -1;
		len = 0;

	}	
	THeadList(const THeadList<T>& list_object)//Конструктор копирования
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
		pHead = new TNode<T>;
		pHead->pNext = pFirst;
		len = list_object.len;
		TList<T>::Reset();
	}
	inline THeadList<T>& operator=(const THeadList<T>& list_object)
	{
		if (list_object.pFirst == nullptr)
		{
			TList<T>::DelList();
		}
		else
		{
			TList<T>::DelList();
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
			pHead->pNext = pFirst;
			TList<T>::Reset();
		}
		return *this;
	}
	~THeadList()
	{
		TList<T>::DelList();
		delete pHead;
	}
	virtual void InsFirst (const T& _val)override
	{
		TList<T>::InsFirst(_val);
		pHead->pNext = pFirst;

		
	}
	virtual void DelFirst ()override
	{
		TList<T>::DelFirst();
		pHead->pNext = pFirst;

	}
};

