#include <stdio.h>

int main(void) {
	int i, j;
	int num;

	printf("input : ");
	scanf("%d", &num);

	for (i = 0; i < num; ++i) {
		for (j = 0; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}