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
