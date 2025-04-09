//
// Created by Damon on 2025/4/9.
//

#include "my_algorithms.h"

// 这类问题没办法从k向1进行递归，因为没办法确认 k - x 中的x是多少，所以考虑使用从小到大迭代的方法
// 需要额外关注的一点，如果在迭代的过程中，f(3)实际上作为迭代的基石，应该是等于3，而在函数的返回值方面，f(3)应该是要返回2
int CutRope(int k)
{
    if (k <= 1) { return 0; }
    if (k == 2) { return 1;}
    if (k == 3) { return 2; }
    std::vector<int> product;
    product.reserve(k + 1);
    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3;
    for (int i = 4; i <= k; i++) {
        int maxProduct = 0;
        for (int j = 1; j <i; j++) {
            maxProduct = std::max(maxProduct, (product[j] * product[i - j]));
        }
        product[i] = maxProduct;
    }
    return product[k];
}
