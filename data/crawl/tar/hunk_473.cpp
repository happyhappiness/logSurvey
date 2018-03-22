 #endif
 
   /* See if we only want new files, and check if this one is too old to
-	   put in the archive. */
-  if (f_new_files
-      && !f_gnudump
-      && new_time > hstat.st_mtime
-      && !S_ISDIR (hstat.st_mode)
-      && (f_new_files > 1 || new_time > hstat.st_ctime))
+     put in the archive.  */
+
+  if (!incremental_option && !S_ISDIR (current_stat.st_mode)
+      && current_stat.st_mtime < newer_mtime_option
+      && (!after_date_option || current_stat.st_ctime < newer_ctime_option))
     {
-      if (curdev == -1)
-	{
-	  msg ("%s: is unchanged; not dumped", p);
-	}
+      if (parent_device == -1)
+	WARN ((0, 0, _("%s: is unchanged; not dumped"), p));
+      /* FIXME: recheck this return.  */
       return;
     }
 
-#ifndef __MSDOS__
-  /* See if we are trying to dump the archive */
-  if (ar_dev && hstat.st_dev == ar_dev && hstat.st_ino == ar_ino)
+#if !MSDOS
+  /* See if we are trying to dump the archive.  */
+
+  if (ar_dev && current_stat.st_dev == ar_dev && current_stat.st_ino == ar_ino)
     {
-      msg ("%s is the archive; not dumped", p);
+      WARN ((0, 0, _("%s is the archive; not dumped"), p));
       return;
     }
 #endif
