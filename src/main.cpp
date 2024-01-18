#include <iostream>
#include "segtree.hpp"
#include "matrix.hpp"

int main()
{
    int size = 0;
    int qnt_op = 0;
    std::cin >> size;
    std::cin >> qnt_op;

    segtree st(size);

    st.buildTree(1, 0, size - 1);

    for (int i = 0; i < qnt_op; i++)
    {
        char op;
        std::cin >> op;

        if (op == 'u')
        {
            int x;
            Matrix m;
            std::cin >> x;
            for (int j = 0; j < 2; ++j)
            {
                for (int k = 0; k < 2; ++k)
                {
                    int val;
                    std::cin >> val;
                    m.set(j, k, val);
                }
            }
            st.update(x, m, 1, 0, size - 1);
        }
        else if (op == 'q')
        {
            int t0, td, t1, t2;
            std::cin >> t0 >> td >> t1 >> t2;
            Matrix result = st.query(t0, td, 1, 0, size - 1);
            Matrix aux;
            aux.set(0, 0, t1);
            aux.set(1, 0, t2);
            aux.set(0, 1, 0);
            aux.set(1, 1, 0);
            Matrix temp = result * aux;
            std::cout << temp.get(0, 0) % 100000000 << ' ';
            std::cout << temp.get(1, 0) % 100000000 << std::endl;
        }
        else
        {
            // Operação desconhecida
            std::cerr << "Operação desconhecida." << std::endl;
            std::cerr << "Use 'q' para query e 'u' para update." << std::endl;
            return 1;
        }
    }

    return 0;
}