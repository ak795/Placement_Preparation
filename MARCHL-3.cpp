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

	int Test ;
	cin >> Test ;

	while(Test--) {
		int N ;
		cin >> N ;
		int a[N + 1][N + 1] , cZ = 0 ;
		int minBW = 0 ;

		for(int i = 0 ; i < N ; i++) {
			for(int j = 0 ; j < N ; j++) {
				cin >> a[i][j] ;

				if(a[i][j] == 0) {
					cZ++ ;
				}
			}
		}

		if(cZ == N * N) {
			cout << minBW << '\n' ;
		}		

		else {
			bool flag = false ;
			map < int , int > cnt ;
			int k =  1 ;

			for(int i = N - 1 ; i >= 1 ; i--) {
				cnt[i] = 2 * k ;
				k++ ;
			}

			for(int diff = N - 1 ; diff >= 1 ; diff--) {
				for(int i = 1 ; i <= N ; i++) {
					for(int j = 1 ; j <= N ; j++) {
						if(abs(i - j) == diff and cZ > 0) {
							cZ-- ;
							cnt[diff]-- ;
						}

						else {
							if(cZ == 0) {
								flag = true ;
								break ;
							}
						}
					}

					if(flag) {
						break ;
					}
				}

				if(flag) {
					minBW = diff ;
					break ;
				}
			}

			for(int i = N - 1 ; i >= 1 ; i--) {
				if(cnt[i] == 0) {
					minBW = i - 1 ;
				}
			}

			cout << minBW << '\n' ;
		}

	}

return 0 ;
}