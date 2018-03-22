}

void
exec_fatal (char const *name)
{
  call_arg_fatal ("exec", name);
}

void
link_error (char const *target, char const *source)
{
  int e = errno;
  ERROR ((0, e, _("%s: Cannot hard link to %s"),
	  quotearg_colon (source), quote_n (1, target)));
}

void
mkdir_error (char const *name)
{
  call_arg_error ("mkdir", name);
}

void
mkfifo_error (char const *name)
{
  call_arg_error ("mkfifo", name);
}

void
mknod_error (char const *name)
{
  call_arg_error ("mknod", name);
}

void
open_error (char const *name)
{
  call_arg_error ("open", name);
}

void
open_fatal (char const *name)
{
  call_arg_fatal ("open", name);
}

void
open_warn (char const *name)
{
  call_arg_warn ("open", name);
}

void
open_diag (char const *name)
{
  if (ignore_failed_read_option)
