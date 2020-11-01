---

This report was generated for **kjzhou2** using **ba08233239f07780ea5c743bf9a4df6a62ea86dd** (latest commit as of **November 1st 2020, 12:08 pm**)

---




## Score: 98/150 (65.33%)


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
==74== Memcheck, a memory error detector
==74== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==74== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==74== Command: ./test -r xml "DH::testRemoveEASY"
==74== 
==74== 
==74== HEAP SUMMARY:
==74==     in use at exit: 64 bytes in 2 blocks
==74==   total heap usage: 1,856 allocs, 1,854 frees, 240,685 bytes allocated
==74== 
==74== 64 bytes in 2 blocks are definitely lost in loss record 1 of 1
==74==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==74==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==74==    by 0x42C5C4: DHHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (dhhashtable.cpp:106)
==74==    by 0x42678A: ____C_A_T_C_H____T_E_S_T____0() (tests-dh.cpp:18)
==74==    by 0x4736A2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==74==    by 0x463DF6: Catch::TestCase::invoke() const (catch.hpp:10793)
==74==    by 0x463D2C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==74==    by 0x460286: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==74==    by 0x45E85E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==74==    by 0x467BF6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==74==    by 0x466892: Catch::Session::runInternal() (catch.hpp:10149)
==74==    by 0x46655A: Catch::Session::run() (catch.hpp:10106)
==74== 
==74== LEAK SUMMARY:
==74==    definitely lost: 64 bytes in 2 blocks
==74==    indirectly lost: 0 bytes in 0 blocks
==74==      possibly lost: 0 bytes in 0 blocks
==74==    still reachable: 0 bytes in 0 blocks
==74==         suppressed: 0 bytes in 0 blocks
==74== 
==74== For counts of detected and suppressed errors, rerun with: -v
==74== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```



### ✗ - [0/10] - DH::testRemoveHard

- **Points**: 0 / 10

```
==76== Memcheck, a memory error detector
==76== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==76== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==76== Command: ./test -r xml "DH::testRemoveHard"
==76== 
==76== 
==76== HEAP SUMMARY:
==76==     in use at exit: 128 bytes in 4 blocks
==76==   total heap usage: 1,878 allocs, 1,874 frees, 241,389 bytes allocated
==76== 
==76== 32 bytes in 1 blocks are definitely lost in loss record 1 of 2
==76==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==76==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==76==    by 0x42C5C4: DHHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (dhhashtable.cpp:106)
==76==    by 0x427A4E: ____C_A_T_C_H____T_E_S_T____2() (tests-dh.cpp:43)
==76==    by 0x4736A2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==76==    by 0x463DF6: Catch::TestCase::invoke() const (catch.hpp:10793)
==76==    by 0x463D2C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==76==    by 0x460286: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==76==    by 0x45E85E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==76==    by 0x467BF6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==76==    by 0x466892: Catch::Session::runInternal() (catch.hpp:10149)
==76==    by 0x46655A: Catch::Session::run() (catch.hpp:10106)
==76== 
==76== 96 bytes in 3 blocks are definitely lost in loss record 2 of 2
==76==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==76==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==76==    by 0x42C5C4: DHHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (dhhashtable.cpp:106)
==76==    by 0x427A7C: ____C_A_T_C_H____T_E_S_T____2() (tests-dh.cpp:46)
==76==    by 0x4736A2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==76==    by 0x463DF6: Catch::TestCase::invoke() const (catch.hpp:10793)
==76==    by 0x463D2C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==76==    by 0x460286: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==76==    by 0x45E85E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==76==    by 0x467BF6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==76==    by 0x466892: Catch::Session::runInternal() (catch.hpp:10149)
==76==    by 0x46655A: Catch::Session::run() (catch.hpp:10106)
==76== 
==76== LEAK SUMMARY:
==76==    definitely lost: 128 bytes in 4 blocks
==76==    indirectly lost: 0 bytes in 0 blocks
==76==      possibly lost: 0 bytes in 0 blocks
==76==    still reachable: 0 bytes in 0 blocks
==76==         suppressed: 0 bytes in 0 blocks
==76== 
==76== For counts of detected and suppressed errors, rerun with: -v
==76== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

```



### ✓ - [7/7] - DH::testResizeOnce

- **Points**: 7 / 7

```
==78== Memcheck, a memory error detector
==78== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==78== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==78== Command: ./test -r xml "DH::testResizeOnce"
==78== 
==78== 
==78== HEAP SUMMARY:
==78==     in use at exit: 0 bytes in 0 blocks
==78==   total heap usage: 1,974 allocs, 1,974 frees, 245,197 bytes allocated
==78== 
==78== All heap blocks were freed -- no leaks are possible
==78== 
==78== For counts of detected and suppressed errors, rerun with: -v
==78== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [11/11] - DH::testResizeAll

