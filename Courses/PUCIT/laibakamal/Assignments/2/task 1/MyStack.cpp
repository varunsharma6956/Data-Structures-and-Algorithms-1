
//BSEF19M003
//LAIBA KAMAL

#include<iostream>
#include "MyStack.h"
using namespace std;

template <class T>//template class type specification
MyStack<T>::MyStack()//parameterized constructor : sets the data members of class to some specific values
{
	size = 200;
	top = -1;
	myStackArray = new T[size];//allocating dynamic memory for variables of type T
}



template <class T>//template class type specification
MyStack<T>::~MyStack()//destructor
{
	if (destruct == 1)
	{
		delete[]myStackArray;
	}
}



template <class T>//template class type specification
MyStack<T>::MyStack(int s)//parameterized constructor : sets the data members of class to some specific values
{
	size = s;
	top = -1;
	myStackArray = new T[size];//allocating dynamic memory for variables of type T
}



template <class T>//template class type specification
int MyStack<T>::getTop()//returns the last index of stack array
{
	return top;
}



template <class T>//template class type specification
void MyStack<T>::push(T value)//takes some value as its parameter and pushes the value on stack (puts it at the end of stack array)
{
	if (!isFull())
		myStackArray[++this->top] = value;
	else
	{
		this->resize();//resize function called
		myStackArray[++this->top] = value;
	}
}




template <class T>//template class type specification
T MyStack<T>::pop()//always returns last element of stack array and decrements top
{
	if (!isEmpty())
		return myStackArray[this->top--];
	else
	{
		if ((top + 1) <= (size / 4))//Likewise when there are less than 1/4 elements in the stack compared to the available capacity,
		{
			this->resize();//resize function called
			return myStackArray[this->top--];
		}
		else
			return myStackArray[this->top--];
	}
}



template <class T>//template class type specification
T MyStack<T>::peak()//always returns the last element of stack array
{
	return myStackArray[top];
}



template <class T>//template class type specification
void MyStack<T>::resize()//(maintains capacity of stack)   
{
	if ((top + 1) <= (size / 4))//Likewise when there are less than 1/4 elements in the stack compared to the available capacity,
	{
		size = size / 2;//it decreases the size it by 1/2 times
	}
	else if (isFull()) //if the stack is full,
	{
		size = size * 2;// increases the size by 2 times.
	}
	else
		size;
}


template <class T>//template class type specification
bool MyStack<T>::isEmpty()//returns true if stack is empty and false if not.
{
	return top == -1;
}


template <class T>//template class type specification
bool MyStack<T>::isFull()//returns true if stack is full and false if not.
{
	return top == size - 1;
}


template <class T>//template class type specification
void MyStack<T>::printStack()//prints the stack from open end to the close end
{
	for (int i = this->top; i >= 0; i--)
	{
		cout << myStackArray[i] << " ";
	}
}


//BSEF19M003
//LAIBA KAMAL





