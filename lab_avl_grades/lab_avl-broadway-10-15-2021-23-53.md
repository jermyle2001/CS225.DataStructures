


## Score: 0/50 (0.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c coloredout.cpp -o .objs/coloredout.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests.cpp -o .objs/tests/tests.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/coloredout.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests.o .objs/cs225/catch/catchmain.o  -std=c++14 -stdlib=libc++ -lc++abi -o test

```


### ✗ - [0/10] - test_find

- **Points**: 0 / 10


```
Original: tree.find("C").compare("C++") == 0
Expanded: -1 == 0
```


### ✗ - [0/5] - test_insert_small

- **Points**: 0 / 5


```
Original: solnPreorderTraversal == preorderTraversal
Expanded: { 4, 1, 5 } == { 5, 4 }
```


### ✗ - [0/10] - test_insert_find

- **Points**: 0 / 10


```
Original: solnPreorderTraversal == preorderTraversal
Expanded: { 3, 1, 0, 2, 5, 8 } == { 1, 0, 3, 2 }
```


### ✗ - [0/10] - test_insert_big

- **Points**: 0 / 10


```
Original: solnFuncCalls == funcCalls
Expanded: { "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeft", "rotateLeft", "rotateLeft", "rotateLeft" }
==
{ "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeft", "rotateLeft", "rotateLeft" }
```


### ✗ - [0/5] - test_remove_small

- **Points**: 0 / 5


```
Original: solnFuncCalls == funcCalls
Expanded: { "rotateLeftRight", "rotateLeft", "rotateRight", "rotateLeft" }
==
{ "rotateLeftRight", "rotateLeft", "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft" }
```


### ✗ - [0/10] - test_remove_big

- **Points**: 0 / 10


```
Original: solnFuncCalls == funcCalls
Expanded: { "rotateRight", "rotateRight", "rotateRight", "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeft", "rotateLeftRight", "rotateLeft", "rotateRight", "rotateRight", "rotateLeft" }
==
{ "rotateRight", "rotateLeft", "rotateRight", "rotateLeft", "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateRight", "rotateRight", "rotateLeft", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateRight", "rotateLeftRight", "rotateLeft", "rotateRight", "rotateLeft", "rotateRight", "rotateLeftRight", "rotateLeft", "rotateRight" }
```


---

This report was generated for **jeremyl6** using **b83d70cd7cb27337765a74c2339c7150bda86bf0** (latest commit as of **October 15th 2021, 11:54 pm**)
