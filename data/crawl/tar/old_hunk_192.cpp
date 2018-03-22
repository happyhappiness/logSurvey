  use_compress_program_option = string;
}

static void
decode_options (int argc, char **argv)
{
  int optchar;			/* option letter */
  int input_files;		/* number of input files */
  char const *textual_date_option = 0;
  char const *backup_suffix_string;
  char const *version_control_string = 0;
  int exclude_options = EXCLUDE_WILDCARDS;
  bool o_option = 0;
  int pax_option = 0;

  /* Set some default option values.  */

  subcommand_option = UNKNOWN_SUBCOMMAND;
  archive_format = DEFAULT_FORMAT;
  blocking_factor = DEFAULT_BLOCKING;
  record_size = DEFAULT_BLOCKING * BLOCKSIZE;
  excluded = new_exclude ();
  newer_mtime_option.tv_sec = TYPE_MINIMUM (time_t);
  newer_mtime_option.tv_nsec = -1;
  recursion_option = FNM_LEADING_DIR;

  owner_option = -1;
  group_option = -1;

  backup_suffix_string = getenv ("SIMPLE_BACKUP_SUFFIX");

  /* Convert old-style tar call by exploding option element and rearranging
     options accordingly.  */

  if (argc > 1 && argv[1][0] != '-')
    {
      int new_argc;		/* argc value for rearranged arguments */
      char **new_argv;		/* argv value for rearranged arguments */
      char *const *in;		/* cursor into original argv */
      char **out;		/* cursor into rearranged argv */
      const char *letter;	/* cursor into old option letters */
      char buffer[3];		/* constructed option buffer */
      const char *cursor;	/* cursor in OPTION_STRING */

      /* Initialize a constructed option.  */

      buffer[0] = '-';
      buffer[2] = '\0';

      /* Allocate a new argument array, and copy program name in it.  */

      new_argc = argc - 1 + strlen (argv[1]);
      new_argv = xmalloc ((new_argc + 1) * sizeof (char *));
      in = argv;
      out = new_argv;
      *out++ = *in++;

      /* Copy each old letter option as a separate option, and have the
	 corresponding argument moved next to it.  */

      for (letter = *in++; *letter; letter++)
	{
	  buffer[1] = *letter;
	  *out++ = xstrdup (buffer);
	  cursor = strchr (OPTION_STRING, *letter);
	  if (cursor && cursor[1] == ':')
	    {
	      if (in < argv + argc)
		*out++ = *in++;
	      else
		USAGE_ERROR ((0, 0, _("Old option `%c' requires an argument."),
			      *letter));
	    }
	}

      /* Copy all remaining options.  */

      while (in < argv + argc)
	*out++ = *in++;
      *out = 0;

      /* Replace the old option list by the new one.  */

      argc = new_argc;
      argv = new_argv;
    }

  /* Parse all options and non-options as they appear.  */

  input_files = 0;

  prepend_default_options (getenv ("TAR_OPTIONS"), &argc, &argv);

  while (optchar = getopt_long (argc, argv, OPTION_STRING, long_options, 0),
	 optchar != -1)
    switch (optchar)
      {
      case '?':
	usage (TAREXIT_FAILURE);

      case 0:
	break;

      case 1:
	/* File name or non-parsed option, because of RETURN_IN_ORDER
	   ordering triggered by the leading dash in OPTION_STRING.  */

	name_add (optarg);
	input_files++;
	break;

      case 'A':
	set_subcommand_option (CAT_SUBCOMMAND);
	break;

      case 'b':
	{
	  uintmax_t u;
	  if (! (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK
		 && u == (blocking_factor = u)
		 && 0 < blocking_factor
		 && u == (record_size = u * BLOCKSIZE) / BLOCKSIZE))
	    USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
			  _("Invalid blocking factor")));
	}
	break;

      case 'B':
	/* Try to reblock input records.  For reading 4.2BSD pipes.  */

	/* It would surely make sense to exchange -B and -R, but it seems
	   that -B has been used for a long while in Sun tar and most
	   BSD-derived systems.  This is a consequence of the block/record
	   terminology confusion.  */

	read_full_records_option = true;
	break;

      case 'c':
	set_subcommand_option (CREATE_SUBCOMMAND);
	break;

      case 'C':
	name_add ("-C");
	name_add (optarg);
	break;

      case 'd':
	set_subcommand_option (DIFF_SUBCOMMAND);
	break;

      case 'f':
	if (archive_names == allocated_archive_names)
	  {
	    allocated_archive_names *= 2;
	    archive_name_array =
	      xrealloc (archive_name_array,
			sizeof (const char *) * allocated_archive_names);
	  }
	archive_name_array[archive_names++] = optarg;
	break;

      case 'F':
	/* Since -F is only useful with -M, make it implied.  Run this
	   script at the end of each tape.  */

	info_script_option = optarg;
	multi_volume_option = true;
	break;

      case 'g':
	listed_incremental_option = optarg;
	after_date_option = true;
	/* Fall through.  */

      case 'G':
	/* We are making an incremental dump (FIXME: are we?); save
	   directories at the beginning of the archive, and include in each
	   directory its contents.  */

	incremental_option = true;
	break;

      case 'h':
	/* Follow symbolic links.  */
	dereference_option = true;
	break;

      case 'i':
	/* Ignore zero blocks (eofs).  This can't be the default,
	   because Unix tar writes two blocks of zeros, then pads out
	   the record with garbage.  */

	ignore_zeros_option = true;
	break;

      case 'I':
	USAGE_ERROR ((0, 0,
		      _("Warning: the -I option is not supported;"
			" perhaps you meant -j or -T?")));
	break;

      case 'j':
	set_use_compress_program_option ("bzip2");
	break;

      case 'k':
	/* Don't replace existing files.  */
	old_files_option = KEEP_OLD_FILES;
	break;

      case 'K':
	starting_file_option = true;
	addname (optarg, 0);
	break;

      case 'l':
	/* When dumping directories, don't dump files/subdirectories
	   that are on other filesystems.  */

	one_file_system_option = true;
	break;

      case 'L':
	{
	  uintmax_t u;
	  if (xstrtoumax (optarg, 0, 10, &u, "") != LONGINT_OK)
	    USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
			  _("Invalid tape length")));
	  tape_length_option = 1024 * (tarlong) u;
	  multi_volume_option = true;
	}
	break;

      case 'm':
	touch_option = true;
	break;

      case 'M':
	/* Make multivolume archive: when we can't write any more into
	   the archive, re-open it, and continue writing.  */

	multi_volume_option = true;
	break;

