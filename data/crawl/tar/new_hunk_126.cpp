  apply_nonancestor_delayed_set_stat ("", 1);
}

bool
rename_directory (char *src, char *dst)
{
  if (rename (src, dst))
    {
      int e = errno;

      switch (e)
	{
	case ENOENT:
	  if (make_directories (dst))
	    {
	      if (rename (src, dst) == 0)
		return true;
	      e = errno;
	    }
	  break;
		    
	case EXDEV:
	  /* FIXME: Fall back to recursive copying */
	  
	default:
	  break;
	}

      ERROR ((0, e, _("Cannot rename %s to %s"),
	      quote_n (0, src),
	      quote_n (1, dst)));
      return false;
    }
  return true;
}
      
void
fatal_exit (void)
{
