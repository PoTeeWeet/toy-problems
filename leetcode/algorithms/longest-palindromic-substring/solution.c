#include <stdio.h>
#include <string.h>

char*  longestPalindrome(char* s) {

  int N = strlen(s);
  if (N == 0) {
    return s;
  }
  int CRP, CLP, currLP = 0;
  int CP = 1;
  int L[2*N];
  L[0] = 0;
  L[1] = 1;
  int largest = 1;
  for (int currRP = 2; currRP < 2*N; currRP++) {
    // case 1 and 2

    currLP = 2*CP - currRP;
    if ((L[currLP] < CRP - currRP) || (L[currLP] == CRP - currRP && CRP == 2*N)) {
      L[currRP] = L[currLP];
    }
    // case 3 and 4
    else {
      int val = L[currLP];
      int i_right = (currLP/2)+(L[currLP]/2);
      int i_left = (currLP/2)-(L[currLP]/2);
      while (i_right < N && i_left >= 0 && s[i_right++] == s[i_left--] ) {
        val++;
      }
      L[currRP] = val;
    }
    int CRP_this = currRP + L[currRP];
    if (CRP_this > CRP) {
      CRP = CRP_this;
      CP = currRP;
    }
    if (L[currRP] > L[largest]) {
      largest = currRP;
    }
  }
  int i = L[largest];
  int i_left = (L[largest] / 2) - i/2;
  char result[i+1];
  strncpy(result, s+i_left, i);
  result[i] = '\0';
  return result;
}

int main()
{
  char *test = "babbabbb";
  printf("%s\n", longestPalindrome(test));
  return 0;
}
