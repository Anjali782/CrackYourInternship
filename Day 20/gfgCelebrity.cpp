bool knows(int a, int b) {
  return MATRIX[a][b]; 
}

int findPotentialCelebrity(int n)
{
    if (n == 0)
        return -1;
    int id = findPotentialCelebrity(n - 1);
    if (id == -1)
        return n - 1;
    else if (knows(id, n - 1)) {
        return n - 1;
    }
    else if (knows(n - 1, id)) {
        return id;
    }
    return -1;
}
int Celebrity(int n)
{
    int id = findPotentialCelebrity(n);
 
    if (id == -1)
        return id;
    else {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
            if (i != id) {
                c1 += knows(id, i);
                c2 += knows(i, id);
            }
        if (c1 == 0 && c2 == n - 1)
            return id;
 
        return -1;
    }
}
