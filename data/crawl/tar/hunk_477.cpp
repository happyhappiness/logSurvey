 /* Extract files from a tar archive.
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
- * Extract files from a tar archive.
- *
- * Written 19 Nov 1985 by John Gilmore, ihnp4!hoptoad!gnu.
- */
-
-#include <stdio.h>
-#include <errno.h>
-#ifndef STDC_HEADERS
-extern int errno;
-#endif
-#include <sys/types.h>
+   Copyright (C) 1988, 92, 93, 94, 96, 97 Free Software Foundation, Inc.
+   Written by John Gilmore, on 1985-11-19.
+
+   This program is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by the
+   Free Software Foundation; either version 2, or (at your option) any later
+   version.
+
+   This program is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
+   Public License for more details.
+
+   You should have received a copy of the GNU General Public License along
+   with this program; if not, write to the Free Software Foundation, Inc.,
+   59 Place - Suite 330, Boston, MA 02111-1307, USA.  */
+
+#include "system.h"
+
 #include <time.h>
 time_t time ();
 
-#ifdef BSD42
-#include <sys/file.h>
+#if HAVE_UTIME_H
+# include <utime.h>
 #else
-#ifndef V7
-#include <fcntl.h>
-#endif
+struct utimbuf
+  {
+    long actime;
+    long modtime;
+  };
 #endif
 
-#ifdef NO_OPEN3
-/* We need the #define's even though we don't use them. */
-#include "open3.h"
-#endif
+#include "common.h"
+
+static time_t now;		/* current time */
+static int we_are_root;		/* true if our effective uid == 0 */
+static int newdir_umask;	/* umask when creating new directories */
+static int current_umask;	/* current umask (which is set to 0 if -p) */
+
+#if 0
+/* "Scratch" space to store the information about a sparse file before
+   writing the info into the header or extended header.  */
+struct sp_array *sparsearray;
 
-#ifdef EMUL_OPEN3
-/* Simulated 3-argument open for systems that don't have it */
-#include "open3.h"
+/* Number of elts storable in the sparsearray.  */
+int   sp_array_size = 10;
 #endif
 
-#include "tar.h"
-#include "port.h"
+struct delayed_set_stat
+  {
+    struct delayed_set_stat *next;
+    char *file_name;
+    struct stat stat_info;
+  };
 
-#if defined(_POSIX_VERSION)
-#include <utime.h>
-#else
-struct utimbuf
+static struct delayed_set_stat *delayed_set_stat_head;
+
+/*--------------------------.
+| Set up to extract files.  |
+`--------------------------*/
+
+void
+extr_init (void)
 {
-  long actime;
-  long modtime;
-};
+  now = time ((time_t *) 0);
+  we_are_root = geteuid () == 0;
 
-#endif
+  /* Option -p clears the kernel umask, so it does not affect proper
+     restoration of file permissions.  New intermediate directories will
+     comply with umask at start of program.  */
+
+  newdir_umask = umask (0);
+  if (same_permissions_option)
+    current_umask = 0;
+  else
+    {
+      umask (newdir_umask);	/* restore the kernel umask */
+      current_umask = newdir_umask;
+    }
 
-extern FILE *msg_file;
+  /* FIXME: Just make sure we can add files in directories we create.  Maybe
+     should we later remove permissions we are adding, here?  */
+  newdir_umask &= ~0300;
+}
 
-extern union record *head;	/* Points to current tape header */
-extern struct stat hstat;	/* Stat struct corresponding */
-extern int head_standard;	/* Tape header is in ANSI format */
+/*------------------------------------------------------------------.
+| Restore mode for FILE_NAME, from information given in STAT_INFO.  |
+`------------------------------------------------------------------*/
 
-extern char *save_name;
-extern long save_totsize;
-extern long save_sizeleft;
+static void
+set_mode (char *file_name, struct stat *stat_info)
+{
+  /* We ought to force permission when -k is not selected, because if the
+     file already existed, open or creat would save the permission bits from
+     the previously created file, ignoring the ones we specified.
+
+     But with -k selected, we know *we* created this file, so the mode
+     bits were set by our open.  If the file has abnormal mode bits, we must
+     chmod since writing or chown has probably reset them.  If the file is
+     normal, we merely skip the chmod.  This works because we did umask (0)
+     when -p, so umask will have left the specified mode alone.  */
+
+  if (!keep_old_files_option
+      || (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX)))
+    if (chmod (file_name, ~current_umask & (int) stat_info->st_mode) < 0)
+      ERROR ((0, errno, _("%s: Cannot change mode to %0.4o"),
+	      file_name, ~current_umask & (int) stat_info->st_mode));
+}
 
-int confirm ();
-void decode_header ();
-void extract_mangle ();
-void extract_sparse_file ();
-long from_oct ();
-void gnu_restore ();
-extern void print_header ();
-extern void skip_file ();
-extern void skip_extended_headers ();
-extern void pr_mkdir ();
-void saverec ();
+/*----------------------------------------------------------------------.
+| Restore stat attributes (owner, group, mode and times) for FILE_NAME, |
+| using information given in STAT_INFO.  SYMLINK_FLAG is non-zero for a |
+| freshly restored symbolic link.				        |
+`----------------------------------------------------------------------*/
 
-int make_dirs ();		/* Makes required directories */
+/* FIXME: About proper restoration of symbolic link attributes, we still do
+   not have it right.  Pretesters' reports tell us we need further study and
+   probably more configuration.  For now, just use lchown if it exists, and
+   punt for the rest.  Sigh!  */
 
