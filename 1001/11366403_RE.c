/*ÌâÄ¿£º¼ÆËã¸ß¾«¶ÈÃÝ¡£R µÄ n ´Î·½£¬0.0 < R > 99.99, 0 < n > 25¡£
  Ë¼Â·£ºÀûÓÃÊý×éÄ£ÄâÈËÊÖ¹¤¼ÆËã³Ë·¨£¬Ò»¿ªÊ¼½«Ð¡ÊýµãÈ¥µô£¬
  ×îºóÓÃÒ»¸öº¯ÊýÀ´´¦ÀíÊý¾Ý,´¦Àí0µÄÎÊÌâºÍ°ÑÐ¡Êýµã¼ÓÉÏ¡£*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

static char sum[1000];
static char arr1[1000],arr2[1000];
static char res[1000];
static char res2[1000];
static char use[1000];
static char gogogo[1000];

int get_point(char *arr);
void string_to_arr(char *arr , int n);
int _strlen(char *arr);
void add(char *arr1, char *arr2,char *sum);
void mult_1(char *arr1, char n,char *res);
void mult_2(char *arr1, char *arr2, char *res2);
void add_0(char *arr1,int a, int b);
void back_point(char *arr,int point,int n);
void check_0(char *arr , int point,int n, int L);

int main(void)
{

    int i,j,p,point,o,L;
    char n;

    while(scanf("%s%d",arr1,&n) == 2)
    {
        if (n == 0)
            {
                printf("1");
                continue;
            }

        o = get_point(arr1);

        point = (o == 0)?0:strlen(arr1)-o;

        string_to_arr(arr1,strlen(arr1));

        for(i = 0;i < _strlen(arr1)+1;i++)
                arr2[i] = arr1[i];

        for( p= 0;p<n-1;p++)
        {
            mult_2(arr1,arr2,res2);

            for(i = 0;i < _strlen(res2)+1;i++)
                arr1[i] = res2[i];
        }

        L = _strlen(arr1);

        for(i = 0;i<200;i++)
                res2[i] = 0;

        back_point(arr1,point,n);

        check_0(res2,point,n,L);

        printf("%s",res2);

        putchar('\n');
    }

return 0;
}

int get_point(char *arr)
{
    int i = 0,p = 0;

    while(arr[i++] != 0)
    {
        if(arr[i] != '.')
            continue;
        else
        {
            p = i;
            break;
        }
    }

    for(i = i;arr[i+1] != 0;i++)
    {
        arr[i] = arr[i+1];
        arr[i+1] = 0;
    }

    return p;
}

int _strlen(char *arr)
{
    int i;

    for(i = 0;arr[i]!= -1;i++)
        continue;

    return i;
}

void string_to_arr(char *arr, int n)
{
    int i;

    for(i = 0;i < n;i++)
        arr[i] = arr[i]-48;

    arr[n] = -1;

    if(arr[0] == 0)
        {
            for(i = 0; i< _strlen(arr)+2;i++)
                arr[i] = arr[i+1];
        }
    return;
}

void add(char *arr1, char *arr2,char *sum)
{
    int L1 , L2;
    int i;
    int a,b=0;

    L1 = _strlen(arr1);
    L2 = _strlen(arr2);

    for(i = 0;i < 81;i++)
        sum[i] = 0;

    sum[L1 + 1] = -1;

    for(i = L1;i >= 0;i--)
    {
        a = arr1[i-1] + arr2[i-1]+b;

        if(a < 10)
        {
            sum[i] += a;
            b=0;
        }
        else
        {
            sum[i] += (a-10);

            b=1;
        }
    }
    if(sum[0] == 0)
        {
            for(i = 0; i< _strlen(sum)+2;i++)
                sum[i] = sum[i+1];
        }


    return;
}

void mult_1(char *arr1, char n,char *res)
{
    int L;
    int a,b = 0,i;

    L = _strlen(arr1);

    for(i = 0;i < 81;i++)
        res[i] = 0;

    res[L+1] = -1;

    for(i = L -1;i >= 0;i--)
    {
        a = arr1[i] * n+b;

        if(a < 10)
        {
            res[i+1] += a;
            b = 0;
        }
        else
        {
            res[i+1] += (a%10);
            b = a/10;
        }
    }
    if(b != 0)
        res[0] = b;

    if(res[0] == 0)
        {
            for(i = 0; i< _strlen(res)+2;i++)
                res[i] = res[i+1];
        }

    return;
}

void mult_2(char *arr1, char *arr2, char *res2)
{
    int k = _strlen(arr1)+_strlen(arr2);
    int i = _strlen(arr2)-1,j,l,p;

    mult_1(arr1,arr2[i],res2);

    add_0(res2,k,0);

    i--;

    for(i = _strlen(arr2)-2,l = 1;i>=0;i--,l++)
    {
        mult_1(arr1,arr2[i],use);

        add_0(use,k,l);

        add(res2,use,gogogo);

        for(j = 0;j< _strlen(gogogo)+1;j++)
            res2[j] = gogogo[j];

        for(p = 0;p < 81;p++)
        gogogo[p] = 0;

    }
if(res2[0] == 0)
    {
        for(i = 0; i<_strlen(res2)+2;i++)
            res2[i] = res2[i+1];
    }

return;
}

void add_0(char *arr1,int a,int b)
{
    int m;//Ç°ÃæÒª¼ÓµÄ0Êý
    int i,j,L,k;

    L =_strlen(arr1);
    m = a -L -b;

    for(j = 0,k=L;j < m;j++,k++)   //
    {
        for(i = k;i>=0;i--)
            arr1[i+1] = arr1[i];
        arr1[0] = 0;
    }

    for(i = 0;i<b;i++,k++)  //ºóÃæ¼Ó0
    {
        arr1[k] = -0;
        arr1[k+1] = -1;
    }

return;
}

void back_point(char *arr,int point,int n)
{
    int i,j,L,k;

    L = _strlen(arr);

    point = point * n;

    if(point == 0)
        for(i= 0;i < L ;i++)
            res2[i] = arr[i]+48;
    else if(point > L)
    {
        for(j = 0,k=L;j < point - L;j++,k++)   //Ç°Ãæ¼Ó0
        {
            for(i = k;i>=0;i--)
                arr[i+1] = arr[i];
            arr[0] = 0;
        }

        res2[0] = '.';

        for(i= 1;i<_strlen(arr)+1;i++)
            res2[i] = arr[i-1]+48;
    }
    else
    {
        for(i = 0;i < L-point;i++)
            res2[i] = arr[i]+48;

        res2[i] = '.';

        for(i= i+1;i<L+1;i++)
            res2[i] = arr[i-1]+48;
    }
return;
}

void check_0(char *arr , int point,int n, int L)
{
    int i,j;

    point = point *n;

    if(point == 0)
        return;
    else
        for(i = L ;arr[i] == '0';i--)
                arr[i] = 0;
return;
}

