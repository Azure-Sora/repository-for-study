// void main() {
// 	int i = 0;
// 	int j = 0;
// 	float a[10000];
// 	for (i = 0; i < 10000; i++)
// 		a[i] = 1.0;
// 	for (i = 0; j < 10000; j++) {
// 		for (j = 1; j <= 10000; i++) {
// 			a[i] = a[j];
// 		}
// 	}
// }

// float a[10000];
// void assign(int i) {
// 	int j;
// 	for (j = 0; j < 10000; j++)
// 		a[i] = a[j];
// }
// void main() {
// 	int i;
// 	for (i = 0; i < 10000; i++)
// 		a[i] = 1.0;
// 	for (i = 0; i < 10000; i++)
// 		assign(i);
// }

// void main() {
// 	int i;
// 	int j;
// 	int max_num = 100000000;
// 	for (i = 0; i < max_num; i++)
// 		j = i / 2;
// }

// void main() {
// 	unsigned int i;
// 	unsigned int j;
// 	unsigned int max_num = 100000000;
// 	for (i = 0; i < max_num; i++)
// 		j = i / 2;
// }

// Case 3
// void main() {
// 	int i = 0;
// 	int j = 0;
// 	int max_num = 100000000;
// 	while (i < max_num) {
// 		j = i / 2;
// 		i = i + 1;
// 	}
// }
// The time is : ______________
// Case 4
// void main() {
// 	int i = -1;
// 	int j = 0;
// 	int max_num = 100000000;
// 	while (++i < max_num) {
// 		j = i / 2;
// 		i = i + 1;
// 	}
// }
// The time is : ______________
// Case 5
// void prt(int i) {
// 	int j = i / 2;
// }
// void main() {
// 	int max_num = 10000000;
// 	for (int i = 0; i < max_num; i++)
// 		prt(i);
// }

// This is matrix multiplication

// #include <time.h>
// clock_t start, stop;
// #include <stdio.h>
// #include <stdlib.h>
// void main() {
// 	start = clock();
// 	float a[250][250], b[250][250], c[250][250];
// 	int i, j, k;
// 	for (i = 0; i < 250; i++)
// 		for (j = 0; j < 250; j++)
// 			for (k = 0; k < 250; k++)
// 				// matrix multiplication
// 				c[i][j] += a[i][k] * b[k][j];
// 	stop = clock();
// 	printf("%ld", stop - start);
// }