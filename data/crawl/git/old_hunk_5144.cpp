
Keep in mind:

 - That what you print to stderr and stdout is usually ignored

   Inside <script> part, the standard output and standard error
   streams are discarded, and the test harness only reports "ok" or
   "not ok" to the end user running the tests. Under --verbose, they
   are shown to help debugging the tests.