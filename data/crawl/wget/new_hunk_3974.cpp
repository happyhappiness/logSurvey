#ifndef errno
extern int errno;
#endif

/* The file descriptor used for logging. */

static FILE *logfp;

/* Whether logging is saved at all.  */
int save_log_p;

/* In the event of a hang-up, and if its output was on a TTY, Wget
   redirects its output to `wget-log'.

   For the convenience of reading this newly-created log, we store the
   last several lines ("screenful", hence the choice of 24) of Wget
   output, and dump them as context when the time comes.  */
#define SAVED_LOG_LINES 24

/* log_lines is a circular buffer that stores SAVED_LOG_LINES lines of
   output.  log_line_current always points to the position in the
   buffer that will be written to next.  When log_line_current reaches
   SAVED_LOG_LINES, it is reset to zero.

   The problem here is that we'd have to either (re)allocate and free
   strings all the time, or limit the lines to an arbitrary number of
   characters.  Instead of settling for either of these, we do both:
   if the line is smaller than a certain "usual" line length (80 chars
   by default), a preallocated memory is used.  The rare lines that
   are longer than 80 characters are malloc'ed and freed separately.
   This gives good performance with minimum memory consumption and
   fragmentation.  */

#define STATIC_LENGTH 80

static struct log_ln {
  char static_line[STATIC_LENGTH + 1]; /* statically allocated
                                          line. */
  char *malloced_line;		/* malloc'ed line, for lines of output
                                   larger than 80 characters. */
  char *content;		/* this points either to malloced_line
                                   or to the appropriate static_line.
                                   If this is NULL, it means the line
                                   has not yet been used. */
} log_lines[SAVED_LOG_LINES];

/* The current position in the ring. */
static int log_line_current = -1;

/* Whether the most recently written line was "trailing", i.e. did not
   finish with \n.  This is an important piece of information because
   the code is always careful to append data to trailing lines, rather
   than create new ones.  */
static int trailing_line;


#define ROT_ADVANCE(num) do {			\
  if (++num >= SAVED_LOG_LINES)			\
    num = 0;					\
} while (0)

/* Free the log line index with NUM.  This calls free on
   ln->malloced_line if it's non-NULL, and it also resets
   ln->malloced_line and ln->content to NULL.  */

static void
free_log_line (int num)
{
  struct log_ln *ln = log_lines + num;
  if (ln->malloced_line)
    {
      free (ln->malloced_line);
      ln->malloced_line = NULL;
    }
  ln->content = NULL;
}

/* Append bytes in the range [start, end) to one line in the log.  The
   region is not supposed to contain newlines, except for the last
   character (at end[-1]).  */

static void
saved_append_1 (const char *start, const char *end)
{
  int len = end - start;
  if (!len)
    return;

  /* First, check whether we need to append to an existing line or to
     create a new one.  */
  if (!trailing_line)
    {
      /* Create a new line. */
      struct log_ln *ln;

      if (log_line_current == -1)
	log_line_current = 0;
      else
	free_log_line (log_line_current);
      ln = log_lines + log_line_current;
      if (len > STATIC_LENGTH)
	{
	  ln->malloced_line = strdupdelim (start, end);
	  ln->content = ln->malloced_line;
	}
      else
	{
	  memcpy (ln->static_line, start, len);
	  ln->static_line[len] = '\0';
	  ln->content = ln->static_line;
	}
    }
  else
    {
      /* Append to the last line.  If the line is malloc'ed, we just
         call realloc and append the new string.  If the line is
         static, we have to check whether appending the new string
         would make it exceed STATIC_LENGTH characters, and if so,
         convert it to malloc(). */
      struct log_ln *ln = log_lines + log_line_current;
      if (ln->malloced_line)
	{
	  /* Resize malloc'ed line and append. */
	  int old_len = strlen (ln->malloced_line);
	  ln->malloced_line = xrealloc (ln->malloced_line, old_len + len + 1);
	  memcpy (ln->malloced_line + old_len, start, len);
	  ln->malloced_line[old_len + len] = '\0';
	  /* might have changed due to realloc */
	  ln->content = ln->malloced_line;
	}
      else
	{
	  int old_len = strlen (ln->static_line);
	  if (old_len + len > STATIC_LENGTH)
	    {
	      /* Allocate memory and concatenate the old and the new
                 contents. */
	      ln->malloced_line = xmalloc (old_len + len + 1);
	      memcpy (ln->malloced_line, ln->static_line,
		      old_len);
	      memcpy (ln->malloced_line + old_len, start, len);
	      ln->malloced_line[old_len + len] = '\0';
	      ln->content = ln->malloced_line;
	    }
	  else
	    {
	      /* Just append to the old, statically allocated
                 contents.  */
	      memcpy (ln->static_line + old_len, start, len);
	      ln->static_line[old_len + len] = '\0';
	      ln->content = ln->static_line;
	    }
	}
    }
  trailing_line = !(end[-1] == '\n');
  if (!trailing_line)
    ROT_ADVANCE (log_line_current);
}

/* Log the contents of S, as explained above.  If S consists of
   multiple lines, they are logged separately.  If S does not end with
   a newline, it will form a "trailing" line, to which things will get
   appended the next time this function is called.  */

static void
saved_append (const char *s)
{
  while (*s)
    {
      const char *end = strchr (s, '\n');
      if (!end)
	end = s + strlen (s);
      else
	++end;
      saved_append_1 (s, end);
      s = end;
    }
}

/* Check X against opt.verbose and opt.quiet.  The semantics is as
   follows:

