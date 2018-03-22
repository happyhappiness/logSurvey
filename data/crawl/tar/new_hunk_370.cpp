    default:
      WARN ((0, 0,
	     _("Unknown file type '%c' for %s, extracted as normal file"),
	     typeflag, quote (CURRENT_FILE_NAME)));
      goto again_file;
    }

#undef CURRENT_FILE_NAME
}

/* Fix the statuses of all directories that are not ancestors of FILE_NAME.  */
void
apply_delayed_set_stat (char const *file_name)
{
  size_t file_name_len = strlen (file_name);

  while (delayed_set_stat_head)
    {
      struct delayed_set_stat *data = delayed_set_stat_head;
      delayed_set_stat_head = data->next;
      if (data->file_name_len < file_name_len
	  && file_name[data->file_name_len] == '/'
	  && memcmp (file_name, data->file_name, data->file_name_len) == 0)
	break;
      set_stat (data->file_name, &data->stat_info,
		data->invert_permissions, data->permstatus, DIRTYPE);
      free (data);
    }
}

void
fatal_exit (void)
{
  apply_delayed_set_stat ("");
  error (TAREXIT_FAILURE, 0, _("Error is not recoverable: exiting now"));
  abort ();
}
