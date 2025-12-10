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
