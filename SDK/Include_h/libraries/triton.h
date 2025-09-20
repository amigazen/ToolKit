#ifndef LIBRARIES_TRITON_H
#define LIBRARIES_TRITON_H

/*
**	$VER: triton.h 6.11 (11.10.96)
**	Triton Release 2.0
**
**	triton.library definitions
*/

#define	TRITONNAME              "triton.library"
#define TRITONVERSION           TRITON20VERSION
#define	TRITON10VERSION         1L
#define	TRITON11VERSION         2L
#define	TRITON12VERSION         3L
#define	TRITON13VERSION         4L
#define	TRITON14VERSION         5L
#define	TRITON20VERSION         6L


/***********************************************************************************************************/
/************************************************************************************************ Includes */
/***********************************************************************************************************/

#define INTUI_V36_NAMES_ONLY

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_INTUITIONBASE_H
#include <intuition/intuitionbase.h>
#endif

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#ifndef INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
#endif

#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

#ifndef GRAPHICS_GFXBASE_H
#include <graphics/gfxbase.h>
#endif

#ifndef GRAPHICS_GFXMACROS_H
#include <graphics/gfxmacros.h>
#endif

#ifndef LIBRARIES_GADTOOLS_H
#include <libraries/gadtools.h>
#endif

#ifndef LIBRARIES_DISKFONT_H
#include <libraries/diskfont.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef WORKBENCH_STARTUP_H
#include <workbench/startup.h>
#endif

#ifndef WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif


/***********************************************************************************************************/
/************************************************************************************** Some useful things */
/***********************************************************************************************************/

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef min
#define min(a,b) ((a)<=(b)?(a):(b))
#endif


/***********************************************************************************************************/
/************************************************************************************************** Macros */
/***********************************************************************************************************/

#ifndef TR_NOMACROS

/* Project */
#define ProjectDefinition(name) struct TagItem name[]=
#define EndProject              TAG_END
#define WindowTitle(t)          TRWI_Title,(ULONG)(t)
#define ScreenTitle(t)          TRWI_ScreenTitle,(ULONG)(t)
#define WindowID(id)            TRWI_ID,(ULONG)(id)
#define WindowFlags(f)          TRWI_Flags,(ULONG)(f)
#define WindowPosition(pos)     TRWI_Position,(ULONG)(pos)
#define WindowUnderscore(und)   TRWI_Underscore,(ULONG)(und)
#define WindowDimensions(dim)   TRWI_Dimensions,(ULONG)(dim)
#define WindowBackfillWin       TRWI_Backfill,TRBF_WINDOWBACK
#define WindowBackfillReq       TRWI_Backfill,TRBF_REQUESTERBACK
#define WindowBackfillNone      TRWI_Backfill,TRBF_NONE
#define WindowBackfillS         TRWI_Backfill,TRBF_SHINE
#define WindowBackfillSA        TRWI_Backfill,TRBF_SHINE_SHADOW
#define WindowBackfillSF        TRWI_Backfill,TRBF_SHINE_FILL
#define WindowBackfillSB        TRWI_Backfill,TRBF_SHINE_BACKGROUND
#define WindowBackfillA         TRWI_Backfill,TRBF_SHADOW
#define WindowBackfillAF        TRWI_Backfill,TRBF_SHADOW_FILL
#define WindowBackfillAB        TRWI_Backfill,TRBF_SHADOW_BACKGROUND
#define WindowBackfillF         TRWI_Backfill,TRBF_FILL
#define WindowBackfillFB        TRWI_Backfill,TRBF_FILL_BACKGROUND
#define CustomScreen(scr)       TRWI_CustomScreen,((ULONG)(scr))
#define PubScreen(scr)          TRWI_PubScreen,((ULONG)(scr))
#define PubScreenName(name)     TRWI_PubScreenName,((ULONG)(name))
#define QuickHelpOn(on)         TRWI_QuickHelp,((ULONG)(on))

/* Menus */
#define BeginMenu(t)            TRMN_Title,(ULONG)(t)
#define MenuFlags(f)            TRMN_Flags,(f)
#define MenuItem(t,id)          TRMN_Item,(ULONG)(t),TRAT_ID,(id)
#define MenuItemC(t,id)         TRMN_Item,(ULONG)(t),TRMN_Flags,TRMF_CHECKIT,TRAT_ID,(id)
#define MenuItemCC(t,id)        TRMN_Item,(ULONG)(t),TRMN_Flags,TRMF_CHECKED,TRAT_ID,(id)
#define MenuItemCV(t,val,id)    TRMN_Item,(ULONG)(t),TRMN_Flags,(val)?TRMF_CHECKED:TRMF_CHECKIT,TRAT_ID,(id)
#define BeginSub(t)             TRMN_Item,(ULONG)(t)
#define MenuItemD(t,id)         TRMN_Item,(ULONG)(t),MenuFlags(TRMF_DISABLED),TRAT_ID,id
#define SubItem(t,id)           TRMN_Sub,(ULONG)(t),TRAT_ID,id
#define SubItemC(t,id)          TRMN_Sub,(ULONG)(t),TRMN_Flags,TRMF_CHECKIT,TRAT_ID,(id)
#define SubItemCC(t,id)         TRMN_Sub,(ULONG)(t),TRMN_Flags,TRMF_CHECKED,TRAT_ID,(id)
#define SubItemCV(t,val,id)     TRMN_Sub,(ULONG)(t),TRMN_Flags,(val)?TRMF_CHECKED:TRMF_CHECKIT,TRAT_ID,(id)
#define SubItemD(t,id)          TRMN_Sub,(ULONG)(t),MenuFlags(TRMF_DISABLED),TRAT_ID,id
#define ItemBarlabel            TRMN_Item,TRMN_BARLABEL
#define SubBarlabel             TRMN_Sub,TRMN_BARLABEL

