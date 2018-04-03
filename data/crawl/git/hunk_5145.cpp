    consistently when command line arguments --verbose (or -v),
    --debug (or -d), and --immediate (or -i) is given.
 
+Do's, don'ts & things to keep in mind
+-------------------------------------
+
+Here's a few examples of things you probably should and shouldn't do
+when writing tests.
+
+Do:
+
+ - Put as much code as possible inside test_expect_success and other
+   assertions.
+
+   Even code that isn't a test per se, but merely some setup code
+   should be inside a test assertion if at all possible. Test scripts
+   should only have trivial code outside of their assertions.
+
+ - Chain your test assertions
+
+   Write test code like this:
+
+	git merge foo &&
+	git push bar &&
+	test ...
+
+   Instead of:
+
+	git merge hla
+	git push gh
+	test ...
+
+   That way all of the commands in your tests will succeed or fail. If
+   you must ignore the return value of something (e.g. the return
+   value of export is unportable) it's best to indicate so explicitly
+   with a semicolon:
+
+	export HLAGH;
+	git merge hla &&
+	git push gh &&
+	test ...
+
+Don't:
+
+ - exit() within a <script> part.
+
+   The harness will catch this as a programming error of the test.
+   Use test_done instead if you need to stop the tests early (see
+   "Skipping tests" below).
+
+ - Break the TAP output
+
+   The raw output from your test might be interpreted by a TAP
+   harness. You usually don't have to worry about that. TAP harnesses
+   will ignore everything they don't know about, but don't step on
+   their toes in these areas:
+
+   - Don't print lines like "$x..$y" where $x and $y are integers.
+
+   - Don't print lines that begin with "ok" or "not ok".
+
+   A TAP harness expect a line that begins with either "ok" and "not
+   ok" to signal a test passed or failed (and our harness already
+   produces such lines), so your script shouldn't emit such lines to
+   their output.
+
+   You can glean some further possible issues from the TAP grammar
+   (see http://search.cpan.org/perldoc?TAP::Parser::Grammar#TAP_Grammar)
+   but the best indication is to just run the tests with prove(1),
+   it'll complain if anything is amiss.
+
+Keep in mind:
+
+ - That what you print to stderr and stdout is usually ignored
+
+   Inside <script> part, the standard output and standard error
+   streams are discarded, and the test harness only reports "ok" or
+   "not ok" to the end user running the tests. Under --verbose, they
+   are shown to help debugging the tests.
+
+
 Skipping tests
 --------------
 