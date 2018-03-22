/* Buffer management for tar.
   Copyright (C) 1988, 92, 93, 94, 96, 97 Free Software Foundation, Inc.
   Written by John Gilmore, on 1985-08-25.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any later
   version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
   Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   59 Place - Suite 330, Boston, MA 02111-1307, USA.  */

#include "system.h"

#include <signal.h>
#include <time.h>
time_t time ();

#if MSDOS
# include <process.h>
#endif

#if XENIX
# include <sys/inode.h>
#endif

#ifndef FNM_LEADING_DIR
# include <fnmatch.h>
#endif

#include "common.h"
#include "rmt.h"

#define DEBUG_FORK 0		/* if nonzero, childs are born stopped */

#define	STDIN 0			/* standard input  file descriptor */
#define	STDOUT 1		/* standard output file descriptor */

#define	PREAD 0			/* read file descriptor from pipe() */
#define	PWRITE 1		/* write file descriptor from pipe() */

/* Number of retries before giving up on read.  */
#define	READ_ERROR_MAX 10

/* Globbing pattern to append to volume label if initial match failed.  */
#define VOLUME_LABEL_APPEND " Volume [1-9]*"

/* Variables.  */

static tarlong total_written;	/* bytes written on all volumes */
static tarlong bytes_written;	/* bytes written on this volume */

/* FIXME: The following four variables should ideally be static to this
   module.  However, this cannot be done yet, as update.c uses the first
   three a lot, and compare.c uses the fourth.  The cleanup continues!  */

union block *record_start;	/* start of record of archive */
union block *record_end;	/* last+1 block of archive record */
union block *current_block;	/* current block of archive */
enum access_mode access_mode;	/* how do we handle the archive */
static struct stat archive_stat; /* stat block for archive file */

static long record_start_block; /* block ordinal at record_start */

/* Where we write list messages (not errors, not interactions) to.  Stdout
   unless we're writing a pipe, in which case stderr.  */
FILE *stdlis;

static void backspace_output PARAMS ((void));
static int new_volume PARAMS ((enum access_mode));
static void write_error PARAMS ((int));
static void read_error PARAMS ((void));

#if !MSDOS
/* Obnoxious test to see if dimwit is trying to dump the archive.  */
dev_t ar_dev;
ino_t ar_ino;
#endif

/* PID of child program, if compress_option or remote archive access.  */
static int child_pid = 0;

/* Error recovery stuff  */
static int read_error_count;

/* Have we hit EOF yet?  */
static int hit_eof;

/* Checkpointing counter */
static int checkpoint;

/* We're reading, but we just read the last block and its time to update.  */
/* As least EXTERN like this one as possible.  FIXME!  */
extern int time_to_start_writing;

int file_to_switch_to = -1;	/* if remote update, close archive, and use
				   this descriptor to write to */

static int volno = 1;		/* which volume of a multi-volume tape we're
				   on */
static int global_volno = 1;	/* volume number to print in external
				   messages */

/* The pointer save_name, which is set in function dump_file() of module
   create.c, points to the original long filename instead of the new,
   shorter mangled name that is set in start_header() of module create.c.
   The pointer save_name is only used in multi-volume mode when the file
   being processed is non-sparse; if a file is split between volumes, the
   save_name is used in generating the LF_MULTIVOL record on the second
   volume.  (From Pierce Cantrell, 1991-08-13.)  */

char *save_name;		/* name of the file we are currently writing */
long save_totsize;		/* total size of file we are writing, only
				   valid if save_name is non NULL */
long save_sizeleft;		/* where we are in the file we are writing,
				   only valid if save_name is nonzero */

int write_archive_to_stdout = 0;

/* Used by flush_read and flush_write to store the real info about saved
   names.  */
static char *real_s_name = NULL;
static long real_s_totsize;
static long real_s_sizeleft;

/* Functions.  */

#if DEBUG_FORK

static pid_t
myfork (void)
{
  pid_t result = fork();

  if (result == 0)
    kill (getpid (), SIGSTOP);
  return result;
}

# define fork myfork

#endif /* DEBUG FORK */

void
init_total_written (void)
{
  clear_tarlong (total_written);
  clear_tarlong (bytes_written);
}

