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
 *  demo.c - Triton demo program
 *
 */


/*************************************************************************************** Include our stuff */

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


/********************************************************************************* Disable CTRL-C handling */

#ifdef __GNUC__
__chkabort(){}
#else
#ifdef __SASC__
int CXBRK(void) { return(0); }
int chkabort(void) { return(0); }
#endif
#endif


/**************************************************************************************** Global variables */

struct TR_Project *main_project;


/***************************************************************************************** Window 'groups' */

ProjectDefinition(groups_trwintags)
{
  WindowTitle("Groups"), WindowPosition(TRWP_CENTERDISPLAY), WindowUnderscore("~"), WindowID(1),

  HorizGroupA, Space, VertGroupA,
    Space,

    NamedFrameBox("TRGR_PROPSHARE (default)"), ObjectBackfillWin, VertGroupA, Space, HorizGroupC,
      Space,
      Button("Short",1),
      Space,
      Button("And much, much longer...",2),
      Space,
      EndGroup, Space, EndGroup,

    Space,

    NamedFrameBox("TRGR_EQUALSHARE"), ObjectBackfillWin, VertGroupA, Space, HorizGroupEC,
      Space,
      Button("Short",3),
      Space,
      Button("And much, much longer...",4),
      Space,
      EndGroup, Space, EndGroup,

    Space,

    NamedFrameBox("TRGR_PROPSPACES"), ObjectBackfillWin, VertGroupA, Space, HorizGroupSC,
      Space,
      Button("Short",5),
      Space,
      Button("And much, much longer...",6),
      Space,
      EndGroup, Space, EndGroup,

    Space,

    NamedFrameBox("TRGR_ARRAY"), ObjectBackfillWin, VertGroupA, Space, LineArray,
      BeginLine,
        Space,
        Button("Short",7),
        Space,
        Button("And much, much longer...",8),
        Space,
        EndLine,
      Space,
      BeginLine,
        Space,
        Button("Not so short",9),
        Space,
        Button("And a bit longer...",10),
        Space,
        EndLine,
      Space,
      BeginLineI,
        NamedSeparator("An independent line"),
        EndLine,
      Space,
      BeginLine,
        Space,
        Button("foo bar",12),
        Space,
        Button("42",13),
        Space,
        EndLine,
      EndArray, Space, EndGroup,

    Space,
    EndGroup, Space, EndGroup,
  EndProject
};


