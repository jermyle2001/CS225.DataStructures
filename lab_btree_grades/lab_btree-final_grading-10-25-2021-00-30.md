---

This report was generated for **jeremyl6** using **41258457a2016753b669d18caae320876057d729** (latest commit as of **October 24th 2021, 11:59 pm**)

---




## Score: 50/55 (90.91%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests.cpp -o .objs/tests/tests.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests.o .objs/cs225/catch/catchmain.o  -std=c++14 -stdlib=libc++ -lc++abi -o test

```


### ✓ - [5/5] - test_insertion_idx_emp

- **Points**: 5 / 5





### ✓ - [5/5] - test_insertion_idx_small

- **Points**: 5 / 5





### ✗ - [0/5] - test_btree3_small

- **Points**: 0 / 5

```
==62== Memcheck, a memory error detector
==62== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==62== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==62== Command: ./test -r xml "test_btree3_small"
==62== 
==62== Conditional jump or move depends on uninitialised value(s)
==62==    at 0x43487F: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:48)
==62==    by 0x42B430: BTree<int, int>::find(int const&) const (btree.cpp:16)
==62==    by 0x42B0CC: void verify_finds<int, int>(std::__1::vector<std::__1::pair<int, int>, std::__1::allocator<std::__1::pair<int, int> > >&, BTree<int, int>&) (tests.cpp:44)
==62==    by 0x42425F: ____C_A_T_C_H____T_E_S_T____4() (tests.cpp:106)
==62==    by 0x486C32: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==62==    by 0x477386: Catch::TestCase::invoke() const (catch.hpp:10793)
==62==    by 0x4772BC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==62==    by 0x473816: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==62==    by 0x471DEE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==62==    by 0x47B186: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==62==    by 0x479E22: Catch::Session::runInternal() (catch.hpp:10149)
==62==    by 0x479AEA: Catch::Session::run() (catch.hpp:10106)
==62== 
==62== Conditional jump or move depends on uninitialised value(s)
==62==    at 0x43487F: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:48)
==62==    by 0x434930: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:54)
==62==    by 0x42B430: BTree<int, int>::find(int const&) const (btree.cpp:16)
==62==    by 0x42B0CC: void verify_finds<int, int>(std::__1::vector<std::__1::pair<int, int>, std::__1::allocator<std::__1::pair<int, int> > >&, BTree<int, int>&) (tests.cpp:44)
==62==    by 0x42425F: ____C_A_T_C_H____T_E_S_T____4() (tests.cpp:106)
==62==    by 0x486C32: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==62==    by 0x477386: Catch::TestCase::invoke() const (catch.hpp:10793)
==62==    by 0x4772BC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==62==    by 0x473816: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==62==    by 0x471DEE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==62==    by 0x47B186: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==62==    by 0x479E22: Catch::Session::runInternal() (catch.hpp:10149)
==62== 
==62== 
==62== HEAP SUMMARY:
==62==     in use at exit: 0 bytes in 0 blocks
==62==   total heap usage: 1,794 allocs, 1,794 frees, 226,416 bytes allocated
==62== 
==62== All heap blocks were freed -- no leaks are possible
==62== 
==62== For counts of detected and suppressed errors, rerun with: -v
==62== Use --track-origins=yes to see where uninitialised values come from
==62== ERROR SUMMARY: 5 errors from 2 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - test_btree3_large_seq

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree3_large_rand

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree64_large_seq

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree64_large_rand

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree128_med_rand

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree256_med_rand

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree12_double

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree12_strings

- **Points**: 5 / 5





---