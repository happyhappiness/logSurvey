static void
free_child (struct child *child)
{
  output_close (&child->output);

  if (!jobserver_tokens)
    fatal (NILF, "INTERNAL: Freeing child %p (%s) but no tokens left!\n",