void
print_total_written (void)
{
  fprintf (stderr, _("Total bytes written: "));
  print_tarlong (total_written, stderr);
  fprintf (stderr, "\n");
}

/*--------------------------------------------------------.
| Compute and return the block ordinal at current_block.  |
`--------------------------------------------------------*/

long
current_block_ordinal (void)
{
  return record_start_block + (current_block - record_start);
}

/*------------------------------------------------------------------.
| If the EOF flag is set, reset it, as well as current_block, etc.  |
`------------------------------------------------------------------*/

void
reset_eof (void)
{
  if (hit_eof)
    {
      hit_eof = 0;
      current_block = record_start;
      record_end = record_start + blocking_factor;
      access_mode = ACCESS_WRITE;
    }
}

/*-------------------------------------------------------------------------.
| Return the location of the next available input or output block.	   |
| Return NULL for EOF.  Once we have returned NULL, we just keep returning |
| it, to avoid accidentally going on to the next file on the tape.	   |
`-------------------------------------------------------------------------*/

union block *
find_next_block (void)
{
  if (current_block == record_end)
    {
      if (hit_eof)
	return NULL;
      flush_archive ();
      if (current_block == record_end)
	{
	  hit_eof = 1;
	  return NULL;
	}
    }
  return current_block;
}

/*------------------------------------------------------.
| Indicate that we have used all blocks up thru BLOCK.  |
| 						        |
| FIXME: should the arg have an off-by-1?	        |
`------------------------------------------------------*/

void
set_next_block_after (union block *block)
{
  while (block >= current_block)
    current_block++;

  /* Do *not* flush the archive here.  If we do, the same argument to
     set_next_block_after could mean the next block (if the input record
     is exactly one block long), which is not what is intended.  */

  if (current_block > record_end)
    abort ();
}

/*------------------------------------------------------------------------.
| Return the number of bytes comprising the space between POINTER through |
| the end of the current buffer of blocks.  This space is available for	  |
| filling with data, or taking data from.  POINTER is usually (but not	  |
| always) the result previous find_next_block call.			  |
`------------------------------------------------------------------------*/

int
available_space_after (union block *pointer)
{
  return (int) (record_end->buffer - pointer->buffer);
}

/*------------------------------------------------------------------.
| Close file having descriptor FD, and abort if close unsucessful.  |
`------------------------------------------------------------------*/

static void
xclose (int fd)
{
  if (close (fd) < 0)
    FATAL_ERROR ((0, errno, _("Cannot close file #%d"), fd));
}

/*-----------------------------------------------------------------------.
| Duplicate file descriptor FROM into becoming INTO, or else, issue	 |
| MESSAGE.  INTO is closed first and has to be the next available slot.	 |
`-----------------------------------------------------------------------*/

static void
xdup2 (int from, int into, const char *message)
{
  if (from != into)
    {
      int status = close (into);

      if (status < 0 && errno != EBADF)
	FATAL_ERROR ((0, errno, _("Cannot close descriptor %d"), into));
      status = dup (from);
      if (status != into)
	FATAL_ERROR ((0, errno, _("Cannot properly duplicate %s"), message));
      xclose (from);
    }
}

#if MSDOS

/*-------------------------------------------------------.
| Set ARCHIVE for writing, then compressing an archive.	 |
`-------------------------------------------------------*/

static void
child_open_for_compress (void)
{
  FATAL_ERROR ((0, 0, _("Cannot use compressed or remote archives")));
}

/*---------------------------------------------------------.
| Set ARCHIVE for uncompressing, then reading an archive.  |
`---------------------------------------------------------*/

static void
child_open_for_uncompress (void)
{
  FATAL_ERROR ((0, 0, _("Cannot use compressed or remote archives")));
}

#else /* not MSDOS */

/*---------------------------------------------------------------------.
| Return nonzero if NAME is the name of a regular file, or if the file |
| does not exist (so it would be created as a regular file).	       |
`---------------------------------------------------------------------*/

static int
is_regular_file (const char *name)
{
  struct stat stbuf;

  if (stat (name, &stbuf) < 0)
    return 1;

  if (S_ISREG (stbuf.st_mode))
    return 1;

  return 0;
}

/*-------------------------------------------------------.
| Set ARCHIVE for writing, then compressing an archive.	 |
`-------------------------------------------------------*/

