#include <cstdio>
#include <set>
#include <vector>
#define max(a,b) {(a>b)?(a):(b)}
using namespace std;

vector<int> arr;

typedef long long ll;

int main() {


    int n;
    scanf("%d", &n);

    arr.resize(n + 2, 0);
    arr[0] = arr[n + 1] = -1;

    set<int> arrays;
    arrays.insert(0);
    arrays.insert(n + 1);

    int t;
    ll cnt = 0;

    while (n--) {
        scanf("%d", &t);

        arrays.insert(t);
        set<int>::iterator it = arrays.find(t);

        it++;
        arr[t] = arr[*it] + 1;
        it--; it--;
        arr[t] = max(arr[t], arr[*it] + 1);

        cnt += arr[t];

        printf("%lld\n", cnt);
    }

    return 0;
}
