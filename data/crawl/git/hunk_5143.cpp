 
  - Break the TAP output
 
-   The raw output from your test might be interpreted by a TAP
-   harness. You usually don't have to worry about that. TAP harnesses
-   will ignore everything they don't know about, but don't step on
-   their toes in these areas:
+   The raw output from your test may be interpreted by a TAP harness. TAP
+   harnesses will ignore everything they don't know about, but don't step
+   on their toes in these areas:
 
    - Don't print lines like "$x..$y" where $x and $y are integers.
 
    - Don't print lines that begin with "ok" or "not ok".
 
-   A TAP harness expect a line that begins with either "ok" and "not
+   TAP harnesses expect a line that begins with either "ok" and "not
    ok" to signal a test passed or failed (and our harness already
    produces such lines), so your script shouldn't emit such lines to
    their output.
