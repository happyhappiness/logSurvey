    return 1;
  }

  open ("SAVEDOS" . $default_output_stack_level . "out", ">&STDOUT")
        || &error ("ado: $! duping STDOUT\n", 1);
  open ("SAVEDOS" . $default_output_stack_level . "err", ">&STDERR")
        || &error ("ado: $! duping STDERR\n", 1);

  open (STDOUT, "> " . $filename)
        || &error ("ado: $filename: $!\n", 1);
  open (STDERR, ">&STDOUT")
        || &error ("ado: $filename: $!\n", 1);

  $default_output_stack_level++;
}

# close the current stdout/stderr, and restore the previous ones from
