    set_stat (file_name, &current_stat_info.stat, NULL, 0,
	      ARCHIVED_PERMSTATUS, typeflag);
  else
    {
      mkfifo_error (file_name);
      if (backup_option)
	undo_last_backup ();
    }
}  
#endif

/* Extract a file from the archive.  */
void
extract_archive (void)
{
  char typeflag;
  char *file_name;

  set_next_block_after (current_header);
  decode_header (current_header, &current_stat_info, &current_format, 1);

  if (interactive_option && !confirm ("extract", current_stat_info.file_name))
    {
      skip_member ();
      return;
    }

  /* Print the block from current_header and current_stat.  */

  if (verbose_option)
    print_header (&current_stat_info, -1);

  file_name = safer_name_suffix (current_stat_info.file_name, false);
  if (strip_name_components)
    {
      size_t prefix_len = stripped_prefix_len (file_name, strip_name_components);
      if (prefix_len == (size_t) -1)
	{
	  skip_member ();
	  return;
	}
      file_name += prefix_len;
    }

  apply_nonancestor_delayed_set_stat (file_name, 0);

  /* Take a safety backup of a previously existing file.  */

  if (backup_option && !to_stdout_option)
    if (!maybe_backup_file (file_name, 0))
      {
	int e = errno;
	ERROR ((0, e, _("%s: Was unable to backup this file"),
		quotearg_colon (file_name)));
	skip_member ();
	return;
      }

  /* Extract the archive entry according to its type.  */

  /* KLUDGE */
  typeflag = sparse_member_p (&current_stat_info) ?
                  GNUTYPE_SPARSE : current_header->header.typeflag;

  switch (typeflag)
    {
    case GNUTYPE_SPARSE: /* FIXME: Shouldn't we call extract_file at once? */
    case AREGTYPE:
    case REGTYPE:
    case CONTTYPE:

      /* Appears to be a file.  But BSD tar uses the convention that a slash
	 suffix means a directory.  */

      if (current_stat_info.had_trailing_slash)
	extract_dir (file_name, typeflag);
      else
	extract_file (file_name, typeflag);
      break;

    case SYMTYPE:
      extract_symlink (file_name);
      break;
      
    case LNKTYPE:
      extract_link (file_name);
      break;

#if S_IFCHR
    case CHRTYPE:
      current_stat_info.stat.st_mode |= S_IFCHR;
      extract_node (file_name, typeflag);
      break;
#endif

#if S_IFBLK
    case BLKTYPE:
      current_stat_info.stat.st_mode |= S_IFBLK;
      extract_node (file_name, typeflag);
      break;
#endif

#if HAVE_MKFIFO || defined mkfifo
    case FIFOTYPE:
      extract_fifo (file_name, typeflag);
      break;
#endif

    case DIRTYPE:
    case GNUTYPE_DUMPDIR:
      extract_dir (file_name, typeflag);
      break;

    case GNUTYPE_VOLHDR:
      if (verbose_option)
	fprintf (stdlis, _("Reading %s\n"), quote (current_stat_info.file_name));
      break;

    case GNUTYPE_NAMES:
      extract_mangle ();
      break;

    case GNUTYPE_MULTIVOL:
      ERROR ((0, 0,
	      _("%s: Cannot extract -- file is continued from another volume"),
	      quotearg_colon (current_stat_info.file_name)));
      skip_member ();
      if (backup_option)
	undo_last_backup ();
      break;

    case GNUTYPE_LONGNAME:
    case GNUTYPE_LONGLINK:
      ERROR ((0, 0, _("Unexpected long name header")));
      skip_member ();
      if (backup_option)
	undo_last_backup ();
      break;

    default:
      WARN ((0, 0,
	     _("%s: Unknown file type '%c', extracted as normal file"),
	     quotearg_colon (file_name), typeflag));
      extract_file (file_name, typeflag);
    }
}

/* Extract the symbolic links whose final extraction were delayed.  */
