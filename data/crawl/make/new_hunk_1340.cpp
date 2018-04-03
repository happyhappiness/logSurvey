1998-07-28  Paul D. Smith  <psmith@gnu.org>

	* Version 3.77 released.

	* dosbuild.bat: Change to DOS CRLF line terminators.

	* make-stds.texi: Update from latest version.

	* make.texinfo (Options Summary): Clarify that the -r option
	affects only rules, not builtin variables.

1998-07-27  Paul D. Smith  <psmith@gnu.org>

	* make.h: Make __attribute__ resolve to empty for non-GCC _and_
	for GCC pre-2.5.x.

	* misc.c (log_access): Print UID/GID's as unsigned long int for
	maximum portability.

	* job.c (reap_children): Print PIDs as long int for maximum
	portability.

1998-07-24  Eli Zaretskii  <eliz@is.elta.co.il>

	* Makefile.DOS (*_INSTALL, *_UNINSTALL): Replace `true' with `:'.

1998-07-25  Paul D. Smith  <psmith@gnu.org>

	* Version 3.76.94 released.

1998-07-23  Paul D. Smith  <psmith@gnu.org>

	* config.h.W32.template: Make sure all the #defines of macros here
	have a value (e.g., use ``#define HAVE_STRING_H 1'' instead of
	just ``#define HAVE_STRING_H''.  Keeps the preprocessor happy in
	some contexts.

	* make.h: Remove __attribute__((format...)) stuff; using it with
	un-prototyped functions causes older GCC's to fail.

	* Version 3.76.93 released.

1998-07-22  Paul D. Smith  <psmith@gnu.org>

	* file.c (print_file_data_base): Fix average calculation.

1998-07-20  Paul D. Smith  <psmith@gnu.org>

	* main.c (die): Postpone the chdir() until after
	remove_intermediates() so that intermediate targets with relative
	pathnames are removed properly.

1998-07-17  Paul D. Smith  <psmith@gnu.org>

	* filedef.h (struct file): New flag: did we print an error or not?

	* remake.c (no_rule_error): New function to print error messages,
	extraced from remake_file().

	* remake.c (remake_file): Invoke the new error print function.
	(update_file_1): Invoke the error print function if we see that we
	already tried this target and it failed, but that an error wasn't
	printed for it.  This can happen if a file is included with
	-include or sinclude and couldn't be built, then later is also
	the dependency of another target.  Without this change, make just
	silently stops :-/.

1998-07-16  Paul D. Smith  <psmith@gnu.org>

	* make.texinfo: Removed "beta" version designator.
	Updated ISBN for the next printing.

1998-07-13  Paul Eggert  <eggert@twinsun.com>

	* acinclude.m4: New AC_LFS macro to determine if special compiler
	flags are needed to allow access to large files (e.g., Solaris 2.6).
	* configure.in: Invoke it.

1998-07-08  Eli Zaretskii  <eliz@is.elta.co.il>

	* Makefile.DOS: track changes in Makefile.in.

1998-07-07  Paul D. Smith  <psmith@gnu.org>

	* remote-cstms.c (start_remote_job): Move gethostbyaddr() to the
	top so host is initialized early enough.

	* acinclude.m4: New file.  Need some special autoconf macros to
	check for network libraries (-lsocket, -lnsl, etc.) when
	configuring Customs.

	* configure.in (make_try_customs): Invoke new network libs macro.

1998-07-06  Paul D. Smith  <psmith@gnu.org>

	* Version 3.76.92 released.

	* README.customs: Added to the distribution.

	* configure.in (make_try_customs): Rewrite to require an installed
	Customs library, rather than looking at the build directory.

	* Makefile.am (man_MANS): Install make.1.
	* make.1: Renamed from make.man.

	* make.texinfo (Bugs): New mailing list address for GNU make bug
	reports.

1998-07-02  Paul D. Smith  <psmith@gnu.org>

	* Version 3.76.91 released.

	* default.c: Added default rule for new-style RCS master file
	storage; ``% :: RCS/%''.
	Added default rules for DOS-style C++ files with suffix ".cpp".
	They use the new LINK.cpp and COMPILE.cpp macros, which are set by
	default to be equal to LINK.cc and COMPILE.cc.

1998-06-19  Eli Zaretskii  <eliz@is.elta.co.il>

        * job.c (start_job_command): Reset execute_by_shell after an empty
        command was skipped.

1998-06-09  Paul D. Smith  <psmith@gnu.org>

	* main.c (main): Keep track of the temporary filename created when
	reading a makefile from stdin (-f-) and attempt to remove it
	as soon as we know we're not going to re-exec.  If we are, add it
	to the exec'd make's cmd line with "-o" so the exec'd make doesn't
	try to rebuild it.  We still have a hole: if make re-execs then
	the temporary file will never be removed.  To fix this we'd need
	a brand new option that meant "really delete this".
	* AUTHORS, getopt.c, getopt1.c, getopt.h, main.c (print_version):
	Updated mailing addresses.

1998-06-08  Paul D. Smith  <psmith@gnu.org>

	* main.c (main): Andreas Luik <luik@isa.de> points out that the
	check for makefile :: rules with commands but no dependencies
	causing a loop terminates incorrectly.

	* maintMakefile: Make a template for README.DOS to update version
	numbers.

1998-05-30  Andreas Schwab  <schwab@issan.informatik.uni-dortmund.de>

	* remake.c (update_file_1): Don't free the memory for the
	dependency structure when dropping a circular dependency.

1998-05-30  Eli Zaretskii  <eliz@is.elta.co.il>

	* dir.c (file_exists_p, file_impossible_p, file_impossible)
	[__MSDOS__, WINDOWS32]: Retain trailing slash in "d:/", and make
	dirname of "d:foo" be "d:".

1998-05-26  Andreas Schwab  <schwab@issan.informatik.uni-dortmund.de>

	* read.c (read_makefile): Avoid running past EOS when scanning
	file name after `include'.

1998-05-26  Andreas Schwab  <schwab@issan.informatik.uni-dortmund.de>

	* make.texinfo (Flavors): Correct description of conditional
	assignment, which is not equivalent to ifndef.
	(Setting): Likewise.

1998-05-24  Paul D. Smith  <psmith@gnu.org>

	* arscan.c (ar_name_equal): strncmp() might be implemented as a
	macro, so don't put preprocessor conditions inside the arguments
	list.

1998-05-23  Eli Zaretskii  <eliz@is.elta.co.il>

	* read.c (read_makefile) [__MSDOS__, WINDOWS32]: Skip colons in
	drive specs when parsing targets, target-specific variables and
	static pattern rules.  A colon can only be part of drive spec if
	it is after the first letter in a token.

1998-05-22  Eli Zaretskii  <eliz@is.elta.co.il>

	* remake.c (f_mtime) [__MSDOS__]: Allow up to 3 sec of skew before
	yelling bloody murder.

	* dosbuild.bat: Use -DINCLUDEDIR= and -DLIBDIR= where appropriate.

	* read.c (parse_file_seq): Combine the special file-handling code
	for WINDOWS32 and __MSDOS__ into a single snippet.
	(get_next_mword) [__MSDOS__, WINDOWS32]: Allow a word to include a
	colon as part of a drive spec.

	* job.c (batch_mode_shell) [__MSDOS__]: Declare.

1998-05-20  Paul D. Smith  <psmith@gnu.org>

	* Version 3.76.90 released.

1998-05-19  Paul D. Smith  <psmith@gnu.org>

	* make.texinfo (Make Errors): Added a new appendix describing
	common errors make might generate and how to resolve them (or at
	least more information on what they mean).

	* maintMakefile (NMAKEFILES): Use the new automake 1.3 feature
	to create a dependency file to construct Makefile.DOS, SMakefile,
	and NMakefile.
	(.dep_segment): Generate the dependency fragment file.

1998-05-14  Paul D. Smith  <psmith@gnu.org>

	* make.man: Minor changes.

1998-05-13  Paul D. Smith  <psmith@gnu.org>

	* function.c (pattern_matches,expand_function): Change variables
	and types named "word" to something else, to avoid compilation
	problems on Cray C90 Unicos.
	* variable.h: Modify the function prototype.

1998-05-11  Rob Tulloh  <rob_tulloh@tivoli.com>

	* job.c (construct_command_argv_internal): [WINDOWS32] Turn off
	echo when using a batch file, and make sure the command ends in a
	newline.

1998-05-03  Paul D. Smith  <psmith@gnu.org>

	* configure.in (make_try_customs): Add some customs flags if the
	user configures custom support.

	* job.c, remote-cstms.c: Merge in changes for custom library.

	* remote-stub.c: Add option to stub start_remote_job_p().

1998-05-01  Paul D. Smith  <psmith@gnu.org>

	* remake.c (f_mtime): Install VPATH+ handling for archives; use
	the hname field instead of the name field, and rehash when
	appropriate.

1998-04-30  Paul D. Smith  <psmith@gnu.org>

	* rule.c (print_rule_data_base): Print out any pattern-specific
	variable values into the rules database.

	* variable.c (print_variable_set): Make this variable extern, to
	be called by print_rule_data_base() for pattern-specific variables.

	* make.texinfo (Pattern-specific): Document pattern-specific
	variables.

1998-04-29  Paul D. Smith  <psmith@gnu.org>

	* expand.c (variable_expand_for_file): Make static; its only
	called internally.  Look up this target in the list of
	pattern-specific variables and insert the variable set into the
	queue to be searched.

	* filedef.h (struct file): Add a new field to hold the
	previously-found pattern-specific variable reference.  Add a new
	flag to remember whether we already searched for this file.

	* rule.h (struct pattern_var): New structure for storing
	pattern-specific variable values.  Define new function prototypes.

	* rule.c: New variables pattern_vars and last_pattern_var for
	storage and handling of pattern-specific variable values.
	(create_pattern_var): Create a new pattern-specific variable value
	structure.
	(lookup_pattern_var): Try to match a target to one of the
	pattern-specific variable values.

1998-04-22  Paul D. Smith  <psmith@gnu.org>

	* make.texinfo (Target-specific): Document target-specific
	variables.

1998-04-21  Paul D. Smith  <psmith@gnu.org>

	* variable.c (define_variable_in_set): Made globally visible.
	(lookup_variable_in_set): New function: like lookup_variable but
	look only in a specific variable set.
	(target_environment): Use lookup_variable_in_set() to get the
	correct export rules for a target-specific variable.
	(create_new_variable_set): Create a new variable set, and just
	return it without installing it anywhere.
	(push_new_variable_scope): Reimplement in terms of
	create_new_variable_set.

	* read.c (record_target_var): Like record_files, but instead of
	files create a target-specific variable value for each of the
	listed targets.  Invoked from read_makefile() when the target line
	turns out to be a target-specific variable assignment.

1998-04-19  Paul D. Smith <psmith@gnu.org>

	* read.c (read_makefile): Rewrite the entire target parsing
	section to implement target-specific variables.  In particular, we
	cannot expand the entire line as soon as it's read in, since we
	may want to evaluate parts of it with different variable contexts
	active.  Instead, start expanding from the beginning until we find
	the `:' (or `::'), then determine what kind of line this is and
	continue appropriately.

	* read.c (get_next_mword): New function to parse a makefile line
	by "words", considering an entire variable or function as one
	word.  Return the type read in, along with its starting position
	and length.
	(enum make_word_type): The types of words that are recognized by
	get_next_mword().

	* variable.h (struct variable): Add a flag to specify a per-target
	variable.

	* expand.c: Make variable_buffer global.  We need this during the
	new parsing of the makefile.
	(variable_expand_string): New function.  Like variable_expand(),
	but start at a specific point in the buffer, not the beginning.
	(variable_expand): Rewrite to simply call variable_expand_string().

