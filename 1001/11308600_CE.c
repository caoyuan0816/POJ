/*题目：计算高精度幂。R 的 n 次方，0.0 < R > 99.99, 0 < n > 25。
  思路：利用数组模拟人手工计算乘法，一开始将小数点去掉，
  最后用一个函数来处理数据,处理0的问题和把小数点加上。*/

#include <stdio.h>
#include <string.h>

#define LINELEN 81

int  string_to_arr(int _len,char *s,int arr[]);//将输入数据转换为int型数组，并返回小数点在第几位，用-1标志结束
void calculate(int mult1[] , int mult2[], int res[],int use1[],int use2[]);//高精度计算两个数组相乘,得到的结果是倒序以-1为标志的
void copy_arr(int len1,int arr1[],int arr2[]);//用于将数组1的内容复制到数组2
int len_int_arr(int arr[]);//求出一个用-1标识结束的int数组的长度
void plus_two_arrs(int add1[],int add2[], int res[],int use2[]);//将两个int数组add1和add2相加，用-标识结束
void print_arr(int arr[],int n);//将一个倒序，用-1标识结束的int数组，输出为答案

int main(void)
{
    char s[LINELEN];
    int arr[LINELEN] = {};                      //转换后R的存储位置

    int mult1[LINELEN] = {};
    int mult2[LINELEN] = {};                    //定义两个数组相乘需要的空间
    int res[LINELEN] = {};                      //定义两个数组相乘的结果
    int use1[LINELEN] = {};
    int use2[LINELEN] = {};                     //过程变量
    int ans[LINELEN] = {};                      //答案存储

    int n;                      //n的存储位置
    int _len;                   //R的长度
    int _point;                 //小数点从正序的从后往前数的位置
    int i;                      //用于计算R的n次幂时的计数器
    int j;                      //用于计算小数点在哪时用的计数器

    while(scanf("%s%d",s,&n) != EOF)
    {
        _len = strlen(s);

        _point = string_to_arr(_len,s,arr);    //得到R的数组形式,以-1标记结束，并且用得到小数点的位置信息

        copy_arr(_len+1,arr,mult2);    //将R复制到数组mult2中

        for(i = 0;i<n;i++)       //计算R的n次幂
        {
            copy_arr(len_int_arr(res)+1,res,mult1);
            calculate(mult1,mult2,res,use1,use2);
        }

        for(j = 0;j<n;j++)       //计算小数点在哪
        {
            _point *= _point;
        }

        print_arr(res,_point);    //输出答案

    }

    return 0;
}

int  string_to_arr(int _len,char *s,int arr[])
{
    int i ,j,num_point;
    char ch;

    for(i = 0,j = 0;i < _len;i++,j++)
    {
        switch(s[i])
        {
            case '0':
                arr[j] = 0;
                break;
            case '1':
                arr[j] = 1;
                break;
            case '2':
                arr[j] = 2;
                break;
            case '3':
                arr[j] = 3;
                break;
            case '4':
                arr[j] = 4;
                break;
            case '5':
                arr[j] = 5;
                break;
            case '6':
                arr[j] = 6;
                break;
            case '7':
                arr[j] = 7;
                break;
            case '8':
                arr[j] = 8;
                break;
            case '9':
                arr[j] = 9;
                break;
            case '.':
                j = j-1;
                num_point = i;
                break;
            default:
                break;

        }
    }
    arr[i] = -1;
    return len_int_arr(arr) - num_point;

}

void copy_arr(int len1,int arr1[],int arr2[])
{
    int i;

    for(i = 0;i < len1;i++)
    {
        arr2[i] = arr1[i];
    }
    return;
}

int len_int_arr(int arr[])
{
    int i;

    for(i = 1;arr[i] != -1;i++)
        continue;

    return i;
}

void calculate(int mult1[] , int mult2[], int res[],int use1[],int use2[])
{
    int _len1 , _len2;
    int i,j,k,l;
    int a,b,c;  //a用来存储每次乘法下面的单位数，b用来存储每两个单位整数相乘的结果,c进位的数字大小

    _len1 = len_int_arr(mult1);
    _len2 = len_int_arr(mult2);

    for(i = _len2 -1;i >= 0;i--)
    {
        a = mult2[i];              //每次乘法下面的单位的数

        for(j = _len1 -1,k = 0,c = 0;j>= 0;j--,k++)
        {
            b = mult1[j]*a;

            if(b>=10)
            {
                res[k] = b%10+c;
                c = b/10;
            }
            else
            {
                res[k] = b;
                c = 0;
            }
        }

        for(l = _len2-i;l > 1;l--,k++)
        {
            res[k] = 0;
        }

        res[k] = -1;

        plus_two_arrs(res,use1,use1,use2);
    }
    return;
}

void plus_two_arrs(int add1[],int add2[], int res[],int use2[])
{
    int i,j;
    int a,b;

    for (i = 0,b =0;i <= len_int_arr(add1);i++)
    {

        if(i == len_int_arr(add1) && b == 1)
        {
            use2[i] = 1;
        }
        else
        {
            a = add1[i] + add2[i];

            if(a >= 10)
            {
                use2[i] = a -10 + b;
                b = 1;
            }
            else
            {
                use2[i] = a+b;
                b = 0;
            }
        }
    }
    use2[i] = -1;
    copy_arr(len_int_arr(use2)+1,use2,res);
    return;
}

void print_arr(int arr[],int n)
{
    int i,j;

    for(i = len_int_arr(arr)-1,j = 0;i >= 0;i--,j++)
    {
        if(j == n-1)
        {
            putchar('.');
        }
        else
            printf("%d",arr[i]);
    }
    putchar('\n');

    return;
}









