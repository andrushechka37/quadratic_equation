#ifndef TESTIGN_H
#define TESTIGN_H
//----------------------------------------------------------------------------------------------
/// @brief tests one test
///
/// @param array of coefficients
/// @param x1 which is right
/// @param x2 which is right
/// @param x1 which is calculated
/// @param x2 which is calculated
/// @param number_of_roots which is right
/// @param number_of_roots which is calculated
/// @param pointer to x2
///
//----------------------------------------------------------------------------------------------
void test_one_case(double coefs[], double x1_ref, double x2_ref, double x1, double x2, int nroots_ref, int nroots);

//----------------------------------------------------------------------------------------------
/// @brief starts a lot of tests
///
//----------------------------------------------------------------------------------------------
void test_solve(void);

#endif
