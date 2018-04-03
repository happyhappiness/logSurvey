
/*
 * $Id: win32.cc,v 1.7 2003/02/21 22:50:13 robertc Exp $
 *
 * * * * * * * * Legal stuff * * * * * * *
 *
 * (C) 2001 Guido Serassio <serassio@libero.it>,
 *   inspired by previous work by Romeo Anghelache & Eric Stern.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

#include "squid.h"

/* This code compiles only CygWin & Windows NT Port */
#if defined(_SQUID_MSWIN_) || defined(_SQUID_CYGWIN_)
#include <windows.h>

static unsigned int GetOSVersion();

/* ====================================================================== */
/* LOCAL FUNCTIONS */
/* ====================================================================== */

static unsigned int
GetOSVersion()
{
