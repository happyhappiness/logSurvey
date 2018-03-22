   use_compress_program_option = string;
 }
 
-static void
-decode_options (int argc, char **argv)
+void
+license ()
 {
-  int optchar;			/* option letter */
-  int input_files;		/* number of input files */
-  char const *textual_date_option = 0;
-  char const *backup_suffix_string;
-  char const *version_control_string = 0;
-  int exclude_options = EXCLUDE_WILDCARDS;
-  bool o_option = 0;
-  int pax_option = 0;
-
-  /* Set some default option values.  */
-
-  subcommand_option = UNKNOWN_SUBCOMMAND;
-  archive_format = DEFAULT_FORMAT;
-  blocking_factor = DEFAULT_BLOCKING;
-  record_size = DEFAULT_BLOCKING * BLOCKSIZE;
-  excluded = new_exclude ();
-  newer_mtime_option.tv_sec = TYPE_MINIMUM (time_t);
-  newer_mtime_option.tv_nsec = -1;
-  recursion_option = FNM_LEADING_DIR;
-
-  owner_option = -1;
-  group_option = -1;
-
-  backup_suffix_string = getenv ("SIMPLE_BACKUP_SUFFIX");
-
-  /* Convert old-style tar call by exploding option element and rearranging
-     options accordingly.  */
+  printf ("tar (%s) %s\n%s\n", PACKAGE_NAME, PACKAGE_VERSION,
+	  "Copyright (C) 2004 Free Software Foundation, Inc.\n");
+  puts (_("Based on the work of John Gilmore and Jay Fenlason. See AUTHORS\n\
+for complete list of authors.\n"));
+  printf (_("   GNU tar is free software; you can redistribute it and/or modify\n"
+    "   it under the terms of the GNU General Public License as published by\n"
+    "   the Free Software Foundation; either version 2 of the License, or\n"
+    "   (at your option) any later version.\n"
+    "\n"
+    "   GNU Mailutils is distributed in the hope that it will be useful,\n"
+    "   but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
+    "   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
+    "   GNU General Public License for more details.\n"
+    "\n"
+    "   You should have received a copy of the GNU General Public License\n"
+    "   along with GNU Mailutils; if not, write to the Free Software\n"
+    "   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA\n\n"));
+  exit (0);
+}
 
-  if (argc > 1 && argv[1][0] != '-')
+static error_t
+parse_opt(int key, char *arg, struct argp_state *state)
+{
+  struct tar_args *args = state->input;
+  
+  switch (key)
     {
-      int new_argc;		/* argc value for rearranged arguments */
-      char **new_argv;		/* argv value for rearranged arguments */
-      char *const *in;		/* cursor into original argv */
-      char **out;		/* cursor into rearranged argv */
-      const char *letter;	/* cursor into old option letters */
-      char buffer[3];		/* constructed option buffer */
-      const char *cursor;	/* cursor in OPTION_STRING */
-
-      /* Initialize a constructed option.  */
-
-      buffer[0] = '-';
-      buffer[2] = '\0';
-
-      /* Allocate a new argument array, and copy program name in it.  */
-
-      new_argc = argc - 1 + strlen (argv[1]);
-      new_argv = xmalloc ((new_argc + 1) * sizeof (char *));
-      in = argv;
-      out = new_argv;
-      *out++ = *in++;
-
-      /* Copy each old letter option as a separate option, and have the
-	 corresponding argument moved next to it.  */
-
-      for (letter = *in++; *letter; letter++)
-	{
-	  buffer[1] = *letter;
-	  *out++ = xstrdup (buffer);
-	  cursor = strchr (OPTION_STRING, *letter);
-	  if (cursor && cursor[1] == ':')
-	    {
-	      if (in < argv + argc)
-		*out++ = *in++;
-	      else
-		USAGE_ERROR ((0, 0, _("Old option `%c' requires an argument."),
-			      *letter));
-	    }
-	}
-
-      /* Copy all remaining options.  */
-
-      while (in < argv + argc)
-	*out++ = *in++;
-      *out = 0;
-
-      /* Replace the old option list by the new one.  */
-
-      argc = new_argc;
-      argv = new_argv;
-    }
-
-  /* Parse all options and non-options as they appear.  */
-
-  input_files = 0;
-
-  prepend_default_options (getenv ("TAR_OPTIONS"), &argc, &argv);
-
-  while (optchar = getopt_long (argc, argv, OPTION_STRING, long_options, 0),
-	 optchar != -1)
-    switch (optchar)
-      {
-      case '?':
-	usage (TAREXIT_FAILURE);
-
-      case 0:
-	break;
-
       case 1:
-	/* File name or non-parsed option, because of RETURN_IN_ORDER
-	   ordering triggered by the leading dash in OPTION_STRING.  */
-
+	/* File name or non-parsed option, because of ARGP_IN_ORDER */
 	name_add (optarg);
-	input_files++;
+	args->input_files++;
 	break;
 
-      case 'A':
-	set_subcommand_option (CAT_SUBCOMMAND);
-	break;
-
-      case 'b':
-	{
-	  uintmax_t u;
-	  if (! (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK
-		 && u == (blocking_factor = u)
-		 && 0 < blocking_factor
-		 && u == (record_size = u * BLOCKSIZE) / BLOCKSIZE))
-	    USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
-			  _("Invalid blocking factor")));
-	}
-	break;
-
-      case 'B':
-	/* Try to reblock input records.  For reading 4.2BSD pipes.  */
-
-	/* It would surely make sense to exchange -B and -R, but it seems
-	   that -B has been used for a long while in Sun tar and most
-	   BSD-derived systems.  This is a consequence of the block/record
-	   terminology confusion.  */
-
-	read_full_records_option = true;
-	break;
-
-      case 'c':
-	set_subcommand_option (CREATE_SUBCOMMAND);
-	break;
-
-      case 'C':
-	name_add ("-C");
-	name_add (optarg);
-	break;
-
-      case 'd':
-	set_subcommand_option (DIFF_SUBCOMMAND);
-	break;
-
-      case 'f':
-	if (archive_names == allocated_archive_names)
-	  {
-	    allocated_archive_names *= 2;
-	    archive_name_array =
-	      xrealloc (archive_name_array,
-			sizeof (const char *) * allocated_archive_names);
-	  }
-	archive_name_array[archive_names++] = optarg;
-	break;
-
-      case 'F':
-	/* Since -F is only useful with -M, make it implied.  Run this
-	   script at the end of each tape.  */
-
-	info_script_option = optarg;
-	multi_volume_option = true;
-	break;
-
-      case 'g':
-	listed_incremental_option = optarg;
-	after_date_option = true;
-	/* Fall through.  */
-
-      case 'G':
-	/* We are making an incremental dump (FIXME: are we?); save
-	   directories at the beginning of the archive, and include in each
-	   directory its contents.  */
-
-	incremental_option = true;
-	break;
-
-      case 'h':
-	/* Follow symbolic links.  */
-	dereference_option = true;
-	break;
-
-      case 'i':
-	/* Ignore zero blocks (eofs).  This can't be the default,
-	   because Unix tar writes two blocks of zeros, then pads out
-	   the record with garbage.  */
-
-	ignore_zeros_option = true;
-	break;
-
-      case 'I':
-	USAGE_ERROR ((0, 0,
-		      _("Warning: the -I option is not supported;"
-			" perhaps you meant -j or -T?")));
-	break;
-
-      case 'j':
-	set_use_compress_program_option ("bzip2");
-	break;
+    case 'A':
+      set_subcommand_option (CAT_SUBCOMMAND);
+      break;
+      
+    case 'b':
+      {
+	uintmax_t u;
+	if (! (xstrtoumax (arg, 0, 10, &u, "") == LONGINT_OK
+	       && u == (blocking_factor = u)
+	       && 0 < blocking_factor
+	       && u == (record_size = u * BLOCKSIZE) / BLOCKSIZE))
+	  USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (arg),
+			_("Invalid blocking factor")));
+      }
+      break;
 
