#include<bits/stdc++.h>
using namespace std;

double f(double x,double y){
    return x*y+y;
}

double rk4(double x,double y,double h){
    double k1=h*f(x,y);
    double k2=h*f(x+h/2.0,y+k1/2.0);
    double k3=h*f(x+h/2.0,y+k2/2.0);
    double k4=h*f(x+h,y+k3);
    return y+(1.0/6.0)*(k1+2*k2+2*k3+k4);
}

void solveTestCase(int testNum,double x0,double y0,double xn,double h,ofstream& fout){
    double x=x0,y=y0;
    int steps=0;
    while(x+1e-12<xn){
        y=rk4(x,y,h);
        x+=h;
        steps++;
    }
    fout<<"\nTEST CASE "<<testNum<<"\n";
    fout<<fixed<<setprecision(3);
    fout<<"Initial x0: "<<x0<<", y0: "<<y0<<"\n";
    fout<<"Final x: "<<xn<<"\n";
    fout<<"Step size (h): "<<h<<"\n";
    fout<<"Number of steps: "<<steps<<"\n";
    fout<<"Result: y("<<xn<<") = "<<y<<"\n";
    cout<<"\nTEST CASE "<<testNum<<"\n";
    cout<<fixed<<setprecision(3);
    cout<<"Initial x0: "<<x0<<", y0: "<<y0<<"\n";
    cout<<"Final x: "<<xn<<"\n";
    cout<<"Step size (h): "<<h<<"\n";
    cout<<"Number of steps: "<<steps<<"\n";
    cout<<"Result: y("<<xn<<") = "<<y<<"\n";
}

int main(){
    ifstream fin("Input.txt");
    if(!fin.is_open()){
        cout<<"Error: Could not open Input.txt\n";
        return 0;
    }
    int T;
    fin>>T;
    ofstream fout("Output.txt");
    fout<<"Function: f(x,y) = xy + y\n";
    fout<<"Total Test Cases: "<<T<<"\n";
    cout<<"Function: f(x,y) = xy + y\n";
    cout<<"Total Test Cases: "<<T<<"\n";
    double h=0.0001;
    for(int testNum=1;testNum<=T;testNum++){
        double x0,y0,xn;
        fin>>x0>>y0>>xn;
        solveTestCase(testNum,x0,y0,xn,h,fout);
    }
    fin.close();
    fout.close();
    cout<<"\nAll test cases completed! Results saved to Output.txt\n";
    return 0;
}
