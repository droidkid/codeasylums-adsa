#include <iostream>
using namespace std;
//                               balls      w 
// max value can be 2 * 10^14 (2 * 10^5 * 10^9)
// So we have to use long long - 64 bits

typedef long long ll;

int balls[200005];

bool can_fill(int num_balls, 
		int num_buckets, 
		ll max_weight) {

	// You cannot have more than num_buckets
	// Each bucket cannot have more than max_weight

	ll cur_weight = 0;
	int bucket_count = 1;

	for (int i=0; i<num_balls; i++) {
		// No bucket can fit this ball.
		// So might as well just exit.
		if (balls[i] > max_weight) {
			return false;
		}

		// Let's try extending the cur bucket
		if (cur_weight + balls[i] <= max_weight) {
			// You can just add it to existing bucket.
			cur_weight += balls[i];
			continue;
		}
		else {
			// The ball cannot go into the current bucket
			// Let's start a new bucket.
			bucket_count++;
			cur_weight = balls[i];
		}
	}
	if (bucket_count <= num_buckets) {
		return true;
	}
	return false;
}

int main() {
	int n;
	int k; // max number of buckets.
	cin>>n>>k;

	// Let's take all the balls as input.
	ll sum = 0;
	for (int i=0; i<n; i++) {
		cin>>balls[i];
		sum = sum + balls[i];
	}

	ll lo = 1;
	ll hi = sum;

	// Binary Search
	while (lo < hi) {
		// Take the lower bound.
		ll max_weight = (lo + hi) / 2;

		// Predicate Function or Checking Function.
		if (can_fill(n, k, max_weight)) {
			// cout<<lo<<" "<<hi<<": "<<max_weight<<" YES"<<endl;
			hi = max_weight;
		} else {
			// cout<<lo<<" "<<hi<<": "<<max_weight<<" NO"<< endl;
			lo = max_weight + 1;
		}
	}

	cout << lo << endl; // You can also print hi.
	// lo == hi.
}
