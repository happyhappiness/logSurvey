    buffer = AllocMem (len, MEMF_ANY);

    if (!buffer)
      fatal (NILF, "MyExecute: Cannot allocate space for calling a command");

    ptr = buffer;

