  return;

unknown:
  WARN ((0, 0, _("%s: Unknown file type; file ignored"),
	 quotearg_colon (p)));
  if (! ignore_failed_read_option)
    exit_status = TAREXIT_FAILURE;
}
