
sub touch
{
  local (@filenames) = @_;
  local ($file);

  foreach $file (@filenames) {
    (open(T, ">> $file") && print(T "\n") && close(T))
	|| &error("Couldn't touch $file: $!\n", 1);
  }
}

# open a file, write some stuff to it, and close it.

sub create_file
