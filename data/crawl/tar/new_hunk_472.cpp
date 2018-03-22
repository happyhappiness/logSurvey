    char name[1];
  };

struct link *linklist = NULL;	/* points to first link in list */


/*------------------------------------------------------------------------.
| Converts long VALUE into a DIGS-digit field at WHERE, including a       |
| trailing space and room for a NUL.  For example, 3 for DIGS 3 means one |
| digit, a space, and room for a NUL.                                     |
|                                                                         |
| We assume the trailing NUL is already there and don't fill it in.  This |
| fact is used by start_header and finish_header, so don't change it!     |
`------------------------------------------------------------------------*/

/* This should be equivalent to: sprintf (WHERE, "%*lo ", DIGS - 2, VALUE);
   except that sprintf fills in the trailing NUL and we don't.  */

void
to_oct (long value, int digs, char *where)
{
  --digs;			/* Trailing null slot is left alone */
  where[--digs] = ' ';		/* put in the space, though */

  /* Produce the digits -- at least one.  */

  do
    {
      where[--digs] = '0' + (char) (value & 7);	/* one octal digit */
      value >>= 3;
    }
  while (digs > 0 && value != 0);

  /* Leading spaces, if necessary.  */
  while (digs > 0)
    where[--digs] = ' ';
}

/* Writing routines.  */

/*-----------------------------------------------------------------------.
| Just zeroes out the buffer so we don't confuse ourselves with leftover |
| data.									 |
`-----------------------------------------------------------------------*/

static void
clear_buffer (char *buffer)
{
  memset (buffer, 0, BLOCKSIZE);
}

/*-------------------------------------------------------------------------.
| Write the EOT block(s).  We actually zero at least one block, through	   |
| the end of the record.  Old tar, as previous versions of GNU tar, writes |
| garbage after two zeroed blocks.					   |
`-------------------------------------------------------------------------*/

void
write_eot (void)
{
  union block *pointer = find_next_block ();

  if (pointer)
    {
      int space = available_space_after (pointer);

      memset (pointer->buffer, 0, (size_t) space);
      set_next_block_after (pointer);
    }
}

/*-----------------------------------------------------.
| Write a GNUTYPE_LONGLINK or GNUTYPE_LONGNAME block.  |
`-----------------------------------------------------*/

/* FIXME: Cross recursion between start_header and write_long!  */

static union block *start_header PARAMS ((const char *, struct stat *));

static void
write_long (const char *p, char type)
{
  int size = strlen (p) + 1;
  int bufsize;
  union block *header;
  struct stat foo;

  memset (&foo, 0, sizeof foo);
  foo.st_size = size;

  header = start_header ("././@LongLink", &foo);
  header->header.typeflag = type;
  finish_header (header);

  header = find_next_block ();

  bufsize = available_space_after (header);

  while (bufsize < size)
    {
      memcpy (header->buffer, p, (size_t) bufsize);
      p += bufsize;
      size -= bufsize;
      set_next_block_after (header + (bufsize - 1) / BLOCKSIZE);
      header = find_next_block ();
      bufsize = available_space_after (header);
    }
  memcpy (header->buffer, p, (size_t) size);
  memset (header->buffer + size, 0, (size_t) (bufsize - size));
  set_next_block_after (header + (size - 1) / BLOCKSIZE);
}

/* Header handling.  */

/*---------------------------------------------------------------------.
| Make a header block for the file name whose stat info is st.  Return |
| header pointer for success, NULL if the name is too long.	       |
`---------------------------------------------------------------------*/

