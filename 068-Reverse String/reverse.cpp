#include <vector>
#include <string>
#include <iostream>
using namespace std;

void reverse(string &str) {
  //WRITE ME
  //this is the simple reverse function using temp
  int first = 0;
  int last = str.length() - 1;
  while (first < last){
      char temp = str[first];
      str[first] = str[last];
      str[last]= temp;
      first+=1;
      last-=1;
  }


}

int main(void) {
    vector<string> strings;

    strings.push_back("");
    strings.push_back("123");
    strings.push_back("abcd");
    strings.push_back("Captain's log, Stardate 42523.7");
    strings.push_back("Hello, my name is Inigo Montoya.");
    strings.push_back("You can be my wingman anyday!");
    strings.push_back("Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!");
    strings.push_back("amanap lanac a nalp a nam a");


    for (string test: strings) {
        reverse(test);
        cout << test << endl;
    }

    return EXIT_SUCCESS;
}