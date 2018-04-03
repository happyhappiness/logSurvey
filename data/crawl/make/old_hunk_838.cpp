  return new;
}

/* Rehash FILE to NAME.  This is not as simple as resetting
   the `hname' member, since it must be put in a new hash bucket,
   and possibly merged with an existing file called NAME.  */

void
rehash_file (file, name)
     register struct file *file;
     char *name;
{
  char *oldname = file->hname;
  register unsigned int oldhash;
  register char *n;

  while (file->renamed != 0)
    file = file->renamed;

  /* Find the hash values of the old and new names.  */

  oldhash = 0;
  for (n = oldname; *n != '\0'; ++n)
    HASHI (oldhash, *n);

  file_hash_enter (file, name, oldhash, file->name);
}

/* Rename FILE to NAME.  This is not as simple as resetting
   the `name' member, since it must be put in a new hash bucket,
   and possibly merged with an existing file called NAME.  */

void
rename_file (file, name)
     register struct file *file;
     char *name;
{
  rehash_file(file, name);
  while (file)
    {
      file->name = file->hname;
      file = file->prev;
    }
}

void
file_hash_enter (file, name, oldhash, oldname)
     register struct file *file;
     char *name;
     unsigned int oldhash;
     char *oldname;
{
  unsigned int oldbucket = oldhash % FILE_BUCKETS;
  register unsigned int newhash, newbucket;
  struct file *oldfile;
  register char *n;
  register struct file *f;

  newhash = 0;
  for (n = name; *n != '\0'; ++n)
    HASHI (newhash, *n);
  newbucket = newhash % FILE_BUCKETS;

  /* Look for an existing file under the new name.  */

  for (oldfile = files[newbucket]; oldfile != 0; oldfile = oldfile->next)
    if (strieq (oldfile->hname, name))
      break;

  /* If the old file is the same as the new file, never mind.  */
  if (oldfile == file)
    return;

  if (oldhash != 0 && (newbucket != oldbucket || oldfile != 0))
    {
      /* Remove FILE from its hash bucket.  */

      struct file *lastf = 0;

      for (f = files[oldbucket]; f != file; f = f->next)
	lastf = f;

      if (lastf == 0)
	files[oldbucket] = f->next;
      else
	lastf->next = f->next;
    }

  /* Give FILE its new name.  */

  file->hname = name;
  for (f = file->double_colon; f != 0; f = f->prev)
    f->hname = name;

  if (oldfile == 0)
    {
      /* There is no existing file with the new name.  */

      if (newbucket != oldbucket)
	{
	  /* Put FILE in its new hash bucket.  */
	  file->next = files[newbucket];
	  files[newbucket] = file;
	}
    }
  else
    {
      /* There is an existing file with the new name.
	 We must merge FILE into the existing file.  */

      register struct dep *d;

      if (file->cmds != 0)
	{
	  if (oldfile->cmds == 0)
	    oldfile->cmds = file->cmds;
	  else if (file->cmds != oldfile->cmds)
	    {
	      /* We have two sets of commands.  We will go with the
		 one given in the rule explicitly mentioning this name,
		 but give a message to let the user know what's going on.  */
	      if (oldfile->cmds->fileinfo.filenm != 0)
                error (&file->cmds->fileinfo,
                                _("Commands were specified for \
file `%s' at %s:%lu,"),
                                oldname, oldfile->cmds->fileinfo.filenm,
                                oldfile->cmds->fileinfo.lineno);
	      else
		error (&file->cmds->fileinfo,
				_("Commands for file `%s' were found by \
implicit rule search,"),
				oldname);
	      error (&file->cmds->fileinfo,
			      _("but `%s' is now considered the same file \
as `%s'."),
			      oldname, name);
	      error (&file->cmds->fileinfo,
			      _("Commands for `%s' will be ignored \
in favor of those for `%s'."),
			      name, oldname);
	    }
	}

      /* Merge the dependencies of the two files.  */

      d = oldfile->deps;
      if (d == 0)
	oldfile->deps = file->deps;
      else
	{
	  while (d->next != 0)
	    d = d->next;
	  d->next = file->deps;
	}

      merge_variable_set_lists (&oldfile->variables, file->variables);

      if (oldfile->double_colon && file->is_target && !file->double_colon)
	fatal (NILF, _("can't rename single-colon `%s' to double-colon `%s'"),
	       oldname, name);
      if (!oldfile->double_colon  && file->double_colon)
	{
	  if (oldfile->is_target)
	    fatal (NILF, _("can't rename double-colon `%s' to single-colon `%s'"),
		   oldname, name);
	  else
	    oldfile->double_colon = file->double_colon;
	}

      if (file->last_mtime > oldfile->last_mtime)
	/* %%% Kludge so -W wins on a file that gets vpathized.  */
	oldfile->last_mtime = file->last_mtime;

      oldfile->mtime_before_update = file->mtime_before_update;

#define MERGE(field) oldfile->field |= file->field
      MERGE (precious);
      MERGE (tried_implicit);
      MERGE (updating);
