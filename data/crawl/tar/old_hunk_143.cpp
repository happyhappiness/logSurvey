	}
      if (!zero_block_p (diff_buffer, bytes_read))
	{
 	  report_difference (file->stat_info,
			     _("File fragment at %lu is not a hole"), beg);
	  return false;
	}