/* Groups */
#define HorizGroup              TRGR_Horiz,0L
#define HorizGroupE             TRGR_Horiz,TRGR_EQUALSHARE
#define HorizGroupS             TRGR_Horiz,TRGR_PROPSPACES
#define HorizGroupA             TRGR_Horiz,TRGR_ALIGN
#define HorizGroupEA            TRGR_Horiz,TRGR_EQUALSHARE|TRGR_ALIGN
#define HorizGroupSA            TRGR_Horiz,TRGR_PROPSPACES|TRGR_ALIGN
#define HorizGroupC             TRGR_Horiz,TRGR_CENTER
#define HorizGroupEC            TRGR_Horiz,TRGR_EQUALSHARE|TRGR_CENTER
#define HorizGroupSC            TRGR_Horiz,TRGR_PROPSPACES|TRGR_CENTER
#define HorizGroupAC            TRGR_Horiz,TRGR_ALIGN|TRGR_CENTER
#define HorizGroupEAC           TRGR_Horiz,TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER
#define HorizGroupSAC           TRGR_Horiz,TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER
#define VertGroup               TRGR_Vert,0L
#define VertGroupE              TRGR_Vert,TRGR_EQUALSHARE
#define VertGroupS              TRGR_Vert,TRGR_PROPSPACES
#define VertGroupA              TRGR_Vert,TRGR_ALIGN
#define VertGroupEA             TRGR_Vert,TRGR_EQUALSHARE|TRGR_ALIGN
#define VertGroupSA             TRGR_Vert,TRGR_PROPSPACES|TRGR_ALIGN
#define VertGroupC              TRGR_Vert,TRGR_CENTER
#define VertGroupEC             TRGR_Vert,TRGR_EQUALSHARE|TRGR_CENTER
#define VertGroupSC             TRGR_Vert,TRGR_PROPSPACES|TRGR_CENTER
#define VertGroupAC             TRGR_Vert,TRGR_ALIGN|TRGR_CENTER
#define VertGroupEAC            TRGR_Vert,TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER
#define VertGroupSAC            TRGR_Vert,TRGR_PROPSPACES|TRGR_ALIGN|TRGR_CENTER
#define EndGroup                TRGR_End,0L
#define ColumnArray             TRGR_Horiz,TRGR_ARRAY|TRGR_ALIGN|TRGR_CENTER
#define LineArray               TRGR_Vert,TRGR_ARRAY|TRGR_ALIGN|TRGR_CENTER
#define BeginColumn             TRGR_Vert,TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER
#define BeginLine               TRGR_Horiz,TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER
#define BeginColumnI            TRGR_Vert,TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER|TRGR_INDEP
#define BeginLineI              TRGR_Horiz,TRGR_PROPSHARE|TRGR_ALIGN|TRGR_CENTER|TRGR_INDEP
#define BeginColumnE            TRGR_Vert,TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER
#define BeginLineE              TRGR_Horiz,TRGR_EQUALSHARE|TRGR_ALIGN|TRGR_CENTER
#define EndColumn               EndGroup
#define EndLine                 EndGroup
#define EndArray                EndGroup

/* DisplayObject */
#define QuickHelp(str)          TRDO_QuickHelpString,((ULONG)(str))

/* Space */
#define SpaceB                  TROB_Space,TRST_BIG
#define Space                   TROB_Space,TRST_NORMAL
#define SpaceS                  TROB_Space,TRST_SMALL
#define SpaceN                  TROB_Space,TRST_NONE

/* Text */
#define TextN(text)             TROB_Text,0L,TRAT_Text,(ULONG)text
#define TextH(text)             TROB_Text,0L,TRAT_Text,(ULONG)text,TRAT_Flags,TRTX_HIGHLIGHT
#define Text3(text)             TROB_Text,0L,TRAT_Text,(ULONG)text,TRAT_Flags,TRTX_3D
#define TextB(text)             TROB_Text,0L,TRAT_Text,(ULONG)text,TRAT_Flags,TRTX_BOLD
#define TextT(text)             TROB_Text,0L,TRAT_Text,(ULONG)text,TRAT_Flags,TRTX_TITLE
#define TextID(text,id)         TROB_Text,0L,TRAT_Text,(ULONG)text,TRAT_ID,id
#define TextNR(t)               TextN(t),TRAT_Flags,TROF_RIGHTALIGN
#define ClippedText(t)          TextN(t),TRAT_Flags,TRTX_CLIPPED|TRTX_NOUNDERSCORE
#define ClippedTextID(t,id)     TextN(t),TRAT_Flags,TRTX_CLIPPED|TRTX_NOUNDERSCORE,TRAT_ID,id
#define CenteredText(text)      HorizGroupSC,Space,TextN(text),Space,EndGroup
#define CenteredTextH(text)     HorizGroupSC,Space,TextH(text),Space,EndGroup
#define CenteredText3(text)     HorizGroupSC,Space,Text3(text),Space,EndGroup
#define CenteredTextB(text)     HorizGroupSC,Space,TextB(text),Space,EndGroup
#define CenteredTextID(text,id) HorizGroupSC,Space,TextID(text,id),Space,EndGroup
#define CenteredText_BS(text)   HorizGroupSC,SpaceB,TextN(text),SpaceB,EndGroup
#define TextBox(text,id,mwid)   _TextBox, ObjectBackfillB, VertGroup, SpaceS, HorizGroupSC, Space, \
                                TextN(text),TRAT_ID,id,TRAT_MinWidth,mwid, Space, EndGroup, SpaceS, \
                                EndGroup
#define ClippedTextBox(text,id) _TextBox, ObjectBackfillB, VertGroupAC, SpaceS, HorizGroupAC, Space, \
                                ClippedTextID(text,id), Space, EndGroup, SpaceS, EndGroup
#define ClippedTextBoxMW(text,id,mwid) _TextBox, ObjectBackfillB, VertGroupAC, SpaceS, HorizGroupAC, Space, \
                                ClippedTextID(text,id),TRAT_MinWidth,mwid, Space, EndGroup, SpaceS, EndGroup
#define TextRIGHT(t,id)         HorizGroupS, Space, TextN(t), ID(id), EndGroup
#define Integer(i)              TROB_Text,0L,TRAT_Value,(ULONG)(i)
#define IntegerH(i)             TROB_Text,0L,TRAT_Value,(ULONG)(i),TRAT_Flags,TRTX_HIGHLIGHT
#define Integer3(i)             TROB_Text,0L,TRAT_Value,(ULONG)(i),TRAT_Flags,TRTX_3D
#define IntegerB(i)             TROB_Text,0L,TRAT_Value,(ULONG)(i),TRAT_Flags,TRTX_BOLD
#define CenteredInteger(i)      HorizGroupSC,Space,Integer(i),Space,EndGroup
#define CenteredIntegerH(i)     HorizGroupSC,Space,IntegerH(i),Space,EndGroup
#define CenteredInteger3(i)     HorizGroupSC,Space,Integer3(i),Space,EndGroup
#define CenteredIntegerB(i)     HorizGroupSC,Space,IntegerB(i),Space,EndGroup
#define IntegerBox(def,id,mwid) GroupBox, ObjectBackfillB, VertGroup, SpaceS, HorizGroupSC, Space, \
                                Integer(def),TRAT_ID,id,TRAT_MinWidth,mwid, Space, EndGroup, SpaceS, EndGroup

/* Button */
#define Button(text,id)         TROB_Button,0L,TRAT_Text,(ULONG)(text),TRAT_ID,(id)
#define ButtonR(text,id)        TROB_Button,0L,TRAT_Text,(ULONG)(text),TRAT_ID,(id),TRAT_Flags,TRBU_RETURNOK
#define ButtonE(text,id)        TROB_Button,0L,TRAT_Text,(ULONG)(text),TRAT_ID,(id),TRAT_Flags,TRBU_ESCOK
#define ButtonRE(text,id)       TROB_Button,0L,TRAT_Text,(ULONG)(text),TRAT_ID,(id), \
                                TRAT_Flags,TRBU_RETURNOK|TRBU_ESCOK
#define CenteredButton(t,i)     HorizGroupSC,Space,TROB_Button,0L,TRAT_Text,(ULONG)(t),TRAT_ID,(i), \
                                Space,EndGroup
