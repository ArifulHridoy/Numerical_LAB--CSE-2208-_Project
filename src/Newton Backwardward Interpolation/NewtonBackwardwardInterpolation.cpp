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
