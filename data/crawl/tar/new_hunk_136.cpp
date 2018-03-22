
  return true;
}

static bool
read_header0 ()
{
  enum read_header rc = read_header (false);

  if (rc == HEADER_SUCCESS)
    {
      set_next_block_after (current_header);
      return true;
    }
  ERROR ((0, 0, _("This does not look like a tar archive")));
  return false;
}

bool
try_new_volume ()
{
  size_t status;
  union block *header;

  switch (subcommand_option)
    {
