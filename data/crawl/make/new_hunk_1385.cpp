     struct file *f;
{
  register struct dep *d;

  putchar ('\n');
  if (!f->is_target)
    puts ("# Not a target:");
