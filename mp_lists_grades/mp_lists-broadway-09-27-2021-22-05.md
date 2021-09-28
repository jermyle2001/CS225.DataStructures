


## Score: 39/109 (35.78%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1.cpp -o .objs/tests/tests_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part2.cpp -o .objs/tests/tests_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part2_extra.cpp -o .objs/tests/test_part2_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1_extra.cpp -o .objs/tests/tests_part1_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests_part1.o .objs/tests/tests_part2.o .objs/tests/test_part2_extra.o .objs/tests/tests_part1_extra.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - List::insertFront size

- **Points**: 1 / 1

```
==86== Memcheck, a memory error detector
==86== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==86== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==86== Command: ./test -r xml "List::insertFront\ size"
==86== 
==86== 
==86== HEAP SUMMARY:
==86==     in use at exit: 0 bytes in 0 blocks
==86==   total heap usage: 2,347 allocs, 2,347 frees, 268,272 bytes allocated
==86== 
==86== All heap blocks were freed -- no leaks are possible
==86== 
==86== For counts of detected and suppressed errors, rerun with: -v
==86== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::insertBack size

- **Points**: 2 / 2

```
==88== Memcheck, a memory error detector
==88== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==88== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==88== Command: ./test -r xml "List::insertBack\ size"
==88== 
==88== 
==88== HEAP SUMMARY:
==88==     in use at exit: 0 bytes in 0 blocks
==88==   total heap usage: 2,347 allocs, 2,347 frees, 268,272 bytes allocated
==88== 
==88== All heap blocks were freed -- no leaks are possible
==88== 
==88== For counts of detected and suppressed errors, rerun with: -v
==88== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents

- **Points**: 4 / 4

```
==90== Memcheck, a memory error detector
==90== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==90== Command: ./test -r xml "List::insert\ contents"
==90== 
==90== 
==90== HEAP SUMMARY:
==90==     in use at exit: 0 bytes in 0 blocks
==90==   total heap usage: 2,343 allocs, 2,343 frees, 268,176 bytes allocated
==90== 
==90== All heap blocks were freed -- no leaks are possible
==90== 
==90== For counts of detected and suppressed errors, rerun with: -v
==90== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::triplerotate basic

- **Points**: 5 / 5

```
==92== Memcheck, a memory error detector
==92== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==92== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==92== Command: ./test -r xml "List::triplerotate\ basic"
==92== 
==92== 
==92== HEAP SUMMARY:
==92==     in use at exit: 0 bytes in 0 blocks
==92==   total heap usage: 2,351 allocs, 2,351 frees, 268,464 bytes allocated
==92== 
==92== All heap blocks were freed -- no leaks are possible
==92== 
==92== For counts of detected and suppressed errors, rerun with: -v
==92== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/10] - List::triplerotate simple

- **Points**: 0 / 10


```
Original: "< 2 3 1 5 6 4 >" == s.str()
Expanded: "< 2 3 1 5 6 4 >" == "< 2 3 4 5 1 6 >"
```


### ✓ - [5/5] - List::split simple

- **Points**: 5 / 5

```
==95== Memcheck, a memory error detector
==95== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==95== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==95== Command: ./test -r xml "List::split\ simple"
==95== 
==95== 
==95== HEAP SUMMARY:
==95==     in use at exit: 0 bytes in 0 blocks
==95==   total heap usage: 2,205 allocs, 2,205 frees, 263,744 bytes allocated
==95== 
==95== All heap blocks were freed -- no leaks are possible
==95== 
==95== For counts of detected and suppressed errors, rerun with: -v
==95== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split images

- **Points**: 5 / 5





### ✓ - [3/3] - List::_destroy empty list

- **Points**: 3 / 3

```
==98== Memcheck, a memory error detector
==98== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==98== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==98== Command: ./test -r xml "List::_destroy\ empty\ list"
==98== 
==98== 
==98== HEAP SUMMARY:
==98==     in use at exit: 0 bytes in 0 blocks
==98==   total heap usage: 2,355 allocs, 2,355 frees, 269,104 bytes allocated
==98== 
==98== All heap blocks were freed -- no leaks are possible
==98== 
==98== For counts of detected and suppressed errors, rerun with: -v
==98== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::begin() returns an iterator to the front of the list

