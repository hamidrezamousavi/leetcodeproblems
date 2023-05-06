class Solution {
public:
  string calculate(string oper, string x, string y){
    int xx{stoi(x)};
    int yy{stoi(y)};
    switch (oper[0]){
      case '+':
        return to_string(xx + yy);
      case '-':
        return to_string(xx - yy);
      case '*':
        return to_string(xx * yy);
      case '/':
        return to_string(xx / yy);    

        }
      return NULL;
  }
 

  int evalRPN(vector<string>& tokens) {
    stack<string> temp{};
    vector<string> operators{"+", "-", "/", "*"};
    for(string item:tokens){
      if(find(operators.begin(), operators.end(), item)
         != operators.end()){
        string y = temp.top();
        temp.pop();
        string x = temp.top();
        temp.pop();
        temp.push(calculate(item, x, y));

      }else{
        temp.push(item);
      }

    }


    return stoi(temp.top());       
  }

};