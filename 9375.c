#include <stdio.h>
#include <string.h>

int main(void) {
  int T;
  scanf("%d", &T);

  while (T--) {
    int n;
    scanf("%d", &n);

    char types[30][31] = {0};
    int counts[30] = {0};
    int typesCount = 0;

    for (int i = 0; i < n; i++) {
      char name[31], type[31];
      scanf("%s %s", name, type);

      int found = -1;
      for (int j = 0; j < typesCount; j++) {
        if (strcmp(types[j], type) == 0) {
          found = j;
          break;
        }
      }

      if (found == -1) {
        strcpy(types[typesCount], type);
        counts[typesCount] = 1;
        typesCount++;
      } else {
        counts[found]++;
      }
    }

    long long result = 1;
    for (int j = 0; j < typesCount; j++) {
      result *= (counts[j] + 1);
    }

    result -= 1;

    printf("%lld\n", result);
  }

  return 0;
}