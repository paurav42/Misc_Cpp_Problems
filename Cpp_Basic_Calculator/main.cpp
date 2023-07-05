#include<iostream>
#include<stack>
#include<vector>
#include<string>

class Solution{
    public:
    const int ExpressionSum(std::string stringExp){

        // parse each char of string  (5 - 4 + 1- (10 + (3- 7))) 
        // process numbers till we hit a "("
        // if we hit a "(" then with base 0 , 
        // mainsum 5 - 4 = 1
        // st 5 4
        // sign -  
        // number push
        // sign push
        //  number -> process 
        //  
        std::stack<int> st;
        std::stack<char> sn;
        int prevsign = 1, result = 0, num = 0;
        
        for(auto it: stringExp){
            if(isdigit(it)){
                num = num*10 + (it - '0');
                
            }else if(it == '+'){
                result = result + num*prevsign;
                num = 0;
                prevsign = 1;
            }else if(it == '-'){
                result = result + num*prevsign;
                num = 0;
                prevsign = -1;
            }else if(it == '('){
                st.push(result);
                sn.push(prevsign);

                result = 0;
                prevsign = 1;
            }else if(it == ')' && sn.size()){
                result = result + num*prevsign;
                num = 0;
                
                result = st.top() + sn.top()*result;
                st.pop();
                sn.pop();
            }

        }

        result = result+num*prevsign;
        return result;
        

    }

};

int main(){

    return 0;
}