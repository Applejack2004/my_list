#pragma once
#include "TList.h"

template <class T>
class THeadList:public TList<T>
{
protected:
	TNode<T>* Phead;
public:
	THeadList()
	{
		pHead = new TNode<T>;
		pHead->pNext = Phead;
		pStop = pFirst = pPr = pCurr = pLast = pHead;
		pos = -1;
		len = 0;

	}
	~THeadList()
	{
		TList<T>::DelList();
		delete pHead;
	}
	void InsFirst(const T& _val)
	{
		TList<T>::InsFirst(_val);
		pHead->pNext = pFirst;

		
	}
	void DelFirst()
	{
		TList<T>::DelFirst(_val);
		pHead->pNext = pFirst;

	}
};