static union block *
start_header (const char *name, struct stat *st)
{
  union block *header;

  if (!absolute_names_option)
    {
      static int warned_once = 0;

#if MSDOS
      if (name[1] == ':')
	{
	  name += 2;
	  if (!warned_once)
	    {
	      warned_once = 1;
	      WARN ((0, 0, _("Removing drive spec from names in the archive")));
	    }
	}
#endif

      while (*name == '/')
	{
	  name++;		/* force relative path */
	  if (!warned_once)
	    {
	      warned_once = 1;
	      WARN ((0, 0, _("\
Removing leading `/' from absolute path names in the archive")));
	    }
	}
    }

  /* Check the file name and put it in the block.  */

  if (strlen (name) >= (size_t) NAME_FIELD_SIZE)
    write_long (name, GNUTYPE_LONGNAME);
  header = find_next_block ();
  memset (header->buffer, 0, sizeof (union block));

  assign_string (&current_file_name, name);

  strncpy (header->header.name, name, NAME_FIELD_SIZE);
  header->header.name[NAME_FIELD_SIZE - 1] = '\0';

  /* Override some stat fields, if requested to do so.  */

  if (owner_option != (uid_t) -1)
    st->st_uid = owner_option;
  if (group_option != (gid_t) -1)
    st->st_gid = group_option;
  if (mode_option)
    st->st_mode = ((st->st_mode & S_IFMT)
		   | mode_adjust (st->st_mode, mode_option));

  /* Paul Eggert tried the trivial test ($WRITER cf a b; $READER tvf a)
     for a few tars and came up with the following interoperability
     matrix:

	      WRITER
	1 2 3 4 5 6 7 8 9   READER
	. . . . . . . . .   1 = SunOS 4.2 tar
	# . . # # . . # #   2 = NEC SVR4.0.2 tar
	. . . # # . . # .   3 = Solaris 2.1 tar
	. . . . . . . . .   4 = GNU tar 1.11.1
	. . . . . . . . .   5 = HP-UX 8.07 tar
	. . . . . . . . .   6 = Ultrix 4.1
	. . . . . . . . .   7 = AIX 3.2
	. . . . . . . . .   8 = Hitachi HI-UX 1.03
	. . . . . . . . .   9 = Omron UNIOS-B 4.3BSD 1.60Beta

	     . = works
	     # = ``impossible file type''

     The following mask for old archive removes the `#'s in column 4
     above, thus making GNU tar both a universal donor and a universal
     acceptor for Paul's test.  */

  if (archive_format == V7_FORMAT)
    to_oct ((long) st->st_mode & 07777, 8, header->header.mode);
  else
    to_oct ((long) st->st_mode, 8, header->header.mode);

  to_oct ((long) st->st_uid, 8, header->header.uid);
  to_oct ((long) st->st_gid, 8, header->header.gid);
  to_oct ((long) st->st_size, 1 + 12, header->header.size);
  to_oct ((long) st->st_mtime, 1 + 12, header->header.mtime);

  if (incremental_option)
    if (archive_format == OLDGNU_FORMAT)
      {
	to_oct ((long) st->st_atime, 1 + 12, header->oldgnu_header.atime);
	to_oct ((long) st->st_ctime, 1 + 12, header->oldgnu_header.ctime);
      }

  header->header.typeflag = archive_format == V7_FORMAT ? AREGTYPE : REGTYPE;

  switch (archive_format)
    {
    case DEFAULT_FORMAT:
    case V7_FORMAT:
      break;

    case OLDGNU_FORMAT:
      /* Overwrite header->header.magic and header.version in one blow.  */
      strcpy (header->header.magic, OLDGNU_MAGIC);
      break;

    case POSIX_FORMAT:
    case GNU_FORMAT:
      strncpy (header->header.magic, TMAGIC, TMAGLEN);
      strncpy (header->header.version, TVERSION, TVERSLEN);
      break;
    }

  if (archive_format == V7_FORMAT || numeric_owner_option)
    {
      /* header->header.[ug]name are left as the empty string.  */
    }
  else
    {
      uid_to_uname (st->st_uid, header->header.uname);
      gid_to_gname (st->st_gid, header->header.gname);
    }

  return header;
}

