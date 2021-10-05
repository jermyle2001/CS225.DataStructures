


## Score: 102/109 (93.58%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1.cpp -o .objs/tests/tests_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part2_extra.cpp -o .objs/tests/test_part2_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part2.cpp -o .objs/tests/tests_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1_extra.cpp -o .objs/tests/tests_part1_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests_part1.o .objs/tests/test_part2_extra.o .objs/tests/tests_part2.o .objs/tests/tests_part1_extra.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - List::insertFront size

- **Points**: 1 / 1

```
==87== Memcheck, a memory error detector
==87== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==87== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==87== Command: ./test -r xml "List::insertFront\ size"
==87== 
==87== 
==87== HEAP SUMMARY:
==87==     in use at exit: 0 bytes in 0 blocks
==87==   total heap usage: 2,347 allocs, 2,347 frees, 268,272 bytes allocated
==87== 
==87== All heap blocks were freed -- no leaks are possible
==87== 
==87== For counts of detected and suppressed errors, rerun with: -v
==87== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::insertBack size

- **Points**: 2 / 2

```
==89== Memcheck, a memory error detector
==89== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==89== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==89== Command: ./test -r xml "List::insertBack\ size"
==89== 
==89== 
==89== HEAP SUMMARY:
==89==     in use at exit: 0 bytes in 0 blocks
==89==   total heap usage: 2,347 allocs, 2,347 frees, 268,272 bytes allocated
==89== 
==89== All heap blocks were freed -- no leaks are possible
==89== 
==89== For counts of detected and suppressed errors, rerun with: -v
==89== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents

- **Points**: 4 / 4

```
==91== Memcheck, a memory error detector
==91== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==91== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==91== Command: ./test -r xml "List::insert\ contents"
==91== 
==91== 
==91== HEAP SUMMARY:
==91==     in use at exit: 0 bytes in 0 blocks
==91==   total heap usage: 2,343 allocs, 2,343 frees, 268,176 bytes allocated
==91== 
==91== All heap blocks were freed -- no leaks are possible
==91== 
==91== For counts of detected and suppressed errors, rerun with: -v
==91== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::triplerotate basic

- **Points**: 5 / 5

```
==93== Memcheck, a memory error detector
==93== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==93== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==93== Command: ./test -r xml "List::triplerotate\ basic"
==93== 
==93== 
==93== HEAP SUMMARY:
==93==     in use at exit: 0 bytes in 0 blocks
==93==   total heap usage: 2,351 allocs, 2,351 frees, 268,464 bytes allocated
==93== 
==93== All heap blocks were freed -- no leaks are possible
==93== 
==93== For counts of detected and suppressed errors, rerun with: -v
==93== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate simple

- **Points**: 10 / 10

```
==95== Memcheck, a memory error detector
==95== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==95== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==95== Command: ./test -r xml "List::triplerotate\ simple"
==95== 
==95== 
==95== HEAP SUMMARY:
==95==     in use at exit: 0 bytes in 0 blocks
==95==   total heap usage: 2,355 allocs, 2,355 frees, 268,560 bytes allocated
==95== 
==95== All heap blocks were freed -- no leaks are possible
==95== 
==95== For counts of detected and suppressed errors, rerun with: -v
==95== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split simple

- **Points**: 5 / 5

```
==97== Memcheck, a memory error detector
==97== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==97== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==97== Command: ./test -r xml "List::split\ simple"
==97== 
==97== 
==97== HEAP SUMMARY:
==97==     in use at exit: 0 bytes in 0 blocks
==97==   total heap usage: 2,205 allocs, 2,205 frees, 263,744 bytes allocated
==97== 
==97== All heap blocks were freed -- no leaks are possible
==97== 
==97== For counts of detected and suppressed errors, rerun with: -v
==97== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split images

- **Points**: 5 / 5





### ✓ - [3/3] - List::_destroy empty list

- **Points**: 3 / 3

```
==100== Memcheck, a memory error detector
==100== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==100== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==100== Command: ./test -r xml "List::_destroy\ empty\ list"
==100== 
==100== 
==100== HEAP SUMMARY:
==100==     in use at exit: 0 bytes in 0 blocks
==100==   total heap usage: 2,355 allocs, 2,355 frees, 269,104 bytes allocated
==100== 
==100== All heap blocks were freed -- no leaks are possible
==100== 
==100== For counts of detected and suppressed errors, rerun with: -v
==100== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::begin() returns an iterator to the front of the list

- **Points**: 1 / 1

```
==102== Memcheck, a memory error detector
==102== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==102== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==102== Command: ./test -r xml "List::begin()\ returns\ an\ iterator\ to\ the\ front\ of\ the\ list"
==102== 
==102== 
==102== HEAP SUMMARY:
==102==     in use at exit: 0 bytes in 0 blocks
==102==   total heap usage: 2,359 allocs, 2,359 frees, 273,440 bytes allocated
==102== 
==102== All heap blocks were freed -- no leaks are possible
==102== 
==102== For counts of detected and suppressed errors, rerun with: -v
==102== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (pre-increment)

