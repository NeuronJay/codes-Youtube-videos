#include<stdio.h>
#include<iostream>
#define MAX_SIZE 101

using namespace std;

int A[MAX_SIZE]; // defininig the size of the A right from the start 
int top=-1;

class StackArrayList
{
    int *arr;
    int top;
    int N;
	public:
		
    StackArrayList(int size)
    {
        arr = new int [size];
        top = -1;
        N = size;
    }

    void push(int &D)//the function for inserting a new value into the stack
    {
    	
		 	if(top == -1)
	        {
	            top = 0;
	            arr[top] = D;
	        }
	        else
	        {
	            top++;
	            arr[top] = D;
	        }
		
        
    }
    
    int pop()//the function for deletion of a value ( top value ) from the stack 
    {
        if(top == -1) //checkcing if it is EMPTY or not
        {
            cout<<"\nDeletion Not possible";
        }
        else
        {
            int i;
            i = arr[top];
            arr[top] = NULL;
            top--;
            return i;
        }
    }
    
    void clear()
    {
        for( ;top != -1; )
        {
            pop();
        }
    }
    
    void display()// to check whether the above functions aare running or not and to display the stacka at that time
    {
        int i;
        for(i=0;i <= top;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    
    void reverse_cont()
    {
        StackArrayList a1(N);StackArrayList a2(N); //the required stacks 
        int temp1,temp2;//necessary variables needed to handle data 
        int m;
        
        temp1 = pop();
        a1.push(temp1);
        
        while(top != -1)
        {
            temp2 = pop();
            if(temp2 == temp1 - 1)
            {
                a1.push(temp2);
                temp1 = temp2;
            }
            else
            {
                push(temp2);
                while(a1.top != -1)
                {
                    m = a1.pop();
                    a2.push(m);
                    //i--;
                }
                
                temp1 = pop();
                a1.push(temp1);
            }
        }
        while(a1.top != -1)
        {
            m = a1.pop();
            a2.push(m);
        }
        
        while(a2.top != -1)
        {
            m = a2.pop();
            push(m);
        }
    }
};

int main()
{
    cout<<"Enter the Size of Stack : ";
    int siz;cin>>siz;
    
    StackArrayList d(siz);//initializing the stack here
    
    int chk = 0;
    int choice,da,M;
    
    while(1)
    {
        cout<<"\n1. Push";
        cout<<"\n2. Pop";
        cout<<"\n3. Clear";
        cout<<"\n4. Display";
        cout<<"\n5. Reverse the Cont";
        cout<<"\n\nWhat's your choice : ";
        cin>>choice;
        
        switch(choice)//runnign a corresponding swithc case to run the needed function
        {
        	
        case 1:
            {
                if(chk == siz)//checkcing if it is FULL or not
                {
                    cout<<"\nStack is FULL";
                }
                else
                {
                    cout<<"\nEnter the Value : ";
                    cin>>da;
                    
                    d.push(da);//pushing the value data into the stack at the top as required 
                    
                    cout<<"\nElement inserted";//confirmation message 
                    chk++;//keeping track of the top level
                }
                break;
            }
            
        case 2:
            {
                chk--;
                int c = d.pop();
                break;
            }
            
        case 3:
            {
                d.clear();
                cout<<"\nList Cleared";
                break;
            }
            
        case 4:
            {
                cout<<"\nStack : ";
                d.display();
                break;
            }
            
        case 5:
            {
                d.reverse_cont();
                break;
            }
        default:
            {
                cout<<"\nEnter 0 to exit or 1 to continue : ";
                cin>>M;
                if(M == 0)
                {
                    exit(0);
                }
            }
        }
    }
    return 0;
}
