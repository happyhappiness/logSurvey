        }
      if (opt.timestamping)
        {
          fputs (_("\
Cannot specify -N if -O is given. See the manual for details.\n\n"), stdout);
          print_usage ();
          exit (1);
        }
    }

src/ChangeLog | 3 ++-
src/main.c    | 1 +
2 files changed, 3 insertions(+), 1 deletion(-)
