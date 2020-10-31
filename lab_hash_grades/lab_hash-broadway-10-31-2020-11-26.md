---

This report was generated for **kjzhou2** using **2a8789d155056d37c7b11a356c00c26de4ebf4be** (latest commit as of **October 31st 2020, 11:26 am**)

---




## Score: 0/150 (0.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c hashes.cpp -o .objs/hashes.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c textfile.cpp -o .objs/textfile.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-dh.cpp -o .objs/tests/tests-dh.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-sc.cpp -o .objs/tests/tests-sc.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-lp.cpp -o .objs/tests/tests-lp.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/hashes.o .objs/textfile.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests-dh.o .objs/tests/tests-sc.o .objs/tests/tests-lp.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✗ - [0/6] - DH::testRemoveEASY

- **Points**: 0 / 6


```
FAIL: Insert did not work
```


### ✗ - [0/10] - DH::testRemoveHard

- **Points**: 0 / 10


```
FAIL: Insert did not work
```


### ✗ - [0/7] - DH::testResizeOnce

- **Points**: 0 / 7


```
Original: hashTable.tableSize() >= val / 0.7
Expanded: 17 >= 122.8571428571
```


### ✗ - [0/11] - DH::testResizeAll

- **Points**: 0 / 11


```
Original: hashTable.tableSize() >= strings.size() / 0.7
Expanded: 17 >= 37.1428571429
```


### ✗ - [0/6] - DH::testInsertEasy

- **Points**: 0 / 6


```
FAIL: Did not insert key: 'all'
```


### ✗ - [0/10] - DH::testInsertHard

- **Points**: 0 / 10


```
FAIL: Did not insert properly key: 'has'
```


### ✗ - [0/6] - SC::testRemoveEASY

- **Points**: 0 / 6


```
FAIL: Insert did not work
```


### ✗ - [0/10] - SC::testRemoveHard

- **Points**: 0 / 10


```
FAIL: Insert did not work
```


### ✗ - [0/7] - SC::testResizeOnce

- **Points**: 0 / 7


```
Original: hashTable.tableSize() >= val / 0.7
Expanded: 17 >= 122.8571428571
```


### ✗ - [0/11] - SC::testResizeAll

- **Points**: 0 / 11


```
Original: hashTable.tableSize() >= strings.size() / 0.7
Expanded: 17 >= 37.1428571429
```


### ✗ - [0/6] - SC::testInsertEasy

- **Points**: 0 / 6


```
FAIL: Did not insert key: 'all'
```


### ✗ - [0/10] - SC::testInsertHard

- **Points**: 0 / 10


```
FAIL: Did not insert properly key: 'has'
```


### ✗ - [0/6] - LP::testRemoveEASY

- **Points**: 0 / 6


```
FAIL: Insert did not work
```


### ✗ - [0/10] - LP::testRemoveHard

- **Points**: 0 / 10


```
FAIL: Insert did not work
```


### ✗ - [0/7] - LP::testResizeOnce

- **Points**: 0 / 7


```
Original: hashTable.tableSize() >= val / 0.7
Expanded: 17 >= 122.8571428571
```


### ✗ - [0/11] - LP::testResizeAll

- **Points**: 0 / 11


```
Original: hashTable.tableSize() >= strings.size() / 0.7
Expanded: 17 >= 37.1428571429
```


### ✗ - [0/6] - LP::testInsertEasy

- **Points**: 0 / 6


```
FAIL: Did not insert key: 'all'
```


### ✗ - [0/10] - LP::testInsertHard

- **Points**: 0 / 10


```
FAIL: Did not insert properly key: 'has'
```


---