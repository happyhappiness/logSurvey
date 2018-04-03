/* Output to stdout / stderr for GNU make
Copyright (C) 2013 Free Software Foundation, Inc.
This file is part of GNU Make.

GNU Make is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later
version.

GNU Make is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "makeint.h"
#include "job.h"

/* GNU make no longer supports pre-ANSI89 environments.  */

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#ifdef HAVE_FCNTL_H
# include <fcntl.h>
#else
# include <sys/file.h>
#endif

struct output *output_context = NULL;
static unsigned int stdio_traced = 0;

#define OUTPUT_NONE (-1)

#define OUTPUT_ISSET(_out) ((_out)->out >= 0 || (_out)->err >= 0)

/* I really want to move to gnulib.  However, this is a big undertaking
   especially for non-UNIX platforms: how to get bootstrapping to work, etc.
   I don't want to take the time to do it right now.  Use a hack to get a
   useful version of vsnprintf() for Windows.  */
#ifdef _MSC_VER
#define va_copy(_d, _s) ((_d) = (_s))
#define snprintf msc_vsnprintf
static int
msc_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
  int len = -1;

  if (size > 0)
    len = _vsnprintf_s (str, size, _TRUNCATE, format, ap);
  if (len == -1)
    len = _vscprintf (format, ap);

  return len;
}
#endif

/* Write a string to the current STDOUT or STDERR.  */
static void
_outputs (int is_err, const char *msg)
{
  if (! output_context || ! output_context->syncout)
    {
      FILE *f = is_err ? stderr : stdout;
      fputs (msg, f);
      fflush (f);
    }
  else
    {
      int fd = is_err ? output_context->err : output_context->out;
      int len = strlen (msg);
      int r;

      EINTRLOOP (r, lseek (fd, 0, SEEK_END));
      while (1)
        {
          EINTRLOOP (r, write (fd, msg, len));
          if (r == len)
            break;
          if (r <= 0)
            return;
          len -= r;
          msg += r;
        }
    }
}

/* Write a message indicating that we've just entered or
   left (according to ENTERING) the current directory.  */

static int
log_working_directory (int entering)
{
  static char *buf = NULL;
  static unsigned int len = 0;
  unsigned int need;
  const char *fmt;
  char *p;

  /* Only print if directory logging is enabled.  */
  if (entering && ! print_directory_flag)
    return 0;

  /* Get enough space for the longest possible output.  */
  need = strlen (program) + INTEGER_LENGTH + 2 + 1;
  if (starting_directory)
    need += strlen (starting_directory);

  /* Use entire sentences to give the translators a fighting chance.  */
  if (makelevel == 0)
    if (starting_directory == 0)
      if (entering)
        fmt = _("%s: Entering an unknown directory\n");
      else
        fmt = _("%s: Leaving an unknown directory\n");
    else
      if (entering)
        fmt = _("%s: Entering directory '%s'\n");
      else
        fmt = _("%s: Leaving directory '%s'\n");
  else
    if (starting_directory == 0)
      if (entering)
        fmt = _("%s[%u]: Entering an unknown directory\n");
      else
        fmt = _("%s[%u]: Leaving an unknown directory\n");
    else
      if (entering)
        fmt = _("%s[%u]: Entering directory '%s'\n");
      else
        fmt = _("%s[%u]: Leaving directory '%s'\n");

  need += strlen (fmt);

  if (need > len)
    {
      buf = xrealloc (buf, need);
      len = need;
    }

  p = buf;
  if (print_data_base_flag)
    {
      *(p++) = '#';
      *(p++) = ' ';
    }

  if (makelevel == 0)
    if (starting_directory == 0)
      sprintf (p, fmt , program);
    else
      sprintf (p, fmt, program, starting_directory);
  else if (starting_directory == 0)
    sprintf (p, fmt, program, makelevel);
  else
    sprintf (p, fmt, program, makelevel, starting_directory);

  _outputs (0, buf);

  return 1;
}


#ifdef OUTPUT_SYNC

/* Semaphore for use in -j mode with output_sync. */
static sync_handle_t sync_handle = -1;

#define STREAM_OK(_s)       ((fcntl (fileno (_s), F_GETFD) != -1) || (errno != EBADF))

#define FD_NOT_EMPTY(_f)    ((_f) != OUTPUT_NONE && lseek ((_f), 0, SEEK_END) > 0)

/* Set up the sync handle.  Disables output_sync on error.  */
static int
sync_init ()
{
  int combined_output;

#ifdef WINDOWS32
  if ((!STREAM_OK (stdout) && !STREAM_OK (stderr))
      || (sync_handle = create_mutex ()) == -1)
    {
      perror_with_name ("output-sync suppressed: ", "stderr");
      output_sync = 0;
    }
  else
    {
      combined_output = same_stream (stdout, stderr);
      prepare_mutex_handle_string (sync_handle);
    }

#else
  if (STREAM_OK (stdout))
    {
      struct stat stbuf_o, stbuf_e;

      sync_handle = fileno (stdout);
      combined_output = (fstat (fileno (stdout), &stbuf_o) == 0
                         && fstat (fileno (stderr), &stbuf_e) == 0
                         && stbuf_o.st_dev == stbuf_e.st_dev
                         && stbuf_o.st_ino == stbuf_e.st_ino);
    }
  else if (STREAM_OK (stderr))
    sync_handle = fileno (stderr);
  else
    {
      perror_with_name ("output-sync suppressed: ", "stderr");
      output_sync = 0;
    }
#endif

  return combined_output;
}

