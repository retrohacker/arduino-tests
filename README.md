# Arduino unit test experiment

Playing around with writing unit tests for the arduino

Write tests as self contained single-file c++ programms in the `./tests` directory.

Mock libraries in the `./mocks` directory.

# Approach

This approach to testing uses `gcc` to test your logic locally without having to upload a sketch to an arduino.

We accomplish this by providing our own Arduino header w/ our own implementation and having `gcc` use that.

This repo demonstrates the approach using the Arduino tutorial for [building libraries](https://www.arduino.cc/en/Hacking/LibraryTutorial).

# Example Output

Since each test is a separate target/binary we can run them in parallel

```text
$ make -j10 test
Building Morse.o...
Building mocks/Arduino.o...
Validating we waited four times... [OK]
Validating first wait less than second... [OK]
Validating pin was toggled... [OK]
Validating pin was set high first... [OK]
Validating pin was then set low... [OK]
Validating we waited twice... [OK]
Validating pin was toggled... [OK]
Validating pin was set high first... [OK]
Validating pin was then set low... [OK]
Validating we waited twice... [OK]
Validating pinmode was set to 0... [OK]
Validating pinmode was set to 1... [OK]
Validating pinmode was set to 2... [OK]
+-------------------+
| All tests passing |
+-------------------+
```
