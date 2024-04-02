# MachineProject - CuyaLatosa
- Cuya, Vhonne

- Latosa, Jose

 DAXPY (A*X + Y) Function

 Z[i] = A  • X [i] + Y[i] 

<h1>Execution Time Comparison:</h1>


**DEBUG**
| Language      | 2^20          | 2^24         | 2^28        |
| ------------- | ------------- | ------------ | ----------- |
| C             | 0.002333s     | 0.033333s    | 1.914567s  |
| Assembly      | 0.001333s     | 0.018367s    | 1.506967s   |


**RELEASE**
| Language      | 2^20          | 2^24         | 2^28        |
| ------------- | ------------- | ------------ | ----------- |
| C             | 0.001133s     | 0.019400s    | 5.005767s   |
| Assembly      | 0.001200s     | 0.022800s    | 5.509133s   |




When the DAXPY function coded in C and Assembly was tested across different conditions, we saw distinct patterns. In DEBUG mode, Assembly was faster than C, as expected due to its direct hardware control. However, in RELEASE mode, especially with large data sizes (2^28 elements), C outperformed Assembly, suggesting C's compiler optimizations work better for large datasets or Assembly becomes less efficient at this scale.

Interestingly, DEBUG mode showed better performance than RELEASE in some cases, particularly with C handling the largest datasets, hinting at possible optimization issues in RELEASE mode. The jump in execution time when moving from medium to large datasets in RELEASE mode for both languages points to scalability challenges, emphasizing the complexities of optimizing code for performance and the importance of effective code and memory management strategies.

<h1>Debug</h1>

![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/08dbc600-7994-4d74-ae40-2314d7e52140)
![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/5e784ca7-37e6-434e-af0a-44f7362256be)
![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/2de5b755-b96b-42d6-ad81-f43d20ef126c)


<h1>Release</h1>

![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/4f956507-c8dc-460b-8751-dec5b67e661c)
![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/2af4eca8-b499-450d-8d7f-12e0f9447cf6)
![image](https://github.com/vhonnecuya/MachineProject---CuyaLatosa/assets/85780518/b1d611e0-93f8-4b21-b879-8c691abcb4c5)



