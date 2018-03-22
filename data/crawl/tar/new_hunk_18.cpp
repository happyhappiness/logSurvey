    }

  offset = OFF_FROM_HEADER (current_header->oldgnu_header.offset);
  if (offset < 0
      || INT_ADD_OVERFLOW (current_stat_info.stat.st_size, offset)
      || stat_data.st_size != current_stat_info.stat.st_size + offset)
    {
      report_difference (&current_stat_info, _("Size differs"));
      skip_member ();
