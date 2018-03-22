 /* Buffer management for tar.
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
- * Buffer management for tar.
- *
- * Written by John Gilmore, ihnp4!hoptoad!gnu, on 25 August 1985.
- */
-
-#include <stdio.h>
-#include <errno.h>
-#ifndef STDC_HEADERS
-extern int errno;
-#endif
-#include <sys/types.h>		/* For non-Berkeley systems */
+   Copyright (C) 1988, 92, 93, 94, 96, 97 Free Software Foundation, Inc.
+   Written by John Gilmore, on 1985-08-25.
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
 #include <signal.h>
 #include <time.h>
 time_t time ();
 
-#ifdef HAVE_SYS_MTIO_H
-#include <sys/ioctl.h>
-#include <sys/mtio.h>
+#if MSDOS
+# include <process.h>
 #endif
 
-#ifdef BSD42
-#include <sys/file.h>
-#else
-#ifndef V7
-#include <fcntl.h>
-#endif
+#if XENIX
+# include <sys/inode.h>
 #endif
 
-#ifdef	__MSDOS__
-#include <process.h>
+#ifndef FNM_LEADING_DIR
+# include <fnmatch.h>
 #endif
 
-#ifdef XENIX
-#include <sys/inode.h>
-#endif
-
-#include "tar.h"
-#include "port.h"
+#include "common.h"
 #include "rmt.h"
-#include "regex.h"
 
-/* Either stdout or stderr:  The thing we write messages (standard msgs, not
-   errors) to.  Stdout unless we're writing a pipe, in which case stderr */
-FILE *msg_file = stdout;
+#define DEBUG_FORK 0		/* if nonzero, childs are born stopped */
+
+#define	STDIN 0			/* standard input  file descriptor */
+#define	STDOUT 1		/* standard output file descriptor */
+
+#define	PREAD 0			/* read file descriptor from pipe() */
+#define	PWRITE 1		/* write file descriptor from pipe() */
 
-#define	STDIN	0		/* Standard input  file descriptor */
-#define	STDOUT	1		/* Standard output file descriptor */
+/* Number of retries before giving up on read.  */
+#define	READ_ERROR_MAX 10
 
-#define	PREAD	0		/* Read  file descriptor from pipe() */
-#define	PWRITE	1		/* Write file descriptor from pipe() */
+/* Globbing pattern to append to volume label if initial match failed.  */
+#define VOLUME_LABEL_APPEND " Volume [1-9]*"
+
+/* Variables.  */
 
-#define	MAGIC_STAT	105	/* Magic status returned by child, if
-				   it can't exec.  We hope compress/sh
-				   never return this status! */
+static tarlong total_written;	/* bytes written on all volumes */
+static tarlong bytes_written;	/* bytes written on this volume */
 
-void *valloc ();
+/* FIXME: The following four variables should ideally be static to this
+   module.  However, this cannot be done yet, as update.c uses the first
+   three a lot, and compare.c uses the fourth.  The cleanup continues!  */
 
-void writeerror ();
-void readerror ();
+union block *record_start;	/* start of record of archive */
+union block *record_end;	/* last+1 block of archive record */
+union block *current_block;	/* current block of archive */
+enum access_mode access_mode;	/* how do we handle the archive */
+static struct stat archive_stat; /* stat block for archive file */
 
-void ck_pipe ();
-void ck_close ();
+static long record_start_block; /* block ordinal at record_start */
 
-int backspace_output ();
-extern void finish_header ();
-void flush_archive ();
-int isfile ();
-int new_volume ();
-void verify_volume ();
-extern void to_oct ();
+/* Where we write list messages (not errors, not interactions) to.  Stdout
+   unless we're writing a pipe, in which case stderr.  */
+FILE *stdlis;
 
-#ifndef __MSDOS__
-/* Obnoxious test to see if dimwit is trying to dump the archive */
+static void backspace_output PARAMS ((void));
+static int new_volume PARAMS ((enum access_mode));
+static void write_error PARAMS ((int));
+static void read_error PARAMS ((void));
+
+#if !MSDOS
+/* Obnoxious test to see if dimwit is trying to dump the archive.  */
 dev_t ar_dev;
 ino_t ar_ino;
 #endif
 
-/*
- * The record pointed to by save_rec should not be overlaid
- * when reading in a new tape block.  Copy it to record_save_area first, and
- * change the pointer in *save_rec to point to record_save_area.
- * Saved_recno records the record number at the time of the save.
- * This is used by annofile() to print the record number of a file's
- * header record.
- */
-static union record **save_rec;
-union record record_save_area;
-static long saved_recno;
-
-/*
- * PID of child program, if f_compress or remote archive access.
- */
-static int childpid = 0;
-
-/*
- * Record number of the start of this block of records
- */
-long baserec;
-
-/*
- * Error recovery stuff
- */
-static int r_error_count;
-
-/*
- * Have we hit EOF yet?
- */
+/* PID of child program, if compress_option or remote archive access.  */
+static int child_pid = 0;
+
+/* Error recovery stuff  */
+static int read_error_count;
+
+/* Have we hit EOF yet?  */
 static int hit_eof;
 
 /* Checkpointing counter */
 static int checkpoint;
 
-/* JF we're reading, but we just read the last record and its time to update */
-extern time_to_start_writing;
-int file_to_switch_to = -1;	/* If remote update, close archive, and use
+/* We're reading, but we just read the last block and its time to update.  */
+/* As least EXTERN like this one as possible.  FIXME!  */
+extern int time_to_start_writing;
+
+int file_to_switch_to = -1;	/* if remote update, close archive, and use
 				   this descriptor to write to */
 
