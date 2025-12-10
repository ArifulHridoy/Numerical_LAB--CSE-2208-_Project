
#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

void printMatrix(vector<vector<double>>& a, int n, ofstream& out)
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

bool hasCoefficient(const vector<double>& row, int n)
{
	for(int j=0; j<n; j++)
	{
		if(abs(row[j])>EPS) return true;
	}
	return false;
}

void solve(vector<vector<double>>& a, int n, ofstream& out)
{
	for(int col=0, row=0; col<n && row<n; col++, row++)
	{
		int pivot=row;
		for(int r=row+1; r<n; r++)
		{
			if(abs(a[r][col])>abs(a[pivot][col])) pivot=r;
		}
		if(abs(a[pivot][col])<EPS)
		{
			row--;
			continue;
		}
		if(pivot!=row) swap(a[pivot],a[row]);
		double pivotVal=a[row][col];
		for(int j=col; j<=n; j++) a[row][j]/=pivotVal;
		for(int r=0; r<n; r++)
		{
			if(r==row) continue;
			double factor=a[r][col];
			if(abs(factor)<EPS) continue;
			for(int j=col; j<=n; j++) a[r][j]-=factor*a[row][j];
		}
	}

	cout<<"\nReduced Row Echelon Form:\n";
	out<<"\nReduced Row Echelon Form:\n";
	printMatrix(a,n,out);

	bool inconsistent=false;
	int rankA=0, rankAug=0;
	for(int i=0; i<n; i++)
	{
		bool coeffNZ=hasCoefficient(a[i],n);
		bool augNZ=coeffNZ || abs(a[i][n])>EPS;
		if(!coeffNZ && abs(a[i][n])>EPS)
		{
			inconsistent=true;
			break;
		}
		if(coeffNZ) rankA++;
		if(augNZ) rankAug++;
	}

	if(inconsistent)
	{
		cout<<"\nNo Solution (Inconsistent)\n";
		out<<"\nNo Solution (Inconsistent)\n";
		return;
	}

	if(rankA< n)
	{
		cout<<"\nInfinite Solutions\n";
		out<<"\nInfinite Solutions\n";
		return;
	}

	vector<double> x(n);
	for(int i=0; i<n; i++) x[i]=a[i][n];

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

	cout<<"GAUSS JORDAN ELIMINATION\n";
	outFile<<"GAUSS JORDAN ELIMINATION\n";

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
