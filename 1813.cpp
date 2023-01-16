class Solution {
  vector<string> stringToWords(string s) {
    vector<string> words{};
    string word = "";
    for (auto c : s) {
      if (isspace(c)) {
        words.push_back(word);
        word = "";
      } else {
        word += c;
      }
    }
    words.push_back(word);
    return words;
  }
public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> _words1 = stringToWords(sentence1);
    vector<string> _words2 = stringToWords(sentence2);
    vector<string> &shrt = _words1.size() < _words2.size()? _words1: _words2;
    vector<string> &lng = shrt == _words1? _words2: _words1;

    vector<string>::size_type i = 0;
    while (i < shrt.size() && shrt[i] == lng[i]) i++;
    vector<string>::size_type diff = lng.size() - shrt.size();
    while (i < shrt.size() && shrt[i] == lng[i + diff]) i++;

    return i == shrt.size();
  }
};
