---

This report was generated for **jeremyl6** using **6e36d975a423d61fae938af283446d2e7f8784a9** (latest commit as of **November 15th 2021, 11:59 pm**)

---




## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
maze.cpp:12:13: fatal error: 'SquareMaze' is missing exception specification 'noexcept'
SquareMaze::SquareMaze()
            ^
                         noexcept
./maze.h:13:7: note: previous declaration is here
class SquareMaze
      ^
1 error generated.
make: *** [.objs/maze.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c dsets.cpp -o .objs/dsets.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c maze.cpp -o .objs/maze.o

```


---