static void
free_child (struct child *child)
{
  if (!jobserver_tokens)
    fatal (NILF, "INTERNAL: Freeing child %p (%s) but no tokens left!\n",
           child, child->file->name);