#define CenteredButtonR(t,i)    HorizGroupSC,Space,TROB_Button,0L,TRAT_Flags,TRBU_RETURNOK, \
                                TRAT_Text,(ULONG)(t),TRAT_ID,(i),Space,EndGroup
#define CenteredButtonE(t,i)    HorizGroupSC,Space,TROB_Button,0L,TRAT_Flags,TRBU_ESCOK, \
                                TRAT_Text,(ULONG)(t),TRAT_ID,(i),Space,EndGroup
#define CenteredButtonRE(t,i)   HorizGroupSC,Space,TROB_Button,0L,TRAT_Flags,TRBU_RETURNOK|TRBU_ESCOK, \
                                TRAT_Text,(ULONG)(t),TRAT_ID,(i),Space,EndGroup
#define EmptyButton(id)         TROB_Button,0L,TRAT_Text,(ULONG)"",TRAT_ID,(id)
#define GetFileButton(id)       TROB_Button,TRBT_GETFILE,TRAT_Text,(ULONG)"",TRAT_ID,(id), \
                                TRAT_Flags,TRBU_YRESIZE
#define GetDrawerButton(id)     TROB_Button,TRBT_GETDRAWER,TRAT_Text,(ULONG)"",TRAT_ID,(id), \
                                TRAT_Flags,TRBU_YRESIZE
#define GetEntryButton(id)      TROB_Button,TRBT_GETENTRY,TRAT_Text,(ULONG)"",TRAT_ID,(id), \
                                TRAT_Flags,TRBU_YRESIZE
#define GetFileButtonS(s,id)    TROB_Button,TRBT_GETFILE,TRAT_Text,(ULONG)(s),TRAT_ID,(id), \
                                TRAT_Flags,TRBU_YRESIZE
#define GetDrawerButtonS(s,id)  TROB_Button,TRBT_GETDRAWER,TRAT_Text,(ULONG)(s),TRAT_ID,(id), \
                                TRAT_Flags,TRBU_YRESIZE
#define GetEntryButtonS(s,id)   TROB_Button,TRBT_GETENTRY,TRAT_Text,(ULONG)(s),TRAT_ID,(id), \
                                TRAT_Flags,TRBU_YRESIZE

/* Line */
#define Line(flags)             TROB_Line,flags
#define HorizSeparator          HorizGroupEC|TRGR_INDEP,Space,Line(TROF_HORIZ),Space,EndGroup
#define VertSeparator           VertGroupEC|TRGR_INDEP,Space,Line(TROF_VERT),Space,EndGroup
#define NamedSeparator(text)    HorizGroupEC|TRGR_INDEP,Space,Line(TROF_HORIZ),Space,TextT(text),Space, \
                                Line(TROF_HORIZ),Space,EndGroup
#define NamedSeparatorI(te,id)  HorizGroupEC|TRGR_INDEP,Space,Line(TROF_HORIZ),Space,TextT(te),TRAT_ID,id,Space, \
                                Line(TROF_HORIZ),Space,EndGroup
#define NamedSeparatorN(text)   HorizGroupEC|TRGR_INDEP,Line(TROF_HORIZ),Space,TextT(text),Space, \
                                Line(TROF_HORIZ),EndGroup
#define NamedSeparatorIN(te,id) HorizGroupEC|TRGR_INDEP,Line(TROF_HORIZ),Space,TextT(te),TRAT_ID,id,Space, \
                                Line(TROF_HORIZ),EndGroup

/* FrameBox */
#define GroupBox                TROB_FrameBox,TRFB_GROUPING
#define NamedFrameBox(t)        TROB_FrameBox,TRFB_FRAMING,TRAT_Text,(ULONG)(t)
#define _TextBox                TROB_FrameBox,TRFB_TEXT

/* DropBox */
#define DropBox(id)             TROB_DropBox,0L,TRAT_ID,(id)

/* CheckBox gadget */
#define CheckBox(id)            TROB_CheckBox,0L,TRAT_ID,(id)
#define CheckBoxV(value,id)     TROB_CheckBox,0L,TRAT_ID,(id),TRAT_Value,(value)
#define CheckBoxC(id)           TROB_CheckBox,0L,TRAT_ID,(id),TRAT_Value,TRUE
#define CheckBoxLEFT(id)        HorizGroupS, CheckBox(id), Space, EndGroup
#define CheckBoxCLEFT(id)       HorizGroupS, CheckBoxC(id), Space, EndGroup

/* String gadget */
#define StringGadget(def,id)    TROB_String,(ULONG)def,TRAT_ID,(id)
#define StringGadgetNR(def, id) TROB_String,(ULONG)def,TRAT_ID,(id),TRAT_Flags,TRST_NORETURNBROADCAST
#define PasswordGadget(def,id)  TROB_String,(ULONG)def,TRAT_ID,(id),TRAT_Flags,TRST_INVISIBLE

/* Cycle gadget */
#define CycleGadget(ent,val,id) TROB_Cycle,(ULONG)(ent),TRAT_ID,(id),TRAT_Value,(val)
#define MXGadget(ent,val,id)    TROB_Cycle,(ULONG)(ent),TRAT_ID,(id),TRAT_Value,(val),TRAT_Flags,TRCY_MX
#define MXGadgetR(ent,val,id)   TROB_Cycle,(ULONG)(ent),TRAT_ID,(id),TRAT_Value,(val), \
                                TRAT_Flags,TRCY_MX|TRCY_RIGHTLABELS

/* Slider gadget */
#define SliderGadget(mini,maxi,val,id) TROB_Slider,TROF_HORIZ,TRSL_Min,(mini),TRSL_Max,(maxi), \
                                TRAT_ID,(id),TRAT_Value,(val)
#define SliderGadgetV(mini,maxi,val,id) TROB_Slider,TROF_VERT,TRSL_Min,(mini),TRSL_Max,(maxi), \
                                TRAT_ID,(id),TRAT_Value,(val)

/* Scroller gadget */
#define ScrollerGadget(total,visible,val,id) TROB_Scroller,TROF_HORIZ,TRSC_Total,(total), \
                                TRSC_Visible,(visible),TRAT_ID,(id),TRAT_Value,(val)
#define ScrollerGadgetV(total,visible,val,id) TROB_Scroller,TROF_VERT,TRSC_Total,(total), \
                                TRSC_Visible,(visible),TRAT_ID,(id),TRAT_Value,(val)

/* Palette gadget */
#define PaletteGadget(val,id)   TROB_Palette,0L,TRAT_ID,(id),TRAT_Value,(val)

/* Listview gadget */
#define ListRO(ent,id,top)      TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_READONLY, \
                                TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define ListSel(ent,id,top)     TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_SELECT, \
                                TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define ListSS(e,id,top,v)      TROB_Listview,(ULONG)(e),TRAT_Flags,TRLV_NOGAP|TRLV_SHOWSELECTED, \
                                TRAT_ID,id,TRAT_Value,v,TRLV_Top,top
