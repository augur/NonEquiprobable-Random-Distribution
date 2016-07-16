#include <iostream>
#include <fstream>

using namespace std;
//using namespace ios;

int main(int argc, char const *argv[]) {

  ifstream answers;
  int count = stoi(argv[1]);
  answers.open(argv[2], ios::in);

  int matched = 0;
  int valid_ans;
  int attempt_ans;
  for (int i = 0; i < count; i++) {
    answers >> valid_ans;
    cin >> attempt_ans;
    if (valid_ans == attempt_ans) {
      matched++;
    }
  }
  answers.close();

  cout << matched << " of " << count << " are valid" <<  endl;
  return 0;
}
