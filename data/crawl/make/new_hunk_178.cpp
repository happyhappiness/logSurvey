  output_close (&child->output);

  if (!jobserver_tokens)
    ONS (fatal, NILF, "INTERNAL: Freeing child %p (%s) but no tokens left!\n",
         child, child->file->name);

  /* If we're using the jobserver and this child is not the only outstanding
     job, put a token back into the pipe for it.  */