/* Support routine for output_sync() */
static void
pump_from_tmp (int from, FILE *to)
{
  static char buffer[8192];

#ifdef WINDOWS32
  int prev_mode;

  /* "from" is opened by open_tmpfd, which does it in binary mode, so
     we need the mode of "to" to match that.  */
  prev_mode = _setmode (fileno (to), _O_BINARY);
#endif

  if (lseek (from, 0, SEEK_SET) == -1)
    perror ("lseek()");

  while (1)
    {
      int len;
      EINTRLOOP (len, read (from, buffer, sizeof (buffer)));
      if (len < 0)
        perror ("read()");
      if (len <= 0)
        break;
      if (fwrite (buffer, len, 1, to) < 1)
        perror ("fwrite()");
    }

#ifdef WINDOWS32
  /* Switch "to" back to its original mode, so that log messages by
     Make have the same EOL format as without --output-sync.  */
  _setmode (fileno (to), prev_mode);
#endif
}

/* Obtain the lock for writing output.  */
static void *
acquire_semaphore (void)
{
  static struct flock fl;

  fl.l_type = F_WRLCK;
  fl.l_whence = SEEK_SET;
  fl.l_start = 0;
  fl.l_len = 1;
  if (fcntl (sync_handle, F_SETLKW, &fl) != -1)
    return &fl;
  perror ("fcntl()");
  return NULL;
}

/* Release the lock for writing output.  */
static void
release_semaphore (void *sem)
{
  struct flock *flp = (struct flock *)sem;
  flp->l_type = F_UNLCK;
  if (fcntl (sync_handle, F_SETLKW, flp) == -1)
    perror ("fcntl()");
}

/* Synchronize the output of jobs in -j mode to keep the results of
   each job together. This is done by holding the results in temp files,
   one for stdout and potentially another for stderr, and only releasing
   them to "real" stdout/stderr when a semaphore can be obtained. */

void
output_dump (struct output *out)
{
  int outfd_not_empty = FD_NOT_EMPTY (out->out);
  int errfd_not_empty = FD_NOT_EMPTY (out->err);

  if (outfd_not_empty || errfd_not_empty)
    {
      int logged = 0;

      /* Try to acquire the semaphore.  If it fails, dump the output
         unsynchronized; still better than silently discarding it.  */
      void *sem = acquire_semaphore ();

      /* Log the working directory, if we need to.  */
      if (out->syncout)
        logged = log_working_directory (1);

      /* We've entered the "critical section" during which a lock is held.  We
         want to keep it as short as possible.  */
      if (outfd_not_empty)
        pump_from_tmp (out->out, stdout);
      if (errfd_not_empty && out->err != out->out)
        pump_from_tmp (out->err, stderr);

      if (logged)
        log_working_directory (0);

      /* Exit the critical section.  */
      if (sem)
        release_semaphore (sem);

      /* Truncate and reset the output, in case we use it again.  */
      if (out->out != OUTPUT_NONE)
        {
          int e;
          lseek (out->out, 0, SEEK_SET);
          EINTRLOOP (e, ftruncate (out->out, 0));
        }
      if (out->err != OUTPUT_NONE && out->err != out->out)
        {
          int e;
          lseek (out->err, 0, SEEK_SET);
          EINTRLOOP (e, ftruncate (out->err, 0));
        }
    }
}

/* Adds file descriptors to the child structure to support output_sync; one
   for stdout and one for stderr as long as they are open.  If stdout and
   stderr share a device they can share a temp file too.
   Will reset output_sync on error.  */
static void
setup_tmpfile (struct output *out)
{
  /* Is make's stdout going to the same place as stderr?  */
  static int combined_output = -1;

  if (combined_output < 0)
    combined_output = sync_init ();

  if (STREAM_OK (stdout))
    {
      int fd = open_tmpfd ();
      if (fd < 0)
        goto error;
      CLOSE_ON_EXEC (fd);
      out->out = fd;
    }

  if (STREAM_OK (stderr))
    {
      if (out->out != OUTPUT_NONE && combined_output)
        out->err = out->out;
      else
        {
          int fd = open_tmpfd ();
          if (fd < 0)
            goto error;
          CLOSE_ON_EXEC (fd);
          out->err = fd;
        }
    }

  return;

  /* If we failed to create a temp file, disable output sync going forward.  */
 error:
  output_close (out);
  output_sync = 0;
}
#endif /* OUTPUT_SYNC */


void
output_init (struct output *out, unsigned int syncout)
{
  out->out = out->err = OUTPUT_NONE;
  out->syncout = !!syncout;
}

