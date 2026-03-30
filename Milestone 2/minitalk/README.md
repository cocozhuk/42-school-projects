*This project has been created as part of the 42 curriculum by kzhu.*

# Minitalk

## Description

The goal was to build a small data exchange program, to create a reliable communication channel between two independent programs, a Client and a Server, using two exclusively UNIX signals ('SIGUSR1' and 'SIGUSR2').

As it's just one on one transmissionm so the core challengde of this project is data translation, need to translate the char from prgram Client into its 8-bit binary representation using the bitwish operator. eg: 'SIGUSR1' for '1' and 'SIGUSR2' for '0'.

The server acts as a continuously running listener. It catches these incoming signals and uses bitwise shifting (`<<` and `|`) to reconstruct the bits back into their original ASCII characters, printing the message to the standard output in real-time..

## Instructions

To compile the project, clone the repository and run:
`make`
This will generate two executables: 
`server` and `client`.

1. Start the Server:
Open a terminal and run the server. It will display its Process ID (PID), and wait for incoming signals.
`./server`

2. Run the Client:
Open a second terminal window. Execute the client program by passing it the server's PID and the message you want to send.
`./client <SERVER_PID> "Hello, 42!"`


## Resources & AI Usage

References
Sending and Handling Signals in C (kill, signal, sigaction): learning then basic concept of signals between 2 programs.
https://www.youtube.com/watch?v=83M5-NPDeWs&list=PL9LZM-hWdUvsqXxqghK5H1fF07nCV9MyF
Minitalk : Goku and King Kai having a minitalk using Unix signals and sigaction in C: had a general walkthrough on this project.
https://www.youtube.com/watch?v=XqhY9WHahJQ&t=396s

AI Usage:
Explain the UNIX "Signal Dropping" phenomenon and why `usleep` is necessary to prevent data loss.
Troubleshoot `Makefile` linking errors.