#define ListROC(ent,id,top)     TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_READONLY| \
                                TRLV_NOCURSORKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define ListSelC(ent,id,top)    TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_SELECT| \
                                TRLV_NOCURSORKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define ListSSC(e,id,top,v)     TROB_Listview,(ULONG)(e),TRAT_Flags,TRLV_NOGAP|TRLV_SHOWSELECTED| \
                                TRLV_NOCURSORKEYS,TRAT_ID,id,TRAT_Value,v,TRLV_Top,top
#define ListRON(ent,id,top)     TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_READONLY| \
                                TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define ListSelN(ent,id,top)    TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_SELECT| \
                                TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define ListSSN(e,id,top,v)     TROB_Listview,(ULONG)(e),TRAT_Flags,TRLV_NOGAP|TRLV_SHOWSELECTED| \
                                TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,v,TRLV_Top,top
#define ListROCN(ent,id,top)    TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_READONLY| \
                                TRLV_NOCURSORKEYS|TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define ListSelCN(ent,id,top)   TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_SELECT| \
                                TRLV_NOCURSORKEYS|TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define ListSSCN(e,id,top,v)    TROB_Listview,(ULONG)(e),TRAT_Flags,TRLV_NOGAP|TRLV_SHOWSELECTED| \
                                TRLV_NOCURSORKEYS|TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,v,TRLV_Top,top
#define FWListRO(ent,id,top)    TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT| \
                                TRLV_READONLY,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define FWListSel(ent,id,top)   TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT|TRLV_SELECT, \
                                TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define FWListSS(e,id,top,v)    TROB_Listview,(ULONG)(e),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT| \
                                TRLV_SHOWSELECTED,TRAT_ID,id,TRAT_Value,v,TRLV_Top,top
#define FWListROC(ent,id,top)   TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT|TRLV_READONLY| \
                                TRLV_NOCURSORKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define FWListSelC(ent,id,top)  TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT|TRLV_SELECT| \
                                TRLV_NOCURSORKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define FWListSSC(e,id,top,v)   TROB_Listview,(ULONG)(e),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT| \
                                TRLV_SHOWSELECTED|TRLV_NOCURSORKEYS,TRAT_ID,id,TRAT_Value,v,TRLV_Top,top
#define FWListRON(ent,id,top)   TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT|TRLV_READONLY| \
                                TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define FWListSelN(ent,id,top)  TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT|TRLV_SELECT| \
                                TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define FWListSSN(e,id,top,v)   TROB_Listview,(ULONG)(e),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT| \
                                TRLV_SHOWSELECTED|TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,v,TRLV_Top,top
#define FWListROCN(ent,id,top)  TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT|TRLV_READONLY| \
                                TRLV_NOCURSORKEYS|TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define FWListSelCN(ent,id,top) TROB_Listview,(ULONG)(ent),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT|TRLV_SELECT| \
                                TRLV_NOCURSORKEYS|TRLV_NONUMPADKEYS,TRAT_ID,id,TRAT_Value,0,TRLV_Top,top
#define FWListSSCN(e,id,top,v)  TROB_Listview,(ULONG)(e),TRAT_Flags,TRLV_NOGAP|TRLV_FWFONT| \
                                TRLV_SHOWSELECTED|TRLV_NOCURSORKEYS|TRLV_NONUMPADKEYS,TRAT_ID,id, \
                                TRAT_Value,v,TRLV_Top,top

/* Progress indicator */
#define Progress(maxi,val,id)   TROB_Progress,(maxi),TRAT_ID,(id),TRAT_Value,(val)

/* Image */
#define BoopsiImage(img)        TROB_Image,(ULONG)(img),TRAT_Flags,TRIM_BOOPSI
#define BoopsiImageD(img,mw,mh) TROB_Image,(ULONG)(img),TRAT_MinWidth,(mw),TRAT_MinHeight,(mh), \
                                TRAT_Flags,TRIM_BOOPSI

/* Attributes */
#define ID(id)                  TRAT_ID,id
#define Disabled                TRAT_Disabled,TRUE
#define ObjectBackfillWin       TRAT_Backfill,TRBF_WINDOWBACK
#define ObjectBackfillReq       TRAT_Backfill,TRBF_REQUESTERBACK
#define ObjectBackfillB         TRAT_Backfill,TRBF_NONE
#define ObjectBackfillS         TRAT_Backfill,TRBF_SHINE
#define ObjectBackfillSA        TRAT_Backfill,TRBF_SHINE_SHADOW
#define ObjectBackfillSF        TRAT_Backfill,TRBF_SHINE_FILL
#define ObjectBackfillSB        TRAT_Backfill,TRBF_SHINE_BACKGROUND
#define ObjectBackfillA         TRAT_Backfill,TRBF_SHADOW
#define ObjectBackfillAF        TRAT_Backfill,TRBF_SHADOW_FILL
#define ObjectBackfillAB        TRAT_Backfill,TRBF_SHADOW_BACKGROUND
#define ObjectBackfillF         TRAT_Backfill,TRBF_FILL
#define ObjectBackfillFB        TRAT_Backfill,TRBF_FILL_BACKGROUND

/* Requester support */
#define BeginRequester(t,p)     WindowTitle(t),WindowPosition(p),WindowBackfillReq, \
                                WindowFlags(TRWF_NOZIPGADGET|TRWF_NOSIZEGADGET|TRWF_NOCLOSEGADGET| \
                                TRWF_NODELZIP|TRWF_NOESCCLOSE),\
                                VertGroupA,Space,HorizGroupA,Space,GroupBox,ObjectBackfillB
#define BeginRequesterGads      Space,EndGroup,Space
#define EndRequester            Space,EndGroup,EndProject

/* Class construction */
#ifndef TR_THIS_IS_TRITON
#define TR_METHOD(class,method,dstr) ULONG __saveds __asm TRDP_ ## class ## _ ## method \
				(register __a0 struct TROD_ ## class *object,\
				 register __d0 ULONG messageid,\
				 register __a2 struct TROM_ ## dstr *data,\
				 register __a1 struct TR_Class *metaclass)

#define TR_SIMPLEMETHOD(class,method) ULONG __saveds __asm TRDP_ ## class ## _ ## method \
                                (register __a0 struct TROD_ ## class *object,\
				 register __d0 ULONG messageid,\
				 register __a2 void *data,\
				 register __a1 struct TR_Class *metaclass)
#endif /* TR_THIS_IS_TRITON */

#define TR_CONSTRUCTOR(class) struct TROD_ ## class * __saveds __asm TRDP_ ## class ## _NEW \
				(register __a0 struct TROD_ ## class *object,\
				 register __d0 ULONG messageid,\
				 register __a2 struct TROM_NewData *data,\
				 register __a1 struct TR_Class *metaclass)

#define TR_SUPERMETHOD        TR_DoMethodClass((struct TROD_Object *)object,messageid,\
					       (APTR)data,metaclass->trc_SuperClass)
#define Self (*object)

#endif /* TR_NOMACROS */


/***********************************************************************************************************/
/***************************************************************************************** Support library */
/***********************************************************************************************************/

#ifndef TR_NOSUPPORT

extern struct TR_App *__Triton_Support_App;
extern struct IClass *TRIM_trLogo;

