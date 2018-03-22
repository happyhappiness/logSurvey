      }
#endif /* not MSDOS */

#ifdef HAVE_READLINK
    case SYMTYPE:
      {
	size_t len = strlen (current_stat_info.link_name);
	char *linkbuf = alloca (len + 1);

	status = readlink (current_stat_info.file_name, linkbuf, len + 1);

	if (status < 0)
	  {
	    if (errno == ENOENT)
	      readlink_warn (current_stat_info.file_name);
	    else
	      readlink_error (current_stat_info.file_name);
	    report_difference (0);
	  }
	else if (status != len
		 || strncmp (current_stat_info.link_name, linkbuf, len) != 0)
	  report_difference (_("Symlink differs"));

	break;
      }
#endif

    case CHRTYPE:
    case BLKTYPE:
    case FIFOTYPE:

      /* FIXME: deal with umask.  */

      if (!get_stat_data (current_stat_info.file_name, &stat_data))
	break;

      if (current_header->header.typeflag == CHRTYPE
	  ? !S_ISCHR (stat_data.st_mode)
	  : current_header->header.typeflag == BLKTYPE
	  ? !S_ISBLK (stat_data.st_mode)
	  : /* current_header->header.typeflag == FIFOTYPE */
	  !S_ISFIFO (stat_data.st_mode))
	{
	  report_difference (_("File type differs"));
	  break;
	}

      if ((current_header->header.typeflag == CHRTYPE
	   || current_header->header.typeflag == BLKTYPE)
	  && current_stat_info.stat.st_rdev != stat_data.st_rdev)
	{
	  report_difference (_("Device number differs"));
	  break;
	}

      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
	{
	  report_difference (_("Mode differs"));
	  break;
	}

