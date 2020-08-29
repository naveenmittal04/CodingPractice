/*
 * Author: Naveen Kumar Mittal
 * Question: 6.5 from EOPI
 *
 */

#include <iostream>

using namespace std;

class delete_a_key_from_an_array {
 public:
  void print_array(int array[], size_t size) {
    for (int i = 0; i < size; ++i) {
      cout << array[i] << " ";
    }
    cout << endl;
  }
  void delete_key(int array[], size_t size, int key) {
    for (int i = 0, j = 0; j < size; ++j) {
      if (array[j] != key) {
        array[i] = array[j];
        i++;
        // cout << array[i] << " ";
      }
      // print_array(array, size);
    }
  }
};

int main(int argc, char const *argv[]) {
  delete_a_key_from_an_array object;
  int array[] = {5, 3, 7, 11, 3, 3, 3, 5, 7};
  object.delete_key(array, 9, 3);
  object.print_array(array, 5);
  return 0;
}