 2000-03-27  Paul D. Smith  <psmith@gnu.org>
 
+	* scripts/features/statipattrules: Test that static pattern rules
+	whose prerequisite patterns resolve to empty strings throw an
+	error (instead of dumping core).  Fixes PR/1670.
+
 	* scripts/features/reinvoke: Make more robust by touching "b"
 	first, to ensure it's not newer than "a".
 	Reported by Marco Franzen <Marco.Franzen@Thyron.com>.
