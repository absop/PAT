#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define swap2(a, b) ({elem_t tmp = a; a = b; b = tmp;})
#define swap3(a, b, c) ({elem_t tmp = a; a = b; b = c; c = tmp;})

elem_t selectpivot(elem_t v[], int lo, int hi )
{
    int mi = (lo + hi) >> 1;

    if (v[lo] < v[mi])
        swap2(v[lo], v[mi]);

    if (v[hi] < v[lo]) {
        if (v[hi] < v[mi])
            swap3(v[hi], v[lo], v[mi]);
        else
            swap2(v[hi], v[lo]);
    }
    return v[lo];
}

elem_t selectnth(elem_t v[], int lo, int hi, int nth)
{
    if (hi - lo < 2) {
        if (lo == hi)return v[lo];
        if (nth == 1)
            return min(v[lo], v[hi]);
        return max(v[lo], v[hi]);

    }
    // pivot == v[lo] < v[hi]
    int i = lo, j = hi, k;
    elem_t pivot = selectpivot(v, lo, hi);
    while (1) {
        while (v[++i] < pivot);
        while (pivot < v[--j]);
        if (i >= j) break;
        swap2(v[i], v[j]);
    }
    swap2(v[lo], v[j]);

    k = j - lo + 1;
    if (nth < k)return selectnth(v, lo, j - 1, nth);
    if (nth > k)return selectnth(v, j + 1, hi, nth - k);
    return v[j];
}

elem_t Median( elem_t A[], int N )
{
    return selectnth(A, 0, N - 1, N / 2 + 1);
}
