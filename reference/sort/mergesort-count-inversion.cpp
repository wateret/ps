#define INF 123456789

int merge(int A[], int l, int m, int r)
{
  int cinv = 0;
  int cl = m-l+1;
  int cr = r-m;

  int L[cl+1], R[cr+1];
  for (int i = 0; i < cl; i++) L[i] = A[l+i];
  for (int i = 0; i < cr; i++) R[i] = A[m+1+i];
  L[cl] = INF;
  R[cr] = INF;

  int il = 0, ir = 0, ix = l;
  while (ix <= r) {
    if (L[il] > R[ir]) {
      A[ix] = R[ir];
      ir++;
      cinv += m+1-(l+il);
    } else {
      A[ix] = L[il];
      il++;
    }
    ix++;
  }
  return cinv;
}

// Count Inversion while merge sort
int mergeSort(int A[], int l, int r)
{
  int cinv = 0;
  if (l < r)
  {
    int m = (l+r)/2;
    cinv += mergeSort(A, l, m);
    cinv += mergeSort(A, m+1, r);
    cinv += merge(A, l, m, r);
  }
  return cinv;
}
