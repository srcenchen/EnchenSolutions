#include <bits/stdc++.h>
using namespace std;
#define int double long
#define endl "\n"
string format(string ops) {
    if (ops.find('.') != string::npos) {
        ops.erase(ops.find_last_not_of('0') + 1);
        if (!ops.empty() && ops.back() == '.') {
            ops.pop_back();
        }
    }
    return ops;
}
void logStack(stack<int> st, string origin, string ops) {
    cout << "在处理字符串： " << origin << " 时候的 " << format(ops) << " 操作的栈帧" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int solveInner(string str) {
    stack<int> st;
    string tmp;
    char op = '+';
    for (int index = 1; index < str.size(); ++index) {
        char i = str[index];
        if (i >= '0' && i <= '9') {
            tmp.push_back(i);
        } else if (i == '(') {
            // cout << 1;
            // 遇到左括号
            string tmpInner;
            while (str[index] != ')' && index < str.size()) {
                tmpInner.push_back(str[index]);
                index++;
            }
            tmpInner += ')';
            cout << "进入子括号处理流程" << tmpInner << endl;
            tmp = to_string(solveInner(tmpInner));
            cout << "子括号处理流程结束：" << tmpInner << " 结果是：" << format(tmp) << endl; 
        } else {
            int tmpInt = stoi(tmp);
            tmp = "";
            if (op == '*' || op == '/') {
                if (st.size() == 0) {
                    st.push(tmpInt);
                } else {
                    int stTop = st.top();
                    st.pop();
                    if (op == '*') {
                        st.push(stTop * tmpInt);
                    } else {
                        st.push(stTop / tmpInt);
                    }
                }
                // cout << st.top() << endl;
            } else {
                if (op == '-') {
                    st.push(-1 * tmpInt);
                } else {
                    st.push(tmpInt);
                }
            }
            logStack(st, str, op + to_string(tmpInt));
            op = i;
        }
    }
    int ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    // cout << ans;
    return ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    string str;
    cin >> str;
    cout << solveInner(str);
    return 0;
}