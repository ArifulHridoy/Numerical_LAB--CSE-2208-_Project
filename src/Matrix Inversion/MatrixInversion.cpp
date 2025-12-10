#include<bits/stdc++.h>
using namespace std;

const double EPS=1e-10;

void printMatrix(const vector<vector<double>>&a, int n, ofstream&out)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<a[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}
}

void printAugmented(const vector<vector<double>>&a, int n, ofstream&out)
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

bool invert(vector<vector<double>>&a, vector<vector<double>>&inv, int n, ofstream&out)
{
	vector<vector<double>> aug(n, vector<double>(2*n));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			aug[i][j]=a[i][j];
			aug[i][n+j]=(i==j) ? 1.0 : 0.0;
		}
	}

	cout<<"\nAugmented [A|I]:\n";
	out<<"\nAugmented [A|I]:\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2*n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<aug[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<aug[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}

	for(int col=0, row=0; col<n && row<n; col++, row++)
	{
		int pivot=row;
		for(int r=row+1; r<n; r++)
		{
			if(abs(aug[r][col])>abs(aug[pivot][col])) pivot=r;
		}

		if(abs(aug[pivot][col])<EPS)
		{
			cout<<"\nMatrix is singular (det=0)\n";
			out<<"\nMatrix is singular (det=0)\n";
			return false;
		}

		if(pivot!=row) swap(aug[pivot],aug[row]);

		double pivotVal = aug[row][col];
		for(int j=0; j<2*n; j++) aug[row][j] /= pivotVal;

		for(int r=0; r<n; r++)
		{
			if(r==row) continue;
			double factor = aug[r][col];
			if(abs(factor)<EPS) continue;
			for(int j=0; j<2*n; j++) aug[r][j]-=factor*aug[row][j];
		}
	}

	cout<<"\nReduced Row Echelon Form [I|A^-1]:\n";
	out<<"\nReduced Row Echelon Form [I|A^-1]:\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2*n; j++)
		{
			cout<<fixed<<setprecision(3)<<setw(10)<<aug[i][j]<<" ";
			out<<fixed<<setprecision(3)<<setw(10)<<aug[i][j]<<" ";
		}
		cout<<"\n";
		out<<"\n";
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++) inv[i][j]=aug[i][n+j];
	}

	return true;
}

void solve(vector<vector<double>>a, vector<double>b, int n, ofstream &out)
{
	cout<<"\nMatrix A:\n";
	out<<"\nMatrix A:\n";
	printMatrix(a,n,out);

	cout<<"\nVector b:\n";
	out<<"\nVector b:\n";
	for(int i=0; i<n; i++)
	{
		cout<<fixed<<setprecision(3)<<setw(10)<<b[i]<<"\n";
		out<<fixed<<setprecision(3)<<setw(10)<<b[i]<<"\n";
	}

	vector<vector<double>>inv(n, vector<double>(n));

	if(!invert(a,inv,n,out))
	{
		return;
	}

	cout<<"\nInverse Matrix A^-1:\n";
	out<<"\nInverse Matrix A^-1:\n";
	printMatrix(inv, n, out);

	vector<double> x(n, 0);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++) x[i]+=inv[i][j]*b[j];
	}

	cout<<"\nSolution (x = A^-1 * b):\n";
	out<<"\nSolution (x = A^-1 * b):\n";
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

	cout<<"MATRIX INVERSION\n";
	outFile<<"MATRIX INVERSION\n";

	for(int t=1; t<=testCases; t++)
	{
		int n; inFile>>n;

		cout<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";
		outFile<<"\nTest Case "<<t<<" ("<<n<<"x"<<n<<")\n";

		vector<vector<double>> a(n,vector<double>(n));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++) inFile>>a[i][j];
		}

		vector<double> b(n);
		for(int i=0; i<n; i++) inFile>>b[i];

		solve(a,b,n,outFile);
	}

	inFile.close();
	outFile.close();
	return 0;
}
