#include <iostream>
#include <conio.h>
#include <fstream>
#include <list>
#include <string.h>
#include <stdio.h>
int usernamecheck(char A[20]);
int passcheck(char A[20]);
int userchecker(char A[20]) ;
int passchecker (char A[20]) ;
int calc1 (char A[7]) ;
int calc2 (char A[7]) ;
int opcheck (char A , int B , int C);
int factor(int A) ;
int TV(int A, int B) ;
int Mysin (int N, int X ) ;
using namespace std ;
int main ()
{
	//----------------- 1-Sign up -----------------------
	
	cout<<"all commands:\n1-Sign up \n2-Log in \n3-Help \nPlease entre your command:" ;
	char A[10] ;
	gets(A) ;
	for (int i=0;i<=10;i++)
		if(A[i]==('Q'||'q'))
			return 0;
	if(strcmp(A,"help")==0)
	{
		cout<<"Description of Commands:\n1-sign up: you can register on this console with this command \n 2-Login: you can Log in on this console with this command\n " ;
		cout<<"3-Help : with this command i can help you not to be confused\n" ;
		return main();
	}

	if(strcmp(A,"sign up")==0)
	{
		char B[20];
		int F=0;
		while (F==0)
		{
			cout<<"please enter username:\n";
			gets(B);
			F=usernamecheck(B) ;
		}
		F=0 ;
		char C[20] ;
		while(F==0) 
		{
			cout<<"please enter password:\n";
			gets(C);
			F=passcheck(C) ;
		}
		F=0 ;
		char D[10];
		while (F==0)
		{
			cout<<"please confirm your password:\n";
			gets(D);
			F=passcheck(D) ;
			if (strcmp(C,D)!=0)
				F=0 ;
		}
		ofstream textFile;
		 textFile.open("Users.txt",std::ios::app);
		 textFile << B<<'\t';
	    textFile << C<<'\n';
		textFile.close() ;

		cout<<"user "<<B<<" shas been successfully added\n" ;
		return main();
	}
	//----------------- 2-log in ---------------
	if(strcmp(A,"log in")==0)
	{
		char S[20],E[20],F[10];
		int H=0,L=0,h=0 ;
		while (H==0)
		{	
			ifstream textFile("Users.txt") ;
			cout<<"entre your username:\n";
			gets(E) ;
			for (int i=0;i<=10;i++)
			{
				if(E[i]=='Q')
					return 0;
			}
			H=userchecker(E) ;
			if (H==1)
			{	
				cout<<"entre your Password:\n" ;
				gets(F);
				H=0 ;
				H=passchecker(F) ;
				if(H==1)
					cout<<"you are logged in successfully!\n" ;
				else 
				{
					cout<<"wrong Username or password\n" ;
					H=0 ;
					textFile.close() ;
				}
			}
		}
		while (h==0)
		{

			cout<<E<<">> \n1-calc \n2-load\n3-log out\n";
			cout<<E<<">>";
			char J[8];
			gets(J) ;
			for (int i=0;i<=10;i++)
			{
				if(J[i]=='Q')
					return 0;
			}
		//--------------------- 3-calculate ----------------------
			if(strcmp(J,"calc")==0)
			{
				char Z[7],X,V[7] ;
				float R=0,T;
				int t=0,f=1,l=1,P=0,z,v;
				while (P==0)
					{
						cout<<E<<">>enter your first number:" ;
						gets(Z);
						for (int i=0;i<=10;i++)
						{
							if(Z[i]=='Q')
								return 0;
						}
						cout<<E<<">>enter your second number:";
						gets(V);
						for (int i=0;i<=10;i++)
						{
							if(V[i]=='Q')
								return 0;
						}
						cout<<E<<">>enter your operator:";
						cin>>X ;
						if(X=='Q')
							return 0;
						R=calc1 (Z) ;
						if (R!=0)
						{
							P=1 ;
							T=calc2(V) ;
							if(T!=0)
								P=1 ;
							else 
								cout<<E<<">>wrong numbers\n" ;
						}
						else 
							cout<<E<<">>wrong numbers\n" ;

					}
					f=opcheck(X,R,T) ;
					if (f==55555555)
						P=0 ;
					else
						cout<<E<<">>Answer is  "<<f<<'\n' ;
			}
			//---------------- 4-Load ---------------------
			if (strcmp(J,"load")==0)
			{
				char Q[20] ;
				int d=0 ;
				while(d==0)
				{
					cout<<E<<">>what file do you want to load:" ;
					char O[15] ;
					int e=0;
					gets(O) ;
					for (int i=0;i<=10;i++)
					{
						if(O[i]=='Q')
							return 0;
					}
					fstream textFile("O") ;
					if (!textFile)
						cout<<"No such file in directory" ;
					else 
					{
						while(!textFile.eof())
						{
							textFile >> Q ;
							cout<<Q ;
						}
						d=1 ;
					}

				}
			}
			//--------------- 5-log out ----------------

			if(strcmp(J,"log out")==0)
			{
				cout<<E<<">>you have log out successfully\n";
				getch() ;
				return 0 ;
			}
			h=0 ;
			
		}

	}
	if(strcmp(A,"help")!=0)
	{
		cout<<"you are inserting the wrong command\n" ;
	}
	getch();
	return 0;
}
//-------------------

