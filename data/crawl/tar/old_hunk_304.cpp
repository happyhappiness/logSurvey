}

/* Fix the statuses of all directories whose statuses need fixing, and
   which are not ancestors of FILE_NAME.  */
static void
apply_nonancestor_delayed_set_stat (char const *file_name)
{
  size_t file_name_len = strlen (file_name);

  while (delayed_set_stat_head)
    {
      struct delayed_set_stat *data = delayed_set_stat_head;
      if (data->file_name_len < file_name_len
	  && file_name[data->file_name_len]
	  && (ISSLASH (file_name[data->file_name_len])
	      || ISSLASH (file_name[data->file_name_len - 1]))
	  && memcmp (file_name, data->file_name, data->file_name_len) == 0)
	break;
      delayed_set_stat_head = data->next;
      set_stat (data->file_name, &data->stat_info,
		data->invert_permissions, data->permstatus, DIRTYPE);
      free (data);
    }
}
