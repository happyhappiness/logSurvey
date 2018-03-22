-/* List a tar archive.
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
- * List a tar archive.
- *
- * Also includes support routines for reading a tar archive.
- *
- * this version written 26 Aug 1985 by John Gilmore (ihnp4!hoptoad!gnu).
- */
-
-#include <stdio.h>
-#include <ctype.h>
-#include <sys/types.h>
-#include <errno.h>
-#ifndef STDC_HEADERS
-extern int errno;
-#endif
-#include <time.h>
+/* List a tar archive, with support routines for reading a tar archive.
+   Copyright (C) 1988, 92, 93, 94, 96, 97 Free Software Foundation, Inc.
+   Written by John Gilmore, on 1985-08-26.
 
-#ifdef BSD42
-#include <sys/file.h>
-#else
-#ifndef V7
-#include <fcntl.h>
-#endif
-#endif
+   This program is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by the
+   Free Software Foundation; either version 2, or (at your option) any later
+   version.
 
-#define	isodigit(c)	( ((c) >= '0') && ((c) <= '7') )
+   This program is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
+   Public License for more details.
 
-#include "tar.h"
-#include "port.h"
+   You should have received a copy of the GNU General Public License along
+   with this program; if not, write to the Free Software Foundation, Inc.,
+   59 Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
-extern FILE *msg_file;
+/* Define to non-zero for forcing old ctime() instead of isotime().  */
+#undef USE_OLD_CTIME
 
-long from_oct ();		/* Decode octal number */
-void demode ();			/* Print file mode */
-void restore_saved_dir_info ();
-PTR ck_malloc ();
+#include "system.h"
 
-union record *head;		/* Points to current archive header */
-struct stat hstat;		/* Stat struct corresponding */
-int head_standard;		/* Tape header is in ANSI format */
+#include <ctype.h>
+#include <time.h>
+
+#define	ISODIGIT(Char) \
+  ((unsigned char) (Char) >= '0' && (unsigned char) (Char) <= '7')
+#define ISSPACE(Char) (ISASCII (Char) && isspace (Char))
 
-int check_exclude ();
-void close_archive ();
-void decode_header ();
-int findgid ();
-int finduid ();
-void name_gather ();
-int name_match ();
-void names_notfound ();
-void open_archive ();
-void print_header ();
-int read_header ();
-void saverec ();
-void skip_file ();
-void skip_extended_headers ();
+#include "common.h"
 
-extern char *quote_copy_string ();
+union block *current_header;	/* points to current archive header */
+struct stat current_stat;	/* stat struct corresponding */
+enum archive_format current_format; /* recognized format */
 
+/*-----------------------------------.
+| Main loop for reading an archive.  |
+`-----------------------------------*/
 
-/*
- * Main loop for reading an archive.
- */
 void
-read_and (do_something)
-     void (*do_something) ();
+read_and (void (*do_something) ())
 {
-  int status = 3;		/* Initial status at start of archive */
-  int prev_status;
-  extern time_t new_time;
-  char save_linkflag;
+  enum read_header status = HEADER_STILL_UNREAD;
+  enum read_header prev_status;
+  char save_typeflag;
 
-  name_gather ();		/* Gather all the names */
-  open_archive (1);		/* Open for reading */
+  name_gather ();
+  open_archive (ACCESS_READ);
 
-  for (;;)
+  while (1)
     {
       prev_status = status;
       status = read_header ();
       switch (status)
 	{
+	case HEADER_STILL_UNREAD:
+	  abort ();
 
-	case 1:		/* Valid header */
-	  /* We should decode next field (mode) first... */
-	  /* Ensure incoming names are null terminated. */
+	case HEADER_SUCCESS:
+
+	  /* Valid header.  We should decode next field (mode) first.
+	     Ensure incoming names are null terminated.  */
+
+	  /* FIXME: This is a quick kludge before 1.12 goes out.  */
+	  current_stat.st_mtime
+	    = from_oct (1 + 12, current_header->header.mtime);
 
 	  if (!name_match (current_file_name)
-	      || (f_new_files && hstat.st_mtime < new_time)
-	      || (f_exclude && check_exclude (current_file_name)))
+	      || current_stat.st_mtime < newer_mtime_option
+	      || (exclude_option && check_exclude (current_file_name)))
 	    {
-
 	      int isextended = 0;
 
-	      if (head->header.linkflag == LF_VOLHDR
-		  || head->header.linkflag == LF_MULTIVOL
-		  || head->header.linkflag == LF_NAMES)
+	      if (current_header->header.typeflag == GNUTYPE_VOLHDR
+		  || current_header->header.typeflag == GNUTYPE_MULTIVOL
+		  || current_header->header.typeflag == GNUTYPE_NAMES)
 		{
 		  (*do_something) ();
 		  continue;
 		}
-	      if (f_show_omitted_dirs
-		  && head->header.linkflag == LF_DIR)
-		msg ("Omitting %s\n", current_file_name);
-	      /* Skip past it in the archive */
-	      if (head->header.isextended)
+	      if (show_omitted_dirs_option
+		  && current_header->header.typeflag == DIRTYPE)
+		WARN ((0, 0, _("Omitting %s"), current_file_name));
+
+	      /* Skip past it in the archive.  */
+
+	      if (current_header->oldgnu_header.isextended)
 		isextended = 1;
-	      save_linkflag = head->header.linkflag;
-	      userec (head);
+	      save_typeflag = current_header->header.typeflag;
+	      set_next_block_after (current_header);
 	      if (isextended)
 		{
-		  /*					register union record *exhdr;
-
-					for (;;) {
-					    exhdr = findrec();
-					    if (!exhdr->ext_hdr.isextended) {
-					    	userec(exhdr);
-					    	break;
-					    }
-					}
-					userec(exhdr);*/
+#if 0
+		  union block *exhdr;
+
+		  while (1)
+		    {
+		      exhdr = find_next_block ();
+		      if (!exhdr->sparse_header.isextended)
+			{
+			  set_next_block_after (exhdr);
+			  break;
+			}
+		    }
+		  set_next_block_after (exhdr);
+#endif
 		  skip_extended_headers ();
 		}
-	      /* Skip to the next header on the archive */
-	      if (save_linkflag != LF_DIR)
-		skip_file ((long) hstat.st_size);
-	      continue;
 
+	      /* Skip to the next header on the archive.  */
+
+	      if (save_typeflag != DIRTYPE)
+		skip_file ((long) current_stat.st_size);
+	      continue;
 	    }
 
 	  (*do_something) ();
 	  continue;
 
-	  /*
-			 * If the previous header was good, tell them
-			 * that we are skipping bad ones.
-			 */
-	case 0:		/* Invalid header */
-	  userec (head);
+	case HEADER_ZERO_BLOCK:
+	  if (block_number_option)
+	    fprintf (stdlis, _("block %10ld: ** Block of NULs **\n"),
+		     current_block_ordinal ());
+
+	  set_next_block_after (current_header);
+	  status = prev_status;
+	  if (ignore_zeros_option)
+	    continue;
+	  break;
+
+	case HEADER_END_OF_FILE:
+	  if (block_number_option)
+	    fprintf (stdlis, _("block %10ld: ** End of File **\n"),
+		     current_block_ordinal ());
+	  break;
+
+	case HEADER_FAILURE:
+	  /* If the previous header was good, tell them that we are
+	     skipping bad ones.  */
+	  set_next_block_after (current_header);
 	  switch (prev_status)
 	    {
-	    case 3:		/* Error on first record */
-	      msg ("Hmm, this doesn't look like a tar archive.");
-	      /* FALL THRU */
-	    case 2:		/* Error after record of zeroes */
-	    case 1:		/* Error after header rec */
-	      msg ("Skipping to next file header...");
-	    case 0:		/* Error after error */
+	    case HEADER_STILL_UNREAD:
+	      WARN ((0, 0, _("Hmm, this doesn't look like a tar archive")));
+	      /* Fall through.  */
+
+	    case HEADER_ZERO_BLOCK:
+	    case HEADER_SUCCESS:
+	      WARN ((0, 0, _("Skipping to next file header")));
+	      break;
+
+	    case HEADER_END_OF_FILE:
+	    case HEADER_FAILURE:
+	      /* We are in the middle of a cascade of errors.  */
 	      break;
 	    }
 	  continue;
-
-	case 2:		/* Record of zeroes */
-	  userec (head);
-	  status = prev_status;	/* If error after 0's */
-	  if (f_ignorez)
-	    continue;
-	  /* FALL THRU */
-	case EOF:		/* End of archive */
-	  break;
 	}
       break;
-    };
+    }
 
