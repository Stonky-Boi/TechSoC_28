#include <iostream>
using namespace std;

float square_root(float input)
{
    if (input >= 0)
    {
        float tolerance = 0.0001;
        float output = input / 2;
        float error = 1;
        while (abs(output - error) > tolerance)
        {
            error = output;
            output = 0.5 * (output + (input / output));
        }
        return output;
    }
    else
    {
        cout << "Number must be greater than or equal to zero." << endl;
        return -1;
    }
}
float cube_root(float input)
{
    if (input >= 0)
    {
        float tolerance = 0.0001;
        float output = input / 3;
        float error = 1;
        while (abs(output - error) > tolerance)
        {
            error = output;
            output = ((2 * output) + (input / (output * output))) / 3;
        }
        return output;
    }
    else
    {
        cout << "Number must be greater than or equal to zero." << endl;
        return -1;
    }
}

float exponential(float input)
{
    float output = 1;
    float term = 1;
    for (int i = 1; i < 200; i++)
    {
        term = term * (input / i);
        output = output + term;
    }
    return output;
}
float logarithm(float input)
{
    if (input > 0)
    {
        float error = input - 1;
        float output = error;
        float term = error;
        for (int i = 2; abs(term) > 0.0001; i++)
        {
            term *= -error;
            output += term / i;
        }
        return output;
    }
    else
    {
        cout << "Number must be greater than zero.";
        return -1;
    }
}

float sine(int input)
{
    float term = input;
    float output = term;
    for (int i = 3, sign = -1; abs(term) > 0.0001; i += 2, sign *= -1)
    {
        term *= (input * input) / (i * (i - 1));
        output += sign * term;
    }
    return output;
}
float cosine(int input)
{
    float term = 1;
    float output = term;
    for (int i = 2, sign = -1; abs(term) > 0.0001; i += 2, sign *= -1)
    {
        term *= (input * input) / (i * (i - 1));
        output += sign * term;
    }
    return output;
}
float tangent(float input)
{
    float output = (sine(input)) / (cosine(input));
    return output;
}
float cosecant(float input)
{
    float output = 1 / (sine(input));
    return output;
}
float secant(float input)
{
    float output = 1 / (cosine(input));
    return output;
}
float cotangent(float input)
{
    float output = 1 / (tangent(input));
    return output;
}

float factorial(float input)
{
    float output = 1;
    if (input < 0)
    {
        cout << "Entered number must be greater than zero" << endl;
        return -1;
    }
    else
    {
        for (int i = 1; i <= input; i++)
            output = output * i;
        return output;
    }
}
float permutation(float input_1, float input_2)
{
    float factor_1, factor_2;
    factor_1 = factorial(input_1);
    factor_2 = factorial(input_2);
    float output = factor_1 / factor_2;
    return output;
}
float combination(float input_1, float input_2)
{
    float factor_1, factor_2, factor_3;
    factor_1 = factorial(input_1);
    factor_2 = factorial(input_2);
    factor_3 = factorial(input_1 - input_2);
    float output = factor_1 / (factor_2 * factor_3);
    return output;
}

