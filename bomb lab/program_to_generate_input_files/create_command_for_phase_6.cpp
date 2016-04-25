#include<cstdio>
#include<algorithm>

int main(int argc, char * argv[])
{
	puts("b explode_bomb");
	puts("b *0x8048e8f");
	for(int index = 1; index <= 720; ++index) printf("r input_files_for_phase_6/input%d\n", index);
	puts("q");
	puts("");
	return 0;
}