- **Points**: 1 / 1

```
==104== Memcheck, a memory error detector
==104== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==104== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==104== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (pre-increment)"
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



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (post-increment)

- **Points**: 1 / 1

```
==106== Memcheck, a memory error detector
==106== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==106== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==106== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (post-increment)"
==106== 
==106== 
==106== HEAP SUMMARY:
==106==     in use at exit: 0 bytes in 0 blocks
==106==   total heap usage: 2,359 allocs, 2,359 frees, 275,840 bytes allocated
==106== 
==106== All heap blocks were freed -- no leaks are possible
==106== 
==106== For counts of detected and suppressed errors, rerun with: -v
==106== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==108== Memcheck, a memory error detector
==108== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==108== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==108== Command: ./test -r xml "List::ListIterator::operator++\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==108== 
==108== 
==108== HEAP SUMMARY:
==108==     in use at exit: 0 bytes in 0 blocks
==108==   total heap usage: 2,359 allocs, 2,359 frees, 278,240 bytes allocated
==108== 
==108== All heap blocks were freed -- no leaks are possible
==108== 
==108== For counts of detected and suppressed errors, rerun with: -v
==108== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- moves the iterator backwards

- **Points**: 1 / 1

```
==110== Memcheck, a memory error detector
==110== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==110== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==110== Command: ./test -r xml "List::ListIterator::operator--\ moves\ the\ iterator\ backwards"
==110== 
==110== 
==110== HEAP SUMMARY:
==110==     in use at exit: 0 bytes in 0 blocks
==110==   total heap usage: 2,359 allocs, 2,359 frees, 273,440 bytes allocated
==110== 
==110== All heap blocks were freed -- no leaks are possible
==110== 
==110== For counts of detected and suppressed errors, rerun with: -v
==110== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==112== Memcheck, a memory error detector
==112== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==112== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==112== Command: ./test -r xml "List::ListIterator::operator--\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==112== 
==112== 
==112== HEAP SUMMARY:
==112==     in use at exit: 0 bytes in 0 blocks
==112==   total heap usage: 2,359 allocs, 2,359 frees, 278,240 bytes allocated
==112== 
==112== All heap blocks were freed -- no leaks are possible
==112== 
==112== For counts of detected and suppressed errors, rerun with: -v
==112== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is reached

- **Points**: 1 / 1

```
==114== Memcheck, a memory error detector
==114== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==114== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==114== Command: ./test -r xml "List::ListIterator::end\ is\ reached"
==114== 
==114== 
==114== HEAP SUMMARY:
==114==     in use at exit: 0 bytes in 0 blocks
==114==   total heap usage: 2,352 allocs, 2,352 frees, 270,872 bytes allocated
==114== 
==114== All heap blocks were freed -- no leaks are possible
==114== 
==114== For counts of detected and suppressed errors, rerun with: -v
==114== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is not ::begin in a non-empty list

- **Points**: 1 / 1

```
==116== Memcheck, a memory error detector
==116== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==116== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==116== Command: ./test -r xml "List::ListIterator::end\ is\ not\ ::begin\ in\ a\ non-empty\ list"
==116== 
==116== 
==116== HEAP SUMMARY:
==116==     in use at exit: 0 bytes in 0 blocks
==116==   total heap usage: 2,352 allocs, 2,352 frees, 273,272 bytes allocated
==116== 
==116== All heap blocks were freed -- no leaks are possible
==116== 
==116== For counts of detected and suppressed errors, rerun with: -v
==116== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::reverse simple

- **Points**: 4 / 4

```
==118== Memcheck, a memory error detector
==118== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==118== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==118== Command: ./test -r xml "List::reverse\ simple"
==118== 
==118== 
==118== HEAP SUMMARY:
==118==     in use at exit: 0 bytes in 0 blocks
==118==   total heap usage: 2,208 allocs, 2,208 frees, 263,852 bytes allocated
==118== 
==118== All heap blocks were freed -- no leaks are possible
==118== 
==118== For counts of detected and suppressed errors, rerun with: -v
==118== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/2] - List::reverse edge cases

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✓ - [5/5] - List::reverseNth #3

- **Points**: 5 / 5