- **Points**: 1 / 1

```
==100== Memcheck, a memory error detector
==100== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==100== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==100== Command: ./test -r xml "List::begin()\ returns\ an\ iterator\ to\ the\ front\ of\ the\ list"
==100== 
==100== 
==100== HEAP SUMMARY:
==100==     in use at exit: 0 bytes in 0 blocks
==100==   total heap usage: 2,359 allocs, 2,359 frees, 273,440 bytes allocated
==100== 
==100== All heap blocks were freed -- no leaks are possible
==100== 
==100== For counts of detected and suppressed errors, rerun with: -v
==100== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (pre-increment)

- **Points**: 1 / 1

```
==102== Memcheck, a memory error detector
==102== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==102== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==102== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (pre-increment)"
==102== 
==102== 
==102== HEAP SUMMARY:
==102==     in use at exit: 0 bytes in 0 blocks
==102==   total heap usage: 2,359 allocs, 2,359 frees, 275,840 bytes allocated
==102== 
==102== All heap blocks were freed -- no leaks are possible
==102== 
==102== For counts of detected and suppressed errors, rerun with: -v
==102== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (post-increment)

- **Points**: 1 / 1

```
==104== Memcheck, a memory error detector
==104== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==104== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==104== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (post-increment)"
==104== 
==104== 
==104== HEAP SUMMARY:
==104==     in use at exit: 0 bytes in 0 blocks
==104==   total heap usage: 2,359 allocs, 2,359 frees, 275,840 bytes allocated
==104== 
==104== All heap blocks were freed -- no leaks are possible
==104== 
==104== For counts of detected and suppressed errors, rerun with: -v
==104== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==106== Memcheck, a memory error detector
==106== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==106== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==106== Command: ./test -r xml "List::ListIterator::operator++\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==106== 
==106== 
==106== HEAP SUMMARY:
==106==     in use at exit: 0 bytes in 0 blocks
==106==   total heap usage: 2,359 allocs, 2,359 frees, 278,240 bytes allocated
==106== 
==106== All heap blocks were freed -- no leaks are possible
==106== 
==106== For counts of detected and suppressed errors, rerun with: -v
==106== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- moves the iterator backwards

- **Points**: 1 / 1

```
==108== Memcheck, a memory error detector
==108== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==108== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==108== Command: ./test -r xml "List::ListIterator::operator--\ moves\ the\ iterator\ backwards"
==108== 
==108== 
==108== HEAP SUMMARY:
==108==     in use at exit: 0 bytes in 0 blocks
==108==   total heap usage: 2,359 allocs, 2,359 frees, 273,440 bytes allocated
==108== 
==108== All heap blocks were freed -- no leaks are possible
==108== 
==108== For counts of detected and suppressed errors, rerun with: -v
==108== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==110== Memcheck, a memory error detector
==110== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==110== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==110== Command: ./test -r xml "List::ListIterator::operator--\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==110== 
==110== 
==110== HEAP SUMMARY:
==110==     in use at exit: 0 bytes in 0 blocks
==110==   total heap usage: 2,359 allocs, 2,359 frees, 278,240 bytes allocated
==110== 
==110== All heap blocks were freed -- no leaks are possible
==110== 
==110== For counts of detected and suppressed errors, rerun with: -v
==110== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is reached

- **Points**: 1 / 1

```
==112== Memcheck, a memory error detector
==112== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==112== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==112== Command: ./test -r xml "List::ListIterator::end\ is\ reached"
==112== 
==112== 
==112== HEAP SUMMARY:
==112==     in use at exit: 0 bytes in 0 blocks
==112==   total heap usage: 2,352 allocs, 2,352 frees, 270,872 bytes allocated
==112== 
==112== All heap blocks were freed -- no leaks are possible
==112== 
==112== For counts of detected and suppressed errors, rerun with: -v
==112== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is not ::begin in a non-empty list

- **Points**: 1 / 1

```
==114== Memcheck, a memory error detector
==114== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==114== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==114== Command: ./test -r xml "List::ListIterator::end\ is\ not\ ::begin\ in\ a\ non-empty\ list"
==114== 
==114== 
==114== HEAP SUMMARY:
==114==     in use at exit: 0 bytes in 0 blocks
==114==   total heap usage: 2,352 allocs, 2,352 frees, 273,272 bytes allocated
==114== 
==114== All heap blocks were freed -- no leaks are possible
==114== 
==114== For counts of detected and suppressed errors, rerun with: -v
==114== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - List::reverse

