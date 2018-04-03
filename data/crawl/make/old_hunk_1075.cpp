{
  extern char *ctime ();

  printf ("Member `%s'%s: %ld bytes at %ld (%ld).\n",
	  name, truncated ? " (name might be truncated)" : "",
	  size, hdrpos, datapos);
  printf ("  Date %s", ctime (&date));
  printf ("  uid = %d, gid = %d, mode = 0%o.\n", uid, gid, mode);

  return 0;
}
