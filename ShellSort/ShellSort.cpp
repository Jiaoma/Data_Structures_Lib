#include<cstdio>
void ShellSort(int a[],int num)
{
	int j,step;
	for	(step=num/2;step>0;step/=2)
			for(j=step;j<num;j+=step)
			{
				if(a[j]<a[j-step])
				{
					int temp=a[j];
					int k=j-step;
					while(k>=0 && a[k]>temp)
					{
						a[k+step]=a[k];
						k-=step;
					}
					a[k+step]=temp;
				}
			}
}
int main(int argc, const char * argv[]) {
    int num;
    int input[100005];
    while (scanf("%d",&num)!=EOF) {
        for (int i=0; i<num; i++) {
            scanf("%d",&(input[i]));
        }
    	ShellSort(input,num);
        for (int j=0; j<num; j++) {
            printf("%d ",input[j]);
        }
        printf("\n");
    }
    return 0;
}
