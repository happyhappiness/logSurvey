        }
      if (opt.timestamping)
        {
          logprintf (LOG_NOTQUIET, "%s", _("\
WARNING: timestamping does nothing in combination with -O. See the manual\n\
for details.\n\n"));
        }
    }

src/ChangeLog | 3 ++-
src/main.c    | 1 +
2 files changed, 3 insertions(+), 1 deletion(-)
