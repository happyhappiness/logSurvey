   IGNORE_FAILED_READ_OPTION,
   INDEX_FILE_OPTION,
   KEEP_NEWER_FILES_OPTION,
+  LICENSE_OPTION,
   MODE_OPTION,
   NEWER_MTIME_OPTION,
   NO_ANCHORED_OPTION,
   NO_IGNORE_CASE_OPTION,
   NO_OVERWRITE_DIR_OPTION,
+  NO_RECURSION_OPTION,
+  NO_SAME_OWNER_OPTION,
+  NO_SAME_PERMISSIONS_OPTION,
   NO_WILDCARDS_OPTION,
   NO_WILDCARDS_MATCH_SLASH_OPTION,
   NULL_OPTION,
   NUMERIC_OWNER_OPTION,
   OCCURRENCE_OPTION,
+  OLD_ARCHIVE_OPTION,
   OVERWRITE_OPTION,
   OWNER_OPTION,
   PAX_OPTION,
   POSIX_OPTION,
   PRESERVE_OPTION,
   RECORD_SIZE_OPTION,
+  RECURSION_OPTION,
   RECURSIVE_UNLINK_OPTION,
   REMOVE_FILES_OPTION,
   RMT_COMMAND_OPTION,
   RSH_COMMAND_OPTION,
+  SAME_OWNER_OPTION,
   SHOW_DEFAULTS_OPTION,
   SHOW_OMITTED_DIRS_OPTION,
   STRIP_COMPONENTS_OPTION,
   SUFFIX_OPTION,
   TOTALS_OPTION,
+  USAGE_OPTION,
   USE_COMPRESS_PROGRAM_OPTION,
   UTC_OPTION,
+  VERSION_OPTION,
   VOLNO_FILE_OPTION,
   WILDCARDS_OPTION,
   WILDCARDS_MATCH_SLASH_OPTION
 };
 
