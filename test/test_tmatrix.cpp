#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(7), m2(m1);

	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int>*m1 = new TMatrix<int>(7);
	TMatrix<int> m2(*m1);
	delete m1;
	
	ASSERT_NO_THROW(m2[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(7);

	EXPECT_EQ(7, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[-7][-13]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[7][13]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(7);

	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(5), m2(5);

	for (int i = 0; i < 5; i++)	m1[i][i] = i;
	m2 = m1;

	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(13), m2(7);
	m1 = m2;

	EXPECT_EQ(m1.GetSize(), 7);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(5), m2(7);

	for (int i = 0; i < 5; i++)	m1[i][i] = i;
	m2 = m1;

	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(7), m2(m1);

	EXPECT_EQ(m1==m2, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(7);

	EXPECT_EQ(m1 == m1, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5), m2(7);

	EXPECT_EQ(m1 != m2, true);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int>m1(5), m2(5), res(5);

	for (int i = 0; i < 5; i++) 
	{
		m2[i][i] = 2;
		m1[i][i] = 1;
	}
	res = m1 + m2;

	for (int i = 0; i < 5; i++) 
	{
		EXPECT_EQ(res[i][i], 3);
	}

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int>m1(5), m2(10);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int>m1(5), m2(5), res(5);

	for (int i = 0; i < 5; i++) 
	{
		m2[i][i] = 2;
		m1[i][i] = 1;
	}
	res = m1 - m2;

	for (int i = 0; i < 5; i++) 
	{
		EXPECT_EQ(res[i][i], -1);
	}

}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int>m1(5), m2(10);

	ASSERT_ANY_THROW(m1 - m2);
}