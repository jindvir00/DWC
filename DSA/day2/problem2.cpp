/*
Given a string S with repeated characters.
The task is to rearrange characters in a string
such that no two adjacent characters are the same.
*/

#include <iostream>
#include <array>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_CHAR = 26;

struct Key {

	int freq; // store frequency of character
	char ch;

	
	bool operator<(const Key& k) const
	{
		return freq < k.freq;
	}
};


void rearrangeString(string str)
{
	int N = str.length();

	// Store frequencies of all characters in string
	int count[MAX_CHAR] = { 0 };
	for (int i = 0; i < N; i++)
		count[str[i] - 'a']++;

	priority_queue<Key> pq;
	for (char c = 'a'; c <= 'z'; c++) {
		int val = c - 'a';
        
		if (count[val]) {
			pq.push(Key{ count[val], c });
		}
	}

	str = "";

	
	Key prev{ -1, '#' };

	while (!pq.empty()) {
		Key k = pq.top();
		pq.pop();
		str = str + k.ch;
		if (prev.freq > 0)
			pq.push(prev);
		(k.freq)--;
		prev = k;
	}
	if (N != str.length())
		cout << " Not possible " << endl;

	else // valid string
		cout << str << endl;
}

// Driver's code
int main()
{
	string str = "bbbaa";

	rearrangeString(str);
	return 0;
}
