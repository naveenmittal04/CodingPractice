/*
 * Author: Naveen Kumar Mittal
 * Question: 6.12 from EOPI
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class All_prime {
 public:
  void solution1(int n) {
    vector<int> hash;
    bool is_prime;
    for (int i = 2; i < n; ++i) {
      is_prime = true;
      for (int j = 0; j < hash.size(); ++j) {
        if (i % hash[j] == 0) {
          is_prime = false;
          break;
        }
      }
      if (is_prime) {
        hash.push_back(i);
        cout << i << " ";
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  All_prime object;
  {
    object.solution1(10);
    cout << endl;
  }
  {
    object.solution1(100);
    cout << endl;
  }
  {
    object.solution1(1000);
    cout << endl;
  }
  return 0;
}