-static int volno = 1;		/* JF which volume of a multi-volume tape
-				   we're on */
-static int global_volno = 1;	/* Volume number to print in external messages. */
+static int volno = 1;		/* which volume of a multi-volume tape we're
+				   on */
+static int global_volno = 1;	/* volume number to print in external
+				   messages */
+
+/* The pointer save_name, which is set in function dump_file() of module
+   create.c, points to the original long filename instead of the new,
+   shorter mangled name that is set in start_header() of module create.c.
+   The pointer save_name is only used in multi-volume mode when the file
+   being processed is non-sparse; if a file is split between volumes, the
+   save_name is used in generating the LF_MULTIVOL record on the second
+   volume.  (From Pierce Cantrell, 1991-08-13.)  */
+
+char *save_name;		/* name of the file we are currently writing */
+long save_totsize;		/* total size of file we are writing, only
+				   valid if save_name is non NULL */
+long save_sizeleft;		/* where we are in the file we are writing,
+				   only valid if save_name is nonzero */
+
+int write_archive_to_stdout = 0;
+
+/* Used by flush_read and flush_write to store the real info about saved
+   names.  */
+static char *real_s_name = NULL;
+static long real_s_totsize;
+static long real_s_sizeleft;
+
+/* Functions.  */
 
-char *save_name = 0;		/* Name of the file we are currently writing */
-long save_totsize;		/* total size of file we are writing.  Only
-				   valid if save_name is non_zero */
-long save_sizeleft;		/* Where we are in the file we are writing.
-				   Only valid if save_name is non-zero */
+#if DEBUG_FORK
 
-int write_archive_to_stdout;
+static pid_t
+myfork (void)
+{
+  pid_t result = fork();
 
-/* Used by fl_read and fl_write to store the real info about saved names */
-static char real_s_name[NAMSIZ];
-static long real_s_totsize;
-static long real_s_sizeleft;
+  if (result == 0)
+    kill (getpid (), SIGSTOP);
+  return result;
+}
+
+# define fork myfork
+
+#endif /* DEBUG FORK */
+
+void
+init_total_written (void)
+{
+  clear_tarlong (total_written);
+  clear_tarlong (bytes_written);
+}
+
+void
+print_total_written (void)
+{
+  fprintf (stderr, _("Total bytes written: "));
+  print_tarlong (total_written, stderr);
+  fprintf (stderr, "\n");
+}
+
+/*--------------------------------------------------------.
+| Compute and return the block ordinal at current_block.  |
+`--------------------------------------------------------*/
 
-/* Reset the EOF flag (if set), and re-set ar_record, etc */
+long
+current_block_ordinal (void)
+{
+  return record_start_block + (current_block - record_start);
+}
+
+/*------------------------------------------------------------------.
+| If the EOF flag is set, reset it, as well as current_block, etc.  |
+`------------------------------------------------------------------*/
 
 void
-reset_eof ()
+reset_eof (void)
 {
   if (hit_eof)
     {
       hit_eof = 0;
-      ar_record = ar_block;
-      ar_last = ar_block + blocking;
-      ar_reading = 0;
+      current_block = record_start;
+      record_end = record_start + blocking_factor;
+      access_mode = ACCESS_WRITE;
     }
 }
 
-/*
- * Return the location of the next available input or output record.
- * Return NULL for EOF.  Once we have returned NULL, we just keep returning
- * it, to avoid accidentally going on to the next file on the "tape".
- */
-union record *
-findrec ()
+/*-------------------------------------------------------------------------.
+| Return the location of the next available input or output block.	   |
+| Return NULL for EOF.  Once we have returned NULL, we just keep returning |
+| it, to avoid accidentally going on to the next file on the tape.	   |
+`-------------------------------------------------------------------------*/
+
+union block *
+find_next_block (void)
 {
-  if (ar_record == ar_last)
+  if (current_block == record_end)
     {
       if (hit_eof)
-	return (union record *) NULL;	/* EOF */
+	return NULL;
       flush_archive ();
-      if (ar_record == ar_last)
+      if (current_block == record_end)
 	{
-	  hit_eof++;
-	  return (union record *) NULL;	/* EOF */
+	  hit_eof = 1;
+	  return NULL;
 	}
     }
-  return ar_record;
+  return current_block;
 }
 
+/*------------------------------------------------------.
+| Indicate that we have used all blocks up thru BLOCK.  |
+| 						        |
+| FIXME: should the arg have an off-by-1?	        |
+`------------------------------------------------------*/
 
-/*
- * Indicate that we have used all records up thru the argument.
- * (should the arg have an off-by-1? XXX FIXME)
- */
 void
-userec (rec)
-     union record *rec;
+set_next_block_after (union block *block)
 {
-  while (rec >= ar_record)
-    ar_record++;
-  /*
-	 * Do NOT flush the archive here.  If we do, the same
-	 * argument to userec() could mean the next record (if the
-	 * input block is exactly one record long), which is not what
-	 * is intended.
-	 */
-  if (ar_record > ar_last)
+  while (block >= current_block)
+    current_block++;
+
+  /* Do *not* flush the archive here.  If we do, the same argument to
+     set_next_block_after could mean the next block (if the input record
+     is exactly one block long), which is not what is intended.  */
+
+  if (current_block > record_end)
     abort ();
 }
 
+/*------------------------------------------------------------------------.
+| Return the number of bytes comprising the space between POINTER through |
+| the end of the current buffer of blocks.  This space is available for	  |
+| filling with data, or taking data from.  POINTER is usually (but not	  |
+| always) the result previous find_next_block call.			  |
+`------------------------------------------------------------------------*/
 
-/*
- * Return a pointer to the end of the current records buffer.
- * All the space between findrec() and endofrecs() is available
- * for filling with data, or taking data from.
- */
-union record *
-endofrecs ()
+int
+available_space_after (union block *pointer)
 {
-  return ar_last;
+  return (int) (record_end->buffer - pointer->buffer);
 }
 
+/*------------------------------------------------------------------.
+| Close file having descriptor FD, and abort if close unsucessful.  |
+`------------------------------------------------------------------*/
 