#if !MSDOS
      case 'N':
	after_date_option = true;
	/* Fall through.  */

      case NEWER_MTIME_OPTION:
	if (NEWER_OPTION_INITIALIZED (newer_mtime_option))
	  USAGE_ERROR ((0, 0, _("More than one threshold date")));

	if (FILESYSTEM_PREFIX_LEN (optarg) != 0
	    || ISSLASH (*optarg)
	    || *optarg == '.')
	  {
	    struct stat st;
	    if (deref_stat (dereference_option, optarg, &st) != 0)
	      {
		stat_error (optarg);
		USAGE_ERROR ((0, 0, _("Date file not found")));
	      }
	    newer_mtime_option.tv_sec = st.st_mtime;
	    newer_mtime_option.tv_nsec = TIMESPEC_NS (st.st_mtim);
	  }
	else
	  {
	    if (! get_date (&newer_mtime_option, optarg, NULL))
	      {
		WARN ((0, 0, _("Substituting %s for unknown date format %s"),
		       tartime (newer_mtime_option.tv_sec), quote (optarg)));
		newer_mtime_option.tv_nsec = 0;
	      }
	    else
	      textual_date_option = optarg;
	  }

	break;
#endif /* not MSDOS */

      case 'o':
	o_option = true;
	break;

      case 'O':
	to_stdout_option = true;
	break;

      case 'p':
	same_permissions_option = true;
	break;

      case 'P':
	absolute_names_option = true;
	break;

      case 'r':
	set_subcommand_option (APPEND_SUBCOMMAND);
	break;

      case 'R':
	/* Print block numbers for debugging bad tar archives.  */

	/* It would surely make sense to exchange -B and -R, but it seems
	   that -B has been used for a long while in Sun tar ans most
	   BSD-derived systems.  This is a consequence of the block/record
	   terminology confusion.  */

	block_number_option = true;
	break;

      case 's':
	/* Names to extr are sorted.  */

	same_order_option = true;
	break;

      case 'S':
	sparse_option = true;
	break;

      case 't':
	set_subcommand_option (LIST_SUBCOMMAND);
	verbose_option++;
	break;

      case 'T':
	files_from_option = optarg;
	break;

      case 'u':
	set_subcommand_option (UPDATE_SUBCOMMAND);
	break;

      case 'U':
	old_files_option = UNLINK_FIRST_OLD_FILES;
	break;

      case UTC_OPTION:
	utc_option = true;
	break;

      case 'v':
	verbose_option++;
	break;

      case 'V':
	volume_label_option = optarg;
	break;

      case 'w':
	interactive_option = true;
	break;

      case 'W':
	verify_option = true;
	break;

      case 'x':
	set_subcommand_option (EXTRACT_SUBCOMMAND);
	break;

      case 'X':
	if (add_exclude_file (add_exclude, excluded, optarg,
			      exclude_options | recursion_option, '\n')
	    != 0)
	  {
	    int e = errno;
	    FATAL_ERROR ((0, e, "%s", quotearg_colon (optarg)));
	  }
	break;

      case 'y':
	USAGE_ERROR ((0, 0,
		      _("Warning: the -y option is not supported;"
			" perhaps you meant -j?")));
	break;

      case 'z':
	set_use_compress_program_option ("gzip");
	break;

      case 'Z':
	set_use_compress_program_option ("compress");
	break;

      case ANCHORED_OPTION:
	exclude_options |= EXCLUDE_ANCHORED;
	break;

      case ATIME_PRESERVE_OPTION:
	atime_preserve_option = true;
	break;

      case CHECKPOINT_OPTION:
	checkpoint_option = true;
	break;

      case BACKUP_OPTION:
	backup_option = true;
	if (optarg)
	  version_control_string = optarg;
	break;

      case DELETE_OPTION:
	set_subcommand_option (DELETE_SUBCOMMAND);
	break;

      case EXCLUDE_OPTION:
	add_exclude (excluded, optarg, exclude_options | recursion_option);
	break;

      case FORCE_LOCAL_OPTION:
	force_local_option = true;
	break;

      case FORMAT_OPTION:
	set_archive_format (optarg);
	break;

      case INDEX_FILE_OPTION:
	index_file_name = optarg;
	break;

      case IGNORE_CASE_OPTION:
	exclude_options |= FNM_CASEFOLD;
	break;

      case IGNORE_FAILED_READ_OPTION:
	ignore_failed_read_option = true;
	break;

      case KEEP_NEWER_FILES_OPTION:
	old_files_option = KEEP_NEWER_FILES;
	break;

      case GROUP_OPTION:
	if (! (strlen (optarg) < GNAME_FIELD_SIZE
	       && gname_to_gid (optarg, &group_option)))
	  {
	    uintmax_t g;
	    if (xstrtoumax (optarg, 0, 10, &g, "") == LONGINT_OK
		&& g == (gid_t) g)
	      group_option = g;
	    else
	      FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
			    _("%s: Invalid group")));
	  }
	break;

      case MODE_OPTION:
	mode_option
	  = mode_compile (optarg,
			  MODE_MASK_EQUALS | MODE_MASK_PLUS | MODE_MASK_MINUS);
	if (mode_option == MODE_INVALID)
	  FATAL_ERROR ((0, 0, _("Invalid mode given on option")));
	if (mode_option == MODE_MEMORY_EXHAUSTED)
	  xalloc_die ();
	break;

      case NO_ANCHORED_OPTION:
	exclude_options &= ~ EXCLUDE_ANCHORED;
	break;

      case NO_IGNORE_CASE_OPTION:
	exclude_options &= ~ FNM_CASEFOLD;
	break;

      case NO_OVERWRITE_DIR_OPTION:
	old_files_option = NO_OVERWRITE_DIR_OLD_FILES;
	break;

      case NO_WILDCARDS_OPTION:
	exclude_options &= ~ EXCLUDE_WILDCARDS;
	break;

      case NO_WILDCARDS_MATCH_SLASH_OPTION:
	exclude_options |= FNM_FILE_NAME;
	break;

      case NULL_OPTION:
	filename_terminator = '\0';
	break;

      case NUMERIC_OWNER_OPTION:
	numeric_owner_option = true;
	break;

      case OCCURRENCE_OPTION:
	if (!optarg)
	  occurrence_option = 1;
	else
	  {
	    uintmax_t u;
	    if (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK)
	      occurrence_option = u;
	    else
	      FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
			    _("Invalid number")));
	  }
	break;

      case OVERWRITE_OPTION:
	old_files_option = OVERWRITE_OLD_FILES;
	break;

      case OWNER_OPTION:
	if (! (strlen (optarg) < UNAME_FIELD_SIZE
	       && uname_to_uid (optarg, &owner_option)))
	  {
	    uintmax_t u;
	    if (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK
		&& u == (uid_t) u)
	      owner_option = u;
	    else
	      FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
			    _("Invalid owner")));
	  }
	break;

      case PAX_OPTION:
	pax_option++;
	xheader_set_option (optarg);
	break;

      case POSIX_OPTION:
	set_archive_format ("posix");
	break;

      case PRESERVE_OPTION:
	same_permissions_option = true;
	same_order_option = true;
	break;

      case RECORD_SIZE_OPTION:
	{
	  uintmax_t u;
	  if (! (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK
		 && u == (size_t) u))
	    USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
			  _("Invalid record size")));
	  record_size = u;
	  if (record_size % BLOCKSIZE != 0)
	    USAGE_ERROR ((0, 0, _("Record size must be a multiple of %d."),
			  BLOCKSIZE));
	  blocking_factor = record_size / BLOCKSIZE;
	}
	break;

      case RECURSIVE_UNLINK_OPTION:
	recursive_unlink_option = true;
	break;

      case REMOVE_FILES_OPTION:
	remove_files_option = true;
	break;

      case RMT_COMMAND_OPTION:
	rmt_command_option = optarg;
	break;
	
      case RSH_COMMAND_OPTION:
	rsh_command_option = optarg;
	break;

      case SHOW_DEFAULTS_OPTION:
	printf ("--format=%s -f%s -b%d\n",
		archive_format_string (DEFAULT_ARCHIVE_FORMAT),
		DEFAULT_ARCHIVE, DEFAULT_BLOCKING);
	exit(0);

      case STRIP_COMPONENTS_OPTION:
	{
	  uintmax_t u;
	  if (! (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK
		 && u == (size_t) u))
	    USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
			  _("Invalid number of elements")));
	  strip_name_components = u;
	}
	break;

      case SUFFIX_OPTION:
	backup_option = true;
	backup_suffix_string = optarg;
	break;

      case TOTALS_OPTION:
	totals_option = true;
	break;

      case USE_COMPRESS_PROGRAM_OPTION:
	set_use_compress_program_option (optarg);
	break;

      case VOLNO_FILE_OPTION:
	volno_file_option = optarg;
	break;

      case WILDCARDS_OPTION:
	exclude_options |= EXCLUDE_WILDCARDS;
	break;

      case WILDCARDS_MATCH_SLASH_OPTION:
	exclude_options &= ~ FNM_FILE_NAME;
	break;

      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':