-      case 'k':
-	/* Don't replace existing files.  */
-	old_files_option = KEEP_OLD_FILES;
-	break;
+    case 'B':
+      /* Try to reblock input records.  For reading 4.2BSD pipes.  */
+      
+      /* It would surely make sense to exchange -B and -R, but it seems
+	 that -B has been used for a long while in Sun tar and most
+	 BSD-derived systems.  This is a consequence of the block/record
+	 terminology confusion.  */
+      
+      read_full_records_option = true;
+      break;
 
-      case 'K':
-	starting_file_option = true;
-	addname (optarg, 0);
-	break;
+    case 'c':
+      set_subcommand_option (CREATE_SUBCOMMAND);
+      break;
 
-      case 'l':
-	/* When dumping directories, don't dump files/subdirectories
-	   that are on other filesystems.  */
+    case 'C':
+      name_add ("-C");
+      name_add (arg);
+      break;
 
-	one_file_system_option = true;
-	break;
+    case 'd':
+      set_subcommand_option (DIFF_SUBCOMMAND);
+      break;
 
-      case 'L':
+    case 'f':
+      if (archive_names == allocated_archive_names)
 	{
-	  uintmax_t u;
-	  if (xstrtoumax (optarg, 0, 10, &u, "") != LONGINT_OK)
-	    USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
-			  _("Invalid tape length")));
-	  tape_length_option = 1024 * (tarlong) u;
-	  multi_volume_option = true;
+	  allocated_archive_names *= 2;
+	  archive_name_array =
+	    xrealloc (archive_name_array,
+		      sizeof (const char *) * allocated_archive_names);
 	}
-	break;
-
-      case 'm':
-	touch_option = true;
-	break;
-
-      case 'M':
-	/* Make multivolume archive: when we can't write any more into
-	   the archive, re-open it, and continue writing.  */
+      archive_name_array[archive_names++] = arg;
+      break;
 
