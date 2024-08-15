#include <iostream>
using namespace std;

void main()
{
    int n,m,t;
    float o,r,s;
    cout << "Select the type of function:" <<endl;
    cout << "1. Simple" <<endl;
    cout << "2. Powers and Roots" <<endl;
    cout << "3. Exponents and Logarithms" <<endl;
    cout << "4. Trigonometric" <<endl;
    cout << "5. " <<endl;
    cout << "6. Factorial and Reciprocal" <<endl;
    cout << "7. Equation Solver" <<endl;
    cout << "8. Permutations and Combinations" <<endl;
    cin >> n;
    switch(n)
    {
        case 1: 
        int p,q;
        cout << "Select the function:" <<endl;
        cout << "1. Addition" <<endl;
        cout << "2. Subtraction" <<endl;
        cout << "3. Multiplication" <<endl;
        cout << "4. Division" <<endl;
        cin >> m;
        cout << "Enter two numbers:" <<endl;
        cin >> p,q;
        switch(m)
        {
            case 1:
            s = p + q;
            cout << "The sum is " << s << "." <<endl;
            break;

            case 2:
            s = p - q;
            cout << "The difference is " << s << "." <<endl;
            break;

            case 3:
            s = p * q;
            cout << "The product is " << s << "." <<endl;
            break;

            case 4:
            s = p / q;
            r = p % q;
            cout << "The quotient is " << s << " and the remainder is " << r << "." <<endl;
            break;

            default:
            break;
        }
        break;

        case 2:
        cout << "Select the function:" <<endl;
        cout << "1. Square" <<endl;
        cout << "2. Cube" <<endl;
        cout << "3. Square Root" <<endl;
        cout << "4. Cube Root" <<endl;
        cin >> m;
        cout << "Enter a number:" <<endl;
        cin >> o;
        switch(m)
        {
            case 1:
            s = o * o;
            break;

            case 2:
            s = o * o * o;
            break;

            case 3:
            s = srt(o);
            break;

            case 4:
            s = crt(o);
            break;

            default:
            break;
        }
        cout << "The value is " << s << "." <<endl;
        break;

        case 3:
        cout << "Select the function:" <<endl;
        cout << "1. Exponent of 10" <<endl;
        cout << "2. Exponent of e" <<endl;
        cout << "3. Natural Logarithm" <<endl;
        cout << "4. Common Language" <<endl;
        cin >> m;
        cout << "Enter a value:" <<endl;
        cin >> o;
        switch(m)
        {
            case 1:
            s = expten(o);
            break;

            case 2:
            s = expe(o);
            break;

            case 3:
            s = logten(o);
            break;

            case 4:
            s = loge(o);
            break;

            default:
            break;
        }
        cout << "The value is " << s << "." <<endl;
        break;

        case 4:
        cout << "Select the function:" <<endl;
        cout << "1. Sine" <<endl;
        cout << "2. Cosine" <<endl;
        cout << "3. Tangent" <<endl;
        cout << "4. Cosecant" <<endl;
        cout << "5. Secant" <<endl ;
        cout << "6. Cotangent" <<endl;
        cin >> m;
        cout << "Select D for Degrees and R for Radians:" <<endl;
        cin >> t;
        cout << "Enter a value:" <<endl;
        cin >> r;
        switch(t)
        {
            case 'D':
            o = r * 3.141592654/180;
            break;

            case 'R':
            o = r;
            break;

            default:
            break;
        }
        switch(m)
        {
            case 1:
            s = sin(o);
            break;

            case 2:
            s = cos(o);
            break;

            case 3:
            s = tan(o);
            break;

            case 4:
            s = cosec(o);
            break;

            case 5:
            s = sec(o);
            break;

            case 6:
            s = cot(o);
            break;

            default:
            break;
        }
        cout << "The value is " << s << "." <<endl;
        break;

        case 5:
        break;

        case 6:
        cout << "Select the function:" <<endl;
        cout << "1. Factorial" <<endl;
        cout << "2. Reciprocal" <<endl;
        cin >> m;
        cout << "Enter a value:" <<endl;
        cin >> o;
        switch(m)
        {
            case 1:
            s = fact(o);
            cout << "The value is " << s << "." <<endl;
            break;

            case 2:
            if(o=0)
            {
                cout << "Division by zero is not defined." <<endl;
            }
            else
            {
                s = 1 / o;
                cout << "The value is " << s << "." <<endl;
            }
            break;

            default:
            break;
        }
        break;

        case 7:
        cout << "Select the function:" <<endl;
        cout << "1. Linear Equations in 2 Variables" <<endl;
        cout << "2. Linear Equations in 3 Variables" <<endl;
        cout << "3. Quadratic Equations" <<endl;
        cout << "4. Cubic Equations" <<endl;
        cin >> m;
        switch(m)
        {
            case 1:
            float a1,a2,b1,b2,c1,c2,x,y;
            cout << "Enter the terms in ax + by = c.";
            cout << "a1 = " <<endl << "b1 = " <<endl << "c1 = " <<endl << "a2 = " <<endl << "b2 = " <<endl << "c2 = " <<endl;
            cin >> a1,a2,b1,b2,c1,c2;
            x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
            y = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2);
            cout << "The value of x is " << x << " and the value of y is " << y << "." <<endl;
            break;

            case 2:
            cout << "Enter the terms in ax + by + cz = d.";
            cout << "Give Up";
            break;

            case 3:
            float a,b,c,x1,x2,d,D;
            cout << "Enter the terms in ax^2 + bx + c = 0.";
            cout << "a = " <<endl << "b = " <<endl << "c = " <<endl;
            cin >> a,b,c;
            d = b * b - 4 * a * c;
            D = srt(d);
            x1 = (-b + D) / (2 * a);
            x2 = (-b - D) / (2 * a);
            cout << "The value of x is " << x1 << " and " << x2 << "." <<endl;
            break;

            case 4:
            cout << "Enter the terms in ax^3 + bx^2 + cx + d = 0.";
            cout << "Give Up";
            break;

            default:
            break;
        }
        break;

        case 8:
        cout << "Select the function:" <<endl;
        cout << "1. Permutation nPr" <<endl;
        cout << "2. Combination nCr" <<endl;
        cin >> m;
        cout << "Enter a value:" <<endl;
        cin >> o;
        switch(m)
        {
            case 1:
            s = per(o);
            break;

            case 2:
            s = com(o);
            break;

            default:
            break;
        }
        cout << "The value is " << s << "." <<endl;
        break;

        default:
        break;
    }
}

float srt(float o)
{};
float crt(float o)
{};
float expten(float o)
{};
float expe(float o)
{};
float logten(float o)
{};
float loge(float o)
{};
float sin(float o)
{};
float cos(float o)
{};
float tan(float o)
{};
float cosec(float o)
{};
float sec(float o)
{};
float cot(float o)
{};
float fact(float o)
{};
float per(float o)
{};
float com(float o)
{};