int main()
{
    int function_type, function;
    float input, result;
    while (true)
    {
        cout << "Select the type of function:" << endl
             << "1. Simple" << endl
             << "2. Powers and Roots" << endl
             << "3. Exponents and Logarithms" << endl
             << "4. Trigonometric" << endl
             << "5. Factorial and Reciprocal" << endl
             << "6. Equation Solver" << endl
             << "7. Permutations and Combinations" << endl
             << "8. Exit" << endl;
        cin >> function_type;
        switch (function_type)
        {
        case 1:
            int input_1, input_2;
            cout << "Select the function:" << endl
                 << "1. Addition" << endl
                 << "2. Subtraction" << endl
                 << "3. Multiplication" << endl
                 << "4. Division" << endl;
            cin >> function;
            cout << "Enter two numbers:" << endl;
            cin >> input_1 >> input_2;
            switch (function)
            {
            case 1:
                result = input_1 + input_2;
                cout << "The sum is " << result << "." << endl;
                break;
            case 2:
                result = input_1 - input_2;
                cout << "The difference is " << result << "." << endl;
                break;
            case 3:
                result = input_1 * input_2;
                cout << "The product is " << result << "." << endl;
                break;
            case 4:
                if (input_2 == 0)
                    cout << "Division by zero is not defined." << endl;
                else
                {
                    result = input_1 / input_2;
                    cout << "The quotient is " << result << "." << endl;
                    result = int(input_1) % int(input_2);
                    cout << "The remainder is " << result << "." << endl;
                }
                break;
            default:
                break;
            }
            break;
        case 2:
            cout << "Select the function:" << endl
                 << "1. Square" << endl
                 << "2. Cube" << endl
                 << "3. Square Root" << endl
                 << "4. Cube Root" << endl;
            cin >> function;
            cout << "Enter a number:" << endl;
            cin >> input;
            switch (function)
            {
            case 1:
                result = input * input;
                break;
            case 2:
                result = input * input * input;
                break;
            case 3:
                result = square_root(input);
                break;
            case 4:
                result = cube_root(input);
                break;
            default:
                break;
            }
            cout << "The value is " << result << "." << endl;
            break;
        case 3:
            cout << "Select the function:" << endl
                 << "1. Exponent" << endl
                 << "2. Logarithm" << endl;
            cin >> function;
            cout << "Enter a value:" << endl;
            cin >> input;
            switch (function)
            {
            case 1:
                result = exponential(input);
                break;
            case 2:
                result = logarithm(input);
                break;
            default:
                break;
            }
            cout << "The value is " << result << "." << endl;
            break;
        case 4:
            char unit_select;
            int angle;
            cout << "Select the function:" << endl
                 << "1. Sine" << endl
                 << "2. Cosine" << endl
                 << "3. Tangent" << endl
                 << "4. Cosecant" << endl
                 << "5. Secant" << endl
                 << "6. Cotangent" << endl;
            cin >> function;
            cout << "Enter D for Degrees and R for Radians:" << endl;
            cin >> unit_select;
            cout << "Enter a value:" << endl;
            cin >> angle;
            switch (unit_select)
            {
            case 'D':
                input = angle * 3.141592654 / 180;
                break;
            case 'R':
                input = angle;
                break;
            default:
                break;
            }
            switch (function)
            {
            case 1:
                result = sine(input);
                break;
            case 2:
                result = cosine(input);
                break;
            case 3:
                result = tangent(input);
                break;
            case 4:
                result = cosecant(input);
                break;
            case 5:
                result = secant(input);
                break;
            case 6:
                result = cotangent(input);
                break;
            default:
                break;
            }
            cout << "The value is " << result << "." << endl;
            break;
        case 5:
            cout << "Select the function:" << endl
                 << "1. Factorial" << endl
                 << "2. Reciprocal" << endl;
            cin >> function;
            cout << "Enter a value:" << endl;
            cin >> input;
            switch (function)
            {
            case 1:
                result = factorial(input);
                cout << "The value is " << result << "." << endl;
                break;
            case 2:
                if (input == 0)
                    cout << "Division by zero is not defined." << endl;
                else
                {
                    result = 1 / input;
                    cout << "The value is " << result << "." << endl;
                }
                break;
            default:
                break;
            }
            break;
        case 6:
            cout << "Select the function:" << endl
                 << "1. Linear Equations in 2 Variables" << endl
                 << "2. Linear Equations in 3 Variables" << endl
                 << "4. Cubic Equations" << endl;
            cin >> function;
            switch (function)
            {
            case 1:
                float a1, a2, b1, b2, c1, c2, x, y;
                cout << "Enter the terms in ax + by = c." << endl
                     << "a1 = " << endl
                     << "b1 = " << endl
                     << "c1 = " << endl
                     << "a2 = " << endl
                     << "b2 = " << endl
                     << "c2 = " << endl;
                cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
                x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
                y = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2);
                cout << "The value of x is " << x << " and the value of y is " << y << "." << endl;
                break;
            case 2:
                cout << "Enter the terms in ax + by + cz = d.";
                cout << "Give Up";
                break;
            case 3:
                float a, b, c, x1, x2, d, D;
                cout << "Enter the terms in ax^2 + bx + c = 0." << endl
                     << "a = " << endl
                     << "b = " << endl
                     << "c = " << endl;
                cin >> a >> b >> c;
                d = b * b - 4 * a * c;
                D = square_root(d);
                x1 = (-b + D) / (2 * a);
                x2 = (-b - D) / (2 * a);
                cout << "The values of x are " << x1 << " and " << x2 << "." << endl;
                break;
            case 4:
                cout << "Give Up";
                break;
            default:
                break;
            }
            break;
        case 7:
            cout << "Select the function:" << endl
                 << "1. Permutation nPr" << endl
                 << "2. Combination nCr" << endl;
            cin >> function;
            cout << "Enter n and r:" << endl;
            float n, r;
            cin >> n >> r;
            switch (function)
            {
            case 1:
                result = permutation(n, r);
                break;
            case 2:
                result = combination(n, r);
                break;
            default:
                break;
            }
            cout << "The value is " << result << "." << endl;
            break;
        case 8:
            break;
        default:
            break;
        }
    }
    return 0;
}
