/********************************************************************
* Description:
* Author: Vagrant User <>
* Created at: Thu May 27 11:42:40 UTC 2021
* Computer: freebsd
* System: FreeBSD 12.2-STABLE on amd64
*
* Copyright (c) 2021 Vagrant User  All rights reserved.
*
********************************************************************/
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
#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 255.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS "*******************************************"
int menu(void);
int getnights(void);
void showprice(double rate, int nights);
