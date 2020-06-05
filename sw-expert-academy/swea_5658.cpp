#include<iostream>
#include<deque>
#include<set>
#include<cmath>
using namespace std;

void make_numbers(deque<int>& dq, set<int>& s, int N)
{
    int num, len = N / 4;
    for (int i = 0; i < N; i += len) {
        num = 0;
        for (int j = 0; j < len; j++) {
            num += (int)pow(16, len - 1 - j) * dq[i + j];
        }
        s.insert(num);
    }
}

int get_kth_max(deque<int>& dq, int N, int K)
{
    int len = N / 4;
    set<int> s;

    make_numbers(dq, s, N);
    for (int i = 0; i < len; i++) {
        dq.emplace_front(dq.back());
        dq.pop_back();
        make_numbers(dq, s, N);
    }

    set<int>::iterator itr = s.end();
    for (int i = 0; i < K; i++) --itr;

    return *itr;
}

int main()
{
    int T, N, K, result;
    string s;
    cin >> T;

    deque<int> dq;
    for (int i = 1; i <= T; i++) {
        cin >> N >> K >> s;
        for (int j = 0; j < N; j++) {
            if ('0' <= s[j] && s[j] <= '9') {
                dq.emplace_back(s[j] - '0');
            }
            else {
                dq.emplace_back(s[j] - 'A' + 10);
            }
        }

        result = get_kth_max(dq, N, K);
        cout << "#" << i << " " << result << "\n";
        dq.clear();
    }

    return 0;
}