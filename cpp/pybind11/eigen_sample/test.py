import cppimport
import numpy as np
import timeit

code = cppimport.imp("code")

if __name__ == '__main__':
    A = np.array([[1,2,1],
                  [2,1,0],
                  [-1,1,2]])

    print(A)
    print(code.det(A))
    print(code.inv(A))
    NUMBER=1000
    CODES="\
import cppimport;\
import numpy as np;\
code = cppimport.imp('code');\
v = np.ones(100000, dtype=np.float64);\
code.scale_by_2_1(v)\
"
    print(timeit.timeit(CODES, number=NUMBER)/NUMBER)
    CODES="\
import cppimport;\
import numpy as np;\
code = cppimport.imp('code');\
v = np.ones(100000, dtype=np.float64);\
code.scale_by_2_2(v)\
"
    print(timeit.timeit(CODES, number=NUMBER)/NUMBER)
    CODES="\
import cppimport;\
import numpy as np;\
code = cppimport.imp('code');\
v = np.ones(100000, dtype=np.float64);\
code.scale_by_2_3(v)\
"
    print(timeit.timeit(CODES, number=NUMBER)/NUMBER)

