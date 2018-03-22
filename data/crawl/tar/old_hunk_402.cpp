	utime (p, &restore_times);
      return;
    }

  else if (S_ISCHR (current_stat.st_mode))
    type = CHRTYPE;
  else if (S_ISBLK (current_stat.st_mode))
    type = BLKTYPE;
  else if (S_ISFIFO (current_stat.st_mode)
	   || S_ISSOCK (current_stat.st_mode))
    type = FIFOTYPE;
  else
    goto unknown;

  if (archive_format == V7_FORMAT)
    goto unknown;

  current_stat.st_size = 0;	/* force 0 size */
  header = start_header (p, &current_stat);
  if (! header)
    {
      exit_status = TAREXIT_FAILURE;
      return;	/* eg name too long */
    }

  header->header.typeflag = type;

  if (type != FIFOTYPE)