- **Points**: 11 / 11

```
==80== Memcheck, a memory error detector
==80== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==80== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==80== Command: ./test -r xml "DH::testResizeAll"
==80== 
==80== 
==80== HEAP SUMMARY:
==80==     in use at exit: 0 bytes in 0 blocks
==80==   total heap usage: 1,873 allocs, 1,873 frees, 238,685 bytes allocated
==80== 
==80== All heap blocks were freed -- no leaks are possible
==80== 
==80== For counts of detected and suppressed errors, rerun with: -v
==80== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [6/6] - DH::testInsertEasy

- **Points**: 6 / 6

```
==82== Memcheck, a memory error detector
==82== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==82== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==82== Command: ./test -r xml "DH::testInsertEasy"
==82== 
==82== 
==82== HEAP SUMMARY:
==82==     in use at exit: 0 bytes in 0 blocks
==82==   total heap usage: 1,855 allocs, 1,855 frees, 240,653 bytes allocated
==82== 
==82== All heap blocks were freed -- no leaks are possible
==82== 
==82== For counts of detected and suppressed errors, rerun with: -v
==82== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/10] - DH::testInsertHard

- **Points**: 0 / 10

```
==84== Memcheck, a memory error detector
==84== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==84== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==84== Command: ./test -r xml "DH::testInsertHard"
==84== 
==84== 
==84== HEAP SUMMARY:
==84==     in use at exit: 64 bytes in 2 blocks
==84==   total heap usage: 1,877 allocs, 1,875 frees, 241,357 bytes allocated
==84== 
==84== 64 bytes in 2 blocks are definitely lost in loss record 1 of 1
==84==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==84==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==84==    by 0x42C5C4: DHHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (dhhashtable.cpp:106)
==84==    by 0x42B14A: ____C_A_T_C_H____T_E_S_T____10() (tests-dh.cpp:137)
==84==    by 0x4736A2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==84==    by 0x463DF6: Catch::TestCase::invoke() const (catch.hpp:10793)
==84==    by 0x463D2C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==84==    by 0x460286: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==84==    by 0x45E85E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==84==    by 0x467BF6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==84==    by 0x466892: Catch::Session::runInternal() (catch.hpp:10149)
==84==    by 0x46655A: Catch::Session::run() (catch.hpp:10106)
==84== 
==84== LEAK SUMMARY:
==84==    definitely lost: 64 bytes in 2 blocks
==84==    indirectly lost: 0 bytes in 0 blocks
==84==      possibly lost: 0 bytes in 0 blocks
==84==    still reachable: 0 bytes in 0 blocks
==84==         suppressed: 0 bytes in 0 blocks
==84== 
==84== For counts of detected and suppressed errors, rerun with: -v
==84== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```



### ✓ - [6/6] - SC::testRemoveEASY

- **Points**: 6 / 6

```
==86== Memcheck, a memory error detector
==86== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==86== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==86== Command: ./test -r xml "SC::testRemoveEASY"
==86== 
==86== 
==86== HEAP SUMMARY:
==86==     in use at exit: 0 bytes in 0 blocks
==86==   total heap usage: 1,855 allocs, 1,855 frees, 241,392 bytes allocated
==86== 
==86== All heap blocks were freed -- no leaks are possible
==86== 
==86== For counts of detected and suppressed errors, rerun with: -v
==86== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - SC::testRemoveHard

- **Points**: 10 / 10

```
==88== Memcheck, a memory error detector
==88== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==88== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==88== Command: ./test -r xml "SC::testRemoveHard"
==88== 
==88== 
==88== HEAP SUMMARY:
==88==     in use at exit: 0 bytes in 0 blocks
==88==   total heap usage: 1,877 allocs, 1,877 frees, 242,272 bytes allocated
==88== 
==88== All heap blocks were freed -- no leaks are possible
==88== 
==88== For counts of detected and suppressed errors, rerun with: -v
==88== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [7/7] - SC::testResizeOnce

- **Points**: 7 / 7

