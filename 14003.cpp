#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int A;
  std::cin >> A;

  std::vector<int> arr(A);
  for (int i = 0; i < A; i++) std::cin >> arr[i];

  std::vector<int> lis;
  std::vector<int> index(A);
  std::vector<int> prev(A, -1);

  int lastIdx = -1;

  for (int i = 0; i < A; i++) {
    auto pos = std::lower_bound(lis.begin(), lis.end(), arr[i]);
    int idx = pos - lis.begin();

    if (pos == lis.end()) {
      lis.push_back(arr[i]);
      lastIdx = i;
    } else {
      *pos = arr[i];
    }

    index[idx] = i;
    if (idx > 0) {
      prev[i] = index[idx - 1];
    }
  }

  std::vector<int> result;

  for (int i = lastIdx; i != -1; i = prev[i]) {
    result.push_back(arr[i]);
  }

  std::reverse(result.begin(), result.end());

  // answer
  std::cout << lis.size() << '\n';
  for (int num : result) {
    std::cout << num << " ";
  }
  std::cout << '\n';

  return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <vector>

// int main(void) {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(NULL);
//   std::cout.tie(NULL);

//   int A;
//   std::cin >> A;

//   std::vector<int> arr(A);
//   for (int i = 0; i < A; i++) std::cin >> arr[i];

//   std::vector<int> lis;
//   std::vector<int> lisIdx(A);
//   std::vector<int> prev(A, -1);

//   for (int i = 0; i < A; i++) {
//     auto pos = std::lower_bound(lis.begin(), lis.end(), arr[i]);
//     int idx = pos - lis.begin();

//     if (pos == lis.end()) {
//       lis.push_back(arr[i]);
//     } else {
//       *pos = arr[i];
//     }

//     lisIdx[i] = idx;
//     if (idx > 0) {
//       for (int j = i - 1; j >= 0; j--) {
//         if (lisIdx[j] == idx - 1 && arr[j] < arr[i]) {
//           prev[i] = j;
//           break;
//         }
//       }
//     }
//   }

//   int lisSize = lis.size();

//   std::vector<int> result(lisSize);
//   int lastIdx = -1;

//   for (int i = A - 1; i >= 0; i--) {
//     if (lisIdx[i] == lisSize - 1) {
//       lastIdx = i;
//       break;
//     }
//   }

//   for (int i = lisSize - 1; i >= 0; i--) {
//     result[i] = arr[lastIdx];
//     lastIdx = prev[lastIdx];
//   }

//   // answer
//   std::cout << lisSize << '\n';
//   for (int i = 0; i < lisSize; i++) {
//     std::cout << result[i] << " ";
//   }
//   std::cout << '\n';

//   return 0;
// }
