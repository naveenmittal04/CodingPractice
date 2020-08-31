/*
 * Author: Naveen Kumar Mittal
 * Question: 6.6 from EOPI
 *
 */

#include <iostream>

using namespace std;

class delete_duplicates_from_sorted_array {
 public:
  void print_array(int array[], size_t size) {
    for (int i = 0; i < size; ++i) {
      cout << array[i] << " ";
    }
    cout << endl;
  }
  void delete_key(int array[], size_t size) {
    int i = 0, j = 0;
    for (; j + 1 < size; ++j) {
      if (array[j] != array[j + 1]) {
        array[i] = array[j];
        i++;
      }
      print_array(array, size);
    }
    array[i] = array[j];
  }
};

int main(int argc, char const *argv[]) {
  delete_duplicates_from_sorted_array object;
  int array[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
  object.delete_key(array, 9);
  object.print_array(array, size);
  return 0;
}