/*-------------------------------------------------------------------------.
| Finish off a filled-in header block and write it out.  We also print the |
| file name and/or full info if verbose is on.				   |
`-------------------------------------------------------------------------*/

void
finish_header (union block *header)
{
  int i, sum;
  char *p;

  memcpy (header->header.chksum, CHKBLANKS, sizeof (header->header.chksum));

  sum = 0;
  p = header->buffer;
  for (i = sizeof (*header); --i >= 0; )
    /* We can't use unsigned char here because of old compilers, e.g. V7.  */
    sum += 0xFF & *p++;

  /* Fill in the checksum field.  It's formatted differently from the
     other fields: it has [6] digits, a null, then a space -- rather than
     digits, a space, then a null.  We use to_oct then write the null in
     over to_oct's space.  The final space is already there, from
     checksumming, and to_oct doesn't modify it.

     This is a fast way to do:

     sprintf(header->header.chksum, "%6o", sum);  */

  to_oct ((long) sum, 8, header->header.chksum);
  header->header.chksum[6] = '\0';	/* zap the space */

  set_next_block_after (header);

  if (verbose_option
      && header->header.typeflag != GNUTYPE_LONGLINK
      && header->header.typeflag != GNUTYPE_LONGNAME)
    {
      /* These globals are parameters to print_header, sigh.  */

      current_header = header;
      /* current_stat is already set up.  */
      current_format = archive_format;
      print_header ();
    }
}

/* Sparse file processing.  */

/*-------------------------------------------------------------------------.
| Takes a blockful of data and basically cruises through it to see if it's |
| made *entirely* of zeros, returning a 0 the instant it finds something   |
| that is a nonzero, i.e., useful data.					   |
`-------------------------------------------------------------------------*/

static int
zero_block_p (char *buffer)
{
  int counter;

  for (counter = 0; counter < BLOCKSIZE; counter++)
    if (buffer[counter] != '\0')
      return 0;
  return 1;
}

/*---.
| ?  |
`---*/

static void
init_sparsearray (void)
{
  int counter;

  sp_array_size = 10;

  /* Make room for our scratch space -- initially is 10 elts long.  */

  sparsearray = (struct sp_array *)
    xmalloc (sp_array_size * sizeof (struct sp_array));
  for (counter = 0; counter < sp_array_size; counter++)
    {
      sparsearray[counter].offset = 0;
      sparsearray[counter].numbytes = 0;
    }
}

/*---.
| ?  |
`---*/

static void
find_new_file_size (int *filesize, int highest_index)
{
  int counter;

  *filesize = 0;
  for (counter = 0;
       sparsearray[counter].numbytes && counter <= highest_index;
       counter++)
    *filesize += sparsearray[counter].numbytes;
}

/*-----------------------------------------------------------------------.
| Make one pass over the file NAME, studying where any non-zero data is, |
| that is, how far into the file each instance of data is, and how many  |
| bytes are there.  Save this information in the sparsearray, which will |
| later be translated into header information.                           |
`-----------------------------------------------------------------------*/

/* There is little point in trimming small amounts of null data at the head
   and tail of blocks, only avoid dumping full null blocks.  */

/* FIXME: this routine might accept bits of algorithmic cleanup, it is
   too kludgey for my taste...  */