static void
child_open_for_compress (void)
{
  int parent_pipe[2];
  int child_pipe[2];
  int grandchild_pid;

  if (pipe (parent_pipe) < 0)
    FATAL_ERROR ((0, errno, _("Cannot open pipe")));

  child_pid = fork ();
  if (child_pid < 0)
    FATAL_ERROR ((0, errno, _("Cannot fork")));

  if (child_pid > 0)
    {
      /* The parent tar is still here!  Just clean up.  */

      archive = parent_pipe[PWRITE];
      xclose (parent_pipe[PREAD]);
      return;
    }

  /* The new born child tar is here!  */

  program_name = _("tar (child)");

  xdup2 (parent_pipe[PREAD], STDIN, _("(child) Pipe to stdin"));
  xclose (parent_pipe[PWRITE]);

  /* Check if we need a grandchild tar.  This happens only if either:
     a) we are writing stdout: to force reblocking;
     b) the file is to be accessed by rmt: compressor doesn't know how;
     c) the file is not a plain file.  */

  if (strcmp (archive_name_array[0], "-") != 0
      && !_remdev (archive_name_array[0])
      && is_regular_file (archive_name_array[0]))
    {
      if (backup_option)
	maybe_backup_file (archive_name_array[0], 1);

      /* We don't need a grandchild tar.  Open the archive and launch the
	 compressor.  */

      archive = creat (archive_name_array[0], 0666);
      if (archive < 0)
	{
	  int saved_errno = errno;

	  if (backup_option)
	    undo_last_backup ();
	  FATAL_ERROR ((0, saved_errno, _("Cannot open archive %s"),
			archive_name_array[0]));
	}
      xdup2 (archive, STDOUT, _("Archive to stdout"));
      execlp (use_compress_program_option, use_compress_program_option,
	      (char *) 0);
      FATAL_ERROR ((0, errno, _("Cannot exec %s"),
		    use_compress_program_option));
    }

  /* We do need a grandchild tar.  */

  if (pipe (child_pipe) < 0)
    FATAL_ERROR ((0, errno, _("Cannot open pipe")));

  grandchild_pid = fork ();
  if (grandchild_pid < 0)
    FATAL_ERROR ((0, errno, _("Child cannot fork")));

  if (grandchild_pid > 0)
    {
      /* The child tar is still here!  Launch the compressor.  */

      xdup2 (child_pipe[PWRITE], STDOUT, _("((child)) Pipe to stdout"));
      xclose (child_pipe[PREAD]);
      execlp (use_compress_program_option, use_compress_program_option,
	      (char *) 0);
      FATAL_ERROR ((0, errno, _("Cannot exec %s"),
		    use_compress_program_option));
    }

  /* The new born grandchild tar is here!  */

  program_name = _("tar (grandchild)");

  /* Prepare for reblocking the data from the compressor into the archive.  */

  xdup2 (child_pipe[PREAD], STDIN, _("(grandchild) Pipe to stdin"));
  xclose (child_pipe[PWRITE]);

  if (strcmp (archive_name_array[0], "-") == 0)
    archive = STDOUT;
  else
    archive = rmtcreat (archive_name_array[0], 0666, rsh_command_option);
  if (archive < 0)
    FATAL_ERROR ((0, errno, _("Cannot open archive %s"),
		  archive_name_array[0]));

  /* Let's read out of the stdin pipe and write an archive.  */

  while (1)
    {
      int status = 0;
      char *cursor;
      int length;

      /* Assemble a record.  */

      for (length = 0, cursor = record_start->buffer;
	   length < record_size;
	   length += status, cursor += status)
	{
	  int size = record_size - length;

	  if (size < BLOCKSIZE)
	    size = BLOCKSIZE;
	  status = read (STDIN, cursor, (size_t) size);
	  if (status <= 0)
	    break;
	}

      if (status < 0)
	FATAL_ERROR ((0, errno, _("Cannot read from compression program")));

      /* Copy the record.  */

      if (status == 0)
	{
	  /* We hit the end of the file.  Write last record at
	     full length, as the only role of the grandchild is
	     doing proper reblocking.  */

	  if (length > 0)
	    {
	      memset (record_start->buffer + length, 0,
		      (size_t) record_size - length);
	      status = rmtwrite (archive, record_start->buffer,
				 (unsigned int) record_size);
	      if (status != record_size)
		write_error (status);
	    }

	  /* There is nothing else to read, break out.  */
	  break;
	}

      status = rmtwrite (archive, record_start->buffer,
			 (unsigned int) record_size);
      if (status != record_size)
 	write_error (status);
    }

#if 0
  close_archive ();
#endif
  exit (exit_status);
}

