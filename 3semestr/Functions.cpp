#pragma once
#include "Functions.h"
double Q(double x)
{
    return x + 1;
}
double P(double x)
{
    return 1 + pow(x, gamma);
}
double U(double x)
{
    return pow(x, alpha) * pow(1.0 - x, beta);
}
double a_i(int i)
{
    return P(i * h);
}
double q_i(int i)
{
    return Q(i * h);
}


double F(int i) //qu-p'u'-pu''
{
    double x = i * h;
    return Q(x) * U(x) -
        gamma * pow(x, gamma - 1) * //p'
        (alpha * pow(x, alpha - 1) * pow(1 - x, beta) -
            beta * pow(1 - x, beta - 1) * pow(x, alpha)) - //u'
        P(x) * ( //p * u''
            alpha * (alpha - 1) * pow(x, alpha - 2) * pow(1 - x, beta) -
            alpha * beta * pow(1 - x, beta - 1) * pow(x, alpha - 1) +
            beta * (beta - 1) * pow(1 - x, beta - 2) * pow(x, alpha) -
            alpha * beta * pow(x, alpha - 1) * pow(1 - x, beta - 1)
            );
}

