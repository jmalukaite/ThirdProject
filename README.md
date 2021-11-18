# V1.0
The code used in previous versions is implemented using two different strategies. 

First strategy:
The first strategy is to divide *Studentas studentai* container into two new containers of the same type as studentai (*Studentas zemesniojoLygio* and *Studentas aukstesniojoLygio*). The division is based on the final mark of each student.

Second strategy:
Only one new *Studentas* type container, called *zemesniojoLygio*, is created. Students that have their final mark lower than 5.00 are removed from container *studentai* and put into the new created container. This way the container *studentai* consists only of students with higher than 5.00 final mark.

## Changes compairing to previous versions
- Generating random files of 100000 students.
- Implementing mentioned strategies using list and vector.
- Optimizing code using *remove_if*.

## Optimization
The code version with vectors is optimized using *remove_if*. A new function, called *Palyginimas* is created and returns 'True' if a student's final mark is lower than 5.00. *remove_if* removes students from vector<Studentas> studentai if Palyginimas returns 'True'. Even though the code is optimized using recommended functions, the time of compiling is longer than using the first strategy. This is because of double iteration.