/*---------------------------------------------------------.
| Set ARCHIVE for uncompressing, then reading an archive.  |
`---------------------------------------------------------*/

static void
child_open_for_uncompress (void)
{
  int parent_pipe[2];
  int child_pipe[2];
  int grandchild_pid;

  if (pipe (parent_pipe) < 0)
    FATAL_ERROR ((0, errno, _("Cannot open pipe")));

  child_pid = fork ();
  if (child_pid < 0)
    FATAL_ERROR ((0, errno, _("Cannot fork")));

  if (child_pid > 0)
    {
      /* The parent tar is still here!  Just clean up.  */

      read_full_records_option = 1;
      archive = parent_pipe[PREAD];
      xclose (parent_pipe[PWRITE]);
      return;
    }

  /* The new born child tar is here!  */

  program_name = _("tar (child)");

  xdup2 (parent_pipe[PWRITE], STDOUT, _("(child) Pipe to stdout"));
  xclose (parent_pipe[PREAD]);

  /* Check if we need a grandchild tar.  This happens only if either:
     a) we're reading stdin: to force unblocking;
     b) the file is to be accessed by rmt: compressor doesn't know how;
     c) the file is not a plain file.  */

  if (strcmp (archive_name_array[0], "-") != 0
      && !_remdev (archive_name_array[0])
      && is_regular_file (archive_name_array[0]))
    {
      /* We don't need a grandchild tar.  Open the archive and lauch the
	 uncompressor.  */

      archive = open (archive_name_array[0], O_RDONLY | O_BINARY, 0666);
      if (archive < 0)
	FATAL_ERROR ((0, errno, _("Cannot open archive %s"),
		      archive_name_array[0]));
      xdup2 (archive, STDIN, _("Archive to stdin"));
      execlp (use_compress_program_option, use_compress_program_option,
	      "-d", (char *) 0);
      FATAL_ERROR ((0, errno, _("Cannot exec %s"),
		    use_compress_program_option));
    }

  /* We do need a grandchild tar.  */

  if (pipe (child_pipe) < 0)
    FATAL_ERROR ((0, errno, _("Cannot open pipe")));

  grandchild_pid = fork ();
  if (grandchild_pid < 0)
    FATAL_ERROR ((0, errno, _("Child cannot fork")));

  if (grandchild_pid > 0)
    {
      /* The child tar is still here!  Launch the uncompressor.  */

      xdup2 (child_pipe[PREAD], STDIN, _("((child)) Pipe to stdin"));
      xclose (child_pipe[PWRITE]);
      execlp (use_compress_program_option, use_compress_program_option,
	      "-d", (char *) 0);
      FATAL_ERROR ((0, errno, _("Cannot exec %s"),
		    use_compress_program_option));
    }

  /* The new born grandchild tar is here!  */

  program_name = _("tar (grandchild)");

  /* Prepare for unblocking the data from the archive into the uncompressor.  */

  xdup2 (child_pipe[PWRITE], STDOUT, _("(grandchild) Pipe to stdout"));
  xclose (child_pipe[PREAD]);

  if (strcmp (archive_name_array[0], "-") == 0)
    archive = STDIN;
  else
    archive = rmtopen (archive_name_array[0], O_RDONLY | O_BINARY,
		       0666, rsh_command_option);
  if (archive < 0)
    FATAL_ERROR ((0, errno, _("Cannot open archive %s"),
		  archive_name_array[0]));

  /* Let's read the archive and pipe it into stdout.  */

  while (1)
    {
      char *cursor;
      int maximum;
      int count;
      int status;

      read_error_count = 0;

    error_loop:
      status = rmtread (archive, record_start->buffer,
			(unsigned int) (record_size));
      if (status < 0)
	{
	  read_error ();
	  goto error_loop;
	}
      if (status == 0)
	break;
      cursor = record_start->buffer;
      maximum = status;
      while (maximum)
	{
	  count = maximum < BLOCKSIZE ? maximum : BLOCKSIZE;
	  status = write (STDOUT, cursor, (size_t) count);
	  if (status < 0)
	    FATAL_ERROR ((0, errno, _("\
Cannot write to compression program")));

	  if (status != count)
	    {
	      ERROR ((0, 0, _("\
Write to compression program short %d bytes"),
		      count - status));
	      count = status;
	    }

	  cursor += count;
	  maximum -= count;
	}
    }

#if 0
  close_archive ();
#endif
  exit (exit_status);
}

