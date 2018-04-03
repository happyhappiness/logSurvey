  char               *p;
  downloaded_file_t  downloaded_file_return;

  {
    /* First we do a "dry run": go through the list L and see whether
       any URL needs to be converted in the first place.  If not, just
