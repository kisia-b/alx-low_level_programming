#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int _putchar(char c);
ssize_t read_textfile(const char *fname, size_t letters);
int create_file(const char *fname, char *text_content);
int append_text_to_file(const char *fname, char *text_content);

#endif /*MAIN_H*/
