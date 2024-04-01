# MachineProject - CuyaLatosa


Execution Time Comparison:

[n = 2^20]
C        = Average execution time: 0.001433s
Assembly = Average execution time: 0.000967s

[n = 2^24]
C        = Average execution time: 0.022267s
Assembly = Average execution time: 0.016767s

[n = 2_28]
C        = Average execution time: 11.898100s
Assembly = Average execution time: 4.493033s


The assembly code runs faster than the C code because it skips some steps like function calls and uses special instructions that do multiple calculations at once. It also may access memory more efficiently.
It eliminates function call overhead by directly implementing the loop logic, utilizes SIMD instructions for parallel processing of arithmetic operations, and potentially benefits from optimized memory access patterns.
![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/a7cff023-e00c-4cd2-8236-4dca68824591)
![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/57768eeb-3750-42dd-b768-6bf40c105e3c)
![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/0f45a0c5-eed1-4b82-9e59-416430c1011e)


