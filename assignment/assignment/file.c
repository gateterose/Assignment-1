#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fileDescriptor;  // Variable to store the file descriptor

    // Open or create a file named "example.txt" for both reading and writing, with read and write permissions for the owner only
    fileDescriptor = open("example.txt", O_CREAT | O_RDWR, 0600);
    
    if (fileDescriptor < 0) {  // Check if file opening failed
        perror("Error opening file");  // Print error message
        return 1;  // Exit with error status
    }

    // Write "Hello World" to the file
    if (write(fileDescriptor, "Hello World", 11) == -1) {  // Check if write failed
        perror("Error writing to file");  // Print error message
        close(fileDescriptor);  // Close the file
        return 1;  // Exit with error status
    }
    
    // Move the file offset to the beginning of the file
    if (lseek(fileDescriptor, 0, SEEK_SET) == -1) {  // Check if seek failed
        perror("Error seeking file");  // Print error message
        close(fileDescriptor);  // Close the file
        return 1;  // Exit with error status
    }
    
    char buffer[12];  // Buffer to store read content

    // Read the content from the file into the buffer
    if (read(fileDescriptor, buffer, 11) == -1) {  // Check if read failed
        perror("Error reading from file");  // Print error message
        close(fileDescriptor);  // Close the file
        return 1;  // Exit with error status
    }
    buffer[11] = '\0';  // Null-terminate the string
    
    // Print the read content
    printf("Content read from the file: %s\n", buffer);
    
    // Close the file
    close(fileDescriptor);

    return 0;  // Exit with success status
}
