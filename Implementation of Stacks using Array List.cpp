#include<stdio.h>
#include<iostream>
#define MAX_SIZE 101

using namespace std;

int A[MAX_SIZE]; // defininig the size of the A right from the start 
int top=-1;

void Push(int x) //the function for inserting a new value into the stack
{
	if(top == MAX_SIZE - 1 ) //checkcing if it is FULL or not
	{
		cout<<"ERROR";
	}
	A[++top] = x;
}

void Pop()//the function for deletion of a value ( top value ) from the stack 
{
	if(top == -1) //checkcing if it is EMPTY or not
	{
		cout<<"ERROR";
	}
	top--;
	return;
}

void print()// to check whether the above functions aare running or not and to display the stacka at that time
{
	int i;
	for(i=0;i<=top;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int Top()
{
	return A[top];
}

int main()
{
	Push(2);print();
	Push(5);print();
	Push(10);print();
	Pop();print();
	Push(13);print();
}