+    case 'F':
+      /* Since -F is only useful with -M, make it implied.  Run this
+	 script at the end of each tape.  */
+      
+      info_script_option = arg;
+      multi_volume_option = true;
+      break;
+      
+    case 'g':
+      listed_incremental_option = arg;
+      after_date_option = true;
+      /* Fall through.  */
+      
+    case 'G':
+      /* We are making an incremental dump (FIXME: are we?); save
+	 directories at the beginning of the archive, and include in each
+	 directory its contents.  */
+      
+      incremental_option = true;
+      break;
+      
+    case 'h':
+      /* Follow symbolic links.  */
+      dereference_option = true;
+      break;
+      
+    case 'i':
+      /* Ignore zero blocks (eofs).  This can't be the default,
+	 because Unix tar writes two blocks of zeros, then pads out
+	 the record with garbage.  */
+      
+      ignore_zeros_option = true;
+      break;
+      
+    case 'I':
+      USAGE_ERROR ((0, 0,
+		    _("Warning: the -I option is not supported;"
+		      " perhaps you meant -j or -T?")));
+      break;
+      
+    case 'j':
+      set_use_compress_program_option ("bzip2");
+      break;
+      
+    case 'k':
+      /* Don't replace existing files.  */
+      old_files_option = KEEP_OLD_FILES;
+      break;
+      
+    case 'K':
+      starting_file_option = true;
+      addname (arg, 0);
+      break;
+      
+    case 'l':
+      /* When dumping directories, don't dump files/subdirectories
+	 that are on other filesystems.  */
+      
+      one_file_system_option = true;
+      break;
+      
+    case 'L':
+      {
+	uintmax_t u;
+	if (xstrtoumax (arg, 0, 10, &u, "") != LONGINT_OK)
+	  USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (arg),
+			_("Invalid tape length")));
+	tape_length_option = 1024 * (tarlong) u;
 	multi_volume_option = true;
-	break;
-
+      }
+      break;
+      
+    case 'm':
+      touch_option = true;
+      break;
+      
+    case 'M':
+      /* Make multivolume archive: when we can't write any more into
+	 the archive, re-open it, and continue writing.  */
+      
+      multi_volume_option = true;
+      break;
+      
 #if !MSDOS
-      case 'N':
-	after_date_option = true;
-	/* Fall through.  */
-
-      case NEWER_MTIME_OPTION:
-	if (NEWER_OPTION_INITIALIZED (newer_mtime_option))
-	  USAGE_ERROR ((0, 0, _("More than one threshold date")));
-
-	if (FILESYSTEM_PREFIX_LEN (optarg) != 0
-	    || ISSLASH (*optarg)
-	    || *optarg == '.')
-	  {
-	    struct stat st;
-	    if (deref_stat (dereference_option, optarg, &st) != 0)
-	      {
-		stat_error (optarg);
-		USAGE_ERROR ((0, 0, _("Date file not found")));
-	      }
-	    newer_mtime_option.tv_sec = st.st_mtime;
-	    newer_mtime_option.tv_nsec = TIMESPEC_NS (st.st_mtim);
-	  }
-	else
-	  {
-	    if (! get_date (&newer_mtime_option, optarg, NULL))
-	      {
-		WARN ((0, 0, _("Substituting %s for unknown date format %s"),
-		       tartime (newer_mtime_option.tv_sec), quote (optarg)));
-		newer_mtime_option.tv_nsec = 0;
-	      }
-	    else
-	      textual_date_option = optarg;
-	  }
-
-	break;
+    case 'N':
+      after_date_option = true;
+      /* Fall through.  */
+
+    case NEWER_MTIME_OPTION:
+      if (NEWER_OPTION_INITIALIZED (newer_mtime_option))
+	USAGE_ERROR ((0, 0, _("More than one threshold date")));
+      
+      if (FILESYSTEM_PREFIX_LEN (arg) != 0
+	  || ISSLASH (*arg)
+	  || *arg == '.')
+	{
+	  struct stat st;
+	  if (deref_stat (dereference_option, arg, &st) != 0)
+	    {
+	      stat_error (arg);
+	      USAGE_ERROR ((0, 0, _("Date file not found")));
+	    }
+	  newer_mtime_option.tv_sec = st.st_mtime;
+	  newer_mtime_option.tv_nsec = TIMESPEC_NS (st.st_mtim);
+	}
+      else
+	{
+	  if (! get_date (&newer_mtime_option, arg, NULL))
+	    {
+	      WARN ((0, 0, _("Substituting %s for unknown date format %s"),
+		     tartime (newer_mtime_option.tv_sec), quote (arg)));
+	      newer_mtime_option.tv_nsec = 0;
+	    }
+	  else
+	    args->textual_date_option = arg;
+	}
+      
+      break;
 #endif /* not MSDOS */
+      
+    case 'o':
+      args->o_option = true;
+      break;
+      
+    case 'O':
+      to_stdout_option = true;
+      break;
 
-      case 'o':
-	o_option = true;
-	break;
-
-      case 'O':
-	to_stdout_option = true;
-	break;
-
-      case 'p':
-	same_permissions_option = true;
-	break;
-
-      case 'P':
-	absolute_names_option = true;
-	break;
-
-      case 'r':
-	set_subcommand_option (APPEND_SUBCOMMAND);
-	break;
-
-      case 'R':
-	/* Print block numbers for debugging bad tar archives.  */
-
-	/* It would surely make sense to exchange -B and -R, but it seems
-	   that -B has been used for a long while in Sun tar ans most
-	   BSD-derived systems.  This is a consequence of the block/record
-	   terminology confusion.  */
-
-	block_number_option = true;
-	break;
-
-      case 's':
-	/* Names to extr are sorted.  */
+    case 'p':
+      same_permissions_option = true;
+      break;
+      
+    case 'P':
+      absolute_names_option = true;
+      break;
+      
+    case 'r':
+      set_subcommand_option (APPEND_SUBCOMMAND);
+      break;
+      
+    case 'R':
+      /* Print block numbers for debugging bad tar archives.  */
+      
+      /* It would surely make sense to exchange -B and -R, but it seems
+	 that -B has been used for a long while in Sun tar ans most
+	 BSD-derived systems.  This is a consequence of the block/record
+	 terminology confusion.  */
+      
+      block_number_option = true;
+      break;
+      
+    case 's':
+      /* Names to extr are sorted.  */
+      
+      same_order_option = true;
+      break;
+      
+    case 'S':
+      sparse_option = true;
+      break;
+      
+    case 't':
+      set_subcommand_option (LIST_SUBCOMMAND);
+      verbose_option++;
+      break;
 
