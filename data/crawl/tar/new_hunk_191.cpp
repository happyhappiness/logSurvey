  IGNORE_FAILED_READ_OPTION,
  INDEX_FILE_OPTION,
  KEEP_NEWER_FILES_OPTION,
  LICENSE_OPTION,
  MODE_OPTION,
  NEWER_MTIME_OPTION,
  NO_ANCHORED_OPTION,
  NO_IGNORE_CASE_OPTION,
  NO_OVERWRITE_DIR_OPTION,
  NO_RECURSION_OPTION,
  NO_SAME_OWNER_OPTION,
  NO_SAME_PERMISSIONS_OPTION,
  NO_WILDCARDS_OPTION,
  NO_WILDCARDS_MATCH_SLASH_OPTION,
  NULL_OPTION,
  NUMERIC_OWNER_OPTION,
  OCCURRENCE_OPTION,
  OLD_ARCHIVE_OPTION,
  OVERWRITE_OPTION,
  OWNER_OPTION,
  PAX_OPTION,
  POSIX_OPTION,
  PRESERVE_OPTION,
  RECORD_SIZE_OPTION,
  RECURSION_OPTION,
  RECURSIVE_UNLINK_OPTION,
  REMOVE_FILES_OPTION,
  RMT_COMMAND_OPTION,
  RSH_COMMAND_OPTION,
  SAME_OWNER_OPTION,
  SHOW_DEFAULTS_OPTION,
  SHOW_OMITTED_DIRS_OPTION,
  STRIP_COMPONENTS_OPTION,
  SUFFIX_OPTION,
  TOTALS_OPTION,
  USAGE_OPTION,
  USE_COMPRESS_PROGRAM_OPTION,
  UTC_OPTION,
  VERSION_OPTION,
  VOLNO_FILE_OPTION,
  WILDCARDS_OPTION,
  WILDCARDS_MATCH_SLASH_OPTION
};

const char *argp_program_version = "tar (" PACKAGE ") " VERSION;
const char *argp_program_bug_address = "<" PACKAGE_BUGREPORT ">";
static char doc[] = N_("GNU `tar' saves many files together into a single tape or disk archive, and can restore individual files from the archive.\n\
\n\
Examples:\n\
  tar -cf archive.tar foo bar  # Create archive.tar from files foo and bar.\n\
  tar -tvf archive.tar         # List all files in archive.tar verbosely.\n\
  tar -xf archive.tar          # Extract all files from archive.tar.\n\
\vThe backup suffix is `~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.\n\
The version control may be set with --backup or VERSION_CONTROL, values are:\n\n\
  t, numbered     make numbered backups\n\
  nil, existing   numbered if numbered backups exist, simple otherwise\n\
  never, simple   always make simple backups\n");


static struct argp_option options[] = {
  {NULL, 0, NULL, 0,
   N_("Main operation mode:"), 0},
  
  {"list", 't', 0, 0,
   N_("list the contents of an archive"), 10 },
  {"extract", 'x', 0, 0,
   N_("extract files from an archive"), 10 },
  {"get", 0, 0, OPTION_ALIAS, NULL},
  {"create", 'c', 0, 0,
   N_("create a new archive"), 10 },
  {"diff", 'd', 0, 0,
   N_("find differences between archive and file system"), 10 },
  {"compare", 0, 0, OPTION_ALIAS, NULL, 10},
  {"append", 'r', 0, 0,
   N_("append files to the end of an archive"), 10 },
  {"update", 'u', 0, 0,
   N_("only append files newer than copy in archive"), 10 },
  {"catenate", 'A', 0, 0,
   N_("append tar files to an archive"), 10 },
  {"concatenate", 0, 0, OPTION_ALIAS, NULL, 10},
  {"delete", DELETE_OPTION, 0, 0,
   N_("delete from the archive (not on mag tapes!)"), 10 },

  {NULL, 0, NULL, 0,
   N_("Operation modifiers:"), 20},

