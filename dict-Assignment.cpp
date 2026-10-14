#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
unordered_map<string, int> dic;

bool compareWords(string w1, string w2) {
    if (dic[w1] != dic[w2]) {
        return dic[w1] > dic[w2];
    }
    return w1 < w2;
}

int main() {
    while (true) {
         cout<< "1. Add Word"<<endl;
        cout<< "2. Search Word"<<endl;
        cout<< "3. Suggest Words"<<endl;
        cout<< "4. Exit"<<endl;
        cout<< "Choose option: ";

        int ch;
        cin >> ch;

        if (ch==1) {
            string word;
            cout<<"Enter word: ";
            cin>>word;
            if (dic.find(word) != dic.end()) {
                cout <<"already exists"<<endl;
            } else {
                dic[word]= 1;
                cout<< "word added"<<endl;
            }
        }
        else if (ch==2) {
            string word;
            cout << "Enter word: ";
            cin >> word;
            if (dic.find(word)!= dic.end()) {
                dic[word]++;
                cout << "Found"<<endl;
            } else {
                cout<< "Not found"<<endl;
            }
        }
        else if (ch ==3) {
            string prefix;
            int k;
            cout <<"Enter prefix:";
            cin >> prefix;
            cout<< "Enter k: ";
            cin >> k;
            if (k <= 0) {
                cout << "K must be greater than 0"<<endl;
                continue;
            }
            vector<string> res;
            for (auto entry : dic) {
                string word = entry.first;

                if (word.find(prefix)== 0) {
                    res.push_back(word);
                }

            }

            sort(res.begin(), res.end(), compareWords);
            cout << "Suggestions:[";

            for (int i = 0; i < k && i < res.size(); i++) {
                cout << res[i];
                if (i + 1 < k && i + 1 < res.size()) {
                    cout << " , ";
                }
            }

            cout << "]\n";
        }
        else if (ch == 4) {
            cout << "Exiting"<<endl;
            break;
        }
        else {
            cout << "Invalid choice"<<endl;
        }
    }

    return 0;
}
