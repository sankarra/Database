# Database
In this project, I implemented a database using binary search trees. I have a student BST and a faculty BST to hold student and faculty data respectively. This program also uses templates to promote multi-functionality. All comparison of student and faculty data is based on the id of the student or faculty. Another feature implemented in this program is the ability to rollback a transaction. In this program, we treat a series of up to 5 updates as a transaction. We remember the updates done to the BST using a stack data structure (operation, student and faculty stacks) and use the stack to undo the changes. 

I have included my source text files, studentTable and facultyTable in which the program can be run on. My program separates data based on commas.
