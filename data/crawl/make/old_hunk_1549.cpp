#ifdef TEST

long int
describe_member (desc, name, hdrpos, datapos, size, date, uid, gid, mode)
     int desc;
     char *name;
     long int hdrpos, datapos, size, date;
     int uid, gid, mode;
{
  extern char *ctime ();

  printf ("Member %s: %ld bytes at %ld (%ld).\n", name, size, hdrpos, datapos);
  printf ("  Date %s", ctime (&date));
  printf ("  uid = %d, gid = %d, mode = 0%o.\n", uid, gid, mode);

