#include <iostream>
#include <string>

using namespace std;

int x,y,cx=1,cy=1;

int hilbert(int iter, string s, int dir) {
	int pasi = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A' && iter > 0) {
			pasi += hilbert(iter - 1, "+BF-AFA-FB+", dir);
		} else if (s[i] == 'B' && iter > 0) {
			pasi += hilbert(iter - 1, "-AF+BFB+FA-", dir);
		} else if (s[i] == 'F') {
			pasi++;
			if (dir == 0) cx++;
			if (dir == 2) cx--;
			if (dir == 1) cy--;
			if (dir == 3) cy++;
			cout << cx << " " << cy << '\n';
		}
        if (cx == x && cy == y) {
            return pasi;
        }
		if (s[i] == '-') dir++;
		if (s[i] == '+') dir--;
		if (dir < 0) dir = 3;
		dir = dir % 4;
	}

	return pasi;
}


int main(){
    int k;
    cin>>k>>x>>y;
    int x1=1,y1=1;
    int kon = hilbert(k, "A", 0);
    cout<<kon;
    return 0;
}
