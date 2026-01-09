#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
void showMatrix(const bool X[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) cout<<X[i][j]<<' ';
		cout<<"\n";
	}
}

void inputMatrix(double X[N][N]){
	for(int i=0;i<N;i++){
		cout<<"Row "<<i+1<<": ";
		for(int j=0;j<N;j++){
			cin>>X[i][j];
		}
	}
}

void findLocalMax(const double X[N][N], bool ans[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==0 || j==0 || i==N-1 || j==N-1) ans[i][j]=0;
			else{
				if(X[i][j]>=X[i-1][j] && X[i][j]>=X[i][j-1] && X[i][j]>=X[i+1][j] && X[i][j]>=X[i][j+1]) ans[i][j]=1;
				else ans[i][j]=0;
			}
		}
	}
}