```
==90== Memcheck, a memory error detector
==90== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==90== Command: ./test -r xml "SC::testResizeOnce"
==90== 
==90== 
==90== HEAP SUMMARY:
==90==     in use at exit: 0 bytes in 0 blocks
==90==   total heap usage: 2,009 allocs, 2,009 frees, 249,760 bytes allocated
==90== 
==90== All heap blocks were freed -- no leaks are possible
==90== 
==90== For counts of detected and suppressed errors, rerun with: -v
==90== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [11/11] - SC::testResizeAll

- **Points**: 11 / 11

```
==92== Memcheck, a memory error detector
==92== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==92== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==92== Command: ./test -r xml "SC::testResizeAll"
==92== 
==92== 
==92== HEAP SUMMARY:
==92==     in use at exit: 0 bytes in 0 blocks
==92==   total heap usage: 1,908 allocs, 1,908 frees, 242,944 bytes allocated
==92== 
==92== All heap blocks were freed -- no leaks are possible
==92== 
==92== For counts of detected and suppressed errors, rerun with: -v
==92== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [6/6] - SC::testInsertEasy

- **Points**: 6 / 6

```
==94== Memcheck, a memory error detector
==94== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==94== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==94== Command: ./test -r xml "SC::testInsertEasy"
==94== 
==94== 
==94== HEAP SUMMARY:
==94==     in use at exit: 0 bytes in 0 blocks
==94==   total heap usage: 1,854 allocs, 1,854 frees, 241,344 bytes allocated
==94== 
==94== All heap blocks were freed -- no leaks are possible
==94== 
==94== For counts of detected and suppressed errors, rerun with: -v
==94== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - SC::testInsertHard

- **Points**: 10 / 10

```
==96== Memcheck, a memory error detector
==96== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==96== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==96== Command: ./test -r xml "SC::testInsertHard"
==96== 
==96== 
==96== HEAP SUMMARY:
==96==     in use at exit: 0 bytes in 0 blocks
==96==   total heap usage: 1,876 allocs, 1,876 frees, 242,224 bytes allocated
==96== 
==96== All heap blocks were freed -- no leaks are possible
==96== 
==96== For counts of detected and suppressed errors, rerun with: -v
==96== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/6] - LP::testRemoveEASY

- **Points**: 0 / 6

```
==98== Memcheck, a memory error detector
==98== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==98== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==98== Command: ./test -r xml "LP::testRemoveEASY"
==98== 
==98== 
==98== HEAP SUMMARY:
==98==     in use at exit: 64 bytes in 2 blocks
==98==   total heap usage: 1,856 allocs, 1,854 frees, 240,685 bytes allocated
==98== 
==98== 64 bytes in 2 blocks are definitely lost in loss record 1 of 1
==98==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==98==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==98==    by 0x4400CF: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:107)
==98==    by 0x43A93A: ____C_A_T_C_H____T_E_S_T____0() (tests-lp.cpp:18)
==98==    by 0x4736A2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==98==    by 0x463DF6: Catch::TestCase::invoke() const (catch.hpp:10793)
==98==    by 0x463D2C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==98==    by 0x460286: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==98==    by 0x45E85E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==98==    by 0x467BF6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==98==    by 0x466892: Catch::Session::runInternal() (catch.hpp:10149)
==98==    by 0x46655A: Catch::Session::run() (catch.hpp:10106)
==98== 
==98== LEAK SUMMARY:
==98==    definitely lost: 64 bytes in 2 blocks
==98==    indirectly lost: 0 bytes in 0 blocks
==98==      possibly lost: 0 bytes in 0 blocks
==98==    still reachable: 0 bytes in 0 blocks
==98==         suppressed: 0 bytes in 0 blocks
==98== 
==98== For counts of detected and suppressed errors, rerun with: -v
==98== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```



### ✗ - [0/10] - LP::testRemoveHard

- **Points**: 0 / 10

