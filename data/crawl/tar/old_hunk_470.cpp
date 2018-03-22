/* Buffer management for tar.
   Copyright (C) 1988, 1992, 1993 Free Software Foundation

This file is part of GNU Tar.

GNU Tar is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Tar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Tar; see the file COPYING.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

/*
 * Buffer management for tar.
 *
 * Written by John Gilmore, ihnp4!hoptoad!gnu, on 25 August 1985.
 */

#include <stdio.h>
#include <errno.h>
#ifndef STDC_HEADERS
extern int errno;
#endif
#include <sys/types.h>		/* For non-Berkeley systems */
#include <signal.h>
#include <time.h>
time_t time ();

#ifdef HAVE_SYS_MTIO_H
#include <sys/ioctl.h>
#include <sys/mtio.h>
#endif

#ifdef BSD42
#include <sys/file.h>
#else
#ifndef V7
#include <fcntl.h>
#endif
#endif

#ifdef	__MSDOS__
#include <process.h>
#endif

#ifdef XENIX
#include <sys/inode.h>
#endif

#include "tar.h"
#include "port.h"
#include "rmt.h"
#include "regex.h"

/* Either stdout or stderr:  The thing we write messages (standard msgs, not
   errors) to.  Stdout unless we're writing a pipe, in which case stderr */
FILE *msg_file = stdout;

#define	STDIN	0		/* Standard input  file descriptor */
#define	STDOUT	1		/* Standard output file descriptor */

#define	PREAD	0		/* Read  file descriptor from pipe() */
#define	PWRITE	1		/* Write file descriptor from pipe() */

#define	MAGIC_STAT	105	/* Magic status returned by child, if
				   it can't exec.  We hope compress/sh
				   never return this status! */

void *valloc ();

void writeerror ();
void readerror ();

void ck_pipe ();
void ck_close ();

int backspace_output ();
extern void finish_header ();
void flush_archive ();
int isfile ();
int new_volume ();
void verify_volume ();
extern void to_oct ();

#ifndef __MSDOS__
/* Obnoxious test to see if dimwit is trying to dump the archive */
dev_t ar_dev;
ino_t ar_ino;
#endif

/*
 * The record pointed to by save_rec should not be overlaid
 * when reading in a new tape block.  Copy it to record_save_area first, and
 * change the pointer in *save_rec to point to record_save_area.
 * Saved_recno records the record number at the time of the save.
 * This is used by annofile() to print the record number of a file's
 * header record.
 */
static union record **save_rec;
union record record_save_area;
static long saved_recno;

/*
 * PID of child program, if f_compress or remote archive access.
 */
static int childpid = 0;

/*
 * Record number of the start of this block of records
 */
long baserec;

/*
 * Error recovery stuff
 */
static int r_error_count;

/*
 * Have we hit EOF yet?
 */
static int hit_eof;

/* Checkpointing counter */
static int checkpoint;

/* JF we're reading, but we just read the last record and its time to update */
extern time_to_start_writing;
int file_to_switch_to = -1;	/* If remote update, close archive, and use
				   this descriptor to write to */

static int volno = 1;		/* JF which volume of a multi-volume tape
				   we're on */
static int global_volno = 1;	/* Volume number to print in external messages. */

char *save_name = 0;		/* Name of the file we are currently writing */
long save_totsize;		/* total size of file we are writing.  Only
				   valid if save_name is non_zero */
long save_sizeleft;		/* Where we are in the file we are writing.
				   Only valid if save_name is non-zero */

int write_archive_to_stdout;

/* Used by fl_read and fl_write to store the real info about saved names */
static char real_s_name[NAMSIZ];
static long real_s_totsize;
static long real_s_sizeleft;

/* Reset the EOF flag (if set), and re-set ar_record, etc */

void
reset_eof ()
{
  if (hit_eof)
    {
      hit_eof = 0;
      ar_record = ar_block;
      ar_last = ar_block + blocking;
      ar_reading = 0;
    }
}

