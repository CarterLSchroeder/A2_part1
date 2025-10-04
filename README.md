# A2_part1
The Star Wars program shows how fork() and wait() work. There are four characters that each adjust their own shield.
The MF starts with 50% power. Create a loop using a fork that creates four child processes. Each of these processes
prints the name of the character and their adjusted shield value. There is a separate answer for each character
and wait() is used to wait for all child processes to be finished before the parent prints the final shield. 



The process sums program splits up the work of adding numbers from one to N using processes. 
I used fork() to create child processes and used a pipe to send the partial sum back to the parent. 
In the parent process, waitpid() is used to make sure the child is finished before getting the sum of the results.
It will make an array and split it into four segments, call fork(), and sum the child's segments and result to the parent
Use call waitpid() to wait for the child to finish, then read from the pipes and add then print the final sum. 
