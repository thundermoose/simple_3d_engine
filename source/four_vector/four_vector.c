#include <four_vector/four_vector.h>
#include <math.h>
#include <thundertester/test.h>

float four_vector_norm_3d(four_vector_t vector)
{
	four_vector_t vector_square = vector*vector;
	return sqrt(vector_square[0]+
		    vector_square[1]+
		    vector_square[2]);
}

float four_vector_norm_4d(four_vector_t vector)
{
	four_vector_t vector_square = vector*vector;
	return sqrt(vector_square[0]+
		    vector_square[1]+
		    vector_square[2]+
		    vector_square[3]);
}

float four_vector_scalar_3d(four_vector_t left_vector,
			    four_vector_t right_vector)
{
	four_vector_t vector_square = left_vector*right_vector;
	return sqrt(vector_square[0]+
		    vector_square[1]+
		    vector_square[2]);
}

float four_vector_scalar_4d(four_vector_t left_vector,
			    four_vector_t right_vector)
{
	four_vector_t vector_square = left_vector*right_vector;
	return sqrt(vector_square[0]+
		    vector_square[1]+
		    vector_square[2]+
		    vector_square[3]);
}

new_test(norm_3d_of_unit_3d_vector,
	 four_vector_t vector = {0.7821080382182704, 
	 		       	 0.42726756860548354, 
			       	 0.4535961214255773,
			       	 0.0};
	 assert_that(fabs(four_vector_norm_3d(vector)-1)<1e-12);
	);
new_test(norm_4d_of_unit_4d_vector,
	 four_vector_t vector={0.6407153907146608, 0.35002441322865624, 0.28384457999376717, 0.6216099682706644};
	 assert_that(fabs(four_vector_norm_4d(vector)-1)<1e-12);
	);

new_test(scalar_3d_orthogonal,
	 four_vector_t vector1 = {1,0,0,0};
	 four_vector_t vector2 = {0,1,0,0};
	 assert_that(fabs(four_vector_scalar_3d(vector1,vector2))<1e-12);
	);

new_test(scalar_3d_orthogonal,
	 four_vector_t vector1 = {1,0,0,0};
	 four_vector_t vector2 = {0,1,0,0};
	 assert_that(fabs(four_vector_scalar_3d(vector1,vector2))<1e-12);
	);
