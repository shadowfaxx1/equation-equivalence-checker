#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;
vector <int > bo;
int precedence(char op){
    if(op=='^')
    return 3;
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;

    return 0;
}
 
int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
        // case 'x': return 
        
            }
}
int equivalent(string tokens){
    int i;
    stack <int> values;
    stack <char> ops;
    values.push(1);

    for(i = 0; i < tokens.length(); i++){
        if(tokens[i] == ' ')
            continue;
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
        else if(isdigit(tokens[i])){
            int val = 0;
            // cout<<"bool"<<isdigit(tokens[i]);

            while(i < tokens.length() &&
                        isdigit(tokens[i]) )
            {
                val = (val*10) + (tokens[i]-'0');
                i++;

            }
                values.push(val);
            
              i--;
        }
          else if(tokens[i]=='x')
        {
             int val3;
             val3=values.top();
             values.pop();
             tokens[i]='2';
            int cat;
            cat=(int)tokens[i]-48;
            if(tokens[i+1]=='^')
            {
                int valx=(int)tokens[i+2]-48;
                char op3= tokens[i+1];
                int exp =applyOp(cat,valx,op3);
                if(val3==(int)val3)
                {
                    values.push(val3*exp);

                }  
                else{
                    values.push(exp);

                }
                i=i+2;

            }
        else{ 
            
                if(val3==(int)val3)
                {
                    values.push(val3*cat);

                }  
                else{
                    values.push(cat*1);

                } 
          
}
        }
         else if(tokens[i]=='y')
         {

            if(tokens[i+1]=='^')
            {
               char op3= tokens[i+1];
               int valz=values.top();
               values.pop();

               int valx=(int)tokens[i+2]-48;
                 tokens[i]='1';
                int cat2;
                cat2=(int)tokens[i]-48;

               values.push(valz*(applyOp(valx,cat2,op3)));
                i+2;
            }
            else{
             int val4;
             val4=values.top();
             values.pop();
             tokens[i]='1';
             int cat2;
             cat2=(int)tokens[i]-48;
            values.push(cat2*val4);
            }

         }
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty())
               ops.pop();
        }
        else
        {
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
             
            ops.push(tokens[i]);
        }
    }
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}
int stringdiv(string s)
{
    
    int ps=s.find(' ');
    string s1=s.substr(ps+1);
    string s2=s.substr(0,ps);

    int x=equivalent(s1);
    int y=equivalent(s2);

    

    if(x==y)
    {
        bo.push_back(1);
    }
    else{
        bo.push_back(0);
    }
}
int main()
{
    fstream f2;
    string s;
    printf("enter the file's name ");
    cin>>s;

    f2.open(s,ios::in);

    if(f2.is_open()){
        string p;
        while(getline(f2,p)){

            stringdiv(p);

        }
    }

    f2.close();
    fstream f1;
    f1.open("out_file.txt",ios::out);
    if(f1.is_open())
    {
        f1<<"kaif khan "<<" "<<"<mail2kaifkhan@gmail.com>\n";
        for(auto i=bo.begin();i!=bo.end();i++)
            {
                if(*i==1)
                f1<<"true\n";
                else
                f1<<"false\n";
                
            }
    }
    f1.close();


}
