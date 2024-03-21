#include<bits/stdc++.h>
using namespace std;

void CalculatorLayout() {
    auto printSeparator = []() {
        cout << "\t+------------------------------------------------------------------------------------------------+" << endl;
    };

    auto printButtonRow = [](const string& button1, const string& button2, const string& button3, const string& button4) {
        cout << "\t| " << setw(14) << left << button1 << " \t| " << setw(14) << left << button2
             << "\t | " << setw(14) << left << button3 << " \t| " << setw(14) << left << button4 << " \t|" << endl;
    };

    printSeparator();
    cout << "\t|                                        CALCULATOR                                              |" << endl;
    printSeparator();

    printButtonRow("\t 1: +", " 2: -", " 3: *", " 4: /");
    printButtonRow("\t 5: ^", " 6: log", " 7: x^2", " 8: sqrt");
    printButtonRow("\t 9: sin", "10: cos", "11: tan", "12: !");
    printButtonRow("\t13: sin^-1", "14: cos^-1", "15: tan^-1", "16: Exit");
    printButtonRow("\t17: nCr", "18: nPr", "", "");

    printSeparator();
}

void Linear(float a, float b)
 {
    if (a == 0)
    {
        if (b == 0)
            cout << "\n\tMultiple solutions" << endl;
        else
            cout << "\n\tNo solution" << endl;
    }
    else
    {
        float x = -b / a;
        cout << "\n\tSolution: x = " << x << endl;
    }
}


void Quadratic(float a, float b, float c)
 {
    if (a == 0)
    {
        Linear(b, c);
        return;
    }

    float D = b * b - 4 * a * c;
    if (D > 0)
    {
        float x1 = (-b + sqrt(D)) / (2 * a);
        float x2 = (-b - sqrt(D)) / (2 * a);
        cout << "\n\tSolutions: x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (D == 0)
    {
        float x = -b / (2 * a);
        cout << "\n\tSolution: x = " << x << endl;
    }
    else
    {
        float RP = -b / (2 * a);
        float IP = sqrt(-D) / (2 * a);
        cout << "\n\tSolutions: x1 = " << RP << " + " << IP << "i"
             << ", x2 = " << RP << " - " << IP << "i" << endl;
    }
}


void Cubic(float a, float b, float c, float d)
 {
    if (a == 0)
    {
        Quadratic(b, c, d);
        return;
    }

    float D, q, r, theta;
    q = (3 * a * c - b * b) / (9 * a * a);
    r = (9 * a * b * c - 27 * a * a * d - 2 * b * b * b) / (54 * a * a * a);
    D = q * q * q + r * r;

    if (D > 0)
    {
        float s = cbrt(r + sqrt(D));
        float t = cbrt(r - sqrt(D));
        float x1 = -b / (3 * a) + s + t;
        cout << "\n\tSolution: x = " << x1 << endl;
    }
    else if (D == 0)
    {
        float x = -b / (3 * a) - (q + q * q * q) / 3;
        cout << "\n\tSolution: x = " << x << endl;
    }
    else
    {
        float theta = acos(r / sqrt(-(q * q * q)));
        float x1 = -2 * sqrt(-q) * cos(theta / 3) - b / (3 * a);
        float x2 = -2 * sqrt(-q) * cos((theta + 2 * M_PI) / 3) - b / (3 * a);
        float x3 = -2 * sqrt(-q) * cos((theta - 2 * M_PI) / 3) - b / (3 * a);
        cout << "\n\tSolutions: x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
    }
}

void Equation()
{
    int choice;
    cout << "\tChoices:" << endl;
    cout << "\t1. Linear Equation:" << endl;
    cout << "\t2. Quadratic Equation:" << endl;
    cout << "\t3. Cubic Equation:" << endl;
    cout << "\tEnter choices: \n\t";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            float a, b;
            cout << "\n\tEnter value of a: ";
            cin >> a;
            cout << "\n\tEnter value of b: ";
            cin >> b;
            Linear(a, b);
            break;
        }
        case 2:
        {
            float a, b, c;
            cout << "\n\tEnter value of a: ";
            cin >> a;
            cout << "\n\tEnter value of b: ";
            cin >> b;
            cout << "\n\tEnter value of c: ";
            cin >> c;
            Quadratic(a, b, c);
            break;
        }
        case 3:
        {
            float a, b, c, d;
            cout << "\n\tEnter value of a: ";
            cin >> a;
            cout << "\n\tEnter value of b: ";
            cin >> b;
            cout << "\n\tEnter value of c: ";
            cin >> c;
            cout << "\n\tEnter value of d: ";
            cin >> d;
            Cubic(a, b, c, d);
            break;
        }
        default:
            cout << "\n\tInvalid choice!" << endl;
    }
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}


    int nCr(int n, int r){
        return fact(n) / (fact(r) * fact(n - r));
    }

    int nPr(int n, int r){
        return fact(n) / fact(n - r);
    }