-/* If nonzero, display usage information and exit.  */
-static int show_help;
-
-/* If nonzero, print the version on standard output and exit.  */
-static int show_version;
-
-static struct option long_options[] =
-{
-  {"absolute-names", no_argument, 0, 'P'},
-  {"after-date", required_argument, 0, 'N'},
-  {"anchored", no_argument, 0, ANCHORED_OPTION},
-  {"append", no_argument, 0, 'r'},
-  {"atime-preserve", no_argument, 0, ATIME_PRESERVE_OPTION},
-  {"backup", optional_argument, 0, BACKUP_OPTION},
-  {"block-number", no_argument, 0, 'R'},
-  {"blocking-factor", required_argument, 0, 'b'},
-  {"bzip2", no_argument, 0, 'j'},
-  {"catenate", no_argument, 0, 'A'},
-  {"checkpoint", no_argument, 0, CHECKPOINT_OPTION},
-  {"check-links", no_argument, &check_links_option, 1},
-  {"compare", no_argument, 0, 'd'},
-  {"compress", no_argument, 0, 'Z'},
-  {"concatenate", no_argument, 0, 'A'},
-  {"confirmation", no_argument, 0, 'w'},
-  /* FIXME: --selective as a synonym for --confirmation?  */
-  {"create", no_argument, 0, 'c'},
-  {"delete", no_argument, 0, DELETE_OPTION},
-  {"dereference", no_argument, 0, 'h'},
-  {"diff", no_argument, 0, 'd'},
-  {"directory", required_argument, 0, 'C'},
-  {"exclude", required_argument, 0, EXCLUDE_OPTION},
-  {"exclude-from", required_argument, 0, 'X'},
-  {"extract", no_argument, 0, 'x'},
-  {"file", required_argument, 0, 'f'},
-  {"files-from", required_argument, 0, 'T'},
-  {"force-local", no_argument, 0, FORCE_LOCAL_OPTION},
-  {"format", required_argument, 0, FORMAT_OPTION},
-  {"get", no_argument, 0, 'x'},
-  {"group", required_argument, 0, GROUP_OPTION},
-  {"gunzip", no_argument, 0, 'z'},
-  {"gzip", no_argument, 0, 'z'},
-  {"help", no_argument, &show_help, 1},
-  {"ignore-case", no_argument, 0, IGNORE_CASE_OPTION},
-  {"ignore-failed-read", no_argument, 0, IGNORE_FAILED_READ_OPTION},
-  {"ignore-zeros", no_argument, 0, 'i'},
-  /* FIXME: --ignore-end as a new name for --ignore-zeros?  */
-  {"incremental", no_argument, 0, 'G'},
-  {"index-file", required_argument, 0, INDEX_FILE_OPTION},
-  {"info-script", required_argument, 0, 'F'},
-  {"interactive", no_argument, 0, 'w'},
-  {"keep-newer-files", no_argument, 0, KEEP_NEWER_FILES_OPTION},
-  {"keep-old-files", no_argument, 0, 'k'},
-  {"label", required_argument, 0, 'V'},
-  {"list", no_argument, 0, 't'},
-  {"listed-incremental", required_argument, 0, 'g'},
-  {"mode", required_argument, 0, MODE_OPTION},
-  {"multi-volume", no_argument, 0, 'M'},
-  {"new-volume-script", required_argument, 0, 'F'},
-  {"newer", required_argument, 0, 'N'},
-  {"newer-mtime", required_argument, 0, NEWER_MTIME_OPTION},
-  {"null", no_argument, 0, NULL_OPTION},
-  {"no-anchored", no_argument, 0, NO_ANCHORED_OPTION},
-  {"no-ignore-case", no_argument, 0, NO_IGNORE_CASE_OPTION},
-  {"no-overwrite-dir", no_argument, 0, NO_OVERWRITE_DIR_OPTION},
-  {"no-wildcards", no_argument, 0, NO_WILDCARDS_OPTION},
-  {"no-wildcards-match-slash", no_argument, 0, NO_WILDCARDS_MATCH_SLASH_OPTION},
-  {"no-recursion", no_argument, &recursion_option, 0},
-  {"no-same-owner", no_argument, &same_owner_option, -1},
-  {"no-same-permissions", no_argument, &same_permissions_option, -1},
-  {"numeric-owner", no_argument, 0, NUMERIC_OWNER_OPTION},
-  {"occurrence", optional_argument, 0, OCCURRENCE_OPTION},
-  {"old-archive", no_argument, 0, 'o'},
-  {"one-file-system", no_argument, 0, 'l'},
-  {"overwrite", no_argument, 0, OVERWRITE_OPTION},
-  {"owner", required_argument, 0, OWNER_OPTION},
-  {"pax-option", required_argument, 0, PAX_OPTION},
-  {"portability", no_argument, 0, 'o'},
-  {"posix", no_argument, 0, POSIX_OPTION},
-  {"preserve", no_argument, 0, PRESERVE_OPTION},
-  {"preserve-order", no_argument, 0, 's'},
-  {"preserve-permissions", no_argument, 0, 'p'},
-  {"recursion", no_argument, &recursion_option, FNM_LEADING_DIR},
-  {"recursive-unlink", no_argument, 0, RECURSIVE_UNLINK_OPTION},
-  {"read-full-records", no_argument, 0, 'B'},
-  /* FIXME: --partial-blocks might be a synonym for --read-full-records?  */
-  {"record-size", required_argument, 0, RECORD_SIZE_OPTION},
-  {"remove-files", no_argument, 0, REMOVE_FILES_OPTION},
-  {"rmt-command", required_argument, 0, RMT_COMMAND_OPTION},
-  {"rsh-command", required_argument, 0, RSH_COMMAND_OPTION},
-  {"same-order", no_argument, 0, 's'},
-  {"same-owner", no_argument, &same_owner_option, 1},
-  {"same-permissions", no_argument, 0, 'p'},
-  {"show-defaults", no_argument, 0, SHOW_DEFAULTS_OPTION},
-  {"show-omitted-dirs", no_argument, 0, SHOW_OMITTED_DIRS_OPTION},
-  {"sparse", no_argument, 0, 'S'},
-  {"starting-file", required_argument, 0, 'K'},
-  {"strip-components", required_argument, 0, STRIP_COMPONENTS_OPTION },
-  {"suffix", required_argument, 0, SUFFIX_OPTION},
-  {"tape-length", required_argument, 0, 'L'},
-  {"to-stdout", no_argument, 0, 'O'},
-  {"totals", no_argument, 0, TOTALS_OPTION},
-  {"touch", no_argument, 0, 'm'},
-  {"uncompress", no_argument, 0, 'Z'},
-  {"ungzip", no_argument, 0, 'z'},
-  {"unlink-first", no_argument, 0, 'U'},
-  {"update", no_argument, 0, 'u'},
-  {"utc", no_argument, 0, UTC_OPTION },
-  {"use-compress-program", required_argument, 0, USE_COMPRESS_PROGRAM_OPTION},
-  {"verbose", no_argument, 0, 'v'},
-  {"verify", no_argument, 0, 'W'},
-  {"version", no_argument, &show_version, 1},
-  {"volno-file", required_argument, 0, VOLNO_FILE_OPTION},
-  {"wildcards", no_argument, 0, WILDCARDS_OPTION},
-  {"wildcards-match-slash", no_argument, 0, WILDCARDS_MATCH_SLASH_OPTION},
-
-  {0, 0, 0, 0}
-};
-
-/* Print a usage message and exit with STATUS.  */
-void
-usage (int status)
-{
-  if (status != TAREXIT_SUCCESS)
-    fprintf (stderr, _("Try `%s --help' for more information.\n"),
-	     program_name);
-  else
-    {
-      fputs (_("\
-GNU `tar' saves many files together into a single tape or disk archive, and\n\
-can restore individual files from the archive.\n"),
-	     stdout);
-      printf (_("\nUsage: %s [OPTION]... [FILE]...\n\
+const char *argp_program_version = "tar (" PACKAGE ") " VERSION;
+const char *argp_program_bug_address = "<" PACKAGE_BUGREPORT ">";
+static char doc[] = N_("GNU `tar' saves many files together into a single tape or disk archive, and can restore individual files from the archive.\n\
 \n\
 Examples:\n\
-  %s -cf archive.tar foo bar  # Create archive.tar from files foo and bar.\n\
-  %s -tvf archive.tar         # List all files in archive.tar verbosely.\n\
-  %s -xf archive.tar          # Extract all files from archive.tar.\n"),
-	     program_name, program_name, program_name, program_name);
-      fputs (_("\
-\n\
-If a long option shows an argument as mandatory, then it is mandatory\n\
-for the equivalent short option also.  Similarly for optional arguments.\n"),
-	     stdout);
-      fputs(_("\
-\n\
-Main operation mode:\n\
-  -t, --list              list the contents of an archive\n\
-  -x, --extract, --get    extract files from an archive\n\
-  -c, --create            create a new archive\n\
-  -d, --diff, --compare   find differences between archive and file system\n\
-  -r, --append            append files to the end of an archive\n\
-  -u, --update            only append files newer than copy in archive\n\
-  -A, --catenate          append tar files to an archive\n\
-      --concatenate       same as -A\n\
-      --delete            delete from the archive (not on mag tapes!)\n"),
-	    stdout);
-      fputs (_("\
-\n\
-Operation modifiers:\n\
-  -W, --verify               attempt to verify the archive after writing it\n\
-      --remove-files         remove files after adding them to the archive\n\
-  -k, --keep-old-files       don't replace existing files when extracting\n\
-      --keep-newer-files     don't replace existing files that are newer\n\
-                             than their archive copies\n\
-      --overwrite            overwrite existing files when extracting\n\
-      --no-overwrite-dir     preserve metadata of existing directories\n\
-  -U, --unlink-first         remove each file prior to extracting over it\n\
-      --recursive-unlink     empty hierarchies prior to extracting directory\n\
-  -S, --sparse               handle sparse files efficiently\n\
-  -O, --to-stdout            extract files to standard output\n\
-  -G, --incremental          handle old GNU-format incremental backup\n\
-  -g, --listed-incremental=FILE\n\
-                             handle new GNU-format incremental backup\n\
-      --ignore-failed-read   do not exit with nonzero on unreadable files\n\
-      --occurrence[=NUM]     process only the NUMth occurrence of each file in\n\
-                             the archive. This option is valid only in\n\
-                             conjunction with one of the subcommands --delete,\n\
-                             --diff, --extract or --list and when a list of\n\
-                             files is given either on the command line or\n\
-                             via -T option.\n\
-                             NUM defaults to 1.\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Handling of file attributes:\n\
-      --owner=NAME             force NAME as owner for added files\n\
-      --group=NAME             force NAME as group for added files\n\
-      --mode=CHANGES           force (symbolic) mode CHANGES for added files\n\
-      --atime-preserve         don't change access times on dumped files\n\
-  -m, --modification-time      don't extract file modified time\n\
-      --same-owner             try extracting files with the same ownership\n\
-      --no-same-owner          extract files as yourself\n\
-      --numeric-owner          always use numbers for user/group names\n\
-  -p, --same-permissions       extract permissions information\n\
-      --no-same-permissions    do not extract permissions information\n\
-      --preserve-permissions   same as -p\n\
-  -s, --same-order             sort names to extract to match archive\n\
-      --preserve-order         same as -s\n\
-      --preserve               same as both -p and -s\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Device selection and switching:\n\
-  -f, --file=ARCHIVE             use archive file or device ARCHIVE\n\
-      --force-local              archive file is local even if has a colon\n\
-      --rmt-command=COMMAND      use given rmt COMMAND instead of /etc/rmt\n\
-      --rsh-command=COMMAND      use remote COMMAND instead of rsh\n\
-  -[0-7][lmh]                    specify drive and density\n\
-  -M, --multi-volume             create/list/extract multi-volume archive\n\
-  -L, --tape-length=NUM          change tape after writing NUM x 1024 bytes\n\
-  -F, --info-script=FILE         run script at end of each tape (implies -M)\n\
-      --new-volume-script=FILE   same as -F FILE\n\
-      --volno-file=FILE          use/update the volume number in FILE\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Device blocking:\n\
-  -b, --blocking-factor=BLOCKS   BLOCKS x 512 bytes per record\n\
-      --record-size=SIZE         SIZE bytes per record, multiple of 512\n\
-  -i, --ignore-zeros             ignore zeroed blocks in archive (means EOF)\n\
-  -B, --read-full-records        reblock as we read (for 4.2BSD pipes)\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Archive format selection:\n\
-      --format=FMTNAME               create archive of the given format.\n\
-                                     FMTNAME is one of the following:\n\
-                                     v7        old V7 tar format\n\
-                                     oldgnu    GNU format as per tar <= 1.12\n\
-                                     gnu       GNU tar 1.13 format\n\
-                                     ustar     POSIX 1003.1-1988 (ustar) format\n\
-                                     posix     POSIX 1003.1-2001 (pax) format\n\
-      --old-archive, --portability   same as --format=v7\n\
-      --posix                        same as --format=posix\n\
-  --pax-option keyword[[:]=value][,keyword[[:]=value], ...]\n\
-                                     control pax keywords\n\
-  -V, --label=NAME                   create archive with volume name NAME\n\
-              PATTERN                at list/extract time, a globbing PATTERN\n\
-  -j, --bzip2                        filter the archive through bzip2\n\
-  -z, --gzip, --ungzip               filter the archive through gzip\n\
-  -Z, --compress, --uncompress       filter the archive through compress\n\
-      --use-compress-program=PROG    filter through PROG (must accept -d)\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Local file selection:\n\
-  -C, --directory=DIR          change to directory DIR\n\
-  -T, --files-from=NAME        get names to extract or create from file NAME\n\
-      --null                   -T reads null-terminated names, disable -C\n\
-      --exclude=PATTERN        exclude files, given as a PATTERN\n\
-  -X, --exclude-from=FILE      exclude patterns listed in FILE\n\
-      --anchored               exclude patterns match file name start (default)\n\
-      --no-anchored            exclude patterns match after any /\n\
-      --ignore-case            exclusion ignores case\n\
-      --no-ignore-case         exclusion is case sensitive (default)\n\
-      --wildcards              exclude patterns use wildcards (default)\n\
-      --no-wildcards           exclude patterns are plain strings\n\
-      --wildcards-match-slash  exclude pattern wildcards match '/' (default)\n\
-      --no-wildcards-match-slash exclude pattern wildcards do not match '/'\n\
-  -P, --absolute-names         don't strip leading `/'s from file names\n\
-  -h, --dereference            dump instead the files symlinks point to\n\
-      --no-recursion           avoid descending automatically in directories\n\
-  -l, --one-file-system        stay in local file system when creating archive\n\
-  -K, --starting-file=NAME     begin at file NAME in the archive\n\
-      --strip-components=NUM   strip NUM leading components from file names\n\
-                               before extraction\n"),
-	     stdout);
-#if !MSDOS
-      fputs (_("\
-  -N, --newer=DATE-OR-FILE     only store files newer than DATE-OR-FILE\n\
-      --newer-mtime=DATE       compare date and time when data changed only\n\
-      --after-date=DATE        same as -N\n"),
-	     stdout);
-#endif
-      fputs (_("\
-      --backup[=CONTROL]       backup before removal, choose version control\n\
-      --suffix=SUFFIX          backup before removal, override usual suffix\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Informative output:\n\
-      --help            print this help, then exit\n\
-      --version         print tar program version number, then exit\n\
-  -v, --verbose         verbosely list files processed\n\
-      --checkpoint      print directory names while reading the archive\n\
-      --check-links     print a message if not all links are dumped\n\
-      --totals          print total bytes written while creating archive\n\
-      --index-file=FILE send verbose output to FILE\n\
-      --utc             print file modification dates in UTC\n\
-  -R, --block-number    show block number within archive with each message\n\
-  -w, --interactive     ask for confirmation for every action\n\
-      --confirmation    same as -w\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Compatibility options:\n\
-  -o                                 when creating, same as --old-archive\n\
-                                     when extracting, same as --no-same-owner\n"),
-             stdout);
-
-      fputs (_("\
-\n\
-The backup suffix is `~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.\n\
-The version control may be set with --backup or VERSION_CONTROL, values are:\n\
-\n\
+  tar -cf archive.tar foo bar  # Create archive.tar from files foo and bar.\n\
+  tar -tvf archive.tar         # List all files in archive.tar verbosely.\n\
+  tar -xf archive.tar          # Extract all files from archive.tar.\n\
+\vThe backup suffix is `~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.\n\
+The version control may be set with --backup or VERSION_CONTROL, values are:\n\n\
   t, numbered     make numbered backups\n\
   nil, existing   numbered if numbered backups exist, simple otherwise\n\
-  never, simple   always make simple backups\n"),
-	     stdout);
-      printf (_("\
-\n\
-ARCHIVE may be FILE, HOST:FILE or USER@HOST:FILE; DATE may be a textual date\n\
-or a file name starting with `/' or `.', in which case the file's date is used.\n\
-*This* `tar' defaults to `--format=%s -f%s -b%d'.\n"),
-	      archive_format_string (DEFAULT_ARCHIVE_FORMAT),
-	      DEFAULT_ARCHIVE, DEFAULT_BLOCKING);
-      printf (_("\nReport bugs to <%s>.\n"), PACKAGE_BUGREPORT);
-    }
-  exit (status);
-}
+  never, simple   always make simple backups\n");
 
-/* Parse the options for tar.  */
 
-/* Available option letters are DEHIJQY and aenqy.  Some are reserved:
+static struct argp_option options[] = {
+  {NULL, 0, NULL, 0,
+   N_("Main operation mode:"), 0},
+  
+  {"list", 't', 0, 0,
+   N_("list the contents of an archive"), 10 },
+  {"extract", 'x', 0, 0,
+   N_("extract files from an archive"), 10 },
+  {"get", 0, 0, OPTION_ALIAS, NULL},
+  {"create", 'c', 0, 0,
+   N_("create a new archive"), 10 },
+  {"diff", 'd', 0, 0,
+   N_("find differences between archive and file system"), 10 },
+  {"compare", 0, 0, OPTION_ALIAS, NULL, 10},
+  {"append", 'r', 0, 0,
+   N_("append files to the end of an archive"), 10 },
+  {"update", 'u', 0, 0,
+   N_("only append files newer than copy in archive"), 10 },
+  {"catenate", 'A', 0, 0,
+   N_("append tar files to an archive"), 10 },
+  {"concatenate", 0, 0, OPTION_ALIAS, NULL, 10},
+  {"delete", DELETE_OPTION, 0, 0,
+   N_("delete from the archive (not on mag tapes!)"), 10 },
+
+  {NULL, 0, NULL, 0,
+   N_("Operation modifiers:"), 20},
+
+  {"verify", 'W', 0, 0,
+   N_("attempt to verify the archive after writing it"), 21 },
+  {"remove-files", REMOVE_FILES_OPTION, 0, 0,
+   N_("remove files after adding them to the archive"), 21 },
+  {"keep-old-files", 'k', 0, 0,
+   N_("don't replace existing files when extracting"), 21 },
+  {"keep-newer-files", KEEP_NEWER_FILES_OPTION, 0, 0,
+   N_("don't replace existing files that are newer than their archive copies"), 21 },
+  {"no-overwrite-dir", NO_OVERWRITE_DIR_OPTION, 0, 0,
+   N_("preserve metadata of existing directories"), 21 },
+  {"overwrite", OVERWRITE_OPTION, 0, 0,
+   N_("overwrite existing files when extracting"), 21 },
+  {"unlink-first", 'U', 0, 0,
+   N_("remove each file prior to extracting over it"), 21 },
+  {"recursive-unlink", RECURSIVE_UNLINK_OPTION, 0, 0,
+   N_("empty hierarchies prior to extracting directory"), 21 },
+  {"sparse", 'S', 0, 0,
+   N_("handle sparse files efficiently"), 21 },
+  {"to-stdout", 'O', 0, 0,
+   N_("extract files to standard output"), 21 },
+  {"incremental", 'G', 0, 0,
+   N_("handle old GNU-format incremental backup"), 21 },
+  {"listed-incremental", 'g', N_("FILE"), 0,
+   N_("handle new GNU-format incremental backup"), 21 },
+  {"ignore-failed-read", IGNORE_FAILED_READ_OPTION, 0, 0,
+   N_("do not exit with nonzero on unreadable files"), 21 },
+  {"occurrence", OCCURRENCE_OPTION, N_("NUMBER"), OPTION_ARG_OPTIONAL,
+   N_("process only the NUMth occurrence of each file in the archive. This option is valid only in conjunction with one of the subcommands --delete, --diff, --extract or --list and when a list of files is given either on the command line or via -T option. NUMBER defaults to 1."), 21 },
+
+  {NULL, 0, NULL, 0,
+   N_("Handling of file attributes:"), 30 },
+
+  {"owner", OWNER_OPTION, N_("NAME"), 0,
+   N_("force NAME as owner for added files"), 31 },
+  {"group", GROUP_OPTION, N_("NAME"), 0,
+   N_("force NAME as group for added files"), 31 },
+  {"mode", MODE_OPTION, N_("CHANGES"), 0,
+   N_("force (symbolic) mode CHANGES for added files"), 31 },
+  {"atime-preserve", ATIME_PRESERVE_OPTION, 0, 0,
+   N_("don't change access times on dumped files"), 31 },
+  {"touch", 'm', 0, 0,
+   N_("don't extract file modified time"), 31 },
+  {"same-owner", SAME_OWNER_OPTION, 0, 0,
+   N_("try extracting files with the same ownership"), 31 },
+  {"no-same-owner", NO_SAME_OWNER_OPTION, 0, 0,
+   N_("extract files as yourself"), 31 },
+  {"numeric-owner", NUMERIC_OWNER_OPTION, 0, 0,
+   N_("always use numbers for user/group names"), 31 },
+  {"preserve-permissions", 'p', 0, 0,
+   N_("extract permissions information"), 31 },
+  {"same-permissions", 0, 0, OPTION_ALIAS, NULL, 31 },
+  {"no-same-permissions", NO_SAME_PERMISSIONS_OPTION, 0, 0,
+   N_("do not extract permissions information"), 31 },
+  {"preserve-order", 's', 0, 0,
+   N_("sort names to extract to match archive"), 31 },
+  {"same-order", 0, 0, OPTION_ALIAS, NULL, 31 },
+  {"preserve", PRESERVE_OPTION, 0, 0,
+   N_("same as both -p and -s"), 31 },
+
+  {NULL, 0, NULL, 0,
+   N_("Device selection and switching:"), 40 },
+  
+  {"file", 'f', N_("ARCHIVE"), 0,
+   N_("use archive file or device ARCHIVE"), 41 },
+  {"force-local", FORCE_LOCAL_OPTION, 0, 0,
+   N_("archive file is local even if has a colon"), 41 },
+  {"rmt-command", RMT_COMMAND_OPTION, N_("COMMAND"), 0,
+   N_("use given rmt COMMAND instead of rmt"), 41 }, 
+  {"rsh-command", RSH_COMMAND_OPTION, N_("COMMAND"), 0,
+   N_("use remote COMMAND instead of rsh"), 41 },
+#ifdef DEVICE_PREFIX
+  {"-[0-7][lmh]", 0, NULL, OPTION_DOC,
+   N_("specify drive and density"), 41 },
+#endif  
+  {NULL, '0', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '1', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '2', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '3', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '4', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '5', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '6', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '7', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '8', NULL, OPTION_HIDDEN, NULL, 41 },
+  {NULL, '9', NULL, OPTION_HIDDEN, NULL, 41 },
+  
+  {"multi-volume", 'M', 0, 0,
+   N_("create/list/extract multi-volume archive"), 41 },
+  {"tape-length", 'L', N_("NUMBER"), 0,
+   N_("change tape after writing NUMBER x 1024 bytes"), 41 },
+  {"info-script", 'F', N_("NAME"), 0,
+   N_("run script at end of each tape (implies -M)"), 41 },
+  {"new-volume-script", 0, 0, OPTION_ALIAS, NULL, 41 },
+  {"volno-file", VOLNO_FILE_OPTION, N_("FILE"), 0,
+   N_("use/update the volume number in FILE"), 41 },
+
+  {NULL, 0, NULL, 0,
+   N_("Device blocking:"), 50 },
+
+  {"blocking-factor", 'b', N_("BLOCKS"), 0,
+   N_("BLOCKS x 512 bytes per record"), 51 },
+  {"record-size", RECORD_SIZE_OPTION, N_("NUMBER"), 0,
+   N_("SIZE bytes per record, multiple of 512"), 51 },
+  {"ignore-zeros", 'i', 0, 0,
+   N_("ignore zeroed blocks in archive (means EOF)"), 51 },
+  {"read-full-records", 'B', 0, 0,
+   N_("reblock as we read (for 4.2BSD pipes)"), 51 }, 
+
+  {NULL, 0, NULL, 0,
+   N_("Archive format selection:"), 60 },
+  
+  {"format", FORMAT_OPTION, N_("FORMAT"), 0,
+   N_("create archive of the given format."), 61 },
+
+  {"", 0, NULL, OPTION_DOC, N_("FORMAT is one of the following:"), 62},
+  {"", 0, NULL, OPTION_DOC, N_("v7        old V7 tar format"), 63},
+  {"", 0, NULL, OPTION_DOC, N_("oldgnu    GNU format as per tar <= 1.12"), 63},
+  {"", 0, NULL, OPTION_DOC, N_("gnu       GNU tar 1.13.x format"), 63},
+  {"", 0, NULL, OPTION_DOC, N_("ustar     POSIX 1003.1-1988 (ustar) format"), 63 },
+  {"", 0, NULL, OPTION_DOC, N_("posix     POSIX 1003.1-2001 (pax) format"), 63 },
+
+  {"old-archive", OLD_ARCHIVE_OPTION, 0, 0, /* FIXME */
+   N_("same as --format=v7"), 68 },
+  {"portability", 0, 0, OPTION_ALIAS, NULL, 68 },
+  {"posix", POSIX_OPTION, 0, 0,
+   N_("same as --format=posix"), 68 },
+  {"pax-option", PAX_OPTION, N_("keyword[[:]=value][,keyword[[:]=value], ...]"), 0,
+   N_("control pax keywords"), 68 },
+  {"label", 'V', N_("TEXT"), 0,
+   N_("create archive with volume name NAME. At list/extract time, use TEXT as a globbing pattern"), 68 },
+  {"bzip2", 'j', 0, 0,
+   N_("filter the archive through bzip2"), 68 },
+  {"gzip", 'z', 0, 0,
+   N_("filter the archive through gzip"), 68 },
+  {"gunzip", 0, 0, OPTION_ALIAS, NULL, 68 },
+  {"ungzip", 0, 0, OPTION_ALIAS, NULL, 68 },
+  {"compress", 'Z', 0, 0,
+   N_("filter the archive through compress"), 68 },
+  {"uncompress", 0, 0, OPTION_ALIAS, NULL, 68 },
+  {"use-compress-program", USE_COMPRESS_PROGRAM_OPTION, N_("PROG"), 0,
+   N_("filter through PROG (must accept -d)"), 68 },
+
+  {NULL, 0, NULL, 0,
+   N_("Local file selection:"), 70 },
+
+  {"directory", 'C', N_("DIR"), 0,
+   N_("change to directory DIR"), 71 },
+  {"files-from", 'T', N_("FILE-OF-NAMES"), 0,
+   N_("get names to extract or create from file NAME"), 71 },
+  {"null", NULL_OPTION, 0, 0,
+   N_("-T reads null-terminated names, disable -C"), 71 },
+  {"exclude", EXCLUDE_OPTION, N_("PATTERN"), 0,
+   N_("exclude files, given as a PATTERN"), 71 },
+  {"exclude-from", 'X', N_("FILE"), 0,
+   N_("exclude patterns listed in FILE"), 71 },
+  {"ignore-case", IGNORE_CASE_OPTION, 0, 0,
+   N_("exclusion ignores case"), 71 },
+  {"anchored", ANCHORED_OPTION, 0, 0,
+   N_("exclude patterns match file name start (default)"), 71 },
+  {"no-anchored", NO_ANCHORED_OPTION, 0, 0,
+   N_("exclude patterns match after any /"), 71 },
+  {"no-ignore-case", NO_IGNORE_CASE_OPTION, 0, 0,
+   N_("exclusion is case sensitive (default)"), 71 },
+  {"no-wildcards", NO_WILDCARDS_OPTION, 0, 0,
+   N_("exclude patterns are plain strings"), 71 },
+  {"no-wildcards-match-slash", NO_WILDCARDS_MATCH_SLASH_OPTION, 0, 0,
+   N_("exclude pattern wildcards do not match '/'"), 71 },
+  {"no-recursion", NO_RECURSION_OPTION, 0, 0,
+   N_("avoid descending automatically in directories"), 71 },
+  {"one-file-system", 'l', 0, 0, /* FIXME: emit warning */
+   N_("stay in local file system when creating archive"), 71 },
+  {"recursion", RECURSION_OPTION, 0, 0,
+   N_("recurse into directories (default)"), 71 },
+  {"absolute-names", 'P', 0, 0,
+   N_("don't strip leading `/'s from file names"), 71 },
+  {"dereference", 'h', 0, 0,
+   N_("dump instead the files symlinks point to"), 71 },
+  {"starting-file", 'K', N_("MEMBER-NAME"), 0,
+   N_("begin at member MEMBER-NAME in the archive"), 71 },
+  {"strip-components", STRIP_COMPONENTS_OPTION, N_("NUMBER"), 0,
+   N_("strip NUMBER leading components from file names"), 71 },
+  {"newer", 'N', N_("DATE-OR-FILE"), 0,
+   N_("only store files newer than DATE-OR-FILE"), 71 },
+  {"newer-mtime", NEWER_MTIME_OPTION, N_("DATE"), 0,
+   N_("compare date and time when data changed only"), 71 },
+  {"after-date", 'N', N_("DATE"), 0,
+   N_("same as -N"), 71 },
+  {"backup", BACKUP_OPTION, N_("CONTROL"), OPTION_ARG_OPTIONAL,
+   N_("backup before removal, choose version CONTROL"), 71 },
+  {"suffix", SUFFIX_OPTION, N_("STRING"), 0,
+   N_("backup before removal, override usual suffix ('~' unless overridden by environment variable SIMPLE_BACKUP_SUFFIX"), 71 },
+  {"wildcards", WILDCARDS_OPTION, 0, 0,
+   N_("exclude patterns use wildcards (default)"), 71 },
+  {"wildcards-match-slash", WILDCARDS_MATCH_SLASH_OPTION, 0, 0,
+   N_("exclude pattern wildcards match '/' (default)"), 71 },
+
+  {NULL, 0, NULL, 0,
+   N_("Informative output:"), 80 },
+  
+  {"verbose", 'v', 0, 0,
+   N_("verbosely list files processed"), 81 },
+  {"checkpoint", CHECKPOINT_OPTION, 0, 0,
+   N_("print directory names while reading the archive"), 81 },
+  {"check-links", CHECK_LINKS_OPTION, 0, 0,
+   N_("print a message if not all links are dumped"), 82 },
+  {"totals", TOTALS_OPTION, 0, 0,
+   N_("print total bytes written while creating archive"), 82 },
+  {"utc", UTC_OPTION, 0, 0,
+   N_("print file modification dates in UTC"), 82 },
+  {"index-file", INDEX_FILE_OPTION, N_("FILE"), 0,
+   N_("send verbose output to FILE"), 82 },
+  {"block-number", 'R', 0, 0,
+   N_("show block number within archive with each message"), 82 },
+  {"interactive", 'w', 0, 0,
+   N_("ask for confirmation for every action"), 82 },
+  {"confirmation", 0, 0, OPTION_ALIAS, NULL, 82 },
+  {"show-defaults", SHOW_DEFAULTS_OPTION, 0, 0,
+   N_("Show tar defaults"), 82 },
+  {"show-omitted-dirs", SHOW_OMITTED_DIRS_OPTION, 0, 0,
+   N_("When listing or extracting, list each directory that does not match search criteria"), 82 },
+  
+  {NULL, 0, NULL, 0,
+   N_("Compatibility options:"), 90 },
 
