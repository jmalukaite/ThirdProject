# v.05
In this version *vector<Studentas>* was changed to *list<Studentas>*. The aim is to compare and analyze whether the reading time from generated student file and student grouping is different (and how much) using vector and list.

## Changes compairing to v.04 version
- vector<Studentas> changed to list<Studentas>.
- Only counting the time needed to read from file and group the students according to their final mark. 

## Compile time
Using vector<Studentas>:
  
<img width="556" alt="v 04 analize" src="https://user-images.githubusercontent.com/76739304/140506406-f4e60e17-2dbe-4694-9550-d310bde6d746.png">

Using list<Studentas>:
  
<img width="551" alt="v 05 analize" src="https://user-images.githubusercontent.com/76739304/140506465-15d08456-33fa-40a7-8f3e-7ed4cd7e7810.png">

## Findings
As we can see from the compile time, reading from file and grouping time is very similar using list and vector. However, grouping takes a little bit less time using list (to iterate through the list<Studentas>, iterator was included in the project).
  
## Computer characteristics
- CPU 2,3 GHz 8-Core Intel Core i9
- RAM 16 GB 2667 MHz DDR4
- Macintosh HD 1 TB
  
## Edited
  
<img width="599" alt="versija05" src="https://user-images.githubusercontent.com/76739304/143242447-4fbbdf0d-dbe4-4629-9f21-7ccca28f1d2c.png">
