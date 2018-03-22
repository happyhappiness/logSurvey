
  return true;
}
      
bool
try_new_volume ()
{
  size_t status;
  enum read_header rc;
  union block *block;

  switch (subcommand_option)
    {
