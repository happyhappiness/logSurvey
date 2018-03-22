#endif

  /* See if we only want new files, and check if this one is too old to
     put in the archive.  */

  if (!incremental_option && !S_ISDIR (current_stat.st_mode)
      && current_stat.st_mtime < newer_mtime_option
      && (!after_date_option || current_stat.st_ctime < newer_ctime_option))
    {
      if (parent_device == -1)
	WARN ((0, 0, _("%s: is unchanged; not dumped"), p));
      /* FIXME: recheck this return.  */
      return;
    }

#if !MSDOS
  /* See if we are trying to dump the archive.  */

  if (ar_dev && current_stat.st_dev == ar_dev && current_stat.st_ino == ar_ino)
    {
      WARN ((0, 0, _("%s is the archive; not dumped"), p));
      return;
    }
#endif

  /* Check for multiple links.

     We maintain a list of all such files that we've written so far.  Any
     time we see another, we check the list and avoid dumping the data
     again if we've done it once already.  */

  if (current_stat.st_nlink > 1
      && (S_ISREG (current_stat.st_mode)
#ifdef S_ISCTG
	  || S_ISCTG (current_stat.st_mode)
#endif
#ifdef S_ISCHR
	  || S_ISCHR (current_stat.st_mode)
#endif
#ifdef S_ISBLK
	  || S_ISBLK (current_stat.st_mode)
#endif
#ifdef S_ISFIFO
	  || S_ISFIFO (current_stat.st_mode)
#endif
      ))
    {
      struct link *lp;

      /* FIXME: First quick and dirty.  Hashing, etc later.  */

      for (lp = linklist; lp; lp = lp->next)
	if (lp->ino == current_stat.st_ino && lp->dev == current_stat.st_dev)
	  {
	    char *link_name = lp->name;

	    /* We found a link.  */

	    while (!absolute_names_option && *link_name == '/')
	      {
		static int warned_once = 0;

		if (!warned_once)
		  {
		    warned_once = 1;
		    WARN ((0, 0, _("\
Removing leading `/' from absolute links")));
		  }
		link_name++;
	      }
	    if (strlen (link_name) >= NAME_FIELD_SIZE)
	      write_long (link_name, GNUTYPE_LONGLINK);
	    assign_string (&current_link_name, link_name);

	    current_stat.st_size = 0;
	    header = start_header (p, &current_stat);
	    if (header == NULL)
	      {
		exit_status = TAREXIT_FAILURE;
		return;
	      }
	    strncpy (header->header.linkname,
		     link_name, NAME_FIELD_SIZE);

	    /* Force null truncated.  */

	    header->header.linkname[NAME_FIELD_SIZE - 1] = 0;

	    header->header.typeflag = LNKTYPE;
	    finish_header (header);

	    /* FIXME: Maybe remove from list after all links found?  */

	    if (remove_files_option)
	      if (unlink (p) == -1)
		ERROR ((0, errno, _("Cannot remove %s"), p));

	    /* We dumped it.  */
	    return;
	  }

      /* Not found.  Add it to the list of possible links.  */

      lp = (struct link *)
	xmalloc ((size_t) (sizeof (struct link) + strlen (p)));
      lp->ino = current_stat.st_ino;
      lp->dev = current_stat.st_dev;
      strcpy (lp->name, p);
      lp->next = linklist;
      linklist = lp;
    }

  /* This is not a link to a previously dumped file, so dump it.  */

  if (S_ISREG (current_stat.st_mode)
#ifdef S_ISCTG
      || S_ISCTG (current_stat.st_mode)
#endif
      )
    {
      int f;			/* file descriptor */
      long bufsize, count;
      long sizeleft;
      union block *start;
      int header_moved;
      char isextended = 0;
      int upperbound;
#if 0
      static int cried_once = 0;
#endif

      header_moved = 0;

      if (sparse_option)
	{
	  /* Check the size of the file against the number of blocks
	     allocated for it, counting both data and indirect blocks.
	     If there is a smaller number of blocks that would be
	     necessary to accommodate a file of this size, this is safe
	     to say that we have a sparse file: at least one of those
	     blocks in the file is just a useless hole.  For sparse
	     files not having more hole blocks than indirect blocks, the
	     sparseness will go undetected.  */

	  /* tar.h defines ST_NBLOCKS in term of 512 byte sectors, even
	     for HP-UX's which count in 1024 byte units and AIX's which
	     count in 4096 byte units.  So this should work...  */

	  /* Bruno Haible sent me these statistics for Linux.  It seems
	     that some filesystems count indirect blocks in st_blocks,
	     while others do not seem to:

	     minix-fs   tar: size=7205, st_blocks=18 and ST_NBLOCKS=18
	     extfs      tar: size=7205, st_blocks=18 and ST_NBLOCKS=18
	     ext2fs     tar: size=7205, st_blocks=16 and ST_NBLOCKS=16
	     msdos-fs   tar: size=7205, st_blocks=16 and ST_NBLOCKS=16

	     Dick Streefland reports the previous numbers as misleading,
	     because ext2fs use 12 direct blocks, while minix-fs uses only
	     6 direct blocks.  Dick gets:

	     ext2	size=20480	ls listed blocks=21
	     minix	size=20480	ls listed blocks=21
	     msdos	size=20480	ls listed blocks=20

	     It seems that indirect blocks *are* included in st_blocks.
	     The minix filesystem does not account for phantom blocks in
	     st_blocks, so `du' and `ls -s' give wrong results.  So, the
	     --sparse option would not work on a minix filesystem.  */

	  if (current_stat.st_size > ST_NBLOCKS (current_stat) * BLOCKSIZE)
	    {
	      int filesize = current_stat.st_size;
	      int counter;

	      header = start_header (p, &current_stat);
	      if (header == NULL)
		{
		  exit_status = TAREXIT_FAILURE;
		  return;
		}
	      header->header.typeflag = GNUTYPE_SPARSE;
	      header_moved = 1;

	      /* Call the routine that figures out the layout of the
		 sparse file in question.  UPPERBOUND is the index of the
		 last element of the "sparsearray," i.e., the number of
		 elements it needed to describe the file.  */

	      upperbound = deal_with_sparse (p, header);

	      /* See if we'll need an extended header later.  */

	      if (upperbound > SPARSES_IN_OLDGNU_HEADER - 1)
		header->oldgnu_header.isextended = 1;

	      /* We store the "real" file size so we can show that in
		 case someone wants to list the archive, i.e., tar tvf
		 <file>.  It might be kind of disconcerting if the
		 shrunken file size was the one that showed up.  */

	      to_oct ((long) current_stat.st_size, 1 + 12,
		      header->oldgnu_header.realsize);

	      /* This will be the new "size" of the file, i.e., the size
		 of the file minus the blocks of holes that we're
		 skipping over.  */

	      find_new_file_size (&filesize, upperbound);
	      current_stat.st_size = filesize;
	      to_oct ((long) filesize, 1 + 12, header->header.size);

	      for (counter = 0; counter < SPARSES_IN_OLDGNU_HEADER; counter++)
		{
		  if (!sparsearray[counter].numbytes)
		    break;

		  to_oct (sparsearray[counter].offset, 1 + 12,
			  header->oldgnu_header.sp[counter].offset);
		  to_oct (sparsearray[counter].numbytes, 1 + 12,
			  header->oldgnu_header.sp[counter].numbytes);
		}

	    }
	}
      else
	upperbound = SPARSES_IN_OLDGNU_HEADER - 1;

      sizeleft = current_stat.st_size;

      /* Don't bother opening empty, world readable files.  Also do not open
	 files when archive is meant for /dev/null.  */

      if (dev_null_output
	  || (sizeleft == 0 && 0444 == (0444 & current_stat.st_mode)))
	f = -1;
      else
	{
	  f = open (p, O_RDONLY | O_BINARY);
	  if (f < 0)
	    {
	      WARN ((0, errno, _("Cannot add file %s"), p));
	      if (!ignore_failed_read_option)
		exit_status = TAREXIT_FAILURE;
	      return;
	    }
	}

      /* If the file is sparse, we've already taken care of this.  */

      if (!header_moved)
	{
	  header = start_header (p, &current_stat);
	  if (header == NULL)
	    {
	      if (f >= 0)
		close (f);
	      exit_status = TAREXIT_FAILURE;
	      return;
	    }
	}
#ifdef S_ISCTG
      /* Mark contiguous files, if we support them.  */

      if (archive_format != V7_FORMAT && S_ISCTG (current_stat.st_mode))
	header->header.typeflag = CONTTYPE;
#endif
      isextended = header->oldgnu_header.isextended;
      save_typeflag = header->header.typeflag;
      finish_header (header);
      if (isextended)
	{
#if 0
	  int sum = 0;
#endif
	  int counter;
#if 0
	  union block *exhdr;
	  int arraybound = SPARSES_IN_SPARSE_HEADER;
#endif
	  /* static */ int index_offset = SPARSES_IN_OLDGNU_HEADER;

	extend:
	  exhdr = find_next_block ();

	  if (exhdr == NULL)
	    {
	      exit_status = TAREXIT_FAILURE;
	      return;
	    }
	  memset (exhdr->buffer, 0, BLOCKSIZE);
	  for (counter = 0; counter < SPARSES_IN_SPARSE_HEADER; counter++)
	    {
	      if (counter + index_offset > upperbound)
		break;

	      to_oct ((long) sparsearray[counter + index_offset].numbytes,
		      1 + 12,
		      exhdr->sparse_header.sp[counter].numbytes);
	      to_oct ((long) sparsearray[counter + index_offset].offset,
		      1 + 12,
		      exhdr->sparse_header.sp[counter].offset);
	    }
	  set_next_block_after (exhdr);
#if 0
	  sum += counter;
	  if (sum < upperbound)
	    goto extend;
#endif
	  if (index_offset + counter <= upperbound)
	    {
	      index_offset += counter;
	      exhdr->sparse_header.isextended = 1;
	      goto extend;
	    }

	}
      if (save_typeflag == GNUTYPE_SPARSE)
	{
	  if (finish_sparse_file (f, &sizeleft, current_stat.st_size, p))
	    goto padit;
	}
      else
	while (sizeleft > 0)
	  {
	    if (multi_volume_option)
	      {
		assign_string (&save_name, p);
		save_sizeleft = sizeleft;
		save_totsize = current_stat.st_size;
	      }
	    start = find_next_block ();

	    bufsize = available_space_after (start);

	    if (sizeleft < bufsize)
	      {
		/* Last read -- zero out area beyond.  */

		bufsize = (int) sizeleft;
		count = bufsize % BLOCKSIZE;
		if (count)
		  memset (start->buffer + sizeleft, 0,
			  (size_t) (BLOCKSIZE - count));
	      }
	    if (f < 0)
	      count = bufsize;
	    else
	      count = read (f, start->buffer, (size_t) bufsize);
	    if (count < 0)
	      {
		ERROR ((0, errno, _("\
Read error at byte %ld, reading %d bytes, in file %s"),
			(long) (current_stat.st_size - sizeleft), bufsize, p));
		goto padit;
	      }
	    sizeleft -= count;

	    /* This is nonportable (the type of set_next_block_after's arg).  */

	    set_next_block_after (start + (count - 1) / BLOCKSIZE);

	    if (count == bufsize)
	      continue;
	    ERROR ((0, 0, _("File %s shrunk by %d bytes, padding with zeros"),
		    p, sizeleft));
	    goto padit;		/* short read */
	  }

      if (multi_volume_option)
	assign_string (&save_name, NULL);

      if (f >= 0)
	{
	  close (f);
	  if (atime_preserve_option)
	    utime (p, &restore_times);
	}
      if (remove_files_option)
	{
	  if (unlink (p) == -1)
	    ERROR ((0, errno, _("Cannot remove %s"), p));
	}
      return;

      /* File shrunk or gave error, pad out tape to match the size we
	 specified in the header.  */

    padit:
      while (sizeleft > 0)
	{
	  save_sizeleft = sizeleft;
	  start = find_next_block ();
	  memset (start->buffer, 0, BLOCKSIZE);
	  set_next_block_after (start);
	  sizeleft -= BLOCKSIZE;
	}
      if (multi_volume_option)
	assign_string (&save_name, NULL);
      if (f >= 0)
	{
	  close (f);
	  if (atime_preserve_option)
	    utime (p, &restore_times);
	}
      return;
    }

