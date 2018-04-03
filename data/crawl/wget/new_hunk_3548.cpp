  if (res < -1)
    res = -1;
  if (opt.verbose)
    progress_finish (progress);
  return res;
}

/* Return a printed representation of the download rate, as
   appropriate for the speed.  Appropriate means that if rate is
   greater than 1K/s, kilobytes are used, and if rate is greater than
   1MB/s, megabytes are used.

   If PAD is non-zero, strings will be padded to the width of 7
   characters (xxxx.xx).  */
