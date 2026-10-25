#
#  OpenTriton -- A free release of the triton.library source code
#  Copyright (C) 1993-1998  Stefan Zeiger
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
#  Makefile - Makefile for gcc
#


CC	= gcc

CFLAGS	= -O2

LFLAGS	= -ltriton -lauto

all:	Demo EnvPrint trLogo ToolManager1 ToolManager2 ToolManager3 ProgInd CustomClass

Demo: Demo.c
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

EnvPrint: EnvPrint.c
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

trLogo: trLogo.c
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

ToolManager1: ToolManager1.c
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

ToolManager2: ToolManager2.c
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

ToolManager3: ToolManager3.c
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

ProgInd: ProgInd.c
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

CustomClass: CustomClass.c
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS) -Lm