#ifdef S_ISLNK
  else if (S_ISLNK (current_stat.st_mode))
    {
      int size;
      char *buffer = (char *) alloca (PATH_MAX + 1);

      size = readlink (p, buffer, PATH_MAX + 1);
      if (size < 0)
	{
	  WARN ((0, errno, _("Cannot add file %s"), p));
	  if (!ignore_failed_read_option)
	    exit_status = TAREXIT_FAILURE;
	  return;
	}
      buffer[size] = '\0';
      if (size >= NAME_FIELD_SIZE)
	write_long (buffer, GNUTYPE_LONGLINK);
      assign_string (&current_link_name, buffer);

      current_stat.st_size = 0;	/* force 0 size on symlink */
      header = start_header (p, &current_stat);
      if (header == NULL)
	{
	  exit_status = TAREXIT_FAILURE;
	  return;
	}
      strncpy (header->header.linkname, buffer, NAME_FIELD_SIZE);
      header->header.linkname[NAME_FIELD_SIZE - 1] = '\0';
      header->header.typeflag = SYMTYPE;
      finish_header (header);	/* nothing more to do to it */
      if (remove_files_option)
	{
	  if (unlink (p) == -1)
	    ERROR ((0, errno, _("Cannot remove %s"), p));
	}
      return;
    }
