#pragma once
#include "matrix.h"


TridiagonalMatrix::TridiagonalMatrix()
{
}

    size_t  TridiagonalMatrix::getSize()
    {
        return size;
    }

    TridiagonalMatrix::TridiagonalMatrix(int n)
    {
        n++;
        size = n;
        diag = new double[n];
        high_diag = new double[n - 1];
        low_diag = new double[n - 1];
       
        SetDiag(0, 1);
        for (int i = 1; i < n - 1; i++)
        {
           SetHighDiag(i, -P((i + 1) * h));
        }
        for (int i = 2; i < n; i++)
        {
            SetLowDiag(i, -P(i * h));
        }
        for (int i = 1; i < n; i++)
        {
            SetDiag(i, P(i * h) + P((i + 1) * h) + h * h * Q(i * h));
        }
       SetDiag(n, 1);

    }
    TridiagonalMatrix::TridiagonalMatrix(TridiagonalMatrix& matrix) : TridiagonalMatrix(matrix.getSize())
    {
        std::copy_n(matrix.high_diag, size - 1, high_diag);
        std::copy_n(matrix.diag, size, diag);
        std::copy_n(matrix.low_diag, size - 1, low_diag);
    }
    double& TridiagonalMatrix::Element(int rows, int colums)
    {

        if (rows == colums)
        {
            return diag[colums];
        }
        else if (colums - rows == 1)
        {
            return high_diag[rows];
        }
        else if (rows - colums == 1)
        {
            return low_diag[colums];
        }
    }
    /// <summary>
    /// Задание элемента верхней диагонали
    /// </summary>
    /// <param name="row"> Индекс строки </param>
    /// <param name="value"> Записываемое значение </param>
    void TridiagonalMatrix::SetHighDiag(int row, double value)
    {
        high_diag[row] = value;
    }
    /// <summary>
    /// Задание элемента центральной диагонали
    /// </summary>
    /// <param name="row"> Индекс строки </param>
    /// <param name="value"> Записываемое значение </param>
    void TridiagonalMatrix::SetDiag(int row, double value)
    {
        diag[row] = value;
    }
    /// <summary>
    /// Задание элемента нижней диагонали
    /// </summary>
    /// <param name="row"> Индекс строки </param>
    /// <param name="value"> Записываемое значение </param>
    void TridiagonalMatrix::SetLowDiag(int row, double value)
    {
        low_diag[row - 1] = value;
    }
    /*void Print()
   {
       Console.WriteLine("Матрица коэффициентов:");
       for (int i = 0; i < size; i++)
       {
           for (int j = 0; j < size; j++)
           {
               Console.Write(this[i, j].ToString() + ' ');
           }
           Console.WriteLine();
       }
   }*/
   /// <summary>
   /// Выводит матрицу в виде системы уравнений с вектором значений b
   /// </summary>
   /// <param name="b"> Вектор значений </param>
  /* public void Print(double[] b)
   {
       Console.WriteLine("Матрица коэффициентов | значение:");
       for (int i = 0; i < size; i++)
       {
           for (int j = 0; j < size; j++)
           {
               Console.Write(this[i, j].ToString() + ' ');
           }
           Console.WriteLine(" | " + b[i]);
       }
   }*/
