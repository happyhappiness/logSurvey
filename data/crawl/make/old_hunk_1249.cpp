ar_touch (name)
     char *name;
{
  error ("touch archive member is not available on VMS");
  return -1;
}
#else