#ifdef DEVICE_PREFIX
	{
	  int device = optchar - '0';
	  int density;
	  static char buf[sizeof DEVICE_PREFIX + 10];
	  char *cursor;

	  density = getopt_long (argc, argv, "lmh", 0, 0);
	  strcpy (buf, DEVICE_PREFIX);
	  cursor = buf + strlen (buf);

#ifdef DENSITY_LETTER

	  sprintf (cursor, "%d%c", device, density);

#else /* not DENSITY_LETTER */

	  switch (density)
	    {
	    case 'l':
#ifdef LOW_NUM
	      device += LOW_NUM;
#endif
	      break;

	    case 'm':
#ifdef MID_NUM
	      device += MID_NUM;
#else
	      device += 8;
#endif
	      break;

	    case 'h':
#ifdef HGH_NUM
	      device += HGH_NUM;
#else
	      device += 16;
#endif
	      break;

	    default:
	      usage (TAREXIT_FAILURE);
	    }
	  sprintf (cursor, "%d", device);

#endif /* not DENSITY_LETTER */

	  if (archive_names == allocated_archive_names)
	    {
	      allocated_archive_names *= 2;
	      archive_name_array =
		xrealloc (archive_name_array,
			  sizeof (const char *) * allocated_archive_names);
	    }
	  archive_name_array[archive_names++] = strdup (buf);
	}
	break;

#else /* not DEVICE_PREFIX */

	USAGE_ERROR ((0, 0,
		      _("Options `-[0-7][lmh]' not supported by *this* tar")));

#endif /* not DEVICE_PREFIX */
      }

  /* Special handling for 'o' option:

