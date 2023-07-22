#include <iostream>
#include <vector>
using namespace std;

int X, Y, N;//maximum direction of crystal,no of times blow wind over the crystal
vector<vector<char>> g;//vector
vector<int> wm, wn;//direction of wind

void doit(int x, int y) {
  char ch = (x >= 1 && x <= X && y >= 1 && y <= Y ? g[y][x] : '.');//small x and y starting position
  if (!ch) return;
  for (int i = 0; i < N; i++) {
    int x2 = x + (ch == '.' ? wm[i] : -wm[i]);//new position x2,y2
    int y2 = y + (ch == '.' ? wn[i] : -wn[i]);
    if (x2 >= 1 && x2 <= X && y2 >= 1 && y2 <= Y && !g[y2][x2]) {
      g[y2][x2] = ch;
      doit(x2, y2);//doit function
    }
  }
}

int main() {
  while (cin >> X >> Y >> N) {
    g = vector<vector<char>>(Y+1, vector<char>(X+1));
    wm = wn = vector<int>(N);
    for (int i = 0; i < N; i++) {
      int B, x, y;//boundary
      cin >> wm[i] >> wn[i] >> B;
      for (int j = 0; j < B; j++) {
        cin >> x >> y;
        g[y][x] = '#';
        int x2 = x-wm[i], y2 = y-wn[i];//mlecule not exists
        if (x2 >= 1 && x2 <= X && y2 >= 1 && y2 <= Y) g[y2][x2] = '.';
      }
    }
    for (int y = -Y; y <= 2*Y; y++) for (int x = -X; x <= 2*X; x++) doit(x, y);

    for (int y = 1; y <= Y; y++) {
      for (int x = 1; x <= X; x++) cout << (g[y][x] ? g[y][x] : '.');
      cout << endl;
    }
    cout << endl;
    for (int y = 1; y <= Y; y++) {
      for (int x = 1; x <= X; x++) cout << (g[y][x] ? g[y][x] : '#');
      cout << endl;
    }
  }
}


/*
6 6 3
1 1 3 3 1 1 3 2 2
0 2 6 3 1 1 3 2 2 6 4 5 3 4 2
1 -1 4 1 3 2 4 3 5 4 6*/
