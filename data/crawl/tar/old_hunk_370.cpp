    default:
      WARN ((0, 0,
	     _("Unknown file type '%c' for %s, extracted as normal file"),
	     typeflag, CURRENT_FILE_NAME));
      goto again_file;
    }

#undef CURRENT_FILE_NAME
}

/*----------------------------------------------------------------.
| Set back the utime and mode for all the extracted directories.  |
`----------------------------------------------------------------*/

void
apply_delayed_set_stat (void)
{
  struct delayed_set_stat *data;

  while (delayed_set_stat_head)
    {
      data = delayed_set_stat_head;
      delayed_set_stat_head = delayed_set_stat_head->next;
      set_stat (data->file_name, &data->stat_info, 0);
      free (data->file_name);
      free (data);
    }
}
