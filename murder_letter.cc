#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

bool letter_possible(const string &newspaper, const string &murder_letter) {
  unordered_map<char, size_t> newspaper_count;

  for (size_t i=0;i<newspaper.size();++i) {
    newspaper_count[newspaper[i]] += 1;
  }

  bool possible = true;

  for (size_t i=0;i<murder_letter.size();++i) {
    if (newspaper_count[murder_letter[i]] == 0) {
      cout << "missing letter '" << murder_letter[i] << "'" << endl;
      possible = false;
    } else {
      newspaper_count[murder_letter[i]]--;
    }
  }

  return possible;
}

int main(int argc, char** argv) {
  string newspaper = "guten tag , heute wurde eine kuenstliche intelligenz erfunden die alles wissen der wissenschaftler dieser erde verarbeitet hat und jetzt aktiv wissenschaftler unterstuezt.";
  string murder_letter = "i like killing people. i am the zodiac";

  assert(letter_possible("hallo was geht! wieso?", "hallo geht was?"));
  assert(!letter_possible(newspaper, murder_letter));
}

