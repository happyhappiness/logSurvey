    buffer = AllocMem (len, MEMF_ANY);

    if (!buffer)
      fatal ("MyExecute: Cannot allocate space for calling a command");

    ptr = buffer;