/*
 * Return the location of the next available input or output record.
 * Return NULL for EOF.  Once we have returned NULL, we just keep returning
 * it, to avoid accidentally going on to the next file on the "tape".
 */
union record *
findrec ()
{
  if (ar_record == ar_last)
    {
      if (hit_eof)
	return (union record *) NULL;	/* EOF */
      flush_archive ();
      if (ar_record == ar_last)
	{
	  hit_eof++;
	  return (union record *) NULL;	/* EOF */
	}
    }
  return ar_record;
}


/*
 * Indicate that we have used all records up thru the argument.
 * (should the arg have an off-by-1? XXX FIXME)
 */
void
userec (rec)
     union record *rec;
{
  while (rec >= ar_record)
    ar_record++;
  /*
	 * Do NOT flush the archive here.  If we do, the same
	 * argument to userec() could mean the next record (if the
	 * input block is exactly one record long), which is not what
	 * is intended.
	 */
  if (ar_record > ar_last)
    abort ();
}


/*
 * Return a pointer to the end of the current records buffer.
 * All the space between findrec() and endofrecs() is available
 * for filling with data, or taking data from.
 */
union record *
endofrecs ()
{
  return ar_last;
}


/*
 * Duplicate a file descriptor into a certain slot.
 * Equivalent to BSD "dup2" with error reporting.
 */
void
dupto (from, to, msg)
     int from, to;
     char *msg;
{
  int err;

  if (from != to)
    {
      err = close (to);
      if (err < 0 && errno != EBADF)
	{
	  msg_perror ("Cannot close descriptor %d", to);
	  exit (EX_SYSTEM);
	}
      err = dup (from);
      if (err != to)
	{
	  msg_perror ("cannot dup %s", msg);
	  exit (EX_SYSTEM);
	}
      ck_close (from);
    }
}

#ifdef __MSDOS__
void
child_open ()
{
  fprintf (stderr, "MS-DOS %s can't use compressed or remote archives\n", tar);
  exit (EX_ARGSBAD);
}

