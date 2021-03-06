-This version of GNU make has been tested on
-OpenVMS V8.3 (Alpha) and V8.4 (Integrity).
+Overview:                                                       -*-text-mode-*-
+---------
 
-Build instructions
-Make a 1st version
-       $ @makefile.com  ! ignore any compiler and/or linker warning
-       $ copy make.exe 1st-make.exe
-  Use the 1st version to generate a 2nd version
-       $ mc sys$disk:[]1st-make clean  ! ignore any file not found messages
-       $ mc sys$disk:[]1st-make
-  Verify your 2nd version
-       $ copy make.exe 2nd-make.exe
-       $ mc sys$disk:[]2nd-make clean
-       $ mc sys$disk:[]2nd-make
-  Don't use the HP C V7.2-001 compiler, which has an incompatible change
-  how __STDC__ is defined. This results at least in compile time warnings.
-
-Changes since GNU make 3.82
+  This version of GNU make has been tested on:
+  OpenVMS V8.3/V8.4 (Alpha) and V8.4 (Integrity) AND V7.3 (VAX)
+
+  This version of GNU Make is intended to be run from DCL to run
+  make scripts with a special syntax that is described below.  It
+  likely will not be able to run unmodified Unix makefiles.
+
+  There is an older implementation of GNU Make that was ported to GNV.
+  Work is now in progress to merge that port to get a single version
+  of GNU Make available.  When that merge is done, GNU Make will auto
+  detect that it is running under a Posix shell and then operate as close to
+  GNU Make on Unix as possible.
+
+  The descriptions below are for running GNU make from DCL or equivalent.
+
+
+Recipe differences:
+-------------------
+
+  GNU Make for OpenVMS can not currently run native Unix make files because of
+  differences in the implementation that it is not aware of the GNV packages.
+
+  I am trying to document the current behavior in this section.  This is based
+  on the information in the file NEWS. and running the test suite.
+  TODO: More tests are needed to validate and demonstrate the OpenVMS
+  expected behavior.
+
+  The format for recipes are a combination of Unix macros, a subset of
+  simulated UNIX commands, some shell emulation, and OpenVMS commands.
+  This makes the resulting makefiles unique to the OpenVMS port of GNU make.
+
+  If you are creating a OpenVMS specific makefile from scratch, you should also
+  look at MMK (Madgoat Make) available at https://github.com/endlesssoftware/mmk
+  MMK uses full OpenVMS syntax and a persistent subprocess is used for the
+  recipe lines, allowing multiple line rules.
+
+  The default makefile search order is "makefile.vms", "gnumakefile",
+  "makefile".  TODO: See if that lookup is case sensitive.
+
+  When Make is invoked from DCL, it will create a foreign command
+  using the name of executable image, with any facility prefix removed,
+  for the duration of the make program, so it can be used internally
+  to recursively run make().  The macro MAKE_COMMAND will be set to
+  this foreign command.
+
+  When make is launched from an exec*() command from a C program,
+  the foreign command is not created.  The macro MAKE_COMMAND will be
+  set to the actual command passed as argv[0] to the exec*() function.
+
+  If the DCL symbol or logical name GNV$MAKE_USE_MCR exists, then
+  the macro MAKE_COMMAND will be set to be an "MCR" command with the
+  absolute path used by DCL to launch make.  The foreign command
+  will not be created.
+
+  The macro MAKE is set to be the same value as the macro MAKE_COMMAND
+  on all platforms.
+
+  Each recipe command is normally run as a separate spawned processes,
+  except for the cases documented below where a temporary DCL command
+  file may be used.
+
+  BUG: Testing has shown that the commands in the temporary command files
+  are not always created properly.  This issue is still under investigation.
+
+  Any macros marked as exported are temporarily created as DCL symbols
+  for child images to use.  DCL symbol substitution is not done with these
+  commands.
+  TODO: Add symbol substitution.
+
+  When a temporary DCL command file is used, DCL symbol substitution
+  will work.
+
+  Command lines of excessive length are broken and written to a command file
+  in sys$scratch:. There's no limit to the lengths of commands (and no need
+  for .opt files :-) any more.
+
+  The '<', '>' and '>>' redirection has been implemented by using
+  temporary command files.  These will be described later.
+
+  The DCL symbol or logical name GNV$MAKE_USE_CMD_FILE when set to a
+  string starting with one of '1','T', or 'E' for "1", "TRUE", or "ENABLE",
+  then temporary DCL command files are always used for running commands.
+  In this case, the exported environment environment variables are
+  created by command file.  BUG: Environment variables that hold values
+  with dollar signs in them are not exported correctly.
+
+  GNU Make generally does text comparisons for the targets and sources.  The
+  make program itself can handle either Unix or OpenVMS format filenames, but
+  normally does not do any conversions from one format to another.
+  TODO: The OpenVMS format syntax handling is incomplete.
+  TODO: ODS-5 EFS support is missing.
+  BUG: The internal routines to convert filenames to and from OpenVMS format
+  do not work correctly.
+
+  Note: In the examples below, line continuations such as a backslash may have
+  been added to make the examples easier to read in this format.
+  BUG: That feature does not completely work at this time.
+
+  Since the OpenVMS utilities generally expect OpenVMS format paths, you will
+  usually have to use OpenVMS format paths for rules and targets.
+  BUG: Relative OpenVMS paths may not work in targets, especially combined
+  with vpaths.  This is because GNU make will just concatenate the directories
+  as it does on Unix.
+
+  The variables $^ and $@ separate files with commas instead of spaces.
+  While this may seem the natural thing to do with OpenVMS, it actually
+  causes problems when trying to use other make functions that expect the
+  files to be separated by spaces.  If you run into this, you need the
+  following workaround to convert the output.
+  TODO: Look at have the $^ and $@ use spaces like on Unix and have
+  and easy to use function to do the conversions and have the built
+  in OpenVMS specific recipes and macros use it.
+
+  Example:
+
+comma := ,
+empty :=
+space := $(empty) $(empty)
+
+foo: $(addsuffix .3,$(subs $(comma),$(space),$^)
+
+
+  Makefile variables are looked up in the current environment. You can set
+  symbols or logicals in DCL and evaluate them in the Makefile via
+  $(<name-of-symbol-or-logical>).  Variables defined in the Makefile
+  override OpenVMS symbols/logicals.
+
+  OpenVMS logical and symbols names show up as "environment" using the
+  origin function.  when the "-e" option is specified, the origion function
+  shows them as "environment override".  On Posix the test scripts indicate
+  that they should show up just as "environment".
+
+  When GNU make reads in a symbol or logical name into the environment, it
+  converts any dollar signs found to double dollar signs for convenience in
+  using DCL symbols and logical names in recipes.  When GNU make exports a
+  DCL symbol for a child process, if the first dollar sign found is followed
+  by second dollar sign, then all double dollar signs will be convirted to
+  single dollar signs.
+
+  The variable $(ARCH) is predefined as IA64, ALPHA or VAX respectively.
+  Makefiles for different OpenVMS systems can now be written by checking
+  $(ARCH).  Since IA64 and ALPHA are similar, usually just a check for
+  VAX or not VAX is sufficient.
+
+  You may have to update makefiles that assume VAX if not ALPHA.
+
+ifeq ($(ARCH),VAX)
+  $(ECHO) "On the VAX"
+else
+  $(ECHO) "On the ALPHA  or IA64"
+endif
+
+  Empty commands are handled correctly and don't end in a new DCL process.
+
+  The exit command needs to have OpenVMS exit codes.  To pass a Posix code
+  back to the make script, you need to encode it by multiplying it by 8
+  and then adding %x1035a002 for a failure code and %x1035a001 for a
+  success.  Make will interpret any posix code other than 0 as a failure.
+  TODO: Add an option have simulate Posix exit commands in recipes.
+
+  Lexical functions can be used in pipes to simulate shell file test rules.
+
+  Example:
+
+  Posix:
+b : c ; [ -f $@ ] || echo >> $@
+
+  OpenVMS:
+b : c ; if f$$search("$@") then pipe open/append xx $@ ; write xx "" ; close xx
+
+
+  You can also use pipes and turning messages off to silently test for a
+  failure.
+
+x = %x1035a00a
+
+%.b : %.c
+<tab>pipe set mess/nofac/noiden/nosev/notext ; type $^/output=$@ || exit $(x)
+
+
+Runtime issues:
+
+  The OpenVMS C Runtime has a convention for encoding a Posix exit status into
+  to OpenVMS exit codes.  These status codes will have the hex value of
+  0x35a000.  OpenVMS exit code may also have a hex value of %x10000000 set on
+  them.  This is a flag to tell DCL not to write out the exit code.
+
+  To convert an OpenVMS encoded Posix exit status code to the original code
+  You subtract %x35a000 and any flags from the OpenVMS code and divide it by 8.
+
+  WARNING: Backward-incompatibility!
+  The make program exit now returns the same encoded Posix exit code as on
+  Unix. Previous versions returned the OpenVMS exit status code if that is what
+  caused the recipe to fail.
+  TODO: Provide a way for scripts calling make to obtain that OpenVMS status
+  code.
+
+  Make internally has two error codes, MAKE_FAILURE and MAKE_TROUBLE.  These
+  will have the error "-E-" severity set on exit.
+
+  MAKE_TROUBLE is returned only if the option "-q" or "--question" is used and
+  has a Posix value of 1 and an OpenVMS status of %x1035a00a.
+
+  MAKE_FAILURE has a Posix value of 2 and an OpenVMS status of %x1035a012.
+
+  Output from GNU make may have single quotes around some values where on
+  other platforms it does not.  Also output that would be in double quotes
+  on some platforms may show up as single quotes on VMS.
+
+  There may be extra blank lines in the output on VMS.
+  https://savannah.gnu.org/bugs/?func=detailitem&item_id=41760
+
+  There may be a "Waiting for unfinished jobs..." show up in the output.
+
+  Error messages generated by Make or Unix utilities may slightly vary from
+  Posix platforms.  Typically the case may be different.
+
+  When make deletes files, on posix platforms it writes out 'rm' and the list
+  of files.  On VMS, only the files are writen out, one per line.
+  TODO: VMS
+
+  There may be extra leading white space or additional or missing whitespace
+  in the output of recipes.
+
+  GNU Make uses sys$scratch: for the tempfiles that it creates.
+
+  The OpenVMS CRTL library maps /tmp to sys$scratch if the TMP: logical name
+  does not exist.  As the CRTL may use both sys$scratch: and /tmp internally,
+  if you define the TMP logical name to be different than SYS$SCRATCH:,
+  you may end up with only some temporary files in TMP: and some in SYS$SCRATCH:
+
+  The default include directory for including other makefiles is
+  SYS$SYSROOT:[SYSLIB] (I don't remember why I didn't just use
+  SYS$LIBRARY: instead; maybe it wouldn't work that way).
+  TODO:  A better default may be desired.
+
+  If the device for a file in a recipe does not exist, on OpenVMS an error
+  message of "stat: <file>: no such device or address" will be output.
+
+  Make ignores success, informational, or warning errors (-S-, -I-, or
+  -W-).  But it will stop on -E- and -F- errors. (unless you do something
+  to override this in your makefile, or whatever).
+
+
+Unix compatibilty features:
 ---------------------------
 
-Fix build problems.
-
-The new feature "Loadable objects" is not yet supported. If you need it,
-please send a change request or submit a bug report.
-
-The new option --output-sync (-O) is accepted but has no effect: GNU make
-for VMS does not support running multiple commands simultaneously.
-
-Changes for GNU make 3.82
-
-Michael Gehre (at VISTEC-SEMI dot COM) supplied a fix for a problem with
-timestamps of object modules in OLBs. The timestamps were not correctly
-adjusted to GMT based time, if the local VMS time was using a daylight saving
-algorithm and if daylight saving was switched off.
-
-John Eisenbraun (at HP dot COM) supplied fixes and and an enhancement to append
-output redirection in action lines.
-
-Rework of ctrl+c and ctrl+y handling.
-
-Fix a problem with cached strings, which showed on case-insensitive file
-systems.
-
-Build fixes for const-ified code in VMS specific sources.
-
-A note on appending the redirected output. With this change, a simple mechanism
-is implemented to make ">>" work in action lines. In VMS there is no simple
-feature like ">>" to have DCL command or program output redirected and appended
-to a file. GNU make for VMS already implements the redirection of output. If
-such a redirection is detected, an ">" on the action line, GNU make creates a
-DCL command procedure to execute the action and to redirect its output. Based
-on that, now ">>" is also recognized and a similar but different command
-procedure is created to implement the append. The main idea here is to create a
-temporary file which collects the output and which is appended to the wanted
-output file. Then the temporary file is deleted. This is all done in the
-command procedure to keep changes in make small and simple. This obviously has
-some limitations but it seems good enough compared with the current ">"
-implementation. (And in my opinion, redirection is not really what GNU make has
-to do.) With this approach, it may happen that the temporary file is not yet
-appended and is left in SYS$SCRATCH. The temporary file names look like
-"CMDxxxxx.". Any time the created command procedure can not complete, this
-happens. Pressing Ctrl+Y to abort make is one case. In case of Ctrl+Y the
-associated command procedure is left in SYS$SCRATCH as well. Its name is
-CMDxxxxx.COM.
-
-Change in the Ctrl+Y handling. The CtrlY handler now uses $delprc to delete all
-children. This way also actions with DCL commands will be stopped. As before
-the CtrlY handler then sends SIGQUIT to itself, which is handled in common
-code.
-
-Change in deleteing temporary command files. Temporary command files are now
-deleted in the vms child termination handler. That deletes them even if
-a Ctrl+C was pressed.
-
-The behavior of pressing Ctrl+C is not changed. It still has only an effect,
-after the current action is terminated. If that doesn't happen or takes too
-long, Ctrl+Y should be used instead.
-
-Changes for GNU make 3.80
-
-. In default.c define variable ARCH as IA64 for VMS on Itanium systems.
-
-. In makefile.vms avoid name collision for glob and globfree.
-
-This is the VMS port of GNU Make done by Hartmut.Becker@compaq.com.
-
-It is based on the specific version 3.77k and on 3.78.1. 3.77k was done
-by Klaus K�mpf <kkaempf@rmi.de>, the code was based on the VMS port of
-GNU Make 3.60 by Mike Moretti.
-
-It was ported on OpenVMS/Alpha V7.1, DECC V5.7-006. It was re-build and
-tested on OpenVMS/Alpha V7.2, OpenVMS/VAX 7.1 and 5.5-2. Different
-versions of DECC were used. VAXC was tried: it fails; but it doesn't
-seem worth to get it working. There are still some PTRMISMATCH warnings
-during the compile. Although perl is working on VMS the test scripts
-don't work. The function $shell is still missing.
-
-There is a known bug in some of the VMS CRTLs. It is in the shipped
-versions of VMS V7.2 and V7.2-1 and in the currently (October 1999)
-available ECOs for VMS V7.1 and newer versions. It is fixed in versions
-shipped with newer VMS versions and all ECO kits after October 1999. It
-only shows up during the daylight saving time period (DST): stat()
-returns a modification time 1 hour ahead. This results in GNU make
-warning messages. For a just created source you will see:
+  The variable $(CD) is implemented as a built in Change Directory
+  command. This invokes the 'builtin_cd'  Executing a 'set default'
+  recipe doesn't do the trick, since it only affects the subprocess
+  spawned for that command.
+  TODO: Need more info on how to use and side effects
 
- $ gmake x.exe
- gmake.exe;1: *** Warning: File 'x.c' has modification time in the future (940582863 > 940579269)
- cc    /obj=x.obj x.c
- link  x.obj    /exe=x.exe
- gmake.exe;1: *** Warning:  Clock skew detected.  Your build may be incomplete.
+  Unix shell style I/O redirection is supported. You can now write lines like:
+  "<tab>mcr sys$disk:[]program.exe < input.txt > output.txt &> error.txt"
+  BUG: This support is not handling built in make macros with "<" in them
+  properly.
 
+  Posix shells have ":" as a null command.  OpenVMS generates a DCL warning
+  when this is encountered.  It would probably be simpler to have OpenVMS just
+  handle this instead of changing all the tests that use this feature.
+  https://savannah.gnu.org/bugs/index.php?41761
 
-New in 3.78.1:
+  A note on appending the redirected output.  A simple mechanism is
+  implemented to make ">>" work in action lines. In OpenVMS there is no simple
+  feature like ">>" to have DCL command or program output redirected and
+  appended to a file. GNU make for OpenVMS already implements the redirection
+  of output. If such a redirection is detected, an ">" on the action line,
+  GNU make creates a DCL command procedure to execute the action and to
+  redirect its output. Based on that, now ">>" is also recognized and a
+  similar but different command procedure is created to implement the
+  append. The main idea here is to create a temporary file which collects
+  the output and which is appended to the wanted output file. Then the
+  temporary file is deleted. This is all done in the command procedure to
+  keep changes in make small and simple. This obviously has some limitations
+  but it seems good enough compared with the current ">" implementation.
+  (And in my opinion, redirection is not really what GNU make has to do.)
+  With this approach, it may happen that the temporary file is not yet
+  appended and is left in SYS$SCRATCH.
 
-Fix a problem with automatically remaking makefiles. GNU make uses an
-execve to restart itself after a successful remake of the makefile. On
-UNIX systems execve replaces the running program with a new one and
-resets all signal handling to the default. On VMS execve creates a child
-process, signal and exit handlers of the parent are still active, and,
-unfortunately, corrupt the exit code from the child. Fix in job.c:
-ignore SIGCHLD.
+  The temporary file names look like "CMDxxxxx.". Any time the created
+  command procedure can not complete, this happens. Pressing Ctrl+Y to
+  abort make is one case. In case of Ctrl+Y the associated command
+  procedure is left in SYS$SCRATCH as well. Its name is CMDxxxxx.COM.
 
-Added some switches to reflect latest features of DECC. Modifications in
-makefile.vms.
+  The CtrlY handler now uses $delprc to delete all children. This way also
+  actions with DCL commands will be stopped. As before the CtrlY handler
+  then sends SIGQUIT to itself, which is handled in common code.
 
-Set some definitions to reflect latest features of DECC. Modifications in
-config.h-vms (which is copied to config.h).
+  Temporary command files are now deleted in the OpenVMS child termination
+  handler. That deletes them even if a Ctrl+C was pressed.
+  TODO: Does the previous section about >> leaving files still apply?
 
-Added extern strcmpi declaration to avoid 'implicitly declared' messages.
-Modification in make.h.
+  The behavior of pressing Ctrl+C is not changed. It still has only an effect,
+  after the current action is terminated. If that doesn't happen or takes too
+  long, Ctrl+Y should be used instead.
 
-Default rule for C++, conditionals for gcc (GCC_IS_NATIVE) or DEC/Digital/
-Compaq c/c++ compilers. Modifications in default.c.
 
-Usage of opendir() and friends, suppress file version. Modifications in dir.c.
+Build Options:
 
-Added VMS specific code to handle ctrl+c and ctrl+y to abort make.
-Modifications in job.c.
+  Added support to have case sensitive targets and dependencies but to
+  still use case blind file names. This is especially useful for Java
+  makefiles on VMS:
 
-Added support to have case sensitive targets and dependencies but to
-still use case blind file names. This is especially useful for Java
-makefiles on VMS:
+<TAB>.SUFFIXES :
+<TAB>.SUFFIXES : .class .java
+<TAB>.java.class :
+<TAB><TAB>javac "$<"
+<TAB>HelloWorld.class :      HelloWorld.java
 
-	.SUFFIXES :
-	.SUFFIXES :	.class .java
-	.java.class :
-		javac "$<
-	HelloWorld.class :      HelloWorld.java
+  A new macro WANT_CASE_SENSITIVE_TARGETS in config.h-vms was introduced.
+  It needs to be enabled to get this feature; default is disabled.
+  TODO: This should be a run-time setting based on if the process
+  has been set to case sensitive.
 
-A new macro WANT_CASE_SENSITIVE_TARGETS in config.h-vms was introduced.
-It needs to be enabled to get this feature; default is disabled.  The
-macro HAVE_CASE_INSENSITIVE_FS must not be touched: it is still enabled.
-Modifications in file.c and config.h-vms.
 
-Bootstrap make to start building make is still makefile.com, but make
-needs to be re-made with a make to make a correct version: ignore all
-possible warnings, delete all objects, rename make.exe to a different
-name and run it.
+Unimplemented functionality:
 
-Made some minor modifications to the bootstrap build makefile.com.
-
-This is the VMS port of GNU Make.
+  The new feature "Loadable objects" is not yet supported. If you need it,
+  please send a change request or submit a bug report.
 
-It is based on the VMS port of GNU Make 3.60 by Mike Moretti.
+  The new option --output-sync (-O) is accepted but has no effect: GNU make
+  for OpenVMS does not support running multiple commands simultaneously.
 
-This port was done by Klaus K�mpf <kkaempf@rmi.de>
 
-There is first-level support available from proGIS Software, Germany.
-Visit their web-site at http://www.progis.de to get information
-about other vms software and forthcoming updates to gnu make.
+Self test failures and todos:
+-----------------------------
 
-New for 3.77:
+  GNU make was not currently translating the OpenVMS encoded POSIX values
+  returned to it back to the Posix values.  I have temporarily modified the
+  Perl test script to compensate for it.  This should be being handled
+  internally to Make.
+  TODO: Verify and update the Perl test script.
 
-/bin/sh style I/O redirection is supported. You can now write lines like
-	mcr sys$disk:[]program.exe < input.txt > output.txt &> error.txt
+  The features/parallelism test was failing. OpenVMS is executing the rules
+  in sequence not in parallel as this feature was not implemented.
+  GNU Make on VMS no longer claims it is implemented.
+  TODO: Implement it.
 
-Makefile variables are looked up in the current environment. You can set
-symbols or logicals in DCL and evaluate them in the Makefile via
-$(<name-of-symbol-or-logical>).  Variables defined in the Makefile
-override VMS symbols/logicals !
+  The vpath feature may need the targets to be in OpenVMS format.  To be
+  consistent with other target processing, this restriction should be removed.
+  TODO: Verify this after recent changes.
 
-Functions for file names are working now. See the GNU Make manual for
-$(dir ...)  and $(wildcard ...).  Unix-style and VMS-style names are
-supported as arguments.
+  The features/vpathgpath test is failing.  Reason has not yet been determined.
 
-The default rules are set up for GNU C. Building an executable from a
-single source file is as easy as 'make file.exe'.
+  The misc/bs-nl test is failing.  This is where a line is continued with a
+  backslash.
 
-The variable $(ARCH) is predefined as ALPHA or VAX resp. Makefiles for
-different VMS systems can now be written by checking $(ARCH) as in
-  ifeq ($(ARCH),ALPHA)
-    $(ECHO) "On the Alpha"
-  else
-    $(ECHO) "On the VAX"
-  endif
+  The options/dash-e test is failing.  Need to determine how to do overrides
+  on VMS.
 
-Command lines of excessive length are correctly broken and written to a
-batch file in sys$scratch for later execution. There's no limit to the
-lengths of commands (and no need for .opt files :-) any more.
+  The options/dash-k test is failing.  Test is not stopping when it should.
 
-Empty commands are handled correctly and don't end in a new DCL process.
+  The options/dash-n test is failing.  The "+" handling is not working.
+  MAKEFLAG appears not to work.
 
+  Symlink support is not present.  Symlinks are supported by OpenVMS 8.3 and
+  later.
 
-New for 3.76:
+  The targets/INTERMEDIATE and targets/SECONDARY tests are failing.
+  When make deletes files, on posix platforms it writes out 'rm' and the list
+  of files.  On vms, only the files are writen out, one per line.
 
-John W. Eaton has updated the VMS port to support libraries and VPATH.
+  The variables/GNUMAKEFLAGS and variables/MAKE_RESTARTS are failing.
 
+  The variables/MAKEFILES test is failing.  Reason not yet determined.
 
-To build Make, simply type @makefile.  This should compile all the
-necessary files and link Make.  There is also a file called
-makefile.vms.  If you already have GNU Make built you can just use
-Make with this makefile to rebuild.
+  The variables/MAKEFLAGS test is failing.  Looks like the child is failing.
 
-Here are some notes about GNU Make for VMS:
+  The variables/automatic test is failing.
+  The $^D, $^F, $+D, $+F cases are failing.
 
-The cd command is supported if it's called as $(CD). This invokes
-the 'builtin_cd' command which changes the directory.
-Calling 'set def' doesn't do the trick, since a sub-shell is
-spawned for this command, the directory is changed *in this sub-shell*
-and the sub-shell ends.
+  The variables/undefine test is failing.  Undefine of multi-line define fails.
 
-Libraries are not supported. They were in GNU Make 3.60 but somehow I
-didn't care porting the code. If there is enough interest, I'll do it at
-some later time.
+  Error messages should be supressed with the "-" at the beginning of a line.
+  On openVMS they were showing up.  TODO: Is this still an issue?
 
-The variable $^ separates files with commas instead of spaces (It's the
-natural thing to do for VMS).
+  The internal vmsify and unixify OpenVMS to/from UNIX are not handling logical
+  names correctly.
 
-See defaults.c for VMS default suffixes and my definitions for default
-rules and variables.
 
-The shell function is not implemented yet.
+Build instructions:
+------------------
+
+  Don't use the HP C V7.2-001 compiler, which has an incompatible change
+  how __STDC__ is defined. This results at least in compile time warnings.
 
-Load average routines haven't been implemented for VMS yet.
+Make a 1st version
+       $ @makefile.com  ! ignore any compiler and/or linker warning
+       $ copy make.exe 1st-make.exe
 
-The default include directory for including other makefiles is
-SYS$SYSROOT:[SYSLIB] (I don't remember why I didn't just use
-SYS$LIBRARY: instead; maybe it wouldn't work that way).
+  Use the 1st version to generate a 2nd version as a test.
+       $ mc sys$disk:[]1st-make clean  ! ignore any file not found messages
+       $ mc sys$disk:[]1st-make
+
+  Verify your 2nd version by building Make again.
+       $ copy make.exe 2nd-make.exe
+       $ mc sys$disk:[]2nd-make clean
+       $ mc sys$disk:[]2nd-make
+
+
+Running the tests:
+------------------
 
-The default makefiles make looks for are: makefile.vms, gnumakefile,
-makefile., and gnumakefile. .
+  Running the tests on OpenVMS requires the following software to be installed
+  as most of the tests are Unix oriented.
 
-The stat() function and handling of time stamps in VMS is broken, so I
-replaced it with a hack in vmsfunctions.c. I will provide a full rewrite
-somewhere in the future. Be warned, the time resolution inside make is
-less than what vms provides. This might be a problem on the faster Alphas.
+  * Perl 5.18 or later.
+    https://sourceforge.net/projects/vmsperlkit/files/
+  * GNV 2.1.3 + Updates including a minimum of:
+    * Bash 4.3.30
+    * ld_tools 3.0.2
+    * coreutils 8.21
+   https://sourceforge.net/p/gnv/wiki/InstallingGNVPackages/
+   https://sourceforge.net/projects/gnv/files/
 
-You can use a : in a filename only if you precede it with a backslash ('\').
-E.g.- hobbes\:[bogas.files]
+   As the test scripts need to create some foreign commands that persist
+   after the test is run, it is recommend that either you use a subprocess or
+   a dedicated login to run the tests.
 
-Make ignores success, informational, or warning errors (-S-, -I-, or
-to override this in your makefile, or whatever).
+   To get detailed information for running the tests:
 
-Remote stuff isn't implemented yet.
+   $ set default [.tests]
+   $ @run_make_tests help
 
-Multiple line DCL commands, such as "if" statements, must be put inside
-command files.  You can run a command file by using \@.
+   Running the script with no parameters will run all the tests.
 
+   After the the test script has been run once in a session, assuming
+   that you built make in sys$disk:[make], you can redefined the
+   "bin" logical name as follows:
 
-VMS changes made for 3.74.3
+   $ define bin sys$disk:[make],gnv$gnu:[bin]
 
-Lots of default settings are adapted for VMS. See default.c.
+   Then you can use Perl to run the scripts.
 
-Long command lines are now converted to command files.
+   $ perl run_make_tests.pl
 
-Comma (',') as a separator is now allowed. See makefile.vms for an example.
 
-Copyright (C) 1996-2014 Free Software Foundation, Inc.
-This file is part of GNU Make.
+Acknowlegements:
+----------------
 
-GNU Make is free software; you can redistribute it and/or modify it under the
-terms of the GNU General Public License as published by the Free Software
-Foundation; either version 3 of the License, or (at your option) any later
-version.
+See NEWS. for details of past changes.
 
-GNU Make is distributed in the hope that it will be useful, but WITHOUT ANY
-WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
-A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
+  These are the currently known contributers to this port.
 
-You should have received a copy of the GNU General Public License along with
-this program.  If not, see <http://www.gnu.org/licenses/>.
+  Hartmut Becker
+  John Malmberg
+  Michael Gehre
+  John Eisenbraun
+  Klaus Kaempf
+  Mike Moretti
+  John W. Eaton
