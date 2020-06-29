Project 1: Tokenizer
====================
## Overview:
The objective is to build a tokenizer that maintains a history, by allowing
the user to view and recall a certain history item by using a command.

## How to Use the Program:
To compile the program type **make all** and to run it type **./exec**. To use it type
a string, then hit enter. You will be then shown results related to milestones
1 - 4. If you want to exit the program, type '0'.

## Bugs
The print_tokens function omits the very last token. For example, if you type
a string such as "How are you today?", you will get "How" "are" "you".

## Feedback by Teaching Team
1. Use fgets() instead of scanf()
2. Do not forget to include '\0' to signal the end of arrays
3. Use of modularization
4. Clean your repo to get rid of unnecessary files
5. Give meaningful names to variables