static int
deal_with_sparse (char *name, union block *header)
{
  long numbytes = 0;
  long offset = 0;
  int file;
  int sparse_index = 0;
  int count;
  char buffer[BLOCKSIZE];

  if (archive_format == OLDGNU_FORMAT)
    header->oldgnu_header.isextended = 0;

  if (file = open (name, O_RDONLY), file < 0)
    /* This problem will be caught later on, so just return.  */
    return 0;

  init_sparsearray ();
  clear_buffer (buffer);

  while (count = read (file, buffer, sizeof buffer), count != 0)
    {
      /* Realloc the scratch area as necessary.  FIXME: should reallocate
	 only at beginning of a new instance of non-zero data.  */

      if (sparse_index > sp_array_size - 1)
	{

	  sparsearray = (struct sp_array *)
	    xrealloc (sparsearray,
		      2 * sp_array_size * sizeof (struct sp_array));
	  sp_array_size *= 2;
	}

      /* Process one block.  */

      if (count == sizeof buffer)

	if (zero_block_p (buffer))
	  {
	    if (numbytes)
	      {
		sparsearray[sparse_index++].numbytes = numbytes;
		numbytes = 0;
	      }
	  }
	else
	  {
	    if (!numbytes)
	      sparsearray[sparse_index].offset = offset;
	    numbytes += count;
	  }

      else

	/* Since count < sizeof buffer, we have the last bit of the file.  */

	if (!zero_block_p (buffer))
	  {
	    if (!numbytes)
	      sparsearray[sparse_index].offset = offset;
	    numbytes += count;
	  }
	else
	  /* The next two lines are suggested by Andreas Degert, who says
	     they are required for trailing full blocks to be written to the
	     archive, when all zeroed.  Yet, it seems to me that the case
	     does not apply.  Further, at restore time, the file is not as
	     sparse as it should.  So, some serious cleanup is *also* needed
	     in this area.  Just one more... :-(.  FIXME.  */
	  if (numbytes)
	    numbytes += count;

      /* Prepare for next block.  */

      offset += count;
      /* FIXME: do not clear unless necessary.  */
      clear_buffer (buffer);
    }

  if (numbytes)
    sparsearray[sparse_index++].numbytes = numbytes;
  else
    {
      sparsearray[sparse_index].offset = offset - 1;
      sparsearray[sparse_index++].numbytes = 1;
    }

  close (file);
  return sparse_index - 1;
}

/*---.
| ?  |
`---*/

static int
finish_sparse_file (int file, long *sizeleft, long fullsize, char *name)
{
  union block *start;
  int bufsize;
  int sparse_index = 0;
  int count;
  long pos;
  long nwritten = 0;

  while (*sizeleft > 0)
    {
      start = find_next_block ();
      memset (start->buffer, 0, BLOCKSIZE);
      bufsize = sparsearray[sparse_index].numbytes;
      if (!bufsize)
	{
	  /* We blew it, maybe.  */

	  ERROR ((0, 0, _("Wrote %ld of %ld bytes to file %s"),
		  fullsize - *sizeleft, fullsize, name));
	  break;
	}
      pos = lseek (file, sparsearray[sparse_index++].offset, 0);

      /* If the number of bytes to be written here exceeds the size of
	 the temporary buffer, do it in steps.  */

      while (bufsize > BLOCKSIZE)
	{
#if 0
	  if (amount_read)
	    {
	      count = read (file, start->buffer + amount_read,
			    BLOCKSIZE - amount_read);
	      bufsize -= BLOCKSIZE - amount_read;
	      amount_read = 0;
	      set_next_block_after (start);
	      start = find_next_block ();
	      memset (start->buffer, 0, BLOCKSIZE);
	    }
#endif
	  /* Store the data.  */

	  count = read (file, start->buffer, BLOCKSIZE);
	  if (count < 0)
	    {
	      ERROR ((0, errno, _("\
Read error at byte %ld, reading %d bytes, in file %s"),
			 fullsize - *sizeleft, bufsize, name));
	      return 1;
	    }
	  bufsize -= count;
	  *sizeleft -= count;
	  set_next_block_after (start);
	  nwritten += BLOCKSIZE;	/* FIXME: ??? */
	  start = find_next_block ();
	  memset (start->buffer, 0, BLOCKSIZE);
	}

      {
	char buffer[BLOCKSIZE];

	clear_buffer (buffer);
	count = read (file, buffer, (size_t) bufsize);
	memcpy (start->buffer, buffer, BLOCKSIZE);
      }

      if (count < 0)
	{
	  ERROR ((0, errno,
		  _("Read error at byte %ld, reading %d bytes, in file %s"),
		  fullsize - *sizeleft, bufsize, name));
	  return 1;
	}
#if 0
      if (amount_read >= BLOCKSIZE)
	{
	  amount_read = 0;
	  set_next_block_after (start + (count - 1) / BLOCKSIZE);
	  if (count != bufsize)
	    {
	      ERROR ((0, 0,
		      _("File %s shrunk by %d bytes, padding with zeros"),
		      name, sizeleft));
	      return 1;
	    }
	  start = find_next_block ();
	}
      else
	amount_read += bufsize;
#endif
      nwritten += count;	/* FIXME: ??? */
      *sizeleft -= count;
      set_next_block_after (start);

    }
  free (sparsearray);
#if 0
  printf (_("Amount actually written is (I hope) %d.\n"), nwritten);
  set_next_block_after (start + (count - 1) / BLOCKSIZE);
#endif
  return 0;
}

