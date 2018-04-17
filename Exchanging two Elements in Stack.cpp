#include<stdio.h>
#include<iostream>
#define MAX_SIZE 101

using namespace std;
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
    
    void swap_ele(int &a, int &b)
    {
        StackArrayList m(N),n(N);//defining the two different stacks required to do the task
        int i,j;
        int temp1,temp2;
        int temp3,temp4;
        i = top;  j = a-1;
        
        while(i != a)//running the loop to move all the emelements before the rwquired element into a new stack m 
        {
            temp1 = pop();
            m.push(temp1);
            i--;
        }
        
        temp1 = pop();//contains the first element to be swapped
        
        while(j != b)//running the loop to move all the emelements between the given numbers i.e before the ssecong number into a new stack n 
        {
            temp2 = pop();
            n.push(temp2);
            j--;
        }
        
        temp2 = pop();//contains the second element to be swapped
        
        push(temp1);//pushing 1st element into the spot of 2nd element
        
        while(n.top != -1)//destacking the stack n to replace the numbers in the original order 
        {
            temp3 = n.pop();
            push(temp3);
        }
        
        push(temp2);//pushing 2nd element into the spot of 1st element
        
        while(m.top != -1)//destacking the stack m to replace the numbers in the original order 
        {
            temp4 = m.pop();
            push(temp4);
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
        cout<<"\n5. Swap Elements";
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
                cout<<"\nStack : ";//ginving user the fair idea of the current stage 
                d.display();
                
                int a,b;
                
                cout<<"\nEnter the two positions (a > b) : ";
                cin>>a>>b;
                
                a--;    b--;//the stack is starting technically from -, hence to give the same feature 
                
                d.swap_ele(a,b);
                
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