-   e  exit immediately with a nonzero exit status if unexpected errors occur
-   E  use extended headers (draft POSIX headers, that is)
-   I  same as T (for compatibility with Solaris tar)
-   n  the archive is quickly seekable, so don't worry about random seeks
-   q  stop after extracting the first occurrence of the named file
-   y  per-file gzip compression
-   Y  per-block gzip compression */
+  {NULL, 'o', 0, 0,
+   N_("when creating, same as --old-archive. When extracting, same as --no-same-owner"), 91 },
+
+  {NULL, 0, NULL, 0,
+   N_("Other options:"), 100 },
 
-#define OPTION_STRING \
-  "-01234567ABC:F:GIK:L:MN:OPRST:UV:WX:Zb:cdf:g:hijklmoprstuvwxyz"
+  {"help",  '?', 0, 0,  N_("Give this help list"), -1},
+  {"usage", USAGE_OPTION, 0, 0,  N_("Give a short usage message"), -1},
+  {"license", LICENSE_OPTION, 0, 0, N_("Print license and exit"), -1},
+  {"version", VERSION_OPTION, 0, 0,  N_("Print program version"), -1},
+  /* FIXME -V (--label) conflicts with the default short option for
+     --version */
+  
+  {0, 0, 0, 0}
+};
+
+struct tar_args {
+  char const *textual_date_option;
+  int exclude_options;
+  bool o_option;
+  int pax_option;
+  char const *backup_suffix_string;
+  char const *version_control_string;
+  int input_files;
+};
+
+static void
+show_default_settings (FILE *stream)
+{
+  fprintf (stream,
+	   "--format=%s -f%s -b%d --rmt-command=%s --rsh-command=%s\n",
+	   archive_format_string (DEFAULT_ARCHIVE_FORMAT),
+	   DEFAULT_ARCHIVE, DEFAULT_BLOCKING,
+	   DEFAULT_RMT_COMMAND, REMOTE_SHELL);
+}
 
 static void
 set_subcommand_option (enum subcommand subcommand)
