#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "cache.h"


/* Here is an our naive implementation */
char rotate_descr[] = "Naive Row-wise Traversal of src";
void rotate(int dim, pixel* src, pixel* dst) {
	int i, j;

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			COPY(&dst[PIXEL(dim - 1 - j, i, dim)], &src[PIXEL(i, j, dim)]);
		}
	}

	return;
}

char func1[] = "rotate_per_Npx";
void rotate_per_Npx(int dim, pixel* src, pixel* dst)
{
	int i, j, br, bc;
	int px_per_op = dim > 512 ? 4 : 8;
	int blocks = dim / px_per_op;

	for (br = 0; br < blocks; ++br)
	{
		for (bc = 0; bc < blocks; ++bc)
		{
			for (i = 0; i < px_per_op; i++) {
				for (j = 0; j < px_per_op; j++) {
					COPY(&dst[PIXEL(i + px_per_op * br, j + px_per_op * bc, dim)], &src[PIXEL(j + px_per_op * bc, dim - 1 - (i + px_per_op * br), dim)]);
				}
			}
		}
	}
}

/* Add additional functions to test here */
void register_rotate_functions() {
	//add_rotate_function(&rotate, rotate_descr);
	add_rotate_function(&rotate_per_Npx, func1);

}

