#include<bits/stdc++.h>

using namespace std;

vector<double> gaussJordan(vector<vector<double>> a,int n)
{
    for(int i=0; i<n; i++)
    {
        double pivot=a[i][i];

        for(int j=0; j<=n; j++)a[i][j]/=pivot;

        for(int k=0; k<n; k++)if(k!=i)
            {
                double f=a[k][i];

                for(int m=0; m<=n; m++)a[k][m]-=f*a[i][m];

            }
    }

    vector<double> ans(n);

    for(int i=0; i<n; i++)ans[i]=a[i][n];

    return ans;
}

string polyString(const vector<double>&c)
{
    stringstream ss;

    int m=c.size()-1;

    bool first=true;

    for(int i=0; i<=m; i++)
    {
        double a=c[i];
        int p=i;

        if(!first)ss<<(a>=0?" + ":" - ");

        else if(a<0)
        {
            ss<<"-";
        }

        if(a<0)a=-a;
        ss<<fixed<<setprecision(6)<<a;

        if(p==1)ss<<"x";
        else if(p>1)ss<<"x^"<<p;

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
        int n,m;
        inputFile>>n>>m;

        vector<double>x(n),y(n);

        for(int i=0; i<n; i++)inputFile>>x[i];
        for(int i=0; i<n; i++)inputFile>>y[i];

        vector<double>S(2*m+1,0.0);

        for(int p=0; p<=2*m; p++)
        {
            for(int i=0; i<n; i++)S[p]+=pow(x[i],p);
        }

        vector<vector<double>>aug(m+1,vector<double>(m+2,0.0));

        for(int i=0; i<=m; i++)for(int j=0; j<=m; j++)aug[i][j]=S[i+j];

        for(int i=0; i<=m; i++)
        {
            double sum=0;

            for(int k=0; k<n; k++)sum+=pow(x[k],i)*y[k];

            aug[i][m+1]=sum;
        }

        vector<double>coef=gaussJordan(aug,m+1);
        string poly=polyString(coef);

        cout<<"Test Case "<<tc<<"\n";
        outputFile<<"Test Case "<<tc<<"\n";

        cout<<"Data points: "<<n<<"\n";
        outputFile<<"Data points: "<<n<<"\n";

        cout<<"Polynomial degree: "<<m<<"\n";
        outputFile<<"Polynomial degree: "<<m<<"\n";

        cout<<"x: ";
        outputFile<<"x: ";

        for(int i=0; i<n; i++)
        {
            cout<<x[i]<<" ";
            outputFile<<x[i]<<" ";
        }

        cout<<"\ny: ";
        outputFile<<"\ny: ";

        for(int i=0; i<n; i++)
        {
            cout<<y[i]<<" ";
            outputFile<<y[i]<<" ";
        }

        cout<<"\n";
        outputFile<<"\n";

        cout<<fixed<<setprecision(6);
        outputFile<<fixed<<setprecision(6);

        for(int i=0; i<=m; i++)
        {
            cout<<"a"<<i<<" = "<<coef[i]<<"\n";
            outputFile<<"a"<<i<<" = "<<coef[i]<<"\n";
        }

        cout<<"Polynomial: y = "<<poly<<"\n\n";
        outputFile<<"Polynomial: y = "<<poly<<"\n\n";

    }

    inputFile.close();
    outputFile.close();

    return 0;
}
