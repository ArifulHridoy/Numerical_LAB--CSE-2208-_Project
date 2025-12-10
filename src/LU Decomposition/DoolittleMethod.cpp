#include<bits/stdc++.h>
using namespace std;

const double EPS=1e-10;

void printMatrix(const vector<vector<double>>&a, int n, ofstream& out)
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

bool decompose(const vector<vector<double>>&a, vector<vector<double>>&L, vector<vector<double>>&U, int n, bool &singular)
{
	singular=false;
	for(int i=0; i<n; i++)
	{
		for(int k=i; k<n; k++)
		{
			double sum=0;
			for(int j=0; j<i; j++) sum+=L[i][j]*U[j][k];
			U[i][k]=a[i][k]-sum;
		}
		if(abs(U[i][i])<EPS)
		{
			singular=true;
			U[i][i]=0.0;
			L[i][i]=1.0;
			for(int k=i+1; k<n; k++) L[k][i]=0.0;
			continue;
		}
		for(int k=i; k<n; k++)
		{
			if(i==k) L[i][i]=1.0;
			else
			{
				double sum=0;
				for(int j=0; j<i; j++) sum+=L[k][j]*U[j][i];
				L[k][i]=(a[k][i]-sum)/U[i][i];
			}
		}
	}
	return true;
}

vector<double>forwardSub(const vector<vector<double>>&L, const vector<double>&b, int n)
{
	vector<double>y(n);
	for(int i=0; i<n; i++)
	{
		double sum=0;
		for(int j=0; j<i; j++) sum+=L[i][j]*y[j];
		y[i]=(b[i]-sum)/L[i][i];
	}
	return y;
}

vector<double>backSub(const vector<vector<double>>&U, const vector<double>&y, int n)
{
	vector<double>x(n);
	for(int i=n-1; i>=0; i--)
	{
		double sum=0;
		for(int j=i+1; j<n; j++) sum+=U[i][j]*x[j];
		x[i]=(y[i]-sum)/U[i][i];
	}
	return x;
}

void solve(vector<vector<double>>a, int n, ofstream &out)
{
	vector<vector<double>>L(n,vector<double>(n,0)),U(n,vector<double>(n,0));
	bool singular=false;

	decompose(a,L,U,n,singular);

	vector<double> b(n);
	for(int i=0; i<n; i++) b[i]=a[i][n];

	vector<double>y=forwardSub(L,b,n);

	bool zeroPivot=false, inconsistent=false;
	for(int i=0; i<n; i++)
	{
		if(abs(U[i][i])<EPS) zeroPivot=true;
		bool rowZero=true;
		for(int j=0; j<n; j++)
		{
			if(abs(U[i][j])>EPS)
			{
				rowZero=false;
				break;
			}
		}
		if(rowZero && abs(y[i])>EPS) inconsistent=true;
	}

	cout<<"\nL matrix:\n";
	out<<"\nL matrix:\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<L[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<L[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}

	cout<<"\nU matrix:\n";
	out<<"\nU matrix:\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<U[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<U[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}

	if(zeroPivot||singular)
	{
		cout<<"\nMatrix A is singular (det A = 0)\n";
		out<<"\nMatrix A is singular (det A = 0)\n";
		if(inconsistent)
		{
			cout<<"=> System has NO solution.\n";
			out<<"=> System has NO solution.\n";
		}
		else
		{
			cout<<"=> System has infinitely many solutions.\n";
			out<<"=> System has infinitely many solutions.\n";
		}
		return;
	}

	vector<double>x=backSub(U,y,n);

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

	cout<<"LU DECOMPOSITION (Doolittle)\n";
	outFile<<"LU DECOMPOSITION (Doolittle)\n";

	for(int t=1; t<=testCases; t++)
	{
		int n;
		inFile>>n;

		cout<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";
		outFile<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";

		vector<vector<double>> a(n,vector<double>(n+1));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<=n; j++) inFile>>a[i][j];
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
