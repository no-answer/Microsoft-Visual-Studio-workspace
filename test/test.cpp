// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, sum;
int yanghui[20][20];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	yanghui[1][1] = 1;
	for (int i = 2; i <= 15; i++)
	{
		for (int j = 2; j <= i - 1; j++)
			yanghui[i][j] = yanghui[i - 1][j - 1] + yanghui[i - 1][j];
		yanghui[i][1] = yanghui[i - 1][1];
		yanghui[i][i] = yanghui[i - 1][i - 1];
	}
	cin >> n >> sum;
	int* N = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		N[i] = i;
	do
	{
		int mark = 0, s = 0;
		for (int i = 1; i <= n; i++)
		{
			s += yanghui[n][i] * N[i];
			if (s > sum)
			{
				sort(N + i, N + n + 1, cmp);
				mark = 1;
				break;
			}
		}
		if (mark == 1)
			continue;
		if (s == sum)
		{
			for (int i = 1; i <= n; i++)
				cout << N[i] << " ";
			cout << endl;
			break;
		}
	} while (next_permutation(N + 1, N + 1 + n));
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