-/*
- * Duplicate a file descriptor into a certain slot.
- * Equivalent to BSD "dup2" with error reporting.
- */
-void
-dupto (from, to, msg)
-     int from, to;
-     char *msg;
+static void
+xclose (int fd)
 {
-  int err;
+  if (close (fd) < 0)
+    FATAL_ERROR ((0, errno, _("Cannot close file #%d"), fd));
+}
+
+/*-----------------------------------------------------------------------.
+| Duplicate file descriptor FROM into becoming INTO, or else, issue	 |
+| MESSAGE.  INTO is closed first and has to be the next available slot.	 |
+`-----------------------------------------------------------------------*/
 
-  if (from != to)
+static void
+xdup2 (int from, int into, const char *message)
+{
+  if (from != into)
     {
-      err = close (to);
-      if (err < 0 && errno != EBADF)
-	{
-	  msg_perror ("Cannot close descriptor %d", to);
-	  exit (EX_SYSTEM);
-	}
-      err = dup (from);
-      if (err != to)
-	{
-	  msg_perror ("cannot dup %s", msg);
-	  exit (EX_SYSTEM);
-	}
-      ck_close (from);
+      int status = close (into);
+
+      if (status < 0 && errno != EBADF)
+	FATAL_ERROR ((0, errno, _("Cannot close descriptor %d"), into));
+      status = dup (from);
+      if (status != into)
+	FATAL_ERROR ((0, errno, _("Cannot properly duplicate %s"), message));
+      xclose (from);
     }
 }
 
-#ifdef __MSDOS__
-void
-child_open ()
+#if MSDOS
+
+/*-------------------------------------------------------.
+| Set ARCHIVE for writing, then compressing an archive.	 |
+`-------------------------------------------------------*/
+
+static void
+child_open_for_compress (void)
 {
-  fprintf (stderr, "MS-DOS %s can't use compressed or remote archives\n", tar);
-  exit (EX_ARGSBAD);
+  FATAL_ERROR ((0, 0, _("Cannot use compressed or remote archives")));
 }
 
-#else
-void
-child_open ()
+/*---------------------------------------------------------.
+| Set ARCHIVE for uncompressing, then reading an archive.  |
+`---------------------------------------------------------*/
+
+static void
+child_open_for_uncompress (void)
 {
-  int pipe[2];
-  int err = 0;
+  FATAL_ERROR ((0, 0, _("Cannot use compressed or remote archives")));
+}
 
-  int kidpipe[2];
-  int kidchildpid;
+#else /* not MSDOS */
 
-#define READ	0
-#define WRITE	1
+/*---------------------------------------------------------------------.
+| Return nonzero if NAME is the name of a regular file, or if the file |
+| does not exist (so it would be created as a regular file).	       |
+`---------------------------------------------------------------------*/
 
