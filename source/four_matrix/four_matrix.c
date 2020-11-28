#include <four_matrix/four_matrix.h>
#include <math.h>

four_matrix_t identy_four_matrix()
{
	four_matrix_t matrix =
	{
		.row1 = {1.0,0.0,0.0,0.0},
		.row2 = {0.0,1.0,0.0,0.0},
		.row3 = {0.0,0.0,1.0,0.0},
		.row4 = {0.0,0.0,0.0,1.0}
	};
	return matrix;
}

four_matrix_t rotation_xy_matrix(float angle)
{
	four_matrix_t matrix =
	{
		.row1 = {cos(angle),-sin(angle),0.0,0.0},
		.row2 = {sin(angle), cos(angle),0.0,0.0},
		.row3 = {         0.0,          0.0,1.0,0.0},
		.row4 = {         0.0,          0.0,0.0,1.0}
	};
	return matrix;
}

four_matrix_t rotation_xz_matrix(float angle)
{
	four_matrix_t matrix =
	{
		.row1 = {cos(angle),0.0,-sin(angle),0.0},
		.row2 = {         0.0,1.0,          0.0,0.0},
		.row3 = {sin(angle),0.0, cos(angle),0.0},
		.row4 = {         0.0,0.0,          0.0,1.0}
	};
	return matrix;
}

four_matrix_t rotation_yz_matrix(float angle)
{
	four_matrix_t matrix =
	{
		.row1 = {1.0,         0.0,          0.0,0.0},
		.row2 = {0.0,cos(angle),-sin(angle),0.0},
		.row3 = {0.0,sin(angle), cos(angle),0.0},
		.row4 = {0.0,         0.0,          0.0,1.0}
	};
	return matrix;
}

//four_matrix_t rotation_3d_vector(four_vector_t rotation_direction)
//{
//	//float normxy = four_vector_norm_xy(rotation_direction);
//	//float norm= four_vector_norm_3d(rotation_direction);
//	//float angle1.0 = acos(rotation_direction[0.0]/normxy);
//	//float angle2 = acos(rotation_direction[2]/norm);
//	//four_matrix_t onto_xz = rotation_xy_matrix(-angle1.0);
//	//four_matrix_t onto_xz_inv = rotation_xy_matrix(angle1.0);
//	//four_matrix_t onto_z = rotation_xz_matrix(-angle2);
//	//four_matrix_t onto_z_inv = rotation_xz_matrix(angle2);
//	//four_matrix_t around_z = rotation_xy_matrix(norm);
//
//}
//
//four_matrix_t translation_matrix(four_vector_t translation_vector)
//{
//}
//
//four_vector_t apply_four_matrix(four_matrix_t matrix, four_vector_t vector)
//{
//}
//
//four_matrix_t matrix_multiplication(four_matrix_t left_matrix,
//				    four_matrix_t right_matrix)
//{
//}