#endif /* S_ISLNK */

  else if (S_ISDIR (current_stat.st_mode))
    {
      DIR *directory;
      struct dirent *entry;
      char *namebuf;
      int buflen;
      int len;
      int our_device = current_stat.st_dev;

      /* If this tar program is installed suid root, like for Amanda, the
	 access might look like denied, while it is not really.

	 FIXME: I have the feeling this test is done too early.  Couldn't it
	 just be bundled in later actions?  I guess that the proper support
	 of --ignore-failed-read is the key of the current writing.  */

      if (access (p, R_OK) == -1 && geteuid () != 0)
	{
	  WARN ((0, errno, _("Cannot add directory %s"), p));
	  if (!ignore_failed_read_option)
	    exit_status = TAREXIT_FAILURE;
	  return;
	}

      /* Build new prototype name.  Ensure exactly one trailing slash.  */

      len = strlen (p);
      buflen = len + NAME_FIELD_SIZE;
      namebuf = xmalloc ((size_t) (buflen + 1));
      strncpy (namebuf, p, (size_t) buflen);
      while (len >= 1 && namebuf[len - 1] == '/')
	len--;
      namebuf[len++] = '/';
      namebuf[len] = '\0';

      if (1)
	{
	  /* The "1" above used to be "archive_format != V7_FORMAT", GNU tar
	     was just not writing directory blocks at all.  Daniel Trinkle
	     writes: ``All old versions of tar I have ever seen have
	     correctly archived an empty directory.  The really old ones I
	     checked included HP-UX 7 and Mt. Xinu More/BSD.  There may be
	     some subtle reason for the exclusion that I don't know, but the
	     current behavior is broken.''  I do not know those subtle
	     reasons either, so until these are reported (anew?), just allow
	     directory blocks to be written even with old archives.  */

	  current_stat.st_size = 0;	/* force 0 size on dir */

	  /* FIXME: If people could really read standard archives, this
	     should be:

	     header
	       = start_header (standard_option ? p : namebuf, &current_stat);

	     but since they'd interpret DIRTYPE blocks as regular
	     files, we'd better put the / on the name.  */

	  header = start_header (namebuf, &current_stat);
	  if (header == NULL)
	    {
	      exit_status = TAREXIT_FAILURE;
	      return;	/* eg name too long */
	    }

	  if (incremental_option)
	    header->header.typeflag = GNUTYPE_DUMPDIR;
	  else /* if (standard_option) */
	    header->header.typeflag = DIRTYPE;

	  /* If we're gnudumping, we aren't done yet so don't close it.  */

	  if (!incremental_option)
	    finish_header (header);	/* done with directory header */
	}

      if (incremental_option && gnu_list_name->dir_contents)
	{
	  int sizeleft;
	  int totsize;
	  int bufsize;
	  union block *start;
	  int count;
	  char *buffer, *p_buffer;

	  buffer = gnu_list_name->dir_contents; /* FOO */
	  totsize = 0;
	  for (p_buffer = buffer; p_buffer && *p_buffer;)
	    {
	      int tmp;

	      tmp = strlen (p_buffer) + 1;
	      totsize += tmp;
	      p_buffer += tmp;
	    }
	  totsize++;
	  to_oct ((long) totsize, 1 + 12, header->header.size);
	  finish_header (header);
	  p_buffer = buffer;
	  sizeleft = totsize;
	  while (sizeleft > 0)
	    {
	      if (multi_volume_option)
		{
		  assign_string (&save_name, p);
		  save_sizeleft = sizeleft;
		  save_totsize = totsize;
		}
	      start = find_next_block ();
	      bufsize = available_space_after (start);
	      if (sizeleft < bufsize)
		{
		  bufsize = sizeleft;
		  count = bufsize % BLOCKSIZE;
		  if (count)
		    memset (start->buffer + sizeleft, 0,
			   (size_t) (BLOCKSIZE - count));
		}
	      memcpy (start->buffer, p_buffer, (size_t) bufsize);
	      sizeleft -= bufsize;
	      p_buffer += bufsize;
	      set_next_block_after (start + (bufsize - 1) / BLOCKSIZE);
	    }
	  if (multi_volume_option)
	    assign_string (&save_name, NULL);
	  if (atime_preserve_option)
	    utime (p, &restore_times);
	  return;
	}

      /* See if we are about to recurse into a directory, and avoid doing
	 so if the user wants that we do not descend into directories.  */

      if (no_recurse_option)
	return;

      /* See if we are crossing from one file system to another, and
	 avoid doing so if the user only wants to dump one file system.  */

      if (one_file_system_option && !top_level
	  && parent_device != current_stat.st_dev)
	{
	  if (verbose_option)
	    WARN ((0, 0, _("%s: On a different filesystem; not dumped"), p));
	  return;
	}

      /* Now output all the files in the directory.  */

      errno = 0;		/* FIXME: errno should be read-only */

      directory = opendir (p);
      if (!directory)
	{
	  ERROR ((0, errno, _("Cannot open directory %s"), p));
	  return;
	}

      /* Hack to remove "./" from the front of all the file names.  */

      if (len == 2 && namebuf[0] == '.' && namebuf[1] == '/')
	len = 0;

      /* FIXME: Should speed this up by cd-ing into the dir.  */

      while (entry = readdir (directory), entry)
	{
	  /* Skip `.' and `..'.  */

	  if (is_dot_or_dotdot (entry->d_name))
	    continue;

	  if ((int) NAMLEN (entry) + len >= buflen)
	    {
	      buflen = len + NAMLEN (entry);
	      namebuf = (char *) xrealloc (namebuf, (size_t) (buflen + 1));
#if 0
	      namebuf[len] = '\0';
	      ERROR ((0, 0, _("File name %s%s too long"),
		      namebuf, entry->d_name));
	      continue;
#endif
	    }
	  strcpy (namebuf + len, entry->d_name);
	  if (exclude_option && check_exclude (namebuf))
	    continue;
	  dump_file (namebuf, our_device, 0);
	}

      closedir (directory);
      free (namebuf);
      if (atime_preserve_option)
	utime (p, &restore_times);
      return;
    }

