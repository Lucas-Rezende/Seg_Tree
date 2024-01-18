#include "segtree.hpp"

segtree::segtree(int max_size)
{
    MAX = max_size;
    v = new Matrix[MAX];
    seg = new Matrix[4*MAX];

    for (int i = 0; i < MAX; i++)
    {
        v[i] = Matrix();
    }
    for (int i = 0; i < 4 * MAX; i++)
    {
        seg[i] = Matrix();
    }
}

segtree::~segtree()
{
    delete[] v;
    delete[] seg;
}

Matrix segtree::buildTree(int p, int l, int r)
{
    if (l == r)
    {
        return seg[p] = v[l];
    }
    int m = (l + r) / 2;
    return seg[p] = segtree::multiplyMatrices(buildTree(2 * p, l, m), buildTree(2 * p + 1, m + 1, r));
}

Matrix segtree::multiplyMatrices(Matrix a, Matrix b)
{
    return a * b;
}

Matrix segtree::query(int a, int b, int p, int l, int r)
{
    if (b < l || r < a)
    {
        return Matrix();
    }
    if (l >= a && r <= b)
    {
        return seg[p];
    }
    int m = (l + r) / 2;
    return query(a, b, 2 * p, l, m) * query(a, b, 2 * p + 1, m + 1, r);
}

Matrix segtree::update(int i, const Matrix &x, int p, int l, int r)
{
    if (i < l || r < i)
    {
        return seg[p];
    }
    if (l == r)
    {
        return seg[p] = x;
    }
    int m = (l + r) / 2;
    return seg[p] = segtree::multiplyMatrices(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}