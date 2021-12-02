# SecondProject 1.1 Version
## What's new?
- Studentas struct changed to Studentas class.
- Nuskaitymas changed to *readStudentas*, so that it would represent class criterias more correctly. readStudentas reads *vardas*, *pavarde*, *namuDarbai* and *egzaminas* of one object.
- Analysis of compiling time using struct and class.
- Analysis of compiling time using different optimization flags, such as O1, O2, O3. By default O0 is used at the beginning. The optimization level is changed in the CMakeList.txt file using commands:
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O3")

## Struct and Class compiling time
<img width="688" alt="default O0" src="https://user-images.githubusercontent.com/76739304/144506965-6596c605-0249-4d2a-a149-45f9f3ed4199.png">
As we can see from the results, when there ar 100000 students, compiling takes less time using struct than using class. However, when there are 1000000 students, compiling time is faster using class than struct.

## Changing optimization levels
### O1
<img width="642" alt="O1" src="https://user-images.githubusercontent.com/76739304/144507383-647b69e9-eb38-491f-a092-1fbb7e6af828.png">

### O2
<img width="638" alt="O2" src="https://user-images.githubusercontent.com/76739304/144507403-c50eca18-c71c-4cec-b302-8ce2a04ee257.png">

### O3
<img width="667" alt="O3" src="https://user-images.githubusercontent.com/76739304/144507421-b75274e6-4ffc-4a62-9b17-dba25a36a0ab.png">

