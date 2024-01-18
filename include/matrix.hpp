#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
private:
    // Matriz 2x2
    int mat[2][2];

public:
    // Construtor padrão
    Matrix();

    /**
     * Obtém o valor do elemento na posição (i, j) da matriz.
     *
     * @param i Índice da linha.
     * @param j Índice da coluna.
     * @return Valor do elemento na posição (i, j).
     */
    int get(int i, int j) const;

    /**
     * Define o valor do elemento na posição (i, j) da matriz.
     *
     * @param i Índice da linha.
     * @param j Índice da coluna.
     * @param val Novo valor a ser atribuído.
     */
    void set(int i, int j, int val);

    /**
     * Multiplica a matriz atual por outra matriz.
     *
     * @param other Matriz a ser multiplicada.
     * @return Matriz resultante da multiplicação.
     */
    Matrix operator*(const Matrix& other) const;
};

#endif