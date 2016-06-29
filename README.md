# NonEquiprobable-Random-Distribution

### input_generator
  * takes number of probabilities to generate (as command line argument)
  * returns nonequiprobable distribution of probabilities, (as space-separated array of floating point values, to STDOUT)
  * currently implemented as gaussian distribution
  * Sum of probabilities is obviously equal to 1
  * sample usage:
  ```
  $ ./input_generator 4
  0.161612 0.192579 0.369044 0.276765 
  ```
