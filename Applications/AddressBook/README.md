# Challenge Solution

In this repo I will be submitting my solution to the coding challenge of the 26th of January.

## Behaviour

+ **Add** option: asks the user to input certain pieces of information and adds an entry to the database.
+ **Remove** option: gets a keyword and a type of search from the user and removes the matching entries (if multiple entries have the same value in a field, it should ask further information to the user to know which is the entry they want removed, but this has not yet been implemented).
+ **Search** option: receives a keyword and a type of search and performs the search using a hash_table.

+ Name, other names, street, town and country format: only letters and spaces.
+ Email format: includes an '@' and a '.'. The first before the later. The dot is 2+ characters before the end of the email.
+ Phone format: contains 8 or 9 digits and nothin else than digits.

## Issues with the code

+ Each of the search options check if the provided string is found in the database as the corresponding field of an individual. If it's found the system print a message notifying that it was found (it may be one match or multiple). If this search is performed to delete an entry, it will delete all of the matches.
+ This escalates well in execution times but not so efficiently in terms of space as every hash map contains it's keys in string format. In general string usage should be checked because I feel the number of string copies and allocations could be improved.

## Planning 3 weeks of development.

I tried to lay out the code to be used as base for future work. I designed the classes and methods so any other developer could complete their functionality easily and without needing to refactor. If I had 3 weeks to develop this I would structure it in a similar way (although more polished). I would maybe separate the interface (although it's just through the console) from the main application so eventually it could be replaced by a GUI without altering the application code. I would complete and redesign the user interaction with the console which is not very fluid. I would improve the encapsulation (getters and setters and private variables) of the Person struct and would revisit it's layout to make sure it's easier to add new fields. I would have a lot of free time at the end so I would end up researching and benchmarking the hash_map against a normal ordered map or looking for a way to improve loading times (reading the save file and launching the application). 

## Stay in touch

+ Linkedin - https://www.linkedin.com/in/manuel-tabares/
