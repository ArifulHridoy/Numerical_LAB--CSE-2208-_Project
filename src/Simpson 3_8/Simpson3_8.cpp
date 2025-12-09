#include<bits/stdc++.h>
using namespace std;

vector<double>coefficients;
int degree;

double f(double x)
{
    double result=0;
    for(int i=0; i<=degree; i++)
        result+=coefficients[i]*pow(x,degree-i);
    return result;
}

string generateFunctionString()
{
    stringstream ss;
    ss<<"f(x) = ";
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
            if(coefficients[i]<0) ss<<"-";
        }
        double absCoeff=fabs(coefficients[i]);
        int power=degree-i;
        if(power==0)
        {
            ss<<absCoeff;
        }
        else if(power==1)
        {
            if(fabs(absCoeff-1.0)<1e-10) ss<<"x";
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

double simpson_three_eighth(double a,double b,int n)
{
    if(n%3!=0)
    {
        cout<<"Error: n must be a multiple of 3 for Simpson's 3/8 rule.\n";
        return NAN;
    }
    double h=(b-a)/n;
    double sum=f(a)+f(b);
    for(int i=1; i<n; i++)
    {
        double x=a+i*h;
        if(i%3==0)
            sum+=2*f(x);
        else
            sum+=3*f(x);
    }
    return (3*h/8)*sum;
}

void solveTestCase(int testNum,double a,double b,int n,ofstream& fout)
{
    string functionStr=generateFunctionString();
    double h=(b-a)/n;
    double result=simpson_three_eighth(a,b,n);
    fout<<"\nTEST CASE "<<testNum<<"\n";
    fout<<"Function: "<<functionStr<<"\n";
    fout<<fixed<<setprecision(6);
    fout<<"Degree: "<<degree<<"\n";
    fout<<"Lower Limit (a): "<<a<<"\n";
    fout<<"Upper Limit (b): "<<b<<"\n";
    fout<<"Number of intervals (n): "<<n<<"\n";
    fout<<"Step size (h): "<<h<<"\n";
    if(isnan(result))
    {
        fout<<"Result: Error - n must be a multiple of 3\n";
    }
    else
    {
        fout<<"Integral value: "<<result<<"\n";
    }
    cout<<"\nTEST CASE "<<testNum<<"\n";
    cout<<"Function: "<<functionStr<<"\n";
    cout<<fixed<<setprecision(6);
    cout<<"Degree: "<<degree<<"\n";
    cout<<"Lower Limit (a): "<<a<<"\n";
    cout<<"Upper Limit (b): "<<b<<"\n";
    cout<<"Number of intervals (n): "<<n<<"\n";
    cout<<"Step size (h): "<<h<<"\n";
    if(isnan(result))
    {
        cout<<"Result: Error - n must be a multiple of 3\n";
    }
    else
    {
        cout<<"Integral value: "<<result<<"\n";
    }
}

int main()
{
    ifstream fin("Input.txt");
    int T; fin>>T;
    ofstream fout("Output.txt");
    fout<<"Total Test Cases: "<<T<<"\n";
    cout<<"Total Test Cases: "<<T<<"\n";
    for(int testNum=1; testNum<=T; testNum++)
    {
        fin>>degree;
        coefficients.resize(degree+1);
        for(int i=0; i<=degree; i++)
        {
            fin>>coefficients[i];
        }
        double a,b;
        int n;
        fin>>a>>b>>n;
        solveTestCase(testNum,a,b,n,fout);
    }
    fin.close();
    fout.close();
    cout<<"\nAll test cases completed! Results saved to Output.txt\n";
    return 0;
}
