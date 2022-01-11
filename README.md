These are solutions written in c for the Advent of Code - 2021. 
See https://adventofcode.com/2021

Each problem generally has two parts. Examples of filenames for day 7 are:
- d07a.c - solution for first part
- d07b.c - solution for second part
- d07x.txt - example data set
- d07a.txt - problem data set; the same for both parts.

Files of the sort d07b.c may not exist if the two parts of the problem were
similar enough to do both in d07a.c.

The c programs generally have an fopen statement where I can change the data
file and recompile to go between example and pronlem datasets.

Sometimes, as in day 8, there may be a third program, eg d08c.c. This is an
indication I thought of a better/different way to do some part of the problem.

There may be a file like d07notes.txt if I felt more explanation was needed,
or just felt like making general comments. Sometimes it is just additional
compilation notes.

These are not examples of good coding style nor necessarily of good code
as they are one-offs where getting them to work quickly and correctly was the
main objective. (Though I have cleaned them up a bit to remove debugging
printfs() and such.) (Also, unlike most people, I find code with a minimum of
extraneous spaces easier to read. YMMV) 
