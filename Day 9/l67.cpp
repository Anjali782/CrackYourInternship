class Solution {
public:
string addBinary(string a, string b) {
  int m = a.size();
  int n = b.size();
  string ans;

  int i = m - 1, j = n - 1;
  int c = 0, ca, cb, s;

  while (i >= 0 and j >= 0) {
    ca = a[i] - '0', cb = b[j] - '0';
    s = c + ca + cb;
    if (s == 3) {
      c = 1;
      ans = '1' + ans;
    } else if (s == 2) {
      c = 1;
      ans = '0' + ans;
    } else if (s == 1) {
      c = 0;
      ans = '1' + ans;
    } else {
      c = 0;
      ans = '0' + ans;
    }

    --i, --j;
  }

  while (i >= 0) {
    ca = a[i] - '0';
    s = c + ca;
    if (s == 2) {
      c = 1;
      ans = '0' + ans;
    } else if (s == 1) {
      c = 0;
      ans = '1' + ans;
    } else {
      c = 0;
      ans = '0' + ans;
    }
    --i;
  }

  while (j >= 0) {
    ca = b[j] - '0';
    s = c + ca;
    if (s == 2) {
      c = 1;
      ans = '0' + ans;
    } else if (s == 1) {
      c = 0;
      ans = '1' + ans;
    } else {
      c = 0;
      ans = '0' + ans;
    }
    --j;
  }

  if (c)
    ans = '1' + ans;

  return ans;
}
};
