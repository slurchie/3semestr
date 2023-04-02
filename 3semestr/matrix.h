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
    /// ������� �������� ������� ���������
    /// </summary>
    /// <param name="row"> ������ ������ </param>
    /// <param name="value"> ������������ �������� </param>
    void SetHighDiag(int row, double value);
    /// <summary>
    /// ������� �������� ����������� ���������
    /// </summary>
    /// <param name="row"> ������ ������ </param>
    /// <param name="value"> ������������ �������� </param>
    void SetDiag(int row, double value);
    /// <summary>
    /// ������� �������� ������ ���������
    /// </summary>
    /// <param name="row"> ������ ������ </param>
    /// <param name="value"> ������������ �������� </param>
    void SetLowDiag(int row, double value);
   
};