    return 1;
  }

  my $dup = undef;
  open($dup, '>&', STDOUT) or error("ado: $! duping STDOUT\n", 1);
  push @OUTSTACK, $dup;

  open($dup, '>&', STDERR) or error("ado: $! duping STDERR\n", 1);
  push @ERRSTACK, $dup;

  open(STDOUT, '>', $filename) or error("ado: $filename: $!\n", 1);
  open(STDERR, ">&STDOUT") or error("ado: $filename: $!\n", 1);
}

# close the current stdout/stderr, and restore the previous ones from
