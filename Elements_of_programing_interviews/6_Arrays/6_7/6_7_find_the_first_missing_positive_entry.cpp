/*
 * Author: Naveen Kumar Mittal
 * Question: 6.6 from EOPI
 *
 */

#include <iostream>

using namespace std;

class find_the_first_missing_positive_entry {
 public:
  void print_array(int array[], size_t size) {
    for (int i = 0; i < size; ++i) {
      cout << array[i] << " ";
    }
    cout << endl;
  }
  int get_key(int array[], size_t size) {
    for (int i = 0; i < size; ++i) {
      if (array[i] < 0 || array[i] > size) {
        array[i] = 0;
      }
      // print_array(array, size);
    }
    for (int i = 0; i < size; ++i) {
      if (abs(array[i]) - 1 < size) {
        if (array[abs(array[i]) - 1] > 0) {
          array[abs(array[i]) - 1] = -1 * array[abs(array[i])];
        } else if (array[abs(array[i]) - 1] == 0) {
          array[abs(array[i]) - 1] = -1 * (size + 1);
        }
      }
      print_array(array, size);
    }
    for (int i = 0; i < size; ++i) {
      if (array[i] >= 0) {
        return i + 1;
      }
    }
    return size + 1;
  }
};

int main(int argc, char const *argv[]) {
  find_the_first_missing_positive_entry object;
  {
    int array[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
    cout << "result " << object.get_key(array, 9) << endl;
  }
  {
    int array[] = {1, 2, 3, 4, 5};
    cout << "result " << object.get_key(array, 5) << endl;
  }
  {
    int array[] = {-1, -2, 0, 1, 2, 4};
    cout << "result " << object.get_key(array, 6) << endl;
  }
  {
    int array[] = {-1, -12, 0, 1, 12, 14};
    cout << "result " << object.get_key(array, 6) << endl;
  }
  return 0;
}