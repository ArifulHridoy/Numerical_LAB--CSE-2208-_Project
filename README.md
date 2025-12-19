# Numerical Methods in C++

## Overview

Numerical Methods are mathematical techniques used to **approximate solutions** to problems that may not have exact analytical solutions. They are widely used in engineering, physics, computer science and many applied fields.

This project is a comprehensive collection of classical **Numerical Methods implemented in C++**, organized for easy learning and practical use.

---

# Table of Contents

- [Solution of Non-Linear Equations](#solution-of-non-linear-equations)
  - [Bisection Method](#bisection-method)
    - [Theory](#bisection-theory)
    - [Code](#bisection-code)
    - [Input](#bisection-input)
    - [Output](#bisection-output)
  - [False Position Method](#false-position-method)
    - [Theory](#false-position-theory)
    - [Code](#false-position-code)
    - [Input](#false-position-input)
    - [Output](#false-position-output)
  - [Newton Raphson Method](#newton-raphson-method)
    - [Theory](#newton-raphson-theory)
    - [Code](#newton-raphson-code)
    - [Input](#newton-raphson-input)
    - [Output](#newton-raphson-output)
  - [Secant Method](#secant-method)
    - [Theory](#secant-theory)
    - [Code](#secant-code)
    - [Input](#secant-input)
    - [Output](#secant-output)

- [Solution of Linear Equations](#solution-of-linear-equations)
  - [Gauss Elimination Method](#gauss-elimination-method)
    - [Theory](#gauss-elimination-theory)
    - [Code](#gauss-elimination-code)
    - [Input](#gauss-elimination-input)
    - [Output](#gauss-elimination-output)
  - [Gauss Jordan Elimination Method](#gauss-jordan-elimination-method)
    - [Theory](#gauss-jordan-theory)
    - [Code](#gauss-jordan-code)
    - [Input](#gauss-jordan-input)
    - [Output](#gauss-jordan-output)
  - [LU Decomposition Method](#lu-decomposition-method)
    - [Theory](#lu-decomposition-theory)
    - [Code](#lu-decomposition-code)
    - [Input](#lu-decomposition-input)
    - [Output](#lu-decomposition-output)
  - [Matrix Inversion](#matrix-inversion)
    - [Theory](#matrix-inversion-theory)
    - [Code](#matrix-inversion-code)
    - [Input](#matrix-inversion-input)
    - [Output](#matrix-inversion-output)

- [Differential Equation Solving](#differential-equation-solving)
  - [Runge-Kutta 4th Order Method](#runge-kutta-4th-order-method)
    - [Theory](#runge-kutta-theory)
    - [Code](#runge-kutta-code)
    - [Input](#runge-kutta-input)
    - [Output](#runge-kutta-output)

- [Interpolation Methods](#interpolation-methods)
  - [Newton Forward Interpolation](#newton-forward-interpolation)
    - [Theory](#newton-forward-theory)
    - [Code](#newton-forward-code)
    - [Input](#newton-forward-input)
    - [Output](#newton-forward-output)
  - [Newton Backward Interpolation](#newton-backward-interpolation)
    - [Theory](#newton-backward-theory)
    - [Code](#newton-backward-code)
    - [Input](#newton-backward-input)
    - [Output](#newton-backward-output)
  - [Newton Divided Difference Interpolation](#newton-divided-difference-interpolation)
    - [Theory](#newton-divided-difference-theory)
    - [Code](#newton-divided-difference-code)
    - [Input](#newton-divided-difference-input)
    - [Output](#newton-divided-difference-output)

- [Numerical Differentiation](#numerical-differentiation)
  - [Differentiation by Forward Interpolation](#differentiation-forward-interpolation)
    - [Theory](#differentiation-forward-theory)
    - [Code](#differentiation-forward-code)
    - [Input](#differentiation-forward-input)
    - [Output](#differentiation-forward-output)
  - [Differentiation by Backward Interpolation](#differentiation-backward-interpolation)
    - [Theory](#differentiation-backward-theory)
    - [Code](#differentiation-backward-code)
    - [Input](#differentiation-backward-input)
    - [Output](#differentiation-backward-output)

- [Curve Fitting / Regression](#curve-fitting--regression)
  - [Linear Regression](#linear-regression)
    - [Theory](#linear-regression-theory)
    - [Code](#linear-regression-code)
    - [Input](#linear-regression-input)
    - [Output](#linear-regression-output)
  - [Polynomial Regression](#polynomial-regression)
    - [Theory](#polynomial-regression-theory)
    - [Code](#polynomial-regression-code)
    - [Input](#polynomial-regression-input)
    - [Output](#polynomial-regression-output)
  - [Transcendental Regression](#transcendental-regression)
    - [Theory](#transcendental-regression-theory)
    - [Code](#transcendental-regression-code)
    - [Input](#transcendental-regression-input)
    - [Output](#transcendental-regression-output)

- [Numerical Integration](#numerical-integration)
  - [Simpson's 1/3 Rule](#simpsons-13-rule)
    - [Theory](#simpson-13-theory)
    - [Code](#simpson-13-code)
    - [Input](#simpson-13-input)
    - [Output](#simpson-13-output)
  - [Simpson's 3/8 Rule](#simpsons-38-rule)
    - [Theory](#simpson-38-theory)
    - [Code](#simpson-38-code)
    - [Input](#simpson-38-input)
    - [Output](#simpson-38-output)

---

## Solution of Non-Linear Equations

### Bisection Method

#### Bisection Theory

BISECTION METHOD - DOCUMENTATION
=================================

This program finds the roots of polynomial equations using the Bisection Method.
Supports multiple test cases in a single run.

INPUT FORMAT (Input.txt):
-------------------------
Line 1: Number of test cases (T)

For each test case:
  Line 1: Degree of polynomial (n)
  Line 2: Coefficients (n+1 values) from highest degree to constant term

EXAMPLE:
--------
Input.txt:
3
4
4 -9 0 0 4
3
1 -6 11 -6
2
1 0 -4

This represents 3 test cases:
1. Degree 4: f(x) = 4x^4 - 9x^3 + 4
2. Degree 3: f(x) = x^3 - 6x^2 + 11x - 6
3. Degree 2: f(x) = x^2 - 4

FEATURES:
---------
- Multiple test cases support
- Dynamic polynomial evaluation
- Automatic function string generation
- Removes duplicate roots
- Formatted output with precision control
- Error tolerance: 0.001 (default)

#### Bisection Code

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<double>coefficients;
int degree;

double f(double x)
{
    double result = 0;
    for(int i=0; i<=degree; i++) result+=coefficients[i]*pow(x,degree-i);
    return result;
}

string generateFunctionString()
{
    stringstream ss; ss<<"f(x) = ";
    bool first=true;

    for(int i=0; i<=degree; i++)
    {
        if(fabs(coefficients[i])<1e-10) continue;

        if(!first)
        {
            if(coefficients[i]>0) ss<<" + ";
            else ss<<" - ";
        }
        else
        {
            if(coefficients[i]<0)ss<<"-";
        }

        double absCoeff=fabs(coefficients[i]);
        int power=degree-i;

        if(power==0)
        {
            ss<<absCoeff;
        }
        else if(power==1)
        {
            if(fabs(absCoeff-1.0)<1e-10)ss<<"x";
            else ss<<absCoeff<<"x";
        }
        else
        {
            if(fabs(absCoeff-1.0)<1e-10) ss<<"x^"<<power;
            else ss<<absCoeff<<"x^"<<power;
        }

        first=false;
    }

    return ss.str();
}

double limCalc(double an, double an1, double an2)
{
    if(fabs(an)<1e-10) return 10.0;
    return sqrt((an1/an)*(an1/an)-2*(an2/an));
}

void removeDup(vector<double>&roots, double E)
{
    sort(roots.begin(),roots.end());
    roots.erase(unique(roots.begin(), roots.end(),
                       [&](double a,double b)
    {
        return fabs(a-b)<E;
    }),roots.end());
}

void solveTestCase(int testNum, ofstream &fout)
{
    string functionStr=generateFunctionString();
    vector<double>roots;
    double lim;
    if(degree>=2)
    {
        double an=coefficients[0];
        double an1=(degree>=1)?coefficients[1]:0;
        double an2=(degree>=2)?coefficients[2]:0;
        lim=limCalc(an,an1,an2);
    }
    else
    {
        lim=10.0;
    }

    double E=0.001;

    for(double i=-lim; i<=lim; i+=0.5)
    {
        double x1=i;
        double x2=i+0.5;

        if(fabs(f(x1))<E)
        {
            roots.push_back(x1);
            continue;
        }
        if(fabs(f(x2))<E)
        {
            roots.push_back(x2);
            i+=0.5;
            continue;
        }

        if(f(x1)*f(x2)<0)
        {
            while(fabs(x2-x1)>E)
            {
                double mid=(x1+x2)/2;
                if(fabs(f(mid))<E)
                {
                    x1=x2=mid;
                    break;
                }
                if(f(mid)*f(x1)<0)
                    x2=mid;
                else
                    x1=mid;
            }
            roots.push_back((x1+x2)/2);
        }
    }

    removeDup(roots,E);

    fout<<"\n"<<string(60,'=')<<"\n";
    fout<<"TEST CASE "<<testNum<<"\n";
    fout<<string(60, '=')<<"\n";
    fout<<"Function: "<<functionStr<<"\n";
    fout<<fixed<<setprecision(6);
    fout<<"Degree: "<<degree<<"\n";
    fout<<"Error Tolerance: "<<E<<"\n";
    fout<<"Search Limit: "<<lim<<"\n";
    fout<<"Roots:\n";
    if(roots.empty())
    {
        fout<<"  No roots found in the search range.\n";
    }
    else
    {
        for(double r : roots)
            fout<<"  x = "<<r<<"\n";
    }
    fout<<string(60,'=')<< "\n";
}

int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");

    int T;
    fin>>T;

    fout<<"BISECTION METHOD - MULTIPLE TEST CASES\n";
    fout<<"Total Test Cases: "<<T<<"\n";

    for(int testNum=1; testNum<=T; testNum++)
    {
        fin>>degree;
        coefficients.clear();
        coefficients.resize(degree+1);

        for(int i=0; i<=degree; i++)
            fin>>coefficients[i];

        solveTestCase(testNum,fout);
    }

    fin.close();
    fout.close();

    return 0;
}
```

#### Bisection Input

```
3
4
4 -9 0 0 4
3
1 -6 11 -6
2
1 0 -4
```

#### Bisection Output

```
BISECTION METHOD - MULTIPLE TEST CASES
Total Test Cases: 3

============================================================
TEST CASE 1
============================================================
Function: f(x) = 4x^4 - 9x^3 + 4
Degree: 4
Error Tolerance: 0.001000
Search Limit: 2.250000
Roots:
  x = 0.906250
  x = 2.148926
============================================================

============================================================
TEST CASE 2
============================================================
Function: f(x) = x^3 - 6x^2 + 11x - 6
Degree: 3
Error Tolerance: 0.001000
Search Limit: 3.741657
Roots:
  x = 0.999554
  x = 2.000530
  x = 2.999554
============================================================

============================================================
TEST CASE 3
============================================================
Function: f(x) = x^2 - 4
Degree: 2
Error Tolerance: 0.001000
Search Limit: 2.828427
Roots:
  x = -1.999814
  x = 2.000186
============================================================
```

---

### False Position Method

#### False Position Theory

FALSE POSITION METHOD - DOCUMENTATION

This program finds the roots of polynomial functions using the False Position Method.
Supports multiple test cases in a single run.

FALSE POSITION METHOD FORMULA:
------------------------------
x_n = (x_{n-1} * f(x_n) - x_n * f(x_{n-1})) / (f(x_n) - f(x_{n-1}))

The method uses regula falsi (false position) to find roots by linear interpolation.
It requires a sign change f(x_1) * f(x_2) < 0 in the interval [x_1, x_2].

INPUT FORMAT (Input.txt):
-------------------------
Line 1: Number of test cases (T)

For each test case:
  Line 1: Degree of polynomial (n)
  Line 2: Coefficients (n+1 values) from highest degree to constant term
  Line 3: Tolerance (E) - convergence criterion

EXAMPLE:
--------
Input.txt:
2
4
1 -5 0 4 0
0.0001
3
1 2 -5 -6
0.001

This represents 2 test cases:
1. f(x) = x^4 - 5x^3 + 4x with tolerance 0.0001
2. f(x) = x^3 + 2x^2 - 5x - 6 with tolerance 0.001

FEATURES:

- Multiple test cases support
- Dynamic polynomial evaluation
- Automatic function string generation
- Automatic root search with sign change detection
- Iteration count tracking for convergence analysis
- Duplicate root removal within tolerance
- Formatted output with precision control
- Console and file output simultaneously
- Input validation and error handling

#### False Position Code

```cpp
#include<bits/stdc++.h>

using namespace std;

double f(vector<double>&c,double x)
{
    double r=0;
    int d=c.size()-1;

    for(int i=0; i<c.size(); i++)
    {
        r+=c[i]*pow(x,d-i);
    }

    return r;
}

string genPoly(vector<double>&c)
{
    stringstream ss;

    int d=c.size()-1;

    for(int i=0; i<c.size(); i++)
    {
        int cd=d-i;
        double cf=c[i];

        if(i>0)
        {
            ss<<(cf>=0?" + ":" - ");
            cf=abs(cf);
        }

        if(cd==0)
        {
            ss<<fixed<<setprecision(4)<<cf;
        }

        else if(cd==1)
        {
            ss<<fixed<<setprecision(4)<<cf<<"*x";
        }

        else
        {
            ss<<fixed<<setprecision(4)<<cf<<"*x^"<<cd;
        }
    }

    return ss.str();
}

double limCalc(vector<double>&c)
{
    if(c.size()<3)return 10;

    return sqrt(abs((c[1]/c[0])*(c[1]/c[0])-2*(c[2]/c[0])));
}

int main()
{
    ifstream inputFile("Input.txt");
    ofstream outputFile("Output.txt");

    if(!inputFile.is_open())
    {
        cerr<<"Error opening Input.txt!"<<endl;
        return 1;
    }

    int testCases;
    inputFile>>testCases;

    for(int tc=1; tc<=testCases; tc++)
    {
        int degree;
        inputFile>>degree;

        vector<double>coefficients(degree+1);
        for(int i=0; i<=degree; i++)
        {
            inputFile>>coefficients[i];
        }

        double E;
        inputFile>>E;

        cout<<"Test Case "<<tc<<"\n";
        outputFile<<"Test Case "<<tc<<"\n";

        string polynomial=genPoly(coefficients);
        cout<<"Polynomial: f(x) = "<<polynomial<<"\n";

        outputFile<<"Polynomial: f(x) = "<<polynomial<<"\n";

        cout<<"Tolerance (E): "<<scientific<<E<<"\n";
        outputFile<<"Tolerance (E): "<<scientific<<E<<"\n";

        vector<double>roots;

        double lim=limCalc(coefficients);
        lim=min(lim,100.0);

        cout<<"Search limit: [-"<<lim<<", "<<lim<<"]\n";
        outputFile<<"Search limit: [-"<<lim<<", "<<lim<<"]\n";
        int cnt=0;

        for(double i=-lim; i<lim; i+=0.5)
        {
            double x1=i;
            double x2=i+0.5;

            if(fabs(f(coefficients,x1))<E)
            {
                roots.push_back(x1);
                continue;
            }

            if(fabs(f(coefficients,x2))<E)
            {
                roots.push_back(x2);
                continue;
            }

            if(f(coefficients,x1)*f(coefficients,x2)<0)
            {
                double fx1=f(coefficients,x1);
                double fx2=f(coefficients,x2);
                double x0;
                int iterations=0;
                while(fabs(x2-x1)>E)
                {
                    iterations++;
                    x0=(x1*fx2-x2*fx1)/(fx2-fx1);

                    double fx0=f(coefficients,x0);

                    if(fabs(fx0)<E)break;

                    if(fx0*fx1<0)
                    {
                        x2=x0;
                        fx2=fx0;
                    }
                    else
                    {
                        x1=x0;
                        fx1=fx0;
                    }
                }

                cnt++;
                cout<<"Root "<<cnt<<" found in ["<<fixed<<setprecision(4)<<x1<<", "<<x2<<"]: "<<x0<<" (Iterations: "<<iterations<<")\n";

                outputFile<<"Root "<<cnt<<" found in ["<<fixed<<setprecision(4)<<x1<<", "<<x2<<"]: "<<x0<<" (Iterations: "<<iterations<<")\n";
                roots.push_back(x0);
            }
        }
      sort(roots.begin(), roots.end());

roots.erase(
    unique(roots.begin(), roots.end(), [E](double a, double b)
    {
        return fabs(a - b) < E;
    }),
    roots.end()
);

        cout<<"All Real Roots:\n";
        outputFile<<"All Real Roots:\n";

        if(roots.empty())
        {
            cout<<"No roots found.\n";
            outputFile<<"No roots found.\n";
        }

        else
        {
            for(int i=0; i<roots.size(); i++)
            {
                cout<<"Root "<<(i+1)<<": "<<fixed<<setprecision(6)<<roots[i]<<"\n";
                outputFile<<"Root "<<(i+1)<<": "<<fixed<<setprecision(6)<<roots[i]<<"\n";
            }
        }
        cout<<"\n";
        outputFile<<"\n";
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
```

#### False Position Input

```
2
4
1 -5 0 4 0
0.0001
3
1 2 -5 -6
0.001
```

#### False Position Output

```
Test Case 1
Polynomial: f(x) = 1.0000*x^4 - 5.0000*x^3 + 0.0000*x^2 + 4.0000*x + 0.0000
Tolerance (E): 1.000000e-04
Search limit: [-5.000000e+00, 5.000000e+00]
Root 1 found in [-1.0000, -0.8284]: -0.8284 (Iterations: 9)
Root 2 found in [4.8284, 5.0000]: 4.8284 (Iterations: 6)
All Real Roots:
Root 1: -0.828423
Root 2: 0.000000
Root 3: 1.000000
Root 4: 4.828427

Test Case 2
Polynomial: f(x) = 1.0000*x^3 + 2.0000*x^2 - 5.0000*x - 6.0000
Tolerance (E): 1.000000e-03
Search limit: [-3.741657e+00, 3.741657e+00]
Root 1 found in [-3.2417, -2.9999]: -3.0000 (Iterations: 5)
Root 2 found in [-1.0003, -0.7417]: -1.0000 (Iterations: 3)
Root 3 found in [1.9995, 2.2583]: 1.9999 (Iterations: 4)
All Real Roots:
Root 1: -2.999978
Root 2: -1.000010
Root 3: 1.999936
```

---

### Newton Raphson Method

#### Newton Raphson Theory

NEWTON-RAPHSON METHOD - DOCUMENTATION

This program finds roots of polynomial functions using the Newton-Raphson iterative method.
Supports multiple test cases with automatic root finding in specified intervals.

NEWTON-RAPHSON FORMULA:
-----------------------
x_{n+1} = x_n - f(x_n) / f'(x_n)

Starting from an initial guess x₀, the method iteratively improves the approximation
until convergence. Requires the function to be differentiable.

CONVERGENCE CRITERIA:
--------------------
The iteration stops when:
  |x_{n+1} - x_n| < E  (successive approximations are close)
  OR
  |f(x_n)| < E  (function value is near zero)

The method has quadratic convergence near simple roots, making it very efficient.

INPUT FORMAT (Input.txt):
-------------------------
Line 1: Number of test cases (T)

For each test case:
  Line 1: Degree of polynomial (n)
  Line 2: Coefficients (n+1 values) from highest degree to constant term
  Line 3: Search interval [a, b], Tolerance (E)
  Line 4: Maximum iterations allowed

EXAMPLE:
--------
Input.txt:
2
3
1 -6 11 -6
0 5 0.0001
50
4
1 0 -5 0 4
-3 5 0.0001
100

This represents 2 test cases:
1. f(x) = x³ - 6x² + 11x - 6, search in [0,5], tolerance 0.0001, max 50 iterations
2. f(x) = x⁴ - 5x² + 4, search in [-3,5], tolerance 0.0001, max 100 iterations

FEATURES:

- Multiple test cases support
- Automatic polynomial evaluation
- Derivative calculation (analytical)
- Multiple starting points for comprehensive root finding
- Duplicate root filtering
- Iteration count tracking for each root
- Division by zero protection (checks if f'(x) ≈ 0)
- Invalid result filtering (checks for NaN/Inf)
- High precision output (6 decimal places)
- Console and file output simultaneously

#### Newton Raphson Code

```cpp
#include<bits/stdc++.h>

using namespace std;

double evalPoly(const vector<double>&c,double x)
{
    double val=0;
    int n=c.size();

    for(int i=0; i<n; i++)
    {
        val+=c[i]*pow(x,n-1-i);
    }
    return val;
}

double evalDeriv(const vector<double>&c,double x)
{
    double val=0;
    int n=c.size();

    for(int i=0; i<n-1; i++)
    {
        val+=(n-1-i)*c[i]*pow(x,n-2-i);
    }
    return val;
}

string printPoly(const vector<double>&c)
{
    stringstream ss;
    int n=c.size();
    bool first=true;

    for(int i=0; i<n; i++)
    {
        double a=c[i];
        int p=n-1-i;

        if(fabs(a)<1e-12)continue;
        if(!first&&a>=0)ss<<" + ";

        else if(a<0)
        {
            ss<<" - ";
            a=-a;
        }

        if(p==0)ss<<a;
        else if(p==1)ss<<a<<"x";
        else ss<<a<<"x^"<<p;

        first=false;
    }

    return ss.str();
}

int main()
{
    ifstream inputFile("Input.txt");
    ofstream outputFile("Output.txt");

    if(!inputFile.is_open())
    {
        cerr<<"Error opening Input.txt!"<<endl;
        return 1;
    }

    int testCases;
    inputFile>>testCases;

    for(int tc=1; tc<=testCases; tc++)
    {
        int deg;
        inputFile>>deg;

        vector<double>coef(deg+1);

        for(int i=0; i<=deg; i++)inputFile>>coef[i];

        double a,b,E;
        inputFile>>a>>b>>E;

        int maxIter;
        inputFile>>maxIter;

        cout<<"Test Case "<<tc<<"\n";
        outputFile<<"Test Case "<<tc<<"\n";

        string poly=printPoly(coef);
        cout<<"Polynomial: f(x) = "<<poly<<"\n";

        outputFile<<"Polynomial: f(x) = "<<poly<<"\n";
        cout<<"Search interval: ["<<a<<", "<<b<<"]\n";

        outputFile<<"Search interval: ["<<a<<", "<<b<<"]\n";
        cout<<"Tolerance (E): "<<scientific<<E<<"\n";

        outputFile<<"Tolerance (E): "<<scientific<<E<<"\n";
        cout<<"Max iterations: "<<maxIter<<"\n";

        outputFile<<"Max iterations: "<<maxIter<<"\n";
        set<double>roots;

        int counter=1;

        for(double x=a; x<=b; x+=0.5)
        {
            double x_curr=x;
            double x1;
            int i;

            for(i=1; i<=maxIter; i++)
            {
                double fx=evalPoly(coef,x_curr);
                double fdx=evalDeriv(coef,x_curr);

                if(fabs(fdx)<1e-12)break;
                x1=x_curr-fx/fdx;

                if(fabs(x1-x_curr)<E||fabs(fx)<E)break;
                x_curr=x1;
            }

            double rRounded=round(x1*1000.0)/1000.0;

            if(!isfinite(rRounded))continue;

            if(roots.find(rRounded)==roots.end())
            {
                roots.insert(rRounded);
                cout<<"Root "<<counter<<" = "<<fixed<<setprecision(6)<<rRounded<<" (Iterations: "<<i<<")\n";
                outputFile<<"Root "<<counter<<" = "<<fixed<<setprecision(6)<<rRounded<<" (Iterations: "<<i<<")\n";
                counter++;
            }
        }

        if(roots.empty())
        {
            cout<<"No real roots found.\n";
            outputFile<<"No real roots found.\n";
        }

        cout<<"\n";
        outputFile<<"\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
```

#### Newton Raphson Input

```
2
3
1 -6 11 -6
0 5 0.0001
50
4
1 0 -5 0 4
-3 5 0.0001
100
```

#### Newton Raphson Output

```
Test Case 1
Polynomial: f(x) = 1x^3 - 6x^2 + 11x - 6
Search interval: [0, 5]
Tolerance (E): 1.000000e-04
Max iterations: 50
Root 1 = 1.000000 (Iterations: 6)
Root 2 = 3.000000 (Iterations: 2)
Root 3 = 2.000000 (Iterations: 1)

Test Case 2
Polynomial: f(x) = 1x^4 - 5x^2 + 4
Search interval: [-3.000000, 5.000000]
Tolerance (E): 1.000000e-04
Max iterations: 100
Root 1 = -2.000000 (Iterations: 6)
Root 2 = -1.000000 (Iterations: 1)
Root 3 = 1.000000 (Iterations: 4)
Root 4 = 2.000000 (Iterations: 13)
```

---

### Secant Method

#### Secant Theory

SECANT METHOD – DOCUMENTATION 

This program finds real roots of polynomial equations using the Secant Method. 
It supports multiple test cases, file input, and outputs results to both the console and a text file. 
PURPOSE 
To determine all real roots of a polynomial by applying the Secant Method across a calculated 
search interval. 
The program reads polynomial coefficients from an input file and applies numerical root-finding 
to each test case. 

METHOD OVERVIEW :

The Secant Method is an iterative numerical technique used to approximate roots of equations 
of the form: 

		f(x)=0  
It uses two initial guesses and applies: 

			xn+1=  (𝑥0𝑓(𝑥1)−𝑥1𝑓(𝑥0))/(𝑥1)−𝑓(𝑥0)
Iteration continues until: 

		∣xn+1−xn∣<ϵ and ∣f(xn+1)∣<ϵ  
where ε is the error tolerance. 

POLYNOMIAL EVALUATION:

The polynomial is defined as:

		f(x)=a0+a1x+a2x2+⋯+anxn 
		
Coefficients are supplied from highest degree to constant term but internally reversed for 
computation. 

ROOT BOUND (Cauchy's Bound) :

To ensure all real roots are  detected, the program computes: 

		∣x∣ ≤  1 + max (∣𝑎𝑖/𝑎𝑛∣) 
This value defines the search interval: [−B,B],
where B is the computed bound. 

STEP-WISE ROOT SEARCH :

The interval is scanned using small sub-intervals: 

• Step size: 0.45 

• Error tolerance: 0.001 

Each sub-interval [x, x + 0.45] becomes an initial guess pair for the Secant method. 

Duplicate roots (closely spaced values) are automatically ignored. 

INPUT FORMAT (input.txt) 

T 

n 

a_n a_(n−1) ... a_1 a_0 

a_n a_(n−1) ... a_1 a_0 

... 
Where: 

• T = number of test cases 

• n = degree of the polynomial 

• Next line has n+1 coefficients from highest degree to constant term 

EXAMPLE INPUT 

3 

2

1 -5 6 

3 

1 -6 11 -6 

4 

1 0 -7 0 6 

This represents 3 polynomials: 

	1. x2−5x+6x  
	2. x3−6x2+11x−6 
	3. x4−7x2+6
 
OUTPUT DESCRIPTION 

For each test case, the program outputs:

1. The polynomial in readable form

2. The computed root bound 

3. Each detected real root 

4. The interval used in Secant Method 

5. Number of iterations required 

6. A separator line between test cases
   
Output is written: 

• To console 

• To output.txt 

 
OUTPUT EXAMPLE 
 
Polynomial: 1x^2 - 5x + 6 

Root bound: 6 

range: [1.800000, 1.350000] Root: 2.000371 Iterations: 4 

range: [2.700000, 2.250000] Root: 3.000117 Iterations: 4

--------------------------------------- 
 
FEATURES 

• Supports multiple test cases

• Uses Cauchy’s Bound to guarantee root coverage 

• Detects and avoids duplicate roots 

• Outputs to both console and file (output.txt)

• Formatted polynomial printing

• Error tolerance = 0.001 

• Step size = 0.45 

#### Secant Code

```cpp
#include<bits/stdc++.h>
using namespace std;
vector<double> roots;
ofstream fout;


double f(double x, const vector<double>& v)
{
    double poly = 0;
    for(int i = 0; i < v.size(); i++)
        poly += v[i] * pow(x, i);
    return poly;
}

void poly(const vector<double>& v)
{
    bool firstTerm = true;
    int n = v.size();

    for(int i = n - 1; i >= 0; i--)
    {
        if(fabs(v[i]) < 1e-12) continue;

        if(!firstTerm)
        {
            if(v[i] < 0) cout << " - ", fout << " - ";
            else cout << " + ", fout << " + ";
        }
        else
        {
            if(v[i] < 0) cout << "-", fout << "-";
            firstTerm = false;
        }

        double c = fabs(v[i]);

        if(i == 0) cout << c, fout << c;
        else if(i == 1) cout << c << "x", fout << c << "x";
        else cout << c << "x^" << i, fout << c << "x^" << i;
    }

    cout << endl;
    fout << endl;
}


void secant(double x0, double x1, double error, vector<double>& v)
{
    double x2;
    int it = 0;

    while(fabs(x1 - x0) >= error && fabs(f(x1, v)) >= error)
    {
        double fx0 = f(x0, v);
        double fx1 = f(x1, v);

        if(fabs(fx1 - fx0) < 1e-12) return;

        x2 = (x0 * fx1 - x1 * fx0) / (fx1 - fx0);
        it++;

        x0 = x1;
        x1 = x2;
    }

    if(fabs(f(x2, v)) > error) return;

    for(double r : roots)
        if(fabs(r - x2) < error) return;

    roots.push_back(x2);

    cout << fixed << setprecision(6);
    fout << fixed << setprecision(6);

    cout << "range: [" << x0 << ", " << x1 << "] ";
    fout << "range: [" << x0 << ", " << x1 << "] ";

    cout << "Root: " << x2 << " Iterations: " << it << endl;
    fout << "Root: " << x2 << " Iterations: " << it << endl;
}

int main()
{
    ifstream fin("Input.txt");
    fout.open("Output.txt");

    if(!fin.is_open())
    {
        cout << "Cannot open input.txt" << endl;
        return 0;
    }

    int t;
    fin >> t;

    while(t--)
    {
        roots.clear();

        int n;
        fin >> n;

        int m = n + 1;
        vector<double> v(m);

        for(double &x : v) fin >> x;
        reverse(v.begin(), v.end());

        cout << "\nPolynomial: ";
        fout << "\nPolynomial: ";
        poly(v);

        double xmax = 0;
        for(int i = 0; i < m; i++)
            xmax = max(xmax, 1.0 + fabs(v[i] / v[n]));

        cout << "Root bound: " << xmax << endl;
        fout << "Root bound: " << xmax << endl;

        double step = 0.45;
        double error = 1e-3;

        for(double i = -xmax; i <= xmax; i += step)
            secant(i, i + step, error, v);

        cout << "---------------------------------------\n";
        fout << "---------------------------------------\n";
    }

    fin.close();
    fout.close();
    return 0;
}
```

#### Secant Input

```
3
2
1 -5 6
3
1 -6 11 -6
4
1 0 -7 0 6
```

#### Secant Output

```
Polynomial: 1x^2 - 5x + 6
Root bound: 7
range: [1.997448, 1.999937] Root: 1.999937 Iterations: 9
range: [2.997955, 3.000031] Root: 3.000031 Iterations: 4
---------------------------------------

Polynomial: 1.000000x^3 - 6.000000x^2 + 11.000000x - 6.000000
Root bound: 12.000000
range: [0.995828, 0.999820] Root: 0.999820 Iterations: 13
range: [2.019031, 1.999970] Root: 1.999970 Iterations: 2
range: [2.998532, 2.999971] Root: 2.999971 Iterations: 6
---------------------------------------

Polynomial: 1.000000x^4 - 7.000000x^2 + 6.000000
Root bound: 8.000000
range: [-2.450095, -2.449497] Root: -2.449497 Iterations: 11
range: [0.999352, 1.000006] Root: 1.000006 Iterations: 9
range: [-0.999423, -1.000006] Root: -1.000006 Iterations: 3
range: [2.449534, 2.449490] Root: 2.449490 Iterations: 5
---------------------------------------
```

---

## Solution of Linear Equations

### Gauss Elimination Method

#### Gauss Elimination Theory

Gaussian Elimination Report

What it does
- Solves linear systems using Gaussian elimination with partial pivoting.
- Detects three outcomes per test case: Unique Solution, No Solution (inconsistent), Infinite Solutions (dependent).
- Handles multiple test cases in a single run, reading from Input.txt and writing to Output.txt while printing to console.

Input format (Input.txt)
- First line: T (number of test cases)
- For each test case:
  - Line: n (number of variables/rows)
  - Next n lines: n+1 numbers per line representing the augmented matrix [A|b]

Algorithm steps
1) Partial pivoting each column to select the largest pivot.
2) Forward elimination to upper-triangular form.
3) Consistency checks for zero/near-zero pivots and zero rows.
4) Back substitution when a unique solution exists.

Theory (brief)
- Gaussian elimination transforms the augmented matrix [A|b] into an upper-triangular form U via elementary row operations.
- Partial pivoting swaps rows to place the largest available pivot on the diagonal, reducing numerical error and avoiding division by tiny pivots.
- If a pivot column becomes all zeros but the augmented part is non-zero, the system is inconsistent (no solution). If both are zero, the system may have infinitely many solutions.
- Once U is obtained with non-zero diagonal entries, back substitution solves Ux = c efficiently from bottom to top.

Output format
- For each test case, console and Output.txt show:
  - Header: Test Case k (nxn)
  - Labeled block: Matrix: followed by the augmented matrix values to 3 decimals
  - Result line:
      * Unique Solution
          x1 = value
          x2 = value
          ...
      * No Solution
      * Infinite Solutions

Notes
- Uses a tolerance of 1e-10 to treat pivots or coefficients as zero for stability.

#### Gauss Elimination Code

```cpp
#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<double>>& a, int n, ofstream& out)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
            out<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
        }
        cout<<"\n";
        out<<"\n";
    }
}

void solve(vector<vector<double>> &a, int n, ofstream &out)
{
    for(int i=0; i<n-1; i++)
    {
        int maxRow=i;
        for(int k=i+1; k<n; k++)
        {
            if(abs(a[k][i])>abs(a[maxRow][i]))
            {
                maxRow=k;
            }
        }
        if(maxRow!=i)
        {
            swap(a[i],a[maxRow]);
        }
        if(abs(a[i][i])<1e-10)
        {
            bool consistent=true;
            for(int j=i+1; j<n; j++)
            {
                bool allZero=true;
                for(int k=i; k<n; k++)
                {
                    if(abs(a[j][k])>1e-10)
                    {
                        allZero=false;
                        break;
                    }
                }
                if(allZero && abs(a[j][n])>1e-10)
                {
                    consistent=false;
                    break;
                }
            }
            if(!consistent)
            {
                cout<<"\nNo Solution (Inconsistent)\n";
                out<<"\nNo Solution (Inconsistent)\n";
                return;
            }
            else
            {
                cout<<"\nInfinite Solutions\n";
                out<<"\nInfinite Solutions\n";
                return;
            }
        }
        for(int j=i+1; j<n; j++)
        {
            double factor=a[j][i]/a[i][i];
            for(int k=i; k<=n; k++)
            {
                a[j][k]=a[j][k]-factor*a[i][k];
            }
        }
    }
    bool zeroRow=true;
    for(int k=0; k<n; k++)
    {
        if(abs(a[n-1][k])>1e-10)
        {
            zeroRow=false;
            break;
        }
    }
    if(zeroRow && abs(a[n-1][n])>1e-10)
    {
        cout<<"\nNo Solution!\n";
        out<<"\nNo Solution!\n";
        return;
    }
    if(abs(a[n-1][n-1])<1e-10)
    {
        cout<<"\nInfinite Solutions!\n";
        out<<"\nInfinite Solutions!\n";
        return;
    }
    vector<double> x(n);
    for(int i=n-1; i>=0; i--)
    {
        double sum=0;
        for(int j=i+1; j<n; j++)
        {
            sum=sum+a[i][j]*x[j];
        }
        x[i]=(a[i][n]-sum)/a[i][i];
    }
    cout<<"\nUnique Solution!\n";
    out<<"\nUnique Solution!\n";
    for(int i=0; i<n; i++)
    {
        cout<<fixed<<setprecision(3)<<"x"<<i+1<<" = "<<x[i]<<"\n";
        out<<fixed<<setprecision(3)<<"x"<<i+1<<" = "<<x[i]<<"\n";
    }
}

int main()
{
    ifstream inFile("Input.txt");
    ofstream outFile("Output.txt");
    int testCases;
    inFile>>testCases;
    cout<<"GAUSSIAN ELIMINATION\n";
    outFile<<"GAUSSIAN ELIMINATION\n";
    for(int t=1; t<=testCases; t++)
    {
        int n;
        inFile>>n;
        cout<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";
        outFile<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";
        vector<vector<double>> a(n,vector<double>(n+1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                inFile>>a[i][j];
            }
        }
        cout<<"Matrix:\n";
        outFile<<"Matrix:\n";
        printMatrix(a,n,outFile);
        solve(a,n,outFile);
    }
    inFile.close();
    outFile.close();
    return 0;
}
```

#### Gauss Elimination Input

```
4

3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

2
1 2 3
2 4 5

3
2 4 6 8
1 2 3 4
3 6 9 12

2
1 1 2
1 1 3
```

#### Gauss Elimination Output

```
GAUSSIAN ELIMINATION

Test Case 1 (3x3)
Matrix:
     2.000      1.000     -1.000      8.000 
    -3.000     -1.000      2.000    -11.000 
    -2.000      1.000      2.000     -3.000 

Unique Solution!
x1 = 2.000
x2 = 3.000
x3 = -1.000

Test Case 2 (2x2)
Matrix:
     1.000      2.000      3.000 
     2.000      4.000      5.000 

No Solution!

Test Case 3 (3x3)
Matrix:
     2.000      4.000      6.000      8.000 
     1.000      2.000      3.000      4.000 
     3.000      6.000      9.000     12.000 

Infinite Solutions

Test Case 4 (2x2)
Matrix:
     1.000      1.000      2.000 
     1.000      1.000      3.000 

No Solution!
```

---

### Gauss Jordan Elimination Method

#### Gauss Jordan Theory

Gauss-Jordan Elimination Report

What it does :
- Solves linear systems using Gauss-Jordan elimination with partial pivoting.
- Reduces the augmented matrix to Reduced Row Echelon Form (RREF).
- Detects three outcomes per test case: Unique Solution, No Solution (inconsistent), Infinite Solutions (dependent).
- Handles multiple test cases in one run, reading from Input.txt and writing to Output.txt while printing to console.

Algorithm steps
1) Partial pivoting: swap the current row with the row having the largest absolute pivot in the column.
2) Scale the pivot row so the pivot becomes 1.
3) Eliminate the pivot column in all other rows to reach RREF.
4) Check ranks to classify: inconsistent, infinite solutions, or unique solution (read directly from RREF).

Theory (brief)
- Gauss-Jordan applies row operations to convert [A|b] directly to RREF, where each pivot is 1 and the pivot columns have zeros elsewhere.
- Partial pivoting improves numerical stability and avoids dividing by tiny pivots.
- Rank comparison: if rank(A) < rank([A|b]) → inconsistent; if rank(A) < n but rank(A) == rank([A|b]) → infinite solutions; if rank(A) = n → unique solution.

#### Gauss Jordan Code

```cpp

#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

void printMatrix(vector<vector<double>>& a, int n, ofstream& out)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}
}

bool hasCoefficient(const vector<double>& row, int n)
{
	for(int j=0; j<n; j++)
	{
		if(abs(row[j])>EPS) return true;
	}
	return false;
}

void solve(vector<vector<double>>& a, int n, ofstream& out)
{
	for(int col=0, row=0; col<n && row<n; col++, row++)
	{
		int pivot=row;
		for(int r=row+1; r<n; r++)
		{
			if(abs(a[r][col])>abs(a[pivot][col])) pivot=r;
		}
		if(abs(a[pivot][col])<EPS)
		{
			row--;
			continue;
		}
		if(pivot!=row) swap(a[pivot],a[row]);
		double pivotVal=a[row][col];
		for(int j=col; j<=n; j++) a[row][j]/=pivotVal;
		for(int r=0; r<n; r++)
		{
			if(r==row) continue;
			double factor=a[r][col];
			if(abs(factor)<EPS) continue;
			for(int j=col; j<=n; j++) a[r][j]-=factor*a[row][j];
		}
	}

	cout<<"\nReduced Row Echelon Form:\n";
	out<<"\nReduced Row Echelon Form:\n";
	printMatrix(a,n,out);

	bool inconsistent=false;
	int rankA=0, rankAug=0;
	for(int i=0; i<n; i++)
	{
		bool coeffNZ=hasCoefficient(a[i],n);
		bool augNZ=coeffNZ || abs(a[i][n])>EPS;
		if(!coeffNZ && abs(a[i][n])>EPS)
		{
			inconsistent=true;
			break;
		}
		if(coeffNZ) rankA++;
		if(augNZ) rankAug++;
	}

	if(inconsistent)
	{
		cout<<"\nNo Solution (Inconsistent)\n";
		out<<"\nNo Solution (Inconsistent)\n";
		return;
	}

	if(rankA< n)
	{
		cout<<"\nInfinite Solutions\n";
		out<<"\nInfinite Solutions\n";
		return;
	}

	vector<double> x(n);
	for(int i=0; i<n; i++) x[i]=a[i][n];

	cout<<"\nUnique Solution!\n";
	out<<"\nUnique Solution!\n";
	for(int i=0; i<n; i++)
	{
		cout<<fixed<<setprecision(3)<<"x"<<i+1<<" = "<<x[i]<<"\n";
		out<<fixed<<setprecision(3)<<"x"<<i+1<<" = "<<x[i]<<"\n";
	}
}

int main()
{
	ifstream inFile("Input.txt");
	ofstream outFile("Output.txt");

	int testCases;
	inFile>>testCases;

	cout<<"GAUSS JORDAN ELIMINATION\n";
	outFile<<"GAUSS JORDAN ELIMINATION\n";

	for(int t=1; t<=testCases; t++)
	{
		int n;
		inFile>>n;

		cout<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";
		outFile<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";

		vector<vector<double>> a(n,vector<double>(n+1));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<=n; j++) inFile>>a[i][j];
		}

		cout<<"Matrix:\n";
		outFile<<"Matrix:\n";
		printMatrix(a,n,outFile);

		solve(a,n,outFile);
	}

	inFile.close();
	outFile.close();
	return 0;
}
```

#### Gauss Jordan Input

```

4

3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

2
1 2 3
2 4 5

3
2 4 6 8
1 2 3 4
3 6 9 12

2
1 1 2
1 1 3
```

#### Gauss Jordan Output

```
GAUSS JORDAN ELIMINATION

Test Case 1 (3x3)
Matrix:
     2.000      1.000     -1.000      8.000 
    -3.000     -1.000      2.000    -11.000 
    -2.000      1.000      2.000     -3.000 

Reduced Row Echelon Form:
     1.000      0.000      0.000      2.000 
     0.000      1.000      0.000      3.000 
     0.000      0.000      1.000     -1.000 

Unique Solution!
x1 = 2.000
x2 = 3.000
x3 = -1.000

Test Case 2 (2x2)
Matrix:
     1.000      2.000      3.000 
     2.000      4.000      5.000 

Reduced Row Echelon Form:
     1.000      2.000      2.500 
     0.000      0.000      0.500 

No Solution (Inconsistent)

Test Case 3 (3x3)
Matrix:
     2.000      4.000      6.000      8.000 
     1.000      2.000      3.000      4.000 
     3.000      6.000      9.000     12.000 

Reduced Row Echelon Form:
     1.000      2.000      3.000      4.000 
     0.000      0.000      0.000      0.000 
     0.000      0.000      0.000      0.000 

Infinite Solutions

Test Case 4 (2x2)
Matrix:
     1.000      1.000      2.000 
     1.000      1.000      3.000 

Reduced Row Echelon Form:
     1.000      1.000      2.000 
     0.000      0.000      1.000 

No Solution (Inconsistent)
```

---

### LU Decomposition Method

#### LU Decomposition Theory

LU Decomposition (Doolittle) Report

What it does :
- Solves linear systems by factoring A into L (unit lower) and U (upper) using the Doolittle method.
- Handles multiple test cases, reading from Input.txt, writing to Output.txt, and printing to console.
- Reports L and U matrices; classifies outcomes: unique solution, no solution (inconsistent), or infinitely many solutions (singular but consistent).

Algorithm steps :
1) Doolittle LU factorization without pivoting: U has diagonals from A, L has 1s on the diagonal.
2) Compute y via forward substitution (Ly = b).
3) Detect singularity: if any |U[i][i]| < EPS, flag singular and inspect rows of U with y to classify.
4) If singular and a zero row in U has nonzero y → No solution; if singular and zero row with zero y → Infinite solutions.
5) Only when all pivots are nonzero run back substitution (Ux = y) and print unique solution; always print L and U matrices.

Theory (brief) :
- For nonsingular A with nonzero leading principal minors, A = LU exists with L unit lower-triangular and U upper-triangular (Doolittle sets L diagonals to 1).
- Factorization cost is O(n^3); triangular solves are O(n^2).
- If a pivot is zero, det(A) = 0.

#### LU Decomposition Code

```cpp
#include<bits/stdc++.h>
using namespace std;

const double EPS=1e-10;

void printMatrix(const vector<vector<double>>&a, int n, ofstream& out)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}
}

bool decompose(const vector<vector<double>>&a, vector<vector<double>>&L, vector<vector<double>>&U, int n, bool &singular)
{
	singular=false;
	for(int i=0; i<n; i++)
	{
		for(int k=i; k<n; k++)
		{
			double sum=0;
			for(int j=0; j<i; j++) sum+=L[i][j]*U[j][k];
			U[i][k]=a[i][k]-sum;
		}
		if(abs(U[i][i])<EPS)
		{
			singular=true;
			U[i][i]=0.0;
			L[i][i]=1.0;
			for(int k=i+1; k<n; k++) L[k][i]=0.0;
			continue;
		}
		for(int k=i; k<n; k++)
		{
			if(i==k) L[i][i]=1.0;
			else
			{
				double sum=0;
				for(int j=0; j<i; j++) sum+=L[k][j]*U[j][i];
				L[k][i]=(a[k][i]-sum)/U[i][i];
			}
		}
	}
	return true;
}

vector<double>forwardSub(const vector<vector<double>>&L, const vector<double>&b, int n)
{
	vector<double>y(n);
	for(int i=0; i<n; i++)
	{
		double sum=0;
		for(int j=0; j<i; j++) sum+=L[i][j]*y[j];
		y[i]=(b[i]-sum)/L[i][i];
	}
	return y;
}

vector<double>backSub(const vector<vector<double>>&U, const vector<double>&y, int n)
{
	vector<double>x(n);
	for(int i=n-1; i>=0; i--)
	{
		double sum=0;
		for(int j=i+1; j<n; j++) sum+=U[i][j]*x[j];
		x[i]=(y[i]-sum)/U[i][i];
	}
	return x;
}

void solve(vector<vector<double>>a, int n, ofstream &out)
{
	vector<vector<double>>L(n,vector<double>(n,0)),U(n,vector<double>(n,0));
	bool singular=false;

	decompose(a,L,U,n,singular);

	vector<double> b(n);
	for(int i=0; i<n; i++) b[i]=a[i][n];

	vector<double>y=forwardSub(L,b,n);

	bool zeroPivot=false, inconsistent=false;
	for(int i=0; i<n; i++)
	{
		if(abs(U[i][i])<EPS) zeroPivot=true;
		bool rowZero=true;
		for(int j=0; j<n; j++)
		{
			if(abs(U[i][j])>EPS)
			{
				rowZero=false;
				break;
			}
		}
		if(rowZero && abs(y[i])>EPS) inconsistent=true;
	}

	cout<<"\nL matrix:\n";
	out<<"\nL matrix:\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<L[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<L[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}

	cout<<"\nU matrix:\n";
	out<<"\nU matrix:\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<U[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<U[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}

	if(zeroPivot||singular)
	{
		cout<<"\nMatrix A is singular (det A = 0)\n";
		out<<"\nMatrix A is singular (det A = 0)\n";
		if(inconsistent)
		{
			cout<<"=> System has NO solution.\n";
			out<<"=> System has NO solution.\n";
		}
		else
		{
			cout<<"=> System has infinitely many solutions.\n";
			out<<"=> System has infinitely many solutions.\n";
		}
		return;
	}

	vector<double>x=backSub(U,y,n);

	cout<<"\nUnique Solution!\n";
	out<<"\nUnique Solution!\n";
	for(int i=0; i<n; i++)
	{
		cout<<fixed<<setprecision(3)<<"x"<<i+1<<" = "<<x[i]<<"\n";
		out<<fixed<<setprecision(3)<<"x"<<i+1<<" = "<<x[i]<<"\n";
	}
}

int main()
{
	ifstream inFile("Input.txt");
	ofstream outFile("Output.txt");

	int testCases;
	inFile>>testCases;

	cout<<"LU DECOMPOSITION (Doolittle)\n";
	outFile<<"LU DECOMPOSITION (Doolittle)\n";

	for(int t=1; t<=testCases; t++)
	{
		int n;
		inFile>>n;

		cout<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";
		outFile<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";

		vector<vector<double>> a(n,vector<double>(n+1));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<=n; j++) inFile>>a[i][j];
		}

		cout<<"Matrix:\n";
		outFile<<"Matrix:\n";
		printMatrix(a,n,outFile);

		solve(a,n,outFile);
	}

	inFile.close();
	outFile.close();
	return 0;
}
```

#### LU Decomposition Input

```
4

3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

2
1 2 3
2 4 5

3
2 4 6 8
1 2 3 4
3 6 9 12

2
1 1 2
1 1 3
```

#### LU Decomposition Output

```
LU DECOMPOSITION (Doolittle)

Test Case 1 (3x3)
Matrix:
     2.000      1.000     -1.000      8.000 
    -3.000     -1.000      2.000    -11.000 
    -2.000      1.000      2.000     -3.000 

L matrix:
     1.000      0.000      0.000 
    -1.500      1.000      0.000 
    -1.000      4.000      1.000 

U matrix:
     2.000      1.000     -1.000 
     0.000      0.500      0.500 
     0.000      0.000     -1.000 

Unique Solution!
x1 = 2.000
x2 = 3.000
x3 = -1.000

Test Case 2 (2x2)
Matrix:
     1.000      2.000      3.000 
     2.000      4.000      5.000 

L matrix:
     1.000      0.000 
     2.000      1.000 

U matrix:
     1.000      2.000 
     0.000      0.000 

Matrix A is singular (det A = 0)
=> System has NO solution.

Test Case 3 (3x3)
Matrix:
     2.000      4.000      6.000      8.000 
     1.000      2.000      3.000      4.000 
     3.000      6.000      9.000     12.000 

L matrix:
     1.000      0.000      0.000 
     0.500      1.000      0.000 
     1.500      0.000      1.000 

U matrix:
     2.000      4.000      6.000 
     0.000      0.000      0.000 
     0.000      0.000      0.000 

Matrix A is singular (det A = 0)
=> System has infinitely many solutions.

Test Case 4 (2x2)
Matrix:
     1.000      1.000      2.000 
     1.000      1.000      3.000 

L matrix:
     1.000      0.000 
     1.000      1.000 

U matrix:
     1.000      1.000 
     0.000      0.000 

Matrix A is singular (det A = 0)
=> System has NO solution.
```

---

### Matrix Inversion

#### Matrix Inversion Theory

Matrix Inversion Report

What it does :
- Solves linear systems AX = b by computing A^-1 using Gauss-Jordan elimination on augmented [A|I].
- Handles multiple test cases, reading from Input.txt (matrix A and vector b per test case), writing to Output.txt, and printing to console.
- Reports the inverse matrix A^-1 and the solution vector x = A^-1 * b.
- Detects singular matrices (det = 0) and reports failure.

Algorithm steps :
1) Construct augmented matrix [A|I] by appending identity matrix to A.
2) Apply Gauss-Jordan elimination (forward and back substitution simultaneously) with partial pivoting to reduce [A|I] to [I|A^-1].
3) If a pivot is ~zero (|pivot| < EPS = 1e-10), matrix is singular; report failure.
4) Extract A^-1 from the right half of the RREF matrix.
5) Compute solution x = A^-1 * b by matrix-vector multiplication.

Theory (brief) :
- Matrix inversion by Gauss-Jordan is equivalent to solving n systems Ae_i = b_i for unit vectors e_i.
- By augmenting with I and reducing to RREF, the right block becomes A^-1.
- Computational cost is O(n^3) for factorization; multiplication by b adds O(n^2).

#### Matrix Inversion Code

```cpp
#include<bits/stdc++.h>
using namespace std;

const double EPS=1e-10;

void printMatrix(const vector<vector<double>>&a, int n, ofstream&out)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}
}

void printAugmented(const vector<vector<double>>&a, int n, ofstream&out)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}
}

bool invert(vector<vector<double>>&a, vector<vector<double>>&inv, int n, ofstream&out)
{
	vector<vector<double>> aug(n, vector<double>(2*n));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			aug[i][j]=a[i][j];
			aug[i][n+j]=(i==j) ? 1.0 : 0.0;
		}
	}

	cout<<"\nAugmented [A|I]:\n";
	out<<"\nAugmented [A|I]:\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2*n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<aug[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<aug[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}

	for(int col=0, row=0; col<n && row<n; col++, row++)
	{
		int pivot=row;
		for(int r=row+1; r<n; r++)
		{
			if(abs(aug[r][col])>abs(aug[pivot][col])) pivot=r;
		}

		if(abs(aug[pivot][col])<EPS)
		{
			cout<<"\nMatrix is singular (det=0)\n";
			out<<"\nMatrix is singular (det=0)\n";
			return false;
		}

		if(pivot!=row) swap(aug[pivot],aug[row]);

		double pivotVal = aug[row][col];
		for(int j=0; j<2*n; j++) aug[row][j] /= pivotVal;

		for(int r=0; r<n; r++)
		{
			if(r==row) continue;
			double factor = aug[r][col];
			if(abs(factor)<EPS) continue;
			for(int j=0; j<2*n; j++) aug[r][j]-=factor*aug[row][j];
		}
	}

	cout<<"\nReduced Row Echelon Form [I|A^-1]:\n";
	out<<"\nReduced Row Echelon Form [I|A^-1]:\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2*n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<aug[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<aug[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++) inv[i][j]=aug[i][n+j];
	}

	return true;
}

void solve(vector<vector<double>>a, vector<double>b, int n, ofstream &out)
{
	cout<<"\nMatrix A:\n";
	out<<"\nMatrix A:\n";
	printMatrix(a,n,out);

	cout<<"\nVector b:\n";
	out<<"\nVector b:\n";
	for(int i=0; i<n; i++)
	{
		cout<<fixed<<setprecision(3)<<setw(10)<<b[i]<<"\n";
		out<<fixed<<setprecision(3)<<setw(10)<<b[i]<<"\n";
	}

	vector<vector<double>>inv(n, vector<double>(n));

	if(!invert(a,inv,n,out))
	{
		return;
	}

	cout<<"\nInverse Matrix A^-1:\n";
	out<<"\nInverse Matrix A^-1:\n";
	printMatrix(inv, n, out);

	vector<double> x(n, 0);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++) x[i]+=inv[i][j]*b[j];
	}

	cout<<"\nSolution (x = A^-1 * b):\n";
	out<<"\nSolution (x = A^-1 * b):\n";
	for(int i=0; i<n; i++)
	{
		cout<<fixed<<setprecision(3)<<"x"<<i+1<<" = "<<x[i]<<"\n";
		out<<fixed<<setprecision(3)<<"x"<<i+1<<" = "<<x[i]<<"\n";
	}
}

int main()
{
	ifstream inFile("Input.txt");
	ofstream outFile("Output.txt");

	int testCases;
	inFile>>testCases;

	cout<<"MATRIX INVERSION\n";
	outFile<<"MATRIX INVERSION\n";

	for(int t=1; t<=testCases; t++)
	{
		int n; inFile>>n;

		cout<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";
		outFile<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";

		vector<vector<double>> a(n,vector<double>(n));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++) inFile>>a[i][j];
		}

		vector<double> b(n);
		for(int i=0; i<n; i++) inFile>>b[i];

		solve(a,b,n,outFile);
	}

	inFile.close();
	outFile.close();
	return 0;
}
```

#### Matrix Inversion Input

```
4

3
2 1 -1
-3 -1 2
-2 1 2
8 -11 -3

2
1 2
2 4
3 5

3
2 4 6
1 2 3
3 6 9
8 4 12

2
1 1
1 1
2 3
```

#### Matrix Inversion Output

```
MATRIX INVERSION

Test Case 1 (3x3)

Matrix A:
     2.000      1.000     -1.000 
    -3.000     -1.000      2.000 
    -2.000      1.000      2.000 

Vector b:
     8.000
   -11.000
    -3.000

Augmented [A|I]:
     2.000      1.000     -1.000      1.000      0.000      0.000 
    -3.000     -1.000      2.000      0.000      1.000      0.000 
    -2.000      1.000      2.000      0.000      0.000      1.000 

Reduced Row Echelon Form [I|A^-1]:
     1.000      0.000      0.000      4.000      3.000     -1.000 
     0.000      1.000      0.000     -2.000     -2.000      1.000 
     0.000      0.000      1.000      5.000      4.000     -1.000 

Inverse Matrix A^-1:
     4.000      3.000     -1.000 
    -2.000     -2.000      1.000 
     5.000      4.000     -1.000 

Solution (x = A^-1 * b):
x1 = 2.000
x2 = 3.000
x3 = -1.000

Test Case 2 (2x2)

Matrix A:
     1.000      2.000 
     2.000      4.000 

Vector b:
     3.000
     5.000

Augmented [A|I]:
     1.000      2.000      1.000      0.000 
     2.000      4.000      0.000      1.000 

Matrix is singular (det=0)

Test Case 3 (3x3)

Matrix A:
     2.000      4.000      6.000 
     1.000      2.000      3.000 
     3.000      6.000      9.000 

Vector b:
     8.000
     4.000
    12.000

Augmented [A|I]:
     2.000      4.000      6.000      1.000      0.000      0.000 
     1.000      2.000      3.000      0.000      1.000      0.000 
     3.000      6.000      9.000      0.000      0.000      1.000 

Matrix is singular (det=0)

Test Case 4 (2x2)

Matrix A:
     1.000      1.000 
     1.000      1.000 

Vector b:
     2.000
     3.000

Augmented [A|I]:
     1.000      1.000      1.000      0.000 
     1.000      1.000      0.000      1.000 

Matrix is singular (det=0)
```

---

## Differential Equation Solving

### Runge-Kutta 4th Order Method

#### Runge-Kutta Theory

RUNGE-KUTTA 4TH ORDER METHOD - DOCUMENTATION

This program solves differential equations using the Runge-Kutta 4th Order method.
Supports multiple test cases with different initial conditions.

FUNCTION:
---------
dy/dx = f(x,y) = xy + y

RUNGE-KUTTA 4TH ORDER FORMULA:

y(n+1) = y(n) + (h/6)[k1 + 2k2 + 2k3 + k4]
where:
  k1 = h*f(x(n), y(n))
  k2 = h*f(x(n) + h/2, y(n) + k1/2)
  k3 = h*f(x(n) + h/2, y(n) + k2/2)
  k4 = h*f(x(n) + h, y(n) + k3)

FEATURES:
- Multiple test cases support
- Fixed step size: h = 0.001
- Adaptive iteration count based on x range
- Accurate 4th order method
- Formatted output with precision control

#### Runge-Kutta Code

```cpp
#include<bits/stdc++.h>
using namespace std;
#define db double

double f(double x,double y)
{
    return x*y+y;
}

double rk4(db x,db y,db h)
{
    db k1=h*f(x,y);
    db k2=h*f(x+h/2.0,y+k1/2.0);
    db k3=h*f(x+h/2.0,y+k2/2.0);
    db k4=h*f(x+h,y+k3);
    return y+(1.0/6.0)*(k1+2*k2+2*k3+k4);
}

void solve(int t,db x0,db y0,db xn,db h,ofstream& fout)
{
    db x=x0,y=y0;
    int steps=0;

        while(x+1e-12<xn)
        {
            y=rk4(x,y,h);
            x+=h;
            steps++;
        }

    fout<<"\nTEST CASE #"<<t<<endl<<endl;
    fout<<fixed<<setprecision(3);
    fout<<"Initial x0: "<<x0<<", y0: "<<y0<<endl;
    fout<<"Final x: "<<xn<<endl;
    fout<<"Step size (h): "<<h<<endl;
    fout<<"Number of steps: "<<steps<<endl;
    fout<<"Result: y("<<xn<<") = "<<y<<endl;

    cout<<"\nTEST CASE #"<<t<<endl<<endl;
    cout<<fixed<<setprecision(3);
    cout<<"Initial x0: "<<x0<<", y0: "<<y0<<endl;
    cout<<"Final x: "<<xn<<endl;
    cout<<"Step size (h): "<<h<<endl;
    cout<<"Number of steps: "<<steps<<endl;
    cout<<"Result: y("<<xn<<") = "<<y<<endl;
}

int main(){
    ifstream fin("Input.txt");
    if(!fin.is_open())
    {
        cout<<"Error: Could not open Input.txt";
        return 0;
    }

    int T;
    fin>>T;

    ofstream fout("Output.txt");
    fout<<"Function: f(x,y) = xy + y\n";
    fout<<"Total Test Cases: "<<T<<"\n";

    cout<<"Function: f(x,y) = xy + y\n";
    cout<<"Total Test Cases: "<<T<<"\n";

    double h=0.001;

    for(int t=1;t<=T;t++)
    {
        double x0,y0,xn;
        fin>>x0>>y0>>xn;
        double step=h;
        if(xn<x0) step=-h;

        solve(t,x0,y0,xn,step,fout);
    }

    fin.close();
    fout.close();

    cout<<"\nAll test cases completed! Results saved to Output.txt\n";
    return 0;
}
```

#### Runge-Kutta Input

```
3
0 1 1
0 2 2
1 1 3
```

#### Runge-Kutta Output

```
Function: f(x,y) = xy + y
Total Test Cases: 3

TEST CASE #1

Initial x0: 0.000, y0: 1.000
Final x: 1.000
Step size (h): 0.001
Number of steps: 1000
Result: y(1.000) = 4.482

TEST CASE #2

Initial x0: 0.000, y0: 2.000
Final x: 2.000
Step size (h): 0.001
Number of steps: 2000
Result: y(2.000) = 109.196

TEST CASE #3

Initial x0: 1.000, y0: 1.000
Final x: 3.000
Step size (h): 0.001
Number of steps: 2000
Result: y(3.000) = 403.429
```

---

## Interpolation Methods

### Newton Forward Interpolation

#### Newton Forward Theory

NEWTON FORWARD INTERPOLATION - DOCUMENTATION

This program performs Newton Forward Interpolation to estimate function values at intermediate points.
Supports multiple test cases with automatic polynomial order detection.

NEWTON FORWARD INTERPOLATION FORMULA:
-------------------------------------
f(x) = f(x₀) + uΔf(x₀) + [u(u-1)/2!]Δ²f(x₀) + [u(u-1)(u-2)/3!]Δ³f(x₀) + ...

where:
  u = (x - x₀) / h
  h = step size (x₁ - x₀)
  Δⁿf(x₀) = nth forward difference at x₀

FORWARD DIFFERENCE TABLE:
-------------------------
Δf(xᵢ) = f(xᵢ₊₁) - f(xᵢ)
Δ²f(xᵢ) = Δf(xᵢ₊₁) - Δf(xᵢ)
Δⁿf(xᵢ) = Δⁿ⁻¹f(xᵢ₊₁) - Δⁿ⁻¹f(xᵢ)

Best suited for interpolation near the beginning of the data table.
Requires equally spaced x values.

#### Newton Forward Code

```cpp
#include<bits/stdc++.h>

using namespace std;

int fact(int n)
{
    return(n<=1)?1:n*fact(n-1);
}

int detectOrder(const vector<vector<double>>&dd,double eps=1e-6)
{
    int n=dd.size();

    for(int j=1; j<n; j++)
    {
        bool allZero=true;

        for(int i=0; i<n-j; i++)
        {
            if(fabs(dd[i][j])>eps)
            {
                allZero=false;
                break;
            }
        }

        if(allZero)return j-1;
    }

    return n-1;
}

int main()
{

    ifstream inputFile("Input.txt");
    ofstream outputFile("Output.txt");

    if(!inputFile.is_open())
    {
        cerr<<"Error opening Input.txt!"<<endl;
        return 1;
    }

    int testCases;
    inputFile>>testCases;

    for(int tc=1; tc<=testCases; tc++)
    {
        int n;
        inputFile>>n;

        vector<double>x(n),y(n);

        for(int i=0; i<n; i++)inputFile>>x[i];
        for(int i=0; i<n; i++)inputFile>>y[i];

        double X;
        inputFile>>X;

        cout<<"Test Case "<<tc<<"\n";
        outputFile<<"Test Case "<<tc<<"\n";

        cout<<"Number of data points: "<<n<<"\n";
        outputFile<<"Number of data points: "<<n<<"\n";

        cout<<"Data points (x, y):\n";
        outputFile<<"Data points (x, y):\n";

        for(int i=0; i<n; i++)
        {
            cout<<"("<<x[i]<<", "<<y[i]<<")\n";
            outputFile<<"("<<x[i]<<", "<<y[i]<<")\n";
        }

        cout<<"Interpolation point X: "<<X<<"\n";
        outputFile<<"Interpolation point X: "<<X<<"\n";

        double h=x[1]-x[0];
        double u=(X-x[0])/h;

        vector<vector<double>>diff(n,vector<double>(n,0));

        for(int i=0; i<n; i++)diff[i][0]=y[i];

        for(int j=1; j<n; j++)
        {
            for(int i=0; i<n-j; i++)
            {
                diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
            }
        }

        cout<<"Forward Difference Table:\n";
        outputFile<<"Forward Difference Table:\n";

        for(int i=0; i<n; i++)
        {
            cout<<"y["<<i<<"] = "<<fixed<<setprecision(6)<<diff[i][0];
            outputFile<<"y["<<i<<"] = "<<fixed<<setprecision(6)<<diff[i][0];

            for(int j=1; j<n-i; j++)
            {
                cout<<" | "<<diff[i][j];
                outputFile<<" | "<<diff[i][j];
            }

            cout<<"\n";
            outputFile<<"\n";
        }

        double fx=diff[0][0];
        double u_term=1;

        for(int k=1; k<n; k++)
        {
            u_term*=(u-(k-1));
            fx+=(u_term*diff[0][k])/fact(k);
        }

        int order=detectOrder(diff);

        cout<<"Step size (h): "<<h<<"\n";
        outputFile<<"Step size (h): "<<h<<"\n";

        cout<<"u value: "<<u<<"\n";
        outputFile<<"u value: "<<u<<"\n";

        cout<<"Detected Polynomial Order: "<<order<<"\n";
        outputFile<<"Detected Polynomial Order: "<<order<<"\n";

        cout<<"Interpolated value f("<<X<<") = "<<fixed<<setprecision(6)<<fx<<"\n";
        outputFile<<"Interpolated value f("<<X<<") = "<<fixed<<setprecision(6)<<fx<<"\n";

        cout<<"\n";
        outputFile<<"\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
```

#### Newton Forward Input

```
2
5
0 1 2 3 4
1 2 4 8 16
2.5
4
1 2 3 4
1 8 27 64
2.5
```

#### Newton Forward Output

```
Test Case 1
Number of data points: 5
Data points (x, y):
(0, 1)
(1, 2)
(2, 4)
(3, 8)
(4, 16)
Interpolation point X: 2.5
Forward Difference Table:
y[0] = 1.000000 | 1.000000 | 1.000000 | 1.000000 | 1.000000
y[1] = 2.000000 | 2.000000 | 2.000000 | 2.000000
y[2] = 4.000000 | 4.000000 | 4.000000
y[3] = 8.000000 | 8.000000
y[4] = 16.000000
Step size (h): 1.000000
u value: 2.500000
Detected Polynomial Order: 4
Interpolated value f(2.500000) = 5.648438

Test Case 2
Number of data points: 4
Data points (x, y):
(1, 1)
(2, 8)
(3, 27)
(4, 64)
Interpolation point X: 2.5
Forward Difference Table:
y[0] = 1.000000 | 7.000000 | 12.000000 | 6.000000
y[1] = 8.000000 | 19.000000 | 18.000000
y[2] = 27.000000 | 37.000000
y[3] = 64.000000
Step size (h): 1.000000
u value: 1.500000
Detected Polynomial Order: 2
Interpolated value f(2.500000) = 15.625000
```

---

### Newton Backward Interpolation

#### Newton Backward Theory

Newton Backward Interpolation – Documentation 
This program performs Newton Backward Interpolation to estimate the value of a function at a 
given point using backward differences of tabulated data. 

OBJECTIVE 
To calculate the interpolated value f(X) for a given value X from a set of discrete data points   
(xi, yi) using Newton Backward Interpolation formula. 

THEORY 

For n data points x0, x1, ..., xn-1 with corresponding function values y0, y1, ..., yn-1, the backward 
interpolation formula is: 

		f(𝑋) = 𝑦𝑛 + 𝑣 𝛥𝑦𝑛 + (𝑣(𝑣+1)/2! ) 𝛥²𝑦𝑛 + (𝑣(𝑣+1)(𝑣+2)/3! ) 𝛥³𝑦𝑛 + ... 
		
Where: 

	• yn = yn-1 
	• v = (𝑋 − 𝑥𝑛)/ℎ
	• h = xi – xi-1  
    Δk yn = k-th backward difference at last point 

INPUT FORMAT (input.txt) 

T 

n 

x1 x2 ... xn 

y1 y2 ... yn 

X 

(repeat for T test cases) 

EXAMPLE INPUT 

4

5 

1 2 3 4 5 

2 4 8 16 32

3 

4 

10 20 30 40

5 7 10 15 

35 

3

0 1 2 

1 3 7 

1

5 

2 4 6 8 10 

4 8 18 32 50 

7  

OUTPUT (Console + output.txt) 

For each test case, the program prints: 
1. Test Case Number 
2. Number of data points (n) 
3. x[] and y[] values 
4. Interpolation point X 
5. Full backward difference table (n×n including zeros) 
6. Interpolated value at X 
EXAMPLE OUTPUT:

TestCase#1 

n: 5 

x: 1 2 3 4 5 

y: 2 4 8 16 32

X: 3 

Backward Difference Table: 

2 0 0 0 0
   
4 2 0 0 0 

8 4 2 0 0 

16 8 4 2 0 

32 16 8 4 2 

Interpolated Value: 8

ALGORITHM :

1. Read number of test cases T
• For each test case: 
a. Read n, x[], y[], X.

b. Initialize n×n difference table with zeros.

c. Fill first column with y[] values .

d. Compute backward differences column by column. 

e. Apply Newton Backward Formula to compute interpolated value .

f. Print inputs, difference table, and interpolated value to console and output file.


FEATURES:

• Handles multiple test cases.

• Works with uniformly spaced data points.

• Prints full backward difference table including zeros.

• Displays all input and output for clarity.

• Outputs results to both console and output.txt.

#### Newton Backward Code

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

int fact(int n)
{
    if(n==0 or n==1) return 1;
    else return n*fact(n-1);
}

db backward(vector<db>&x, vector<db>&y, int X, vector<vector<db>>&diff)
{
    int n=x.size();
    db h=x[n-1]-x[n-2];
    db v=(X-x[n-1])/h;

    for(int i=0;i<n;i++) diff[i][0]=y[i];

    for(int j=1;j<n;j++)
    {
        for(int i=n-1;i>=j;i--)
        {
            diff[i][j]=diff[i][j-1]-diff[i-1][j-1];
        }
    }

    db ans=y[n-1];
    db term=1;

    for(int i=1;i<n;i++)
    {
        term=term*(v+(i-1));
        ans+=(term*diff[n-1][i])/fact(i);
    }

    return ans;
}

void solve(ifstream&fin, ofstream&fout, int tc)
{
    int n;
    fin>>n;

    vector<db>x(n),y(n);
    for(int i=0;i<n;i++) fin>>x[i];
    for(int i=0;i<n;i++) fin>>y[i];

    int X;
    fin>>X;

    vector<vector<db>>diff(n, vector<db>(n,0));

    db ans=backward(x,y,X,diff);

    cout<<"TestCase #"<<tc<<endl;;
    cout<<"n: "<<n<<endl;
    cout<<"x: ";
    for(auto &i:x) cout<<i<<" ";
    cout<<"\ny: ";
    for(auto &i:y) cout<<i<<" ";
    cout<<"\nX: "<<X<<"\n";

    cout<<endl<<"Backward DifferenceTable:"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<diff[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Interpolated Value: "<<ans<<endl<<endl;;

    fout<<"TestCase #"<<tc<<endl;
    fout<<"n: "<<n<<"\n";
    fout<<"x: ";
    for(auto &i:x) fout<<i<<" ";
    fout<<"\ny: ";
    for(auto &i:y) fout<<i<<" ";
    fout<<"\nX: "<<X<<endl;

    fout<<endl<<"Backward Difference Table:"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fout<<diff[i][j]<<" ";
        }
        fout<<endl;
    }

    fout<<"Interpolated Value: "<<ans<<endl<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout<<"Error: input.txt not found"<<endl;;
        return 0;
    }

    int T;
    fin>>T;

    cout<<"Total Test Cases: "<<T<<endl<<endl;;
    fout<<"Total Test Cases: "<<T<<endl<<endl;;

    for(int tc=1;tc<=T;tc++)
    {
        solve(fin,fout,tc);
    }

    cout<<"Output written in output.txt\n";

    return 0;
}
```

#### Newton Backward Input

```
4
5
1 2 3 4 5
2 4 8 16 32
3

4
10 20 30 40
5 7 10 15
35

3
0 1 2
1 3 7
1

5
2 4 6 8 10
4 8 18 32 50
7
```

#### Newton Backward Output

```
Total Test Cases: 4

TestCase #1
n: 5
x: 1 2 3 4 5 
y: 2 4 8 16 32 
X: 3

Backward Difference Table:

2 0 0 0 0 
4 2 0 0 0 
8 4 2 0 0 
16 8 4 2 0 
32 16 8 4 2 
Interpolated Value: 8

TestCase #2
n: 4
x: 10 20 30 40 
y: 5 7 10 15 
X: 35

Backward Difference Table:

5 0 0 0 
7 2 0 0 
10 3 1 0 
15 5 2 1 
Interpolated Value: 12.1875
```

---

### Newton Divided Difference Interpolation

#### Newton Divided Difference Theory

NEWTON DIVIDED DIFFERENCE INTERPOLATION

This program performs Newton Forward Interpolation using the divided difference method to 
estimate the value of a function at a given point X from unequally spaced data points. 
OBJECTIVE 
To calculate the interpolated value f(X) for a given value X using Newton Forward Interpolation 
when the data points are not equally spaced. 

THEORY 

Newton Forward Interpolation for unequal spacing uses divided differences. 
For n+1 data points (𝑥0, 𝑦0),(𝑥1,𝑦1),... ,(𝑥𝑛, 𝑦𝑛), the polynomial is: 

		P𝑛(𝑋) = 𝑓[𝑥0] + (𝑋−𝑥0)𝑓[𝑥0,𝑥1] + (𝑋−𝑥0)(𝑋−𝑥1)𝑓[𝑥0,𝑥1,𝑥2] + ...+ (𝑋−𝑥0)...(𝑋 −𝑥_{𝑛 −1})𝑓[𝑥0,...,𝑥𝑛] 
		
Where 𝑓[𝑥𝑖,...,𝑥𝑗] are divided differences, computed as: 

	f[𝑥𝑖] = 𝑦𝑖  
	f[𝑥𝑖, 𝑥𝑖 + 1] = (𝑓[𝑥𝑖 +1] − 𝑓[𝑥𝑖]) /(𝑥𝑖 +1−𝑥𝑖) 
	f[𝑥𝑖, . . . , 𝑥𝑖 + 𝑘] = (𝑓[𝑥𝑖 +1,...,𝑥𝑖 + 𝑘] − 𝑓[𝑥_𝑖,...,𝑥_𝑖 + 𝑘 − 1])/(𝑥𝑖 +𝑘 − 𝑥𝑖)
The error of interpolation is given by: 

		e𝑟𝑟𝑜𝑟(𝑋) = 𝑓[𝑥0,...,𝑥𝑛](𝑋 − 𝑥0)(𝑋 −𝑥1)...(𝑋 −𝑥𝑛 −1) 
		
INPUT FORMAT (input.txt) 

T  

N 

x0 x1 ... xn

y0 y1 ... yn 

X 

EXAMPLE INPUT 

1 

4 

1 4 5 7 10 

2 20 30 56 100 

8 

OUTPUT (Console + output.txt) 

For each test case, the program prints: 
1. Test Case Number 
2. Number of data points (n) 
3. x[] and y[] values 
4. Interpolation point X 
5. Full divided difference table (n+1 x n+1 including zeros) 
6. Interpolated value at X 
7. Truncation error

EXAMPLE OUTPUT

Test Case  #1 

n: 4 

x: 1.0000 4.0000 5.0000 7.0000 10.0000 

y: 2.0000 20.0000 30.0000 56.0000 100.0000 

X: 8

Difference Table:

2.0000 6.0000 1.0000 0.0000 -0.0123

20.0000 10.0000 1.0000 -0.1111 0.0000 

30.0000 13.0000 0.3333 0.0000 0.0000

56.0000 14.6667 0.0000 0.0000 0.0000

100.0000 0.0000 0.0000 0.0000 0.0000

Interpolation: 70.9630 

Truncation error: 1.0370

ALGORITHM 

1. Read number of test cases T 
2. For each test case:
  
• Read n, x[], y[], X

• Initialize (n+1)x(n+2) difference table with zeros

• Fill first column with y[] values 

• Compute divided differences column by column

• Apply Newton Forward formula to compute interpolated value

• Compute true error 

• Print inputs, difference table, interpolated value, and error to console and output file 
FEATURES 

• Handles multiple test cases

• Works with unequally spaced data

• Prints full divided difference table including zeros

• Displays all input and output for clarity

• Outputs results to both console and output.txt

This method works for both equally and unequally spaced data points.



#### Newton Divided Difference Code

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

vector<vector<db>> difftable(vector<double>&x, vector<double>&y)
{
    int n=x.size();
    vector<vector<db>> diff(n, vector<db>(n+1,0));
    for(int i=0;i<n;i++) diff[i][0]=y[i];
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            diff[i][j]=(diff[i+1][j-1]-diff[i][j-1])/(x[i+j]-x[i]);
        }
    }
    return diff;
}

double poly(vector<db>&x, vector<vector<db>>&diff, int X)
{
    db fx=diff[0][0];
    int n=x.size();
    db term=1;
    for(int i=1;i<n;i++)
    {
        term*=(X-x[i-1]);
        fx+=diff[0][i]*term;
    }
    return fx;
}

double error(vector<db>&x, vector<vector<db>>&diff, int X)
{
    int n=x.size()-1;
    db fxn=diff[0][n];
    db pd=1;
    for(int i=0;i<n;i++) pd*=(X-x[i]);
    return fabs(fxn*pd);
}

void solve(ifstream&fin, ofstream&fout, int tc)
{
    int n;
    fin>>n;
    vector<double> x(n+1), y(n+1);
    for(int i=0;i<=n;i++) fin>>x[i];
    for(int i=0;i<=n;i++) fin>>y[i];
    int X;
    fin>>X;

    auto diff=difftable(x,y);
    db res=poly(x,diff,X);
    db er=error(x,diff,X);

    cout<<fixed<<setprecision(4);
    fout<<fixed<<setprecision(4);

    cout<<"TestCase #"<<tc<<endl;
    cout<<"n: "<<n<<"\n";
    cout<<"x: "; for(auto &i:x) cout<<i<<" ";
    cout<<"\ny: "; for(auto &i:y) cout<<i<<" ";
    cout<<"\nX: "<<X<<endl;

    cout<<endl<<"DifferenceTable:"<<endl<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<diff[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    cout<<"Interpolation: "<<res<<endl;
    cout<<"Truncation error: "<<er<<endl<<endl;

    fout<<"TestCase #"<<tc<<endl;
    fout<<"n: "<<n<<endl;
    fout<<"x: "; for(auto &i:x) fout<<i<<" ";
    fout<<"\ny: "; for(auto &i:y) fout<<i<<" ";
    fout<<"\nX: "<<X<<endl;

    fout<<endl<<"DifferenceTable:"<<endl<<endl;;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            fout<<diff[i][j]<<" ";
        fout<<endl;
    }
    fout<<endl;
    fout<<"Interpolation: "<<res<<"\n";
    fout<<"Truncation error: "<<er<<endl<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout<<"Error: input.txt not found\n";
        return 0;
    }

    int T;
    fin>>T;

    cout<<"Total TestCases: "<<T<<endl<<endl;
    fout<<"Total TestCases: "<<T<<endl<<endl;

    for(int tc=1;tc<=T;tc++)
    {
        solve(fin,fout,tc);
    }

    cout<<"Output written in output.txt"<<endl;
    return 0;
}
```

#### Newton Divided Difference Input

```
6
3
2 5 6 8
4 25 36 64
5
2
0 1 2
0 1 4
1
4
1 3 4 6 7
2 6 12 24 32
5
2
1 2 4
1 3 15
3
3
0 2 5 7
1 8 30 70
6
4
1 4 5 7 10
2 20 30 56 100
8
```

#### Newton Divided Difference Output

```
Total TestCases: 6

TestCase #1
n: 3
x: 2.0000 5.0000 6.0000 8.0000 
y: 4.0000 25.0000 36.0000 64.0000 
X: 5

DifferenceTable:

4.0000 7.0000 1.0000 0.0000 
25.0000 11.0000 1.0000 0.0000 
36.0000 14.0000 0.0000 0.0000 
64.0000 0.0000 0.0000 0.0000 

Interpolation: 25.0000
Truncation error: 0.0000

TestCase #2
n: 2
x: 0.0000 1.0000 2.0000 
y: 0.0000 1.0000 4.0000 
X: 1

DifferenceTable:

0.0000 1.0000 1.0000 
1.0000 3.0000 0.0000 
4.0000 0.0000 0.0000 

Interpolation: 1.0000
Truncation error: 0.0000
```

---

## Numerical Differentiation

### Differentiation by Forward Interpolation

#### Differentiation Forward Theory

The objective of this experiment is to calculate the first and second derivatives of a function at 
a given point using Newton’s Forward Interpolation formula. The program uses equally spaced 
data points and compares the computed derivatives with the analytical derivatives to 
determine the error. 

Theory 

Newton’s Forward Interpolation is a numerical method for estimating function values and their 
derivatives using a set of discrete data points. For a function f(x)f(x)f(x) evaluated at equally 
spaced points x0,x1,...,xn  the derivatives at a point XXX can be approximated as: 
Forward Difference Table 


• First Derivative f′(X) 

	Δ1yi = yi+1−yi 
	Δ2yi = Δ1yi+1−Δ1yi 
	Δ3yi = Δ2yi+1−Δ2yi 
Where 

		𝑦𝑖 = 𝑓(𝑥𝑖) 
		
Derivative Formulas :

		𝑓′(𝑋) ≈ (𝑦0 + (2𝑢−1)𝛥2𝑦0/2! + (3𝑢2−6𝑢+2)𝛥3𝑦0/3! +⋯)/ℎ
• Second Derivative

		𝑓′′(𝑋) ≈ (𝛥2𝑦0+(𝑢 −1)𝛥3𝑦0+⋯) /ℎ2
Where: 

	 u=(𝑋−𝑥0)/ℎ 
	 ℎ=𝑥(𝑖+1)−𝑥𝑖  
	 
Error Calculation :

The computed derivatives are compared with analytical derivatives f′(X) and f′′(X): 

	Error  = ∣𝐴𝑛𝑎𝑙𝑦𝑡𝑖𝑐𝑎𝑙−𝑁𝑢𝑚𝑒𝑟𝑖𝑐𝑎𝑙∣/𝐴𝑛𝑎𝑙𝑦𝑡𝑖𝑐𝑎𝑙×100  
 
Input Format (input.txt) 

• Line 1: Number of test cases T 

• For each test case: 

o n → number of intervals 

o a b → start and end of interval 

o X → point at which derivatives are computed 

Example: 

4 

4

1 2

1.5 

5

0 1 

0.5 

6 

1 3 

2.5

3 

2 4

3.2 

 
Output 
• For each test case, the program outputs:

• Test case number 

• Number of intervals, a, b, and X 

• Forward difference table 

• First derivative f′(X) 

• Second derivative f′′(X) 

• Percentage errors of first and second derivatives 

Example Console / Output.txt format:

TEST CASE #1 

n: 4, a: 1, b: 2, X: 1.5 

Difference table:

2         1         0		0

3         2			1		0

5         4			1		0

9         6         0		0

... 

y': 4.123 

y'': 5.456 

First diff error: 0.0123% 

Second diff error: 0.0345%

Algorithm / Steps  

1. Read number of test cases T. 

2. For each test case: 

• Read 𝑛,𝑎,𝑏,𝑋 input file. 

• Compute step size ℎ = (𝑏 −𝑎)/𝑛   

• Generate equally spaced points 𝑥𝑖 = 𝑎 + 𝑖 ∗ ℎ and compute 𝑦𝑖 = 𝑓(𝑥𝑖). 

• Construct forward difference table. 

• Compute first derivative f′(X)) using Newton’s formula. 

• Compute second derivative f′′(X) using Newton’s formula. 

• Compare with analytical derivatives to compute percentage error. 

Print input, difference table, derivatives, and errors to console and output file.

Features 

• Supports multiple test cases 

• Calculates first and second derivatives numerically 

• Generates full forward difference table 

• Calculates percentage error with analytical derivatives 

• Outputs results to both console and file 


#### Differentiation Forward Code

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

int fact(int n)
{
    if(n==1 or n==0) return 1;
    else return fact(n-1)*n;
}

db f(db x)
{
    return ((pow(cos(x),5))-6*(pow(sin(x),5)))+log(x)+2;
}

db f1(db x)
{
    return -5*sin(x)*pow(cos(x),4)  -30*pow(sin(x),4)*cos(x)+1/x;
}

db f2(db x)
{
     return 30 * pow(sin(x), 5)-120 * pow(sin(x), 3) * pow(cos(x), 2)
            +20 * pow(sin(x), 2) * pow(cos(x), 3)
           -5 * pow(cos(x), 5)
           -1.0 / pow(x, 2);
}

vector<vector<db>> difftable(vector<db>&y)
{
    int n=y.size();
    vector<vector<db>>dftbl(n,vector<db>(n,0));
    for(int i=0;i<n;i++)  dftbl[i][0]=y[i];
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            dftbl[i][j]=dftbl[i+1][j-1]-dftbl[i][j-1];
        }
    }
    return dftbl;
}

void solve(int tc, ifstream &fin, ofstream &fout)
{
    int n;
    fin>>n;
    cout<<"Reading number of intervals n: "<<n<<endl;
    fout<<"Reading number of intervals n: "<<n<<endl;

    db a,b;
    fin>>a>>b;
    cout<<"Reading interval start (a): "<<a<<", end (b): "<<b<<endl;
    fout<<"Reading interval start (a): "<<a<<", end (b): "<<b<<endl;

    db X;
    fin>>X;
    cout<<"Reading interpolation point X: "<<X<<endl;
    fout<<"Reading interpolation point X: "<<X<<endl;

    db h=(b-a)/n;

    vector<db>x(n),y(n);
    for(int i=0;i<n;i++)
    {
        x[i]=a+ i*h;
        y[i]=f(x[i]);
    }

    db u=(X-x[0])/h;
    vector<vector<db>>diff=difftable(y);

    db y1 = (diff[0][1] + (2*u-1)*diff[0][2]/fact(2)+ (3*u*u-6*u+2)*diff[0][3]/fact(3))/h;
    db y2= ((diff[0][2])+(u-1)*diff[0][3])/(h*h);

    db y1_1=f1(X);
    db y2_1=f2(X);
    db error_y1 = abs((y1_1-y1)/y1)*100;
    db error_y2 = abs((y2_1-y2)/y2)*100;

    cout<<"\nTEST CASE #"<<tc<<"\n";
    cout<<"n: "<<n<<", a: "<<a<<", b: "<<b<<", X: "<<X<<"\n";
    cout<<"Difference table:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(10)<<diff[i][j]<<" ";
        cout<<endl;
    }
    cout<<"y': "<<y1<<endl;
    cout<<"y'': "<<y2<<endl;
    cout<<"functional value"<<endl;
    cout<<"y': "<<y1_1<<endl;
    cout<<"y'': "<<y2_1<<endl;
    cout<<"First diff error: "<<error_y1<<"%"<<endl;
    cout<<"Second diff error: "<<error_y2<<"%"<<endl;

    fout<<"\nTEST CASE #"<<tc<<"\n";
    fout<<"n: "<<n<<", a: "<<a<<", b: "<<b<<", X: "<<X<<"\n";
    fout<<"Difference table:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            fout<<setw(10)<<diff[i][j]<<" ";
        fout<<endl;
    }
    fout<<"y': "<<y1<<endl;
    fout<<"y'': "<<y2<<endl;
    fout<<"functional value"<<endl;
    fout<<"y': "<<y1_1<<endl;
    fout<<"y'': "<<y2_1<<endl;
    fout<<"First diff error: "<<error_y1<<"%"<<endl;
    fout<<"Second diff error: "<<error_y2<<"%"<<endl;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    if(!fin)
    {
        cout<<"Error: input.txt not found\n";
        return 0;
    }

    ofstream fout("output.txt");

    int t;
    fin>>t;
    cout<<"Total Test Cases: "<<t<<"\n";
    fout<<"Total Test Cases: "<<t<<"\n";

    for(int tc=1;tc<=t;tc++)
    {
        solve(tc, fin, fout);
    }

    cout<<"\nAll test cases completed! Results saved to output.txt\n";
    fin.close();
    fout.close();
    return 0;
}
```

#### Differentiation Forward Input

```
4
10
1 2
1.2
10
2 5.5
2.2
10
1 3
1.5
10
2 4
2.3
10
0.5 2.5
1
```

#### Differentiation Forward Output

```
Total Test Cases: 4
Reading number of intervals n: 10
Reading interval start (a): 1, end (b): 2
Reading interpolation point X: 1.2

TEST CASE #1
n: 10, a: 1, b: 2, X: 1.2
Difference table:
 -0.485274  -0.773437 0.000624729  0.0838691 0.00039901 -0.0142342 0.00134595  0.0028391 -0.000833681 -0.000475536 
  -1.25871  -0.772812  0.0844938  0.0842681 -0.0138352 -0.0128883 0.00418505 0.00200542 -0.00130922          0 
  -2.03152  -0.688318   0.168762  0.0704329 -0.0267235 -0.00870321 0.00619047 0.000696203          0          0 
  -2.71984  -0.519556   0.239195  0.0437094 -0.0354267 -0.00251273 0.00688668          0          0          0 
   -3.2394  -0.280361   0.282904 0.00828277 -0.0379394 0.00437394          0          0          0          0 
  -3.51976  0.0025429   0.291187 -0.0296566 -0.0335655          0          0          0          0          0 
  -3.51722    0.29373    0.26153 -0.0632221          0          0          0          0          0          0 
  -3.22349    0.55526   0.198308          0          0          0          0          0          0          0 
  -2.66823   0.753569          0          0          0          0          0          0          0          0 
  -1.91466          0          0          0          0          0          0          0          0          0 
y': -7.44543
y'': 8.44938
functional value
y': -7.45044
y'': 8.44411
First diff error: 0.0672453%
Second diff error: 0.0624101%
```

---

### Differentiation by Backward Interpolation

#### Differentiation Backward Theory

DIFFERENTIATION USING NEWTON BACKWARD INTERPOLATION

This method uses Newton's backward difference formula to compute derivatives
near the end of a data table. It constructs backward differences and applies
Newton's backward differentiation formulas.

BACKWARD DIFFERENCE DERIVATIVE FORMULAS:
f'(xₙ) = [∇f(xₙ) + (2s+1)∇²f(xₙ)/2! + (3s²+6s+2)∇³f(xₙ)/6 + ...] / h

where s = (x - xₙ)/h

Used for polynomial differentiation with backward differences.

#### Differentiation Backward Code

```cpp
#include<bits/stdc++.h>

using namespace std;

double polyValue(const vector<double>&coeff,double x)
{
    double val=0,p=1;
    for(double c:coeff)
    {
        val+=c*p;
        p*=x;
    }
    return val;
}

double trueDerivative(const vector<double>&coeff,double x)
{
    double val=0;
    for(int i=1; i<coeff.size(); i++)
    {
        val+=i*coeff[i]*pow(x,i-1);
    }
    return val;
}

vector<vector<double>>buildBackwardDiffTable(const vector<double>&y)
{
    int n=y.size();
    vector<vector<double>>diff(n,vector<double>(n,0));
    for(int i=0; i<n; i++)diff[i][0]=y[i];
    for(int j=1; j<n; j++)
    {
        for(int i=n-1; i>=j; i--)
        {
            diff[i][j]=diff[i][j-1]-diff[i-1][j-1];
        }
    }
    return diff;
}

double newtonBackwardDerivative5(const vector<vector<double>>&diff,double xn,double h,double xp,int n)
{
    double s=(xp-xn)/h;
    double der=0;
    if(n>=2) der+=diff[n-1][1];
    if(n>=3) der+=((2*s+1)/2.0)*diff[n-1][2];
    if(n>=4) der+=((3*s*s+6*s+2)/6.0)*diff[n-1][3];
    if(n>=5) der+=((4*s*s*s+18*s*s+22*s+6)/24.0)*diff[n-1][4];
    if(n>=6) der+=((5*s*s*s*s+40*s*s*s+105*s*s+100*s+24)/120.0)*diff[n-1][5];
    return der/h;
}

string polyString(const vector<double>&c)
{
    stringstream ss;
    bool first=true;
    for(int i=0; i<c.size(); i++)
    {
        double a=c[i];
        if(fabs(a)<1e-12) continue;
        if(!first) ss<<(a>=0?" + ":" - ");
        else if(a<0) ss<<"-";
        if(a<0) a=-a;
        ss<<fixed<<setprecision(4)<<a;
        if(i==1) ss<<"x";
        else if(i>1) ss<<"x^"<<i;
        first=false;
    }
    return ss.str();
}

int main()
{
    ifstream inputFile("Input.txt");
    ofstream outputFile("Output.txt");
    if(!inputFile.is_open())
    {
        cerr<<"Error opening Input.txt!"<<endl;
        return 1;
    }
    int testCases;
    inputFile>>testCases;
    for(int tc=1; tc<=testCases; tc++)
    {
        int deg;
        inputFile>>deg;
        vector<double>coeff(deg+1);
        for(int i=0; i<=deg; i++) inputFile>>coeff[i];
        int n;
        inputFile>>n;
        vector<double>x(n),y(n);
        for(int i=0; i<n; i++) inputFile>>x[i];
        for(int i=0; i<n; i++) y[i]=polyValue(coeff,x[i]);
        double xp;
        inputFile>>xp;
        double h=x[1]-x[0];
        auto diff=buildBackwardDiffTable(y);
        double approx=newtonBackwardDerivative5(diff,x[n-1],h,xp,n);
        double trueVal=trueDerivative(coeff,xp);
        double err=fabs((trueVal-approx)/trueVal)*100.0;
        string poly=polyString(coeff);
        cout<<"Test Case "<<tc<<"\n";
        outputFile<<"Test Case "<<tc<<"\n";
        cout<<"Polynomial: f(x) = "<<poly<<"\n";
        outputFile<<"Polynomial: f(x) = "<<poly<<"\n";
        cout<<"Number of points: "<<n<<"\n";
        outputFile<<"Number of points: "<<n<<"\n";
        cout<<"x-values: ";
        outputFile<<"x-values: ";
        for(int i=0; i<n; i++)
        {
            cout<<x[i]<<" ";
            outputFile<<x[i]<<" ";
        }
        cout<<"\n";
        outputFile<<"\n";
        cout<<"y-values: ";
        outputFile<<"y-values: ";
        for(int i=0; i<n; i++)
        {
            cout<<fixed<<setprecision(6)<<y[i]<<" ";
            outputFile<<fixed<<setprecision(6)<<y[i]<<" ";
        }
        cout<<"\n";
        outputFile<<"\n";
        cout<<fixed<<setprecision(6);
        outputFile<<fixed<<setprecision(6);
        cout<<"Step size (h): "<<h<<"\n";
        outputFile<<"Step size (h): "<<h<<"\n";
        cout<<"Differentiation point: "<<xp<<"\n";
        outputFile<<"Differentiation point: "<<xp<<"\n";
        cout<<"Backward Difference Table:\n";
        outputFile<<"Backward Difference Table:\n";
        for(int i=0; i<n; i++)
        {
            cout<<"Row "<<i<<":  ";
            outputFile<<"Row "<<i<<":  ";
            for(int j=0; j<=i && j<n; j++)
            {
                cout<<setw(10)<<diff[i][j]<<" ";
                outputFile<<setw(10)<<diff[i][j]<<" ";
            }
            cout<<"\n";
            outputFile<<"\n";
        }
        cout<<"Approximate derivative : "<<approx<<"\n";
        outputFile<<"Approximate derivative : "<<approx<<"\n";
        cout<<"True derivative: "<<trueVal<<"\n";
        outputFile<<"True derivative: "<<trueVal<<"\n";
        cout<<"Percentage error: "<<err<<" %\n\n";
        outputFile<<"Percentage error: "<<err<<" %\n\n";
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
```

#### Differentiation Backward Input

```
2
3
1 2 -1 0.5
6
0 1 2 3 4 5
4.5
2
0 0 1
7
0 0.5 1 1.5 2 2.5 3
2
```

#### Differentiation Backward Output

```
Test Case 1
Polynomial: f(x) = 1.0000 + 2.0000x - 1.0000x^2 + 0.5000x^3
Number of points: 6
x-values: 0 1 2 3 4 5 
y-values: 1.000000 2.500000 5.000000 11.500000 25.000000 48.500000 
Step size (h): 1.000000
Differentiation point: 4.500000
Backward Difference Table:
Row 0:   1.000000 
Row 1:   2.500000   1.500000 
Row 2:   5.000000   2.500000   1.000000 
Row 3:  11.500000   6.500000   4.000000   3.000000 
Row 4:  25.000000  13.500000   7.000000   3.000000   0.000000 
Row 5:  48.500000  23.500000  10.000000   3.000000   0.000000   0.000000 
Approximate derivative : 23.375000
True derivative: 23.375000
Percentage error: 0.000000 %

Test Case 2
Polynomial: f(x) = 1.0000x^2
Number of points: 7
x-values: 0.000000 0.500000 1.000000 1.500000 2.000000 2.500000 3.000000 
y-values: 0.000000 0.250000 1.000000 2.250000 4.000000 6.250000 9.000000 
Step size (h): 0.500000
Differentiation point: 2.000000
Backward Difference Table:
Row 0:   0.000000 
Row 1:   0.250000   0.250000 
Row 2:   1.000000   0.750000   0.500000 
Row 3:   2.250000   1.250000   0.500000   0.000000 
```

---

## Curve Fitting / Regression

### Linear Regression

#### Linear Regression Theory

LINEAR REGRESSION (LEAST SQUARES METHOD) – DOCUMENTATION 

This program performs Simple Linear Regression using the Least Squares Method to find the 
best-fit straight line for a given set of data points. 

OBJECTIVE 
To compute the best-fit linear equation: 
			y = a + bx 
			
from a given set of experimental or numerical data using the least squares regression 
technique, which minimizes the total squared error. 

CONCEPT 
For n data points (xi,yi) the regression line: 

			y= a + bx 
is determined by minimizing: 

			∑(yi−(a+bxi))2  
This leads to two closed-form formulas: 
Slope (b) 

			b= 𝑛∑𝑥𝑦−(∑𝑥)(∑𝑦) / n∑x2−(∑x)2b 

Intercept (a):

				a=∑y−b∑xn 
These values define the best-fit straight line. 
 
PROGRAM FEATURES 
• Reads all inputs from input.txt.

• Writes results to both console and output.txt.

• Handles multiple test cases.

• Prints: 
o Number of data points 

o All x and y values 

o Computed intercept (a) 

o Computed slope (b) 

o Final regression line equation 

 
INPUT FORMAT (input.txt) 

T 

n 

x1 x2 x3 ... xn 

y1 y2 y3 ... yn 

 
(repeat for T test cases) 

Where: 
• t = number of test cases 

• n = number of data points in the test case 

• Next line = n values of x 

• Next line = n values of y 

 
EXAMPLE INPUT 

3 

5

1 2 3 4 5 

2 4 5 4 5 

4 

2 4 6 8 

3 5 7 9 

6 

5 10 15 20 25 30 

12 18 26 33 40 48 

 
OUTPUT (Written to output.txt and displayed on console) :

For each test case, the program prints: 

• Test Case Number

• Total points

• x[] array 

• y[] array 

• Intercept (a) 

• Slope (b) 

• Regression Equation

Example:

Test Case #1 

Number of points: 5 

x values: 1 2 3 4 5

y values: 2 4 5 4 5 

Computed Intercept (a): 2.2 

Computed Slope (b): 0.6 

Line Equation: y = 2.2 + 0.6x 

 
ALGORITHM (Least Squares Method) :

• Read number of data points n 

• Read arrays x[n] and y[n] 

• Compute required sums: 

	o Σx 
	o Σy 
	o Σxy 
	o Σx² 

• Apply formulas: 

o Compute b (slope) 
o Compute a (intercept) 

• Display and store: 

o Input values 
o Calculated coefficients 
o Final regression line

#### Linear Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;
#define db double
void solve(int tc, ifstream &fin, ofstream &fout)
{
    int n;
    fin >> n;
    vector<db> x(n), y(n);
    for(int i = 0; i < n; i++) fin>>x[i];
    for(int i = 0; i < n; i++) fin>>y[i];
    db sX = 0, sY = 0, sXY = 0, sXs = 0;
    for(int i = 0; i < n; i++)
    {
        sX  += x[i];
        sY  += y[i];
        sXY += x[i] * y[i];
        sXs += x[i] * x[i];
    }
    db b = (n * sXY - sX * sY) / (n * sXs - sX * sX);
    db a = (sY - b * sX) / n;
    cout << "Test Case #" << tc << "\n";
    cout << "Number of points: " << n << "\n";
    cout << "x values: ";
    for (db i : x) cout << i << " ";
    cout << "\ny values: ";
    for (db i : y) cout << i << " ";

    cout << "\nComputed Intercept (a): " <<a;
    cout << "\nComputed Slope (b): " <<b;
    cout << "\nLine Equation: y = " <<a << " + " << b << "x"<<endl<<endl;

    fout << "Test Case #" <<tc<<endl;
    fout << "Number of points: "<<n<<endl;
    fout << "x values: ";
    for (db i : x) fout <<i<<" ";
    fout << "\ny values: ";
    for (db i : y) fout <<i<<" ";

    fout << "\nComputed Intercept (a): " <<a;
    fout << "\nComputed Slope (b): " <<b;
    fout << "\nLine Equation: y = "<< a << " + " <<b<<"x"<<endl<<endl;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout << "Error: input.txt not found!" << endl;
        return 0;
    }
    int t;
    fin >> t;
    cout << "Total Test Cases: " << t << "\n\n";
    fout << "Total Test Cases: " << t << "\n\n";
    for(int tc = 1; tc <= t; tc++)
    {
        solve(tc, fin, fout);
    }
    cout << "All results written to output.txt successfully!\n";
}
```

#### Linear Regression Input

```
3
5
1 2 3 4 5
2 4 5 4 5

4
2 4 6 8
3 5 7 9

6
5 10 15 20 25 30
12 18 26 33 40 48
```

#### Linear Regression Output

```
Total Test Cases: 3

Test Case #1
Number of points: 5
x values: 1 2 3 4 5 
y values: 2 4 5 4 5 
Computed Intercept (a): 2.2
Computed Slope (b): 0.6
Line Equation: y = 2.2 + 0.6x

Test Case #2
Number of points: 4
x values: 2 4 6 8 
y values: 3 5 7 9 
Computed Intercept (a): 1
Computed Slope (b): 1
Line Equation: y = 1 + 1x

Test Case #3
Number of points: 6
x values: 5 10 15 20 25 30 
y values: 12 18 26 33 40 48 
Computed Intercept (a): 4.2
Computed Slope (b): 1.44571
Line Equation: y = 4.2 + 1.44571x
```

---

### Polynomial Regression

#### Polynomial Regression Theory

POLYNOMIAL REGRESSION

Extends linear regression to fit polynomial curves of degree m:
y = a₀ + a₁x + a₂x² + ... + aₘxᵐ

The coefficients are found by solving the normal equations:
∑xy = a₀∑x + a₁∑x² + a₂∑x³ + ... + aₘ∑xᵐ⁺¹
...
∑xᵐy = a₀∑xᵐ + a₁∑xᵐ⁺¹ + ... + aₘ∑x²ᵐ

This system is solved using Gauss-Jordan elimination.

#### Polynomial Regression Code

```cpp
#include<bits/stdc++.h>
using namespace std;

void gaussJordan(vector<vector<db>>&augmented, int m)
{
    int n=m+1;
    for(int i=0;i<n;i++)
    {
        int maxR=i;
        for(int k=i+1;k<n;k++)
        {
            if(fabs(augmented[k][i])>fabs(augmented[maxR][i])) maxR=k;
        }
        if(maxR!=i) swap(augmented[i],augmented[maxR]);
        db pivot=augmented[i][i];
        if(fabs(pivot)<1e-12) continue;
        for(int j=0;j<=n;j++) augmented[i][j]/=pivot;
        for(int k=0;k<n;k++)
        {
            if(k!=i)
            {
                db factor=augmented[k][i];
                for(int j=0;j<=n;j++) augmented[k][j]-=factor*augmented[i][j];
            }
        }
    }
}

string polyString(const vector<db>&coeff)
{
    stringstream ss;
    bool first=true;
    for(int i=0;i<coeff.size();i++)
    {
        db a=coeff[i];
        if(fabs(a)<1e-12) continue;
        if(!first)
        {
            if(a>=0) ss<<" + ";
            else ss<<" - ", a=-a;
        }
        else if(a<0) ss<<"-", a=-a;
        ss<<fixed<<setprecision(4)<<a;
        if(i==1) ss<<"x";
        else if(i>1) ss<<"x^"<<i;
        first=false;
    }
    return ss.str();
}

void solve(int tc,ifstream&fin,ofstream&fout)
{
    int n,m;
    fin>>n>>m;
    vector<db>x(n),y(n);
    for(int i=0;i<n;i++) fin>>x[i];
    for(int i=0;i<n;i++) fin>>y[i];

    vector<db>sumX(2*m+1,0);
    for(int i=0;i<=2*m;i++)
    {
        for(int j=0;j<n;j++)
        {
            sumX[i]+=pow(x[j],i);
        }
    }

    vector<db>sumXY(m+1,0);
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            sumXY[i]+=pow(x[j],i)*y[j];
        }
    }

    vector<vector<db>>augmented(m+1,vector<db>(m+2,0));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            augmented[i][j]=sumX[i+j];
        }
        augmented[i][m+1]=sumXY[i];
    }

    gaussJordan(augmented,m);

    vector<db>coeff(m+1);
    for(int i=0;i<=m;i++) coeff[i]=augmented[i][m+1];

    string poly=polyString(coeff);

    cout<<"Test Case #"<<tc<<"\n";
    cout<<"Number of data points (n): "<<n<<"\n";
    cout<<"Polynomial degree (m): "<<m<<"\n";
    cout<<"x values: ";
    for(db val:x) cout<<val<<" ";
    cout<<"\ny values: ";
    for(db val:y) cout<<val<<" ";
    cout<<"\n\nPolynomial coefficients:\n";
    for(int i=0;i<=m;i++)
    {
        cout<<"a"<<i<<" = "<<fixed<<setprecision(6)<<coeff[i]<<"\n";
    }
    cout<<"\nPolynomial: y = "<<poly<<"\n\n";

    fout<<"Test Case #"<<tc<<"\n";
    fout<<"Number of data points (n): "<<n<<"\n";
    fout<<"Polynomial degree (m): "<<m<<"\n";
    fout<<"x values: ";
    for(db val:x) fout<<val<<" ";
    fout<<"\ny values: ";
    for(db val:y) fout<<val<<" ";
    fout<<"\n\nPolynomial coefficients:\n";
    for(int i=0;i<=m;i++)
    {
        fout<<"a"<<i<<" = "<<fixed<<setprecision(6)<<coeff[i]<<"\n";
    }
    fout<<"\nPolynomial: y = "<<poly<<"\n\n";
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout<<"Error: input.txt not found!"<<endl;
        return 0;
    }

    int t;
    fin>>t;
    cout<<"Total Test Cases: "<<t<<"\n\n";
    fout<<"Total Test Cases: "<<t<<"\n\n";

    for(int tc=1;tc<=t;tc++)
    {
        solve(tc,fin,fout);
    }

    cout<<"All results written to output.txt!\n";
    return 0;
}
```

#### Polynomial Regression Input

```
2
6 2
1 2 3 4 5 6
3 8 15 24 35 48

6 3
1 2 3 4 5 6
2 5 10 17 26 37
```

#### Polynomial Regression Output

```
Total Test Cases: 2

Test Case #1
Number of data points (n): 6
Polynomial degree (m): 2
x values: 1 2 3 4 5 6 
y values: 3 8 15 24 35 48 

Polynomial coefficients:
a0 = 0.000000
a1 = 1.000000
a2 = 2.000000

Polynomial: y = 1.0000x + 2.0000x^2

Test Case #2
Number of data points (n): 6
Polynomial degree (m): 3
x values: 1 2 3 4 5 6 
y values: 2 5 10 17 26 37 

Polynomial coefficients:
a0 = 1.000000
a1 = 0.000000
a2 = 1.000000
a3 = 0.000000

Polynomial: y = 1.0000 + 1.0000x^2
```

---

### Transcendental Regression

#### Transcendental Regression Theory

TRANSCENDENTAL REGRESSION

Fits data to exponential and power models by transforming to linear form:

MODEL 1: y = ae^(bx)
  Linearize: ln(y) = ln(a) + bx
MODEL 2: y = ax^b
  Linearize: ln(y) = ln(a) + b*ln(x)

MODEL 3: y = a + be^(x/4)
  Linearize: Requires iterative or custom fitting

After transformation, standard linear regression techniques are applied,
then the results are transformed back to the original form.

#### Transcendental Regression Code

```cpp
#include<bits/stdc++.h>
using namespace std;

void solve(int tc, ifstream&fin, ofstream&fout)
{
    int n, model;
    fin>>n>>model;
    vector<db>x(n),y(n);
    for(int i=0;i<n;i++) fin>>x[i];
    for(int i=0;i<n;i++) fin>>y[i];

    cout<<"Test Case #"<<tc<<"\n";
    cout<<"Number of points: "<<n<<"\n";
    cout<<"Model type: "<<model<<"\n";
    cout<<"x values: ";
    for(db val:x) cout<<val<<" ";
    cout<<"\ny values: ";
    for(db val:y) cout<<val<<" ";
    cout<<"\n\n";

    fout<<"Test Case #"<<tc<<"\n";
    fout<<"Number of points: "<<n<<"\n";
    fout<<"Model type: "<<model<<"\n";
    fout<<"x values: ";
    for(db val:x) fout<<val<<" ";
    fout<<"\ny values: ";
    for(db val:y) fout<<val<<" ";
    fout<<"\n\n";

    if(model==1)
    {
        db sX=0,sY=0,sXY=0,sXs=0;
        for(int i=0;i<n;i++)
        {
            db lnY=log(y[i]);
            sX+=x[i];
            sY+=lnY;
            sXY+=x[i]*lnY;
            sXs+=x[i]*x[i];
        }
        db b=(n*sXY-sX*sY)/(n*sXs-sX*sX);
        db lnA=(sY-b*sX)/n;
        db a=exp(lnA);

        cout<<"Model: y = a * e^(bx)\n";
        cout<<"Computed a: "<<a<<"\n";
        cout<<"Computed b: "<<b<<"\n";
        cout<<"Equation: y = "<<a<<" * e^("<<b<<"x)\n\n";

        fout<<"Model: y = a * e^(bx)\n";
        fout<<"Computed a: "<<a<<"\n";
        fout<<"Computed b: "<<b<<"\n";
        fout<<"Equation: y = "<<a<<" * e^("<<b<<"x)\n\n";
    }
    else if(model==2)
    {
        db sX=0,sY=0,sXY=0,sXs=0;
        for(int i=0;i<n;i++)
        {
            db lnX=log(x[i]);
            db lnY=log(y[i]);
            sX+=lnX;
            sY+=lnY;
            sXY+=lnX*lnY;
            sXs+=lnX*lnX;
        }
        db b=(n*sXY-sX*sY)/(n*sXs-sX*sX);
        db lnA=(sY-b*sX)/n;
        db a=exp(lnA);

        cout<<"Model: y = a * x^b\n";
        cout<<"Computed a: "<<a<<"\n";
        cout<<"Computed b: "<<b<<"\n";
        cout<<"Equation: y = "<<a<<" * x^"<<b<<"\n\n";

        fout<<"Model: y = a * x^b\n";
        fout<<"Computed a: "<<a<<"\n";
        fout<<"Computed b: "<<b<<"\n";
        fout<<"Equation: y = "<<a<<" * x^"<<b<<"\n\n";
    }
    else if(model==3)
    {
        vector<db>z(n);
        for(int i=0;i<n;i++) z[i]=exp(x[i]/4.0);
        db sZ=0,sY=0,sZY=0,sZs=0;
        for(int i=0;i<n;i++)
        {
            sZ+=z[i];
            sY+=y[i];
            sZY+=z[i]*y[i];
            sZs+=z[i]*z[i];
        }
        db b=(n*sZY-sZ*sY)/(n*sZs-sZ*sZ);
        db a=(sY-b*sZ)/n;

        cout<<"Model: y = a + b * e^(x/4)\n";
        cout<<"Computed a: "<<a<<"\n";
        cout<<"Computed b: "<<b<<"\n";
        cout<<"Equation: y = "<<a<<" + "<<b<<" * e^(x/4)\n\n";

        fout<<"Model: y = a + b * e^(x/4)\n";
        fout<<"Computed a: "<<a<<"\n";
        fout<<"Computed b: "<<b<<"\n";
        fout<<"Equation: y = "<<a<<" + "<<b<<" * e^(x/4)\n\n";
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout<<"Error: input.txt not found!"<<endl;
        return 0;
    }

    int t;
    fin>>t;
    cout<<"Total Test Cases: "<<t<<"\n\n";
    fout<<"Total Test Cases: "<<t<<"\n\n";

    for(int tc=1;tc<=t;tc++)
    {
        solve(tc,fin,fout);
    }

    cout<<"All results written to output.txt!\n";
    return 0;
}
```

#### Transcendental Regression Input

```
3
5 1
0 1 2 3 4
1 2.718 7.389 20.086 54.598

5 2
1 2 3 4 5
1 8 27 64 125

5 3
0 4 8 12 16
5 10 18 35 70
```

#### Transcendental Regression Output

```
Total Test Cases: 3

Test Case #1
Number of points: 5
Model type: 1
x values: 0 1 2 3 4 
y values: 1 2.718 7.389 20.086 54.598 

Model: y = a * e^(bx)
Computed a: 0.996263
Computed b: 1.00126
Equation: y = 0.996263 * e^(1.00126x)

Test Case #2
Number of points: 5
Model type: 2
x values: 1 2 3 4 5 
y values: 1 8 27 64 125 

Model: y = a * x^b
Computed a: 1
Computed b: 3
Equation: y = 1 * x^3

Test Case #3
Number of points: 5
Model type: 3
x values: 0 4 8 12 16 
y values: 5 10 18 35 70 

Model: y = a + b * e^(x/4)
Computed a: -2.82689
Computed b: 7.81992
Equation: y = -2.82689 + 7.81992 * e^(x/4)
```

---

## Numerical Integration

### Simpson's 1/3 Rule

#### Simpson 1/3 Theory

SIMPSON'S 1/3 RULE - NUMERICAL INTEGRATION

Simpson's 1/3 rule approximates the integral by fitting parabolas through
three consecutive points. It requires an even number of intervals.

FORMULA:

where:
- h = (b-a)/n
- n must be even
- ∑f(xₒ⵫d⵭) is sum at odd indices (x₁, x₃, x₅, ...)
- ∑f(xₑᵥₑₙ) is sum at even indices (x₂, x₄, x₆, ...)

Provides higher accuracy than Trapezoidal rule with same number of points.

#### Simpson 1/3 Code

```cpp
#include<bits/stdc++.h>
using namespace std;

db f(db x, vector<db>&coeff)
{
    db res=0;
    db power=1;
    for(int i=0;i<coeff.size();i++)
    {
        res+=coeff[i]*power;
        power*=x;
    }
    return res;
}

void solve(int tc, ifstream&fin, ofstream&fout)
{
    int degree;
    fin>>degree;
    vector<db>coeff(degree+1);
    for(int i=0;i<=degree;i++) fin>>coeff[i];

    db a,b;
    int n;
    fin>>a>>b>>n;

    if(n%2!=0)
    {
        cout<<"Test Case #"<<tc<<": Error - n must be even!\n\n";
        fout<<"Test Case #"<<tc<<": Error - n must be even!\n\n";
        return;
    }

    db h=(b-a)/n;

    db sum=f(a,coeff)+f(b,coeff);

    for(int i=1;i<n;i++)
    {
        db x=a+i*h;
        if(i%2==1) sum+=4*f(x,coeff);
        else sum+=2*f(x,coeff);
    }

    db result=(h/3)*sum;

    cout<<"Test Case #"<<tc<<"\n";
    cout<<"Polynomial degree: "<<degree<<"\n";
    cout<<"Coefficients: ";
    for(db c:coeff) cout<<c<<" ";
    cout<<"\nInterval: ["<<a<<", "<<b<<"]\n";
    cout<<"Number of intervals (n): "<<n<<"\n";
    cout<<"Step size (h): "<<h<<"\n";
    cout<<"Integral result: "<<result<<"\n\n";

    fout<<"Test Case #"<<tc<<"\n";
    fout<<"Polynomial degree: "<<degree<<"\n";
    fout<<"Coefficients: ";
    for(db c:coeff) fout<<c<<" ";
    fout<<"\nInterval: ["<<a<<", "<<b<<"]\n";
    fout<<"Number of intervals (n): "<<n<<"\n";
    fout<<"Step size (h): "<<h<<"\n";
    fout<<"Integral result: "<<result<<"\n\n";
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout<<"Error: input.txt not found!"<<endl;
        return 0;
    }

    int t;
    fin>>t;
    cout<<"Total Test Cases: "<<t<<"\n\n";
    fout<<"Total Test Cases: "<<t<<"\n\n";

    for(int tc=1;tc<=t;tc++)
    {
        solve(tc,fin,fout);
    }

    cout<<"All results written to output.txt!\n";
    return 0;
}
```

#### Simpson 1/3 Input

```
3
2
0 0 1
0 2 4

3
0 1 0 0
1 3 6

2
1 2 1
0 2 8
```

#### Simpson 1/3 Output

```
Total Test Cases: 3

Test Case #1
Polynomial degree: 2
Coefficients: 0 0 1 
Interval: [0, 2]
Number of intervals (n): 4
Step size (h): 0.5
Integral result: 2.66667

Test Case #2
Polynomial degree: 3
Coefficients: 0 1 0 0 
Interval: [1, 3]
Number of intervals (n): 6
Step size (h): 0.333333
Integral result: 4

Test Case #3
Polynomial degree: 2
Coefficients: 1 2 1 
Interval: [0, 2]
Number of intervals (n): 8
Step size (h): 0.25
Integral result: 10.6667
```

---

### Simpson's 3/8 Rule

#### Simpson 3/8 Theory

SIMPSON'S 3/8 RULE - NUMERICAL INTEGRATION

Simpson's 3/8 rule uses cubic polynomials for approximation. It requires
the number of intervals to be a multiple of 3.

FORMULA:

where:
- h = (b-a)/n
- n must be a multiple of 3
- ∑f(xᵢ) is sum where i is not a multiple of 3
- ∑f(xⱼ) is sum where j is a multiple of 3 (but not 0 or n)

Often used in combination with Simpson's 1/3 rule for adaptive integration.

#### Simpson 3/8 Code

```cpp
#include<bits/stdc++.h>
using namespace std;

db f(db x, vector<db>&coeff)
{
    db res=0;
    db power=1;
    for(int i=0;i<coeff.size();i++)
    {
        res+=coeff[i]*power;
        power*=x;
    }
    return res;
}

void solve(int tc, ifstream&fin, ofstream&fout)
{
    int degree;
    fin>>degree;
    vector<db>coeff(degree+1);
    for(int i=0;i<=degree;i++) fin>>coeff[i];

    db a,b;
    int n;
    fin>>a>>b>>n;

    if(n%3!=0)
    {
        cout<<"Test Case #"<<tc<<": Error - n must be a multiple of 3!\n\n";
        fout<<"Test Case #"<<tc<<": Error - n must be a multiple of 3!\n\n";
        return;
    }

    db h=(b-a)/n;

    db sum=f(a,coeff)+f(b,coeff);

    for(int i=1;i<n;i++)
    {
        db x=a+i*h;
        if(i%3==0) sum+=2*f(x,coeff);
        else sum+=3*f(x,coeff);
    }

    db result=(3*h/8)*sum;

    cout<<"Test Case #"<<tc<<"\n";
    cout<<"Polynomial degree: "<<degree<<"\n";
    cout<<"Coefficients: ";
    for(db c:coeff) cout<<c<<" ";
    cout<<"\nInterval: ["<<a<<", "<<b<<"]\n";
    cout<<"Number of intervals (n): "<<n<<"\n";
    cout<<"Step size (h): "<<h<<"\n";
    cout<<"Integral result: "<<result<<"\n\n";

    fout<<"Test Case #"<<tc<<"\n";
    fout<<"Polynomial degree: "<<degree<<"\n";
    fout<<"Coefficients: ";
    for(db c:coeff) fout<<c<<" ";
    fout<<"\nInterval: ["<<a<<", "<<b<<"]\n";
    fout<<"Number of intervals (n): "<<n<<"\n";
    fout<<"Step size (h): "<<h<<"\n";
    fout<<"Integral result: "<<result<<"\n\n";
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout<<"Error: input.txt not found!"<<endl;
        return 0;
    }

    int t;
    fin>>t;
    cout<<"Total Test Cases: "<<t<<"\n\n";
    fout<<"Total Test Cases: "<<t<<"\n\n";

    for(int tc=1;tc<=t;tc++)
    {
        solve(tc,fin,fout);
    }

    cout<<"All results written to output.txt!\n";
    return 0;
}
```

#### Simpson 3/8 Input

```
3
2
0 0 1
0 2 6

3
0 1 0 0
1 3 9

2
1 2 1
0 2 12
```

#### Simpson 3/8 Output

```
Total Test Cases: 3

Test Case #1
Polynomial degree: 2
Coefficients: 0 0 1 
Interval: [0, 2]
Number of intervals (n): 6
Step size (h): 0.333333
Integral result: 2.66667

Test Case #2
Polynomial degree: 3
Coefficients: 0 1 0 0 
Interval: [1, 3]
Number of intervals (n): 9
Step size (h): 0.222222
Integral result: 4

Test Case #3
Polynomial degree: 2
Coefficients: 1 2 1 
Interval: [0, 2]
Number of intervals (n): 12
Step size (h): 0.166667
Integral result: 10.6667
```

---

## Purpose of This Repository
- Provide **clean C++ codes** for numerical methods
- Serve as a **learning resource & simulation** for Numerical Methods
- Combine all classical numerical methods in one comprehensive project

## Authors
**1. Md. Toufiq Hasan • Roll: 2207049**  
**2. Shahriar Abdullah • Roll: 2207050**  
**3. Ariful Islam Sheikh • Roll: 2207051**
