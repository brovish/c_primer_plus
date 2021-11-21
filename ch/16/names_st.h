/*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef NAMES_H_
#define NAMES_H_

#include <string.h>
#include <stdio.h>
#define SLEN 32

struct names_st
{
	char fname[SLEN];
	char lname[SLEN];
};

typedef struct names_st names;

void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);

#endif