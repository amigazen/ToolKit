# ToolKit

A standard SDK configuration and universal developer experience for Amiga development

## Setup your ToolKit

The ToolKit project aims to standardise the development tool and SDK configurations for classic Amiga developers, in order to make collaboration easier in the 21st century world of online collaboration and open source.

It is intended that a fully automated installation of ToolKit, currently in development, will soon be available here in this project repository.

Until that time, you can setup a ToolKit compatible SDK by following these instructions:
```
- Unpack the ToolKit SDK.lha archive to a suitable location with enough storage and working space e.g. Work:SDK
- Assign SDK: to this location and ensure this is set in your User-Startup or SDK-Startup (provided with ToolKit) shell script
- Download and unpack the latest Amiga NDK to a similarly suitable location, usually the directory 'NDK' inside your SDK location
-- At the time of writing the NDK is available at (https://www.hyperion-entertainment.com/index.php/downloads?view=download&layout=form&file=126)
- Assign NDK to this location and ensure this is also set in your User-Startup or SDK-Startup (provided with ToolKit) shell script
- Ensure you have at least one of the supported C compilers installed (see below) and more importantly that you have the C compiler compatible to the project you wish to build - not all ToolKit compatible projects support all compilers
- For VBCC, unpack the ToolKit_VBCC.lha on top of your VBCC installation, this will install PosixLib configuration
```
Follow these remaining steps:
-Setup the following assigns:
```
;BEGIN ToolKit
Assign >NIL: SDK: {SDK_PATH}
Assign >NIL: include: SDK:Include_H ADD
Assign >NIL: include: SDK:Include_I ADD
Assign >NIL: lib: SDK:lib
Assign >NIL: Libs: SDK:Libs ADD
Assign >NIL: NDK: {NDK_PATH}
Assign >NIL: lib: NDK:lib ADD
Assign include: NDK:Include_H ADD
Assign include: NDK:Include_I ADD
Assign netinclude: NDK:SANA+RoadshowTCP-IP/netinclude
Path SDK:C NDK:C ADD
;END ToolKit
```
Then finally:
```
From the NDK folder:
- Copy NDK:Tools/CatComp/CatComp to SDK:C/
- Download the following additional SDK components as required by your projects
- For AmiSSL, download the latest release of (https://www.aminet.net/util/libs/AmiSSL-v5-SDK.lha)
-- Unpack the AmiSSL-v5-SDK archive to a location of your choice such as _SDK:Local_
-- Assign sslinclude: to the AmiSSL include directory e.g. `Assign sslinclude: SDK:Local/AmiSSL/include ADD`
- For P96, download the latest release of (https://wiki.icomp.de/w/images/e/e9/Develop.lha)
-- Unpack the Develop archive to a location of your choice such as _SDK:Local_
-- Move or copy the following files to your SDK: location
-- lib/picasso96.lib -> SDK:lib/picasso96.lib
-- libraries/picasso96.h -> SDK:Include_h/libraries/picasso96.h
-- TODO: Copy the rest of the P96 include files
```

Note that the NDK and other complex SDKs such as the AmiSSL SDK are kept separate from the ToolKit directories, so that they can be updated independently without having to figure out which files have changed and merge directories.

## Compiler support

ToolKit compliant projects must support at least one of the supported compilers, however not all projects will support all compilers. Indeed it's likely that a project will only support one specific compiler unless work has been done to add additional configurations.

As a rule of thumb, choose a C compiler that best suits your project:
- For updating most legacy projects, use SAS/C
- For the small number of legacy open source projects that used DICE, use the DICE-nx compiler instead
- For brand new projects and for targeting all Amiga-like platforms, use VBCC
- For porting projects that use standard C and are inherently meant to be POSIX portable use VBCC together with the PosixLib configuration
- For linux porting projects or projects that need a combined classic Amiga and OS4 code base, use GCC and the rest of the ADE tools.

### SAS/C 

The SAS/C compiler, version 6.58 or the later 7.0 release with experimental C++ support, was and still is the most popular C compiler used for classic Amiga projects - many open source releases on Aminet and elsewhere expect the developer to have SAS/C.

SAS/C for Amiga has not been sold commercially since the early 1990s but many developers will likely have access to a copy. 

ToolKit is designed to work with an out of the box install of SAS/C in the normal locations, that is, make sure that your SAS/C installation has been setup like this wherever you have installed it (e.g. in _SDK:sc/_):

