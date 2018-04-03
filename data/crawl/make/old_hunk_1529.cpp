
/* Print the data base of files.  */

void
print_file_data_base ()
{
  register unsigned int i, nfiles, per_bucket;
  register struct file *file;
  register struct dep *d;

  puts ("\n# Files");

