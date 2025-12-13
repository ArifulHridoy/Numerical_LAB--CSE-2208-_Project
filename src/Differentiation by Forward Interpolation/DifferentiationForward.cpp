#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

int fact(int n)
{
    if(n==1 or n==0) return 1;
    else return fact(n-1)*n;
}

db f(db x)
{
    return ((pow(cos(x),5))-6*(pow(sin(x),5)))+log(x)+2;
}

db f1(db x)
{
    return -5*sin(x)*pow(cos(x),4)  -30*pow(sin(x),4)*cos(x)+1/x;
}

db f2(db x)
{
     return 30 * pow(sin(x), 5)-120 * pow(sin(x), 3) * pow(cos(x), 2)
            +20 * pow(sin(x), 2) * pow(cos(x), 3)
           -5 * pow(cos(x), 5)
           -1.0 / pow(x, 2);
}

vector<vector<db>> difftable(vector<db>&y)
{
    int n=y.size();
    vector<vector<db>>dftbl(n,vector<db>(n,0));
    for(int i=0;i<n;i++)  dftbl[i][0]=y[i];
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            dftbl[i][j]=dftbl[i+1][j-1]-dftbl[i][j-1];
        }
    }
    return dftbl;
}

void solve(int tc, ifstream &fin, ofstream &fout)
{


    int n;
    fin>>n;
    cout<<"Reading number of intervals n: "<<n<<endl;
    fout<<"Reading number of intervals n: "<<n<<endl;

    db a,b;
    fin>>a>>b;
    cout<<"Reading interval start (a): "<<a<<", end (b): "<<b<<endl;
    fout<<"Reading interval start (a): "<<a<<", end (b): "<<b<<endl;

    db X;
    fin>>X;
    cout<<"Reading interpolation point X: "<<X<<endl;
    fout<<"Reading interpolation point X: "<<X<<endl;

    db h=(b-a)/n;

    vector<db>x(n),y(n);
    for(int i=0;i<n;i++)
    {
        x[i]=a+ i*h;
        y[i]=f(x[i]);
    }

    db u=(X-x[0])/h;
    vector<vector<db>>diff=difftable(y);

    db y1 = (diff[0][1] + (2*u-1)*diff[0][2]/fact(2)+ (3*u*u-6*u+2)*diff[0][3]/fact(3))/h;
    db y2= ((diff[0][2])+(u-1)*diff[0][3])/(h*h);

    db y1_1=f1(X);
    db y2_1=f2(X);
    db error_y1 = abs((y1_1-y1)/y1)*100;
    db error_y2 = abs((y2_1-y2)/y2)*100;


    cout<<"\nTEST CASE #"<<tc<<"\n";
    cout<<"n: "<<n<<", a: "<<a<<", b: "<<b<<", X: "<<X<<"\n";
    cout<<"Difference table:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(10)<<diff[i][j]<<" ";
        cout<<endl;
    }
    cout<<"y': "<<y1<<endl;
    cout<<"y'': "<<y2<<endl;
    cout<<"functional value"<<endl;
    cout<<"y': "<<y1_1<<endl;
    cout<<"y'': "<<y2_1<<endl;
    cout<<"First diff error: "<<error_y1<<"%"<<endl;
    cout<<"Second diff error: "<<error_y2<<"%"<<endl;


    fout<<"\nTEST CASE #"<<tc<<"\n";
    fout<<"n: "<<n<<", a: "<<a<<", b: "<<b<<", X: "<<X<<"\n";
    fout<<"Difference table:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            fout<<setw(10)<<diff[i][j]<<" ";
        fout<<endl;
    }
    fout<<"y': "<<y1<<endl;
    fout<<"y'': "<<y2<<endl;
    fout<<"functional value"<<endl;
    fout<<"y': "<<y1_1<<endl;
    fout<<"y'': "<<y2_1<<endl;

    fout<<"First diff error: "<<error_y1<<"%"<<endl;
    fout<<"Second diff error: "<<error_y2<<"%"<<endl;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    if(!fin)
    {
        cout<<"Error: input.txt not found\n";
        return 0;
    }

    ofstream fout("output.txt");

    int t;
    fin>>t;
    cout<<"Total Test Cases: "<<t<<"\n";
    fout<<"Total Test Cases: "<<t<<"\n";

    for(int tc=1;tc<=t;tc++)
    {
        solve(tc, fin, fout);
    }

    cout<<"\nAll test cases completed! Results saved to output.txt\n";
    fin.close();
    fout.close();
    return 0;
}
