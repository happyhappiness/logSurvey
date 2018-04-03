    return 1;
  }

  if (--$default_output_stack_level < 0)
  {
    &error ("default output stack has flown under!\n", 1);
  }

  close (STDOUT);
  close (STDERR);

  open (STDOUT, ">&SAVEDOS" . $default_output_stack_level . "out")
        || &error ("ddo: $! duping STDOUT\n", 1);
  open (STDERR, ">&SAVEDOS" . $default_output_stack_level . "err")
        || &error ("ddo: $! duping STDERR\n", 1);

  close ("SAVEDOS" . $default_output_stack_level . "out")
        || &error ("ddo: $! closing SCSDOSout\n", 1);
  close ("SAVEDOS" . $default_output_stack_level . "err")
         || &error ("ddo: $! closing SAVEDOSerr\n", 1);
}

# This runs a command without any debugging info.
