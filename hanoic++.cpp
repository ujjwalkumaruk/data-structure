#include <bits/stdc++.>
void toh(int N, char A, char C, char B) {
  if (N == 0)
    return;
  toh(N - 1, A, B, C);
  cout<<"moving disk from to :\n"<<A<<C;
  toh(N - 1, B, C, A);
}

int main() {
  int N;
  cin>>N;
  toh(N, 'A', 'C', 'B');
  return 0;
}