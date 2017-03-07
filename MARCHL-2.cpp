#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <queue>
#include <string>
#define f first
#define s second
#define pb push_back
#define pp pop_back
#define ll long long int
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define MAX 100000001

using namespace std ;

int main() {

	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;

	int test ;
	cin >> test ;

	while(test--) {
		int N ;
		cin >> N ;

		ll a[N] , ans = -1 ;
		for(int i = 0 ; i < N ; i++) {
			cin >> a[i] ;
		}

		sort(a , a + N) ;

		for(int k = 1 ; k < N ; k++) {
			if(a[k] - a[k - 1] == 1) {
				continue ;
			}

			else {
				
				if(k == 1) {
					ans = a[k - 1] ;
				}

				else {
					ans = a[k] ;
				}

				break ;
 			}
		}

		cout << ans << '\n' ;

		// find consecutive sequence
	}

return 0 ;
}