```
==100== Memcheck, a memory error detector
==100== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==100== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==100== Command: ./test -r xml "LP::testRemoveHard"
==100== 
==100== 
==100== HEAP SUMMARY:
==100==     in use at exit: 128 bytes in 4 blocks
==100==   total heap usage: 1,878 allocs, 1,874 frees, 241,389 bytes allocated
==100== 
==100== 32 bytes in 1 blocks are definitely lost in loss record 1 of 2
==100==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==100==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==100==    by 0x4400CF: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:107)
==100==    by 0x43BBFE: ____C_A_T_C_H____T_E_S_T____2() (tests-lp.cpp:44)
==100==    by 0x4736A2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==100==    by 0x463DF6: Catch::TestCase::invoke() const (catch.hpp:10793)
==100==    by 0x463D2C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==100==    by 0x460286: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==100==    by 0x45E85E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==100==    by 0x467BF6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==100==    by 0x466892: Catch::Session::runInternal() (catch.hpp:10149)
==100==    by 0x46655A: Catch::Session::run() (catch.hpp:10106)
==100== 
==100== 96 bytes in 3 blocks are definitely lost in loss record 2 of 2
==100==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==100==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==100==    by 0x4400CF: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:107)
==100==    by 0x43BC2C: ____C_A_T_C_H____T_E_S_T____2() (tests-lp.cpp:47)
==100==    by 0x4736A2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==100==    by 0x463DF6: Catch::TestCase::invoke() const (catch.hpp:10793)
==100==    by 0x463D2C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==100==    by 0x460286: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==100==    by 0x45E85E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==100==    by 0x467BF6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==100==    by 0x466892: Catch::Session::runInternal() (catch.hpp:10149)
==100==    by 0x46655A: Catch::Session::run() (catch.hpp:10106)
==100== 
==100== LEAK SUMMARY:
==100==    definitely lost: 128 bytes in 4 blocks
==100==    indirectly lost: 0 bytes in 0 blocks
==100==      possibly lost: 0 bytes in 0 blocks
==100==    still reachable: 0 bytes in 0 blocks
==100==         suppressed: 0 bytes in 0 blocks
==100== 
==100== For counts of detected and suppressed errors, rerun with: -v
==100== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

```



### ✓ - [7/7] - LP::testResizeOnce

- **Points**: 7 / 7

```
==102== Memcheck, a memory error detector
==102== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==102== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==102== Command: ./test -r xml "LP::testResizeOnce"
==102== 
==102== 
==102== HEAP SUMMARY:
==102==     in use at exit: 0 bytes in 0 blocks
==102==   total heap usage: 2,010 allocs, 2,010 frees, 246,349 bytes allocated
==102== 
==102== All heap blocks were freed -- no leaks are possible
==102== 
==102== For counts of detected and suppressed errors, rerun with: -v
==102== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [11/11] - LP::testResizeAll

- **Points**: 11 / 11

```
==104== Memcheck, a memory error detector
==104== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==104== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==104== Command: ./test -r xml "LP::testResizeAll"
==104== 
==104== 
==104== HEAP SUMMARY:
==104==     in use at exit: 0 bytes in 0 blocks
==104==   total heap usage: 1,909 allocs, 1,909 frees, 239,837 bytes allocated
==104== 
==104== All heap blocks were freed -- no leaks are possible
==104== 
==104== For counts of detected and suppressed errors, rerun with: -v
==104== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [6/6] - LP::testInsertEasy

- **Points**: 6 / 6

```
==106== Memcheck, a memory error detector
==106== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==106== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==106== Command: ./test -r xml "LP::testInsertEasy"
==106== 
==106== 
==106== HEAP SUMMARY:
==106==     in use at exit: 0 bytes in 0 blocks
==106==   total heap usage: 1,855 allocs, 1,855 frees, 240,653 bytes allocated
==106== 
==106== All heap blocks were freed -- no leaks are possible
==106== 
==106== For counts of detected and suppressed errors, rerun with: -v
==106== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/10] - LP::testInsertHard

- **Points**: 0 / 10

```
==108== Memcheck, a memory error detector
==108== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==108== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==108== Command: ./test -r xml "LP::testInsertHard"
==108== 
==108== 
==108== HEAP SUMMARY:
==108==     in use at exit: 64 bytes in 2 blocks
==108==   total heap usage: 1,877 allocs, 1,875 frees, 241,357 bytes allocated
==108== 
==108== 64 bytes in 2 blocks are definitely lost in loss record 1 of 1
==108==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==108==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==108==    by 0x4400CF: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:107)
==108==    by 0x43F2FA: ____C_A_T_C_H____T_E_S_T____10() (tests-lp.cpp:139)
==108==    by 0x4736A2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==108==    by 0x463DF6: Catch::TestCase::invoke() const (catch.hpp:10793)
==108==    by 0x463D2C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==108==    by 0x460286: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==108==    by 0x45E85E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==108==    by 0x467BF6: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==108==    by 0x466892: Catch::Session::runInternal() (catch.hpp:10149)
==108==    by 0x46655A: Catch::Session::run() (catch.hpp:10106)
==108== 
==108== LEAK SUMMARY:
==108==    definitely lost: 64 bytes in 2 blocks
==108==    indirectly lost: 0 bytes in 0 blocks
==108==      possibly lost: 0 bytes in 0 blocks
==108==    still reachable: 0 bytes in 0 blocks
==108==         suppressed: 0 bytes in 0 blocks
==108== 
==108== For counts of detected and suppressed errors, rerun with: -v
==108== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```



---