  {"verify", 'W', 0, 0,
   N_("attempt to verify the archive after writing it"), 21 },
  {"remove-files", REMOVE_FILES_OPTION, 0, 0,
   N_("remove files after adding them to the archive"), 21 },
  {"keep-old-files", 'k', 0, 0,
   N_("don't replace existing files when extracting"), 21 },
  {"keep-newer-files", KEEP_NEWER_FILES_OPTION, 0, 0,
   N_("don't replace existing files that are newer than their archive copies"), 21 },
  {"no-overwrite-dir", NO_OVERWRITE_DIR_OPTION, 0, 0,
   N_("preserve metadata of existing directories"), 21 },
  {"overwrite", OVERWRITE_OPTION, 0, 0,
   N_("overwrite existing files when extracting"), 21 },
  {"unlink-first", 'U', 0, 0,
   N_("remove each file prior to extracting over it"), 21 },
  {"recursive-unlink", RECURSIVE_UNLINK_OPTION, 0, 0,
   N_("empty hierarchies prior to extracting directory"), 21 },
  {"sparse", 'S', 0, 0,
   N_("handle sparse files efficiently"), 21 },
  {"to-stdout", 'O', 0, 0,
   N_("extract files to standard output"), 21 },
  {"incremental", 'G', 0, 0,
   N_("handle old GNU-format incremental backup"), 21 },
  {"listed-incremental", 'g', N_("FILE"), 0,
   N_("handle new GNU-format incremental backup"), 21 },
  {"ignore-failed-read", IGNORE_FAILED_READ_OPTION, 0, 0,
   N_("do not exit with nonzero on unreadable files"), 21 },
  {"occurrence", OCCURRENCE_OPTION, N_("NUMBER"), OPTION_ARG_OPTIONAL,
   N_("process only the NUMth occurrence of each file in the archive. This option is valid only in conjunction with one of the subcommands --delete, --diff, --extract or --list and when a list of files is given either on the command line or via -T option. NUMBER defaults to 1."), 21 },

  {NULL, 0, NULL, 0,
   N_("Handling of file attributes:"), 30 },

  {"owner", OWNER_OPTION, N_("NAME"), 0,
   N_("force NAME as owner for added files"), 31 },
  {"group", GROUP_OPTION, N_("NAME"), 0,
   N_("force NAME as group for added files"), 31 },
  {"mode", MODE_OPTION, N_("CHANGES"), 0,
   N_("force (symbolic) mode CHANGES for added files"), 31 },
  {"atime-preserve", ATIME_PRESERVE_OPTION, 0, 0,
   N_("don't change access times on dumped files"), 31 },
  {"touch", 'm', 0, 0,
   N_("don't extract file modified time"), 31 },
  {"same-owner", SAME_OWNER_OPTION, 0, 0,
   N_("try extracting files with the same ownership"), 31 },
  {"no-same-owner", NO_SAME_OWNER_OPTION, 0, 0,
   N_("extract files as yourself"), 31 },
  {"numeric-owner", NUMERIC_OWNER_OPTION, 0, 0,
   N_("always use numbers for user/group names"), 31 },
  {"preserve-permissions", 'p', 0, 0,
   N_("extract permissions information"), 31 },
  {"same-permissions", 0, 0, OPTION_ALIAS, NULL, 31 },
  {"no-same-permissions", NO_SAME_PERMISSIONS_OPTION, 0, 0,
   N_("do not extract permissions information"), 31 },
  {"preserve-order", 's', 0, 0,
   N_("sort names to extract to match archive"), 31 },
  {"same-order", 0, 0, OPTION_ALIAS, NULL, 31 },
  {"preserve", PRESERVE_OPTION, 0, 0,
   N_("same as both -p and -s"), 31 },

  {NULL, 0, NULL, 0,
   N_("Device selection and switching:"), 40 },
  
  {"file", 'f', N_("ARCHIVE"), 0,
   N_("use archive file or device ARCHIVE"), 41 },
  {"force-local", FORCE_LOCAL_OPTION, 0, 0,
   N_("archive file is local even if has a colon"), 41 },
  {"rmt-command", RMT_COMMAND_OPTION, N_("COMMAND"), 0,
   N_("use given rmt COMMAND instead of rmt"), 41 }, 
  {"rsh-command", RSH_COMMAND_OPTION, N_("COMMAND"), 0,
   N_("use remote COMMAND instead of rsh"), 41 },
#ifdef DEVICE_PREFIX
  {"-[0-7][lmh]", 0, NULL, OPTION_DOC,
   N_("specify drive and density"), 41 },
#endif  
  {NULL, '0', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '1', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '2', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '3', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '4', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '5', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '6', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '7', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '8', NULL, OPTION_HIDDEN, NULL, 41 },
  {NULL, '9', NULL, OPTION_HIDDEN, NULL, 41 },
  
  {"multi-volume", 'M', 0, 0,
   N_("create/list/extract multi-volume archive"), 41 },
  {"tape-length", 'L', N_("NUMBER"), 0,
   N_("change tape after writing NUMBER x 1024 bytes"), 41 },
  {"info-script", 'F', N_("NAME"), 0,
   N_("run script at end of each tape (implies -M)"), 41 },
  {"new-volume-script", 0, 0, OPTION_ALIAS, NULL, 41 },
  {"volno-file", VOLNO_FILE_OPTION, N_("FILE"), 0,
   N_("use/update the volume number in FILE"), 41 },

