#ifndef __FOUR_MATRIX__
#define __FOUR_MATRIX__

#include <four_vector/four_vector.h>

typedef struct
{
	four_vector_t row1;
	four_vector_t row2;
	four_vector_t row3;
	four_vector_t row4;
} four_matrix_t

four_matrix_t identy_four_matrix();

four_matrix_t rotation_xy_matrix(float angle);

four_matrix_t rotation_xz_matrix(float angle);

four_matrix_t rotation_yz_matrix(float angle);

four_matrix_t rotation_3d_vector(four_vector_t rotation_vector);

four_matrix_t translation_matrix(four_vector_t translation_vector);

four_vector_t apply_four_matrix(four_matrix_t matrix, four_vector_t vector);

four_matrix_t matrix_multiplication(four_matrix_t left_matrix,
				    four_matrix_t right_matrix);

#endif
