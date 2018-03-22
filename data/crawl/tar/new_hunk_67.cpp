2009-03-05  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c: --no-recursive works with --incremental.

2009-03-04  Sergey Poznyakoff  <gray@gnu.org.ua>

	Add xz support.
	
	* src/buffer.c, src/suffix.c: Add support for xz compression.
	* src/tar.c: New option --xz, for compression/decompression using xz.
	Re-assign -J as a short equivalent of --xz.

2009-01-19  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Fix typo.

2008-12-29  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap.conf: Include size_max.
	* gnulib.modules: Remove memset, rmdir. Replace strdup with
	strdup-posix. Patch by Eric Blake.
	* src/tar.c: Implement -I as a shorthand for --use-compress-program.
	* doc/tar.texi: Document -I.
	* tests/pipe.at, tests/shortrec.at: Account for eventual 'Record
	size' output.
	* tests/testsuite.at (AT_TAR_CHECK_HOOK): New define
	(AT_TAR_WITH_HOOK, TAR_IGNREC_HOOK): New macros.

2008-11-30  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/xheader.c: Remove duplicate inclusion of fnmatch.h. Reported
	by Jim Meyering.

2008-11-25  Sergey Poznyakoff  <gray@gnu.org.ua>

	Do not try to drain the input pipe before closing the
	archive. 
	
	* src/buffer.c (close_archive): Remove call to
	sys_drain_input_pipe. Pass hit_eof as the second
	argument to sys_wait_for_child.
	* src/common.h (sys_drain_input_pipe): Remove
	(sys_wait_for_child): Declare second argument.
	* src/system.c (sys_drain_input_pipe): Remove.
	(sys_wait_for_child): Take two arguments. The second one helps to
	decide whether to tolerate child termination on SIGPIPE.

2008-11-03  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/buffer.c (_write_volume_label): Fix typo, which prevented
	`-V label -M' from working.

2008-10-30  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS, configure.ac: Version 1.20.91
	* doc/tar.texi: Document transformation scope flags.
	* src/common.h (transform_symlinks_option): Remove in favor of
	transformation scope flags.
	(XFORM_REGFILE, XFORM_LINK, XFORM_SYMLINK, XFORM_ALL): New macros.
	(transform_name, transform_member_name, transform_name_fp): Take
	an additional argument, specifying scope flags.
	* src/create.c: Reflect changes to transform_name.
	* src/extract.c (extract_link, extract_symlink): Remove calls to
	transform_member_name. It is done in read_header.
	* src/list.c (decode_xform): Reflect change in data type of 2nd
	argument. 
	(transform_member_name): 2nd arg is int.
	(decode_header): Transform file name and link target names.
	* src/tar.c: Remove --transform-symlinks.
	* src/transform.c (struct transform): New member `flags'.
	(transform_flags): New variable.
	(parse_transform_expr): Parse transformation scope flags. Allow to
	set global flags using `flags=' syntax.
	(_transform_name_to_obstack, transform_name_fp)
	(transform_name): Take an additional argument, specifying scope
	flags. 

2008-10-19  Sergey Poznyakoff  <gray@gnu.org.ua>

	* THANKS: Add Ed Leaver.
	* src/buffer.c (short_read): Remove !read_full_records condition,
	which was always false on a first record and thus disabled record
	size autodetection.  Thanks Ed Leaver for the patch.
	(_gnu_flush_read): Handle blocking_factor == 1.
	* tests/sparsemv.at: Reflect changes to buffer.c.
	* tests/sparsemvp.at: Likewise.
	* tests/volsize.at: Likewise.
	* NEWS: Update.
	
2008-10-16  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/common.h (transform_symlinks_option): New global.
	* src/create.c (dump_file0): Transform symlink targets only if
	explicitly required.  Thanks Cyril Strejc for reporting the
	problem.
	* src/tar.c (parse_opt): New options --transform-symlinks and
	--no-transform-symlinks. New alias --xform to the --transform
	option.
	* doc/tar.texi: Document --transform-symlinks
	* NEWS: Update.
	* THANKS: Update.
	
	* src/names.c (name_gather): Use xzalloc.
	* src/buffer.c (short_read): Move record size detection before
	the loop.
	
2008-10-07  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (options): Add --lzop option.

2008-10-05  Xavier Hienne <xavier.hienne@free.fr> (tiny change)

	* src/checkpoint.c (checkpoint_compile_action): Add missing
	`else'. 

2008-09-24  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update.
	* doc/tar.texi: Update.
	* src/tar.c: New option --no-null.

2008-09-23  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/common.h (filename_terminator): Remove global.
	* src/tar.c (filename_terminator): New static.
	* src/names.c (name_next_elt): Do not depend on
	filename_terminator, this was a leftover from 1.13.

2008-09-18  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Remove incorrect example.

2008-09-07  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c (dumpdir_create0): Eliminate gcc warning.
	(attach_directory): Bugfix - add missing return statement.
	* THANKS: Add Enric Hernandez

2008-07-31  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c (struct directory): New member `next'.  Change
	type of `name'.
	(dirhead, dirtail): New statics.
	(make_directory): Reflect changes to struct directory.
	(free_directory, attach_directory): New functions.
	(dirlist_replace_prefix): New function.
	(note_directory): Use attach_directory, instead of make_directory,
	(find_directory, find_directory_meta): Use free_directory.
	(procdir): Replace directory prefixes in directory list to avoid
	marking subdirectories as renamed after renaming their parent
	directory.
	(append_incremental_renames): Iterate over directory list, not
	hash table, to preserve logical ordering of renames.
	* tests/rename04.at, tests/rename05.at: New test cases.
	* tests/Makefile.am, tests/testsuite.at: Add rename04.at and
	rename05.at.
	* tests/atlocal.in (decho): New function.
	* tests/multiv06.at: Use decho instead of echo2.
	* tests/incremental.at: Raise wait interval to 2 seconds.
	
2008-07-24  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (decode_options): Do not allow volume length less
	than record size.
	* src/buffer.c (_gnu_flush_write): Compensate for the effect
	of eventual flush_archive occurring in the middle of buffer
	move.
	Increment records_written only if _flush_write was able to write
	something.
	* tests/multiv06.at: New testcase.
	* tests/Makefile.am, test/testsuite.at: Add tests/multiv06.at

2008-06-26  Sergey Poznyakoff  <gray@gnu.org.ua>

	* configure.ac, NEWS: Version 1.20.90
	* doc/tar.texi: Document -J, --no-auto-compress, etc.
	* src/buffer.c (ct_tar): New constant.
	(magic): Add lzop support.  Proposed by Kevin Day
	<thekevinday@gmail.com>.
	(check_compressed_archive): Do not use autodetect if the
	compression program was specified explicitly.
	Fall back to analyzing archive name, if the autodetection fails.
	* src/suffix.c: Add .lzo
	* src/tar.c: New options --lzop and --no-auto-compress.
	New short option -J (alias for --lzma).

	* src/buffer.c (try_new_volume): Print more information with error
	diagnostics.
	(_gnu_flush_write): Improve error checking.  Adjust
	real_s_sizeleft before calling new_volume to avoid creating
	malformed multivolume headers.
	* tests/delete05.at, tests/gzip.at, tests/ignfail.at,
	tests/longv7.at, tests/lustar01.at, tests/lustar02.at,
	tests/shortfile.at: Update to match new diagnostic wording
	(see 2008-05-06).
	
	* NEWS: Update.

2008-06-14  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi (exclude): Document support for new VCS.
	* THANKS: Update.
	* NEWS: Update.	
	* tests/multiv05.at: Fix typos.
	* tests/volsize.at: Remove a TZ dependency.
	
2008-06-14  Dan Drake <dan@dandrake.org> (tiny change)

	* src/tar.c (exclude_vcs_files): Support for Bazaar, Mercurial and
	Darcs. 

2008-05-06  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (main): Reword the "delayed error" message. New
	wording proposed by Karl Berry.

2008-02-20  Sergey Poznyakoff  <gray@gnu.org.ua>

	* configure.ac: Raise version number to 1.20
	* src/compare.c (diff_dumpdir): const.
	* src/common.h (dumpdir_t,dumpdir_iter_t): New data types.
	(dumpdir_create0,dumpdir_create,dumpdir_free,dumpdir_locate)
	(dumpdir_first,dumpdir_next): New functions.
	* src/incremen.c (dumpdir_create0,dumpdir_create,dumpdir_free)
	(dumpdir_first,dumpdir_next): New functions.
	(dumpdir_locate): Rewrite using binary search.
	(struct directory): Change members char *contents, *icontents to
	struct dumpdir *dump, *idump. All references updated.
	(note_directory): Last arg is const.
	* src/names.c (add_hierarchy_to_namelist): buffer is const.
	* tests/incr03.at, tests/incr04.at, tests/rename02.at,
	tests/rename03.at: Insert calls to sleep between creation of files
	and adding them to the archive.
	
2008-03-31  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/create.c (dump_file0): Count links only for actually dumped
	files. 

2008-03-27  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Document --no-check-device and --check-device.
	* doc/rendition.texi: Change the way FIXME-*refs are handled in
	!PROOF. 
	* doc/intern.texi, doc/tar.texi: Update.
	* doc/untabify.el: New file.
	* doc/Makefile.am (EXTRA_DIST): Add untabify.el
	(untabify, final, check-format, check-refs, check-fixmes)
	(check-unrevised, all-check-docs, check-docs): New rules.
	
	* src/common.h (check_device_option): New global.
	* src/incremen.c (procdir): Use boolean and instead of bitwise
	one. Patch by Jean-Louis Martineau.
	Compare device numbers only if check_device_option is set.
	* src/tar.c: New command line options --no-check-device and
	--check-device. Proposed by Jean-Louis Martineau.
	(parse_opt): Hanlde new options.
	(decode_options): Initialize check_device_option to true.
	
	* THANKS: Update

2008-03-06  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap: Use rsync to get translations.
	* doc/tar.texi: Minor change.
	* lib/.cvsignore: Update
	* po/.cvsignore: Update
	* src/system.c: Remove include setenv.h.
	* tests/atlocal.in (STAR_DATA_URL): Update.
	* tests/star/README: Update URL. 

2008-02-09  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Fix a typo. Reported by Denis Excoffier.

2008-02-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update.
	* configure.ac: Version 1.19.90
	* po/POTFILES.in: Add missing files.
	* src/compare.c (verify_volume): Honor --ignore-zeros.
	Proposed by Jan-Benedict Glaw.
	* tests/shortfile.at (AT_KEYWORDS): Add shortfile0.

2008-02-07  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update.
	* src/create.c (dump_file0): Apply transform_name to symlink
	targets.

2008-02-04  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/transform.c: Support multiple --transform options. Support
	semicolon-separated lists of replace expressions.
	* NEWS, tar.texi: Document changes to the --transform option.

2008-01-30  Paul Eggert  <eggert@cs.ucla.edu>

	* doc/tar.texi: Update Back-Cover text to reflect new GNU wording.

2007-12-17  Paul Eggert  <eggert@cs.ucla.edu>

	Exit with nonzero status if a close fails on an archive.
	Problem (and initial trivial fix)
	* src/buffer.c (close_archive, new_volume): close_error, not
	close_warn. 

2007-12-05  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/buffer.c (check_compressed_archive): Do not bail out if the
	file is too short, set boolean flag, passed as an argument
	instead.  This fixes a bug introduced on 2007-08-24. See also
	tests/shortupd.at.

	* tests/Makefile.am, tests/testsuite.at: Add shortupd.at.
	* tests/shortupd.at: New test.

2007-11-12  Jim Meyering  <meyering@redhat.com>

	Don't read from name[-1].
	* src/incremen.c (make_directory): Handle namelen == 0, since
	find_directory_meta calls make_directory ("").

2007-11-07  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap (checkout): Use URL of the gnulib CVS mirror.
	* gnulib.modules: Add fseeko and snprintf.

2007-10-31  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/checkpoint.c: New actions: bell and ttyout
	* src/system.c (sys_exec_info_script)
	(sys_exec_checkpoint_script): pass the current blocking factor in
	TAR_BLOCKING_FACTOR environment variable.
	* doc/tar.texi: Update
	* NEWS: Update

2007-10-30  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/Makefile.am: Use texi2html and the CVS version of gendocs.sh
	to create HTML versions of the manual.
	* doc/gendocs_template: Likewise.
	* doc/tar.texi: Document --hard-dereference and
	--checkpoint-action options. Improve documentation of
	--check-links.

2007-10-29  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update
	* configure.ac: Version 1.19.1
	* po/POTFILES.in: Add src/checkpoint.c
	* src/Makefile.am (tar_SOURCES): add checkpoint.c
	* src/checkpoint.c: New file - checkpoint handling.
	* src/buffer.c (checkpoint, do_checkpoint): Remove.
	(_flush_write, simple_flush_read, _gnu_flush_read): Use
	checkpoint_run.
	* src/common.h (enum checkpoint_style): Remove.
	(checkpoint_style): Remove.
	(DEFAULT_CHECKPOINT): New define.
	(hard_dereference_option): New variable.
	(sys_exec_checkpoint_script): New declaration.
	* src/create.c (file_count_links): do nothing if
	hard_dereference_option is set.
	* src/system.c (sys_exec_checkpoint_script): New function.
	(sys_exec_info_script): Restore SIGPIPE handler.
	* src/tar.c: (parse_opt): New options --hard-dereference,
	--checkpoint-action.
	(decode_options): Call checkpoint_finish_compile.

	* src/system.c (sys_exec_info_script): Initialize buf. Problem
	reported by Bengt-Arne Fjellner.

2007-10-18  Jim Meyering  <jim@meyering.net>

	Avoid compiler warnings.
	* src/list.c (read_header_primitive): Define two locals, to
	avoid incorrect "may be used uninitialized" warnings.
	* src/incremen.c (procdir): Remove decl of unused local, "len".

2007-10-18  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi (gzip): Remove compression patent
	warning. According to Brett Smith, the patent is
	expired.

2007-10-17  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/suffix.c: New file. Compress format detection by archive
	suffix (when creating). Suggested by Jean-Pierre Demailly.
	* src/Makefile.am: Add suffix.c
	* src/buffer.c (magic): Add an entry for new lzma format. Proposed
	by Lasse Collin.
	* src/common.h (set_comression_program_by_suffix): New prototype.
	* src/tar.c: New options --auto-compress (-a) and --lzma
	* THANKS: Add Lasse Collin and Jean-Pierre Demailly.
	* NEWS: Update
	* doc/tar.texi: Update

2007-10-12  Paul Eggert  <eggert@cs.ucla.edu>

	* src/utf8.c (string_ascii_p): Recode to avoid bogus GCC 4.2.1
	warning about "comparison is always true due to limited range of
	data type" when char is unsigned.

2007-10-11  Paul Eggert  <eggert@cs.ucla.edu>

	Adjust to recent gnulib changes.
	* configure.ac: Dont' check for strerror, since gnulib now does this.
	* .cvsignore: Add m4, tar-[0-9]*.
	* lib/.cvsignore: Adjust to various gnulib file name changes.
	Add .deps, rmt-command.h.

2007-10-10  Sergey Poznyakoff  <gray@gnu.org.ua>

	* configure.ac, NEWS: Raise version number to 1.19
	* tests/star/README: Update

2007-10-05  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/create.c (dump_regular_file): Fix file padding in case of
	truncation to zero size.
	* NEWS: Update

2007-10-04  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/T-null.at: Use AT_DATA for sample output.

2007-10-03  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c (try_purge_directory): Ensure that arguments to T
	and R are safe.

2007-09-29  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c (obstack_code_rename): Apply safer_name_suffix to
	name arguments before storing them in T and R records. Reported by
	Nicholas Cole.

2007-09-27  Sergey Poznyakoff  <gray@gnu.org.ua>

	* configure.ac: Raise version number to 1.18.90
	* NEWS: Likewise

	* doc/snapshot.texi: Document version 2.
	* doc/dumpdir.texi: Update.

	Implement --exclude-tag* and --exclude-cache* options for listed
	incremental archives.
	New option --exclude-vcs to exclude VCS-specific files and
	directories.

	* NEWS: Update
	* doc/tar.texi: Document --exclude-vcs option
	* src/common.h (exclusion_tag_warning, check_exclusion_tags): New
	prototypes.
	* src/create.c (exclusion_tag_warning, check_exclusion_tags):
	Remove static qualifier.
	(check_exclusion_tags): account for dirname without terminating
	slash.
	(dump_dir0): exclusion_tag_all is handled elsewhere.
	* src/incremen.c (struct directory): New member tagfile
	(make_directory): Initialize tagfile to NULL
	(procdir): New argument: entry
	Hanlde exclusion tags.
	(makedumpdir): Take into account directory->tagfile.
	(scan_directory): Hanlde exclusion tags.
	* src/tar.c: New option --exclude-vcs
	(exclude_vcs_files): New function

2007-09-14  Paul Eggert  <eggert@cs.ucla.edu>

	* AUTHORS: Remove unnecessary information.  Just list the
	principal authors.
	* THANKS: Remove info duplicated from AUTHORS.

2007-08-25  Jim Meyering  <jim@meyering.net>

	Don't include <getline.h>.  No longer needed.
	* src/incremen.c: Don't include <getline.h>.  No longer needed.
	* src/buffer.c: Likewise.
	* src/system.c: Likewise.
	* src/tar.c: Likewise.

	Avoid shadowing and unused-variable warnings.
	* src/create.c (check_exclusion_tags): Remove declaration of unused
	local, "ret".
	* src/compare.c (diff_dumpdir): Rename stat->stat_data to avoid
	shadowing the syscall.
	* src/buffer.c (do_checkpoint): Don't shadow the write syscall.
	(try_new_volume): Avoid shadowing "access".
	* src/tar.c (decode_options): Rename index->idx to avoid shadowing.
	(find_argp_option): Rename option->o to avoid shadowing.
	* src/incremen.c (scan_directory): Rename local, dir_name->dir,
	to avoid shadowing the function.
	(get_directory_contents): Likewise.
	* src/system.c (global_pid): Rename from "pid", to avoid being
	shadowed by locals.
	* src/extract.c (apply_nonancestor_delayed_set_stat):
	Rename st->sb to avoid shadowing another local.

2007-08-24  Sergey Poznyakoff  <gray@gnu.org.ua>

	* configure.ac, NEWS: Raise version number to 1.18.1

	* src/buffer.c (check_compressed_archive): Detect files smaller
	than 512 bytes.
	* tests/shortfile.at: New test case for the above change.
	* tests/testsuite.at, tests/Makefile.am: Add shortfile.at

2007-08-19  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap: Gnulib initialization destroyed paxutils m4 files.
	Initialize paxutils structure after that of gnulib.

2007-08-12  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/names.c (contains_dot_dot): Fix double-dot recognition in
	case of duplicate /. Patch by Dmitry V. Levin.

	* bootstrap (symlink_to_gnulib): Make sure the target directory
	exists and create it if it does not.

	* doc/tar.texi: Fix a typo.

2007-06-28  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap: Update for the change of the TP URL

2007-06-27  Sergey Poznyakoff  <gray@gnu.org.ua>

        Relicense under GPLv3

2007-06-21  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/testsuite.at (AT_TAR_MKHIER): Skip test if genfile is
	unable to create the file
	* tests/lustar01.at: Likewise

2007-06-21  Eric Blake  <ebb9@byu.net>

        Resolve testsuite failures 40-42 on cygwin.
        * tests/testsuite.at (AT_TAR_MKHIER): Skip tests when long
        file names cannot be created.

2007-06-16  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/Makefile.am (tar_TEXINFOS): Add tar-snapshot-edit.texi
	* doc/tar-snapshot-edit.texi: New file
	* doc/tar.texi (Fixing Snapshot Files): New appendix

	* scripts/tar-snapshot-edit: New file
	* tests/extrac07.at: Add back write permissions on dir

2007-06-09  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/exclude.at: Sort the output.

2007-06-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* configure.ac, NEWS: Raise version number to 1.17

	* doc/tar.texi, doc/intern.texi: Replace: s/filename/file name/;
	s/(ASCII|ID|BSD)/@acronym{&}/;s/"[^"]+"/``&''/
	Use `path' only when it refers to search paths, use
	`file name' otherwise.
	Fix various errors (based on patch by Benno Schulenberg)

	* doc/tar.texi (Operation Summary): Restore alphabetical order of
	the options.

2007-06-02  Sergey Poznyakoff  <gray@gnu.org.ua>

	Fix bug, introduced on 2007-03-30.

	* src/common.h (xform_type): New data type
	(transform_member_name): Last argument is of xform_type type
	All callers updated

	* src/extract.c: Update calls to transform_member_name
	* src/list.c (decode_xform): Exempt symbolic links from component
	stripping and name suffix normalization.

	* tests/extrac07.at: Update

2007-05-30  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/xheader.c (decx): Unknown pax keywords produce a warning,
	not error.

2007-05-29  Paul Eggert  <eggert@cs.ucla.edu>

	* src/misc.c (set_file_atime): Use gl_futimens, not futimens,
	due to gnulib change.

2007-05-19  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/common.h (buffer_write_global_xheader): New function
	(struct xheader): Move definition to tar.h
	(extended_header): Remove global
	(xheader_init): New function
	(xheader_decode_global,xheader_store,xheader_read)
	(xheader_write_global,xheader_write,xheader_string_begin)
	(xheader_string_add,xheader_string_end): Take xhdr as first
	argument.
	* src/tar.h (struct xheader): New definition
	(struct tar_stat_info): New member xhdr (extended header).

	* src/xheader.c (xheader_init): New function
	(xheader_decode_global,xheader_store,xheader_read)
	(xheader_write_global,xheader_write,xheader_string_begin)
	(xheader_string_add,xheader_string_end): Take xhdr as first
	argument.

	* src/buffer.c (buffer_write_global_xheader): New function
	Update to use new xheader calls.

	* src/compare.c, src/create.c, src/delete.c, src/list.c,
	src/sparse.c, src/tar.c, src/update.c: Global extended_header
	removed, use new xheader calls instead.

	* tests/T-null.at: Minor fix
	* tests/atlocal.in (tarball_prereq): Discard eventual md5sum
	output.

2007-05-18  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/create.c (dump_file0): Original ctime cannot be used as a
	directory change indicator if --remove-files is given.

2007-04-12  Paul Eggert  <eggert@cs.ucla.edu>

	Adjust to latest Gnulib.
	* lib/.cvsignore: Add dirfd.c, dirfd.h, float+.h, mbscasecmp.c,
	stdio.h, stdio_.h, stdlib.h, stdlib_.h, time.h, time_.h, unistd.h.
	Remove exit.h, getcwd.h, mempcpy.h, memrchr.h, mkdtemp.h, stpcpy.h,
	strcase.h, strchrnul.h, strdup.h, strndup.h, strnlen.h, time_r.h,
	vsnprintf.h.
	* m4/.cvsignore: Remove localedir.h.  Sort.

2007-04-03  Paul Eggert  <eggert@cs.ucla.edu>

	* src/common.h (closeopen): Remove decl.
	* src/misc.c: Don't include <sys/time.h>, <sys/resource.h>; no longer
	needed.
	(get_max_open_files, closeopen): Remove.  All callers removed.
	(chdir_dir): Use a different technique, which doesn't rely on closing
	all open files.
	* src/tar.c (main): Don't call closeopen.

2007-04-04  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update
	* doc/tar.texi: Update
	* src/system.c (sys_exec_info_script): Store the
	inter-communication fd in the environment variable TAR_FD

2007-04-03  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (main): Move closeopen after decode_options to
	allow shell process substitution to work.
	* tests/extrac07.at: Expect a warning on stderr.

2007-03-30  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/common.h (transform_name_fp): Change signature
	(transform_member_name): New function
	* src/extract.c (extract_link, extract_symlink): Use
	transform_member_name instead of safer_name_suffix so that
	--transform and --strip-components affect links as well.
	* src/list.c (transform_member_name): New function
	(decode_header): Use transform_member_name
	* src/names.c (all_names_found): Remove check for matching_flags.
	* NEWS: Update

	* TODO: Update
	* bootstrap (slurp): Remove any occurrences of $bt from the
	generated gnulib.mk
	* src/incremen.c: Do not include mkdtemp.h

2007-01-26  Paul Eggert  <eggert@cs.ucla.edu>

	Adjust to recent gnulib changes.
	* lib/.cvsignore: Add fchownat.c, rmt-command.h, strerror.c, string.h,
	string_.h, sys, sys_time_.h, unistd_.h, wchar_.h, wctype_.h.
	Remove localedir.h, size_max.h, xsize.h.
	* src/xheader.c: Don't include stpcpy.h; no longer needed, now that
	gnulib string.h defines stpcpy on all platforms.

2007-01-23  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Document --exclude-caches* and --exclude-tag*
	options.
	* src/common.h (exclude_caches_option): Remove
	(enum exclusion_tag_type): New data type
	(add_exclude_tag): Rename to add_exclusion_tag
	(cachedir_file_p): New prototype
	* src/create.c (struct exclude_tag): rename to exclusion_tag
	(check_exclusion_tags): New function
	(cachedir_file_p): New function (from check_cache_directory)
	(dump_dir0,dump_file0): Use check_exclusion_tags
	* src/tar.c: New options --exclude-caches-all,
	--exclude-caches-under, --exclude-tag-all, --exclude-tag-under
	* tests/exclude.at: New file
	* tests/Makefile.am (TESTSUITE_AT): Add exclude.at
	* tests/testsuite.at: Add exclude.at

2007-01-19  Sergey Poznyakoff  <gray@gnu.org.ua>

	* gnulib.modules: Require strerror
	* doc/gendocs_template: Fix typos
	* scripts/xsparse.c (expand_sparse): use ftruncate to handle the
	trailing hole
	* src/sparse.c (sparse_skip_file,pax_dump_header_1)
	(pax_decode_header): Keep track of the number of bytes
	written.
	* configure.ac: Version 1.16.2
	* NEWS: Update

2007-01-04  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/compare.c (diff_dumpdir): Compare directory contents using
	dumpdir_cmp.  Do not free dumpdir_buffer, it will leave the
	incremental directory table in the inconsistent state and trigger
	full dump.
	(read_and_process): Process dumpdirs no matter what the archive
	format.
	* src/incremen.c (list_dumpdir): Minor fixes.

	* src/compare.c (read_and_process): Fix type of "size"

2006-12-13  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/T-null.at: Skip the test if genfile is not able to create
	the filename with an embedded newline.

2006-12-12  Paul Eggert  <eggert@cs.ucla.edu>

	Port to Forte Developer 7 C 5.4 and C99.
	* src/common.h (add_exclude_tag): Add decl; C99 requires this
	and Forte warns about it.
	* src/incremen.c: Include <mkdtemp.h> for mkdtemp prototype,
	for same reason.
	* src/misc.c (get_max_open_files): Rewrite to avoid code that
	Forte C complains about as being unreachable.
	* src/xheader.c (mtime_code): Rewrite to avoid Forte error
	reported by Trond Hasle Amundsen.

	* src/incremen.c (compare_dirnames): Rewrite to avoid casts.
	* src/utf8.c (string_ascii_p): Likewise.
	* src/xheader.c (mtime_coder, volume_size_coder, volume_offset_coder):
	Likewise.

2006-12-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap: Add paxutils files to dot_ignore.

	* configure.ac: Raise version number to 1.16.1
	* bootstrap (slurp): Create .(cvs|git)ignore if not present
	* po/.cvsignore, m4/.cvsignore: Remove automatically generated
	files.

2006-12-07  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update
	* Makefile.am (distclean-local): Fixed
	* doc/tar.texi: Update documentation of --exclude-tag
	* src/create.c (dump_dir0): Move checks for exclude tags to
	dump_file0.
	(dump_dir): Move calls to ensure_slash to dump_file0
	* src/extract.c (extract_file): Call skip_member if open fails.
	Patch proposed by Jan-Benedict Glaw <jbglaw@lug-owl.de>
	* tests/truncate.at: Use genfile instead of dd, because on some
	systems /dev/zero is not available.

2006-12-04  Paul Eggert  <eggert@cs.ucla.edu>

	* NEWS: Fix some race conditions with tar -x --same-owner.
	* src/extract.c (ARCHIVED_PERMSTATS): Add a comment saying that
	S_IRWXG | S_IRWXO might be masked out.
	(set_mode): Set the mode if some bits were masked out originally.
	(set_stat): Don't chmod before chown, as that might temporarily
	grant permissions that we don't want to grant.  The chmod was
	there only to work around broken hosts, so add a comment advising
	users not to use those broken hosts instead.
	(repair_delayed_set_stat, extract_dir):
	Remember to mask out current umask before inverting permissions.
	(extract_dir): If the owner might change, or if the mode has
	special bits, create the directory 700 at first, but restore it later.
	(open_output_file): New arg mode; all uses changed.
	(extract_file, extract_node, extract_fifo): If the owner might
	change, omit group and other bits at first, but restore them after
	changing the owner.

2006-12-04  Jim Meyering  <jim@meyering.net>

	* doc/tar.texi (Long Options): Remove doubled word.

2006-11-30  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/xheader.c (xheader_read): Remove unused variable

	* po/POTFILES.in: Remove src/mangle.c

	* bootstrap: Implement --update-po and .bootstrap

	* src/create.c (dump_dir0): Implement --exclude-tag option
	* src/tar.c: Likewise
	* doc/tar.texi (exclude): Document --exclude-tag

2006-11-29  Paul Eggert  <eggert@cs.ucla.edu>

	* NEWS: Remove support for mangled names.
	* doc/tar.texi (verbose tutorial): Likewise.
	* src/Makefile.am (tar_SOURCES): Remove mangle.c.
	* src/common.h (extract_mangle): Remove decl.
	* src/extract.c (extract_mangle_wrapper): Remove.
	(prepare_to_extract): Remove support for mangled names.
	* src/list.c (read_and, print_header): Likewise.
	* src/mangle.c: Remove.
	* src/tar.h (GNUTYPE_NAMES): Remove.

	Port to latest gnulib.  There were a lot of changes, so the
	simplest way to get this up and running was to switch to coreutils
	bootstrap procedure.  I noticed one feature missing after this
	merge: the ability to update a single .po file.  I can add that
	later if need be.
	* README-cvs, bootstrap.conf: New files.
	* lib/.cvsignore: Remove Makefile.am, printf-parse.c, vasnprintf.c.
	Add fstatat.c, gnulib.mk, openat-proc.c, same-inode.h, stat_.h,
	tempname.c, tempname.h, uinttostr.c.
	* lib/printf-parse.c, lib/vasnprintf.c: New files, from coreutils,
	to override gnulib, so that we don't need xsize.h.
	* bootstrap: Replace with coreutils bootstrap, except add support
	for paxutils.
	* configure.ac (gl_USE_SYSTEM_EXTENSIONS): Remove, as gl_EARLY now
	does this.
	(gl_EARLY, gl_INIT): Add.
	(tar_GNULIB): Remove.
	* gnulib.modules: Add configmake.
	* lib/Makefile.tmpl: Remove, replacing with....
	* lib/Makefile.am: New file.
	* src/Makefile.am (tar.o): Remove dependency: Automake does this
	for us.
	* src/tar.c: Include <configmake.h> and <rmt-command.h>, not
	<localedir.h>.

2006-11-13  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/xheader.c (mtime_coder): Treat non-null data as a pointer to
	struct timespec, overriding st->mtime
	* src/create.c (start_header): Pass mtime as a call-specific data
	to xheader_store.

	* tests/truncate.at: Do not use 'k' modifier in dd options.
	* tests/append02.at: Do not depend on command timing.

2006-11-01  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (enum read_file_list_state.file_list_skip): New value
	(read_name_from_file): Skip zero-length entries

	* tests/T-empty.at: New test case
	* tests/T-null.at: New test case
	* tests/extrac07.at: New test case
	* tests/Makefile.am: Add new test cases.
	* tests/testsuite.at: Add new test cases.
	* tests/extrac02.at: Add more keywords
	* tests/extrac04.at: Likewise
	* tests/extrac06.at: Likewise
	* tests/shortrec.at: Do not assume tar's default archive is stdout

2006-10-31  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/extract.c, src/xheader.c: Call last_component instead of
	base_name. The latter returns a malloced string since 2006-03-11.

2006-10-21  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS, configure.ac: Version 1.16
	* Makefile.am (distclean-local): New rule

2006-10-17  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c: Fix help output formatting.  Thanks Benno
	Schulenberg.

2006-10-16  Sergey Poznyakoff  <gray@gnu.org.ua>

	* Makefile.am (dist-hook): Create a cpio archive.
	* NEWS: Update

2006-10-14  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi (Synopsis): Document tar exit codes.
	* src/create.c (dump_regular_file,dump_file0): Set exit_status to
	TAREXIT_DIFFERS if the file being dumped was truncated or
	otherwise changed.
	* src/tar.c: Do not attempt to close stderr after call to
	close_stdout.
	* tests/grow.at: New test case
	* tests/Makefile.am: New test grow.at
	* tests/testsuite.at: Likewise
	* tests/truncate.at (AT_KEYWORDS): Keyword `filechange'
	Test tar exit status.

	* src/buffer.c (_open_archive): Make sure stdlis is set to stderr
	when we are writing archive to stdout (unless --index-file is
	used). Bug introduced on 2006-07-06.
	* tests/Makefile.am: New test verbose.at
	* tests/testsuite.at: Likewise
	* tests/indexfile.at (AT_KEYWORDS): Add stdout keyword
	* tests/verbose.at: New test case

2006-10-02  Sergey Poznyakoff  <gray@gnu.org.ua>

	* THANKS: Add Joerg Weilbier
	* src/buffer.c (new_volume): Initialize current_block
	* src/xheader.c (xheader_string_end): Fix diagnostic message.
	* tests/multiv05.at: New testcase.
	* tests/Makefile.am, tests/testsuite.at: Add multiv05.at

2006-09-27  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap: Use ${package} instead of hardcoding package name
	* doc/tar.texi: Minor fix
	* src/tar.c (doc0, doc1, initialize_argp_doc): Removed.  Rely on
	the new argp method instead.

2006-09-12  Sergey Poznyakoff  <gray@gnu.org.ua>

	* README: Fix a typo

2006-09-08  Paul Eggert  <eggert@cs.ucla.edu>

	Adjust to latest gnulib.
	* lib/.cvsignore: Add at-func.c, configmake.h, fchmodat.c,
	fcntl.h, fcntl_.h, inttypes_.h, lstat.c, lstat.h.
	* tests/testsuite.at (AT_TAR_MKHIER): Use install-sh -d
	rather than the no-longer-included mkinstalldirs.

2006-09-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c (try_purge_directory): Initialize struct st.  Fix
	condition for selecting candidates for removal.
	* README-alpha: List texinfo among build prerequisites for the CVS
	version.

	* bootstrap (intl_files_to_remove): Do not remove m4/inttypes-h.m4
	and m4/inttypes-pri.m4

2006-08-11  Paul Eggert  <eggert@cs.ucla.edu>

	* bootstrap: Set XGETTEXT_OPTIONS to flag our printf-format functions,
	so that translators are warned about strings that are formats but
	don't look like formats.  This might help prevent core dumps.
	* configure.ac (AM_GNU_GETTEXT): Upgrade to need-formatstring-macros.
	Suggested by Eric Blake to avoid problems like
	<http://lists.gnu.org/archive/html/bug-coreutils/2006-07/msg00087.html>.
	(AM_GNU_GETTEXT_VERSION): Upgrade from 0.12.1 to 0.15.  The gettext
	manual says we should use the version number normally expected of
	maintainers, neither more nor less.

	* bootstrap (get_translations):
	Don't exclude ky.po; it is working again.

2006-08-09  Paul Eggert  <eggert@cs.ucla.edu>

	* bootstrap (get_translations):
	Don't exclude ja.po; it is working again.
	Don't remove all old .po files if we're merely updating one.
	* po/.cvsignore: Add Makevars.

2006-08-07  Paul Eggert  <eggert@cs.ucla.edu>

	* src/tar.c: Work around limitation imposed by gettext 0.15
	by concatenating strings with "\v" after translation.
	(doc): Remove, splitting into:
	(doc0, doc1): New constants.
	(argp): Don't use doc; just initialize to NULL.
	(initialize_argp_doc): New function.
	(decode_options): Use it.

	* bootstrap: Redo po file retrieval to match Bison's method,
	since the translation project changed its index format.
	Don't use --assume-autoconf; it's now replaced
	by looking in configure.ac.
	(m4/codeset.m4, m4/intdiv.m4, m4/inttypes-pri.m4, m4/isc-posix.m4):
	(m4/lcmessage.m4, m4/onceonly_2_57.m4, m4/gettext.m4, m4/glibc21.m4):
	(m4/inttypes_h.m4, m4/lib-ld.m4, m4/lib-prefix.m4, m4/po.m4):
	(m4/stdint_h.m4, m4/uintmax_t.m4, m4/ulonglong.m4):
	Don't rename to ..._gl.m4, as this is no longer needed.
	(m4/geteext.m4): Patch to remove the need for intl/*.
	Use autopoint manually, then remove the intl files,
	then undo changes to gnulib files that autoreconf made,
	and then run aclocal/autoconf/autoheader/automake.
	This makes our bootstrap procedure closer to Bison's.
	(po/Makevars): Generate automatically.
	* configure.ac (AC_PREREQ): Update from 2.59 to 2.60.
	(gl_AC_TYPE_INTMAX_T, jm_AC_TYPE_UINTMAX_T): Remove.
	* gnulib.modules: Add inttypes, stdint.
	* lib/.cvsignore: Add close-stream.c, close-stream.h,
	stdint.h, stdint_.h.
	* po/Makefile: Remove; now automatically generated.

	* src/incremen.c (read_incr_db_01): Check input strings more
	carefully.  Do not pass arbitrary char values to isspace, as
	this has undefined behavior.  Likewise for assigning arbitrary
	uintmax_t values to other types.
	(read_negative_num, read_unsigned_num, read_timespec):
	New functions, to check input values a bit more carefuly.
	(read_num): Use read_unsigned_num.  New arg MAX_VAL;
	all callers changed.
	(read_incr_db_2): Use these new functions.
	Use a consistent diagnostic for unexpected EOF.
	(read_directory_file): Do not assign arbitrary uintmax_t value
	to int.
	(read_timespec, write_directory_file_entry, write_directory_file):
	Handle negative time_t values correctly.  We don't bother to do
	this with pre-2 formats, since presumably the time stamps were
	output incorrectly.

	* src/tar.c (doc): Don't use \v in an argument to gettext;
	gettext 0.15 rejects this.

2006-07-24  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (decode_options): Do not require -L with -M -Hpax.
	It could be needed in future, but currently it is not.
	* src/create.c (to_chars_subst): Update comment regarding OLDGNU
	vs. GNU format differences.
	(mode_to_chars): Treat OLDGNU_FORMAT same as GNU_FORMAT. Fixes bug
	reported by TAMUKI Shoichi <tamuki@linet.gr.jp>, which caused
	equivalent `tar cf ...' and `tar rf ...' commands to produce
	different archives.

	* tests/append02.at: New test case
	* tests/Makefile.am, tests/testsuite.at: Add append02.at

2006-07-20  Paul Eggert  <eggert@cs.ucla.edu>

	* bootstrap: Adjust to today's change to gnulib-tool by invoking
	it with --assume-autoconf='latest-stable'.

2006-07-16  Paul Eggert  <eggert@cs.ucla.edu>

	Adjust to recent gnulib changes.
	* lib/.cvsignore: Remove atexit.c, exit.c, getndelim2.c, getndelim2.h,
	pathmax.h, paxconvert.c, paxerror.h, xstrdup.c.
	Add inttypes.h, mktime.c, wcwidth.h, xstrndup.c, xstrndup.h.
	* src/create.c (start_header): Adjust to API change to mode_adjust.

2006-07-09  Sergey Poznyakoff  <gray@gnu.org.ua>

	* THANKS: Add Ralf Wildenhues
	* NEWS: Update

2006-07-09  Ralf Wildenhues   <Ralf.Wildenhues@gmx.de>

	* doc/dumpdir.texi, doc/snapshot.texi, doc/sparse.texi,
        doc/tar.texi: Fix some typos.

2006-07-06  Sergey Poznyakoff  <gray@gnu.org.ua>

	tar --index-file=FILE --file=- sent the archive to FILE, and
	the listing to stderr. Bug reported by Marcin Gryszkalis
	<mg@fork.pl>

	* src/buffer.c (_open_archive): Remove stdlis initialization
	* src/tar.c (decode_options): Initialize stdlis
	* tests/indexfile.at: New test case
	* tests/testsuite.at: Include indexfile.at
	* tests/Makefile.am (TESTSUITE_AT): Add indexfile.at

2006-07-05  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/Makefile.am (manual): Fix TEXINPUTS
	* doc/rendition.texi (FIXME): Do not use deprecated @quote-args.
	Do not use @allow-recursion. In its current form the macro is not
	recursive.

2006-07-03  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap (update_po): Fix single translation update

2006-07-03  Sergey Poznyakoff  <gray@gnu.org.ua>

	* configure.ac (AC_CHECK_FUNCS): Check for getdtablesize
	* src/common.h (closeopen): New function
	* src/misc.c (chdir_arg): Use x2nrealloc to reallocate wd.
	(get_max_open_files,closeopen): New functions
	(chdir_do): Do not use save_cwd if it was already used more than
	max_open_files-4 times to avoid running off the file
	descriptors.
	* src/tar.c (main): Call closeopen
	* doc/tar.texi: Update --directory description
	* NEWS: Update

2006-06-26  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Update. Add cross-references.
	* doc/sparse.texi: Add cross-references.

2006-06-25  Sergey Poznyakoff  <gray@gnu.org.ua>

	* scripts/xsparse.c: A sample utility to expand sparse files
	extracted by third-party tars. It is not meant to be installed nor
	to be included in the distribution. It is here, so that it can be
	obtained either from CVS or from the tar web site.
	* doc/Makefile.am (tar_TEXINFOS): Sorted
	* doc/tar.texi (Other Tars): New node describing how to extract
	GNU-specific member formats using third-party tars.
	* src/common.h (sparse_file_p): Remove
	* src/sparse.c: Likewise
	* src/create.c: Use ST_IS_SPARSE instead of sparse_file_p (update
	paxutils first)
	* src/tar.c: --sparse-version turns on --sparse

2006-06-24  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/buffer.c (print_total_stats): Add default case.
	* src/common.h (name_init): New prototype.
	(xheader_string_end): Return bool.
	* src/extract.c (extract_volhdr): Add missing return
	* src/incremen.c: Remove not used variables
	* src/sparse.c (pax_dump_header_0): Return false if
	xheader_string_end fails (for 0.1 formats).
	(pax_dump_header): Return meaningful value
	* src/transform.c (segm_count): Change type to size_t
	* src/xheader.c (xhdr_tab.decoder): pass keyword as a second
	argument. All callers changed.
	(decode_record): Check for numeric overflow
	(xheader_string_end): Return boolean value. Check for possible
	numeric overflow

2006-06-23  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/sparse.texi: New file
	* doc/Makefile.am (tar_TEXINFOS): Add sparse.texi
	* doc/intern.texi (Sparse Formats): New node
	* doc/tar.texi: Update master menu

	* src/common.h (tar_sparse_major,tar_sparse_minor): New globals.
	* src/sparse.c: Implement sparse format versioning. Implement new
	version (1.0) of PAX sparse format.
	(pax_sparse_member_p): Fix condition
	(pax_dump_header): A dispatcher function
	(pax_dump_header_0,pax_dump_header_1): New functions.
	(pax_optab): Update
	(oldgnu_dump_header): Minor fix: make sure
	sparse_header.isextended is set before calling
	set_next_block_after
	* src/tar.c: New option --sparse-version
	* src/tar.h (struct tar_stat_info.sparse_major,sparse_minor): New
	members.
	* src/xheader.c: Implement new keywords: GNU.sparse.name,
	GNU.sparse.major, GNU.sparse.minor, GNU.sparse.realsize

	* tests/spmpv00.at, tests/spmvp01.at, tests/spmvp10.at: New
	testcases.

	* tests/Makefile.am: Add spmvp00.at, spmpv01.at, spmpv10.at
	* tests/shortrec.at: Explicitely give `-f -' to the tar invocation
	* tests/sparsemvp.at: Rewritten as an include file.
	(TAR_MVP_TEST): New macro
	* tests/testsuite.at: Include sparsemvp.at, spmvp00.at,
	spmvp01.at, spmvp10.at

2006-06-21  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi (Overriding File Metadata): New node
	Document --mtime option.
	* src/common.h (set_mtime_option,mtime_option): New globals
	* src/create.c (start_header): Override mtime if requested
	* src/tar.c: Implement new option, --mtime, allowing to set
	modification times for all archive members during creation.
	(struct tar_args): textual_date_option replaced with a linked list
	textual_date. All references updated.
	(get_date_or_file,report_textual_dates): New functions.
	* configure.ac: Raise version number to 1.15.92
	* NEWS: Update

2006-06-20  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/common.h (struct name.explicit): Remove
	Use variable names in all declarations
	(name_scan): Remove second argument
	* src/delete.c: Remove second argument from calls to name_scan
	* src/update.c: Likewise
	* src/incremen.c (procdir): Use is_individual_file to check for
	files explicitely specified in the command line. Fixes bug
	reported by Dat Head on 19 Jun 2006 (descending into mountpoints
	with --one-file-system in use)
	* src/misc.c (maybe_backup_file): Second argument is bool
	* src/names.c (name_next_elt): Call register_individual_file
	(namelist_match): Remove third argument
	(name_match): Change return type to bool
	(name_scan): Remove second argument
	* src/sparse.c (pax_dump_header): Store original sparse file name
	in GNU.sparse.name variable. The name field in the ustar header
	now contains generated name (%d/GNUSparseFile.%p/%f), so that
	non-pax-aware tars won't extract the file under the original
	filename.
	* src/xheader.c (GNU.sparse.name): New variable for storing sparse
	file name.

2006-06-13  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/Makefile.am (check-options): Expand macros before grepping
	in $(info_TEXINFOS)
	* doc/rendition.texi (FIXME) [!PROOF_FOOTNOTED]: Enclose in a
	cartouche
	* doc/tar.texi: Define op as codeindex. Use special macros to
	populate it
	Consequently prefer @dfn{long options} over @dfn{mnemonic
	options}.
	Document --unquote, --no-unquote
	(Short Option Summary): Build a table of cross-references to the
	corresponding long options.
	(Using Multiple Tapes,Multi-Volume Archives): Rewritten

	* doc/value.texi (xopindex,opsummary): New macros

	* doc/Makefile.am (check-options): New goal
	* doc/tar.texi: Update
	* src/tar.c: Implement --overwrite-dir option (long ago
	documented).

2006-06-12  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Document better the --totals option
	* NEWS: Update
	* src/buffer.c (total_blocks_deleted): New variable
	(set_start_time): Set volume_start_time and last_stat_time as well
	(set_volume_start_time): New function
	(compute_duration): Do not call set_start_time, update
	last_stat_time instead. Use it in calculation instead of
	start_time, which is now set only once, upon startup.
	(print_total_written): Removed.
	(print_total_stats): New function for printing byte/speed statistics.
	(_open_archive): Detect attempts to update compressed archives.
	(_gnu_flush_write): Always update prev_written.
	(open_archive): Call set_volume_start_time.
	* src/common.h (volume_start_time,last_stat_time): New globals
	(print_total_written): Replaced with:
	(print_total_stats): New function
	* src/delete.c (records_skipped): Remove static qualifier, the
	variable is used by print_total_stats in buffer.c
	* src/extract.c (check_time): Use volume_start_time when checking
	for timestamp plausability.
	* src/tar.c: (options, parse_opt): Allow for optional argument to
	the --totals option, which specifies a signal upon delivery of which
	the statistics must be output.
	(main): Call print_total_stats if total_option is set.

2006-06-11  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/xheader.c (xheader_set_single_keyword): Fix typo.
	(decode_time): Avoid using gotos.

	* doc/mastermenu.el: New file
	* doc/Makefile.am (master-menu): New goal
	* doc/tar.texi: Update master menu

2006-06-10  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Remove leftover include

2006-06-09  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/Makefile.am (tar_TEXINFOS): Add intern.texi
	(EXTRA_DIST): Remove convtexi.pl, add texify.sed
	* doc/intern.texi: New file
	* doc/convtexi.pl: Remove
	* doc/texify.sed: Auxiliary script to convert ../src/tar.h to
	header.texi
	* doc/rendition.texi: Fix typo
	* doc/tar.texi: Update
	* src/tar.h: Fix indentation, introduce end-of-format marker for
	texify.sed

	* THANKS: Add Jason Armistead
	* doc/tar.texi: Update
	* NEWS: Update
	* src/buffer.c: Implement more flexible checkpoint style
	* src/common.h (checkpoint_option): Change type to unsigned
	(checkpoint_style): New variable.
	* src/tar.c: --checkpoint takes an optional argument specifying
	number of records between two successive checkpoints (proposed
	by Jason Armistead on 2004-06-22).  Optional dot starting the
	argument means "print dots instead of textual checkpoints".
	(tar_help): New function
	* src/transform.c: Minor fixes.

2006-06-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* gnulib.modules: Add mkdtemp
	* doc/dumpdir.texi: New file
	* doc/Makefile.am (tar_TEXINFOS): Add dumpdir.texi
	* doc/tar.texi: Document dumpdir format
	* src/incremen.c (dumpdir_locate,obstack_code_rename):
	(purge_directory): Re-implement renaming. Introduce
	'X' control code.
	(make_tmp_dir_name): Remove

	* src/transform.c (set_transform_expr,_transform_name_to_obstack):
	Implement NUMBER flag.
	(add_char_segment): Fix length assignement

	* doc/tar.texi: Update

2006-06-07  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/transform.c (transform_name_fp): Run fun even if
	_transform_name_to_obstack returns false.
	(_transform_name_to_obstack,set_transform_expr): Implement GNU
	extension case conversion operations.

	* doc/tar.texi (transform): Document the option.

2006-06-02  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update
	* src/common.h (set_transform_expr): New function
	* tests/Makefile.am: Add incr04.at
	* tests/testsuite.at: Likewise
	* tests/incr04.at: New test case
	* tests/long01.at: Fix typo in the comment
	* tests/multiv04.at: Use genfile --files-from

	(Above changes need new genfile.c from paxutils)

	* TODO: Update
	* NEWS: Update
	* doc/tar.texi: Update
	* src/transform.c: New file
	* src/Makefile.am (tar_SOURCES): New module transform.c
	* src/common.h (transform_name, transform_name_fp): New functions
	(show_stored_names_option): Renamed to
	show_transformed_names_option. All uses changed
	* src/create.c (dump_file0): Transform file name
	* src/extract.c (extract_archive): safer_name_suffix and
	stripped_prefix_len are now called by decode_header
	* src/list.c (print_header): Update displayable name selection.
	* src/tar.c: New option --transform
	New option --show-transformed-names generalizes
	--show-stored-names. The latter is retained as an alias.

2006-05-31  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c (make_directory): Fix initialization of struct
	directory.

2006-05-25  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Document use of globbing patterns.
	* src/tar.c (parse_opt): Add comment before --preserve case.

2006-05-24  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update
	* doc/tar.texi: Update
	* configure.ac (AM_INIT_AUTOMAKE): Use tar-ustar option. Raise
	version requirement to 1.9
	* src/common.h (struct name): Refactured
	(warn_regex_usage): New variable.
	(dump_file): First argument is const char*.
	(name_init,name_add): Removed
	(name_add_name,name_add_dir): New functions
	(name_next): Return const char*.
	* src/create.c: (dump_file,dump_file0): First argument is const
	char*. All callers updated.
	* src/names.c: Rewritten handling of member names in the command
	line. Tar no longer attempts to guess globbing patterns, instead
	it relies on --wildcard option.
	(init_names): Removed.
	(struct name_elt): New structure.
	(name_array): Change type to struct name_elt. All references updated
	(name_add_name,name_add_dir): New functions
	(name_next_elt): New function
	(name_next): Rewritten using name_next_elt.
	(namelist_match): Rewritten pattern matching using
	exclude_fnmatch.
	(names_notfound): Warn if globbing patterns were used without
	--wildcards option
	* src/tar.c (options): Move globbing-related options into a
	separate group. Set -l as an alias to --check-links, as required
	by UNIX98
	(struct tar_args): New fields
	wildcards,matching_flags,include_anchored
	(MAKE_EXCL_OPTIONS,MAKE_INCL_OPTIONS): New macros
	(parse_opt): Use x2nrealloc to grow archive_name_array.
	Use MAKE_EXCL_OPTIONS,MAKE_INCL_OPTIONS to create appropriate
	fnmatch options, and name_add_name,name_add_dir to handle member
	name and -C arguments.
	(decode_options): Likewise
	(main): Remove call to init_names.

	* tests/append.at, tests/append01.at, tests/extrac01.at,
	tests/options.at, tests/options02.at, tests/same-order01.at,
	tests/same-order02.at: Make AT_SETUP more readable.

2006-05-23  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/buffer.c (change_tape_menu): Fix typo (uninitialized
	variable) introduced yesterday.

2006-05-22  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Use @var{file_name} instead of @var{file name}
	* src/buffer.c (change_tape_menu): Break the loop after obtaining
	new archive name. Check for empty input line.

2006-05-15  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/atlocal.in (XFAILFILE): New variable
	* tests/version.at: Create $XFAILFILE on failure
	* tests/testsuite.at (AT_TAR_CHECK): Declare expected failure if
	$XFAILFILE exists.

2006-05-13  Sergey Poznyakoff  <gray@gnu.org.ua>

	* THANKS: Update
	* src/buffer.c (read_header0): Use read_header_primitive to avoid
	clubbering current_tar_info. All callers updated.
	* src/common.h (read_header_primitive): New function
	* src/extract.c (extract_volhdr): New function
	(prepare_to_extract): Use extract_volhdr as extractor for volume
	names.
	* src/list.c (read_header_primitive): New function
	(read_header): Front end for read_header_primitive
	* tests/chtype.at: New file
	* tests/volsize.at: New file
	* tests/Makefile.am (TESTSUITE_AT): Add chtype.at, volsize.at
	(check-full): New target.
	* tests/atlocal.in (TEST_DATA_URL,STAR_DATA_URL)
	(STAR_TESTSCRIPTS): Provide default values.
	(tarball_prereq): New function
	* tests/testsuite.at (AT_TARBALL_PREREQ): New defun
	(AT_STAR_PREREQ): Rewrite using tarball_prereq
	Include chtype.at and volsize.at
	* tests/volume.at: Add keywords.

	* tests/star/gtarfail.at, tests/star/gtarfail2.at,
	tests/star/multi-fail.at, tests/star/pax-big-10g.at,
	tests/star/ustar-big-2g.at, tests/star/ustar-big-8g.at
	(AT_STAR_PREREQ): Provide md5 sum.

	* lib/.cvsignore: Update

2006-05-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/testsuite.at (AT_SORT_PREREQ, AT_UNPRIVILEGED_PREREQ): New
	defines

	* tests/extrac04.at, tests/incr03.at, tests/listed02.at,
	tests/pipe.at, tests/rename01.at, tests/rename02.at,
	tests/rename03.at, tests/same-order01.at: Call
	AT_SORT_PREREQ. Remove fd 2 redirection after calls to sort
	* ignfail.at: Call AT_UNPRIVILEGED_PREREQ

2006-05-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	Listed incremental backups: keep more information about
	directories. Handle renamed directories more effectively
	(initial implementation, more updates to follow).
	Source tree before this point is tagged
	alpha_1_15_90_incremental_1.

        * NEWS: Update
        * configure.ac: Raise version number to 1.15.91
	* src/common.h (rename_directory,append_incremental_renames): New
	functions.
	* src/extract.c (rename_directory): New function
        * src/incremen.c (struct directory.contents, flags): New members
	(nfs,found,new): Remove. Replaced by appropriate bitmask values in
	`flags' field. All uses updated.
	(directory_meta_table): New table.
	(hash_directory): Rename to hash_directory_name
	(compare_directories): Rename to compare_directory_names
	(hash_directory_meta,compare_directory_meta,find_directory_meta):
	New functions
	(compare_dirents): Removed
        (note_directory): Get 7th argument: directory contents.
        All callers updated
        (dumpdir_locate,makedumpdir): New functions
        (scan_directory): Rewritten. Use makedumpdir to create a sorted
        dumpdir array. This makes the obstack argument unnecessary. Besides,
        ALL_CHILDREN flag is set only for new directories.
	(procdir): Change return type to struct directory. Return
	immediately if the directory was already initialized. Discover
	directory renames using directory_meta_table.
	(append_incremental_renames): New function.
        (read_directory_file, write_directory_file): Use new snapshot file
        format.
	* src/names.c (collect_and_sort_names): Update dir_contents of the
	first non-fake name entry when in listed incremental mode.

        * tests/incr03.at: New testcase
	* tests/rename01.at: New testcase
	* tests/rename02.at: New testcase
	* tests/rename03.at: New testcase
        * tests/Makefile.am: Add
	incr03.at,rename01.at,rename02.at,rename03.at
        * tests/testsuite.at: Likewise.
	* tests/listed02.at: Update for the new behavior
        * tests/multiv04.at (AT_KEYWORDS): Add missing incremental kw.

2006-05-02  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/buffer.c (try_new_volume): Attempt to continue if the name
	is apparently truncated in a GNU format volume.

	* tests/comprec.at, tests/delete01.at, tests/delete02.at,
	tests/delete04.at, tests/delete05.at, tests/extrac05.at,
	tests/listed01.at, tests/multiv01.at, tests/multiv02.at,
	tests/pipe.at, tests/same-order01.at, tests/same-order02.at,
	tests/sparse01.at, tests/sparse03.at: Always use genfile --file,
	this enables extra error checking.

	* tests/multiv03.at: Attempt to extract a member with truncated
	file name from the archive.

	* src/buffer.c (_open_archive): Remove unnecessary argument to
	check_compressed_archive.

2006-04-25  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/sparse01.at, tests/sparse02.at, tests/sparse03.at,
	tests/sparsemv.at, tests/sparsemvp.at: Skip the test if the file
	system does not support sparse files.
	* doc/tar.texi (@copying): Remove the reference to not existing
	invariant section.

2006-04-11  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/extract.c (extract_dir): Fix toggling existing directory
	permissions (Debian bug #361077). Use parts of patch provided by
	Ian Jackson <iwj@ubuntu.com>.
	* src/compare.c: Minor changes
	* src/incremen.c (directory.new): New member
	(note_directory,find_directory: Use make_directory to create
	struct directory entries
	(procdir): Avoid duplicating  directories in the incremental
	backup map.
	* tests/Makefile.am (TESTSUITE_AT): Add extrac06.at
	* tests/testsuite.at: Include extrac06.at

2006-03-18  Ralf Wildenhues  <Ralf.Wildenhues@gmx.de> (trivial change)

	* tests/atlocal.in (PATH): Add build-aux from the source tree,
	not the build tree.

2006-03-13  Sergey Poznyakoff  <gray@gnu.org.ua>

	* THANKS: Add Benno Schulenberg

2006-03-13  Jim Meyering <jim@meyering.net>

	* tests/listed02.at:  Sort the two lines of stderr from the
	first `tar -v --listed-incremental'.  They would come out
	reversed and provoke a test failure on a tmpfs
	file system.

2006-03-13  Benno Schulenberg <benno@nietvergeten.nl>

	* doc/tar.texi: Minor fixes.
	* src/tar.c (options): Consistently begin help messages with a
	lowercase letter.

2006-03-12  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/Makefile.am (AM_CPPFLAGS): Define LOCALEDIR

2006-03-07  Paul Eggert  <eggert@cs.ucla.edu>

	* src/buffer.c (record_buffer_aligned): New var.
	(init_buffer): Use it to ensure that the buffer is aligned.
	This doesn't result in any measurable performance improvement
	on my host (Debian GNU/Linux 3.1 stable, with default block size),
	but I assume it does help on some hosts.

	* lib/.cvsignore: Sort.

2006-03-04  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/shortrec.at: Use -f - to read from stdin.

2006-02-21  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Fix typo: --to-command instead of --to-program

2006-02-20  Paul Eggert  <eggert@cs.ucla.edu>

	* tests/multiv04.at (split directory members in a MV archive):
	Don't use %X in an awk printf format; this doesn't work with
	Solaris 10 /usr/bin/awk.  Use %x instead.

2006-02-20  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/create.c (split_long_name): Fix maximum length estimation.
	Patch by Jim Lowe.
	* tests/Makefile.am (lustar01.at,lustar02.at,lustar03.at): New
	tests.
	* tests/atlocal.in: Add build-aux to the PATH
	* tests/long01.at: Remove mkhier, use AT_TAR_MKHIER instead
	* tests/longv7.at: Reword test title
	* tests/lustar01.at: New test
	* tests/lustar02.at: New test
	* tests/lustar03.at: New test
	* tests/testsuite.at (AT_TAR_MKHIER): New macro
	(lustar01.at,lustar02.at,lustar03.at): New tests.

2006-02-20  Paul Eggert  <eggert@cs.ucla.edu>

	* bootstrap: Don't claim lib/Makefile.am is generated automatically
	from itself.

	Avoid installation glitches on Solaris 8 with Sun C 5.4.
	* lib/.cvsignore: Add system-ioctl.h.
	* lib/Makefile.tmpl (noinst_HEADERS): Add system-ioctl.h.
	* src/buffer.c: Include system-ioctl.h.
	* src/compare.c: Likewise.
	* src/delete.c: Likewise.
	* src/system.c: Include <getline.h>, <setenv.h>.
	* src/tar.c: Include <getline.h>.

2006-02-19  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/buffer.c (add_chunk_header): Free st.orig_file_name after
	calling	finish_header().
	(new_volume): Prompt the user for archive name if unable to open
	next archive.

	* src/create.c (dump_file0): Restore file_count_links,
	accidentally removed on 2005-11-29.
	* configure.ac: Raise version number to 1.15.90
	* NEWS: Likewise.

2006-02-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (tar_set_quoting_style): Provide second argument to
	the format spec: program_invocation_short_name. Reported by Jim
	Meyering.

2006-02-07  Paul Eggert  <eggert@cs.ucla.edu>

	* gnulib.modules: Add closeout, exitfial.
	* lib/.cvsignore: Add __fpending.c, __fpending.h, closeout.c,
	closeout.h.
	* src/buffer.c: Incluse closeout.h.
	(_open_archive): Use freopen rather than fopen, so
	that stdlis is always either stdout or stderr.  Use
	close_stdout_set_file_name to report its name.
	* src/tar.c: Include closeout.h and exitfail.h.
	(parse_opt, usage): Call close_stdout as appropriate, to check for
	write errors.
	(decode_options): Exit with status TAREXIT_FAILURE, not 1.
	(main): Set exit_failure, to exit with proper status on memory
	allocation failure and the like.
	Use close_stdout rather than rolling our own test.

	* NEWS: --version now outputs copyright etc., to conform to the
	GNU coding standards.  Remove --license.
	* gnulib.modules: Add version-etc-fsf.
	* doc/tar.texi: Document the change.
	* lib/.cvsignore: Add version-etc-fsf.c, version-etc.c, version-etc.h.
	* scripts/Makefile.am (SED_CMD): Update PAKCAGE_NAME, not PACKAGE.
	* scripts/backup.in: Remove --license.  Change --version to conform
	to GCS.
	* scripts/restore.in: Likewise.
	* scripts/backup.sh.in (license): Output briefer license in the
	style of coreutils, for consistency with other changes.
	* src/tar.c: Include <version-etc.h>.
	(LICENSE_OPTION): Remove.
	(options): Remove --license.
	(license): Remove.
	(parse_opt): Use version_etc instead of rolling it ourselves.
	Remove --license.
	* tests/version.at (tar --version): Check only the first line of
	output.

	* ChangeLog, NEWS, src/common.h, src/extract.c, src/incremen.c:
	* src/list.c, src/names.c, src/tar.h, src/xheader.c:
	Update copyright year to 2006.

2006-02-07  Jim Meyering  <jim@meyering.net>

	* src/xheader.c (sparse_map_decoder): Fix misleading diagnostic.

2006-01-31  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/common.h (get_gnu_dumpdir): Remove prototype
	(is_dumpdir): New function
	* src/extract.c (prepare_to_extract): Use is_dumpdir member to
	check for dumpdirs.
	* src/incremen.c (get_gnu_dumpdir): Static
	(is_dumpdir): New function
	(purge_directory): Use is_dumpdir
	* src/list.c (list_archive): Use is_dumpdir
	Do not wrap skip_member in mv_begin/mv_end, the function itself
	takes care of it.
	(decode_header): Set stat_info->is_dumpdir
	(skip_member): Do nothing if skipped is true
	* src/tar.h (struct tar_stat_info): New members is_dumpdir and skipped.

2006-01-22  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (decode_options): Refuse using --delete with
	compression options.

2006-01-18  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Updated.
	* configure.ac (DEFAULT_QUOTING_STYLE): New configuration variable
	* doc/tar.texi: Initial documentation for --quoting-style,
	--quote-chars and --no-quote-chars option.
	* src/tar.c: Implement new options --quoting-style, --quote-chars
	and --no-quote-chars.

2006-01-09  Paul Eggert  <eggert@cs.ucla.edu>

	* bootstrap: Default to pserver, and switch to cvs.sv.gnu.org,
	to accommodate recent changes to the GNU CVS server.
	* lib/.cvsignore: Add argp-pin.c, mkdirat.c, openat-priv.h.

2005-12-14  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/names.c (name_scan): Take an additional argument requesting
	exact matching.
	* src/common.h (name_scan): Change prototype.
	* src/delete.c, src/incremen.c, src/update.c: Update invocations
	of name_scan.

2005-12-13  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/common.h (struct name): New member `explicit'. Remove unused
	member `isdir'.
	* src/incremen.c (procdir): If name_scan() returns something,
	check if it was explicitely given in the command line
	* src/names.c (addname,add_hierarchy_to_namelist): Initialize
	explicit member appropriately.

	* src/incremen.c (procdir): If --one-file-system is given and a
	directory is found to be on another device, *and* this directory
	is explicitely given in the command line, then do not omit it.

2005-12-11  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Update
	* doc/tar.texi: Document --delay-directory-restore option.
	(Configuring Help Summary): Document usage of ARGP_HELP_FMT
	variable to customize help output.
	* src/common.h (delay_directory_restore_option): New global.
	* src/extract.c (directories_first): Replaced by
	delay_directory_restore_option. All uses changed.
	* src/tar.c (options,parse_opt): New options
	--delay-directory-restore and --no-delay-directory-restore

2005-12-09  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/buffer.c (open_archive): Add default case to shut up gcc.
	* src/common.h (set_file_atime): Add prototype.
	* src/create.c (to_chars_subst): Remove unused variable
	Make sure useful result code is returned.
	* src/incremen.c (read_directory_file): Fix format string
	Thanks Eric Blake for reporting.

2005-12-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi (Current status): Renamed to 'Changes' and moved to
	appendices.
	(Large or Negative Values): Rewritten
	* src/common.h (gid_to_chars, major_to_chars, minor_to_chars)
	(mode_to_chars, off_to_chars, size_to_chars, time_to_chars)
	(uid_to_chars, uintmax_to_chars): Return bool
	* src/create.c (gid_to_chars, major_to_chars, minor_to_chars)
	(mode_to_chars, off_to_chars, size_to_chars, time_to_chars)
	(uid_to_chars, uintmax_to_chars): Return bool
	(to_chars): Return bool
	(start_header): Check return values of convertion routines. Fail
	if unable to store data in the header.

2005-12-07  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Following the discussion with Karl Berry,
	discontinue using @value{} substitutions for Texinfo commands.
	Properly index all long options. Print a
	separate long option index.
	* doc/value.texi: Remove @set's

	* doc/tar.texi: Update --info-script documentation
	Resolve some more FIXMEs.
	* scripts/dump-remind.in: Use TAR_VOLUME instead of reading volno
	file.
	* src/buffer.c (new_volume): Update invocation
	(change_tape_menu): New function. Disable '!' command if given
	--restrict option.
	* src/common.h (sys_exec_info_script): Update declaration
	(restrict_option): New global
	* src/system.c (sys_exec_info_script): The script can supply new
	archive name to use by writing it to file descriptor 3.
	* src/tar.c (options): Add --restrict option. Use macros for
	option grouping.
	(license): Print full list of copyright years
	* NEWS: Update

2005-12-06  Eric Blake  <ebb9@byu.net> (trivial changes)

	* configure.ac (DENSITY_LETTER): Fix m4 overquoting.
	* .cvsignore: Ignore .bootstrap.

2005-12-06  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Document --to-command and --info-script
	options. Add missing xrefs.
	* src/buffer.c (new_volume): Use sys_exec_info_script() instead of
	system().
	* src/common.h (archive_format_string,subcommand_string)
	(sys_exec_info_script): New prototypes.
	* src/system.c (sys_exec_info_script): New function.
	* src/tar.c (archive_format_string): Remove static qualifier.
	(subcommand_string): New function.

2005-12-01  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/extract.c: Fix restoring of directory timestamps from
	incremental archives.
	(directories_first): New variable.
	(prepare_to_extract): Set directories_first
	(extract_archive): Call apply_nonancestor_delayed_set_stat() only
	if not extracting from an incremental archive
	(extract_dir): Obtain root_device here, to make sure it works
	correctly with -C.

	* src/incremen.c (purge_directory): Skip the member and return if
	the archive is not in incremental format.
	* tests/incr02.at: New testcase
	* tests/Makefile.am: Add incr02.at
	* tests/testsuite.at: Likewise

	* THANKS: Add Guerkan Karaman.
	* NEWS: Update

2005-11-30  Paul Eggert  <eggert@cs.ucla.edu>

	* doc/tar.texi (Option Summary): Rewrite the
	--atime-preserve=system description in response to Ian Turner's
	proposed patch.

2005-11-30  Ian Turner  <ian@zmanda.com>

	* doc/tar.texi (Extracting Specific Files): Remove obsolescent
	FIXME.

2005-11-29  Paul Eggert  <eggert@cs.ucla.edu>

	* NEWS: New option --atime-preserve=system, which uses O_NOATIME.
	* THANKS: Add Ian Turner.

	* configure.ac: Prefer AC_CHECK_HEADERS_ONCE to AC_CHECK_HEADERS.
	Check for stropts.h and sys/filio.h too, for _FIOSATIME.
	* doc/tar.texi: Change "modification time" to "data modification
	time", "change time" to "status change time", and "filesystem" to
	"file system", so that we use terminology consistent with POSIX.
	Use American spacing rather than French for sentence ends.
	"non-dependable" -> "undependable".
	(Option Summary, Attributes): Explain better the pitfalls of the
	--atime-preserve option, and suggest read-only mounts,loopback
	mounts, and noatime mounts for older systems.
	* doc/value.texi (op-atime-preserve-system): Renamed from
	op-atime-preserver-system to fix a misspelling.
	* src/common.h (enum atime_preserve): Use lower case for enum values.
	* src/compare.c: Don't include utimens.h; no longer needed.
	(diff_file): Use set_file_atime rather than utimens; avoid closing
	diff_handle until after this, so that we can set the file time stamp
	via the file descriptor rather than via its name.
	* src/create.c: Don't include utimens.h; no longer needed.
	(dump_regular_finish): Remove.  All callers now do its work inline.
	(dump_dir): New arg FD.  All callers changed.
	Use fdsavedir rather than savedir.
	(unknown_file_error): Arg is a const pointer now.
	(dump_file0): 2nd arg is a const pointer now.
	Treat directories more like files, with respect to --atime-preserve.
	For example, also warn if a directory changes while we are dumping it.
	Prefer file descriptors to file names when retrieving/setting file
	attributes; this saves path-resolution time and allows us to avoid
	changing mtime/ctime on Solaris when restoring atime as root.
	Use O_DIRECTORY when opening directories, to avoid some race conditions.
	Do not reset atime if mtime has changed.  Report an error if
	we cannot reset atime.

	* lib/.cvsignore: Add malloc.h, regcomp.c, regex.c, regex.h,
	regex_internal.c, regex_internal.h, regexc.c; used by rpmatch.

2005-11-29  Ian Turner  <ian@zmanda.com>

	First cut at adding support for --atime-preserve=system.
	* doc/tar.texi (Option Summary): First cut at documenting it.
	All other uses of --atime-preserve changed to --atime-preserve=replace.
	* doc/value.texi (op-atime-preserve-replace, op-atime-preserver-system):
	New.
	(op-atime-preserve): Mention METHOD.
	* src/common.h (atime_preserve): New enum.
	(atime_preserve_option): Now of the enum type rather than bool.
	All uses changed.
	* src/compare.c (diff_file): Read with O_NOATIME if asked for.
	* src/create.c (dump_file0): Read regular and CTG files with O_NOATIME
	if asked for.
	* src/tar.c (usage): Mention new usage.
	(parse_opt): Parse new usage.

2005-11-29  Paul Eggert  <eggert@cs.ucla.edu>

	* THANKS: Convert back to UTF-8, sort (using LC_ALL=C on Debian
	stable), and consistently use tabs rather than spaces.

2005-11-27  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/xheader.c: Remove parts of code prematurely introduced
	yesterday. Thanks Eric Blake.

2005-11-26  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/xheader.c (xheader_format_name): Fix memory leak.

2005-11-11  Sergey Poznyakoff  <gray@gnu.org.ua>

	* gnulib.modules: Add rpmatch
	* lib/stdopen.h, lib/stdopen.c: New file. Imported from coreutils.
	* lib/Makefile.tmpl: Add stdopen.h, stdopen.c
	* po/POTFILES.in: Add rpmatch.c
	* src/tar.c (confirm): Rewritten using rpmatch.
	(decode_options): Minor optimizations
	(main): Call stdopen() to ensure the first three descriptors are
	open.

	* tests/multiv01.at, tests/multiv02.at, tests/multiv03.at,
	tests/multiv04.at, tests/sparsemv.at, tests/sparsemvp.at,
	tests/star/multi-fail.at: Close stdin so that if something fails
	causing tar to ask for the next volume, it won't hang the
	testsuite.

	* src/buffer.c (flush_write,flush_read): Change data type.
	(flush_archive): Compute actual buffer fill level before calling
	low level function.
	(close_archive): Call flush_archive again if the first call
	resulted in partially filled buffer.
	(try_new_volume): Rewritten handling of initial headers.
	(add_chunk_header): New function. Write an additional header
	before the continuation chunk. The purpose of the header is to
	allow third-party tars to extract the member.
	(simple_flush_write): Take an argument.
	(_gnu_flush_write): Correctly handle partially filled buffers.
	* src/common.h (flush_read,flush_write): Functions, again.
	(write_extended): Changed declaration
	(xheader_format_name): New declaration
	* src/create.c (write_extended): Change type and meaning of
	the first argument. All callers updated
	* src/xheader.c (xheader_format_name): Remove static
	qualifier. Change last argument.
	Correct buffer size calculation (allocated too much space).
	(xheader_write): Increase global_header_count here ...
	(xheader_write_global): ... instead of here

	* tests/testsuite.at (AT_TAR_CHECK): Define TEST_TAR_FORMAT
	* tests/multiv01.at: Update
	* tests/multiv02.at: Update
	* tests/multiv03.at: Update
	* tests/sparsemvp.at: Update
	* tests/star/multi-fail.at: Update

	* scripts/tarcat: Handle archives in pax format. Improve handling
	of traditional archives.
	* doc/tar.texi (Tarcat): New node

2005-11-10  Sergey Poznyakoff  <gray@gnu.org.ua>

	Fix splitting of sparse files between the volumes.

	* src/buffer.c (try_new_volume): Bugfix. Always check
	continued_file_name. If it is absent, the volume is out
	of sync.
	(add_multi_volume_header): Create GNU.volume.filename keyword in
	the extended header.
	* src/sparse.c (sparse_dump_region): Call mv_size_left.
	(sparse_dump_file): Enclose the loop in mv_begin/mv_end.
	* src/system.c: Do not pad compressed output if it goes to
	stdout.
	* src/xheader.c (xhdr_tab): New keyword GNU.volume.filename.

	* tests/sparsemv.at: New testcase
	* tests/sparsemvp.at: New testcase
	* tests/Makefile.am: Add sparsemv.at and sparsemvp.at.
	* tests/testsuite.at: Likewise.

2005-11-09  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/buffer.c: Rewritten in a more modular fashion to provide
	GNU extensions (multi-volume archives and archive labels) in
	pax format.
	NOTICE, that some of the aspects (e.g. splitting the archive
	on the extended header boundary) are still not solved, others
	(splitting a sparse file between the volume) require additional
	testing. Wait for the next commit.

	(volume_label,continued_file_name,continued_file_size)
	(continued_file_offset): New globals.
	(save_name,save_totsize,save_sizeleft): Make static
	(mv_begin,mv_end,mv_total_size,mv_size_left): New functions
	(open_archive,flush_write,flush_read): Rewritten

	* src/common.h (save_name,save_sizeleft,save_totsize): Remove
	globals.
	(volume_label,continued_file_name,continued_file_size): New
	variables.
	(flush_read,flush_write): Pointers to functions
	(mv_begin,mv_end,mv_total_size,mv_size_left): New functions
	(write_extended): New function.

	* src/compare.c, src/create.c, src/extract.c, src/incremen.c,
	src/list.c: Use mv_.* functions uniformly instead of fiddling
	with the global variables.
	* src/sparse.c: Use mv_.* functions where necessary.
	* src/tar.c (decode_options): Allow to use --multi-volume and
	--label with pax archives.
	* src/xheader.c (xhdr_tab): Support for new GNU keywords.

	* tests/delete01.at, tests/delete02.at, tests/delete03.at,
	tests/delete04.at, tests/delete05.at, tests/extrac01.at,
	tests/extrac02.at, tests/extrac03.at, tests/extrac04.at,
	tests/extrac05.at, tests/incr01.at, tests/incremental.at,
	tests/listed01.at, tests/listed02.at, tests/long01.at,
	tests/longv7.at, tests/multiv01.at, tests/multiv02.at,
	tests/multiv03.at, tests/multiv04.at, tests/options.at,
	tests/options02.at, tests/same-order01.at, tests/same-order02.at,
	tests/sparse01.at, tests/sparse02.at, tests/sparse03.at,
	tests/star/multi-fail.at (AT_KEYWORDS): Improve to allow execution
	of related tests in groups.

	* doc/tar.texi: Update

2005-11-07  Paul Eggert  <eggert@cs.ucla.edu>

	* src/xheader.c (struct xhdr_tab.coder): Last arg is void const *,
	not void *, to avoid create.c warning from GCC "passing argument 3
	of 'xheader_store' discards qualifiers from pointer target type".
	(dummy_coder, atime_coder, gid_coder, gname_coder, linkpath_coder):
	(ctime_coder, mtime_coder, path_coder, size_coder, uid_coder):
	(uname_coder, sparse_size_coder, sparse_numblocks_coder):
	(sparse_offset_coder, sparse_numbytes_coder, dumpdir_coder):
	(xheader_store): Likewise.
	* src/common.h (xheader_store): Likewise.

2005-11-07  Sergey Poznyakoff  <gray@gnu.org.ua>
       and  Paul Eggert  <eggert@cs.ucla.edu>

	* src/tar.c (NS_PRECISION_FORMAT_MASK): New macro.
	(tar_timespec_cmp): New function. Wrapper over
	timespec_cmp using the timespec precision provided by the
	current archive format.
	* src/common.h (tar_timespec_cmp): New declaration.
	* src/compare.c (diff_file): Use tar_timespec_cmp.
	* src/extract.c (file_newer_p): Likewise.
	* src/update.c (update_archive): Likewise.
	* tests/truncate.at: Reverted changes
	* tests/update.at: Reverted changes

2005-11-07  Sergey Poznyakoff  <gray@gnu.org.ua>

	Support for incremental formats in pax archives.
	Fixed POSIX compatibility of `sparse' extended header keywords.

	* src/common.h (dumpdir_size,get_gnu_dumpdir)
	(xheader_string_begin,xheader_string_add)
	(xheader_string_end): New functions.
	* src/create.c (dump_dir0): Handle incremental backups in pax
	archives.
	* src/incremen.c (dumpdir_size, get_gnu_dumpdir): New functions.
	(purge_directory): Use stat_info.dumpdir instead of getting its
	value explicitely.
	* src/list.c (list_archive): Handle incremental backups in pax
	format.
	(decode_header): Initialize stat_info.dumpdir
	* src/sparse.c (sparse_diff_file): Bugfix: set seekable.
	(pax_dump_header): Store sparse map in GNU.sparse.map. If this
	variable has been explicitely deleted, use GNU.sparse.offset/
	GNU.sparse.numbytes variables.
	* src/tar.c (decode_options): Incremental options are allowed with
	--format=pax
	(tar_stat_destroy): Free dumpdir
	* src/tar.h (struct tar_stat_info.dumpdir): New member.
	* src/xheader.c (xheader_keyword_deleted_p): Remove static
	qualifier.
	(struct xhdr_tab.decoder): Change prototype. POSIX allows string
	values to contain embedded nulls, so take an extra argument
	specifying the length of the string.
	(decx,decg,dummy_decoder,atime_decoder,gid_decoder)
	(gname_decoder,linkpath_decoder,ctime_decoder,mtime_decoder)
	(path_decoder,size_decoder,uid_decoder,uname_decoder)
	(sparse_size_decoder,sparse_numblocks_decoder)
	(sparse_offset_decoder,sparse_numbytes_decoder): Likewise.
	(decode_record): Pass value length to the handler
	(run_override_list): Pass value length to the decoder
	(xheader_print_n): New function
	(xheader_print): Rewritten using xheader_print_n
	(xheader_finish): Do not rely om strlen to compute the length of
	the collected string: it can contain embedded nulls
	(xheader_string_begin,xheader_string_add,xheader_string_end): New
	functions.
	(sparse_map_decoder,dumpdir_coder,dumpdir_decoder): New
	functions. Handle GNU.sparse.map and GNU.dumpdir variables.
	(xhdr_tab): Add new variables.

	* tests/incr01.at: Test gnu, oldgnu, and posix formats
	* tests/incremental.at: Likewise

2005-11-06  Paul Eggert  <eggert@cs.ucla.edu>

	* NEWS: Minor language and white space fixes.

	* tests/truncate.at: Create files whose time stamps must fall on
	1-second boundaries.  This prevents tests from failing on hosts
	like Solaris 8 that have nanosecond-resolution file time stamps.
	* tests/update.at: Likewise.

	* src/xheader.c (strtoimax, strtoumax): Remove decls; now done
	in system.h.

2005-11-06  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Properly document incremental dumps
	* doc/value.texi: Likewise.
	* doc/snapshot.texi: Likewise.

2005-11-05  Sergey Poznyakoff  <gray@gnu.org.ua>

	Improve listed incremental format:

	* src/common.h (update_parent_directory): New prototype.
	* src/create.c (dump_file): Call update_parent_directory.
	* src/incremen.c (struct directory.mtime): New member.
	(note_directory): Take additional arguments. All callers updated.
	(scan_directory): Updated to use more metadata. In particular,
	this allows to correctly detect renamed files.
	(read_directory_file,write_directory_file)
	(write_directory_file_entry): Support new directory file format.
	* tests/listed01.at: Sleep 1 sec before creating second file.
	* tests/listed02.at: Never skip the test. It should work on any
	filesystem.

	* doc/snapshot.texi: New file
	* doc/tar.texi: Update.
	* doc/Makefile.am: Update.

2005-11-04  Paul Eggert  <eggert@cs.ucla.edu>

	* src/extract.c (set_stat): Rewrite to avoid bug in Forte
	Developer 7 C 5.4 Patch 111708-09 (2004-02-19).

2005-11-04  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap: Fix quoting in help output.
	(update_po): Use backward-compatible wget option --cache instead
	of deprecated -C to accomodate for wget 1.10.
	Changes proposed by Eric Blake
	* THANKS: Add Eric Blake

2005-11-02  Paul Eggert  <eggert@cs.ucla.edu>

	* doc/tar.texi: Consistently put two spaces after sentences,
	and put commas after "i.e." and "e.g.".  This is the usual GNU
	style in manuals.

	* lib/.cvsignore: Add creat-safer.c, fcntl--.h, fcntl-safer.h,
	open-safer.c, openat-die.c, verify.h, to accommodate recent gnulib
	changes.

2005-10-27  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/compare.c (diff_dumpdir): Pass a valid device number to
	get_directory_contents.

	* THANKS: Add John Thomas McDole

	* bootstrap: If file `.bootstrap' exists in the cwd and is
	readable, prepend its contents to the command line

2005-10-21  Sergey Poznyakoff  <gray@gnu.org.ua>

	* tests/link01.at: Skip test if ln fails (suppose the OS does
	not support hard links).

2005-10-04  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/tar.c (decode_options): Report error if -A or -r is used
	together with compression option.

2005-09-29  Sergey Poznyakoff  <gray@gnu.org.ua>

	* doc/tar.texi: Use @option and @kbd consistently.
	Document new options.

2005-09-28  Sergey Poznyakoff  <gray@gnu.org.ua>

	* NEWS: Updated
	* src/common.h (show_stored_names_option): New variable
	* src/list.c (print_header): If show_stored_names_option is given,
	list member names as stored in the archive. Patch proposed by Erik
	Cumps <erik.cumps@icos.be>
	* src/tar.c: Implement --show-stored-names option

	* src/common.h (test_label_option): New variable;
	* src/list.c (print_header): Special handling if test_label_option
	is set.
	* src/names.c (all_names_found): If test_label_option is set
	return true.
	* src/tar.c: New option --test-label tests the archive volume
	label. The option proposed by Wouter Verhelst <wouter@nixsys.be>

2005-09-21  Paul Eggert  <eggert@cs.ucla.edu>

	* tests/Makefile.am (clean-local): Don't attempt to run
	$(TESTSUITE) if it doesn't exist.  Problem reported by
	Eric Blake.

2005-09-16  Paul Eggert  <eggert@cs.ucla.edu>

	Don't filter time stamps through the resolution supported
	by struct stat; keep them to full nanosecond resolution.
	This affects behavior only on older hosts or file systems
	that have lower-resolution time stamps.
	* src/common.h (OLDER_STAT_TIME): Parenthesize arg.
	(OLDER_TAR_STAT_TIME): New macro.
	(code_timespec): New function.
	(BILLION, LOG10_BILLION, TIMESPEC_STRSIZE_BOUND): New constants.
	* src/compare.c (diff_file): Use full time stamp resolution.
	* src/create.c (start_header, dump_file0): Likewise.
	(start_header, dump_file0): Adjust to new structure layout.
	(dump_regular_finish): Simplify by using timespec_cmp.
	* src/extract.c (struct delayed_set_stat): Don't store stat info
	that we don't need, to save space.  All uses changed.
	(struct delayed_set_stat, struct delayed_link, file_newer_p):
	(create_placeholder_file, extract_link, apply_delayed_links):
	Use full time stamp resolution.
	(check_time): Use code_timespec rather than rolling our own code.
	(set_stat, delay_set_stat): Arg now points to tar_stat_info to
	avoid losing time information.  All callers changed.
	* src/list.c (read_and, decode_header, print_heaeder):
	Use full time stamp resolution.
	* src/misc.c (code_timespec): New function.
	* src/tar.h (struct tar_stat_info): Record atime, mtime, ctime
	separately, for benefit of hosts with lower resolution.
	* src/update.c (update_archive): Use full time stamp resolution.
	* src/xheader.c (code_time): Use new code_timespec function
	to simplify code.
	(atime_coder, atime_decoder, ctime_coder, ctime_decoder):
	(mtime_coder, mtime_decoder): Use full time stamp resolution.

	Report time stamps to full resolution in environment.
	Report memory allocation failures rather than ignoring them.
	* src/system.c (time_to_env): New function.
	(oct_to_env, str_to_env, chr_to_env): Report memory allocation failures.
	(stat_to_env): Report full resolution in time stamps.

2005-09-16  Paul Eggert  <eggert@cs.ucla.edu>

	Merge changes from gnulib for file system sub-second time stamps.
	* configure.ac: Remove checks for struct stat.st_spare1, struct
	stat.st_atim.tv_nsec, struct stat.st_atimespec.tv_nsec, struct
	stat.st_atimensec, as gnulib now does this for us.
	Similarly for LIB_CLOCK_GETTIME.
	* gnulib.modules: Add stat-time.
	* lib/.cvsignore: Add stat-time.h.
	* src/common.h: Include stat-time.h.
	(timespec_lt): Remove.  All callers changed to use timespec_cmp.
	(get_stat_atime, get_stat_ctime, get_stat_mtime):
	(set_stat_atime, set_stat_ctime, set_stat_mtime):
	Remove; now defined by stat-time.h.

2005-09-14  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c (list_dumpdir): New function. Used to dump
	contents of GNUTYPE_DUMPDIR blocks.
	* src/common.h (list_dumpdir): Likewise.
	* src/list.c (list_archive): Use list_dumpdir() to display
	GNUTYPE_DUMPDIR blocks. Do that only if two or more -v options are
	given.

2005-09-12  Paul Eggert  <eggert@cs.ucla.edu>

	* lib/.cvsignore: Adjust to current gnulib and modules used.
	Add getdelim.c, getdelim.h, mbchar.c, mbchar.h, mbuiter.h, memchr.c,
	pipe-safer.c, size_max.h, strdup.c, strdup.h, strnlen.h, strnlen1.c,
	strnlen1.h, unistd--.h.
	Remove getndelim2.c, getndelim2.h, pathmax.h, sysexits.h, xstrdup.c.

	Treat fishy-looking hard links like fishy-looking symlinks.
	* src/extract.c (struct delayed_set_stat): Rename after_symlinks
	member to after_links.  All uses changed.
	(struct delayed_link): Renamed from struct delayed_symlink.
	All uses changed.  New member is_symlink.
	(delayed_link_head): Renamed from delayed_symlink_head.  All uses
	changed.
	(create_placeholder_file): New function, taken from extract_symlink.
	(extract_link): Create placeholders for fishy-looking hard links.
	(extract_symlink): Move code into create_placeholder_file.
	(apply_delayed_links): Renamed from apply_delayed_symlinks.
	All uses changed.  Create both hard links and symlinks.

2005-09-03  Paul Eggert  <eggert@cs.ucla.edu>

	* README-alpha: Modernize description of software required for
	developers.

2005-09-03  Sergey Poznyakoff  <gray@gnu.org.ua>

	* gnulib.modules: Add strdup
	* src/incremen.c (purge_directory): Do not dereference symbolic
	links. Bug reported by Ralph Corderoy <ralph@inputplus.co.uk> and
	David Brown <davidb@davidb.org>
	* tests/incr01.at: New test.
	* tests/Makefile.am: Add incr01.at
	* tests/testsuite.at: Likewise
	* THANKS: Updated

2005-08-17  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/incremen.c (read_directory_file): Use strtoumax to read
	snapshot file contents.
	(write_directory_file_entry): Use umaxtostr().

2005-07-31  Sergey Poznyakoff  <gray@gnu.org.ua>

	* src/create.c (file_dumpable_p,dump_file0): Fix handling of
	sparse files to /dev/null with --totals option.
	* tests/update.at: Remove dependency on file order.

2005-07-08  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* doc/tar.texi: Fix typo.

2005-07-07  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* tests/pipe.at: Pipe the output from `tar xfv' through sort.

2005-06-25  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/sparse.c (tar_sparse_init): Fill structure with zeros. Call
	sparse_select_optab(). All callers updated.
	(sparse_member_p, sparse_fixup_header): Use tar_sparse_init().

2005-06-23  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/sparse.c (pax_sparse_member_p): Checking member size
	vs. file size is not reliable enough. Use sparse_map_avail.

	* tests/star/gtarfail.at: Adapt to the new output format
	* tests/star/gtarfail2.at: Likewise
	* tests/star/multi-fail.at: Likewise
	* tests/star/pax-big-10g.at: Likewise
	* tests/star/ustar-big-2g.at: Likewise
	* tests/star/ustar-big-8g.at: Likewise

	* tests/sparse03.at: New test.
	* tests/Makefile.am: Add sparse03.at
	* tests/testsuite.at: Likewise

	* src/xheader.c (size_decoder): Do not set archive_file_size.

	Fix bugs introduced yesterday:

	* src/sparse.c (tar_sparse_init):  Initialize
	dimped_size to 0.
	(sparse_scan_file): Initialize archive_file_size to 0. The
	variable keeps size of the file *as stored in the archive*, not
	the size reported by stat.

2005-06-22  Paul Eggert  <eggert@cs.ucla.edu>

	A sweep of the sparse code prompted by a bug report by Jim Meyering.
	* src/sparse.c: Include <inttostr.h>.
	(struct tar_sparse_file): offset and dumped_size are off_t, not
	size_t.  optab is now const *.
	(dump_zeros): Return bool success flag, not off_t.
	All callers changed.
	Use a constant-zero buffer rather than clearing a buffer each time.
	Don't mess up if write fails.
	(dump_zeros, check_sparse_region):
	Don't assume off_t is no wider than size_t.
	(tar_sparse_init): Don't bother clearing a field that is already clear.
	(zero_block_p): First arg is const *, not *.
	(clear_block, SPARSES_INIT_COUNT): Remove.
	(sparse_add_map): First arg is now struct start_stat_info *, not
	struct tar_sparse_file *.  All callers changed.
	Use x2nrealloc to check for size_t overflow.
	(parse_scan_file): Cache commonly-used parts of file.
	Use an auto buffer, not a static one.
	Don't bother clearing the buffer; not needed.
	Don't bother clearing items that are already clear.
	(oldgnu_optab, star_optab, pax_optab): Now const.
	(sparse_dump_region): Don't bother clearing the buffer before
	reading into it; just clear the parts that aren't read into.
	(sparse_dump_file): Clear the whole local variable 'file'.
	(diff_buffer): Remove; now a local var.
	(check_sparse_region): Don't bother clearing buffer before
	reading into it.  Don't assume off_t is promoted to long.
	(oldgnu_get_sparse_info, star_get_sparse_info):
	Use an auto status, not static.
	* src/tar.h (struct tar_stat_info): had_trailing_slash is
	now bool, not int.
	* src/xheader.c (sparse_offset_coder, sparse_numbytes_coder):
	Rewrite to avoid cast.
	(sparse_offset_decoder, sparse_numbytes_decoder):
	Diagnose excess entries rather than crashing.

2005-06-22  Jim Meyering  <jim@meyering.net>

	* src/common.h (timespec_lt): Add a return type: bool.

2005-06-21  Paul Eggert  <eggert@cs.ucla.edu>

	Further improvements inspired by Jim Meyering's fixes.

	* NEWS: Better support for full-resolution time stamps.
	The -v option now prints time stamps only to 1-minute resolution.
	* gnulib.modules: Add utimens.
	* lib/.cvsignore: Add imaxtostr.c, inttostr.c, inttostr.h,
	offtostr.c, umaxtostr.c, utimens.c, utimens.h.  Remove paxconvert.c.
	* lib/Makefile.tmpl (libtar_a_SOURCES): Remove paxconvert.c.
	* lib/paxconvert.c: Remove; superseded by umaxtostr.c.
	* po/POTFILES.in: Remove lib/paxconvert.c.  Add lib/xalloc-die.c,
	lib/obstack.c.
	* src/buffer.c (set_start_time, compute_duration, start_time):
	Use gettime rather than rolling our own code.
	* src/common.h (OLDGNU_NAME_FIELD_SIZE, MAXOCTAL11, MAXOCTAL7): Remove.
	(newer_ctime_option): Remove.
	(timespec_lt): New function.
	(OLDER_STAT_TIME): Use it.
	(string_to_chars): First arg is char const *, not char *.
	(tartime): Time arg is now struct timespec.  New bool arg.
	All callers changed.
	(code_ns_fraction): New decl.
	(sys_stat_nanoseconds): Remove decl.
	(get_stat_atime, get_stat_ctime, get_stat_mtime): New functions.
	(set_stat_atime, set_stat_ctime, set_stat_mtime): New functions.
	* src/compare.c: Include utimens.h rather than rolling our own.
	(diff_dir, diff_file, diff_link, diff_symlink, diff_special):
	Prototype.
	(diff_dumpdir, diff_multivol): Prototype.
	(diff_file): Support higher-resolution time stamps.
	* src/create.c: Include utimens.h rather than rolling our own.
	(MAX_OCTAL_VAL): New macro.
	(tar_copy_str, string_to_chars): Don't bother to zero-fill;
	the destination is already zeroed.
	(string_to_chars): First arg is char const *.
	(start_private_header): Use MINOR_TO_CHARS, not MAJOR_TO_CHARS,
	for minor device number.
	(write_header_name, dump_hard_link, dump_file0):
	Simplify test for old GNU format.
	(start_header): Put in placeholders for uid, etc., even when
	using extended headers, for benefit of older "tar" implementations.
	Don't assume uintmax_t is wider than 32 bits.
	Output extended header for mtime if needed.
	(dump_regular_finish, dump_file0):
	Support extended time stamp resolution.
	* src/extract.c: Include utimens.h rather than rolling our own.
	(check_time): Support extended time stamp resolution.
	* src/list.c: Include <inttostr.h>.
	(tartime): Use umaxtostr rather than stringify_uintmax_t_backwards.
	* src/xheader.c: Include <inttostr.h>.
	Do not include <xstrtol.h>.
	(strtoimax) [!HAVE_DECL_STRTOIMAX && !defined strtoimax]: New decl.
	(strtoumax) [!HAVE_DECL_STRTOUMAX && !defined strtoumax]: New decl.
	(BILLION, LOG10_BILLION): New constants.
	(to_decimal): Remove; superseded by inttostr.  All callers changed
	to use umaxtostr.
	(xheader_format_name): Don't assume pids and uintmax_t values
	fit in 63 bytes (!) when printed.
	(decode_record): Don't bother to check for ERANGE; an out of range
	value must be treater than len_max anyway.
	If the length is out of range, output it in the diagnostic.
	(format_uintmax): Remove; all callers changed to use umaxtostr.
	(xheader_print): Don't assume sizes can be printed in 99 bytes (!).
	(out_of_range_header): New function.
	(decode_time): Use it.
	(code_time): Accept struct timespec, not time_t and unsigned long.
	All callers changed.  Size sbuf properly, and remove unnecessary check.
	Don't assume time stamps can fit in 199 bytes.
	Handle negative time stamps.  Handle fractional time stamps
	more consistently.  Don't output unnecessary trailing zeros.
	(decode_time): Yield struct timespec, not time_t and unsigned long.
	All callers changed.
	Handle negative time stamps.  Truncate towards minus infinity
	consistently.  Improve overflow checks, and output a better
	diagnostic on overflow.
	(code_num): Don't assume uintmax_t can be printed in 99 bytes (!).
	(decode_num): New function, for better diagnostics.
	(atime_coder, atime_decoder, gid_decoder, ctime_coder):
	(ctime_decoder, mtime_coder, mtime_decoder, size_decoder):
	(uid_decoder, sparse_size_decoder, sparse_numblocks_decoder):
	(sparse_offset_decoder, sparse_numbytes_decoder):
	Use decode_num, etc., instead of xstrtoumax, etc.

2005-06-21  Jim Meyering  <jim@meyering.net>

	Carefully crafted invalid headers can cause buffer overrun.
	Invalid header fields go undiagnosed.
	Some valid time strings are ignored.

	* src/xheader.c (sparse_numblocks_decoder): Remove unchecked use
	of `calloc'.  Use xcalloc instead.
	(decode_time, gid_decoder, size_decoder, uid_decoder):
	(sparse_size_decoder, sparse_offset_decoder, sparse_numblocks_decoder):
	Ensure that the result of calling xstrtoumax is no larger than
	the maximum value for the target type.  Upon any failure, exit with
	a diagnostic.
	(sparse_numblocks_decoder): Avoid buffer overrun/heap corruption:
	use x2nrealloc, rather than `n *= 2' and xrealloc(p, n,....
	(decode_time): Rewrite to accept time strings like
	1119018481.000000000.  Before, such strings were always ignored.

2005-06-13  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/create.c (dump_file0): Check for is_avoided_name()
	first. Fixes bug reported by Martin Lohmeier
	<martin@mein-horde.de>
	* tests/update.at: New file
	* tests/Makefile.am (TESTSUITE_AT): Add update.at
	* tests/testsuite.at: Likewise

2005-06-13  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac (AC_STRUCT_ST_BLKSIZE)
	(AC_STRUCT_ST_BLOCKS): Removed. Handled by system.m4.

2005-06-02  Paul Eggert  <eggert@cs.ucla.edu>

	* src/names.c (excluded_name): excluded_filename ->
	excluded_file_name, because the name was changed in gnulib.

2005-05-30  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.c (read_name_from_file,update_argv): Automatically
	detect nul-terminated list files.
	* NEWS: Updated

2005-05-27  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* scripts/backup.sh.in: Bugfixes.

2005-05-26  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* scripts/backup.in: Minor fixes
	* scripts/backup.sh.in (mt_begin,mt_rewind)
	(mt_offline,mt_status):	Use $MT to invoke mt
	(init_common): Set --rsh-command option for mt if TAPE_FILE is a
	remote archive.
	* doc/tar.texi: Document new backup scripts behavior

2005-05-22  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* lib/.cvsignore: Updated
	* lib/Makefile.tmpl: Add new paxutils files
	* po/POTFILES.in: Likewise
	* src/buffer.c: Update invocations of safer_name_suffix()
	* src/create.c: Likewise
	* src/extract.c: Likewise
	* src/xheader.c: Likewise
	* src/common.h: Include paxlib.h instead of paxerror.h
	(safer_name_suffix,removed_prefixes_p): Removed. The functions are
	imported from paxutils
	* src/names.c (hash_string_hasher,hash_string_compare)
	(hash_string_insert,hash_string_lookup,removed_prefixes_p)
	(safer_name_suffix): Moved to paxutils

2005-05-19  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap (copy_files): Accept optional third argument: a prefix
	to be appended to destination file names.
	Import paxutils/paxlib files.
	* configure.ac: Remove checking for LIB_SETSOCKOPT, it is handled
	by paxutils.
	* lib/Makefile.tmpl (libtar_a_SOURCES): Add paxerror.c paxexit.c
	paxconvert.c
	* po/POTFILES.in: Likewise.
	* src/common.h: Remove defines and declarations imported from
	paxutils
	* src/misc.c: Likewise
	* src/list.c (stringify_uintmax_t_backwards): Moved to paxutils

2005-05-17  Paul Eggert  <eggert@cs.ucla.edu>

	* src/misc.c (remove_any_file): Fix typo in previous change.

2005-05-14  Paul Eggert  <eggert@cs.ucla.edu>

	Port to Solaris 10's treatment of unlinking directories.
	* gnulib-modules: Add unlinkdir.
	* lib/.cvsignore: Add unlinkdir.h, unlinkdir.c.
	* src/common.h (we_are_root): Remove extern decl; it's now static.
	* src/extract.c (we_are_root): Now static.
	* src/misc.c: Include <unlinkdir.h>.
	(remove_any_file): Use cannot_unlink_dir () rather than	we_are_root.

	* ChangeLog, ChangeLog.1, Makefile.am, NEWS, PORTS, README,
	README-alpha, TODO, bootstrap, configure.ac, doc/Makefile.am,
	doc/convtexi.pl, doc/fdl.texi, doc/gendocs_template,
	lib/Makefile.tmpl, lib/prepargs.c, lib/waitpid.c, po/POTFILES.in,
	scripts/Makefile.am, scripts/backup-specs, scripts/backup.in,
	scripts/backup.sh.in, scripts/restore.in, src/Makefile.am,
	src/arith.h, src/buffer.c, src/common.h, src/compare.c,
	src/create.c, src/delete.c, src/extract.c, src/incremen.c,
	src/list.c, src/mangle.c, src/misc.c, src/names.c, src/sparse.c,
	src/system.c, src/tar.c, src/tar.h, src/update.c, src/utf8.c,
	src/xheader.c, tests/Makefile.am, tests/append.at,
	tests/append01.at, tests/comprec.at, tests/delete01.at,
	tests/delete02.at, tests/delete03.at, tests/delete04.at,
	tests/delete05.at, tests/extrac01.at, tests/extrac02.at,
	tests/extrac03.at, tests/extrac04.at, tests/extrac05.at,
	tests/gzip.at, tests/ignfail.at, tests/incremental.at,
	tests/link01.at, tests/listed01.at, tests/listed02.at,
	tests/long01.at, tests/longv7.at, tests/multiv01.at,
	tests/multiv02.at, tests/multiv03.at, tests/multiv04.at,
	tests/old.at, tests/options.at, tests/options02.at, tests/pipe.at,
	tests/recurse.at, tests/same-order01.at, tests/same-order02.at,
	tests/shortrec.at, tests/sparse01.at, tests/sparse02.at,
	tests/testsuite.at, tests/truncate.at, tests/version.at,
	tests/volume.at, tests/star/gtarfail.at, tests/star/gtarfail2.at,
	tests/star/multi-fail.at, tests/star/pax-big-10g.at,
	tests/star/quicktest.sh, tests/star/ustar-big-2g.at,
	tests/star/ustar-big-8g.at:
	Update FSF postal mail address.

2005-05-12  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* NEWS: Updated
	* THANKS: Updated
	* bootstrap: Install files from paxutils/doc
	* doc/Makefile.am (tar_TEXINFOS): Add genfile.texi
	* doc/tar.texi (Genfile): New appendix
	* src/compare.c (diff_file): diff_handle was not initialized
	* src/create.c (dump_regular_file): Correctly pad archive members
	that shrunk during archiving. Repored by Frank Heckenbach.
	* src/extract.c (file_newer_p): Return false if file does not
	exist
	(prepare_to_extract): Correct warning wording.
	* tests/truncate.at: New test case
	* tests/Makefile.am: Add truncate.at
	* tests/testsuite.at: Likewise.

	* doc/.cvsignore: Updated
	* lib/.cvsignore: Updated
	* tests/.cvsignore: Updated

2005-05-02  Paul Eggert  <eggert@cs.ucla.edu>

	* tests/multivol04.at: Tell awk to read from /dev/null.

	Adjust to recent gnulib changes.
	* lib/.cvsignore: Add dup-safer.c, fd-safer.c, unistd-safer.h.
	* src/common.h (initial_umask): New var.
	* src/create.c (start_ueader): Use it, and adjust to new modechange
	API.
	(hash_link): unsigned -> size_t parameters and result.
	* src/incremen.c (hash_directory): Likewise.
	* src/names.c (hash_string_hasher): Likewise.
	* src/tar.c (parse_opt): Set it, and adjust to new modechange API.

2005-04-19  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* tests/Makefile.am: Add shortrec.at.

2005-04-18  Paul Eggert  <eggert@cs.ucla.edu>

	* src/buffer.c (reading_from_pipe): Remove.  All uses removed.
	(short_read): Don't warn about short reads; they're normal.
	* tests/shortrec.at: New file.
	* tests/testsuite.at: Include it.

	* bootstrap (gnulib_modules): Don't create a file modlist.tmp, as
	it is sometimes left behind as a garbage file (maybe due to the
	multiple traps?).

2005-04-14  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c: Handle Solaris 'X' type flag
	* src/tar.h (SOLARIS_XHDTYPE): New define

2005-04-06  Sergey Poznyakoff  <gray@mirddin.farlep.net>

	* src/tar.c: Minor fixes to text messages. Proposed by Benno
	Schulenberg.
	* src/extract.c: Likewise
	(extract_file): Assign orig_file_name
	to save_name uniformly over the program. This fixes matching
	directory names at the start of an archive volume.
	* src/buffer.c (flush_write): Warn when the name of the archive
	straddling volume boundary is longer than 100 characters. Earlier
	behavior was to issue a fatal error.
	(struct zip_magic): Reverted part of changes from 2005-04-04.
	They make the maintenance too costly. Removing `unsigned'
	qualifier from `magic' member should be enough.
	* src/compare.c (diff_init): Read directory file if in listed
	incremental. This prevents spurious 'Contents differ' diagnostics.
	(diff_archive): Minor fixes to text messages
	(diff_file,diff_dumpdir,diff_multivol): Assign orig_file_name
	to save_name uniformly over the program. This fixes matching
	directory names at the start of an archive volume.
	* src/create.c: Assign orig_file_name
	to save_name uniformly over the program. This fixes matching
	directory names at the start of an archive volume.
	* src/list.c: Likewise

	* tests/multiv03.at: Modified to match the new behavior
	* tests/multiv04.at: New file. Test splittind directory members between
	the archive volumes.
	* tests/Makefile.am: Add multiv04.at
	* tests/testsuite.at: Likewise.

2005-04-04  Paul Eggert  <eggert@cs.ucla.edu>

	* configure.ac (AC_CONFIG_AUX_DIR): Rename from config to build-aux,
	for reasons discussed in the thread beginning at
	<http://lists.gnu.org/archive/html/bug-gnulib/2005-03/msg00119.html>.
	* .cvsignore: Remove config; add build-aux.

	* src/buffer.c (struct zip_magic): Use char arrays, not pointers.
	The unsigned char * pointer ran afoul of pedantic C compilers, and
	we didn't need pointers anyway.  Put the size field before the
	data to avoid unnecessary padding.  All uses changed.
	(magic) Make it const, since it doesn't change.  All uses changed.

2005-04-02  Paul Eggert  <eggert@cs.ucla.edu>

	* src/xheader.c (decode_record): Don't dump core when given
	a corrupted extended header.  Problem reported by Jim Meyering.
	Also, check for other ways that the header might be invalid,
	e.g., missing newline at end.  Do not allow keys with nulls.
	Allow blanks before and after length, as POSIX requires.
	Do not allow leading "-" in length.  Check for length overflow.
	(xheader_decode, xheader_decode_global): Let decode_record
	check for exhaustion of record.
	(xheader_read): Null-terminate the extended record;
	decode_record relies on this.

2005-03-21  Paul Eggert  <eggert@cs.ucla.edu>

	* bootstrap (TP_URL): Change from
	<http://www2.iro.umontreal.ca/~gnutra/po/maint/tar/> to
	<http://www.iro.umontreal.ca/translation/maint/tar/> to avoid
	some redirection glitches.
	Use "trap - 0" rather than "trap 0" to fix a POSIX-conformance bug.
	* doc/.cvsignore: Change "tar.info" to "tar.info*".  Sort.
	* lib/.cvsignore: Add intprops.h (new gnulib file).

2005-03-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c (print_header): Print UID/GID in case of
	empty user/group name. This could occur when dumping
	files belonging to non-existing users and when listing
	broken archives.
	Reported by Igor Lautar.

	* src/create.c: Correctly parse empty uname/gname
	* src/sparse.c (sparse_scan_file): Bugfix. offset had
	incorrect type.

	* scripts/backup.in: Use `head -n 1'. Provide missing
	argument to ${MT_STATUS}. Proposed by Jan Merka.
	* scripts/backup.sh.in: Likewise. Fixed typo in
	MT_OFFLINE assignment.
	* scripts/restore.in (restore_fs): Use root_fs

2005-02-15  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/create.c: Replace strdup with xstrdup
	* src/names.c: Likewise
	* src/tar.c: Likewise

	* tests/append01.at: Added reference to bug-tar archive
	* tests/listed02.at: Use -print with find.

2005-02-11  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* THANKS: Added Tim Adye. Fixed UTF.
	* src/list.c (read_header): Removed assignment to
	oldgnu_header.isextended. It was breaking append mode.

	* tests/append01.at: New test.
	* tests/Makefile.am: Added append01.at
	* tests/testsuite.at: Likewise

2005-02-06  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* gnulib.modules: New file. List of required gnulib
	modules.
	* bootstrap: Merge list of required modules from
	paxutils with that from tar proper.
	* src/tar.c: Various fixes in help and diagnostic messages.

2005-02-05  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/common.h (EXTRACT_OVER_PIPE): New macro
	* src/compare.c: Code clean up.
	* src/extract.c (extract_archive): Do not check for
	EXTRACT_OVER_PIPE, decode_options() does this.
	* src/misc.c (exec_error,fork_error,dup2_error)
	(pipe_error): Removed unneeded functions.
	* src/system.c (sys_exec_command): Use xclose, xpipe,
	xfork, xdup2 and exec_fatal.
	* src/tar.c (options): Improved sorting. Document --backup=off.
	(decode_options): Clear backup_option if necessary.

2005-02-05  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Initial implementation of --to-command option proposed
	by Hansjoerg Lipp.

	* bootstrap: Get setenv module from gnulib
	* src/buffer.c: Do not use 8-bit chars in comments
	* src/common.h (to_command_option)
	(ignore_command_error_option): New globals
	(sys_exec_command,sys_wait_command): New commands
	* src/extract.c (extract_file): Handle to_command_option
	Fix error recovery: decrease `size' by `written', not
	by `count', otherwise tar misses the next header
	Do not diagnose write error if to_command_option
	is set, since the command may have exited prematurely.
	It would be better to check for sigpipe, though.
	(prepare_to_extract): Handle to_command_option
	* src/misc.c (exec_error, fork_error, dup_error)
	(pipe_error): New functions
	* src/system.c (sys_exec_command)
	(sys_wait_command): New functions
	* src/tar.c: Handle new options --to-command,
	--ignore-command-error
	* THANKS: Added Hansjoerg Lipp

2005-02-03  Paul Eggert  <eggert@cs.ucla.edu>

	* src/list.c (from_header): New arg OCTAL_ONLY, normally false.
	All uses changed.  Fix typo that sometimes suppressed all "Archive
	contains obsolescent base-64 headers" warnings, not just the first
	one.
	(tar_checksum): Accept only octal checksums, since they aren't
	supposed to overflow into weird formats.

	Adjust to gnulib changes.
	* lib/.cvsignore: Add chdir-long.c, chdir-long.h, memrchr.c,
	memrchr.h, openat.c, openat.h.  Remove pathmax.h (added by
	mistake, perhaps?), sysexit.h (my typo), xstrdup.c (gnulib removed
	this file).  Sort entries.

2005-02-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/extract.c: Further rewrite.
	* src/buffer.c: Removed unused variables.
	* src/list.c: Likewise
	* src/tar.c (update_argv): Changed type to void

	* src/common.h (OLDGNU_NAME_FIELD_SIZE): New constant
	* src/create.c (start_private_header,write_header_name)
	(dump_hard_link): Restore compatibility with 1.13.25
	* src/extract.c (extract_archive): Rewritten
	* src/list.c: Add translators' comments
	* src/tar.c (options) Minor spelling fix
	* tests/star/quicktest.sh: Determine path to the tar executable.

2005-02-03  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* po/POTFILES.in: Added tests/genfile.c
	* src/buffer.c (short_read): Use ngettext()
	(new_volume): use quote().
	* src/create.c: Use quote()
	* src/extract.c: Likewise
	* src/xheader.c: Likewise
	* src/misc.c: Add comments to translators

	* tests/same-order01.at: sort ls output
	* tests/sparse01.at (RE_CHECK): Added missing space

	* tests/sparse02.at: Test extracting sparse files over a pipe.
	* tests/Makefile.am: Added sparse02.at
	* tests/testsuite.at: Likewise
	* tests/listed02.at: Skip the test on filesystems that do not
	update ctime of a file when renaming it. To be reverted when
	the new incremental mode is ready.
	* tests/sparse01.at: Extract and compare sparse file

2005-02-02  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/sparse.c: Extract sparse files even if the output
	fd is not seekable.

2005-02-01  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: Add a comment to lib/Makefile.am saying that this
	is an autogenerated file.
	Exit with code 1 if any of autotools fails.
	* lib/Makefile.tmpl: Insert Emacs magic to the first line.
	* tests/Makefile.am: Add append.at

	* m4/.cvsignore: Ignore all *.m4 files

2005-01-18  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Rewritten handling of -T (--files-from) option. Now it
	inserts the file names immediately into argv array which allows
	for:
	1) any valid tar options (including another -T) to be used in the file
	2) any number of -T options to be given in command line

	* configure.ac: Raised version number to 1.15.2
	* src/common.h: Include obstack.h
	(files_from_option): Removed
	(unquote_option): New variable
	(stat_fatal): New function
	(name_close): Removed function.
	* src/incremen.c: Remove inclusion of obstack.h
	* src/xheader.c: Likewise.
	* src/misc.c (stat_fatal): New function
	* src/names.c (name_file): Removed variable.
	(read_name_from_file): Removed function. All callers changed.
	(name_close): Removed function. All callers changed.
	* src/tar.c: New options --unquote (--no-unquote) and
	--add-file
	(add_file_id,read_name_from_file,update_argv): New functions
	(parse_opt): Rewritten handling of -T option. Handle hidden
	--HANG option for debugging purposes.
	(decode_options): Init unquote_option to true. Init argv_stk.
	Remove unneeded references to files_from_option

	* doc/tar.texi: Document new options.
	Moved rendition macros and option value definitions into
	separate files
	* doc/rendition.texi: New file
	* doc/value.texi: New file
	* doc/Makefile.am: Updated

2005-01-13  Paul Eggert  <eggert@cs.ucla.edu>

	* tests/testsuite.at (RE_CHECK): Use "join - file", not
	"join file -", to work around a bug in Solaris 8 join.
	Problem reported by Tomohiro Suzuki.

2005-01-13  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c (read_header): Fixed calculation of the
	size for GNU long name/link. Tar was reading one block
	more if name_size was divisible by 512. Thanks Josef
	Bauer.
	* tests/long01.at: New file. Test listing of GNU long names
	divisible by 512.
	* tests/pipe.at: Sort tar output.
	* tests/Makefile.am: Added long01.at
	* tests/testsuite.at: Likewise.
	* THANKS: Added Josef Bauer
	* lib/.cvsignore: Updated
	* m4/.cvsignore: Updated
	* NEWS: Updated

2005-01-11  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* directory: Updated for 1.15.1
	* doc/Makefile.am: Use gendocs.sh to generate web documentation
	* doc/gendocs_template: Template file for gendocs.sh
	* doc/tar.texi: Updated docs for --[no-]same-permissions
	* src/tar.c: Reworded docstrings for --[no-]same-permissions

2005-01-06  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: Create m4/paxutils.m4
	* configure.ac: Call tar_PAXUTILS
	* tests/options02.at: Test that tar correctly handles non-option
	arguments interspersed with options.
	* tests/Makefile.am: Add options02.at
	* tests/testsuite.at: Likewise
	* tests/listed02.at: Do not create useless directory

2005-01-05  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.c (parse_opt): Bugfix: Use ARGP_KEY_ARG. Thanks
	Mike Frysinger <vapier@gentoo.org> for reporting.

2005-01-04  Paul Eggert  <eggert@cs.ucla.edu>

	* lib/Makefile.tmpl (localedir.h): Omit needless quotes and a
	needless sed command.  Problem reported by Paul Jarc.

2004-12-23  Paul Eggert  <eggert@cs.ucla.edu>

	Accommodate latest gnulib.
	* doc/.cvsignore: Add getdate.texi.
	* bootstrap: Do not treat alloca-opt specially; this is no
	longer needed (and breaks builds) with latest gnulib.

2004-12-22  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.c (main): Reverted recent changes (#ifdef).

2004-12-21  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Raise version number to 1.15.1
	Check for locale.h
	* NEWS: Entry for 1.15.1
	* src/buffer.c: Bugfix. Changes introduced 2004-11-26
	broke extraction from stdin.
	* src/list.c (from_header, tar_checksum): Changed declaration.
	All callers updated.
	* src/common.h: Likewise
	* src/tar.c (main): Protect invocation of setlocale by
	ifdef.

	* tests/comprec.at: New test
	* tests/pipe.at: New test
	* tests/Makefile.am (comprec.at,pipe.at): New tests
	* tests/testsuite.at: Likewise
	* tests/gzip.at: Use AT_GZIP_PREREQ
	* tests/star/pax-big-10g.at: Likewise
	* tests/star/ustar-big-2g.at: Likewise
	* tests/star/ustar-big-8g.at: Likewise

	* tests/extrac04.at: Discard stderr from sort, on some
	systems it spits out lots of irrelevant info.
	* tests/listed02.at: Likewise

	* doc/index.html.in: Rewritten in xhtml to follow recent
	GNU site standards.
	* THANKS: Updated

2004-12-20  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Released version 1.15. Sources up to this point are
	tagged release_1_15.

	* configure.ac: Raised version number to 1.15
	* NEWS: Likewise
	* directory: Updated
	* bootstrap (update_po): Give -r to wget. Always remove index.html
	Ignore alloca-opt module (it duplicates alloca)

	* tests/Makefile.am: Distribute star/quicktest.sh
	* tests/star/README: Document quicktest.sh
	* tests/star/qucktest.sh: Removed.
	* tests/star/quicktest.sh: New file.

2004-12-18  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* NEWS: Updated
	* doc/tar.texi: Document auto-detection of compressed archive
	formats.
	* src/tar.c (decode_options): Ignore --seek if used with --delete.
	Delete.c is based on the assumption that the archive is being
	actually read, not lseeked.

	* tests/delete05.at: New file
	* tests/extrac02.at: Fixed typo in AT_SETUP
	* tests/Makefile.am: Added delete05.at
	* tests/testsuite.at: Likewise.

2004-12-17  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/delete.c (delete_archive_members): Bugfix: when
	attempting to delete an nonexistent member, the last
	blocking_factor blocks were zeroed.

2004-12-14  Paul Eggert  <eggert@cs.ucla.edu>

	* TODO: Mention sub-second resolution, lutimes, lchmod.

2004-11-27  Paul Eggert  <eggert@cs.ucla.edu>

	Adjust to recent gnulib changes.
	* doc/getdate.texi: Remove, since bootstrap gets it from gnulib now.
	* .cvsignore: Add rmt, rmt/*, rmt/*/*.
	* lib/.cvsignore: Add allocsa.c, allocsa.h, allocsa.valgrind,
	charset.alias, config.charset, getcwd.c, getcwd.h, localcharset.c,
	localcharset.h, ref-add.sed, ref-add.sin, ref-del.sed,
	ref-del.sin, setenv.c, setenv.h, unsetenv.c.  Remove pathmax.h,
	xstrdup.c.
	* m4/.cvsignore: Add allocsa.m4, eealloc.m4, getcwd-path-max.m4,
	localcharset.m4, realloc.m4, setenv.m4.  Remove malloc.m4,
	pathmax.m4, realloc.m4.

2004-11-26  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Raised version number to 1.14.91
	* scripts/tarcat: New file
	* scripts/Makefile.am: Added tarcat
	* src/buffer.c (hit_eof): Changed type to boolean
	(read_full_records,reading_from_pipe): New variables
	(check_compressed_archive,open_compressed_archive): New functions
	(open_archive): Autodetect compressed archives and act accordingly.
	Set reading_from_pipe. This fixes controversial set of changes
	introduced 2004-05-11,2004-03-22.
	* src/list.c (tar_checksum): New function
	(read_header): Use tar_checksum().
	* src/common.h (tar_checksum): New function

	* tests/star/README: Updated
	* NEWS: Updated
	* PORTS: Updated

2004-11-16  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.c (decode_options): Fixed -o semantics. Thanks
	Jean Delvare <khali@linux-fr.org>

2004-10-25  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: Add localcharset
	* lib/Makefile.tmpl: Initialize SUFFIXES and CLEANFILES since the
	makefile snippet from localcharset uses '+=' on them.
	* src/Makefile.am (LDADD): Add LIBICONV
	* src/list.c (decode_header): Set uname/gname to NULL if their
	header counterparts are empty
	* src/tar.c (options): Use OPTION_NO_TRANS
	* src/utf8.c: Use locale_charset() from gnulib

	* tests/star/README: Updated

	* NEWS: Updated
	* TODO: Minor fix

2004-10-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* THANKS: Added Bryan Ford
	* doc/Makefile.am (.text): Fixed rule
	* po/POTFILES.in: Added argp-help.c

2004-10-04  Bryan Ford  <baford@mit.edu>

	* src/tar.c: New option --exclude-caches, to exclude
	cache directories automatically on archive creation.
	Cache directories are directories containing a
	standardized tag file, as specified at:
		http://www.brynosaurus.com/cachedir/spec.html
	* src/common.h: New variable exclude_caches_option.
	* src/create.c: New function check_cache_directory(),
	called from dump_dir0() if exclude_caches_option is set,
	to check for a cache directory tag and exclude the directory
	if such a tag is found.
	* doc/tar.texi: Updated accordingly.

2004-09-16  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* doc/tar.texi: Minor fix
	* src/tar.c (options): Minor fix

2004-09-12  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* TODO: Updated
	* lib/Makefile.tmpl: Added 'rtapelib.o: localedir.h' dependency
	* src/common.h: Comment WANT_DIRECTORY_REMOVE_OPTION.
	* src/extract.c: Normalized use of remove_any_file().
	* src/misc.c: Likewise.
	* src/tar.c (parse_opt): Emit warning if -l option is used.
	(show_default_settings): REMOTE_SHELL may be undefined

2004-09-07  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Test suite rewritten in autotest.

	* configure.ac: Updated for autotest
	* src/tar.c (argp_program_version): Modified.
	* tests/Makefile.am: Rewritten for autotest.

	* tests/.cvsignore: Updated
	* tests/append.at: New file
	* tests/atlocal.in: New file
	* tests/delete01.at: New file
	* tests/delete02.at: New file
	* tests/delete03.at: New file
	* tests/delete04.at: New file
	* tests/extrac01.at: New file
	* tests/extrac02.at: New file
	* tests/extrac03.at: New file
	* tests/extrac04.at: New file
	* tests/extrac05.at: New file
	* tests/gzip.at: New file
	* tests/ignfail.at: New file
	* tests/incremental.at: New file
	* tests/link01.at: New file
	* tests/listed01.at: New file
	* tests/listed02.at: New file
	* tests/longv7.at: New file
	* tests/multiv01.at: New file
	* tests/multiv02.at: New file
	* tests/multiv03.at: New file
	* tests/old.at: New file
	* tests/options.at: New file
	* tests/recurse.at: New file
	* tests/same-order01.at: New file
	* tests/same-order02.at: New file
	* tests/sparse01.at: New file
	* tests/testsuite.at: New file
	* tests/version.at: New file
	* tests/volume.at: New file
	* tests/star/gtarfail.at: New file
	* tests/star/gtarfail2.at: New file
	* tests/star/multi-fail.at: New file
	* tests/star/pax-big-10g.at: New file
	* tests/star/ustar-big-2g.at: New file
	* tests/star/ustar-big-8g.at: New file

	* tests/preset.in: Removed
	* tests/before: Removed
	* tests/after: Removed
	* tests/version.sh: Removed.
	* tests/append.sh: Removed.
	* tests/delete01.sh: Removed.
	* tests/delete02.sh: Removed.
	* tests/delete03.sh: Removed.
	* tests/delete04.sh: Removed.
	* tests/extrac01.sh: Removed.
	* tests/extrac02.sh: Removed.
	* tests/extrac03.sh: Removed.
	* tests/extrac04.sh: Removed.
	* tests/extrac05.sh: Removed.
	* tests/gzip.sh: Removed.
	* tests/incremen.sh: Removed.
	* tests/ignfail.sh: Removed.
	* tests/link01.sh: Removed.
	* tests/listed01.sh: Removed.
	* tests/listed02.sh: Removed.
	* tests/longv7.sh: Removed.
	* tests/multiv01.sh: Removed.
	* tests/multiv02.sh: Removed.
	* tests/multiv03.sh: Removed.
	* tests/old.sh: Removed.
	* tests/options.sh: Removed.
	* tests/same-order01.sh: Removed.
	* tests/same-order02.sh: Removed.
	* tests/volume.sh: Removed.
	* tests/recurse.sh: Removed.
	* tests/sparse01.sh: Removed.
	* tests/star/gtarfail.sh: Removed.
	* tests/star/gtarfail2.sh: Removed.
	* tests/star/multi-fail.sh: Removed.
	* tests/star/ustar-big-2g.sh: Removed.
	* tests/star/ustar-big-8g.sh: Removed.
	* tests/star/pax-big-10g.sh: Removed.

2004-09-07  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: Install genfile.c from paxutils
	* tests/genfile.c: Removed. Integrated into
	paxutils.
	* tests/mksparse.c: Removed. Integrated into
	(paxutils) genfile.c
	* tests/Makefile.am: Removed mksparse
	* tests/sparse01.sh: Use genfile instead of mksparse

2004-09-06  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Started merging with cpio into paxutils. Sources before
	this point are tagged alpha-1_14_90

	* Makefile.am: Updated for use with paxutils
	* README-alpha: Likewise
	* bootstrap: Likewise
	* configure.ac: Likewise
	* lib/Makefile.tmpl: Likewise
	* po/POTFILES.in: Likewise
	* src/Makefile.am: Likewise
	* src/buffer.c: Likewise
	* src/common.h: Likewise
	* src/compare.c: Likewise
	* src/create.c: Likewise
	* src/delete.c: Likewise
	* src/extract.c: Likewise
	* src/incremen.c: Likewise
	* src/list.c: Likewise
	* src/mangle.c: Likewise
	* src/misc.c: Likewise
	* src/names.c: Likewise
	* src/sparse.c: Likewise
	* src/system.c: Likewise
	* src/tar.c: Likewise
	* src/update.c: Likewise
	* src/utf8.c: Likewise
	* src/xheader.c: Likewise

	* src/system.h: Removed
	* src/rmt.c: Removed
	* src/rmt.h: Removed
	* src/rtapelib.c: Removed

2004-09-03  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* tests/listed02.sh: Do not depend on any particular ordering
	of output.

2004-09-02  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* doc/tar.texi: Document the use of -C option in
	file lists. Document --seek option.
	* configure.ac: New option --with-rmt. New configuration variable
	DEFAULT_RMT_DIR. Removed DEFAULT_RMT_COMMAND.
	* src/Makefile.am: Install rmt into rmtdir
	* src/tar.c (usage): Minor fix.
	* NEWS: Updated.
	* README: Updated.

2004-09-01  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Raised version number to 1.14.90
	* src/common.h (is_individual_file): New prototype
	* src/create.c (dump_file0): Fix bug introduced
	2004-02-21.
	* src/names.c (register_individual_file)
	(is_individual_file): New functions.
	* tests/listed01.sh: Use genfile instead of dd.
	* tests/listed02.sh: New file.
	* tests/Makefile.am: Added listed02.sh

	* NEWS: Updated

2004-08-31  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/sparse.c (sparse_add_map): Fixed improper initializations
	of sparse_map_size. We assume that whatever number it contains
	describes adequately the current size of sparse_map. The only
	number we need to reset is sparse_map_avail.
	* src/compare.c (verify_volume): Call set_next_block_after
	if read_header returns HEADER_FAILURE
	Destroy and reinitialize content of current_stat_info and
	extended_header after each iteration (bug reported by
	John L. Males <jlmales@yahoo.com>).
	Issue a warning if the created archive contains some members
	whose file names were stripped off their leading prefixes.
	This is a temporary fix of the issue reported by Bdale Garbee
	<bdale@gag.com> (Refs: Debian bug 230064, Message-Id
	<87n07kyzhi.fsf@rover.gag.com>, Sun, 15 Feb 2004 11:22:17 -0700)

	* src/names.c (removed_prefixes_p): New function.

	* src/buffer.c: When computing write rate do not take
	into account the time needed to verify the archive(s).
	The bug reported by John L. Males <jlmales@yahoo.com>
	(set_start_time,compute_duration): New functions.
	(print_total_written): Use the result of compute_duration().
	(close_archive): Call compute_duration.
	* src/common.h (set_start_time, removed_prefixes_p): New prototypes.
	* src/list.c (decode_header): Fixed initialization
	of stat_info->is_sparse
	* src/tar.c (main): Call set_start_time().

	* src/misc.c (unquote_string): Unquote '\a' and '\v'.
	Reported by Helmut Waitzmann <helmut.waitzmann@web.de>.

	* NEWS: Updated
	* THANKS: Updated

2004-08-30  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.c: Fix copy-n-paste errors in the license

2004-08-19  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* scripts/backup.in: Renamed LIBPATH to LIBDIR.
	Use ROOT_FS with -C option. Do not send mail
	if ADMINISTRATOR is set to NONE.
	* scripts/backup.sh.in (test_root): Append / to
	ROOT_FS if it does not already end in it.
	* scripts/restore.in: Renamed LIBPATH to LIBDIR.
	New option -a (--all). Do not start restore unless
	-a or patterns are given.
	(restore_fs,restore_files): Fixed use of --listed option.
	* doc/tar.texi: Updated
	* NEWS: Updated

2004-08-17  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.c (find_argp_option): Fixed typo

2004-08-12  Paul Eggert  <eggert@cs.ucla.edu>

	Merge argp, getopt, xalloc changes from gnulib.
	* bootstrap (gnulib_modules): Add xalloc-die.
	Remove code to test for patches; we don't have patches now.
	Set LC_ALL=C so that file names sort consistently.
	Prefer the gnulib copies of gettext.m4, glibc21.m4,
	lib-ld.m4, lib-prefix.m4, po.m4 too.

	* patches/getopt.diff: Remove; gnulib now works unpatched.
	* configure.ac (_getopt_long_only_r): Remove check.
	gl_ARGP now does this for us.
	* lib/.cvsignore: Add fnmatch.h, getopt_.h, sysexit.h,
	xalloc-die.c.
	* src/extract.c: Adjust to changes to gnulib xalloc module.
	(extr_init): Remove assignment to xalloc_fail_func; no longer needed.
	(xalloc_die): New function.

2004-08-10  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* NEWS: Updated

	* src/buffer.c (flush_write): Limit filenames
	of the members that straddle multivolume archive
	boundary to 100 characters.
	(flush_read): Use strncmp when comparing multivolume member
	names.
	* tests/multiv03.sh: New file
	* tests/Makefile.am: Added multiv03.sh

2004-08-09  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c (read_and): Call decode_header before
	calling skip_member()
	(skip_member): Use is_sparse field to determine if the
	member is a sparse file.

	* tests/Makefile.am: Added extrac05.sh
	* tests/extrac05.sh: New file
	* tests/append.sh: Rearranged leading comments. Added explicit
	references to report messages wherever available.
	* tests/delete01.sh: Likewise
	* tests/delete02.sh: Likewise
	* tests/delete03.sh: Likewise
	* tests/delete04.sh: Likewise
	* tests/extrac01.sh: Likewise
	* tests/extrac02.sh: Likewise
	* tests/extrac03.sh: Likewise
	* tests/extrac04.sh: Likewise
	* tests/gzip.sh: Likewise
	* tests/ignfail.sh: Likewise
	* tests/incremen.sh: Likewise
	* tests/link01.sh: Likewise
	* tests/listed01.sh: Likewise
	* tests/longv7.sh: Likewise
	* tests/multiv01.sh: Likewise
	* tests/multiv02.sh: Likewise
	* tests/old.sh: Likewise
	* tests/options.sh: Likewise
	* tests/recurse.sh: Likewise
	* tests/same-order01.sh: Likewise
	* tests/same-order02.sh: Likewise
	* tests/sparse01.sh: Likewise
	* tests/version.sh: Likewise
	* tests/volume.sh: Likewise

2004-08-08  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: Extended --update-po option to take an
	optional argument specifying the po file to update.
	* src/create.c: Improved compatibility with 1.13.25
	* tests/link01.sh: New file.
	* tests/Makefile.am: Added link01.sh

2004-08-06  Paul Eggert  <eggert@cs.ucla.edu>

	Merge from gnulib.

	* patches/argp.diff: Remove; no longer needed.

	* lib/.cvsignore: Add stat-macros.h.
	Remove addext.c, malloc.c, realloc.c.

	* src/extract.c: Include <getcwd.h>.
	(extract_archive): Rewrite with new macro IS_ABSOLUTE_FILE_NAME.
	* src/extract.c (make_directories):
	FILESYSTEM_PREFIX_LEN -> FILE_SYSTEM_PREFIX_LEN.
	* src/misc.c (must_be_dot_or_slash): Likewise.
	* src/names.c (excluded_name, safer_name_suffix, stripped_prefix_len):
	Likewise.
	* src/tar.c (parse_opt): Likewise.
	* src/incremen.c (purge_directory): Fix format buffer typos in warning
	strings.
	* src/tar.c (options): Add missing initializers to pacify gcc.
	(decode_options): Remove unused var.

2004-08-02  Paul Eggert  <eggert@cs.ucla.edu>

	* bootstrap (gnulib_modules): Add getpagesize.
	* configure.ac (valloc): Remove check; valloc no longer used.
	* lib/.cvsignore: Add getpagesize.h.
	* m4/.cvsignore: Add getpagesize.m4.
	* src/buffer.c (record_buffer): New var.
	(open_archive): Don't use valloc; on older or buggy hosts, you can't
	free the result.  Use page_aligned_alloc instead.
	* src/compare.c (diff_init): Likewise.
	* src/buffer.c (open_archive): Record the pointer to be freed
	into record_buffer.
	(close_archive): Free record_buffer.
	* src/common.h (page_aligned_alloc): New decl.
	* src/misc.c (quote_n, quote): Remove these redundant functions.
	(ptr_align): New function, from coreutils/src/system.h.
	(page_aligned_alloc): New function.
	* src/system.h (valloc): Remove.

2004-07-09  Paul Eggert  <eggert@cs.ucla.edu>

	* src/extract.c (extract_archive): Do not report an error
	when hard-linking X to X when X exists.  Problem reported by
	Toby Peterson.
	* lib/.cvsignore: Add fchown-stub.c.

2004-06-29  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* NEWS: Updated
	* src/common.h (root_device): New global.
	(gnu_restore): Renamed to purge_directory().
	* src/extract.c (extr_init): Save the device number
	of the root device.
	(extract_archive): Renamed gnu_restore() to purge_directory().
	* src/incremen.c (gnu_restore): Renamed to purge_directory().
	Do not attempt to purge the directory if it is on a different
	device and one_file_system_option is set.

2004-06-25  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* doc/tar.texi: The actual default for exclude patterns
	is --no-anchored. Fixed.
	* src/tar.c (options): Likewise.
	Thanks "Felix Natter" <felix.natter@ldc.de> for noticing.

2004-06-22  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* doc/tar.texi: Fixed several inconsistencies.
	* src/tar.c: Fixed docstring for --checkpoint option.

2004-05-19  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/buffer.c (seek_archive): New function
	* src/common.h (seek_archive): New function
	(seekable_archive): New global.
	* src/list.c (skip_file): Use seek_archive() if
	possible.
	* src/tar.c (struct fmttab): Accept 'pax' as alias
	for 'posix'
	(options): New option -n (--seek).
	* src/update.c: Determine type of the archive before
	appending to it.

	* TODO: Updated.

2004-05-19  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: New option --update-po
	* src/tar.c: New option -H (short alias to --format)
	* doc/tar.texi: Document -H option
 	* src/names.c (safer_name_suffix): Fixed bug introduced
	2004-05-11.

2004-05-16  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: Apply patches from patch subdirectory
	* patches: New dir
	* patches/argp.diff: New file
	* patches/getopt.diff: New file
	* configure.ac: Check for _getopt_long_only_r and
	force using included version of getopt if the function
	is not available.
	* src/tar.c: Use argp for command line parsing.
	* src/system.h: Minor formatting fix
	* m4/.cvsignore: Updated
	* lib/.cvsignore: Updated
	* doc/tar.texi: Minor fix.
	* src/extract.c: Fix improper use of 'path' term
	* src/incremen.c: Likewise
	* src/list.c: Likewise
	* src/misc.c: Likewise
	* src/names.c: Likewise
	* src/rmt.h: Likewise
	* src/rtapelib.c: Likewise
	* src/update.c: Likewise
	* src/xheader.c: Likewise
	* tests/star/README: Minor fix

2004-05-13  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Raised version number to 1.14.1
	* src/tar.c: Renamed --strip-path to --strip-components
	Changed improper use of _() to ngettext().
	* src/extract.c: Renamed strip_path_option to strip_components_option
	* src/common.h: Likewise.
	* NEWS: Updated.
	* doc/tar.texi: Updated

2004-05-11  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/system.c (sys_child_open_for_uncompress): Do not
	set read_full_records_option: the compressed archive is
	likely not to contain integer number of records. Should
	the user wish to use reblocking, he may always give tar
	-B option. This is a minor improvement over the change
	dated 2004-03-22.
	* src/buffer.c (open_archive): Removed assignment to
	read_full_records_option.

	* src/names.c (safer_name_suffix): (safer_name_suffix): Use "%s"
	as the format argument, rather than a possibly-translated variable
	string. Patch provided by Jim Meyering  <jim@meyering.net>
	* src/tar.c (decode_options): Fixed typo in the comment.
	* tests/star/README: Minor correction

2004-05-11  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* directory: New file. GNU directory entry for tar.
	* doc/Makefile.am: Rewritten. Added rules for generating
	documentation for the project's website.
	* doc/.cvsignore: Updated
	* doc/index.html.in: New file.

2004-05-11  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Raised version number to 1.14
	* NEWS: Updated.
	* tests/after: Added copyleft statement
	* tests/before: Added copyleft statement
	* tests/preset.in: Added copyleft statement

	Tar 1.14 is released. Sources up to this point are tagged
	release_1_14

2004-05-10  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Fixed prerequisite headers for sys/buf.h
	(needed on FreeBSD)
	* src/system.h: Likewise.
	* tests/after (compare): Fixed argument quoting under eval
	* tests/before: Quote TAR_ARCHIVE_FORMATS

2004-05-10  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* NEWS: Updated
	* README: Updated
	* PORTS: Updated
	* configure.ac: Call gl_AC_TYPE_INTMAX_T. Document
	DEFAULT_.* variables. Use DEFAULT_RMT_COMMAND to set
	the pathname of the rmt utility.
	New option --enable-backup-scripts.
	* doc/tar.texi: Updated
	* scripts/Makefile.am: Install the scripts only if requested
	by the configure.
	* scripts/backup.in: Fixed --version output.
	Fixed initialization of the listing files and printing
	the time of the last previous level dump.
	* scripts/restore.in: Fixed --version output.
	* src/Makefile.am (localedir.h rule): Generate correct
	DEFAULT_RMT_COMMAND variable.
	* src/common.h (rmt_command_option): New variable.
	* src/list.c (read_and): Print block number before
	issuing 'Skipping to next header' diagnostics, if
	requested by block_number_option.
	* src/rtapelib.c: Use rmt_command_option instead of
	hardcoded "/etc/rmt".
	* src/tar.c: New option --rmt-command.
	(decode_options): Handle --rmt-command. Initialize
	rmt_command_option to DEFAULT_RMT_COMMAND.

2004-05-09  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* doc/tar.texi: Further update.

2004-05-08  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Minor fix
	* scripts/Makefile.am: Updated
	* scripts/backup-specs: Updated
	* scripts/backup.in: Minor fixes
	* scripts/backup.sh: Removed
	* scripts/backup.sh.in: New file. Source for backup.sh
	* scripts/restore.in: New file
	* scripts/.cvsignore: Updated
	* scripts/WARNING: Removed
	* doc/tar.texi: Updated
	* NEWS: Updated

2004-05-07  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/names.c (name_gather): Bugfix: Honor single -C with
	--same-order.
	* tests/same-order01.sh: New file
	* tests/same-order02.sh: New file
	* tests/Makefile.am: Updated

	* tests/append.sh: Added copyleft header
	* tests/delete01.sh: Likewise
	* tests/delete02.sh: Likewise
	* tests/delete04.sh: Likewise
	* tests/extrac01.sh: Likewise
	* tests/extrac02.sh: Likewise
	* tests/extrac03.sh: Likewise
	* tests/extrac04.sh: Likewise
	* tests/gzip.sh: Likewise
	* tests/ignfail.sh: Likewise
	* tests/incremen.sh: Likewise
	* tests/multiv01.sh: Likewise
	* tests/old.sh: Likewise
	* tests/options.sh: Likewise
	* tests/recurse.sh: Likewise
	* tests/version.sh: Likewise
	* tests/volume.sh: Likewise
	* tests/star/gtarfail.sh: Likewise
	* tests/star/gtarfail2.sh: Likewise
	* tests/star/multi-fail.sh: Likewise
	* tests/star/pax-big-10g.sh: Likewise
	* tests/star/qucktest.sh: Likewise
	* tests/star/ustar-big-2g.sh: Likewise
	* tests/star/ustar-big-8g.sh: Likewise

	* doc/.cvsignore: Updated

2004-05-06  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Check whether date accepts +format argument
	(for backup scripts).
	* scripts/level-0: Removed
	* scripts/level-1: Removed
	* scripts/weekly.new: Removed
	* scripts/dump-remind: Removed
	* scripts/backup.in: New file
	* scripts/backup.sh: New file
	* scripts/dump-remind.in: New file
	* scripts/backup-specs: Updated
	* scripts/Makefile.am: Updated for new directory contents.
	* scripts/.cvsignore: Updated

2004-05-05  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* TODO: Updated
	* doc/tar.texi:	Updated
	* src/tar.c: --utc implies -vv

2004-04-28  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/utf8.c: Make sure ICONV_CONST is defined. AM_ICONV
	does not define it if it fails to find iconv.h.

2004-04-26  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: Use gnulib-tool to generate lib/Makefile.am
	and parts of configure.ac
	* configure.ac: Invoke tar_GNULIB to configure gnulib stuff.
	* lib/Makefile.am: Removed
	* lib/Makefile.tmpl: New file.
	* lib/.cvsignore: Updated
	* m4/.cvsignore: Updated
	* src/xheader.c: Include stpcpy.h

	* src/create.c: Produce an error, not warning, if the
	filename is too long.
	* tests/longv7.sh: Synchronized with the recent changes.

2004-04-20  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Fixed test for iconv_t
	* src/rmt.h: Bugfix by Jürgen Weigert
	* THANKS: Add Jürgen Weigert
	* tests/star/README: Fixed typo

2004-04-04  Paul Eggert  <eggert@twinsun.com>

	Merge getdate documentation changes from coreutils.

	* doc/getdate.texi: Update from coreutils CVS.
	* doc/tar.texi: Fix getdate menu to match getdate.texi's.

	Merge recent gnulib changes, and remove some lint.

	Improve support for nanosecond-resolution time stamps.
	* bootstrap: Add gettime, timespec modules.
	* configure.ac (gl_GETTIME, gl_TIMESPEC): Add.
	* lib/.cvsignore (getopt_int.h, gettime.c, gettimeofday.c,
	timespec.h): Add.
	* lib/Makefile.am (libtar_a_SOURCES): Add gettime.c, timespec.h.
	* m4/.cvsignore: Add clock_time.m4, gettime.m4, gettimeofday.m4,
	st_mtim.m4, timespec.m4.  Remove malloc.m4, realloc.m4.
	* src/common.h (newer_mtime_option): Now a struct timespec, not
	time_t.  All uses changed.
	(NEWER_OPTION_INITIALIZED, OLDER_STAT_MTIME): New macros.
	* src/create.c (dump_file0): Use OLDER_STAT_TIME to compare times.
	* src/incremen.c (scan_path): Likewise.
	* src/list.c (read_and): Likewise.
	* src/list.c (read_and): Use NEWER_OPTION_INITIALIZED to decide
	whether newer_mtime_option is initialized.
	* src/tar.c (decode_options): Likewise.
	* src/tar.c (decode_options): Adjust to new signature for get_date.

	* src/buffer.c (short_read, flush_read): Use size_t, not ssize_t, for
	result of safe_read, full_write, and similar functions.
	Detect safe_read error by comparing to SAFE_READ_ERROR;
	detect full_write error by comparing to 0.
	All uses changed.
	* src/common.h (write_error_details, sys_write_archive_buffer):
	Likewise.
	* src/misc.c (write_error_details): Likewise.
	* src/rmt.c (main): Likewise.
	* src/rmt.h (rmt_read__, rmt_write__): Likewise.
	* src/rtapelib.c (rmt_read__, rmt_write__, rmt_ioctl__): Likewise.
	* src/sparse.c (sparse_scan_file, sparse_dump_region,
	check_sparse_region, check_data_region): Likewise.
	* src/system.c (sys_write_archive_buffer, sys_drain_input_pipe,
	sys_child_open_for_compress, sys_child_open_for_uncompress): Likewise.
	* src/update.c (append_file): Likewise.

	* src/buffer.c (clear_read_error_count): Use explicit (void)
	to indicate a function with no arguments.
	* src/create.c (check_links): Likewise.
	* src/system.c (sys_get_archive_stat, sys_save_archive_dev_ino,
	sys_detect_dev_null_output, sys_drain_input_pipe, sys_spawn_shell,
	sys_reset_uid_gid, sys_get_archive_stat, sys_save_archive_dev_ino,
	sys_detect_dev_null_output, sys_drain_input_pipe, sys_spawn_shell):
	Likewise.
	* src/utf8.c (get_input_charset): Likewise.
	* src/xheader.c (xheader_ghdr_name, xheader_write_global,
	xheader_decode_global, extended_header_init): Likewise.
	* tests/mksparse.c (usage): Likewise.

	* src/buffer.c (new_volume): Rename local variables to avoid
	shadowing warnings.
	* src/common.h (file_dumpable_p, sys_stat_nanoseconds,
	sparse_file_p, sparse_member_p, sparse_fixup_header,
	sparse_dump_file, sparce_extract_file, sparse_skip_file,
	sparse_diff_file): Likewise.
	* src/compare.c (diff_archive): Likewise.
	* src/create.c (file_dumpable_p, dump_regular_file, dump_dir0,
	dump_dir, dump_hard_link, file_count_links, dump_file0, dump_file):
	Likewise.
	* src/extract.c (repair_delayed_set_stat): Likewise.
	* src/misc.c (maybe_backup_file, add_hierarchy_to_namelist):
	Likewise.
	* src/sparse.c (struct tar_sparse_optab, tar_sparse_dump_region,
	tar_sparse_extract_region, sparse_dump_region, sparse_extract_region,
	sparse_dump_file, sparse_file_p, sparse_member_p,
	sparse_fixup_header, sparse_extract_file, sparse_skip_file,
	check_data_region, sparse_diff_file): Likewise.
	* src/system.c (sys_stat_nanoseconds): Likewise.
	* src/xheader.c (xheader_format_name): Likewise.

	* src/common.h (enum old_files): Remove comma before }; not portable.

	* src/common.h (read_fatal_details): Add __attribute__ ((noreturn)).
	* src/rmt.c (usage): Likewise.
	* src/xheader.c (xheader_set_single_keyword): Likewise.
	* tests/genfile.c (usage): Likewise.
	* tests/mksparse.c (die, usage): Likewise.  Also add printf attribute
	to die.

	* src/common.h (gname_to_gid, uname_to_uid): Add const to avoid
	some gcc warnings.
	* src/names.c (uname_to_uid, gname_to_gid): Likewise.
	* src/utf8.c (struct langtab.lang, struct langtab.terr, struct
	langtab.charset, charset_lookup): Likewise.

	* src/common.h (name_init): Remove unused args.  All callers changed.
	* src/names.c (name_init): Likewise.

	* src/common.h (usage, xheader_write, xheader_write_global,
	sys_reset_uid_gid): New decls.

	* src/compare.c (report_difference, process_noop): Add
	__attribute__ ((unused)) for unused attributes.
	* src/sparse.c (oldgnu_sparse_member_p, star_sparse_member_p):
	Likewise.
	* src/xheader.c (dummy_coder, dummy_decoder, atime_coder,
	gid_coder, gname_coder, linkpath_coder, ctime_coder, mtime_coder,
	path_coder, size_coder, uid_coder, uname_coder,
	sparse_numblocks_coder): Likewise.

	* src/create.c (dump_regular_finish, dump_dir0, dump_dir,
	dump_file0): Now static.
	* src/utf8.c (charset_lookup): Likewise.
	* src/xheader.c (xheader_protected_pattern_p,
	xheader_protected_keyword_p, xheader_set_single_keyword,
	xheader_keyword_deleted_p, xheader_keyword_override_p,
	xheader_list_append, xheader_list_destroy, xheader_set_keyword_equal):
	Likewise.
	* tests/genfile.c (usage): Likewise.
	* tests/mksparse.c (die, mkhole, mksparse, usage, xlat_suffix):
	Likewise.

	* src/create.c (hash_link): Rewrite to avoid cast.

	* src/extract.c (file_newer_p): Use parameter, not global var.
	* src/misc.c (write_error_details): Likewise.

	* src/extract.c (prepare_to_extract): Remove directory arg; not
	used.  All callers changed.

	* src/misc.c (close_fatal): Remove; not used.
	* src/system.c (sys_utimes): Likewise.

	* src/rmt.c (get_string): Avoid buffer overrun (off by 1 error).

	* src/rmt.c (main): Update copyright date to 2004.
	* src/tar.c (decode_options): Likewise.

	* src/rtapelib.c (get_status_string): Don't lose errno when
	skipping the error messages.
	(get_status): Report an error if atol returns a negative number.

	* src/utf8.c (struct langtab, langtab, charset_lookup,
	get_input_charset) [!defined HAVE_LIBCONV]: Omit unused
	definitions.
	(iconv_open, iconv, iconv_close) [!defined HAVE_LIBCONV]:
	Use macros, not definitions, to avoid type clashes with system
	headers.
	(charset_lookup): Local var is now auto, not static.
	(utf8_convert): Use ICONV_CONST instead of const, to avoid
	type clashes.

	* src/utf8.c (langtab): Initialize all elements of struct, to
	avoid gcc warning.
	* src/xheader.c (xhdr_tab): Likewise.

	* src/xheader.c: Include fnmatch.h, since we use fnmatch.

	* tests/mksparse.c (mkhole): Fix typo: bool was assigned to off_t.

2004-04-04  Sergey Poznyakoff  <gray@Noldor.runasimi.org>

	* NEWS: Updated
	* configure.ac: Raised version number to 1.13.94
	* src/system.h: Protect inclusion of <sys/time.h>
	by ifdef.
	Declare time() if HAVE_DECL_TIME is 0
	* tests/.cvsignore: Added mksparse

	* tests/sparse01.sh: New file
	* tests/multiv02.sh: New file
	* tests/Makefile.am: Add sparse01.sh and multiv02.sh
	* tests/longv7.sh: Added missing call to 'after'

	* src/common.h: Added missing prototypes
	* src/compare.c (diff_archive): Use is_sparse member
	instead of GNUTYPE_SPARSE.
	* src/create.c: Removed unused variables
	* src/extract.c (extract_archive): Use sparse_member_p instead
	of GNUTYPE_SPARSE.
	Removed unused variables
	* src/list.c (decode_header): Use sparse_fixup_header to correct
	the st_size value.
	(print_header): Do not rely on GNUTYPE_SPARSE type.
	Use st->stat.st_size to print real file size.
	(skip_member): Assign stat_info.file_name to save_name. This fixes
	bug reported by Mads Martin Joergensen <mmj@suse.de>
	Use sparse_skip_file() to skip sparse members.
	* src/rtapelib.c: include "common.h"
	* src/sparse.c (struct tar_sparse_optab.sparse_member_p)
	(struct tar_sparse_optab.fixup_header): New member
	(tar_sparse_member_p): New function.
	(tar_sparse_init): Return true if decode_header is not provided
	(tar_sparse_fixup_header)
	(sparse_member_p,sparse_fixup_header)
	(sparse_skip_file)
	(oldgnu_sparse_member_p,oldgnu_fixup_header,star_sparse_member_p)
	(star_fixup_header, pax_sparse_member_p): New function
	(pax_decode_header): Remove
	* src/system.h: Include <sys/time.h> and <utime.h> when available
	* src/tar.c (usage): Prototype moved to common.h
	* src/tar.h (struct tar_stat_info.is_sparse): New member
	* src/utf8.c (utf8_convert): Changed prototype
	(get_input_charset): Removed unused variable
	* src/xheader.c: include <fnmatch.h>
	(size_decoder): Assign to both st->archive_file_size and
	st->stat.st_size.
	(st->stat.st_size): Assign to st->stat.st_size
	(sparse_numbytes_decoder): Removed unused variable
	* src/.cvsignore: Added .gdbinit
	* THANKS: Added Mads Martin Joergensen

2004-03-26  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/create.c (write_long_name): Do not allow more than
	NAME_FIELD_SIZE-1 characters in a file name for V7 format
	archives.
	* tests/longv7.sh: New file.
	* tests/Makefile.am: Add longv7.sh

2004-03-22  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/buffer.c (open_archive): Clear read_full_records_option
	if reading from a pipe.
	(short_read): Display warning about the deduced record size
	if version > 1
	* tests/star/pax-big-10g.sh: Updated to match the above changes.
	* tests/star/ustar-big-2g.sh: Likewise.
	* tests/star/ustar-big-8g.sh: Likewise.

	* configure.ac: Added gl_FUNC_STRTOULL
	* src/create.c (start_header): Check for GNU_FORMAT
	if incremental_option is set.
	* src/xheader.c (to_decimal): New function.
	(xheader_format_name): Use to_decimal() instead of snprintf.
	* tests/listed01.sh: Use genfile instead of dd
	* tests/multiv01.sh: Likewise.

2004-03-12  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c (read_and): Stop processing the archive after
	encountering a single zero record. Many old archives contain
	arbitrary garbage after it.
	The warning is issued anyway.

2004-03-02  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/rtapelib.c (rmt_lseek__,rmt_ioctl__): Bugfix. The
	conversion buffer was not null terminated. Fix provided
	by Leland Lucius <llucius@tiny.net>
	* THANKS: Added Leland Lucius
	* src/utf8.c (utf8_convert): Indentation fix.

2004-02-29  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/buffer.c (flush_read): Bugfix: the
	condition at line 714 included

	      || (status > 0 && !read_full_records_option)

	which is grossly wrong, since even if new_volume() below succeeds,
	the subsequent call to rmtread will overwrite the chunk of data
	already read in the buffer and thus spoil everything.
	* src/system.c (sys_child_open_for_uncompress): Minor stylistic
	fix.
	* tests/star/multi-fail.sh: New test.
	* tests/Makefile.am: Added multi-fail.sh
	* tests/star/README: Updated

2004-02-29  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* NEWS: Updated
	* configure.ac: Removed spurious AC_CHECK_LIB(iconv)
	* src/common.h (utc_option): new global
	(enum old_files.KEEP_NEWER_FILES): New element
	* src/extract.c: Handle --keep-newer-files option
	* src/list.c (tartime): Print UTC if --utc was given.
	* src/tar.c: New options: --utc and keep-newer-files

	* tests/Makefile.am: Added new tests
	* tests/after: Rewritten
	* tests/before: Rewritten
	* tests/preset.in: Rewritten
	* tests/delete03.sh: Accommodate for the new testsuite logic
	* tests/gzip.sh: Likewise
	* tests/incremen.sh: Likewise
	* tests/listed01.sh: Likewise
	* tests/multiv01.sh: Likewise
	* tests/old.sh: Likewise
	* tests/options.sh: Likewise
	* tests/version.sh: Likewise
	* tests/volume.sh: Likewise

	* tests/star: New directory
	* tests/star/README: New file
	* tests/star/gtarfail.sh: New file
	* tests/star/gtarfail2.sh: New file
	* tests/star/pax-big-10g.sh: New file
	* tests/star/qucktest.sh: New file
	* tests/star/ustar-big-2g.sh: New file
	* tests/star/ustar-big-8g.sh: New file

2004-02-26  Paul Eggert  <eggert@twinsun.com>

	* doc/tar.texi (dircategory Individual utilities): Append period,
	as suggested by Karl Berry.

2004-02-24  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c (decode_header): Call xheader_decode before
	the assignment to current_stat_info.archive_file_size.

2004-02-23  Paul Eggert  <eggert@twinsun.com>

	* configure.ac: Invoke AM_ICONV, to define ICONV_CONST if needed.

2004-02-23  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	1.13.93 released.

	* NEWS: Updated
	* tests/before: Move testing of the prerequisite archive formats
	to the separate function 'prereq'. Do not expect any arguments
	* tests/delete03.sh: Use prereq() instead of passing arguments
	to 'before'.
	* tests/incremen.sh: Likewise.
	* tests/listed01.sh: Likewise.
	* tests/multiv01.sh: Likewise.

2004-02-22  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Added UTF-8 support. Finished global extended header
	support.

	* NEWS: Minor fix
	* configure.ac: Detect libiconv
	* src/utf8.c: New file. Conversions to and from utf-8.
	* src/Makefile.am: Added utf8.c
	* src/create.c (write_header_name) In pax format, use
	"path" keyword if the file name is not ASCII
	(start_header): Likewise for uname and gname.
	* src/list.c: Decode encountered global headers.
	* src/xheader.c: Use keywords from the global
	headers.
	Correctly handle UTF-8 conversions.
	(xheader_list_destroy): New function.
	(xheader_set_single_keyword,xheader_set_keyword_equal): Added
	missing gettext markers
	(decode_record): Rewritten using caller-provided handler and
	data closure.
	* tests/listed01.sh: Give credit to Andreas Schuldei.

2004-02-21  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/create.c (dump_file0): The conditional at line
	1296 prevented incremental backups on individual files
	from working, as reported by Andreas Schuldei
	<andreas@schuldei.org>.

	This is due to the condition

	  (0 < top_level || !incremental_option)

	Removing it makes incremental backups work for individual
	files as well as for directories. On the other hand, it does
	not affect other functionality, as shown by the reasoning below:

	To begin with, the two parts of this condition are mutually
	superfluous, because

	  1) when top_level < 0, incremental_option == 1
	  so the condition yields false
	  2) when top_level >= 0, incremental_option == 0
	  so the condition yields true.

	In other words, it is completely equivalent to

	      (!incremental_option)

	Now, let's consider the effect of its removal. There are two cases:

	1) when incremental_option==1
	This means incremental backup in progress. In this case dump_file
	is invoked only for directories or for files marked with 'Y' by
	get_directory_contents. The latter are those that did not meet the
	condition in incremen.c:242, which is exactly the same condition
	as this at create.c:1296. So, for these files the check
	(!incremental_option) is useless, since the rest of the
	conditional will yield false anyway. On the other hand, if
	dump_file is invoked on a directory, the conditional will yield
	false due to !S_ISDIR assertion, so these will be processed as usual.

	Thus, for this case the extra condition (!incremental_option) is
	irrelevant, and its removal won't alter the behavior of tar,
	*except* that it will enable incremental backups on individual
	files, which is the wanted effect.

	2) when incremental_option==0
	In this case the condition yields true and its removal does not
	affect the functionality.

	* THANKS: Updated
	* configure.ac: Raised patchlevel to 93
	* src/incremen.c: Minor stylistic fixes.
	* tests/listed01.sh: New test. Check listed incremental
	backups on individual files.
	* tests/Makefile.am: Added listed01.sh

2004-02-20  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/common.h (simple_finish_header,start_private_header): New
	declarations
	(xheader_ghdr_name): Changed declaration
	* src/create.c (start_private_header): Removed static qualifier.
	(write_extended): Removed superfluous last argument. Use
	xheader_write()
	(simple_finish_header): New function.
	(finish_header): Use simple_finish_header() to break recursive
	dependency between this function and write_extended().
	* src/tar.c (assert_format): Do not bail out if several
	--format arguments are given. This is a common case when
	TAR_OPTIONS are used.
	(decode_options): New option --show-defaults displays the
	compiled-in defaults.
	Use POSIX format if no --format option was given and
	--pax-option was specified.
	Do not allow to use --pax-option unless the archive format is
	set to POSIX (or reading subcommand is requested).

	* src/update.c (update_archive): Write global extended header if
	constructed.
	* src/xheader.c (xheader_format_name): Bugfix.
	(xheader_xhdr_name): Changed the default extended header name
	to '%d/PaxHeaders.%p/%f', as POSIX requires.
	(xheader_ghdr_name): Removed unused argument.
	(xheader_write,xheader_write_global): New function.
	(xheader_decode): Modified to honor overrides whatever
	the current archive format is.

	* src/delete.c (delete_archive_members): Call xheader_decode
	unconditionally.
	* src/list.c (decode_header): Likewise.
	* src/incremen.c (sort_obstack): Fixed typo in the comment

	* doc/tar.texi: Document new default for extended
	header names.

	* tests/before: Accept an optional list of allowed archive
	formats. Exit with the status 77 if the current archive
	format does not match any of them.
	* tests/delete03.sh: Require gnu, oldgnu or posix format
	* tests/incremen.sh: Require gnu or oldgnu format
	* tests/multiv01.sh: Likewise

2004-02-20  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* doc/tar.texi (Option Summary): Documented --pax-option
	* src/tar.c: Likewise.
	* NEWS: Likewise.
	* src/create.c (to_chars): Added a comment.
	* src/tar.h: Comment to GNU_FORMAT

2004-02-18  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* README: Updated
	* configure.ac: Added stpcpy
	* bootstrap: Likewise
	* lib/Makefile.am: Likewise
	* src/common.h (xheader_xhdr_name,xheader_ghdr_name): New
	functions
	* src/create.c (write_extended): Call xheader_xhdr_name
	instead of using hardcoded "././@PaxHeader" name.
	* src/tar.c: New option --pax-option (equivalent to -o option
	of pax).
	* src/xheader.c: Implement pax -o option. Fixed misleading
	heading comment (introduced 2003-09-02).
	* src/incremen.c: Minor fixes
	* m4/.cvsignore: Updated

2004-02-17  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/incremen.c: Removed accumulator stuff in favor of obstack.
	(get_directory_contents): Split into two functions
	* src/update.c: Minor changes
	* doc/tar.texi: Fixed typo

2004-02-15  Paul Eggert  <eggert@twinsun.com>

	Fix Debian bug 230872, originally reported by Jeff King in
	<http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=230872>.

	* doc/tar.texi (posix compliance): Remove.  The whole section
	was a misunderstanding of what POSIXLY_CORRECT is supposed to
	mean.  The GNU Coding Standards says that POSIXLY_CORRECT
	is for disabling extensions that are incompatible with POSIX:
	it is not for disabling compatible extensions.  All references
	to this section removed.
	(posix): This format is created only if the posix format is
	specified; it is no longer created if gnu format is specified
	and POSIXLY_CORRECT is set.
	* src/tar.c (decode_options): Ignore POSIXLY_CORRECT.
	POSIX does not specify the behavior of tar, so we should
	not worry about POSIXLY_CORRECT here.

2004-01-21  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* Makefile.am: Removed m4
	* configure.ac: Require automake-1.8/autoconf-2.59. Removed
	m4/Makefile.
	* README-alpha: Updated
	* bootstrap: Updated TP URL, improved help output. Default
	to :ext:anoncvs and set CVS_RSH, unless already set.
	* m4/Makefile.am: Removed

2004-01-21  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* bootstrap: Bugfix by Marco Gerards <metgerards@student.han.nl>:
	Use $option instead of $1 so all options will be parsed.

2004-01-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Started rewriting buffer.c ...

	* bootstrap: New option --no-po
	* src/buffer.c (new_volume,check_label_pattern): Changed return type.
	(time_to_start_writing): Changed data type
	(file_to_switch_to): Removed. Variable never assigned to.
	(open_archive) Moved option compatibility checks to tar.c
	Other minor changes.
	* src/common.h (maybe_backup_file): Changed return type
	* src/misc.c: Likewise.
	* src/create.c: Updated invocations of safer_name_suffix
	* src/extract.c: Likewise
	* src/delete.c: Updated assignment to write_archive_to_stdout
	* src/tar.c (decode_options): More option compatibility checks
	(moved from buffer.c)
	* src/update.c (time_to_start_writing): Changed data type.
	* tests/recurse.sh: New test case.
	* tests/mksparse.c: New file.
	* tests/Makefile.am: Added recurse.sh and mksparse.c

2004-01-02  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/sparse.c (sparse_diff_file): Bugfix. Thanks
	Martin Simmons for the patch.
	* src/create.c (dump_dir0): Bugfix. Thanks Piotr Czerwinski
	<pius@pld-linux.org> for the patch.

2003-12-26  Paul Eggert  <eggert@twinsun.com>

	Synchronize with Gettext 0.13.1, Automake 1.8, Autoconf 2.59,
	and translation website.

	* bootstrap: Don't bother skipping codeset.m4, glibc21.m4,
	intdiv0.m4, inttypes_h.m4, inttypes.m4, inttypes-pri.m4,
	isc-posix.m4, and lcmessage.m4 from gnulib.  This list of files is
	a bit obsolete anyway, now that gettext 0.13.1 is out.  Also, the
	files are replaced by autoreconf.  Also, there seems to be a bug
	in gettext/autoconf/automake if we try to omit these files after
	autoreconf has replaced them, even though the gettext manual says
	they're optional.  So give up and just include them for now, even
	though they make 'configure' longer and slower.

	Change translation URL from
	<http://www.iro.umontreal.ca/contrib/po/maint/tar/> to
	<http://www2.iro.umontreal.ca/~gnutra/po/maint/tar/> to
	accommodate translator website revamp.

	Fail if autoreconf fails.

	* m4/.cvsignore: Add intmax.m4, longdouble.m4, printf-posix.m4,
	signed.m4, size_max.m4, wchar_t.m4, wint_t.m4, xsize.m4, to
	ignore files now supplied by gettext 0.13.1.

2003-12-25  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Synchronized with the backup repository on Mirddin

2003-12-19  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Check for varios members of struct stat
	that may represent file modification times with a subsecond
	precision.
	Check for utimes (for future use)
	* src/buffer.c (short_read): Issue a warning on short reads.
	* src/common.h (sys_stat_nanoseconds): New function
	* src/create.c (dump_file0): Use sys_stat_nanoseconds().
	* src/list.c (read_and): Treat only two successive zero
	filled blocks as an EOF indicator. Issue a warning if
	a single one is encountered.
	* src/system.c (sys_stat_nanoseconds): New function
	* src/tar.h (tar_stat_info.atime_nsec,mtime_nsec,ctime_nsec): New
	members.
	* src/xheader.c (code_time,decode_time): Support for subsecond
	precision.
	(atime_coder,atime_decoder,ctime_coder,ctime_decoder)
	(mtime_coder,mtime_decoder): Update invocations of code_time and
	decode_time.
	(gid_decoder,size_decoder,uid_decoder,sparse_size_decoder)
	(sparse_numblocks_decoder,sparse_offset_decoder)
	(sparse_numbytes_decoder): Updated

2003-12-18  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/names.c (safer_name_suffix): Reverted change made
	2003-11-14. Reason: Discussion with Paul Eggert and
	Jean-Louis Martineau. See also ChangeLog entry from
	1999-08-14.
	* tests/delete03.sh: Likewise.
	* tests/extrac04.sh: Likewise.
	* tests/multiv01.sh: Likewise.

2003-12-12  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/incremen.c (write_directory_file): Use sys_truncate
	* src/list.c (print_header): Use archive_file_size member
	when printing real file size.
	* src/sparse.c (sparse_scan_file): Correctly handle files with
	a hole at the end.
	(sparse_dump_region,sparse_extract_region): Allow for zero size
	trailing blocks

2003-12-12  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Raised version number to 1.13.92
	* src/list.c (decode_header): Discern between pax and ustar
	formats
	Initialize current_stat_info.archive_file_size.

	NOTE: Modifications from this date on are temporarily
	stored on local CVS on mirddin. This repository will
	be synchronized with Savannah as soon as the latter
	becomes operational again.

2003-12-01  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* TODO: Updated
	* src/sparse.c: Initial implementation of GNU/pax sparse
	file format.
	* src/common.h (xheader_store): Changed prototype.
	* src/create.c: Update calls to xheader_store
	* src/extract.c (extract_archive): Check reported size vs.
	archive file size to determine if we have to do with a
	sparse file.
	* src/tar.c (usage): Cleaned up the sample argument to --newer
	option.
	(decode_options): Allow --sparse for POSIX_FORMAT archives.
	* src/xheader.c (struct xhdr_tab.coder; all coder function): Added
	extra argument
	Implemented GNU.sparse.* keywords.

2003-11-30  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Check for setlocale. Thanks Bruno Haible for
	reporting.

2003-11-25  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/create.c (write_gnu_long_link): Use oldgnu
	magic with @LongLink blocks.

2003-11-17  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.h: Support for star sparse format.
	* src/sparse.c: Likewise.

2003-11-17  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/sparse.c (sparse_diff_file): New function
	* src/common.h (sys_compare_uid,sys_compare_gid): New functions
	(sys_compare_uid_gid): Removed.
	(sys_compare_links,report_difference): Changed prototype
	(sparse_diff_file): New function
	* src/system.c (sys_compare_uid,sys_compare_gid): New functions
	(sys_compare_uid_gid): Removed.
	(sys_compare_links): Changed declaration
	* src/compare.c (diff_archive): Use sparse_diff_file.

2003-11-16  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Rewritten sparse file handling.

	* src/sparse.c: New file. Provides a universal framework
	for various methods for sparse files handling.
	* src/Makefile.am: Added sparse.c
	* src/common.h (struct sp_array,sparsearray,sp_array_size)
	(init_sparsearray,fill_in_sparse_array): Removed
	(enum dump_status): New data type
	(pad_archive,close_diag,open_diag,read_diag_details)
	(readlink_diag,savedir_diag,seek_diag_details,stat_diag): New
	functions.
	(sparse_file_p,sparse_dump_file,sparse_extract_file): New
	functions.
	(print_header): Changed prototype declaration.
	* src/tar.h (struct sp_array): Declaration from common.h
	(struct tar_stat_info): New members archive_file_size,
	sparse_map_avail,sparse_map.
	* src/create.c: Major rewrite.
	* src/extract.c: Use new sparse file interface.
	* src/compare.c (diff_sparse_files): Temporary placeholder.

	* src/buffer.c: Minor changes
	* src/tar.c: Likewise.
	* src/list.c: Likewise.
	* src/misc.c (close_diag,open_diag,read_diag_details)
	(readlink_diag,savedir_diag,seek_diag_details,stat_diag): New
	diagnostics functions.
	* src/incremen.c: Use new diagnostics functions.
	* src/names.c: Likewise.

2003-11-14  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Fixed check for setsockopt

	* src/create.c: Do not zero-terminate name field if
	the name is exactly 100 characters long.
	(write_ustar_long_name): Fixed cheking for unsplittable
	names.

2003-11-14  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/create.c (start_header): Removed debugging hook
	(dump_file): Fixed handling of linkname field.
	* src/names.c (safer_name_suffix): If the input
	file name ends with a slash, output one should do so
	as well.
	* doc/tar.texi: Documented --format=ustar

2003-11-14  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.h (archive_format): USTAR_FORMAT: New type.
	* src/create.c: Added POSIX.1-1988 support.
	* src/names.c (safer_name_suffix): Skip leading ./
	* src/tar.c: New option --format=ustar forces
	POSIX.1-1988 archive format.
	* tests/delete03.sh: Updated.
	* tests/extrac04.sh: Updated.
	* tests/multiv01.sh: Updated.

2003-11-13  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c (read_and): Initialize current_stat_info
	and extended_header at the start of the loop.
	* src/names.c (all_names_found): Check if the argument
	contains valid filename. Fixes coredump on `not_a_tar_file'
	* src/xheader.c (atime_decoder,gid_decoder,ctime_decoder)
	(mtime_decoder,size_decoder,uid_decoder): Use xstrtoumax.
	Fixes `pax-big-10g' bug.

2003-11-12  Paul Eggert  <eggert@twinsun.com>

	Fix some C compatibility bugs reported by Joerg Schilling.

	* src/common.h (stripped_prefix_len): Fix misspelling
	"stripped_path_len" in declaration.
	* src/rmt.c (main): Use "return FOO;" rather than
	"exit (FOO);"; we no longer have to worry about
	pre-ANSI hosts that mishandled returned values from "main".
	* src/tar.c (main): Likewise.  This avoids warnings on some
	compilers.
	* src/system.c: Include signal.h, for 'kill'.
	* src/system.h (DEV_BSIZE): Remove.
	(DEFAULT_ST_BLKSIZE): New macro.
	(ST_BLKSIZE): Use it, instead of DEV_BSIZE.
	* src/tar.c (enum): Remove comma just before }.

2003-11-12  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c (decode_header): Initialize st_atime and
	st_ctime.

2003-11-11  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac (tar_save_LIBS): Bugfix. Thanks Adrian
	Bunk <bunk@fs.tum.de> for reporting.
	* doc/tar.texi: Fixed spelling. Thanks Martin Buchholz
	<martin@xemacs.org> for spotting.

2003-11-04  Paul Eggert  <eggert@twinsun.com>

	* src/xheader.c (xhdr_tab): Make it extern, not static, as C89 and
	C99 require this.

2003-10-26  Paul Eggert  <eggert@twinsun.com>

	* src/system.c (sys_spawn_shell): Cast trailing null to (char *).
	Bug reported by Christian Weisgerber.

2003-10-19  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* AUTHORS: Updated
	* NEWS: Updated
	* src/tar.c (decode_options): Removed superfluous archive format
	check
	* doc/tar.texi: Documented new features.

2003-10-08  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* NEWS: Updated
	* THANKS: Added Wojciech Polak
	* configure.ac: Added checks for missing functions. Raised
	version number to indicate alpha release.
	* lib/Makefile.am: Added missing headers
	* lib/waitpid.c: Added missing includes.
	* src/extract.c: Likewise.
	* src/names.c: Removed spurious includes.
	* src/xheader.c: Likewise.
	* src/system.h [MSDOS]: Fixed spelling of EACCES. Added
	macro overriding broken mkdir prototypes.

2003-10-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Check for dev_t and ino_t.
	* m4/Makefile.am: Added missing files.
	* src/system.c: New file.
	* src/Makefile.am: Added system.c
	* src/common.h: Prototypes for functions from system.c
	* src/system.h (SET_BINARY_MODE, ERRNO_IS_EACCESS): New defines
	* src/buffer.c: Moved system dependencies to system.c
	* src/compare.c: Likewise.
	* src/create.c: Likewise.
	* src/delete.c: Likewise.
	* src/extract.c: Likewise.
	* src/rtapelib.c: Likewise.

2003-10-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	Implemented --occurrence option.

	* NEWS: Updated.
	* src/tar.c: New option --occurrence.
	* src/common.h (occurrence_option): New global
	(struct name): Changed `found' member to `uintmax_t
	found_count'.
	(names_done): Removed
	(all_names_found): Changed prototype.
	(ISFOUND,WASFOUND): New macros
	* src/delete.c (delete_archive_members): Honor --occurrence
	option.
	* src/list.c (read_and): Likewise.
	* src/names.c: Count number of occurrences of each name in the
	archive.
	(name_match): Honor --occurrence option.
	(names_done): Removed
	(all_names_found,names_notfound): Rewritten.

2003-10-02  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/tar.c: Removed extra precaution regarding
	subcommand_option == CAT_SUBCOMMAND
	* lib/Makefile.am: Updated

2003-10-02  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/common.h (names_done): New function.
	* src/names.c: Likewise.
	* src/list.c (read_and): Use all_names_found() as `while'
	condition.
	* src/tar.c: New option --first-copy
	* NEWS: Updated

2003-09-24  Paul Eggert  <eggert@twinsun.com>

	* src/rmt.c (main): Don't translate Copyright string; international
	law says the word "Copyright" should be in English.
	* src/tar.c (decode_options): Likewise.

2003-09-22  Paul Eggert  <eggert@twinsun.com>

	* doc/tar.texi (extracting untrusted archives): New section.

	* src/common.h (stripped_path_len): Renamed from cut_path_elements.
	Return size_t, not pointer, so that we don't have to worry about
	violating the C standard by converting char const * to char *.
	All callers changed.
	* src/names.c (stripped_path_len): Likewise.  Strip file system
	prefix, too.  Count adjacent slashes as if they were one slash;
	that is the POSIX standard.

2003-09-17  Paul Eggert  <eggert@twinsun.com>

	* README-alpha: Document maintainer tool assumptions a bit.  GNU
	'sed' is no longer required.  For GNU m4 1.4, suggest the patch in
	Debian bug 211447.  Fix minor misspellings/whitespace nits.

	* configure.ac (AC_AIX, AC_MINIX): Remove; subsumed by
	gl_USE_SYSTEM_EXTENSIONS.

	* lib/.cvsignore: Add exit.h, time_r.c, time_r.h.
	* m4/.cvsignore: Add restrict.m4, time_r.m4.

2003-09-17  Paul Eggert  <eggert@twinsun.com>

	* bootstrap: Don't use "for option; do";
	Solaris 8 /bin/sh doesn't like that.

2003-09-17  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* README-alpha: Updated
	* bootstrap: Updated

2003-09-17  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* README-alpha: Updated
	* bootstrap: Updated
	* po/POTFILES.in: Added src/xheader.c
	* src/common.h (cut_path_elements): Added proto.

2003-09-05  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/buffer.c: Use ngettext where appropriate.
	* src/compare.c: Likewise.
	* src/create.c: Likewise.
	* src/misc.c: Likewise.
	* src/tar.c: Likewise.
	* src/update.c: Likewise.

2003-09-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* .cvsignore: Added *.shar.gz
	* NEWS: Updated
	* TODO: Updated
	* src/common.h (strip_path_elements): New variable.
	* src/extract.c (extract_archive): Implemented --strip-path
	* src/names.c (cut_path_elements): New function.
	* src/tar.c: New option --strip-path=NUM.
	(decode_options) Assign boolean values to bool variables.

2003-09-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/delete.c: Fixed deletion from the POSIX archives.
	* src/list.c (read_header): Minor change.
	* src/tar.c (main): Do not check for volume_label_option
	if subcommand_option is not CREATE_SUBCOMMAND.
	* src/xheader.c (xheader_decode): Store the header as
	well (for eventual delete).

	* tests/incremen.sh: Explicitly request GNU format. This will
	disappear when GNU extended header keywords are working.
	* tests/multiv01.sh: Likewise
	* tests/volume.sh: Likewise

2003-09-04  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/create.c: Support for "linkpath" extended keyword.
	* src/xheader.c (decode_record): Reversed the return
	condition.

2003-09-03  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* configure.ac: Allow to redefine the default output format.
	* src/tar.c: Use DEFAULT_ARCHIVE_FORMAT macro
	(archive_format_string): New function.
	(usage): Updated help output.
	* README: Updated.
	* NEWS: Updated.
	* TODO: Updated.

2003-09-02  Paul Eggert  <eggert@twinsun.com>

	* src/common.h (destroy_stat, xheader_decode, xheader_store,
	xheader_read, xheader_finish, xheader_destroy): Add decls;
	C99 requires this.

	* src/create.c (write_extended): Remove unused local 'bufsize'.

	* src/delete.c (delete_archive_members): Handle case of
	HEADER_SUCCESS_EXTENDED followed by HEADER_FAILURE.
	* src/list.c (read_and): Abort if HEADER_SUCCESS_EXTENDED
	occurs, as it's not possible.
	* src/update.c (update_archive): Likewise.

	Use "const" when possible in new code.
	* src/tar.c (struct fmttab.name): Now char const *.  All uses changed.
	(fmttab): Now const.  All uses changed.
	* src/xheader.c (struct xhdr_tab.keyword): Now pointer to const.
	(struct xhdr_tab.coder, struct xhdr_tab.decoder, locate_handler,
	decode_record, xheader_store, xheader_print, code_string, code_time,
	code_num, dummy_coder, dummy_decoder, atime_coder, atime_decoder,
	gid_coder, gid_decoder, gname_coder, gname_decoder, linkpath_coder,
	linkpath_decoder, ctime_coder, ctime_decoder, mtime_coder,
	mtime_decoder, path_coder, path_decoder, size_coder, size_decoder,
	uid_coder, uid_decoder, uname_coder, uname_decoder):
	Use pointers to const when possible.
	(xhdr_tab): Now const.

	* src/tar.c (fmttab): Avoid GCC warning by not eliding initializers.
	(set_archive_format): Report an error if no format name matches,
	instead of returning an undefined value.

	* src/xheader.c (struct xhdr_tab.decoder, dummy_decoder,
	atime_decoder, gid_decoder, gname_decoder, linkpath_decoder,
	ctime_decoder, mtime_decoder, path_decoder, size_decoder,
	uid_decoder, uname_decoder): Remove unused keyword arg.
	All uses changed.

	* src/tar.c (set_archive_format): Now static.
	* src/xheader.c (xhdr_tab, format_uintmax): Now static.

	* src/xheader.c (dummy_coder, dummy_decoder, atime_coder,
	atime_decoder, gid_coder, gid_decoder, gname_coder, gname_decoder,
	linkpath_coder, linkpath_decoder, mtime_coder, mtime_decoder,
	ctime_coder, ctime_decoder, path_coder, path_decoder, size_coder,
	size_decoder, uid_coder, uid_decoder, uname_coder, uname_decoder):
	Remove forward decls; no longer needed.
	(xhdr_tab): Move to end, so that the forward decls aren't needed.
	Add a forward declaration.

	Use 'bool' in new code, when appropriate.
	* src/xheader.c (decode_record): Return bool, not int.
	* src/common.h (read_header): Since it accepts bool, change
	all callers to use false and true rather than 0 and 1.

	* src/xheader.c (decode_record): Fix misspelling in diagnostic
	"extended headed" -> "extended header".

	GNU coding style fixes.
	* src/xheader.c (decode_record, xheader_decode):
	Do not use decls like "char *p, *q;".

	Minor style fixes.
	(xheader_store): Avoid parentheses around object operand of sizeof.

2003-09-03  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/create.c (start_header): Store long file names
	in "path" keyword of an extended header if in POSIX
	mode.
	(finish_header): print header before calling write_extended().
	* src/list.c (list_archive): Always decode the header. This
	is necessary so the extended header is processed and the correct
	filename is printed no matter what the state of verbose_option.
	* src/xheader.c (xhdr_tab): Reserved GNU keywords (commented out
	for the time being).

2003-09-01  Paul Eggert  <eggert@twinsun.com>

	Update from gnulib, and correct fnmatch to fnmatch-gnu.
	* bootstrap (gnulib_modules): Change fnmatch to fnmatch-gnu.
	Sort.
	* configure.ac (gl_USE_SYSTEM_EXTENSIONS): Use this instead
	of AC_GNU_SOURCE.
	* lib/.cvsignore: Add alloca.h, stdbool.h.  Sort.  Append newline.
	* lib/Makefile.am (lib_OBJECTS): New macro, for convenience when
	copying rules from gnulib module descriptions.
	(BUILT_SOURCES, EXTRA_DIST, all-local, alloca.h):
	Update from gnulib modules alloca, fnmatch, getline, stdbool.
	* m4/.cvsignore: Add utimes-null.m4.  Sort.

2003-09-01  Sergey Poznyakoff

	Added initial support for creating POSIX headers.

	* src/common.h (MAXOCTAL11,MAXOCTAL7): New defines
	(string_to_chars): New functions
	(struct xheader): Changed structure
	(gid_to_gname,gname_to_gid,uid_to_uname,uname_to_uid): Changed
	prototypes.
	* src/create.c (string_to_chars): New function.
	(write_extended): New function
	(start_header): Create extended POSIX headers if necessary.
	(finish_header): Likewise.
	* src/list.c (print_header): Take user/group from
	current_stat_info.
	* src/names.c (gid_to_gname,gname_to_gid)
	(uid_to_uname,uname_to_uid): Changed prototypes.
	* src/tar.c: New option --format.
	* src/tar.h (OLDGNU_COMPATIBILITY): Removed
	(struct extra_header): Removed unused structure.
	(union block.extra_header): Removed unused member.
	* src/xheader.c: Implemented coder functions.
	* bootstrap: Added obstack.
	* lib/.cvsignore: Likewise.
	* configure.ac: Added 'gl_OBSTACK'
	* m4/Makefile.am: Added new files.
	* m4/.cvsignore: Likewise.
	* TODO: Minor formatting change

2003-08-31  Sergey Poznyakoff

	Added initial support for POSIX extended and STAR headers
	(only for listing/extracting).

	* src/xheader.c: New file.
	* src/Makefile.am: Added xheader.c
	* src/tar.h (struct star_header): New datatype
	(XHDTYPE,XGLTYPE): New defines
	(enum archive_format:STAR_FORMAT): New member
	(struct tar_stat_info): New datatype.
	(union block.star_header): New member.
	* src/common.h (orig_file_name,current_file_name)
	(current_trailing_slash,current_link_name): Removed variables.
	(current_stat_info): New variable
	(current_stat): Removed
	(extended_header): New variable
	(decode_header): Changed prototype.
	* src/list.c (decode_header): Added initial support for POSIX extended
	and STAR headers.
	(skip_member): Check oldgnu_header only if current_format is set
	to OLDGNU_FORMAT.
	* src/buffer.c: Use current_stat_info
	* src/compare.c: Likewise.
	* src/create.c: Likewise.
	* src/delete.c: Likewise.
	* src/incremen.c: Likewise.
	* src/mangle.c: Likewise.
	* src/update.c: Likewise.
	* src/extract.c: Likewise.
	(make_directories): Improved check for the existence of the directory
	* src/tar.c (destroy_stat): New function.

2003-08-29  Paul Eggert  <eggert@twinsun.com>

	* NEWS, bootstrap: Drop en_GB locale; it was more trouble than it
	was worth (e.g., different users in en_GB disagree about -ize
	versus -ise).
	* po/en_GB.po: Remove.

2003-07-28  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* TODO: Updated
	* NEWS: Updated
	* src/tar.c: Removed support for the obsolete command line
	options.
	* doc/tar.texi: Removed references to the obsolete command
	line options.

2003-07-27  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* TODO: Updated
	* NEWS: Updated
	* doc/tar.texi: Updated
	* src/common.h (check_links_option): New variable
	(orig_file_name): New variable
	(check_links): New proto.
	* src/create.c (struct link.nlink): New member
	(link_table): Static for the module.
	(dump_file): Update `link' member when adding new links
	to the link_table.
	(check_links): New function.
	* src/list.c (print_header): Use orig_file_name.
	* src/tar.c: New option --check-links. Changed semantics of
	-o to comply to UNIX98 when extracting and to its previous
	semantics otherwise.
	(main): Call check_links if --check-links. was given.

2003-07-25  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* src/list.c (print_header): Revised
	* NEWS: Started the entry for 1.13.26
	* doc/Makefile.am (tar.dvi): Fixed TEXINPUTS value.

2003-07-24  Sergey Poznyakoff  <gray@Mirddin.farlep.net>

	* .cvsignore: Added to the repository.
	* doc/.cvsignore: Likewise.
	* lib/.cvsignore: Likewise.
	* m4/.cvsignore: Likewise.
	* po/.cvsignore: Likewise.
	* scripts/.cvsignore: Likewise.
	* src/.cvsignore: Likewise.
	* tests/.cvsignore: Likewise.

	* lib/Makefile.am: Added exitfail.[hc]
	* src/misc.c (chdir_do): Fixed call to restore_cwd
	* src/buffer.c (flush_read): Fixed behavior on short
	reads right after opening the new archive (multiv01.sh test).
	(new_volume): Special handling for "-".
	* src/list.c (print_header): Print trailing slash if
	current_trailing_slash was set (extrac03.sh,extrac04.sh tests).
	* tests/multiv01.sh: Minor changes.
	* m4/Makefile.am: Added missing files.

2003-07-05  Paul Eggert  <eggert@twinsun.com>

	Finish the checkin begin yesterday.

	* NEWS: Document the user-visible changes installed in the last
	two days.

	* TODO: New file (actually, resurrected; but with new contents).

	* src/list.c (read_and): Give full type for procedure arg.
	(read_header): Strip trailing slashes, setting current_trailing_slash.
	(tartime): Avoid int overflow when printing year (!).
	(print_header): New arg specifying block ordinal.  All uses changed.
	Print link as 'h' type.  Give labels for long links and names.

	* src/misc.c (contains_dot_dot): Moved to names.c
	(must_be_dot_or_slash): New function.
	(safer_rmdir): Use it.
	(remove_any_file): Now takes enum as option, not boolean.
	Check for (Linux) EISDIR as well as (POSIX) EPERM when attempting
	to unlink a directory.
	(deref_stat): Accept bool, not int.

	* src/names.c (namelist_match): Allow partial matches only if
	recursive.
	(hash_string_hasher): Renamed from hash_avoided_name.
	(hash_string_compare): Renamed from compare_avoided_anames.
	(hash_string_insert, hash_string_lookup): New functions.
	(add_avoided_name, is_avoided_name): Use them.
	(safer_name_suffix): New function.
	(contains_dot_dot): Moved here from misc.c.  Now returns bool, not int.

	* src/rmt.c: Don't include print-copyr.h.
	(prepare_input_buffer): New arg FD.
	Do not read more than INT_MAX bytes at once,
	since it breaks on some brain damaged Tru64 hosts.
	Divide size by two
	when retrying instead of subtracting 1024; for speed.
	(main): Use gettext to translate (C), not print_copyright.

	* src/system.h: Include <alloca.h> and <stdbool.h> unconditionally,
	now that gnulib handles this.
	Include <stddef.h> and <limits.h> unconditionally, now that we assume
	C89 or better.
	Assume that offsetof is defined in stddef.h.
	Do not include <sys/param.h>.
	(realloc, lseek): Do not declare.
	(HAVE_DECL_VALLOC): Renamed from HAVE_VALLOC.
	(CHAR_BIT, CHAR_MAX, UCHAR_MAX, LONG_MAX): Remove
	declarations, since we now assume C89 or better.
	(PARAMS): Remove, as we now assume C89.  All uses changed.
	(bindtextdomain, textdomain): Include <gettext.h> to define.
	Include <unlocked-io.h>.
	(valloc): Define if not defined, and if valloc is not declared.
	(xstrdup): Remove decl.

	* src/tar.c: Do not include <print-copyr.h>.
	Include <getdate.h>.
	(get_date): Remove decl.
	(ATIME_PRESERVE_OPTION, CHECKPOINT_OPTION, FORCE_LOCAL_OPTION,
	IGNORE_FAILED_READ_OPTION, INDEX_FILE_OPTION, NO_OVERWRITE_DIR_OPTION,
	NUMERIC_OWNER_OPTION, RECURSIVE_UNLINK_OPTION, REMOVE_FILES_OPTION,
	SHOW_OMITTED_DIRS_OPTION, TOTALS_OPTION): New constants.
	(long_options, decode_options): Use them.
	(OVERWRITE_DIR_OPTION): Remove.
	(long_options): New options --index-file, --no-overwrite-dir.
	Remove --overwrite-dir option.
	(usage): Use PACKAGE_BUGREPORT.
	(decode_options): Terminate new argv properly.
	Use PACKAGE_NAME, PACKAGE_VERSION.
	If verbose, report how we grokked any textual date option.
	(main): Add support for index-file.

	* tests/Makefile.am: Convert to UTF-8.
	(AUTOMAKE_OPTIONS): Remove.
	(TESTS): Add delete04.sh, multiv01.sh, options.sh.
	(INCLUDES): Remove ../intl.
	(LDADD): Don't link libtar.a twice.

	* tests/genfile.c: Convert to UTF-8.
	Don't include <print-copyr.h>.
	(DEFAULT_PATTERN): Renamed from DEFAULT.
	(ZEROS_PATTERN): Renamed from ZEROS.
	(main): Use gettext to translate (C), not print_copyright.

2003-07-04  Paul Eggert  <eggert@twinsun.com>

	Revamp to meet current standards of autoconf, automake,
	gettext, and gnulib, and incorporate new translations.

	* config/config.guess, config/config.sub, config/depcomp,
	config/install-sh, config/mdate-sh, config/missing,
	config/mkinstalldirs, config/texinfo.texi:
	Moved here from parent directory, or from doc.
	* config.hin: Renamed from config.h.in.
	* config/config.rpath: New file.

	* intl: Remove this subdirectory.

	* lib/fnmatch_.h: Renamed from lib/fnmatch.hin.

	* lib/getstr.c, lib/getstr.h, lib/msleep.c, lib/print-copyr.c,
	lib/print-copyr.h, lib/readutmp.c, lib/rename.c, lib/stpcpy.c,
	lib/strstr.c, lib/strtoimax.c, lib/strtoll.c, lib/strtoull.c,
	lib/strtoumax.c, lib/unicodeio.c, lib/unicodeio.h,
	lib/xstrtoimax.c, m4/c-bs-a.m4, m4/ccstdc.m4, m4/check-decl.m4,
	m4/decl.m4, m4/jm-mktime.m4, m4/prereq.m4, m4/xstrtoimax.m4,
	stamp-h.in: Remove.

	* lib/alloca_.h, lib/fnmatch_loop.c, lib/gettext.h, lib/pathmax.h,
	lib/safe-write.c, lib/safe-write.h, lib/stdbool_.h, lib/strcase.h,
	lib/stripslash.c, lib/unlocked-io.h, lib/xgetcwd.h, m4/alloca.m4,
	m4/backupfile.m4, m4/bison.m4, m4/chown.m4, m4/dirname.m4,
	m4/dos.m4, m4/exclude.m4, m4/fileblocks.m4, m4/ftruncate.m4,
	m4/getdate.m4, m4/getopt.m4, m4/hash.m4, m4/human.m4,
	m4/intdiv0.m4, m4/intmax_t.m4, m4/inttypes-pri.m4,
	m4/inttypes_h.m4, m4/isc-posix.m4, m4/lchown.m4, m4/lib-ld.m4,
	m4/lib-link.m4, m4/lib-prefix.m4, m4/memset.m4, m4/mktime.m4,
	m4/modechange.m4, m4/nls.m4, m4/onceonly.m4, m4/pathmax.m4,
	m4/po.m4, m4/quote.m4, m4/quotearg.m4, m4/rmdir.m4,
	m4/safe-read.m4, m4/safe-write.m4, m4/save-cwd.m4, m4/savedir.m4,
	m4/ssize_t.m4, m4/stdbool.m4, m4/stdint_h.m4, m4/strcase.m4,
	m4/strtoimax.m4, m4/strtol.m4, m4/strtoll.m4, m4/strtoul.m4,
	m4/strtoull.m4, m4/strtoumax.m4, m4/tm_gmtoff.m4, m4/uintmax_t.m4,
	m4/unlocked-io.m4, m4/xalloc.m4, m4/xgetcwd.m4, m4/xstrtol.m4,
	po/LINGUAS, po/Makevars, po/Rules-quot, po/boldquot.sed,
	po/en@boldquot.header, po/en@quot.header, po/en_GB.po,
	po/insert-header.sin, po/remove-potcdate.sin, po/stamp-po: New files.

	* ABOUT-NLS, INSTALL, lib/addext.c, lib/alloca.c, lib/argmatch.c,
	lib/argmatch.h, lib/backupfile.c, lib/backupfile.h, lib/dirname.c,
	lib/dirname.h, lib/error.c, lib/exclude.c, lib/exclude.h,
	lib/fnmatch.h, lib/full-write.c, lib/full-write.h, lib/getdate.h,
	lib/getdate.y, lib/getline.c, lib/getline.h, lib/getopt.c,
	lib/getopt.h, lib/getopt1.c, lib/hash.c, lib/hash.h, lib/human.c,
	lib/human.h, lib/lchown.c, lib/malloc.c, lib/mktime.c,
	lib/modechange.c, lib/modechange.h, lib/quote.c, lib/quote.h,
	lib/quotearg.c, lib/quotearg.h, lib/realloc.c, lib/safe-read.c,
	lib/safe-read.h, lib/save-cwd.c, lib/save-cwd.h, lib/savedir.c,
	lib/savedir.h, lib/strcasecmp.c, lib/utime.c, lib/xalloc.h,
	lib/xgetcwd.c, lib/xmalloc.c, lib/xstrdup.c, lib/xstrtol.c,
	lib/xstrtol.h, lib/xstrtoumax.c, m4/codeset.m4, m4/d-ino.m4,
	m4/error.m4, m4/fnmatch.m4, m4/getcwd.m4, m4/getline.m4, m4/gettext.m4,
	m4/glibc21.m4, m4/iconv.m4, m4/inttypes.m4, m4/lcmessage.m4,
	m4/longlong.m4, m4/malloc.m4, m4/mbrtowc.m4, m4/mbstate_t.m4,
	m4/progtest.m4, m4/realloc.m4, m4/strerror_r.m4, m4/ulonglong.m4,
	m4/utimbuf.m4, m4/utime.m4, m4/utimes.m4, m4/xstrtoumax.m4,
	po/Makefile.in.in:
	Upgrade to latest version from external source.  The file "bootstrap"
	now grabs these automatically, so we needn't keep track of them
	in this change long any longer.

	* Makefile.am (AUTOMAKE_OPTIONS): Remove.  Now done by configure.ac.
	(SUBDIRS): Remove intl.
	* PORTS: Update for star, Macintosh.
	* README, README-alpha: Suggest Autoconf 2.57, Automake 1.7.5,
	Bison 1.875, gettext 0.12.1.
	* THANKS: Add Bernhard Rosenkraenzer, Solar Designer.
	* configure.ac (AC_INIT, AM_INIT_AUTOMAKE): Convert to modern form.
	(AC_CONFIG_AUX_DIR): New.
	(AC_CONFIG_HEADERS): Rename config.h.in to config.hin, to be more
	like coreutils.
	(AC_PREREQ): Bump from 2.52 to 2.57.
	(AC_GNU_SOURCE): New.
	(AC_PROG_GCC_TRADITIONAL, AM_C_PROTOTYPES, AC_C_CONST): Remove;
	we no longer support K&R C.
	(YACC): Remove.
	(AC_CHECK_HEADERS): Remove limits.h, poll.h, stdbool.h, stropts.h,
	sys/ioccom.h, sys/param.h, sys/time.h, sys/timeb.h, wchar.h, wctype.h.
	(AC_MBSTATE_T): Remove.
	(HAVE_UTIME_H, HAVE_DECL_FREE, HAVE_DECL_GETGRGID, HAVE_DECL_GETPWUID,
	HAVE_DECL_GETENV, HAVE_DECL_MALLOC, HAVE_DECL_STRTOUL,
	HAVE_DECL_STRTOULL, HAVE_MKNOD): Remove our special code.
	(AM_STDBOOL_H): Add.
	(AC_HEADER_TIME, AC_STRUCT_TIMEZONE,
	jm_CHECK_TYPE_STRUCT_DIRENT_D_INO): Remove.
	(AC_CHECK_TYPE): Remove ssize_t.
	(gt_TYPE_SSIZE_T): Add.
	(jm_AC_PREREQ_XSTRTOUMAX, jm_PREREQ_ADDEXT, jm_PREREQ_ERROR,
	jm_PREREQ_HUMAN, jm_PREREQ_QUOTEARG, jm_PREREQ_XGETCWD,
	AC_FUNC_ALLOCA, AC_FUNC_CLOSEDIR_VOID, AC_FUNC_STRERROR_R,
	AC_FUNC_FNMATCH, AC_FUNC_VPRINTF, AM_FUNC_GETLINE, jm_FUNC_MALLOC,
	jm_FUNC_MKTIME, jm_FUNC_REALLOC):
	Remove.  Switch to gnulib macros like gl_BACKUPFILE instead.
	(tar_LDADD): Rename to LIB_CLOCK_GETTIME.  All uses changed.
	(rmt_LDADD): Rename to LIB_SETSOCKOPT.  All uses changed.
	(AC_CHECK_FUNCS): Remove fchdir, ftime, getcwd, isascii, nap,
	napms, poll, select, strstr, usleep.
	(AC_REPLACE_FUNCS): Remove ftruncate, lchown, memset, rename,
	rmdir, strcasecmp, strncasecmp, strtol, strtoul.
	(AM_GNU_GETTEXT): Use external and need-ngettext options.
	(AM_GNU_GETTEXT_VERSION): New.
	(AC_OUTPUT): Remove intl/Makefile.

	* doc/Makefile.am (AUTOMAKE_OPTIONS): Remove.
	($(srcdir)/tar.info, tar.dvi): Remove obsolete warnings.
	* doc/fdl.texi: Update to current GNU version.
	* doc/gettext.texi: Update to current coreutils version,
	plus a copyright notice.
	* doc/tar.texi: Switch to new method for doing copyright notices.
	Use @acronym instead of @sc where appropriate.
	Remove empty examples.  Give a few more examples.

	* lib/Makefile.am (AUTOMAKE_OPTIONS): Remove.
	(EXTRA_DIST, libtar_a_SOURCES): Switch to gnulib, so that they
	are built up in pieces with +=.
	(noinst_HEADERS, INCLUDES): Remove.
	(BUILT_SOURCES, MAINTAINERCLEANFILES, MOSTLYCLEANFILES): New.
	(libtar_a_LIBADD): Use $ rather than @.
	(all-local, alloca.h, fnmatch.h, stdbool.h): New rules, from gnulib.

	* m4/Makefile.am (EXTRA_DIST): Add alloca.m4, backupfile.m4,
	bison.m4, chown.m4, dirname.m4, dos.m4, exclude.m4, fileblocks.m4,
	ftruncate.m4, getdate.m4, getopt.m4, hash.m4, human.m4,
	intdiv0.m4, intmax_t.m4, inttypes_h.m4, inttypes-pri.m4,
	isc-posix.m4, lcown.m4, lib-ld.m4, lib-link.m4, lib-prefix.m4,
	memset.m4, mktime.m4, modechange.m4, nls.m4, onceonly.m4,
	pathmax.m4, po.m4, quotearg.m4, quote.m4, rmdir.m4, safe-read.m4,
	safe-write.m4, save-cwd.m4, savedir.m4, ssize_t.m4, stdbool.m4,
	stdint_h.m4, strcase.m4, strtoimax.m4, strtoll.m4, strtol.m4,
	strtoull.m4, strtoul.m4, strtoumax.m4, tm_gmtoff.m4, uintmax_t.m4,
	unlocked-io.m4, xalloc.m4, xgetcwd.m4, xstrtol.m4.
	Remove c-bs-a.m4, ccstdc.m4, check-decl.m4, decl.m4, jm-mktime.m4,
	prereq.m4, xstrtoimax.m4.

	* po/POTFILES.in: Remove tests/genfile.c; it doesn't need to
	be translated, since it's not a user-visible tool.

	* scripts/Makefile.am (AUTOMAKE_OPTIONS): Remove.

	* src/Makefile.am (AUTOMAKE_OPTIONS): Remove.
	(INCLUDES): Remove ../intl.  Put top-srcdir before ., for
	consistency with coreutils.
	(LDADD): Link LIBINTL after libtar.a, since
	it's now external and should stand by itself.

	* src/buffer.c (print_total_written): Adjust to new human.h
	interface.
	(child_open_for_compress): Do not increase size to BLOCKSIZE.
	(open_archive): Open index file name.
	Strip trailing slahes from file names.
	(flush_write): Set size to 0 if not saving names.
	(flush_write, flush_read): Use safer_name_suffix rather than
	inline code.

	* src/common.h: Include <quote.h>.
	(absolute_names_option, atime_preserve_option, backup_option,
	block_number_option, checkpoint_option, dereference_option,
	force_local_option, ignore_failed_read_option, ignore_zeros_option,
	incremental_option, interactive_option, multi_volume_option,
	numeric_owner_option, one_file_system_option, recursive_unlink_option,
	read_full_records_option, remove_files_option, same_order_option,
	show_omitted_dirs_option, sparse_option, starting_file_option,
	to_stdout_option, totals_option, touch_option, verify_option,
	dev_null_output, now_verifying, we_are_root): Now bool, not int.
	(current_trailing_slash, index_file_name, recent_long_name_blocks,
	recent_long_link_blocks): New vars.
	(NO_OVERWRITE_DIR_OLD_FILES): New constant.
	(OVERWRITE_OLD_DIRS): Remove.
	(enum remove_option): New enum.
	(remove_any_file): Use it as option arg, not int.
	(is_avoided_name, contains_dot_dot): Return bool, not int.
	(safer_name_suffix): New decl.

	* src/compare.c (now_verifying): Now bool, not int.
	(fill_in_sparse_array): Move to extract.c.  Now returns bool;
	all callers changed to test for failure.
	(diff_sparse_files): Take size from current_stat, not from param.
	(diff_archive): Do not count trailing slashes in archives.
	(verify_volume): Test for header failure after loop, not before.

	* src/create.c (relativize): Remove; replaced by safer_name_suffix.
	All callers changed.
	(start_header): Clear devmajor and devminor fields, too.
	(finish_header): New arg block_ordinal.
	(init_sparsearray): Now extern.  Set sp_array_size to
	SPARSES_IN_OLDGNU_HEADER if it is zero.
	(dump_file): Keep link table as a hash.
	Do not count "file changed as we read it" as a failure.

	* src/delete.c (recent_long_name_blocks, recent_long_link_blocks):
	Move extern decl to common.h.

	* src/extract.c (we_are_root): Now bool, not int.
	(check_time): Warn about implausibly old time stamps.
	(set_stat): Use utimbuf, not stat_info.
	(prepare_to_extract): New arg DIRECTORY.
	(fill_in_sparse_array): Moved here from compare.c.
	(extract_sparse_file): Now returns off_t, giving size left.
	Truncate file at end.
	(extract_archive): Use safer_name_suffix rather than rolling our own.
	Use fill_in_sparse_array rather than rolling our own.
	Strip trailing slashes more effectively.
	Check for unsafe names.

	* src/incremen.c (struct directory): nfs and found are now of type
	bool, not int.
	(gnu_restore): Now takes directory name as argument, not offset
	of directory name in a global.  All uses changed.
	(CURRENT_FILE_NAME): Remove.

	New tests.
	* tests/delete04.sh, tests/multiv01.sh, tests/options.sh: New
	files.

2002-09-30  Paul Eggert  <eggert@twinsun.com>

	* src/rmt.c (prepare_input_buffer): Renamed form
	prepare_record_buffer.  All uses changed.  Do not assume that
	size_t is the same width as int.

2002-03-29  Paul Eggert  <eggert@twinsun.com>

	* src/incremen.c (get_directory_contents):
	If ignore_failed_read_option, only warn about
	get_directory_contents failures.  Fix suggested by
	Mark Costlow.

2002-01-31  Mark W. Eichin  <eichin@thok.org>

	* src/buffer.c (child_open_for_compress): Don't try to read
	past the end of the buffer.

2001-10-11  Jim Meyering  <meyering@lucent.com>

	* argmatch.c (argmatch_invalid): Use quotearg_n_style (0, ...
	and quote_n (1, ... to avoid clobbering a buffer.

2001-09-26  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.ac (AM_INIT_AUTOMAKE): Version 1.13.25.

	* src/buffer.c (flush_read): Don't diagnose partial blocks before
	end of file; just ignore them silently.

	* src/list.c (read_header): Don't keep around extended name
	and link info indefinitely; keep it only for the next file.
	This fixes a bug introduced in 1.13.24, and removes the need
	for some static variables.  Set recent_long_name and
	recent_long_link to zero if there were no long links; this
	avoids a violation of ANSI C rules for pointers in delete.c.
	* THANKS: Add Christian Laubscher.

2001-09-26  Jim Meyering  <meyering@lucent.com>

	* doc/tar.texi (Remote Tape Server): is know -> is known

2001-09-25  Paul Eggert  <eggert@twinsun.com>

	* lib/unicodeio.c (EILSEQ): Include <iconv.h> first, since
	<iconv.h> may define EILSEQ (e.g. libiconv).  Define a
	replacement EILSEQ to be ENOENT, not EINVAL, since callers may
	want to distinguish EINVAL and EILSEQ.

2001-09-24  Christophe Kalt  <Christophe.Kalt@kbcfp.com>

	* src/extract.c (maybe_recoverable):
	Treat OVERWRITE_OLD_DIRS like DEFAULT_OLD_FILES.

2001-09-22  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.ac (AM_INIT_AUTOMAKE): Version 1.13.24.

	* ABOUT-NLS, intl/*: Update to gettext-0.10.40, replacing LGPL
	with GPL.

	* INSTALL, mkinstalldirs: Update to autoconf 2.52 version.
	* PORTS: Add copyright notice, 'star' reference.
	* README-alpha: Add copyright notice, autoconf 2.52 patch.
	* THANKS: Add Christophe Kalt.
	* config.sub: Upgrade to 2001-09-14 version.

	* configure.ac (ALL_LINGUAS): Add ko.
	* po/ko.po: Resurrected file.

	* doc/convtexi.pl: Add coding advice for Emacs.

	* doc/getdate.texi: Add copyright notice.

	* doc/mdate-sh: Upgrade to automake 1.5 version.

	* doc/tar.texi (extracting files): Mention --to-stdout.
	(Option Summary, Dealing with Old Files): New option --overwrite-dir.
	(Overwrite Old Files): Likewise.

	* lib/Makefile.am (noinst_HEADERS):
	Remove copysym.h.  Add print-copyr.h, unicodeio.h.
	(libtar_a_SOURCES): Remove copysym.c, Add print-copyr.c, unicodeio.c.

	* lib/copysym.c, lib/copysym.h: Remove.
	* lib/print-copyr.c, lib/print-copyr.h, lib/unicodeio.c,
	lib/unicodeio.h: New files.

	* lib/error.c, lib/getopt.c, lib/getopt.h, lib/getopt1.c,
	lib/mktime.c, lib/strtoll.c: Switch from LGPL to GPL.

	* lib/quotearg.c (HAVE_MBSINIT): Undef if !HAVE_MBRTOWC.
	(mbsinit): Define to 1 if !defined mbsinit && !HAVE_MBSINIT.

	* m4/Makefile.am (EXTRA_DIST): Remove isc-posix.m4.
	* m4/isc-posix.m4: Remove.

	* m4/prereq.m4 (jm_PREREQ_QUOTEARG): Check for mbsinit.

	* po/POTFILES.in: Add copyright notice.

	* src/Makefile.am (LDADD): Like libtar.a before @INTLLIBS@ as
	well as after.
	* tests/Makefile.am (LDADD): Likewise.

	* src/buffer.c (write_archive_buffer, close_archive):
	If an archive is a socket, treat it like a FIFO.
	(records_read, records_written): New vars.
	(write_archive_to_stdout): Now bool, not int.
	(open_archive, flush_write, flush_read): Keep records_read and
	records_written up to date.

	* src/common.h (enum old_files): New value OVERWRITE_OLD_DIRS.
	(write_archive_to_stdout): Now bool, not int.
	(enum read_header): New value HEADER_SUCCESS_EXTENDED.
	(read_header): Now takes bool arg.  Existing callers modified
	to pass 0, unless otherwise specified.

	* src/delete.c (records_read): Remove; now a global.
	(acting_as_filter): Now bool, not int.
	(recent_long_name, recent_long_link, recent_long_name_blocks,
	recent_long_link_blocks, records_read, records_written): New decls.
	(records_skipped): New var.
	(move_archive): Don't divide by zero if arg is 0.
	Use the above vars to compute how far to move.
	(write_recent_blocks): New function.
	(delete_archive_member): Pass 1 to read_header, so that it doesn't
	read more than 1 block.  Handle resulting HEADER_SUCCESS_EXTENDED code.
	Keep track of how many records have been skipped.
	Let the buffer code count records.
	When copying a header, copy any extended headers that came before it.

	* src/extract.c (extract_archive): When marking a directory to be
	updated after symlinks, stat all directories after it in the
	delayed-set-stat list too, since they will be checked after
	symlinks.  Add support for --overwrite-dir.

	* src/list.c (recent_long_name, recent_long_link,
	recent_long_name_blocks, recent_long_link_blocks): New vars.
	(read_and): Pass 0 to read_header.
	(read_header): New arg RAW_EXTENDED_HEADERS.  Store away extended
	headers into new vars.  Null-terminate incoming symbolic links.

	* src/rmt.c: Include print-copyr.h, not copysym.h.
	(main): Use print_copyright, not copyright_symbol.
	* src/tar.c (decode_options): Likewise.
	(OVERWRITE_DIR_OPTION): New constant.
	(long_options, usage, decode_options): Add --overwrite-dir.

	* src/tar.h: Put copyright notice into documentation.

	* tests/Makefile.am (TESTS): Add delete03.sh.
	* tests/delete03.sh: New file.

	* tests/genfile.c: Include print-copyr.h, not copysym.h.
	(main): Use print_copyright, not copyright_symbol.
	Include <argmatch.h>.
	(pattern_strings): Remove.
	(pattern_args, pattern_types): New constants.
	(main): Use XARGMATCH, not argmatch.

2001-09-20  Jim Meyering  <meyering@lucent.com>

	* lib/xstrtol.c (strtoimax): Guard declaration with
	`#if !HAVE_DECL_STRTOIMAX', rather than just `#ifndef strtoimax'.
	The latter fails because some systems (at least rs6000-ibm-aix4.3.3.0)
	have their own, conflicting declaration of strtoimax in sys/inttypes.h.
	(strtoumax): Likewise, for completeness (it wasn't necessary).
	* m4/xstrtoimax.m4 (jm_AC_PREREQ_XSTRTOIMAX):
	Check for declaration of strtoimax.
	* m4/xstrtoumax.m4 (jm_AC_PREREQ_XSTRTOUMAX):
	Check for declaration of strtoumax.

2001-09-16  Paul Eggert  <eggert@twinsun.com>

	* fnmatch.m4 (jm_FUNC_FNMATCH): Fix typo in previous patch: yes -> no.

2001-09-14  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.ac (AC_INIT_AUTOMAKE): Version 1.13.23.

	* README-alpha: Describe automake patch.

	* configure.ac (LIBOBJS):
	Remove automake 1.4 workaround, as we're using 1.5 now.
	(USE_INCLUDED_LIBINTL): New AC_DEFINE.

	* lib/copysym.c: Include stddef.h, for size_t.
	Include langinfo.h if needed.
	Use locale_charset only if USE_INCLUDED_LIBINTL;
	if not, use nl_langinfo (CODESET) if available.

2001-09-13  Paul Eggert  <eggert@twinsun.com>

	* config.guess, config.sub: Sync with canonical versions.

	* configure.ac (jm_PREREQ_XGETCWD): Add.

	* lib/Makefile.am (noinst_HEADERS): Add copysym.h.
	(libtar_a_SOURCES): Add copysym.c.
	* copysym.c, copysym.h: New files.

	* lib/error.c: Sync with fileutils version.

	* m4/Makefile.am (EXTRA_DIST): Add getcwd.m4; remove uintmax_t.m4.
	* m4/getcwd.m4: New file.
	* m4/uintmax_t.m4: Remove.

	* m4/gettext.m4 (AM_WITH_NLS):
	Fix bug with calculating version of Bison 1.29.
	Reported by Karl Berry.

	* src/Makefile.am (datadir): Remove.

	* src/rmt.c: Include copysym.h.
	(main): Use copyright_symbol to translate copyright notice,
	instead of gettext.
	* src/tar.c: Likewise.
	* tests/genfile.c: Likewise.

	* src/system.h (MB_LEN_MAX): New symbol.

2001-09-11  Paul Eggert  <eggert@twinsun.com>

	* src/extract.c (struct delayed_set_stat): New member
	'after_symlinks'.
	(delay_set_stat): Initialize it to 0.
	(set_mode): New arg current_stat_info.  Use it (if nonnull) to avoid
	taking an extra stat ourselves.  All callers changed.
	(set_stat): Likewise.
	(apply_nonancestor_delayed_set_stat): New arg 'after_symlinks'.
	If false, stop when encountering a struct whose 'after_symlinks'
	member is true.  Otherwise, go through all structures but check
	them more carefully.  All callers changed.
	(extract_archive): When extracting a deferred symlink, if its parent
	directory's status needs fixing, then mark the directory as needing
	to be fixed after symlinks.
	(extract_finish): Fix status of ordinary directories, then apply
	delayed symlinks, then fix the status of directories that are
	ancestors of delayed symlinks.

	* src/rtapelib.c (rexec):
	Remove declaration; it ran afoul of prototypes on Crays.
	Reported by Wendy Palm of Cray.

2001-09-06  Paul Eggert  <eggert@twinsun.com>

	* lib/strtoimax.c (HAVE_LONG_LONG):
	Redefine to HAVE_UNSIGNED_LONG_LONG if unsigned.
	(strtoimax): Use sizeof (long), not
	sizeof strtol (ptr, endptr, base),
	to work around bug in IBM C compiler.

2001-09-04  Paul Eggert  <eggert@twinsun.com>

	* lib/xgetcwd.c: Include "xalloc.h".
	(xgetcwd): Do not return NULL when memory is exhausted; instead,
	report an error and exit.

	* m4/prereq.m4 (jm_PREREQ_XREADLINK): New macro.
	(jm_PREREQ): Use it.

2001-09-03  Paul Eggert  <eggert@twinsun.com>

	* m4/prereq.m4 (jm_PREREQ): Add jm_PREREQ_XGETCWD.
	(jm_PREREQ_XGETCWD): New macro.

	* lib/exclude.c (fnmatch_no_wildcards):
	Fix typo that caused us to do case-folding
	search even when that was not desired.  This occurred only in the
	no-wildcard case.

	* lib/xgetcwd.c: Include pathmax.h if not HAVE_GETCWD.
	Do not include xalloc.h.
	(INITIAL_BUFFER_SIZE): New symbol.
	Do not use xmalloc / xrealloc, since the caller is responsible for
	handling errors.  Preserve errno around `free' during failure.
	Do not overrun buffer when using getwd.

	* lib/xgetcwd.c (xgetcwd):
	Use HAVE_GETCWD_NULL, not defined __GLIBC__ && __GLIBC__ >= 2,
	to decide whether to use getcwd (NULL, 0).

2001-09-02  Paul Eggert  <eggert@twinsun.com>

	* lib/xgetcwd.c: Fix typo in local var; from Jim Meyering.

2001-09-01  Jim Meyering  <meyering@lucent.com>

	* exclude.c: Use `""', not `<>' to #include non-system header files.
	(fnmatch_no_wildcards): Rewrite not to use function names, strcasecmp
	and strncasecmp as r-values.  Unixware didn't have declarations.

2001-08-31  Jim Meyering  <meyering@lucent.com>

	* lib/xgetcwd.c (xgetcwd): Reorganize to avoid some duplication.
	Use an initial, malloc'd, buffer of length 128 rather than
	a statically allocated one of length 1024.

2001-08-30  Paul Eggert  <eggert@twinsun.com>

	* lib/utime.c: Include full-write.h.
	* lib/xstrtol.c (strtoimax): New decl.

2001-08-29  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.ac (AC_INIT_AUTOMAKE): Version 1.13.22.

	* src/create.c (dump_file): Relativize link names before dumping.
	This fixes a bug reported by Jose Pedro Oliveira.

	* src/create.c (dump_file): Use offsetof when computing sizes for
	struct hack; this avoids wasted space in some cases.
	* src/incremen.c (note_directory, find_directory): Likewise.
	* src/names.c (name_gather, addname): Likewise.

	* src/extract.c (extract_archive): Use strcpy, not memcpy,
	for consistency with other code that does similar things.
	* src/names.c (name_gather): Likewise.

	* src/names.c (read_name_from_file, name_next, name_gather,
	add_hierarchy_to_namelist): Avoid quadratic behavior when
	reallocating buffers.  Check for buffer size overflow.
	(addname): Avoid unnecessary clearing of memory.

2001-08-29  "Jan D."  <Jan.Djarv@mbox200.swipnet.se>

	* src/extract.c (delay_set_stat): Fix off-by-one error in file
	name size allocation that caused core dumps.

2001-08-28  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.ac (AC_INIT_AUTOMAKE): Version 1.13.21.

	* configure.ac (GNU_SOURCE): Define to 1, not /**/.
	(major_t, minor_t, ssize_t): Use new-style AC_CHECK_TYPE.
	(daddr_t): Remove; no longer used.
	(jm_PREREQ_HUMAN): Add.

	* acconfig.h: Remove; no longer needed.

	* config.guess, config.sub:
	New files, from automake 1.5.  Gettext 0.10.39 needs them.
	* depcomp, missing, mkinstalldirs: Upgrade to automake 1.5.

	* Makefile.am (AUTOMAKE_OPTIONS): Add dist-bzip2.
	(SUBDIRS): Put intl before lib, as gettext requires.

	* ABOUT-NLS: Upgrade to gettext 0.10.39.
	* intl: Upgrade entire directory to gettext 0.10.39.
	* m4/codeset.m4, m4/glibc21.m4, m4/iconv.m4:
	New files, from gettext 0.10.39.
	* m4/gettext.m4, m4/isc-posix.m4, m4/lcmessage.m4, m4/progtest.m4,
	Upgrade to gettext 0.10.39,
	* po/Makefile.in.in: Likewise, except fix a typo in its copying
	permissions.
	* po/cat-id-tbl.c, po/stamp-cat-id:
	Remove; no longer used by gettext 0.10.39.
	* po/ChangeLog: New file.

	* doc/Makefile.am (EXTRA_DIST): Add freemanuals.texi.
	$(srcdir)/tar.texi: Likewise.
	* doc/freemanuals.texi: New file.
	* doc/tar.texi (Free Software Needs Free Documentation): New appendix.
	`fileds' -> `fields'
	* doc/texinfo.tex: Upgrade to version 2001-07-25.07.

	* lib/Makefile.am (EXTRA_DIST): Add strtoll.c, strtoimax.c.
	(noinst_HEADERS): Add quote.h.
	(libtar_a_SOURCES): Add quote.c, xstrtoimax.c.

	* lib/exclude.c: Fix typo in '#include <stdint.h>' directive.

	* lib/full-write.c, lib/savedir.c: Comment fix.

	* lib/pathmax.h: Remove.

	* lib/quote.c, lib/quote.h: New files.

	* lib/xgetcwd.c: Don't include pathmax.h.
	Include stdlib.h and unistd.h if available.
	Include xalloc.h.
	(xmalloc, xstrdup, free): Remove decls.
	(xgetcwd): Don't assume sizes fit in unsigned.
	Check for overflow when computing sizes.
	Simplify reallocation code.

	* lib/xmalloc.c: Quote failure tests.

	* lib/strtoumax.c, lib/xstrtoimax.c: New files.

	* lib/strtoimax.c: Renamed from strtouxmax.c.  Make it more
	similar to strtol.c.
	(UNSIGNED): Renamed from STRTOUXMAX_UNSIGNED.
	(verify): New macro.
	(strtoumax, uintmax_t, strtoull, strtol): Remove.
	(intmax_t, strtoimax, strtol, strtoll): New macros, if UNSIGNED.
	(strtoimax): Renamed from strtoumax.  All uses of unsigned values
	changed to signed values.  Check sizes at compile-time, not
	run-time.  Prefer strtol to strtoll if both work.
	(main): Remove.

	* lib/xstrtol.h (xstrtoimax): New decl.

	* m4/Makefile.am (EXTRA_DIST):
	Add codeset.m4, glibc21.m4, iconv.m4, inttypes.m4,
	longlong.m4, xstrtoimax.m4.

	* m4/inttypes.m4 (jm_AC_HEADER_INTTYPES_H):
	Remove; now done by autoconf.
	(jm_AC_TYPE_INTMAX_T, jm_AC_TYPE_UINTMAX_T): Replace with
	Use AC_CHECK_TYPE instead of merely looking for the header.

	* m4/uintmax_t.m4: Use shorter comment.

	* m4/xstrtoumax.m4 (jm_AC_PREREQ_XSTRTOUMAX):
	Quote first arg of AC_DEFUN.
	Require jm_AC_TYPE_INTMAX_T and jm_AC_TYPE_LONG_LONG since they
	is needed to parse the include file.
	Simplify logic behind the args to AC_REPLACE.

	* src/Makefile.am (OMIT_DEPENDENCIES): Remove.

	* src/ansi2knr.1, src/ansi2knr.c: Remove; wasn't being used.

	* src/rmt.c (main):
	Use "Copyright %d" to simplify the translator's job in the future.
	Advise translator about circle-C.
	* src/tar.c: (decode_options): Likewise.
	* tests/genfile.c (main): Likewise.

2001-08-28  Jim Meyering  <meyering@lucent.com>

	* lib/argmatch.c: Include "quote.h".
	(argmatch_invalid): Quote the context.

	* lib/dirname.c (dir_name): Fix typo on PC platforms.

	* lib/backupfile.c, lib/basename.c, lib/dirname.c, lib/strtoul.c:
	Use single-quote for local .h files.

	* lib/error.h (__attribute__): Don't depend on __STRICT_ANSI__.

	* lib/getopt.c, lib/getopt.h, lib/getopt1.c: Upgrade to recent
	glibc versions.

	* lib/getdate.y (get_date): Initialize tm_isdst to -1 before
	invoking mktime the last time.

	* lib/pathmax.h: Use #if rather than #ifdef for HAVE_UNISTD_H.

	* lib/rename.c: Major rewrite by Volker Borchert to use system
	rename function, but to work around problems with trailing
	slashes.

	* lib/strtoll.c: New file, from glibc.
	* lib/strtoul.c: Update from glibc.

	* lib/strtouxmax.c: Renamed from lib/strtoumax.c.
	Add support for signed numbers, too.
	(strtoul, strtoull): Do not declare if STRTOUXMAX_UNSIGNED
	is not defined.
	(strtol, strtoll): Declare as needed, if STRTOUXMAX_UNSIGNED is
	not defined.
	(strtoumax, uintmax_t, strtoull, strtoul): New macros.
	(main): Use generic names in debugging output.
	* lib/strtoimax.c: Plus add the following changes of my own:
	(main): Use accurate names in debugging output.

	* lib/xgetcwd.c (xgetcwd): Use getcwd if glibc 2 or later.
	Don't use PATH_MAX.

	* m4/c-bs-a.m4, m4/check-decl.m4, m4/d-ino.m4, m4/error.m4,
	m4/getline.m4, m4/jm-mktime.m4, m4/malloc.m4, m4/mbrtowc.m4,
	m4/mbstate_t.m4, m4/realloc.m4, m4/uintmax_t.m4, m4/utimbuf.m4,
	m4/utime.m4, m4/utimes.m4:
	Quote the first argument in each use of AC_DEFUN.

	* m4/getline.m4: Don't use string.h.

	* m4/inttypes.m4, m4/longlong.m4, m4/xstrtoimax.m4: New files.

	* m4/mbrtowc.m4 (jm_FUNC_MBRTOWC): @%:@ -> #.

2001-08-27  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.ac (AC_INIT_AUTOMAKE): Version 1.13.20.

	The biggest change is the new --exclude semantics and options.
	The basic idea was suggested by Gerhard Poul; thanks!

	* NEWS: Describe new --exclude semantics and options, and bug fixes.
	* README: ignfail.sh fails on some NFS hosts.
	* NEWS, README, lib/xstrtol.h: Add copyright notice.

	* Makefile.am (ACLOCAL_AMFLAGS): Add -I m4.
	(M4DIR, ACINCLUDE_INPUTS, $(srcdir)/acinclude.m4):
	Remove; the automake bug has been fixed.
	* acinclude.m4: Remove.

	* configure.ac: Renamed from configure.in.
	(AC_PREREQ): Bump from 2.13 to 2.52.
	(ALL_LINGUAS): Add id, tr.  Remove ko, as po/ko.po (dated
	1997-05-30) has an encoding error.
	(jm_AC_HEADER_INTTYPES_H): Remove; now done by autoconf.
	(AC_FUNC_FNMATCH): Use AC_CONFIG_LINKS, not AC_LINK_FILES.

	* doc/fdl.texi: Update to current GNU version.

	* doc/tar.texi: Put leading '*' in direntry.
	Accommodate new gfdl sectioning.
	New option --recursion (the default) that is the inverse of
	--no-recursion.

	New options --anchored, --ignore-case, --wildcards,
	--wildcards-match-slash, and their negations (e.g., --no-anchored).
	Along with --recursion and --no-recursion, these control how exclude
	patterns are interpreted.  The default interpretation of exclude
	patterns is now --no-anchored --no-ignore-case --recursion
	--wildcards --wildcards-match-slash.

	* lib/Makefile.am (OMIT_DEPENDENCIES): Remove.

	* lib/exclude.c (bool): Declare, perhaps by including stdbool.h.
	(<sys/types.h>): Include only if HAVE_SYS_TYPES_H.
	(<stdlib.h>, <string.h>, <strings.h>, <inttypes.h>, <stdint.h>):
	Include	if available.
	(<xalloc.h>): Include
	(SIZE_MAX): Define if <stdint.h> or <inttypes.h> doesn't.
	(verify): New macro.  Use it to verify that EXCLUDE macros do not
	collide with FNM macros.
	(struct patopts): New struct.
	(struct exclude): Use it, as exclude patterns now come with options.
	(new_exclude): Support above changes.
	(new_exclude, add_exclude_file):
	Initial size must now be a power of two to simplify overflow checking.
	(free_exclude, fnmatch_no_wildcards): New function.
	(excluded_filename): No longer requires options arg, as the options
	are determined by add_exclude.  Now returns bool, not int.
	(excluded_filename, add_exclude):
	Add support for the fancy new exclusion options.
	(add_exclude, add_exclude_file): Now takes int options arg.
	Check for arithmetic overflow when computing sizes.
	(add_exclude_file): xrealloc might modify errno, so don't
	realloc until after errno might be used.

	* lib/exclude.h (EXCLUDE_ANCHORED, EXCLUDE_INCLUDE,EXCLUDE_WILDCARDS):
	New macros.
	(free_exclude): New decl.
	(add_exclude, add_exclude_file): Now takes int options arg.
	(excluded_filename): No longer requires options arg, as the options
	are determined by add_exclude.  Now returns bool, not int.

	* lib/prepargs.c: Include <string.h>; required for C99 since
	we use strlen.

	* lib/quotearg.c:
	BSD/OS 4.1 wchar.h requires FILE and struct tm to be declared.

	* lib/xstrtol.h (_DECLARE_XSTRTOL): Improve quality of
	diagnostic for LONGINT_INVALID_SUFFIX_CHAR.

	* m4/Makefile.am (EXTRA_DIST): Add check-decl.m4, mbrtowc.m4.
	Remove inttypes_h.m4, largefile.m4, mktime.m4.

	* m4/inttypes_h.m4, m4/largefile.m4, m4/mktime.m4: Remove;
	subsumed by Autoconf 2.50.

	* m4/error.m4: Upgrade to serial 2.

	* m4/fnmatch.m4 (jm_FUNC_FNMATCH): Upgrade to serial 4, but
	remove test for GNU C library.  It's not correct, as some
	older glibcs are buggy.

	* m4/getline.m4, m4/malloc.m4: Upgrade to serial 4.

	* m4/prereq.m4: Upgrade to serial 20, but then:
	(jm_PREREQ): Add jm_PREREQ_EXCLUDE.
	(jm_PREREQ_EXCLUDE): New macro.
	(jm_PREREQ_HUMAN): Remove jm_AC_HEADER_INTTYPES_H, as it is subsumed
	by autoconf 2.5x.

	* m4/realloc.m4: Upgrade to serial 4.

	* m4/strerror_r.m4: Revert to serial 1002.

	* m4/uintmax_t.m4: Upgrade to autoconf 2.5x.

	* m4/utimes.m4: Upgrade to latest version (still "serial 3").

	* m4/xstrtoumax.m4: Upgrade to serial 3, but then:
	(jm_AC_PREREQ_XSTRTOUMAX): Remove jm_AC_HEADER_INTTYPES_H, as
	it is now subsumed by autoconf.  Add inttypes.h.

	* po/cs.po, po/da.po, po/de.po, po/es.po, po/et.po, po/fr.po,
	po/it.po, po/pl.po, po/sl.po, po/sv.po: Sync with translation project.

	* src/buffer.c (new_volume): Stop if the script exits with an error.

	* src/common.h (excluded_with_slash, excluded_without_slash):
	Remove, replacing by:
	(excluded): New decl.
	(link_error): New decl.
	(excluded_name): Now returns bool.

	* src/extract.c:
	(struct delayed_symlinks, extract_archive, apply_delayed_symlinks):
	Support hard links to symbolic links.

	(struct delayed_symlink): Remove 'names' member, replacing it with
	'sources' and 'target' member.  All uses changed.

	(struct string_list): New type.

	(delayed_set_stat, extract_archive): Use offsetof when computing sizes
	for struct hack; this avoids wasted space in some cases.

	(extract_archive): Fix test for absolute pathnames and/or "..".
	Use link_error to report errors for links.
	Remove redundant trailing '/' at "really_dir", for all uses, not
	just before invoking mkdir.
	If overwriting old files, do not worry so much about existing
	directories.
	Fix mode computation in the case where the directory exists.

	(apply_delayed_symlinks): If we can't make a hard link to a symbolic
	link, make a copy of the symbolic link.

	* src/incremen.c (get_directory_contents):
	If ignore_failed_read_option, only warn about
	stat failures.

	* src/list.c (from_header): Do not issue a diagnostic if TYPE is zero.
	However, check for error even for '-' or '+' case.

	(print_header): Try parsing uids and gids as unsigned integers first,
	and as a uid_t or gid_t only if that fails.  This adds support for
	listing positive uids and gids that are greater than UID_MAX and
	GID_MAX.

	* src/misc.c (link_error): New function.

	* src/names.c (collect_and_sort_names):
	If ignore_failed_read_option, only warn about
	stat errors.

	(excluded_name): Now returns bool.  Simplify, as the fancy
	features are now all in excluded_filename.

	* src/rtapelib.c (base_name): Remove decl, as system.h now
	declares it.

	* src/system.h: Include stddef.h if available.
	(offsetof): Declare if stddef.h doesn't.

	Include <dirname.h>.
	(FILESYSTEM_PREFIX_LEN, ISSLASH): Remove; now defined by dirname.h.

	* src/tar.c (ANCHORED_OPTION, IGNORE_CASE_OPTION,
	NO_ANCHORED_OPTION, NO_IGNORE_CASE_OPTION, NO_WILDCARDS_OPTION,
	NO_WILDCARDS_MATCH_SLASH_OPTION, WILDCARDS_OPTION,
	WILDCARDS_MATCH_SLASH_OPTION):
	New enum values.

	(long_options, usage, decode_options): Add support for --anchored,
	--ignore-case, --no-anchored, --no-ignore-case, --no-wildcards,
	--no-wildcards-match-slash, --recursion, --wildcards,
	--wildcards-match-slash.

	(decode_options): Implement the new way of interpreting exclude
	patterns.

	(usage): --newer-mtime takes a DATE operand.  DATE may be a file name.

	(OPTION_STRING, decode_options): Add -I, -y.  Currently these options
	just print error messages suggesting alternatives.

	(add_filtered_exclude): Remove.

	* tests/Makefile.am (TESTS): Alphabetize, except put version.sh first.

	* tests/extrac04.sh (out): Remove
	directory/subdirectory/file1, as the new semantics for
	--exclude exclude it.

	* tests/genfile.c (main): Don't use non-ASCII char in msgid.

2001-08-12  Paul Eggert  <eggert@twinsun.com>

	* lib/addext.c (<errno.h>): Include.
	(errno): Declare if not defined.
	(addext): Work correctly on the Hurd, where pathconf returns -1 and
	leaves errno alone, because there is no limit.  Also, work even if
	size_t is narrower than long.

2001-07-08  Paul Eggert  <eggert@twinsun.com>

	* lib/alloca.c (alloca): Arg is of type size_t, not unsigned.

2001-05-10  Paul Eggert  <eggert@twinsun.com>

	* lib/addext.c (ISSLASH, base_name): Remove decls; now in dirname.h.
	Include <backupfile.h> and <dirname.h> after size_t is defined.
	(addext): Use base_len to trim redundant trailing slashes instead of
	doing it ourselves.

	* lib/backupfile.c (ISSLASH, base_name):
	Remove decls; now in dirname.h.
	Include <argmatch.h>, <backupfile.h>, <dirname.h> after size_t
	is defined.
	(find_backup_file_name): Rename locals to avoid new functions.
	Use base_len instead of rolling it ourselves.
	Work even if dirlen is 0.
	Use a dir of '.' if given the empty string.

	* lib/basename.c:
	Do not include <stdio.h>, <assert.h>; no longer needed.
	(FILESYSTEM_PREFIX_LEN, PARAMS, ISSLASH): Remove; now in dirname.h.
	Include <string.h>, <dirname.h>.
	(base_name): Allow file names ending in slashes, other than names
	that are all slashes.  In this case, return the basename followed
	by the slashes.

	* lib/dirname.c: Include <string.h> instead of <stdlib.h>.
	(FILESYSTEM_PREFIX_LEN, ISSLASH): Remove; now in dirname.h.
	(dir_len): Renamed from dirlen.
	All callers changed.

	* lib/dirname.h (DIRECTORY_SEPARATOR, ISSLASH, FILESYSTEM_PREFIX_LEN):
	New macros.
	(base_name, base_len, dir_len, strip_trailing_slashes): New decls.

2001-02-16  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c (mbrtowc, mbrtowc, mbsinit):
	Do not declare or define if HAVE_MBRTOWC,
	since the test for HAVE_MBRTOWC now requires proper declarations.

	* lib/alloca.c (malloc): Undef before defining.

2001-02-13  Paul Eggert  <eggert@twinsun.com>

	* src/compare.c (read_and_process): Use off_t for size.
	From Maciej W. Rozycki.

2001-01-26  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c: Include stddef.h.  From Jim Meyering.

2001-01-12  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AC_INIT_AUTOMAKE): Version 1.13.19.

	* lib/savedir.h (savedir): Remove size arg.

	* doc/tar.texi: Add @setchapternewpage odd.
	Remove -I as an alias for -T, for now.
	Add @dircategory.
	Update copyright.  Remove "Published by".
	Dates beginning with / or . are taken to be file names.

	* src/tar.c (<time.h>): Do not include;
	(time): Do not declare.
	(usage): Remove -I as an alias for -T.
	(OPTION_STRING): Remove -I.
	(decode_options): Dates that look like an absolute path name,
	or that start with '.', are presumed to be file names whose
	dates are taken.
	Remove 'I' as an aliase for 'T'.
	Update copyright.

	* src/extract.c (<time.h>): Do not include; system.h now does this.
	(make_directories): Skip filesystem prefixes.
	Don't assume '/' is the only separator.
	(extract_sparse_file): Use new full_write semantics.
	On write error, return instead of invoking skip_file.
	Do not free sparsearray; caller does this now.
	(apply_nonancestor_delayed_set_stat): Do not assume '/' is the only
	separator.
	(extract_archive): Don't assume file name lengths fit in int.
	Report what got stripped from member name; it might be more than '/'.
	Use new full_write semantics.
	Do not pass redundant trailing "/" to mkdir, as POSIX does not allow
	mkdir to ignore it.
	Do not report mkdir error if old_files_option == KEEP_OLD_FILES.

	* src/buffer.c (<time.h>): Do not include; system.h now does this.
	(time): Remove decl; likewise.
	(child_open_for_uncompress): Use new full_write semantics.
	(flush_write): Use ISSLASH instead of testing for '/'.
	(flush_read): Likewise.

	* src/rmt.h (_remdev): Look for / anywhere in Path.

	* src/misc.c (contains_dot_dot): Skip filesystem prefix.
	Don't assume '/' is the only separator.
	(safer_rmdir): Don't assume '/' is the only separator.

	* src/compare.c (diff_archive): Don't assume '/' is the only separator.

	* lib/dirname.h (dirlen): New decl.

	* src/incremen.c (get_directory_contents):
	Remove path_size arg; all callers changed.
	Don't assume '/' is the only directory separator.
	(gnu_restore): Work even if file name length doesn't fit in int.

	* lib/addext.c (ISSLASH): New macro.
	(addext): Trim any redundant trailing slashes.

	* src/names.c (name_next):
	Don't assume '/' is the only directory separator.
	(namelist_match): Likewise.
	(add_hierarchy_to_namelist): Remove dirsize arg.
	Do not assume '/' is the only directory separator.
	(new_name): Likewise.

	* lib/Makefile.am (noinst_HEADERS): Add dirname.h, full-write.h.
	(libtar_a_SOURCES): Add dirname.c.

	* src/create.c (relativize):
	New function, with much of old start_header's guts.
	Handle filesystem prefixes.
	(start_header): Use this new function.
	(init_sparsearray): Don't bother to zero out the new array;
	it's not needed.
	(deal_with_sparse): Fix array allocation bug.
	(create_archive): Don't assume '/' is the only separator.
	(dump_file): Likewise.
	Don't worry about leading / in symlink targets.

	* lib/savedir.c (savedir):
	Remove size arg; it wasn't portable.  All callers changed.

	* lib/utime.c (utime_null): Adjust to new full_write convention.

	* configure.in (YACC): Avoid portability problem with Ultrix sh.

	* lib/backupfile.c: Include <dirname.h>.
	(ISSLASH): New macro.
	(find_backup_file_name): Use dirlen to calculate directory lengths.
	(max_backup_version): Strip redundant trailing slashes.

	* src/common.h: Include <full-write.h>.
	(get_directory_contents): No longer has size arg.
	(gnu_restore): Arg is size_t, not int.

	* src/system.h: Include <time.h>.
	(time): Declare if not defined.

	* lib/full-write.c: Include full-write.h, not safe-read.h.
	full_write returns size_t, with short writes meaning failure.
	All callers changed.

	* src/rtapelib.c: Include full-write.h.

	* src/rmt.c: Include full-write.h.
	(main): Update copyright.

	* doc/getdate.texi: Mention that only English is supported.
	Show how to use "date" so that the output is acceptable to getdate.
	Mention Z as an abbreviation for UTC.

	* lib/full-write.h: New file.

	* src/list.c: system.h now does time.h stuff.

	* lib/dirname.c:
	Use HAVE_STDLIB_H, not STDC_HEADERS, to decide whether to include
	stdlib.h.
	Do not include string.h, strings.h, or assert.h; no longer needed.
	(strrchr, memrchr, malloc): Remove decls; no longer needed.
	Include <xalloc.h>.
	(base_name): New decl.
	(BACKSLASH_IS_PATH_SEPARATOR): Remove.
	(dir_name_r): Remove.
	(dirlen): New function.
	(dir_name): Use dirlen instead of dir_name_r.
	(<string.h>, <strings.h>): Include only if test program.
	(main): Use "return 0", not "exit (0)".

2000-12-08  Paul Eggert  <eggert@twinsun.com>

	* lib/dirname.h: New file.

2000-11-02  Vesselin Atanasov  <vesselin@bgnet.bg>

	* lib/fnmatch.c: Do not comment out all the code if we are using
	the GNU C library, because in some cases we are replacing buggy
	code in the GNU C library itself.

2000-10-30  Paul Eggert  <eggert@twinsun.com>

	* lib/fnmatch.c (FOLD): Do not assume that characters are unsigned.

2000-10-29  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AC_INIT_AUTOMAKE): Version 1.13.18.

	* src/tar.c: Include <fnmatch.h>, for FNM_LEADING_DIR.

2000-10-28  Paul Eggert  <eggert@twinsun.com>

	* doc/tar.texi: --no-recursion now applies to extraction, too.
	* src/create.c (dump_file): no_recurse_option -> ! recursion_option
	* src/names.c (namelist_match, excluded_name):
	Do not match subfiles of a directory
	if --no-recursion is specified.
	* src/tar.c (NO_RECURSE_OPTION): Remove.
	(long_options): Have getopt set the --no-recursion flag.
	(decode_options): Initialize recursion_option to FNM_LEADING_DIR.
	Remove case for NO_RECURSE_OPTION.
	* src/common.h (recursion_option):
	Renamed from no_recurse_option, with sense
	negated, and with FNM_LEADING_DIR being the nonzero value.

	* names.c (namelist_match): New function.
	(name_match, name_scan): Use it to eliminate duplicate code.
	(names_notfound): Remove special case for Amiga.

2000-10-27  Paul Eggert  <eggert@twinsun.com>

	* src/misc.c (read_error_details, read_warn_details,
	read_fatal_details): Don't assume size_t is unsigned long.

	* src/buffer.c (flush_read): If read_full_records_option, try to
	fill the input buffer, as --delete -f - needs this.

2000-10-24  Paul Eggert  <eggert@twinsun.com>

	* m4/strerror_r.m4 (AC_FUNC_STRERROR_R): Port to autoconf 2.13.

	* src/buffer.c (check_label_pattern):
	Make sure header name is a string before
	passing it to fnmatch.
	(init_volume_number): Check for global_volno overflow.
	(new_volume): Check for global_volno overflow.

	* src/tar.c (decode_options):
	Check that volume label is not too long to overflow
	name in tar header block.

	* Makefile.am (EXTRA_DIST): Remove rebox.el.

	* configure.in (HAVE_DECL_STRERROR_R): Remove our handwritten code.
	(AC_FUNC_STRERROR_R): Use this instead.

2000-10-23  Paul Eggert  <eggert@twinsun.com>

	* src/extract.c: Include <time.h>, since we invoke "time".

	* lib/prepargs.c (prepend_default_options):
	Don't use NULL, for portability.

	* m4/fnmatch.m4: Add "working" to message.

	* src/names.c: (_GNU_SOURCE): Remove; autoconf now does this.
	Include <hash.h>.
	(getpwuid, getgrgid): Declare only if system headers don't.
	(gid_to_gname): Don't invoke setgrent.
	(namelist): Now static, not global.
	(nametail): New var.  All uses of namelast changed to use
	nametail, with one extra level of indirection.
	(name_gather): Use memcpy instead of strncpy + assignment of NUL.
	(name_match): Set nametail too, when setting namelist to null.
	(add_hierarchy_to_namelist): Change type of dir arg from char * to
	struct name *, so that we don't have to look up the name again
	here.  Get change_dir from dir rather than as a separate arg.  Add
	dirsize arg, and pass it along to get_directory_contents.  Remove
	unnecessary check of directory type.
	(new_name): Do not append a slash if PATH already ends in one.
	(avoided_names, struct avoided_name): Remove.
	(avoided_name_table): New var, replacing avoided_names.
	(hash_avoided_name, compare_avoided_names): New function.
	(add_avoided_name, is_avoided_name): Use hash table rather than
	linked list.

	* src/buffer.c (_GNU_SOURCE): Remove; autoconf now does this.
	(child_open_for_compress, child_open_for_uncompress,
	close_archive): Propagate any failure of the compression process
	back to "tar".
	(open_archive, flush_write, flush_read, close_archive): Do not
	allocate an array of size PATH_MAX, as PATH_MAX might be (size_t)
	-1.  Instead, allocate an array with the size that's needed.
	(open_archive): Don't bother checking S_ISCHR of /dev/null.
	(backspace_output): Don't try to backspace past start of archive.
	(close_archive): Remove special case for DELETE_SUBCOMMAND.

	* acconfig.h (_GNU_SOURCE, DEFAULT_ARCHIVE, DEFAULT_BLOCKING,
	DENSITY_LETTER, DEVICE_PREFIX, EMUL_OPEN3, HAVE_GETGRGID,
	HAVE_GETPWUID, HAVE_MKNOD, HAVE_RTAPELIB, HAVE_ST_FSTYPE_STRING,
	HAVE_UNION_WAIT, HAVE_UTIME_H, HAVE_VALLOC, MTIO_CHECK_FIELD, PACKAGE,
	PROTOTYPES, REMOTE_SHELL, STD_INC_PATH, VERSION, WITH_CATALOGS,
	WITH_DMALLOC, WITH_REGEX):
	Remove; now generated automatically.

	* configure.in (_GNU_SOURCE): Define to empty, not 1, for
	compatibility for glibc fragments.
	(_GNU_SOURCE, HAVE_UTIME_H, MTIO_CHECK_FIELD,
	HAVE_ST_FSTYPE_STRING, HAVE_MKNOD, REMOTE_SHELL, DENSITY_LETTER,
	DEVICE_PREFIX, DEFAULT_ARCHIVE, DEFAULT_BLOCKING): Add comment so
	that we needn't put an entry into acconfig.h.
	(ALL_LINGUAS): Add da.
	(AC_C_BACKSLASH_A): Remove; jm_PREREQ_QUOTEARG now does this.
	(AC_CHECK_HEADERS): Add stdbool.h (for hash.h users), wctype.h
	(for strtol.c).
	(AC_MBSTATE_T): Add.
	(RMT): Append $(EXEEXT).
	(HAVE_GETGRGID, HAVE_GETPWUID, pe_AC_TYPE_SIGNED_CHAR): Remove.
	(HAVE_DECL_FREE, HAVE_DECL_GETGRGID, HAVE_DECL_GETPWUID,
	HAVE_DECL_GETENV, HAVE_DECL_MALLOC, HAVE_DECL_STRTOUL,
	HAVE_DECL_STRTOULL, HAVE_DECL_STRERROR_R): New macros.
	(jm_PREREQ_ADDEXT, jm_PREREQ_ERROR, jm_PREREQ_QUOTEARG): Add.
	(AC_REPLACE_FUNCS): Remove execlp; no longer needed.
	(AC_CHECK_FUNCS): Add clock_gettime; AC_SEARCH_LIBS wasn't enough.
	Remove mbrtowc; jm_PREREQ_QUOTEARG now does this.
	(EMUL_OPEN3): Remove; no longer needed.
	(DENSITY_LETTER, DEVICE_PREFIX): Simplify m4 quoting.

	* m4/fnmatch.m4 (AC_FUNC_FNMATCH): Detect d*/*1 vs d/s/1 bug.

	* src/common.h: Do not include basename.h.
	* src/rtapelib.c (base_name): Do not include basename.h;
	declare base_name instead.

	* lib/basename.h, lib/execlp.c, lib/getpagesize.h, lib/mkdir.c:
	Remove these files.
	* lib/getstr.c, lib/getstr.h, lib/hash.h, lib/hash.h, lib/prepargs.c,
	lib/prepargs.h, lib/savedir.c, lib/savedir.h: New files.
	* lib/Makefile.am (EXTRA_DIST, noinst_HEADERS, libtar_a_SOURCES):
	Adjust to the above changes.

	* lib/Makefile.am (AUTOMAKE_OPTIONS): Remove ../src/ansi2knr.

	* src/open3.c: Remove.

	* src/Makefile.am (AUTOMAKE_OPTIONS): Remove ansi2knr.
	(tar_SOURCES): Remove open3.c.
	(INCLUDES): Remove -I.., as automake does that.
	(OMIT_DEPENDENCIES): ../lib/fnmatch.h -> fnmatch.h.  Add localedir.h.

	The following changes are to put LOCALEDIR into localedir.h instead
	of passing it on the command line.
	(DEFS): Remove.
	(DISTCLEANFILES): New macro.
	(localedir.h): New rule.
	(rmt.o tar.o): Now depend on localedir.h.

	* tests/delete02.sh, tests/extrac04.sh: New files.

	* tests/Makefile.am (AUTOMAKE_OPTIONS): Remove ansi2knr.
	(TESTS): Add extrac04.sh, and restore delete02.sh.
	(DEFS): Remove; LOCALEDIR is now done via localedir.h.
	(INCLUDES): Remove -I.. as automake does this now.

	* src/rtapelib.c (rexec): Don't declare unless using it.
	(do_command): Simplify signal-handling code slightly.

	* src/delete.c (blocks_needed): Remove.  All uses changed to use
	blocking_factor - new_blocks.
	(acting_as_filter): New var.
	(write_record, delete_archive_members): Use acting_as_filter
	rather than archive == STDIN_FILENO to detect whether we're acting
	as a filter, as open can return STDIN_FILENO in some cases.
	(delete_archive_members): Ignore zero blocks if
	ignore_zeros_option is nonzero.  Fix bug that messed up last
	output block: write_eot can't be used here, as it gets confused
	when the input is at end of file.

	* src/compare.c (diff_archive): Do not impose an arbitrary limit on
	symbolic link contents length.  Pass directory size to
	get_directory_contents.

	* m4/decl.m4, m4/error.m4, m4/mbstate_t.m4, m4/prereq.m4,
	m4/strerror_r.m4: New files.
	* m4/signedchar.m4: Remove this file.
	* Makefile.am (ACINCLUDE_INPUTS): Adjust to above changes.
	* m4/Makefile.am (EXTRA_DIST): Likewise.

	* Makefile.am (DISTCLEANFILES): Add intl/libintl.h.

	* po/da.po: New translation file.

	* src/mangle.c (extract_mangle):
	Fix diagnostic with wrong number of %s'es.

	* lib/fnmatch.c (fnmatch):
	Fix some FNM_FILE_NAME and FNM_LEADING_DIR bugs,
	e.g. fnmatch("d*/*1", "d/s/1", FNM_FILE_NAME) incorrectly yielded zero.

	* lib/full-write.c (full_write): Some buggy drivers return 0 when you
	fall off a device's end.  Detect this.

	* src/system.h (IN_CTYPE_DOMAIN): Renamed from CTYPE_DOMAIN.  All
	uses changed.
	(open): Remove macro; we no longer support EMUL_OPEN3.  Do not
	include <pathmax.h> and directory include files like <dirent.h>;
	no longer used.  Include <savedir.h> instead.
	(closedir, signed_char): remove macro; no longer used.
	(bool, false, true): Include <stdbool.h> if you have the include
	file, otherwise define.

	* src/misc.c:
	(is_dot_or_dotdot, closedir_error, closedir_warn, opendir_error,
	opendir_warn, readdir_error): Remove; no longer needed.
	(safer_rmdir): Strip leading ./ (or .// or ./// or ././ or etc.)
	before deciding whether we're trying to remove ".".
	(remove_any_file): Try unlink first if we are not root.  Use
	savedir when recursively removing directories, to avoid exhausting
	file descriptors.
	(savedir_error, savedir_warn, symlink_error): New functions.

	* src/list.c: (read_and): Do not invoke
	apply_nonancestor_delayed_set_stat; DO_SOMETHING is now
	responsible for that.  Do not invoke apply_delayed_set_stat; our
	caller is now responsible for that.
	(read_header): Use signed char instead of signed_char.  Prevent
	later references to current_header from mistakenly treating it as
	an old GNU header.
	(from_header): Quote invalid base-64 strings in diagnostics.
	(time_from_header): Do not warn about future timestamps in
	archive; check_time now does that.
	(print_header): Quote unknown file types.
	(skip_member): New function, replacing skip_extended_headers and
	now skipping the whole member instead of just the extended
	headers.  All callers changed.  This makes the code handle
	extended headers uniformly, and fixes some bugs.

	* src/update.c (update_archive): Use skip_member.

	* src/extract.c (we_are_root): Now global.
	(struct delayed_symlink): New type.
	(delayed_symlink_head): New var.
	(extr_init, fatal_exit): Invoke extract_finish on fatal errors,
	not apply_delayed_set_stat.
	(set_mode, set_stat): Pointer args are now const pointers.
	(check_time): New function.
	(set_stat): Warn if setting a file's timestamp to be the future.
	(make_directories): Do not save and restore errno.
	(maybe_recoverable): Set errno to ENOENT if we cannot make missing
	intermediate directories.
	(extract_archive): Invoke apply_nonancestor_delayed_set_stat here,
	not in caller.  Extract potentially dangerous symbolic links more
	carefully, deferring their creation until the end, and using a
	regular file placeholder in the meantime.  Do not remove trailing
	/ and /. from file names.  Do not bother checking for ".." when
	checking whether a directory loops back on itself, as loopbacks
	can occur with symlinks too.  Also, in that case, do not bother
	saving and restoring errno; just set it to EEXIST.
	(apply_nonancestor_delayed_set_stat): A prefix is a potential
	ancestor if it ends in slash too (as well as ending in a char just
	before slash).
	(apply_delayed_set_stat): Remove.
	(apply_delayed_symlinks, extract_finish): New functions.

	* doc/fdl.texi: New file.
	* doc/Makefile.am (EXTRA_DIST): Add fdl.texi.
	($(srcdir)/tar.info): Add fdl.texi.  Invoke makeinfo with --no-split.
	* doc/tar.texi: Add Free Documentation License.  New section
	"Overwrite Old Files", and revamp that section to make it easier to
	follow.  "tar" -> "GNU tar" where appropriate.  Migrate getdate
	documentation into getdate.texi.  Fix several minor typos.  Describe
	TAR_OPTIONS.  Describe incompatibility between incremental backups and
	--atime-preserve.  Describe incompatibility between --verify and other
	options.  Mention that tar normally removes symbolic links rather than
	following them, when extracting a file of the same name.

	* THANKS: Add gpoul.  Change skip's address.

	* po/POTFILES.in: Add lib/human.c.

	* src/common.h (namelist, namelast): Remove decls.
	(we_are_root, extract_finish, skip_member, savedir_error,
	savedir_warn, symlink_error, gnu_list_name): New decls.
	(apply_delayed_set_stat, apply_nonancestor_delayed_set_stat,
	skip_extended_headers, is_dot_or_dotdot, closedir_error,
	closedir_warn, opendir_error, opendir_warn, readdir_error,
	readdir_warn): Remove decls.
	(get_directory_contents): New off_t arg.
	(addname): Now returns struct name *.

	* src/tar.h, tests/genfile.c: Fix comments.

	* src/create.c: Include hash.h.
	(gnu_list_name): Remove decl.
	(struct link): Remove "next" member.
	(linklist): Remove.
	(start_header): Say "leading `FOO'" rather than "`FOO' prefix" for
	consistency with other diagnostics.
	(deal_with_sparse): Check for I/O error when closing the file.
	(create_archive): Do not allocate an array of size PATH_MAX, as
	PATH_MAX might be (size_t) -1.  Instead, allocate an array with
	the size that's needed.
	(hash_link, compare_links): New functions.
	(dump_file): Do not exhaust open file descriptors when descending
	deeply into a directory, by using savedir rather than
	opendir/readdir.  Do not zero-fill the name buffer unnecessarily.
	Hash the set of links already created, instead of using a linked
	list.  Fix some bugs in outputting sparse files which caused the
	sparse tables to be incorrect.  When a file unexpectedly shrinks,
	output zeros rather than garbage.  Do not allocate an array of
	size PATH_MAX, as PATH_MAX might be (size_t) -1.  Instead,
	allocate an array with the size that's needed.

	* src/incremen.c: Include hash.h.
	(struct directory): Remove "next", "dir_text".  Change "name" to
	be char[1] with struct hack, not const char *.  Add "found".
	(directory_list): Remove.  Replaced by directory_table.
	(directory_table): New var.
	(nfs_string): Renamed from nfs.
	(hash_directory, compare_directories): New functions.
	(note_directory): Now returns struct directory *.  First arg is
	now const pointer.  struct stat arg is now dev_t, ino_t, nfs.
	Remove text arg.  New "found" arg, basically corresponding to the
	old text arg not being null.  All callers changed.
	(note_directory, find_directory): Use hash table rather than
	linked list.
	(get_directory_contents): New arg "device".  Use savedir to do the
	hard work.  Save the nfs-ness of stat_data, since it might change
	under us.  Use note_directory instead of find_directory to save
	some work.  When adding an "A" record, do it with
	add_to_accumulator instead of cheating with strcat.
	(read_directory_file): Use "+" flag before device to indicate
	whether it was NFS.  Fix typo in checking for strtoul error.
	(write_directory_file_entry): New function.
	(write_directory_file): Use it, and use the hash routines to
	traverse the directory table.
	(gnu_restore): Use savedir rather than opendir/readdir.

	* src/tar.c: Include localedir.h, prepargs.h.
	(long_options): Now static.
	(long_options, usage, decode_options): -j is now short for
	--bzip2, and -I is now an alias for -T.
	(decode_options, main): argv is not const pointer now.
	(decode_options): Invoke prepend_default_options to support
	TAR_OPTIONS.  In diagnostic, mention the string that was the
	invalid blocking factor, tape length, group, owner, or record
	size.  --delete is no longer incompatible with -f -, undoing
	2000-01-07 change.
	(main): Invoke extract_finish at end of extraction.

	* src/rmt.c: Include localedir.h.
	(main): Update copyright date to 2000.

	* doc/getdate.texi: New file, taken from fileutils 4.0.27, with the
	following changes: Use @sc where appropriate.  Document the ranges of
	supported times more precisely.  Add Eggert to getdate authors.
	Document old Latin 12m/12pm tradition.  Remove list of alphabetic time
	zone names, as it wasn't correct and people shouldn't be relying on it
	anyway.  Relative items also account for non-DST adjustments.  Fix
	some misspellings.

	* lib/prepargs.c, lib/prepargs.h, tests/extrac04.sh: New file.

	* tests/ignfail.sh: opendir -> savedir in diagnostics.

	* tests/preset.in: Set LANGUAGE to the empty string, for some
	brain damaged host.

2000-10-20  Paul Eggert  <eggert@twinsun.com>

	* m4/fnmatch.m4: Mention the GNU C library.

2000-10-19  Paul Eggert  <eggert@twinsun.com>

	* m4/fnmatch.m4: Add a couple more test cases to catch bugs in
	glibc 2.1.95.

2000-10-17  Paul Eggert  <eggert@twinsun.com>

	* lib/human.c (<limits.h>): Do not include; human.h does it if needed.
	(CHAR_BIT): Remove.

	* lib/human.h (<limits.h>): Include if HAVE_LIMITS_H.
	(CHAR_BIT): Define if not defined.

2000-09-09  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c: From fileutils: rename ISASCII to IN_CTYPE_DOMAIN.

2000-08-07  Paul Eggert  <eggert@twinsun.com>

	* lib/xmalloc.c: Memory exhausted -> memory exhausted

	* lib/xalloc.h (xalloc_msg_memory_exhausted):
	change to array from char *.

2000-08-06  Paul Eggert  <eggert@twinsun.com>

	* m4/mbstate_t.m4: Define mbstate_t to be int, not char, for
	compatibility with glibc 2.1.3 strftime.c.

2000-07-31  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c (quotearg_n_options):
	Don't make the initial slot vector a constant,
	since it might get modified.

	* lib/quotearg.c: Add support for more than one preallocated slot.

2000-07-30  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c (quotearg_n_options):
	Preallocate a slot 0 buffer, so that the caller
	can always quote one small component of a "memory exhausted" message
	in slot 0.

2000-07-23  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c:
	Include <wchar.h> even if ! (HAVE_MBRTOWC && 1 < MB_LEN_MAX), so that
	mbstate_t is always defined.

	Do not inspect MB_LEN_MAX, since it's incorrectly defined to be 1 in
	some GCC installations, and this configuration error is likely to be
	common.

2000-07-22  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c:
	When the system forces us to redefine mbstate_t, shadow its mbsinit
	function.  From Bruno Haible.

2000-07-14  Paul Eggert  <eggert@twinsun.com>

	* lib/xmalloc.c: Simplify exhausted message.

	* lib/quotearg.h: Update copyright date; from Jim Meyering.

2000-07-13  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.h (enum quoting style):
	New constant clocale_quoting_style.

	* lib/quotearg.c:
	(quoting_style_args, quoting_style_vals, quotearg_buffer_restyled):
	Add support for clocale_quoting_style, undoing previous change to
	locale_quoting_style.

2000-07-10  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c:
	<wchar.h>: Include only if HAVE_MBRTOWC && 1 < MB_LEN_MAX,
	since otherwise we don't need it.
	(MB_CUR_MAX): Redefine to 1 if ! (HAVE_MBRTOWC && 1 < MB_LEN_MAX),
	since we don't do multibytes in that case.
	(quotearg_buffer_restyled): If a unibyte locale, don't bother to
	invoke multibyte primitives.

	* m4/mbstate_t.m4 (AC_MBSTATE_T):
	Renamed from AC_MBSTATE_T_OBJECT.  All uses changed.
	Change from a two-part test, which defines both HAVE_MBSTATE_T_OBJECT
	and mbstate_t, to a single-part test that simply defines mbstate_t.

	* lib/quotearg.c (mbrtowc): Do not use HAVE_WCHAR_H in the definition.
	Use defined mbstate_t, not HAVE_MBSTATE_T_OBJECT,
	to decide whether to define the BeOS workaround macro;
	this adjusts to the change to AC_MBSTATE_T.

	* m4/strerror_r.m4: New file.

2000-07-05  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c: Use double-quote to quote.

	* lib/quotearg.c (N_): New macro.
	(gettext_default): New function.
	(quotearg_buffer_restyled): Use gettext_default ("{LEFT QUOTATION MARK}",
	"\"") for left quote, and gettext_default ("{RIGHT QUOTATION MARK}", "\"")
	for right quote.

	* lib/quotearg.c (struct quoting_options):
	Simplify quote_these_too dimension.
	From Bruno Haible  <haible@clisp.cons.org>.

	* m4/mbstate_t.m4 (AC_MBSTATE_T_OBJECT):
	Test for mbstate_t only if the test
	for an object-type mbstate_t fails.

	* lib/quotearg.c (mbrtowc): Declare returned type, since BeOS doesn't.

2000-07-03  Paul Eggert  <eggert@twinsun.com>

	* m4/mbstate_t.m4 (AC_MBSTATE_T_OBJECT): Port to autoconf 2.13.
	Add AC_CHECK_HEADERS(stdlib.h), since we use HAVE_STDLIB_H.

	* lib/quotearg.c (mbrtowc):
	Assign to *pwc, and return 1 only if result is nonzero.
	(iswprint): Define to ISPRINT if we are substituting our own mbrtowc.

2000-07-02  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c (mbstate_t):
	Do not define; it should be defined with AC_CHECK_TYPE.

2000-06-26  Paul Eggert  <eggert@twinsun.com>

	* m4/mbstate_t.m4: Include stdio.h before wchar.h, to work around
	a bug in glibc 2.1.3.

	* lib/xmalloc.c: Fix inaccurate comment for xrealloc.

2000-06-19  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c (ISASCII): Add #undef and move definition to follow
	inclusion of wctype.h to work around solaris2.6 namespace pollution.
	(ISPRINT): Likewise.
	Reported by Tom Tromey.

2000-06-15  Paul Eggert  <eggert@twinsun.com>

	* lib/human.c (adjust_value): New function.
	(human_readable_inexact): Apply rounding style even when printing
	approximate values.

	* lib/human.c: Avoid shadowing warnings.
	From Jim Meyering.

2000-06-14  Paul Eggert  <eggert@twinsun.com>

	* lib/human.c (human_readable_inexact): Allow an input block size
	that is not a multiple of the output block size, and vice versa.

	* lib/getdate.y (get_date): Apply relative times after time zone
	indicator, not before.

2000-05-31  Paul Eggert  <eggert@twinsun.com>

	* m4/largefile.m4: Rewrite so that we don't need to run getconf,
	and thus don't need AC_CANONICAL_HOST.

	(AC_SYS_LARGEFILE_FLAGS, AC_SYS_LARGEFILE_SPACE_APPEND): Remove.
	(AC_SYS_LARGEFILE_TEST_INCLUDES): New macro.
	(AC_SYS_LARGEFILE_MACRO_VALUE): Change arguments from
	CODE-TO-SET-DEFAULT to VALUE, INCLUDES, FUNCTION-BODY.  All uses
	changed.  Instead of inspecting the output of getconf, try to
	compile the test program without and with the macro definition.
	(AC_SYS_LARGEFILE): Do not require AC_CANONICAL_HOST or check for
	getconf.  Instead, check for the needed flags by compiling test
	programs.

	* configure.in (AC_CANONICAL_HOST): Remove; the largefile stuff no
	longer needs it.
	* config.guess, config.sub: Remove these files, for similar reasons.

2000-05-03  Paul Eggert  <eggert@twinsun.com>

	* m4/largefile.m4 (AC_SYS_LARGEFILE): Define _XOPEN_SOURCE to be
	500, instead of _GNU_SOURCE to be 1, to work around glibc 2.1.3
	bug.  This avoids a clash when files like regex.c that define
	_GNU_SOURCE.

2000-05-02  Paul Eggert  <eggert@twinsun.com>

	* m4/largefile.m4 (AC_SYS_LARGEFILE):
	Define _GNU_SOURCE if this is needed to make
	ftello visible (e.g. glibc 2.1.3).  Use compile-time test, rather than
	inspecting host and OS, to decide whether to define _LARGEFILE_SOURCE.

	* lib/quotearg.c (mbrtowc, mbstat_t):
	Add definitions if !HAVE_MBSTATE_T_OBJECT.
	(<wctype.h>): Include if HAVE_WCTYPE_H.
	(iswprint): Define to 1 if we lack it

2000-04-18  Paul Eggert  <eggert@twinsun.com>

	* m4/mbstate_t.m4: New file.

2000-04-17  Bruno Haible  <haible@clisp.cons.org>

	* tests/ignfail.sh: Test for uid 0 along with user "root".

2000-04-05  Paul Eggert  <eggert@twinsun.com>

	* m4/largefile.m4 (AC_SYS_LARGEFILE_FLAGS):
	Don't use -n32 on IRIX if the installer said
	otherwise.

2000-02-28  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c (ALERT_CHAR): New macro.
	(quotearg_buffer_restyled): Use it.

2000-02-23  Rainer Orth  <ro@TechFak.Uni-Bielefeld.DE>

	* src/list.c (tartime): Fix off-by-one error when copying year if
	OLD_CTIME.

2000-02-18  Paul Eggert  <eggert@twinsun.com>

	* lib/getdate.y: Handle two-digit years with leading zeros correctly.
	(textint): New typedef.
	(parser_control): Changed from struct parser_control to typedef
	(for consistency).  Member year changed from int to textint.  All
	uses changed.
	(YYSTYPE): Removed; replaced by %union with int and textint
	members.
	(tID): Removed; not used.
	(tDAY, tDAY_UNIT, tDAYZONE, tHOUR_UNIT, tID, tLOCAL_ZONE,
	tMERIDIAN, tMINUTE_UNIT, tMONTH, tMONTH_UNIT tSEC_UNIT, tSNUMBER,
	tUNUMBER, tYEAR_UNIT, tZONE, o_merid): Now of type <intval>.
	(tSNUMBER, tUNUMBER): Now of type <textintval>.
	(date, number, to_year): Use width of number in digits, not its
	value, to determine whether it's a 2-digit year, or a 2-digit
	time.
	(yylex): Store number of digits of numeric tokens.  Return '?' for
	unknown identifiers, rather than (unused) tID.

2000-01-16  Paul Eggert  <eggert@twinsun.com>

	* lib/quotearg.c (quotearg_buffer_restyled):
	Do not quote alert, backslash, formfeed,
	and vertical tab unnecessarily in shell quoting style.

2000-01-15  Paul Eggert  <eggert@twinsun.com>

	* m4/c-bs-a.m4:
	Change quoting to be compatible with future autoconf versions.

2000-01-11  Paul Eggert  <eggert@twinsun.com>

	* lib/exclude.c (FILESYSTEM_PREFIX_LEN, ISSLASH): Remove unused macros.

2000-01-07  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AC_INIT_AUTOMAKE): Version 1.13.17.

	Fix bug with fnmatch.h dependency, as follows:
	* src/Makefile.am (OMIT_DEPENDENCIES): New macro.
	* lib/Makefile.am (OMIT_DEPENDENCIES): New macro.

	* src/common.h (apply_nonancestor_delayed_set_stat):
	Renamed from apply_delayed_set_stat.
	(apply_delayed_set_stat, decode_mode, chmod_error_details,
	chown_error_details, close_warn, closedir_warn, mkdir_error,
	read_error_details, read_fatal_details, read_warn_details,
	seek_error_details, seek_warn_details, utime_error,
	write_error_details, write_fatal_details): New decls.

	Make diagnostic messages more regular.
	* src/create.c (dump_file): Quote file names with colons if possible.
	* src/compare.c	(diff_archive): Likewise.
	* src/extract.c (repair_delayed_set_stat, extract_archive): Likewise.
	* src/incremen.c (get_directory_contents, gnu_restore): Likewise.
	* src/mangle.c (extract_mangle): Likewise.
	* src/misc.c (call_arg_error, call_arg_fatal, call_arg_warn):
	Likewise.
	* src/buffer.c (archive_write_error, flush_archive, close_archive,
	new_volume, xclose):
	Use error message functions to report errors consistently.
	* src/compare.c (diff_sparse_files, diff_archive): Likewise.
	* src/create.c (finish_sparse_file, dump_file): Likewise.
	* src/extract.c (set_mode, set_stat, extract_sparse_file,
	extract_archive): Likewise.
	* src/list.c (list_archive): Likewise.
	* src/update.c (append_file): Likewise.
	* src/compare.c (diff_init, diff_sparse_files):
	Use xalloc_die to report memory exhaustion.
	* src/incremen.c (gnu_restore): Likewise.
	* src/list.c (read_header): Likewise.
	* src/mangle.c (extract_mangle): Likewise.
	* src/misc.c (maybe_backup_file): Likewise.
	* src/tar.c (decode_options): Likewise.
	* src/compare.c (read_and_process, fill_in_sparse_array,
	diff_sparse_files):
	Use consistent terminology for unexpected-EOF message.
	* src/extract.c (extract_sparse_file, extract_archive): Likewise.
	* src/list.c (list_archive, read_header, skip_file,
	skip_extended_headers): Likewise.
	* src/buffer.c (archive_write_error): Add noreturn attribute to decl.
	(xdup2): Regularize messages with rest of tar.

	* src/buffer.c (flush_read): Don't read past EOF.

	* src/extract.c (extr_init):
	If we run out of memory, invoke apply_delayed_set_stat.
	(prepare_to_extract): Don't complain if we can't remove ".".
	(apply_delayed_set_stat): New function.
	(apply_nonancestor_delayed_set_stat):
	Renamed from apply_delayed_set_stat.  All uses changed.
	Don't remove head if it doesn't apply.

	* src/create.c (find_new_file_size):
	Return size instead of storing through pointer.
	All callers changed.
	(deal_with_sparse): Don't keep reading after read errors.
	(finish_sparse_file): Just abort if there is an internal error.
	(dump_file): Fix typo: stat_warn and stat_error were interchanged.
	Don't restore access times on directories during incremental dumps
	until after dealing with the directory.
	If ignoring failed reads, count closedir, read, and unknown
	file errors as warnings, not errors.
	Fix buffer overrun problem when dumping sparse files.

	* src/list.c (read_and):
	Invoke apply_nonancestor_delayed_set_stat on file names
	after handling them.
	(decode_mode): Remove; moved to misc.c.

	* src/misc.c (safer_rmdir): New function.
	(remove_any_file): Use it to avoid problems with rmdir(".").
	(maybe_backup_file): Regularize diagnostics.
	(undo_backup_file): Likewise.
	(decode_mode): Moved here from list.c.
	(chmod_error_details, chown_error_details, close_fatal,
	close_warn, closedir_warn, mkdir_error, read_error_details,
	read_warn_details, read_fatal_details, seek_error_details,
	seek_warn_details, utime_error, write_error_details,
	write_fatal_details): New functions.

	* src/delete.c (save_record): Remove static variable (now local).
	(move_archive): Don't position before start of archive.
	(write_record): Abort if count is zero at inopportune time.
	Plug memory leak.

	* src/tar.c (decode_options): --delete and -f - are now
	incompatible, since we didn't have time to fix their bugs.

	* tests/Makefile.am (TESTS): Remove delete02.sh.
	* tests/ignfail.sh: Adjust to new quoting scheme again.

2000-01-06  Paul Eggert  <eggert@twinsun.com>

	* lib/getdate.y: Sync tm_diff with the GNU C Library.
	(TM_YEAR_BASE): Renamed from TM_YEAR_ORIGIN.  All uses changed.
	(tm_diff): Renamed from difftm.  All uses changed.
	Replace body with that taken from GNU C Library 2.1.3pre1.
	(get_date): Prefer tm_gmtoff to tm_diff if available.

1999-12-29  "Melissa O'Neill"  <oneill@cs.sfu.ca>

	* tests/incremen.sh: Invoke stat on newly created file so that its
	ctime is updated on Nextstep.

1999-12-21  Machael Stone  <mstone@cs.loyola.edu>

	* lib/getdate.y (get_date):
	Fix typo when checking for time_t overflow in time zone calculations.

1999-12-13  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AC_INIT_AUTOMAKE): Version 1.13.16.

	* README-alpha: New file.
	* README: New sections for gzip and bzip2, Solaris.
	Remove mention of BACKLOG.

	* configure.in (AC_C_BACKSLASH_A): Add.
	(AC_CHECK_HEADERS): Add wchar.h.
	(AC_CHECK_FUNCS): Add mbrtowc.
	(AC_FUNC_CLOSEDIR_VOID): Add.

	* tests/Makefile.am (TESTS): Add delete02.sh.
	(POSTPONED_TESTS): Remove.
	(EXTRA_DIST): Remove $(POSTPONED_TESTS).

	* tests/preset.in:
	Set LC_ALL rather than LANGUAGE, LANG, and LC_MESSAGES.

	* tests/ignfail.sh (err): Adjust to new quoting scheme.

	* tests/delete02.sh: Fix typo: need to list archive2, not archive.

	* tests/extrac03.sh: Use -P option, so that .. doesn't get diagnosed.

	* src/tar.c ("quotearg.h"): New include.
	(usage): Now has __attribute__ ((noreturn)).
	(confirm): Report errno if we can't open tty.
	(confirm, decode_options):
	Quote arbitrary strings in diagnostics.
	(OVERWRITE_OPTION): New constant.
	(long_options, usage, decode_options): New --overwrite option.
	(decode_options): --keep-old-files, --overwrite, and --unlink-first
	are now mutually exclusive.
	Don't assume that gettext preserves errno.
	(main): Set default quoting style to escape_quoting_style.

	* src/update.c (<quotearg.h>): New include.
	(append_file):
	Don't assume that gettext preserves errno.
	Quote arbitrary strings in diagnostics.
	Check for close error.

	* src/names.c (<quotearg.h>): New include.
	(name_init, name_next, name_close, names_notfound,
	collect_and_sort_names): Don't assume that gettext preserves
	errno.  Quote arbitrary strings in diagnostics.
	(excluded_name): Fix typo that caused empty patterns to be
	mishandled.

	* src/misc.c (<quotearg.h>): New include.
	(quote_copy_string): Quote only newline and backslash; the output is no
	longer meant for humans, and is locale-independent.
	(contains_dot_dot): New function.
	(remove_any_file): Don't use lstat; just rmdir the file and then use
	unlink if the rmdir fails because the file isn't a directory.
	Check for readdir and closedir errors.
	(maybe_backup_file): Report "stat" for stat errors.
	(maybe_backup_file, chdir_do):
	Quote arbitrary strings in diagnostics.
	(maybe_backup_file, undo_last_backup):
	Don't assume that gettext preserves errno.
	(call_arg_error, call_arg_fatal, call_arg_warn,
	chdir_fatal, close_error, closedir_error, exec_fatal, mkfifo_error,
	mknod_error, open_error, open_fatal, open_warn, opendir_error,
	opendir_warn, read_error, read_fatal, readdir_error, readdir_warn,
	readlink_error, readlink_warn, seek_error, seek_warn, stat_error,
	stat_warn, truncate_error, truncate_warn, unlink_error, waitpid_error,
	write_error, write_fatal, xfork, xpipe, quote_n, quote): New functions.

	* src/system.h (__attribute__): New macro.
	(O_NDELAY, O_NONBLOCK, O_APPEND): Remove.
	(S_ISDOOR): New macro.
	(closedir): New macro, if CLOSEDIR_VOID.

	* src/rmt.c, src/rtapelib.c (decode_oflag):
	O_APPEND might not be defined.

	* src/list.c: (read_and, list_archive):
	Quote arbitrary strings in diagnostics.
	(from_header): Use locale_quoting_style to quote diagnostics.
	(print_header, print_for_mkdir): Quote with quotearg, not quote_copy_string.

	* src/rmt.h (REM_BIAS): Increase from 128 to (1 << 30).

	* src/Makefile.am: Use ## for copyright comments.

	* src/extract.c (<quotearg.h>): New include.
	(enum permstatus): New enum.
	(struct delayed_set_stat): file_name is now at end of buffer, to avoid
	two mallocs.  New members file_name_len, invert_permissions, permstatus.
	(extr_init): Remove hack that silently adjusted newdir_umask.
	(set_mode, set_stat): New args invert_permissions, permstatus, typeflag.
	Use these args to decide whether and how to set modes.
	(set_mode, set_stat, prepare_to_extract, extract_sparse_file, extract_archive):
	Don't assume that gettext preserves errno.
	(set_stat): Remove arg symlink_flag; subsumed by typeflag.
	(delay_set_stat, repair_delayed_set_stat): New functions.
	(make_directories): Avoid mkdir where last part of path is "..".
	Create a struct delayed_set_stat for each directory made.
	(prepare_to_extract): Renamed from unlink_destination, and
	return 0 immediately if to_stdout_option; all callers changed.
	(maybe_recoverable): New parameter interdir_made.
	Add support for --overwrite.
	(extract_sparse_file, extract_archive):
	Quote arbitrary strings in diagnostics.
	(extract_archive): By default, warn about ".." in member names, and skip them.
	Don't open files with O_NONBLOCK or O_APPEND.
	Open with O_TRUNC only if --overwrite; otherwise, use O_EXCL to avoid
	overwriting them.  Pass only rwxrwxrwx permissions to `open' and `mkdir',
	minus the current umask.  Keep track of intermediate directories made,
	to avoid looping when making x/../x when x doesn't exist; the
	earlier code solved this in a different way that didn't fit well
	into the new scheme.  Don't extract permissions onto existing
	directories unless --overwrite is given.  Do not add -wx------
	permissions to new directories permanently; just do it temporarily.
	Remove no-longer-needed hack with MSDOS and directory time stamps.
	(apply_delayed_set_stat): New argument specifies which directories to
	fix statuses of.  Do not wait until the end of extraction to fix
	statuses; instead, fix a directory's status once we exit that directory.
	This requires less memory and does the right thing in some cases
	where the old method didn't.
	(fatal_exit): New function.

	* src/incremen.c (<quotearg.h>): New include.
	(get_directory_contents, gnu_restore):
	Check for readdir and closedir errors.
	(get_directory_contents, read_directory_file, gnu_restore):
	Quote arbitrary strings in diagnostics.
	(get_directory_contents, read_directory_file, write_directory_file):
	Don't assume that gettext preserves errno.

	* src/create.c (<quotearg.h>): New include.
	(start_header): Use `member names' to refer to archive member names, not
	`archive names'.  Warn about `..' in member names.
	(finish_sparse_file, dump_file):
	Quote arbitrary strings in diagnostics.
	(finish_sparse_file, dump_file):
	Don't assume that gettext preserves errno.
	(dump_file): Don't use `access' to determine whether a directory is readable;
	this isn't reliable if tar is setuid.  Use `opendir' instead.
	Check for readdir and closedir failures.
	Don't dump sockets as if they were fifos; just warn and skip.

	* src/delete.c (move_archive):
	Don't report fatal error merely because sizes don't fit
	into struct mtop values; fall back on lseek instead.
	Say `Cannot' uniformly, instead of `Could not' sometimes and `Cannot' others.
	Say `reposition' instead of `re-position'.
	(delete_archive_members):
	Set archive to STDOUT_FILENO before outputting trailing buffer.

	* src/compare.c (<quotearg.h>): New include.
	(diff_init): Use `Cannot' uniformly, instead of `Could not' sometimes
	and `Cannot' others.
	(report_difference, diff_archive):
	Quote arbitrary strings in diagnostics.
	(process_rawdata, diff_sparse_files, get_stat_data, diff_archive, seek_warn):
	Don't assume that gettext preserves errno.
	(diff_archive): Don't open regular files with O_NONBLOCK.
	Preserve access times of files if --atime.

	* src/common.h (FATAL_ERROR): Use new fatal_exit function to exit.
	(FATAL_ERROR, USAGE): Don't return 0.
	(enum old files): New enum.
	(old_files_option): New variable, replacing keep_old_files_option and
	unlink_first_option.
	(apply_delayed_set_stat): Now takes char const * param.
	(fatal_exit, contains_dot_dot, chdir_fatal, close_error,
	closedir_error, exec_fatal, mkfifo_error, mknod_error, open_error,
	open_fatal, open_warn, opendir_error, opendir_warn, read_error,
	read_fatal, readdir_error, readdir_warn, readlink_error,
	readlink_warn, seek_error, seek_warn, stat_error, stat_warn,
	truncate_error, truncate_warn, unlink_error, waitpid_error,
	write_error, write_fatal, xfork, xpipe, quote, quote_n): New decls.

	* src/buffer.c:
	(xclose, xdup2, child_open_for_compress, child_open_for_uncompress,
	archive_write_error, archive_read_error, flush_archive, close_archive,
	init_volume_number, new_volume):
	Don't assume that gettext preserves errno.

	(xdup2): Don't report errno if dup returns an unexpected nonnegative value.
	(open_archive): Reject multivolume verify attempts a bit earlier.
	Rename local variable `access', in case it's defined by system header.

	(open_archive, backspace_output): Use `Cannot' uniformly, instead of
	`Could not' sometimes and `Cannot' others.

	(open_archive, flush_read, flush_archive, close_archive, new_volume):
	Quote arbitrary strings in diagnostics.

	(read_error): Set archive to STDOUT_FILENO temporarily when writing
	archive buffer.

	(init_volume_number): Check for input and output errors in volno_file.

	(new_volume): Use new fatal_exit function to exit, and new xfork
	function to fork.

	* m4/Makefile.am (EXTRA_DIST): Add c-bs-a.m4.

	* Makefile.am (ACINCLUDE_INPUTS): Add $(M4DIR)/c-bs-a.m4.

	* doc/tar.texi: Add --overwrite.
	--absolute-names rejects ".." in names.

	* lib/quotearg.c: Add support for multibyte characters.
	(ISGRAPH): Remove.
	(ISPRINT): New macro.
	(<wchar.h>): Include if HAVE_MBRTOWC && HAVE_WCHAR_H.
	(isprint, mbrtowc, mbsinit, mbstate_t): New macros,
	defined if ! (HAVE_MBRTOWC && HAVE_WCHAR_H).
	(quotearg_buffer_restyled): New function, with most of the old
	quotearg_buffer's contents.
	Major rewrite to support multibyte characters.
	(quotearg_buffer): Now just calls quotearg_buffer_restyled.

	* m4/c-bs-a.m4: New file.

	* lib/Makefile.am: Use ## for copyright notice.

	* scripts/Makefile.am: Use ## on copyright notice.

	* doc/Makefile.am:
	($(srcdir)/tar.info, tar.dvi): We now use texinfo 4.0.

1999-12-05  Paul Eggert  <eggert@twinsun.com>

	* doc/ChangeLog, lib/ChangeLog, scripts/ChangeLog,
	src/ChangeLog, tests/ChangeLog: Remove these files.
	* ChangeLog.1: New file, incorporating the above files, plus old
	ChangeLog entries.
	* Makefile.am (EXTRA_DIST): Add ChangeLog.1.

1999-12-05  Dale Worley  <worley@ariadne.com>

	* src/compare.c (<utime.h>, struct utimbuf): Add.
	(diff_archive): Restore access times if --atime.
	* doc/tar.texi: Explain that --atime also preserves modification time.

1999-12-04  Gerhard Poul  <gpoul@gnu.org>

	* ABOUT-NLS: Update to latest version from ftp.gnu.org.
	* BACKLOG, TODO: Remove.
	* Makefile.am (all-local, BABYL, dist-zoo, id, ID): Remove.
	* README: Bring up to date.

1999-12-03  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13.15.

	* src/compare.c (diff_archive):
	Do not set errno to EPIPE; we no longer use perror.

	* src/create.c (dump_file):
	If a parent directory said that a file should be there but it is
	absent, diagnose it as being removed in the meantime.
	Do not pass meaningless errno to ERROR when reporting that the
	file changed as we read it.
	Report that a file changed if its ctime changes; this is more
	sensitive than mtime+size, and more accurate.

	* src/incremen.c (enum children): New type.
	(struct directory): Change old char allnew member to new enum children
	children member.
	All uses changed.
	(get_directory_contents): When doing an incremental dump that does
	not cross filesystem boundaries, dump the mount points, even though
	they are in a different filesystem.  This is for convenience when
	restoring, and for consistency with non-incremental dumps.
	This requires a 3-way flag for keeping track of which children we want,
	so we use enum children rather than boolean.

	* src/open3.c (modes): Remove.
	(open3): Remove unportable assumptions about flag encodings.
	Use `stat' instead of `access' for testing file existence,
	to avoid problems with setuid programs.

	* src/names.c (name_next): If file names are given both in the
	command line (e.g. via -C) and in a file (via -T), do not
	ignore the command-line names.

	* m4/uintmax_t.m4: Backport to autoconf 2.13.

	* doc/tar.texi: Clarify getdate authorship.

1999-11-23  Paul Eggert  <eggert@twinsun.com>

	* lib/Makefile.am (DISTCLEANFILES): New macro.

	* configure.in (tar_fnmatch_hin):
	Remove; it runs afoul of a bug in autoconf 2.13.
	Instead, always link fnmatch.h to some file, even if it's a throwaway.

1999-11-19  Paul Eggert  <eggert@twinsun.com>

	* m4/largefile.m4: Update serial.

1999-11-18  Paul Eggert  <eggert@twinsun.com>

	* m4/largefile.m4 (AC_SYS_LARGEFILE_FLAGS): Work around a bug in
	the QNX shell, which doesn't propagate exit status of failed
	commands inside shell assignments.

1999-11-07  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13.14.

	* configure.in (AC_PREREQ): Bump to 2.13.
	(ALL_LINGUAS): Add pt_BR, ja.
	(AC_FUNC_FNMATCH): Remove lib/funmatch.h before invoking, not after.
	(tar_cv_path_RSH): Prefer a non-symlink rsh to a symlink one,
	for AIX crossbuilds.

	* doc/tar.texi: New node create options for --ignore-failed-read.
	Remove unused version control symbols.
	Modernize texinfo usage.

	* src/tar.c (usage): Add examples.

	* m4/fnmatch.m4 (AC_FUNC_FNMATCH):
	Include fnmatch.h when testing fnmatch.

	* src/common.h (collect_and_sort_names): New decl.

	* src/list.c (from_header):
	Handle 32-bit two's complement negative time stamps
	even if the leading octal digit is 2 or 3.

	* src/extract.c (set_stat): Remove duplicate code.

	* src/create.c (to_chars): Remove trailing newline from warning.
	(dump_file): Ignore doors.
	(finish_header): Report block numbers with origin 0, not origin 1.

	* src/rmt.c: Include getopt.h.
	(long_opts): New constant.
	(usage): New function.
	(main): Implement --help and --version.
	Output usage message if arguments are bad.

1999-10-10  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13.13.

	* README: Remove --with-dmalloc.
	Add --disable-largefile.
	Remove old NeXT dirent problems, or AIX valloc problems.
	Remove old union wait advice, and old %lld advice.
	Remove advice about FreeBSD 2.1.7, ISC 4.1mu, Ultrix `make'.

	* doc/tar.texi: Clarify documentation for portable file names.

	* configure.in (AM_WITH_DMALLOC): Remove.
	(ALL_LINGUAS): Add ja.

	* src/tar.c (decode_options):
	Invalid dates are now treated as (time_t) -1.
	Redo version message to conform to GNU standards.

	* src/create.c (dump_file):
	Fix typo: last two args to dump_file were interchanged.
	* src/update.c (update_archive): Likewise.

	* src/common.h (tartime): New decl.

	* src/list.c (tartime): Now extern.
	(read_and): Invalid headers cause errors, not warnings.

1999-10-03  Paul Eggert  <eggert@twinsun.com>

	* lib/getdate.y (__attribute__):
	Don't use if GCC claims to be before 2.8; this is
	needed for OPENStep 4.2 cc.  Also, don't use if strict ANSI.

1999-09-25  Paul Eggert  <eggert@twinsun.com>

	* lib/fnmatch.c, lib/fnmatch.hin: Merge changes from latest glibc.
	* lib/getopt.c, lib/getopt.h, lib/getopt1.c: Likewise.

	* tests/incremen.sh: Add yet another sleep.

1999-09-24  Paul Eggert  <eggert@twinsun.com>

	* NEWS: A read error now causes a nonzero exit status.

	* src/create.c (to_chars): Fix base-256 output.

	* src/buffer.c (write_error):
	Read error is an error, not just a warning.

1999-09-24  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13.12.

	* src/tar.c (<time.h>): Include.
	(time): Declare if not defined.
	(confirm): Don't read past EOF.
	(long_options, usage): Add --no-same-owner, --no-same-permissions.
	(main): Use clock_gettime if available.

	* tests/Makefile.am (TESTS): Add incremen.sh
	(INCLUDES): Add -I../lib, for fnmatch.h.

	* src/update.c (update_archive):
	Remove call to name_expand; had no effect.
	Use chdir_do to change into directory.
	Use deref_stat instead of stat.
	Use add_avoided_name to mark names to be avoided; the old method of
	setting a bit with the name caused all descendants of that name to
	be avoided, in some circumstances.

	* tests/incremen.sh: Remove unnecessary sleeps.

	* src/names.c (name_next): Go back to using plain chdir.
	(name_gather): Use chdir_arg to keep track of arguments to chdir.
	(addname): Likewise.
	(name_match): Use chdir_do to act on chdir args.
	(merge_sort): Moved here from incremen.c.
	(compare_names, add_hierarchy_to_namelist, collect_and_sort_names):
	Likewise.
	(name_expand): Remove.
	(name_from_list): Skip fake names.
	Use chdir_do to act on chdir args.
	(struct avoided_name): New struct.
	(avoided_names): New var.
	(add_avoided_name, is_avoided_name): New functions.

	* src/system.h (stat, lstat): Define in terms of statx on
	STX_HIDDEN && !_LARGE_FILES /* AIX */ hosts.
	(UCHAR_MAX): New macro.
	(TYPE_MAXIMUM): Cast to arg type, for types narrow than int.

	* m4/largefile.m4: Work around GCC 2.95.1 bug with HP-UX 10.20.

	* src/incremen.c (<time.h>): Remove include; no longer used.
	(time): Remove decl.
	(time_now): Remove.
	(get_directory_contents): Use deref_stat.
	Consider a subdirectory to be all new only if
	listed_incremental_option or if it its timestamp is newer than the
	cutoff.
	(add_hierarchy_to_namelist, merge_sort): Move to names.c.
	(read_directory_file): Now extern.  Do not set time_now.
	(write_directory_file): Renamed from write_dir_file.
	Use start_time instead of time_now.
	(compare_names, collect_and_sort_names): Move to names.c.

	* src/mangle.c (<time.h>): Remove; not used.
	(time): Do not declare.

	* src/misc.c (chdir_from_initial_wd): Remove.
	(deref_stat): New function.
	(struct wd): New struct.
	(wd, wds, wd_alloc): New variables.
	(chdir_arg, chdir_do): New function.

	* src/compare.c (get_stat_data): Use deref_stat.

	* src/common.h (name_expand): Remove.

	* src/list.c (time): Declare if not defined.
	(base_64_digits): Moved here from create.c.
	(base64_map): Use UCHAR_MAX for size, not less-clear (unsigned char)
	-1.
	(read_and): Don't get time from header unless we need it now;
	as getting time can cause duplicate diagnostics if bogus.
	Remove "Hmm, " from diagnostic.
	Use "Skipping to next header" uniformly.
	(from_header): Renamed from from_chars.  All uses changed.
	Allow different forms for unportable 2's complement numbers.
	Don't check for extended forms when parsing checksums.
	Parse base-256 output.
	(gid_from_header): Renamed from gid_from_chars.  All uses changed.
	(major_from_header): Renamed from major_from_chars.  All uses changed.
	(minor_from_header): Renamed from minor_from_chars.  All uses changed.
	(mode_from_header): Renamed from mode_from_chars.  All uses changed.
	(off_from_header): Renamed from off_from_chars.  All uses changed.
	(size_from_header): Renamed from size_from_chars.  All uses changed.
	(time_from_header): Renamed from time_from_chars.  All uses changed.
	Warn about future timestamps.
	(uid_from_header): Renamed from uid_from_chars.  All uses changed.
	(uintmax_from_header): Renamed from uintmax_from_chars.
	All uses changed.
	(tartime): New function, incorporating isotime.
	(isotime): Delete.
	(print_header): Use tartime.

	* src/create.c (to_chars): Fix typo in decl.
	Don't assign through char const *.
	Rename name_expand back to collect_and_sort_names.

	* src/extract.c (<time.h>): No need to include.
	(time): No need to declare.
	(now): Remove variable.
	(extr_init): Don't initialize `now'.
	Increment same_permissions_option and same_owner_option if we_are_root
	is nonzero; this supports the new --no-same-owner option.
	(set_stat): Use start_time instead of `now'.

	* src/create.c (struct link): Remove unused linkcount member.
	(base_64_digits): Move to list.c.
	(base_8_digits): Remove.
	(to_octal): New function, with some of old contents of to_base.
	(to_base): Remove.
	(to_base256): New function.
	(to_chars): Use base 256, not base 64, for huge values.
	(mode_to_chars): Don't use two's complement in GNU format or POSIX
	format.
	(dump_file): Interchange last two arguments. If TOP_LEVEL is negative,
	it means we have an incremental dump where we don't know whether this
	is a top-level call.
	Use deref_stat instead of statx / stat / lstat.
	Cast result of alloca.
	Check for dates if 0 < top_level, not if listed_incremental_option.
	Move multiple-link check after directory check.
	Do not dump avoided names.
	Dump hard links to symbolic names as links, not as separate
	symbolic links.
	start_header cannot return a null pointer, so don't test for it.
	Likewise for find_next_block.

	* src/buffer.c, src/common.h (<human.h>): Include.
	(read_error): Read error is an error, not just a warning.
	(print_total_written): Also print human-readable byte count, and
	bytes/s.
	(open_archive, flush_write): Use start_time, not current time.
	(flush_read): Report about garbage bytes ignored at end of archive,
	but act on non-garbage bytes (instead of ignoring them).
	(new_volume): Use WARN for warnings.

	* doc/Makefile.am:
	($(srcdir)/tar.info): Add -I$(srcdir) so that subdir builds work.

	* Makefile.am (ACINCLUDE_INPUTS): Add $(M4DIR)/fnmatch.m4.

	* m4/Makefile.am (EXTRA_DIST): Add fnmatch.m4.

	* lib/Makefile.am (noinst_HEADERS):
	Rename fnmatch.h to fnmatch.hin; add human.h.
	(libtar_a_SOURCES): Add human.c, xstrtoul.c.
	(INCLUDES): Remove -I.. -I$(srcdir) -- automake adds this for us.

	* src/Makefile.am (rmt_LDADD, tar_LDADD): New macros.

	* lib/fnmatch.c (strchrnul):
	Define to __strchrnul if _LIBC, to our own replacement otherwise.
	Do not define if !_LIBC and if it already exists.
	(internal_fnmatch): Use it.

	* configure.in (tar_LDADD): New variable, used only when linking tar.
	(rmt_LDADD): Similarly, for rmt.
	(AC_FUNC_FNMATCH): Link fnnmatch.hin to fnmatch.h if we're using our
	fnmatch.c; otherwise, use the system fnmatch.h.

	* doc/tar.texi: Add --no-same-owner, --no-same-permissions.
	Modernize sample backup script.

	* THANKS: Martin Goik's email address has changed.

	* m4/fnmatch.m4: New file.

1999-09-03  Paul Eggert  <eggert@twinsun.com>

	* lib/lchown.h (ENOSYS): Don't use ENOMSG; it's not in NeXTStep3.3.
	Use EINVAL instead.

1999-08-29  Paul Eggert  <eggert@twinsun.com>

	* lib/getdate.y (get_date):
	Rename outermost local `probe' to `quarter'.
	Rename latter local `tm' to probe_tm.
	From: Jim Meyering <meyering@ascend.com>
	Message-ID: <uryn1vafyyc.fsf@ixi.eng.ascend.com>

1999-08-28  Paul Eggert  <eggert@twinsun.com>

	* lib/getdate.y (PC): New macro; use it when possible.
	(number): Handle `Nov 11 1996' example correctly.
	See Risks Digest 20.55 (1999-08-27)
	http://catless.ncl.ac.uk/Risks/20.55.html#subj18

1999-08-23  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13.11.

	Remove minor cases of lint from many source files: this includes
	unnecessary casts, uses of NULL, etc.

	* configure.in (AC_PROG_YACC): Remove.
	(YACC): Always use bison.
	(AC_STRUCT_TIMEZONE): Add.
	(AC_REPLACE_FUNCS): Add strcasecmp, strncasecmp.

	* doc/tar.texi: --bzip2 is now -I.  Remove obsolete time zone info.
	Fix spelling.

	* lib/Makefile.am (EXTRA_DIST): Add strcasecmp.c, strncasecmp.c.
	($(srcdir)/getdate.c): Rename y.tab.c to getdate.c only if successful.

	* lib/strcasecmp.c, lib/strncasecmp.c: New files.

	* src/common.h (merge_sort): Remove decl; no longer exported.

	* src/system.h (voidstar): Remove.
	(memcpy, memcmp): Cast args.
	("xalloc.h"): Add include.
	(xmalloc, xrealloc): Remove decl.

	* src/mangle.c (time): Do not declare if defined.
	(first_mangle, mangled_num): Remove.

	* src/list.c (from_chars): Report out-of-range values more precisely.
	(off_from_chars): Do not allow negative offsets.
	(uid_from_chars): Allow negative uids.

	* src/create.c (linklist): Now static.
	(to_chars): Fix wording of message to match from_chars.

	* src/misc.c (merge_sort): Move to incremen.c.
	* src/incremen.c (merge_sort): Move here from misc.c; now static.
	It's too painful to make it both generic and portable.
	(read_directory_file): "timestamp" -> "time stamp" in messages.

	* src/tar.c (long_options, usage, main): -y is now -I (for --bzip).
	(usage): Fix misspelling.
	(OPTION_STRING): -y is now -I.
	(decode_options): Use -1, not EOF, for getopt_long result.
	Fix typo when invoking xstrtoumax: look for LONGINT_OK, not LONG_MAX.
	Handle operands after any "--" argument.
	(main): Report any output errors.

	* src/rmt.c (main): status is ssize_t, not long.

	* src/names.c (name_gather): Handle trailing -C option correctly.
	(addname): use memcpy, not strncpy, to copy a string of known length.
	(name_match): Handle trailing -C option correctly.
	Propagate -C option to following files.
	(name_match, name_scan): Remove redundant matching code.

	* src/buffer.c (open_archive): Use American spelling in diagnostic.

	* lib/getdate.y: Major rewrite.  Add copyright notice.
	(<stdio.h>): Include only if testing.
	(ISUPPER): Remove.
	(ISLOWER): New macro.
	(<string.h>): Include if HAVE_STRING_H, not USG.
	(bcopy): Remove.
	(yymaxdepth, ..., yycheck): Don't bother to redefine, since we assume
	bison.
	(EPOCH_YEAR): Renamed from EPOCH.
	(table): Renamed from TABLE.
	(meridian): Now an anonymous enum.
	(struct parser_control): New type.
	(YYLEX_PARAM, YYPARSE_PARAM, YYSTYPE): New macros.
	(yyInput, ..., yyRelYear): Migrated into struct parser_control.
	(%pure_parser): Added, so that the parser is pure.
	(%union): Removed; the type is now just plain int.
	All %type directives removed.
	(tLOCAL_ZONE): New %token.
	(month_day_table): Renamed from MonthDayTable.
	(gmtime, localtime, mktime, time): Declare only if not defined.
	(meridian_table): New table.
	(dst_table): New table.
	(units_table): renamed from UnitsTable.
	(relative_time_table): Renamed from OtherTable.
	(time_zone_table): Renamed from TimezoneTable.  Modernized.
	(military_table): Renamed from MilitaryTable.
	(to_hour): Renamed from ToHour.
	(to_year): Renamed from ToYear.
	(lookup_zone): New function.
	(LookupWord): Renamed from lookup_word.  Use lookup_zone for time
	zones.
	(yylex): Now reentrant.  All callers changed.
	(get_date): Add support for local time zone abbreviations.
	Make it reentrant.

1999-08-20  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13.10.

	* src/create.c (to_chars): Generate GNU base-64 representation
	if we are generating an old or new GNU format tar file for a
	number that can't be represented with the POSIX format.

	* configure.in (AC_CHECK_FUNCS): Add fchdir.
	(AM_FUNC_GETLINE): Add.
	(LIBOBJS): Add getline.o to workaround comment.
	* Makefile.am (ACINCLUDE_INPUTS): Add $(M4DIR)/getline.m4.
	* m4/Makefile.am (EXTRA_DIST): Add getline.m4.
	* lib/Makefile.am (noinst_HEADERS): Add getline.h, save-cwd.h.
	(libtar_a_SOURCES): Add save-cwd.c, xgetcwd.c.
	* lib/getline.c, lib/getline.h, lib/save-cwd.c,
	lib/save-cwd.h, m4/getline.m4: New files.

	* src/misc.c (<save-cwd.h>): Include.
	(chdir_from_initial_wd): New function.

	* src/names.c (name_next): Use chdir_from_initial_wd, not chdir.
	(name_gather): Handle `-C x -C y' correctly.
	Do not rely on addname to handle -C.
	(addname): New CHANGE_DIR parameter.  All callers changed.
	Remove ugly calls to getcwd; no longer needed.
	(name_match, name_from_list): Use chdir_from_initial_wd, not chdir.

	* src/incremen.c (listed_incremental_stream): New var.
	(read_directory_file): Remove arbitrary limits on file name length.
	Do not attempt to get the working directory; we can bypass this
	on fchdir hosts.  Open the listed_incremental_option file for both
	read and write instead of opening it twice.  Check for I/O errors
	when doing I/O to this file.  Check for invalid data in the file,
	and report line numbers of invalid data.
	(write_dir_file): Likewise.
	(collect_and_sort_names): Use chdir_from_initial_wd, not chdir.
	Do not invoke write_dir_file; that's our caller's responsibility.

	* src/list.c (max): New macro.
	(isotime): Now takes time_t, not time_t *.  Report the decimal values
	of times that can't be broken down.
	(print_header): Don't assume that major and minor device numbers can
	fit into uintmax_t.

	* src/common.h (struct name): change_dir is now char const *.
	(write_directory_file): Remove unused decl.
	(STRINGIFY_BIGINT): Assume b always points to UINTMAX_STRSIZE_BOUND
	chars; the old `sizeof (b)' broke when b was a pointer not an array.
	(chdir_from_initial_wd): New decl.
	(addname): New 2nd arg.

	* THANKS: Torsten Lull -> Catrin Urbanneck

1999-08-18  Paul Eggert  <eggert@twinsun.com>

	* configure.in (HAVE_GETHOSTENT, HAVE_SETSOCKOPT):
	Don't depend on ac_cv_func variables.
	From Albert Chin-A-Young <china@thewrittenword.com>.

1999-08-18  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13.9

	* m4/signedchar.m4: New file.
	* configure.in (pe_AC_TYPE_SIGNED_CHAR): Add.
	* src/system.h (signed_char): New macro.
	* Makefile.am (ACINCLUDE_INPUTS): Add $(M4DIR)/signedchar.m4.
	* m4/Makefile.am (EXTRA_DIST): Add signedchar.m4.

	* src/create.c (write_eot): Write at least two zero blocks.

	* src/extract.c (extract_archive): Fix sparse array bug:
	we did not find end of array correctly.

	* src/compare.c: (fill_in_sparse_array, diff_sparse_files):
	Don't assume find_next_block yields nonnull.
	* src/extract.c (extract_sparse_file, extract_archive): Likewise.
	* src/list.c (skip_extended_headers): Likewise.

	* src/list.c (read_and, list_archive): Simplify code.
	(read_header): Fix computation of signed checksums on machines where
	char is unsigned.
	Do not consider a block to be zero unless all its bytes are zero,
	even the checksum bytes.  Do not attempt to parse the checksum of
	a zero block.  Fix memory leak with long names and links.
	(from_chars): Accommodate a buggy tar that outputs leading NUL
	if the previous field overflows.

	* src/misc.c (quote_copy_string): Generate \177 for '\177', not
	\?, for portability to non-ASCII hosts.

1999-08-16  Paul Eggert  <eggert@twinsun.com>

	* configure.in (AM_INIT_AUTOMAKE), NEWS: Version 1.13.8.

	* src/extract.c (make_directories): Do not chown intermediate
	directories, even if we are root.

	* src/list.c (read_header): Fix bugs when interpreting
	POSIX-compliant headers that do not contain null bytes in the
	header or link names.

1999-08-14  Paul Eggert  <eggert@twinsun.com>

	* configure.in (AM_INIT_AUTOMAKE), NEWS: Version 1.13.7.

	* configure.in (AC_CHECK_HEADERS): Remove sys/wait.h.
	(AC_HEADER_SYS_WAIT): Add.
	(AC_REPLACE_FUNCS): Add waitpid.
	(tar_cv_header_union_wait, HAVE_UNION_WAIT): Remove.
	* lib/waitpid.c: New file.
	* lib/Makefile.am (EXTRA_DIST): Add waitpid.c.
	* src/system.h (WCOREDUMP): Remove; no longer used.
	(WIFSTOPPED): Likewise.
	(WEXITSTATUS, WIFSIGNALED): Default to Solaris 7 versions.
	* src/buffer.c (child_open_for_compress): Undo previous change.
	(close_archive): Use waitpid, POSIX-style, instead of old BSD style.
	(new_volume): Likewise.

	* src/buffer.c, src/extract.c, src/incremen.c (time):
	Don't declare if defined.
	* src/extract.c (extr_init): Remove unneeded cast around 0 arg to time.
	* src/incremen.c (read_directory_file):
	Invoke `time' the same way everyone else does.
	Check validity of --listed-incremental file contents a bit better.
	Do not worry about --after-date-option; tar.c now checks this.
	* src/list.c (isotime): Report ??? if localtime returns null.
	Don't assume years fit into four digits.
	Don't append trailing newline.
	(print_header): Report ??? if localtime returns null;
	Don't assume years fit into four digits.

	* src/compare.c (diff_archive): Do not fall back on absolute name
	when --absolute-names is not specified.

	* src/create.c (start_header):
	Include text of ignored filesystem prefix in warning.
	(create_archive): Check for excluded names when doing incremental
	pass through directory.
	(dump_file): Do not dump old files explicitly given on command line
	when using --listed-incremental.  Do not strip ./ prefix from names.

	* src/tar.c: -g now implies after_date_option = 1.
	-g and -N are now incompatible options.

	* doc/tar.texi: Explain --exclude better.  Don't strip leading `./'.

1999-08-11  Jeff Dairiki  <dairiki@dairiki.org>

	* src/list.c (read_header): Don't parse OLDGNU_FORMAT
	incremental headers as POSIX prefixes.

1999-08-11  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in: Version 1.13.6.

	* configure.in (ALL_LINGUAS): Add pt_BR.
	* po/pt_BR.po: New file.

	* doc/Makefile.am ($(srcdir)/tar.info, $(srcdir)/header.texi):
	Renamed from tar.info and header.texi; adjust actions so that
	they work in other directories.

	* doc/tar.texi: Add -y and --bzip2.
	Patterns containing / now exclude only file names whose prefix match.

	* lib/exclude.h (excluded_filename): New option parameter.
	(add_exclude_file): New ADD_FUNC parameter.
	(excluded_pathname): Remove decl.
	* lib/exclude.c (_GNU_SOURCE):
	Remove; no longer needed since we don't use FNM_ macros.
	(excluded_filename): Renamed from excluded_filename_opts.
	(excluded_filename, excluded_pathname): Remove.
	(add_exclude_file): New ADD_FUNC parameter.

	* po/POTFILES.in: Add lib/quotearg.c.

	* src/buffer.c (_GNU_SOURCE): Define.
	(<fnmatch.h>): Include unconditionally.
	(child_open_for_compress): Dup after closing, to avoid possible file
	descriptor exhaustion.
	(flush_write): Use FILESYSTEM_PREFIX_LEN instead of MSDOS ifdef.
	(flush_read): Likewise.

	* src/common.h (LG_8, LG_64): New macros.
	(excluded_with_slash, excluded_without_slash): New vars.
	(excluded): Remove.
	(base_64_digits): New decl.
	(gid_to_chars, major_to_chars, minor_to_chars, mode_to_chars,
	off_to_chars, size_to_chars, time_to_chars, uid_to_chars,
	uintmax_to_chars,
	GID_TO_CHARS, MAJOR_TO_CHARS, MINOR_TO_CHARS, MODE_TO_CHARS,
	OFF_TO_CHARS, SIZE_TO_CHARS, TIME_TO_CHARS, UID_TO_CHARS,
	UINTMAX_TO_CHARS):
	Renamed from gid_to_oct, major_to_oct, minor_to_oct, mode_to_oct,
	off_to_oct, size_to_oct, time_to_oct, uid_to_oct, uintmax_to_oct,
	GID_TO_OCT, MAJOR_TO_OCT, MINOR_TO_OCT, MODE_TO_OCT, OFF_TO_OCT,
	SIZE_TO_OCT, TIME_TO_OCT, UID_TO_OCT, UINTMAX_TO_OCT,
	respectively.  All definitions and uses changed.
	(excluded_name): New decl.

	* src/compare.c (diff_archive):
	Open files with O_NONBLOCK instead of O_NDELAY.

	* src/create.c (base_64_digits): New constant.
	(base_8_digits): New macro.
	(MAX_VAL_WITH_DIGITS): New macro.
	(to_base): First half of old to_oct.  Support base 64 too.
	(to_chars): Other half of old to_oct, for 64-bit support.
	(GID_NOBODY, UID_NOBODY): Don't define if the headers don't.
	(gid_substitute, uid_substitute): Look up names dynamically if
	GID_NOBODY and UID_NOBODY aren't defined; use -2 if all else fails.
	(mode_to_chars): Renamed from mode_to_oct.
	Support negative values in all the _to_chars functions.
	(start_header): Use FILESYSTEM_PREFIX_LEN instead of MSDOS ifdef.
	Abort if archive format is DEFAULT_FORMAT when it shouldn't be.
	(dump_file): Inspect entire pathname, not just new file name
	component, when deciding whether to exclude it.

	* src/extract.c (extract_archive):
	Open files with O_NONBLOCK instead of O_NDELAY.

	* src/incremen.c (get_directory_contents):
	Inspect entire pathname, not just new file name
	component, when deciding whether to exclude it.

	* src/list.c (<fnmatch.h>): Do not include.
	(from_chars): Renamed from from_oct.  New parameter specifying
	the negative of the minimum allowed value.  Support negative
	and base-64 values.
	(base64_map): New var.
	(base64_init): New function.
	(print_header): Output numeric uids and gids if numeric_owner_option.

	* src/misc.c (quote_copy_string): Use LG_8 instead of constants.

	* src/names.c (_GNU_SOURCE): Define.
	(<fnmatch.h>): Include unconditionally.
	(excluded_name): New function, taking over duties of excluded_pathname.
	All uses changed.

	* src/rmt.c (decode_oflag): New function.
	(main): Use it to support symbolic open flags.

	* src/rtapelib.c (encode_oflag): New function.
	(rmt_open__): Do not allow newlines in the path.
	Propagate errno correctly.
	Decode symbolic open flags, if present.

	* src/system.h (FILESYSTEM_PREFIX_LEN, ISSLASH, O_ACCMODE, O_NONBLOCK):
	New macros.

	* src/tar.c: (long_options, usage, OPTION_STRING, decode_options):
	New -y or --bzip2 option.
	(add_filtered_exclude): New function.
	(decode_options): Put excluded patterns with / into
	excluded_with_slash, and without / into excluded_without_slash.
	Compare newer_mtime_option to its new initial value
	TYPE_MINIMUM (time_t) when deciding whether more than one
	threshold date was specified.

1999-07-20  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in: Version 1.13.5.

	* src/common.h (FATAL_ERROR): Invoke apply_delayed_set_stat
	before exiting.
	* src/buffer.c (new_volume): Likewise.
	* src/incremen.c (read_directory_file): Likewise.
	* src/tar.c (decode_options):
	ERROR ((TAREXIT_FAILURE, ... -> FATAL_ERROR ((0,
	for consistency.

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13.4.
	* configure.in (AC_CHECK_FUNCS): Add lstat, readlink, symlink.

	* src/system.h (lstat): Define only if !HAVE_LSTAT && !defined lstat.
	(S_ISMPB, S_ISMPC, S_ISNWK): Remove unused macros.
	(S_ISBLK, S_ISCHR, S_ISCTG, S_ISFIFO, S_ISLNK, S_ISSOCK):
	Define to 0 if the corresponding S_IF* macro is not defined.
	(mkfifo): Do not define if already defined, or if S_IFIFO
	is not defined.

	* src/compare.c (diff_archive): Use HAVE_READLINK, not
	S_ISLNK, to determine whether to invoke readlink.
	* src/create.c (dump_file): Likewise.

	* src/extract.c (set_mode):
	Do not chmod unless we are root or the -p option was given;
	this matches historical practice.
	(unlink_destination): New function, which checks for unlink failures.
	(maybe_recoverable): Stay quiet if -U.
	(extract_archive): Use O_EXCL if unlink_first_option.
	Report unlink failures.
	Use HAVE_SYMLINK, not S_ISLNK, to determine whether symlink exists.
	Use HAVE_MKFIFO || defined mkfifo, not S_ISFIFO, to determine whether
	mkfifo exists.

	* src/incremen.c (get_directory_contents): Depend on
	S_ISHIDDEN, not AIX, to determine whether to invoke S_ISHIDDEN.

	* src/list.c: Remove S_IS* ifdefs.
	* src/misc.c (maybe_backup_file): Likewise.

	* src/misc.c (maybe_backup_file):
	"Virtual memory exhausted" -> "Memory exhausted",
	to conform to the other places this message is issued.

	* src/mangle.c (extract_mangle):
	Replace #ifdef S_ISLNK with #ifdef HAVE_SYMLINK.

	* src/rtapelib.c (rmt_open__):
	Remove typo that caused us to omit the first char
	of the basename.

1999-07-16  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): version 1.13.3.

	* doc/tar.texi: A path name is excluded if any of its file name
	components matches an excluded pattern, even if the path name was
	specified on the command line.
	* src/create.c (create_archive): Likewise.
	* src/list.c (read_and): Likewise.
	* src/update.c (update_archive): Likewise.
	* lib/exclude.h (excluded_pathname): New decl.
	* lib/exclude.c (_GNU_SOURCE): Define.
	(FILESYSTEM_PREFIX_LEN, ISSLASH): New macros.
	(excluded_filename_opts): New function.
	(excluded_pathname): New function.

	* lib/Makefile.am (EXTRA_DIST):
	xstrtol.c moved here from libtar_a_SOURCES.
	(libtar_a_SOURCES): Move xstrtol.c to EXTRA_DIST.
	Remove xstrtoul.c; no longer needed.
	* lib/xstrtol.c: Remove.

	* src/tar.c (decode_options):
	Set newer_time_option to TYPE_MINIMUM, so that
	negative timestamps are handled correctly.
	Replace invocations of xstrtol and xstrtoul with xstrtoumax, for
	uniformity (and so that we don't need to have the other fns).
	(main): Remove call to init_total_written; no longer needed.

	* configure.in (AC_CHECK_SIZEOF): Remove no-longer-needed
	checks for unsigned long and long long.
	* src/arith.c: Remove.
	* src/Makefile.am (tar_SOURCES): Remove arith.c.
	* po/POTFILES.in: Remove src/arith.c.
	* src/arith.h: Use double, to simplify configuration gotchas.
	(tarlong): Now double.
	(TARLONG_FORMAT): New macro.
	(BITS_PER_BYTE, BITS_PER_TARLONG, SUPERDIGIT, BITS_PER_SUPERDIGIT,
	LONGS_PER_TARLONG, SIZEOF_TARLONG, struct tarlong,
	zerop_tarlong_helper, lessp_tarlong_helper, clear_tarlong_helper,
	add_to_tarlong_helper, mult_tarlong_helper, print_tarlong_helper,
	zerop_tarlong, lessp_tarlong, clear_tarlong, add_to_tarlong,
	mult_tarlong, print_tarlong): Remove.  All callers replaced with
	arithmetic ops.

	* src/common.h (init_total_written): Remove decl.

	* src/buffer.c (total_written):
	Remove; replaced with prev_written + bytes_written.
	(prev_written): New var.
	(init_total_written): Remove.
	(print_total_written): Use TARLONG_FORMAT instead of print_tarlong.

	* m4/ulonglong.m4 (jm_AC_TYPE_UNSIGNED_LONG_LONG):
	Make sure that we can shift, multiply
	and divide unsigned long long values; Ultrix cc can't do it.

	* lib/modechange.c (mode_compile): Use uintmax_t, not unsigned long.
	Check for any unknown bits, not just unknown bits left of the leftmost
	known bit.

	* lib/quotearg.c (quotearg_buffer):
	Don't quote spaces if C quoting style.
	* src/list.c (from_oct):
	Use C quoting style for error; omit trailing NULs.

1999-07-14  Paul Eggert  <eggert@twinsun.com>

	* configure.in (AM_INIT_AUTOMAKE), NEWS: Version 1.13.2.

	* m4/xstrtoumax.m4 (jm_AC_PREREQ_XSTRTOUMAX): Check whether
	<inttypes.h> defines strtoumax as a macro (and not as a function).
	HP-UX 10.20 does this.

	* src/tar.c (usage): tar-bugs@gnu.org -> bug-tar@gnu.org
	* PORTS, README, TODO, doc/tar.texi: Likewise.

1999-07-12  Paul Eggert  <eggert@twinsun.com>

	* configure.in (AM_INIT_AUTOMAKE): Version 1.13.1.
	(LIBOBJS): Add mktime.o to automake 1.4 bug workaround.

	* src/list.c (decode_header):
	Do not assume that S_IFBLK and S_IFCHR are defined.

	* src/create.c (start_header): Do not assume S_IFMT is defined.
	(dump_file): Remove unnecessary check for screwy apollo lossage.
	Do not assume S_IFBLK and S_IFCHR are defined.

	* src/extract.c (extract_archive):
	Test whether S_IFCHR and S_IFBLK are nonzero,
	not whether they are defined, for consistency with other tests.

	* src/buffer.c (is_regular_file):
	Don't succeed on files that we can't access due to
	permissions problems.
	(open_archive): Fix wording on fatal error message.
	Don't bother to stat /dev/null if the archive is not a character
	special device.

	* src/compare.c (process_rawdata, diff_sparse_files, diff_archive):
	Report an error, not a warning, for I/O errors.
	(process_rawdata, process_dumpdir, diff_sparse_files):
	Change ungrammatical "Data differs" to "Contents differ".
	(get_stat_data): Find hidden files on AIX.
	Accept file name as argument; all uses changed.
	(get_stat_data, diff_archive): Use system error message for
	nonexistent files rather than rolling our own.
	(diff_archive): Unknown file types are errors, not warnings.
	Normalize spelling of message to "File type differs".
	Use get_stat_data to get link status, for consistency.
	Do not inspect st_rdev for fifos.
	Do not assume st_mode values contain only file types and mode bits.
	Check for mode changes and device number changes separately.

	* src/update.c (append_file):
	Open the file before statting it, to avoid a race.
	Complain about file shrinkage only when we reach EOF.

1999-07-08  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.13 released.

	* configure.in (AC_EXEEXT): Add.

	* lib/Makefile.am (noinst_HEADERS):
	Add basename.h, exclude.h.  Remove full-write.h.
	(libtar_a_SOURCES): Add exclude.c.

	* lib/basename.h, lib/exclude.c, lib/exclude.h, lib/safe-read.h:
	New files.
	* lib/full-write.c: Include safe-read.h instead of full-write.h.
	* lib/safe-read.h (safe_read): New decl.
	* src/rmt.c: Include safe-read.h.
	* src/rtapelib.c: Include basename.h, save-read.h.
	(rmt_open__): Use base_name to compute base name.

	* src/common.h:
	Include basename.h, exclude.h; don't include full-write.h.
	(exclude_option): Remove decl.
	(excluded): New decl.
	(add_exclude, add_exclude_file, check_exclude): Remove decls.

	* src/list.c (read_and):
	Use excluded_filename instead of check_exclude.
	Check base name of incoming file name, not entire file name, when
	deciding whether to exclude it.

	* src/create.c (finish_sparse_file):
	Use excluded_filename instead of check_exclude.
	Don't bother to stat excluded file names.
	* src/incremen.c (get_directory_contents): Likewise.

	* src/names.c (exclude_pool, exclude_pool_size,
	allocated_exclude_pool_size, simple_exclude_array,
	simple_excludes, allocated_simple_excludes,
	pattern_exclude_array, pattern_excludes,
	allocated_pattern_excludes, add_exclude, add_exclude_file,
	check_exclude):
	Remove; now done in ../lib/exclude.c.

	* src/tar.c (decode_options): Initialize `excluded'.
	Use new add_exclude_file and add_exclude functions.

1999-07-05  Paul Eggert  <eggert@twinsun.com>

	* m4/gettext.m4: Use changequote rather than [[ ]].

	* lib/safe-read.c: Renamed from lib/full-read.c.
	(safe_read): Renamed from full_read.  All uses changed.
	* lib/safe-read.h, lib/full-write.h: New files.
	* lib/Makefile.am (noinst_HEADERS): Add full-write.h, safe-read.h.
	(libtar_a_SOURCES): Rename full-read.c to safe-read.c.
	* lib/full-write.c: Include full-write.h.
	* src/common.h: Include full-write.h, safe-read.h.
	* src/system.h: (full_read, full_write): Remove decls.

	* src/Makefile.am (datadir): New var; needed for Solaris gettext.

	* src/system.h (bindtextdomain, textdomain): undef before
	defining, to avoid preprocessor warnings with --disable-nls
	on hosts whose locale.h includes libintl.h.

	* lib/xstrtol.c (__strtol): Remove decl; it doesn't work if __strtol
	expands to a macro, which occurs in HP-UX 10.20 with strtoumax.
	(strtol, strtoul): New decls (for pre-ANSI hosts), to replace
	the above decl.

1999-07-02  Paul Eggert  <eggert@twinsun.com>

	* Makefile.am (ACINCLUDE_INPUTS): Add $(M4DIR)/mktime.m4.
	* m4/mktime.m4: New file.
	* m4/Makefile.am.in, m4/README: Remove these files.
	* m4/Makefile.am (EXTRA_DIST): Add mktime.m4;
	remove README, Makefile.am.in.
	(Makefile.am): Remove rule; it didn't work in BSD/OS 4.0.
	* m4/jm-mktime.m4 (jm_FUNC_MKTIME): Invoke AC_FUNC_MKTIME,
	not AM_FUNC_MKTIME.

	* src/tar.c: Include signal.h.
	(SIGCHLD): Define to SIGCLD if SIGCLD is defined but SIGCHLD is not.
	(main): Ensure SIGCHLD is not ignored.

	(BACKUP_OPTION, DELETE_OPTION, EXCLUDE_OPTION, GROUP_OPTION,
	MODE_OPTION, NEWER_MTIME_OPTION, NO_RECURSE_OPTION, NULL_OPTION,
	OWNER_OPTION, POSIX_OPTION, PRESERVE_OPTION, RECORD_SIZE_OPTION,
	RSH_COMMAND_OPTION, SUFFIX_OPTION, USE_COMPRESS_PROGRAM_OPTION,
	VOLNO_FILE_OPTION, OBSOLETE_ABSOLUTE_NAMES,
	OBSOLETE_BLOCK_COMPRESS, OBSOLETE_BLOCKING_FACTOR,
	OBSOLETE_BLOCK_NUMBER, OBSOLETE_READ_FULL_RECORDS, OBSOLETE_TOUCH,
	OBSOLETE_VERSION_CONTROL): Make sure they can't be valid chars, so
	they don't overlap with char codes.  Use an enum instead of a lot
	of #defines.

	* src/system.h (ISASCII): Remove.
	(CTYPE_DOMAIN, ISDIGIT, ISODIGIT, ISPRINT, ISSPACE, S_ISUID,
	S_ISGID, S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP,
	S_IROTH, S_IWOTH, S_IXOTH, MODE_WXUSR, MODE_R, MODE_RW,
	MODE_RWX, MODE_ALL, SEEK_SET, SEEK_CUR, SEEK_END, CHAR_MAX,
	LONG_MAX): New macros.

	* src/incremen.c (ISDIGIT, ISSPACE): Remove; now in system.h.
	(read_directory_file): Cast ISSPACE arg to unsigned char.
	* src/misc.c (ISPRINT): Remove; now in system.h.
	(remove_any_file): Add brackets to pacify gcc -Wall.
	* src/list.c: Don't include <ctype.h>; system.h already does this.
	(ISODIGIT, ISSPACE): Remove; now in system.h.
	(decode_header): No need to AND mode with 07777; MODE_FROM_OCT
	does this now.
	(from_oct): Cast ISSPACE arg to unsigned char.

	* src/create.c (mode_to_oct): Translate modes from internal to
	external form.
	* src/list.c (mode_from_oct): Translate modes from external to
	internal form.  Do not complain about unrecognized mode bits.
	* src/common.h (TSUID, TSGID, TSVTX, TUREAD, TUWRITE, TUEXEC,
	TGREAD, TGWRITE, TGEXEC, TOREAD, TOWRITE, TOEXEC): Remove undefs.

	* src/extract.c: (extr_init, make_directories, extract_archive):
	Do not assume mode bits have traditional Unix values.
	* src/list.c (decode_mode): Likewise.
	* src/create.c (start_header, dump_file): Likewise.
	* src/buffer.c (child_open_for_compress,
	child_open_for_uncompress, open_archive, (close_archive): Likewise.
	* src/compare.c (diff_archive): Likewise.

	* src/extract.c (set_mode): Use %04 not %0.4 format.
	(extract_sparse_file): Do not use data_block uninitialized.
	Check for lseek failures.

	* src/rtapelib.c (rmt_lseek__):
	Convert lseek whence values to portable integers on the wire.
	* src/rmt.c (main): Likewise.  Check for whence values out of range.

	* src/create.c (finish_sparse_file): Use lseek whence macros
	instead of integers.
	* src/buffer.c (backspace_output): Likewise.
	* src/compare.c (diff_archive, verify_volume): Likewise.
	* src/delete.c (move_archive): Likewise.
	* src/extract.c (extract_sparse_file): Likewise.

	* src/create.c (dump_file): Do not invoke finish_sparse_file
	on a negative file descriptor.

	* src/buffer.c: Add braces to pacify gcc -Wall.

	* src/compare.c (diff_sparse_files): Report lseek errors.

	* configure.in (ALL_LINGUAS): Add cs, es, ru.

	* PORTS, TODO: gnu.ai.mit.edu -> gnu.org

	* src/arith.c, src/buffer.c (new_volume): Don't put ^G in
	message to be internationalized; \a doesn't work with msgfmt.

	* src/tar.c (long_options, main, usage, OPTION_STRING):
	Remove -E or --ending-file.
	* src/list.c (read_and): Likewise.
	* src/common.h (ending_file_option): Likewise.
	* src/buffer.c (close_archive): Likewise.

	* tests/after: Don't run two commands together in a pipeline,
	as some old shells mishandle pipeline exit status.

1999-06-28  Paul Eggert  <eggert@twinsun.com>

	* configure.in (AM_INIT_AUTOMAKE): version 1.12.64015.
	* NEWS: Describe changes since 1.12.
	* README: Update bug reporting address; move paxutils ref to NEWS.

	Handle EINTR correctly.
	* lib/Makefile.am (libtar_a_SOURCES): Add full-read.c, full-write.c.
	* lib/full-read.c, lib/full-write.c: New files.
	* src/buffer.c (child_open_for_compress, child_open_for_uncompress):
	Prefer full_read to read and full_write to write.
	* src/compare.c (process_rawdata, diff_sparse_files): Likewise.
	* src/create.c (deal_with_sparse, finish_sparse_file, dump_file):
	Likewise.
	* src/extract.c (extract_sparse_file): Likewise.
	* src/rmt.c (get_string, main, report_error_message,
	report_numbered_error): Likewise.
	* src/rmt.h (rmtread, rmtwrite): Likewise.
	* src/rtapelib.c (do_command, get_status_string, rmt_read__,
	rmt_write__, rmt_ioctl__): Likewise.
	* src/update.c (append_file): Likewise.
	* src/system.h (full_read, full_write): New decls.

	* po/POTFILES.in: Add lib/argmatch.c, lib/error.c lib/getopt.c,
	lib/xmalloc.c, src/arith.c, src/misc.c.

	* src/system.h (STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO):
	New macros.  All uses of STDIN and STDOUT changed.
	* src/rmt.c (prepare_record_buffer, main): Use STDIN_FILENO
	instead of 0 and STDOUT_FILENO instead of 1.
	* src/rtapelib.c (_rmt_rexec): Use STDIN_FILENO and STDOUT_FILENO
	instead of fileno (stdin) and fileno (stdout) or 0 and 1.

	* src/rmt.c (private_strerror): Avoid const.  Translate results.

	* tests/Makefile.am (TESTS): Remove incremen.sh; it doesn't work
	in the presence of NFS clock skew.

1999-06-25  Paul Eggert  <eggert@twinsun.com>

	* configure.in (AM_INIT_AUTOMAKE): version 1.12.64014.

	* src/buffer.c (write_archive_buffer): New function.
	(child_open_for_compress, flush_write, flush_read): Use it to write
	buffers.
	(open_archive): Report error if fstat of archive fails.
	Improve efficiency of check for /dev/null.
	Also, fix some corner cases with remote archives and /dev/null checking.
	(close_archive): Test for input fifo only if not remote.
	Truncate output archive only if it's not remote.

	* src/misc.c (remove_any_file):
	Don't terminate if you see . or ..; just skip them.

1999-06-18  Paul Eggert  <eggert@twinsun.com>

	* configure.in (AM_INIT_AUTOMAKE): version 1.12.64013.

	Output sizes using a format that's more compatible with
	traditional tar (and with GNU Emacs).
	* src/common.h (GID_TO_OCT, MAJOR_TO_OCT, MINOR_TO_OCT,
	MODE_TO_OCT, SIZE_TO_OCT, UID_TO_OCT, UINTMAX_TO_OCT):
	Don't subtract 1 from size.
	* src/create.c (to_oct): Prepend leading zeros, not spaces.
	Output a trailing NUL unless the value won't fit without it.
	(finish_header): No need to append NUL to chksum, now that
	to_oct is doing it.

1999-06-16  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): version 1.12.64012.

	* src/Makefile.am (LDADD): Link libtar.a after @INTLLIBS@, since
	@INTLLIBS@ might invoke rpl_realloc.

	* src/tar.c (backup_type): Remove decl; backupfile.h now has it.
	(intconv): Remove; use xstrto* fns instead.
	("xstrtol.h"): Include.
	(check_decimal): Remove.
	(long_options, usage, OPTION_STRING, decode_options):
	Remove -y, --bzip2, --unbzip2.
	(decode_options): Use xget_version instead of get_version.
	Check for overflow with -b and -L and RECORD_SIZE_OPTION.
	Replace invocations of check_decimal  with xstrtoumax.

	* tests/preset.in (echo_n, echo_c): Remove.

	* tests/after: Don't rely on $echo_c and $echo_n.

	* lib/addext.c, lib/dirname.c, lib/lchown.c, lib/lchown.h,
	lib/malloc.c, lib/mktime.c, lib/realloc.c, lib/strtol.c, lib/strtoul.c,
	lib/strtoull.c, lib/strtoumax.c, lib/utime.c, lib/xstrtol.c,
	lib/xstrtol.h, lib/xstrtoul.c, lib/xstrtoumax.c,
	m4/Makefile.am.in, m4/README, m4/ccstdc.m4, m4/d-ino.m4,
	m4/gettext.m4, m4/inttypes_h.m4, m4/isc-posix.m4,
	m4/jm-mktime.m4, m4/largefile.m4, m4/lcmessage.m4,
	m4/malloc.m4, m4/progtest.m4, m4/realloc.m4, m4/uintmax_t.m4,
	m4/ulonglong.m4, m4/utimbuf.m4, m4/utime.m4, m4/utimes.m4,
	m4/xstrtoumax.m4: New files.

	* configure.in(fp_PROG_ECHO): Remove; no longer needed.
	(AC_SYS_LARGEFILE): Renamed from AC_LFS.
	(jm_AC_HEADER_INTTYPES_H): Replaces inline code.
	(jm_STRUCT_DIRENT_D_INO, jm_AC_TYPE_UINTMAX_T, jm_AC_PREREQ_XSTRTOUMAX): Add.
	(AC_CHECK_FUNCS): Remove lchown.
	(AC_REPLACE_FUNCS): Remove basename, dirname.
	Add lchown, strtol, strtoul.
	(jm_FUNC_MKTIME): Add.
	(LIBOBJS): Replace .o with $U.o, so that the .o files in LIBOBJS
	are also built via the ANSI2KNR-filtering rules.
	Use a no-op line to work around bug in automake 1.4 with malloc and
	realloc.
	(AC_OUTPUT): Add m4/Makefile.

	* lib/Makefile.am (EXTRA_DIST):
	Add lchown.c, malloc.c, mktime.c, realloc.c,
	strtol.c, strtoul.c, strtoull.c, strtoumax.c, utime.c.
	(noinst_HEADERS): Add lchown.h, modechange.h, xstrtol.h.
	(libtar_a_SOURCES): Add addext.c, basename.c, xstrtol.c,
	xstrtoul.c, xstrtoumax.c.  Remove getversion.c.
	($(srcdir)/getdate.c:): Remove `expect conflicts' line.

	* src/system.h (uintmax_t): Don't declare; configure now does this.

	* src/common.h (backup_type): New decl.
	* src/common.h, src/misc.c, src/tar.c:
	Move include of backupfile.h to common.h.

	* src/misc.c (maybe_backup_file):
	Pass backup_type to find_backup_file_name.

	* src/list.c (print_header): Change sizes of uform and gform from 11 to
	UINTMAX_STRSIZE_BOUND.

	* doc/tar.texi: Remove --bzip2.
	Fix @xref typos reported by latest makeinfo.

	* Makefile.am (ACLOCAL_AMFLAGS): New macro.
	(SUBDIRS): Add m4.
	(M4DIR, ACINCLUDE_INPUTS): New macros.
	($(srcdir)/acinclude.m4): New rule.

	* acconfig.h (ENABLE_NLS, HAVE_CATGETS, HAVE_GETTEXT,
	HAVE_INTTYPES_H, HAVE_LC_MESSAGES, HAVE_STPCPY): Remve #undefs;
	now generated automatically by autoconf.

1999-05-15  Paul Eggert  <eggert@twinsun.com>

	* doc/tar.texi: Remove -y.

1999-04-09  Paul Eggert  <eggert@twinsun.com>

	* src/system.h (INT_STRLEN_BOUND): Fix off-by-factor-of-10 typo
	(we were allocating too much storage).
	(uintmax_t): Don't declare; configure now does this.

	* ABOUT-NLS: Update to gettext 0.10.35 edition.

1999-03-22  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): version 1.12.64010

	* acinclude.m4 (AC_LFS_FLAGS):
	Don't use -mabi=n32 with GCC on IRIX 6.2; it's the default.
	(AC_LFS): -n32, -o32, and -n64 are CPPFLAGS, not CFLAGS.
	(jm_FUNC_MALLOC, jm_FUNC_REALLOC): New macros.

	* configure.in (jm_FUNC_MALLOC, jm_FUNC_REALLOC):
	New macros; needed for latest GNU xmalloc.c.

	* Makefile.am (noinst_HEADERS): Add quotearg.h, xalloc.h.
	(libtar_a_SOURCES): Add quotearg.c.
	* list.c: Include <quotearg.h>.
	(from_oct): Add forward decl.
	(read_header): Return HEADER_FAILURE if we can't parse the checksum.
	(from_oct): Report an error only if TYPE is nonzero.
	Quote any funny characters in bad header.

1999-03-20  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): version 1.12.64009

	* acinclude.m4 (AC_LFS_FLAGS): Add support for IRIX 6.2 and later.
	(AC_LFS_SPACE_APPEND): Assume $2 is quoted properly; all callers
	changed.
	(AC_LFS): Simplify AIX revision number test.

1999-03-17  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): version 1.12.64008

	* configure.in (AC_VALIDATE_CACHED_SYSTEM_TUPLE):
	Remove; it doesn't work that well
	with AC_CANONICAL_HOST.
	(fp_WITH_INCLUDED_MALLOC): Remove; we'll just use the system malloc.

	* Makefile.am (EXTRA_DIST): Remove AC-PATCHES, AM-PATCHES, BI-PATCHES.

	* Makefile.am (EXTRA_DIST): Remove gmalloc.c.

	* acinclude.m4 (fp_WITH_INCLUDED_MALLOC): Remove.

	* tar.texi: Fix bug-report addr.

	* README: Remove --with-included-malloc.
	Upgrade version numbers of build software.

1999-03-07  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.12.64007.

	* acinclude.m4 (AM_WITH_NLS): Port to Solaris 2.5.1,
	where bindtextdomain and gettext require -lintl.
	(AC_LFS_FLAGS): Simplify so that it only gets the flags;
	`no' means it failed.
	(AC_LFS_SPACE_APPEND, AC_LFS_MACRO_VALUE): New macros.
	(AC_LFS): Use them.  Set _FILE_OFFSET_BITS, _LARGEFILE_SOURCE, and
	_LARGE_FILES from LFS_CFLAGS, so that in the normal case we don't need
	to add anything to the command line (it's all in config.h).
	Put any extra -D and -I options into CPPFLAGS, the rest into CFLAGS.

1999-03-01  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.12.64006.

	* acinclude.m4 (AC_LFS_FLAGS): Port to AIX 4.2.

	* src/list.c: (gid_from_oct, major_from_oct, minor_from_oct,
	mode_from_oct, off_from_oct, size_from_oct, time_from_oct,
	uid_from_oct, uintmax_from_oct): Use TYPE_MAXIMUM instead of macros
	like OFF_MAX, which are not reliable
	(e.g. OFF_MAX in AIX 4.2 is incorrect).
	* src/system.h (GID_MAX, MAJOR_MAX, MINOR_MAX, MODE_MAX, OFF_MAX,
	SIZE_MAX, TIME_MAX,UID_MAX, UINTMAX_MAX):  Remove; no longer used.

	* src/incremen.c (get_directory_contents):
	Don't use statx if _LARGE_FILES; it doesn't work under AIX 4.2.
	Have statx depend on STX_HIDDEN, not AIX.

	* src/create.c (to_oct):
	New parameter substitute, giving a substitute value to use
	when the original value is out of range.  Do not append a space to the
	output; modern tars don't.  When a value is out of range, specify the
	maximum value, not the number of bits.
	(GID_NOBODY, UID_NOBODY): New macros.
	(gid_to_oct, uid_to_oct): Use them as substitutes.
	(finish_header): Do not assume that UINTMAX_TO_OCT appends a space.
	(dump_file): Check whether the file changed as we read it.

	* src/rmt.c (main): Remove suspicious AIX/386 code.

1999-02-19  Paul Eggert  <eggert@twinsun.com>

	* intl/localealias.c (read_alias_file): Don't assume that memcpy
	returns a type compatible with char *; it doesn't on SunOS
	4.1.4 with Sun cc, since <string.h> doesn't declare memcpy.

	* NEWS, configure.in (AM_INIT_AUTOMAKE): Version 1.12.64005.

	* src/tar.c (long_options, usage): Prefer --unbzip2 to --bunzip2.
	* doc/tar.texi: Add --bzip2, --unbzip2 options.

	* configure.in (AC_CANONICAL_HOST, AC_VALIDATE_CACHED_SYSTEM_TUPLE):
	Add.
	(AC_LINK_FILES): Omit; AM_GNU_GETTEXT now does this.
	(AC_OUTPUT): Omit munging of po/Makefile; AM_GNU_GETTEXT now does this.
	* acinclude.m4 (AM_WITH_NLS):
	Update to latest gettext version (serial 5).
	(AC_LFS_FLAGS): New macro
	(AC_LFS): Use it.  Append to CFLAGS, LDFLAGS, LDLIBS instead of
	working only with unset variables.  Append to CFLAGS, not CPPFLAGS.
	Work properly in cross-compilation scenario, by checking for getconf
	with AC_CHECK_TOOL and by ditching uname in favor of
	AC_CANONICAL_HOST and $host_os.  Add --disable-lfs option.

	* lib/getdate.y: Update to fileutils 4.0 getdate.y, with one patch:
	replace FORCE_ALLOCA_H with HAVE_ALLOCA_H.
	* lib/Makefile.am (AUTOMAKE_OPTIONS): Append ../src/ansi2knr,
	since getdate.y now uses ANSI code.

	* config.guess, config.sub: New files; taken from automake 1.4.

	* intl/Makefile.in, intl/VERSION, intl/bindtextdom.c,
	intl/cat-compat.c, intl/dcgettext.c, intl/dgettext.c,
	intl/explodename.c, intl/finddomain.c, intl/gettext.c,
	intl/gettext.h, intl/gettextP.h, intl/hash-string.h,
	intl/l10nflist.c, intl/libgettext.h, intl/loadinfo.h,
	intl/loadmsgcat.c, intl/localealias.c, intl/textdomain.c:
	Update to GNU gettext 0.10.35, with patches as per GCC snapshot 990109.

1999-02-01  Paul Eggert  <eggert@twinsun.com>

	* src/tar.c: Update copyright.

	* NEWS: 1.12.64004

1999-02-01  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in: Version 1.12.64004

	* configure.in (AC_LFS): Use this macro, instead of open-coding it.

	* acinclude.m4 (AC_LFS, AM_PROG_CC_STDC): New macros.

	* src/extract.c (extract_archive): Fix bug when extracting sparse
	files: they were trashing the tar file header.

	* src/tar.c: (long_options, usage, OPTION_STRING, decode_options):
	Add -y or --bzip2 or --bunzip2 option.

1999-01-30  Paul Eggert  <eggert@twinsun.com>

	* src/names.c (cached_no_such_uname, cached_no_such_gname,
	cached_no_such_uid, cached_no_such_gid): New vars.
	(uid_to_uname, gid_to_gname, uname_to_uid, gname_to_gid):
	Cache failures, too.

	* src/tar.c (decode_options):
	Don't pass names longer than UNAME_FIELD_SIZE to
	uname_to_uid, as it messes up the cache.  Similarly for gname_to_uid.

1999-01-27  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in: Version 1.12.64003

	* src/buffer.c (backspace_output, close_archive):  Cast
	rmtlseek position arg to off_t, for benefit of K&R compilers
	with long long.
	* src/compare.c (verify_volume): Likewise.

	* NEWS, configure.in: Version 1.12.64002

	* src/create.c (gid_to_oct, major_to_oct, minor_to_oct, mode_to_oct,
	off_to_oct, size_to_oct, time_to_oct, uid_to_oct):
	Cast arg to uintmax_t for benefit of pre-ANSI compilers with long long.
	* src/list.c: (gid_from_oct, major_from_oct, minor_from_oct,
	mode_from_oct, off_from_oct, size_from_oct, time_from_oct,
	uid_from_oct): Likewise.

1999-01-25  Paul Eggert  <eggert@twinsun.com>

	* incremen.sh: Fix timing bug in regression test.

1999-01-22  Paul Eggert  <eggert@twinsun.com>

	* NEWS, configure.in: Update version

	* Makefile.am (localedir): Change to $(datadir)/locale.
	(DEFS): New macro, defining LOCALEDIR.
	(tar.o, tar._o, rmt.o, rmt._o): Remove.
	(INCLUDES): Add -I..

	* Makefile.am (localedir): Change to $(datadir)/locale.

1999-01-21  Paul Eggert  <eggert@twinsun.com>

	* NEWS, README, configure.in: Unofficial version 1.12.64001.

	* tests/Makefile.am (localedir): Change to $(datadir)/locale.
	* src/Makefile.am (localedir): Likewise.
	(DEFS): New macro, defining LOCALEDIR.
	(tar.o, tar._o, rmt.o, rmt._o): Remove.
	(INCLUDES): Add `-I..'.

	* tests/incremen.sh: Fix timing bug.

1999-01-20  Paul Eggert  <eggert@twinsun.com>

	* NEWS, README, configure.in: Unofficial version 1.12.64000.
	`lfs.7' changed to `64000' in version number
	to conform to gnits standards.

	* COPYING, INSTALL, doc/texinfo.tex, install-sh, missing,
	mkinstalldirs, ansi2knr.c: Update to latest public versions.

	Rebuild with automake 1.4 and autoconf 2.13, to work around some
	porting problems.

1998-12-07  Paul Eggert  <eggert@twinsun.com>

	* NEWS, README, configure.in: Unofficial version 1.12.lfs.6.

	* src/list.c (read_header):
	Accept file names as specified by POSIX.1-1996 section 10.1.1.

1998-11-30  Paul Eggert  <eggert@twinsun.com>

	* configure.in: Quote the output of uname.

	* src/extract.c (set_stat): chmod after chown even when not root;
	if we are using --same-owner this is needed e.g. on Solaris 2.5.1.

1998-11-15  Paul Eggert  <eggert@twinsun.com>

	* NEWS, README, configure.in: Unofficial version 1.12.lfs.5.

	* configure.in (ac_test_CPPFLAGS, ac_test_LDFLAGS, ac_test_LIBS,
	ac_getconfs, ac_result): Special case for HP-UX 10.20 or later.

1998-10-28  Paul Eggert  <eggert@twinsun.com>

	* NEWS, README, configure.in: Unofficial version 1.12.lfs.4.

	* src/system.h (voidstar): Use void * if __STDC__ is defined,
	not merely nonzero.

	* src/rtapelib.c: Don't use rexec code unless compiled with WITH_REXEC.
	On many installations, rexec is disabled.

1998-08-07  Paul Eggert  <eggert@twinsun.com>

	* NEWS, README, configure.in: Unofficial version 1.12.lfs.3.

	* src/names.c (uid_to_uname, gid_to_gname): Don't used cached name
	for nameless users and groups.

1998-02-17  Paul Eggert  <eggert@twinsun.com>

	* NEWS, README, configure.in: Unofficial version 1.12.lfs.2.
	* NEWS, README: Add explanation of why this isn't an official version.

1998-02-02  Paul Eggert  <eggert@twinsun.com>

	* NEWS, README, configure.in: Unofficial version 1.12.lfs.1.
	This is an unofficial version.

1997-12-17  Paul Eggert  <eggert@twinsun.com>

	* src/incremen.c (ST_DEV_MSB): New macro.
	(NFS_FILE_STAT): Use most significant bit of st_dev,
	even if it's unsigned.

1997-12-08  Paul Eggert  <eggert@twinsun.com>

	* src/system.h (ST_NBLOCKS): Fix typo in definition.

1997-11-19  Paul Eggert  <eggert@twinsun.com>

	* configure.in (HAVE_INTTYPES_H):
	Don't ignore cache variable if it's already set.

1997-11-10  Paul Eggert  <eggert@twinsun.com>

	* src/rmt.c (main): Don't assume mt_count is of type daddr_t.
	* src/delete.c (records_read): Now off_t.
	(move_archive): Don't assume mt_count is of type daddr_t.

1997-10-30  Paul Eggert  <eggert@twinsun.com>

	* configure.in (CPPFLAGS, LDFLAGS, LIBS):
	Set to appropriate values if large file support
	needs explicit enabling.
	(HAVE_INTTYPES_H, HAVE_ST_FSTYPE_STRING, daddr_t, major_t, minor_t,
	ssize_t):
	New macros to configure.
	(AC_TYPE_MODE_T, AC_TYPE_PID_T, AC_TYPE_OFF_T): Add.

	* acconfig.h (daddr_t, HAVE_INTTYPES_H, HAVE_ST_FSTYPE_STRING,
	major_t, minor_t, ssize_t): New macros.

	* src/arith.h (TARLONG_FORMAT):
	Fix typo: %uld -> %lu.  Use unsigned when long long
	(%lld -> %llu).
	(add_to_tarlong_helper, mult_tarlong_helper): 2nd arg is now unsigned long.
	(add_to_tarlong, mult_tarlong): Cast 2nd arg to unsigned long.

	* src/arith.c (add_to_tarlong_helper, mult_tarlong_helper):
	2nd arg is now unsigned long.

	* src/rmt.c (allocated_size): Now size_t, and now initialized to 0.
	(prepare_record_buffer): Arg is now size_t.
	Remove now-useless casts.

	(main): Use `long' for status, so that it can store ssize_t.
	Use daddr_t, mode_t, size_t, off_t when appropriate.
	Convert daddr_t and off_t values ourselves, since they might be longer
	than long.  Convert other types using `long' primitives.
	When processing MTIOCTOP, do not try to pass resulting
	count back, since it won't work (it could be too large) and it's
	not expected anyway.

	* src/update.c:
	(append_file) Use off_t, size_t, ssize_t when appropriate.  Remove
	now-useless casts.  Use unsigned long to print *_t types, except use
	STRINGIFY_BIGINT for off_t.
	(update_archive): Cast -1 to dev_t when necessary.

	* src/tar.c (check_decimal):
	Now returns 1 if successful, 0 otherwise, and returns
	uintmax_t value into new arg.  Check for arithmetic overflow.
	(decode_options): Avoid overflow if record_size fits in size_t but not int.
	Check for overflow on user or group ids.

	* src/compare.c (diff_init, process_rawdata, read_and_process,
	diff_sparse_files, diff_archive):
	Use off_t, pid_t, size_t, ssize_t when appropriate.
	Remove now-useless casts.  Use unsigned long to print *_t types,
	except use STRINGIFY_BIGINT for off_t.

	(process_noop, process_rawdata, process_dumpdir, read_and_process):
	Size arg is now size_t.

	(diff_sparse_files): Arg is now off_t.  Check for size_t overflow
	when allocating buffer.

	* src/rtapelib.c:
	(do_command, rmt_open__, rmt_read__, rmt_lseek__, rmt_ioctl__):
	Use pid_t, size_t, ssize_t when appropriate.  Remove now-useless casts.
	Use unsigned long to print *_t types, except use STRINGIFY_BIGINT for
	off_t.

	(get_status_string, get_status_off): New function.
	(get_status): Now returns long, so that it can store ssize_t.
	Invoke get_status_string to do the real work.
	(rmt_read__, rmt_write__): Now returns ssize_t. Size arg is now size_t.
	(rmt_lseek__): Now returns off_t, using new get_status_off function.
	(rmt_ioctl__): Convert mt_count by hand,
	since it might be longer than long.

	* src/mangle.c (extract_mangle):
	Check for overflow when converting off_t to size_t.
	Use off_t, size_t when appropriate.  Remove now-useless casts.

	* src/system.h (mode_t): Remove; now done by autoconf.
	(ST_NBLOCKS): Do not overflow if st_size is near maximum.
	Return number of ST_NBLOCKSIZE-byte blocks,
	not number of 512-byte blocks;
	this also helps to avoid overflow.
	(st_blocks): Declare if needed.
	(ST_NBLOCKSIZE): New macro.
	(<limits.h>, <inttypes.h>): Include if available.
	(CHAR_BIT): New macro.
	(uintmax_t): New typedef.
	(TYPE_SIGNED, TYPE_MINIMUM, TYPE_MAXIMUM, INT_STRLEN_BOUND,
	UINTMAX_STRSIZE_BOUND, GID_MAX, MAJOR_MAX, MINOR_MAX, MODE_MAX,
	OFF_MAX, SIZE_MAX, TIME_MAX, UID_MAX, UINTMAX_MAX): New macros.

	* src/names.c (name_init):
	Fix typo in error message: FILE* was passed, but char*
	was wanted.

	(read_name_from_file, name_gather, addname, name_match, name_scan,
	add_exclude): Use size_t when appropriate.  Remove now-useless casts.

	(exclude_pool_size, allocated_exclude_pool_size): Now size_t.

	* src/extract.c (newdir_umask, current_umask): Now mode_t.
	(extract_sparse_file): Args now use off_t.

	(set_mode, set_stat, make_directories, extract_sparse_file,
	extract_archive): Use off_t, size_t, ssize_t when appropriate.  Remove
	now-useless casts.  Use unsigned long to print *_t types, except use
	STRINGIFY_BIGINT for off_t.

	* src/misc.c (quote_copy_string):
	Use size_t when appropriate.  Remove now-useless casts.

	* src/list.c (read_and, list_archive, read_header, decode_mode,
	print_header, print_for_mkdir):
	Use mode_t, off_t, size_t when appropriate.  Remove
	now-useless casts.  Use unsigned long to print *_t types, except use
	STRINGIFY_BIGINT for off_t.

	(read_header): Check for overflow when converting header size.

	(from_oct): Now static.  Now returns uintmax_t.  `where' arg is now
	const char *.  Size arg is now size_t.  Now takes new type and maxval
	args.  Compute result using uintmax_t, not long.  Report error if
	field does not contain octal number in range.
	(gid_from_oct, major_from_oct, minor_from_oct, mode_from_oct,
	off_from_oct, size_from_oct, time_from_oct, uid_from_oct,
	uintmax_from_oct): New functions.

	(stringify_uintmax_t_backwards): New function.

	(decode_mode, print_for_mkdir): Mode arg is now mode_t.
	(skip_file): Offset arg is now off_t.

	* src/buffer.c (record_start_block, save_totsize, save_sizeleft,
	real_s_totsize, real_s_sizeleft, current_block_ordinal):
	Now off_t.
	(write_error): Arg is now ssize_t.
	(child_pid): Now pid_t.
	(available_space_after): Now size_t.

	(child_open_for_compress, child_open_for_uncompress, flush_write,
	open_archive, flush_write, write_error, flush_read, close_archive):
	Use pid_t, ssize_t, size_t when appropriate.  Remove now-useless
	casts.  Use unsigned long to print *_t types, except use
	STRINGIFY_BIGINT for off_t.

	* src/delete.c (records_read): Now daddr_t.
	(move_archive): Arg is now daddr_t.  Check for overflow when
	computing offset.
	(move_archive, delete_archive_members): Use daddr_t, off_t when
	appropriate.  Remove now-useless casts.

	* src/rmt.h (rmt_read__, rmt_write__): Now returns ssize_t.
	(rmt_lseek): Now returns off_t.

	* src/create.c (to_oct):
	Now static.  Value arg is now uintmax_t.  Accept new args
	giving name of type of octal field, for error messages.  Report an
	error if the value is too large to fit in the field.
	(gid_to_oct, major_to_oct, minor_to_oct, mode_to_oct, off_to_oct,
	size_to_oct, time_to_oct, uid_to_oct, uintmax_to_oct): New functions.

	(write_eot, write_long, finish_header, deal_with_sparse,
	finish_sparse_file, dump_file): Use dev_t, off_t, ssize_t, size_t when
	appropriate.  Remove now-useless casts.  Use unsigned long to print
	*_t types, except use STRINGIFY_BIGINT for off_t.

	(find_new_file_size): 1st arg is now off_t*.
	(finish_sparse_file): Args now use off_t, not long.
	Check for lseek error.
	(create_archive, dump_file): Cast -1 to dev_t when necessary.
	(dump_file): Device arg is now dev_t.
	Avoid overflow when testing whether file has holes
	by using the new ST_NBLOCKSIZE macro.

	* src/incremen.c (struct accumulator, add_to_accumulator,
	get_directory_contents, add_hierarchy_to_namelist, gnu_restore):
	Use size_t for sizes.
	(struct directory, get_directory_contents, add_hierarchy_to_namelist):
	Use dev_t, ino_t for devices and inodes.
	(gnu_restore): Use off_t for file offsets.
	(struct directory): Use char for flags.  Add new flag `nfs'.
	(nfs): New constant
	(NFS_FILE_STAT): New macro.
	(note_directory): Accept struct stat * instead of
	device and inode number.  All callers changed.
	(note_directory, get_directory_contents):
	Use NFS_FILE_STAT to determine whether directory is an NFS directory.
	(write_dir_file): Cast time_t to unsigned long before printing as %lu.

	* src/common.h (record_size, struct name, struct sp_array,
	available_space_after):
	Use size_t for sizes.
	(save_sizeleft, save_totsize, current_block_ordinal, skip_file):
	Use off_t for file offsets.
	(struct name): dir_contents is now const char *, not char *.
	(dump_file, get_directory_contents): Use dev_t for devices.
	(to_oct): Remove decl.
	(GID_TO_OCT, MAJOR_TO_OCT, MINOR_TO_OCT, MODE_TO_OCT, SIZE_TO_OCT,
	UID_TO_OCT, UINTMAX_TO_OCT, OFF_TO_OCT, TIME_TO_OCT, STRINGIFY_BIGINT,
	GID_FROM_OCT, MAJOR_FROM_OCT, MINOR_FROM_OCT, MODE_FROM_OCT,
	OFF_FROM_OCT, SIZE_FROM_OCT, TIME_FROM_OCT, UID_FROM_OCT,
	UINTMAX_FROM_OCT): New macros.
	(gid_to_oct, major_to_oct, minor_to_oct, mode_to_oct, off_to_oct,
	size_to_oct, time_to_oct, uid_to_oct, uintmax_to_oct,
	stringify_uintmax_t_backwards, gid_from_oct, major_from_oct,
	minor_from_oct, mode_from_oct, off_from_oct, size_from_oct,
	time_from_oct, uid_from_oct, uintmax_from_oct): New decls.
	(print_for_mkdir): 2nd arg is now mode_t.

	-----

	See ChangeLog.1 for earlier changes.

	-----

	Copyright (C) 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005, 2006, 2007
	Free Software Foundation, Inc.

	This file is part of GNU tar.

	GNU tar is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.

	GNU tar is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with GNU tar; see the file COPYING.  If not, write to
	the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
	Boston, MA 02110-1301, USA.

Local Variables:
mode: change-log
version-control: never
End: