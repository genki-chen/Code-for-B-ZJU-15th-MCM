/*************************************************************************
  > File Name: 2_1.cpp
  > Author: genki_chen
  > Mail: genki_chen@aliyun.com 
  > Created Time: 2018年05月10日 星期四 14时34分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
double score(int rank_B,int rank_C,long long i);
int main()
{
	double sum;
	int flag = 0;
	int A_flag = 0;
	int flag_plus = 0;
	int coin = 0;
	int step=1;
	int j=1,k=1;
	int rank_B=1,rank_C=1,rank_I=1,rank_II=1,rank_III=1;
	int rank_A = 1;
	int rank_I_need=1,rank_II_need=1,rank_III_need=1;
	double I_sub,II_sub,III_sub;
	long long time;
	long long i,tmp_time=0;
	long int a[]={
		0,830,1630,4900,14700,51300,97100,194200,388000,776000
	};
	long long B_need[]={
		0,960,2880,5760,8640,17280,51840,86500,173000,519000
	};
	long long C_need[]={
		0,2300,6900,13800,27650,51840,89800,137100,274000,810000
	};
	long long A_need[]={
		0,660,1320,2600,5200,9200,16900,38000,76000,228000
	};
	int opi_I_rank[]={
		0,0,1,2,3,4,4,5,6,7,7
	};
	int opi_II_rank[]={
		0,0,2,2,3,4,5,6,6,7,8
	};
	int opi_III_rank[]={
		0,0,2,3,4,5,6,6,7,8,9
	};
	int I_keep[]={
		0,480,960,1920,3840,7680,15360,30720,61440,122880,245760
	};
	int II_keep[]={
		0,720,1440,2880,5760,11520,23040,46080,92160,184320,368640
	};
	int III_keep[]={
		0,1200,2400,4800,9600,19200,38400,76800,153600,307200,614400
	};

	cin >> time;
	for(i=1;;i++)
	{
		tmp_time++;

		if(I_sub <= I_keep[rank_A])
			I_sub += 60 * rank_I ;
		else
			I_sub += 60 * rank_I - (I_sub - I_keep[rank_A])*0.1*(0.5+(k-1)*0.05) ;
		if(II_sub <= II_keep[rank_A])
			II_sub += 60 * rank_II ;
		else
			II_sub += 60 * rank_II - (II_sub - II_keep[rank_A])*0.1*(0.5+(k-1)*0.05) ;
		if(III_sub <= III_keep[rank_A])
			III_sub += 60 * rank_III ;
		else
			III_sub += 60 * rank_III - (III_sub - III_keep[rank_A])*0.1*(0.5+(k-1)*0.05) ;

		if(B_need[j] <= C_need[k])
		{
			rank_II_need = opi_II_rank[j];
			rank_I_need = opi_I_rank[rank_II_need];
			flag = 0;
		}
		else
		{
			rank_III_need = opi_III_rank[k];
			rank_I_need = opi_I_rank[rank_III_need];
			flag = 1;
		}

		if((I_sub - I_keep[rank_A])*0.1*(0.5+(k-1)*0.05) >= (60*rank_I)*(rank_I*60)/(double (A_need[rank_A]) - I_sub) && flag_plus == 0)
		{
			A_flag = 1;
		}
		if((I_sub - I_keep[rank_A])*0.1*(0.5+(k-1)*0.05) >= (60*rank_I)*(rank_I*60)/(double (a[rank_I]) - I_sub) )
		{
			A_flag = 1;
		}
		if((I_sub - I_keep[rank_A])*0.1*(0.5+(k-1)*0.05) >= (60*rank_I)*(rank_I*60)/(double (a[rank_II]) - I_sub)  && flag == 0)
		{
			A_flag = 1;
		}
		if((I_sub - I_keep[rank_A])*0.1*(0.5+(k-1)*0.05) >= (60*rank_I)*(rank_I*60)/(double (a[rank_III]) - I_sub) && flag == 1)
		{
			A_flag = 1;
		}
		if((II_sub - II_keep[rank_A])*0.1*(0.5+(k-1)*0.05) >= (60*rank_II)*(rank_II*60)/(double (B_need[j]) - II_sub) && flag == 0)
		{
			A_flag = 1;
		}
		if((III_sub - III_keep[rank_A])*0.1*(0.5+(k-1)*0.05) >= (60*rank_I)*(rank_I*60)/(double (C_need[k]) - III_sub) && flag == 1)
		{
			A_flag = 1;
		}
		if(rank_I < rank_I_need)
		{
			if(I_sub >= a[rank_I])	
			{
				I_sub -= a[rank_I];
				cout << "第" << step++ << "步升级I到"<< ++rank_I << endl;
			}
		}
		else if(rank_II < rank_II_need && flag == 0)
		{
			if(I_sub >= a[rank_II])	
			{
				I_sub -= a[rank_II];
				cout << "第" << step++ << "步升级II到"<< ++rank_II << endl;
			}
		}
		else if(rank_III < rank_III_need && flag == 1)
		{
			if(I_sub >= a[rank_III])	
			{
				I_sub -= a[rank_III];
				cout << "第" << step++ << "步升级III到"<< ++rank_III << endl;
			}
		}
		if(A_flag == 1)
		{
			if(rank_A < 11)
				if(I_sub >= A_need[rank_A])	
				{
					I_sub -=  A_need[rank_A];
					A_flag = 0;
					cout << "第" << step++ << "步升级A到"<< ++rank_A << endl;
				}
		}

		if(rank_I >= rank_I_need && rank_II >= rank_II_need && rank_III >= rank_III_need)
		{
			flag_plus = 1;
		}
		else
		{
			flag_plus = 0;
		}
		if(flag_plus == 1)
		{
			switch(coin)
			{
				case 0:
					{
						if(rank_II<10)
							if(I_sub >= a[rank_II])	
							{
								I_sub -= a[rank_II];
								cout << "第" << step++ << "步升级II到"<< ++rank_II << endl;
								coin = 1;	
							}
						//cout << "反转了" << endl;
						break;
					}
				case 1:
					{
						if(rank_III<10)
							if(I_sub >= a[rank_III])	
							{
								I_sub -= a[rank_III];
								cout << "第" << step++ << "步升级III到"<< ++rank_III << endl;
								coin = 0;	
							}
						//cout << "反转了" << endl;
						break;
					}
				default:
					break;
			}
		}
		if(j < 10)
			if(II_sub >= B_need[j])
			{
				II_sub -= B_need[j];
				sum += score(j,k,tmp_time);
				cout << "第" << step++ << "步升级B到"<< ++j << endl;
				tmp_time = 0;
			}
		if(k < 10)
			if(III_sub >= C_need[k])
			{
				III_sub -= C_need[k];
				sum += score(j,k,tmp_time);
				cout << "第" << step++ << "步升级C到"<< ++k << endl;
				tmp_time = 0;
			}
		if(i>= time)
		{
			rank_B = j;
			rank_C = k;
			break;
		}

	}
	cout << rank_I << ';' << rank_II << ';'<< rank_III << endl;
	cout << rank_A << ';'<< rank_B << ';' << rank_C << endl;
	sum += score(j,k,tmp_time);
	cout << "结算分数为" << sum << endl;
}
double score(int rank_B,int rank_C,long long i)
{
	double sco;
	sco = (1+(rank_B-1)*0.1)*(0.5+(rank_C-1)*0.05)*i;
	return sco;
}