-static time_t now = 0;		/* Current time */
-static we_are_root = 0;		/* True if our effective uid == 0 */
-static int notumask = ~0;	/* Masks out bits user doesn't want */
+static void
+set_stat (char *file_name, struct stat *stat_info, int symlink_flag)
+{
+  struct utimbuf utimbuf;
 
-/*
- * "Scratch" space to store the information about a sparse file before
- * writing the info into the header or extended header
- */
-/*struct sp_array	*sparsearray;*/
+  if (!symlink_flag)
+    {
+      /* We do the utime before the chmod because some versions of utime are
+	 broken and trash the modes of the file.  */
 
-/* number of elts storable in the sparsearray */
-/*int	sp_array_size = 10;*/
+      if (!touch_option)
+	{
+	  /* We set the accessed time to `now', which is really the time we
+	     started extracting files, unless incremental_option is used, in
+	     which case .st_atime is used.  */
 
-struct saved_dir_info
+	  /* FIXME: incremental_option should set ctime too, but how?  */
+
+	  if (incremental_option)
+	    utimbuf.actime = stat_info->st_atime;
+	  else
+	    utimbuf.actime = now;
+
+	  utimbuf.modtime = stat_info->st_mtime;
+
+	  if (utime (file_name, &utimbuf) < 0)
+	    ERROR ((0, errno,
+		    _("%s: Could not change access and modification times"),
+		    file_name));
+	}
+
+      /* Some systems allow non-root users to give files away.  Once this
+	 done, it is not possible anymore to change file permissions, so we
+	 have to set permissions prior to possibly giving files away.  */
+
+      set_mode (file_name, stat_info);
+    }
+
+  /* If we are root, set the owner and group of the extracted file, so we
+     extract as the original owner.  Or else, if we are running as a user,
+     leave the owner and group as they are, so we extract as that user.  */
+
+  if (we_are_root || same_owner_option)
+    {
+#if HAVE_LCHOWN
+
+      /* When lchown exists, it should be used to change the attributes of
+	 the symbolic link itself.  In this case, a mere chown would change
+	 the attributes of the file the symbolic link is pointing to, and
+	 should be avoided.  */
+
+      if (symlink_flag)
+	{
+	  if (lchown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
+	    ERROR ((0, errno, _("%s: Cannot lchown to uid %d gid %d"),
+		    file_name, stat_info->st_uid, stat_info->st_gid));
+	}
+      else
+	{
+	  if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
+	    ERROR ((0, errno, _("%s: Cannot chown to uid %d gid %d"),
+		    file_name, stat_info->st_uid, stat_info->st_gid));
+	}
+
+#else /* not HAVE_LCHOWN */
+
+      if (!symlink_flag)
+
+	if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
+	  ERROR ((0, errno, _("%s: Cannot chown to uid %d gid %d"),
+		  file_name, stat_info->st_uid, stat_info->st_gid));
+
+#endif/* not HAVE_LCHOWN */
+
+      if (!symlink_flag)
+
+	/* On a few systems, and in particular, those allowing to give files
+	   away, changing the owner or group destroys the suid or sgid bits.
+	   So, when root, let's attempt setting these bits once more.  */
+
+	if (we_are_root && (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX)))
+	  set_mode (file_name, stat_info);
+    }
+}
+
+/*-----------------------------------------------------------------------.
+| After a file/link/symlink/directory creation has failed, see if it's	 |
+| because some required directory was not present, and if so, create all |
+| required directories.  Return non-zero if a directory was created.	 |
+`-----------------------------------------------------------------------*/
+
+static int
+make_directories (char *file_name)
 {
-  char *path;
-  int mode;
-  int atime;
-  int mtime;
-  struct saved_dir_info *next;
-};
-
-struct saved_dir_info *saved_dir_info_head;
-
-/*
- * Set up to extract files.
- */
-void
-extr_init ()
+  char *cursor;			/* points into path */
+  int did_something = 0;	/* did we do anything yet? */
+  int saved_errno = errno;	/* remember caller's errno */
+  int status;
+
+  for (cursor = strchr (file_name, '/');
+       cursor != NULL;
+       cursor = strchr (cursor + 1, '/'))
+    {
+      /* Avoid mkdir of empty string, if leading or double '/'.  */
+
+      if (cursor == file_name || cursor[-1] == '/')
+	continue;
+
+      /* Avoid mkdir where last part of path is '.'.  */
+
+      if (cursor[-1] == '.' && (cursor == file_name + 1 || cursor[-2] == '/'))
+	continue;
+
+      *cursor = '\0';		/* truncate the path there */
+      status = mkdir (file_name, ~newdir_umask & 0777);
+
+      if (status == 0)
+	{
+	  /* Fix ownership.  */
+
+	  if (we_are_root)
+	    if (chown (file_name, current_stat.st_uid, current_stat.st_gid) < 0)
+	      ERROR ((0, errno,
+		      _("%s: Cannot change owner to uid %d, gid %d"),
+		      file_name, current_stat.st_uid, current_stat.st_gid));
+
+	  print_for_mkdir (file_name, cursor - file_name,
+			   ~newdir_umask & 0777);
+	  did_something = 1;
+
+	  *cursor = '/';
+	  continue;
+	}
+
+      *cursor = '/';
+
+      if (errno == EEXIST
+#if MSDOS
+	  /* Turbo C mkdir gives a funny errno.  */
+	  || errno == EACCES
+#endif
+	  )
+	/* Directory already exists.  */
+	continue;
+
+      /* Some other error in the mkdir.  We return to the caller.  */
+      break;
+    }
+
+  errno = saved_errno;		/* FIXME: errno should be read-only */
+  return did_something;		/* tell them to retry if we made one */
+}
+
+/*--------------------------------------------------------------------.
+| Attempt repairing what went wrong with the extraction.  Delete an   |
+| already existing file or create missing intermediate directories.   |
+| Return nonzero if we somewhat increased our chances at a successful |
+| extraction.  errno is properly restored on zero return.	      |
+`--------------------------------------------------------------------*/
+
+static int
+maybe_recoverable (char *file_name)
 {
-  int ourmask;
+  switch (errno)
+    {
+    case EEXIST:
+      /* Attempt deleting an existing file.  However, with -k, just stay
+	 quiet.  */
 
-  now = time ((time_t *) 0);
-  if (geteuid () == 0)
-    we_are_root = 1;
-
-  /*
-	 * We need to know our umask.  But if f_use_protection is set,
-	 * leave our kernel umask at 0, and our "notumask" at ~0.
-	 */
-  ourmask = umask (0);		/* Read it */
-  if (!f_use_protection)
+      if (keep_old_files_option)
+	return 0;
+
+      return remove_any_file (file_name, 0);
+
+    case ENOENT:
+      /* Attempt creating missing intermediate directories.  */
+
+      return make_directories (file_name);
+
+    default:
+      /* Just say we can't do anything about it...  */
+
+      return 0;
+    }
+}
+
+/*---.
+| ?  |
+`---*/
+
+static void
+extract_sparse_file (int fd, long *sizeleft, long totalsize, char *name)
+{
+  union block *data_block;
+  int sparse_ind = 0;
+  int written, count;
+
+  /* FIXME: `data_block' might be used uninitialized in this function.
+     Reported by Bruno Haible.  */
+
+  /* assuming sizeleft is initially totalsize */
+
+  while (*sizeleft > 0)
     {
-      (void) umask (ourmask);	/* Set it back how it was */
-      notumask = ~ourmask;	/* Make umask override permissions */
+      data_block = find_next_block ();
+      if (data_block == NULL)
+	{
+	  ERROR ((0, 0, _("Unexpected EOF on archive file")));
+	  return;
+	}
+      lseek (fd, sparsearray[sparse_ind].offset, 0);
+      written = sparsearray[sparse_ind++].numbytes;
+      while (written > BLOCKSIZE)
+	{
+	  count = write (fd, data_block->buffer, BLOCKSIZE);
+	  if (count < 0)
+	    ERROR ((0, errno, _("%s: Could not write to file"), name));
+	  written -= count;
+	  *sizeleft -= count;
+	  set_next_block_after (data_block);
+	  data_block = find_next_block ();
+	}
+
+      count = write (fd, data_block->buffer, (size_t) written);
+
+      if (count < 0)
+	ERROR ((0, errno, _("%s: Could not write to file"), name));
+      else if (count != written)
+	{
+	  ERROR ((0, 0, _("%s: Could only write %d of %d bytes"),
+		     name, count, totalsize));
+	  skip_file ((long) (*sizeleft));
+	}
+
+      written -= count;
+      *sizeleft -= count;
+      set_next_block_after (data_block);
     }
+  free (sparsearray);
+  set_next_block_after (data_block);
 }
 
+/*----------------------------------.
+| Extract a file from the archive.  |
+`----------------------------------*/
 
-/*
- * Extract a file from the archive.
- */
 void
