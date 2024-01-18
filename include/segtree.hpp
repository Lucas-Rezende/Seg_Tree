#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include "matrix.hpp"

class segtree
{
private:
    Matrix* v;
    Matrix* seg;
    int MAX;
public:
    segtree(int max_size);
    ~segtree();

    /**
     * Constrói a árvore de segmentos.
     *
     * @param p O índice da árvore de segmentos.
     * @param l O valor esquerdo do intervalo.
     * @param r O valor direito do intervalo.
     *
     * @return A matriz construída.
     */
    Matrix buildTree(int p, int l, int r);

    /**
     * Multiplica duas matrizes.
     *
     * @param a A primeira matriz.
     * @param b A segunda matriz.
     *
     * @return O resultado da multiplicação das matrizes.
     */
    Matrix multiplyMatrices(Matrix a, Matrix b);

    /**
     * Consulta a árvore de segmentos.
     *
     * @param a O valor esquerdo do intervalo de consulta.
     * @param b O valor direito do intervalo de consulta.
     * @param p O índice da árvore de segmentos.
     * @param l O valor esquerdo do intervalo.
     * @param r O valor direito do intervalo.
     *
     * @return A matriz resultante da consulta.
     */
    Matrix query(int a, int b, int p, int l, int r);

    /**
     * Atualiza a árvore de segmentos.
     *
     * @param i O índice do elemento a ser atualizado.
     * @param x A nova matriz.
     * @param p O índice da árvore de segmentos.
     * @param l O valor esquerdo do intervalo.
     * @param r O valor direito do intervalo.
     *
     * @return A matriz atualizada.
     */
    Matrix update(int i, const Matrix &x, int p, int l, int r);
};

#endif