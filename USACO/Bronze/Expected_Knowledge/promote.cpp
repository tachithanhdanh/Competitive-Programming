#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	// initialize file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	freopen("promote.in","r",stdin);
	freopen("promote.out","w",stdout);

	// read in counts for bronze
	int bronzeBefore, bronzeAfter;
	cin >> bronzeBefore >> bronzeAfter;
		
	// read in counts for silver
	int silverBefore, silverAfter;
	cin >> silverBefore >> silverAfter;

	// read in counts for gold
	int goldBefore, goldAfter;
	cin >> goldBefore >> goldAfter;

	// read in counts for platinum
	int platinumBefore, platinumAfter;
	cin >> platinumBefore >> platinumAfter;
		
	// do the computations
	int goldToPlatinum = platinumAfter - platinumBefore;
	int silverToGold = goldAfter - goldBefore + platinumAfter - platinumBefore;
	int bronzeToSilver = silverAfter - silverBefore + goldAfter - goldBefore + platinumAfter - platinumBefore;
		
	// print the answers
	cout << bronzeToSilver << "\n" << silverToGold << "\n" << goldToPlatinum;
		
	return 0;
}