1998-04-13  Paul D. Smith  <psmith@gnu.org>

	* remake.c (update_goal_chain): Allow the rebuilding makefiles
	step to use parallel jobs.  Not sure why this was disabled:
	hopefully we won't find out :-/.

1998-04-11  Paul D. Smith  <psmith@gnu.org>

	* main.c (main): Set the CURDIR makefile variable.
	* make.texinfo (Recursion): Document it.

1998-03-17  Paul D. Smith  <psmith@gnu.org>

	* misc.c (makefile_fatal): If FILE is nil, invoke plain fatal().
	* variable.c (try_variable_definition): Use new feature.

1998-03-10  Paul D. Smith  <psmith@gnu.org>

	* main.c (main): Don't pass included, rebuilt makefiles to
	re-exec'd makes with -o.  Reopens a possible loop, but it caused
	too many problems.

1998-03-02  Paul D. Smith  <psmith@gnu.org>

	* variable.c (try_variable_definition): Implement ?=.
	* make.texinfo (Setting): Document it.

1998-02-28  Eli Zaretskii  <eliz@is.elta.co.il>

	* job.c (start_job_command): Reset execute_by_shell after an empty
        command, like ":", has been seen.

Tue Oct 07 15:00:00 1997  Phil Brooks <phillip_brooks@hp.com>

	* make.h: [WINDOWS32] make case sensitivity configurable
	* dir.c: [WINDOWS32] make case sensitivity configurable
	* README.W32: Document case sensitivity
	* config.ami: Share case warping code with Windows

