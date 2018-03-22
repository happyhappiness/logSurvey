-/* Tar -- a tape archiver.
-   Copyright (C) 1988, 1992, 1993 Free Software Foundation
-
-This file is part of GNU Tar.
-
-GNU Tar is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
-
-GNU Tar is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
-
-You should have received a copy of the GNU General Public License
-along with GNU Tar; see the file COPYING.  If not, write to
-the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
-
-/*
- * A tar (tape archiver) program.
- *
- * Written by John Gilmore, ihnp4!hoptoad!gnu, starting 25 Aug 85.
- */
-
-#include <stdio.h>
-#include <sys/types.h>		/* Needed for typedefs in tar.h */
-#include "getopt.h"
-#include "regex.h"
-
-/*
- * The following causes "tar.h" to produce definitions of all the
- * global variables, rather than just "extern" declarations of them.
- */
-#define TAR_EXTERN		/**/
-#include "tar.h"
-
-#include "port.h"
-#include "fnmatch.h"
-
-/*
- * We should use a conversion routine that does reasonable error
- * checking -- atoi doesn't.  For now, punt.  FIXME.
- */
-#define intconv	atoi
-PTR ck_malloc ();
-PTR ck_realloc ();
-extern int getoldopt ();
-extern void read_and ();
-extern void list_archive ();
-extern void extract_archive ();
-extern void diff_archive ();
-extern void create_archive ();
-extern void update_archive ();
-extern void junk_archive ();
-extern void init_volume_number ();
-extern void closeout_volume_number ();
-
-/* JF */
-extern time_t get_date ();
-
-time_t new_time;
-
-static FILE *namef;		/* File to read names from */
-static char **n_argv;		/* Argv used by name routines */
-static int n_argc;		/* Argc used by name routines */
-static char **n_ind;		/* Store an array of names */
-static int n_indalloc;		/* How big is the array? */
-static int n_indused;		/* How many entries does it have? */
-static int n_indscan;		/* How many of the entries have we scanned? */
-
-
-extern FILE *msg_file;
-
-int check_exclude ();
-void add_exclude ();
-void add_exclude_file ();
-void addname ();
-void describe ();
-void diff_init ();
-void extr_init ();
-int is_regex ();
-void name_add ();
-void name_init ();
-void options ();
-char *un_quote_string ();
-
-#ifndef S_ISLNK
-#define lstat stat
-#endif
+/* A tar (tape archiver) program.
+   Copyright (C) 1988, 92, 93, 94, 95, 96, 97 Free Software Foundation, Inc.
+   Written by John Gilmore, starting 1985-08-25.
 
-#ifndef DEFBLOCKING
-#define DEFBLOCKING 20
-#endif
+   This program is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by the
+   Free Software Foundation; either version 2, or (at your option) any later
+   version.
 
-#ifndef DEF_AR_FILE
-#define DEF_AR_FILE "tar.out"
-#endif
+   This program is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
+   Public License for more details.
 
-/* For long options that unconditionally set a single flag, we have getopt
-   do it.  For the others, we share the code for the equivalent short
-   named option, the name of which is stored in the otherwise-unused `val'
-   field of the `struct option'; for long options that have no equivalent
-   short option, we use nongraphic characters as pseudo short option
-   characters, starting (for no particular reason) with character 10. */
+   You should have received a copy of the GNU General Public License along
+   with this program; if not, write to the Free Software Foundation, Inc.,
+   59 Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
-struct option long_options[] =
-{
-  {"create", 0, 0, 'c'},
-  {"append", 0, 0, 'r'},
-  {"extract", 0, 0, 'x'},
-  {"get", 0, 0, 'x'},
-  {"list", 0, 0, 't'},
-  {"update", 0, 0, 'u'},
-  {"catenate", 0, 0, 'A'},
-  {"concatenate", 0, 0, 'A'},
-  {"compare", 0, 0, 'd'},
-  {"diff", 0, 0, 'd'},
-  {"delete", 0, 0, 14},
-  {"help", 0, 0, 12},
-
-  {"null", 0, 0, 16},
-  {"directory", 1, 0, 'C'},
-  {"record-number", 0, &f_sayblock, 1},
-  {"files-from", 1, 0, 'T'},
-  {"label", 1, 0, 'V'},
-  {"exclude-from", 1, 0, 'X'},
-  {"exclude", 1, 0, 15},
-  {"file", 1, 0, 'f'},
-  {"block-size", 1, 0, 'b'},
-  {"version", 0, 0, 11},
-  {"verbose", 0, 0, 'v'},
-  {"totals", 0, &f_totals, 1},
-
-  {"read-full-blocks", 0, &f_reblock, 1},
-  {"starting-file", 1, 0, 'K'},
-  {"to-stdout", 0, &f_exstdout, 1},
-  {"ignore-zeros", 0, &f_ignorez, 1},
-  {"keep-old-files", 0, 0, 'k'},
-  {"same-permissions", 0, &f_use_protection, 1},
-  {"preserve-permissions", 0, &f_use_protection, 1},
-  {"modification-time", 0, &f_modified, 1},
-  {"preserve", 0, 0, 10},
-  {"same-order", 0, &f_sorted_names, 1},
-  {"same-owner", 0, &f_do_chown, 1},
-  {"preserve-order", 0, &f_sorted_names, 1},
-
-  {"newer", 1, 0, 'N'},
-  {"after-date", 1, 0, 'N'},
-  {"newer-mtime", 1, 0, 13},
-  {"incremental", 0, 0, 'G'},
-  {"listed-incremental", 1, 0, 'g'},
-  {"multi-volume", 0, &f_multivol, 1},
-  {"info-script", 1, 0, 'F'},
-  {"new-volume-script", 1, 0, 'F'},
-  {"absolute-paths", 0, &f_absolute_paths, 1},
-  {"interactive", 0, &f_confirm, 1},
-  {"confirmation", 0, &f_confirm, 1},
-
-  {"verify", 0, &f_verify, 1},
-  {"dereference", 0, &f_follow_links, 1},
-  {"one-file-system", 0, &f_local_filesys, 1},
-  {"old-archive", 0, 0, 'o'},
-  {"portability", 0, 0, 'o'},
-  {"compress", 0, 0, 'Z'},
-  {"uncompress", 0, 0, 'Z'},
-  {"block-compress", 0, &f_compress_block, 1},
-  {"gzip", 0, 0, 'z'},
-  {"ungzip", 0, 0, 'z'},
-  {"use-compress-program", 1, 0, 18},
-    
-
-  {"same-permissions", 0, &f_use_protection, 1},
-  {"sparse", 0, &f_sparse_files, 1},
-  {"tape-length", 1, 0, 'L'},
-  {"remove-files", 0, &f_remove_files, 1},
-  {"ignore-failed-read", 0, &f_ignore_failed_read, 1},
-  {"checkpoint", 0, &f_checkpoint, 1},
-  {"show-omitted-dirs", 0, &f_show_omitted_dirs, 1},
-  {"volno-file", 1, 0, 17},
-  {"force-local", 0, &f_force_local, 1},
-  {"atime-preserve", 0, &f_atime_preserve, 1},
+#include "system.h"
 
-  {0, 0, 0, 0}
-};
-
-/*
- * Main routine for tar.
- */
-void
-main (argc, argv)
-     int argc;
-     char **argv;
-{
-  extern char version_string[];
-
-  tar = argv[0];		/* JF: was "tar" Set program name */
-  filename_terminator = '\n';
-  errors = 0;
+#include <getopt.h>
 
-  options (argc, argv);
+/* The following causes "common.h" to produce definitions of all the global
+   variables, rather than just "extern" declarations of them.  GNU tar does
+   depend on the system loader to preset all GLOBAL variables to neutral (or
+   zero) values, explicit initialisation is usually not done.  */
+#define GLOBAL
+#include "common.h"
 
-  if (!n_argv)
-    name_init (argc, argv);
+#include "backupfile.h"
+enum backup_type get_version ();
 
-  if (f_volno_file)
-    init_volume_number ();
-
-  switch (cmd_mode)
-    {
-    case CMD_CAT:
-    case CMD_UPDATE:
-    case CMD_APPEND:
-      update_archive ();
-      break;
-    case CMD_DELETE:
-      junk_archive ();
-      break;
-    case CMD_CREATE:
-      create_archive ();
-      if (f_totals)
-	fprintf (stderr, "Total bytes written: %d\n", tot_written);
-      break;
-    case CMD_EXTRACT:
-      if (f_volhdr)
-	{
-	  const char *err;
-	  label_pattern = (struct re_pattern_buffer *)
-	    ck_malloc (sizeof *label_pattern);
-	  err = re_compile_pattern (f_volhdr, strlen (f_volhdr),
-				    label_pattern);
-	  if (err)
-	    {
-	      fprintf (stderr, "Bad regular expression: %s\n",
-		       err);
-	      errors++;
-	      break;
-	    }
-
-	}
-      extr_init ();
-      read_and (extract_archive);
-      break;
-    case CMD_LIST:
-      if (f_volhdr)
-	{
-	  const char *err;
-	  label_pattern = (struct re_pattern_buffer *)
-	    ck_malloc (sizeof *label_pattern);
-	  err = re_compile_pattern (f_volhdr, strlen (f_volhdr),
-				    label_pattern);
-	  if (err)
-	    {
-	      fprintf (stderr, "Bad regular expression: %s\n",
-		       err);
-	      errors++;
-	      break;
-	    }
-	}
-      read_and (list_archive);
-#if 0
-      if (!errors)
-	errors = different;
-#endif
-      break;
-    case CMD_DIFF:
-      diff_init ();
-      read_and (diff_archive);
-      break;
-    case CMD_VERSION:
-      fprintf (stderr, "%s\n", version_string);
-      break;
-    case CMD_NONE:
-      msg ("you must specify exactly one of the r, c, t, x, or d options\n");
-      fprintf (stderr, "For more information, type ``%s --help''.\n", tar);
-      exit (EX_ARGSBAD);
-    }
-  if (f_volno_file)
-    closeout_volume_number ();
-  exit (errors);
-  /* NOTREACHED */
-}
+/* FIXME: We should use a conversion routine that does reasonable error
+   checking -- atoi doesn't.  For now, punt.  */
+#define intconv	atoi
 
+time_t get_date ();
 