#ifdef S_ISCHR
  else if (S_ISCHR (current_stat.st_mode))
    type = CHRTYPE;
#endif

#ifdef S_ISBLK
  else if (S_ISBLK (current_stat.st_mode))
    type = BLKTYPE;
#endif

  /* Avoid screwy apollo lossage where S_IFIFO == S_IFSOCK.  */

#if (_ISP__M68K == 0) && (_ISP__A88K == 0) && defined(S_ISFIFO)
  else if (S_ISFIFO (current_stat.st_mode))
    type = FIFOTYPE;
#endif

#ifdef S_ISSOCK
  else if (S_ISSOCK (current_stat.st_mode))
    type = FIFOTYPE;
#endif

  else
    goto unknown;

  if (archive_format == V7_FORMAT)
    goto unknown;

  current_stat.st_size = 0;	/* force 0 size */
  header = start_header (p, &current_stat);
  if (header == NULL)
    {
      exit_status = TAREXIT_FAILURE;
      return;	/* eg name too long */
    }

  header->header.typeflag = type;

#if defined(S_IFBLK) || defined(S_IFCHR)
  if (type != FIFOTYPE)
    {
      to_oct ((long) major (current_stat.st_rdev), 8,
	      header->header.devmajor);
      to_oct ((long) minor (current_stat.st_rdev), 8,
	      header->header.devminor);
    }
#endif

  finish_header (header);
  if (remove_files_option)
    {
      if (unlink (p) == -1)
	ERROR ((0, errno, _("Cannot remove %s"), p));
    }
  return;

unknown:
  ERROR ((0, 0, _("%s: Unknown file type; file ignored"), p));
}