-	same_order_option = true;
-	break;
+    case 'T':
+      files_from_option = arg;
+      break;
+      
+    case 'u':
+      set_subcommand_option (UPDATE_SUBCOMMAND);
+      break;
+      
+    case 'U':
+      old_files_option = UNLINK_FIRST_OLD_FILES;
+      break;
+      
+    case UTC_OPTION:
+      utc_option = true;
+      break;
+      
+    case 'v':
+      verbose_option++;
+      break;
+      
+    case 'V':
+      volume_label_option = arg;
+      break;
+      
+    case 'w':
+      interactive_option = true;
+      break;
+      
+    case 'W':
+      verify_option = true;
+      break;
+      
+    case 'x':
+      set_subcommand_option (EXTRACT_SUBCOMMAND);
+      break;
+      
+    case 'X':
+      if (add_exclude_file (add_exclude, excluded, arg,
+			    args->exclude_options | recursion_option, '\n')
+	  != 0)
+	{
+	  int e = errno;
+	  FATAL_ERROR ((0, e, "%s", quotearg_colon (arg)));
+	}
+      break;
+      
+    case 'y':
+      USAGE_ERROR ((0, 0,
+		    _("Warning: the -y option is not supported;"
+		      " perhaps you meant -j?")));
+      break;
+      
+    case 'z':
+      set_use_compress_program_option ("gzip");
+      break;
+      
+    case 'Z':
+      set_use_compress_program_option ("compress");
+      break;
+      
+    case ANCHORED_OPTION:
+      args->exclude_options |= EXCLUDE_ANCHORED;
+      break;
+      
+    case ATIME_PRESERVE_OPTION:
+      atime_preserve_option = true;
+      break;
+      
+    case CHECKPOINT_OPTION:
+      checkpoint_option = true;
+      break;
+      
+    case BACKUP_OPTION:
+      backup_option = true;
+      if (arg)
+	args->version_control_string = arg;
+      break;
+      
+    case DELETE_OPTION:
+      set_subcommand_option (DELETE_SUBCOMMAND);
+      break;
+      
+    case EXCLUDE_OPTION:
+      add_exclude (excluded, arg, args->exclude_options | recursion_option);
+      break;
+      
+    case FORCE_LOCAL_OPTION:
+      force_local_option = true;
+      break;
+      
+    case FORMAT_OPTION:
+      set_archive_format (arg);
+      break;
+      
+    case INDEX_FILE_OPTION:
+      index_file_name = arg;
+      break;
+      
+    case IGNORE_CASE_OPTION:
+      args->exclude_options |= FNM_CASEFOLD;
+      break;
+      
+    case IGNORE_FAILED_READ_OPTION:
+      ignore_failed_read_option = true;
+      break;
+      
+    case KEEP_NEWER_FILES_OPTION:
+      old_files_option = KEEP_NEWER_FILES;
+      break;
+      
+    case GROUP_OPTION:
+      if (! (strlen (arg) < GNAME_FIELD_SIZE
+	     && gname_to_gid (arg, &group_option)))
+	{
+	  uintmax_t g;
+	  if (xstrtoumax (arg, 0, 10, &g, "") == LONGINT_OK
+	      && g == (gid_t) g)
+	    group_option = g;
+	  else
+	    FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (arg),
+			  _("%s: Invalid group")));
+	}
+      break;
+      
+    case MODE_OPTION:
+      mode_option
+	= mode_compile (arg,
+			MODE_MASK_EQUALS | MODE_MASK_PLUS | MODE_MASK_MINUS);
+      if (mode_option == MODE_INVALID)
+	FATAL_ERROR ((0, 0, _("Invalid mode given on option")));
+      if (mode_option == MODE_MEMORY_EXHAUSTED)
+	xalloc_die ();
+      break;
+      
+    case NO_ANCHORED_OPTION:
+      args->exclude_options &= ~ EXCLUDE_ANCHORED;
+      break;
+      
+    case NO_IGNORE_CASE_OPTION:
+      args->exclude_options &= ~ FNM_CASEFOLD;
+      break;
+      
+    case NO_OVERWRITE_DIR_OPTION:
+      old_files_option = NO_OVERWRITE_DIR_OLD_FILES;
+      break;
+      
+    case NO_WILDCARDS_OPTION:
+      args->exclude_options &= ~ EXCLUDE_WILDCARDS;
+      break;
+      
+    case NO_WILDCARDS_MATCH_SLASH_OPTION:
+      args->exclude_options |= FNM_FILE_NAME;
+      break;
+      
+    case NULL_OPTION:
+      filename_terminator = '\0';
+      break;
+      
+    case NUMERIC_OWNER_OPTION:
+      numeric_owner_option = true;
+      break;
+      
+    case OCCURRENCE_OPTION:
+      if (!arg)
+	occurrence_option = 1;
+      else
+	{
+	  uintmax_t u;
+	  if (xstrtoumax (arg, 0, 10, &u, "") == LONGINT_OK)
+	    occurrence_option = u;
+	  else
+	    FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (arg),
+			  _("Invalid number")));
+	}
+      break;
+      
+    case OVERWRITE_OPTION:
+      old_files_option = OVERWRITE_OLD_FILES;
+      break;
 