#ifndef TR_NOMACROS
#ifndef __OBJAM__
#define Application __Triton_Support_App
#endif /* __OBJAM__ */
#endif /* TR_NOMACROS */

#endif /* TR_NOSUPPORT */


/***********************************************************************************************************/
/***************************************************************************************** The method type */
/***********************************************************************************************************/

typedef ULONG __asm (*TR_Method)(register __a0 struct TROD_Object *, register __d0 ULONG,
				 register __a2 APTR, register __a1 struct TR_Class *);


/***********************************************************************************************************/
/******************************************************* Public parts of the application message structure */
/***********************************************************************************************************/

#ifndef TR_THIS_IS_TRITON

struct TR_Message
{
  struct TR_Project *           trm_Project;    /* The project which triggered the message */
  ULONG                         trm_ID;         /* The object's ID (where appropriate) */
  ULONG                         trm_Class;      /* The Triton message class */
  ULONG                         trm_Data;       /* The class-specific data */
  ULONG                         trm_Code;       /* Currently only used by TRMS_KEYPRESSED */
  ULONG                         trm_Qualifier;  /* IEQUALIFIERs */
  ULONG                         trm_Seconds;    /* \ Copy of system clock time (Only where */
  ULONG                         trm_Micros;     /* / available! If not set, trm_Seconds is 0) */
  struct TR_App *               trm_App;        /* The project's application */
};

#endif

enum TR_MessageClasses
{
  TRMS_CLOSEWINDOW = 1, /* The window should be closed */
  TRMS_ERROR,           /* An error occured. Error code in trm_Data */
  TRMS_NEWVALUE,        /* Object's value has changed. New value in trm_Data */
  TRMS_ACTION,          /* Object has triggered an action */
  TRMS_ICONDROPPED,     /* Icon dropped over window (ID=0) or object. AppMessage* in trm_Data */
  TRMS_KEYPRESSED,      /* Key pressed. trm_Data contains ASCII code, trm_Code raw code and
                           trm_Qualifier contains qualifiers */
  TRMS_HELP,            /* The user requested help for the specified ID */
  TRMS_DISKINSERTED,    /* A disk has been inserted into a drive */
  TRMS_DISKREMOVED      /* A disk has been removed from a drive */
};


/***********************************************************************************************************/
/************************************************************************************** Triton error codes */
/***********************************************************************************************************/

enum TR_ErrorCodes
{
  TRER_OK = 0,                /* No error */
  TRER_ALLOCMEM,              /* Not enough memory */
  TRER_OPENWINDOW,            /* Can't open window */
  TRER_WINDOWTOOBIG,          /* Window would be too big for screen */
  TRER_DRAWINFO,              /* Can't get screen's DrawInfo */
  TRER_OPENFONT,              /* Can't open font */
  TRER_CREATEMSGPORT,         /* Can't create message port */
  TRER_INSTALLOBJECT,         /* Can't create an object */
  TRER_CREATECLASS,           /* Can't create a class */
  TRER_NOLOCKPUBSCREEN,       /* Can't lock public screen */
  TRER_CREATEMENUS = 12,      /* Error while creating the menus */
  TRER_GT_CREATECONTEXT = 14, /* Can't create gadget context */
  TRER_MAXERRORNUM            /* PRIVATE! */
};


/***********************************************************************************************************/
/***************************************************************************************** Object messages */
/***********************************************************************************************************/

#define TROM_NEW                1L         /* Create object */
#define TROM_INSTALL            2L         /* Tell object to install itself in the window */
#define TROM_REFRESH            4L         /* Refresh object */
#define TROM_REMOVE             6L         /* Remove object from window */
#define TROM_DISPOSE            7L         /* Dispose an object's private data */
#define TROM_GETATTRIBUTE       8L         /* Get an object's attribute */
#define TROM_SETATTRIBUTE       9L         /* Set an object's attribute */
#define TROM_EVENT              10L        /* IDCMP event */
#define TROM_DISABLED           11L        /* Disabled object */
#define TROM_ENABLED            12L        /* Enabled object */
#define TROM_KEYDOWN            13L        /* Key pressed */
#define TROM_REPEATEDKEYDOWN    14L        /* Key pressed repeatedly */
#define TROM_KEYUP              15L        /* Key released */
#define TROM_KEYCANCELLED       16L        /* Key cancelled */
#define TROM_CREATECLASS        17L        /* Create class-specific data */
#define TROM_DISPOSECLASS       18L        /* Dispose class-specific data */
#define TROM_HIT                22L        /* Find an object for a coordinate pair */
#define TROM_ACTIVATE           23L        /* Activate an object */

/* Data for TROM_NEW */
struct TROM_NewData
{
  /* The following elements are set up for the object (read only) */
  struct TR_Project *           project;
  struct TagItem *              firstitem;
  ULONG                         objecttype;
  ULONG                         grouptype;
  ULONG                         itemdata;
  ULONG                         backfilltype;
  /* The following elements have to be set by the object and read by class_DisplayObject */
  BOOL                          parseargs;
};

/* Data for TROM_INSTALL */
struct TROM_InstallData
{
  ULONG                         left;
  ULONG                         top;
  ULONG                         width;
  ULONG                         height;
};

/* Data for TROM_SETATTRIBUTE */
struct TROM_SetAttributeData
{
  ULONG                         attribute;
  ULONG                         value;
};

/* Data for TROM_EVENT */
struct TROM_EventData
{
  struct IntuiMessage *         imsg;
};
#define TROM_EVENT_SWALLOWED    1
#define TROM_EVENT_CONTINUE     0

/* Data for TROM_HIT */
struct TROM_HitData
{
  ULONG                         x;
  ULONG                         y;
  struct TROD_DisplayObject *   object;
};


/***********************************************************************************************************/
/******************************************************************************* Tags for TR_OpenProject() */
/***********************************************************************************************************/

/* Tag bases */
#define TRTG_OAT              (TAG_USER+0x400)  /* Object attribute (0x1 to 0x3FF) */
#define TRTG_CLS              (TAG_USER+0x100)  /* Class ID (0x1 to 0x2FF) */
#define TRTG_OAT2             (TAG_USER+0x80)   /* PRIVATE! */
#define TRTG_PAT              (TAG_USER)        /* Project attribute */
#define TRTG_SER(ser)         ((ser)<<11)       /* Serial number for public, 1 for private classes */
#define TRTG_PRVCLS(num)      (TRTG_SER(1)+TRTG_CLS+(num))
#define TRTG_PRVOAT(num)      (TRTG_SER(1)+TRTG_OAT+(num))


