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