-      case 'S':
-	sparse_option = true;
-	break;
+    case OWNER_OPTION:
+      if (! (strlen (arg) < UNAME_FIELD_SIZE
+	     && uname_to_uid (arg, &owner_option)))
+	{
+	  uintmax_t u;
+	  if (xstrtoumax (arg, 0, 10, &u, "") == LONGINT_OK
+	      && u == (uid_t) u)
+	    owner_option = u;
+	  else
+	    FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (arg),
+			  _("Invalid owner")));
+	}
+      break;
+      
+    case PAX_OPTION:
+      args->pax_option++;
+      xheader_set_option (arg);
+      break;
+      
+    case POSIX_OPTION:
+      set_archive_format ("posix");
+      break;
+      
+    case PRESERVE_OPTION:
+      same_permissions_option = true;
+      same_order_option = true;
+      break;
+      
+    case RECORD_SIZE_OPTION:
+      {
+	uintmax_t u;
+	if (! (xstrtoumax (arg, 0, 10, &u, "") == LONGINT_OK
+	       && u == (size_t) u))
+	  USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (arg),
+			_("Invalid record size")));
+	record_size = u;
+	if (record_size % BLOCKSIZE != 0)
+	  USAGE_ERROR ((0, 0, _("Record size must be a multiple of %d."),
+			BLOCKSIZE));
+	blocking_factor = record_size / BLOCKSIZE;
+      }
+      break;
+      
+    case RECURSIVE_UNLINK_OPTION:
+      recursive_unlink_option = true;
+      break;
+      
+    case REMOVE_FILES_OPTION:
+      remove_files_option = true;
+      break;
+      
+    case RMT_COMMAND_OPTION:
+      rmt_command_option = arg;
+      break;
+      
+    case RSH_COMMAND_OPTION:
+      rsh_command_option = arg;
+      break;
+      
+    case SHOW_DEFAULTS_OPTION:
+      show_default_settings (stdout);
+      exit(0);
+      
+    case STRIP_COMPONENTS_OPTION:
+      {
+	uintmax_t u;
+	if (! (xstrtoumax (arg, 0, 10, &u, "") == LONGINT_OK
+	       && u == (size_t) u))
+	  USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (arg),
+			_("Invalid number of elements")));
+	strip_name_components = u;
+      }
+      break;
 
-      case 't':
-	set_subcommand_option (LIST_SUBCOMMAND);
-	verbose_option++;
-	break;
+    case SHOW_OMITTED_DIRS_OPTION:
+      show_omitted_dirs_option = true;
+      break;
+      
+    case SUFFIX_OPTION:
+      backup_option = true;
+      args->backup_suffix_string = arg;
+      break;
+      
+    case TOTALS_OPTION:
+      totals_option = true;
+      break;
+      
+    case USE_COMPRESS_PROGRAM_OPTION:
+      set_use_compress_program_option (arg);
+      break;
+      
+    case VOLNO_FILE_OPTION:
+      volno_file_option = arg;
+      break;
+      
+    case WILDCARDS_OPTION:
+      args->exclude_options |= EXCLUDE_WILDCARDS;
+      break;
+      
+    case WILDCARDS_MATCH_SLASH_OPTION:
+      args->exclude_options &= ~ FNM_FILE_NAME;
+      break;
 
-      case 'T':
-	files_from_option = optarg;
-	break;
+    case CHECK_LINKS_OPTION:
+      check_links_option = 1;
+      break;
+      
+    case NO_RECURSION_OPTION:
+      recursion_option = 0;
+      break;
 
-      case 'u':
-	set_subcommand_option (UPDATE_SUBCOMMAND);
-	break;
+    case NO_SAME_OWNER_OPTION:
+      same_owner_option = -1;
+      break;
 
-      case 'U':
-	old_files_option = UNLINK_FIRST_OLD_FILES;
-	break;
+    case NO_SAME_PERMISSIONS_OPTION:
+      same_permissions_option = -1;
+      break;
 
-      case UTC_OPTION:
-	utc_option = true;
-	break;
+    case RECURSION_OPTION:
+      recursion_option = FNM_LEADING_DIR;
+      break;
 
-      case 'v':
-	verbose_option++;
-	break;
+    case SAME_OWNER_OPTION:
+      same_owner_option = 1;
+      break;
+      
+    case '0':
+    case '1':
+    case '2':
+    case '3':
+    case '4':
+    case '5':
+    case '6':
+    case '7':
 
