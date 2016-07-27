# NonEquiprobable-Random-Distribution

### distrib_generator
  * takes number of outcomes of random event to generate and optionally PRG seed (as command line arguments)
  * returns nonequiprobable distribution of outcome probabilities, (as space-separated array of floating point values, to STDOUT)
  * currently implemented as gaussian distribution
  * sum of probabilities is obviously equal to 1
  * sample usage:
```
$ ./distrib_generator 4
0.161612 0.192579 0.369044 0.276765
$ ./distrib_generator 4 42
0.211431 0.16566 0.357825 0.265084
$ ./distrib_generator 4 42
0.211431 0.16566 0.357825 0.265084
```


### random_value
  * takes number of values to return as command line argument
  * also takes optional PRG seed
  * returns plenty of random values in range [0;1) to STDOUT
  * Why not use shell utilities for random?
    * Want to use same (seed based) mechanism as in distribution generator
    * More convenient way to get real [0...1) value  
  * sample usage:
```
$ ./random_value 1
0.847809
$ ./random_value 1 42
0.524587
$ ./random_value 1 42
0.524587
```  

### validator
  * TODO description


### trivial_solver
  * takes several values, whitespace separated, from STDIN:
    * number of random event outcomes
    * distribution of outcome probabilities itself
    * number of random values
    * random values set as well
  * returns indices of occured outcomes to STDOUT
  * uses straight trivial algorithm: incrementally iterates over distribution
  * sample usage:
```
$ ./trivial_solver < ../tests/trivial_solver_1.txt
0 1 2
```


### Attempt 1
  * reads input as trivial_solver does
  * sorts probabilities in descending order, maintaining their original position
  * performance depends on distribution properties
  * works about **1.2** times faster than trivial_solver, on gaussian distribution from distrib_generator
  * solves problem **only partially**:
    * although it produces proper random distribution of outcomes on abstract random values set
    * on fixed random values set, exact answers will not match trivial_solver's one    

### Attempt 2
  * reads input as trivial_solver does
  * builds enhanced distribution array, by adding sum of previous elements to next one (this action also makes array sorted)
  * performs binary search of given random values on enhanced array
  * performance is almost independent of distribution properties
  * works about **1.7** times faster than trivial_solver
  * **Quite rarely** results get messed up (some of them - 50% or more - cease to match answers from trivial_solver). More interestingly, it happens simultaneously with abnormal *Attempt 1* percent of matching answers (usually it has less than 0.1% matched) - about 50% or more matches. **AND** sum of matched percents of *Attempts 1* and *2* is roughly equals 100%. Wow.
    * later investigation opened following thing: it happens when there exists 'error' string in *answers.txt* (which means trivial_solver couldn't match one of distributions)
    * It is no doubt some extreme case in operations with floating point values
    * Increasing precision of fp-values to 15 digits in their string representation fixes this problem (or simply moves it probability of occurrence from *quite rare* to *nearly impossible*)

### Attempt 3
  * TODO description
