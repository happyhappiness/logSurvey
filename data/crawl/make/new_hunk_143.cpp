    buffer = AllocMem (len, MEMF_ANY);

    if (!buffer)
      O (fatal, NILF, "MyExecute: Cannot allocate space for calling a command\n");

    ptr = buffer;