int usernamecheck(char A[20]) 
{
	if(strlen(A)<=2 || strlen (A)>=20)
		{
			cout<<"wrong input format\n";
			return 0 ;
		}
		for (int i=0 ;A[i]!='\0';i++)
		{
			if (A[i]>='A' && A[i]<='z')
				int f=1 ;
			else 
			{
			cout<<"wrong input format\n";
			return 0 ;
			}
		}
	return 1 ;

}
///------------------------------------------

int passcheck(char A[20]) 
{
	if (strlen(A)<=2 || strlen (A)>=10)
	{
		cout<<"wrong input format\n" ;
		return 0 ;
	}
	for (int i=0 ;A[i]!='\0';i++)
		{
			if (A[i]>='0' && A[i]<='9')
				int f=1 ;
			else 
			{
			cout<<"wrong input format\n";
			return 0 ;
			}
		}
	return 1;
}
//-----------------
int userchecker(char A[20]) 
{
	char S[20];
	int H=0 ;
	ifstream textFile("Users.txt") ;
	while(!textFile.eof())
	{
		textFile >> S ;
		for (int i=0 ; i<=1000;i++)
		{
			H=strcmp(A,S);
			if(H==0)
				return 1;
			while(!textFile.eof())
			{
				textFile >> S;
				textFile >> S;
				break ;
			}

		}
		textFile>>S;
	}
	return 0 ;
}



int passchecker (char A[20]) 
{
	char S[20];
	int H=0 ;
	ifstream textFile("Users.txt") ;
	while(!textFile.eof())
	{
		textFile >> S ;
		textFile >> S ;
		for (int i=0 ; i<=1000;i++)
		{
			H=strcmp(A,S);
			if(H==0)
				return 1;
			while(!textFile.eof())
			{
				textFile >> S;
				textFile >> S;
				break ;
			}

		}
		textFile>>S;
	}
	return 0 ;
}
int calc1 (char A[7]) 
{
	
	float t,H,R=0,l=0,f=0,g=0;
	int i=0,h=0 ;
		while(A[i]!='\0')
			{
				
				if(A[i]>='0' && A[i]<='9' || A[i]==' '|| A[i]=='.' || A[i]=='-')
				{
					if (A[i]=='-')
						t=1 ;
					else if (A[i]=='.')
						{
							l++;
							g=1 ;
						}
					
					else	if (A[i]==' ')
							t=1 ;
					else
					{
						H=A[i]-48;
						R=R*10+H ;
						f=f+1 ;
						if (g!=0)
						{
							f=0 ;
							g=0 ;
						}

					}
				}
				else 
				{
					cout<<"wrong input format\n" ;
					return 0 ;

				}
				i++;
				h=i-1 ;
				

			} 
		if (f!=0)
			f=f+1;
		if (l!=0||l==1)
		{
			if(l==1 && (f==0 || f==1))
			{
				R=R/10 ;
			}

			else
			{	
				for (int i=1 ; i<=f;i++)
					l=l*10 ;
				R = R/l ;
			}
		}
		if(A[i]=='-')
			R=-1*R ;
	return R;
}

int calc2 (char A[7]) 
{
	float t=0,H,R=0,l=0,f=0,g=0;
	int i=0,h=0 ;
		while(A[i]!='\0')
			{
				
				if(A[i]>='0' && A[i]<='9' || A[i]==' '|| A[i]=='.' || A[i]=='-')
				{
					if (A[i]=='-')
						t=1 ;
					else if (A[i]=='.')
						{
							l++;
							g=1 ;
						}
					
					else	if (A[i]==' ')
							t++ ;
					else
					{
						H=A[i]-48;
						R=R*10+H ;
						f=f+1 ;
						if (g!=0)
						{
							f=0 ;
							g=0 ;
						}

					}
				}
				else 
				{
					cout<<"wrong input format\n" ;
					return 0 ;

				}
				i++;
				h=i-1 ;
				

			} 
		if (f!=0)
			f=f+1;
		if (l!=0||l==1)
		{
			if(l==1 && (f==0 || f==1))
			{
				R=R/10 ;
			}

			else
			{	
				for (int i=1 ; i<=f;i++)
					l=l*10 ;
				R = R/l ;
			}
		}
		if(A[i]=='-')
			R=-1*R ;
	return R;
}
int opcheck (char A , int B , int C) 
{
	int F;
	switch (A)
	{
		case '-' :
			F=B-C ;
			break ;
		case '*' :
			F=B*C ;
			break ;
		case '+' :
			F=B+C;
			break ;
		case '/' :
			F=B/C ;
			break ;
		case '\\' :
			F=B/C ;
			break ;
		case '%' :
			F=B%C ;
			break ;
		case '!' :
			F=factor(B) ;
			break ;
		case '^' :
			F=TV(B,C) ;
			break ;
		case '#':
			F=Mysin(B,C) ;
			break ;
		default :
			cout<<"wrong input format" ;
			return 55555555;
	}
	return F ;
}

int factor(int A)
{
	int sum=1 ;
	for (int i=1;i<=A;i++)
		sum = sum*i ;
	return sum ;
}
int TV(int A, int B) 
{
	int sum = 1 ;
	for(int i=1; i<=B;i++)
		sum=A*sum ;
	return sum ;
}
int Mysin(int X , int N) 
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
