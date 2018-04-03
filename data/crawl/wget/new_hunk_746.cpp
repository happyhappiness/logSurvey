         token on the next line. */
      if (remaining_chars <= strlen (token)) 
        {
          printf ("\n%*c", leading_spaces, ' ');
          remaining_chars = line_length - leading_spaces;
        }
      printf ("%s ", token);
doc/ChangeLog     | 8 ++++++++
doc/sample.wgetrc | 2 +-
doc/wget.texi     | 5 ++---
src/ChangeLog     | 4 ++++
src/init.c        | 2 ++
5 files changed, 17 insertions(+), 4 deletions(-)
