     char *name;
{
  if (name[0] == '\0')
    fatal ("empty string invalid as file name");

  if (name[0] == '~')
    {