/* Window/Project */
#define TRWI_Title              (TRTG_PAT+0x01) /* STRPTR: The window title */
#define TRWI_Flags              (TRTG_PAT+0x02) /* See below for window flags */
#define TRWI_Underscore         (TRTG_PAT+0x03) /* char *: The underscore for menu and gadget shortcuts */
#define TRWI_Position           (TRTG_PAT+0x04) /* Window position, see below */
#define TRWI_CustomScreen       (TRTG_PAT+0x05) /* struct Screen * */
#define TRWI_PubScreen          (TRTG_PAT+0x06) /* struct Screen *, must have been locked! */
#define TRWI_PubScreenName      (TRTG_PAT+0x07) /* STRPTR, Triton is doing the locking */
#define TRWI_PropFontAttr       (TRTG_PAT+0x08) /* struct TextAttr *: The proportional font */
#define TRWI_FixedWidthFontAttr (TRTG_PAT+0x09) /* struct TextAttr *: The fixed-width font */
#define TRWI_Backfill           (TRTG_PAT+0x0A) /* The backfill type, see below */
#define TRWI_ID                 (TRTG_PAT+0x0B) /* ULONG: The window ID */
#define TRWI_Dimensions         (TRTG_PAT+0x0C) /* struct TR_Dimensions * */
#define TRWI_ScreenTitle        (TRTG_PAT+0x0D) /* STRPTR: The screen title */
#define TRWI_QuickHelp          (TRTG_PAT+0x0E) /* BOOL: Quick help active? */

/* Menus */
#define TRMN_Title              (TRTG_PAT+0x65) /* STRPTR: Menu */
#define TRMN_Item               (TRTG_PAT+0x66) /* STRPTR: Menu item */
#define TRMN_Sub                (TRTG_PAT+0x67) /* STRPTR: Menu subitem */
#define TRMN_Flags              (TRTG_PAT+0x68) /* See below for flags */

/* General object attributes */
#define TRAT_ID               (TRTG_OAT2+0x16)  /* The object's/menu's ID */
#define TRAT_Flags            (TRTG_OAT2+0x17)  /* The object's flags */
#define TRAT_Value            (TRTG_OAT2+0x18)  /* The object's value */
#define TRAT_Text             (TRTG_OAT2+0x19)  /* The object's text */
#define TRAT_Disabled         (TRTG_OAT2+0x1A)  /* Disabled object? */
#define TRAT_Backfill         (TRTG_OAT2+0x1B)  /* Backfill pattern */
#define TRAT_MinWidth         (TRTG_OAT2+0x1C)  /* Minimum width */
#define TRAT_MinHeight        (TRTG_OAT2+0x1D)  /* Minimum height */


/***********************************************************************************************************/
/******************************************************************************************** Window flags */
/***********************************************************************************************************/

#define TRWF_BACKDROP           0x00000001L     /* Create a backdrop borderless window */
#define TRWF_NODRAGBAR          0x00000002L     /* Don't use a dragbar */
#define TRWF_NODEPTHGADGET      0x00000004L     /* Don't use a depth-gadget */
#define TRWF_NOCLOSEGADGET      0x00000008L     /* Don't use a close-gadget */
#define TRWF_NOACTIVATE         0x00000010L     /* Don't activate window */
#define TRWF_NOESCCLOSE         0x00000020L     /* Don't send TRMS_CLOSEWINDOW when Esc is pressed */
#define TRWF_NOPSCRFALLBACK     0x00000040L     /* Don't fall back onto default PubScreen */
#define TRWF_NOZIPGADGET        0x00000080L     /* Don't use a zip-gadget */
#define TRWF_ZIPCENTERTOP       0x00000100L     /* Center the zipped window on the title bar */
#define TRWF_NOMINTEXTWIDTH     0x00000200L     /* Minimum window width not according to title text */
#define TRWF_NOSIZEGADGET       0x00000400L     /* Don't use a sizing-gadget */
#define TRWF_NOFONTFALLBACK     0x00000800L     /* Don't fall back to topaz.8 */
#define TRWF_NODELZIP           0x00001000L     /* Don't zip the window when Del is pressed */
#define TRWF_SIMPLEREFRESH      0x00002000L     /* *** OBSOLETE *** (V3+) */
#define TRWF_ZIPTOCURRENTPOS    0x00004000L     /* Will zip the window at the current position (OS3.0+) */
#define TRWF_APPWINDOW          0x00008000L     /* Create an AppWindow without using class_dropbox */
#define TRWF_ACTIVATESTRGAD     0x00010000L     /* Activate first string gadget after opening the window */
#define TRWF_HELP               0x00020000L     /* Pressing <Help> will create a TRMS_HELP message (V4) */
#define TRWF_SYSTEMACTION       0x00040000L     /* System status messages will be sent (V4) */


/***********************************************************************************************************/
/********************************************************************************************** Menu flags */
/***********************************************************************************************************/

#define TRMF_CHECKIT            0x00000001L     /* Leave space for a checkmark */
#define TRMF_CHECKED            0x00000002L     /* Check the item (includes TRMF_CHECKIT) */
#define TRMF_DISABLED           0x00000004L     /* Ghost the menu/item */


/***********************************************************************************************************/
/**************************************************************************************** Window positions */
/***********************************************************************************************************/

enum TR_WindowPositions
{
  TRWP_DEFAULT = 0,         /* Let Triton choose a good position */
  TRWP_BELOWTITLEBAR,       /* Left side of screen, below title bar */
  TRWP_CENTERTOP = 1025,    /* Top of screen, centered on the title bar */
  TRWP_TOPLEFTSCREEN,       /* Top left corner of screen */
  TRWP_CENTERSCREEN,        /* Centered on the screen */
  TRWP_CENTERDISPLAY,       /* Centered on the currently displayed clip */
  TRWP_MOUSEPOINTER,        /* Under the mouse pointer */
  TRWP_ABOVECOORDS =  2049, /* Above coordinates from the dimensions struct */
  TRWP_BELOWCOORDS          /* Below coordinates from the dimensions struct */
};


/***********************************************************************************************************/
/************************************************************************** Backfill types / System images */
/***********************************************************************************************************/

enum TR_Images
{
  /* Abstract patterns */
  TRBF_WINDOWBACK = 0,            /* Window backfill */
  TRBF_REQUESTERBACK,             /* Requester backfill */
  /* Basic paterns */
  TRBF_NONE,                      /* No backfill (= Fill with BACKGROUNDPEN) */
  TRBF_SHINE,                     /* Fill with SHINEPEN */
  TRBF_SHINE_SHADOW,              /* Fill with SHINEPEN + SHADOWPEN */
  TRBF_SHINE_FILL,                /* Fill with SHINEPEN + FILLPEN */
  TRBF_SHINE_BACKGROUND,          /* Fill with SHINEPEN + BACKGROUNDPEN */
  TRBF_SHADOW,                    /* Fill with SHADOWPEN */
  TRBF_SHADOW_FILL,               /* Fill with SHADOWPEN + FILLPEN */
  TRBF_SHADOW_BACKGROUND,         /* Fill with SHADOWPEN + BACKGROUNDPEN */
  TRBF_FILL,                      /* Fill with FILLPEN */
  TRBF_FILL_BACKGROUND,           /* Fill with FILLPEN + BACKGROUNDPEN */
  /* System images */
  TRSI_USBUTTONBACK = 0x00010002, /* Unselected button backfill */
  TRSI_SBUTTONBACK                /* Selected button backfill */
};


/***********************************************************************************************************/
/********************************************************************************************* Frame types */
/***********************************************************************************************************/

