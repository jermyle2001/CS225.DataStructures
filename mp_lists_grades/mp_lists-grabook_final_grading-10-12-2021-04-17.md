---

This report was generated for **jeremyl6** using **dc4eaa129f382187460b157f8f808935f2603204** (latest commit as of **October 4th 2021, 11:59 pm**)

---




## Score: 116/126 (92.06%)


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
==92== Memcheck, a memory error detector
==92== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==92== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==92== Command: ./test -r xml "List::insertFront\ size"
==92== 
==92== 
==92== HEAP SUMMARY:
==92==     in use at exit: 0 bytes in 0 blocks
==92==   total heap usage: 2,462 allocs, 2,462 frees, 285,632 bytes allocated
==92== 
==92== All heap blocks were freed -- no leaks are possible
==92== 
==92== For counts of detected and suppressed errors, rerun with: -v
==92== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::insertBack size

- **Points**: 2 / 2

```
==94== Memcheck, a memory error detector
==94== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==94== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==94== Command: ./test -r xml "List::insertBack\ size"
==94== 
==94== 
==94== HEAP SUMMARY:
==94==     in use at exit: 0 bytes in 0 blocks
==94==   total heap usage: 2,462 allocs, 2,462 frees, 285,632 bytes allocated
==94== 
==94== All heap blocks were freed -- no leaks are possible
==94== 
==94== For counts of detected and suppressed errors, rerun with: -v
==94== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents

- **Points**: 4 / 4

```
==96== Memcheck, a memory error detector
==96== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==96== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==96== Command: ./test -r xml "List::insert\ contents"
==96== 
==96== 
==96== HEAP SUMMARY:
==96==     in use at exit: 0 bytes in 0 blocks
==96==   total heap usage: 2,458 allocs, 2,458 frees, 285,536 bytes allocated
==96== 
==96== All heap blocks were freed -- no leaks are possible
==96== 
==96== For counts of detected and suppressed errors, rerun with: -v
==96== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::triplerotate basic

- **Points**: 5 / 5

```
==98== Memcheck, a memory error detector
==98== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==98== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==98== Command: ./test -r xml "List::triplerotate\ basic"
==98== 
==98== 
==98== HEAP SUMMARY:
==98==     in use at exit: 0 bytes in 0 blocks
==98==   total heap usage: 2,466 allocs, 2,466 frees, 285,824 bytes allocated
==98== 
==98== All heap blocks were freed -- no leaks are possible
==98== 
==98== For counts of detected and suppressed errors, rerun with: -v
==98== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate simple

- **Points**: 10 / 10

```
==100== Memcheck, a memory error detector
==100== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==100== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==100== Command: ./test -r xml "List::triplerotate\ simple"
==100== 
==100== 
==100== HEAP SUMMARY:
==100==     in use at exit: 0 bytes in 0 blocks
==100==   total heap usage: 2,470 allocs, 2,470 frees, 285,920 bytes allocated
==100== 
==100== All heap blocks were freed -- no leaks are possible
==100== 
==100== For counts of detected and suppressed errors, rerun with: -v
==100== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split simple

- **Points**: 5 / 5

```
==102== Memcheck, a memory error detector
==102== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==102== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==102== Command: ./test -r xml "List::split\ simple"
==102== 
==102== 
==102== HEAP SUMMARY:
==102==     in use at exit: 0 bytes in 0 blocks
==102==   total heap usage: 2,320 allocs, 2,320 frees, 281,104 bytes allocated
==102== 
==102== All heap blocks were freed -- no leaks are possible
==102== 
==102== For counts of detected and suppressed errors, rerun with: -v
==102== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split images

- **Points**: 5 / 5





### ✓ - [3/3] - List::_destroy empty list

- **Points**: 3 / 3

```
==105== Memcheck, a memory error detector
==105== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==105== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==105== Command: ./test -r xml "List::_destroy\ empty\ list"
==105== 
==105== 
==105== HEAP SUMMARY:
==105==     in use at exit: 0 bytes in 0 blocks
==105==   total heap usage: 2,470 allocs, 2,470 frees, 286,464 bytes allocated
==105== 
==105== All heap blocks were freed -- no leaks are possible
==105== 
==105== For counts of detected and suppressed errors, rerun with: -v
==105== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::begin() returns an iterator to the front of the list

