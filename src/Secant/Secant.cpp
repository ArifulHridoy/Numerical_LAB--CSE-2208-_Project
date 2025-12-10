#include<bits/stdc++.h>
using namespace std;
vector<double> roots;
ofstream fout;


double f(double x, const vector<double>& v)
{
    double poly = 0;
    for(int i = 0; i < v.size(); i++)
        poly += v[i] * pow(x, i);
    return poly;
}

void poly(const vector<double>& v)
{
    bool firstTerm = true;
    int n = v.size();

    for(int i = n - 1; i >= 0; i--)
    {
        if(fabs(v[i]) < 1e-12) continue;

        if(!firstTerm)
        {
            if(v[i] < 0) cout << " - ", fout << " - ";
            else cout << " + ", fout << " + ";
        }
        else
        {
            if(v[i] < 0) cout << "-", fout << "-";
            firstTerm = false;
        }

        double c = fabs(v[i]);

        if(i == 0) cout << c, fout << c;
        else if(i == 1) cout << c << "x", fout << c << "x";
        else cout << c << "x^" << i, fout << c << "x^" << i;
    }

    cout << endl;
    fout << endl;
}


void secant(double x0, double x1, double error, vector<double>& v)
{
    double x2;
    int it = 0;

    while(fabs(x1 - x0) >= error && fabs(f(x1, v)) >= error)
    {
        double fx0 = f(x0, v);
        double fx1 = f(x1, v);

        if(fabs(fx1 - fx0) < 1e-12) return;

        x2 = (x0 * fx1 - x1 * fx0) / (fx1 - fx0);
        it++;

        x0 = x1;
        x1 = x2;
    }

    if(fabs(f(x2, v)) > error) return;

    for(double r : roots)
        if(fabs(r - x2) < error) return;

    roots.push_back(x2);

    cout << fixed << setprecision(6);
    fout << fixed << setprecision(6);

    cout << "range: [" << x0 << ", " << x1 << "] ";
    fout << "range: [" << x0 << ", " << x1 << "] ";

    cout << "Root: " << x2 << " Iterations: " << it << endl;
    fout << "Root: " << x2 << " Iterations: " << it << endl;
}

int main()
{
    ifstream fin("Input.txt");
    fout.open("Output.txt");

    if(!fin.is_open())
    {
        cout << "Cannot open input.txt" << endl;
        return 0;
    }

    int t;
    fin >> t;

    while(t--)
    {
        roots.clear();

        int n;
        fin >> n;

        int m = n + 1;
        vector<double> v(m);

        for(double &x : v) fin >> x;
        reverse(v.begin(), v.end());

        cout << "\nPolynomial: ";
        fout << "\nPolynomial: ";
        poly(v);

        double xmax = 0;
        for(int i = 0; i < m; i++)
            xmax = max(xmax, 1.0 + fabs(v[i] / v[n]));

        cout << "Root bound: " << xmax << endl;
        fout << "Root bound: " << xmax << endl;

        double step = 0.45;
        double error = 1e-3;

        for(double i = -xmax; i <= xmax; i += step)
            secant(i, i + step, error, v);

        cout << "---------------------------------------\n";
        fout << "---------------------------------------\n";
    }

    fin.close();
    fout.close();
    return 0;
}