VOID do_groups(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *groups_project;

  if(groups_project=TR_OpenProject(Application,groups_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==groups_project) switch(trmsg->trm_Class)
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
    TR_UnlockProject(main_project);
    TR_CloseProject(groups_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/****************************************************************************************** Window 'menus' */

struct TagItem menus_trwintags[]=
{
  WindowID(2), WindowTitle("Menus"),

  TRMN_Title,                 (ULONG) "A menu",
   TRMN_Item,                 (ULONG) "A simple item", TRAT_ID, 1,
   TRMN_Item,                 (ULONG) "Another item", TRAT_ID, 2,
   TRMN_Item,                 (ULONG) "And now... a barlabel", TRAT_ID, 3,
   TRMN_Item,                 (ULONG) TRMN_BARLABEL,
   TRMN_Item,                 (ULONG) "1_An item with a shortcut", TRAT_ID, 4,
   TRMN_Item,                 (ULONG) "2_Another one", TRAT_ID, 5,
   TRMN_Item,                 (ULONG) "3_And number 3", TRAT_ID, 6,
   TRMN_Item,                 (ULONG) TRMN_BARLABEL,
   TRMN_Item,                 (ULONG) "_F1_And under OS3.0: Extended command keys", TRAT_ID, 6,
   TRMN_Item,                 (ULONG) "_F2_Another one", TRAT_ID, 7,
   TRMN_Item,                 (ULONG) TRMN_BARLABEL,
   TRMN_Item,                 (ULONG) "How do you like submenus?",
    TRMN_Sub,                 (ULONG) "G_Great!", TRAT_ID, 8,
    TRMN_Sub,                 (ULONG) "F_Fine", TRAT_ID, 9,
    TRMN_Sub,                 (ULONG) "D_Don't know", TRAT_ID, 10,
    TRMN_Sub,                 (ULONG) "N_Not so fine", TRAT_ID, 11,
    TRMN_Sub,                 (ULONG) "P_Puke!", TRAT_ID, 12,

  TRMN_Title,                 (ULONG) "Another menu",
   TRMN_Item,                 (ULONG) "This item is ghosted", TRMN_Flags, TRMF_DISABLED, TRAT_ID, 100,
   TRMN_Item,                 (ULONG) TRMN_BARLABEL,
   TRMN_Item,                 (ULONG) "Item 1 is checked", TRMN_Flags, TRMF_CHECKED, TRAT_ID, 13,
   TRMN_Item,                 (ULONG) "Item 2 can be checked, too", TRMN_Flags, TRMF_CHECKIT, TRAT_ID, 14,

  TRMN_Title,                 (ULONG) "Ghosted menu",
  TRMN_Flags,                 (ULONG) TRMF_DISABLED,
   TRMN_Item,                 (ULONG) "Item 1", TRAT_ID, 101,
   TRMN_Item,                 (ULONG) "Item 2", TRAT_ID, 102,

  TAG_END
};


VOID do_menus(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *menus_project;

  if(menus_project=TR_OpenProject(Application,menus_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==menus_project) switch(trmsg->trm_Class)
        {
          case TRMS_CLOSEWINDOW:
            close_me=TRUE;
            break;

          case TRMS_ERROR:
            puts(TR_GetErrorString(trmsg->trm_Data));
            break;

          case TRMS_NEWVALUE:
            printf("The new value of object %d is %d.\n",trmsg->trm_ID,trmsg->trm_Data);
            break;

          case TRMS_ACTION:
            printf("Object %d has triggered an action.\n",trmsg->trm_ID);
            break;
        }
        TR_ReplyMsg(trmsg);
      } 
    }
    TR_UnlockProject(main_project);
    TR_CloseProject(menus_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/**************************************************************************************** Window 'gadgets' */

STRPTR cycle_entries[]=
{
  "Entry 0",
  "1",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  NULL
};


STRPTR mx_entries[]=
{
  "Choice 0",
  "Choice 1",
  "Choice 2",
  NULL
};


struct TagItem gadgets_trwintags[]=
{
  WindowID(3),
  WindowTitle("Gadgets"),
  WindowPosition(TRWP_CENTERDISPLAY),

  TRGR_Vert,                  (ULONG) TRGR_PROPSHARE|TRGR_ALIGN,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_CENTER,
      TROB_Space,             (ULONG) NULL,
      TROB_Line,              (ULONG) TROF_HORIZ,
      TROB_Space,             (ULONG) NULL,
      TROB_Text,              (ULONG) NULL, TRAT_Text, (ULONG) "GadTools", TRAT_Flags, (ULONG) TRTX_TITLE,
      TROB_Space,             (ULONG) NULL,
      TROB_Line,              (ULONG) TROF_HORIZ,
      TROB_Space,             (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_CheckBox,        (ULONG) NULL,
          TRAT_ID,            (ULONG) 1,
          TRAT_Value,         (ULONG) TRUE,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "_Checkbox",
          TRAT_ID,            (ULONG) 1,
        TROB_Space,           (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_Slider,          (ULONG) NULL,
          TRAT_ID,            (ULONG) 4,
          TRSL_Min,           (ULONG) 1,
          TRSL_Max,           (ULONG) 3,
          TRAT_Value,         (ULONG) 1,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "_Slider: ",
          TRAT_ID,            (ULONG) 4,
        TROB_Text,            (ULONG) NULL,
          TRAT_Value,         (ULONG) 1,
          TRAT_ID,            (ULONG) 4,
          TRAT_MinWidth,      (ULONG) 3,
      TROB_Space,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_Scroller,        (ULONG) NULL,
          TRAT_ID,            (ULONG) 5,
          TRAT_Value,         (ULONG) 2,
          TRSC_Total,         (ULONG) 7,
          TRSC_Visible,       (ULONG) 3,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "Sc_roller: ",
          TRAT_ID,            (ULONG) 5,
        TROB_Text,            (ULONG) NULL,
          TRAT_Value,         (ULONG) 2,
          TRAT_ID,            (ULONG) 5,
          TRAT_MinWidth,      (ULONG) 3,
      TROB_Space,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_Palette,         (ULONG) NULL,
          TRAT_ID,            (ULONG) 3,
          TRAT_Value,         (ULONG) 1,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "_Palette: ",
          TRAT_ID,            (ULONG) 3,
        TROB_Text,            (ULONG) NULL,
          TRAT_Value,         (ULONG) 1,
          TRAT_ID,            (ULONG) 3,
          TRAT_MinWidth,      (ULONG) 3,
      TROB_Space,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_Cycle,           (ULONG) cycle_entries,
          TRAT_ID,            (ULONG) 6,
          TRAT_Value,         (ULONG) 4,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "C_ycle: ",
          TRAT_ID,            (ULONG) 6,
        TROB_Text,            (ULONG) NULL,
          TRAT_Value,         (ULONG) 4,
          TRAT_ID,            (ULONG) 6,
          TRAT_MinWidth,      (ULONG) 3,
      TROB_Space,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_Cycle,           (ULONG) mx_entries,
          TRAT_ID,            (ULONG) 13,
          TRAT_Value,         (ULONG) 1,
          TRAT_Flags,         (ULONG) TRCY_MX,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "_MX: ",
          TRAT_ID,            (ULONG) 13,
        TROB_Text,            (ULONG) NULL,
          TRAT_Value,         (ULONG) 1,
          TRAT_ID,            (ULONG) 13,
          TRAT_MinWidth,      (ULONG) 3,
        TROB_Space,           (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_String,          (ULONG) "foo bar",
          TRAT_ID,            (ULONG) 7,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "S_tring",
          TRAT_ID,            (ULONG) 7,
      TROB_Space,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_String,          (ULONG) "",
          TRAT_Flags,         (ULONG) TRST_INVISIBLE,
          TRAT_ID,            (ULONG) 15,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "Pass_word",
          TRAT_ID,            (ULONG) 15,
      TROB_Space,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER,
      TRGR_Horiz,             (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
        TROB_Space,           (ULONG) NULL,
        TROB_String,          (ULONG) "0.42",
          TRAT_Flags,         (ULONG) TRST_FLOAT,
          TRST_Filter,        (ULONG) "01234567.,",
          TRAT_ID,            (ULONG) 16,
      TRGR_End,               (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
        TROB_Text,            (ULONG) NULL,
          TRAT_Text,          (ULONG) "_Octal float",
          TRAT_ID,            (ULONG) 16,
      TROB_Space,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_CENTER,
      TROB_Space,             (ULONG) NULL,
      TROB_Line,              (ULONG) TROF_HORIZ,
      TROB_Space,             (ULONG) NULL,
      TROB_Text,              (ULONG) NULL, TRAT_Text, (ULONG) "BOOPSI", TRAT_Flags, (ULONG) TRTX_TITLE,
      TROB_Space,             (ULONG) NULL,
      TROB_Line,              (ULONG) TROF_HORIZ,
      TROB_Space,             (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
      TROB_Space,             (ULONG) NULL,
      TROB_Button,            (ULONG) NULL, TRAT_ID, 2, TRAT_Text, (ULONG) "_Button",
      TROB_Space,             (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER,
      TROB_Space,             (ULONG) NULL,
      TROB_Text,              (ULONG) NULL, TRAT_Text, (ULONG) "_File:", TRAT_ID, 10,
      TROB_Space,             (ULONG) NULL,
      TROB_Button,            (ULONG) TRBT_GETFILE, TRAT_ID, 10, TRAT_Text, (ULONG) "",
      TROB_Space,             (ULONG) NULL,
      TROB_Text,              (ULONG) NULL, TRAT_Text, (ULONG) "_Drawer:", TRAT_ID, 11,
      TROB_Space,             (ULONG) NULL,
      TROB_Button,            (ULONG) TRBT_GETDRAWER, TRAT_ID, 11, TRAT_Text, (ULONG) "",
      TROB_Space,             (ULONG) NULL,
      TROB_Text,              (ULONG) NULL, TRAT_Text, (ULONG) "_Entry:", TRAT_ID, 12,
      TROB_Space,             (ULONG) NULL,
      TROB_Button,            (ULONG) TRBT_GETENTRY, TRAT_ID, 12, TRAT_Text, (ULONG) "",
      TROB_Space,             (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_End,                 (ULONG) NULL,

  TAG_END
};


VOID do_gadgets(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *gadgets_project;

  if(gadgets_project=TR_OpenProject(Application,gadgets_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==gadgets_project) switch(trmsg->trm_Class)
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
    TR_UnlockProject(main_project);
    TR_CloseProject(gadgets_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/************************************************************************************** Window 'disabling' */

struct TagItem disabling_trwintags[]=
{
  WindowID(4), WindowTitle("Disabling"), WindowPosition(TRWP_CENTERDISPLAY),

  TRGR_Vert,                  (ULONG) TRGR_PROPSHARE|TRGR_ALIGN,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
      TROB_Space,             (ULONG) NULL,
      TROB_CheckBox,          (ULONG) NULL, TRAT_ID, 1, TRAT_Value, TRUE,
      TROB_Space,             (ULONG) NULL,
      TROB_Text,              (ULONG) NULL, TRAT_Text, (ULONG) "_Disabled", TRAT_ID, 1,
      TRGR_Horiz,             (ULONG) TRGR_PROPSPACES,
        TROB_Space,           (ULONG) NULL,
        TRGR_End,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_EQUALSHARE|TRGR_CENTER,
      TROB_Space,             (ULONG) NULL,
      TROB_Line,              (ULONG) TROF_HORIZ,
      TROB_Space,             (ULONG) NULL,
      TRGR_End,               (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
      TROB_Space,             (ULONG) NULL,
      TROB_CheckBox,          (ULONG) NULL, TRAT_Value, TRUE, TRAT_ID, 2, TRAT_Disabled, TRUE,
      TROB_Space,             (ULONG) NULL,
      TROB_Text,              (ULONG) NULL, TRAT_Text, (ULONG) "_Checkbox", TRAT_ID, 2,
      TROB_Space,             (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

    TRGR_Horiz,               (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER,
      TROB_Space,             (ULONG) NULL,
      TROB_Button,            (ULONG) NULL, TRAT_Text, (ULONG) "_Button", TRAT_ID, 3, TRAT_Disabled, TRUE,
      TROB_Space,             (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

  TRGR_End,                   (ULONG) NULL,

  TAG_END
};


VOID do_disabling(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *disabling_project;

  if(disabling_project=TR_OpenProject(Application,disabling_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==disabling_project) switch(trmsg->trm_Class)
        {
          case TRMS_CLOSEWINDOW:
            close_me=TRUE;
            break;

          case TRMS_ERROR:
            puts(TR_GetErrorString(trmsg->trm_Data));
            break;

          case TRMS_NEWVALUE:
            if(trmsg->trm_ID==1)
            {
              TR_SetAttribute(disabling_project,2,TRAT_Disabled,trmsg->trm_Data);
              TR_SetAttribute(disabling_project,3,TRAT_Disabled,trmsg->trm_Data);
            }
        }
        TR_ReplyMsg(trmsg);
      }
    }
    TR_UnlockProject(main_project);
    TR_CloseProject(disabling_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/******************************************************************************************* Window 'text' */

ProjectDefinition(text_trwintags)
{
  WindowID(5), WindowTitle("Text"), WindowPosition(TRWP_CENTERDISPLAY),
  VertGroupA,
    Space, CenteredText("Normal text"),
    Space, CenteredTextH("Highlighted text"),
    Space, CenteredText3("3-dimensional text"),
    Space, CenteredTextB("Bold text"),
    Space, CenteredText("A _shortcut"),
    Space, CenteredInteger(42),
    Space, HorizGroupAC,
             Space,
             ClippedText("This is a very long text which is truncated to fit with TRTX_CLIPPED."),
             Space, EndGroup,
    Space, EndGroup, EndProject
};


VOID do_text(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *text_project;

  if(text_project=TR_OpenProject(Application,text_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==text_project) switch(trmsg->trm_Class)
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
    TR_UnlockProject(main_project);
    TR_CloseProject(text_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/*********************************************************************************** Window 'notification' */

ProjectDefinition(notification_trwintags)
{
  WindowID(6), WindowTitle("Notification"), WindowPosition(TRWP_CENTERDISPLAY),
  VertGroupA,
    Space,
    NamedSeparatorI("_Checkmarks",1),
    Space,

    HorizGroupSAC,
      Space, CheckBox(1),
      Space, CheckBox(1),
      Space, CheckBox(1),
      Space, EndGroup,

    Space,

    HorizGroupSAC,
      Space, CheckBox(1),
      Space, CheckBox(1),
      Space, CheckBox(1),
      Space, EndGroup,

    Space,
    HorizGroupSAC,
      Space, CheckBox(1),
      Space, CheckBox(1),
      Space, CheckBox(1),
      Space, EndGroup,

    Space,
    NamedSeparatorI("_Slider and Progress indicator",2),
    Space,

    HorizGroupAC,
      Space,
      SliderGadget(0,10,8,2),
      Space,
      Integer3(8),TRAT_ID,2,TRAT_MinWidth,3,
      Space,
      EndGroup,

    Space,

    HorizGroupAC,
      Space,
      TextN("0%"),
      Space,
      Progress(10,8,2),
      Space,
      TextN("100%"),
      Space,
      EndGroup,

    Space,
  EndGroup, EndProject
};


VOID do_notification(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *notification_project;

  if(notification_project=TR_OpenProject(Application,notification_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==notification_project) switch(trmsg->trm_Class)
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
    TR_UnlockProject(main_project);
    TR_CloseProject(notification_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/*************************************************************************************** Window 'backfill' */

ProjectDefinition(backfill_trwintags)
{
  WindowID(7), WindowTitle("Backfill"), WindowPosition(TRWP_CENTERDISPLAY),
  VertGroupA,
    Space,  CenteredText("Each window and"),
    SpaceS, CenteredText("FrameBox can have"),
    SpaceS, CenteredText("one of the following"),
    SpaceS, CenteredText("backfill patterns"),
    Space,  HorizGroupA,
              Space, GroupBox, ObjectBackfillS, SpaceB,
              Space, GroupBox, ObjectBackfillSA, SpaceB,
              Space, GroupBox, ObjectBackfillSF, SpaceB,
              Space, EndGroup,
    Space,  HorizGroupA,
              Space, GroupBox, ObjectBackfillSB, SpaceB,
              Space, GroupBox, ObjectBackfillA, SpaceB,
              Space, GroupBox, ObjectBackfillAF, SpaceB,
              Space, EndGroup,
    Space,  HorizGroupA,
              Space, GroupBox, ObjectBackfillAB, SpaceB,
              Space, GroupBox, ObjectBackfillF, SpaceB,
              Space, GroupBox, ObjectBackfillFB, SpaceB,
              Space, EndGroup,
    Space, EndGroup, EndProject
};


VOID do_backfill(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *backfill_project;

  if(backfill_project=TR_OpenProject(Application,backfill_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==backfill_project) switch(trmsg->trm_Class)
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
    TR_UnlockProject(main_project);
    TR_CloseProject(backfill_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/************************************************************************************** Window 'appwindow' */

ProjectDefinition(appwindow_trwintags)
{
  WindowID(8), WindowTitle("AppWindow"), WindowPosition(TRWP_CENTERDISPLAY),
  VertGroupA,
    Space,  CenteredText("This window is an application window."),
    SpaceS, CenteredText("Drop icons into the window or into"),
    SpaceS, CenteredText("the icon drop boxes below and see"),
    SpaceS, CenteredText("what will happen..."),
    Space,  HorizGroupA,
              Space, DropBox(1),
              Space, DropBox(2),
              Space, EndGroup,
    Space, EndGroup, EndProject
};


VOID do_appwindow(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *appwindow_project;
  UBYTE reqstr[200],dirname[100];

  if(appwindow_project=TR_OpenProject(Application,appwindow_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==appwindow_project) switch(trmsg->trm_Class)
        {
          case TRMS_CLOSEWINDOW:
            close_me=TRUE;
            break;

          case TRMS_ERROR:
            puts(TR_GetErrorString(trmsg->trm_Data));
            break;

          case TRMS_ICONDROPPED:
            dirname[0]=0;
            NameFromLock(((struct AppMessage *)(trmsg->trm_Data))->am_ArgList->wa_Lock,dirname,100);
            AddPart(dirname,((struct AppMessage *)(trmsg->trm_Data))->am_ArgList->wa_Name,100);
            switch(trmsg->trm_ID)
            {
              case 1:
                sprintf(reqstr,"Icon(s) dropped into the left box.\tName of first dropped icon:\n%%3%s",dirname);
                break;
              case 2:
                sprintf(reqstr,"Icon(s) dropped into the right box.\tName of first dropped icon:\n%%3%s",dirname);
                break;
              default:
                sprintf(reqstr,"Icon(s) dropped into the window.\tName of first dropped icon:\n%%3%s",dirname);
            }
            TR_EasyRequestTags(Application,reqstr,"_Ok",
              TREZ_LockProject,appwindow_project,TREZ_Title,"AppWindow report",TREZ_Activate,TRUE,TAG_END);
            break;
        }
        TR_ReplyMsg(trmsg);
      }
    }
    TR_UnlockProject(main_project);
    TR_CloseProject(appwindow_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/****************************************************************************************** Window 'lists' */

struct TR_Dimensions lists_dim;

extern struct List LVList1;
extern struct List LVList2;
extern struct List LVList3;

struct Node LVNodes1[] =
{
  { &LVNodes1[1], (struct Node *)&LVList3.lh_Head,  0, 0, "This is a" },
  { &LVNodes1[2], &LVNodes1[0],                     0, 0, "READ ONLY" },
  { &LVNodes1[3], &LVNodes1[1],                     0, 0, "Listview" },
  { &LVNodes1[4], &LVNodes1[2],                     0, 0, "gadget using" },
  { &LVNodes1[5], &LVNodes1[3],                     0, 0, "the fixed-" },
  { &LVNodes1[6], &LVNodes1[4],                     0, 0, "width font." },
  { &LVNodes1[7], &LVNodes1[5],                     0, 0, "" },
  { &LVNodes1[ 8], &LVNodes1[ 6],                   0, 0, "This window" },
  { &LVNodes1[ 9], &LVNodes1[ 7],                   0, 0, "will remember" },
  { &LVNodes1[10], &LVNodes1[ 8],                   0, 0, "its position" },
  { &LVNodes1[11], &LVNodes1[ 9],                   0, 0, "even without" },
  { &LVNodes1[12], &LVNodes1[10],                   0, 0, "the Preferences" },
  { &LVNodes1[13], &LVNodes1[11],                   0, 0, "system, when" },
  { &LVNodes1[14], &LVNodes1[12],                   0, 0, "you reopen it," },
  { &LVNodes1[15], &LVNodes1[13],                   0, 0, "because it has" },
  { &LVNodes1[16], &LVNodes1[14],                   0, 0, "got a dimension" },
  { &LVNodes1[17], &LVNodes1[15],                   0, 0, "structure" },
  { &LVNodes1[18], &LVNodes1[16],                   0, 0, "attached" },
  { (struct Node *)&LVList3.lh_Tail, &LVNodes1[17], 0, 0, "to it." }
};

struct Node LVNodes2[] =
{
  { &LVNodes2[1], (struct Node *)&LVList3.lh_Head,  0, 0, "This is a" },
  { &LVNodes2[2], &LVNodes2[0],                     0, 0, "SELECT" },
  { &LVNodes2[3], &LVNodes2[1],                     0, 0, "Listview" },
  { &LVNodes2[4], &LVNodes2[2],                     0, 0, "gadget." },
  { &LVNodes2[5], &LVNodes2[3],                     0, 0, "Use the" },
  { &LVNodes2[6], &LVNodes2[4],                     0, 0, "numeric" },
  { &LVNodes2[7], &LVNodes2[5],                     0, 0, "key pad to" },
  { &LVNodes2[8], &LVNodes2[6],                     0, 0, "move" },
  { (struct Node *)&LVList3.lh_Tail, &LVNodes2[7],  0, 0, "around." }
};

struct Node LVNodes3[] =
{
  { &LVNodes3[1], (struct Node *)&LVList3.lh_Head,  0, 0, "This is a" },
  { &LVNodes3[2], &LVNodes3[0],                     0, 0, "SHOW" },
  { &LVNodes3[3], &LVNodes3[1],                     0, 0, "SELECTED" },
  { &LVNodes3[4], &LVNodes3[2],                     0, 0, "Listview" },
  { &LVNodes3[5], &LVNodes3[3],                     0, 0, "gadget." },
  { &LVNodes3[6], &LVNodes3[4],                     0, 0, "This list" },
  { &LVNodes3[7], &LVNodes3[5],                     0, 0, "is a bit" },
  { &LVNodes3[8], &LVNodes3[6],                     0, 0, "longer, so" },
  { &LVNodes3[9], &LVNodes3[7],                     0, 0, "that you" },
  { &LVNodes3[10],&LVNodes3[8],                     0, 0, "can try the" },
  { &LVNodes3[11],&LVNodes3[9],                     0, 0, "other" },
  { &LVNodes3[12],&LVNodes3[10],                    0, 0, "keyboard" },
  { (struct Node *)&LVList3.lh_Tail, &LVNodes3[11], 0, 0, "shortcuts." }
};

struct List LVList1=
{
  (struct Node *)&LVNodes1[0],
  (struct Node *)NULL,
  (struct Node *)&LVNodes1[18],
  0,0
};

struct List LVList2=
{
  (struct Node *)&LVNodes2[0],
  (struct Node *)NULL,
  (struct Node *)&LVNodes2[8],
  0,0
};

struct List LVList3=
{
  (struct Node *)&LVNodes3[0],
  (struct Node *)NULL,
  (struct Node *)&LVNodes3[12],
  0,0
};


struct TagItem lists_trwintags[]=
{
  WindowID(9), WindowTitle("Lists"), WindowPosition(TRWP_CENTERDISPLAY), WindowDimensions(&lists_dim),
  HorizGroupA, Space, VertGroupA,
    Space,
    NamedSeparatorIN("_Read only",1),
    Space,
    FWListROCN(&LVList1,1,0),
    Space,
    NamedSeparatorIN("_Select",2),
    Space,
    ListSelC(&LVList2,2,0),
    Space,
    NamedSeparatorIN("S_how selected",3),
    Space,
    ListSSN(&LVList3,3,0,1),
    Space,
  EndGroup, Space, EndGroup,
  EndProject
};


VOID do_lists(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  struct TR_Project *lists_project;

  if(lists_project=TR_OpenProject(Application,lists_trwintags))
  {
    TR_LockProject(main_project);
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==lists_project) switch(trmsg->trm_Class)
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
    TR_UnlockProject(main_project);
    TR_CloseProject(lists_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/****************************************************************************************** Window 'about' */

/* Note: This could be done even simpler with TR_EasyRequest().       */
/* ~~~~~ It is done with TR_AutoRequest() to show you how this works. */
/*       See window 'AppWindow' for a TR_EasyRequest() example.       */

ProjectDefinition(about_trwintags)
{
  BeginRequester("About...",TRWP_CENTERDISPLAY),

  VertGroupA, Space,  CenteredText3("Triton Demo 2.0"),
              SpaceS, CenteredText("� 1993-1996 by Stefan Zeiger"),
              Space,  HorizSeparator,
              Space,  CenteredText("This program is using the"),
              SpaceS, CenteredText("Triton GUI creation system"),
              SpaceS, CenteredText("which is � by Stefan Zeiger"),
              Space,  EndGroup,

  BeginRequesterGads,
  CenteredButtonRE("_Ok",1),
  EndRequester
};


/******************************************************************************************* Window 'main' */

ProjectDefinition(main_trwintags)
{
  WindowID(10), WindowTitle("Triton Demo"), WindowPosition(TRWP_CENTERDISPLAY), WindowFlags(TRWF_HELP),
  QuickHelpOn(TRUE),
  BeginMenu("Project"),
    MenuItem("?_About...",101),
    ItemBarlabel,
    MenuItem("H_Help",102),
    MenuItemCC("I_QuickHelp",104),
    ItemBarlabel,
    MenuItem("Q_Quit",103),
  VertGroupA,
    Space,  CenteredText3("T � r � i � t � o � n"),
    Space,  CenteredText3("The object oriented GUI creation system"),
    Space,  CenteredText("Demo program for release 2.0"),
    Space,  CenteredText("Written and � 1993-1996 by Stefan Zeiger"),
    Space,  HorizSeparator,
    Space,  HorizGroupEA,
              Space, Button("_Gadgets",1),       QuickHelp("Show some fancy gadgets"),
              Space, Button("G_roups",2),        QuickHelp("Groupies?\nHuh huh..."),
              Space, Button("_Text",3),          QuickHelp("You know what \'text\' means, huh?"),
              Space, EndGroup,
    Space, HorizGroupEA,
              Space, Button("_Notification",4),  QuickHelp("So you're super-connected now..."),
              Space, Button("_Backfill",5),      QuickHelp("United colors of Triton"),
              Space, Button("_Disabling",6),     QuickHelp("To be or not to be"),
              Space, EndGroup,
    Space, HorizGroupEA,
              Space, Button("_AppWindow",7),     QuickHelp("Demonstrate AppWindow feature"),
              Space, Button("_Menus",8),         QuickHelp("A fancy pull-down menu"),
              Space, Button("_Lists",9),         QuickHelp("� 4 eggs\n� 1/2lbs bread\n� 1l milk\t%3PS: Don't be late"),
              Space, EndGroup,
    Space, EndGroup, EndProject
};


VOID do_main(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Message *trmsg;
  UBYTE reqstr[256];
  STRPTR helpString;

  if(main_project=TR_OpenProject(Application,main_trwintags))
  {
    while(!close_me)
    {
      TR_Wait(Application,NULL);
      while(trmsg=TR_GetMsg(Application))
      {
        if(trmsg->trm_Project==main_project) switch(trmsg->trm_Class)
        {
          case TRMS_CLOSEWINDOW:
            close_me=TRUE;
            break;

          case TRMS_HELP:
	    if(helpString=(STRPTR)TR_GetAttribute(main_project,trmsg->trm_ID,TRDO_QuickHelpString))
	      sprintf(reqstr,"Help for object %ld:\n%%h%s",trmsg->trm_ID,helpString);
	    else
	      sprintf(reqstr,"No help available for object %ld.",trmsg->trm_ID);
            TR_EasyRequestTags(Application,reqstr,"_Ok",TREZ_LockProject,main_project,TREZ_Title,"Triton help",TAG_END);
            break;

          case TRMS_ERROR:
            puts(TR_GetErrorString(trmsg->trm_Data));
            break;

          case TRMS_NEWVALUE:
            if(trmsg->trm_ID==104) TR_SetAttribute(main_project,0,TRWI_QuickHelp,trmsg->trm_Data);
            break;

          case TRMS_ACTION:
            switch(trmsg->trm_ID)
            {
              case 1:
                do_gadgets();
                break;
              case 2:
                do_groups();
                break;
              case 3:
                do_text();
                break;
              case 4:
                do_notification();
                break;
              case 5:
                do_backfill();
                break;
              case 6:
                do_disabling();
                break;
              case 7:
                do_appwindow();
                break;
              case 8:
                do_menus();
                break;
              case 9:
                do_lists();
                break;
              case 101:
                TR_AutoRequest(Application,main_project,about_trwintags);
                break;
              case 102:
                TR_EasyRequestTags(Application,"To get help, move the mouse pointer over\nany gadget or menu item and press <Help>\nor turn on QuickHelp before.","_Ok",TREZ_LockProject,main_project,TREZ_Title,"Triton help",TAG_END);
                break;
              case 103:
                close_me=TRUE;
            }
            break;
        }
        TR_ReplyMsg(trmsg);
      }
    }
    TR_CloseProject(main_project);
  }
  else puts(TR_GetErrorString(TR_GetLastError(Application)));
}


/******************************************************************************************* Main function */

int main(void)
{
  if(TR_OpenTriton(TRITON20VERSION,
		   TRCA_Name,"TritonDemo",
		   TRCA_LongName,"Triton demo",
		   TRCA_Version,"2.0",TAG_END))
  {
    do_main();
    TR_CloseTriton();
    return 0;
  } else puts("Can't open triton.library v6+.");

  return 20;
}
