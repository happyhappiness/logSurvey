       unrecoverably absent.  */

    static time_t now;
#ifdef VMS
    /* Handle vms 64bit to 32bit time hack introduced in vms_stat() ... */
    static unsigned long vms_now[2]; /* assumes 32 bit long ! */
    static int vms_now_set = 0;

    if (!vms_now_set)
      {
	sys$gettim(vms_now);
	now = ((vms_now[0]>>24) & 0xff) + ((vms_now[1]<<8) & 0xffffff00);
	vms_now_set = 1;
      }
#endif
    if (mtime > now && ! file->updated)
      {
	/* This file's time appears to be in the future.
	   Update our concept of the present, and compare again.  */
#ifndef VMS
	extern time_t time ();
	if (mtime > time (&now))
#else
	if ((mtime != -1) && (mtime > now))
#endif
	  {
	    error ("*** File `%s' has modification time in the future",
		   file->name);
