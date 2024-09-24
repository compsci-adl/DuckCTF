# Calculator confusion
**Category**: Misc (I think)\
**Author**: James\
**Difficulty**: Easy

### Description
ałaizd ein rotaluklak jóm ela ,ainezcilbo ecąjupętsan ćanokyw ęjubórp ,ycomop

![Equation image](src/Equation.png)

Use port xxxx

### Solution
First to understand the question we have to work out what the question is. 

If we reverse it we get: _pomocy, próbuję wykonać następujące obliczenia, ale mój kalkulator nie działa_\
Slap that into google translate and we translate the Polish to: _help, I'm trying to do the following calculations but my calculator isn't working_

When we go to the port we are promoted with: _Input your expression to be calculated:_

From this we can tell that we need to input an expression into the script. Inputting the expression normally will not work and neither will simplifying it.\
The question is written backwards (or reverse) and in polish.\
So if we use Reverse Polish Notation for the expression in the photo we will get: **127 38 sin / 16 13 2 ^ 3 14 3 / ^ - + / 8 sqrt %**

Inputting this will return the flag from the calculator app. 

TLDR: Use Reverse Polish Notation\

_Since there is a + in the formula, there are two possible answers._\
**Answer 1**: 127 38 sin / 16 13 2 ^ 3 14 3 / ^ - + / 8 sqrt %\
**Answer 2**: 127 38 sin / 13 2 ^ 3 14 3 / ^ - 16 + / 8 sqrt %\
**Flag**: quack{looC_yreV_sI_hsiloP_esreveR}