enum TR_FrameTypes
{
  /* Copies of the GadTools BBFT_#? types */
  TRFT_BUTTON = 1,
  TRFT_RIDGE,
  TRFT_ICONDROPBOX,
  /* Triton's low-level frame types */
  TRFT_XENBUTTON1 = 33,
  TRFT_XENBUTTON2,
  TRFT_NEXTBUTTON,
  /* Triton's abstract frame types */
  TRFT_ABSTRACT_BUTTON = 65,
  TRFT_ABSTRACT_ICONDROPBOX,
  TRFT_ABSTRACT_FRAMEBOX,
  TRFT_ABSTRACT_PROGRESS,
  TRFT_ABSTRACT_GROUPBOX
};


/***********************************************************************************************************/
/*********************************************************************************************** Pen types */
/***********************************************************************************************************/

enum TR_PenTypes
{
  TRPT_SYSTEMPEN = 0,
  TRPT_GRAPHICSPEN = 1,
  TRPT_TRITONPEN = 128
};

enum TR_TritonPenTypes /* TRPT_TRITONPEN */
{
  TRTP_NORMUSCORE         = 0,
  TRTP_HIGHUSCORE         = 1,
  TRTP_HALFSHINE          = 2,
  TRTP_HALFSHADOW         = 3,
  TRTP_USSTRINGGADBACK    = 4,
  TRTP_SSTRINGGADBACK     = 5,
  TRTP_USSTRINGGADFRONT   = 6,
  TRTP_SSTRINGGADFRONT    = 7
};


/***********************************************************************************************************/
/************************************************************************************ Various object flags */
/***********************************************************************************************************/

/* General flags */
#define TROF_RAISED             0x00000001L     /* Raised object                                 */
#define TROF_HORIZ              0x00000002L     /* Horizontal object \ Set automatically         */
#define TROF_VERT               0x00000004L     /* Vertical object   / in groups                 */
#define TROF_RIGHTALIGN         0x00000008L     /* Align object to the right border if available */
#define TROF_GENERAL_MASK       0x000000FFL     /* PRIVATE! */

/* Text flags for different kinds of text-related objects */
#define TRTX_NOUNDERSCORE       0x00000100L     /* Don't interpret underscores */
#define TRTX_HIGHLIGHT          0x00000200L     /* Highlight text */
#define TRTX_3D                 0x00000400L     /* 3D (shadowed) look */
#define TRTX_BOLD               0x00000800L     /* Softstyle 'bold' */
#define TRTX_TITLE              0x00001000L     /* A title (e.g. of a group) */
#define TRTX_MULTILINE          0x00002000L     /* A multi-line text. See TR_PrintText() autodoc clip */
#define TRTX_RIGHTALIGN         TROF_RIGHTALIGN /* Align text to the right border */
#define TRTX_CENTER             0x00004000L     /* Center text */
#define TRTX_SELECTED           0x00008000L     /* PRIVATE! */


/***********************************************************************************************************/
/******************************************************************************************** Menu entries */
/***********************************************************************************************************/

#define TRMN_BARLABEL           (-1L)           /* A barlabel instead of text */


/***********************************************************************************************************/
/********************************************************************************* Tags for TR_CreateApp() */
/***********************************************************************************************************/

#define TRCA_Name               (TAG_USER+1)
#define TRCA_LongName           (TAG_USER+2)
#define TRCA_Info               (TAG_USER+3)
#define TRCA_Version            (TAG_USER+4)
#define TRCA_Release            (TAG_USER+5)
#define TRCA_Date               (TAG_USER+6)


/***********************************************************************************************************/
/******************************************************************************* Tags for TR_EasyRequest() */
/***********************************************************************************************************/

#define TREZ_ReqPos             (TAG_USER+1)
#define TREZ_LockProject        (TAG_USER+2)
#define TREZ_Return             (TAG_USER+3)
#define TREZ_Title              (TAG_USER+4)
#define TREZ_Activate           (TAG_USER+5)


/***********************************************************************************************************/
/*************************************************************** Public parts of the Application structure */
/***********************************************************************************************************/

#ifndef TR_THIS_IS_TRITON

typedef struct TR_App
{
  VOID *                        tra_MemPool;    /* The memory pool */
  ULONG                         tra_BitMask;    /* Bits to Wait() for */
  STRPTR                        tra_Name;       /* Unique name */
} TR_App;

#endif


/***********************************************************************************************************/
/********************************************************************* Public parts of the Class structure */
/***********************************************************************************************************/

#ifndef TR_THIS_IS_TRITON

typedef struct TR_Class
{
  struct MinNode                trc_Node;         /* PRIVATE! */
  struct TR_Class             * trc_SuperClass;
} TR_Class;

#endif


/***********************************************************************************************************/
/******************************************************************************** The Dimensions structure */
/***********************************************************************************************************/

typedef struct TR_Dimensions
{
  UWORD                         trd_Left;       /* Left */
  UWORD                         trd_Top;        /* Top */
  UWORD                         trd_Width;      /* Width */
  UWORD                         trd_Height;     /* Height */
  UWORD                         trd_Left2;      /* Left */
  UWORD                         trd_Top2;       /* Top */
  UWORD                         trd_Width2;     /* Width */
  UWORD                         trd_Height2;    /* Height */
  BOOL                          trd_Zoomed;     /* Window zoomed? */
  UWORD                         reserved[3];    /* For future expansions */
} TR_Dimensions;


/***********************************************************************************************************/
/***************************************** Default classes, attributes and flags (assembled automatically) */
/***********************************************************************************************************/

/* class_Object */

#ifndef TR_THIS_IS_TRITON
  struct TROD_Object
  {
    struct MinNode        Node;             /* The node for linking all objects */
    struct TR_Class *     Class;            /* The object's class */
    struct TR_Project *   Project;          /* The object's project */

    ULONG                 Reserved[6];
  };
#endif

#define TROB_Object             (TRTG_CLS+0x3D) /* A root class object */

/* class_DisplayObject */

#ifndef TR_THIS_IS_TRITON
  struct TROD_DisplayObject
  {
    struct TROD_Object    O;                /* Superclass object data */
    ULONG                 ID;               /* The object's ID */
    ULONG                 MinWidth;         /* The precalculated minimum width */
    ULONG                 MinHeight;        /* The precalculated minimum height */
    ULONG                 Left;             /* The X coordinate of the object */
    ULONG                 Top;              /* The Y coordinate of the object */
    ULONG                 Width;            /* The width of the object */
    ULONG                 Height;           /* The height of the object */
    ULONG                 Flags;            /* See below for flags */
    BOOL                  XResize;          /* Horizontally resizable? */
    BOOL                  YResize;          /* Vertically resizable? */
    STRPTR                QuickHelpString;  /* QuickHelp string */
    WORD                  Shortcut;         /* The object's shortcut */
    ULONG                 BackfillType;     /* The object's backfill type */
    BOOL                  Installed;        /* Does the object have an on-screen representation? */

    ULONG                 Reserved[4];      /* Private! */
  };
#endif

#define TROB_DisplayObject      (TRTG_CLS+0x3C) /* A basic display object */

#define TRDO_QuickHelpString    (TRTG_OAT+0x1E3)

