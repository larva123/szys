#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a, b, c, d = 0;
	int m = 1, n, p, q;
	printf("请输入出题个数:");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	while (m <= n)
	{
		a = rand() % 100;
		b = rand() % 100;
		p = rand() % 4;
		q = rand() % 4 + 1;
		switch (abs(p / q - 3))  //调整各种运算出现的概率
		{
		case 0:
			if (a + b <= 100)  //和不能超过100
			{
				printf("%d＋%d=", a, b);
				scanf("%d", &c);
				if (a + b == c)
				{
					printf("计算正确。\n");
					d = d + 1;   //记录做对的题并打分
				}
				else
					printf("计算错误，答案为：%d。\n", a + b);
			}
			else
			{
				m = m - 1;  //两个随机数不满足条件时不计入循环（与switch外m=m+1抵消）
			}
			break;
		case 1:
			if (a - b >= 0)  //差不为负
			{
				printf("%d－%d=", a, b);
				scanf("%d", &c);
				if (a - b == c)
				{
					printf("计算正确。\n");
					d = d + 1;
				}
				else
					printf("计算错误，答案为：%d。\n", a - b);
			}
			else
			{
				m = m - 1;
			}
			break;
		case 2:
			if (a * b <= 100)   //积不能超过100
			{
				printf("%d×%d=", a, b);
				scanf("%d", &c);
				if (a * b == c)
				{
					printf("计算正确。\n");
					d = d + 1;
				}
				else
					printf("计算错误，答案为：%d。\n", a * b);
			}
			else
			{
				m = m - 1;
			}
			break;
		case 3:
			if (b != 0 && (double)a / b - a / b == 0)  //商不为小数或分数
			{
				printf("%d÷%d=", a, b);
				scanf("%d", &c);
				if (a / b == c)
				{
					printf("计算正确。\n");
					d = d + 1;
				}
				else
					printf("计算错误，答案为：%d。\n", a / b);
			}
			else
			{
				m = m - 1;
			}
			break;
		}
		m = m + 1;  //循环计数
	}
	printf("\n");
	printf("运算结束，你做对了%d题，做错了%d题，得分为：%d分。\n", d, n-d, d);  //统计运算结果
}