-  /*
-	 * Check for multiple links.
-	 *
-	 * We maintain a list of all such files that we've written so
-	 * far.  Any time we see another, we check the list and
-	 * avoid dumping the data again if we've done it once already.
-	 */
-  if (hstat.st_nlink > 1
-      && (S_ISREG (hstat.st_mode)
+
+  /* Check for multiple links.
+
+     We maintain a list of all such files that we've written so far.  Any
+     time we see another, we check the list and avoid dumping the data
+     again if we've done it once already.  */
+
+  if (current_stat.st_nlink > 1
+      && (S_ISREG (current_stat.st_mode)
 #ifdef S_ISCTG
-	  || S_ISCTG (hstat.st_mode)
+	  || S_ISCTG (current_stat.st_mode)
 #endif
 #ifdef S_ISCHR
-	  || S_ISCHR (hstat.st_mode)
+	  || S_ISCHR (current_stat.st_mode)
 #endif
 #ifdef S_ISBLK
-	  || S_ISBLK (hstat.st_mode)
+	  || S_ISBLK (current_stat.st_mode)
 #endif
 #ifdef S_ISFIFO
-	  || S_ISFIFO (hstat.st_mode)
+	  || S_ISFIFO (current_stat.st_mode)
 #endif
       ))
     {
-      register struct link *lp;
+      struct link *lp;
+
+      /* FIXME: First quick and dirty.  Hashing, etc later.  */
 
-      /* First quick and dirty.  Hashing, etc later FIXME */
       for (lp = linklist; lp; lp = lp->next)
-	{
-	  if (lp->ino == hstat.st_ino &&
-	      lp->dev == hstat.st_dev)
-	    {
-	      char *link_name = lp->name;
+	if (lp->ino == current_stat.st_ino && lp->dev == current_stat.st_dev)
+	  {
+	    char *link_name = lp->name;
 
-	      /* We found a link. */
-	      while (!f_absolute_paths && *link_name == '/')
-		{
-		  static int link_warn = 0;
-
-		  if (!link_warn)
-		    {
-		      msg ("Removing leading / from absolute links");
-		      link_warn++;
-		    }
-		  link_name++;
-		}
-	      if (link_name - lp->name >= NAMSIZ)
-		write_long (link_name, LF_LONGLINK);
-	      current_link_name = link_name;
+	    /* We found a link.  */
 
-	      hstat.st_size = 0;
-	      header = start_header (p, &hstat);
-	      if (header == NULL)
-		{
-		  critical_error = 1;
-		  goto badfile;
-		}
-	      strncpy (header->header.arch_linkname,
-		       link_name, NAMSIZ);
+	    while (!absolute_names_option && *link_name == '/')
+	      {
+		static int warned_once = 0;
+
+		if (!warned_once)
+		  {
+		    warned_once = 1;
+		    WARN ((0, 0, _("\
+Removing leading `/' from absolute links")));
+		  }
+		link_name++;
+	      }
+	    if (strlen (link_name) >= NAME_FIELD_SIZE)
+	      write_long (link_name, GNUTYPE_LONGLINK);
+	    assign_string (&current_link_name, link_name);
 
-	      /* Force null truncated */
-	      header->header.arch_linkname[NAMSIZ - 1] = 0;
+	    current_stat.st_size = 0;
+	    header = start_header (p, &current_stat);
+	    if (header == NULL)
+	      {
+		exit_status = TAREXIT_FAILURE;
+		return;
+	      }
+	    strncpy (header->header.linkname,
+		     link_name, NAME_FIELD_SIZE);
 
-	      header->header.linkflag = LF_LINK;
-	      finish_header (header);
-	      /* FIXME: Maybe remove from list after all links found? */
-	      if (f_remove_files)
-		{
-		  if (unlink (p) == -1)
-		    msg_perror ("cannot remove %s", p);
-		}
-	      return;		/* We dumped it */
-	    }
-	}
+	    /* Force null truncated.  */
 
-      /* Not found.  Add it to the list of possible links. */
-      lp = (struct link *) ck_malloc ((unsigned) (sizeof (struct link) + strlen (p)));
-      if (!lp)
-	{
-	  if (!nolinks)
-	    {
-	      msg (
-	      "no memory for links, they will be dumped as separate files");
-	      nolinks++;
-	    }
-	}
-      lp->ino = hstat.st_ino;
-      lp->dev = hstat.st_dev;
+	    header->header.linkname[NAME_FIELD_SIZE - 1] = 0;
+
+	    header->header.typeflag = LNKTYPE;
+	    finish_header (header);
+
+	    /* FIXME: Maybe remove from list after all links found?  */
+
+	    if (remove_files_option)
+	      if (unlink (p) == -1)
+		ERROR ((0, errno, _("Cannot remove %s"), p));
+
+	    /* We dumped it.  */
+	    return;
+	  }
+
+      /* Not found.  Add it to the list of possible links.  */
+
+      lp = (struct link *)
+	xmalloc ((size_t) (sizeof (struct link) + strlen (p)));
+      lp->ino = current_stat.st_ino;
+      lp->dev = current_stat.st_dev;
       strcpy (lp->name, p);
       lp->next = linklist;
       linklist = lp;
     }
 
-  /*
-	 * This is not a link to a previously dumped file, so dump it.
-	 */
-  if (S_ISREG (hstat.st_mode)
+  /* This is not a link to a previously dumped file, so dump it.  */
+
+  if (S_ISREG (current_stat.st_mode)
 #ifdef S_ISCTG
-      || S_ISCTG (hstat.st_mode)
+      || S_ISCTG (current_stat.st_mode)
 #endif
-    )
+      )
     {
-      int f;			/* File descriptor */
+      int f;			/* file descriptor */
       long bufsize, count;
       long sizeleft;
-      register union record *start;
+      union block *start;
       int header_moved;
       char isextended = 0;
       int upperbound;
-      /*		int	end_nulls = 0; */
+#if 0
+      static int cried_once = 0;
+#endif
 
       header_moved = 0;
 
-#ifdef BSD42
-      if (f_sparse_files)
+      if (sparse_option)
 	{
-	  /*
-	 	 * JK - This is the test for sparseness: whether the
-		 * "size" of the file matches the number of blocks
-		 * allocated for it.  If there is a smaller number
-		 * of blocks that would be necessary to accommodate
-		 * a file of this size, we have a sparse file, i.e.,
-		 * at least one of those records in the file is just
-		 * a useless hole.
-		 */
-#ifdef hpux			/* Nice of HPUX to gratuitiously change it, huh?  - mib */
-	  if (hstat.st_size - (hstat.st_blocks * 1024) > 1024)
-#else
-	  if (hstat.st_size - (hstat.st_blocks * RECORDSIZE) > RECORDSIZE)
-#endif
+	  /* Check the size of the file against the number of blocks
+	     allocated for it, counting both data and indirect blocks.
+	     If there is a smaller number of blocks that would be
+	     necessary to accommodate a file of this size, this is safe
+	     to say that we have a sparse file: at least one of those
+	     blocks in the file is just a useless hole.  For sparse
+	     files not having more hole blocks than indirect blocks, the
+	     sparseness will go undetected.  */
+
+	  /* tar.h defines ST_NBLOCKS in term of 512 byte sectors, even
+	     for HP-UX's which count in 1024 byte units and AIX's which
+	     count in 4096 byte units.  So this should work...  */
+
+	  /* Bruno Haible sent me these statistics for Linux.  It seems
+	     that some filesystems count indirect blocks in st_blocks,
+	     while others do not seem to:
+
+	     minix-fs   tar: size=7205, st_blocks=18 and ST_NBLOCKS=18
+	     extfs      tar: size=7205, st_blocks=18 and ST_NBLOCKS=18
+	     ext2fs     tar: size=7205, st_blocks=16 and ST_NBLOCKS=16
+	     msdos-fs   tar: size=7205, st_blocks=16 and ST_NBLOCKS=16
+
+	     Dick Streefland reports the previous numbers as misleading,
+	     because ext2fs use 12 direct blocks, while minix-fs uses only
+	     6 direct blocks.  Dick gets:
+
+	     ext2	size=20480	ls listed blocks=21
+	     minix	size=20480	ls listed blocks=21
+	     msdos	size=20480	ls listed blocks=20
+
+	     It seems that indirect blocks *are* included in st_blocks.
+	     The minix filesystem does not account for phantom blocks in
+	     st_blocks, so `du' and `ls -s' give wrong results.  So, the
+	     --sparse option would not work on a minix filesystem.  */
+
+	  if (current_stat.st_size > ST_NBLOCKS (current_stat) * BLOCKSIZE)
 	    {
-	      int filesize = hstat.st_size;
-	      register int i;
+	      int filesize = current_stat.st_size;
+	      int counter;
 
-	      header = start_header (p, &hstat);
+	      header = start_header (p, &current_stat);
 	      if (header == NULL)
 		{
-		  critical_error = 1;
-		  goto badfile;
+		  exit_status = TAREXIT_FAILURE;
+		  return;
 		}
-	      header->header.linkflag = LF_SPARSE;
-	      header_moved++;
-
-	      /*
-			 * Call the routine that figures out the
-			 * layout of the sparse file in question.
-			 * UPPERBOUND is the index of the last
-			 * element of the "sparsearray," i.e.,
-			 * the number of elements it needed to
-			 * describe the file.
-			 */
+	      header->header.typeflag = GNUTYPE_SPARSE;
+	      header_moved = 1;
+
+	      /* Call the routine that figures out the layout of the
+		 sparse file in question.  UPPERBOUND is the index of the
+		 last element of the "sparsearray," i.e., the number of
+		 elements it needed to describe the file.  */
 
 	      upperbound = deal_with_sparse (p, header);
 
-	      /*
-			 * See if we'll need an extended header
-			 * later
-			 */
-	      if (upperbound > SPARSE_IN_HDR - 1)
-		header->header.isextended++;
-	      /*
-			 * We store the "real" file size so
-			 * we can show that in case someone wants
-			 * to list the archive, i.e., tar tvf <file>.
-			 * It might be kind of disconcerting if the
-			 * shrunken file size was the one that showed
-			 * up.
-			 */
-	      to_oct ((long) hstat.st_size, 1 + 12,
-		      header->header.realsize);
-
-	      /*
-			 * This will be the new "size" of the
-			 * file, i.e., the size of the file
-			 * minus the records of holes that we're
-			 * skipping over.
-			 */
+	      /* See if we'll need an extended header later.  */
+
+	      if (upperbound > SPARSES_IN_OLDGNU_HEADER - 1)
+		header->oldgnu_header.isextended = 1;
+
+	      /* We store the "real" file size so we can show that in
+		 case someone wants to list the archive, i.e., tar tvf
+		 <file>.  It might be kind of disconcerting if the
+		 shrunken file size was the one that showed up.  */
+
+	      to_oct ((long) current_stat.st_size, 1 + 12,
+		      header->oldgnu_header.realsize);
+
+	      /* This will be the new "size" of the file, i.e., the size
+		 of the file minus the blocks of holes that we're
+		 skipping over.  */
 
 	      find_new_file_size (&filesize, upperbound);
-	      hstat.st_size = filesize;
-	      to_oct ((long) filesize, 1 + 12,
-		      header->header.size);
-	      /*				to_oct((long) end_nulls, 1+12,
-						header->header.ending_blanks);*/
+	      current_stat.st_size = filesize;
+	      to_oct ((long) filesize, 1 + 12, header->header.size);
 
-	      for (i = 0; i < SPARSE_IN_HDR; i++)
+	      for (counter = 0; counter < SPARSES_IN_OLDGNU_HEADER; counter++)
 		{
-		  if (!sparsearray[i].numbytes)
+		  if (!sparsearray[counter].numbytes)
 		    break;
-		  to_oct (sparsearray[i].offset, 1 + 12,
-			  header->header.sp[i].offset);
-		  to_oct (sparsearray[i].numbytes, 1 + 12,
-			  header->header.sp[i].numbytes);
+
+		  to_oct (sparsearray[counter].offset, 1 + 12,
+			  header->oldgnu_header.sp[counter].offset);
+		  to_oct (sparsearray[counter].numbytes, 1 + 12,
+			  header->oldgnu_header.sp[counter].numbytes);
 		}
 
 	    }
 	}
-#else
-      upperbound = SPARSE_IN_HDR - 1;
-#endif
+      else
+	upperbound = SPARSES_IN_OLDGNU_HEADER - 1;
+
+      sizeleft = current_stat.st_size;
 
-      sizeleft = hstat.st_size;
-      /* Don't bother opening empty, world readable files. */
-      if (sizeleft > 0 || 0444 != (0444 & hstat.st_mode))
+      /* Don't bother opening empty, world readable files.  Also do not open
+	 files when archive is meant for /dev/null.  */
+
+      if (dev_null_output
+	  || (sizeleft == 0 && 0444 == (0444 & current_stat.st_mode)))
+	f = -1;
+      else
 	{
 	  f = open (p, O_RDONLY | O_BINARY);
 	  if (f < 0)
-	    goto badperror;
-	}
-      else
-	{
-	  f = -1;
+	    {
+	      WARN ((0, errno, _("Cannot add file %s"), p));
+	      if (!ignore_failed_read_option)
+		exit_status = TAREXIT_FAILURE;
+	      return;
+	    }
 	}
 
-      /* If the file is sparse, we've already taken care of this */
+      /* If the file is sparse, we've already taken care of this.  */
+
       if (!header_moved)
 	{
-	  header = start_header (p, &hstat);
+	  header = start_header (p, &current_stat);
 	  if (header == NULL)
 	    {
 	      if (f >= 0)
-		(void) close (f);
-	      critical_error = 1;
-	      goto badfile;
+		close (f);
+	      exit_status = TAREXIT_FAILURE;
+	      return;
 	    }
 	}
 #ifdef S_ISCTG
-      /* Mark contiguous files, if we support them */
-      if (f_standard && S_ISCTG (hstat.st_mode))
-	{
-	  header->header.linkflag = LF_CONTIG;
-	}
+      /* Mark contiguous files, if we support them.  */
+
+      if (archive_format != V7_FORMAT && S_ISCTG (current_stat.st_mode))
+	header->header.typeflag = CONTTYPE;
 #endif
-      isextended = header->header.isextended;
-      save_linkflag = header->header.linkflag;
+      isextended = header->oldgnu_header.isextended;
+      save_typeflag = header->header.typeflag;
       finish_header (header);
       if (isextended)
 	{
-	  /*			int	 sum = 0;*/
-	  register int i;
-	  /*			register union record *exhdr;*/
-	  /*			int	 arraybound = SPARSE_EXT_HDR;*/
-	  /* static */ int index_offset = SPARSE_IN_HDR;
+#if 0
+	  int sum = 0;
+#endif
+	  int counter;
+#if 0
+	  union block *exhdr;
+	  int arraybound = SPARSES_IN_SPARSE_HEADER;
+#endif
+	  /* static */ int index_offset = SPARSES_IN_OLDGNU_HEADER;
 
-	extend:exhdr = findrec ();
+	extend:
+	  exhdr = find_next_block ();
 
 	  if (exhdr == NULL)
 	    {
-	      critical_error = 1;
-	      goto badfile;
+	      exit_status = TAREXIT_FAILURE;
+	      return;
 	    }
-	  bzero (exhdr->charptr, RECORDSIZE);
-	  for (i = 0; i < SPARSE_EXT_HDR; i++)
+	  memset (exhdr->buffer, 0, BLOCKSIZE);
+	  for (counter = 0; counter < SPARSES_IN_SPARSE_HEADER; counter++)
 	    {
-	      if (i + index_offset > upperbound)
+	      if (counter + index_offset > upperbound)
 		break;
-	      to_oct ((long) sparsearray[i + index_offset].numbytes,
+
+	      to_oct ((long) sparsearray[counter + index_offset].numbytes,
 		      1 + 12,
-		      exhdr->ext_hdr.sp[i].numbytes);
-	      to_oct ((long) sparsearray[i + index_offset].offset,
+		      exhdr->sparse_header.sp[counter].numbytes);
+	      to_oct ((long) sparsearray[counter + index_offset].offset,
 		      1 + 12,
-		      exhdr->ext_hdr.sp[i].offset);
+		      exhdr->sparse_header.sp[counter].offset);
 	    }
-	  userec (exhdr);
-	  /*			sum += i;
-			if (sum < upperbound)
-				goto extend;*/
-	  if (index_offset + i <= upperbound)
+	  set_next_block_after (exhdr);
+#if 0
+	  sum += counter;
+	  if (sum < upperbound)
+	    goto extend;
+#endif
+	  if (index_offset + counter <= upperbound)
 	    {
-	      index_offset += i;
-	      exhdr->ext_hdr.isextended++;
+	      index_offset += counter;
+	      exhdr->sparse_header.isextended = 1;
 	      goto extend;
 	    }
 
 	}
-      if (save_linkflag == LF_SPARSE)
+      if (save_typeflag == GNUTYPE_SPARSE)
 	{
-	  if (finish_sparse_file (f, &sizeleft, hstat.st_size, p))
+	  if (finish_sparse_file (f, &sizeleft, current_stat.st_size, p))
 	    goto padit;
 	}
       else
 	while (sizeleft > 0)
 	  {
-
-	    if (f_multivol)
+	    if (multi_volume_option)
 	      {
-		save_name = p;
+		assign_string (&save_name, p);
 		save_sizeleft = sizeleft;
-		save_totsize = hstat.st_size;
+		save_totsize = current_stat.st_size;
 	      }
-	    start = findrec ();
+	    start = find_next_block ();
 
-	    bufsize = endofrecs ()->charptr - start->charptr;
+	    bufsize = available_space_after (start);
 
 	    if (sizeleft < bufsize)
 	      {
-		/* Last read -- zero out area beyond */
+		/* Last read -- zero out area beyond.  */
+
 		bufsize = (int) sizeleft;
-		count = bufsize % RECORDSIZE;
+		count = bufsize % BLOCKSIZE;
 		if (count)
-		  bzero (start->charptr + sizeleft,
-			 (int) (RECORDSIZE - count));
+		  memset (start->buffer + sizeleft, 0,
+			  (size_t) (BLOCKSIZE - count));
 	      }
-	    count = read (f, start->charptr, bufsize);
+	    if (f < 0)
+	      count = bufsize;
+	    else
+	      count = read (f, start->buffer, (size_t) bufsize);
 	    if (count < 0)
 	      {
-		msg_perror ("read error at byte %ld, reading\
- %d bytes, in file %s", hstat.st_size - sizeleft, bufsize, p);
+		ERROR ((0, errno, _("\
+Read error at byte %ld, reading %d bytes, in file %s"),
+			(long) (current_stat.st_size - sizeleft), bufsize, p));
 		goto padit;
 	      }
 	    sizeleft -= count;
 
-	    /* This is nonportable (the type of userec's arg). */
-	    userec (start + (count - 1) / RECORDSIZE);
+	    /* This is nonportable (the type of set_next_block_after's arg).  */
+
+	    set_next_block_after (start + (count - 1) / BLOCKSIZE);
 
 	    if (count == bufsize)
 	      continue;
-	    msg ("file %s shrunk by %d bytes, padding with zeros.", p, sizeleft);
-	    goto padit;		/* Short read */
+	    ERROR ((0, 0, _("File %s shrunk by %d bytes, padding with zeros"),
+		    p, sizeleft));
+	    goto padit;		/* short read */
 	  }
 
-      if (f_multivol)
-	save_name = 0;
+      if (multi_volume_option)
+	assign_string (&save_name, NULL);
 
       if (f >= 0)
-	(void) close (f);
-
-      if (f_remove_files)
+	{
+	  close (f);
+	  if (atime_preserve_option)
+	    utime (p, &restore_times);
+	}
+      if (remove_files_option)
 	{
 	  if (unlink (p) == -1)
-	    msg_perror ("cannot remove %s", p);
+	    ERROR ((0, errno, _("Cannot remove %s"), p));
 	}
-      if (f_atime_preserve)
-	utime (p, &restore_times);
       return;
 
-      /*
-		 * File shrunk or gave error, pad out tape to match
-		 * the size we specified in the header.
-		 */
+      /* File shrunk or gave error, pad out tape to match the size we
+	 specified in the header.  */
+
     padit:
       while (sizeleft > 0)
 	{
 	  save_sizeleft = sizeleft;
-	  start = findrec ();
-	  bzero (start->charptr, RECORDSIZE);
-	  userec (start);
-	  sizeleft -= RECORDSIZE;
+	  start = find_next_block ();
+	  memset (start->buffer, 0, BLOCKSIZE);
+	  set_next_block_after (start);
+	  sizeleft -= BLOCKSIZE;
 	}
-      if (f_multivol)
-	save_name = 0;
+      if (multi_volume_option)
+	assign_string (&save_name, NULL);
       if (f >= 0)
-	(void) close (f);
-      if (f_atime_preserve)
-	utime (p, &restore_times);
+	{
+	  close (f);
+	  if (atime_preserve_option)
+	    utime (p, &restore_times);
+	}
       return;
     }
 
 #ifdef S_ISLNK
-  else if (S_ISLNK (hstat.st_mode))
+  else if (S_ISLNK (current_stat.st_mode))
     {
       int size;
-      char *buf = alloca (PATH_MAX + 1);
+      char *buffer = (char *) alloca (PATH_MAX + 1);
 
-      size = readlink (p, buf, PATH_MAX + 1);
+      size = readlink (p, buffer, PATH_MAX + 1);
       if (size < 0)
-	goto badperror;
-      buf[size] = '\0';
-      if (size >= NAMSIZ)
-	write_long (buf, LF_LONGLINK);
-      current_link_name = buf;
-
-      hstat.st_size = 0;	/* Force 0 size on symlink */
-      header = start_header (p, &hstat);
+	{
+	  WARN ((0, errno, _("Cannot add file %s"), p));
+	  if (!ignore_failed_read_option)
+	    exit_status = TAREXIT_FAILURE;
+	  return;
+	}
+      buffer[size] = '\0';
+      if (size >= NAME_FIELD_SIZE)
+	write_long (buffer, GNUTYPE_LONGLINK);
+      assign_string (&current_link_name, buffer);
+
+      current_stat.st_size = 0;	/* force 0 size on symlink */
+      header = start_header (p, &current_stat);
       if (header == NULL)
 	{
-	  critical_error = 1;
-	  goto badfile;
+	  exit_status = TAREXIT_FAILURE;
+	  return;
 	}
-      strncpy (header->header.arch_linkname, buf, NAMSIZ);
-      header->header.arch_linkname[NAMSIZ - 1] = '\0';
-      header->header.linkflag = LF_SYMLINK;
-      finish_header (header);	/* Nothing more to do to it */
-      if (f_remove_files)
+      strncpy (header->header.linkname, buffer, NAME_FIELD_SIZE);
+      header->header.linkname[NAME_FIELD_SIZE - 1] = '\0';
+      header->header.typeflag = SYMTYPE;
+      finish_header (header);	/* nothing more to do to it */
+      if (remove_files_option)
 	{
 	  if (unlink (p) == -1)
-	    msg_perror ("cannot remove %s", p);
+	    ERROR ((0, errno, _("Cannot remove %s"), p));
 	}
       return;
     }
-#endif
+#endif /* S_ISLNK */
 
-  else if (S_ISDIR (hstat.st_mode))
+  else if (S_ISDIR (current_stat.st_mode))
     {
-      register DIR *dirp;
-      register struct dirent *d;
+      DIR *directory;
+      struct dirent *entry;
       char *namebuf;
       int buflen;
-      register int len;
-      int our_device = hstat.st_dev;
+      int len;
+      int our_device = current_stat.st_dev;
+
+      /* If this tar program is installed suid root, like for Amanda, the
+	 access might look like denied, while it is not really.
+
+	 FIXME: I have the feeling this test is done too early.  Couldn't it
+	 just be bundled in later actions?  I guess that the proper support
+	 of --ignore-failed-read is the key of the current writing.  */
+
+      if (access (p, R_OK) == -1 && geteuid () != 0)
+	{
+	  WARN ((0, errno, _("Cannot add directory %s"), p));
+	  if (!ignore_failed_read_option)
+	    exit_status = TAREXIT_FAILURE;
+	  return;
+	}
+
+      /* Build new prototype name.  Ensure exactly one trailing slash.  */
 
-      /* Build new prototype name */
       len = strlen (p);
-      buflen = len + NAMSIZ;
-      namebuf = ck_malloc (buflen + 1);
-      strncpy (namebuf, p, buflen);
-      while (len >= 1 && '/' == namebuf[len - 1])
-	len--;			/* Delete trailing slashes */
-      namebuf[len++] = '/';	/* Now add exactly one back */
-      namebuf[len] = '\0';	/* Make sure null-terminated */
-
-      /*
-		 * Output directory header record with permissions
-		 * FIXME, do this AFTER files, to avoid R/O dir problems?
-		 * If old archive format, don't write record at all.
-		 */
-      if (!f_oldarch)
+      buflen = len + NAME_FIELD_SIZE;
+      namebuf = xmalloc ((size_t) (buflen + 1));
+      strncpy (namebuf, p, (size_t) buflen);
+      while (len >= 1 && namebuf[len - 1] == '/')
+	len--;
+      namebuf[len++] = '/';
+      namebuf[len] = '\0';
+
+      if (1)
 	{
-	  hstat.st_size = 0;	/* Force 0 size on dir */
-	  /*
-			 * If people could really read standard archives,
-			 * this should be:		(FIXME)
-			header = start_header(f_standard? p: namebuf, &hstat);
-			 * but since they'd interpret LF_DIR records as
-			 * regular files, we'd better put the / on the name.
-			 */
-	  header = start_header (namebuf, &hstat);
+	  /* The "1" above used to be "archive_format != V7_FORMAT", GNU tar
+	     was just not writing directory blocks at all.  Daniel Trinkle
+	     writes: ``All old versions of tar I have ever seen have
+	     correctly archived an empty directory.  The really old ones I
+	     checked included HP-UX 7 and Mt. Xinu More/BSD.  There may be
+	     some subtle reason for the exclusion that I don't know, but the
+	     current behavior is broken.''  I do not know those subtle
+	     reasons either, so until these are reported (anew?), just allow
+	     directory blocks to be written even with old archives.  */
+
+	  current_stat.st_size = 0;	/* force 0 size on dir */
+
+	  /* FIXME: If people could really read standard archives, this
+	     should be:
+
+	     header
+	       = start_header (standard_option ? p : namebuf, &current_stat);
+
+	     but since they'd interpret DIRTYPE blocks as regular
+	     files, we'd better put the / on the name.  */
+
+	  header = start_header (namebuf, &current_stat);
 	  if (header == NULL)
 	    {
-	      critical_error = 1;
-	      goto badfile;	/* eg name too long */
+	      exit_status = TAREXIT_FAILURE;
+	      return;	/* eg name too long */
 	    }
 
-	  if (f_gnudump)
-	    header->header.linkflag = LF_DUMPDIR;
-	  else if (f_standard)
-	    header->header.linkflag = LF_DIR;
+	  if (incremental_option)
+	    header->header.typeflag = GNUTYPE_DUMPDIR;
+	  else /* if (standard_option) */
+	    header->header.typeflag = DIRTYPE;
+
+	  /* If we're gnudumping, we aren't done yet so don't close it.  */
 
-	  /* If we're gnudumping, we aren't done yet so don't close it. */
-	  if (!f_gnudump)
-	    finish_header (header);	/* Done with directory header */
+	  if (!incremental_option)
+	    finish_header (header);	/* done with directory header */
 	}
 
-      if (f_gnudump)
+      if (incremental_option && gnu_list_name->dir_contents)
 	{
 	  int sizeleft;
 	  int totsize;
 	  int bufsize;
-	  union record *start;
+	  union block *start;
 	  int count;
-	  char *buf, *p_buf;
+	  char *buffer, *p_buffer;
 
-	  buf = gnu_list_name->dir_contents;	/* FOO */
+	  buffer = gnu_list_name->dir_contents; /* FOO */
 	  totsize = 0;
-	  for (p_buf = buf; p_buf && *p_buf;)
+	  for (p_buffer = buffer; p_buffer && *p_buffer;)
 	    {
 	      int tmp;
 
-	      tmp = strlen (p_buf) + 1;
+	      tmp = strlen (p_buffer) + 1;
 	      totsize += tmp;
-	      p_buf += tmp;
+	      p_buffer += tmp;
 	    }
 	  totsize++;
 	  to_oct ((long) totsize, 1 + 12, header->header.size);
 	  finish_header (header);
-	  p_buf = buf;
+	  p_buffer = buffer;
 	  sizeleft = totsize;
 	  while (sizeleft > 0)
 	    {
-	      if (f_multivol)
+	      if (multi_volume_option)
 		{
-		  save_name = p;
+		  assign_string (&save_name, p);
 		  save_sizeleft = sizeleft;
 		  save_totsize = totsize;
 		}
-	      start = findrec ();
-	      bufsize = endofrecs ()->charptr - start->charptr;
+	      start = find_next_block ();
+	      bufsize = available_space_after (start);
 	      if (sizeleft < bufsize)
 		{
 		  bufsize = sizeleft;
-		  count = bufsize % RECORDSIZE;
+		  count = bufsize % BLOCKSIZE;
 		  if (count)
-		    bzero (start->charptr + sizeleft, RECORDSIZE - count);
+		    memset (start->buffer + sizeleft, 0,
+			   (size_t) (BLOCKSIZE - count));
 		}
-	      bcopy (p_buf, start->charptr, bufsize);
+	      memcpy (start->buffer, p_buffer, (size_t) bufsize);
 	      sizeleft -= bufsize;
-	      p_buf += bufsize;
-	      userec (start + (bufsize - 1) / RECORDSIZE);
+	      p_buffer += bufsize;
+	      set_next_block_after (start + (bufsize - 1) / BLOCKSIZE);
 	    }
-	  if (f_multivol)
-	    save_name = 0;
-	  if (f_atime_preserve)
+	  if (multi_volume_option)
+	    assign_string (&save_name, NULL);
+	  if (atime_preserve_option)
 	    utime (p, &restore_times);
 	  return;
 	}
 
-      /* Now output all the files in the directory */
-#if 0
-      if (f_dironly)
-	return;			/* Unless the cmdline said not to */
-#endif
-      /*
-		 * See if we are crossing from one file system to another,
-		 * and avoid doing so if the user only wants to dump one file system.
-		 */
-      if (f_local_filesys && !toplevel && curdev != hstat.st_dev)
+      /* See if we are about to recurse into a directory, and avoid doing
+	 so if the user wants that we do not descend into directories.  */
+
+      if (no_recurse_option)
+	return;
+
+      /* See if we are crossing from one file system to another, and
+	 avoid doing so if the user only wants to dump one file system.  */
+
+      if (one_file_system_option && !top_level
+	  && parent_device != current_stat.st_dev)
 	{
-	  if (f_verbose)
-	    msg ("%s: is on a different filesystem; not dumped", p);
+	  if (verbose_option)
+	    WARN ((0, 0, _("%s: On a different filesystem; not dumped"), p));
 	  return;
 	}
 
+      /* Now output all the files in the directory.  */
+
+      errno = 0;		/* FIXME: errno should be read-only */
 
-      errno = 0;
-      dirp = opendir (p);
-      if (!dirp)
+      directory = opendir (p);
+      if (!directory)
 	{
-	  if (errno)
-	    {
-	      msg_perror ("can't open directory %s", p);
-	    }
-	  else
-	    {
-	      msg ("error opening directory %s",
-		   p);
-	    }
+	  ERROR ((0, errno, _("Cannot open directory %s"), p));
 	  return;
 	}
 
-      /* Hack to remove "./" from the front of all the file names */
+      /* Hack to remove "./" from the front of all the file names.  */
+
       if (len == 2 && namebuf[0] == '.' && namebuf[1] == '/')
 	len = 0;
 
-      /* Should speed this up by cd-ing into the dir, FIXME */
-      while (NULL != (d = readdir (dirp)))
+      /* FIXME: Should speed this up by cd-ing into the dir.  */
+
+      while (entry = readdir (directory), entry)
 	{
-	  /* Skip . and .. */
-	  if (is_dot_or_dotdot (d->d_name))
+	  /* Skip `.' and `..'.  */
+
+	  if (is_dot_or_dotdot (entry->d_name))
 	    continue;
 
-	  if (NLENGTH (d) + len >= buflen)
+	  if ((int) NAMLEN (entry) + len >= buflen)
 	    {
-	      buflen = len + NLENGTH (d);
-	      namebuf = ck_realloc (namebuf, buflen + 1);
-	      /* namebuf[len]='\0';
-				msg("file name %s%s too long",
-					namebuf, d->d_name);
-				continue; */
+	      buflen = len + NAMLEN (entry);
+	      namebuf = (char *) xrealloc (namebuf, (size_t) (buflen + 1));
+#if 0
+	      namebuf[len] = '\0';
+	      ERROR ((0, 0, _("File name %s%s too long"),
+		      namebuf, entry->d_name));
+	      continue;
+#endif
 	    }
-	  strcpy (namebuf + len, d->d_name);
-	  if (f_exclude && check_exclude (namebuf))
+	  strcpy (namebuf + len, entry->d_name);
+	  if (exclude_option && check_exclude (namebuf))
 	    continue;
 	  dump_file (namebuf, our_device, 0);
 	}
 
-      closedir (dirp);
+      closedir (directory);
       free (namebuf);
-      if (f_atime_preserve)
+      if (atime_preserve_option)
 	utime (p, &restore_times);
       return;
     }
 
 #ifdef S_ISCHR
-  else if (S_ISCHR (hstat.st_mode))
-    {
-      type = LF_CHR;
-    }
+  else if (S_ISCHR (current_stat.st_mode))
+    type = CHRTYPE;
 #endif
 
 #ifdef S_ISBLK
-  else if (S_ISBLK (hstat.st_mode))
-    {
-      type = LF_BLK;
-    }
+  else if (S_ISBLK (current_stat.st_mode))
+    type = BLKTYPE;
 #endif
 
-  /* Avoid screwy apollo lossage where S_IFIFO == S_IFSOCK */
+  /* Avoid screwy apollo lossage where S_IFIFO == S_IFSOCK.  */
+
 #if (_ISP__M68K == 0) && (_ISP__A88K == 0) && defined(S_ISFIFO)
-  else if (S_ISFIFO (hstat.st_mode))
-    {
-      type = LF_FIFO;
-    }
+  else if (S_ISFIFO (current_stat.st_mode))
+    type = FIFOTYPE;
 #endif
 
 #ifdef S_ISSOCK
-  else if (S_ISSOCK (hstat.st_mode))
-    {
-      type = LF_FIFO;
-    }
+  else if (S_ISSOCK (current_stat.st_mode))
+    type = FIFOTYPE;
 #endif
+
   else
     goto unknown;
 
-  if (!f_standard)
+  if (archive_format == V7_FORMAT)
     goto unknown;
 
-  hstat.st_size = 0;		/* Force 0 size */
-  header = start_header (p, &hstat);
+  current_stat.st_size = 0;	/* force 0 size */
+  header = start_header (p, &current_stat);
   if (header == NULL)
     {
-      critical_error = 1;
-      goto badfile;		/* eg name too long */
+      exit_status = TAREXIT_FAILURE;
+      return;	/* eg name too long */
     }
 
-  header->header.linkflag = type;
+  header->header.typeflag = type;
+
 #if defined(S_IFBLK) || defined(S_IFCHR)
-  if (type != LF_FIFO)
+  if (type != FIFOTYPE)
     {
-      to_oct ((long) major (hstat.st_rdev), 8,
+      to_oct ((long) major (current_stat.st_rdev), 8,
 	      header->header.devmajor);
-      to_oct ((long) minor (hstat.st_rdev), 8,
+      to_oct ((long) minor (current_stat.st_rdev), 8,
 	      header->header.devminor);
     }
 #endif
 
   finish_header (header);
-  if (f_remove_files)
+  if (remove_files_option)
     {
       if (unlink (p) == -1)
-	msg_perror ("cannot remove %s", p);
+	ERROR ((0, errno, _("Cannot remove %s"), p));
     }
   return;
 
 unknown:
-  msg ("%s: Unknown file type; file ignored.", p);
-}
-
-int
-finish_sparse_file (fd, sizeleft, fullsize, name)
-     int fd;
-     long *sizeleft, fullsize;
-     char *name;
-{
-  union record *start;
-  char tempbuf[RECORDSIZE];
-  int bufsize, sparse_ind = 0, count;
-  long pos;
-  long nwritten = 0;
-
-
-  while (*sizeleft > 0)
-    {
-      start = findrec ();
-      bzero (start->charptr, RECORDSIZE);
-      bufsize = sparsearray[sparse_ind].numbytes;
-      if (!bufsize)
-	{			/* we blew it, maybe */
-	  msg ("Wrote %ld of %ld bytes to file %s",
-	       fullsize - *sizeleft, fullsize, name);
-	  break;
-	}
-      pos = lseek (fd, sparsearray[sparse_ind++].offset, 0);
-      /*
-		 * If the number of bytes to be written here exceeds
-		 * the size of the temporary buffer, do it in steps.
-		 */
-      while (bufsize > RECORDSIZE)
-	{
-	  /*			if (amt_read) {
-				count = read(fd, start->charptr+amt_read, RECORDSIZE-amt_read);
-				bufsize -= RECORDSIZE - amt_read;
-				amt_read = 0;
-				userec(start);
-				start = findrec();
-				bzero(start->charptr, RECORDSIZE);
-			}*/
-	  /* store the data */
-	  count = read (fd, start->charptr, RECORDSIZE);
-	  if (count < 0)
-	    {
-	      msg_perror ("read error at byte %ld, reading %d bytes, in file %s",
-			  fullsize - *sizeleft, bufsize, name);
-	      return 1;
-	    }
-	  bufsize -= count;
-	  *sizeleft -= count;
-	  userec (start);
-	  nwritten += RECORDSIZE;	/* XXX */
-	  start = findrec ();
-	  bzero (start->charptr, RECORDSIZE);
-	}
-
-
-      clear_buffer (tempbuf);
-      count = read (fd, tempbuf, bufsize);
-      bcopy (tempbuf, start->charptr, RECORDSIZE);
-      if (count < 0)
-	{
-	  msg_perror ("read error at byte %ld, reading %d bytes, in file %s",
-		      fullsize - *sizeleft, bufsize, name);
-	  return 1;
-	}
-      /*		if (amt_read >= RECORDSIZE) {
-			amt_read = 0;
-			userec(start+(count-1)/RECORDSIZE);
-			if (count != bufsize) {
-				msg("file %s shrunk by %d bytes, padding with zeros.", name, sizeleft);
-				return 1;
-			}
-			start = findrec();
-		} else
-			amt_read += bufsize;*/
-      nwritten += count;	/* XXX */
-      *sizeleft -= count;
-      userec (start);
-
-    }
-  free (sparsearray);
-  /*	printf ("Amount actually written is (I hope) %d.\n", nwritten); */
-  /*	userec(start+(count-1)/RECORDSIZE);*/
-  return 0;
-
-}
-
-void
-init_sparsearray ()
-{
-  register int i;
-
-  sp_array_size = 10;
-  /*
-	 * Make room for our scratch space -- initially is 10 elts long
-	 */
-  sparsearray = (struct sp_array *) ck_malloc (sp_array_size * sizeof (struct sp_array));
-  for (i = 0; i < sp_array_size; i++)
-    {
-      sparsearray[i].offset = 0;
-      sparsearray[i].numbytes = 0;
-    }
-}
-
-
-
-/*
- * Okay, we've got a sparse file on our hands -- now, what we need to do is
- * make a pass through the file and carefully note where any data is, i.e.,
- * we want to find how far into the file each instance of data is, and how
- * many bytes are there.  We store this information in the sparsearray,
- * which will later be translated into header information.  For now, we use
- * the sparsearray as convenient storage.
- *
- * As a side note, this routine is a mess.  If I could have found a cleaner
- * way to do it, I would have.  If anyone wants to find a nicer way to do
- * this, feel free.
- */
-
-/* There is little point in trimming small amounts of null data at the */
-/* head and tail of blocks -- it's ok if we only avoid dumping blocks */
-/* of complete null data */
-int
-deal_with_sparse (name, header, nulls_at_end)
-     char *name;
-     union record *header;
-     int nulls_at_end;
-{
-  long numbytes = 0;
-  long offset = 0;
-  /*	long	save_offset;*/
-  int fd;
-  /*	int	current_size = hstat.st_size;*/
-  int sparse_ind = 0, cc;
-  char buf[RECORDSIZE];
-#if 0
-  int read_last_data = 0;	/* did we just read the last record? */
-#endif
-  int amidst_data = 0;
-
-  header->header.isextended = 0;
-  /*
-	 * Can't open the file -- this problem will be caught later on,
-	 * so just return.
-	 */
-  if ((fd = open (name, O_RDONLY)) < 0)
-    return 0;
-
-  init_sparsearray ();
-  clear_buffer (buf);
-
-  while ((cc = read (fd, buf, sizeof buf)) != 0)
-    {
-
-      if (sparse_ind > sp_array_size - 1)
-	{
-
-	  /*
-		 * realloc the scratch area, since we've run out of room --
-		 */
-	  sparsearray = (struct sp_array *)
-	    ck_realloc (sparsearray,
-		     2 * sp_array_size * (sizeof (struct sp_array)));
-	  sp_array_size *= 2;
-	}
-      if (cc == sizeof buf)
-	{
-	  if (zero_record (buf))
-	    {
-	      if (amidst_data)
-		{
-		  sparsearray[sparse_ind++].numbytes
-		    = numbytes;
-		  amidst_data = 0;
-		}
-	    }
-	  else
-	    {			/* !zero_record(buf) */
-	      if (amidst_data)
-		numbytes += cc;
-	      else
-		{
-		  amidst_data = 1;
-		  numbytes = cc;
-		  sparsearray[sparse_ind].offset
-		    = offset;
-		}
-	    }
-	}
-      else if (cc < sizeof buf)
-	{
-	  /* This has to be the last bit of the file, so this */
-	  /* is somewhat shorter than the above. */
-	  if (!zero_record (buf))
-	    {
-	      if (!amidst_data)
-		{
-		  amidst_data = 1;
-		  numbytes = cc;
-		  sparsearray[sparse_ind].offset
-		    = offset;
-		}
-	      else
-		numbytes += cc;
-	    }
-	}
-      offset += cc;
-      clear_buffer (buf);
-    }
-  if (amidst_data)
-    sparsearray[sparse_ind++].numbytes = numbytes;
-  else
-    {
-      sparsearray[sparse_ind].offset = offset-1;
-      sparsearray[sparse_ind++].numbytes = 1;
-    }
-  close (fd);
-
-  return sparse_ind - 1;
-}
-
-/*
- * Just zeroes out the buffer so we don't confuse ourselves with leftover
- * data.
- */
-void
-clear_buffer (buf)
-     char *buf;
-{
-  register int i;
-
-  for (i = 0; i < RECORDSIZE; i++)
-    buf[i] = '\0';
-}
-
-#if 0				/* I'm leaving this as a monument to Joy Kendall, who wrote it -mib */
-/*
- * JK -
- * This routine takes a character array, and tells where within that array
- * the data can be found.  It skips over any zeros, and sets the first
- * non-zero point in the array to be the "start", and continues until it
- * finds non-data again, which is marked as the "end."  This routine is
- * mainly for 1) seeing how far into a file we must lseek to data, given
- * that we have a sparse file, and 2) determining the "real size" of the
- * file, i.e., the number of bytes in the sparse file that are data, as
- * opposed to the zeros we are trying to skip.
- */
-where_is_data (from, to, buffer)
-     int *from, *to;
-     char *buffer;
-{
-  register int i = 0;
-  register int save_to = *to;
-  int amidst_data = 0;
-
-
-  while (!buffer[i])
-    i++;
-  *from = i;
-
-  if (*from < 16)		/* don't bother */
-    *from = 0;
-  /* keep going to make sure there isn't more real
-	   data in this record */
-  while (i < RECORDSIZE)
-    {
-      if (!buffer[i])
-	{
-	  if (amidst_data)
-	    {
-	      save_to = i;
-	      amidst_data = 0;
-	    }
-	  i++;
-	}
-      else if (buffer[i])
-	{
-	  if (!amidst_data)
-	    amidst_data = 1;
-	  i++;
-	}
-    }
-  if (i == RECORDSIZE)
-    *to = i;
-  else
-    *to = save_to;
-
-}
-
-#endif
-
-/* Note that this routine is only called if zero_record returned true */
-#if 0				/* But we actually don't need it at all. */
-where_is_data (from, to, buffer)
-     int *from, *to;
-     char *buffer;
-{
-  char *fp, *tp;
-
-  for (fp = buffer; !*fp; fp++)
-    ;
-  for (tp = buffer + RECORDSIZE - 1; !*tp; tp--)
-    ;
-  *from = fp - buffer;
-  *to = tp - buffer + 1;
-}
-
-#endif
-
-
-
-/*
- * Takes a recordful of data and basically cruises through it to see if
- * it's made *entirely* of zeros, returning a 0 the instant it finds
- * something that is a non-zero, i.e., useful data.
- */
-int
-zero_record (buffer)
-     char *buffer;
-{
-  register int i;
-
-  for (i = 0; i < RECORDSIZE; i++)
-    if (buffer[i] != '\000')
-      return 0;
-  return 1;
-}
-
-void
-find_new_file_size (filesize, highest_index)
-     int *filesize;
-     int highest_index;
-{
-  register int i;
-
-  *filesize = 0;
-  for (i = 0; sparsearray[i].numbytes && i <= highest_index; i++)
-    *filesize += sparsearray[i].numbytes;
-}
-
-/*
- * Make a header block for the file  name  whose stat info is  st .
- * Return header pointer for success, NULL if the name is too long.
- */
-union record *
-start_header (name, st)
-     char *name;
-     register struct stat *st;
-{
-  register union record *header;
-
-  if (strlen (name) >= NAMSIZ)
-    write_long (name, LF_LONGNAME);
-
-  header = (union record *) findrec ();
-  bzero (header->charptr, sizeof (*header));	/* XXX speed up */
-
-  /*
-	 * Check the file name and put it in the record.
-	 */
-  if (!f_absolute_paths)
-    {
-      static int warned_once = 0;
-#ifdef __MSDOS__
-      if (name[1] == ':')
-	{
-	  name += 2;
-	  if (!warned_once++)
-	    msg ("Removing drive spec from names in the archive");
-	}
-#endif
-      while ('/' == *name)
-	{
-	  name++;		/* Force relative path */
-	  if (!warned_once++)
-	    msg ("Removing leading / from absolute path names in the archive.");
-	}
-    }
-  current_file_name = name;
-  strncpy (header->header.arch_name, name, NAMSIZ);
-  header->header.arch_name[NAMSIZ - 1] = '\0';
-
-  to_oct ((long) (f_oldarch ? (st->st_mode & 07777) : st->st_mode),
-	  8, header->header.mode);
-  to_oct ((long) st->st_uid, 8, header->header.uid);
-  to_oct ((long) st->st_gid, 8, header->header.gid);
-  to_oct ((long) st->st_size, 1 + 12, header->header.size);
-  to_oct ((long) st->st_mtime, 1 + 12, header->header.mtime);
-  /* header->header.linkflag is left as null */
-  if (f_gnudump)
-    {
-      to_oct ((long) st->st_atime, 1 + 12, header->header.atime);
-      to_oct ((long) st->st_ctime, 1 + 12, header->header.ctime);
-    }
-
-#ifndef NONAMES
-  /* Fill in new Unix Standard fields if desired. */
-  if (f_standard)
-    {
-      header->header.linkflag = LF_NORMAL;	/* New default */
-      strcpy (header->header.magic, TMAGIC);	/* Mark as Unix Std */
-      finduname (header->header.uname, st->st_uid);
-      findgname (header->header.gname, st->st_gid);
-    }
-#endif
-  return header;
-}
-
-/*
- * Finish off a filled-in header block and write it out.
- * We also print the file name and/or full info if verbose is on.
- */
-void
-finish_header (header)
-     register union record *header;
-{
-  register int i, sum;
-  register char *p;
-
-  bcopy (CHKBLANKS, header->header.chksum, sizeof (header->header.chksum));
-
-  sum = 0;
-  p = header->charptr;
-  for (i = sizeof (*header); --i >= 0;)
-    {
-      /*
-		 * We can't use unsigned char here because of old compilers,
-		 * e.g. V7.
-		 */
-      sum += 0xFF & *p++;
-    }
-
-  /*
-	 * Fill in the checksum field.  It's formatted differently
-	 * from the other fields:  it has [6] digits, a null, then a
-	 * space -- rather than digits, a space, then a null.
-	 * We use to_oct then write the null in over to_oct's space.
-	 * The final space is already there, from checksumming, and
-	 * to_oct doesn't modify it.
-	 *
-	 * This is a fast way to do:
-	 * (void) sprintf(header->header.chksum, "%6o", sum);
-	 */
-  to_oct ((long) sum, 8, header->header.chksum);
-  header->header.chksum[6] = '\0';	/* Zap the space */
-
-  userec (header);
-
-  if (f_verbose)
-    {
-      extern union record *head;/* Points to current tape header */
-      extern int head_standard;	/* Tape header is in ANSI format */
-
-      /* These globals are parameters to print_header, sigh */
-      head = header;
-      /* hstat is already set up */
-      head_standard = f_standard;
-      print_header ();
-    }
-
-  return;
-}
-
-
-/*
- * Quick and dirty octal conversion.
- * Converts long "value" into a "digs"-digit field at "where",
- * including a trailing space and room for a null.  "digs"==3 means
- * 1 digit, a space, and room for a null.
- *
- * We assume the trailing null is already there and don't fill it in.
- * This fact is used by start_header and finish_header, so don't change it!
- *
- * This should be equivalent to:
- *	(void) sprintf(where, "%*lo ", digs-2, value);
- * except that sprintf fills in the trailing null and we don't.
- */
-void
-to_oct (value, digs, where)
-     register long value;
-     register int digs;
-     register char *where;
-{
-
-  --digs;			/* Trailing null slot is left alone */
-  where[--digs] = ' ';		/* Put in the space, though */
-
-  /* Produce the digits -- at least one */
-  do
-    {
-      where[--digs] = '0' + (char) (value & 7);	/* one octal digit */
-      value >>= 3;
-    }
-  while (digs > 0 && value != 0);
-
-  /* Leading spaces, if necessary */
-  while (digs > 0)
-    where[--digs] = ' ';
-
-}
-
-
-/*
- * Write the EOT record(s).
- * We actually zero at least one record, through the end of the block.
- * Old tar writes garbage after two zeroed records -- and PDtar used to.
- */
-void
-write_eot ()
-{
-  union record *p;
-  int bufsize;
-
-  p = findrec ();
-  if (p)
-    {
-      bufsize = endofrecs ()->charptr - p->charptr;
-      bzero (p->charptr, bufsize);
-      userec (p);
-    }
-}
-
-/* Write a LF_LONGLINK or LF_LONGNAME record. */
-void
-write_long (p, type)
-     char *p;
-     char type;
-{
-  int size = strlen (p) + 1;
-  int bufsize;
-  union record *header;
-  struct stat foo;
-
-
-  bzero (&foo, sizeof foo);
-  foo.st_size = size;
-
-  header = start_header ("././@LongLink", &foo);
-  header->header.linkflag = type;
-  finish_header (header);
-
-  header = findrec ();
-
-  bufsize = endofrecs ()->charptr - header->charptr;
-
-  while (bufsize < size)
-    {
-      bcopy (p, header->charptr, bufsize);
-      p += bufsize;
-      size -= bufsize;
-      userec (header + (bufsize - 1) / RECORDSIZE);
-      header = findrec ();
-      bufsize = endofrecs ()->charptr - header->charptr;
-    }
-  bcopy (p, header->charptr, size);
-  bzero (header->charptr + size, bufsize - size);
-  userec (header + (size - 1) / RECORDSIZE);
+  ERROR ((0, 0, _("%s: Unknown file type; file ignored"), p));
 }