#else
void
child_open ()
{
  int pipe[2];
  int err = 0;

  int kidpipe[2];
  int kidchildpid;

#define READ	0
#define WRITE	1

  ck_pipe (pipe);

  childpid = fork ();
  if (childpid < 0)
    {
      msg_perror ("cannot fork");
      exit (EX_SYSTEM);
    }
  if (childpid > 0)
    {
      /* We're the parent.  Clean up and be happy */
      /* This, at least, is easy */

      if (ar_reading)
	{
	  f_reblock++;
	  archive = pipe[READ];
	  ck_close (pipe[WRITE]);
	}
      else
	{
	  archive = pipe[WRITE];
	  ck_close (pipe[READ]);
	}
      return;
    }

  /* We're the kid */
  if (ar_reading)
    {
      dupto (pipe[WRITE], STDOUT, "(child) pipe to stdout");
      ck_close (pipe[READ]);
    }
  else
    {
      dupto (pipe[READ], STDIN, "(child) pipe to stdin");
      ck_close (pipe[WRITE]);
    }

  /* We need a child tar only if
	   1: we're reading/writing stdin/out (to force reblocking)
	   2: the file is to be accessed by rmt (compress doesn't know how)
	   3: the file is not a plain file */
#ifdef NO_REMOTE
  if (!(ar_files[0][0] == '-' && ar_files[0][1] == '\0') && isfile (ar_files[0]))
#else
  if (!(ar_files[0][0] == '-' && ar_files[0][1] == '\0') && !_remdev (ar_files[0]) && isfile (ar_files[0]))
#endif
    {
      /* We don't need a child tar.  Open the archive */
      if (ar_reading)
	{
	  archive = open (ar_files[0], O_RDONLY | O_BINARY, 0666);
	  if (archive < 0)
	    {
	      msg_perror ("can't open archive %s", ar_files[0]);
	      exit (EX_BADARCH);
	    }
	  dupto (archive, STDIN, "archive to stdin");
	  /* close(archive); */
	}
      else
	{
	  archive = creat (ar_files[0], 0666);
	  if (archive < 0)
	    {
	      msg_perror ("can't open archive %s", ar_files[0]);
	      exit (EX_BADARCH);
	    }
	  dupto (archive, STDOUT, "archive to stdout");
	  /* close(archive); */
	}
    }
  else
    {
      /* We need a child tar */
      ck_pipe (kidpipe);

      kidchildpid = fork ();
      if (kidchildpid < 0)
	{
	  msg_perror ("child can't fork");
	  exit (EX_SYSTEM);
	}

      if (kidchildpid > 0)
	{
	  /* About to exec compress:  set up the files */
	  if (ar_reading)
	    {
	      dupto (kidpipe[READ], STDIN, "((child)) pipe to stdin");
	      ck_close (kidpipe[WRITE]);
	      /* dup2(pipe[WRITE],STDOUT); */
	    }
	  else
	    {
	      /* dup2(pipe[READ],STDIN); */
	      dupto (kidpipe[WRITE], STDOUT, "((child)) pipe to stdout");
	      ck_close (kidpipe[READ]);
	    }
	  /* ck_close(pipe[READ]); */
	  /* ck_close(pipe[WRITE]); */
	  /* ck_close(kidpipe[READ]);
			ck_close(kidpipe[WRITE]); */
	}
      else
	{
	  /* Grandchild.  Do the right thing, namely sit here and
		   read/write the archive, and feed stuff back to compress */
	  tar = "tar (child)";
	  if (ar_reading)
	    {
	      dupto (kidpipe[WRITE], STDOUT, "[child] pipe to stdout");
	      ck_close (kidpipe[READ]);
	    }
	  else
	    {
	      dupto (kidpipe[READ], STDIN, "[child] pipe to stdin");
	      ck_close (kidpipe[WRITE]);
	    }

	  if (ar_files[0][0] == '-' && ar_files[0][1] == '\0')
	    {
	      if (ar_reading)
		archive = STDIN;
	      else
		archive = STDOUT;
	    }
	  else			/* This can't happen if (ar_reading==2)
				archive = rmtopen(ar_files[0], O_RDWR|O_CREAT|O_BINARY, 0666);
	  	  			else */ if (ar_reading)
	    archive = rmtopen (ar_files[0], O_RDONLY | O_BINARY, 0666);
	  else
	    archive = rmtcreat (ar_files[0], 0666);

	  if (archive < 0)
	    {
	      msg_perror ("can't open archive %s", ar_files[0]);
	      exit (EX_BADARCH);
	    }

	  if (ar_reading)
	    {
	      for (;;)
		{
		  char *ptr;
		  int max, count;

		  r_error_count = 0;
		error_loop:
		  err = rmtread (archive, ar_block->charptr, (int) (blocksize));
		  if (err < 0)
		    {
		      readerror ();
		      goto error_loop;
		    }
		  if (err == 0)
		    break;
		  ptr = ar_block->charptr;
		  max = err;
		  while (max)
		    {
		      count = (max < RECORDSIZE) ? max : RECORDSIZE;
		      err = write (STDOUT, ptr, count);
		      if (err != count)
			{
			  if (err < 0)
			    {
			      msg_perror ("can't write to compression program");
			      exit (EX_SYSTEM);
			    }
			  else
			    msg ("write to compression program short %d bytes",
				 count - err);
			  count = (err < 0) ? 0 : err;
			}
		      ptr += count;
		      max -= count;
		    }
		}
	    }
	  else
	    {
	      for (;;)
		{
		  int n;
		  char *ptr;

		  n = blocksize;
		  ptr = ar_block->charptr;
		  while (n)
		    {
		      err = read (STDIN, ptr, (n < RECORDSIZE) ? n : RECORDSIZE);
		      if (err <= 0)
			break;
		      n -= err;
		      ptr += err;
		    }
		  /* EOF */
		  if (err == 0)
		    {
		      if (!f_compress_block)
			blocksize -= n;
		      else
			bzero (ar_block->charptr + blocksize - n, n);
		      err = rmtwrite (archive, ar_block->charptr, blocksize);
		      if (err != (blocksize))
			writeerror (err);
		      if (!f_compress_block)
			blocksize += n;
		      break;
		    }
		  if (n)
		    {
		      msg_perror ("can't read from compression program");
		      exit (EX_SYSTEM);
		    }
		  err = rmtwrite (archive, ar_block->charptr, (int) blocksize);
		  if (err != blocksize)
		    writeerror (err);
		}
	    }

	  /* close_archive(); */
	  exit (0);
	}
    }
  /* So we should exec compress (-d) */
  if (ar_reading)
    execlp (f_compressprog, f_compressprog, "-d", (char *) 0);
  else
    execlp (f_compressprog, f_compressprog, (char *) 0);
  msg_perror ("can't exec %s", f_compressprog);
  _exit (EX_SYSTEM);
}


