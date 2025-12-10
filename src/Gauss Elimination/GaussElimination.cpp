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