  {NULL, 0, NULL, 0,
   N_("Device blocking:"), 50 },

  {"blocking-factor", 'b', N_("BLOCKS"), 0,
   N_("BLOCKS x 512 bytes per record"), 51 },
  {"record-size", RECORD_SIZE_OPTION, N_("NUMBER"), 0,
   N_("SIZE bytes per record, multiple of 512"), 51 },
  {"ignore-zeros", 'i', 0, 0,
   N_("ignore zeroed blocks in archive (means EOF)"), 51 },
  {"read-full-records", 'B', 0, 0,
   N_("reblock as we read (for 4.2BSD pipes)"), 51 }, 

  {NULL, 0, NULL, 0,
   N_("Archive format selection:"), 60 },
  
  {"format", FORMAT_OPTION, N_("FORMAT"), 0,
   N_("create archive of the given format."), 61 },

  {"", 0, NULL, OPTION_DOC, N_("FORMAT is one of the following:"), 62},
  {"", 0, NULL, OPTION_DOC, N_("v7        old V7 tar format"), 63},
  {"", 0, NULL, OPTION_DOC, N_("oldgnu    GNU format as per tar <= 1.12"), 63},
  {"", 0, NULL, OPTION_DOC, N_("gnu       GNU tar 1.13.x format"), 63},
  {"", 0, NULL, OPTION_DOC, N_("ustar     POSIX 1003.1-1988 (ustar) format"), 63 },
  {"", 0, NULL, OPTION_DOC, N_("posix     POSIX 1003.1-2001 (pax) format"), 63 },

  {"old-archive", OLD_ARCHIVE_OPTION, 0, 0, /* FIXME */
   N_("same as --format=v7"), 68 },
  {"portability", 0, 0, OPTION_ALIAS, NULL, 68 },
  {"posix", POSIX_OPTION, 0, 0,
   N_("same as --format=posix"), 68 },
  {"pax-option", PAX_OPTION, N_("keyword[[:]=value][,keyword[[:]=value], ...]"), 0,
   N_("control pax keywords"), 68 },
  {"label", 'V', N_("TEXT"), 0,
   N_("create archive with volume name NAME. At list/extract time, use TEXT as a globbing pattern"), 68 },
  {"bzip2", 'j', 0, 0,
   N_("filter the archive through bzip2"), 68 },
  {"gzip", 'z', 0, 0,
   N_("filter the archive through gzip"), 68 },
  {"gunzip", 0, 0, OPTION_ALIAS, NULL, 68 },
  {"ungzip", 0, 0, OPTION_ALIAS, NULL, 68 },
  {"compress", 'Z', 0, 0,
   N_("filter the archive through compress"), 68 },
  {"uncompress", 0, 0, OPTION_ALIAS, NULL, 68 },
  {"use-compress-program", USE_COMPRESS_PROGRAM_OPTION, N_("PROG"), 0,
   N_("filter through PROG (must accept -d)"), 68 },

  {NULL, 0, NULL, 0,
   N_("Local file selection:"), 70 },

