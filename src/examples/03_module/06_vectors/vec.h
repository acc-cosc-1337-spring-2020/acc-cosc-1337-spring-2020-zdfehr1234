#include<string>
#include<vector>

using std::vector;

/*
Write function prototype for function loop_vector_w_index with no parameters.

*/

void loop_vector_w_index(vector<int> nums);

/*
Write function prototype for function loop_vector_w_index with a vector of int pass by value parameter.

*/

void loop_vector_w_index_ref(vector<int> &nums);

/*
Write function prototype for function loop_vector_w_index with a vector of int pass by reference parameter.
*/

void loop_vector_w_index_ref_const(const vector<int> &nums);

/*
Write function prototype for function loop_vector_w_index with a vector of int const pass by reference parameter.
*/


void loop_vector_w_auto(vector<int> &nums);
void loop_vector_w_auto_ref(vector<int> &nums);
void loop_vector_w_auto_ref_const(const vector<int> &nums);
