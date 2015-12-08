// my_AKS.cpp: определяет точку входа для консольного приложения.
//

#include"stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


/* Standard C Function: Greatest Common Divisor */
long gcd ( long long a, long b )
{
	long c;
	while ( a != 0 ) 
	{
		c = a; a = b%a;  b = c;
	}
	return b;
}

//PerfectPower
long PerfectPower ( long n)
{


	long b=2;
	long k=(log(n)/log(2));
	long long a;
	while (b<=k)
	{
		long c=(ceil((log(n)/log(2))/log(b)));
		//a=pow(2,c);
		a = 1<<c;
		while (pow(a,b)>n)
		{
			double d=(((b-1)*a+n/pow(a,(b-1)))/b);
			long e=(floor(d));
			a=long(e);
		}

		if (n==pow(a,b))// if n is a perfect power
		{
			//cout<<n<<"_is_a_perfect_power,_hence_is_not_prime\n";
			//cout<<"n=a^b\n";
			//cout<<"b="<<b<<"\n";
			//cout<<"a="<<a<<"\n\n";
			return(1);
		}
		else 
		{
			b=b+1;
		}
	}
	if  (n!=pow(a,b))

	{
		return(0);//n is not a perfect power
	}
}

//isprime
long isprime (long n)

{
	long s;
	long t;
	t=4;
	for (s=2; t<=n; s++)
	{

		if (n%s==0)
		{//n has factors other than n and 1, hence is composite. 
			//cout<<"is composite";
			return(0);
		}
		else
		{
			t=t+2*s-1;
		}
	}
	//cout<<"is prime";
	return(1);// n is prime no divisor other than n a nd 1 found
}

//largestprime
long largestprime ( long n)

{

	long f=1;
	long r=2;
	long x=n;
	while (x!=1 && sqrt(r)<=n)

	{
		while (x%r==0)
		{
			x=x/r;
			f=r;
		}
		r=r+1;
	}
	if (x==1)
	{
		//cout<< f;
		return (f);
	}
	else 
	{
		//cout<< x;
		return(x);
	}
}

//congruence
long congruence (long a, long n,  long r)

{	long x=1;

/*

	

	long b=pow(x,r)-1;// b=x^r-1;
	long c=x+a;

	int f=((int)(pow(c,n)))%b;
	long e=x;
	int  g=(int)(pow(e,n))%b;

	g=g-a;
	if(f==g)
	{
	//cout<<"n is prime\n";
	return(1);//n is prime
	}
	else
	{
	//cout<<"n is not prime\n ";
	return(0);// n is not prime*/
if ((((long)(pow(( x +a ),n) - (pow(x,n) +a))%n!=0) && ((long)(pow(x,r) - 1) % n != 0 )))
	{
		return(0);//cout<<"n is not prime\n ";

	}
	else return(1);//cout<<"n is prime\n";	

}	
	
	 


int _tmain(int argc, _TCHAR* argv[])
{	
	/*if (argc != 3) 
	{
		cout<<"error";
		return 1;
	}
	*/

	
	//ifstream file;
	ifstream file((argv[1]));
	//file.open("input.txt"); 
	long n;
	file>>n;
	//cout<<n<<endl;

	file.close(); 

	//ofstream file_out;
	ofstream file_out((argv[2]));;
	//file_out.open("output.txt"); 

	bool isPrimeFlag = true;
	//bool truex=true; 
	
	long r=2;
	//cout<<" Enter_a_positive_integer_number_n_you_want_to_be_tested\n ";
	//cin >> n;

	if(n<1)
	{
		file_out<<" the_number_must_be_positive\n ";
	
	}
	else

		if (n==1)
		{
			file_out<<" 1_is_neither_prime_or_composite\n ";
			
		}
		else 

			if (n==2)
			{
				file_out<<" 2_is_prime\n ";
				
			}

			else 
			{
				int PP=PerfectPower(n); 
				//проверяет n на точную степень
				//возвращает 1, если n точная степень, 0 если нет 
				if(PP==1)
				{
					//cout<<"n is a perfect power, hence n is not prime ";
					//return(0);
					isPrimeFlag = false;
				}
				else 
					// find a suitable r;
				{

					while(r<n)
					{ 
						int r1=gcd(r,n);
						if (r1!=1)
						{
							isPrimeFlag = false;
							break;//cout<<"n has factors other than n and 1, hence is composite!	";
							//return(0);
						}
						
						r++;
						
					}
				}


				long prime=isprime(r);
				while(prime==0){
					{
						r=r+1;// увеличть r пока не станет простым
						prime=isprime(r);
					}


					long q=largestprime(r-1); // q должно быть наибольшим простым делителем r-1

					double t1=4*sqrt(r)*(log(n)/log(2));

					long t2=(int)pow(n,((r-1)/q))%r;

					if (q >= t1 && t2 != 1)

					{

						break; //q удовлетворяет всем условиям 
					}

					else
					{
						r=r+1;				
					}



				}
				if (r>n)
				{
					r=n;
				}

				//cout<<"r="<< r<<"\n";
				//int x=2;

				int a;
				long b=(2*sqrt(r)*(log(n)/log(2)));

				for (a=1;a<=b;a++)
				{ 	
					long f=congruence(a,n,r);

					if (f==1)
					{
						//cout<<"n is  prime";		
						//break;	
					}


					else 
					{
						//cout<<"n is not  prime ";
						isPrimeFlag = false;
						break;
					}
					
}




			}


			if (isPrimeFlag == true)
			{
				file_out << "n is prime";
			}
			else
				file_out << "n is composite";

			file_out.close();
			}
			




			




			