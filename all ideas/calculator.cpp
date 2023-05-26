#include<iostream>
#include<cmath>

using namespace std;

void arithmetic(){
    int op = 0;
    float A = 0;
    float B = 0;

    cout << "Select operation\n";
    cout << "[1] Addition\n";
    cout << "[2] Subtraction\n";
    cout << "[3] Product\n";
    cout << "[4] Division\n";

    cin >> op;
    cout << "Enter the first number: ";
    cin >> A;
    cout << "Enter the second number: ";
    cin >> B;

    cout << "Result: ";

    switch(op){
        case 1:
            cout << (A + B);
            break;
        case 2:
            cout << (A - B);
            break;
        case 3:
            cout << (A * B);
            break;
        case 4:
            cout << (A / B);
            break;
        default:
            cout << "Invalid operation";
            break;
    }
    cout << endl;
}

void trigonometric(){
    int op = 0;
    float val = 0.0;

    cout << "Select\n";
    cout << "[1] Sine\n";
    cout << "[2] Cosine\n";
    cout << "Op: ";
    cin >> op;
    cout << "Enter the value: ";
    cin >> val;

    if(op == 1){
        cout << sin(val);
    }
    else if(op == 2){
        cout << cos(val);
    }
    else{
        cout << "Invalid operation";
    }
    cout << endl;
}

void exponential(){
    float base = 0.0;
    float eee = 0.0;

    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> eee;

    cout << pow(base, eee) << endl;
}

void logarithmic(){
    float value = 0.0;
    cout << "Enter the value to calculate the natural logarithm (log(e)): ";
    cin >> value;
    cout << log(value) << endl;
}

int main(){
    int sel = 0;
    char choice = 'y';
    cout << "Advanced Calculator\n";

    cout << "[1] Arithmetic\n";
    cout << "[2] Trigonometric\n";
    cout << "[3] Exponential\n";
    cout << "[4] Logarithmic\n";
    cout << "Your choice: ";

    while(choice == 'y'){
        cout << "Enter the type of operation you want to calculate: ";
        cin >> sel;

        switch(sel){
            case 1:
                arithmetic();
                break;
            case 2:
                trigonometric();
                break;
            case 3:
                exponential();
                break;
            case 4:
                logarithmic();
                break;
            default:
                cout << "Invalid Operation";
        }

        cout << "Do you want to continue? (y/n)" << endl;
        cin >> choice;
        if(choice == 'n'){
            break;
        }
    }

    return 0;
}

