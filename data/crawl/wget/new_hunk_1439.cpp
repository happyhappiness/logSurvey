    {
      logprintf (LOG_NOTQUIET, _("\
%s: certificate common name %s doesn't match requested host name %s.\n"),
                 severity, quote (common_name), quote (host));
      success = false;
    }

  if (success)
    DEBUGP (("X509 certificate successfully verified and matches host %s\n",
             quotearg_style (escape_quoting_style, host)));
  X509_free (cert);

 no_cert:
  if (opt.check_cert && !success)
    logprintf (LOG_NOTQUIET, _("\
To connect to %s insecurely, use `--no-check-certificate'.\n"),
               quotearg_style (escape_quoting_style, host));

  /* Allow --no-check-cert to disable certificate checking. */
  return opt.check_cert ? success : true;
ChangeLog               |  21 ++
GNUmakefile             |  60 ++++--
NEWS                    |   2 +
doc/ChangeLog           |   5 +
doc/wget.texi           |   6 +-
lib/Makefile.am         | 159 ++++++++++++++-
lib/getdelim.c          | 130 ++++++++++++
lib/getline.c           |  29 +++
lib/getopt.c            |   6 +-
lib/getpass.c           | 231 +++++++++++++++++++++
lib/getpass.h           |  31 +++
lib/realloc.c           |  87 ++++++++
lib/stdio.h             | 411 +++++++++++++++++++++++++++++++++++++
lib/stdio.in.h          | 382 +++++++++++++++++++++++++++++++++++
lib/stdlib.h            | 254 +++++++++++++++++++++++
lib/stdlib.in.h         | 225 +++++++++++++++++++++
lib/unistd.in.h         |  27 ++-
m4/eoverflow.m4         |  70 +++++++
m4/extensions.m4        |  82 ++++++++
m4/getdelim.m4          |  34 ++++
m4/getline.m4           |  81 ++++++++
m4/getpass.m4           |  47 +++++
m4/gnulib-cache.m4      |   6 +-
m4/gnulib-common.m4     |  23 ++-
m4/gnulib-comp.m4       | 124 +++++++++++-
m4/include_next.m4      |   9 +-
m4/malloc.m4            |  41 ++++
m4/realloc.m4           |  23 +++
m4/stdio_h.m4           |  85 ++++++++
m4/stdlib_h.m4          |  45 +++++
m4/unistd_h.m4          |   7 +-
md5/Makefile.am         |   2 +-
md5/m4/gnulib-cache.m4  |   2 +-
md5/m4/gnulib-common.m4 |  23 ++-
md5/m4/gnulib-comp.m4   |  83 +++++++-
md5/m4/include_next.m4  |   9 +-
md5/m4/md5.m4           |   5 +-
md5/m4/stdint.m4        |  16 +-
md5/md5.c               |  30 +--
md5/md5.h               |  12 +-
md5/stdint.h            | 523 ++++++++++++++++++++++++++++++++++++++++++++++++
md5/stdint.in.h         |  10 +-
md5/wchar.in.h          |  11 +-
src/ChangeLog           |  15 ++
src/init.c              |   1 +
src/main.c              |  24 +++
src/options.h           |   1 +
src/sysdep.h            |   4 +-
48 files changed, 3417 insertions(+), 97 deletions(-)
create mode 100644 lib/getdelim.c
create mode 100644 lib/getline.c
create mode 100644 lib/getpass.c
create mode 100644 lib/getpass.h
create mode 100644 lib/realloc.c
create mode 100644 lib/stdio.h
create mode 100644 lib/stdio.in.h
create mode 100644 lib/stdlib.h
create mode 100644 lib/stdlib.in.h
create mode 100644 m4/eoverflow.m4
create mode 100644 m4/extensions.m4
create mode 100644 m4/getdelim.m4
create mode 100644 m4/getline.m4
create mode 100644 m4/getpass.m4
create mode 100644 m4/malloc.m4
create mode 100644 m4/realloc.m4
create mode 100644 m4/stdio_h.m4
create mode 100644 m4/stdlib_h.m4
create mode 100644 md5/stdint.h
