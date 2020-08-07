#############################################################
How to run the code:
1. All the execution shoild take place on a full sized terminal.
2. The .exe is not provided. editor.c should be compiled to create a.out which can then be executed.
3. editor.c and home.txt should be in the same folder at the time of execution.
#############################################################
Observing output:
1. When a.out is run, the user is taken to the home page. It asks him the choice of task to be performed:
    a. write and save a file.
    b. edit a file(by rewriting or adding more text).
    c. saving a duplicate of a file(save as feature).
    d. search for a word/pattern and highlight it (find feature).
    e. comparing two files.
    f. deleting a file.

2. If the user enters w(case insensitive), he/she will be prompted to enter text.
3. Since user input is read through a buffer, paragraph is changed by .. instead of enter.
4. The user keeps on entering text till he/she enters NO (case sensitive) on a new line.
5. The user is then asked if he/she wants to read what has been written.
6. If 1 is entered, the text is shown in a rectangular box(in the center of screen).
7. The user is then asked to save the text with a suitable name(only alphabets or numbers without any extension).
8. The textfile is then saved ,having the entererd filename and is stored in the same folder as the editor.c file.

9. If the user enters e(case insensitive), he/she will be asked whether to rewrite an existing file(1) or add text to an existing file(2).
10. If the user entered 1, the name of file to be rewritten will be asked.
11. Then user will be prompted for input in the same way as in write mode.
12. When the user enters NO, he/she will be asked if he wants to save changes and then they will be kept or discarded accordingly.
13. If 1 is entered, the user is asked if he wants to see the changed file and accordingly the file is shown.
Caution: If the user enters anything other than 1 or 2 here, the details in the file will be lost. 
14. Had the user entered 2, the name of file to which text will be added is asked.    
15. Then user will be prompted for input in the same way as in write mode.
16. When the user enters NO, the same result will be observed as for 1.

17. If the user enters s(case insensitive), he/she will be asked for the name of file that has to be resaved.
18. The user will then be asked if he/she wants to read its contents before resaving and accordingly the text will/will not be displayed.
19. He/she will then be asked for the name of file and the file will then be saved. (Original file will remain available)

20. If the user enters f(case insensitive), he/she will be asked for a word/pattern to be searched(max length is 25).
21. He/She will then be asked for the file in which the pattern is to be searched. (File cannot contain more than 1000 words.)
22. The user will then be provided the search results.
23. If match is found, the results will be stored in search.txt (available in the same folder).
24. If the search results are saved, the file will contain escape sequences for color change so the file may not be readable in an editor but can be easily read from terminal (cat search.txt).

25. If the user enters c(case insensitive), he/she will be asked for the name of both of the files whose data is to compared.
26. After comparison, the result will be displayed.

27. If the user enters d(case insensitive), he/she will be asked for the name of file which is to deleted.
28. Before deleting, the user will again be prompted to confirm deletion.
29. If 1 is pressed, the file will be deleted otherwise it won't be.

30. Had the user entered any other alphabet, the program would have closed with an appropriate message.
############################################################
Known limitations of the code:
1. Some of the data has been hard-coded so some output may not show up as expected(especially home page and data read in write mode shown in box). The screenshot of expected output of both the cases are attached. Also the correctness of data read can be verified by cat filename.txt on terminal after the program ends and code for home page(home.c) is also provided along with home.txt.  
2. In word/pattern search, the max size of pattern to searched has been fixed at 25 characters and the file in which search is done cannot have more than 1000 words.
3. Any text file that is to be used has to be in the same folder as editor.c .There is no way of providing path to the file.
4. Further due to time constraints, feature to add text at any user defined position was not added. (NOTE: Nothing was spoken about this feature in the abstract. We came up with it later)
#############################################################
The code was developed together by Saijal and Sujay as an entry in Code Cops event.
#############################################################
