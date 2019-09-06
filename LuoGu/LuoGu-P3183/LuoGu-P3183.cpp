// LuoGu-P3183.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int dfs(int a, int n, int *dp, vector<int>*matrix)
{
	if (matrix[a].size() == 0)
		return 1;
	if (dp[a] > 0)
		return dp[a];
	int temp = 0;
	for (int i = 0; i < matrix[a].size(); i++)
	{
		temp += dfs(matrix[a][i], n, dp, matrix);
	}
	dp[a] = temp;
	return temp;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>* matrix = new vector<int> [n+1];
	int* dp = new int [n + 1];
	bool* N = new bool[n + 1];
	for (int i = 0; i <= n; i++)
	{
		dp[i] = -1;
		N[i] = true;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		N[b] = false;
		matrix[a].push_back(b);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++)
		if (N[i] && matrix[i].size() != 0)
			answer += dfs(i, n, dp, matrix);
	cout << answer << endl;
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
