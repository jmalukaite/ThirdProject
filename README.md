# v.03
##What's new?
- CODE REFACTORING. Functions trasferred to few cpp files according to the work they do, for example *pazymiuSuvedimas.cpp* contains to functions *AsitiktinisPazymiuSuvedimas()* and *PazymiuSuvedimasRanka()*. The headers of the functions transferred to .h files accordingly by the .cpp files.
- EXCEPTION HANDLING. The name of the file is checked when the program tries to open it and if the name is incorrect or the file is chosen wrongly, an error is shown. What is more, an error is printed when a user tries to input a mark that is negative. The error reminds the user that all marks must be positive numbers.
