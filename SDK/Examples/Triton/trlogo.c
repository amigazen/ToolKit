/*
 *  OpenTriton -- A free release of the triton.library source code
 *  Copyright (C) 1993-1998  Stefan Zeiger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  trLogo.c - The Triton logo
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libraries/triton.h>

#ifdef __GNUC__
#ifndef __OPTIMIZE__
#include <clib/triton_protos.h>
#else
#include <inline/triton.h>
#endif /* __OPTIMIZE__ */
#else
#include <proto/triton.h>
#endif /* __GNUC__ */


int main(void)
{
  if(TR_OpenTriton(TRITON11VERSION,TRCA_Name,"trLogo",TRCA_LongName,"trLogo",TRCA_Info,"The Triton Logo",TRCA_Version,"1.0",TAG_END))
  {
    if(TRIM_trLogo_Init())
    {
      TR_AutoRequestTags(Application,NULL,
        WindowID(1), WindowPosition(TRWP_CENTERDISPLAY),
        WindowTitle("trLogo"), WindowFlags(TRWF_NOMINTEXTWIDTH),
        BoopsiImageD(TRIM_trLogo,57,57),
        TAG_END);
      TRIM_trLogo_Free();
    }
    TR_CloseTriton();
    return 0;
  }

  puts("Can't open triton.library v2+.");
  return 20;
}
