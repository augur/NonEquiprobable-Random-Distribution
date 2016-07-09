# NonEquiprobable-Random-Distribution

### distrib_generator
  * takes number of probabilities to generate and optionally PRG seed (as command line arguments)
  * returns nonequiprobable distribution of probabilities, (as space-separated array of floating point values, to STDOUT)
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

### trivial_solver
  * takes several values, whitespace separated, from STDIN:
    * number of probabilities
    * distribution of probabilities itself
    * number of random values
    * random values set as well
  * returns indices of occured probabilities to STDOUT
  * uses straight trivial algorithm: incrementally iterates over distribution
  * sample usage:
```
$ ./trivial_solver < ../tests/trivial_solver_1.txt
0 1 2
```


### Attempt 1
  * TODO: description
