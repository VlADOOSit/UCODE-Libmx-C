#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

void mx_printchar(char c);
int mx_strlen(const char* s);
void mx_printstr(const char* s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_strnew(const int size);
char* mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
void mx_str_reverse(char *s);
void mx_swap_char(char *s1, char *s2);
char *mx_itoa(int number);
void mx_foreach(const int *arr, int size, void(*f)(int));
int mx_strcmp(const char *s1, const char *s2);
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);


#endif
