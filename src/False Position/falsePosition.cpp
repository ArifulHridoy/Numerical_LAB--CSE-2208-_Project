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
