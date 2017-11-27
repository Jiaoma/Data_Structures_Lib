
#include <cstdio>
bool shellsort1(int a[], int n)  
{  
    int i, j, gap;  
  
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = 0; i < gap; i++)
        {  
            for (j = i + gap; j < n; j += gap)   
                if (a[j] < a[j - gap])  
                {  
                    int temp = a[j];  
                    int k = j - gap;  
                    while (k >= 0 && a[k] > temp)  
                    {  
                        a[k + gap] = a[k];  
                        k -= gap;  
                    }  
                    a[k + gap] = temp;  
                }  
        }  
    return true;
}  
int main(int argc, const char * argv[]) {
    int num;
    int input[100005];
    while (scanf("%d",&num)!=EOF) {
        input[0]=0;
        for (int i=1; i<=num; i++) {
            scanf("%d",&(input[i])); 
        }
        if (shellsort1(input, num)) {
            for (int j=1; j<=num; j++) {
                printf("%d ",input[j]);
            }
            printf("\n");
        }
        else
            printf("\n");
    }
    return 0;
}