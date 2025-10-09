#include <iostream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string inp;
    stack<float> st;

    while (true){
        float num1, num2, ans;
        cin >> inp;
        if (inp == "="){
            break;
        }
        if (inp == "+"){
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();
            ans = num2 + num1;
            st.push(ans);
        }
        else if (inp == "-"){
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();
            ans = num2 - num1;
            st.push(ans);
        }
        else if (inp == "*"){
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();
            ans = num2 * num1;
            st.push(ans);
        }
        else if (inp == "/"){
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();
            ans = num2 / num1;
            st.push(ans);
        }
        else{
            float num = stof(inp);
            st.push(num);

        }
    }

    cout << fixed << setprecision(4) << st.top();

}