-extract_archive ()
+extract_archive (void)
 {
-  register char *data;
-  int fd, check, namelen, written, openflag;
+  union block *data_block;
+  int fd;
+  int status;
+  int name_length;
+  int written;
+  int openflag;
   long size;
-  struct utimbuf acc_upd_times;
-  register int skipcrud;
-  register int i;
-  /*	int sparse_ind = 0;*/
-  union record *exhdr;
-  struct saved_dir_info *tmp;
-  /*	int end_nulls; */
-
-  saverec (&head);		/* Make sure it sticks around */
-  userec (head);		/* And go past it in the archive */
-  decode_header (head, &hstat, &head_standard, 1);	/* Snarf fields */
-
-  if (f_confirm && !confirm ("extract", current_file_name))
+  int skipcrud;
+  int counter;
+#if 0
+  int sparse_ind = 0;
+#endif
+  union block *exhdr;
+  struct delayed_set_stat *data;
+
+#define CURRENT_FILE_NAME (skipcrud + current_file_name)
+
+  set_next_block_after (current_header);
+  decode_header (current_header, &current_stat, &current_format, 1);
+
+  if (interactive_option && !confirm ("extract", current_file_name))
     {
-      if (head->header.isextended)
+      if (current_header->oldgnu_header.isextended)
 	skip_extended_headers ();
-      skip_file ((long) hstat.st_size);
-      saverec ((union record **) 0);
+      skip_file ((long) current_stat.st_size);
       return;
     }
 
-  /* Print the record from 'head' and 'hstat' */
-  if (f_verbose)
+  /* Print the block from `current_header' and `current_stat'.  */
+
+  if (verbose_option)
     print_header ();
 
-  /*
-	 * Check for fully specified pathnames and other atrocities.
-	 *
-	 * Note, we can't just make a pointer to the new file name,
-	 * since saverec() might move the header and adjust "head".
-	 * We have to start from "head" every time we want to touch
-	 * the header record.
-	 */
+  /* Check for fully specified file names and other atrocities.  */
+
   skipcrud = 0;
-  while (!f_absolute_paths
-	 && '/' == current_file_name[skipcrud])
+  while (!absolute_names_option && CURRENT_FILE_NAME[0] == '/')
     {
       static int warned_once = 0;
 
-      skipcrud++;		/* Force relative path */
-      if (!warned_once++)
+      skipcrud++;		/* force relative path */
+      if (!warned_once)
 	{
-	  msg ("Removing leading / from absolute path names in the archive.");
+	  warned_once = 1;
+	  WARN ((0, 0, _("\
+Removing leading `/' from absolute path names in the archive")));
 	}
     }
 
-  switch (head->header.linkflag)
-    {
+  /* Take a safety backup of a previously existing file.  */
 
-    default:
-      msg ("Unknown file type '%c' for %s, extracted as normal file",
-	   head->header.linkflag, skipcrud + current_file_name);
-      /* FALL THRU */
-
-      /*
-	  * JK - What we want to do if the file is sparse is loop through
-	  * the array of sparse structures in the header and read in
-	  * and translate the character strings representing  1) the offset
-	  * at which to write and 2) how many bytes to write into numbers,
-	  * which we store into the scratch array, "sparsearray".  This
-	  * array makes our life easier the same way it did in creating
-	  * the tar file that had to deal with a sparse file.
-	  *
-	  * After we read in the first five (at most) sparse structures,
-	  * we check to see if the file has an extended header, i.e.,
-	  * if more sparse structures are needed to describe the contents
-	  * of the new file.  If so, we read in the extended headers
-	  * and continue to store their contents into the sparsearray.
-	  */
-    case LF_SPARSE:
+  if (backup_option && !to_stdout_option)
+    if (!maybe_backup_file (CURRENT_FILE_NAME, 0))
+      {
+	ERROR ((0, errno, _("%s: Was unable to backup this file"),
+		CURRENT_FILE_NAME));
+	if (current_header->oldgnu_header.isextended)
+	  skip_extended_headers ();
+	skip_file ((long) current_stat.st_size);
+	return;
+      }
+
+  /* Extract the archive entry according to its type.  */
+
+  switch (current_header->header.typeflag)
+    {
+      /* JK - What we want to do if the file is sparse is loop through
+	 the array of sparse structures in the header and read in and
+	 translate the character strings representing 1) the offset at
+	 which to write and 2) how many bytes to write into numbers,
+	 which we store into the scratch array, "sparsearray".  This
+	 array makes our life easier the same way it did in creating the
+	 tar file that had to deal with a sparse file.
+
+	 After we read in the first five (at most) sparse structures, we
+	 check to see if the file has an extended header, i.e., if more
+	 sparse structures are needed to describe the contents of the new
+	 file.  If so, we read in the extended headers and continue to
+	 store their contents into the sparsearray.  */
+
+    case GNUTYPE_SPARSE:
       sp_array_size = 10;
-      sparsearray = (struct sp_array *) ck_malloc (sp_array_size * sizeof (struct sp_array));
-      for (i = 0; i < SPARSE_IN_HDR; i++)
+      sparsearray = (struct sp_array *)
+	xmalloc (sp_array_size * sizeof (struct sp_array));
+
+      for (counter = 0; counter < SPARSES_IN_OLDGNU_HEADER; counter++)
 	{
-	  sparsearray[i].offset =
-	    from_oct (1 + 12, head->header.sp[i].offset);
-	  sparsearray[i].numbytes =
-	    from_oct (1 + 12, head->header.sp[i].numbytes);
-	  if (!sparsearray[i].numbytes)
+	  sparsearray[counter].offset =
+	    from_oct (1 + 12,
+		      current_header->oldgnu_header.sp[counter].offset);
+	  sparsearray[counter].numbytes =
+	    from_oct (1 + 12,
+		      current_header->oldgnu_header.sp[counter].numbytes);
+	  if (!sparsearray[counter].numbytes)
 	    break;
 	}
 
-      /*		end_nulls = from_oct(1+12, head->header.ending_blanks);*/
-
-      if (head->header.isextended)
+      if (current_header->oldgnu_header.isextended)
 	{
-	  /* read in the list of extended headers
-			    and translate them into the sparsearray
-			    as before */
+	  /* Read in the list of extended headers and translate them into
+	     the sparsearray as before.  */
 
-	  /* static */ int ind = SPARSE_IN_HDR;
+	  /* static */ int ind = SPARSES_IN_OLDGNU_HEADER;
 
-	  for (;;)
+	  while (1)
 	    {
-
-	      exhdr = findrec ();
-	      for (i = 0; i < SPARSE_EXT_HDR; i++)
+	      exhdr = find_next_block ();
+	      for (counter = 0; counter < SPARSES_IN_SPARSE_HEADER; counter++)
 		{
-
-		  if (i + ind > sp_array_size - 1)
+		  if (counter + ind > sp_array_size - 1)
 		    {
-		      /*
-					  * realloc the scratch area
-					  * since we've run out of room --
-					  */
-		      sparsearray = (struct sp_array *)
-			ck_realloc (sparsearray,
-			    2 * sp_array_size * (sizeof (struct sp_array)));
+		      /* Realloc the scratch area since we've run out of
+			 room.  */
+
 		      sp_array_size *= 2;
+		      sparsearray = (struct sp_array *)
+			xrealloc (sparsearray,
+				  sp_array_size * (sizeof (struct sp_array)));
 		    }
-		  if (!exhdr->ext_hdr.sp[i].numbytes)
+		  /* Compare to 0, or use !(int)..., for Pyramid's dumb
+		     compiler.  */
+		  if (exhdr->sparse_header.sp[counter].numbytes == 0)
 		    break;
-		  sparsearray[i + ind].offset =
-		    from_oct (1 + 12, exhdr->ext_hdr.sp[i].offset);
-		  sparsearray[i + ind].numbytes =
-		    from_oct (1 + 12, exhdr->ext_hdr.sp[i].numbytes);
+		  sparsearray[counter + ind].offset =
+		    from_oct (1 + 12,
+			      exhdr->sparse_header.sp[counter].offset);
+		  sparsearray[counter + ind].numbytes =
+		    from_oct (1 + 12,
+			      exhdr->sparse_header.sp[counter].numbytes);
 		}
-	      if (!exhdr->ext_hdr.isextended)
+	      if (!exhdr->sparse_header.isextended)
 		break;
 	      else
 		{
-		  ind += SPARSE_EXT_HDR;
-		  userec (exhdr);
+		  ind += SPARSES_IN_SPARSE_HEADER;
+		  set_next_block_after (exhdr);
 		}
 	    }
-	  userec (exhdr);
+	  set_next_block_after (exhdr);
 	}
+      /* Fall through.  */
+
+    case AREGTYPE:
+    case REGTYPE:
+    case CONTTYPE:
 
-      /* FALL THRU */
-    case LF_OLDNORMAL:
-    case LF_NORMAL:
-    case LF_CONTIG:
-      /*
-		  * Appears to be a file.
-		  * See if it's really a directory.
-		  */
-      namelen = strlen (skipcrud + current_file_name) - 1;
-      if (current_file_name[skipcrud + namelen] == '/')
+      /* Appears to be a file.  But BSD tar uses the convention that a slash
+	 suffix means a directory.  */
+
+      name_length = strlen (CURRENT_FILE_NAME) - 1;
+      if (CURRENT_FILE_NAME[name_length] == '/')
 	goto really_dir;
 
-      /* FIXME, deal with protection issues */
+      /* FIXME: deal with protection issues.  */
+
     again_file:
-      openflag = (f_keep ?
+      openflag = (keep_old_files_option ?
 		  O_BINARY | O_NDELAY | O_WRONLY | O_CREAT | O_EXCL :
 		  O_BINARY | O_NDELAY | O_WRONLY | O_CREAT | O_TRUNC)
-	| ((head->header.linkflag == LF_SPARSE) ? 0 : O_APPEND);
-      /*
-			  * JK - The last | is a kludge to solve the problem
-			  * the O_APPEND flag  causes with files we are
-			  * trying to make sparse:  when a file is opened
-			  * with O_APPEND, it writes  to the last place
-			  * that something was written, thereby ignoring
-			  * any lseeks that we have done.  We add this
-			  * extra condition to make it able to lseek when
-			  * a file is sparse, i.e., we don't open the new
-			  * file with this flag.  (Grump -- this bug caused
-			  * me to waste a good deal of time, I might add)
-			  */
-
-      if (f_exstdout)
+	| ((current_header->header.typeflag == GNUTYPE_SPARSE) ? 0 : O_APPEND);
+
+      /* JK - The last | is a kludge to solve the problem the O_APPEND
+	 flag causes with files we are trying to make sparse: when a file
+	 is opened with O_APPEND, it writes to the last place that
+	 something was written, thereby ignoring any lseeks that we have
+	 done.  We add this extra condition to make it able to lseek when
+	 a file is sparse, i.e., we don't open the new file with this
+	 flag.  (Grump -- this bug caused me to waste a good deal of
+	 time, I might add)  */
+
+      if (to_stdout_option)
 	{
 	  fd = 1;
 	  goto extract_file;
 	}
-#ifdef O_CTG
-      /*
-		  * Contiguous files (on the Masscomp) have to specify
-		  * the size in the open call that creates them.
-		  */
-      if (head->header.linkflag == LF_CONTIG)
-	fd = open ((longname ? longname : head->header.name)
-		   + skipcrud,
-		   openflag | O_CTG,
-		   hstat.st_mode, hstat.st_size);
+
+      if (unlink_first_option)
+	remove_any_file (CURRENT_FILE_NAME, recursive_unlink_option);
+
+#if O_CTG
+      /* Contiguous files (on the Masscomp) have to specify the size in
+	 the open call that creates them.  */
+
+      if (current_header->header.typeflag == CONTTYPE)
+	fd = open (CURRENT_FILE_NAME, openflag | O_CTG,
+		   current_stat.st_mode, current_stat.st_size);
       else
-#endif
+	fd = open (CURRENT_FILE_NAME, openflag, current_stat.st_mode);
+
+#else /* not O_CTG */
+      if (current_header->header.typeflag == CONTTYPE)
 	{
-#ifdef NO_OPEN3
-	  /*
-			  * On raw V7 we won't let them specify -k (f_keep), but
-			  * we just bull ahead and create the files.
-			  */
-	  fd = creat ((longname
-		       ? longname
-		       : head->header.name) + skipcrud,
-		      hstat.st_mode);
-#else
-	  /*
-			  * With 3-arg open(), we can do this up right.
-			  */
-	  fd = open (skipcrud + current_file_name,
-		     openflag, hstat.st_mode);
-#endif
+	  static int conttype_diagnosed = 0;
+
+	  if (!conttype_diagnosed)
+	    {
+	      conttype_diagnosed = 1;
+	      WARN ((0, 0, _("Extracting contiguous files as regular files")));
+	    }
 	}
+      fd = open (CURRENT_FILE_NAME, openflag, current_stat.st_mode);
+
+#endif /* not O_CTG */
 
       if (fd < 0)
 	{
-	  if (make_dirs (skipcrud + current_file_name))
+	  if (maybe_recoverable (CURRENT_FILE_NAME))
 	    goto again_file;
-	  msg_perror ("Could not create file %s",
-		      skipcrud + current_file_name);
-	  if (head->header.isextended)
+
+	  ERROR ((0, errno, _("%s: Could not create file"),
+		  CURRENT_FILE_NAME));
+	  if (current_header->oldgnu_header.isextended)
 	    skip_extended_headers ();
-	  skip_file ((long) hstat.st_size);
-	  goto quit;
+	  skip_file ((long) current_stat.st_size);
+	  if (backup_option)
+	    undo_last_backup ();
+	  break;
 	}
 
     extract_file:
-      if (head->header.linkflag == LF_SPARSE)
+      if (current_header->header.typeflag == GNUTYPE_SPARSE)
 	{
 	  char *name;
-	  int namelen;
-
-	  /*
-			  * Kludge alert.  NAME is assigned to header.name
-			  * because during the extraction, the space that
-			  * contains the header will get scribbled on, and
-			  * the name will get munged, so any error messages
-			  * that happen to contain the filename will look
-			  * REAL interesting unless we do this.
-			  */
-	  namelen = strlen (skipcrud + current_file_name) + 1;
-	  name = (char *) ck_malloc ((sizeof (char)) * namelen);
-	  bcopy (skipcrud + current_file_name, name, namelen);
-	  size = hstat.st_size;
-	  extract_sparse_file (fd, &size, hstat.st_size, name);
+	  int name_length_bis;
+
+	  /* Kludge alert.  NAME is assigned to header.name because
+	     during the extraction, the space that contains the header
+	     will get scribbled on, and the name will get munged, so any
+	     error messages that happen to contain the filename will look
+	     REAL interesting unless we do this.  */
+
+	  name_length_bis = strlen (CURRENT_FILE_NAME) + 1;
+	  name = (char *) xmalloc ((sizeof (char)) * name_length_bis);
+	  memcpy (name, CURRENT_FILE_NAME, (size_t) name_length_bis);
+	  size = current_stat.st_size;
+	  extract_sparse_file (fd, &size, current_stat.st_size, name);
 	}
       else
-	for (size = hstat.st_size;
+	for (size = current_stat.st_size;
 	     size > 0;
 	     size -= written)
 	  {
+#if 0
+	    long offset, numbytes;
+#endif
+	    if (multi_volume_option)
+	      {
+		assign_string (&save_name, current_file_name);
+		save_totsize = current_stat.st_size;
+		save_sizeleft = size;
+	      }
 
-	    /*			long	offset,
-				 numbytes;*/
+	    /* Locate data, determine max length writeable, write it,
+	       block that we have used the data, then check if the write
+	       worked.  */
 
-	    if (f_multivol)
+	    data_block = find_next_block ();
+	    if (data_block == NULL)
 	      {
-		save_name = current_file_name;
-		save_totsize = hstat.st_size;
-		save_sizeleft = size;
+		ERROR ((0, 0, _("Unexpected EOF on archive file")));
+		break;		/* FIXME: What happens, then?  */
 	      }
 
-	    /*
-			  * Locate data, determine max length
-			  * writeable, write it, record that
-			  * we have used the data, then check
-			  * if the write worked.
-			  */
-	    data = findrec ()->charptr;
-	    if (data == NULL)
-	      {			/* Check it... */
-		msg ("Unexpected EOF on archive file");
-		break;
+	    /* If the file is sparse, use the sparsearray that we created
+	       before to lseek into the new file the proper amount, and to
+	       see how many bytes we want to write at that position.  */
+
+#if 0
+	    if (current_header->header.typeflag == GNUTYPE_SPARSE)
+	      {
+		off_t pos;
+
+		pos = lseek (fd, (off_t) sparsearray[sparse_ind].offset, 0);
+		fprintf (msg_file, _("%d at %d\n"), (int) pos, sparse_ind);
+		written = sparsearray[sparse_ind++].numbytes;
 	      }
-	    /*
-			  * JK - If the file is sparse, use the sparsearray
-			  * that we created before to lseek into the new
-			  * file the proper amount, and to see how many
-			  * bytes we want to write at that position.
-			  */
-	    /*			if (head->header.linkflag == LF_SPARSE) {
-				 off_t pos;
-
-				 pos = lseek(fd, (off_t) sparsearray[sparse_ind].offset, 0);
-				 printf("%d at %d\n", (int) pos, sparse_ind);
-				 written = sparsearray[sparse_ind++].numbytes;
-			 } else*/
-	    written = endofrecs ()->charptr - data;
+	    else
+#endif
+	      written = available_space_after (data_block);
+
 	    if (written > size)
 	      written = size;
-	    errno = 0;
-	    check = write (fd, data, written);
-	    /*
-			  * The following is in violation of strict
-			  * typing, since the arg to userec
-			  * should be a struct rec *.  FIXME.
-			  */
-	    userec ((union record *) (data + written - 1));
-	    if (check == written)
+	    errno = 0;		/* FIXME: errno should be read-only */
+	    status = write (fd, data_block->buffer, (size_t) written);
+
+	    set_next_block_after ((union block *)
+				  (data_block->buffer + written - 1));
+	    if (status == written)
 	      continue;
-	    /*
-			  * Error in writing to file.
-			  * Print it, skip to next file in archive.
-			  */
-	    if (check < 0)
-	      msg_perror ("couldn't write to file %s",
-			  skipcrud + current_file_name);
+
+	    /* Error in writing to file.  Print it, skip to next file in
+	       archive.  */
+
+	    if (status < 0)
+	      ERROR ((0, errno, _("%s: Could not write to file"),
+		      CURRENT_FILE_NAME));
 	    else
-	      msg ("could only write %d of %d bytes to file %s",
-		   check, written, skipcrud + current_file_name);
+	      ERROR ((0, 0, _("%s: Could only write %d of %d bytes"),
+		      CURRENT_FILE_NAME, status, written));
 	    skip_file ((long) (size - written));
-	    break;		/* Still do the close, mod time, chmod, etc */
+	    break;		/* still do the close, mod time, chmod, etc */
 	  }
 
-      if (f_multivol)
-	save_name = 0;
+      if (multi_volume_option)
+	assign_string (&save_name, NULL);
+
+      /* If writing to stdout, don't try to do anything to the filename;
+	 it doesn't exist, or we don't want to touch it anyway.  */
 
-      /* If writing to stdout, don't try to do anything
-			    to the filename; it doesn't exist, or we don't
-			    want to touch it anyway */
-      if (f_exstdout)
+      if (to_stdout_option)
 	break;
 
-      /*		if (head->header.isextended) {
-			 register union record *exhdr;
-			 register int i;
+#if 0
+      if (current_header->header.isextended)
+	{
+	  union block *exhdr;
+	  int counter;
+
+	  for (counter = 0; counter < 21; counter++)
+	    {
+	      off_t offset;
 
-			 for (i = 0; i < 21; i++) {
-				 long offset;
+	      if (!exhdr->sparse_header.sp[counter].numbytes)
+		break;
+	      offset = from_oct (1 + 12, exhdr->sparse_header.sp[counter].offset);
+	      written = from_oct (1 + 12, exhdr->sparse_header.sp[counter].numbytes);
+	      lseek (fd, offset, 0);
+	      status = write (fd, data_block->buffer, written);
+	      if (status == written)
+		continue;
+	    }
+	}
+#endif
+      status = close (fd);
+      if (status < 0)
+	{
+	  ERROR ((0, errno, _("%s: Error while closing"), CURRENT_FILE_NAME));
+	  if (backup_option)
+	    undo_last_backup ();
+	}
 
-				 if (!exhdr->ext_hdr.sp[i].numbytes)
-					 break;
-				 offset = from_oct(1+12,
-						 exhdr->ext_hdr.sp[i].offset);
-				 written = from_oct(1+12,
-						 exhdr->ext_hdr.sp[i].numbytes);
-				 lseek(fd, offset, 0);
-				 check = write(fd, data, written);
-				 if (check == written) continue;
+      set_stat (CURRENT_FILE_NAME, &current_stat, 0);
+      break;
 
-			 }
+    case SYMTYPE:
+      if (to_stdout_option)
+	break;
 
+#ifdef S_ISLNK
+      if (unlink_first_option)
+	remove_any_file (CURRENT_FILE_NAME, recursive_unlink_option);
 
-		 }*/
-      check = close (fd);
-      if (check < 0)
-	{
-	  msg_perror ("Error while closing %s",
-		      skipcrud + current_file_name);
-	}
+      while (status = symlink (current_link_name, CURRENT_FILE_NAME),
+	     status != 0)
+	if (!maybe_recoverable (CURRENT_FILE_NAME))
+	  break;
 
+      if (status == 0)
 
-    set_filestat:
+	/* Setting the attributes of symbolic links might, on some systems,
+	   change the pointed to file, instead of the symbolic link itself.
+	   At least some of these systems have a lchown call, and the
+	   set_stat routine knows about this.    */
 
-      /*
-		  * If we are root, set the owner and group of the extracted
-		  * file.  This does what is wanted both on real Unix and on
-		  * System V.  If we are running as a user, we extract as that
-		  * user; if running as root, we extract as the original owner.
-		  */
-      if (we_are_root || f_do_chown)
-	{
-	  if (chown (skipcrud + current_file_name,
-		     hstat.st_uid, hstat.st_gid) < 0)
-	    {
-	      msg_perror ("cannot chown file %s to uid %d gid %d",
-			  skipcrud + current_file_name,
-			  hstat.st_uid, hstat.st_gid);
-	    }
-	}
+	set_stat (CURRENT_FILE_NAME, &current_stat, 1);
 
-      /*
-       * Set the modified time of the file.
-       *
-       * Note that we set the accessed time to "now", which
-       * is really "the time we started extracting files".
-       * unless f_gnudump is used, in which case .st_atime is used
-       */
-      if (!f_modified)
-	{
-	  /* fixme if f_gnudump should set ctime too, but how? */
-	  if (f_gnudump)
-	    acc_upd_times.actime = hstat.st_atime;
-	  else
-	    acc_upd_times.actime = now;	/* Accessed now */
-	  acc_upd_times.modtime = hstat.st_mtime;	/* Mod'd */
-	  if (utime (skipcrud + current_file_name,
-		     &acc_upd_times) < 0)
-	    {
-	      msg_perror ("couldn't change access and modification times of %s", skipcrud + current_file_name);
-	    }
-	}
-      /* We do the utime before the chmod because some versions of
-		   utime are broken and trash the modes of the file.  Since
-		   we then change the mode anyway, we don't care. . . */
-
-      /*
-		 * If '-k' is not set, open() or creat() could have saved
-		 * the permission bits from a previously created file,
-		 * ignoring the ones we specified.
-		 * Even if -k is set, if the file has abnormal
-		 * mode bits, we must chmod since writing or chown() has
-		 * probably reset them.
-		 *
-		 * If -k is set, we know *we* created this file, so the mode
-		 * bits were set by our open().   If the file is "normal", we
-		 * skip the chmod.  This works because we did umask(0) if -p
-		 * is set, so umask will have left the specified mode alone.
-		 */
-      if ((!f_keep)
-	  || (hstat.st_mode & (S_ISUID | S_ISGID | S_ISVTX)))
+      else
 	{
-	  if (chmod (skipcrud + current_file_name,
-		     notumask & (int) hstat.st_mode) < 0)
-	    {
-	      msg_perror ("cannot change mode of file %s to %lo",
-			  skipcrud + current_file_name,
-			  notumask & (int) hstat.st_mode);
-	    }
+	  ERROR ((0, errno, _("%s: Could not create symlink to `%s'"),
+		  CURRENT_FILE_NAME, current_link_name));
+	  if (backup_option)
+	    undo_last_backup ();
 	}
-
-    quit:
       break;
 
-    case LF_LINK:
+#else /* not S_ISLNK */
+      {
+	static int warned_once = 0;
+
+	if (!warned_once)
+	  {
+	    warned_once = 1;
+	    WARN ((0, 0, _("\
+Attempting extraction of symbolic links as hard links")));
+	  }
+      }
+      /* Fall through.  */
+
+#endif /* not S_ISLNK */
+
+    case LNKTYPE:
+      if (to_stdout_option)
+	break;
+
+      if (unlink_first_option)
+	remove_any_file (CURRENT_FILE_NAME, recursive_unlink_option);
+
     again_link:
       {
 	struct stat st1, st2;
 
-	check = link (current_link_name, skipcrud + current_file_name);
+	/* MSDOS does not implement links.  However, djgpp's link() actually
+	   copies the file.  */
+	status = link (current_link_name, CURRENT_FILE_NAME);
 
-	if (check == 0)
+	if (status == 0)
 	  break;
-	if (make_dirs (skipcrud + current_file_name))
+	if (maybe_recoverable (CURRENT_FILE_NAME))
 	  goto again_link;
-	if (f_gnudump && errno == EEXIST)
+
+	if (incremental_option && errno == EEXIST)
 	  break;
 	if (stat (current_link_name, &st1) == 0
-	    && stat (current_file_name + skipcrud, &st2) == 0
+	    && stat (CURRENT_FILE_NAME, &st2) == 0
 	    && st1.st_dev == st2.st_dev
 	    && st1.st_ino == st2.st_ino)
 	  break;
-	msg_perror ("Could not link %s to %s",
-		    skipcrud + current_file_name,
-		    current_link_name);
-      }
-      break;
 
-#ifdef S_ISLNK
-    case LF_SYMLINK:
-    again_symlink:
-      check = symlink (current_link_name,
-		       skipcrud + current_file_name);
-      /* FIXME, don't worry uid, gid, etc... */
-      if (check == 0)
-	break;
-      if (make_dirs (current_file_name + skipcrud))
-	goto again_symlink;
-      msg_perror ("Could not create symlink to %s",
-		  current_link_name);
+	ERROR ((0, errno, _("%s: Could not link to `%s'"),
+		CURRENT_FILE_NAME, current_link_name));
+	if (backup_option)
+	  undo_last_backup ();
+      }
       break;
-#endif
 
-#ifdef S_IFCHR
-    case LF_CHR:
-      hstat.st_mode |= S_IFCHR;
+#if S_IFCHR
+    case CHRTYPE:
+      current_stat.st_mode |= S_IFCHR;
       goto make_node;
 #endif
 
-#ifdef S_IFBLK
-    case LF_BLK:
-      hstat.st_mode |= S_IFBLK;
+#if S_IFBLK
+    case BLKTYPE:
+      current_stat.st_mode |= S_IFBLK;
 #endif
+
 #if defined(S_IFCHR) || defined(S_IFBLK)
     make_node:
-      check = mknod (current_file_name + skipcrud,
-		     (int) hstat.st_mode, (int) hstat.st_rdev);
-      if (check != 0)
+      if (to_stdout_option)
+	break;
+
+      if (unlink_first_option)
+	remove_any_file (CURRENT_FILE_NAME, recursive_unlink_option);
+
+      status = mknod (CURRENT_FILE_NAME, (int) current_stat.st_mode,
+		     (int) current_stat.st_rdev);
+      if (status != 0)
 	{
-	  if (make_dirs (skipcrud + current_file_name))
+	  if (maybe_recoverable (CURRENT_FILE_NAME))
 	    goto make_node;
-	  msg_perror ("Could not make %s",
-		      current_file_name + skipcrud);
+
+	  ERROR ((0, errno, _("%s: Could not make node"), CURRENT_FILE_NAME));
+	  if (backup_option)
+	    undo_last_backup ();
 	  break;
 	};
-      goto set_filestat;
+      set_stat (CURRENT_FILE_NAME, &current_stat, 0);
+      break;
 #endif
 
 #ifdef S_ISFIFO
-      /* If local system doesn't support FIFOs, use default case */
-    case LF_FIFO:
-    make_fifo:
-      check = mkfifo (current_file_name + skipcrud,
-		      (int) hstat.st_mode);
-      if (check != 0)
-	{
-	  if (make_dirs (current_file_name + skipcrud))
-	    goto make_fifo;
-	  msg_perror ("Could not make %s",
-		      skipcrud + current_file_name);
+    case FIFOTYPE:
+      if (to_stdout_option)
+	break;
+
+      if (unlink_first_option)
+	remove_any_file (CURRENT_FILE_NAME, recursive_unlink_option);
+
+      while (status = mkfifo (CURRENT_FILE_NAME, (int) current_stat.st_mode),
+	     status != 0)
+	if (!maybe_recoverable (CURRENT_FILE_NAME))
 	  break;
-	};
-      goto set_filestat;
+
+      if (status == 0)
+	set_stat (CURRENT_FILE_NAME, &current_stat, 0);
+      else
+	{
+	  ERROR ((0, errno, _("%s: Could not make fifo"), CURRENT_FILE_NAME));
+	  if (backup_option)
+	    undo_last_backup ();
+	}
+      break;
 #endif
 
-    case LF_DIR:
-    case LF_DUMPDIR:
-      namelen = strlen (current_file_name + skipcrud) - 1;
+    case DIRTYPE:
+    case GNUTYPE_DUMPDIR:
+      name_length = strlen (CURRENT_FILE_NAME) - 1;
+
     really_dir:
-      /* Check for trailing /, and zap as many as we find. */
-      while (namelen
-	     && current_file_name[skipcrud + namelen] == '/')
-	current_file_name[skipcrud + namelen--] = '\0';
-      if (f_gnudump)
-	{			/* Read the entry and delete files
-					   that aren't listed in the archive */
-	  gnu_restore (skipcrud);
+      /* Check for trailing /, and zap as many as we find.  */
+      while (name_length && CURRENT_FILE_NAME[name_length] == '/')
+	CURRENT_FILE_NAME[name_length--] = '\0';
+
+      if (incremental_option)
+	{
+	  /* Read the entry and delete files that aren't listed in the
+	     archive.  */
 
+	  gnu_restore (skipcrud);
 	}
-      else if (head->header.linkflag == LF_DUMPDIR)
-	skip_file ((long) (hstat.st_size));
+      else if (current_header->header.typeflag == GNUTYPE_DUMPDIR)
+	skip_file ((long) (current_stat.st_size));
 
+      if (to_stdout_option)
+	break;
 
     again_dir:
-      check = mkdir (skipcrud + current_file_name,
-		     (we_are_root ? 0 : 0300) | (int) hstat.st_mode);
-      if (check != 0)
+      status = mkdir (CURRENT_FILE_NAME,
+		     (we_are_root ? 0 : 0300) | (int) current_stat.st_mode);
+      if (status != 0)
 	{
-	  struct stat st1;
+	  /* If the directory creation fails, let's consider immediately the
+	     case where the directory already exists.  We have three good
+	     reasons for clearing out this case before attempting recovery.
+
+	     1) It would not be efficient recovering the error by deleting
+	     the directory in maybe_recoverable, then recreating it right
+	     away.  We only hope we will be able to adjust its permissions
+	     adequately, later.
+
+	     2) Removing the directory might fail if it is not empty.  By
+	     exception, this real error is traditionally not reported.
+
+	     3) Let's suppose `DIR' already exists and we are about to
+	     extract `DIR/../DIR'.  This would fail because the directory
+	     already exists, and maybe_recoverable would react by removing
+	     `DIR'.  This then would fail again because there are missing
+	     intermediate directories, and maybe_recoverable would react by
+	     creating `DIR'.  We would then have an extraction loop.  */
+
+	  if (errno == EEXIST)
+	    {
+	      struct stat st1;
+	      int saved_errno = errno;
+
+	      if (stat (CURRENT_FILE_NAME, &st1) == 0 && S_ISDIR (st1.st_mode))
+		goto check_perms;
 
-	  if (make_dirs (skipcrud + current_file_name))
+	      errno = saved_errno; /* FIXME: errno should be read-only */
+	    }
+
+	  if (maybe_recoverable (CURRENT_FILE_NAME))
 	    goto again_dir;
-	  /* If we're trying to create '.', let it be. */
-	  if (current_file_name[skipcrud + namelen] == '.' &&
-	      (namelen == 0 ||
-	       current_file_name[skipcrud + namelen - 1] == '/'))
+
+	  /* If we're trying to create '.', let it be.  */
+
+	  /* FIXME: Strange style...  */
+
+	  if (CURRENT_FILE_NAME[name_length] == '.'
+	      && (name_length == 0
+		  || CURRENT_FILE_NAME[name_length - 1] == '/'))
 	    goto check_perms;
-	  if (errno == EEXIST
-	      && stat (skipcrud + current_file_name, &st1) == 0
-	      && (S_ISDIR (st1.st_mode)))
-	    break;
-	  msg_perror ("Could not create directory %s", skipcrud + current_file_name);
+
+	  ERROR ((0, errno, _("%s: Could not create directory"),
+		  CURRENT_FILE_NAME));
+	  if (backup_option)
+	    undo_last_backup ();
 	  break;
 	}
 
     check_perms:
-      if (!we_are_root && 0300 != (0300 & (int) hstat.st_mode))
+      if (!we_are_root && 0300 != (0300 & (int) current_stat.st_mode))
 	{
-	  hstat.st_mode |= 0300;
-	  msg ("Added write and execute permission to directory %s",
-	       skipcrud + current_file_name);
+	  current_stat.st_mode |= 0300;
+	  WARN ((0, 0, _("Added write and execute permission to directory %s"),
+		 CURRENT_FILE_NAME));
 	}
 
-      /*
-       * If we are root, set the owner and group of the extracted
-       * file.  This does what is wanted both on real Unix and on
-       * System V.  If we are running as a user, we extract as that
-       * user; if running as root, we extract as the original owner.
-       */
-      if (we_are_root || f_do_chown)
-	{
-	  if (chown (skipcrud + current_file_name,
-		     hstat.st_uid, hstat.st_gid) < 0)
-	    {
-	      msg_perror ("cannot chown file %s to uid %d gid %d",
-			  skipcrud + current_file_name,
-			  hstat.st_uid, hstat.st_gid);
-	    }
-	}
+#if !MSDOS
+      /* MSDOS does not associate timestamps with directories.   In this
+	 case, no need to try delaying their restoration.  */
+
+      if (touch_option)
+
+	/* FIXME: I do not believe in this.  Ignoring time stamps does not
+	   alleviate the need of delaying the restoration of directories'
+	   mode.  Let's ponder this for a little while.  */
+
+	set_mode (CURRENT_FILE_NAME, &current_stat);
 
-      if (!f_modified)
-	{
-	  tmp = ((struct saved_dir_info *) 
-		 ck_malloc (sizeof (struct saved_dir_info)));
-	  tmp->path = (char *) ck_malloc (strlen (skipcrud 
-						  + current_file_name) + 1);
-	  strcpy (tmp->path, skipcrud + current_file_name);
-	  tmp->mode = hstat.st_mode;
-	  tmp->atime = hstat.st_atime;
-	  tmp->mtime = hstat.st_mtime;
-	  tmp->next = saved_dir_info_head;
-	  saved_dir_info_head = tmp;
-	}
       else
 	{
-	  /* This functions exactly as the code for set_filestat above. */
-	  if ((!f_keep)
-	      || (hstat.st_mode & (S_ISUID | S_ISGID | S_ISVTX)))
-	    {
-	      if (chmod (skipcrud + current_file_name,
-			 notumask & (int) hstat.st_mode) < 0)
-		{
-		  msg_perror ("cannot change mode of file %s to %lo",
-			      skipcrud + current_file_name,
-			      notumask & (int) hstat.st_mode);
-		}
-	    }
+	  data = ((struct delayed_set_stat *)
+		      xmalloc (sizeof (struct delayed_set_stat)));
+	  data->file_name = xstrdup (CURRENT_FILE_NAME);
+	  data->stat_info = current_stat;
+	  data->next = delayed_set_stat_head;
+	  delayed_set_stat_head = data;
 	}
+#endif /* !MSDOS */
       break;
 
-    case LF_VOLHDR:
-      if (f_verbose)
-	{
-	  printf ("Reading %s\n", current_file_name);
-	}
+    case GNUTYPE_VOLHDR:
+      if (verbose_option)
+	fprintf (stdlis, _("Reading %s\n"), current_file_name);
       break;
 
-    case LF_NAMES:
-      extract_mangle (head);
+    case GNUTYPE_NAMES:
+      extract_mangle ();
       break;
 
-    case LF_MULTIVOL:
-      msg ("Can't extract '%s'--file is continued from another volume\n", current_file_name);
-      skip_file ((long) hstat.st_size);
+    case GNUTYPE_MULTIVOL:
+      ERROR ((0, 0, _("\
+Cannot extract `%s' -- file is continued from another volume"),
+	      current_file_name));
+      skip_file ((long) current_stat.st_size);
+      if (backup_option)
+	undo_last_backup ();
       break;
 
-    case LF_LONGNAME:
-    case LF_LONGLINK:
-      msg ("Visible long name error\n");
-      skip_file ((long) hstat.st_size);
+    case GNUTYPE_LONGNAME:
+    case GNUTYPE_LONGLINK:
+      ERROR ((0, 0, _("Visible long name error")));
+      skip_file ((long) current_stat.st_size);
+      if (backup_option)
+	undo_last_backup ();
       break;
-    }
 
-  /* We don't need to save it any longer. */
-  saverec ((union record **) 0);/* Unsave it */
-}
-
-/*
- * After a file/link/symlink/dir creation has failed, see if
- * it's because some required directory was not present, and if
- * so, create all required dirs.
- */
-int
-make_dirs (pathname)
-     char *pathname;
-{
-  char *p;			/* Points into path */
-  int madeone = 0;		/* Did we do anything yet? */
-  int save_errno = errno;	/* Remember caller's errno */
-  int check;
-
-  if (errno != ENOENT)
-    return 0;			/* Not our problem */
-
-  for (p = index (pathname, '/'); p != NULL; p = index (p + 1, '/'))
-    {
-      /* Avoid mkdir of empty string, if leading or double '/' */
-      if (p == pathname || p[-1] == '/')
-	continue;
-      /* Avoid mkdir where last part of path is '.' */
-      if (p[-1] == '.' && (p == pathname + 1 || p[-2] == '/'))
-	continue;
-      *p = 0;			/* Truncate the path there */
-      check = mkdir (pathname, 0777);	/* Try to create it as a dir */
-      if (check == 0)
-	{
-	  /* Fix ownership */
-	  if (we_are_root)
-	    {
-	      if (chown (pathname, hstat.st_uid,
-			 hstat.st_gid) < 0)
-		{
-		  msg_perror ("cannot change owner of %s to uid %d gid %d", pathname, hstat.st_uid, hstat.st_gid);
-		}
-	    }
-	  pr_mkdir (pathname, p - pathname, notumask & 0777);
-	  madeone++;		/* Remember if we made one */
-	  *p = '/';
-	  continue;
-	}
-      *p = '/';
-      if (errno == EEXIST)	/* Directory already exists */
-	continue;
-      /*
-		 * Some other error in the mkdir.  We return to the caller.
-		 */
-      break;
+    default:
+      WARN ((0, 0,
+	     _("Unknown file type '%c' for %s, extracted as normal file"),
+	     current_header->header.typeflag, CURRENT_FILE_NAME));
+      goto again_file;
     }
 
-  errno = save_errno;		/* Restore caller's errno */
-  return madeone;		/* Tell them to retry if we made one */
+#undef CURRENT_FILE_NAME
 }
 
-void
-extract_sparse_file (fd, sizeleft, totalsize, name)
-     int fd;
-     long *sizeleft, totalsize;
-     char *name;
-{
-  /*	register char	*data;*/
-  union record *datarec;
-  int sparse_ind = 0;
-  int written, count;
-
-  /* assuming sizeleft is initially totalsize */
-
+/*----------------------------------------------------------------.
+| Set back the utime and mode for all the extracted directories.  |
+`----------------------------------------------------------------*/
 
-  while (*sizeleft > 0)
-    {
-      datarec = findrec ();
-      if (datarec == NULL)
-	{
-	  msg ("Unexpected EOF on archive file");
-	  return;
-	}
-      lseek (fd, sparsearray[sparse_ind].offset, 0);
-      written = sparsearray[sparse_ind++].numbytes;
-      while (written > RECORDSIZE)
-	{
-	  count = write (fd, datarec->charptr, RECORDSIZE);
-	  if (count < 0)
-	    msg_perror ("couldn't write to file %s", name);
-	  written -= count;
-	  *sizeleft -= count;
-	  userec (datarec);
-	  datarec = findrec ();
-	}
-
-      count = write (fd, datarec->charptr, written);
-
-      if (count < 0)
-	{
-	  msg_perror ("couldn't write to file %s", name);
-	}
-      else if (count != written)
-	{
-	  msg ("could only write %d of %d bytes to file %s", count, 
-	       totalsize, name);
-	  skip_file ((long) (*sizeleft));
-	}
-
-      written -= count;
-      *sizeleft -= count;
-      userec (datarec);
-    }
-  free (sparsearray);
-  /*	if (end_nulls) {
-		register int i;
-
-		printf("%d\n", (int) end_nulls);
-		for (i = 0; i < end_nulls; i++)
-			write(fd, "\000", 1);
-	}*/
-  userec (datarec);
-}
-
-/* Set back the utime and mode for all the extracted directories. */
-void 
-restore_saved_dir_info ()
+void
+apply_delayed_set_stat (void)
 {
-  struct utimbuf acc_upd_times;
+  struct delayed_set_stat *data;
 
-  while (saved_dir_info_head != NULL)
+  while (delayed_set_stat_head != NULL)
     {
-      /* fixme if f_gnudump should set ctime too, but how? */
-      if (f_gnudump)
-	acc_upd_times.actime = saved_dir_info_head->atime;
-      else
-	acc_upd_times.actime = now;	/* Accessed now */
-      acc_upd_times.modtime = saved_dir_info_head->mtime;	/* Mod'd */
-      if (utime (saved_dir_info_head->path, &acc_upd_times) < 0)
-	{
-	  msg_perror ("couldn't change access and modification times of %s",
-		      saved_dir_info_head->path);
-	}
-      if ((!f_keep) || (saved_dir_info_head->mode & (S_ISUID | S_ISGID | S_ISVTX)))
-	{
-	  if (chmod (saved_dir_info_head->path,
-		     notumask & saved_dir_info_head->mode) < 0)
-	    {
-	      msg_perror ("cannot change mode of file %s to %lo",
-			  saved_dir_info_head->path,
-			  notumask & saved_dir_info_head->mode);
-	    }
-	}
-      saved_dir_info_head = saved_dir_info_head->next;
+      data = delayed_set_stat_head;
+      delayed_set_stat_head = delayed_set_stat_head->next;
+      set_stat (data->file_name, &data->stat_info, 0);
+      free (data->file_name);
+      free (data);
     }
 }