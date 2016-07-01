# NonEquiprobable-Random-Distribution

### distrib_generator
  * takes number of probabilities to generate and optionally PRG seed (as command line arguments)
  * returns nonequiprobable distribution of probabilities, (as space-separated array of floating point values, to STDOUT)
  * currently implemented as gaussian distribution
  * Sum of probabilities is obviously equal to 1
  * sample usage:
```
$ ./distrib_generator 4
0.161612 0.192579 0.369044 0.276765
$ ./distrib_generator 4 42
0.211431 0.16566 0.357825 0.265084
$ ./distrib_generator 4 42
0.211431 0.16566 0.357825 0.265084
```
