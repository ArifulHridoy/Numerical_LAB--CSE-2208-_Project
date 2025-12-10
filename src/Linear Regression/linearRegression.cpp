#include <bits/stdc++.h>
using namespace std;
#define db double
void solve(int tc, ifstream &fin, ofstream &fout)
{
    int n;
    fin >> n;
    vector<db> x(n), y(n);
    for(int i = 0; i < n; i++) fin>>x[i];
    for(int i = 0; i < n; i++) fin>>y[i];
    db sX = 0, sY = 0, sXY = 0, sXs = 0;
    for(int i = 0; i < n; i++)
    {
        sX  += x[i];
        sY  += y[i];
        sXY += x[i] * y[i];
        sXs += x[i] * x[i];
    }
    db b = (n * sXY - sX * sY) / (n * sXs - sX * sX);
    db a = (sY - b * sX) / n;
    cout << "Test Case #" << tc << "\n";
    cout << "Number of points: " << n << "\n";
    cout << "x values: ";
    for (db i : x) cout << i << " ";
    cout << "\ny values: ";
    for (db i : y) cout << i << " ";
    //cout<<fixed<<setprecision(4);
    //fout<<fixed<<setprecision(4);

    cout << "\nComputed Intercept (a): " <<a;
    cout << "\nComputed Slope (b): " <<b;
    cout << "\nLine Equation: y = " <<a << " + " << b << "x"<<endl<<endl;

    fout << "Test Case #" <<tc<<endl;
    fout << "Number of points: "<<n<<endl;
    fout << "x values: ";
    for (db i : x) fout <<i<<" ";
    fout << "\ny values: ";
    for (db i : y) fout <<i<<" ";

    fout << "\nComputed Intercept (a): " <<a;
    fout << "\nComputed Slope (b): " <<b;
    fout << "\nLine Equation: y = "<< a << " + " <<b<<"x"<<endl<<endl;
}


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout << "Error: input.txt not found!" << endl;
        return 0;
    }
    int t;
    fin >> t;
    cout << "Total Test Cases: " << t << "\n\n";
    fout << "Total Test Cases: " << t << "\n\n";
    for(int tc = 1; tc <= t; tc++)
    {
        solve(tc, fin, fout);
    }
    cout << "All results written to output.txt successfully!\n";

}
