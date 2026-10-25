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
 *  Toolmanager3.c - My own creation for a ToolManager GUI
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


STRPTR cycle_entries[]={"Exec","Image","Sound","Menu","Icon","Dock","Access",NULL};

extern struct List LVList;

struct Node LVNodes[] =
{
  { &LVNodes[1], (struct Node *)&LVList.lh_Head,  0, 0, "2024view" },
  { &LVNodes[2], &LVNodes[0],                     0, 0, "Add to archive" },
  { &LVNodes[3], &LVNodes[1],                     0, 0, "Delete" },
  { &LVNodes[4], &LVNodes[2],                     0, 0, "Edit text" },
  { &LVNodes[5], &LVNodes[3],                     0, 0, "Env" },
  { &LVNodes[6], &LVNodes[4],                     0, 0, "Exchange" },
  { &LVNodes[7], &LVNodes[5],                     0, 0, "Global Help System" },
  { &LVNodes[8], &LVNodes[6],                     0, 0, "Multiview" },
  { (struct Node *)&LVList.lh_Tail, &LVNodes[7],  0, 0, "Paint" }
};

struct List LVList={&LVNodes[0],NULL,&LVNodes[8],0,0};


int main(void)
{
  if(TR_OpenTriton(TRITON11VERSION,TRCA_Name,"ToolManagerGUIDemo3",TRCA_LongName,"ToolManager GUI demo 3",TRCA_Info,"My own creation for a ToolManager GUI",TAG_END))
  {
    TR_AutoRequestTags(Application,NULL,
      WindowID(1), WindowPosition(TRWP_CENTERDISPLAY),
      WindowTitle("ToolManager GUI demo 3"),

      VertGroupA,

        Space,

        HorizGroupAC,
          Space,
          TextID("_Object type",1),
          Space,
          CycleGadget(cycle_entries,0,1),
          Space,
        EndGroup,

        Space,

        NamedSeparatorI("Object _list",2),

        Space,

        HorizGroupAC,
          Space,
            VertGroupAC,
              ListSS(&LVList,2,0,0),
              HorizGroupEA,
                Button("_New...",8),
                Button("_Edit...",9),
              EndGroup,
              HorizGroupEA,
                Button("Co_py",10),
                Button("Remove",11),
              EndGroup,
            EndGroup,
          Space,
          Line(TROF_VERT),
          Space,
            VertGroupA|TRGR_FIXHORIZ,
              Button("Top",3),
              Space,
              Button("Up",4),
              Space,
              Button("Down",5),
              Space,
              Button("Bottom",6),
              VertGroupS,Space,EndGroup,
              Button("So_rt",7),
            EndGroup,
          Space,
        EndGroup,

        Space,

        HorizSeparator,

        Space,

        HorizGroup,
          Space,
          HorizGroupS,
            Button("_Save",12),
            Space,
            Button("_Use",13),
            Space,
            Button("_Test",14),
            Space,
            Button("_Cancel",15),
          EndGroup,
          Space,
        EndGroup,

        Space,

      EndGroup,

      TAG_END);
    TR_CloseTriton();
    return 0;
  }
  puts("Can't open triton.library v2+.");
  return 20;
}
