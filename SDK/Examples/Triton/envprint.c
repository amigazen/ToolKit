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
 *  envprint.c - Envprint 2.0 GUI created with Triton
 *
 *  As you can see below, it is possible to mix the tag format with
 *  the C pre-processor macro format. (Actually I was just too lazy
 *  to transform the whole project definition from tags to macros ;)
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libraries/triton.h>

#ifdef __GNUC__
#ifndef __OPTIMIZE__
#include <clib/triton_protos.h>
#include <clib/dos_protos.h>
#else
#include <inline/triton.h>
#include <inline/dos.h>
#endif /* __OPTIMIZE__ */
#else
#include <proto/triton.h>
#include <proto/dos.h>
#endif /* __GNUC__ */


#ifdef __GNUC__
__chkabort(){}
#else
#ifdef __SASC__
int CXBRK(void) { return(0); }
int chkabort(void) { return(0); }
#endif
#endif


ProjectDefinition(main_trwintags)
{
  WindowID(1), WindowPosition(TRWP_CENTERDISPLAY),
  WindowTitle("EnvPrint 2.0 <THIS IS ONLY A NON-FUNCTIONAL GUI DEMO>"),

  BeginMenu("Project"),
    BeginSub("Load"),
      SubItem("S_Load sender...",1),
      SubItem("D_Load addressee...",2),
      SubItem("C_Load comment...",3),
    BeginSub("Save"),
      SubItem("O_Load sender",4),
      SubItem("E_Load addressee",5),
      SubItem("M_Load comment",6),
    BeginSub("Sace as"),
      SubItem("U_Load sender as...",7),
      SubItem("T_Load addressee as...",8),
      SubItem("N_Load comment as...",9),
    MenuItem("F_Delete file...",10),
    ItemBarlabel,
    MenuItem("P_Print...",11),
    MenuItem("R_Preferences...",12),
    ItemBarlabel,
    MenuItem("?_About...",13),
    ItemBarlabel,
    MenuItem("Q_Quit",14),

  BeginMenu("Edit"),
    MenuItem("W_Swap",15),
    MenuItem("X_Clear",16),

  HorizGroupA,
    Space,
    VertGroupA,
      HorizGroupEAC,
        VertGroupA,

          Space,

          NamedSeparatorI("Se_nder",101),

          TROB_Space,         (ULONG) NULL,

          HorizGroup,
            StringGadget(NULL,101),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_1",1101),
              EndGroup,
            EndGroup,

          SpaceS,

          HorizGroup,
            StringGadget(NULL,102),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_2",1102),
              EndGroup,
            EndGroup,

          SpaceS,

          HorizGroup,
            StringGadget(NULL,103),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_3",1103),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,104),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_4",1104),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,105),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_5",1105),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,106),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_6",1106),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,107),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_7",1107),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,108),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_8",1108),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) NULL,

          TRGR_End,           (ULONG) NULL,

        TROB_Space,           (ULONG) NULL,

        TRGR_Vert,            (ULONG) TRGR_PROPSHARE|TRGR_ALIGN,

          TROB_Space,         (ULONG) NULL,

          NamedSeparatorI("Add_ressee",201),

          TROB_Space,         (ULONG) NULL,

          HorizGroup,
            StringGadget(NULL,201),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_!",1201),
              EndGroup,
            EndGroup,

          SpaceS,

          HorizGroup,
            StringGadget(NULL,202),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_\"",1202),
              EndGroup,
            EndGroup,

          SpaceS,

          HorizGroup,
            StringGadget(NULL,203),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_§",1203),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,204),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_$",1204),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,205),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_%%",1205),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,206),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_&",1206),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,207),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_/",1207),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) TRST_SMALL,

          HorizGroup,
            StringGadget(NULL,208),
            HorizGroup|TRGR_FIXHORIZ,
              GetEntryButtonS("_(",1208),
              EndGroup,
            EndGroup,

          TROB_Space,         (ULONG) NULL,

          TRGR_End,           (ULONG) NULL,

        TRGR_End,             (ULONG) NULL,

      NamedSeparatorI("Co_mment",301),

      TROB_Space,             (ULONG) NULL,

      HorizGroup,
        StringGadget(NULL,301),
        HorizGroup|TRGR_FIXHORIZ,
          GetEntryButtonS("_0",1301),
          EndGroup,
        EndGroup,

      TROB_Space,             (ULONG) NULL,

      TRGR_End,               (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,
    TROB_Line,                (ULONG) TROF_VERT|TROF_RAISED,

    TROB_Space,               (ULONG) TRST_BIG,

    TRGR_Vert,                (ULONG) TRGR_PROPSHARE|TRGR_ALIGN|TRGR_FIXHORIZ,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_EQUALSHARE|TRGR_CENTER,
        TROB_Line,            (ULONG) TROF_HORIZ,
        TROB_Space,           (ULONG) NULL,
        TROB_Text,            (ULONG) NULL, TRAT_Text, (ULONG) "Load", TRAT_Flags, TRTX_TITLE,
        TROB_Space,           (ULONG) NULL,
        TROB_Line,            (ULONG) TROF_HORIZ,
        TRGR_End,             (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TROB_Button,            (ULONG) NULL, TRAT_Text, (ULONG) "_Sender...", TRAT_ID, 501,
      TROB_Space,             (ULONG) TRST_SMALL,
      TROB_Button,            (ULONG) NULL, TRAT_Text, (ULONG) "_Addressee...", TRAT_ID, 502,
      TROB_Space,             (ULONG) TRST_SMALL,
      TROB_Button,            (ULONG) NULL, TRAT_Text, (ULONG) "_Comment...", TRAT_ID, 503,
      TROB_Space,             (ULONG) NULL,
      TRGR_Horiz,             (ULONG) TRGR_EQUALSHARE|TRGR_CENTER,
        TROB_Line,            (ULONG) TROF_HORIZ,
        TROB_Space,           (ULONG) NULL,
        TROB_Text,            (ULONG) NULL, TRAT_Text, (ULONG) "Save", TRAT_Flags, TRTX_TITLE,
        TROB_Space,           (ULONG) NULL,
        TROB_Line,            (ULONG) TROF_HORIZ,
        TRGR_End,             (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
      TROB_Button,            (ULONG) NULL, TRAT_Text, (ULONG) "S_ender...", TRAT_ID, 504,
      TROB_Space,             (ULONG) TRST_SMALL,
      TROB_Button,            (ULONG) NULL, TRAT_Text, (ULONG) "A_ddressee...", TRAT_ID, 505,
      TROB_Space,             (ULONG) TRST_SMALL,
      TROB_Button,            (ULONG) NULL, TRAT_Text, (ULONG) "C_omment...", TRAT_ID, 506,
      TROB_Space,             (ULONG) TRST_BIG,
      TROB_Line,              (ULONG) TROF_HORIZ,
      TROB_Space,             (ULONG) TRST_BIG,
      TRGR_Horiz,             (ULONG) TRGR_EQUALSHARE,
        TROB_Button,          (ULONG) NULL, TRAT_Text, (ULONG) "_Print...", TRAT_ID, 507,
        TROB_Space,           (ULONG) TRST_SMALL,
        TROB_Button,          (ULONG) NULL, TRAT_Text, (ULONG) "S_wap", TRAT_ID, 508,
        TRGR_End,             (ULONG) NULL,
      TROB_Space,             (ULONG) TRST_SMALL,
      TRGR_Horiz,             (ULONG) TRGR_EQUALSHARE,
        TROB_Button,          (ULONG) NULL, TRAT_Text, (ULONG) "Pre_fs...", TRAT_ID, 509,
        TROB_Space,           (ULONG) TRST_SMALL,
        TROB_Button,          (ULONG) NULL, TRAT_Text, (ULONG) "C_lear", TRAT_ID, 510,
        TRGR_End,             (ULONG) NULL,
      TROB_Space,             (ULONG) NULL,
    TRGR_End,                 (ULONG) NULL,

    TROB_Space,               (ULONG) NULL,

  TRGR_End,                   (ULONG) NULL,

  TAG_END
};


VOID do_main(VOID)
{
  BOOL close_me=FALSE;
  struct TR_Project *main_project;
  struct TR_Message *trmsg;

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

          case TRMS_ERROR:
            puts(TR_GetErrorString(trmsg->trm_Data));
            break;
        }
        TR_ReplyMsg(trmsg);
      }
    }
    TR_CloseProject(main_project);
  }
}


int main(void)
{
  if(TR_OpenTriton(TRITON11VERSION,TRCA_Name,"Envprint",TRCA_LongName,"EnvPrint GUI demo",TRCA_Version,"2.0",TAG_END))
  {
    do_main();
    TR_CloseTriton();
    return 0;
  }

  puts("Can't open triton.library v2+.");
  return 20;
}