-  restore_saved_dir_info ();
+  apply_delayed_set_stat ();
   close_archive ();
-  names_notfound ();		/* Print names not found */
+  names_notfound ();		/* print names not found */
 }
 
+/*---------------------------------------------.
+| Print a header block, based on tar options.  |
+`---------------------------------------------*/
 
-/*
- * Print a header record, based on tar options.
- */
 void
-list_archive ()
+list_archive (void)
 {
-  extern char *save_name;
-  int isextended = 0;		/* Flag to remember if head is extended */
+  int isextended = 0;		/* to remember if current_header is extended */
 
-  /* Save the record */
-  saverec (&head);
+  /* Print the header block.  */
 
-  /* Print the header record */
-  if (f_verbose)
+  if (verbose_option)
     {
-      if (f_verbose > 1)
-	decode_header (head, &hstat, &head_standard, 0);
+      if (verbose_option > 1)
+	decode_header (current_header, &current_stat, &current_format, 0);
       print_header ();
     }
 
-  if (f_gnudump && head->header.linkflag == LF_DUMPDIR)
+  if (incremental_option && current_header->header.typeflag == GNUTYPE_DUMPDIR)
     {
       size_t size, written, check;
-      char *data;
-      extern long save_totsize;
-      extern long save_sizeleft;
+      union block *data_block;
 
-      userec (head);
-      if (f_multivol)
+      set_next_block_after (current_header);
+      if (multi_volume_option)
 	{
-	  save_name = current_file_name;
-	  save_totsize = hstat.st_size;
+	  assign_string (&save_name, current_file_name);
+	  save_totsize = current_stat.st_size;
 	}
-      for (size = hstat.st_size; size > 0; size -= written)
+      for (size = current_stat.st_size; size > 0; size -= written)
 	{
-	  if (f_multivol)
+	  if (multi_volume_option)
 	    save_sizeleft = size;
-	  data = findrec ()->charptr;
-	  if (data == NULL)
+	  data_block = find_next_block ();
+	  if (!data_block)
 	    {
-	      msg ("EOF in archive file?");
-	      break;
+	      ERROR ((0, 0, _("EOF in archive file")));
+	      break;		/* FIXME: What happens, then?  */
 	    }
-	  written = endofrecs ()->charptr - data;
+	  written = available_space_after (data_block);
 	  if (written > size)
 	    written = size;
-	  errno = 0;
-	  check = fwrite (data, sizeof (char), written, msg_file);
-	  userec ((union record *) (data + written - 1));
+	  errno = 0;		/* FIXME: errno should be read-only */
+	  check = fwrite (data_block->buffer, sizeof (char), written, stdlis);
+	  set_next_block_after ((union block *)
+				(data_block->buffer + written - 1));
 	  if (check != written)
 	    {
-	      msg_perror ("only wrote %ld of %ld bytes to file %s", check, written, current_file_name);
-	      skip_file ((long) (size) - written);
+	      ERROR ((0, errno, _("Only wrote %ld of %ld bytes to file %s"),
+		      check, written, current_file_name));
+	      skip_file ((long) (size - written));
 	      break;
 	    }
 	}
-      if (f_multivol)
-	save_name = 0;
-      saverec ((union record **) 0);	/* Unsave it */
-      fputc ('\n', msg_file);
-      fflush (msg_file);
+      if (multi_volume_option)
+	assign_string (&save_name, NULL);
+      fputc ('\n', stdlis);
+      fflush (stdlis);
       return;
 
     }
-  saverec ((union record **) 0);/* Unsave it */
-  /* Check to see if we have an extended header to skip over also */
-  if (head->header.isextended)
+
+  /* Check to see if we have an extended header to skip over also.  */
+
+  if (current_header->oldgnu_header.isextended)
     isextended = 1;
 
-  /* Skip past the header in the archive */
-  userec (head);
+  /* Skip past the header in the archive.  */
+
+  set_next_block_after (current_header);
+
+  /* If we needed to skip any extended headers, do so now, by reading
+     extended headers and skipping past them in the archive.  */
 
-  /*
- 	 * If we needed to skip any extended headers, do so now, by
- 	 * reading extended headers and skipping past them in the
-	 * archive.
-	 */
   if (isextended)
     {
-      /*		register union record *exhdr;
+#if 0
+      union block *exhdr;
 
-		for (;;) {
-			exhdr = findrec();
+      while (1)
+	{
+	  exhdr = find_next_block ();
 
-			if (!exhdr->ext_hdr.isextended) {
-				userec(exhdr);
-				break;
-			}
-			userec(exhdr);
-		}*/
+	  if (!exhdr->sparse_header.isextended)
+	    {
+	      set_next_block_after (exhdr);
+	      break;
+	    }
+	  set_next_block_after (exhdr);
+	}
+#endif
       skip_extended_headers ();
     }
 
