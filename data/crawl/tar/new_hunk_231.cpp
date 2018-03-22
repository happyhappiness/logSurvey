/* Handle write errors on the archive.  Write errors are always fatal.
   Hitting the end of a volume does not cause a write error unless the
   write was the first record of the volume.  */
void
archive_write_error (ssize_t status)
{
  /* It might be useful to know how much was written before the error
