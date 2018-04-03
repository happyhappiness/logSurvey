
  retval = write_xattr_metadata ("user.xdg.origin.url", escnonprint_uri (origin_url), fp);
  if ((!retval) && referrer_url)
    retval = write_xattr_metadata ("user.xdg.referrer.url", escnonprint_uri (referrer_url), fp);

  return retval;
}