```
==121== Memcheck, a memory error detector
==121== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==121== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==121== Command: ./test -r xml "List::reverseNth\ #3"
==121== 
==121== 
==121== HEAP SUMMARY:
==121==     in use at exit: 0 bytes in 0 blocks
==121==   total heap usage: 2,214 allocs, 2,214 frees, 264,032 bytes allocated
==121== 
==121== All heap blocks were freed -- no leaks are possible
==121== 
==121== For counts of detected and suppressed errors, rerun with: -v
==121== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::merge #2

- **Points**: 5 / 5

```
==123== Memcheck, a memory error detector
==123== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==123== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==123== Command: ./test -r xml "List::merge\ #2"
==123== 
==123== 
==123== HEAP SUMMARY:
==123==     in use at exit: 16 bytes in 1 blocks
==123==   total heap usage: 2,244 allocs, 2,243 frees, 265,824 bytes allocated
==123== 
==123== LEAK SUMMARY:
==123==    definitely lost: 0 bytes in 0 blocks
==123==    indirectly lost: 0 bytes in 0 blocks
==123==      possibly lost: 0 bytes in 0 blocks
==123==    still reachable: 16 bytes in 1 blocks
==123==         suppressed: 0 bytes in 0 blocks
==123== Reachable blocks (those to which a pointer was found) are not shown.
==123== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==123== 
==123== For counts of detected and suppressed errors, rerun with: -v
==123== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #3

- **Points**: 2 / 2

```
==125== Memcheck, a memory error detector
==125== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==125== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==125== Command: ./test -r xml "List::sort\ simple\ #3"
==125== 
==125== 
==125== HEAP SUMMARY:
==125==     in use at exit: 0 bytes in 0 blocks
==125==   total heap usage: 2,205 allocs, 2,205 frees, 263,784 bytes allocated
==125== 
==125== All heap blocks were freed -- no leaks are possible
==125== 
==125== For counts of detected and suppressed errors, rerun with: -v
==125== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::reverse

- **Points**: 5 / 5





### ✓ - [5/5] - List::reverseNth #1

- **Points**: 5 / 5





### ✓ - [5/5] - List::reverseNth #2

- **Points**: 5 / 5





### ✓ - [10/10] - List::merge

- **Points**: 10 / 10

```
==130== Memcheck, a memory error detector
==130== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==130== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==130== Command: ./test -r xml "List::merge"
==130== 
==130== 
==130== HEAP SUMMARY:
==130==     in use at exit: 16 bytes in 1 blocks
==130==   total heap usage: 243,309 allocs, 243,308 frees, 79,504,961 bytes allocated
==130== 
==130== LEAK SUMMARY:
==130==    definitely lost: 0 bytes in 0 blocks
==130==    indirectly lost: 0 bytes in 0 blocks
==130==      possibly lost: 0 bytes in 0 blocks
==130==    still reachable: 16 bytes in 1 blocks
==130==         suppressed: 0 bytes in 0 blocks
==130== Reachable blocks (those to which a pointer was found) are not shown.
==130== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==130== 
==130== For counts of detected and suppressed errors, rerun with: -v
==130== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #1

- **Points**: 2 / 2

```
==132== Memcheck, a memory error detector
==132== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==132== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==132== Command: ./test -r xml "List::sort\ simple\ #1"
==132== 
==132== 
==132== HEAP SUMMARY:
==132==     in use at exit: 0 bytes in 0 blocks
==132==   total heap usage: 2,202 allocs, 2,202 frees, 263,672 bytes allocated
==132== 
==132== All heap blocks were freed -- no leaks are possible
==132== 
==132== For counts of detected and suppressed errors, rerun with: -v
==132== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #2

- **Points**: 2 / 2

```
==134== Memcheck, a memory error detector
==134== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==134== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==134== Command: ./test -r xml "List::sort\ simple\ #2"
==134== 
==134== 
==134== HEAP SUMMARY:
==134==     in use at exit: 0 bytes in 0 blocks
==134==   total heap usage: 2,202 allocs, 2,202 frees, 263,720 bytes allocated
==134== 
==134== All heap blocks were freed -- no leaks are possible
==134== 
==134== For counts of detected and suppressed errors, rerun with: -v
==134== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::sort #1

- **Points**: 5 / 5





### ✓ - [5/5] - List::sort #2

- **Points**: 5 / 5





### ✓ - [4/4] - List::insert contents #2

- **Points**: 4 / 4

```
==138== Memcheck, a memory error detector
==138== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==138== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==138== Command: ./test -r xml "List::insert\ contents\ #2"
==138== 
==138== 
==138== HEAP SUMMARY:
==138==     in use at exit: 0 bytes in 0 blocks
==138==   total heap usage: 2,358 allocs, 2,358 frees, 268,672 bytes allocated
==138== 
==138== All heap blocks were freed -- no leaks are possible
==138== 
==138== For counts of detected and suppressed errors, rerun with: -v
==138== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - List::split edge cases

- **Points**: 0 / 5


```
Original: "< 1 2 3 4 >" == s2.str()
Expanded: "< 1 2 3 4 >" == "< 1 >"
```


---

This report was generated for **jeremyl6** using **dc4eaa129f382187460b157f8f808935f2603204** (latest commit as of **October 4th 2021, 5:20 pm**)