-      case 'V':
-	volume_label_option = optarg;
-	break;
+#ifdef DEVICE_PREFIX
+      {
+	int device = key - '0';
+	int density;
+	static char buf[sizeof DEVICE_PREFIX + 10];
+	char *cursor;
 
-      case 'w':
-	interactive_option = true;
-	break;
+	if (arg[1])
+	  argp_error (state, _("Malformed density argument: '%s'"), arg);
+	
+	strcpy (buf, DEVICE_PREFIX);
+	cursor = buf + strlen (buf);
 
-      case 'W':
-	verify_option = true;
-	break;
+#ifdef DENSITY_LETTER
 
-      case 'x':
-	set_subcommand_option (EXTRACT_SUBCOMMAND);
-	break;
+	sprintf (cursor, "%d%c", device, arg[0]);
+	
+#else /* not DENSITY_LETTER */
 
-      case 'X':
-	if (add_exclude_file (add_exclude, excluded, optarg,
-			      exclude_options | recursion_option, '\n')
-	    != 0)
+	switch (arg[0])
 	  {
-	    int e = errno;
-	    FATAL_ERROR ((0, e, "%s", quotearg_colon (optarg)));
-	  }
-	break;
-
-      case 'y':
-	USAGE_ERROR ((0, 0,
-		      _("Warning: the -y option is not supported;"
-			" perhaps you meant -j?")));
-	break;
-
-      case 'z':
-	set_use_compress_program_option ("gzip");
-	break;
-
-      case 'Z':
-	set_use_compress_program_option ("compress");
-	break;
-
-      case ANCHORED_OPTION:
-	exclude_options |= EXCLUDE_ANCHORED;
-	break;
-
-      case ATIME_PRESERVE_OPTION:
-	atime_preserve_option = true;
-	break;
-
-      case CHECKPOINT_OPTION:
-	checkpoint_option = true;
-	break;
-
-      case BACKUP_OPTION:
-	backup_option = true;
-	if (optarg)
-	  version_control_string = optarg;
-	break;
-
-      case DELETE_OPTION:
-	set_subcommand_option (DELETE_SUBCOMMAND);
-	break;
-
-      case EXCLUDE_OPTION:
-	add_exclude (excluded, optarg, exclude_options | recursion_option);
-	break;
-
-      case FORCE_LOCAL_OPTION:
-	force_local_option = true;
-	break;
-
-      case FORMAT_OPTION:
-	set_archive_format (optarg);
-	break;
-
-      case INDEX_FILE_OPTION:
-	index_file_name = optarg;
-	break;
-
-      case IGNORE_CASE_OPTION:
-	exclude_options |= FNM_CASEFOLD;
-	break;
-
-      case IGNORE_FAILED_READ_OPTION:
-	ignore_failed_read_option = true;
-	break;
-
-      case KEEP_NEWER_FILES_OPTION:
-	old_files_option = KEEP_NEWER_FILES;
-	break;
+	  case 'l':
+#ifdef LOW_NUM
+	    device += LOW_NUM;
+#endif
+	    break;
+	    
+	  case 'm':
+#ifdef MID_NUM
+	    device += MID_NUM;
+#else
+	    device += 8;
+#endif
+	    break;
+	    
+	  case 'h':
+#ifdef HGH_NUM
+	    device += HGH_NUM;
+#else
+	    device += 16;
+#endif
+	    break;
 
-      case GROUP_OPTION:
-	if (! (strlen (optarg) < GNAME_FIELD_SIZE
-	       && gname_to_gid (optarg, &group_option)))
-	  {
-	    uintmax_t g;
-	    if (xstrtoumax (optarg, 0, 10, &g, "") == LONGINT_OK
-		&& g == (gid_t) g)
-	      group_option = g;
-	    else
-	      FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
-			    _("%s: Invalid group")));
+	  default:
+	    argp_error (state, _("Unknown density: '%c'"), arg[0]);
 	  }
-	break;
-
-      case MODE_OPTION:
-	mode_option
-	  = mode_compile (optarg,
-			  MODE_MASK_EQUALS | MODE_MASK_PLUS | MODE_MASK_MINUS);
-	if (mode_option == MODE_INVALID)
-	  FATAL_ERROR ((0, 0, _("Invalid mode given on option")));
-	if (mode_option == MODE_MEMORY_EXHAUSTED)
-	  xalloc_die ();
-	break;
-
-      case NO_ANCHORED_OPTION:
-	exclude_options &= ~ EXCLUDE_ANCHORED;
-	break;
-
-      case NO_IGNORE_CASE_OPTION:
-	exclude_options &= ~ FNM_CASEFOLD;
-	break;
-
-      case NO_OVERWRITE_DIR_OPTION:
-	old_files_option = NO_OVERWRITE_DIR_OLD_FILES;
-	break;
-
-      case NO_WILDCARDS_OPTION:
-	exclude_options &= ~ EXCLUDE_WILDCARDS;
-	break;
-
-      case NO_WILDCARDS_MATCH_SLASH_OPTION:
-	exclude_options |= FNM_FILE_NAME;
-	break;
-
-      case NULL_OPTION:
-	filename_terminator = '\0';
-	break;
-
-      case NUMERIC_OWNER_OPTION:
-	numeric_owner_option = true;
-	break;
+	sprintf (cursor, "%d", device);
+	
+#endif /* not DENSITY_LETTER */
 
-      case OCCURRENCE_OPTION:
-	if (!optarg)
-	  occurrence_option = 1;
-	else
+	if (archive_names == allocated_archive_names)
 	  {
-	    uintmax_t u;
-	    if (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK)
-	      occurrence_option = u;
-	    else
-	      FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
-			    _("Invalid number")));
+	    allocated_archive_names *= 2;
+	    archive_name_array =
+	      xrealloc (archive_name_array,
+			sizeof (const char *) * allocated_archive_names);
 	  }