- **Points**: 1 / 1

```
==107== Memcheck, a memory error detector
==107== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==107== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==107== Command: ./test -r xml "List::begin()\ returns\ an\ iterator\ to\ the\ front\ of\ the\ list"
==107== 
==107== 
==107== HEAP SUMMARY:
==107==     in use at exit: 0 bytes in 0 blocks
==107==   total heap usage: 2,474 allocs, 2,474 frees, 290,800 bytes allocated
==107== 
==107== All heap blocks were freed -- no leaks are possible
==107== 
==107== For counts of detected and suppressed errors, rerun with: -v
==107== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (pre-increment)

- **Points**: 1 / 1

```
==109== Memcheck, a memory error detector
==109== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==109== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==109== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (pre-increment)"
==109== 
==109== 
==109== HEAP SUMMARY:
==109==     in use at exit: 0 bytes in 0 blocks
==109==   total heap usage: 2,474 allocs, 2,474 frees, 293,200 bytes allocated
==109== 
==109== All heap blocks were freed -- no leaks are possible
==109== 
==109== For counts of detected and suppressed errors, rerun with: -v
==109== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (post-increment)

- **Points**: 1 / 1

```
==111== Memcheck, a memory error detector
==111== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==111== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==111== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (post-increment)"
==111== 
==111== 
==111== HEAP SUMMARY:
==111==     in use at exit: 0 bytes in 0 blocks
==111==   total heap usage: 2,474 allocs, 2,474 frees, 293,200 bytes allocated
==111== 
==111== All heap blocks were freed -- no leaks are possible
==111== 
==111== For counts of detected and suppressed errors, rerun with: -v
==111== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==113== Memcheck, a memory error detector
==113== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==113== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==113== Command: ./test -r xml "List::ListIterator::operator++\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==113== 
==113== 
==113== HEAP SUMMARY:
==113==     in use at exit: 0 bytes in 0 blocks
==113==   total heap usage: 2,474 allocs, 2,474 frees, 295,600 bytes allocated
==113== 
==113== All heap blocks were freed -- no leaks are possible
==113== 
==113== For counts of detected and suppressed errors, rerun with: -v
==113== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- moves the iterator backwards

- **Points**: 1 / 1

```
==115== Memcheck, a memory error detector
==115== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==115== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==115== Command: ./test -r xml "List::ListIterator::operator--\ moves\ the\ iterator\ backwards"
==115== 
==115== 
==115== HEAP SUMMARY:
==115==     in use at exit: 0 bytes in 0 blocks
==115==   total heap usage: 2,474 allocs, 2,474 frees, 290,800 bytes allocated
==115== 
==115== All heap blocks were freed -- no leaks are possible
==115== 
==115== For counts of detected and suppressed errors, rerun with: -v
==115== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==117== Memcheck, a memory error detector
==117== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==117== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==117== Command: ./test -r xml "List::ListIterator::operator--\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==117== 
==117== 
==117== HEAP SUMMARY:
==117==     in use at exit: 0 bytes in 0 blocks
==117==   total heap usage: 2,474 allocs, 2,474 frees, 295,600 bytes allocated
==117== 
==117== All heap blocks were freed -- no leaks are possible
==117== 
==117== For counts of detected and suppressed errors, rerun with: -v
==117== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is reached

- **Points**: 1 / 1

