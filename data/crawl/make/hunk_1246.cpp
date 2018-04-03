+1998-09-21  Paul D. Smith  <psmith@gnu.org>
+
+	* job.c (construct_command_argv_internal): Only add COMMAND.COM
+	"@echo off" line for non-UNIXy shells.
+
+1998-09-09  Paul D. Smith  <psmith@gnu.org>
+
+	* w32/subproc/sub_proc.c: Add in missing HAVE_MKS_SHELL tests.
+
+1998-09-04  Paul D. Smith  <psmith@gnu.org>
+
+	* read.c (read_makefile): If we hit the "missing separator" error,
+	check for the common case of 8 spaces instead of a TAB and give an
+	extra comment to help people out.
+
+1998-08-29  Paul Eggert  <eggert@twinsun.com>
+
+	* configure.in (AC_STRUCT_ST_MTIM_NSEC):
+	Renamed from AC_STRUCT_ST_MTIM.
+
+	* acinclude.m4 (AC_STRUCT_ST_MTIM_NSEC):  Likewise.
+	Port to UnixWare 2.1.2 and pedantic Solaris 2.6.
+
+	* acconfig.h (ST_MTIM_NSEC):
+	Renamed from HAVE_ST_MTIM, with a new meaning.
+
+	* filedef.h (FILE_TIMESTAMP_FROM_S_AND_NS):
+	Use new ST_MTIM_NSEC macro.
+
+1998-08-26  Paul D. Smith  <psmith@gnu.org>
+
+	* remake.c (check_dep): For any intermediate file, not just
+	secondary ones, try implicit and default rules if no explicit
+	rules are given.  I'm not sure why this was restricted to
+	secondary rules in the first place.
+
+1998-08-24  Paul D. Smith  <psmith@gnu.org>
+
+	* make.texinfo (Special Targets): Update documentation for
+	.INTERMEDIATE: if used with no dependencies, then it does nothing;
+	old docs said it marked all targets as intermediate, which it
+	didn't... and which would be silly :).
+
+	* implicit.c (pattern_search): If we find a dependency in our
+	internal tables, make sure it's not marked intermediate before
+	accepting it as a found_file[].
+
+1998-08-20  Paul D. Smith  <psmith@gnu.org>
+
+	* ar.c (ar_glob): Use existing alpha_compare() with qsort.
+	(ar_glob_alphacompare): Remove it.
+
+	Modify Paul Eggert's patch so we don't abandon older systems:
+
+	* configure.in: Warn the user if neither waitpid() nor wait3() is
+	available.
+
+	* job.c (WAIT_NOHANG): Don't syntax error on ancient hosts.
+	(child_handler, dead_children): Define these if WAIT_NOHANG is not
+	available.
+	(reap_children): Only track the dead_children count if no
+	WAIT_NOHANG.  Otherwise, it's a boolean.
+
+	* main.c (main): Add back signal handler if no WAIT_NOHANG is
+	available; only use default signal handler if it is.
+
+1998-08-20  Paul Eggert  <eggert@twinsun.com>
+
+	Install a more robust signal handling mechanism for systems which
+	support it.
+
+	* job.c (WAIT_NOHANG): Define to a syntax error if our host
+	is truly ancient; this should never happen.
+	(child_handler, dead_children): Remove.
+	(reap_children): Don't try to keep separate track of how many
+	dead children we have, as this is too bug-prone.
+	Just ask the OS instead.
+	(vmsHandleChildTerm): Fix typo in error message; don't mention
+	child_handler.
+
+	* main.c (main): Make sure we're not ignoring SIGCHLD/SIGCLD;
+	do this early, before we could possibly create a subprocess.
+	Just use the default behavior; don't have our own handler.
+
+1998-08-18  Eli Zaretskii  <eliz@is.elta.co.il>
+
+	* read.c (read_makefile) [__MSDOS__, WINDOWS32]: Add code to
+	recognize library archive members when dealing with drive spec
+	mess.  Discovery and initial fix by George Racz <gracz@mincom.com>.
+
+1998-08-18  Paul D. Smith  <psmith@gnu.org>
+
+	* configure.in: Check for stdlib.h explicitly (some hosts have it
+	but don't have STDC_HEADERS).
+	* make.h: Use HAVE_STDLIB_H.  Clean up some #defines.
+	* config.ami: Re-compute based on new config.h.in contents.
+	* config.h-vms: Ditto.
+	* config.h.W32: Ditto.
+	* configh.dos: Ditto.
+
+1998-08-17  Paul D. Smith  <psmith@gnu.org>
+
+	* make.texinfo: Added copyright year to the printed copy.  Removed
+	the price from the manual.  Change the top-level reference to
+	running make to be "Invoking make" instead of "make Invocation",
+	to comply with GNU doc standards.
+
+	* make.h (__format__, __printf__): Added support for these in
+	__attribute__ macro.
+	(message, error, fatal): Use ... prototype form under __STDC__.
+	Add __format__ attributes for printf-style functions.
+
+	* configure.in (AC_FUNC_VPRINTF): Check for vprintf()/_doprnt().
+
+	* misc.c(message, error, fatal): Add preprocessor stuff to enable
+	creation of variable-argument functions with appropriate
+	prototypes, that works with ANSI, pre-ANSI, varargs.h, stdarg.h,
+	v*printf(), _doprnt(), or none of the above.  Culled from GNU
+	fileutils and slightly modified.
+	(makefile_error, makefile_error): Removed (merged into error() and
+	fatal(), respectively).
+	* amiga.c: Use them.
+	* ar.c: Use them.
+	* arscan.c: Use them.
+	* commands.c: Use them.
+	* expand.c: Use them.
+	* file.c: Use them.
+	* function.c: Use them.
+	* job.c: Use them.
+	* main.c: Use them.
+	* misc.c: Use them.
+	* read.c: Use them.
+	* remake.c: Use them.
+	* remote-cstms.c: Use them.
+	* rule.c: Use them.
+	* variable.c: Use them.
+
+	* make.h (struct floc): New structure to store file location
+	information.
+	* commands.h (struct commands): Use it.
+	* variable.c (try_variable_definition): Use it.
+	* commands.c: Use it.
+	* default.c: Use it.
+	* file.c: Use it.
+	* function.c: Use it.
+	* misc.c: Use it.
+	* read.c: Use it.
+	* rule.c: Use it.
+
+1998-08-16  Paul Eggert  <eggert@twinsun.com>
+
+	* filedef.h (FILE_TIMESTAMP_PRINT_LEN_BOUND): Add 10, for nanoseconds.
+
+1998-08-16  Paul Eggert  <eggert@twinsun.com>
+
+	* filedef.h (FLOOR_LOG2_SECONDS_PER_YEAR): New macro.
+	(FILE_TIMESTAMP_PRINT_LEN_BOUND): Tighten bound, and try to
+	make it easier to understand.
+
+1998-08-14  Paul D. Smith  <psmith@gnu.org>
+
+	* read.c (read_makefile): We've already unquoted any colon chars
+	by the time we're done reading the targets, so arrange for
+	parse_file_seq() on the target list to not do so again.
+
+1998-08-05  Paul D. Smith  <psmith@gnu.org>
+
+	* configure.in: Added glob/configure.in data.  We'll have the glob
+	code include the regular make config.h, rather than creating its
+	own.
+
+	* getloadavg.c (main): Change return type to int.
+
+1998-08-01  Paul Eggert  <eggert@twinsun.com>
+
+	* job.c (reap_children): Ignore unknown children.
+
+1998-07-31  Paul D. Smith  <psmith@gnu.org>
+
+	* make.h, filedef.h, dep.h, rule.h, commands.h, remake.c:
+	Add prototypes for functions.  Some prototypes needed to be moved
+	in order to get #include order reasonable.
+
+1998-07-30  Paul D. Smith  <psmith@gnu.org>
+
+	* make.h: Added MIN/MAX.
+	* filedef.h: Use them; remove FILE_TIMESTAMP_MIN.
+
+1998-07-30  Paul Eggert  <eggert@twinsun.com>
+
+        Add support for sub-second timestamp resolution on hosts that
+        support it (just Solaris 2.6, so far).
+
+	* acconfig.h (HAVE_ST_MTIM, uintmax_t): New undefs.
+	* acinclude.m4 (jm_AC_HEADER_INTTYPES_H, AC_STRUCT_ST_MTIM,
+        jm_AC_TYPE_UINTMAX_T): New defuns.
+	* commands.c (delete_target): Convert file timestamp to
+        seconds before comparing to archive timestamp.  Extract mod
+        time from struct stat using FILE_TIMESTAMP_STAT_MODTIME.
+	* configure.in (C_STRUCT_ST_MTIM, jm_AC_TYPE_UINTMAX_T): Add.
+        (AC_CHECK_LIB, AC_CHECK_FUNCS): Add clock_gettime.
+	* file.c (snap_deps): Use FILE_TIMESTAMP, not time_t.
+        (file_timestamp_now, file_timestamp_sprintf): New functions.
+        (print_file): Print file timestamps as FILE_TIMESTAMP, not
+        time_t.
+	* filedef.h: Include <inttypes.h> if available and if HAVE_ST_MTIM.
+        (FILE_TIMESTAMP, FILE_TIMESTAMP_STAT_MODTIME, FILE_TIMESTAMP_MIN,
+        FILE_TIMESTAMPS_PER_S, FILE_TIMESTAMP_FROM_S_AND_NS,
+        FILE_TIMESTAMP_DIV, FILE_TIMESTAMP_MOD, FILE_TIMESTAMP_S,
+        FILE_TIMESTAMP_NS, FILE_TIMESTAMP_PRINT_LEN_BOUND): New macros.
+        (file_timestamp_now, file_timestamp_sprintf): New decls.
+        (struct file.last_mtime, f_mtime, file_mtime_1, NEW_MTIME):
+        time_t -> FILE_TIMESTAMP.
+	* implicit.c (pattern_search): Likewise.
+	* vpath.c (vpath_search, selective_vpath_search): Likewise.
+	* main.c (main): Likewise.
+	* remake.c (check_dep, name_mtime, library_search, f_mtime): Likewise.
+        (f_mtime): Use file_timestamp_now instead of `time'.
+        Print file timestamp with file_timestamp_sprintf.
+	* vpath.c (selective_vpath_search): Extract file time stamp from
+        struct stat with FILE_TIMESTAMP_STAT_MODTIME.
+
 1998-07-28  Paul D. Smith  <psmith@gnu.org>
 
 	* Version 3.77 released.
