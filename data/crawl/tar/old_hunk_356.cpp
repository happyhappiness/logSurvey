  return did_something;		/* tell them to retry if we made one */
}

/*--------------------------------------------------------------------.
| Unlink the destination, if we are supposed to do so.		      |
| Return zero if extraction should not proceed.			      |
`--------------------------------------------------------------------*/

static int
unlink_destination (char const *file_name)
{
  if (unlink_first_option
      && !remove_any_file (file_name, recursive_unlink_option)
      && errno != ENOENT)
    {
      ERROR ((0, errno, _("Cannot remove %s"), file_name));
      return 0;
    }

