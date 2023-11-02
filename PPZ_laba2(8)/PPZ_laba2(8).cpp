#include <iostream>
using namespace std;
void filling(int*& nums, int i, int n, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 10001;
			i++;
			filling(nums, i, n, mode);
		}
	}
	else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < 0 || nums[i]>10000);
			cout << " writed...\n";
			i++;
			filling(nums, i, n, mode);
		}
	}
}
void extract(int* nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
bool checking(int*& numb, int n)
{
	bool answ = 1;
	int max, maxI = 0, i;
	max = numb[0];
	for (i = 0; i < n; i++)
	{
		if(max<numb[i])
		{
			max = numb[i];
			maxI = i;
		}
	}
	for (int i = maxI; i < n-1; i++)
	{
		if (max > numb[i+1])
		{
			max = numb[i+1];
		}
		else return 0;
	}
	max = numb[maxI];
	for (int i = maxI; i > 1; i--)
	{
		if (max > numb[i-1])
		{
			max = numb[i-1];
		}
		else return 0;
	}
	return answ;
}
int main()
{
	int n, modeint;
	bool mode;
	do {
		cout << "Enter array size(1 - 10000): ";
		cin >> n;
	} while (n < 1 || n > 10000);
	int* nums = new int[n];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling(nums, 0, n, mode);
	extract(nums, 0, n);
	if (checking(nums, n))
	{
		cout << "\nTrue.";
	}
	else cout << "\nFalse.";
}