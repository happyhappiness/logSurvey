  if (child->deleted)
    return;

  /* Delete the target file if it changed.  */
  delete_target (child->file, (char *) 0);

  /* Also remove any non-precious targets listed in the `also_make' member.  */
  for (d = child->file->also_make; d != 0; d = d->next)
    delete_target (d->file, child->file->name);

  child->deleted = 1;
}