void display(const vector<int>& vec)
 {
    cout << "\tVector: [ ";
    for (int i = 0;i<vec.size();++i)
    {
        cout << vec[i] << " ";
    }
    cout << "]\n" << endl;
}


vector<int> Addition(const vector<int>& vec1, const vector<int>& vec2)
 {
    int size = min(vec1.size(), vec2.size());
    vector<int> result(size);

    for (int i = 0; i < size; ++i)
    {
        result[i] = vec1[i] + vec2[i];
    }
    return result;
}


vector<int> Subtraction(const vector<int>& vec1, const vector<int>& vec2)
 {
    int size = min(vec1.size(), vec2.size());
    vector<int> result(size);

    for (int i = 0; i < size; ++i)
    {
        result[i] = vec1[i] - vec2[i];
    }
    return result;
}


int dotProduct(const vector<int>& vec1, const vector<int>& vec2)
 {
    int size = min(vec1.size(), vec2.size());
    int result = 0.0;

    for (int i = 0; i < size; ++i)
    {
        result += vec1[i] * vec2[i];
    }
    return result;
}


vector<int> crossProduct(const vector<int>& vec1, const vector<int>& vec2)
 {
    if (vec1.size() < 3 || vec2.size() < 3)
    {
        cout << "\tCross product is:" << endl;
        return {};
    }

    vector<int> result(3);
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
    return result;
}

void Vector(){
    int t;
    cout << "\tEnter the size of vectors: \n\t";
    cin >> t;

    vector<int> vector1, vector2;

    cout << "\tEnter elements for vector 1: \n";
    int val;
    for (int i = 0; i < t; ++i)
    {
        cout<<"\t";
        cin >> val;
        vector1.push_back(val);
    }

    cout << "\tEnter elements for vector 2: \n";
    for (int i = 0; i < t; ++i)
    {
        cout<<"\t";
        cin >> val;
        vector2.push_back(val);
    }

    cout << "\tVector 1: \n";
    display(vector1);
    cout << "\tVector 2: \n";
    display(vector2);

    cout << "\t1. Addition" << endl;
    cout << "\t2. Subtraction" << endl;
    cout << "\t3. Dot Product" << endl;
    cout << "\t4. Cross Product\n" << endl;
    int choice;
    cout << "\tEnter your choice: "<<endl;
    cin >> choice;

    switch (choice)
     {
        case 1:
            if (vector1.size() != vector2.size())
            {
                cout << "\tError:Size doesn't match!" << endl;
            }
            else
            {
                vector<int> result = Addition(vector1, vector2);
                cout << "\tAddition Result: ";
                display(result);
            }
            break;
        case 2:
            if (vector1.size() != vector2.size()) {
                cout << "\tError:Size doesn't match!" << endl;
            } else {
                vector<int> result = Subtraction(vector1, vector2);
                cout << "\tSubtraction Result: \n";
                display(result);
            }
            break;
        case 3:
            if (vector1.size() != vector2.size())
            {
                cout << "\tError: Size doesn't match!" << endl;
            }
            else
            {
                cout << "\tDot Product: " << dotProduct(vector1, vector2) << endl;
            }
            break;
        case 4:
            if (vector1.size() != 3 || vector2.size() != 3)
            {
                cout << "\tError: Size doesn't match!" << endl;
            }
            else
            {
                vector<int> result = crossProduct(vector1, vector2);
                cout << "\tCross Product: ";
                display(result);
            }
            break;
        default:
            cout << "\tInvalid choice!" << endl;
            break;
    }
}


int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

string infixToPostfix(const string& expr) {
    string postfix = "";
    stack<char> st;

    for (char ch : expr) {
        if (isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && getPrecedence(st.top()) >= getPrecedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& expr) {
    stack<int> st;

    for (char ch : expr) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (ch) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
                case '^':
                    st.push(pow(operand1, operand2));
                default:
                    break;
            }
        }
    }
    return st.top();
}


