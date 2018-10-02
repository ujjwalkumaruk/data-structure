#include <stdio.h>

void tower_of_hanoi (int N, char A, char C, char B) {
  if (N == 0)
    return;
  tower_of_hanoi (N - 1, A, B, C);
  printf("moving disk from %c to %c\n", A, C);
  tower_of_hanoi (N - 1, B, C, A);
}

int main() {
  int N;
  scanf("%d", &N);
  tower_of_hanoi(N, 'A', 'C', 'B');
  return 0;
}