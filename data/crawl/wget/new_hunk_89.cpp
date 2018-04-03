  return last_retr_err;
}

/* Append the suffix ".badhash" to the file NAME, except without
   overwriting an existing file with that name and suffix.  */
void
badhash_suffix (char *name)
{
  char *bhash, *uname;

  bhash = concat_strings (name, ".badhash", (char *)0);
  uname = unique_name (bhash, false);

  logprintf (LOG_VERBOSE, _("Renaming ‘%s’ to ‘%s’.\n"), name, uname);

  if (link (name, uname))
    logprintf (LOG_NOTQUIET, "link: %s\n", strerror (errno));
  else if (unlink (name))
    logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));

  xfree (bhash);
  xfree (uname);
}

/* Append the suffix ".badhash" to the file NAME, except without
   overwriting an existing file with that name and suffix.

   Remove the file NAME if the option --delete-after is specified, or
   if the option --keep-badhash isn't set.  */
void
badhash_or_remove (char *name)
{
  if (opt.delete_after || !opt.keep_badhash)
    {
      logprintf (LOG_VERBOSE, _("Removing %s.\n"), quote (name));
      if (unlink (name))
        logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
    }
  else
    {
      badhash_suffix(name);
    }
}

int metalink_res_cmp (const void* v1, const void* v2)
{
  const metalink_resource_t *res1 = *(metalink_resource_t **) v1,