vector <vector <int> > matrix_input(char a){
    int n,m;
    cout<<"\n\tEnter the The Dimension of Matrix"<<a;
    cout<<"\n\tHow Many rows?\n\t";
    cin>>n;
    cout<<"\n\tHow Many columns?\n\t";
    cin>>m;

    vector < vector <int> > v;
    for(int i=1;i<=n;i++)
    {
        vector <int> tmp_v;
        for(int j=1;j<=m;j++)
        {
            int x;
            cout<<"\t"<<a<<i<<j<<" = ";
            cin>>x;
            tmp_v.push_back(x);
        }
        v.push_back(tmp_v);
    }
    return v;
}
 void matrix_mul() {
    int m1[10][10], m2[10][10], result[10][10];
    int r1, c1, r2, c2;

    cout << "\n\tEnter rows and columns for first matrix: \n\t";
    cin >> r1; cout<<"\n\t";
    cin >> c1;

    cout << "\tEnter rows and columns for second matrix: \n\t";
    cin >> r2; cout<<"\n\t";
    cin >> c2;


    while (c1 != r2) {
        cout << "\tError! Columns of first matrix not equal to rows of second.\n";
        cout << "\tEnter rows and columns for first matrix:\n\t ";
        cin >> r1 >> c1;
        cout << "\tEnter rows and columns for second matrix: \n\t";
        cin >> r2 >> c2;
    }

    cout << "\tEnter elements of first matrix:\n";
    for(int i = 0; i < r1; ++i) {
        for(int j = 0; j < c1; ++j) {
            cout<<"\t";
            cin >> m1[i][j];
        }
    }

    cout << "\tEnter elements of second matrix:\n";
    for(int i = 0; i < r2; ++i) {
        for(int j = 0; j < c2; ++j) {
            cout<<"\t";
            cin >> m2[i][j];
        }
    }

    for(int i = 0; i < r1; ++i) {
        for(int j = 0; j < c2; ++j) {
            result[i][j] = 0;
        }
    }

    for(int i =0; i < r1; ++i) {
        for(int j =0; j < c2; ++j) {
            for(int k =0; k < c1; ++k) {
                result[i][j]  += m1[i][k] * m2[k][j];
            }
        }
    }

    cout << "\n\tResultant matrix:\n\t";
    for(int i =0; i <r1; ++i) {
        for(int j =0; j<c2; ++j) {
            cout <<result[i][j] << " ";
        }
        cout<<"\n\t";
    }
}

void matrix(){
    cout<<"\n\t **Choose Keyword for Matrix Operation**\n\n";
    cout<<"\t1. Matrix Addition\n";
    cout<<"\t2. Matrix Subtraction\n";
    cout<<"\t3. Matrix Multiplication\n";
    cout<<"\t4. Matrix Trace\n\t";


    int option;
    cin>>option;

    char ch1='A';
    char ch2='B';

    if(option ==4){
            vector<vector <int> > v1;
            v1=matrix_input(ch1);

            int sum=0;
            for(int i=0;i<v1.size();i++){
                for(int j=0;j<v1[i].size();j++){
                    if(i==j){
                        sum=sum+v1[i][j];
                    }
                }
        }   cout<<"\n\tTrace = "<<sum<<endl;
    }

    else if(option==3){
        matrix_mul();
    }

    else if(option==2){
            vector<vector <int> > v1,v2;
            v1=matrix_input(ch1);
            v2=matrix_input(ch2);
            cout<<"\n\tFinal Matrix:\n\t";

            for(int i=0;i<v1.size();i++){
                for(int j=0;j<v1[i].size();j++){
                cout<<v1[i][j] - v2[i][j]<<" ";
                }
            cout<<"\n\t";
            }
    }
   else if(option==1){
            vector<vector <int> > v1,v2;
            v1=matrix_input(ch1);
            v2=matrix_input(ch2);
            cout<<"\n\tFinal Matrix:\n\t";

            for(int i=0;i<v1.size();i++){
                for(int j=0;j<v1[i].size();j++){
                cout<<v1[i][j] + v2[i][j]<<" ";
                }
            cout<<"\n\t";
            }
    }
    else{
        cout<<"\tWrong Input"<<endl;
    }




}

