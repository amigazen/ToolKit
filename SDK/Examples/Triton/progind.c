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
 *  progind.c - Progress indicator demo
 *
 */


/* /////////////////////////////////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////////////////////////////////////////////////////// Include our stuff // */
/* /////////////////////////////////////////////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libraries/triton.h>

#ifdef __GNUC__
#ifndef __OPTIMIZE__
#include <clib/triton_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>
#else
#include <inline/triton.h>
#include <inline/dos.h>
#include <inline/intuition.h>
#endif /* __OPTIMIZE__ */
#else
#include <proto/triton.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#endif /* __GNUC__ */


/* /////////////////////////////////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////////////////////////////////////////////////////////// Window 'main' // */
/* /////////////////////////////////////////////////////////////////////////////////////////////////////// */

enum IDs {ID_MAIN_GADGET_STOP=1, ID_MAIN_PROGIND};


VOID do_main(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *project;
  ULONG i;

  if(project=TR_OpenProjectTags(Application,
    WindowID(1),
    WindowTitle("Progress Indicator Demo"),
    WindowPosition(TRWP_CENTERDISPLAY),
    WindowFlags(TRWF_NOCLOSEGADGET|TRWF_NOESCCLOSE),

    VertGroupA,
      Space,  CenteredText("Working..."),
      Space,  HorizGroupA,
                Space, Progress(100,0,ID_MAIN_PROGIND), /* A per cent progress indicator */
                Space, EndGroup,
      SpaceS,HorizGroupA,
                Space, HorizGroupSA, TextN("000%"), Space, TextN("050%"), Space, TextN("100%"), EndGroup,
                Space, EndGroup,
      Space, HorizGroupSA,
                Space, ButtonE("_Stop",ID_MAIN_GADGET_STOP),
                Space, EndGroup,
      Space, EndGroup,

    EndProject))
  {
    for(i=0;(i<100)&&(!close_me);i++)
    {
      /* Wait 1/5 second. You might want to do some real work here ;) */

      Delay(10L);

      /* Display our progress */

      TR_SetAttribute(project,ID_MAIN_PROGIND,TRAT_Value,i);

      /* And Check for the 'Stop' gadget. Note that you always have to include
         such a TR_GetMsg() loop, even if there's no gadget for stopping. You
         have to call TR_GetMsg() regularly so that Triton may react on the
         user's wishes, e.g. redrawing the window contents after a resize. */

      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==project) switch(trmsg->trm_Class)
        {
          case TRMS_CLOSEWINDOW:
            close_me=TRUE;
            break;

          case TRMS_ERROR:
            puts(TR_GetErrorString(trmsg->trm_Data));
            break;

          case TRMS_ACTION:
            if(trmsg->trm_ID==ID_MAIN_GADGET_STOP) close_me=TRUE;
        }
        TR_ReplyMsg(trmsg);
      }
    }
    TR_CloseProject(project);
  }
  else puts("Can't open window.");
}


/* /////////////////////////////////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////////////////////////////////////////////////////////// Main function // */
/* /////////////////////////////////////////////////////////////////////////////////////////////////////// */

int main(void)
{
  if(TR_OpenTriton(TRITON11VERSION,TRCA_Name,"trProgIndDemo",TRCA_Version,"1.0",TAG_END))
  {
    do_main();
    TR_CloseTriton();
    return 0;
  } else puts("Can't open triton.library v2+.");

  return 20;
}
