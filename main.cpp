

/*double sum(int n)
{
    double sum = 0;
    int i;
    for (int i = 1; i <= n; ++i)
    {
        sum += 1.0 / (static_cast<double>(i) * i + 2.0 * i + 1.0);
    }
    return sum;
}

int main() 
{
    int n;
    cout << "n = ";
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}*/

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double formula_a_n(int n) //  вычисление n-ого члена ряда
{
    double a_n = pow(-1, static_cast<double>(n)) * (static_cast<double>(n - 1) / (pow(static_cast<double>(n), 3) + static_cast<double>(n)));
    return a_n;
}
double Sum1(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += formula_a_n(i);
    }
    return sum;
}

double Sum2(int n)
{
    double eps = numeric_limits<double>::epsilon(); // Стандартная точность eps
    double sum = formula_a_n(1);
    int i = 1;
    while (fabs(formula_a_n(i)) >= eps && formula_a_n(i) != 0)
    {
        ++i;
        if (i <= n)
            sum += formula_a_n(i);
        else
            break;
    }
    return sum;
}

int main()
{
    setlocale(0, "");
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    double result1 = Sum1(n);
    double result2 = Sum2(n);

    cout << "Сумма первых " << n << " членов ряда: " << result1 << endl;
    cout << "Сумма с точностью до стандартной eps: " << result2 << endl;

    return 0;
}








