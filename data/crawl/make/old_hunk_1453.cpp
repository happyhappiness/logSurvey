  if (memname_p != 0)
    *memname_p = savestring (p + 1, end - (p + 1));
}  

static long int ar_member_date_1 ();

/* Return the modtime of NAME.  */

