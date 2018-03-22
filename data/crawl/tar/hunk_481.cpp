 /* Update a tar archive.
-   Copyright (C) 1988, 1992 Free Software Foundation
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
-/* JF implement the 'r' 'u' and 'A' options for tar. */
-/* The 'A' option is my own invention:  It means that the file-names are
-   tar files, and they should simply be appended to the end of the archive.
-   No attempt is made to block the reads from the args; if they're on raw
-   tape or something like that, it'll probably lose. . . */
-
-#include <sys/types.h>
-#include <stdio.h>
-#include <errno.h>
-#ifndef STDC_HEADERS
-extern int errno;
-#endif
-
-#ifdef HAVE_SYS_MTIO_H
-#include <sys/ioctl.h>
-#include <sys/mtio.h>
-#endif
-
-#ifdef BSD42
-#include <sys/file.h>
-#else
-#ifndef V7
-#include <fcntl.h>
-#endif
-#endif
-
-#ifndef	__MSDOS__
-#include <pwd.h>
-#include <grp.h>
-#endif
-
-#define STDIN 0
-#define STDOUT 1
-
-#include "tar.h"
-#include "port.h"
-#include "rmt.h"
-
-int time_to_start_writing = 0;	/* We've hit the end of the old stuff,
-				   and its time to start writing new stuff
-				   to the tape.  This involves seeking
-				   back one block and re-writing the current
-				   block (which has been changed). */
-
-char *output_start;		/* Pointer to where we started to write in
-				   the first block we write out.  This is used
-				   if we can't backspace the output and have
-				   to null out the first part of the block */
-
-extern void skip_file ();
-extern void skip_extended_headers ();
-
-extern union record *head;
-extern struct stat hstat;
-
-void append_file ();
-void close_archive ();
-int confirm ();
-void decode_header ();
-void fl_read ();
-void fl_write ();
-void flush_archive ();
-int move_arch ();
-struct name *name_scan ();
-char *name_from_list ();
-void name_expand ();
-void name_gather ();
-void names_notfound ();
-void open_archive ();
-int read_header ();
-void reset_eof ();
-void write_block ();
-void write_eot ();
-
-/* Implement the 'r' (add files to end of archive), and 'u' (add files to
-   end of archive if they arent there, or are more up to date than the
-   version in the archive.) commands.*/
-void
-update_archive ()
+   Copyright (C) 1988, 1992, 1994, 1996, 1997 Free Software Foundation, Inc.
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
+/* Implement the 'r', 'u' and 'A' options for tar.  'A' means that the
+   file names are tar files, and they should simply be appended to the end
+   of the archive.  No attempt is made to record the reads from the args; if
+   they're on raw tape or something like that, it'll probably lose...  */
+
+#include "system.h"
+#include "common.h"
+
+/* FIXME: This module should not directly handle the following variable,
+   instead, this should be done in buffer.c only.  */
+extern union block *current_block;
+
+/* We've hit the end of the old stuff, and its time to start writing new
+   stuff to the tape.  This involves seeking back one record and
+   re-writing the current record (which has been changed).  */
+int time_to_start_writing = 0;
+
+/* Pointer to where we started to write in the first record we write out.
+   This is used if we can't backspace the output and have to null out the
+   first part of the record.  */
+char *output_start;
+
+/*------------------------------------------------------------------------.
+| Catenate file PATH to the archive without creating a header for it.  It |
+| had better be a tar file or the archive is screwed.			  |
+`------------------------------------------------------------------------*/
+
+static void
+append_file (char *path)
 {
-  int found_end = 0;
-  int status = 3;
-  int prev_status;
-  char *p;
-  struct name *name;
-  extern void dump_file ();
-
-  name_gather ();
-  if (cmd_mode == CMD_UPDATE)
-    name_expand ();
-  open_archive (2);		/* Open for updating */
+  int handle;
+  struct stat stat_data;
+  long bytes_left;
 
-  do
+  if (stat (path, &stat_data) != 0
+      || (handle = open (path, O_RDONLY | O_BINARY), handle < 0))
     {
-      prev_status = status;
-      status = read_header ();
-      switch (status)
-	{
-	case EOF:
-	  found_end = 1;
-	  break;
-
-	case 0:		/* A bad record */
-	  userec (head);
-	  switch (prev_status)
-	    {
-	    case 3:
-	      msg ("This doesn't look like a tar archive.");
-	      /* FALL THROUGH */
-	    case 2:
-	    case 1:
-	      msg ("Skipping to next header");
-	    case 0:
-	      break;
-	    }
-	  break;
+      ERROR ((0, errno, _("Cannot open file %s"), path));
+      return;
+    }
 
-	  /* A good record */
-	case 1:
-	  /* printf("File %s\n",head->header.name); */
-	  /* head->header.name[NAMSIZ-1]='\0'; */
-	  if (cmd_mode == CMD_UPDATE && (name = name_scan (current_file_name)))
-	    {
+  bytes_left = stat_data.st_size;
 
-	      /* struct stat hstat; */
-	      struct stat nstat;
-	      int head_standard;
-
-	      decode_header (head, &hstat, &head_standard, 0);
-	      if (stat (current_file_name, &nstat) < 0)
-		{
-		  msg_perror ("can't stat %s:", current_file_name);
-		}
-	      else
-		{
-		  if (hstat.st_mtime >= nstat.st_mtime)
-		    name->found++;
-		}
-	    }
-	  userec (head);
-	  if (head->header.isextended)
-	    skip_extended_headers ();
-	  skip_file ((long) hstat.st_size);
-	  break;
+  while (bytes_left > 0)
+    {
+      union block *start = find_next_block ();
+      long buffer_size = available_space_after (start);
+      int status;
 
-	case 2:
-	  ar_record = head;
-	  found_end = 1;
-	  break;
+      if (bytes_left < buffer_size)
+	{
+	  buffer_size = bytes_left;
+	  status = buffer_size % BLOCKSIZE;
+	  if (status)
+	    memset (start->buffer + bytes_left, 0,
+		    (size_t) (BLOCKSIZE - status));
 	}
-    }
-  while (!found_end);
 
-  reset_eof ();
-  time_to_start_writing = 1;
-  output_start = ar_record->charptr;
+      status = read (handle, start->buffer, (size_t) buffer_size);
+      if (status < 0)
+	FATAL_ERROR ((0, errno,
+		_("Read error at byte %ld reading %d bytes in file %s"),
+		stat_data.st_size - bytes_left, buffer_size, path));
+      bytes_left -= status;
 
-  while (p = name_from_list ())
-    {
-      if (f_confirm && !confirm ("add", p))
-	continue;
-      if (cmd_mode == CMD_CAT)
-	append_file (p);
-      else
-	dump_file (p, -1, 1);
+      set_next_block_after (start + (status - 1) / BLOCKSIZE);
+
+      if (status != buffer_size)
+	FATAL_ERROR ((0, 0, _("%s: File shrunk by %d bytes, (yark!)"),
+		      path, bytes_left));
     }
 
-  write_eot ();
-  close_archive ();
-  names_notfound ();
+  close (handle);
 }
 
-/* Catenate file p to the archive without creating a header for it.  It had
-   better be a tar file or the archive is screwed */
+/*-----------------------------------------------------------------------.
+| Implement the 'r' (add files to end of archive), and 'u' (add files to |
+| end of archive if they arent there, or are more up to date than the	 |
+| version in the archive.) commands.					 |
+`-----------------------------------------------------------------------*/
 
 void
-append_file (p)
-     char *p;
+update_archive (void)
 {
-  int fd;
-  struct stat statbuf;
-  long bytes_left;
-  union record *start;
-  long bufsiz, count;
-
-  if (0 != stat (p, &statbuf) || (fd = open (p, O_RDONLY | O_BINARY)) < 0)
-    {
-      msg_perror ("can't open file %s", p);
-      errors++;
-      return;
-    }
+  enum read_header previous_status = HEADER_STILL_UNREAD;
+  int found_end = 0;
 
-  bytes_left = statbuf.st_size;
+  name_gather ();
+  if (subcommand_option == UPDATE_SUBCOMMAND)
+    name_expand ();
+  open_archive (ACCESS_UPDATE);
 
-  while (bytes_left > 0)
+  while (!found_end)
     {
-      start = findrec ();
-      bufsiz = endofrecs ()->charptr - start->charptr;
-      if (bytes_left < bufsiz)
-	{
-	  bufsiz = bytes_left;
-	  count = bufsiz % RECORDSIZE;
-	  if (count)
-	    bzero (start->charptr + bytes_left, (int) (RECORDSIZE - count));
-	}
-      count = read (fd, start->charptr, bufsiz);
-      if (count < 0)
-	{
-	  msg_perror ("read error at byte %ld reading %d bytes in file %s", statbuf.st_size - bytes_left, bufsiz, p);
-	  exit (EX_ARGSBAD);	/* FOO */
-	}
-      bytes_left -= count;
-      userec (start + (count - 1) / RECORDSIZE);
-      if (count != bufsiz)
+      enum read_header status = read_header ();
+
+      switch (status)
 	{
-	  msg ("%s: file shrunk by %d bytes, yark!", p, bytes_left);
+	case HEADER_STILL_UNREAD:
 	  abort ();
-	}
-    }
-  (void) close (fd);
-}
-
-#ifdef DONTDEF
-bprint (fp, buf, num)
-     FILE *fp;
-     char *buf;
-{
-  int c;
 
-  if (num == 0 || num == -1)
-    return;
-  fputs (" '", fp);
-  while (num--)
-    {
-      c = *buf++;
-      if (c == '\\')
-	fputs ("\\\\", fp);
-      else if (c >= ' ' && c <= '~')
-	putc (c, fp);
-      else
-	switch (c)
+	case HEADER_SUCCESS:
 	  {
-	  case '\n':
-	    fputs ("\\n", fp);
-	    break;
-	  case '\r':
-	    fputs ("\\r", fp);
-	    break;
-	  case '\b':
-	    fputs ("\\b", fp);
-	    break;
-	  case '\0':
-	    /* fputs("\\-",fp); */
-	    break;
-	  default:
-	    fprintf (fp, "\\%03o", c);
+	    struct name *name;
+
+	    if (subcommand_option == UPDATE_SUBCOMMAND
+		&& (name = name_scan (current_file_name), name))
+	      {
+		struct stat stat_data;
+		enum archive_format unused;
+
+		decode_header (current_header, &current_stat, &unused, 0);
+		if (stat (current_file_name, &stat_data) < 0)
+		  ERROR ((0, errno, _("Cannot stat %s"), current_file_name));
+		else if (current_stat.st_mtime >= stat_data.st_mtime)
+		  name->found = 1;
+	      }
+	    set_next_block_after (current_header);
+	    if (current_header->oldgnu_header.isextended)
+	      skip_extended_headers ();
+	    skip_file ((long) current_stat.st_size);
 	    break;
 	  }
-    }
-  fputs ("'\n", fp);
-}
-
-#endif
-
-int number_of_blocks_read = 0;
-
-int number_of_new_records = 0;
-int number_of_records_needed = 0;
 
-union record *new_block = 0;
-union record *save_block = 0;
-
-void
-junk_archive ()
-{
-  int found_stuff = 0;
-  int status = 3;
-  int prev_status;
-  struct name *name;
-
-  /* int dummy_head; */
-  int number_of_records_to_skip = 0;
-  int number_of_records_to_keep = 0;
-  int number_of_kept_records_in_block;
-  int sub_status;
-  extern int write_archive_to_stdout;
-
-  /* fprintf(stderr,"Junk files\n"); */
-  name_gather ();
-  open_archive (2);
-
-  while (!found_stuff)
-    {
-      prev_status = status;
-      status = read_header ();
-      switch (status)
-	{
-	case EOF:
-	  found_stuff = 1;
+	case HEADER_ZERO_BLOCK:
+	  current_block = current_header;
+	  found_end = 1;
 	  break;
 
-	case 0:
-	  userec (head);
-	  switch (prev_status)
-	    {
-	    case 3:
-	      msg ("This doesn't look like a tar archive.");
-	      /* FALL THROUGH */
-	    case 2:
-	    case 1:
-	      msg ("Skipping to next header");
-	      /* FALL THROUGH */
-	    case 0:
-	      break;
-	    }
+	case HEADER_END_OF_FILE:
+	  found_end = 1;
 	  break;
 
-	case 1:
-	  /* head->header.name[NAMSIZ-1] = '\0'; */
-	  /* fprintf(stderr,"file %s\n",head->header.name); */
-	  if ((name = name_scan (current_file_name)) == (struct name *) 0)
+	case HEADER_FAILURE:
+	  set_next_block_after (current_header);
+	  switch (previous_status)
 	    {
-	      userec (head);
-	      /* fprintf(stderr,"Skip %ld\n",(long)(hstat.st_size)); */
-	      if (head->header.isextended)
-		skip_extended_headers ();
-	      skip_file ((long) (hstat.st_size));
+	    case HEADER_STILL_UNREAD:
+	      WARN ((0, 0, _("This does not look like a tar archive")));
+	      /* Fall through.  */
+
+	    case HEADER_SUCCESS:
+	    case HEADER_ZERO_BLOCK:
+	      ERROR ((0, 0, _("Skipping to next header")));
+	      /* Fall through.  */
+
+	    case HEADER_FAILURE:
 	      break;
-	    }
-	  name->found = 1;
-	  found_stuff = 2;
-	  break;
 
-	case 2:
-	  found_stuff = 1;
+	    case HEADER_END_OF_FILE:
+	      abort ();
+	    }
 	  break;
 	}
-    }
-  /* fprintf(stderr,"Out of first loop\n"); */
 
-  if (found_stuff != 2)
-    {
-      write_eot ();
-      close_archive ();
-      names_notfound ();
-      return;
+      previous_status = status;
     }
 
-  if (write_archive_to_stdout)
-    write_archive_to_stdout = 0;
-  new_block = (union record *) malloc (blocksize);
-  if (new_block == 0)
-    {
-      msg ("Can't allocate secondary block of %d bytes", blocksize);
-      exit (EX_SYSTEM);
-    }
-
-  /* Save away records before this one in this block */
-  number_of_new_records = ar_record - ar_block;
-  number_of_records_needed = blocking - number_of_new_records;
-  if (number_of_new_records)
-    bcopy ((void *) ar_block, (void *) new_block, (number_of_new_records) * RECORDSIZE);
-
-  /* fprintf(stderr,"Saved %d recs, need %d more\n",number_of_new_records,number_of_records_needed); */
-  userec (head);
-  if (head->header.isextended)
-    skip_extended_headers ();
-  skip_file ((long) (hstat.st_size));
-  found_stuff = 0;
-  /* goto flush_file; */
-
-  for (;;)
-    {
-      /* Fill in a block */
-      /* another_file: */
-      if (ar_record == ar_last)
-	{
-	  /* fprintf(stderr,"New block\n"); */
-	  flush_archive ();
-	  number_of_blocks_read++;
-	}
-      sub_status = read_header ();
-      /* fprintf(stderr,"Header type %d\n",sub_status); */
-
-      if (sub_status == 2 && f_ignorez)
-	{
-	  userec (head);
-	  continue;
-	}
-      if (sub_status == EOF || sub_status == 2)
-	{
-	  found_stuff = 1;
-	  bzero (new_block[number_of_new_records].charptr, RECORDSIZE * number_of_records_needed);
-	  number_of_new_records += number_of_records_needed;
-	  number_of_records_needed = 0;
-	  write_block (0);
-	  break;
-	}
-
-      if (sub_status == 0)
-	{
-	  msg ("Deleting non-header from archive.");
-	  userec (head);
-	  continue;
-	}
+  reset_eof ();
+  time_to_start_writing = 1;
+  output_start = current_block->buffer;
 
-      /* Found another header.  Yipee! */
-      /* head->header.name[NAMSIZ-1] = '\0'; */
-      /* fprintf(stderr,"File %s ",head->header.name); */
-      if (name = name_scan (current_file_name))
-	{
-	  name->found = 1;
-	  /* fprintf(stderr,"Flush it\n"); */
-	  /* flush_file: */
-	  /* decode_header(head,&hstat,&dummy_head,0); */
-	  userec (head);
-	  number_of_records_to_skip = (hstat.st_size + RECORDSIZE - 1) / RECORDSIZE;
-	  /* fprintf(stderr,"Flushing %d recs from %s\n",number_of_records_to_skip,head->header.name); */
-
-	  while (ar_last - ar_record <= number_of_records_to_skip)
-	    {
+  {
+    char *path;
 
-	      /* fprintf(stderr,"Block: %d <= %d  ",ar_last-ar_record,number_of_records_to_skip); */
-	      number_of_records_to_skip -= (ar_last - ar_record);
-	      flush_archive ();
-	      number_of_blocks_read++;
-	      /* fprintf(stderr,"Block %d left\n",number_of_records_to_skip); */
-	    }
-	  ar_record += number_of_records_to_skip;
-	  /* fprintf(stderr,"Final %d\n",number_of_records_to_skip); */
-	  number_of_records_to_skip = 0;
+    while (path = name_from_list (), path)
+      {
+	if (interactive_option && !confirm ("add", path))
 	  continue;
-	}
-
-      /* copy_header: */
-      new_block[number_of_new_records] = *head;
-      number_of_new_records++;
-      number_of_records_needed--;
-      number_of_records_to_keep = (hstat.st_size + RECORDSIZE - 1) / RECORDSIZE;
-      userec (head);
-      if (number_of_records_needed == 0)
-	write_block (1);
-      /* copy_data: */
-      number_of_kept_records_in_block = ar_last - ar_record;
-      if (number_of_kept_records_in_block > number_of_records_to_keep)
-	number_of_kept_records_in_block = number_of_records_to_keep;
-
-      /* fprintf(stderr,"Need %d kept_in %d keep %d\n",blocking,number_of_kept_records_in_block,number_of_records_to_keep); */
-
-      while (number_of_records_to_keep)
-	{
-	  int n;
-
-	  if (ar_record == ar_last)
-	    {
-	      /* fprintf(stderr,"Flush. . .\n"); */
-	      fl_read ();
-	      number_of_blocks_read++;
-	      ar_record = ar_block;
-	      number_of_kept_records_in_block = blocking;
-	      if (number_of_kept_records_in_block > number_of_records_to_keep)
-		number_of_kept_records_in_block = number_of_records_to_keep;
-	    }
-	  n = number_of_kept_records_in_block;
-	  if (n > number_of_records_needed)
-	    n = number_of_records_needed;
-
-	  /* fprintf(stderr,"Copying %d\n",n); */
-	  bcopy ((void *) ar_record, (void *) (new_block + number_of_new_records), n * RECORDSIZE);
-	  number_of_new_records += n;
-	  number_of_records_needed -= n;
-	  ar_record += n;
-	  number_of_records_to_keep -= n;
-	  number_of_kept_records_in_block -= n;
-	  /* fprintf(stderr,"Now new %d  need %d  keep %d  keep_in %d rec %d/%d\n",
- number_of_new_records,number_of_records_needed,number_of_records_to_keep,
- number_of_kept_records_in_block,ar_record-ar_block,ar_last-ar_block); */
-
-	  if (number_of_records_needed == 0)
-	    {
-	      write_block (1);
-	    }
-	}
-    }
+	if (subcommand_option == CAT_SUBCOMMAND)
+	  append_file (path);
+	else
+	  dump_file (path, -1, 1);
+      }
+  }
 
   write_eot ();
   close_archive ();
   names_notfound ();
 }
