#include<cstdio>
#include<algorithm>

int main(int argc, char * argv[])
{
	puts("b explode_bomb");
	puts("b *0x8048f46");
	for(int index = 1; index <= 1001; ++index) printf("r input_files_for_secret_phase/input%d\n", index);
	puts("q");
	puts("");
	return 0;
}

