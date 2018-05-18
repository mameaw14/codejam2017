#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	long long cur,left,right;
	node(long long cur,long long left, long long right)
		:cur(cur),left(left),right(right){}
	bool operator<(const node& b) const{
		//prlong longf("cmp\n");
		long long minA = min(left,right),minB = min(b.left,b.right);
		long long maxA = max(left,right),maxB = max(b.left,b.right);
		if(minA==minB) {
			if(maxA==maxB) {
				return cur>b.cur;
			}
			return maxA<maxB;
		}
		return minA<minB;
	}
	long long new_left() {
		return cur - left - 1 + (left+1)/2;
	}
	long long new_right() {
		return cur + (right+1)/2;
	}
	node* new_node_left() {
		long long n = new_left();
		//prlong longf("l %d %d %d\n",n,left-(cur-n),cur-n-1);
		return new node(n,left-(cur-n),cur-n-1);
	}
	node* new_node_right() {
		long long n = new_right();
		//prlong longf("r %d %d %d\n",n,n-cur-1,right-(n-cur));
		return new node(n,n-cur-1,right-(n-cur));
	}
};
struct MyComparator {
    bool operator() (node* arg1, node* arg2) {
        return *arg1 < *arg2; //calls your operator
    }
};
int program() {
	long long n,k;
	scanf("%d %d",&n,&k);
	priority_queue<node*,vector<node*>,MyComparator> q;
	q.push(new node((n+1)/2,(n+1)/2-1,(n+1)-(n+1)/2-1));
	while(k--) {
		node* t = q.top();
		q.pop();
		//prlong longf("%d %d %d\n", t->cur, t->left, t->right);
		if(t->left!=0) q.push(t->new_node_left());
		if(t->right!=0) q.push(t->new_node_right());
		if(k==0) printf("%d %d", max(t->left,t->right), min(t->left,t->right));
	}
	return 0;
}
main() {
	long long t;
	scanf("%d",&t);
	for (long long i = 0; i < t; ++i)
	{
		printf("case #%d: ", i+1);
		program();
		printf("\n");
	}
}