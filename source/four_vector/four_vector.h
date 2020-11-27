#ifndef __FOUR_VECTOR__
#define __FOUR_VECTOR__

typedef float four_vector_t __attribute__((vector_size(16)));

float four_vector_norm_xy(four_vector_t vector);

float four_vector_norm_3d(four_vector_t vector);

float four_vector_norm_4d(four_vector_t vector);

float four_vector_scalar_3d(four_vector_t left_vector,
			    four_vector_t right_vector);

float four_vector_scalar_4d(four_vector_t left_vector,
			    four_vector_t right_vector);
#endif
