#include <iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#define Peoplenumber 30
using namespace std;
struct student{
    char num[4];
    char name[20];
    float score[8]={0};
    float sum;
    int judgment[8];
}stu[10],temp;
int main()
{
    int n,k,i,j,m;
    ifstream putin1("/Users/s20181102936/Desktop/student.txt");
    ifstream putin2("/Users/s20181102936/Desktop/caipan.txt");
    ofstream putout ("/Users/s20181102936/Desktop/score1.txt ");
    if(putin1.is_open())
    {
        if(putin2.is_open())
        {
            for(k=0;k<Peoplenumber;k++)
            {
                putin1>>stu[k].num>>stu[k].name;
                
                for (int i=0;i<7;i++)
                {
                    putin2>>stu[k].score[i];
                }
            }
            putin2.close();
        }
        putin1.close();
    }
    if(putout.is_open())
    {
        for(k=0;k<Peoplenumber;k++)
        {
            j=1;
            for (int i=0;i<7;i++)
            {
                stu[k].judgment[i]=j;
                j++;
            }
        }
        for(k=0;k<Peoplenumber;k++)
        {
            for (i=0;i<7;i++)
            {
                for(j=1;j<7;j++)
                {
                    if(stu[k].score[j-1]>stu[k].score[j])
                    {
                        m=stu[k].judgment[j-1];
                        stu[k].judgment[j-1]=stu[k].judgment[j];
                        stu[k].judgment[j]=m;
                        n=stu[k].score[j-1];
                        stu[k].score[j-1]=stu[k].score[j];
                        stu[k].score[j]=n;
                    }
                }
            }
        }
        for(k=0;k<Peoplenumber;k++)
        {
            stu[k].sum=0;
            for (int i=1;i<6;i++)
            {
                stu[k].sum+=stu[k].score[i];
            }
        }
        for( i=0;i<Peoplenumber;i++)
        {
            for(int j=1;j<Peoplenumber;j++)
            {
                if(stu[j-1].sum > stu[j].sum)
                {
                    temp=stu[j-1];
                    stu[j-1]=stu[j];
                    stu[j]=temp;
                }
            }
        }
        for(k=0;k<Peoplenumber;k++)
        {
            putout<<setiosflags(ios_base::left)<<"Rank:"<<setw(4)<<k+1<<"Id:"
            <<setw(7)<<stu[k].num<<"Name:"<<setw(7)<<stu[k].name;
            for(int i=1;i<6;i++)
            {
                putout<<"judgment"<<stu[k].judgment[i]<<":"<<setw(4)<<stu[k].score[i];
                
            }
            putout<<"Average:"<<setw(6)<<stu[k].sum/5<<endl;
        }
        putout.close();
    }
    return 0;
}