  {"directory", 'C', N_("DIR"), 0,
   N_("change to directory DIR"), 71 },
  {"files-from", 'T', N_("FILE-OF-NAMES"), 0,
   N_("get names to extract or create from file NAME"), 71 },
  {"null", NULL_OPTION, 0, 0,
   N_("-T reads null-terminated names, disable -C"), 71 },
  {"exclude", EXCLUDE_OPTION, N_("PATTERN"), 0,
   N_("exclude files, given as a PATTERN"), 71 },
  {"exclude-from", 'X', N_("FILE"), 0,
   N_("exclude patterns listed in FILE"), 71 },
  {"ignore-case", IGNORE_CASE_OPTION, 0, 0,
   N_("exclusion ignores case"), 71 },
  {"anchored", ANCHORED_OPTION, 0, 0,
   N_("exclude patterns match file name start (default)"), 71 },
  {"no-anchored", NO_ANCHORED_OPTION, 0, 0,
   N_("exclude patterns match after any /"), 71 },
  {"no-ignore-case", NO_IGNORE_CASE_OPTION, 0, 0,
   N_("exclusion is case sensitive (default)"), 71 },
  {"no-wildcards", NO_WILDCARDS_OPTION, 0, 0,
   N_("exclude patterns are plain strings"), 71 },
  {"no-wildcards-match-slash", NO_WILDCARDS_MATCH_SLASH_OPTION, 0, 0,
   N_("exclude pattern wildcards do not match '/'"), 71 },
  {"no-recursion", NO_RECURSION_OPTION, 0, 0,
   N_("avoid descending automatically in directories"), 71 },
  {"one-file-system", 'l', 0, 0, /* FIXME: emit warning */
   N_("stay in local file system when creating archive"), 71 },
  {"recursion", RECURSION_OPTION, 0, 0,
   N_("recurse into directories (default)"), 71 },
  {"absolute-names", 'P', 0, 0,
   N_("don't strip leading `/'s from file names"), 71 },
  {"dereference", 'h', 0, 0,
   N_("dump instead the files symlinks point to"), 71 },
  {"starting-file", 'K', N_("MEMBER-NAME"), 0,
   N_("begin at member MEMBER-NAME in the archive"), 71 },
  {"strip-components", STRIP_COMPONENTS_OPTION, N_("NUMBER"), 0,
   N_("strip NUMBER leading components from file names"), 71 },
  {"newer", 'N', N_("DATE-OR-FILE"), 0,
   N_("only store files newer than DATE-OR-FILE"), 71 },
  {"newer-mtime", NEWER_MTIME_OPTION, N_("DATE"), 0,
   N_("compare date and time when data changed only"), 71 },
  {"after-date", 'N', N_("DATE"), 0,
   N_("same as -N"), 71 },
  {"backup", BACKUP_OPTION, N_("CONTROL"), OPTION_ARG_OPTIONAL,
   N_("backup before removal, choose version CONTROL"), 71 },
  {"suffix", SUFFIX_OPTION, N_("STRING"), 0,
   N_("backup before removal, override usual suffix ('~' unless overridden by environment variable SIMPLE_BACKUP_SUFFIX"), 71 },
  {"wildcards", WILDCARDS_OPTION, 0, 0,
   N_("exclude patterns use wildcards (default)"), 71 },
  {"wildcards-match-slash", WILDCARDS_MATCH_SLASH_OPTION, 0, 0,
   N_("exclude pattern wildcards match '/' (default)"), 71 },

  {NULL, 0, NULL, 0,
   N_("Informative output:"), 80 },
  
  {"verbose", 'v', 0, 0,
   N_("verbosely list files processed"), 81 },
  {"checkpoint", CHECKPOINT_OPTION, 0, 0,
   N_("print directory names while reading the archive"), 81 },
  {"check-links", CHECK_LINKS_OPTION, 0, 0,
   N_("print a message if not all links are dumped"), 82 },
  {"totals", TOTALS_OPTION, 0, 0,
   N_("print total bytes written while creating archive"), 82 },
  {"utc", UTC_OPTION, 0, 0,
   N_("print file modification dates in UTC"), 82 },
  {"index-file", INDEX_FILE_OPTION, N_("FILE"), 0,
   N_("send verbose output to FILE"), 82 },
  {"block-number", 'R', 0, 0,
   N_("show block number within archive with each message"), 82 },
  {"interactive", 'w', 0, 0,
   N_("ask for confirmation for every action"), 82 },
  {"confirmation", 0, 0, OPTION_ALIAS, NULL, 82 },
  {"show-defaults", SHOW_DEFAULTS_OPTION, 0, 0,
   N_("Show tar defaults"), 82 },
  {"show-omitted-dirs", SHOW_OMITTED_DIRS_OPTION, 0, 0,
   N_("When listing or extracting, list each directory that does not match search criteria"), 82 },
  
  {NULL, 0, NULL, 0,
   N_("Compatibility options:"), 90 },

  {NULL, 'o', 0, 0,
   N_("when creating, same as --old-archive. When extracting, same as --no-same-owner"), 91 },

  {NULL, 0, NULL, 0,
   N_("Other options:"), 100 },

  {"help",  '?', 0, 0,  N_("Give this help list"), -1},
  {"usage", USAGE_OPTION, 0, 0,  N_("Give a short usage message"), -1},
  {"license", LICENSE_OPTION, 0, 0, N_("Print license and exit"), -1},
  {"version", VERSION_OPTION, 0, 0,  N_("Print program version"), -1},
  /* FIXME -V (--label) conflicts with the default short option for
     --version */
  
  {0, 0, 0, 0}
};

struct tar_args {
  char const *textual_date_option;
  int exclude_options;
  bool o_option;
  int pax_option;
  char const *backup_suffix_string;
  char const *version_control_string;
  int input_files;
};

static void
show_default_settings (FILE *stream)
{
  fprintf (stream,
	   "--format=%s -f%s -b%d --rmt-command=%s --rsh-command=%s\n",
	   archive_format_string (DEFAULT_ARCHIVE_FORMAT),
	   DEFAULT_ARCHIVE, DEFAULT_BLOCKING,
	   DEFAULT_RMT_COMMAND, REMOTE_SHELL);
}

static void
set_subcommand_option (enum subcommand subcommand)
