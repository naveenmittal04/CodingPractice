/*
 * Author: Naveen Kumar Mittal
 * Question: 6.5 from EOPI
 *
 */

#include <iostream>

using namespace std;

class delete_a_key_from_an_array {
 public:
  void delete_key(int array[], size_t size, int key) {
    for (int i = 0, j = 0; j < size; ++i, ++j) {
      if (array[j] == key) {
        j++;
      }
      array[i] = array[j];
      cout << array[i] << " ";
    }
  }
};

int main(int argc, char const *argv[]) {
  delete_a_key_from_an_array object;
  int array[] = {5, 3, 7, 11, 2, 3, 13, 5, 7};
  object.delete_key(array, 9, 5);
  return 0;
}