void
output_close (struct output *out)
{
  if (! out)
    {
      if (stdio_traced)
        log_working_directory (0);
      return;
    }

#ifdef OUTPUT_SYNC
  output_dump (out);
#endif

  if (out->out >= 0)
    close (out->out);
  if (out->err >= 0 && out->err != out->out)
    close (out->err);

  output_init (out, 0);
}

/* We're about to run a sub-process so ensure we've got our output set up.  */
void
output_start ()
{
  if (! output_context)
    {
      if (! stdio_traced)
        stdio_traced = log_working_directory (1);
    }
#ifdef OUTPUT_SYNC
  else if (output_context->syncout && ! OUTPUT_ISSET(output_context))
    setup_tmpfile (output_context);
#endif
}

void
outputs (int is_err, const char *msg)
{
  /* For stdio, an empty msg means we're about to invoke a shell command,
     which may or may not generate output, so log the directory.  */
  if (! output_context && ! stdio_traced)
    stdio_traced = log_working_directory (1);

  /* Don't bother to do anything with empty strings.  */
  if (! msg || *msg == '\0')
    return;

#ifdef OUTPUT_SYNC
  if (output_context)
    {
      /* Create a temporary file to write to, if necessary.  */
      if (output_context->syncout && ! OUTPUT_ISSET(output_context))
        setup_tmpfile (output_context);
    }
#endif

  _outputs (is_err, msg);
}


/* Return formatted string buffers.
   If we move to gnulib we can use vasnprintf() etc. to make this simpler.
   Note these functions use a static buffer, so each call overwrites the
   results of the previous call.  */

static struct fmtstring
  {
    char *buffer;
    unsigned int size;
    unsigned int len;
  } fmtbuf = { NULL, 0, 0 };

/* Concatenate a formatted string onto the format buffer.  */
static const char *
vfmtconcat (const char *fmt, va_list args)
{
  va_list vcopy;
  int tot;
  int unused = fmtbuf.size - fmtbuf.len;

  va_copy(vcopy, args);

  tot = vsnprintf (&fmtbuf.buffer[fmtbuf.len], unused, fmt, args);
  assert (tot >= 0);

  if (tot >= unused)
    {
      fmtbuf.size += tot * 2;
      fmtbuf.buffer = xrealloc (fmtbuf.buffer, fmtbuf.size);

      unused = fmtbuf.size - fmtbuf.len;
      tot = vsnprintf (&fmtbuf.buffer[fmtbuf.len], unused, fmt, vcopy);
    }

  va_end(vcopy);

  fmtbuf.len += tot;

  return fmtbuf.buffer;
}

static const char *
fmtconcat (const char *fmt, ...)
{
  const char *p;
  va_list args;

  va_start (args, fmt);
  p = vfmtconcat (fmt, args);
  va_end (args);

  return p;
}

/* Print a message on stdout.  */

void
message (int prefix, const char *fmt, ...)
{
  va_list args;

  assert (fmt != NULL);

  fmtbuf.len = 0;

  if (prefix)
    {
      if (makelevel == 0)
        fmtconcat ("%s: ", program);
      else
        fmtconcat ("%s[%u]: ", program, makelevel);
    }

  va_start (args, fmt);
  vfmtconcat (fmt, args);
  va_end (args);

  fmtconcat ("\n");

  outputs (0, fmtbuf.buffer);
}

/* Print an error message.  */

void
error (const gmk_floc *flocp, const char *fmt, ...)
{
  va_list args;

  assert (fmt != NULL);

  fmtbuf.len = 0;

  if (flocp && flocp->filenm)
    fmtconcat ("%s:%lu: ", flocp->filenm, flocp->lineno);
  else if (makelevel == 0)
    fmtconcat ("%s: ", program);
  else
    fmtconcat ("%s[%u]: ", program, makelevel);

  va_start (args, fmt);
  vfmtconcat (fmt, args);
  va_end (args);

  fmtconcat ("\n");

  outputs (1, fmtbuf.buffer);
}

/* Print an error message and exit.  */

void
fatal (const gmk_floc *flocp, const char *fmt, ...)
{
  va_list args;

  assert (fmt != NULL);

  fmtbuf.len = 0;

  if (flocp && flocp->filenm)
    fmtconcat ("%s:%lu: *** ", flocp->filenm, flocp->lineno);
  else if (makelevel == 0)
    fmtconcat ("%s: *** ", program);
  else
    fmtconcat ("%s[%u]: *** ", program, makelevel);

  va_start (args, fmt);
  vfmtconcat (fmt, args);
  va_end (args);

  fmtconcat (_(".  Stop.\n"));
  outputs (1, fmtbuf.buffer);

  die (2);
}

/* Print an error message from errno.  */

void
perror_with_name (const char *str, const char *name)
{
  error (NILF, _("%s%s: %s"), str, name, strerror (errno));
}

/* Print an error message from errno and exit.  */

void
pfatal_with_name (const char *name)
{
  fatal (NILF, _("%s: %s"), name, strerror (errno));

  /* NOTREACHED */
}