-  if (f_multivol)
-    save_name = current_file_name;
-  /* Skip to the next header on the archive */
+  if (multi_volume_option)
+    assign_string (&save_name, current_file_name);
 
-  skip_file ((long) hstat.st_size);
+  /* Skip to the next header on the archive.  */
 
-  if (f_multivol)
-    save_name = 0;
-}
+  skip_file ((long) current_stat.st_size);
 
+  if (multi_volume_option)
+    assign_string (&save_name, NULL);
+}
 
-/*
- * Read a record that's supposed to be a header record.
- * Return its address in "head", and if it is good, the file's
- * size in hstat.st_size.
- *
- * Return 1 for success, 0 if the checksum is bad, EOF on eof,
- * 2 for a record full of zeros (EOF marker).
- *
- * You must always userec(head) to skip past the header which this
- * routine reads.
- */
-int
-read_header ()
+/*-----------------------------------------------------------------------.
+| Read a block that's supposed to be a header block.  Return its address |
+| in "current_header", and if it is good, the file's size in             |
+| current_stat.st_size.                                                  |
+|                                                                        |
+| Return 1 for success, 0 if the checksum is bad, EOF on eof, 2 for a    |
+| block full of zeros (EOF marker).                                      |
+|                                                                        |
+| You must always set_next_block_after(current_header) to skip past the  |
+| header which this routine reads.                                       |
+`-----------------------------------------------------------------------*/
+
+/* The standard BSD tar sources create the checksum by adding up the
+   bytes in the header as type char.  I think the type char was unsigned
+   on the PDP-11, but it's signed on the Next and Sun.  It looks like the
+   sources to BSD tar were never changed to compute the checksum
+   currectly, so both the Sun and Next add the bytes of the header as
+   signed chars.  This doesn't cause a problem until you get a file with
+   a name containing characters with the high bit set.  So read_header
+   computes two checksums -- signed and unsigned.  */
+
+/* FIXME: The signed checksum computation is broken on machines where char's
+   are unsigned.  It's uneasy to handle all cases correctly...  */
+
+enum read_header
+read_header (void)
 {
-  register int i;
-  register long sum, signed_sum, recsum;
-  register char *p;
-  register union record *header;
-  long from_oct ();
+  int i;
+  long unsigned_sum;		/* the POSIX one :-) */
+  long signed_sum;		/* the Sun one :-( */
+  long recorded_sum;
+  char *p;
+  union block *header;
   char **longp;
-  char *bp, *data;
+  char *bp;
+  union block *data_block;
   int size, written;
   static char *next_long_name, *next_long_link;
-  char *name;
 
-recurse:
+  while (1)
+    {
+      header = find_next_block ();
+      current_header = header;
+      if (!header)
+	return HEADER_END_OF_FILE;
+
+      recorded_sum
+	= from_oct (sizeof header->header.chksum, header->header.chksum);
+
+      unsigned_sum = 0;
+      signed_sum = 0;
+      p = header->buffer;
+      for (i = sizeof (*header); --i >= 0;)
+	{
+	  /* We can't use unsigned char here because of old compilers,
+	     e.g. V7.  */
 
-  header = findrec ();
-  head = header;		/* This is our current header */
-  if (NULL == header)
-    return EOF;
+	  unsigned_sum += 0xFF & *p;
+	  signed_sum += *p++;
+	}
 
-  recsum = from_oct (8, header->header.chksum);
+      /* Adjust checksum to count the "chksum" field as blanks.  */
 
-  sum = 0;
-  p = header->charptr;
-  for (i = sizeof (*header); --i >= 0;)
-    {
-      /*
-		 * We can't use unsigned char here because of old compilers,
-		 * e.g. V7.
-		 */
-      signed_sum += *p;
-      sum += 0xFF & *p++;
-    }
+      for (i = sizeof (header->header.chksum); --i >= 0;)
+	{
+	  unsigned_sum -= 0xFF & header->header.chksum[i];
+	  signed_sum -= header->header.chksum[i];
+	}
+      unsigned_sum += ' ' * sizeof header->header.chksum;
+      signed_sum += ' ' * sizeof header->header.chksum;
 
-  /* Adjust checksum to count the "chksum" field as blanks. */
-  for (i = sizeof (header->header.chksum); --i >= 0;)
-    {
-      sum -= 0xFF & header->header.chksum[i];
-      signed_sum -= (char) header->header.chksum[i];
-    }
-  sum += ' ' * sizeof header->header.chksum;
-  signed_sum += ' ' * sizeof header->header.chksum;
+      if (unsigned_sum == sizeof header->header.chksum * ' ')
+	{
+	  /* This is a zeroed block...whole block is 0's except for the
+	     blanks we faked for the checksum field.  */
 
-  if (sum == 8 * ' ')
-    {
-      /*
-		 * This is a zeroed record...whole record is 0's except
-		 * for the 8 blanks we faked for the checksum field.
-		 */
-      return 2;
-    }
+	  return HEADER_ZERO_BLOCK;
+	}
 
-  if (sum != recsum && signed_sum != recsum)
-    return 0;
+      if (unsigned_sum != recorded_sum && signed_sum != recorded_sum)
+	return HEADER_FAILURE;
 
-  /*
-	 * Good record.  Decode file size and return.
-	 */
-  if (header->header.linkflag == LF_LINK)
-    hstat.st_size = 0;		/* Links 0 size on tape */
-  else
-    hstat.st_size = from_oct (1 + 12, header->header.size);
+      /* Good block.  Decode file size and return.  */
 
-  header->header.arch_name[NAMSIZ - 1] = '\0';
-  if (header->header.linkflag == LF_LONGNAME
-      || header->header.linkflag == LF_LONGLINK)
-    {
-      longp = ((header->header.linkflag == LF_LONGNAME)
-	       ? &next_long_name
-	       : &next_long_link);
-
-      userec (header);
-      if (*longp)
-	free (*longp);
-      bp = *longp = (char *) ck_malloc (hstat.st_size);
-
-      for (size = hstat.st_size;
-	   size > 0;
-	   size -= written)
+      if (header->header.typeflag == LNKTYPE)
+	current_stat.st_size = 0;	/* links 0 size on tape */
+      else
+	current_stat.st_size = from_oct (1 + 12, header->header.size);
+
+      header->header.name[NAME_FIELD_SIZE - 1] = '\0';
+      if (header->header.typeflag == GNUTYPE_LONGNAME
+	  || header->header.typeflag == GNUTYPE_LONGLINK)
 	{
-	  data = findrec ()->charptr;
-	  if (data == NULL)
+	  longp = ((header->header.typeflag == GNUTYPE_LONGNAME)
+		   ? &next_long_name
+		   : &next_long_link);
+
+	  set_next_block_after (header);
+	  if (*longp)
+	    free (*longp);
+	  bp = *longp = (char *) xmalloc ((size_t) current_stat.st_size);
+
+	  for (size = current_stat.st_size; size > 0; size -= written)
 	    {
-	      msg ("Unexpected EOF on archive file");
-	      break;
+	      data_block = find_next_block ();
+	      if (data_block == NULL)
+		{
+		  ERROR ((0, 0, _("Unexpected EOF on archive file")));
+		  break;
+		}
+	      written = available_space_after (data_block);
+	      if (written > size)
+		written = size;
+
+	      memcpy (bp, data_block->buffer, (size_t) written);
+	      bp += written;
+	      set_next_block_after ((union block *)
+				    (data_block->buffer + written - 1));
 	    }
-	  written = endofrecs ()->charptr - data;
-	  if (written > size)
-	    written = size;
 
-	  bcopy (data, bp, written);
-	  bp += written;
-	  userec ((union record *) (data + written - 1));
+	  /* Loop!  */
+
+	}
+      else
+	{
+	  assign_string (&current_file_name,
+			 (next_long_name ? next_long_name
+			  : current_header->header.name));
+	  assign_string (&current_link_name,
+			 (next_long_link ? next_long_link
+			  : current_header->header.linkname));
+	  next_long_link = next_long_name = 0;
+	  return HEADER_SUCCESS;
 	}
-      goto recurse;
-    }
-  else
-    {
-      name = (next_long_name
-	      ? next_long_name
-	      : head->header.arch_name);
-      if (current_file_name)
-	free (current_file_name);
-      current_file_name = ck_malloc (strlen (name) + 1);
-      strcpy (current_file_name, name);
-
-      name = (next_long_link
-	      ? next_long_link
-	      : head->header.arch_linkname);
-      if (current_link_name)
-	free (current_link_name);
-      current_link_name = ck_malloc (strlen (name) + 1);
-      strcpy (current_link_name, name);
-
-      next_long_link = next_long_name = 0;
-      return 1;
     }
 }
 
+/*-------------------------------------------------------------------------.
+| Decode things from a file HEADER block into STAT_INFO, also setting	   |
+| *FORMAT_POINTER depending on the header block format.  If DO_USER_GROUP, |
+| decode the user/group information (this is useful for extraction, but	   |
+| waste time when merely listing).					   |
+| 									   |
+| read_header() has already decoded the checksum and length, so we don't.  |
+| 									   |
+| This routine should *not* be called twice for the same block, since the  |
+| two calls might use different DO_USER_GROUP values and thus might end up |
+| with different uid/gid for the two calls.  If anybody wants the uid/gid  |
+| they should decode it first, and other callers should decode it without  |
+| uid/gid before calling a routine, e.g. print_header, that assumes	   |
+| decoded data.								   |
+`-------------------------------------------------------------------------*/
 
-/*
- * Decode things from a file header record into a "struct stat".
- * Also set "*stdp" to !=0 or ==0 depending whether header record is "Unix
- * Standard" tar format or regular old tar format.
- *
- * read_header() has already decoded the checksum and length, so we don't.
- *
- * If wantug != 0, we want the uid/group info decoded from Unix Standard
- * tapes (for extraction).  If == 0, we are just printing anyway, so save time.
- *
- * decode_header should NOT be called twice for the same record, since the
- * two calls might use different "wantug" values and thus might end up with
- * different uid/gid for the two calls.  If anybody wants the uid/gid they
- * should decode it first, and other callers should decode it without uid/gid
- * before calling a routine, e.g. print_header, that assumes decoded data.
- */
 void
-decode_header (header, st, stdp, wantug)
-     register union record *header;
-     register struct stat *st;
-     int *stdp;
-     int wantug;
+decode_header (union block *header, struct stat *stat_info,
+	       enum archive_format *format_pointer, int do_user_group)
 {
-  long from_oct ();
+  enum archive_format format;
+
+  if (strcmp (header->header.magic, TMAGIC) == 0)
+    format = POSIX_FORMAT;
+  else if (strcmp (header->header.magic, OLDGNU_MAGIC) == 0)
+    format = OLDGNU_FORMAT;
+  else
+    format = V7_FORMAT;
+  *format_pointer = format;
+
+  stat_info->st_mode = from_oct (8, header->header.mode);
+  stat_info->st_mode &= 07777;
+  stat_info->st_mtime = from_oct (1 + 12, header->header.mtime);
 
-  st->st_mode = from_oct (8, header->header.mode);
-  st->st_mode &= 07777;
-  st->st_mtime = from_oct (1 + 12, header->header.mtime);
-  if (f_gnudump)
+  if (format == OLDGNU_FORMAT && incremental_option)
     {
-      st->st_atime = from_oct (1 + 12, header->header.atime);
-      st->st_ctime = from_oct (1 + 12, header->header.ctime);
+      stat_info->st_atime = from_oct (1 + 12, header->oldgnu_header.atime);
+      stat_info->st_ctime = from_oct (1 + 12, header->oldgnu_header.ctime);
     }
 
-  if (0 == strcmp (header->header.magic, TMAGIC))
+  if (format == V7_FORMAT)
+    {
+      stat_info->st_uid = from_oct (8, header->header.uid);
+      stat_info->st_gid = from_oct (8, header->header.gid);
+      stat_info->st_rdev = 0;
+    }
+  else
     {
-      /* Unix Standard tar archive */
-      *stdp = 1;
-      if (wantug)
+      if (do_user_group)
 	{
-#ifdef NONAMES
-	  st->st_uid = from_oct (8, header->header.uid);
-	  st->st_gid = from_oct (8, header->header.gid);
-#else
-	  st->st_uid =
-	    (*header->header.uname
-	     ? finduid (header->header.uname)
-	     : from_oct (8, header->header.uid));
-	  st->st_gid =
-	    (*header->header.gname
-	     ? findgid (header->header.gname)
-	     : from_oct (8, header->header.gid));
-#endif
+	  /* FIXME: Decide if this should somewhat depend on -p.  */
+
+	  if (numeric_owner_option
+	      || !*header->header.uname
+	      || !uname_to_uid (header->header.uname, &stat_info->st_uid))
+	    stat_info->st_uid = from_oct (8, header->header.uid);
+
+	  if (numeric_owner_option
+	      || !*header->header.gname
+	      || !gname_to_gid (header->header.gname, &stat_info->st_gid))
+	    stat_info->st_gid = from_oct (8, header->header.gid);
 	}
-#if defined(S_IFBLK) || defined(S_IFCHR)
-      switch (header->header.linkflag)
+      switch (header->header.typeflag)
 	{
-	case LF_BLK:
-	case LF_CHR:
-	  st->st_rdev = makedev (from_oct (8, header->header.devmajor),
-				 from_oct (8, header->header.devminor));
-	}
+#ifdef S_IFBLK
+	case BLKTYPE:
+	  stat_info->st_rdev = makedev (from_oct (8, header->header.devmajor),
+					from_oct (8, header->header.devminor));
+	  break;
 #endif
-    }
-  else
-    {
-      /* Old fashioned tar archive */
-      *stdp = 0;
-      st->st_uid = from_oct (8, header->header.uid);
-      st->st_gid = from_oct (8, header->header.gid);
-      st->st_rdev = 0;
+
+#ifdef S_IFCHR
+	case CHRTYPE:
+	  stat_info->st_rdev = makedev (from_oct (8, header->header.devmajor),
+					from_oct (8, header->header.devminor));
+	  break;
+#endif
+
+	default:
+	  stat_info->st_rdev = 0;
+	}
     }
 }
 
