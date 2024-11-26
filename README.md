# LBYARCH-MCO2
## Matrix Acceleration

### Execution time and short analysis of the performance

    10 = ave. 0 ms
    100 = ave. 0 ms
    1000 = ave. 0 ms
    10000 = ave. 0.00006667 ms
    100000 = ave. 0.002333 ms

Based on the execution times, a value of Y lesser than 10,000 would result in the function being able to run faster than the timer can precisely track, leading to an estimated timer record of zero milliseconds for each run. However, having at least 10,000 values may increase the average execution time of the function, although it still always finishes running in less then one millisecond. With these being said, the use of assembly code in C-based programs can allow such programs to run quickly due to its nature as a lower-level language that can more directly communicate to the processor, compared to higher-level languages which need to be converted to a form of Assembly and then machine code first, risking small inefficiencies in the process depending on how the compiler compiles the code. <br>

### Screenshot of the program output with the correctness check <br>
![download](https://github.com/user-attachments/assets/d75d546c-5d12-414c-b98b-71c7c1ab2471) <br>
![image](https://github.com/user-attachments/assets/31e0b8ba-8774-467e-bbec-13639a6e0d39)
