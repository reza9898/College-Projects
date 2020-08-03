#include <iostream>
#include <conio.h>
//-----------------Declarations of Functions------------
int Mysin(int N , int X) ;
using namespace std ; 
//---------------------Main Function--------------------
int main() 
{
	int a,b,X,N,S,z;

	cout<<"please entre N,X :" ;
	cin>>X ;
	cin>>N ;

	z = Mysin(N , X) ;
	S=(a*b*z) /2 ;

	cout<<S ;

	getch() ;
	return 0 ;
}
//--------------Implementations of Functions-------------
int Mysin(int N , int X) 
{
	int A=X,B=1,S=-1,F,sum=0,sin,i;
	F=X;
	for ( int i=3; i<=N ; i=i+2)
	{
		A=A*X*X ;
		B=B * i * (i-1 ) ;
		sum = sum + (A/B)*S ;
		S = S*-1 ;
	}
	sin= sum + F ;
	return sin ;
}