-  ck_pipe (pipe);
+static int
+is_regular_file (const char *name)
+{
+  struct stat stbuf;
 
-  childpid = fork ();
-  if (childpid < 0)
+  if (stat (name, &stbuf) < 0)
+    return 1;
+
+  if (S_ISREG (stbuf.st_mode))
+    return 1;
+
+  return 0;
+}
+
+/*-------------------------------------------------------.
+| Set ARCHIVE for writing, then compressing an archive.	 |
+`-------------------------------------------------------*/
+
+static void
+child_open_for_compress (void)
+{
+  int parent_pipe[2];
+  int child_pipe[2];
+  int grandchild_pid;
+
+  if (pipe (parent_pipe) < 0)
+    FATAL_ERROR ((0, errno, _("Cannot open pipe")));
+
+  child_pid = fork ();
+  if (child_pid < 0)
+    FATAL_ERROR ((0, errno, _("Cannot fork")));
+
+  if (child_pid > 0)
     {
-      msg_perror ("cannot fork");
-      exit (EX_SYSTEM);
+      /* The parent tar is still here!  Just clean up.  */
+
+      archive = parent_pipe[PWRITE];
+      xclose (parent_pipe[PREAD]);
+      return;
     }
-  if (childpid > 0)
+
+  /* The new born child tar is here!  */
+
+  program_name = _("tar (child)");
+
+  xdup2 (parent_pipe[PREAD], STDIN, _("(child) Pipe to stdin"));
+  xclose (parent_pipe[PWRITE]);
+
+  /* Check if we need a grandchild tar.  This happens only if either:
+     a) we are writing stdout: to force reblocking;
+     b) the file is to be accessed by rmt: compressor doesn't know how;
+     c) the file is not a plain file.  */
+
+  if (strcmp (archive_name_array[0], "-") != 0
+      && !_remdev (archive_name_array[0])
+      && is_regular_file (archive_name_array[0]))
     {
-      /* We're the parent.  Clean up and be happy */
-      /* This, at least, is easy */
+      if (backup_option)
+	maybe_backup_file (archive_name_array[0], 1);
 
-      if (ar_reading)
-	{
-	  f_reblock++;
-	  archive = pipe[READ];
-	  ck_close (pipe[WRITE]);
-	}
-      else
+      /* We don't need a grandchild tar.  Open the archive and launch the
+	 compressor.  */
+
+      archive = creat (archive_name_array[0], 0666);
+      if (archive < 0)
 	{
-	  archive = pipe[WRITE];
-	  ck_close (pipe[READ]);
+	  int saved_errno = errno;
+
+	  if (backup_option)
+	    undo_last_backup ();
+	  FATAL_ERROR ((0, saved_errno, _("Cannot open archive %s"),
+			archive_name_array[0]));
 	}
-      return;
+      xdup2 (archive, STDOUT, _("Archive to stdout"));
+      execlp (use_compress_program_option, use_compress_program_option,
+	      (char *) 0);
+      FATAL_ERROR ((0, errno, _("Cannot exec %s"),
+		    use_compress_program_option));
     }
 
-  /* We're the kid */
-  if (ar_reading)
+  /* We do need a grandchild tar.  */
+
+  if (pipe (child_pipe) < 0)
+    FATAL_ERROR ((0, errno, _("Cannot open pipe")));
+
+  grandchild_pid = fork ();
+  if (grandchild_pid < 0)
+    FATAL_ERROR ((0, errno, _("Child cannot fork")));
+
+  if (grandchild_pid > 0)
     {
-      dupto (pipe[WRITE], STDOUT, "(child) pipe to stdout");
-      ck_close (pipe[READ]);
+      /* The child tar is still here!  Launch the compressor.  */
+
+      xdup2 (child_pipe[PWRITE], STDOUT, _("((child)) Pipe to stdout"));
+      xclose (child_pipe[PREAD]);
+      execlp (use_compress_program_option, use_compress_program_option,
+	      (char *) 0);
+      FATAL_ERROR ((0, errno, _("Cannot exec %s"),
+		    use_compress_program_option));
     }
+
+  /* The new born grandchild tar is here!  */
+
+  program_name = _("tar (grandchild)");
+
+  /* Prepare for reblocking the data from the compressor into the archive.  */
+
+  xdup2 (child_pipe[PREAD], STDIN, _("(grandchild) Pipe to stdin"));
+  xclose (child_pipe[PWRITE]);
+
+  if (strcmp (archive_name_array[0], "-") == 0)
+    archive = STDOUT;
   else
-    {
-      dupto (pipe[READ], STDIN, "(child) pipe to stdin");
-      ck_close (pipe[WRITE]);
-    }
+    archive = rmtcreat (archive_name_array[0], 0666, rsh_command_option);
+  if (archive < 0)
+    FATAL_ERROR ((0, errno, _("Cannot open archive %s"),
+		  archive_name_array[0]));
 
-  /* We need a child tar only if
-	   1: we're reading/writing stdin/out (to force reblocking)
-	   2: the file is to be accessed by rmt (compress doesn't know how)
-	   3: the file is not a plain file */
-#ifdef NO_REMOTE
-  if (!(ar_files[0][0] == '-' && ar_files[0][1] == '\0') && isfile (ar_files[0]))
-#else
-  if (!(ar_files[0][0] == '-' && ar_files[0][1] == '\0') && !_remdev (ar_files[0]) && isfile (ar_files[0]))
-#endif
+  /* Let's read out of the stdin pipe and write an archive.  */
+
+  while (1)
     {
-      /* We don't need a child tar.  Open the archive */
-      if (ar_reading)
+      int status = 0;
+      char *cursor;
+      int length;
+
+      /* Assemble a record.  */
+
+      for (length = 0, cursor = record_start->buffer;
+	   length < record_size;
+	   length += status, cursor += status)
 	{
-	  archive = open (ar_files[0], O_RDONLY | O_BINARY, 0666);
-	  if (archive < 0)
-	    {
-	      msg_perror ("can't open archive %s", ar_files[0]);
-	      exit (EX_BADARCH);
-	    }
-	  dupto (archive, STDIN, "archive to stdin");
-	  /* close(archive); */
+	  int size = record_size - length;
+
+	  if (size < BLOCKSIZE)
+	    size = BLOCKSIZE;
+	  status = read (STDIN, cursor, (size_t) size);
+	  if (status <= 0)
+	    break;
 	}
-      else
+
+      if (status < 0)
+	FATAL_ERROR ((0, errno, _("Cannot read from compression program")));
+
+      /* Copy the record.  */
+
+      if (status == 0)
 	{
-	  archive = creat (ar_files[0], 0666);
-	  if (archive < 0)
+	  /* We hit the end of the file.  Write last record at
+	     full length, as the only role of the grandchild is
+	     doing proper reblocking.  */
+
+	  if (length > 0)
 	    {
-	      msg_perror ("can't open archive %s", ar_files[0]);
-	      exit (EX_BADARCH);
+	      memset (record_start->buffer + length, 0,
+		      (size_t) record_size - length);
+	      status = rmtwrite (archive, record_start->buffer,
+				 (unsigned int) record_size);
+	      if (status != record_size)
+		write_error (status);
 	    }
-	  dupto (archive, STDOUT, "archive to stdout");
-	  /* close(archive); */
+
+	  /* There is nothing else to read, break out.  */
+	  break;
 	}
+
+      status = rmtwrite (archive, record_start->buffer,
+			 (unsigned int) record_size);
+      if (status != record_size)
+ 	write_error (status);
+    }
+
+#if 0
+  close_archive ();
+#endif
+  exit (exit_status);
+}
+
+/*---------------------------------------------------------.
+| Set ARCHIVE for uncompressing, then reading an archive.  |
+`---------------------------------------------------------*/
+
+static void
+child_open_for_uncompress (void)
+{
+  int parent_pipe[2];
+  int child_pipe[2];
+  int grandchild_pid;
+
+  if (pipe (parent_pipe) < 0)
+    FATAL_ERROR ((0, errno, _("Cannot open pipe")));
+
+  child_pid = fork ();
+  if (child_pid < 0)
+    FATAL_ERROR ((0, errno, _("Cannot fork")));
+
+  if (child_pid > 0)
+    {
+      /* The parent tar is still here!  Just clean up.  */
+
+      read_full_records_option = 1;
+      archive = parent_pipe[PREAD];
+      xclose (parent_pipe[PWRITE]);
+      return;
+    }
+
+  /* The new born child tar is here!  */
+
+  program_name = _("tar (child)");
+
+  xdup2 (parent_pipe[PWRITE], STDOUT, _("(child) Pipe to stdout"));
+  xclose (parent_pipe[PREAD]);
+
+  /* Check if we need a grandchild tar.  This happens only if either:
+     a) we're reading stdin: to force unblocking;
+     b) the file is to be accessed by rmt: compressor doesn't know how;
+     c) the file is not a plain file.  */
+
+  if (strcmp (archive_name_array[0], "-") != 0
+      && !_remdev (archive_name_array[0])
+      && is_regular_file (archive_name_array[0]))
+    {
+      /* We don't need a grandchild tar.  Open the archive and lauch the
+	 uncompressor.  */
+
+      archive = open (archive_name_array[0], O_RDONLY | O_BINARY, 0666);
+      if (archive < 0)
+	FATAL_ERROR ((0, errno, _("Cannot open archive %s"),
+		      archive_name_array[0]));
+      xdup2 (archive, STDIN, _("Archive to stdin"));
+      execlp (use_compress_program_option, use_compress_program_option,
+	      "-d", (char *) 0);
+      FATAL_ERROR ((0, errno, _("Cannot exec %s"),
+		    use_compress_program_option));
     }
+
+  /* We do need a grandchild tar.  */
+
+  if (pipe (child_pipe) < 0)
+    FATAL_ERROR ((0, errno, _("Cannot open pipe")));
+
+  grandchild_pid = fork ();
+  if (grandchild_pid < 0)
+    FATAL_ERROR ((0, errno, _("Child cannot fork")));
+
+  if (grandchild_pid > 0)
+    {
+      /* The child tar is still here!  Launch the uncompressor.  */
+
+      xdup2 (child_pipe[PREAD], STDIN, _("((child)) Pipe to stdin"));
+      xclose (child_pipe[PWRITE]);
+      execlp (use_compress_program_option, use_compress_program_option,
+	      "-d", (char *) 0);
+      FATAL_ERROR ((0, errno, _("Cannot exec %s"),
+		    use_compress_program_option));
+    }
+
+  /* The new born grandchild tar is here!  */
+
+  program_name = _("tar (grandchild)");
+
+  /* Prepare for unblocking the data from the archive into the uncompressor.  */
+
+  xdup2 (child_pipe[PWRITE], STDOUT, _("(grandchild) Pipe to stdout"));
+  xclose (child_pipe[PREAD]);
+
+  if (strcmp (archive_name_array[0], "-") == 0)
+    archive = STDIN;
   else
+    archive = rmtopen (archive_name_array[0], O_RDONLY | O_BINARY,
+		       0666, rsh_command_option);
+  if (archive < 0)
+    FATAL_ERROR ((0, errno, _("Cannot open archive %s"),
+		  archive_name_array[0]));
+
+  /* Let's read the archive and pipe it into stdout.  */
+
+  while (1)
     {
-      /* We need a child tar */
-      ck_pipe (kidpipe);
+      char *cursor;
+      int maximum;
+      int count;
+      int status;
 
-      kidchildpid = fork ();
-      if (kidchildpid < 0)
-	{
-	  msg_perror ("child can't fork");
-	  exit (EX_SYSTEM);
-	}
+      read_error_count = 0;
 
-      if (kidchildpid > 0)
+    error_loop:
+      status = rmtread (archive, record_start->buffer,
+			(unsigned int) (record_size));
+      if (status < 0)
 	{
-	  /* About to exec compress:  set up the files */
-	  if (ar_reading)
-	    {
-	      dupto (kidpipe[READ], STDIN, "((child)) pipe to stdin");
-	      ck_close (kidpipe[WRITE]);
-	      /* dup2(pipe[WRITE],STDOUT); */
-	    }
-	  else
-	    {
-	      /* dup2(pipe[READ],STDIN); */
-	      dupto (kidpipe[WRITE], STDOUT, "((child)) pipe to stdout");
-	      ck_close (kidpipe[READ]);
-	    }
-	  /* ck_close(pipe[READ]); */
-	  /* ck_close(pipe[WRITE]); */
-	  /* ck_close(kidpipe[READ]);
-			ck_close(kidpipe[WRITE]); */
+	  read_error ();
+	  goto error_loop;
 	}
-      else
+      if (status == 0)
+	break;
+      cursor = record_start->buffer;
+      maximum = status;
+      while (maximum)
 	{
-	  /* Grandchild.  Do the right thing, namely sit here and
-		   read/write the archive, and feed stuff back to compress */
-	  tar = "tar (child)";
-	  if (ar_reading)
-	    {
-	      dupto (kidpipe[WRITE], STDOUT, "[child] pipe to stdout");
-	      ck_close (kidpipe[READ]);
-	    }
-	  else
-	    {
-	      dupto (kidpipe[READ], STDIN, "[child] pipe to stdin");
-	      ck_close (kidpipe[WRITE]);
-	    }
+	  count = maximum < BLOCKSIZE ? maximum : BLOCKSIZE;
+	  status = write (STDOUT, cursor, (size_t) count);
+	  if (status < 0)
+	    FATAL_ERROR ((0, errno, _("\
+Cannot write to compression program")));
 
-	  if (ar_files[0][0] == '-' && ar_files[0][1] == '\0')
+	  if (status != count)
 	    {
-	      if (ar_reading)
-		archive = STDIN;
-	      else
-		archive = STDOUT;
+	      ERROR ((0, 0, _("\
+Write to compression program short %d bytes"),
+		      count - status));
+	      count = status;
 	    }
-	  else			/* This can't happen if (ar_reading==2)
-				archive = rmtopen(ar_files[0], O_RDWR|O_CREAT|O_BINARY, 0666);
-	  	  			else */ if (ar_reading)
-	    archive = rmtopen (ar_files[0], O_RDONLY | O_BINARY, 0666);
-	  else
-	    archive = rmtcreat (ar_files[0], 0666);
 
-	  if (archive < 0)
-	    {
-	      msg_perror ("can't open archive %s", ar_files[0]);
-	      exit (EX_BADARCH);
-	    }
-
-	  if (ar_reading)
-	    {
-	      for (;;)
-		{
-		  char *ptr;
-		  int max, count;
-
-		  r_error_count = 0;
-		error_loop:
-		  err = rmtread (archive, ar_block->charptr, (int) (blocksize));
-		  if (err < 0)
-		    {
-		      readerror ();
-		      goto error_loop;
-		    }
-		  if (err == 0)
-		    break;
-		  ptr = ar_block->charptr;
-		  max = err;
-		  while (max)
-		    {
-		      count = (max < RECORDSIZE) ? max : RECORDSIZE;
-		      err = write (STDOUT, ptr, count);
-		      if (err != count)
-			{
-			  if (err < 0)
-			    {
-			      msg_perror ("can't write to compression program");
-			      exit (EX_SYSTEM);
-			    }
-			  else
-			    msg ("write to compression program short %d bytes",
-				 count - err);
-			  count = (err < 0) ? 0 : err;
-			}
-		      ptr += count;
-		      max -= count;
-		    }
-		}
-	    }
-	  else
-	    {
-	      for (;;)
-		{
-		  int n;
-		  char *ptr;
-
-		  n = blocksize;
-		  ptr = ar_block->charptr;
-		  while (n)
-		    {
-		      err = read (STDIN, ptr, (n < RECORDSIZE) ? n : RECORDSIZE);
-		      if (err <= 0)
-			break;
-		      n -= err;
-		      ptr += err;
-		    }
-		  /* EOF */
-		  if (err == 0)
-		    {
-		      if (!f_compress_block)
-			blocksize -= n;
-		      else
-			bzero (ar_block->charptr + blocksize - n, n);
-		      err = rmtwrite (archive, ar_block->charptr, blocksize);
-		      if (err != (blocksize))
-			writeerror (err);
-		      if (!f_compress_block)
-			blocksize += n;
-		      break;
-		    }
-		  if (n)
-		    {
-		      msg_perror ("can't read from compression program");
-		      exit (EX_SYSTEM);
-		    }
-		  err = rmtwrite (archive, ar_block->charptr, (int) blocksize);
-		  if (err != blocksize)
-		    writeerror (err);
-		}
-	    }
-
-	  /* close_archive(); */
-	  exit (0);
+	  cursor += count;
+	  maximum -= count;
 	}
     }
-  /* So we should exec compress (-d) */
-  if (ar_reading)
-    execlp (f_compressprog, f_compressprog, "-d", (char *) 0);
-  else
-    execlp (f_compressprog, f_compressprog, (char *) 0);
-  msg_perror ("can't exec %s", f_compressprog);
-  _exit (EX_SYSTEM);
+
+#if 0
+  close_archive ();
+#endif
+  exit (exit_status);
 }
 
