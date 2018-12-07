----------------------
     INFORMATION
----------------------

Program name: Plagiarism Catcher
Author: Janine Bariuan, Asad Ahmed
The University of Texas at Austin
EE312 Priebe
December 7, 2018


----------------------
     UNZIP FILE
----------------------

To unzip the file, right click on the folder. If on:

- MAC, click on 'Open'
- WINDOWS, click on 'Extract All'



----------------------
      MAKE FILE 
----------------------

-- Make sure all of the following files are located in the same directory (folder): 

cheaters_driver.cpp
cheaters.h

-- On command line:

run:

	$ make -f makefile




---------------------
     RUN PROGRAM
---------------------

-- Arguments:

[1] path to folder locating all the files you want to process
[2] number of n-word sequences you would like to check for each file
[3] minimum amount of matches you would like to print out

-- On the command line:

run:

	$ ./plagiarismCatcher [1] [2] [3]

with examples:

	$ ./plagiarismCatcher sm_doc_set 6 200




----------------------
    PRE-CONDITIONS
----------------------

-- All of the files you would like to process and see if there are matches should be in the same folder.



----------------------
     CONDITIONS
----------------------

-- The larger the amount of files to process, the longer it will take.

For reference:

"sm_doc_set" with 25 files takes 13 secs.
"med_doc_set" with 75 files takes 39 secs.
"big_doc_set" with 1,354 files takes 9 minutes.






