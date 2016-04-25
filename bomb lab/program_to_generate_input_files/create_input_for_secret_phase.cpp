#include<cstdio>
#include<algorithm>

int main(int argc, char * argv[])
{
	char filename[20];
	for(int index = 1; index <= 1001; ++index)
	{
		sprintf(filename, "input%d", index);
		freopen(filename, "w", stdout);
		puts("Public speaking is very easy.");
		puts("1 2 6 24 120 720");
		puts("0 q 777");
		puts("9 austinpowers");
		puts("opukmq");
		puts("4 2 6 3 1 5");
		printf("%d\n\n", index);
	}
	return 0;
}

