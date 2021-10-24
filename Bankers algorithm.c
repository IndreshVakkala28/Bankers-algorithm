#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int max[3][3],all[3][3];
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    scanf("%d",&max[i][j]);
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    scanf("%d",&all[i][j]);
    int ave[3];
    for(int i=0;i<3;i++)
    scanf("%d",&ave[i]);
    int v[3]={-1,-1,-1};
    int f=1;
    int p=0;
    while(f)
    {
        f=0;
        for(int i=0;i<3;i++)
        {
            if(v[i]==-1)
            {
                f=1;
                int s=0;
                for(int j=0;j<3;j++){
                    if(max[i][j]<=all[i][j]+ave[j])
                    s+=1;
                }
                if(s==3)
                {
                    v[i]=p;
                    p+=1;
                    printf("Max matrix:\tAllocation matrix:\n");
                    if(p<=n)
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            printf("%d  ",max[j][k]);
                        }
                        printf("\t\t");
                        for(int k=0;k<3;k++)
                        {
                            printf("%d  ",all[j][k]);
                        }
                        printf("\n");
                    }
                    printf("\nProcess %d runs to completion!\n",p);
                    if(p>0 && p<n)
                    printf(" ");
                    for(int j=0;j<3;j++)
                    {
                        max[i][j]=0;
                        ave[i]=all[i][j] + ave[i];
                        all[i][j]=0;
                    }
                }
            }
        }
    }
    printf("The system is in safe state!!\n");
    printf("Safe Sequence : < %d  %d  %d >",v[0],v[1],v[2]);
}
