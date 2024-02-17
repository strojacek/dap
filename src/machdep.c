/* machine dependent I/O of ints and doubles */

/*  Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
 *
 *  This file is part of Dap.
 *
 *  Dap is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Dap is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Dap.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "dap_make.h"

#define CHARBASE '!'

double dap_double;	/* this is a kluge to get around weird behavior of
			 * "return" and addressing on some machines.
			 * Don't ask me, but it works.
			 */

static int putnd(unsigned int h, int n, char dstr[])
{
int d;	/* this dstr stupidity is also to get around weird behavior on some machines */

d = 0;
while (--n >= 0)
	dstr[d++] = ((h >> (6 * n)) & 0x3f) + CHARBASE;
return d;
}

int dap_dblhigh;
int dap_dbllow;

void dap_putdouble(DFILE *dfp)
{
unsigned int ix[2];
unsigned int sign;
unsigned int e;
/* more weird stuff to get around weird behavior */
char dstr[13];	/* doubles are encoded to 12 bits */
int d;

d = 0;
ix[0] = *(((unsigned int *) &dap_double) + dap_dbllow);
ix[1] = *(((unsigned int *) &dap_double) + dap_dblhigh);
if (!(ix[0] & 0x7fffffff) && !ix[1])
	{
	dstr[d++] = 'A';
	for (e = 0; e < 11; e++)
		dstr[d++] = '!';
	}
else
	{
	sign = ((ix[1] >> 20) & 0x800);
	e =((ix[1] >> 20) & 0x7ff);
	if (!e)
		{
		dstr[d++] = 'A';
		for (e = 0; e < 11; e++)
			dstr[d++] = '!';
		}
	else if (e == 0x7ff)
		{
		for (e = 0; e < 12; e++)
			dstr[d++] = 'a';
		}
	else
		{
		if (sign)
			{
			e = 0x800 - e;
			ix[1] = ((~ix[1]) & 0xfffff);
			ix[0] = (~ix[0]);
			}
		else
			e += 0x800;
		d += putnd(e, 2, dstr + d);
		d += putnd(ix[1], 4, dstr + d);
		d += putnd(ix[0], 6, dstr + d);
		}
	}
dstr[d] = '\0';
for (d = 0; dstr[d]; d++)
        dap_putc(dstr[d], dfp);
}

static unsigned int getnh(char s[], int n)
{
unsigned int h;
int i;

for (h = ((s[0] - CHARBASE) & 0x3f), i = 1; i < n; i++)
	h = ((h << 6) | ((s[i] - CHARBASE) & 0x3f));
return h;
}

void dap_getdouble(char code[])
{
unsigned int ix[2];
unsigned int sign;
unsigned int e;

if (!strncmp(code, "A!!!!!!!!!!!", 12))
	{
	dap_double = 0.0;
	return;
	}
else if (!strncmp(code, "aaaaaaaaaaaa", 12))
	{
	dap_double = 0.0 / 0.0;
	return;
	}
sign = ('!' <= code[0] && code[0] <= '@');
e = getnh(code, 2);
if (sign)
	e = ((0x800 - e) | 0x800);
else
	e -= 0x800;
ix[1] = getnh(code + 2, 4);
ix[0] = getnh(code + 6, 6);
if (sign)
	{
	ix[1] = (((~ix[1]) & 0xfffff) | (e << 20));
	ix[1] = (ix[1] | 0x80000000);
	ix[0] = (~ix[0]);
	}
else
	ix[1] = (ix[1] | (e << 20));
*(((unsigned int *) &dap_double) + dap_dbllow) = ix[0];
*(((unsigned int *) &dap_double) + dap_dblhigh) = ix[1];
}

void dap_putint(int i, DFILE *dfp)
{
int j;
int ndig;
int sign;

if (!i)
	dap_putc('0', dfp);
sign = 1;
if (i < 0)
	{
	sign = -1;
	i = -i;
	}
for (ndig = 0, j = i; j; ndig++)
	j = (j >> 6);
dap_putc('0' + sign * ndig, dfp);
if (sign > 0)
	{
	while (--ndig >= 0)
		dap_putc(((i >> (6 * ndig)) & 0x3f) + CHARBASE, dfp);
	}
else
	{
	while (--ndig >= 0)
		dap_putc(((0x40 - (i >> (6 * ndig))) & 0x3f) + CHARBASE, dfp);
	}
}

int dap_getint(char code[])
{
int i, j;
int ndig;
int sign;

if (!strncmp(code, "0", 1))
	return 0;
sign = (code[0] < '0');
if (sign)
	ndig = '0' - code[0];
else
	ndig = code[0] - '0';
if (sign)
	{
	for (j = 1, i = 0; j <= ndig; j++)
		i = ((i << 6) | (0x40 + CHARBASE - code[j]));
	}
else
	{
	for (j = 1, i = 0; j <= ndig; j++)
		i = ((i << 6) | (code[j] - CHARBASE));
	}
return (sign ? -i : i);
}
