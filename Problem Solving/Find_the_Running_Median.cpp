#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
      priority_queue<int> lower;
    priority_queue<int, vector<int>,greater<int>> higher;
    vector<double> result;

    for(int i=0;i<a.size();i++){
        if(lower.empty() || a[i]<=lower.top()){
            lower.push(a[i]);
        }

        else{
            higher.push(a[i]);
        }


        if(lower.size()>higher.size()+1){
            higher.push(lower.top());
            lower.pop();
        }

        else if(lower.size()<higher.size()){
            lower.push(higher.top());
            higher.pop();
        }

        double median;
        if(lower.size()>higher.size()){
            median=lower.top();
        }
        else{
            median=(lower.top()+higher.top())/2.0;
        }

        result.push_back(median);

    }
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
