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

    if(n>=2)
        der+=diff[n-1][1];

    if(n>=3)
        der+=((2*s+1)/2.0)*diff[n-1][2];

    if(n>=4)
        der+=((3*s*s+6*s+2)/6.0)*diff[n-1][3];

    if(n>=5)
        der+=((4*s*s*s+18*s*s+22*s+6)/24.0)*diff[n-1][4];

    if(n>=6)
        der+=((5*s*s*s*s+40*s*s*s+105*s*s+100*s+24)/120.0)*diff[n-1][5];

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

        if(!first)
            ss<<(a>=0?" + ":" - ");
        else if(a<0)
            ss<<"-";
        if(a<0)
            a=-a;

        ss<<fixed<<setprecision(4)<<a;

        if(i==1)
            ss<<"x";
        else if(i>1)
            ss<<"x^"<<i;
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

        cout<<"Step size (h): "<<h<<"\n";
        outputFile<<"Step size (h): "<<h<<"\n";

        cout<<"Differentiation point: "<<xp<<"\n";
        outputFile<<"Differentiation point: "<<xp<<"\n";

        cout<<"Backward Difference Table:\n";
        outputFile<<"Backward Difference Table:\n";

        for(int i=0; i<n; i++)
        {
            cout<<"Row "<<i<<": ";
            outputFile<<"Row "<<i<<": ";

            for(int j=0; j<=i&&j<n; j++)
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
