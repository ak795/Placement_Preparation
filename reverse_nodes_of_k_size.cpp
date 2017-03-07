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

LLNode *reverseLL(LLNode *head) {

	LLNode *curr = head , *prev = NULL , *tmp = head ;

	while(curr != NULL) {
		tmp = curr -> next ;
		curr -> next = prev ;
		prev = curr ;
		curr = tmp ;
	}

	return prev ;
}

void print(LLNode *head) {

	while(head != NULL) {
		cout << head -> data << ' ' ;
		head = head -> next ;
	}

	cout << '\n' ;
}

LLNode *reverseKNodes(LLNode *head , int k) {

	int cnt = 1 , num = 0 ;
	LLNode *curr = head , *new_head = NULL, *ans_head = NULL , *tmp = NULL, *tmp_head = NULL ;
	bool isFirst = true ;

	while(curr != NULL) {
		if(cnt % k == 1) {
			num++ ;
			if(num == 1) {
				ans_head = reverseLL(tmp_head) ;
				tmp = ans_head ;
			}

			else {
				ans_head -> next = reverseLL(tmp_head) ;
			}

			delete new_head ;
			delete tmp_head ;

			isFirst = true ;
		}

		if(isFirst == true) {
			new_head = new LLNode ;
			tmp_head = new_head ;
			new_head -> data = curr -> data ;
			new_head -> next = NULL ;
			isFirst = false ;
		}

		else {
			new_head = addNode(new_head , curr -> data) ;
		}

		print(tmp_head) ;

		curr = curr -> next ;
		cnt++ ;
	}

	ans_head -> next = NULL ;
	return tmp ;
}

int main() {

	int N , num , k ;
	cin >> N >> k ;

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

 	head = reverseKNodes(head , k) ;
 	print(head) ;

 	return 0 ;
}