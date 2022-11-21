#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>
#include<math.h>

bool is_vowel(char c);
bool is_prime(int x);
void test();

int main(void)
{
  test();

  int cnt=1;
  for (int i='a'; i<='z'; i++){
    for (int j='a'; j<='z'; j++){
      for (int k='a'; k<='z'; k++){
        bool ik_same = i == k;
        bool ij_vowel_diff = is_vowel(i) != is_vowel(j);
        bool sum_is_prime = is_prime((i - 'a' + 1) + (j - 'a' + 1) + (k - 'a' + 1));
        if (ik_same && ij_vowel_diff && sum_is_prime){
          printf("%2i %c%c%c\n", cnt, i, j, k);
          cnt += 1;
        }
      }
    }
  }
  return 0;
}


bool is_vowel(char x)
{
  if (tolower(x) == 'a' || tolower(x) == 'e' || tolower(x) == 'i' || tolower(x) == 'o' || tolower(x) == 'u'){
    return true;
  }
  else{
    return false;
  }
}

bool is_prime(int x)
{
  bool is_prime = true;
  for (int i=2; i<x; i++){
    if (x%i == 0){
      is_prime = false;
    }
  }
  return is_prime;
}

void test()
{
  assert(is_vowel('a') == true);
  assert(is_vowel('e') == true);
  assert(is_vowel('i') == true);
  assert(is_vowel('c') == false);
  assert(is_vowel('A') == true);
  assert(is_vowel('E') == true);
  assert(is_vowel('I') == true);
  assert(is_vowel('C') == false);
  assert(is_prime(2) == true);
  assert(is_prime(3) == true);
  assert(is_prime(5) == true);
  assert(is_prime(10) == false);
}
