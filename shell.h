#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#define SEP_SLASH "/"
#define SEP_ESPAC " \t\r\n\a"

/**
 * struct built_command - anothers commands.
 * @comand: command.
 * @func: function to executing.
 */
typedef struct built_command
{
	char *comand;
	int (*func)(char *, char **, char *, char **, int, int);
} built;
void shell_loop(char **environ, char *argv);
int check_string(char *str, ssize_t length);
void non_interactive(char **environ, char *file);
int arguments1(char *file, char **environ, char *s, int out);
int check_string1(char *str, ssize_t length);
int arguments(char *s, char *file, char **environ, int count, int out);
int get_command(char *s, char **av, char *fl, char **env, int count, int out);
int (*builtin(char *s))(char *, char **, char *, char **, int, int);
int ex(char *s, char **argv, char *file, char **environ, int count, int out);
int envir(char *s, char **av, char *fl, char **env, int count, int out);
int search_command(char **argv, char *file, char **environ, int count);
int path_handler(char **argv, char *file, char **environ, int count);
char *_getenv(char **environ, char *path);
char *check_exec(char *path, char *command);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void printnumber(int number);
void printerrorex(char *file, char **argv, int count, char *message);
int is_num(char c);
void _putchar(char *c);
int _atoi(char *s);
void printerror(char *file, char *argv, int count, char *message);
void newline(int number);
void *real_loc(void *ptr, unsigned int old_size, unsigned int new_size);
void memcp(char *dest, char *src, unsigned int n);

#endif
