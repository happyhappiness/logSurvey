  if (opt.output_document)
    {
      if (HYPHENP (opt.output_document))
        output_stream = stdout;
      else
        {
          struct_fstat st;
tests/ChangeLog                  | 5 +++++
tests/Test-proxied-https-auth.px | 3 ++-
2 files changed, 7 insertions(+), 1 deletion(-)
