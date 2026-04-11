#include<iostream>
#include<string>
using namespace std;
class Node
{
    public :
    int data;
    Node*next;
};
class stack
{  
    public :
     Node* top = NULL;
    void push(char ch)
    {
     Node *newnode ;
     newnode->data = ch;
     newnode->next = top;
     top = newnode;
    }
    char pop()
    {
        Node *newnode = top;
        top = newnode->next;
        char temp = newnode->data;
        delete newnode;
        return temp;
        }
 bool isempty()
 {
    if(top == NULL)
    {
        return 1;
    }
    else
    return 0;
 }
};
class expression
{   public :
    string infix ;
    string postfix = "";
    string prefix = "";
    stack st;
    bool isoperator(char ch)
    {
        if(ch == '*' || ch == '/' || ch  == '-' || ch == '+' || ch == '^')
        {
         return true;
        }
        else 
        return false;
    }
   bool privority(char ch)
   {
    if(ch == '^')
    {
        return 3;
    }
    if(ch == '*' || ch== '/' )
     {
        return 2;
     }
     if(ch == '+' || ch == '-')
     {
        return 1;
     }
     else
     {
        return -1;
     }
   }
   void infixtopost(string infix)
   {
    for(int i = 0;i < infix.length();i++)
    {
        if(infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i]<'Z')
        {
            postfix+=infix[i];
        }
        else if(infix[i] == '(')
        {
          st.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
           while(!st.isempty() && st.top->data != '(')
           {
            postfix+=st.pop();
           }
           if(st.top->data == '(')
           {
            st.pop();
           }
        }
        else if(isoperator(infix[i]))
        {   if(st.isempty())
           {
            st.push(infix[i]);
           }
           else
           {  
            if(privority(infix[i]) >=privority(st.top->data))
            {
              st.push(infix[i]);
            }
            else
            {
                while(privority(infix[i]) < privority(st.top->data))
                {
                    postfix+=st.pop();
                }
                st.push(infix[i]);
            }
        }
     }
     }
   }
   bool ischar(char ch)
   {
    if(ch >= 'a' && ch <= 'z' )
    {
        return true;
    }
    else
   { return false;}
   }
    bool isnum(char ch)
    {
        if(ch >= '0'&& ch <= '9')
        {
            return true;
        }
        else
       {
       return false;
      }
    }
    bool isoperand(char ch)
    {
        return( ischar(ch) || isnum(ch));
    }
    int postfix_eva(string postfix)
    {   int i;
       for( i = 0;i<postfix.length();i++)
       {
        if(isoperand(postfix[i]))
        {
         int val;
         cout<<"enter value"<<postfix[i]<<endl;
         cin>>val;
         st.push(val);
        }
       
       else 
       {
       int a = st.pop();
       int b = st.pop();
       switch(postfix[i])
       {
         case '*' :
            st.push(b*a);
             break;

         case '/':
           st.push(b/a);
           break;

         case '+':
           st.push(b+a);
           break;

         case '-':
          st.push(b-a);
          break;
        }
       }
      }
      int ans = st.pop();
      cout<<"solution"<<postfix << ans;
      return ans;
    }
};
int main()
{   
    expression e1;
    string infix;
    cout<<"Infix ex =";
    cin>>infix;
    while(true)
    {
    int choice;
    cout<<"choice";
     cin>>choice;
        switch(choice)
        {
            case 1 :
            e1.infixtopost(infix);
            break;
            case 2:
            e1.postfix_eva(e1.postfix);
            break;
            default :
            cout<<"no";
        
      }
    }
return 0;
}