```
==119== Memcheck, a memory error detector
==119== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==119== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==119== Command: ./test -r xml "List::ListIterator::end\ is\ reached"
==119== 
==119== 
==119== HEAP SUMMARY:
==119==     in use at exit: 0 bytes in 0 blocks
==119==   total heap usage: 2,467 allocs, 2,467 frees, 288,232 bytes allocated
==119== 
==119== All heap blocks were freed -- no leaks are possible
==119== 
==119== For counts of detected and suppressed errors, rerun with: -v
==119== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is not ::begin in a non-empty list

- **Points**: 1 / 1

```
==121== Memcheck, a memory error detector
==121== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==121== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==121== Command: ./test -r xml "List::ListIterator::end\ is\ not\ ::begin\ in\ a\ non-empty\ list"
==121== 
==121== 
==121== HEAP SUMMARY:
==121==     in use at exit: 0 bytes in 0 blocks
==121==   total heap usage: 2,467 allocs, 2,467 frees, 290,632 bytes allocated
==121== 
==121== All heap blocks were freed -- no leaks are possible
==121== 
==121== For counts of detected and suppressed errors, rerun with: -v
==121== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::reverse simple

- **Points**: 4 / 4

```
==123== Memcheck, a memory error detector
==123== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==123== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==123== Command: ./test -r xml "List::reverse\ simple"
==123== 
==123== 
==123== HEAP SUMMARY:
==123==     in use at exit: 0 bytes in 0 blocks
==123==   total heap usage: 2,323 allocs, 2,323 frees, 281,212 bytes allocated
==123== 
==123== All heap blocks were freed -- no leaks are possible
==123== 
==123== For counts of detected and suppressed errors, rerun with: -v
==123== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/2] - List::reverse edge cases

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✓ - [5/5] - List::reverseNth #3

- **Points**: 5 / 5

```
==126== Memcheck, a memory error detector
==126== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==126== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==126== Command: ./test -r xml "List::reverseNth\ #3"
==126== 
==126== 
==126== HEAP SUMMARY:
==126==     in use at exit: 0 bytes in 0 blocks
==126==   total heap usage: 2,329 allocs, 2,329 frees, 281,392 bytes allocated
==126== 
==126== All heap blocks were freed -- no leaks are possible
==126== 
==126== For counts of detected and suppressed errors, rerun with: -v
==126== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::merge #2

- **Points**: 5 / 5

```
==128== Memcheck, a memory error detector
==128== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==128== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==128== Command: ./test -r xml "List::merge\ #2"
==128== 
==128== 
==128== HEAP SUMMARY:
==128==     in use at exit: 16 bytes in 1 blocks
==128==   total heap usage: 2,359 allocs, 2,358 frees, 283,184 bytes allocated
==128== 
==128== LEAK SUMMARY:
==128==    definitely lost: 0 bytes in 0 blocks
==128==    indirectly lost: 0 bytes in 0 blocks
==128==      possibly lost: 0 bytes in 0 blocks
==128==    still reachable: 16 bytes in 1 blocks
==128==         suppressed: 0 bytes in 0 blocks
==128== Reachable blocks (those to which a pointer was found) are not shown.
==128== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==128== 
==128== For counts of detected and suppressed errors, rerun with: -v
==128== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #3

- **Points**: 2 / 2

```
==130== Memcheck, a memory error detector
==130== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==130== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==130== Command: ./test -r xml "List::sort\ simple\ #3"
==130== 
==130== 
==130== HEAP SUMMARY:
==130==     in use at exit: 0 bytes in 0 blocks
==130==   total heap usage: 2,320 allocs, 2,320 frees, 281,144 bytes allocated
==130== 
==130== All heap blocks were freed -- no leaks are possible
==130== 
==130== For counts of detected and suppressed errors, rerun with: -v
==130== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/2] - List Complex

- **Points**: 0 / 2