```
;BEGIN SAS/C
Assign >NIL: sc: SDK:sc
Assign >NIL: lib: sc:lib ADD
Assign >NIL: include: sc:include ADD
Assign >NIL: cxxinclude: sc:cxxinclude
Path >NIL: sc:c ADD
;END SAS/C
```

Do NOT put any static libraries or include files apart from the ones that come with SAS/C into the sc: directories, this will defeat the object of using ToolKit's standardised configuration. Using ToolKit you can keep your SAS/C installation clean.

To differentiate SAS/C makefiles from other makefiles, ToolKit projects will always name them _smakefile_

### VBCC

The VBCC compiler is a great alternative to SAS/C with better support for C standards, and a universal configuration for both native and cross compilation, as well as support for all Amiga-like platforms.

ToolKit also includes the GNU **make** command which is the preferred build driver to use with VBCC.

ToolKit does not include the VBCC directly - you will need to download it from (http://sun.hasenbraten.de/vbcc/)

Get both the compiler archive (http://phoenix.owl.de/vbcc/current/vbcc_bin_amigaos68k.lha) and the target archive (http://phoenix.owl.de/vbcc/current/vbcc_target_m68k-amigaos.lha)

Unpack them both and run the installaer, making sure that your User-Startup or SDK-Startup is correctly set up to point to your installation location e.g. _SDK:vbcc_
```
;BEGIN vbcc
Assign >NIL: vbcc: SDK:vbcc
Path >NIL: vbcc:bin ADD
SetEnv VBCC vbcc:
;BEGIN vbcc-m68k-amigaos
Assign >NIL: vincludeos3: vbcc:targets/m68k-amigaos/include
Assign >NIL: vincludeos3: "include:" ADD
Assign >NIL: vlibos3: vbcc:targets/m68k-amigaos/lib
;END vbcc-m68k-amigaos
;END vbcc
```

Then get the VBCC PosixLib from (https://www.aminet.net/dev/c/vbcc_PosixLib.lha) and unpack this to the same location where you installed the VBCC target

ToolKit includes a ready-made configuration to use VBCC with the VBCC PosixLib. Unpack the ToolKit_VBCC.lha archive over the top of your VBCC install.

Do NOT put any static libraries or include files apart from the ones that come with VBCC into the vbcc: directories, this will defeat the object of using ToolKit's standardised configuration. Using ToolKit you can keep your VBCC installation almost clean, except for the PosixLib configurations.

To differentiate VBCC makefiles from other makefiles such as those meant for use with GCC, ToolKit has adopted the name 'vmakefile' for any makefile designed to be used with VBCC, although vmakefiles are in fact still valid GNU make files. Since make will not automatically find a vmakefile in the current directory, you can usually build the project with:
```
make -f vmakefile
```

### GCC

For now, it is enough to install the _Amiga Development Environment_ or _ADE_ (a project similar to and one of the inspirations for _ToolKit_), following these instructions:

1) Unpack the archive (https://www.aminet.net/dev/gcc/ADE.lha) to a suitable location e.g. SDK:ADE/
2) Unpack the archive (https://www.aminet.net/dev/gcc/ADE-repack.lha) over the top of the same location (the repack release is missing some crucial empty directories needed by ADE-startup)
3) Set the ADE-Startup script to run in your User-Startup or add it to your ToolKit SDK-Startup. N.B. do not run it more than once per session.
4) TODO: Instructions on configuring ADE to use the NDK3.2 os-include folder instead of the ones it comes with
5) TODO: Instructions for setting up ADE to use latest libnix and clib2 builds

Where a project uses GCC, the makefile will be called simply _makefile_ and the driver will be the same SDK:C/make used with VBCC

### DICE

ToolKit does not currently support the DICE C compiler however since DICE has been made open source, you can find a working version here https://github.com/dice-nx - it is expected that DICE support will eventually be added to ToolKit.  

### StormC, Aztec C, Lattice C, HiSoft C++, Maxon C++

These older, proprietary compilers are not supported by ToolKit even though they are supported by the latest NDK. Still, contributions are welcome if anyone wishes to see ToolKit support these compilers.

## ToolKit inventory

