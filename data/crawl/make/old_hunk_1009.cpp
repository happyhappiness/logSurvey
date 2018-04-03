  return 1;
}

sub touch
{
  local (@filenames) = @_;
  local ($now) = time;
  local ($file);

  foreach $file (@filenames)
  {
    utime ($now, $now, $file)
          || (open (TOUCHFD, ">> $file") && close (TOUCHFD))
               || &error ("Couldn't touch $file: $!\n", 1);
  }
  return 1;
}

# open a file, write some stuff to it, and close it.
