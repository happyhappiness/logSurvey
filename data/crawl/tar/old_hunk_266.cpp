      }
#endif /* not MSDOS */

#ifdef S_ISLNK
    case SYMTYPE:
      {
	char linkbuf[NAME_FIELD_SIZE + 3]; /* FIXME: may be too short.  */

	status = readlink (current_file_name, linkbuf, (sizeof linkbuf) - 1);

	if (status < 0)
	  {
	    if (errno == ENOENT)
	      report_difference (_("No such file or directory"));
	    else
	      {
		WARN ((0, errno, _("Cannot read link %s"), current_file_name));
		report_difference (NULL);
	      }
	    break;
	  }

	linkbuf[status] = '\0';	/* null-terminate it */
	if (strncmp (current_link_name, linkbuf, (size_t) status) != 0)
	  report_difference (_("Symlink differs"));

	break;
      }
#endif /* not S_ISLNK */

#ifdef S_IFCHR
    case CHRTYPE:
      current_stat.st_mode |= S_IFCHR;
      goto check_node;
#endif /* not S_IFCHR */

#ifdef S_IFBLK
      /* If local system doesn't support block devices, use default case.  */

    case BLKTYPE:
      current_stat.st_mode |= S_IFBLK;
      goto check_node;
#endif /* not S_IFBLK */

#ifdef S_ISFIFO
      /* If local system doesn't support FIFOs, use default case.  */

    case FIFOTYPE:
# ifdef S_IFIFO
      current_stat.st_mode |= S_IFIFO;
# endif
      current_stat.st_rdev = 0;	/* FIXME: do we need this? */
      goto check_node;
#endif /* S_ISFIFO */

    check_node:
      /* FIXME: deal with umask.  */

      if (!get_stat_data (&stat_data))
	break;

      if (current_stat.st_rdev != stat_data.st_rdev)
	{
	  report_difference (_("Device numbers changed"));
	  break;
	}

      if (
#ifdef S_IFMT
	  current_stat.st_mode != stat_data.st_mode
#else
	  /* POSIX lossage.  */
	  (current_stat.st_mode & 07777) != (stat_data.st_mode & 07777)
#endif
	  )
	{
	  report_difference (_("Mode or device-type changed"));
	  break;
	}