```
Fatal Error: SIGSEGV - Segmentation violation signal
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
==136== Memcheck, a memory error detector
==136== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==136== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==136== Command: ./test -r xml "List::merge"
==136== 
==136== 
==136== HEAP SUMMARY:
==136==     in use at exit: 16 bytes in 1 blocks
==136==   total heap usage: 243,424 allocs, 243,423 frees, 79,522,321 bytes allocated
==136== 
==136== LEAK SUMMARY:
==136==    definitely lost: 0 bytes in 0 blocks
==136==    indirectly lost: 0 bytes in 0 blocks
==136==      possibly lost: 0 bytes in 0 blocks
==136==    still reachable: 16 bytes in 1 blocks
==136==         suppressed: 0 bytes in 0 blocks
==136== Reachable blocks (those to which a pointer was found) are not shown.
==136== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==136== 
==136== For counts of detected and suppressed errors, rerun with: -v
==136== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #1

- **Points**: 2 / 2

```
==138== Memcheck, a memory error detector
==138== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==138== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==138== Command: ./test -r xml "List::sort\ simple\ #1"
==138== 
==138== 
==138== HEAP SUMMARY:
==138==     in use at exit: 0 bytes in 0 blocks
==138==   total heap usage: 2,317 allocs, 2,317 frees, 281,032 bytes allocated
==138== 
==138== All heap blocks were freed -- no leaks are possible
==138== 
==138== For counts of detected and suppressed errors, rerun with: -v
==138== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #2

- **Points**: 2 / 2

```
==140== Memcheck, a memory error detector
==140== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==140== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==140== Command: ./test -r xml "List::sort\ simple\ #2"
==140== 
==140== 
==140== HEAP SUMMARY:
==140==     in use at exit: 0 bytes in 0 blocks
==140==   total heap usage: 2,317 allocs, 2,317 frees, 281,080 bytes allocated
==140== 
==140== All heap blocks were freed -- no leaks are possible
==140== 
==140== For counts of detected and suppressed errors, rerun with: -v
==140== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::sort #1

- **Points**: 5 / 5





### ✓ - [5/5] - List::sort #2

- **Points**: 5 / 5





### ✓ - [4/4] - List::insert contents #2

- **Points**: 4 / 4

```
==144== Memcheck, a memory error detector
==144== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==144== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==144== Command: ./test -r xml "List::insert\ contents\ #2"
==144== 
==144== 
==144== HEAP SUMMARY:
==144==     in use at exit: 0 bytes in 0 blocks
==144==   total heap usage: 2,473 allocs, 2,473 frees, 286,032 bytes allocated
==144== 
==144== All heap blocks were freed -- no leaks are possible
==144== 
==144== For counts of detected and suppressed errors, rerun with: -v
==144== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - List::split edge cases

- **Points**: 0 / 5


```
Original: "< 1 2 3 4 >" == s2.str()
Expanded: "< 1 2 3 4 >" == "< 1 >"
```


### ✓ - [2/2] - List::triplerotate edge

- **Points**: 2 / 2

```
==147== Memcheck, a memory error detector
==147== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==147== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==147== Command: ./test -r xml "List::triplerotate\ edge"
==147== 
==147== 
==147== HEAP SUMMARY:
==147==     in use at exit: 0 bytes in 0 blocks
==147==   total heap usage: 2,470 allocs, 2,470 frees, 285,960 bytes allocated
==147== 
==147== All heap blocks were freed -- no leaks are possible
==147== 
==147== For counts of detected and suppressed errors, rerun with: -v
==147== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::triplerotate hard

- **Points**: 2 / 2

```
==149== Memcheck, a memory error detector
==149== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==149== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==149== Command: ./test -r xml "List::triplerotate\ hard"
==149== 
==149== 
==149== HEAP SUMMARY:
==149==     in use at exit: 0 bytes in 0 blocks
==149==   total heap usage: 2,475 allocs, 2,475 frees, 286,080 bytes allocated
==149== 
==149== All heap blocks were freed -- no leaks are possible
==149== 
==149== For counts of detected and suppressed errors, rerun with: -v
==149== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate image

- **Points**: 10 / 10





### ✗ - [0/1] - List::ListIterator::operator-- from end

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


---