/*************************************************************************
  > File Name: 1.cpp
  > Author: genki_chen
  > Mail: genki_chen@aliyun.com 
  > Created Time: 2018年05月05日 星期六 15时36分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	long long b=0,c=1;
	long int a[]={
		0,830,1630,4900,14700,51300,97100,194200,388000,776000
	};
	long long B_need[]={
		0,0,960,3840,9600,18240,35520,87360,173860,346860,865860
	};
	long long C_need[]={
		0,0,2300,9200,23000,50650,102490,192290,329390,603390,1413390
	};
	long long A_need[]={
		0,0,660,1980,4580,9780,18980,35880,73880,149880,377880
	};
	long int I_time[10],I_sub[10];
	I_time[0]=0;
	I_sub[0]=0;
	long long  sum=0;
	long long i;
	//long int opi_time_I[11];
	int opi_rank_I[11];
	while(1)
	{
		sum = 0;
		for(i = 1;sum<a[c];i++)
		{
			sum = 60*c*i + b;	
		}
		b = sum-a[c];
		I_time[c]=--i+I_time[c-1];
		I_sub[c]=b;
		c++;
		if(c==10)
			break;
	}
	for(int c=0;c<10;c++)
		cout << I_time[c]<<';'<< I_sub[c] << endl;

	int flag_A=0;
	int rank_II,rank_B;
	int rank_C,rank_A;
	int rank_II_fin[11];
	int rank_III_fin[11];
	int rank_I_fin[11];
	long int B_time[11];
	long int C_time[11];
	long int A_time[11];
	long long I_sub_afterB[11];
	long long I_sub_afterC[11][11];	
	for(rank_II=9;rank_II<11;rank_II++)	
	{
		int sum_II[]={
			0,0,0,0,0,0,0,0,0,0,0
		};
		for( i = 0;i<=(rank_II-1);i++)
		{
			sum_II[rank_II]+=a[i];
		}
		//cout << sum_II[rank_II]<< endl;

		int tmp_II_time[10];
		for(c=0;c<10;c++)
		{
			b=I_sub[c];
			sum = 0;
			for(i = 1;sum<(sum_II[rank_II]);i++)

			{
				sum = 60*(c+1)*i + b;	
			}
			//cout << i << endl;
			tmp_II_time[c]=i+I_time[c]-1; //这里没有算I的余量
			//cout <<"itme"<<c<<';'<< tmp_II_time[c]<< endl;
		}
		int min_c=0,min_time=tmp_II_time[0];
		for(c = 1;c<10;c++)
		{
			if(min_time > tmp_II_time[c])
			{
				min_c = c;
				min_time = tmp_II_time[c];
			}
		}
		min_c++;
		//	cout << "当II的等级为" << rank_II << "时，最优的I等级和时间为" << min_c << ';' << min_time << endl;
		//	opi_time_I[rank_II] = min_time;
		opi_rank_I[rank_II] = min_c;
	}
	for(rank_B=2;rank_B<11;rank_B++)
	{

		int sum_II[]={
			0,0,0,0,0,0,0,0,0,0,0
		};
		int II_sub[]={
			0,0,0,0,0,0,0,0,0,0,0	
		};
		for(rank_II=2;rank_II<11;rank_II++)	
		{
			for( i = 0;i<=(rank_II-1);i++)
			{
				sum_II[rank_II]+=a[i];
			}
			//cout << sum_II[rank_II]<< endl;

			int tmp_II_time[10];
			for(c=0;c<10;c++)
			{
				b=I_sub[c];
				sum = 0;
				for(i = 1;sum<(sum_II[rank_II]);i++)

				{
					sum = 60*(c+1)*i + b;	
				}
				//cout << i << endl;
				tmp_II_time[c]=i+I_time[c]-1; //这里没有算I的余量
				//cout <<"itme"<<c<<';'<< tmp_II_time[c]<< endl;
			}
			int min_c=0,min_time=tmp_II_time[0];
			for(c = 1;c<10;c++)
			{
				if(min_time > tmp_II_time[c])
				{
					min_c = c;
					min_time = tmp_II_time[c];
				}
			}
			min_c++;
			//cout << "当II的等级为" << rank_II << "时，最优的I等级和时间为" << min_c << ';' << min_time << endl;
			//	opi_time_I[rank_II] = min_time;
			opi_rank_I[rank_II] = min_c;
			//这里在计算II的产量
			b = I_sub[min_c-1];
			i = 0;
			II_sub[rank_II] = I_time[min_c-1] * 60;
			int flag_B = 0;
			rank_II_fin[rank_B] = 1;
			B_time[rank_B]=I_time[min_c-1];
			for(int j=1;j<=rank_II;j++)
			{
				//	B_time[rank_B] += i;
				if(II_sub[rank_II] >= B_need[rank_B])
				{
					flag_B = 1;
					//cout << "结束II升级" << b << endl;
					break;
				}
				sum = 0;
				if(j < 10)
				{

					for(i = 1;sum<a[(j)];i++)
					{
						sum = 60*(min_c)*i + b;	
						II_sub[rank_II] += 60*(j);
						B_time[rank_B] ++;
						if(II_sub[rank_II] >= B_need[rank_B])
						{
							flag_B = 1;
							rank_II_fin[rank_B] = j;
							//	b = sum-a[j];
							I_sub_afterB[rank_B] = sum;
							//cout << "这里" << b << endl;
							break;
						}
					}
					b = sum-a[j];
				}
				else
				{
					for(i = 1;;i++)
					{
						sum = 60*(min_c)*i + b;	
						II_sub[rank_II] += 60*(j);
						B_time[rank_B] ++;
						if(II_sub[rank_II] >= B_need[rank_B])
						{
							flag_B = 1;
							rank_II_fin[rank_B] = j;
							I_sub_afterB[rank_B] = sum;
							//cout << "ha3" << b << endl;
							break;
						}
					}

				}
				i--;
				//II_sub[rank_II] += 60*(j)*i; //这里把II的产量放在循环内更符合逻辑
				//I_sub[c]=b;
			}
			//cout << II_sub[rank_II] << endl;
			if(flag_B == 1)
			{
				cout << "当B为" << rank_B << "总时间为" << B_time[rank_B] << "其中，II的等级为" << rank_II_fin[rank_B];
				cout << "，此时I等级为" << min_c << endl;
				rank_I_fin[rank_B] = min_c;
				//I_sub_afterB[rank_B] = b;
				//	cout << "rank_B" << I_sub_afterB[rank_B] << endl;
				break;
			}
			//cout << II_sub[rank_II] << endl;
			//rank_II循环的结束
		}
		//rank_B循环的结束	
	}
	cout << "===================================================================" << endl;
	for(rank_B=2;rank_B<11;rank_B++)
	{
		cout  << I_sub_afterB[rank_B] << endl;
	}
	for(rank_C=2;rank_C<11;rank_C++)
	{

		int flag_C = 0;
		int tmp_B;
		int rank_error = 0;
		for(rank_B = 2;rank_B < 11;rank_B++)
		{
			b = I_sub_afterB[rank_B];
			//cout << rank_B << "初始化" << b << endl;
			i = 0;
			flag_C = 0;
			long long  III_sub=0;
			III_sub = B_time[rank_B] * 60;
			rank_III_fin[rank_C] = 1;
			C_time[rank_C] = B_time[rank_B];

			//				cout << C_time[rank_C] << endl;          //

			for(int j=1;j<=10;j++)
			{
				if(III_sub >= C_need[rank_C] && flag_C == 0)
				{
					flag_C = 1;
					tmp_B = rank_B;
					I_sub_afterC[rank_C][rank_B] = b;
					//cout << j<<"够了" << b << endl;
					break;
				}
				if(j > rank_II_fin[rank_B])
				{
					rank_error = 1;
					break;
				}
				sum = 0;
				if(j < 10)
				{

					for(i = 1;sum<a[(j)];i++)
					{
						sum = 60*(rank_I_fin[rank_B])*i + b;	
						III_sub += 60*(j);
						C_time[rank_C] ++;
						if(III_sub >= C_need[rank_C])
						{
							flag_C = 1;
							rank_III_fin[rank_C] = j;
							if(rank_III_fin[rank_C] > rank_II_fin[rank_B] )
							{
								rank_error = 1;                            //这里III的等级高于II了，所以一开始的时间要改
							}
							I_sub_afterC[rank_C][rank_B] = sum;
							//cout << "达到了" << sum << endl;
							tmp_B = rank_B;
							break;
						}
					}
					b = sum-a[j];
				}
				else
				{
					for(i = 1;;i++)
					{
						sum = 60*(rank_I_fin[rank_B])*i + b;	
						III_sub += 60*(j);
						C_time[rank_C] ++;
						if(III_sub >= C_need[rank_C])
						{
							flag_C = 1;
							rank_III_fin[rank_C] = j;
							if(rank_III_fin[rank_C] > rank_II_fin[rank_B] )
							{
								rank_error = 1;                            //这里III的等级高于II了，所以一开始的时间要改
							}
							tmp_B = rank_B;
							I_sub_afterC[rank_C][rank_B] = sum;
							break;
						}
					}

				}
				i--;
				if(flag_C == 1)
					break;
			}
			if(rank_error == 1)
			{
				rank_error = 0;
				for(int rank_III = rank_II_fin[rank_B]+1 ;rank_III < 11;rank_III++)
				{
					flag_C = 0;
					long long  III_sub=0;
					rank_III_fin[rank_C] = 1;
					C_time[rank_C] = B_time[rank_B] + (I_time[(opi_rank_I[rank_III])+1] - I_time[(opi_rank_I[rank_II_fin[rank_B]]) + 1]);
					III_sub = C_time[rank_C] * 60;
					b = I_sub_afterB[rank_B]+I_sub[(opi_rank_I[rank_III])+1];
					//cout << "贼牛逼的" << b << endl;
					for(int j=1;j<=rank_III;j++)
					{
						if(III_sub >= C_need[rank_C])
						{
							flag_C = 1;
							tmp_B = rank_B;
							rank_I_fin[tmp_B] = opi_rank_I[rank_III];
							break;
						}
						sum = 0;
						if(j<10)
						{

							for(i = 1;sum<a[(j)];i++)
							{
								sum = 60*(opi_rank_I[rank_III])*i + b;	
								III_sub += 60*(j);
								C_time[rank_C] ++;
								if(III_sub >= C_need[rank_C])
								{
									flag_C = 1;
									rank_III_fin[rank_C] = j;
									tmp_B = rank_B;
									I_sub_afterC[rank_C][rank_B] = sum;
									rank_I_fin[tmp_B] = opi_rank_I[rank_III];
									break;
								}
							}
							b = sum-a[j];
						}
						else
						{
							for(i = 1;;i++)
							{
								III_sub += 60*(j);
								C_time[rank_C] ++;
								if(III_sub >= C_need[rank_C])
								{
									flag_C = 1;
									rank_III_fin[rank_C] = j;
									tmp_B = rank_B;
									I_sub_afterC[rank_C][rank_B] = sum;
									rank_I_fin[tmp_B] = opi_rank_I[rank_III];
									break;
								}
							}

						}
					}
					if(flag_C == 1)
						break;
				}
			}
			if(flag_C == 1)
			{
				//cout <<"当C为" << rank_C << "当B为" << tmp_B << "总时间为" << C_time[rank_C] << "其中，III的等级为" << rank_III_fin[rank_C] << ",II等级为"<<rank_II_fin[tmp_B];
				//cout << "，此时I等级为" << rank_I_fin[tmp_B]<< endl;
				//I_sub_afterB[rank_C] = b;

				//break;
			}
			for(rank_A = 2;rank_A < 11;rank_A++)
			{
				b = I_sub_afterC[rank_C][rank_B];
				A_time[rank_A] = C_time[rank_C];
				if(b >= A_need[rank_A])	
				{
					flag_A = 1;
					rank_I_fin[rank_A] = rank_I_fin[tmp_B];
				}
				else
				{
					/*
					for(int j=rank_I_fin[tmp_B];j<=rank_A;j++)
					{
						for(i = 1;sum<a[j];i++)
						{
							sum = 60*(j)*i + b;	
							A_time[rank_A]++;
						}
						b = sum - a[j];
					}
					for(i=1;;i++)
					{
						sum = 60*(rank_A)*i + b;	
						A_time[rank_A]++;
						if(sum >= A_need[rank_A])
						{
							flag_A = 1;
							rank_I_fin[rank_A] = rank_A;
							break;
						}
					}
					*/
					int j = rank_I_fin[tmp_B];
					for(i=1;;i++)
					{
						sum = 60*(j)*i + b;	
						if(a[j] < A_need[rank_A])
						{
						if(sum >= a[j])
						{
							b = sum -a[j];
							//cout << b << endl;
							j++;
						}

						}
						A_time[rank_A]++;
						if(sum >= A_need[rank_A])
						{
							flag_A = 1;
							rank_I_fin[rank_A] = j;
							break;
						}
						
					}

				}
				if(flag_A == 1)
			{
				//cout <<"当C为" << rank_C << "当B为" << tmp_B << "当A为" << rank_A<< "总时间为" << A_time[rank_A] << "其中，III的等级为" << rank_III_fin[rank_C] << ",II等级为"<<rank_II_fin[tmp_B];
				//cout << "，此时I等级为" << rank_I_fin[rank_A]<< endl;
				cout << rank_A << ';' << rank_B << ';' << rank_C << ';' << rank_I_fin[rank_A] << ';'<< rank_II_fin[tmp_B] << ';'<< rank_III_fin[rank_C] << ';'<<A_time[rank_A] <<  endl;
			}
					
			}
		}
		//cout << "------------------------------"<< rank_C << "----------------------------------------" << endl;
	}
}
