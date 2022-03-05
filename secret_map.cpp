#include <iostream>
#include <string>
#include <vector>

using namespace std;

string bit_expression_by_shift(int n, int num)
{
    string str;

    while (--n >= 0)
    {
        if ((1 << n) & num)
        {
            str.push_back('#');
        }
        else
        {
            str.push_back(' ');
        }
    }

    return str;
}

void bit_expression_by_recur(int n, int num, string& str)
{
    if (n-- <= 0)
    {
        return;
    }
    else
    {
        bit_expression_by_recur(n, num / 2, str);
        if (num % 2)
        {
            str.push_back('#');
        }
        else 
        {
            str.push_back(' ');
        }
    }
}

vector<string> solution(int n, vector<int>& arr1, vector<int>& arr2)
{
    vector<string> answer;

    for (int i{ 0 }; i < n; ++i)
    {
        // answer.push_back(bit_expression_by_shift(n, arr1[i] | arr2[i]));
        string tmp_str;
        bit_expression_by_recur(n, arr1[i] | arr2[i], tmp_str);
        answer.push_back(tmp_str);
    }

    return answer;
}



int main()
{
    vector<int> arr1{ 9, 20, 28, 18, 11 };
    vector<int> arr2{ 30, 1, 21, 17, 28 };
    vector<int> arr3{ 46, 33, 33, 22, 31, 50 };
    vector<int> arr4{ 27, 56, 19, 14, 14, 10 };

    for (const auto& elem : solution(arr3.size(), arr3, arr4))
    {
        cout << elem << endl;
    }

    cout << endl;
}