-	break;
-
-      case OVERWRITE_OPTION:
-	old_files_option = OVERWRITE_OLD_FILES;
-	break;
+	archive_name_array[archive_names++] = strdup (buf);
+      }
+      break;
 
-      case OWNER_OPTION:
-	if (! (strlen (optarg) < UNAME_FIELD_SIZE
-	       && uname_to_uid (optarg, &owner_option)))
-	  {
-	    uintmax_t u;
-	    if (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK
-		&& u == (uid_t) u)
-	      owner_option = u;
-	    else
-	      FATAL_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
-			    _("Invalid owner")));
-	  }
-	break;
+#else /* not DEVICE_PREFIX */
 
-      case PAX_OPTION:
-	pax_option++;
-	xheader_set_option (optarg);
-	break;
+      argp_error (state, 
+		  _("Options `-[0-7][lmh]' not supported by *this* tar"));
+      
+#endif /* not DEVICE_PREFIX */
+      
+    case '?':
+      state->flags |= ARGP_NO_EXIT;
+      argp_state_help (state, state->out_stream,
+		       ARGP_HELP_STD_HELP & ~ARGP_HELP_BUG_ADDR);
+      fprintf (state->out_stream, _("\n*This* tar defaults to:\n"));
+      show_default_settings (state->out_stream);
+      fprintf (state->out_stream, "\n");
+      fprintf (state->out_stream, _("Report bugs to %s.\n"), 
+	       argp_program_bug_address);
+      exit (0);
+
+    case USAGE_OPTION:
+      argp_state_help (state, state->out_stream,
+		       ARGP_HELP_USAGE | ARGP_HELP_EXIT_OK);
+      break;
 
-      case POSIX_OPTION:
-	set_archive_format ("posix");
-	break;
+    case VERSION_OPTION:
+      fprintf (state->out_stream, "%s\n", argp_program_version);
+      exit (0);
 
-      case PRESERVE_OPTION:
-	same_permissions_option = true;
-	same_order_option = true;
-	break;
+    case LICENSE_OPTION:
+      license ();
+      break;
 
-      case RECORD_SIZE_OPTION:
-	{
-	  uintmax_t u;
-	  if (! (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK
-		 && u == (size_t) u))
-	    USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
-			  _("Invalid record size")));
-	  record_size = u;
-	  if (record_size % BLOCKSIZE != 0)
-	    USAGE_ERROR ((0, 0, _("Record size must be a multiple of %d."),
-			  BLOCKSIZE));
-	  blocking_factor = record_size / BLOCKSIZE;
-	}
-	break;
+    default:
+      return ARGP_ERR_UNKNOWN;
+    }
+  return 0;
+}
 
-      case RECURSIVE_UNLINK_OPTION:
-	recursive_unlink_option = true;
-	break;
+static struct argp argp = {
+  options,
+  parse_opt,
+  N_("[FILE]..."),
+  doc,
+  NULL,
+  NULL,
+  NULL
+};
 
-      case REMOVE_FILES_OPTION:
-	remove_files_option = true;
-	break;
+void
+usage (int status)
+{
+  argp_help (&argp, stderr, ARGP_HELP_SEE, program_name);
+  exit (status);
+}
 
-      case RMT_COMMAND_OPTION:
-	rmt_command_option = optarg;
-	break;
-	
-      case RSH_COMMAND_OPTION:
-	rsh_command_option = optarg;
-	break;
+/* Parse the options for tar.  */
 
-      case SHOW_DEFAULTS_OPTION:
-	printf ("--format=%s -f%s -b%d\n",
-		archive_format_string (DEFAULT_ARCHIVE_FORMAT),
-		DEFAULT_ARCHIVE, DEFAULT_BLOCKING);
-	exit(0);
+static struct argp_option *
+find_argp_option (struct argp_option *options, int letter)
+{
+  for (;
+       !(options->name == NULL
+	 && options->key == 0
+	 && options->arg == 0
+	 && options->flags
+	 && options->doc == NULL); options++)
+    if (options->key == letter)
+      return options;
+  return NULL;
+}
 
-      case STRIP_COMPONENTS_OPTION:
-	{
-	  uintmax_t u;
-	  if (! (xstrtoumax (optarg, 0, 10, &u, "") == LONGINT_OK
-		 && u == (size_t) u))
-	    USAGE_ERROR ((0, 0, "%s: %s", quotearg_colon (optarg),
-			  _("Invalid number of elements")));
-	  strip_name_components = u;
-	}
-	break;
+/* FIXME:
 
-      case SUFFIX_OPTION:
-	backup_option = true;
-	backup_suffix_string = optarg;
-	break;
+   Available option letters are DEHIJQY and aenqy.  Some are reserved:
 
-      case TOTALS_OPTION:
-	totals_option = true;
-	break;
+   e  exit immediately with a nonzero exit status if unexpected errors occur
+   E  use extended headers (draft POSIX headers, that is)
+   I  same as T (for compatibility with Solaris tar)
+   n  the archive is quickly seekable, so don't worry about random seeks
+   q  stop after extracting the first occurrence of the named file
+   y  per-file gzip compression
+   Y  per-block gzip compression */
 
