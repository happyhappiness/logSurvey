-Current Version: 1.11.2
-
-
-User-visible changes since 1.11.1:
-
-o Changes in backup scripts
-  - cleaned up considerably; notices error conditions better over rsh
-  - DUMP_REMIND_SCRIPT is now an option in backup-specs
-  - new file dump-remind is an example of a DUMP_REMIND_SCRIPT
-o Superfluous "Reading dirname" was a bug; fixed.
-o Incompatibility problems with a bug on Solaris are fixed.
-o New option --gzip (aliases are --ungzip and -z); calls gzip instead
-  of compress.  Also, --use-compress-program lets you specify any
-  compress program.  --compress-block is renamed --block-compress and
-  now requires one of the three compression options to be specified.
-o Several error messages are cleaned up.
-o Directory owners are now set properly when running as root.
-o Provide DUMP_REMIND_SCRIPT in backup-specs as a possible option 
-  for --info-script.
-o Behave better with broken rmt servers.
-o Dump scripts no longer use --atime-preserve; this causes a nasty probem.
-o Several Makefile cleanups.
+GNU tar NEWS - User visible changes.
+Copyright � 1994, 1995, 1996, 1997 Free Software Foundation, Inc.
+
+Version 1.12 - Fran�ois Pinard, 1997-04.
+
+Sensitive matters
+* Use shell globbing patterns for --label, instead of regular expressions.
+* Do not quote anymore internally over the quoting done by the shell.
+
+Output for humans
+* Offer internationalisation capabilities of most recent GNU gettext.
+* Messages available in many more languages, thanks to all translators!
+* Usage of ISO 8601 dates in listings, instead of local American dates.
+* More normalisation and cleanup in error messages.
+
+Creation
+* For helping using tar with find, offer a --no-recursion option.
+* Implement --numeric-owner for ignoring symbolic names at create time.
+* New --owner, --group --mode options, still preliminary.
+* Recognise creating an archive on /dev/null, so Amanda works faster.
+* Object to the creation of an empty archive (like in `tar cf FILE').
+* Barely start implementing --posix and POSIXLY_CORRECT.
+
+Extraction
+* Make a better job at restoring file and directory attributes.
+* Automatically attempt deleting existing files when in the way.
+* Option --unlink-first (-U) removes most files prior to extraction.
+* Option --recursive-unlink removes non-empty directories when in the way.
+* Option --numeric-owner ignores owner/group names, it uses UID/GID instead.
+* Use global umask when creating missing intermediate directories.
+* When symlinks are not available, extract symbolic links as hard links.
+* Diagnose extraction of contiguous files as regular files.
+* New --backup, --suffix and --version-control options.
+
+Various changes
+* Better support of huge archives with --tape-length and --totals.
+* Rename option --read-full-blocks (-B) to --read-full-records (-B).
+* Rename option --block-size (-b) to --blocking-factor (-b).
+* Rename option --record-number (-R) to --block-number (-R).
+* With --block-number (-R), report null blocks and end of file.
+* Implement --record-size for introducing a size in bytes.
+* Delete --block-compress option and rather decide it automatically.
+* Rename option --modification-time to --touch.
+
+Many bugs are squashed, while others still run free.
+
+Version 1.11.8 - Fran�ois Pinard, 1995-06.
+
+* Messages available in French, German, Portuguese and Swedish.
+* The distribution provides a rudimentary Texinfo manual.
+* The device defaults to stdin/stdout, unless overridden by the installer.
+* Option --sparse (-S) should work on more systems.
+* Option --rsh-command may select an alternative remote shell program.
 
+Most changes are internal, and should yield better portability.
 
-==============
-Version 1.11.1
-User-visible changes since 1.11:
+Version 1.11.2 - Michael Bushnell, 1993-03.
+
+* Changes in backup scripts: cleaned up considerably; notices error
+conditions better over rsh; DUMP_REMIND_SCRIPT is now an option in
+backup-specs; new file dump-remind is an example of a
+DUMP_REMIND_SCRIPT.
+
+* Superfluous "Reading dirname" was a bug; fixed.
+
+* Incompatibility problems with a bug on Solaris are fixed.
+
+* New option --gzip (aliases are --ungzip and -z); calls gzip instead
+of compress.  Also, --use-compress-program lets you specify any
+compress program.  --compress-block is renamed --block-compress and
+now requires one of the three compression options to be specified.
+
+* Several error messages are cleaned up.
 
-o Many bug fixes
+* Directory owners are now set properly when running as root.
 
+* Provide DUMP_REMIND_SCRIPT in backup-specs as a possible option
+for --info-script.
+
+* Behave better with broken rmt servers.
+
+* Dump scripts no longer use --atime-preserve; this causes a nasty probem.
+
+* Several Makefile cleanups.
 
-============
-Version 1.11
-User-visible changes since 1.10:
+Version 1.11.1 - Michael Bushnell, 1992-09.
 
-o Many bug fixes
+* Many bug fixes.
+
+Version 1.11 - Michael Bushnell, 1992-09.
+Version 1.10.16 - 1992-07.
+Version 1.10.15 - 1992-06.
+Version 1.10.14 - 1992-05.
+Version 1.10.13 - 1992-01.
 
-o Now uses GNU standard configure, generated by Autoconf.
+* Many bug fixes.
 
-o Long options now use `--'; use of `+' is deprecated and support for it
-  will eventually be removed.
+* Now uses GNU standard configure, generated by Autoconf.
 
-o New option --null causes filenames read by -T to be null-terminated,
-  and causes -C to be ignored.
+* Long options now use `--'; use of `+' is deprecated and support
+for it will eventually be removed.
 
-o New option --remove-files deletes files (but not directories) after
-  they are added to the archive.
+* New option --null causes filenames read by -T to be
+null-terminated, and causes -C to be ignored.
 
-o New option --ignore-failed-read prevents read-errors from affecting
-  the exit status.
+* New option --remove-files deletes files (but not directories)
+after they are added to the archive.
 
-o New option --checkpoint prints occasional messages as the tape is
-  being read or written.
+* New option --ignore-failed-read prevents read-errors from affecting
+the exit status.
 
-o New option --show-omitted-dirs prints the names of directories
-  omitted from the archive.
+* New option --checkpoint prints occasional messages as the tape
+is being read or written.
 
-o Some tape drives which use a non-standard method of indicating
-  end-of-tape now work correctly with multi-tape archives.
+* New option --show-omitted-dirs prints the names of directories
+omitted from the archive.
 
-o --volno-file: Read the volume number used in prompting the user (but
-  not in recording volume ID's on the archive) from a file.
+* Some tape drives which use a non-standard method of indicating
+end-of-tape now work correctly with multi-tape archives.
 
-o When using --multi-volume, you can now give multiple -f arguments;
-  the various tape drives will get used in sequence and then wrap
-  around to the beginning.
+* --volno-file: Read the volume number used in prompting the user
+(but not in recording volume ID's on the archive) from a file.
 
-o Remote archive names no longer have to be in /dev: any file with a
-  `:' is interpreted as remote.  If new option --force-local is given,
-  then even archive files with a `:' are considered local.
+* When using --multi-volume, you can now give multiple -f arguments;
+the various tape drives will get used in sequence and then wrap
+around to the beginning.
 
-o New option --atime-preserve restores (if possible) atimes to their
-  original values after dumping the file.
+* Remote archive names no longer have to be in /dev: any file with a
+`:' is interpreted as remote.  If new option --force-local is given,
+then even archive files with a `:' are considered local.
 
-o No longer does tar confusingly dump "." when you don't tell it what
-  to dump.
+* New option --atime-preserve restores (if possible) atimes to
+their original values after dumping the file.
 
-o When extracting directories, tar now correctly restores their
-  modification and access times.
+* No longer does tar confusingly dump "." when you don't tell it
+what to dump.
 
-o Longnames support is redone differently--long name info directly
-  precedes the long-named file or link in the archive, so you no
-  longer have to wait for the extract to hit the end of the tape for
-  long names to work.
+* When extracting directories, tar now correctly restores their
+modification and access times.
 
+* Longnames support is redone differently--long name info directly
+precedes the long-named file or link in the archive, so you no
+longer have to wait for the extract to hit the end of the tape for
+long names to work.
 
-=============
-Version 1.10:
-User-visible changes since 1.09:
+Version 1.10 - Michael Bushnell, 1991-07.
+
+* Filename to -G is optional.  -C works right.  Names +newer and
 
-Filename to -G is optional.  -C works right.  
-Names +newer and +newer-mtime work right.
+* -g is now +incremental, -G is now +listed-incremental.
 
+* Sparse files now work correctly.
 
-Sparse files now work correctly.
+* +volume is now called +label.
 
-+volume is now called +label.
+* +exclude now takes a filename argument, and +exclude-from does
+what +exclude used to do.
 
-+exclude now takes a filename argument, and +exclude-from does what
-+exclude used to do.
+* Exit status is now correct.
 
-Exit status is now correct.
+* +totals keeps track of total I/O and prints it when tar exits.
 
-+totals keeps track of total I/O and prints it when tar exits.
+* When using +label with +extract, the label is now a regexp.
 
-When using +label with +extract, the label is now a regexp.
+* New option +tape-length (-L) does multi-volume handling like BSD
+dump: you tell tar how big the tape is and it will prompt at that
+point instead of waiting for a write error.
 
-New option +tape-length (-L) does multi-volume handling like BSD dump:
-you tell tar how big the tape is and it will prompt at that point
-instead of waiting for a write error.
+* New backup scripts level-0 and level-1 which might be useful
+to people.  They use a file "backup-specs" for information, and
+shouldn't need local modification.  These are what we use to do
+all our backups at the FSF.
+
+Version 1.09 - Jay Fenlason, 1990-10.
+Version 1.08 - Jay Fenlason, 1990-01.
+Versions 1.07 back to 1.00 by Jay Fenlason.
 
-New backup scripts level-0 and level-1 which might be useful to
-people.  They use a file "backup-specs" for information, and shouldn't
-need local modification.  These are what we use to do all our backups
-at the FSF.
+* See ChangeLog for more details.
