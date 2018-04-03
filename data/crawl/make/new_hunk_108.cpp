  return;
}

static int ctrlYPressed= 0;
/* This is called at main or AST level. It is at AST level for DONTWAITFORCHILD
   and at main level otherwise. In any case it is called when a child process
