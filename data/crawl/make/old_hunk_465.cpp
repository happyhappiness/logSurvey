{
  extern char *ctime ();

  printf (_("Member `%s'%s: %ld bytes at %ld (%ld).\n"),
	  name, truncated ? _(" (name might be truncated)") : "",
	  size, hdrpos, datapos);
  printf (_("  Date %s"), ctime (&date));