#endif /* not MSDOS */

/*--------------------------------------------------------------------------.
| Check the LABEL block against the volume label, seen as a globbing	    |
| pattern.  Return true if the pattern matches.  In case of failure, retry  |
| matching a volume sequence number before giving up in multi-volume mode.  |
`--------------------------------------------------------------------------*/

static int
check_label_pattern (union block *label)
{
  char *string;
  int result;

  if (fnmatch (volume_label_option, label->header.name, 0) == 0)
    return 1;

  if (!multi_volume_option)
    return 0;

  string = xmalloc (strlen (volume_label_option)
		    + sizeof VOLUME_LABEL_APPEND + 1);
  strcpy (string, volume_label_option);
  strcat (string, VOLUME_LABEL_APPEND);
  result = fnmatch (string, label->header.name, 0) == 0;
  free (string);
  return result;
}

/*------------------------------------------------------------------------.
| Open an archive file.  The argument specifies whether we are reading or |
| writing, or both.							  |
`------------------------------------------------------------------------*/

void
open_archive (enum access_mode access)
{
  int backed_up_flag = 0;

  stdlis = to_stdout_option ? stderr : stdout;

  if (record_size == 0)
    FATAL_ERROR ((0, 0, _("Invalid value for record_size")));

  if (archive_names == 0)
    FATAL_ERROR ((0, 0, _("No archive name given")));

  current_file_name = NULL;
  current_link_name = NULL;

  /* FIXME: According to POSIX.1, PATH_MAX may well not be a compile-time
     constant, and the value from sysconf (_SC_PATH_MAX) may well not be any
     size that is reasonable to allocate a buffer.  In the GNU system, there
     is no fixed limit.  The only correct thing to do is to use dynamic
     allocation.  (Roland McGrath)  */

  if (!real_s_name)
    real_s_name = (char *) xmalloc (PATH_MAX);
  /* FIXME: real_s_name is never freed.  */

  save_name = NULL;

  if (multi_volume_option)
    {
      record_start
	= (union block *) valloc ((unsigned) (record_size + (2 * BLOCKSIZE)));
      if (record_start)
	record_start += 2;
    }
  else
    record_start = (union block *) valloc ((unsigned) record_size);
  if (!record_start)
    FATAL_ERROR ((0, 0, _("Could not allocate memory for blocking factor %d"),
		  blocking_factor));

  current_block = record_start;
  record_end = record_start + blocking_factor;
  /* When updating the archive, we start with reading.  */
  access_mode = access == ACCESS_UPDATE ? ACCESS_READ : access;

  if (multi_volume_option && verify_option)
    FATAL_ERROR ((0, 0, _("Cannot verify multi-volume archives")));

  if (use_compress_program_option)
    {
      if (multi_volume_option)
	FATAL_ERROR ((0, 0, _("Cannot use multi-volume compressed archives")));
      if (verify_option)
	FATAL_ERROR ((0, 0, _("Cannot verify compressed archives")));

      switch (access)
	{
	case ACCESS_READ:
	  child_open_for_uncompress ();
	  break;

	case ACCESS_WRITE:
	  child_open_for_compress ();
	  break;

	case ACCESS_UPDATE:
	  FATAL_ERROR ((0, 0, _("Cannot update compressed archives")));
	  break;
	}

      if (access == ACCESS_WRITE && strcmp (archive_name_array[0], "-") == 0)
	stdlis = stderr;
    }
  else if (strcmp (archive_name_array[0], "-") == 0)
    {
      read_full_records_option = 1; /* could be a pipe, be safe */
      if (verify_option)
	FATAL_ERROR ((0, 0, _("Cannot verify stdin/stdout archive")));

      switch (access)
	{
	case ACCESS_READ:
	  archive = STDIN;
	  break;

	case ACCESS_WRITE:
	  archive = STDOUT;
	  stdlis = stderr;
	  break;

	case ACCESS_UPDATE:
	  archive = STDIN;
	  stdlis = stderr;
	  write_archive_to_stdout = 1;
	  break;
	}
    }
  else if (verify_option)
    archive = rmtopen (archive_name_array[0], O_RDWR | O_CREAT | O_BINARY,
		       0666, rsh_command_option);
  else
    switch (access)
      {
      case ACCESS_READ:
	archive = rmtopen (archive_name_array[0], O_RDONLY | O_BINARY, 0666,
			   rsh_command_option);
	break;

      case ACCESS_WRITE:
	if (backup_option)
	  {
	    maybe_backup_file (archive_name_array[0], 1);
	    backed_up_flag = 1;
	  }
	archive = rmtcreat (archive_name_array[0], 0666, rsh_command_option);
	break;

      case ACCESS_UPDATE:
	archive = rmtopen (archive_name_array[0], O_RDWR | O_CREAT | O_BINARY,
			   0666, rsh_command_option);
	break;
      }

  if (archive < 0)
    {
      int saved_errno = errno;

      if (backed_up_flag)
	undo_last_backup ();
      FATAL_ERROR ((0, saved_errno, _("Cannot open %s"),
		    archive_name_array[0]));
    }

#if !MSDOS

  fstat (archive, &archive_stat);

  /* Detect if outputting to "/dev/null".  */
  {
    struct stat dev_null_stat;

    stat ("/dev/null", &dev_null_stat);
    dev_null_output = (S_ISCHR (archive_stat.st_mode)
		       && archive_stat.st_rdev == dev_null_stat.st_rdev);
  }

  if (!_isrmt (archive) && S_ISREG (archive_stat.st_mode))
    {
      ar_dev = archive_stat.st_dev;
      ar_ino = archive_stat.st_ino;
    }

#endif /* not MSDOS */

#if MSDOS
  setmode (archive, O_BINARY);
#endif

  switch (access)
    {
    case ACCESS_READ:
    case ACCESS_UPDATE:
      record_end = record_start; /* set up for 1st record = # 0 */
      find_next_block ();	/* read it in, check for EOF */

      if (volume_label_option)
	{
	  union block *label = find_next_block ();

	  if (!label)
	    FATAL_ERROR ((0, 0, _("Archive not labelled to match `%s'"),
			  volume_label_option));
	  if (!check_label_pattern (label))
	    FATAL_ERROR ((0, 0, _("Volume `%s' does not match `%s'"),
			  label->header.name, volume_label_option));
	}
      break;

    case ACCESS_WRITE:
      if (volume_label_option)
	{
	  memset ((void *) record_start, 0, BLOCKSIZE);
	  if (multi_volume_option)
	    sprintf (record_start->header.name, "%s Volume 1",
		     volume_label_option);
	  else
	    strcpy (record_start->header.name, volume_label_option);

	  assign_string (&current_file_name, record_start->header.name);

	  record_start->header.typeflag = GNUTYPE_VOLHDR;
	  to_oct (time (0), 1 + 12, record_start->header.mtime);
	  finish_header (record_start);
#if 0
	  current_block++;
#endif
	}
      break;
    }
}

/*--------------------------------------.
| Perform a write to flush the buffer.  |
`--------------------------------------*/

void
flush_write (void)
{
  int copy_back;
  int status;

  if (checkpoint_option && !(++checkpoint % 10))
    WARN ((0, 0, _("Write checkpoint %d"), checkpoint));

  if (!zerop_tarlong (tape_length_option)
      && !lessp_tarlong (bytes_written, tape_length_option))
    {
      errno = ENOSPC;		/* FIXME: errno should be read-only */
      status = 0;
    }
  else if (dev_null_output)
    status = record_size;
  else
    status = rmtwrite (archive, record_start->buffer,
		       (unsigned int) record_size);
  if (status != record_size && !multi_volume_option)
    write_error (status);
  else if (totals_option)
    add_to_tarlong (total_written, record_size);

  if (status > 0)
    add_to_tarlong (bytes_written, status);

  if (status == record_size)
    {
      if (multi_volume_option)
	{
	  char *cursor;

	  if (!save_name)
	    {
	      real_s_name[0] = '\0';
