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

	int T ;
	cin >> T ;

	while(T--) {
		int N ;
		cin >> N ;

		ll X[N] , Y[N] ;
		ll wX = 0 , wY = 0 , ans = 3e9 ;

		for(int i = 0 ; i < N ; i++) {
			cin >> X[i] ;
		}

		for(int i = 0 ; i < N ; i++) {
			cin >> Y[i] ;
		}

		bool isCurr = true ;

		for(int i = 0 ; i < N ; i++) {
			if(isCurr) {
				wY += X[i] ;
				isCurr = false ;
			}

			else {
				wX += Y[i] ;
				isCurr = true ;
			}
		}

		ans = min(ans , wX + wY) ;
		isCurr = true ;
		wX = wY = 0 ;

		for(int i = 0 ; i < N ; i++) {
			if(isCurr) {
				wX += Y[i] ;
				isCurr = false ;
			}

			else {
				wY += X[i] ;
				isCurr = true ;
			}
		}

		ans = min(ans , wX + wY) ;
		cout << ans << '\n' ;

	}

return 0 ;
}