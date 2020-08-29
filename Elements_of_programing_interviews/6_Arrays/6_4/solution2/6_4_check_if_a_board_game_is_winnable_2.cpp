/*
 * Author of solution: Naveen Kumar Mittal
 * Question is from Book "Elements of Programining Interviews version 1.4.8"
 * Question number 6.4
 * Page 50
 *
 */

#include <iostream>
#include <vector>

class check_if_a_board_game_is_winnable {
  enum status { not_set, status_false, status_true };
  std::vector<uint64_t> array_;
  std::vector<bool> memory_;
  size_t size_;  // size of array
 public:
  // check_if_a_board_game_is_winnable();
  //~check_if_a_board_game_is_winnable();

  bool helper(size_t index) {
    std::cout << "helper(" << index << ")" << std::endl;
    if (memory_[index] == status_false) {
      return false;
    } else if (memory_[index] == status_true) {
      return true;
    }
    if (index > size_) {
      std::cout << "something went wrong";
      return false;
    }
    if ((index == (size_ - 1)) || (array_[index] >= ((size_ - 1) - index))) {
      // std::cout << "True" << std::endl;
      return true;
    } else if (array_[index] == 0) {
      // std::cout << "False" << std::endl;
      return false;
    }

    for (size_t i = 1; (i <= array_[index]) && ((index + i) < size_); ++i) {
      if (memory_[index + i] == not_set) {
        if (helper(index + i)) {
          // std::cout << "True" << std::endl;
          memory_[index + i] = status_true;
          return true;
        } else {
          memory_[index + i] = status_false;
        }
      } else if (memory_[index + i] == status_true) {
        return true;
      }
    }
    // std::cout << "False" << std::endl;
    return false;
  }

  bool is_game_winnable(int *array, size_t size) {
    if (size < 2) {
      // std::cout << "True" << std::endl;
      return true;
    }

    for (size_t i = 0; i < size; ++i) {
      if (array[i] < 0) {
        std::cout << "Invalid input" << std::endl;
        return false;
      }
      array_.push_back(array[i]);
      memory_.push_back(not_set);
    }
    size_ = array_.size();
    return helper(0);
  }

  void clear_member_variables() {
    array_.clear();
    size_ = 0;
  }
};

int main(int argc, char const *argv[]) {
  check_if_a_board_game_is_winnable object;
  // Test Case 1
  // solution True
  {
    int array[7] = {3, 3, 1, 0, 2, 0, 1};
    bool result = object.is_game_winnable(array, 7);
    object.clear_member_variables();
    std::string result_str = result ? "True" : "False";
    std::cout << "Input {3,3,1,0,2,0,1}. Result ";
    std::cout << result_str << std::endl;
  }

  // Test Case 2
  // solution False
  {
    std::cout << std::endl;
    int array[7] = {3, 2, 0, 0, 2, 0, 1};
    bool result = object.is_game_winnable(array, 7);
    object.clear_member_variables();
    std::string result_str = result ? "True" : "False";
    std::cout << "Input {3,2,0,0,2,0,1}. Result ";
    std::cout << result_str << std::endl;
  }
  return 0;
}