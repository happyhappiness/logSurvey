    What now> 1
------------

You also could say "s" or "sta" or "status" above as long as the
choice is unique.

The main command loop has 6 subcommands (plus help and quit).

status::

   This shows the change between HEAD and index (i.e. what will be
   committed if you say "git commit"), and between index and
   working tree files (i.e. what you could stage further before
   "git commit" using "git-add") for each path.  A sample output
   looks like this:
+
------------
