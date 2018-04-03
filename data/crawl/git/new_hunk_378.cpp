---------------------------------------------


Using diff-highlight as a module
--------------------------------

If you want to pre- or post- process the highlighted lines as part of
another perl script, you can use the DiffHighlight module. You can
either "require" it or just cat the module together with your script (to
avoid run-time dependencies).

Your script may set up one or more of the following variables:

  - $DiffHighlight::line_cb - this should point to a function which is
    called whenever DiffHighlight has lines (which may contain
    highlights) to output. The default function prints each line to
    stdout. Note that the function may be called with multiple lines.

  - $DiffHighlight::flush_cb - this should point to a function which
    flushes the output (because DiffHighlight believes it has completed
    processing a logical chunk of input). The default function flushes
    stdout.

The script may then feed lines, one at a time, to DiffHighlight::handle_line().
When lines are done processing, they will be fed to $line_cb. Note that
DiffHighlight may queue up many input lines (to analyze a whole hunk)
before calling $line_cb. After providing all lines, call
DiffHighlight::flush() to flush any unprocessed lines.

If you just want to process stdin, DiffHighlight::highlight_stdin()
is a convenience helper which will loop and flush for you.


Bugs
----