int main(){

    cout<<"\n\n";
    CalculatorLayout();

    cout<<"\n\t Modes:"<<endl;
    cout<<" \t --------------"<<endl;
    cout<<"\t 19: Expression"<<endl;
    cout<<"\t 20. Matrix "<<endl;
    cout<<"\t 21. Vector "<<endl;
    cout<<"\t 22. Equation"<<endl;

    float x,y,n,r;
    float PI= 3.14159265;
    int choice;

    do{
        cout<<"\n\t **Press the keynumber to select your operation**\n\t";
        cin>>choice;

        if(choice==19){
            string infixExpr;
                cout<<"\tEnter a one-digit infix expression: ";
                cin>>infixExpr;

                string postfixExpr= infixToPostfix(infixExpr);
                int result = evaluatePostfix(postfixExpr);
                cout<<"\tResult: "<<result<<endl;
                break;

        }
         if(choice==17){
            cout << "\tEnter value of n: \n\t";
            cin >> n;
            cout << "\tEnter value of r: \n\t";
            cin >> r;
            if (n < r)
                cout << "\tInvalid input!" << endl;
            else
                cout << "\tnCr = " << nCr(n, r) << endl;
            break;
         }
         if(choice==18){
            cout << "\tEnter value of n: \n\t";
            cin >> n;
            cout << "\tEnter value of r: \n\t";
            cin >> r;
            if (n < r)
                cout << "\tInvalid input!" << endl;
            else
                cout << "\tnPr = " << nPr(n, r) << endl;
            break;
         }
         if(choice==22){
            Equation();
            break;
         }

        switch(choice){

        default: cout<<"\tWrong Input"<<endl;
                break;

        case 20: matrix();
                    break;
        case 21:Vector();
                    break;

        case 16: cout<<"\tExited"<<endl;
                break;

        case 1: cout<<"\tEnter 1st Operand\n\t";
                cin>>x;
                cout<<"\tEnter 2nd Operand\n\t";
                cin>>y;
                cout<<"\tResult = "<<x+y<<endl;
                break;

        case 2: cout<<"\tEnter 1st Operand\n\t";
                cin>>x;
                cout<<"\tEnter 2st Operand\n\t";
                cin>>y;
                cout<<"\tResult = "<<x-y<<endl;
                break;

        case 3: cout<<"\tEnter 1st Operand\n\t";
                cin>>x;
                cout<<"\tEnter 2nd Operand\n\t";
                cin>>y;
                cout<<"\tResult = "<<x*y<<endl;
                break;

        case 4: cout<<"\tEnter 1st Operand\n\t";
                cin>>x;
                cout<<"\tEnter 2nd Operand\n\t";
                cin>>y;
                cout<<"\tResult = "<<x/y<<endl;
                break;

        case 5: cout<<"\tEnter Base \n\t";
                cin>>x;
                cout<<"\tEnter Exponent\n\t";
                cin>>y;
                cout<<"\tResult = "<<pow(x,y)<<endl;
                break;

        case 6: cout<<"\tEnter Number\n\t";
                cin>>x;
                cout<<"\tResult = "<<log10(x)<<endl;
                break;

        case 7: cout<<"\tEnter Number\n\t";
                cin>>x;
                cout<<"\tResult = "<<x*x<<endl;
                break;

        case 8: cout<<"\tEnter Number\n\t";
                cin>>x;
                cout<<"\tResult = "<<sqrt(x)<<endl;
                break;

        case 9: cout<<"\tEnter Degree angle\n\t";
                cin>>x;
                cout<<"\tResult = "<<sin(x*(PI/180.0))<<endl;
                break;

        case 10: cout<<"\tEnter Degree Angle\n\t";
                cin>>x;
                cout<<"\tResult = "<<cos(x*(PI/180.0))<<endl;
                break;

        case 11: cout<<"\tEnter Degree Angle\n\t";
                cin>>x;
                cout<<"\tResult = "<<tan(x*(PI/180.0))<<endl;
                break;

        case 13: cout<<"\tEnter Value\n\t";
                cin>>x;
                cout<<"\tResult = "<<asin(x)*180.0/PI<<endl;
                break;

        case 14: cout<<"\tEnter Value\n\t";
                cin>>x;
                cout<<"\tResult = "<<acos(x)*180.0/PI<<endl;
                break;

        case 15: cout<<"\tEnter Value\n\t";
                cin>>x;
                cout<<"\tResult = "<<atan(x)*180.0/PI<<endl;
                break;

        case 12: cout<<"\tEnter Number\n\t";
                signed long long p,sum=1;
                cin>>p;
                for(int i=1; i<=p; i++){
                    sum=i*sum;
                }
                cout<<"\tResult = "<<sum<<endl;
                break;
        }
    } while(choice!=16);

}
