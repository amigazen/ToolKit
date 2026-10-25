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
 *  CustomClass.c - A simple custom class
 *
 *  ****    ***   *   *  *  *****     ****    ***   *   *  ***   ***     *
 *  *   *  *   *  **  *  *    *       *   *  *   *  **  *   *   *        *
 *  *   *  *   *  * * *       *       ****   *****  * * *   *   *        *
 *  *   *  *   *  *  **       *       *      *   *  *  **   *   *
 *  ****    ***   *   *       *       *      *   *  *   *  ***   ***     *
 *
 *  It's easier than it looks!
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <libraries/triton.h>
#include <graphics/gfx.h>
#include <intuition/intuition.h>

#ifdef __GNUC__
#ifndef __OPTIMIZE__
#include <clib/triton_protos.h>
#include <clib/graphics_protos.h>
#include <clib/intuition_protos.h>
#else
#include <inline/triton.h>
#include <inline/graphics.h>
#include <inline/intuition.h>
#endif /* __OPTIMIZE__ */
#else
#include <proto/triton.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#endif /* __GNUC__ */


/**** So it shall be written, so it shall be done: ****/

/****** class_Clock ******
*
*   NAME	
*	class_Clock -- Display an analog clock.
*
*   SUPERCLASS
*	class_DisplayObject
*
*   SYNOPSIS
*	TROB_Clock
*
*   ATTRIBUTES
*	<Default>        : <unused>
*	TRAT_Clock_Hours : ULONG hours
*	                   (Default: 0)
*	                   [create, set, get]
*	TRAT_Clock_Mins  : ULONG minutes
*	                   (Default: 0)
*	                   [create, set, get]
*	TRAT_Clock_Secs  : ULONG seconds
*	                   (Default: 0)
*	                   [create, set, get]
*	TRAT_Clock_DisplaySeconds : BOOL displayseconds
*	                   (Default: TRUE)
*	                   [create, set, get]
*
******/

/**** The class tag ****/
#define TROB_Clock                  TRTG_PRVCLS(1)

/**** The attribute tags ****/
#define TRAT_Clock_Hours            TRTG_PRVOAT(1)
#define TRAT_Clock_Mins             TRTG_PRVOAT(2)
#define TRAT_Clock_Secs             TRTG_PRVOAT(3)
#define TRAT_Clock_DisplaySeconds   TRTG_PRVOAT(4)

/**** The internal representation of instances of our class ****/
struct TROD_Clock
{
  struct TROD_DisplayObject DO; /* Superclass object data */
  ULONG Hours, Mins, Secs;      /* The currently displayed time */
  BOOL DisplaySecs;             /* Display seconds? */
};

TR_CONSTRUCTOR(Clock) /* This one's called for creating an instance */
{
  /* Initialize default values */
  Self.DisplaySecs=TRUE;

  /* Let the superclass do its work (mainly argument parsing) */
  if(!TR_SUPERMETHOD) return NULL;

  /* Set some DisplayObject fields */
  Self.DO.XResize=TRUE;
  Self.DO.YResize=TRUE;
  Self.DO.MinHeight=50;
  Self.DO.MinWidth=(Self.DO.MinHeight*Self.DO.O.Project->trp_AspectFixing)/16;

  /* We need to see some IDCMP messages */
  Self.DO.O.Project->trp_IDCMPFlags|=IDCMP_MOUSEBUTTONS|IDCMP_MOUSEMOVE|IDCMP_INACTIVEWINDOW;

  /* You asked for it? Here you got it! */
  return object;
}