/* Main functions of this module.  */

/*---.
| ?  |
`---*/

void
create_archive (void)
{
  char *p;

  open_archive (ACCESS_WRITE);

  if (incremental_option)
    {
      char *buffer = xmalloc (PATH_MAX);
      char *q, *bufp;

      collect_and_sort_names ();

      while (p = name_from_list (), p)
	dump_file (p, -1, 1);

      blank_name_list ();
      while (p = name_from_list (), p)
	{
	  strcpy (buffer, p);
	  if (p[strlen (p) - 1] != '/')
	    strcat (buffer, "/");
	  bufp = buffer + strlen (buffer);
	  for (q = gnu_list_name->dir_contents;
	       q && *q;
	       q += strlen (q) + 1)
	    {
	      if (*q == 'Y')
		{
		  strcpy (bufp, q + 1);
		  dump_file (buffer, -1, 1);
		}
	    }
	}
      free (buffer);
    }
  else
    {
      while (p = name_next (1), p)
	dump_file (p, -1, 1);
    }

  write_eot ();
  close_archive ();

  if (listed_incremental_option)
    write_dir_file ();
}

/*----------------------------------------------------------------------.
| Dump a single file.  Recurse on directories.  Result is nonzero for   |
| success.  P is file name to dump.  PARENT_DEVICE is device our parent |
| directory was on.  TOP_LEVEL tells wether we are a toplevel call.     |
|                                                                       |
|  Sets global CURRENT_STAT to stat output for this file.               |
`----------------------------------------------------------------------*/

/* FIXME: One should make sure that for *every* path leading to setting
   exit_status to failure, a clear diagnostic has been issued.  */

void
dump_file (char *p, int parent_device, int top_level)
{
  union block *header;
  char type;
  union block *exhdr;
  char save_typeflag;
  struct utimbuf restore_times;

  /* FIXME: `header' and `upperbound' might be used uninitialized in this
     function.  Reported by Bruno Haible.  */

  if (interactive_option && !confirm ("add", p))
    return;

  /* Use stat if following (rather than dumping) 4.2BSD's symbolic links.
     Otherwise, use lstat (which falls back to stat if no symbolic links).  */

  if (dereference_option != 0
#ifdef STX_HIDDEN		/* AIX */
      ? statx (p, &current_stat, STATSIZE, STX_HIDDEN)
      : statx (p, &current_stat, STATSIZE, STX_HIDDEN | STX_LINK)
#else
      ? stat (p, &current_stat) : lstat (p, &current_stat)
#endif
      )
    {
      WARN ((0, errno, _("Cannot add file %s"), p));
      if (!ignore_failed_read_option)
	exit_status = TAREXIT_FAILURE;
      return;
    }

  restore_times.actime = current_stat.st_atime;
  restore_times.modtime = current_stat.st_mtime;

#ifdef S_ISHIDDEN
  if (S_ISHIDDEN (current_stat.st_mode))
    {
      char *new = (char *) alloca (strlen (p) + 2);
      if (new)
