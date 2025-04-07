# MiniTalk - Signal-Based Communication Project

## Description 

MiniTalk is a simple client-server application that demonstrates inter-process communication using Unix signals. The client sends a string to the server, where each character is transmitted as a sequence of bits (0s and 1s), and the server decodes and displays the message character by character. The communication is done using `SIGUSR1` and `SIGUSR2` signals to represent bits, and the server acknowledges receipt of each character. 

The project includes a **bonus part** where the server must send a signal back to the client to acknowledge each message received and support **Unicode characters**.

This project is part of the 42 curriculum and demonstrates the use of Unix signals for communication between processes.

## Features

### Mandatory Part:
- **Client**: Sends a string to the server one bit at a time using signals.
- **Server**: Decodes the received signal and prints the decoded message.
- **Signal Handling**: Utilizes `SIGUSR1` and `SIGUSR2` to transmit data.

### Bonus Part:
- **Acknowledgement**: The server sends a signal back to the client to acknowledge the receipt of each character.
- **Unicode Support**: The server can decode and print messages with Unicode characters (supports 8-bit encoding).

## Usage

### Client

To run the client, you need to provide the server's PID and the message to send.

```bash
./client <server_pid> <message>

