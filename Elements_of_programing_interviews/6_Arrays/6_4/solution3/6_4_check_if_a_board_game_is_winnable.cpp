/*
 * Author of solution: Naveen Kumar Mittal
 * Question is from Book "Elements of Programining Interviews version 1.4.8"
 * Question number 6.4
 * Page 50
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class check_if_a_board_game_is_winnable {
 public:
  bool is_game_winnable(int *array, size_t size) {
    if (size < 2) {
      // std::cout << "True" << std::endl;
      return true;
    }
    int reachability = 1;
    for (int i = 0; (i < reachability) && (i < size); ++i) {
      reachability = max(reachability, i + array[i] + 1);
      // cout << array[i] << " ";
    }

    if (reachability >= size) {
      return true;
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  check_if_a_board_game_is_winnable object;
  // Test Case 1
  // solution True
  {
    int array[7] = {3, 3, 1, 0, 2, 0, 1};
    bool result = object.is_game_winnable(array, 7);
    string result_str = result ? "True" : "False";
    cout << "Input {3,3,1,0,2,0,1}. Result ";
    cout << result_str << endl;
  }

  // Test Case 2
  // solution False
  {
    cout << endl;
    int array[7] = {3, 2, 0, 0, 2, 0, 1};
    bool result = object.is_game_winnable(array, 7);
    string result_str = result ? "True" : "False";
    cout << "Input {3,2,0,0,2,0,1}. Result ";
    cout << result_str << endl;
  }
  return 0;
}