#pragma once
#include<iostream>
using namespace std;

void printSol(map<int, int>& w) {
	for (auto it = w.begin(); it != w.end(); it++) {
		cout<<it->first<<" - "<<it->second<<"\n";
	}
}

bool isSafe(map<int, int>& w, map<int, int>::iterator k,int m) {
	int sum = 0, totalLeft = 0;
	bool ret = false;
	
	for (auto it = w.begin(); it != k; it++) {
		sum += (it->first) * (it->second);
	}
	
	auto ittt = w.end();
	--ittt;
	if (k != ittt) {
		k++;
	}

	if (sum + k->first <= m) {
		ret = true;
	}
	else
		return false;

	while (k != w.end()) {
		totalLeft += k->first;
		k++;
	}

	if (sum + totalLeft > m) {
		ret = true;
	}
	else {
		return false;
	}

	return ret;

}

/*
	w-list of weight
	wt-weight taken
	wl-weight left
*/

bool pickSS(map<int, int>& w, map<int, int>::iterator k,int wll,int m) {
	static int wt = 0, wl = wll;
	if (wt == m)
		return true;

	for (auto it = k; it != w.end(); it++) {
		if (isSafe(w, it,m)) {
			it->second = 1;
			wt += it->first;
			wl -= it->first;
			if (pickSS(w,++it,wll, m))
				return true;

			//Backtracking
			if (it->second == 1) {
				wt -= it->first;
				wl += it->first;
				it->second = 0;
			}
		}
	}

	return false;
}

void SumofSubsets() {
	int m,wl=0;						//target weight
	cout << "Enter the Target weight : ";
	cin >> m;

	map<int, int>w = {
		{5,0},{10,0},{12,0},{13,0 },{15,0},{18,0}
	};

	for (auto it = w.begin(); it != w.end(); it++) {
		wl += it->first;
	}

	if (pickSS(w,w.begin(), wl, m))
		printSol(w);
	else
		cout << "\nNo Solution exist\n";
		
 }