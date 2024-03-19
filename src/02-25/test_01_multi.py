'''
Author: larry combofish@163.com
Date: 2024-03-02 21:18:59
LastEditors: larry combofish@163.com
LastEditTime: 2024-03-02 21:25:57
FilePath: /code-write/src/02-25/test_01_multi.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
from icecream import ic
import numpy as np
from sklearn.manifold import TSNE

# TSNE.
# TSNE.fit_transform(x)

def main():
    a = np.arange(1, 10).reshape(3,3)
    a = np.expand_dims(a, 0)
    
    ic(a.shape, a)
    
    b = a * 2
    ic(b.shape, b)
    
    c = np.array([2,1,1]).reshape(3, 1)
    c = np.expand_dims(c, 0)
    
    ic(c.shape, c)
    
    d = a @ c
    e = np.matmul(a, c)
    
    ic(d.shape, d)
    ic(e.shape, e)
    
    
if __name__ == '__main__':
    main()