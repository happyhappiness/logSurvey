}

void
seek_error (char const *name)
{
  call_arg_error ("seek", name);
}

void
seek_error_details (char const *name, off_t offset)
{
  char buf[UINTMAX_STRSIZE_BOUND];
  int e = errno;
  ERROR ((0, e, _("%s: Cannot seek to %s"),
	  quotearg_colon (name),
	  STRINGIFY_BIGINT (offset, buf)));
}

void
seek_warn (char const *name)
{
  call_arg_warn ("seek", name);
}

void
seek_warn_details (char const *name, off_t offset)
{
  char buf[UINTMAX_STRSIZE_BOUND];
  int e = errno;
  WARN ((0, e, _("%s: Warning: Cannot seek to %s"),
	 quotearg_colon (name),
	 STRINGIFY_BIGINT (offset, buf)));
}

void
seek_diag_details (char const *name, off_t offset)
{
  if (ignore_failed_read_option)
