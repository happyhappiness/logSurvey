prompt_for_password (void)
{
  if (opt.user)
    printf (_("Password for user %s: "), quote (opt.user));
  else
    printf (_("Password: "));
  return getpass("");
lib/stdlib.h | 15 +++++++++++++++
1 file changed, 15 insertions(+)
