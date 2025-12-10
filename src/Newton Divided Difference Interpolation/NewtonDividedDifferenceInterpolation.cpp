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
