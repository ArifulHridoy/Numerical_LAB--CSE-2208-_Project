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

    cout<<"\n"<<string(60, '=')<<"\n";
    cout<<"TEST CASE "<<testNum<<"\n";
    cout<<string(60,'=')<<"\n";
    cout<<"Function: "<<functionStr<<"\n";
    cout<<fixed<<setprecision(6);
    cout<<"Degree: "<<degree<<"\n";
    cout<<"Error Tolerance: "<<E<<"\n";
    cout<<"Search Limit: "<<lim<<"\n";
    cout<<"Roots:\n";
    if(roots.empty())
    {
        cout<<"  No roots found in the search range.\n";
    }
    else
    {
        for(double r:roots)
            cout<<"  x = "<<r<<"\n";
    }
    cout<<string(60,'=')<<"\n";
}

int main()
{
    ifstream fin("Input.txt");

    int T; fin>>T;

    ofstream fout("Output.txt");
    fout<<"BISECTION METHOD - MULTIPLE TEST CASES\n";
    fout<<"Total Test Cases: "<<T<<"\n";

    cout<<"\nBISECTION METHOD - MULTIPLE TEST CASES\n";
    cout<<"Total Test Cases: "<<T<<"\n";

    for(int testNum=1; testNum<=T; testNum++)
    {
        fin>>degree;

        coefficients.resize(degree+1);
        for(int i=0; i<=degree; i++)
        {
            fin>>coefficients[i];
        }
        solveTestCase(testNum,fout);
    }

    fin.close();
    fout.close();

    cout<<"\n\nAll test cases completed! Results saved to Output.txt\n";

    return 0;
}