-      case USE_COMPRESS_PROGRAM_OPTION:
-	set_use_compress_program_option (optarg);
-	break;
+static void
+decode_options (int argc, char **argv)
+{
+  int optchar;			/* option letter */
+  int index;
+  struct tar_args args;
+  
+  /* Set some default option values.  */
+  args.textual_date_option = NULL;
+  args.exclude_options = EXCLUDE_WILDCARDS;
+  args.o_option = 0;
+  args.pax_option = 0;
+  args.backup_suffix_string = getenv ("SIMPLE_BACKUP_SUFFIX");
+  args.version_control_string = 0;
+  args.input_files = 0;
+  
 
-      case VOLNO_FILE_OPTION:
-	volno_file_option = optarg;
-	break;
+  subcommand_option = UNKNOWN_SUBCOMMAND;
+  archive_format = DEFAULT_FORMAT;
+  blocking_factor = DEFAULT_BLOCKING;
+  record_size = DEFAULT_BLOCKING * BLOCKSIZE;
+  excluded = new_exclude ();
+  newer_mtime_option.tv_sec = TYPE_MINIMUM (time_t);
+  newer_mtime_option.tv_nsec = -1;
+  recursion_option = FNM_LEADING_DIR;
 
-      case WILDCARDS_OPTION:
-	exclude_options |= EXCLUDE_WILDCARDS;
-	break;
+  owner_option = -1;
+  group_option = -1;
 
-      case WILDCARDS_MATCH_SLASH_OPTION:
-	exclude_options &= ~ FNM_FILE_NAME;
-	break;
+  /* Convert old-style tar call by exploding option element and rearranging
+     options accordingly.  */
 
-      case '0':
-      case '1':
-      case '2':
-      case '3':
-      case '4':
-      case '5':
-      case '6':
-      case '7':
+  if (argc > 1 && argv[1][0] != '-')
+    {
+      int new_argc;		/* argc value for rearranged arguments */
+      char **new_argv;		/* argv value for rearranged arguments */
+      char *const *in;		/* cursor into original argv */
+      char **out;		/* cursor into rearranged argv */
+      const char *letter;	/* cursor into old option letters */
+      char buffer[3];		/* constructed option buffer */
 
-#ifdef DEVICE_PREFIX
-	{
-	  int device = optchar - '0';
-	  int density;
-	  static char buf[sizeof DEVICE_PREFIX + 10];
-	  char *cursor;
+      /* Initialize a constructed option.  */
 
-	  density = getopt_long (argc, argv, "lmh", 0, 0);
-	  strcpy (buf, DEVICE_PREFIX);
-	  cursor = buf + strlen (buf);
+      buffer[0] = '-';
+      buffer[2] = '\0';
 
-#ifdef DENSITY_LETTER
+      /* Allocate a new argument array, and copy program name in it.  */
 
-	  sprintf (cursor, "%d%c", device, density);
+      new_argc = argc - 1 + strlen (argv[1]);
+      new_argv = xmalloc ((new_argc + 1) * sizeof (char *));
+      in = argv;
+      out = new_argv;
+      *out++ = *in++;
 
-#else /* not DENSITY_LETTER */
+      /* Copy each old letter option as a separate option, and have the
+	 corresponding argument moved next to it.  */
 
-	  switch (density)
+      for (letter = *in++; *letter; letter++)
+	{
+	  struct argp_option *opt;
+	  
+	  buffer[1] = *letter;
+	  *out++ = xstrdup (buffer);
+	  opt = find_argp_option (options, *letter);
+	  if (opt && opt->arg)
 	    {
-	    case 'l':
-#ifdef LOW_NUM
-	      device += LOW_NUM;
-#endif
-	      break;
-
-	    case 'm':
-#ifdef MID_NUM
-	      device += MID_NUM;
-#else
-	      device += 8;
-#endif
-	      break;
+	      if (in < argv + argc)
+		*out++ = *in++;
+	      else
+		USAGE_ERROR ((0, 0, _("Old option `%c' requires an argument."),
+			      *letter));
+	    }
+	}
 
-	    case 'h':
-#ifdef HGH_NUM
-	      device += HGH_NUM;
-#else
-	      device += 16;
-#endif
-	      break;
+      /* Copy all remaining options.  */
 
-	    default:
-	      usage (TAREXIT_FAILURE);
-	    }
-	  sprintf (cursor, "%d", device);
+      while (in < argv + argc)
+	*out++ = *in++;
+      *out = 0;
 
-#endif /* not DENSITY_LETTER */
+      /* Replace the old option list by the new one.  */
 
-	  if (archive_names == allocated_archive_names)
-	    {
-	      allocated_archive_names *= 2;
-	      archive_name_array =
-		xrealloc (archive_name_array,
-			  sizeof (const char *) * allocated_archive_names);
-	    }
-	  archive_name_array[archive_names++] = strdup (buf);
-	}
-	break;
+      argc = new_argc;
+      argv = new_argv;
+    }
 
-#else /* not DEVICE_PREFIX */
+  /* Parse all options and non-options as they appear.  */
 
-	USAGE_ERROR ((0, 0,
-		      _("Options `-[0-7][lmh]' not supported by *this* tar")));
+  prepend_default_options (getenv ("TAR_OPTIONS"), &argc, &argv);
 
-#endif /* not DEVICE_PREFIX */
-      }
+  if (argp_parse (&argp, argc, argv, ARGP_IN_ORDER|ARGP_NO_HELP,
+		  &index, &args))
+    exit (1); /* FIXME */
+      
 
   /* Special handling for 'o' option:
 
