{
  return ar_name_equal (name, mem, truncated) ? date : 0;
}

/* Set the archive-member NAME's modtime to now.  */

int
ar_touch (name)
     char *name;
