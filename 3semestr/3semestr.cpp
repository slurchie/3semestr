// 3semestr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include "matrix.h"
#include <string>



int n=10; //кол-во разбиений 
//TridiagonalMatrix matrix;
std::string headers[] = { "ih","y_i", "y_i^k", "k", "|y_i-y_i^k|" };
double findH(int n)
{
     return h = 1.0 / n;
}

double* InitiateB()
{
    double* result = new double[n+1];
    result[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (i == 0)
        {
            result[i] = 0;
        }
        else if (i == n)
        {
            result[i] = 0;
        }
        else
        {
            result[i] = F(i) * h * h;
        }
    }
    result[n] = 0;
    return result;
}
static void DirectCourse(TridiagonalMatrix matrix, double* b)
{
    double a;
    for (int i = 2; i < n; i++)
    {
        a = matrix.Element(i, i - 1) / matrix.Element(i - 1, i - 1);
        matrix.Element(i, i - 1)-= matrix.Element(i - 1, i - 1) * a;
        matrix.Element(i,i) -= matrix.Element(i - 1, i) * a;
        b[i] -= b[i - 1] * a;//прямой ход убиарет нижнюю диагональ. остаётся центральная и верхняя
    }
}
/// <summary>
/// Обратный ход метода Прогонки
/// </summary>
/// <param name="matrix"></param>
/// <param name="b"></param>
/// <returns></returns>
double* ReverseCourse(TridiagonalMatrix matrix, double* b)
{
    double* y = new double [n];
    y[n] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        y[i] = (b[i] - y[i + 1] * matrix.Element(i, i + 1)) / matrix.Element(i,i);
    }
    return y; //находит сами занчения
}
std::string** DataToTable(double* x,int k)
{
    std::string** data = new std::string*[4];
    for (int i = 0; i < 4; i++)
    {
        data[i] = new std::string[n];
    }
    for (int i = 0; i < n; i++)
    {
        data[0][i] = round((h * i*100)/100);
        double u = U(i * h); //вычисление значения функции
        data[1][i] = u;
        data[2][i] = x[i];
        data[3][i] = k;
        data[4][i] = abs(x[i] - u);
    }
    return data;
}

void PrintTableLaTeX(std::string nameTable, std::string* names, std::string** data, int rows, int colums)
{
    //настройки таблицы
    std::string result = "\\begin{table}\\caption{" + nameTable + "}\\begin {tabular}{|";
    for (int i = 0; i < colums; i++)
    {
        result += "p{ 3cm}|";
    }
    result += "}\\ hline $" + names[0] + "$ \n";
    for (int i = 1; i < colums; i++) //шапка таблицы
    {
        result += " & $" + names[i] + "$";
    }
    result += "\\ \\hline ";
   
    for (int i = 0; i < rows; i++)
    {
        if (i != 0) result += "\\ \\hline";
        result += "\n" + data[0][i];
        for (int j = 1; j < colums; j++)
        {
            result += " & ";
            result +=data[j][i];
        }
    }
    result += "\\ \\hline\\end{tabular} \\end{table}" + '\n';
std::cout<<result;
}
/// <summary>
/// Метод Прогонки
/// </summary>
/// <param name="A"></param>

 void Progonka(TridiagonalMatrix matrix)
{
    TridiagonalMatrix A(matrix);
    double* B = InitiateB();
    DirectCourse(A, B);
    double* y = ReverseCourse(A, B);
    std::string header = "Метод Прогонки";
    PrintTableLaTeX(header, headers, DataToTable(y,1), 5,n );
}


int main()
{
    
    findH(n);
   TridiagonalMatrix A(n);
  /*  Progonka(A*);*/
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