TR_SIMPLEMETHOD(Clock,INSTALL_REFRESH) /* 2 messages but only 1 method! */
{
  ULONG left,top,width,height;
  struct TR_Project *project;
  double r;
  int d;

  TR_SUPERMETHOD; /* Call DisplayObject's INSTALL or REFRESH method */

  project = Self.DO.O.Project;
  left    = Self.DO.Left;
  top     = Self.DO.Top;
  width   = Self.DO.Width;
  height  = Self.DO.Height;

  /* Fill background */
  TR_AreaFill(project,NULL,left,top,left+width-1,top+height-1,TRBF_NONE,NULL);

  /* Draw ticks */
  SetAPen(project->trp_Window->RPort,TR_GetPen(project,TRPT_SYSTEMPEN,FILLPEN));
  for(d=0;d<360;d+=5)
    {
      r=((double)d)*PI/180.0;
      if(d%30==0)
	{
	  SetAPen(project->trp_Window->RPort,TR_GetPen(project,TRPT_SYSTEMPEN,TEXTPEN));
	  Move(project->trp_Window->RPort,
	       (LONG)(left+width/2+(cos(r)*(width/2-1))),(LONG)(top+height/2+(sin(r)*(height/2-1))));
	  Draw(project->trp_Window->RPort,
	       (LONG)(left+width/2+(cos(r)*(width/2-1))*0.9),(LONG)(top+height/2+(sin(r)*(height/2-1))*0.9));
	  SetAPen(project->trp_Window->RPort,TR_GetPen(project,TRPT_SYSTEMPEN,FILLPEN));
	}
      else
	{
	  Move(project->trp_Window->RPort,
	       (LONG)(left+width/2+(cos(r)*(width/2-1))),(LONG)(top+height/2+(sin(r)*(height/2-1))));
	  Draw(project->trp_Window->RPort,
	       (LONG)(left+width/2+(cos(r)*(width/2-1))*0.95),
	       (LONG)(top+height/2+(sin(r)*(height/2-1))*0.95));
	}
    }

  /* Draw Circle */
  SetAPen(project->trp_Window->RPort,TR_GetPen(project,TRPT_SYSTEMPEN,TEXTPEN));
  DrawEllipse(project->trp_Window->RPort,left+width/2,top+height/2,width/2-1,height/2-1);

  /* Draw second hand (even though this code is new and original :-) */
  if(Self.DisplaySecs)
    {
      SetAPen(project->trp_Window->RPort,TR_GetPen(project,TRPT_SYSTEMPEN,FILLPEN));
      d=270+(((double)(Self.Secs))*360.0/60.0);
      r=((double)d)*PI/180.0;
      Move(project->trp_Window->RPort,left+width/2,top+height/2);
      Draw(project->trp_Window->RPort,
	   (LONG)(left+width/2+(cos(r)*(width/2-1))*0.85),(LONG)(top+height/2+(sin(r)*(height/2-1))*0.85));
    }

  /* Draw minute hand */
  SetAPen(project->trp_Window->RPort,TR_GetPen(project,TRPT_SYSTEMPEN,SHINEPEN));
  d=270+(((double)(Self.Mins))*360.0/60.0);
  r=((double)d)*PI/180.0;
  Move(project->trp_Window->RPort,left+width/2,top+height/2);
  Draw(project->trp_Window->RPort,
       (LONG)(left+width/2+(cos(r)*(width/2-1))*0.75),(LONG)(top+height/2+(sin(r)*(height/2-1))*0.75));

  /* Draw hour hand */
  d=270+(((double)(Self.Hours%12))*360.0/12.0+((double)(Self.Mins))*30.0/60.0);
  r=((double)d)*PI/180.0;
  Move(project->trp_Window->RPort,left+width/2,top+height/2);
  Draw(project->trp_Window->RPort,
       (LONG)(left+width/2+(cos(r)*(width/2-1))*0.60),(LONG)(top+height/2+(sin(r)*(height/2-1))*0.60));

  return 1; /* Everything OK */
}

TR_METHOD(Clock,SETATTRIBUTE,SetAttributeData) /* Set an attribute (upon creation or later) */
{
  /* A good way to do this properly would be:
     1) If a hand is changing erase the old hand with the background pen.
     2) Modify the value.
     3) If a hand was erased in step 1 redraw it.

     But since this is only an example program we'll do it the easy (and short) way:
     1) Modify the value.
     2) Refresh the display. */

  switch(data->attribute)
  {
    case TRAT_Clock_Hours:
      Self.Hours=data->value;
      goto dorefresh;
    case TRAT_Clock_Mins:
      Self.Mins=data->value;
      goto dorefresh;
    case TRAT_Clock_Secs:
      Self.Secs=data->value;
      goto dorefresh;
    case TRAT_Clock_DisplaySeconds:
      Self.DisplaySecs=data->value;
      goto dorefresh;
    default:
      /* Pass messages for unknown attributes on to the superclass */
      return TR_SUPERMETHOD;
    }

dorefresh:
  /* Attention! You can receive TROM_SETATTRIBUTE messages when the object
     isn't currently installed. You have to make sure the object is indeed
     installed before sending it a refresh message! */
  if(Self.DO.Installed) return TR_DoMethod(&Self.DO.O,TROM_REFRESH,NULL);
  else return 1;
}

