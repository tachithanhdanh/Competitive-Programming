#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n" 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("tttt.in","r",stdin);
	freopen("tttt.out","w",stdout); 
	//Your solution starts here.
	char ch[3][3]; set<char> st,sch; 
	string s; set<string> ss;
	for (int i=0;i<3;++i){
		for (int j=0;j<3;++j){
			cin >> ch[i][j];
		}
	}
	// C O W 00 01 02 
	// X X O 10 11 12
	// A B C 20 21 22
	for (int i=0;i<3;++i){
		if (ch[0][i]==ch[1][i] && ch[2][i]==ch[0][i]) {
			st.insert(ch[0][i]);
		}
		if (ch[i][0]==ch[i][1] && ch[i][2]==ch[i][0]){
			st.insert(ch[i][0]);
		}
	}
	if (ch[0][0]==ch[1][1] && ch[0][0]==ch[2][2]){
		st.insert(ch[0][0]);
	}
	if (ch[0][2]==ch[1][1] && ch[0][2]==ch[2][0]){
		st.insert(ch[1][1]);
	}
	cout << st.size() << endl;
	st.clear();
	for (int i=0;i<3;++i){
		for (int j=0;j<3;++j){
			st.insert(ch[i][j]);
			sch.insert(ch[j][i]);
		}
		s="";
		if (st.size()==2){
			auto it=st.begin(); ++it;
			s+=*(st.begin())+*(it);
			if (s[0]>s[1]) swap(s[0],s[1]);
			ss.insert(s);
		}
		s="";
		if (sch.size()==2){
			auto it=sch.begin(); ++it;
			s+=*(sch.begin())+*(it);
			if (s[0]>s[1]) swap(s[0],s[1]);
			ss.insert(s);
		}
		s=""; st.clear(); sch.clear();
	}
	st.clear(); sch.clear();
	for (int i=0;i<3;++i){
		st.insert(ch[i][i]);
		sch.insert(ch[i][2-i]);
	}
	s="";
		if (st.size()==2){
			auto it=st.begin(); ++it;
			s+=*(st.begin())+*(it);
			if (s[0]>s[1]) swap(s[0],s[1]);
			ss.insert(s);
		}
		s="";
		if (sch.size()==2){
			auto it=sch.begin(); ++it;
			s+=*(sch.begin())+*(it);
			if (s[0]>s[1]) swap(s[0],s[1]);
			ss.insert(s);
		}
		s=""; st.clear(); sch.clear();
	cout << ss.size();
	return 0;
}