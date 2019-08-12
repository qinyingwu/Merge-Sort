// �鲢����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include <algorithm>
#include "time.h"
using namespace std;

template <class Type>
void MergeSort(Type a[],int n)
{
	Type *b=new Type[n];
	int s=1;
	while(s<n)
	{
		MergePass(a,b,s,n);
		s+=s;
		MergePass(b,a,s,n);
		s+=s;
	}
}
template <class Type>
void MergePass(Type x[],Type y[],int s,int n)
{
	int i=0;
	while(i<=n-2*s)
	{
		Merge(x,y,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}
	if(i+s<n)
		Merge(x,y,i,i+s-1,n-1);
	else
		for(int j=i;j<=n-1;j++)
			y[j]=x[j];
}
template <class Type>
void Merge(Type c[],Type d[],int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	while((i<=m)&&(j<=r))
		if(c[i]<=c[j])d[k++]=c[i++];
		else d[k++]=c[j++];
		if(i>m)
			for(int q=j;q<=r;q++)d[k++]=c[q];
		else for(int q=i;q<=m;q++)d[k++]=c[q];
}
int _tmain(int argc, _TCHAR* argv[])
{
	long c;
	clock_t start,finish;
	cout<<"������������ɵ��������ݵĸ�����";
	cin>>c;
	int *a=new int[c];
	for(int i=0;i<c;i++)
		a[i]=rand();
	start=clock();
	MergeSort(a,c);
	finish=clock();
	double d=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"MergeSort�������õ�ʱ��Ϊ��"<<d<<"��"<<endl;
	start=clock();
	std::sort(a,a+c);
	finish=clock();
	double f=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"STL���е�Sort���򷽷��������õ�ʱ��Ϊ��"<<f<<"��"<<endl;
	int z;
	cin>>z;
	return 0;
}

