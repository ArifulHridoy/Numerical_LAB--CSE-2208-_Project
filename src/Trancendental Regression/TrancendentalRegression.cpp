#include<bits/stdc++.h>

using namespace std;

void regression(const vector<double>&x,const vector<double>&y,double&a,double&b)
{
    int n=x.size();
    double sumX=0,sumY=0,sumXY=0,sumX2=0;

    for(int i=0; i<n; i++)
    {
        sumX+=x[i];
        sumY+=y[i];
        sumXY+=x[i]*y[i];
        sumX2+=x[i]*x[i];
    }

    b=(n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
    a=(sumY-b*sumX)/n;
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
        int modelType;
        inputFile>>modelType;

        int n;
        inputFile>>n;

        vector<double>x(n),y(n);

        for(int i=0; i<n; i++)inputFile>>x[i];
        for(int i=0; i<n; i++)inputFile>>y[i];

        cout<<"Test Case "<<tc<<"\n";
        outputFile<<"Test Case "<<tc<<"\n";

        cout<<"Model Type: "<<modelType<<"\n";
        outputFile<<"Model Type: "<<modelType<<"\n";

        cout<<"Number of data points: "<<n<<"\n";
        outputFile<<"Number of data points: "<<n<<"\n";

        cout<<"x: ";
        outputFile<<"x: ";

        for(int i=0; i<n; i++)
        {
            cout<<x[i]<<" ";
            outputFile<<x[i]<<" ";
        }

        cout<<"\n";
        outputFile<<"\n";

        cout<<"y: ";
        outputFile<<"y: ";

        for(int i=0; i<n; i++)
        {
            cout<<y[i]<<" ";
            outputFile<<y[i]<<" ";
        }

        cout<<"\n";
        outputFile<<"\n";

        double a,b;

        if(modelType==1)
        {
            vector<double>X(n),Y(n);

            for(int i=0; i<n; i++)
            {
                X[i]=x[i];
                Y[i]=log(y[i]);
            }

            regression(X,Y,a,b);
            a=exp(a);

            cout<<fixed<<setprecision(6);
            outputFile<<fixed<<setprecision(6);

            cout<<"a: "<<a<<"\n";
            outputFile<<"a: "<<a<<"\n";

            cout<<"b: "<<b<<"\n";
            outputFile<<"b: "<<b<<"\n";

            cout<<"Model: y = "<<a<<" * e^("<<b<<"x)\n";
            outputFile<<"Model: y = "<<a<<" * e^("<<b<<"x)\n";
        }

        else if(modelType==2)
        {
            vector<double>X(n),Y(n);

            for(int i=0; i<n; i++)
            {
                X[i]=log(x[i]);
                Y[i]=log(y[i]);
            }

            regression(X,Y,a,b);
            a=exp(a);

            cout<<fixed<<setprecision(6);
            outputFile<<fixed<<setprecision(6);

            cout<<"a: "<<a<<"\n";
            outputFile<<"a: "<<a<<"\n";

            cout<<"b: "<<b<<"\n";
            outputFile<<"b: "<<b<<"\n";

            cout<<"Model: y = "<<a<<" * x^("<<b<<")\n";
            outputFile<<"Model: y = "<<a<<" * x^("<<b<<")\n";
        }

        else if(modelType==3)
        {
            vector<double>X(n),Y(n);

            for(int i=0; i<n; i++)
            {
                X[i]=exp(x[i]/4);
                Y[i]=y[i];
            }

            regression(X,Y,a,b);
            cout<<fixed<<setprecision(6);
            outputFile<<fixed<<setprecision(6);

            cout<<"a: "<<a<<"\n";
            outputFile<<"a: "<<a<<"\n";

            cout<<"b: "<<b<<"\n";
            outputFile<<"b: "<<b<<"\n";

            cout<<"Model: y = "<<a<<" + "<<b<<" * e^(x/4)\n";
            outputFile<<"Model: y = "<<a<<" + "<<b<<" * e^(x/4)\n";
        }

        cout<<"\n";
        outputFile<<"\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