-/*
- * Parse the options for tar.
- */
-void
-options (argc, argv)
-     int argc;
-     char **argv;
-{
-  register int c;		/* Option letter */
-  int ind = -1;
-
-  /* Set default option values */
-  blocking = DEFBLOCKING;	/* From Makefile */
-  ar_files = (char **) ck_malloc (sizeof (char *) * 10);
-  ar_files_len = 10;
-  n_ar_files = 0;
-  cur_ar_file = 0;
-
-  /* Parse options */
-  while ((c = getoldopt (argc, argv,
-	       "-01234567Ab:BcC:df:F:g:GhikK:lL:mMN:oOpPrRsStT:uvV:wWxX:zZ",
-			 long_options, &ind)) != EOF)
-    {
-      switch (c)
-	{
-	case 0:		/* long options that set a single flag */
-	  break;
-	case 1:
-	  /* File name or non-parsed option */
-	  name_add (optarg);
-	  break;
-	case 'C':
-	  name_add ("-C");
-	  name_add (optarg);
-	  break;
-	case 10:		/* preserve */
-	  f_use_protection = f_sorted_names = 1;
-	  break;
-	case 11:
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_VERSION;
-	  break;
-	case 12:		/* help */
-	  printf ("This is GNU tar, the tape archiving program.\n");
-	  describe ();
-	  exit (1);
-	case 13:
-	  f_new_files++;
-	  goto get_newer;
-
-	case 14:		/* Delete in the archive */
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_DELETE;
-	  break;
-
-	case 15:
-	  f_exclude++;
-	  add_exclude (optarg);
-	  break;
-
-	case 16:		/* -T reads null terminated filenames. */
-	  filename_terminator = '\0';
-	  break;
-
-	case 17:
-	  f_volno_file = optarg;
-	  break;
-
-	case 18:
-	  if (f_compressprog)
-	    {
-	      msg ("Only one compression option permitted\n");
-	      exit (EX_ARGSBAD);
-	    }
-	  f_compressprog = optarg;
-	  break;
-
-	case 'g':		/* We are making a GNU dump; save
-				   directories at the beginning of
-				   the archive, and include in each
-				   directory its contents */
-	  if (f_oldarch)
-	    goto badopt;
-	  f_gnudump++;
-	  gnu_dumpfile = optarg;
-	  break;
-
-
-	case '0':
-	case '1':
-	case '2':
-	case '3':
-	case '4':
-	case '5':
-	case '6':
-	case '7':
-	  {
-	    /* JF this'll have to be modified for other
-				   systems, of course! */
-	    int d, add;
-	    static char buf[50];
-
-	    d = getoldopt (argc, argv, "lmh");
-#ifdef MAYBEDEF
-	    sprintf (buf, "/dev/rmt/%d%c", c, d);
-#else
-#ifndef LOW_NUM
-#define LOW_NUM 0
-#define MID_NUM 8
-#define HGH_NUM 16
-#endif
-	    if (d == 'l')
-	      add = LOW_NUM;
-	    else if (d == 'm')
-	      add = MID_NUM;
-	    else if (d == 'h')
-	      add = HGH_NUM;
-	    else
-	      goto badopt;
+/* Local declarations.  */
 
-	    sprintf (buf, "/dev/rmt%d", add + c - '0');
-#endif
-	    if (n_ar_files == ar_files_len)
-	      ar_files
-		= (char **)
-		ck_malloc (sizeof (char *)
-			   * (ar_files_len *= 2));
-	    ar_files[n_ar_files++] = buf;
-	  }
-	  break;
-
-	case 'A':		/* Arguments are tar files,
-				   just cat them onto the end
-				   of the archive.  */
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_CAT;
-	  break;
-
-	case 'b':		/* Set blocking factor */
-	  blocking = intconv (optarg);
-	  break;
-
-	case 'B':		/* Try to reblock input */
-	  f_reblock++;		/* For reading 4.2BSD pipes */
-	  break;
-
-	case 'c':		/* Create an archive */
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_CREATE;
-	  break;
-
-#if 0
-	case 'C':
-	  if (chdir (optarg) < 0)
-	    msg_perror ("Can't change directory to %d", optarg);
-	  break;
+#ifndef DEFAULT_ARCHIVE
+# define DEFAULT_ARCHIVE "tar.out"
 #endif
 
-	case 'd':		/* Find difference tape/disk */
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_DIFF;
-	  break;
-
-	case 'f':		/* Use ar_file for the archive */
-	  if (n_ar_files == ar_files_len)
-	    ar_files
-	      = (char **) ck_malloc (sizeof (char *)
-				     * (ar_files_len *= 2));
-
-	  ar_files[n_ar_files++] = optarg;
-	  break;
-
-	case 'F':
-	  /* Since -F is only useful with -M , make it implied */
-	  f_run_script_at_end++;/* run this script at the end */
-	  info_script = optarg;	/* of each tape */
-	  f_multivol++;
-	  break;
-
-	case 'G':		/* We are making a GNU dump; save
-				   directories at the beginning of
-				   the archive, and include in each
-				   directory its contents */
-	  if (f_oldarch)
-	    goto badopt;
-	  f_gnudump++;
-	  gnu_dumpfile = 0;
-	  break;
-
-	case 'h':
-	  f_follow_links++;	/* follow symbolic links */
-	  break;
-
-	case 'i':
-	  f_ignorez++;		/* Ignore zero records (eofs) */
-	  /*
-			 * This can't be the default, because Unix tar
-			 * writes two records of zeros, then pads out the
-			 * block with garbage.
-			 */
-	  break;
-
-	case 'k':		/* Don't overwrite files */
-#ifdef NO_OPEN3
-	  msg ("can't keep old files on this system");
-	  exit (EX_ARGSBAD);
-#else
-	  f_keep++;
+#ifndef DEFAULT_BLOCKING
+# define DEFAULT_BLOCKING 20
 #endif
-	  break;
-
-	case 'K':
-	  f_startfile++;
-	  addname (optarg);
-	  break;
-
-	case 'l':		/* When dumping directories, don't
-				   dump files/subdirectories that are
-				   on other filesystems. */
-	  f_local_filesys++;
-	  break;
-
-	case 'L':
-	  tape_length = intconv (optarg);
-	  f_multivol++;
-	  break;
-	case 'm':
-	  f_modified++;
-	  break;
-
-	case 'M':		/* Make Multivolume archive:
-				   When we can't write any more
-				   into the archive, re-open it,
-				   and continue writing */
-	  f_multivol++;
-	  break;
-
-	case 'N':		/* Only write files newer than X */
-	get_newer:
-	  f_new_files++;
-	  new_time = get_date (optarg, (PTR) 0);
-	  if (new_time == (time_t) - 1)
-	    {
-	      msg ("invalid date format `%s'", optarg);
-	      exit (EX_ARGSBAD);
-	    }
-	  break;
-
-	case 'o':		/* Generate old archive */
-	  if (f_gnudump /* || f_dironly */ )
-	    goto badopt;
-	  f_oldarch++;
-	  break;
-
-	case 'O':
-	  f_exstdout++;
-	  break;
-
-	case 'p':
-	  f_use_protection++;
-	  break;
-
-	case 'P':
-	  f_absolute_paths++;
-	  break;
-
-	case 'r':		/* Append files to the archive */
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_APPEND;
-	  break;
-
-	case 'R':
-	  f_sayblock++;		/* Print block #s for debug */
-	  break;		/* of bad tar archives */
-
-	case 's':
-	  f_sorted_names++;	/* Names to extr are sorted */
-	  break;
-
-	case 'S':		/* deal with sparse files */
-	  f_sparse_files++;
-	  break;
-	case 't':
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_LIST;
-	  f_verbose++;		/* "t" output == "cv" or "xv" */
-	  break;
-
-	case 'T':
-	  name_file = optarg;
-	  f_namefile++;
-	  break;
-
-	case 'u':		/* Append files to the archive that
-				   aren't there, or are newer than the
-				   copy in the archive */
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_UPDATE;
-	  break;
-
-	case 'v':
-	  f_verbose++;
-	  break;
-
-	case 'V':
-	  f_volhdr = optarg;
-	  break;
-
-	case 'w':
-	  f_confirm++;
-	  break;
-
-	case 'W':
-	  f_verify++;
-	  break;
-
-	case 'x':		/* Extract files from the archive */
-	  if (cmd_mode != CMD_NONE)
-	    goto badopt;
-	  cmd_mode = CMD_EXTRACT;
-	  break;
-
-	case 'X':
-	  f_exclude++;
-	  add_exclude_file (optarg);
-	  break;
-
-	case 'z':
-	  if (f_compressprog)
-	    {
-	      msg ("Only one compression option permitted\n");
-	      exit (EX_ARGSBAD);
-	    }
-	  f_compressprog = "gzip";
-	  break;
-
-	case 'Z':
-	  if (f_compressprog)
-	    {
-	      msg ("Only one compression option permitted\n");
-	      exit (EX_ARGSBAD);
-	    }
-	  f_compressprog = "compress";
-	  break;
 
-	case '?':
-	badopt:
-	  msg ("Unknown option.  Use '%s --help' for a complete list of options.", tar);
-	  exit (EX_ARGSBAD);
+static void usage PARAMS ((int));
+
+/* Miscellaneous.  */
 
-	}
-    }
+/*------------------------------------------------------------------------.
+| Check if STRING is the decimal representation of number, and return its |
+| value.  If not a decimal number, return -1.				  |
+`------------------------------------------------------------------------*/
 
-  blocksize = blocking * RECORDSIZE;
-  if (n_ar_files == 0)
-    {
-      n_ar_files = 1;
-      ar_files[0] = getenv ("TAPE");	/* From environment, or */
-      if (ar_files[0] == 0)
-	ar_files[0] = DEF_AR_FILE;	/* From Makefile */
-    }
-  if (n_ar_files > 1 && !f_multivol)
-    {
-      msg ("Multiple archive files requires --multi-volume\n");
-      exit (EX_ARGSBAD);
-    }
-  if (f_compress_block && !f_compressprog)
-    {
-      msg ("You must use a compression option (--gzip, --compress\n\
-or --use-compress-program) with --block-compress.\n");
-      exit (EX_ARGSBAD);
-    }
+static int
+check_decimal (const char *string)
+{
+  int value = -1;
+
+  while (*string)
+    switch (*string)
+      {
+      case '0':
+      case '1':
+      case '2':
+      case '3':
+      case '4':
+      case '5':
+      case '6':
+      case '7':
+      case '8':
+      case '9':
+	value = value < 0 ? *string - '0' : 10 * value + *string - '0';
+	string++;
+	break;
+
+      default:
+	return -1;
+      }
+    return value;
 }
 
+/*----------------------------------------------.
+| Doesn't return if stdin already requested.    |
+`----------------------------------------------*/
 
-/*
- * Print as much help as the user's gonna get.
- *
- * We have to sprinkle in the KLUDGE lines because too many compilers
- * cannot handle character strings longer than about 512 bytes.  Yuk!
- * In particular, MS-DOS and Xenix MSC and PDP-11 V7 Unix have this
- * problem.
- */
-void
-describe ()
-{
-  puts ("choose one of the following:");
-  fputs ("\
-    --concatenate	append tar files to an archive\n\
-    --compare		find differences between archive and file system\n\
-    --get		extract files from an archive\n", stdout);
-
-  fprintf (stdout, "\
-Other options:\n\
-  fputs ("\
-", stdout);			/* KLUDGE */
-  fprintf (stdout, "\
-	   DEF_AR_FILE);
-  fputs ("\
-    --new-volume-script F run script at end of each tape (implies -M)\n\
-", stdout);			/* KLUDGE */
-  fputs ("\
-    --newer DATE	only store files newer than DATE\n\
-    --portability	write a V7 format archive, rather than ANSI format\n\
-    --preserve-permissions extract all protection information\n\
-", stdout);			/* KLUDGE */
-  fputs ("\
-    --preserve-order	list of names to extract is sorted to match archive\n\
-    --confirmation	ask for confirmation for every action\n\
-", stdout);			/* KLUDGE */
-  fputs ("\
-    --uncompress      	filter the archive through compress\n\
-    --ungzip		filter the archive through gzip\n\
-			filter the archive through PROG (which must accept -d)\n\
-", stdout);
-}
+/* Name of option using stdin.  */
+static const char *stdin_used_by = NULL;
 
 void
-name_add (name)
-     char *name;
+request_stdin (const char *option)
 {
-  if (n_indalloc == n_indused)
-    {
-      n_indalloc += 10;
-      n_ind = (char **) (n_indused ? ck_realloc (n_ind, n_indalloc * sizeof (char *)): ck_malloc (n_indalloc * sizeof (char *)));
-    }
-  n_ind[n_indused++] = name;
+  if (stdin_used_by)
+    USAGE_ERROR ((0, 0, _("Options `-%s' and `-%s' both want standard input"),
+		  stdin_used_by, option));
+
+  stdin_used_by = option;
 }
 
-/*
- * Set up to gather file names for tar.
- *
- * They can either come from stdin or from argv.
- */
-void
-name_init (argc, argv)
-     int argc;
-     char **argv;
+/*--------------------------------------------------------.
+| Returns true if and only if the user typed 'y' or 'Y'.  |
+`--------------------------------------------------------*/
+
+int
+confirm (const char *message_action, const char *message_name)
 {
+  static FILE *confirm_file = NULL;
 
-  if (f_namefile)
+  if (!confirm_file)
     {
-      if (optind < argc)
-	{
-	  msg ("too many args with -T option");
-	  exit (EX_ARGSBAD);
-	}
-      if (!strcmp (name_file, "-"))
-	{
-	  namef = stdin;
-	}
+      if (archive == 0 || stdin_used_by)
+	confirm_file = fopen (TTY_NAME, "r");
       else
 	{
-	  namef = fopen (name_file, "r");
-	  if (namef == NULL)
-	    {
-	      msg_perror ("can't open file %s", name_file);
-	      exit (EX_BADFILE);
-	    }
+	  request_stdin ("-w");
+	  confirm_file = stdin;
 	}
+
+      if (!confirm_file)
+	FATAL_ERROR ((0, 0, _("Cannot read confirmation from user")));
     }
-  else
-    {
-      /* Get file names from argv, after options. */
-      n_argc = argc;
-      n_argv = argv;
-    }
-}
 
-/* Read the next filename read from STREAM and null-terminate it.
-   Put it into BUFFER, reallocating and adjusting *PBUFFER_SIZE if necessary.
-   Return the new value for BUFFER, or NULL at end of file. */
+  fprintf (stdlis, "%s %s?", message_action, message_name);
+  fflush (stdlis);
 
-char *
-read_name_from_file (buffer, pbuffer_size, stream)
-     char *buffer;
-     size_t *pbuffer_size;
-     FILE *stream;
-{
-  register int c;
-  register int indx = 0;
-  register size_t buffer_size = *pbuffer_size;
+  {
+    int reply = getc (confirm_file);
+    int character;
 
-  while ((c = getc (stream)) != EOF && c != filename_terminator)
-    {
-      if (indx == buffer_size)
-	{
-	  buffer_size += NAMSIZ;
-	  buffer = ck_realloc (buffer, buffer_size + 2);
-	}
-      buffer[indx++] = c;
-    }
-  if (indx == 0 && c == EOF)
-    return NULL;
-  if (indx == buffer_size)
-    {
-      buffer_size += NAMSIZ;
-      buffer = ck_realloc (buffer, buffer_size + 2);
-    }
-  buffer[indx] = '\0';
-  *pbuffer_size = buffer_size;
-  return buffer;
+    for (character = reply;
+	 character != '\n' && character != EOF;
+	 character = getc (confirm_file))
+      continue;
+    return reply == 'y' || reply == 'Y';
+  }
 }
+
+/* Options.  */
 
-/*
- * Get the next name from argv or the name file.
- *
- * Result is in static storage and can't be relied upon across two calls.
- *
- * If CHANGE_DIRS is non-zero, treat a filename of the form "-C" as
- * meaning that the next filename is the name of a directory to change to.
- * If `filename_terminator' is '\0', CHANGE_DIRS is effectively always 0.
- */
-
-char *
-name_next (change_dirs)
-     int change_dirs;
+/* For long options that unconditionally set a single flag, we have getopt
+   do it.  For the others, we share the code for the equivalent short
+   named option, the name of which is stored in the otherwise-unused `val'
+   field of the `struct option'; for long options that have no equivalent
+   short option, we use nongraphic characters as pseudo short option
+   characters, starting at 2 and going upwards.  */
+
+#define BACKUP_OPTION			2
+#define DELETE_OPTION			3
+#define EXCLUDE_OPTION			4
+#define GROUP_OPTION			5
+#define MODE_OPTION			6
+#define NEWER_MTIME_OPTION		7
+#define NO_RECURSE_OPTION		8
+#define NULL_OPTION			9
+#define OWNER_OPTION			10
+#define POSIX_OPTION			11
+#define PRESERVE_OPTION			12
+#define RECORD_SIZE_OPTION		13
+#define RSH_COMMAND_OPTION		14
+#define SUFFIX_OPTION			15
+#define USE_COMPRESS_PROGRAM_OPTION	16
+#define VOLNO_FILE_OPTION		17
+
+/* Some cleanup is being made in GNU tar long options.  Using old names is
+   allowed for a while, but will also send a warning to stderr.  Take old
+   names out in 1.14, or in summer 1997, whichever happens last.  We use
+   nongraphic characters as pseudo short option characters, starting at 31
+   and going downwards.  */
+
+#define OBSOLETE_ABSOLUTE_NAMES		31
+#define OBSOLETE_BLOCK_COMPRESS		30
+#define OBSOLETE_BLOCKING_FACTOR	29
+#define OBSOLETE_BLOCK_NUMBER		28
+#define OBSOLETE_READ_FULL_RECORDS	27
+#define OBSOLETE_TOUCH			26
+#define OBSOLETE_VERSION_CONTROL	25
+
+/* If nonzero, display usage information and exit.  */
+static int show_help = 0;
+
+/* If nonzero, print the version on standard output and exit.  */
+static int show_version = 0;
+
+struct option long_options[] =
 {
-  static char *buffer;		/* Holding pattern */
-  static int buffer_siz;
-  register char *p;
-  register char *q = 0;
-  register int next_name_is_dir = 0;
-  extern char *un_quote_string ();
-
-  if (buffer_siz == 0)
-    {
-      buffer = ck_malloc (NAMSIZ + 2);
-      buffer_siz = NAMSIZ;
-    }
-  if (filename_terminator == '\0')
-    change_dirs = 0;
-tryagain:
-  if (namef == NULL)
-    {
-      if (n_indscan < n_indused)
-	p = n_ind[n_indscan++];
-      else if (optind < n_argc)
-	/* Names come from argv, after options */
-	p = n_argv[optind++];
-      else
-	{
-	  if (q)
-	    msg ("Missing filename after -C");
-	  return NULL;
-	}
+  {"absolute-names", no_argument, NULL, 'P'},
+  {"absolute-paths", no_argument, NULL, OBSOLETE_ABSOLUTE_NAMES},
+  {"after-date", required_argument, NULL, 'N'},
+  {"append", no_argument, NULL, 'r'},
+  {"atime-preserve", no_argument, &atime_preserve_option, 1},
+  {"backup", optional_argument, NULL, BACKUP_OPTION},
+  {"block-compress", no_argument, NULL, OBSOLETE_BLOCK_COMPRESS},
+  {"block-number", no_argument, NULL, 'R'},
+  {"block-size", required_argument, NULL, OBSOLETE_BLOCKING_FACTOR},
+  {"blocking-factor", required_argument, NULL, 'b'},
+  {"catenate", no_argument, NULL, 'A'},
+  {"checkpoint", no_argument, &checkpoint_option, 1},
+  {"compare", no_argument, NULL, 'd'},
+  {"compress", no_argument, NULL, 'Z'},
+  {"concatenate", no_argument, NULL, 'A'},
+  {"confirmation", no_argument, NULL, 'w'},
+  /* FIXME: --selective as a synonym for --confirmation?  */
+  {"create", no_argument, NULL, 'c'},
+  {"delete", no_argument, NULL, DELETE_OPTION},
+  {"dereference", no_argument, NULL, 'h'},
+  {"diff", no_argument, NULL, 'd'},
+  {"directory", required_argument, NULL, 'C'},
+  {"exclude", required_argument, NULL, EXCLUDE_OPTION},
+  {"exclude-from", required_argument, NULL, 'X'},
+  {"extract", no_argument, NULL, 'x'},
+  {"file", required_argument, NULL, 'f'},
+  {"files-from", required_argument, NULL, 'T'},
+  {"force-local", no_argument, &force_local_option, 1},
+  {"get", no_argument, NULL, 'x'},
+  {"group", required_argument, NULL, GROUP_OPTION},
+  {"gunzip", no_argument, NULL, 'z'},
+  {"gzip", no_argument, NULL, 'z'},
+  {"help", no_argument, &show_help, 1},
+  {"ignore-failed-read", no_argument, &ignore_failed_read_option, 1},
+  {"ignore-zeros", no_argument, NULL, 'i'},
+  /* FIXME: --ignore-end as a new name for --ignore-zeros?  */
+  {"incremental", no_argument, NULL, 'G'},
+  {"info-script", required_argument, NULL, 'F'},
+  {"interactive", no_argument, NULL, 'w'},
+  {"keep-old-files", no_argument, NULL, 'k'},
+  {"label", required_argument, NULL, 'V'},
+  {"list", no_argument, NULL, 't'},
+  {"listed-incremental", required_argument, NULL, 'g'},
+  {"mode", required_argument, NULL, MODE_OPTION},
+  {"modification-time", no_argument, NULL, OBSOLETE_TOUCH},
+  {"multi-volume", no_argument, NULL, 'M'},
+  {"new-volume-script", required_argument, NULL, 'F'},
+  {"newer", required_argument, NULL, 'N'},
+  {"newer-mtime", required_argument, NULL, NEWER_MTIME_OPTION},
+  {"null", no_argument, NULL, NULL_OPTION},
+  {"no-recursion", no_argument, NULL, NO_RECURSE_OPTION},
+  {"numeric-owner", no_argument, &numeric_owner_option, 1},
+  {"old-archive", no_argument, NULL, 'o'},
+  {"one-file-system", no_argument, NULL, 'l'},
+  {"owner", required_argument, NULL, OWNER_OPTION},
+  {"portability", no_argument, NULL, 'o'},
+  {"posix", no_argument, NULL, POSIX_OPTION},
+  {"preserve", no_argument, NULL, PRESERVE_OPTION},
+  {"preserve-order", no_argument, NULL, 's'},
+  {"preserve-permissions", no_argument, NULL, 'p'},
+  {"recursive-unlink", no_argument, &recursive_unlink_option, 1},
+  {"read-full-blocks", no_argument, NULL, OBSOLETE_READ_FULL_RECORDS},
+  {"read-full-records", no_argument, NULL, 'B'},
+  /* FIXME: --partial-blocks might be a synonym for --read-full-records?  */
+  {"record-number", no_argument, NULL, OBSOLETE_BLOCK_NUMBER},
+  {"record-size", required_argument, NULL, RECORD_SIZE_OPTION},
+  {"remove-files", no_argument, &remove_files_option, 1},
+  {"rsh-command", required_argument, NULL, RSH_COMMAND_OPTION},
+  {"same-order", no_argument, NULL, 's'},
+  {"same-owner", no_argument, &same_owner_option, 1},
+  {"same-permissions", no_argument, NULL, 'p'},
+  {"show-omitted-dirs", no_argument, &show_omitted_dirs_option, 1},
+  {"sparse", no_argument, NULL, 'S'},
+  {"starting-file", required_argument, NULL, 'K'},
+  {"suffix", required_argument, NULL, SUFFIX_OPTION},
+  {"tape-length", required_argument, NULL, 'L'},
+  {"to-stdout", no_argument, NULL, 'O'},
+  {"totals", no_argument, &totals_option, 1},
+  {"touch", no_argument, NULL, 'm'},
+  {"uncompress", no_argument, NULL, 'Z'},
+  {"ungzip", no_argument, NULL, 'z'},
+  {"unlink-first", no_argument, NULL, 'U'},
+  {"update", no_argument, NULL, 'u'},
+  {"use-compress-program", required_argument, NULL, USE_COMPRESS_PROGRAM_OPTION},
+  {"verbose", no_argument, NULL, 'v'},
+  {"verify", no_argument, NULL, 'W'},
+  {"version", no_argument, &show_version, 1},
+  {"version-control", required_argument, NULL, OBSOLETE_VERSION_CONTROL},
+  {"volno-file", required_argument, NULL, VOLNO_FILE_OPTION},
 
-      /* JF trivial support for -C option.  I don't know if
-		   chdir'ing at this point is dangerous or not.
-		   It seems to work, which is all I ask. */
-      if (change_dirs && !q && p[0] == '-' && p[1] == 'C' && p[2] == '\0')
-	{
-	  q = p;
-	  goto tryagain;
-	}
-      if (q)
-	{
-	  if (chdir (p) < 0)
-	    msg_perror ("Can't chdir to %s", p);
-	  q = 0;
-	  goto tryagain;
-	}
-      /* End of JF quick -C hack */
+  {0, 0, 0, 0}
+};
 
-#if 0
-      if (f_exclude && check_exclude (p))
-	goto tryagain;
-#endif
-      return un_quote_string (p);
-    }
-  while (p = read_name_from_file (buffer, &buffer_siz, namef))
+/*---------------------------------------------.
+| Print a usage message and exit with STATUS.  |
+`---------------------------------------------*/
+
+static void
+usage (int status)
+{
+  if (status != TAREXIT_SUCCESS)
+    fprintf (stderr, _("Try `%s --help' for more information.\n"),
+	     program_name);
+  else
     {
-      buffer = p;
-      if (*p == '\0')
-	continue;		/* Ignore empty lines. */
-      q = p + strlen (p) - 1;
-      while (q > p && *q == '/')/* Zap trailing "/"s. */
-	*q-- = '\0';
-      if (change_dirs && next_name_is_dir == 0
-	  && p[0] == '-' && p[1] == 'C' && p[2] == '\0')
-	{
-	  next_name_is_dir = 1;
-	  goto tryagain;
-	}
-      if (next_name_is_dir)
-	{
-	  if (chdir (p) < 0)
-	    msg_perror ("Can't change to directory %s", p);
-	  next_name_is_dir = 0;
-	  goto tryagain;
-	}
-#if 0
-      if (f_exclude && check_exclude (p))
-	goto tryagain;
+      fputs (_("\
+GNU `tar' saves many files together into a single tape or disk archive, and\n\
+can restore individual files from the archive.\n"),
+	     stdout);
+      printf (_("\nUsage: %s [OPTION]... [FILE]...\n"), program_name);
+      fputs (_("\
+\n\
+If a long option shows an argument as mandatory, then it is mandatory\n\
+for the equivalent short option also.  Similarly for optional arguments.\n"),
+	     stdout);
+      fputs(_("\
+\n\
+Main operation mode:\n\
+  -t, --list              list the contents of an archive\n\
+  -x, --extract, --get    extract files from an archive\n\
+  -c, --create            create a new archive\n\
+  -d, --diff, --compare   find differences between archive and file system\n\
+  -r, --append            append files to the end of an archive\n\
+  -u, --update            only append files newer than copy in archive\n\
+  -A, --catenate          append tar files to an archive\n\
+      --concatenate       same as -A\n\
+      --delete            delete from the archive (not on mag tapes!)\n"),
+	    stdout);
+      fputs (_("\
+\n\
+Operation modifiers:\n\
+  -W, --verify               attempt to verify the archive after writing it\n\
+      --remove-files         remove files after adding them to the archive\n\
+  -k, --keep-old-files       don't overwrite existing files when extracting\n\
+  -U, --unlink-first         remove each file prior to extracting over it\n\
+      --recursive-unlink     empty hierarchies prior to extracting directory\n\
+  -S, --sparse               handle sparse files efficiently\n\
+  -O, --to-stdout            extract files to standard output\n\
+  -G, --incremental          handle old GNU-format incremental backup\n\
+  -g, --listed-incremental   handle new GNU-format incremental backup\n\
+      --ignore-failed-read   do not exit with nonzero on unreadable files\n"),
+	     stdout);
+      fputs (_("\
+\n\
+Handling of file attributes:\n\
+      --owner=NAME             force NAME as owner for added files\n\
+      --group=NAME             force NAME as group for added files\n\
+      --mode=CHANGES           force (symbolic) mode CHANGES for added files\n\
+      --atime-preserve         don't change access times on dumped files\n\
+  -m, --modification-time      don't extract file modified time\n\
+      --same-owner             try extracting files with the same ownership\n\
+      --numeric-owner          always use numbers for user/group names\n\
+  -p, --same-permissions       extract all protection information\n\
+      --preserve-permissions   same as -p\n\
+  -s, --same-order             sort names to extract to match archive\n\
+      --preserve-order         same as -s\n\
+      --preserve               same as both -p and -s\n"),
+	     stdout);
+      fputs (_("\
+\n\
+Device selection and switching:\n\
+  -f, --file=ARCHIVE             use archive file or device ARCHIVE\n\
+      --force-local              archive file is local even if has a colon\n\
+      --rsh-command=COMMAND      use remote COMMAND instead of rsh\n\
+  -[0-7][lmh]                    specify drive and density\n\
+  -M, --multi-volume             create/list/extract multi-volume archive\n\
+  -L, --tape-length=NUM          change tape after writing NUM x 1024 bytes\n\
+  -F, --info-script=FILE         run script at end of each tape (implies -M)\n\
+      --new-volume-script=FILE   same as -F FILE\n\
+      --volno-file=FILE          use/update the volume number in FILE\n"),
+	     stdout);
+      fputs (_("\
+\n\
+Device blocking:\n\
+  -b, --blocking-factor=BLOCKS   BLOCKS x 512 bytes per record\n\
+      --record-size=SIZE         SIZE bytes per record, multiple of 512\n\
+  -i, --ignore-zeros             ignore zeroed blocks in archive (means EOF)\n\
+  -B, --read-full-records        reblock as we read (for 4.2BSD pipes)\n"),
+	     stdout);
+      fputs (_("\
+\n\
+Archive format selection:\n\
+  -V, --label=NAME                   create archive with volume name NAME\n\
+              PATTERN                at list/extract time, a globbing PATTERN\n\
+  -o, --old-archive, --portability   write a V7 format archive\n\
+      --posix                        write a POSIX conformant archive\n\
+  -z, --gzip, --ungzip               filter the archive through gzip\n\
+  -Z, --compress, --uncompress       filter the archive through compress\n\
+      --use-compress-program=PROG    filter through PROG (must accept -d)\n"),
+	     stdout);
+      fputs (_("\
+\n\
+Local file selection:\n\
+  -C, --directory=DIR          change to directory DIR\n\
+  -T, --files-from=NAME        get names to extract or create from file NAME\n\
+      --null                   -T reads null-terminated names, disable -C\n\
+      --exclude=PATTERN        exclude files, given as a globbing PATTERN\n\
+  -X, --exclude-from=FILE      exclude globbing patterns listed in FILE\n\
+  -P, --absolute-names         don't strip leading `/'s from file names\n\
+  -h, --dereference            dump instead the files symlinks point to\n\
+      --no-recursion           avoid descending automatically in directories\n\
+  -l, --one-file-system        stay in local file system when creating archive\n\
+  -K, --starting-file=NAME     begin at file NAME in the archive\n"),
+	     stdout);
+#if !MSDOS
+      fputs (_("\
+  -N, --newer=DATE             only store files newer than DATE\n\
+      --newer-mtime            compare date and time when data changed only\n\
+      --after-date=DATE        same as -N\n"),
+	     stdout);
 #endif
-      return un_quote_string (p);
+      fputs (_("\
+      --backup[=CONTROL]       backup before removal, choose version control\n\
+      --suffix=SUFFIX          backup before removel, override usual suffix\n"),
+	     stdout);
+      fputs (_("\
+\n\
+Informative output:\n\
+      --help            print this help, then exit\n\
+      --version         print tar program version number, then exit\n\
+  -v, --verbose         verbosely list files processed\n\
+      --checkpoint      print directory names while reading the archive\n\
+      --totals          print total bytes written while creating archive\n\
+  -R, --block-number    show block number within archive with each message\n\
+  -w, --interactive     ask for confirmation for every action\n\
+      --confirmation    same as -w\n"),
+	     stdout);
+      fputs (_("\
+\n\
+The backup suffix is `~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.\n\
+The version control may be set with --backup or VERSION_CONTROL, values are:\n\
+\n\
+  t, numbered     make numbered backups\n\
+  nil, existing   numbered if numbered backups exist, simple otherwise\n\
+  never, simple   always make simple backups\n"),
+	     stdout);
+      printf (_("\
+\n\
+GNU tar cannot read nor produce `--posix' archives.  If POSIXLY_CORRECT\n\
+is set in the environment, GNU extensions are disallowed with `--posix'.\n\
+Support for POSIX is only partially implemented, don't count on it yet.\n\
+ARCHIVE may be FILE, HOST:FILE or USER@HOST:FILE; and FILE may be a file\n\
+or a device.  *This* `tar' defaults to `-f%s -b%d'.\n"),
+	      DEFAULT_ARCHIVE, DEFAULT_BLOCKING);
+      fputs (_("\
+\n\
+Report bugs to <tar-bugs@gnu.ai.mit.edu>.\n"),
+	       stdout);
     }
-  return NULL;
+  exit (status);
 }
 
+/*----------------------------.
+| Parse the options for tar.  |
+`----------------------------*/
 
-/*
- * Close the name file, if any.
- */
-void
-name_close ()
-{
+/* Available option letters are DEHIJQY and aejnqy.  Some are reserved:
 
-  if (namef != NULL && namef != stdin)
-    fclose (namef);
-}
+   y  per-file gzip compression
+   Y  per-block gzip compression */
 
+#define OPTION_STRING \
+  "-01234567ABC:F:GK:L:MN:OPRST:UV:WX:Zb:cdf:g:hiklmoprstuvwxz"
 
-/*
- * Gather names in a list for scanning.
- * Could hash them later if we really care.
- *
- * If the names are already sorted to match the archive, we just
- * read them one by one.  name_gather reads the first one, and it
- * is called by name_match as appropriate to read the next ones.
- * At EOF, the last name read is just left in the buffer.
- * This option lets users of small machines extract an arbitrary
- * number of files by doing "tar t" and editing down the list of files.
- */
-void
-name_gather ()
+static void
+set_subcommand_option (enum subcommand subcommand)
 {
-  register char *p;
-  static struct name *namebuf;	/* One-name buffer */
-  static namelen;
-  static char *chdir_name;
+  if (subcommand_option != UNKNOWN_SUBCOMMAND
+      && subcommand_option != subcommand)
+    USAGE_ERROR ((0, 0,
+		  _("You may not specify more than one `-Acdtrux' option")));
 
-  if (f_sorted_names)
-    {
-      if (!namelen)
-	{
-	  namelen = NAMSIZ;
-	  namebuf = (struct name *) ck_malloc (sizeof (struct name) + NAMSIZ);
-	}
-      p = name_next (0);
-      if (p)
-	{
-	  if (*p == '-' && p[1] == 'C' && p[2] == '\0')
-	    {
-	      chdir_name = name_next (0);
-	      p = name_next (0);
-	      if (!p)
-		{
-		  msg ("Missing file name after -C");
-		  exit (EX_ARGSBAD);
-		}
-	      namebuf->change_dir = chdir_name;
-	    }
-	  namebuf->length = strlen (p);
-	  if (namebuf->length >= namelen)
-	    {
-	      namebuf = (struct name *) ck_realloc (namebuf, sizeof (struct name) + namebuf->length);
-	      namelen = namebuf->length;
-	    }
-	  strncpy (namebuf->name, p, namebuf->length);
-	  namebuf->name[namebuf->length] = 0;
-	  namebuf->next = (struct name *) NULL;
-	  namebuf->found = 0;
-	  namelist = namebuf;
-	  namelast = namelist;
-	}
-      return;
-    }
+  subcommand_option = subcommand;
+}
+
+static void
+set_use_compress_program_option (const char *string)
+{
+  if (use_compress_program_option && strcmp (use_compress_program_option, string) != 0)
+    USAGE_ERROR ((0, 0, _("Conflicting compression options")));
 
-  /* Non sorted names -- read them all in */
-  while (p = name_next (0))
-    addname (p);
+  use_compress_program_option = string;
 }
 
-/*
- * Add a name to the namelist.
- */
-void
-addname (name)
-     char *name;		/* pointer to name */
+static void
+decode_options (int argc, char *const *argv)
 {
-  register int i;		/* Length of string */
-  register struct name *p;	/* Current struct pointer */
-  static char *chdir_name;
-  char *new_name ();
+  int optchar;			/* option letter */
+  int input_files;		/* number of input files */
+  const char *backup_suffix_string;
+  const char *version_control_string;
 
-  if (name[0] == '-' && name[1] == 'C' && name[2] == '\0')
-    {
-      chdir_name = name_next (0);
-      name = name_next (0);
-      if (!chdir_name)
-	{
-	  msg ("Missing file name after -C");
-	  exit (EX_ARGSBAD);
-	}
-      if (chdir_name[0] != '/')
-	{
-	  char *path = ck_malloc (PATH_MAX);
-#if defined(__MSDOS__) || defined(HAVE_GETCWD) || defined(_POSIX_VERSION)
-	  if (!getcwd (path, PATH_MAX))
-	    {
-	      msg ("Couldn't get current directory.");
-	      exit (EX_SYSTEM);
-	    }
-#else
-	  char *getwd ();
+  /* Set some default option values.  */
 
-	  if (!getwd (path))
-	    {
-	      msg ("Couldn't get current directory: %s", path);
-	      exit (EX_SYSTEM);
-	    }
-#endif
-	  chdir_name = new_name (path, chdir_name);
-	  free (path);
-	}
-    }
+  subcommand_option = UNKNOWN_SUBCOMMAND;
+  archive_format = DEFAULT_FORMAT;
+  blocking_factor = DEFAULT_BLOCKING;
+  record_size = DEFAULT_BLOCKING * BLOCKSIZE;
 
-  if (name)
-    {
-      i = strlen (name);
-      /*NOSTRICT*/
-      p = (struct name *) malloc ((unsigned) (sizeof (struct name) + i));
-    }
-  else
-    p = (struct name *) malloc ((unsigned) (sizeof (struct name)));
-  if (!p)
-    {
-      if (name)
-	msg ("cannot allocate mem for name '%s'.", name);
-      else
-	msg ("cannot allocate mem for chdir record.");
-      exit (EX_SYSTEM);
-    }
-  p->next = (struct name *) NULL;
-  if (name)
-    {
-      p->fake = 0;
-      p->length = i;
-      strncpy (p->name, name, i);
-      p->name[i] = '\0';	/* Null term */
-    }
-  else
-    p->fake = 1;
-  p->found = 0;
-  p->regexp = 0;		/* Assume not a regular expression */
-  p->firstch = 1;		/* Assume first char is literal */
-  p->change_dir = chdir_name;
-  p->dir_contents = 0;		/* JF */
-  if (name)
+  owner_option = -1;
+  group_option = -1;
+
+  backup_suffix_string = getenv ("SIMPLE_BACKUP_SUFFIX");
+  version_control_string = getenv ("VERSION_CONTROL");
+
+  /* Convert old-style tar call by exploding option element and rearranging
+     options accordingly.  */
+
+  if (argc > 1 && argv[1][0] != '-')
     {
-      if (index (name, '*') || index (name, '[') || index (name, '?'))
+      int new_argc;		/* argc value for rearranged arguments */
+      char **new_argv;		/* argv value for rearranged arguments */
+      char *const *in;		/* cursor into original argv */
+      char **out;		/* cursor into rearranged argv */
+      const char *letter;	/* cursor into old option letters */
+      char buffer[3];		/* constructed option buffer */
+      const char *cursor;	/* cursor in OPTION_STRING */
+
+      /* Initialize a constructed option.  */
+
+      buffer[0] = '-';
+      buffer[2] = '\0';
+
+      /* Allocate a new argument array, and copy program name in it.  */
+
+      new_argc = argc - 1 + strlen (argv[1]);
+      new_argv = (char **) xmalloc (new_argc * sizeof (char *));
+      in = argv;
+      out = new_argv;
+      *out++ = *in++;
+
+      /* Copy each old letter option as a separate option, and have the
+	 corresponding argument moved next to it.  */
+
+      for (letter = *in++; *letter; letter++)
 	{
-	  p->regexp = 1;	/* No, it's a regexp */
-	  if (name[0] == '*' || name[0] == '[' || name[0] == '?')
-	    p->firstch = 0;	/* Not even 1st char literal */
+	  buffer[1] = *letter;
+	  *out++ = xstrdup (buffer);
+	  cursor = strchr (OPTION_STRING, *letter);
+	  if (cursor && cursor[1] == ':')
+	    if (in < argv + argc)
+	      *out++ = *in++;
+	    else
+	      USAGE_ERROR ((0, 0, _("Old option `%c' requires an argument."),
+			    *letter));
 	}
-    }
 
-  if (namelast)
-    namelast->next = p;
-  namelast = p;
-  if (!namelist)
-    namelist = p;
-}
+      /* Copy all remaining options.  */
 
-/*
- * Return nonzero if name P (from an archive) matches any name from
- * the namelist, zero if not.
- */
-int
-name_match (p)
-     register char *p;
-{
-  register struct name *nlp;
-  register int len;
+      while (in < argv + argc)
+	*out++ = *in++;
 
-again:
-  if (0 == (nlp = namelist))	/* Empty namelist is easy */
-    return 1;
-  if (nlp->fake)
-    {
-      if (nlp->change_dir && chdir (nlp->change_dir))
-	msg_perror ("Can't change to directory %d", nlp->change_dir);
-      namelist = 0;
-      return 1;
+      /* Replace the old option list by the new one.  */
+
+      argc = new_argc;
+      argv = new_argv;
     }
-  len = strlen (p);
-  for (; nlp != 0; nlp = nlp->next)
-    {
-      /* If first chars don't match, quick skip */
-      if (nlp->firstch && nlp->name[0] != p[0])
-	continue;
 
-      /* Regular expressions (shell globbing, actually). */
-      if (nlp->regexp)
+  /* Parse all options and non-options as they appear.  */
+
+  input_files = 0;
+
+  while (optchar = getopt_long (argc, argv, OPTION_STRING, long_options, NULL),
+	 optchar != EOF)
+    switch (optchar)
+      {
+      case '?':
+	usage (TAREXIT_FAILURE);
+
+      case 0:
+	break;
+
+      case 1:
+	/* File name or non-parsed option, because of RETURN_IN_ORDER
+	   ordering triggerred by the leading dash in OPTION_STRING.  */
+
+	name_add (optarg);
+	input_files++;
+	break;
+
+      case 'A':
+	set_subcommand_option (CAT_SUBCOMMAND);
+	break;
+
+      case OBSOLETE_BLOCK_COMPRESS:
+	WARN ((0, 0, _("Obsolete option, now implied by --blocking-factor")));
+	break;
+
+      case OBSOLETE_BLOCKING_FACTOR:
+	WARN ((0, 0, _("Obsolete option name replaced by --blocking-factor")));
+	/* Fall through.  */
+
+      case 'b':
+	blocking_factor = intconv (optarg);
+	record_size = blocking_factor * BLOCKSIZE;
+	break;
+
+      case OBSOLETE_READ_FULL_RECORDS:
+	WARN ((0, 0,
+	       _("Obsolete option name replaced by --read-full-records")));
+	/* Fall through.  */
+
+      case 'B':
+	/* Try to reblock input records.  For reading 4.2BSD pipes.  */
+
+	/* It would surely make sense to exchange -B and -R, but it seems
+	   that -B has been used for a long while in Sun tar ans most
+	   BSD-derived systems.  This is a consequence of the block/record
+	   terminology confusion.  */
+
+	read_full_records_option = 1;
+	break;
+
+      case 'c':
+	set_subcommand_option (CREATE_SUBCOMMAND);
+	break;
+
+      case 'C':
+	name_add ("-C");
+	name_add (optarg);
+	break;
+
+      case 'd':
+	set_subcommand_option (DIFF_SUBCOMMAND);
+	break;
+
+      case 'f':
+	if (archive_names == allocated_archive_names)
+	  {
+	    allocated_archive_names *= 2;
+	    archive_name_array = (const char **)
+	      xrealloc (archive_name_array,
+			sizeof (const char *) * allocated_archive_names);
+	  }
+	archive_name_array[archive_names++] = optarg;
+	break;
+
+      case 'F':
+	/* Since -F is only useful with -M, make it implied.  Run this
+	   script at the end of each tape.  */
+
+	info_script_option = optarg;
+	multi_volume_option = 1;
+	break;
+
+      case 'g':
+	listed_incremental_option = optarg;
+	/* Fall through.  */
+
+      case 'G':
+	/* We are making an incremental dump (FIXME: are we?); save
+	   directories at the beginning of the archive, and include in each
+	   directory its contents.  */
+
+	incremental_option = 1;
+	break;
+
+      case 'h':
+	/* Follow symbolic links.  */
+
+	dereference_option = 1;
+	break;
+
+      case 'i':
+	/* Ignore zero blocks (eofs).  This can't be the default,
+	   because Unix tar writes two blocks of zeros, then pads out
+	   the record with garbage.  */
+
+	ignore_zeros_option = 1;
+	break;
+
+      case 'k':
+	/* Don't overwrite existing files.  */
+
+	keep_old_files_option = 1;
+	break;
+
+      case 'K':
+	starting_file_option = 1;
+	addname (optarg);
+	break;
+
+      case 'l':
+	/* When dumping directories, don't dump files/subdirectories
+	   that are on other filesystems.  */
+
+	one_file_system_option = 1;
+	break;
+
+      case 'L':
+	clear_tarlong (tape_length_option);
+	add_to_tarlong (tape_length_option, intconv (optarg));
+	mult_tarlong (tape_length_option, 1024);
+	multi_volume_option = 1;
+	break;
+
+      case OBSOLETE_TOUCH:
+	WARN ((0, 0, _("Obsolete option name replaced by --touch")));
+	/* Fall through.  */
+
+      case 'm':
+	touch_option = 1;
+	break;
+
+      case 'M':
+	/* Make multivolume archive: when we can't write any more into
+	   the archive, re-open it, and continue writing.  */
+
+	multi_volume_option = 1;
+	break;
+
+#if !MSDOS
+      case 'N':
+	after_date_option = 1;
+	/* Fall through.  */
+
+      case NEWER_MTIME_OPTION:
+	if (newer_mtime_option)
+	  USAGE_ERROR ((0, 0, _("More than one threshold date")));
+
+	newer_mtime_option = get_date (optarg, (voidstar) 0);
+	if (newer_mtime_option == (time_t) -1)
+	  USAGE_ERROR ((0, 0, _("Invalid date format `%s'"), optarg));
+
+	break;
+#endif /* not MSDOS */
+
+      case 'o':
+	if (archive_format == DEFAULT_FORMAT)
+	  archive_format = V7_FORMAT;
+	else if (archive_format != V7_FORMAT)
+	  USAGE_ERROR ((0, 0, _("Conflicting archive format options")));
+	break;
+
+      case 'O':
+	to_stdout_option = 1;
+	break;
+
+      case 'p':
+	same_permissions_option = 1;
+	break;
+
+      case OBSOLETE_ABSOLUTE_NAMES:
+	WARN ((0, 0, _("Obsolete option name replaced by --absolute-names")));
+	/* Fall through.  */
+
+      case 'P':
+	absolute_names_option = 1;
+	break;
+
+      case 'r':
+	set_subcommand_option (APPEND_SUBCOMMAND);
+	break;
+
+      case OBSOLETE_BLOCK_NUMBER:
+	WARN ((0, 0, _("Obsolete option name replaced by --block-number")));
+	/* Fall through.  */
+
+      case 'R':
+	/* Print block numbers for debugging bad tar archives.  */
+
+	/* It would surely make sense to exchange -B and -R, but it seems
+	   that -B has been used for a long while in Sun tar ans most
+	   BSD-derived systems.  This is a consequence of the block/record
+	   terminology confusion.  */
+
+	block_number_option = 1;
+	break;
+
+      case 's':
+	/* Names to extr are sorted.  */
+
+	same_order_option = 1;
+	break;
+
+      case 'S':
+	sparse_option = 1;
+	break;
+
+      case 't':
+	set_subcommand_option (LIST_SUBCOMMAND);
+	verbose_option++;
+	break;
+
+      case 'T':
+	files_from_option = optarg;
+	break;
+
+      case 'u':
+	set_subcommand_option (UPDATE_SUBCOMMAND);
+	break;
+
+      case 'U':
+	unlink_first_option = 1;
+	break;
+
+      case 'v':
+	verbose_option++;
+	break;
+
+      case 'V':
+	volume_label_option = optarg;
+	break;
+
+      case 'w':
+	interactive_option = 1;
+	break;
+
+      case 'W':
+	verify_option = 1;
+	break;
+
+      case 'x':
+	set_subcommand_option (EXTRACT_SUBCOMMAND);
+	break;
+
+      case 'X':
+	exclude_option = 1;
+	add_exclude_file (optarg);
+	break;
+
+      case 'z':
+	set_use_compress_program_option ("gzip");
+	break;
+
+      case 'Z':
+	set_use_compress_program_option ("compress");
+	break;
+
+      case OBSOLETE_VERSION_CONTROL:
+	WARN ((0, 0, _("Obsolete option name replaced by --backup")));
+	/* Fall through.  */
+
+      case BACKUP_OPTION:
+	backup_option = 1;
+	if (optarg)
+	  version_control_string = optarg;
+	break;
+
+      case DELETE_OPTION:
+	set_subcommand_option (DELETE_SUBCOMMAND);
+	break;
+
+      case EXCLUDE_OPTION:
+	exclude_option = 1;
+	add_exclude (optarg);
+	break;
+
+      case GROUP_OPTION:
+	if (!gname_to_gid (optarg, &group_option))
+	  if (!check_decimal (optarg) >= 0)
+	    ERROR ((TAREXIT_FAILURE, 0, _("Invalid group given on option")));
+	  else
+	    group_option = check_decimal (optarg);
+	break;
+
+      case MODE_OPTION:
+	mode_option
+	  = mode_compile (optarg,
+			  MODE_MASK_EQUALS | MODE_MASK_PLUS | MODE_MASK_MINUS);
+	if (mode_option == MODE_INVALID)
+	  ERROR ((TAREXIT_FAILURE, 0, _("Invalid mode given on option")));
+	if (mode_option == MODE_MEMORY_EXHAUSTED)
+	  ERROR ((TAREXIT_FAILURE, 0, _("Memory exhausted")));
+	break;
+
+      case NO_RECURSE_OPTION:
+	no_recurse_option = 1;
+	break;
+
+      case NULL_OPTION:
+	filename_terminator = '\0';
+	break;
+
+      case OWNER_OPTION:
+	if (!uname_to_uid (optarg, &owner_option))
+	  if (!check_decimal (optarg) >= 0)
+	    ERROR ((TAREXIT_FAILURE, 0, _("Invalid owner given on option")));
+	  else
+	    owner_option = check_decimal (optarg);
+	break;
+
+      case POSIX_OPTION:
+#if OLDGNU_COMPATIBILITY
+	if (archive_format == DEFAULT_FORMAT)
+	  archive_format = GNU_FORMAT;
+	else if (archive_format != GNU_FORMAT)
+	  USAGE_ERROR ((0, 0, _("Conflicting archive format options")));
+#else
+	if (archive_format == DEFAULT_FORMAT)
+	  archive_format = POSIX_FORMAT;
+	else if (archive_format != POSIX_FORMAT)
+	  USAGE_ERROR ((0, 0, _("Conflicting archive format options")));
+#endif
+	break;
+
+      case PRESERVE_OPTION:
+	same_permissions_option = 1;
+	same_order_option = 1;
+	break;
+
+      case RECORD_SIZE_OPTION:
+	record_size = intconv (optarg);
+	if (record_size % BLOCKSIZE != 0)
+	  USAGE_ERROR ((0, 0, _("Record size must be a multiple of %d."),
+			BLOCKSIZE));
+	blocking_factor = record_size / BLOCKSIZE;
+	break;
+
+      case RSH_COMMAND_OPTION:
+	rsh_command_option = optarg;
+	break;
+
+      case SUFFIX_OPTION:
+	backup_option = 1;
+	backup_suffix_string = optarg;
+	break;
+
+      case VOLNO_FILE_OPTION:
+	volno_file_option = optarg;
+	break;
+
+      case USE_COMPRESS_PROGRAM_OPTION:
+	set_use_compress_program_option (optarg);
+	break;
+
+      case '0':
+      case '1':
+      case '2':
+      case '3':
+      case '4':
+      case '5':
+      case '6':
+      case '7':
+
+#ifdef DEVICE_PREFIX
 	{
-	  if (fnmatch (nlp->name, p, FNM_LEADING_DIR) == 0)
+	  int device = optchar - '0';
+	  int density;
+	  static char buf[sizeof DEVICE_PREFIX + 10];
+	  char *cursor;
+
+	  density = getopt_long (argc, argv, "lmh", NULL, NULL);
+	  strcpy (buf, DEVICE_PREFIX);
+	  cursor = buf + strlen (buf);
+
+#ifdef DENSITY_LETTER
+
+	  sprintf (cursor, "%d%c", device, density);
+
+#else /* not DENSITY_LETTER */
+
+	  switch (density)
 	    {
-	      nlp->found = 1;	/* Remember it matched */
-	      if (f_startfile)
-		{
-		  free ((void *) namelist);
-		  namelist = 0;
-		}
-	      if (nlp->change_dir && chdir (nlp->change_dir))
-		msg_perror ("Can't change to directory %s", nlp->change_dir);
-	      return 1;		/* We got a match */
+	    case 'l':
+#ifdef LOW_NUM
+	      device += LOW_NUM;
+#endif
+	      break;
+
+	    case 'm':
+#ifdef MID_NUM
+	      device += MID_NUM;
+#else
+	      device += 8;
+#endif
+	      break;
+
+	    case 'h':
+#ifdef HGH_NUM
+	      device += HGH_NUM;
+#else
+	      device += 16;
+#endif
+	      break;
+
+	    default:
+	      usage (TAREXIT_FAILURE);
 	    }
-	  continue;
-	}
+	  sprintf (cursor, "%d", device);
 
-      /* Plain Old Strings */
-      if (nlp->length <= len	/* Archive len >= specified */
-	  && (p[nlp->length] == '\0' || p[nlp->length] == '/')
-      /* Full match on file/dirname */
-	  && strncmp (p, nlp->name, nlp->length) == 0)	/* Name compare */
-	{
-	  nlp->found = 1;	/* Remember it matched */
-	  if (f_startfile)
+#endif /* not DENSITY_LETTER */
+
+	  if (archive_names == allocated_archive_names)
 	    {
-	      free ((void *) namelist);
-	      namelist = 0;
+	      allocated_archive_names *= 2;
+	      archive_name_array = (const char **)
+		xrealloc (archive_name_array,
+			  sizeof (const char *) * allocated_archive_names);
 	    }
-	  if (nlp->change_dir && chdir (nlp->change_dir))
-	    msg_perror ("Can't change to directory %s", nlp->change_dir);
-	  return 1;		/* We got a match */
+	  archive_name_array[archive_names++] = buf;
+
+	  /* FIXME: How comes this works for many archives when buf is
+	     not xstrdup'ed?  */
 	}
-    }
+	break;
 
-  /*
-	 * Filename from archive not found in namelist.
-	 * If we have the whole namelist here, just return 0.
-	 * Otherwise, read the next name in and compare it.
-	 * If this was the last name, namelist->found will remain on.
-	 * If not, we loop to compare the newly read name.
-	 */
-  if (f_sorted_names && namelist->found)
-    {
-      name_gather ();		/* Read one more */
-      if (!namelist->found)
-	goto again;
-    }
-  return 0;
-}
+#else /* not DEVICE_PREFIX */
 
+	USAGE_ERROR ((0, 0,
+		      _("Options `-[0-7][lmh]' not supported by *this* tar")));
 
-/*
- * Print the names of things in the namelist that were not matched.
- */
-void
-names_notfound ()
-{
-  register struct name *nlp, *next;
-  register char *p;
+#endif /* not DEVICE_PREFIX */
+      }
 
-  for (nlp = namelist; nlp != 0; nlp = next)
-    {
-      next = nlp->next;
-      if (!nlp->found)
-	msg ("%s not found in archive", nlp->name);
-
-      /*
-		 * We could free() the list, but the process is about
-		 * to die anyway, so save some CPU time.  Amigas and
-		 * other similarly broken software will need to waste
-		 * the time, though.
-		 */
-#ifdef amiga
-      if (!f_sorted_names)
-	free (nlp);
-#endif
-    }
-  namelist = (struct name *) NULL;
-  namelast = (struct name *) NULL;
+  /* Process trivial options.  */
 
-  if (f_sorted_names)
+  if (show_version)
     {
-      while (0 != (p = name_next (1)))
-	msg ("%s not found in archive", p);
+      printf ("tar (GNU %s) %s\n", PACKAGE, VERSION);
+      fputs (_("\
+\n\
+Copyright (C) 1988, 92, 93, 94, 95, 96, 97 Free Software Foundation, Inc.\n"),
+	     stdout);
+      fputs (_("\
+This is free software; see the source for copying conditions.  There is NO\n\
+warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"),
+	     stdout);
+      fputs (_("\
+\n\
+Written by John Gilmore and Jay Fenlason.\n"),
+	     stdout);
+      exit (TAREXIT_SUCCESS);
     }
-}
-
-/* These next routines were created by JF */
 
-void
-name_expand ()
-{
-  ;
-}
+  if (show_help)
+    usage (TAREXIT_SUCCESS);
 
-/* This is like name_match(), except that it returns a pointer to the name
-   it matched, and doesn't set ->found  The caller will have to do that
-   if it wants to.  Oh, and if the namelist is empty, it returns 0, unlike
-   name_match(), which returns TRUE */
+  /* Derive option values and check option consistency.  */
 
-struct name *
-name_scan (p)
-     register char *p;
-{
-  register struct name *nlp;
-  register int len;
-
-again:
-  if (0 == (nlp = namelist))	/* Empty namelist is easy */
-    return 0;
-  len = strlen (p);
-  for (; nlp != 0; nlp = nlp->next)
+  if (archive_format == DEFAULT_FORMAT)
     {
-      /* If first chars don't match, quick skip */
-      if (nlp->firstch && nlp->name[0] != p[0])
-	continue;
+#if OLDGNU_COMPATIBILITY
+      archive_format = OLDGNU_FORMAT;
+#else
+      archive_format = GNU_FORMAT;
+#endif
+    }
 
-      /* Regular expressions */
-      if (nlp->regexp)
-	{
-	  if (fnmatch (nlp->name, p, FNM_LEADING_DIR) == 0)
-	    return nlp;		/* We got a match */
-	  continue;
-	}
+  if (archive_format == GNU_FORMAT && getenv ("POSIXLY_CORRECT"))
+    archive_format = POSIX_FORMAT;
 
-      /* Plain Old Strings */
-      if (nlp->length <= len	/* Archive len >= specified */
-	  && (p[nlp->length] == '\0' || p[nlp->length] == '/')
-      /* Full match on file/dirname */
-	  && strncmp (p, nlp->name, nlp->length) == 0)	/* Name compare */
-	return nlp;		/* We got a match */
-    }
+  if ((volume_label_option != NULL
+       || incremental_option || multi_volume_option || sparse_option)
+      && archive_format != OLDGNU_FORMAT && archive_format != GNU_FORMAT)
+    USAGE_ERROR ((0, 0,
+		  _("GNU features wanted on incompatible archive format")));
 
-  /*
-	 * Filename from archive not found in namelist.
-	 * If we have the whole namelist here, just return 0.
-	 * Otherwise, read the next name in and compare it.
-	 * If this was the last name, namelist->found will remain on.
-	 * If not, we loop to compare the newly read name.
-	 */
-  if (f_sorted_names && namelist->found)
+  if (archive_names == 0)
     {
-      name_gather ();		/* Read one more */
-      if (!namelist->found)
-	goto again;
+      /* If no archive file name given, try TAPE from the environment, or
+	 else, DEFAULT_ARCHIVE from the configuration process.  */
+
+      archive_names = 1;
+      archive_name_array[0] = getenv ("TAPE");
+      if (archive_name_array[0] == NULL)
+	archive_name_array[0] = DEFAULT_ARCHIVE;
     }
-  return (struct name *) 0;
-}
 
-/* This returns a name from the namelist which doesn't have ->found set.
-   It sets ->found before returning, so successive calls will find and return
-   all the non-found names in the namelist */
+  /* Allow multiple archives only with `-M'.  */
 
-struct name *gnu_list_name;
+  if (archive_names > 1 && !multi_volume_option)
+    USAGE_ERROR ((0, 0,
+		  _("Multiple archive files requires `-M' option")));
 
-char *
-name_from_list ()
-{
-  if (!gnu_list_name)
-    gnu_list_name = namelist;
-  while (gnu_list_name && gnu_list_name->found)
-    gnu_list_name = gnu_list_name->next;
-  if (gnu_list_name)
+  /* If ready to unlink hierarchies, so we are for simpler files.  */
+  if (recursive_unlink_option)
+    unlink_first_option = 1;
+
+  /* Forbid using -c with no input files whatsoever.  Check that `-f -',
+     explicit or implied, is used correctly.  */
+
+  switch (subcommand_option)
     {
-      gnu_list_name->found++;
-      if (gnu_list_name->change_dir)
-	if (chdir (gnu_list_name->change_dir) < 0)
-	  msg_perror ("can't chdir to %s", gnu_list_name->change_dir);
-      return gnu_list_name->name;
+    case CREATE_SUBCOMMAND:
+      if (input_files == 0 && !files_from_option)
+	USAGE_ERROR ((0, 0,
+		      _("Cowardly refusing to create an empty archive")));
+      break;
+
+    case EXTRACT_SUBCOMMAND:
+    case LIST_SUBCOMMAND:
+    case DIFF_SUBCOMMAND:
+      for (archive_name_cursor = archive_name_array;
+	   archive_name_cursor < archive_name_array + archive_names;
+	   archive_name_cursor++)
+	if (!strcmp (*archive_name_cursor, "-"))
+	  request_stdin ("-f");
+      break;
+
+    case CAT_SUBCOMMAND:
+    case UPDATE_SUBCOMMAND:
+    case APPEND_SUBCOMMAND:
+      for (archive_name_cursor = archive_name_array;
+	   archive_name_cursor < archive_name_array + archive_names;
+	   archive_name_cursor++)
+	if (!strcmp (*archive_name_cursor, "-"))
+	  USAGE_ERROR ((0, 0,
+			_("Options `-Aru' are incompatible with `-f -'")));
+
+    default:
+      break;
     }
-  return (char *) 0;
-}
 
-void
-blank_name_list ()
-{
-  struct name *n;
+  archive_name_cursor = archive_name_array;
 
-  gnu_list_name = 0;
-  for (n = namelist; n; n = n->next)
-    n->found = 0;
-}
+  /* Prepare for generating backup names.  */
 
-char *
-new_name (path, name)
-     char *path, *name;
-{
-  char *path_buf;
+  if (backup_suffix_string)
+    simple_backup_suffix = xstrdup (backup_suffix_string);
 
-  path_buf = (char *) malloc (strlen (path) + strlen (name) + 2);
-  if (path_buf == 0)
-    {
-      msg ("Can't allocate memory for name '%s/%s", path, name);
-      exit (EX_SYSTEM);
-    }
-  (void) sprintf (path_buf, "%s/%s", path, name);
-  return path_buf;
+  if (backup_option)
+    backup_type = get_version (version_control_string);
 }
+
+/* Tar proper.  */
 
-/* returns non-zero if the luser typed 'y' or 'Y', zero otherwise. */
+/*-----------------------.
+| Main routine for tar.	 |
+`-----------------------*/
 
 int
-confirm (action, file)
-     char *action, *file;
+main (int argc, char *const *argv)
 {
-  int c, nl;
-  static FILE *confirm_file = 0;
-  extern FILE *msg_file;
-  extern char TTY_NAME[];
+  program_name = argv[0];
+  setlocale (LC_ALL, "");
+  bindtextdomain (PACKAGE, LOCALEDIR);
+  textdomain (PACKAGE);
 
-  fprintf (msg_file, "%s %s?", action, file);
-  fflush (msg_file);
-  if (!confirm_file)
-    {
-      confirm_file = (archive == 0) ? fopen (TTY_NAME, "r") : stdin;
-      if (!confirm_file)
-	{
-	  msg ("Can't read confirmation from user");
-	  exit (EX_SYSTEM);
-	}
-    }
-  c = getc (confirm_file);
-  for (nl = c; nl != '\n' && nl != EOF; nl = getc (confirm_file))
-    ;
-  return (c == 'y' || c == 'Y');
-}
+  exit_status = TAREXIT_SUCCESS;
+  filename_terminator = '\n';
 
-char *x_buffer = 0;
-int size_x_buffer;
-int free_x_buffer;
+  /* Pre-allocate a few structures.  */
 
-char **exclude = 0;
-int size_exclude = 0;
-int free_exclude = 0;
+  allocated_archive_names = 10;
+  archive_name_array = (const char **)
+    xmalloc (sizeof (const char *) * allocated_archive_names);
+  archive_names = 0;
 
-char **re_exclude = 0;
-int size_re_exclude = 0;
-int free_re_exclude = 0;
+  init_names ();
 
-void
-add_exclude (name)
-     char *name;
-{
-  /*	char *rname;*/
-  /*	char **tmp_ptr;*/
-  int size_buf;
+  /* Decode options.  */
 
-  un_quote_string (name);
-  size_buf = strlen (name);
+  decode_options (argc, argv);
+  name_init (argc, argv);
 
-  if (x_buffer == 0)
-    {
-      x_buffer = (char *) ck_malloc (size_buf + 1024);
-      free_x_buffer = 1024;
-    }
-  else if (free_x_buffer <= size_buf)
-    {
-      char *old_x_buffer;
-      char **tmp_ptr;
-
-      old_x_buffer = x_buffer;
-      x_buffer = (char *) ck_realloc (x_buffer, size_x_buffer + 1024);
-      free_x_buffer = 1024;
-      for (tmp_ptr = exclude; tmp_ptr < exclude + size_exclude; tmp_ptr++)
-	*tmp_ptr = x_buffer + ((*tmp_ptr) - old_x_buffer);
-      for (tmp_ptr = re_exclude; tmp_ptr < re_exclude + size_re_exclude; tmp_ptr++)
-	*tmp_ptr = x_buffer + ((*tmp_ptr) - old_x_buffer);
-    }
+  /* Main command execution.  */
 
-  if (is_regex (name))
-    {
-      if (free_re_exclude == 0)
-	{
-	  re_exclude = (char **) (re_exclude ? ck_realloc (re_exclude, (size_re_exclude + 32) * sizeof (char *)): ck_malloc (sizeof (char *) * 32));
-	  free_re_exclude += 32;
-	}
-      re_exclude[size_re_exclude] = x_buffer + size_x_buffer;
-      size_re_exclude++;
-      free_re_exclude--;
-    }
-  else
+  if (volno_file_option)
+    init_volume_number ();
+
+  switch (subcommand_option)
     {
-      if (free_exclude == 0)
-	{
-	  exclude = (char **) (exclude ? ck_realloc (exclude, (size_exclude + 32) * sizeof (char *)): ck_malloc (sizeof (char *) * 32));
-	  free_exclude += 32;
-	}
-      exclude[size_exclude] = x_buffer + size_x_buffer;
-      size_exclude++;
-      free_exclude--;
-    }
-  strcpy (x_buffer + size_x_buffer, name);
-  size_x_buffer += size_buf + 1;
-  free_x_buffer -= size_buf + 1;
-}
+    case UNKNOWN_SUBCOMMAND:
+      USAGE_ERROR ((0, 0,
+		    _("You must specify one of the `-Acdtrux' options")));
 
-void
-add_exclude_file (file)
-     char *file;
-{
-  FILE *fp;
-  char buf[1024];
+    case CAT_SUBCOMMAND:
+    case UPDATE_SUBCOMMAND:
+    case APPEND_SUBCOMMAND:
+      update_archive ();
+      break;
 
-  if (strcmp (file, "-"))
-    fp = fopen (file, "r");
-  else
-    /* Let's hope the person knows what they're doing. */
-    /* Using -X - -T - -f - will get you *REALLY* strange
-		   results. . . */
-    fp = stdin;
+    case DELETE_SUBCOMMAND:
+      delete_archive_members ();
+      break;
 
-  if (!fp)
-    {
-      msg_perror ("can't open %s", file);
-      exit (2);
-    }
-  while (fgets (buf, 1024, fp))
-    {
-      /*		int size_buf;*/
-      char *end_str;
+    case CREATE_SUBCOMMAND:
+      if (totals_option)
+	init_total_written ();
 
-      end_str = rindex (buf, '\n');
-      if (end_str)
-	*end_str = '\0';
-      add_exclude (buf);
+      create_archive ();
+      name_close ();
 
-    }
-  fclose (fp);
-}
+      if (totals_option)
+	print_total_written ();
+      break;
 
-int
-is_regex (str)
-     char *str;
-{
-  return index (str, '*') || index (str, '[') || index (str, '?');
-}
+    case EXTRACT_SUBCOMMAND:
+      extr_init ();
+      read_and (extract_archive);
+      break;
 
-/* Returns non-zero if the file 'name' should not be added/extracted */
-int
-check_exclude (name)
-     char *name;
-{
-  int n;
-  char *str;
-  extern char *strstr ();
+    case LIST_SUBCOMMAND:
+      read_and (list_archive);
+      break;
 
-  for (n = 0; n < size_re_exclude; n++)
-    {
-      if (fnmatch (re_exclude[n], name, FNM_LEADING_DIR) == 0)
-	return 1;
-    }
-  for (n = 0; n < size_exclude; n++)
-    {
-      /* Accept the output from strstr only if it is the last
-		   part of the string.  There is certainly a faster way to
-		   do this. . . */
-      if ((str = strstr (name, exclude[n]))
-	  && (str == name || str[-1] == '/')
-	  && str[strlen (exclude[n])] == '\0')
-	return 1;
+    case DIFF_SUBCOMMAND:
+      diff_init ();
+      read_and (diff_archive);
+      break;
     }
-  return 0;
+
+  if (volno_file_option)
+    closeout_volume_number ();
+
+  /* Dispose of allocated memory, and return.  */
+
+  free (archive_name_array);
+  name_term ();
+
+  if (exit_status == TAREXIT_FAILURE)
+    error (0, 0, _("Error exit delayed from previous errors"));
+  exit (exit_status);
 }