+#endif /* not MSDOS */
 
-/* return non-zero if p is the name of a directory */
-int
-isfile (p)
-     char *p;
+/*--------------------------------------------------------------------------.
+| Check the LABEL block against the volume label, seen as a globbing	    |
+| pattern.  Return true if the pattern matches.  In case of failure, retry  |
+| matching a volume sequence number before giving up in multi-volume mode.  |
+`--------------------------------------------------------------------------*/
+
+static int
+check_label_pattern (union block *label)
 {
-  struct stat stbuf;
+  char *string;
+  int result;
 
-  if (stat (p, &stbuf) < 0)
+  if (fnmatch (volume_label_option, label->header.name, 0) == 0)
     return 1;
-  if (S_ISREG (stbuf.st_mode))
-    return 1;
-  return 0;
+
+  if (!multi_volume_option)
+    return 0;
+
+  string = xmalloc (strlen (volume_label_option)
+		    + sizeof VOLUME_LABEL_APPEND + 1);
+  strcpy (string, volume_label_option);
+  strcat (string, VOLUME_LABEL_APPEND);
+  result = fnmatch (string, label->header.name, 0) == 0;
+  free (string);
+  return result;
 }
 
-#endif
+/*------------------------------------------------------------------------.
+| Open an archive file.  The argument specifies whether we are reading or |
+| writing, or both.							  |
+`------------------------------------------------------------------------*/
 
