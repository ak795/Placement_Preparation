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
#define MAX 2111

using namespace std ;

bool checkDuplicate(string inp) {
	int len = inp.size() ;
	int check = 0 ;

	for(int k = 0 ; k < len ; k++) {
		int t = inp[k] - 'a' ; 

		if( (check & (1 << t)) > 0 ) {
			return true ;
		}  

		check |= (1 << t) ;
	}

	return false ;
}

int main()
{
    ios_base::sync_with_stdio(false) ;

    cin.tie(0) ;

    int check = 0 ;
    string str ;
    cin >> str ;
   	
   	if(checkDuplicate(str)) {
   		cout << "Duplicates Present." << '\n' ;
   	}

   	else {
   		cout << "No Duplicates." << '\n' ;
   	}

    return 0 ;
}