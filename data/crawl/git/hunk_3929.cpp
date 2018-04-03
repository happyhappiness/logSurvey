    The result is a script that lists topics to be merged in order to
    rebuild 'pu' as the input to Meta/Reintegrate script.  Remove
    later topics that should not be in 'jch' yet.  Add a line that
-   consists of '###' before the name of the first topic in the output
-   that should be in 'jch' but not in 'next' yet.
+   consists of '### match next' before the name of the first topic
+   in the output that should be in 'jch' but not in 'next' yet.
 
  - Now we are ready to start merging topics to 'next'.  For each
    branch whose tip is not merged to 'next', one of three things can
