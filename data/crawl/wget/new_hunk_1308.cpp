  if (opt.output_document)
    {
      if (HYPHENP (opt.output_document))
        {
#ifdef WINDOWS
          FILE *result;
          result = freopen (NULL, "wb", stdout);
          if (result == NULL)
            {
              logputs (LOG_NOTQUIET, _("\
WARNING: Can't reopen standard output in binary mode;\n\
         downloaded file may contain inappropriate line endings.\n"));
            }
#endif
          output_stream = stdout;
        }
      else
        {
          struct_fstat st;
tests/ChangeLog                  | 5 +++++
tests/Test-proxied-https-auth.px | 3 ++-
2 files changed, 7 insertions(+), 1 deletion(-)
