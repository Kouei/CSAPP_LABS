#include<cstdio>
#include<algorithm>

int main(int argc, char * argv[])
{
	int nums[] = {1, 2, 3, 4, 5, 6};
	int index = 1;
	char filename[20];
	do
	{
		sprintf(filename, "input%d", index++);
		freopen(filename, "w", stdout);
		puts("Public speaking is very easy.");
		puts("1 2 6 24 120 720");
		puts("0 q 777");
		puts("9 austinpowers");
		puts("opukmq");
		printf("%d %d %d %d %d %d\n\n", nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]);
	}while(std::next_permutation(nums, nums + sizeof(nums) / sizeof(nums[0])));
	return 0;
}

