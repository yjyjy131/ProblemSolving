#include <stdio.h>
#include <string.h>
#define MAX_NUM 100000

 main() {
	int i, n, x;
	int c, count;
	int num = 0; // 현재의 배열넘버
	int arr[MAX_NUM] = { 0, };
	char command[BUFSIZ];

	scanf("%d", &n);

	count = 1;


	for (i = 1; i <= n; i++) {
		scanf("%s", &command);

		if (strcmp(command, "push") == 0) {
			scanf("%d", &x);
			arr[count - 1] = x;
			count += 1;

		}
		else if (strcmp(command, "pop") == 0) {
			if (count >= 2) {
				printf("%d\n", arr[count - 2]);
				arr[count - 2] = 0;
				count += -1; 
			
			}
			else {
				printf("-1\n");
			}
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", count-1);
		}
		else if (strcmp(command, "empty") == 0) {
			if (count == 1) {
				printf("1\n");
			}
			else { printf("0\n"); 
			}
		}
		else if (strcmp(command, "top") == 0) {
			if (count >= 2) {
				printf("%d\n", arr[count - 2]);
			}
			else { printf("-1\n");
			}
		}
	}

}