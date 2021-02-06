#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

struct rectangle
{
	int x1,x2,y1,y2;
};

int intersect(rectangle a, rectangle b){
	int xOverlap=max(0,min(a.x2,b.x2)-max(a.x1,b.x1));
	int yOverlap=max(0,min(a.y2,b.y2)-max(a.y1,b.y1));
	return xOverlap*yOverlap;
}

int area(rectangle a){
	return (a.x2-a.x1)*(a.y2-a.y1);
}

rectangle a[3]; int maxX,maxY;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	//Your solution starts here.
	//http://www.usaco.org/current/data/sol_billboard_bronze_dec17.html
	//http://www.usaco.org/index.php?page=viewproblem2&cpid=759
	for (int i=0;i<3;++i){
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
	}
	cout << area(a[0])+area(a[1])-intersect(a[0],a[2])-intersect(a[1],a[2]);
	return 0;
}
 
