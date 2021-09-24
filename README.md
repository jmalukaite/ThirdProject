# V.01
###### Variables
In this realization data is saved using array of objects. The structure of an object called **Studentas** has seven variables, including *Vardas*, *Pavarde*, *ndSkaicius*, *namuDarbai*, *namuDarbuSuma*, *egzaminas* and *galutinis*.

###### Functions
In the file there are seven functions:
1. **StudentoDuomenuSuvedimas**. The user has to input the names and last names of students and choose whether their marks should be randomized or written by hand.
2. **AtsitiktinisPazymiuSuvedimas**. If the user wrote 'A' in the console, a function that randomizes the marks of homework and exam is called. At the same time, the sum of marks received from homework is being calculated.
3. **PazymiuSuvedimasRanka**. If the user chose to input marks by hand, they can do so by writing as many marks as wished and stop by writing '0'.
4. **NamuDarbuVidurkioSkaiciavimas**. The function returns the average mark of homework.
5. **NamuDarbuMedianosSkaiciavimas**. The function returns the median of homework. Firstly, the marks are sorted using *sort()* algorithm and then the middle element, which is the median, is found.
6. **GalutinioSkaiciavimas**. This function returns the mark of the whole course. For the calculating part, a formula is used:
<img width="347" alt="Screenshot 2021-09-24 at 19 20 47" src="https://user-images.githubusercontent.com/76739304/134708420-eff8d79f-67ad-4106-a6e5-336888606996.png"> \
The user can choose, whether the median or average should be used.
7. **Spausdinimas**. Prints the results: name, last name and final mark.

###### Example of Implementation
<img width="1136" alt="Screenshot 2021-09-24 at 18 48 23" src="https://user-images.githubusercontent.com/76739304/134704369-880247ee-669e-4601-a3d9-7ed5cd2381bd.png">
