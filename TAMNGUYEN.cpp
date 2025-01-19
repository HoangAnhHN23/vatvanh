#include <bits/stdc++.h>
using namespace std;

#define max 1000000
#define maxln 6*log(10)

int isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void find(vector<int>& numbers, int a, int b, int c) {
    if (a*b*c > max) return;
    int x = 1;
    while (x*log(a) <= maxln) {
        int y = 1;
        while (x*log(a) + y*log(b) <= maxln) {
            int z = 1;
            while (x*log(a) + y*log(b) + z*log(c) <= maxln) {
                numbers.push_back((int) (pow(a,x)*pow(b,y)*pow(c,z)));
                z += 1;
            }
            y += 1;
        }
        x += 1;
    }
    return;
}

int main() {
    vector<int> primes;
    vector<int> numbers;
    
    for (int i = 2; i <= 103; i++)
        if (isPrime(i)) primes.push_back(i);
    
    int n = primes.size();
    
    for (int i = 0; i < n - 2; ++i)
        for (int j = i + 1; j < n - 1; ++j)
            for (int k = j + 1; k < n; ++k)
                find(numbers,primes[i],primes[j],primes[k]);
    
    sort(numbers.begin(), numbers.end());
    
    int q;
    int a;
    int b;
    
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        
        auto it1 = lower_bound(numbers.begin(), numbers.end(), a);
        int index1;
        if (it1 != numbers.end()) index1 = it1 - numbers.begin();
        else {
            cout << 0;
            continue;
        }
        
        auto it2 = lower_bound(numbers.begin(), numbers.end(), b);
        int index2;
        if (it2 != numbers.end()) {
            if (numbers[it2 - numbers.begin()] == b) index2 = it2 - numbers.begin();
            else index2 = (it2 - numbers.begin()) - 1;
        }
        else {
            index2 = numbers.size() - 1;
        }
        
        cout << index2 - index1 + 1 << endl;
    }
    return 0;
}
