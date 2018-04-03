  no error (not even a warning) for a nonexistent makefile.

* Commands in an invocation of the `shell' function are now run with a
  modified environment like recipes are, so you can use `export' et al
  to set up variables for them.  They used to run with the environment
  that `make' started with.

Version 3.66
