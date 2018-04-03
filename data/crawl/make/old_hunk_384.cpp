
  foreach $file (@_) {
    (open(T, ">> $file") && print(T "\n") && close(T))
	|| &error("Couldn't touch $file: $!\n", 1);
  }
}