-
-void
-write_block (f)
-     int f;
-{
-  /* fprintf(stderr,"Write block\n"); */
-  /* We've filled out a block.  Write it out. */
-
-  /* Backspace back to where we started. . . */
-  if (archive != STDIN)
-    (void) move_arch (-(number_of_blocks_read + 1));
-
-  save_block = ar_block;
-  ar_block = new_block;
-
-  if (archive == STDIN)
-    archive = STDOUT;
-  fl_write ();
-
-  if (archive == STDOUT)
-    archive = STDIN;
-  ar_block = save_block;
-
-  if (f)
-    {
-      /* Move the tape head back to where we were */
-      if (archive != STDIN)
-	(void) move_arch (number_of_blocks_read);
-      number_of_blocks_read--;
-    }
-
-  number_of_records_needed = blocking;
-  number_of_new_records = 0;
-}
-
-/* Move archive descriptor by n blocks worth.  If n is positive we move
-   forward, else we move negative.   If its a tape, MTIOCTOP had better
-   work.  If its something else, we try to seek on it.  If we can't
-   seek, we lose! */
-int
-move_arch (n)
-     int n;
-{
-  long cur;
-
-#ifdef MTIOCTOP
-  struct mtop t;
-  int er;
-
-  if (n > 0)
-    {
-      t.mt_op = MTFSR;
-      t.mt_count = n;
-    }
-  else
-    {
-      t.mt_op = MTBSR;
-      t.mt_count = -n;
-    }
-  if ((er = rmtioctl (archive, MTIOCTOP, &t)) >= 0)
-    return 1;
-  if (errno == EIO && (er = rmtioctl (archive, MTIOCTOP, &t)) >= 0)
-    return 1;
-#endif
-
-  cur = rmtlseek (archive, 0L, 1);
-  cur += blocksize * n;
-
-  /* fprintf(stderr,"Fore to %x\n",cur); */
-  if (rmtlseek (archive, cur, 0) != cur)
-    {
-      /* Lseek failed.  Try a different method */
-      msg ("Couldn't re-position archive file.");
-      exit (EX_BADARCH);
-    }
-  return 3;
-}