ToolKit currently consists of the following command line tools, found in SDK:C/
- make - The GNU make build driver, for VBCC and GCC
- CShell - an Amiga native csh-like command shell
- rman - generates _man_ files 
- ctags - generates C prototypes from an input file
- Texinfo makeinfo - generates 
- FlexCat - an alternative, cross-platform localization catalog compiler (coming soon)

The following third party tools should be downloaded and installed 
- Copy the following tools from the NDK:Tools directory to SDK:C
- CatComp - the localization catalog compiler 
- Autodoc - the automated API documentation maker
- LibDescConverter to generate shared library prototypes and pragmas from an .sfd file, also placed in SDK:C
- currently only available from https://gitlab.com/boemann/libdescconverter
- TODO: ToolKit assumes you have LhA somewhere in your path. If you don't, get it  and install to SDK:C/

ToolKit also includes the following static and shared libraries, found in SDK:lib and SDK:Libs respectively:
- asyncio.library - Martin Taillefer's asynchronous i/o shared library
- z.library - zlib as a shared library 
- gtlayout.library - the GadTools layout library
- reaction.lib - a remake of the autoopen static link library for ReAction compatible to, but not reusing any code from, the original

ToolKit supports the following application frameworks for Amiga:
- OpenTriton triton.library
- BGUI bgui.library - coming soon
- ReAction - included with the NDK
- APlusPlus - coming soon in a new expanded version 

## Frequently Asked Questions 

### Is ToolKit going to support OS4?

OS4 has a much more comprehensive full SDK that inspired many of the ideas behind ToolKit.

Where appropriate, ToolKit aims to offer a similar set of capabilities as the OS4 SDK. If and when an OS4 version of ToolKit is released it will be complementary to, not duplicating functionality of, the OS4 SDK.

### Is ToolKit going to support AROS?

AROS enthusiasts are very welcome and encouraged to contribute a similar SDK inspired by ToolKit, for AROS.

### Is ToolKit going to support MorphOS?

MorphOS enthusiasts are very welcome and encouraged to contribute a similar SDK inspired by ToolKit, for MorphOS.

### What additional features are coming to ToolKit?

To avoid empty promises, new features will only be announced when close to release, although the intention is stated above to create an automated installation of the ToolKit core features. 

### Don't we need _git_ to be able to collaborate over the internet?

It is true that classic Amiga lacks a version of the git command, and even OS4 has only a very limited 'sgit' implementation. Until such time as an Amiga native build of git is available, it is suggested to do primary development on an emulated Amiga device, on projects stored on the host's shared filesystem, so that the host platform can be used for git and code editing activities, while builds can be native or cross-compiled (using vamos, or a cross-compiler build of GCC), and testing can be done on the emulated Amiga.

### Do you only support C?

The intention is to support at least C, C++ and probably Amiga E with ToolKit. After that, it depends.

### Why doesn't ToolKit come with all batteries included such as the NDK or C compilers?

ToolKit is built on open source. Non-open source components cannot be bundled with ToolKit releases.

### What's with the name _ToolKit_?

**SDK** or _Software Development Kit_ is on its own too generic a name, while the official Amiga SDK's have always been called _Native Development Kits_ or **NDK** for short. Since the Amiga Workbench metaphor describes software as 'Tools', and the suffix -Kit is common in the software development world (especially for the Cocoa/Swift platform  where the SDK for every subsystem is a separate 'Kit') to describe specific type of SDK, the name ToolKit was chosen to emphasise that this is an SDK, for making Tools.

### What is the amigazen project?

ToolKit is universal developer experience produced by the _amigazen project_, which is itself an attempt to revive abandoned open source projects for the classic Amiga and Amiga-like platforms and catalyse new development by making it easier for old projects to build straight out of the box. 

When inheriting legacy software the first question any professional software developer needs to know is _Does it build?_ and with long since abandoned Amiga projects the answer is often 'no it needs a bunch of missing dependencies, specific versions of include files, a bespoke configuration of compiler only found on the original developer's hard disk (currently in a landfill somewhere), and a bunch of hardcoded device volume and directory names. 

amigazen project created ToolKit as a common standard for all projects to follow so that developers can be sure that if their development environment is setup for ToolKit, then other developers can eaasily build and contribute to their projects.

## Haiku

_A web, suddenly_
(ami gazen)

__Forty years meditation__
(Yonjuu no zazen ga)

_Minds awaken, free_
(kokoro hiraku)