/* return non-zero if p is the name of a directory */
int
isfile (p)
     char *p;
{
  struct stat stbuf;

  if (stat (p, &stbuf) < 0)
    return 1;
  if (S_ISREG (stbuf.st_mode))
    return 1;
  return 0;
}

#endif

/*
 * Open an archive file.  The argument specifies whether we are
 * reading or writing.
 */
/* JF if the arg is 2, open for reading and writing. */
void
open_archive (reading)
     int reading;
{
  msg_file = f_exstdout ? stderr : stdout;

  if (blocksize == 0)
    {
      msg ("invalid value for blocksize");
      exit (EX_ARGSBAD);
    }

  if (n_ar_files == 0)
    {
      msg ("No archive name given, what should I do?");
      exit (EX_BADARCH);
    }

  /*NOSTRICT*/
  if (f_multivol)
    {
      ar_block = (union record *) valloc ((unsigned) (blocksize + (2 * RECORDSIZE)));
      if (ar_block)
	ar_block += 2;
    }
  else
    ar_block = (union record *) valloc ((unsigned) blocksize);
  if (!ar_block)
    {
      msg ("could not allocate memory for blocking factor %d",
	   blocking);
      exit (EX_ARGSBAD);
    }

  ar_record = ar_block;
  ar_last = ar_block + blocking;
  ar_reading = reading;

  if (f_multivol && f_verify)
    {
      msg ("cannot verify multi-volume archives");
      exit (EX_ARGSBAD);
    }

  if (f_compressprog)
    {
      if (reading == 2 || f_verify)
	{
	  msg ("cannot update or verify compressed archives");
	  exit (EX_ARGSBAD);
	}
      if (f_multivol)
	{
	  msg ("cannot use multi-volume compressed archives");
	  exit (EX_ARGSBAD);
	}
      child_open ();
      if (!reading && ar_files[0][0] == '-' && ar_files[0][1] == '\0')
	msg_file = stderr;
      /* child_open(rem_host, rem_file); */
    }
  else if (ar_files[0][0] == '-' && ar_files[0][1] == '\0')
    {
      f_reblock++;		/* Could be a pipe, be safe */
      if (f_verify)
	{
	  msg ("can't verify stdin/stdout archive");
	  exit (EX_ARGSBAD);
	}
      if (reading == 2)
	{
	  archive = STDIN;
	  msg_file = stderr;
	  write_archive_to_stdout++;
	}
      else if (reading)
	archive = STDIN;
      else
	{
	  archive = STDOUT;
	  msg_file = stderr;
	}
    }
  else if (reading == 2 || f_verify)
    {
      archive = rmtopen (ar_files[0], O_RDWR | O_CREAT | O_BINARY, 0666);
    }
  else if (reading)
    {
      archive = rmtopen (ar_files[0], O_RDONLY | O_BINARY, 0666);
    }
  else
    {
      archive = rmtcreat (ar_files[0], 0666);
    }
  if (archive < 0)
    {
      msg_perror ("can't open %s", ar_files[0]);
      exit (EX_BADARCH);
    }
#ifndef __MSDOS__
  if (!_isrmt (archive))
    {
      struct stat tmp_stat;

      fstat (archive, &tmp_stat);
      if (S_ISREG (tmp_stat.st_mode))
	{
	  ar_dev = tmp_stat.st_dev;
	  ar_ino = tmp_stat.st_ino;
	}
    }
#endif

#ifdef	__MSDOS__
  setmode (archive, O_BINARY);
#endif

  if (reading)
    {
      ar_last = ar_block;	/* Set up for 1st block = # 0 */
      (void) findrec ();	/* Read it in, check for EOF */

      if (f_volhdr)
	{
	  union record *head;
#if 0
	  char *ptr;

	  if (f_multivol)
	    {
	      ptr = malloc (strlen (f_volhdr) + 20);
	      sprintf (ptr, "%s Volume %d", f_volhdr, 1);
	    }
	  else
	    ptr = f_volhdr;
#endif
	  head = findrec ();
	  if (!head)
	    {
	      msg ("Archive not labelled to match %s", f_volhdr);
	      exit (EX_BADVOL);
	    }
	  if (re_match (label_pattern, head->header.arch_name,
			strlen (head->header.arch_name), 0, 0) < 0)
	    {
	      msg ("Volume mismatch!  %s!=%s", f_volhdr,
		   head->header.arch_name);
	      exit (EX_BADVOL);
	    }
#if 0
	  if (strcmp (ptr, head->header.name))
	    {
	      msg ("Volume mismatch!  %s!=%s", ptr, head->header.name);
	      exit (EX_BADVOL);
	    }
	  if (ptr != f_volhdr)
	    free (ptr);
#endif
	}
    }
  else if (f_volhdr)
    {
      bzero ((void *) ar_block, RECORDSIZE);
      if (f_multivol)
	sprintf (ar_block->header.arch_name, "%s Volume 1", f_volhdr);
      else
	strcpy (ar_block->header.arch_name, f_volhdr);
      current_file_name = ar_block->header.arch_name;
      ar_block->header.linkflag = LF_VOLHDR;
      to_oct (time (0), 1 + 12, ar_block->header.mtime);
      finish_header (ar_block);
      /* ar_record++; */
    }
}


