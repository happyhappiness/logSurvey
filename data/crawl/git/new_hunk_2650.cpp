   ref-filter API that is shared with "git tag" and "git
   for-each-ref".

 * The test for various line-ending conversions has been enhanced.

 * A few test scripts around "git p4" have been improved for
   portability.

 * Many allocations that is manually counted (correctly) that are
   followed by strcpy/sprintf have been replaced with a less error
   prone constructs such as xstrfmt.


Also contains various documentation updates and code clean-ups.

