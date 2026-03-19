#include <stdio.h>
#include <string.h>

int x,y,cx=1,cy=1;

int hilbert(int iter, char *s, int dir) {
	int pasi = 0;

	for (int i = 0; i < strlen(s); i++) {
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
			printf("%d %d\n",cx,cy);
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
    scanf("%d %d %d",&k,&x,&y);
    int x1=1,y1=1;
    int kon = hilbert(k, "A", 0);
    printf("%d",kon);
    return 0;
}