/*
 * Remember a union record * as pointing to something that we
 * need to keep when reading onward in the file.  Only one such
 * thing can be remembered at once, and it only works when reading
 * an archive.
 *
 * We calculate "offset" then add it because some compilers end up
 * adding (baserec+ar_record), doing a 9-bit shift of baserec, then
 * subtracting ar_block from that, shifting it back, losing the top 9 bits.
 */
void
saverec (pointer)
     union record **pointer;
{
  long offset;

  save_rec = pointer;
  offset = ar_record - ar_block;
  saved_recno = baserec + offset;
}

/*
 * Perform a write to flush the buffer.
 */

/*send_buffer_to_file();
  if(new_volume) {
  	deal_with_new_volume_stuff();
	send_buffer_to_file();
  }
 */

void
fl_write ()
{
  int err;
  int copy_back;
  static long bytes_written = 0;

  if (f_checkpoint && !(++checkpoint % 10))
    msg ("Write checkpoint %d\n", checkpoint);
  if (tape_length && bytes_written >= tape_length * 1024)
    {
      errno = ENOSPC;
      err = 0;
    }
  else
    err = rmtwrite (archive, ar_block->charptr, (int) blocksize);
  if (err != blocksize && !f_multivol)
    writeerror (err);
  else if (f_totals)
    tot_written += blocksize;

  if (err > 0)
    bytes_written += err;
  if (err == blocksize)
    {
      if (f_multivol)
	{
	  if (!save_name)
	    {
	      real_s_name[0] = '\0';
