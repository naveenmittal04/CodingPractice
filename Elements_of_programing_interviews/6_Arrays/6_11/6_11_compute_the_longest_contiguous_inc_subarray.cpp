/*
 * Author: Naveen Kumar Mittal
 * Question: 6.10 from EOPI
 *
 */
#include <iostream>

using namespace std;

class Longest_contiguous_subarray {
 public:
  pair<int, int> solution1(int array[], size_t size) {
    if (size < 0) {
      return {0, 0};
    }
    if (size == 1) {
      return {1, 1};
    }
    int r_i = 0, r_j = 0, t_i = 0, t_j = 0, k = 0;
    for (; k < size - 1; ++k) {
      if (array[k] < array[k + 1]) {
        t_j++;
      } else {
        if (t_j - t_i > r_j - r_i) {
          r_i = t_i;
          r_j = t_j;
        }
        t_i = k + 1;
        t_j = t_i;
      }
    }
    if (t_j - t_i > r_j - r_i) {
      r_i = t_i;
      r_j = t_j;
    }

    return {r_i, r_j};
  }
};

int main(int argc, char const *argv[]) {
  Longest_contiguous_subarray object;
  {
    int array[] = {2, 3, 5, 5, 7};
    pair<int, int> result = object.solution1(array, 5);
    cout << "result [" << result.first << "," << result.second
         << "] actual result : [0,2]" << endl;
  }
  {
    int array[] = {5, 4, 3, 2, 1};
    pair<int, int> result = object.solution1(array, 5);
    cout << "result [" << result.first << "," << result.second
         << "] actual result : [0,0]" << endl;
  }
  {
    int array[] = {-1, -2, 10, 1, 2, 4};
    pair<int, int> result = object.solution1(array, 6);
    cout << "result [" << result.first << "," << result.second
         << "] actual result : [3, 5]" << endl;
  }
  {
    int array[] = {-1, -12, 1, 2, 0};
    pair<int, int> result = object.solution1(array, 5);
    cout << "result [" << result.first << "," << result.second
         << "] actual result : [1,3]" << endl;
  }
  return 0;
}