- **Points**: 0 / 5


```
Original: out == expected
Expanded: PNG(w=900, h=600, hash=3fa66744920ffb90)
==
PNG(w=900, h=600, hash=3fa66744920ffb90)
```


### ✗ - [0/5] - List::reverseNth #1

- **Points**: 0 / 5


```
Original: out == expected
Expanded: PNG(w=900, h=600, hash=3fa66744920ffb90)
==
PNG(w=900, h=600, hash=3fa66744920ffb90)
```


### ✗ - [0/5] - List::reverseNth #2

- **Points**: 0 / 5


```
Original: out == expected
Expanded: PNG(w=900, h=600, hash=3fa66744920ffb90)
==
PNG(w=900, h=600, hash=3fa66744920ffb90)
```


### ✗ - [0/10] - List::merge

- **Points**: 0 / 10


```
Original: out == expected
Expanded: PNG(w=600, h=400, hash=0)
==
PNG(w=600, h=400, hash=0)
```


### ✗ - [0/2] - List::sort simple #1

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/2] - List::sort simple #2

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/5] - List::sort #1

- **Points**: 0 / 5


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/5] - List::sort #2

- **Points**: 0 / 5


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/4] - List::reverse simple

- **Points**: 0 / 4


```
Original: "< 4 12 -1 99 3 >" == s.str()
Expanded: "< 4 12 -1 99 3 >" == "< 3 99 -1 12 4 >"
```


### ✓ - [2/2] - List::reverse edge cases

- **Points**: 2 / 2

```
==125== Memcheck, a memory error detector
==125== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==125== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==125== Command: ./test -r xml "List::reverse\ edge\ cases"
==125== 
==125== 
==125== HEAP SUMMARY:
==125==     in use at exit: 0 bytes in 0 blocks
==125==   total heap usage: 2,353 allocs, 2,353 frees, 268,552 bytes allocated
==125== 
==125== All heap blocks were freed -- no leaks are possible
==125== 
==125== For counts of detected and suppressed errors, rerun with: -v
==125== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - List::reverseNth #3

- **Points**: 0 / 5


```
Original: "< 4 3 2 1 8 7 6 5 10 9 >" == s.str()
Expanded: "< 4 3 2 1 8 7 6 5 10 9 >"
==
"< 1 2 3 4 5 6 7 8 9 10 >"
```


### ✗ - [0/5] - List::merge #2

- **Points**: 0 / 5


```
Original: "< 1 2 10 15 20 30 35 40 45 50 55 65 75 100 200 300 400 500 >" == s1.str()
Expanded: "< 1 2 10 15 20 30 35 40 45 50 55 65 75 100 200 300 400 500 >"
==
"< >"
```


### ✗ - [0/2] - List::sort simple #3

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✓ - [4/4] - List::insert contents #2

- **Points**: 4 / 4

```
==130== Memcheck, a memory error detector
==130== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==130== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==130== Command: ./test -r xml "List::insert\ contents\ #2"
==130== 
==130== 
==130== HEAP SUMMARY:
==130==     in use at exit: 0 bytes in 0 blocks
==130==   total heap usage: 2,358 allocs, 2,358 frees, 268,672 bytes allocated
==130== 
==130== All heap blocks were freed -- no leaks are possible
==130== 
==130== For counts of detected and suppressed errors, rerun with: -v
==130== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - List::split edge cases

- **Points**: 0 / 5


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


---

This report was generated for **jeremyl6** using **6019f20486ddead4accacfd15b77a922b91580d7** (latest commit as of **September 27th 2021, 10:05 pm**)
