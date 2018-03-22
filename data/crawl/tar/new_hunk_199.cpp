      va_end (ap);
      fprintf (stdlis, "\n");
    }

  if (exit_status == TAREXIT_SUCCESS)
    exit_status = TAREXIT_DIFFERS;
}

/* Take a buffer returned by read_and_process and do nothing with it.  */
static int
process_noop (size_t size __attribute__ ((unused)),
	      char *data __attribute__ ((unused)))
{
  return 1;
}

static int
process_rawdata (size_t bytes, char *buffer)
{
  size_t status = safe_read (diff_handle, diff_buffer, bytes);

  if (status != bytes)
    {
      if (status == SAFE_READ_ERROR)
	{
	  read_error (current_stat_info.file_name);
	  report_difference (&current_stat_info, NULL);
	}
      else
	{
	  report_difference (&current_stat_info,
			     ngettext ("Could only read %lu of %lu byte",
				       "Could only read %lu of %lu bytes",
				       bytes),