TR_SIMPLEMETHOD(Clock,GETATTRIBUTE) /* Return a requested attribute */
{
  switch((ULONG)data)
  {
    case TRAT_Clock_Hours:
      return Self.Hours;
    case TRAT_Clock_Mins:
      return Self.Mins;
    case TRAT_Clock_Secs:
      return Self.Secs;
    case TRAT_Clock_DisplaySeconds:
      return (ULONG)(Self.DisplaySecs?TRUE:FALSE);
    default:
      /* Pass queries for unknown attributes on to the superclass */
      return TR_SUPERMETHOD;
  }
}

TR_METHOD(Clock,EVENT,EventData) /* React on IDCMP messages */
{
  struct TR_Message *trmsg;

  if((data->imsg->Class==IDCMP_MOUSEBUTTONS)
     &&(data->imsg->MouseX>=Self.DO.Left)
     &&(data->imsg->MouseX<Self.DO.Left+Self.DO.Width)
     &&(data->imsg->MouseY>=Self.DO.Top)
     &&(data->imsg->MouseY<Self.DO.Top+Self.DO.Height)
     &&(data->imsg->Code==SELECTDOWN))
    {
      DisplayBeep(NULL);
/*       if(trmsg=TR_CreateMsg(Self.DO.O.Project->trp_App)) */
/* 	{ */
/* 	  trmsg->trm_ID=Self.DO.ID; */
/* 	  trmsg->trm_Class=TRMS_ACTION; */
/* 	  return TROM_EVENT_SWALLOWED; */
/* 	} */
    }
  return TROM_EVENT_CONTINUE;
}


/**** Let's see if our class works... ****/

int main(void)
{
  int retval=20;
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *project;

  if(TR_OpenTriton(TRITON20VERSION,TRCA_Name,"CustomClass",TRCA_Info,"Triton Custom Class Demo",TRCA_Version,"1.0",TAG_END))
    {
      if(TR_AddClassTags(Application, TROB_Clock, TROB_DisplayObject, NULL, sizeof(struct TROD_Clock),
			 TROM_NEW,          TRDP_Clock_NEW,
			 TROM_INSTALL,      TRDP_Clock_INSTALL_REFRESH,
			 TROM_REFRESH,      TRDP_Clock_INSTALL_REFRESH,
			 TROM_SETATTRIBUTE, TRDP_Clock_SETATTRIBUTE,
			 TROM_GETATTRIBUTE, TRDP_Clock_GETATTRIBUTE,
			 TROM_EVENT,        TRDP_Clock_EVENT,
			 TAG_END))
	{
	  if(project=TR_OpenProjectTags(Application,
					WindowID(1), WindowPosition(TRWP_CENTERDISPLAY),
					WindowTitle("CustomClass (under construction!)"), WindowFlags(TRWF_NOMINTEXTWIDTH),
					QuickHelpOn(TRUE),
					HorizGroupA, Space, VertGroupA,
					  Space,
					  NamedFrameBox("Triton Clock"), ObjectBackfillB,
					    HorizGroupA, Space, VertGroupA,
					      Space,
					      TROB_Clock, NULL, TRAT_Clock_Hours, 5, TRAT_Clock_Mins, 42,
					        ID(1), QuickHelp("Use the mouse to drag the hands\n(NOT IMPLEMENTED YET!)"),
					      Space,
                                            EndGroup, Space, EndGroup,
					  Space, EndGroup, Space, EndGroup, EndProject))
	    {
	      while(!close_me)
		{
		  TR_Wait(Application,NULL);
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
			}
		      TR_ReplyMsg(trmsg);
		    }
		}
	      TR_CloseProject(project);
	    } else puts(TR_GetErrorString(trmsg->trm_Data));
	} else puts("Can't initialize 'Clock' custom class.");
      retval=0;
      TR_CloseTriton();
    } else puts("Can't open triton.library v6+.");

  return retval;
}