Mon Oct  6 18:48:45 CDT 1997 Rob Tulloh <rob_tulloh@dev.tivoli.com>

	* w32/subproc/sub_proc.c: Added support for MKS toolkit shell
	(turn on HAVE_MKS_SHELL).
	* read.c: [WINDOWS32] Fixed a problem with multiple target rules
 	reported by Gilbert Catipon (gcatipon@tibco.com).  If multiple
 	path tokens in a rule did not have drive letters, make would
 	incorrectly concatenate the 2 tokens together.
	* main.c/variable.c: [WINDOWS32] changed SHELL detection code to
 	follow what MSDOS did. In addition to watching for SHELL variable
 	updates, make's main will attempt to default the value of SHELL
 	before and after makefiles are parsed.
	* job.c/job.h: [WINDOWS32] The latest changes made to enable use
 	of the GNUWIN32 shell from make could cause make to fail due to a
 	concurrency condition between parent and child processes.  Make
 	now creates a batch file per job instead of trying to reuse the
 	same singleton batch file.
	* job.c/job.h/function.c/config.h.W32: [WINDOWS32] Renamed macro
 	from HAVE_CYGNUS_GNUWIN32_TOOLS to BATCH_MODE_ONLY_SHELL. Reworked
 	logic to reduce complexity. WINDOWS32 now uses the unixy_shell
 	variable to detect Bourne-shell compatible environments. There is
 	also a batch_mode_shell variable that determines whether not
 	command lines should be executed via script files. A WINDOWS32
 	system with no sh.exe installed would have unixy_shell set to
 	FALSE and batch_mode_shell set to TRUE. If you have a unixy shell
 	that does not behave well when invoking things via 'sh -c xxx',
 	you may want to turn on BATCH_MODE_ONLY_SHELL and see if things
 	improve.
	* NMakefile: Added /D DEBUG to debug build flags so that unhandled
 	exceptions could be debugged.

