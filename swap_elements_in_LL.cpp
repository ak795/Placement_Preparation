// PairWise Swap
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

struct LLNode {
	LLNode *next ;
	int data ;
} ;

LLNode *addNode(LLNode *head , int num) {

	LLNode *tmp = new LLNode ;
	tmp -> data = num ;
	tmp -> next = NULL ;

	head -> next = tmp ;
	head = head -> next ;

	return head ;

}

bool isPresent(LLNode *head, int val) {

	bool found = false ;

	while(head != NULL) {
		if(head -> data == val) {
			found = true ;
			break ;
		}
		head = head -> next ;
	}

	return found ;
}

LLNode *del(LLNode *head , int val) {

	LLNode *tmp = head , *new_head = head ;

	while(tmp != NULL) {
		if(tmp -> data == val) {
			if(tmp == head) {
				head = tmp -> next ;
				new_head = head ;
				break ;
			}

			else {
				head -> next = tmp -> next ;
				break ;
			}
		}

		head = tmp ;
		tmp = tmp -> next ;
	}

	return new_head ;
}

void print(LLNode *head) {

	while(head != NULL) {
		cout << head -> data << ' ' ;
		head = head -> next ;
	}

	cout << '\n' ;
}

LLNode *pairWiseSwap(LLNode *head) {
	 LLNode *curr = head -> next , *prev = head ;
	 LLNode *tmp = NULL ;

	 prev = head ;
	 head = curr ;

	 while(true) {
	 	tmp = curr -> next ;
	 	curr -> next = prev ;

	 	if(tmp == NULL or tmp -> next == NULL) {
	 		prev -> next = tmp ;
	 		break ;
	 	}

	 	prev -> next = tmp -> next ;
	 	prev = tmp ;
	 	curr = prev -> next ;
	 }

	 return head ;
}

int main() {

	int N , num , k ;
	cin >> N;

	cout << "Enter " << N << " Numbers" << '\n' ;

	LLNode *head = new LLNode ; 
	LLNode *tmp = head ;

	for(int k = 0 ; k < N ; k++) {
		cout << "Number " << k + 1 << " : " ;
		cin >> num ;

		if(k == 0) {
			head -> data = num ;
			head -> next = NULL ;
		}

		else {
			head = addNode(head , num) ;
		}
 	}

 	head = tmp ;

 	if(N == 1) {
 		print(head) ;
 		return 0 ;
 	}

 	head = pairWiseSwap(head) ;
 	print(head) ;

return 0 ;
}