-/*
- * Open an archive file.  The argument specifies whether we are
- * reading or writing.
- */
-/* JF if the arg is 2, open for reading and writing. */
 void
-open_archive (reading)
-     int reading;
+open_archive (enum access_mode access)
 {
-  msg_file = f_exstdout ? stderr : stdout;
+  int backed_up_flag = 0;
 
-  if (blocksize == 0)
-    {
-      msg ("invalid value for blocksize");
-      exit (EX_ARGSBAD);
-    }
+  stdlis = to_stdout_option ? stderr : stdout;
 
-  if (n_ar_files == 0)
-    {
-      msg ("No archive name given, what should I do?");
-      exit (EX_BADARCH);
-    }
+  if (record_size == 0)
+    FATAL_ERROR ((0, 0, _("Invalid value for record_size")));
+
+  if (archive_names == 0)
+    FATAL_ERROR ((0, 0, _("No archive name given")));
 
-  /*NOSTRICT*/
-  if (f_multivol)
+  current_file_name = NULL;
+  current_link_name = NULL;
+
+  /* FIXME: According to POSIX.1, PATH_MAX may well not be a compile-time
+     constant, and the value from sysconf (_SC_PATH_MAX) may well not be any
+     size that is reasonable to allocate a buffer.  In the GNU system, there
+     is no fixed limit.  The only correct thing to do is to use dynamic
+     allocation.  (Roland McGrath)  */
+
+  if (!real_s_name)
+    real_s_name = (char *) xmalloc (PATH_MAX);
+  /* FIXME: real_s_name is never freed.  */
+
+  save_name = NULL;
+
+  if (multi_volume_option)
     {
-      ar_block = (union record *) valloc ((unsigned) (blocksize + (2 * RECORDSIZE)));
-      if (ar_block)
-	ar_block += 2;
+      record_start
+	= (union block *) valloc ((unsigned) (record_size + (2 * BLOCKSIZE)));
+      if (record_start)
+	record_start += 2;
     }
   else
-    ar_block = (union record *) valloc ((unsigned) blocksize);
-  if (!ar_block)
-    {
-      msg ("could not allocate memory for blocking factor %d",
-	   blocking);
-      exit (EX_ARGSBAD);
-    }
+    record_start = (union block *) valloc ((unsigned) record_size);
+  if (!record_start)
+    FATAL_ERROR ((0, 0, _("Could not allocate memory for blocking factor %d"),
+		  blocking_factor));
 
-  ar_record = ar_block;
-  ar_last = ar_block + blocking;
-  ar_reading = reading;
+  current_block = record_start;
+  record_end = record_start + blocking_factor;
+  /* When updating the archive, we start with reading.  */
+  access_mode = access == ACCESS_UPDATE ? ACCESS_READ : access;
 
-  if (f_multivol && f_verify)
-    {
-      msg ("cannot verify multi-volume archives");
-      exit (EX_ARGSBAD);
-    }
+  if (multi_volume_option && verify_option)
+    FATAL_ERROR ((0, 0, _("Cannot verify multi-volume archives")));
 
-  if (f_compressprog)
+  if (use_compress_program_option)
     {
-      if (reading == 2 || f_verify)
-	{
-	  msg ("cannot update or verify compressed archives");
-	  exit (EX_ARGSBAD);
-	}
-      if (f_multivol)
+      if (multi_volume_option)
+	FATAL_ERROR ((0, 0, _("Cannot use multi-volume compressed archives")));
+      if (verify_option)
+	FATAL_ERROR ((0, 0, _("Cannot verify compressed archives")));
+
+      switch (access)
 	{
-	  msg ("cannot use multi-volume compressed archives");
-	  exit (EX_ARGSBAD);
+	case ACCESS_READ:
+	  child_open_for_uncompress ();
+	  break;
+
+	case ACCESS_WRITE:
+	  child_open_for_compress ();
+	  break;
+
+	case ACCESS_UPDATE:
+	  FATAL_ERROR ((0, 0, _("Cannot update compressed archives")));
+	  break;
 	}
-      child_open ();
-      if (!reading && ar_files[0][0] == '-' && ar_files[0][1] == '\0')
-	msg_file = stderr;
-      /* child_open(rem_host, rem_file); */
+
+      if (access == ACCESS_WRITE && strcmp (archive_name_array[0], "-") == 0)
+	stdlis = stderr;
     }
-  else if (ar_files[0][0] == '-' && ar_files[0][1] == '\0')
+  else if (strcmp (archive_name_array[0], "-") == 0)
     {
-      f_reblock++;		/* Could be a pipe, be safe */
-      if (f_verify)
-	{
-	  msg ("can't verify stdin/stdout archive");
-	  exit (EX_ARGSBAD);
-	}
-      if (reading == 2)
+      read_full_records_option = 1; /* could be a pipe, be safe */
+      if (verify_option)
+	FATAL_ERROR ((0, 0, _("Cannot verify stdin/stdout archive")));
+
+      switch (access)
 	{
+	case ACCESS_READ:
 	  archive = STDIN;
-	  msg_file = stderr;
-	  write_archive_to_stdout++;
-	}
-      else if (reading)
-	archive = STDIN;
-      else
-	{
+	  break;
+
+	case ACCESS_WRITE:
 	  archive = STDOUT;
-	  msg_file = stderr;
+	  stdlis = stderr;
+	  break;
+
+	case ACCESS_UPDATE:
+	  archive = STDIN;
+	  stdlis = stderr;
+	  write_archive_to_stdout = 1;
+	  break;
 	}
     }
-  else if (reading == 2 || f_verify)
-    {
-      archive = rmtopen (ar_files[0], O_RDWR | O_CREAT | O_BINARY, 0666);
-    }
-  else if (reading)
-    {
-      archive = rmtopen (ar_files[0], O_RDONLY | O_BINARY, 0666);
-    }
+  else if (verify_option)
+    archive = rmtopen (archive_name_array[0], O_RDWR | O_CREAT | O_BINARY,
+		       0666, rsh_command_option);
   else
-    {
-      archive = rmtcreat (ar_files[0], 0666);
-    }
+    switch (access)
+      {
+      case ACCESS_READ:
+	archive = rmtopen (archive_name_array[0], O_RDONLY | O_BINARY, 0666,
+			   rsh_command_option);
+	break;
+
+      case ACCESS_WRITE:
+	if (backup_option)
+	  {
+	    maybe_backup_file (archive_name_array[0], 1);
+	    backed_up_flag = 1;
+	  }
+	archive = rmtcreat (archive_name_array[0], 0666, rsh_command_option);
+	break;
+
+      case ACCESS_UPDATE:
+	archive = rmtopen (archive_name_array[0], O_RDWR | O_CREAT | O_BINARY,
+			   0666, rsh_command_option);
+	break;
+      }
+
   if (archive < 0)
     {
-      msg_perror ("can't open %s", ar_files[0]);
-      exit (EX_BADARCH);
+      int saved_errno = errno;
+
+      if (backed_up_flag)
+	undo_last_backup ();
+      FATAL_ERROR ((0, saved_errno, _("Cannot open %s"),
+		    archive_name_array[0]));
     }
-#ifndef __MSDOS__
-  if (!_isrmt (archive))
-    {
-      struct stat tmp_stat;
 
-      fstat (archive, &tmp_stat);
-      if (S_ISREG (tmp_stat.st_mode))
-	{
-	  ar_dev = tmp_stat.st_dev;
-	  ar_ino = tmp_stat.st_ino;
-	}
+#if !MSDOS
+
+  fstat (archive, &archive_stat);
+
+  /* Detect if outputting to "/dev/null".  */
+  {
+    struct stat dev_null_stat;
+
+    stat ("/dev/null", &dev_null_stat);
+    dev_null_output = (S_ISCHR (archive_stat.st_mode)
+		       && archive_stat.st_rdev == dev_null_stat.st_rdev);
+  }
+
+  if (!_isrmt (archive) && S_ISREG (archive_stat.st_mode))
+    {
+      ar_dev = archive_stat.st_dev;
+      ar_ino = archive_stat.st_ino;
     }
-#endif
 
-#ifdef	__MSDOS__
+#endif /* not MSDOS */
+
+#if MSDOS
   setmode (archive, O_BINARY);
 #endif
 
-  if (reading)
+  switch (access)
     {
-      ar_last = ar_block;	/* Set up for 1st block = # 0 */
-      (void) findrec ();	/* Read it in, check for EOF */
+    case ACCESS_READ:
+    case ACCESS_UPDATE:
+      record_end = record_start; /* set up for 1st record = # 0 */
+      find_next_block ();	/* read it in, check for EOF */
 
-      if (f_volhdr)
+      if (volume_label_option)
 	{
-	  union record *head;
-#if 0
-	  char *ptr;
+	  union block *label = find_next_block ();
+
+	  if (!label)
+	    FATAL_ERROR ((0, 0, _("Archive not labelled to match `%s'"),
+			  volume_label_option));
+	  if (!check_label_pattern (label))
+	    FATAL_ERROR ((0, 0, _("Volume `%s' does not match `%s'"),
+			  label->header.name, volume_label_option));
+	}
+      break;
 
-	  if (f_multivol)
-	    {
-	      ptr = malloc (strlen (f_volhdr) + 20);
-	      sprintf (ptr, "%s Volume %d", f_volhdr, 1);
-	    }
+    case ACCESS_WRITE:
+      if (volume_label_option)
+	{
+	  memset ((void *) record_start, 0, BLOCKSIZE);
+	  if (multi_volume_option)
+	    sprintf (record_start->header.name, "%s Volume 1",
+		     volume_label_option);
 	  else
-	    ptr = f_volhdr;
-#endif
-	  head = findrec ();
-	  if (!head)
-	    {
-	      msg ("Archive not labelled to match %s", f_volhdr);
-	      exit (EX_BADVOL);
-	    }
-	  if (re_match (label_pattern, head->header.arch_name,
-			strlen (head->header.arch_name), 0, 0) < 0)
-	    {
-	      msg ("Volume mismatch!  %s!=%s", f_volhdr,
-		   head->header.arch_name);
-	      exit (EX_BADVOL);
-	    }
+	    strcpy (record_start->header.name, volume_label_option);
+
+	  assign_string (&current_file_name, record_start->header.name);
+
+	  record_start->header.typeflag = GNUTYPE_VOLHDR;
+	  to_oct (time (0), 1 + 12, record_start->header.mtime);
+	  finish_header (record_start);
 #if 0
-	  if (strcmp (ptr, head->header.name))
-	    {
-	      msg ("Volume mismatch!  %s!=%s", ptr, head->header.name);
-	      exit (EX_BADVOL);
-	    }
-	  if (ptr != f_volhdr)
-	    free (ptr);
+	  current_block++;
 #endif
 	}
-    }
-  else if (f_volhdr)
-    {
-      bzero ((void *) ar_block, RECORDSIZE);
-      if (f_multivol)
-	sprintf (ar_block->header.arch_name, "%s Volume 1", f_volhdr);
-      else
-	strcpy (ar_block->header.arch_name, f_volhdr);
-      current_file_name = ar_block->header.arch_name;
-      ar_block->header.linkflag = LF_VOLHDR;
-      to_oct (time (0), 1 + 12, ar_block->header.mtime);
-      finish_header (ar_block);
-      /* ar_record++; */
+      break;
     }
 }
 
+/*--------------------------------------.
+| Perform a write to flush the buffer.  |
+`--------------------------------------*/
 
-/*
- * Remember a union record * as pointing to something that we
- * need to keep when reading onward in the file.  Only one such
- * thing can be remembered at once, and it only works when reading
- * an archive.
- *
- * We calculate "offset" then add it because some compilers end up
- * adding (baserec+ar_record), doing a 9-bit shift of baserec, then
- * subtracting ar_block from that, shifting it back, losing the top 9 bits.
- */
 void
-saverec (pointer)
-     union record **pointer;
+flush_write (void)
 {
-  long offset;
-
-  save_rec = pointer;
-  offset = ar_record - ar_block;
-  saved_recno = baserec + offset;
-}
-
-/*
- * Perform a write to flush the buffer.
- */
-
-/*send_buffer_to_file();
-  if(new_volume) {
-  	deal_with_new_volume_stuff();
-	send_buffer_to_file();
-  }
- */
-
-void
-fl_write ()
-{
-  int err;
   int copy_back;
-  static long bytes_written = 0;
+  int status;
+
+  if (checkpoint_option && !(++checkpoint % 10))
+    WARN ((0, 0, _("Write checkpoint %d"), checkpoint));
 
-  if (f_checkpoint && !(++checkpoint % 10))
-    msg ("Write checkpoint %d\n", checkpoint);
-  if (tape_length && bytes_written >= tape_length * 1024)
+  if (!zerop_tarlong (tape_length_option)
+      && !lessp_tarlong (bytes_written, tape_length_option))
     {
-      errno = ENOSPC;
-      err = 0;
+      errno = ENOSPC;		/* FIXME: errno should be read-only */
+      status = 0;
     }
+  else if (dev_null_output)
+    status = record_size;
   else
-    err = rmtwrite (archive, ar_block->charptr, (int) blocksize);
-  if (err != blocksize && !f_multivol)
-    writeerror (err);
-  else if (f_totals)
-    tot_written += blocksize;
-
-  if (err > 0)
-    bytes_written += err;
-  if (err == blocksize)
+    status = rmtwrite (archive, record_start->buffer,
+		       (unsigned int) record_size);
+  if (status != record_size && !multi_volume_option)
+    write_error (status);
+  else if (totals_option)
+    add_to_tarlong (total_written, record_size);
+
+  if (status > 0)
+    add_to_tarlong (bytes_written, status);
+
+  if (status == record_size)
     {
-      if (f_multivol)
+      if (multi_volume_option)
 	{
+	  char *cursor;
+
 	  if (!save_name)
 	    {
 	      real_s_name[0] = '\0';