Mon Oct  6 00:04:25 1997  Rob Tulloh <rob_tulloh@dev.tivoli.com>

	* main.c: [WINDOWS32] The function define_variable() does not
 	handle NULL. Test before calling it to set Path.
	* main.c: [WINDOWS32] Search Path again after makefiles have been
	parsed to detect sh.exe.
	* job.c: [WINDOWS32] Added support for Cygnus GNU WIN32 tools.
	To use, turn on HAVE_CYGNUS_GNUWIN32_TOOLS in config.h.W32.
	* config.h.W32: Added HAVE_CYGNUS_GNUWIN32_TOOLS macro.

Sun Oct  5 22:43:59 1997  John W. Eaton <jwe@bevo.che.wisc.edu>

	* glob/glob.c (glob_in_dir): [VMS] Globbing shouldn't be
	case-sensitive.
	* job.c (child_execute_job): [VMS] Use a VMS .com file if the
	command contains a newline (e.g. from a define/enddef block).
	* vmsify.c (vmsify): Return relative pathnames wherever possible.
	* vmsify.c (vmsify): An input string like "../.." returns "[--]".

Wed Oct  1 15:45:09 1997  Rob Tulloh <rob_tulloh@tivoli.com>

	* NMakefile: Changed nmake to $(MAKE).
	* subproc.bat: Take the make command name from the command
	line. If no command name was given, default to nmake.
	* job.c: [WINDOWS32/MSDOS] Fix memory stomp: temporary file names
	are now always created in heap memory.
	* w32/subproc/sub_proc.c: New implementation of make_command_line()
	which is more compatible with different Bourne shell implementations.
	Deleted the now obsolete fix_command_line() function.
	* main.c: [WINDOWS32] Any arbitrary spelling of Path can be
	detected. Make will ensure that the special spelling `Path' is
	inserted into the environment when the path variable is propagated
	within itself and to make's children.
	* main.c: [WINDOWS32] Detection of sh.exe was occurring too
	soon. The 2nd check for the existence of sh.exe must come after
	the call to read_all_makefiles().

Fri Sep 26 01:14:18 1997  <zinser@axp602.gsi.de>

	* makefile.com: [VMS] Fixed definition of sys.
	* readme.vms: Comments on what's changed lately.

Fri Sep 26 01:14:18 1997  John W. Eaton <jwe@bevo.che.wisc.edu>

	* read.c (read_all_makefiles): Allow make to find files named
	"MAKEFILE" with no extension on VMS.
	* file.c (lookup_file): Lowercase filenames on VMS.

1997-09-29  Paul D. Smith  <psmith@baynetworks.com>

	* read.c (read_makefile): Reworked target detection again; the old
	version had an obscure quirk.

Fri Sep 19 09:20:49 1997  Paul D. Smith  <psmith@baynetworks.com>

	* Version 3.76.1 released.

	* Makefile.am: Add loadavg files to clean rules.

	* configure.in (AC_OUTPUT): Remove stamp-config; no longer needed.
