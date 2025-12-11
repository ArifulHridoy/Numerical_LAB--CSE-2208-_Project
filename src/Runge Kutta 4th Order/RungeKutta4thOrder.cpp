#include<bits/stdc++.h>
using namespace std;
#define db double

double f(double x,double y)
{
    return x*y+y;
}

double rk4(db x,db y,db h)
{
    db k1=h*f(x,y);
    db k2=h*f(x+h/2.0,y+k1/2.0);
    db k3=h*f(x+h/2.0,y+k2/2.0);
    db k4=h*f(x+h,y+k3);
    return y+(1.0/6.0)*(k1+2*k2+2*k3+k4);
}

void solve(int t,db x0,db y0,db xn,db h,ofstream& fout)
{
    db x=x0,y=y0;
    int steps=0;

        while(x+1e-12<xn)
        {
            y=rk4(x,y,h);
            x+=h;
            steps++;
        }

    fout<<"\nTEST CASE #"<<t<<endl<<endl;
    fout<<fixed<<setprecision(3);
    fout<<"Initial x0: "<<x0<<", y0: "<<y0<<endl;
    fout<<"Final x: "<<xn<<endl;
    fout<<"Step size (h): "<<h<<endl;
    fout<<"Number of steps: "<<steps<<endl;
    fout<<"Result: y("<<xn<<") = "<<y<<endl;

    cout<<"\nTEST CASE #"<<t<<endl<<endl;
    cout<<fixed<<setprecision(3);
    cout<<"Initial x0: "<<x0<<", y0: "<<y0<<endl;
    cout<<"Final x: "<<xn<<endl;
    cout<<"Step size (h): "<<h<<endl;
    cout<<"Number of steps: "<<steps<<endl;
    cout<<"Result: y("<<xn<<") = "<<y<<endl;
}

int main(){
    ifstream fin("Input.txt");
    if(!fin.is_open())
    {
        cout<<"Error: Could not open Input.txt";
        return 0;
    }

    int T;
    fin>>T;

    ofstream fout("Output.txt");
    fout<<"Function: f(x,y) = xy + y\n";
    fout<<"Total Test Cases: "<<T<<"\n";

    cout<<"Function: f(x,y) = xy + y\n";
    cout<<"Total Test Cases: "<<T<<"\n";

    double h=0.001;

    for(int t=1;t<=T;t++)
    {
        double x0,y0,xn;
        fin>>x0>>y0>>xn;
        double step=h;
        if(xn<x0) step=-h;

        solve(t,x0,y0,xn,step,fout);
    }

    fin.close();
    fout.close();

    cout<<"\nAll test cases completed! Results saved to Output.txt\n";
    return 0;
}
