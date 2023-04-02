#pragma once
#include <algorithm>
#include <iterator>
#include "Functions.h"
class TridiagonalMatrix
{
    double* diag;
    double* high_diag;
    double* low_diag;
    size_t size;

public:
    size_t getSize();
    TridiagonalMatrix();
    TridiagonalMatrix(int n);
    TridiagonalMatrix(TridiagonalMatrix& matrix);
    double& Element(int rows, int colums);
    /// <summary>
    /// Задание элемента верхней диагонали
    /// </summary>
    /// <param name="row"> Индекс строки </param>
    /// <param name="value"> Записываемое значение </param>
    void SetHighDiag(int row, double value);
    /// <summary>
    /// Задание элемента центральной диагонали
    /// </summary>
    /// <param name="row"> Индекс строки </param>
    /// <param name="value"> Записываемое значение </param>
    void SetDiag(int row, double value);
    /// <summary>
    /// Задание элемента нижней диагонали
    /// </summary>
    /// <param name="row"> Индекс строки </param>
    /// <param name="value"> Записываемое значение </param>
    void SetLowDiag(int row, double value);
   
};