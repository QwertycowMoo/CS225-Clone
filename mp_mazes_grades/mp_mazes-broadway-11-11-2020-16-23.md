---

This report was generated for **kjzhou2** using **2c5a863d4dcd9f1cfcbb2bfa2de1f250e712a953** (latest commit as of **November 11th 2020, 4:23 pm**)

---




## Score: 195/215 (90.70%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c dsets.cpp -o .objs/dsets.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c maze.cpp -o .objs/maze.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part1.cpp -o .objs/tests/test_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part2.cpp -o .objs/tests/test_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/mazereader.cpp -o .objs/tests/mazereader.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/dsets.o .objs/maze.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/test_part1.o .objs/tests/test_part2.o .objs/tests/mazereader.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [10/10] - addElements1

- **Points**: 10 / 10





### ✓ - [10/10] - addElements2

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion1

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion2

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion3

- **Points**: 10 / 10





### ✓ - [5/5] - size1

- **Points**: 5 / 5





### ✓ - [10/10] - size2

- **Points**: 10 / 10





### ✓ - [10/10] - testMakeSmallMaze

- **Points**: 10 / 10





### ✓ - [10/10] - testMakeMazeConnected

- **Points**: 10 / 10





### ✓ - [10/10] - testMakeMazeAcyclic

- **Points**: 10 / 10





### ✓ - [10/10] - testMakeMazeTree1000

- **Points**: 10 / 10





### ✓ - [10/10] - testMakeMazeRandom

- **Points**: 10 / 10





### ✓ - [10/10] - testSolveMazeValidPath

- **Points**: 10 / 10





### ✓ - [10/10] - testSolutionBottomRow

- **Points**: 10 / 10





### ✓ - [10/10] - testSolutionCorrectSquare

- **Points**: 10 / 10





### ✓ - [10/10] - testSolveMazeSmall

- **Points**: 10 / 10





### ✓ - [10/10] - testSolveMazeLarge

- **Points**: 10 / 10





### ✓ - [10/10] - testDrawMazeSmall

- **Points**: 10 / 10





### ✓ - [10/10] - testDrawMazeMed

- **Points**: 10 / 10





### ✓ - [10/10] - testDrawMazeLarge

- **Points**: 10 / 10





### ✗ - [0/10] - testDrawSolutionMed

- **Points**: 0 / 10


```
Original: *actualOutput == solnImage
Expanded: PNG(w=501, h=501, hash=10000000000000)
==
PNG(w=501, h=501, hash=3fe0000000000000)
```


### ✗ - [0/10] - testDrawSolutionLarge

- **Points**: 0 / 10


```
Original: *actualOutput == solnImage
Expanded: PNG(w=5001, h=5001, hash=10000000000000)
==
PNG(w=5001, h=5001, hash=3fe0000000000000)
```


---