/* Flags */
#define TROB_DISPLAYOBJECT_DISABLED    0x00100000L /* Disabled? */
#define TROB_DISPLAYOBJECT_RETURNOK    0x00200000L /* Activate with <Return> */
#define TROB_DISPLAYOBJECT_ESCOK       0x00400000L /* Activate with <Esc> */
#define TROB_DISPLAYOBJECT_TABOK       0x00800000L /* Activate with <Tab> */
#define TROB_DISPLAYOBJECT_SPACE       0x01000000L /* A spacing object? */

/* class_Text */

#define TROB_Text               (TRTG_CLS+0x30) /* A line of text */

#define TRTX_CLIPPED            0x00010000L     /* Text is clipped */
/* class_String */

#define TROB_String             (TRTG_CLS+0x37) /* A string gadget */

#define TRST_Filter             (TRTG_OAT+0x1E4)

#define TRST_INVISIBLE          0x00010000L     /* A password gadget -> invisible typing */
#define TRST_NORETURNBROADCAST  0x00020000L     /* <Return> keys will not be broadcast to the window */
#define TRST_FLOAT              0x00040000L     /* Separators "." and "," will be accepted only once */

/* class_Space */

#define TROB_Space              (TRTG_CLS+0x285)/* The spaces class */

#define TRST_NONE               1L              /* No space */
#define TRST_SMALL              2L              /* Small space */
#define TRST_NORMAL             3L              /* Normal space (default) */
#define TRST_BIG                4L              /* Big space */

/* class_Slider */

#define TROB_Slider             (TRTG_CLS+0x34) /* A slider gadget */

#define TRSL_Min                (TRTG_OAT+0x1DE)
#define TRSL_Max                (TRTG_OAT+0x1DF)

/* class_Scroller */

#define TROB_Scroller           (TRTG_CLS+0x35) /* A scroller gadget */

#define TRSC_Total              (TRTG_OAT+0x1E0)
#define TRSC_Visible            (TRTG_OAT+0x1E1)

/* class_Progress */

#define TROB_Progress           (TRTG_CLS+0x3A) /* A progress indicator */

/* class_Palette */

#define TROB_Palette            (TRTG_CLS+0x33) /* A palette gadget */

/* class_Listview */

#define TROB_Listview           (TRTG_CLS+0x39) /* A listview gadget */

#define TRLV_Top                (TRTG_OAT+0x1E2)
#define TRLV_VisibleLines       (TRTG_OAT+0x1E4)

#define TRLV_READONLY           0x00010000L     /* A read-only list */
#define TRLV_SELECT             0x00020000L     /* You may select an entry */
#define TRLV_SHOWSELECTED       0x00040000L     /* Selected entry will be shown */
#define TRLV_NOCURSORKEYS       0x00080000L     /* Don't use arrow keys */
#define TRLV_NONUMPADKEYS       0x00100000L     /* Don't use numeric keypad keys */
#define TRLV_FWFONT             0x00200000L     /* Use the fixed-width font */
#define TRLV_NOGAP              0x00400000L     /* Don't leave a gap below the list */

/* class_Line */

#define TROB_Line               (TRTG_CLS+0x2D) /* A simple line */

/* class_Image */

#define TROB_Image              (TRTG_CLS+0x3B) /* An image */

#define TRIM_BOOPSI             0x00010000L     /* Use a BOOPSI IClass image */

/* class_Group */

#define TRGR_Horiz              (TAG_USER+201)  /* Horizontal group */
#define TRGR_Vert               (TAG_USER+202)  /* Vertical group */
#define TRGR_End                (TRTG_OAT2+0x4B)/* End of a group */

#define TRGR_PROPSHARE          0x00000000L     /* Default: Divide objects proportionally */
#define TRGR_EQUALSHARE         0x00000001L     /* Divide objects equally */
#define TRGR_PROPSPACES         0x00000002L     /* Divide spaces proportionally */
#define TRGR_ARRAY              0x00000004L     /* Top-level array group */

#define TRGR_ALIGN              0x00000008L     /* Align resizeable objects in secondary dimension */
#define TRGR_CENTER             0x00000010L     /* Center unresizeable objects in secondary dimension */

#define TRGR_FIXHORIZ           0x00000020L     /* Don't allow horizontal resizing */
#define TRGR_FIXVERT            0x00000040L     /* Don't allow vertical resizing */
#define TRGR_INDEP              0x00000080L     /* Group is independant of surrounding array */

/* class_FrameBox */

#define TROB_FrameBox           (TRTG_CLS+0x32) /* A framing box */

#define TRFB_GROUPING           0x00000001L     /* A grouping box */
#define TRFB_FRAMING            0x00000002L     /* A framing box */
#define TRFB_TEXT               0x00000004L     /* A text container */

/* class_DropBox */

#define TROB_DropBox            (TRTG_CLS+0x38) /* An icon drop box */

/* class_DragItem */

#define TROB_DragItem           (TRTG_CLS+0x3E) /* A draggable item */

/* class_Cycle */

#define TROB_Cycle              (TRTG_CLS+0x36) /* A cycle gadget */

#define TRCY_MX                 0x00010000L     /* Unfold the cycle gadget to a MX gadget */
#define TRCY_RIGHTLABELS        0x00020000L     /* Put the labels to the right of a MX gadget */

/* class_CheckBox */

#define TROB_CheckBox           (TRTG_CLS+0x2F) /* A checkbox gadget */

/* class_Button */

#define TROB_Button             (TRTG_CLS+0x31) /* A BOOPSI button gadget */

#define TRBU_RETURNOK           0x00010000L     /* <Return> answers the button */
#define TRBU_ESCOK              0x00020000L     /* <Esc> answers the button */
#define TRBU_SHIFTED            0x00040000L     /* Shifted shortcut only */
#define TRBU_UNSHIFTED          0x00080000L     /* Unshifted shortcut only */
#define TRBU_YRESIZE            0x00100000L     /* Button resizeable in Y direction */
#define TRBT_TEXT               0L              /* Text button */
#define TRBT_GETFILE            1L              /* GetFile button */
#define TRBT_GETDRAWER          2L              /* GetDrawer button */
#define TRBT_GETENTRY           3L              /* GetEntry button */


/***********************************************************************************************************/
/******************************************************************* Public parts of the Project structure */
/***********************************************************************************************************/

#ifndef TR_THIS_IS_TRITON

typedef struct TR_Project
{
  struct TROD_Object            tro_SC_Object;                  /* PRIVATE! */
  struct TR_App *               trp_App;                        /* Our application */
  VOID *                        trp_MemPool;                    /* The memory pool */
  ULONG                         trp_ID;                         /* The project's ID */
  ULONG                         trp_IDCMPFlags;                 /* The IDCMP flags */
  struct Window *               trp_Window;                     /* The default window */
  UWORD                         trp_AspectFixing;               /* Pixel aspect correction factor */
} TR_Project;

#endif


/***********************************************************************************************************/
/************************************************************************************************* The End */
/***********************************************************************************************************/

#endif /* LIBRARIES_TRITON_H */
