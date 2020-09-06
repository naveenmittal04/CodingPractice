/*
 * Author: Naveen Kumar Mittal
 * Question: 6.10 from EOPI
 *
 */

#include <float.h>

#include <iostream>

using namespace std;

class Max_product_all_but_one {
 public:
  double solution1(double array[], size_t size) {
    if (size < 2) {
      return 0;
    }
    double product = 1;
    double min_neg = 0;
    bool is_min_neg = false;
    double min_non_neg = DBL_MAX;
    bool is_min_non_neg = false;
    for (int i = 0; i < size; ++i) {
      if (array[i] < min_neg) {
        if (is_min_neg) {
          product *= min_neg;
        }
        min_neg = array[i];
        if (!is_min_neg) is_min_neg = true;
      } else if (array[i] < min_non_neg) {
        if (is_min_non_neg) {
          product *= min_non_neg;
        }
        min_non_neg = array[i];
        if (!is_min_non_neg) is_min_non_neg = true;
      } else {
        product *= array[i];
      }
    }

    if (!is_min_non_neg || !is_min_neg) {
      // cout << "min_non_neg " << min_non_neg << " min_neg " << min_neg <<
      // endl;
      return product;
    }

    if (product < 0) {
      return product * min_neg;
    } else {
      return product * min_non_neg;
    }
  }
};

int main(int argc, char const *argv[]) {
  Max_product_all_but_one object;
  {
    double array[] = {2, 3, 5, 5, 7};
    double result = object.solution1(array, 5);
    cout << "result " << result << " actual result : " << 3 * 5 * 5 * 7 << endl;
  }
  {
    double array[] = {1, 2, 3, 4, 5};
    double result = object.solution1(array, 5);
    cout << "result " << result << " actual result : " << 2 * 3 * 4 * 5 << endl;
  }
  {
    double array[] = {-1, -2, 0, 1, 2, 4};
    double result = object.solution1(array, 6);
    cout << "result " << result << " actual result : " << -1 * -2 * 1 * 2 * 4
         << endl;
  }
  {
    double array[] = {-1, -12, 1, 2, 4};
    double result = object.solution1(array, 5);
    cout << "result " << result << " actual result : " << -1 * -12 * 2 * 4
         << endl;
  }
  return 0;
}