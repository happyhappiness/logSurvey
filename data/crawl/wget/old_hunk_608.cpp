  char *env_wgetrc, *user_wgetrc;
  int i;

  printf (_("GNU Wget %s\n\n"), version_string);
#ifdef __VMS
  printf ("GNU Wget %s built on VMS %s %s.\n\n",
   VERSION_STRING, vms_arch(), vms_vers());
