    return 1;
  }

  @OUTSTACK or error("default output stack has flown under!\n", 1);

  close(STDOUT);
  close(STDERR);

  open (STDOUT, '>&', pop @OUTSTACK) or error("ddo: $! duping STDOUT\n", 1);
  open (STDERR, '>&', pop @ERRSTACK) or error("ddo: $! duping STDERR\n", 1);
}

# This runs a command without any debugging info.