+/*------------------------------------------------------------------------.
+| Quick and dirty octal conversion.  Result is -1 if the field is invalid |
+| (all blank, or nonoctal).						  |
+`------------------------------------------------------------------------*/
 
-/*
- * Quick and dirty octal conversion.
- *
- * Result is -1 if the field is invalid (all blank, or nonoctal).
- */
 long
-from_oct (digs, where)
-     register int digs;
-     register char *where;
+from_oct (int digs, char *where)
 {
-  register long value;
+  long value;
 
-  while (isspace (*where))
-    {				/* Skip spaces */
+  while (ISSPACE (*where))
+    {				/* skip spaces */
       where++;
       if (--digs <= 0)
-	return -1;		/* All blank field */
+	return -1;		/* all blank field */
     }
   value = 0;
-  while (digs > 0 && isodigit (*where))
-    {				/* Scan til nonoctal */
+  while (digs > 0 && ISODIGIT (*where))
+    {
+      /* Scan til nonoctal.  */
+
       value = (value << 3) | (*where++ - '0');
       --digs;
     }
 
-  if (digs > 0 && *where && !isspace (*where))
-    return -1;			/* Ended on non-space/nul */
+  if (digs > 0 && *where && !ISSPACE (*where))
+    return -1;			/* ended on non-space/nul */
 
   return value;
 }
 
+#if !USE_OLD_CTIME
 
-/*
- * Actually print it.
- *
- * Plain and fancy file header block logging.
- * Non-verbose just prints the name, e.g. for "tar t" or "tar x".
- * This should just contain file names, so it can be fed back into tar
- * with xargs or the "-T" option.  The verbose option can give a bunch
- * of info, one line per file.  I doubt anybody tries to parse its
- * format, or if they do, they shouldn't.  Unix tar is pretty random here
- * anyway.
- *
- * Note that print_header uses the globals <head>, <hstat>, and
- * <head_standard>, which must be set up in advance.  This is not very clean
- * and should be cleaned up.  FIXME.
- */
-#define	UGSWIDTH	18	/* min width of User, group, size */
-/* UGSWIDTH of 18 means that with user and group names <= 8 chars the columns
-   never shift during the listing.  */
-#define	DATEWIDTH	19	/* Last mod date */
-static int ugswidth = UGSWIDTH;	/* Max width encountered so far */
+/*-------------------------------------------.
+| Return the time formatted along ISO 8601.  |
+`-------------------------------------------*/
+
+/* Also, see http://www.ft.uni-erlangen.de/~mskuhn/iso-time.html.  */
+
+static char *
+isotime (const time_t *time)
+{
+  static char buffer[21];
+  struct tm *tm;
+
+  tm = localtime (time);
+  sprintf (buffer, "%4d-%02d-%02d %02d:%02d:%02d\n",
+	   tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
+	   tm->tm_hour, tm->tm_min, tm->tm_sec);
+  return buffer;
+}
+
+#endif /* not USE_OLD_CTIME */
+
+/*-------------------------------------------------------------------------.
+| Decode MODE from its binary form in a stat structure, and encode it into |
+| a 9 characters string STRING, terminated with a NUL.                     |
+`-------------------------------------------------------------------------*/
+
+static void
+decode_mode (unsigned mode, char *string)
+{
+  unsigned mask;
+  const char *rwx = "rwxrwxrwx";
+
+  for (mask = 0400; mask != 0; mask >>= 1)
+    if (mode & mask)
+      *string++ = *rwx++;
+    else
+      {
+	*string++ = '-';
+	rwx++;
+      }
+
+  if (mode & S_ISUID)
+    string[-7] = string[-7] == 'x' ? 's' : 'S';
+  if (mode & S_ISGID)
+    string[-4] = string[-4] == 'x' ? 's' : 'S';
+  if (mode & S_ISVTX)
+    string[-1] = string[-1] == 'x' ? 't' : 'T';
+
+  *string = '\0';
+}
+
+/*-------------------------------------------------------------------------.
+| Actually print it.							   |
+| 									   |
+| Plain and fancy file header block logging.  Non-verbose just prints the  |
+| name, e.g. for "tar t" or "tar x".  This should just contain file names, |
+| so it can be fed back into tar with xargs or the "-T" option.  The	   |
+| verbose option can give a bunch of info, one line per file.  I doubt	   |
+| anybody tries to parse its format, or if they do, they shouldn't.  Unix  |
+| tar is pretty random here anyway.					   |
+`-------------------------------------------------------------------------*/
+
+/* FIXME: Note that print_header uses the globals HEAD, HSTAT, and
+   HEAD_STANDARD, which must be set up in advance.  Not very clean...  */
+
+/* UGSWIDTH starts with 18, so with user and group names <= 8 chars, the
+   columns never shift during the listing.  */
+#define UGSWIDTH 18
+static int ugswidth = UGSWIDTH;	/* maximum width encountered so far */
+
+/* DATEWIDTH is the number of columns taken by the date and time fields.  */
+#if USE_OLD_CDATE
+# define DATEWIDTH 19
+#else
+# define DATEWIDTH 18
+#endif
 
 void
-print_header ()
+print_header (void)
 {
   char modes[11];
   char *timestamp;
-  char uform[11], gform[11];	/* These hold formatted ints */
+  char uform[11], gform[11];	/* these hold formatted ints */
   char *user, *group;
-  char size[24];		/* Holds a formatted long or maj, min */
-  time_t longie;		/* To make ctime() call portable */
+  char size[24];		/* holds a formatted long or maj, min */
+  time_t longie;		/* to make ctime() call portable */
   int pad;
   char *name;
-  extern long baserec;
 
-  if (f_sayblock)
-    fprintf (msg_file, "rec %10d: ", baserec + (ar_record - ar_block));
-  /* annofile(msg_file, (char *)NULL); */
+  if (block_number_option)
+    fprintf (stdlis, _("block %10ld: "), current_block_ordinal ());
 
-  if (f_verbose <= 1)
+  if (verbose_option <= 1)
     {
-      /* Just the fax, mam. */
-      char *name;
+      /* Just the fax, mam.  */
 
-      name = quote_copy_string (current_file_name);
-      if (name == 0)
-	name = current_file_name;
-      fprintf (msg_file, "%s\n", name);
-      if (name != current_file_name)
-	free (name);
+      char *quoted_name = quote_copy_string (current_file_name);
+
+      if (quoted_name)
+	{
+	  fprintf (stdlis, "%s\n", quoted_name);
+	  free (quoted_name);
+	}
+      else
+	fprintf (stdlis, "%s\n", current_file_name);
     }
   else
     {
-      /* File type and modes */
+      /* File type and modes.  */
+
       modes[0] = '?';
-      switch (head->header.linkflag)
+      switch (current_header->header.typeflag)
 	{
-	case LF_VOLHDR:
+	case GNUTYPE_VOLHDR:
 	  modes[0] = 'V';
 	  break;
 
-	case LF_MULTIVOL:
+	case GNUTYPE_MULTIVOL:
 	  modes[0] = 'M';
 	  break;
 
-	case LF_NAMES:
+	case GNUTYPE_NAMES:
 	  modes[0] = 'N';
 	  break;
 
-	case LF_LONGNAME:
-	case LF_LONGLINK:
-	  msg ("Visible longname error\n");
+	case GNUTYPE_LONGNAME:
+	case GNUTYPE_LONGLINK:
+	  ERROR ((0, 0, _("Visible longname error")));
 	  break;
 
-	case LF_SPARSE:
-	case LF_NORMAL:
-	case LF_OLDNORMAL:
-	case LF_LINK:
+	case GNUTYPE_SPARSE:
+	case REGTYPE:
+	case AREGTYPE:
+	case LNKTYPE:
 	  modes[0] = '-';
-	  if ('/' == current_file_name[strlen (current_file_name) - 1])
+	  if (current_file_name[strlen (current_file_name) - 1] == '/')
 	    modes[0] = 'd';
 	  break;
-	case LF_DUMPDIR:
+	case GNUTYPE_DUMPDIR:
 	  modes[0] = 'd';
 	  break;
-	case LF_DIR:
+	case DIRTYPE:
 	  modes[0] = 'd';
 	  break;
-	case LF_SYMLINK:
+	case SYMTYPE:
 	  modes[0] = 'l';
 	  break;
-	case LF_BLK:
+	case BLKTYPE:
 	  modes[0] = 'b';
 	  break;
-	case LF_CHR:
+	case CHRTYPE:
 	  modes[0] = 'c';
 	  break;
-	case LF_FIFO:
+	case FIFOTYPE:
 	  modes[0] = 'p';
 	  break;
-	case LF_CONTIG:
+	case CONTTYPE:
 	  modes[0] = 'C';
 	  break;
 	}
 
-      demode ((unsigned) hstat.st_mode, modes + 1);
+      decode_mode ((unsigned) current_stat.st_mode, modes + 1);
+
+      /* Timestamp.  */
 
-      /* Timestamp */
-      longie = hstat.st_mtime;
+      longie = current_stat.st_mtime;
+#if USE_OLD_CTIME
       timestamp = ctime (&longie);
       timestamp[16] = '\0';
       timestamp[24] = '\0';
+#else
+      timestamp = isotime (&longie);
+      timestamp[16] = '\0';
+#endif
 
-      /* User and group names */
-      if (*head->header.uname && head_standard)
-	{
-	  user = head->header.uname;
-	}
+      /* User and group names.  */
+
+      if (*current_header->header.uname && current_format != V7_FORMAT)
+	user = current_header->header.uname;
       else
 	{
 	  user = uform;
-	  (void) sprintf (uform, "%d",
-			  from_oct (8, head->header.uid));
-	}
-      if (*head->header.gname && head_standard)
-	{
-	  group = head->header.gname;
+	  sprintf (uform, "%ld", from_oct (8, current_header->header.uid));
 	}
+
+      if (*current_header->header.gname && current_format != V7_FORMAT)
+	group = current_header->header.gname;
       else
 	{
 	  group = gform;
-	  (void) sprintf (gform, "%d",
-			  from_oct (8, head->header.gid));
+	  sprintf (gform, "%ld", from_oct (8, current_header->header.gid));
 	}
 
-      /* Format the file size or major/minor device numbers */
-      switch (head->header.linkflag)
+      /* Format the file size or major/minor device numbers.  */
+
+      switch (current_header->header.typeflag)
 	{
 #if defined(S_IFBLK) || defined(S_IFCHR)
-	case LF_CHR:
-	case LF_BLK:
-	  (void) sprintf (size, "%d,%d",
-			  major (hstat.st_rdev),
-			  minor (hstat.st_rdev));
+	case CHRTYPE:
+	case BLKTYPE:
+	  sprintf (size, "%d,%d",
+		   major (current_stat.st_rdev), minor (current_stat.st_rdev));
 	  break;
 #endif
-	case LF_SPARSE:
-	  (void) sprintf (size, "%ld",
-			  from_oct (1 + 12, head->header.realsize));
+	case GNUTYPE_SPARSE:
+	  sprintf (size, "%ld",
+		   from_oct (1 + 12, current_header->oldgnu_header.realsize));
 	  break;
 	default:
-	  (void) sprintf (size, "%ld", (long) hstat.st_size);
+	  sprintf (size, "%ld", (long) current_stat.st_size);
 	}
 
-      /* Figure out padding and print the whole line. */
+      /* Figure out padding and print the whole line.  */
+
       pad = strlen (user) + strlen (group) + strlen (size) + 1;
       if (pad > ugswidth)
 	ugswidth = pad;
 
+#if USE_OLD_CTIME
+      fprintf (stdlis, "%s %s/%s %*s%s %s %s",
+	       modes, user, group, ugswidth - pad, "",
+	       size, timestamp + 4, timestamp + 20);
+#else
+      fprintf (stdlis, "%s %s/%s %*s%s %s",
+	       modes, user, group, ugswidth - pad, "", size, timestamp);
+#endif
+
       name = quote_copy_string (current_file_name);
-      if (!name)
-	name = current_file_name;
-      fprintf (msg_file, "%s %s/%s %*s%s %s %s %s",
-	       modes,
-	       user,
-	       group,
-	       ugswidth - pad,
-	       "",
-	       size,
-	       timestamp + 4, timestamp + 20,
-	       name);
-
-      if (name != current_file_name)
-	free (name);
-      switch (head->header.linkflag)
+      if (name)
+	{
+	  fprintf (stdlis, " %s", name);
+	  free (name);
+	}
+      else
+	fprintf (stdlis, " %s", current_file_name);
+
+      switch (current_header->header.typeflag)
 	{
-	case LF_SYMLINK:
+	case SYMTYPE:
 	  name = quote_copy_string (current_link_name);
-	  if (!name)
-	    name = current_link_name;
-	  fprintf (msg_file, " -> %s\n", name);
-	  if (name != current_link_name)
-	    free (name);
+	  if (name)
+	    {
+	      fprintf (stdlis, " -> %s\n", name);
+	      free (name);
+	    }
+	  else
+	    fprintf (stdlis, " -> %s\n", current_link_name);
 	  break;
 
-	case LF_LINK:
+	case LNKTYPE:
 	  name = quote_copy_string (current_link_name);
-	  if (!name)
-	    name = current_link_name;
-	  fprintf (msg_file, " link to %s\n", current_link_name);
-	  if (name != current_link_name)
-	    free (name);
+	  if (name)
+	    {
+	      fprintf (stdlis, _(" link to %s\n"), name);
+	      free (name);
+	    }
+	  else
+	    fprintf (stdlis, _(" link to %s\n"), current_link_name);
 	  break;
 
 	default:
-	  fprintf (msg_file, " unknown file type '%c'\n",
-		   head->header.linkflag);
+	  fprintf (stdlis, _(" unknown file type `%c'\n"),
+		   current_header->header.typeflag);
 	  break;
 
-	case LF_OLDNORMAL:
-	case LF_NORMAL:
-	case LF_SPARSE:
-	case LF_CHR:
-	case LF_BLK:
-	case LF_DIR:
-	case LF_FIFO:
-	case LF_CONTIG:
-	case LF_DUMPDIR:
-	  putc ('\n', msg_file);
+	case AREGTYPE:
+	case REGTYPE:
+	case GNUTYPE_SPARSE:
+	case CHRTYPE:
+	case BLKTYPE:
+	case DIRTYPE:
+	case FIFOTYPE:
+	case CONTTYPE:
+	case GNUTYPE_DUMPDIR:
+	  putc ('\n', stdlis);
 	  break;
 
-	case LF_VOLHDR:
-	  fprintf (msg_file, "--Volume Header--\n");
+	case GNUTYPE_VOLHDR:
+	  fprintf (stdlis, _("--Volume Header--\n"));
 	  break;
 
-	case LF_MULTIVOL:
-	  fprintf (msg_file, "--Continued at byte %ld--\n", from_oct (1 + 12, head->header.offset));
+	case GNUTYPE_MULTIVOL:
+	  fprintf (stdlis, _("--Continued at byte %ld--\n"),
+		   from_oct (1 + 12, current_header->oldgnu_header.offset));
 	  break;
 
-	case LF_NAMES:
-	  fprintf (msg_file, "--Mangled file names--\n");
+	case GNUTYPE_NAMES:
+	  fprintf (stdlis, _("--Mangled file names--\n"));
 	  break;
 	}
     }
-  fflush (msg_file);
+  fflush (stdlis);
 }
 
-/*
- * Print a similar line when we make a directory automatically.
- */
+/*--------------------------------------------------------------.
+| Print a similar line when we make a directory automatically.  |
+`--------------------------------------------------------------*/
+
 void
-pr_mkdir (pathname, length, mode)
-     char *pathname;
-     int length;
-     int mode;
+print_for_mkdir (char *pathname, int length, int mode)
 {
   char modes[11];
   char *name;
-  extern long baserec;
 
-  if (f_verbose > 1)
+  if (verbose_option > 1)
     {
-      /* File type and modes */
+      /* File type and modes.  */
+
       modes[0] = 'd';
-      demode ((unsigned) mode, modes + 1);
+      decode_mode ((unsigned) mode, modes + 1);
 
-      if (f_sayblock)
-	fprintf (msg_file, "rec %10d: ", baserec + (ar_record - ar_block));
-      /* annofile(msg_file, (char *)NULL); */
+      if (block_number_option)
+	fprintf (stdlis, _("block %10ld: "), current_block_ordinal ());
       name = quote_copy_string (pathname);
-      if (!name)
-	name = pathname;
-      fprintf (msg_file, "%s %*s %.*s\n",
-	       modes,
-	       ugswidth + DATEWIDTH,
-	       "Creating directory:",
-	       length,
-	       pathname);
-      if (name != pathname)
-	free (name);
+      if (name)
+	{
+	  fprintf (stdlis, "%s %*s %.*s\n", modes, ugswidth + DATEWIDTH,
+		   _("Creating directory:"), length, name);
+	  free (name);
+	}
+      else
+	fprintf (stdlis, "%s %*s %.*s\n", modes, ugswidth + DATEWIDTH,
+		 _("Creating directory:"), length, pathname);
     }
 }
 
+/*--------------------------------------------------------.
+| Skip over SIZE bytes of data in blocks in the archive.  |
+`--------------------------------------------------------*/
 
-/*
- * Skip over <size> bytes of data in records in the archive.
- */
 void
-skip_file (size)
-     register long size;
+skip_file (long size)
 {
-  union record *x;
-  extern long save_totsize;
-  extern long save_sizeleft;
+  union block *x;
 
-  if (f_multivol)
+  if (multi_volume_option)
     {
       save_totsize = size;
       save_sizeleft = size;
