 * "git add -p" is a short-hand to go directly to the selective patch
   subcommand in the interactive command loop and to exit when done.

 * "git add -i" UI has been colorized.  The interactive prompt
   and menu can be colored by setting color.interactive
   configuration.  The diff output (including the hunk picker)
   are colored with color.diff configuration.

 * "git commit --allow-empty" allows you to create a single-parent
   commit that records the same tree as its parent, overriding the usual
