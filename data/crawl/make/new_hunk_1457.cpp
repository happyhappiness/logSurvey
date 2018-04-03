     struct file *f;
{
  register struct dep *d;
#ifdef VMS
  extern char *cvt_time PARAMS ((unsigned long));
#endif
  putchar ('\n');
  if (!f->is_target)
    puts ("# Not a target:");
