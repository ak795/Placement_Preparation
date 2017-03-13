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

struct Node {
  int data ;
  Node *next , *random ;
  Node(int x) {
    data = x ;
    next = random = NULL ;
  }
} ;

void print(Node *head) {
  Node *ptr = head ;
  while(ptr) {
    cout << ptr -> data << ' ' ;
    ptr = ptr -> next ;
  }
  cout << '\n' ;
}

Node *CloneLL(Node *head) {
  Node *curr = head , *tmp = NULL, *ans = NULL ;

  while(curr) {
    tmp = curr -> next ;
    curr -> next = new Node(curr -> data) ;
    curr -> next -> next = tmp ;
    curr = tmp ;
  }

  curr = head ;

  while(curr) {
    curr -> next -> random = curr -> random -> next ;
    curr = curr -> next -> next ;
  }

  Node *original = head , *copy = head -> next ;
  ans = copy ;

  while(original and copy) {
    original -> next = original -> next? original -> next -> next : original -> next;
    copy -> next = copy -> next? copy -> next -> next : copy -> next;
    original = original -> next;
    copy = copy -> next;
   }

  return ans ;
}

int main() {

  ios_base::sync_with_stdio(false) ;
  cin.tie(0) ;

  Node* head = new Node(1) ;
  head -> next = new Node(2) ;
  head -> next -> next = new Node(3) ;
  head -> next -> next -> next = new Node(4) ;
  head -> next -> next -> next -> next = new Node(5) ;

  head -> random = head -> next -> next ;
  head -> next -> random = head ;
  head -> next -> next -> random = head -> next -> next -> next -> next;
  head -> next -> next -> next -> random = head -> next -> next -> next -> next;
  head -> next -> next -> next -> next -> random = head -> next;

  cout << "Original Linked List : \n" ;
  print(head) ;
  cout << "CLoned Linked List : \n" ;

  Node *clone = CloneLL(head) ;
  print(clone) ;

  return 0 ;
}
