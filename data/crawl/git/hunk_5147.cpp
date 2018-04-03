 	smudge = cat
 ------------------------
 
+For best results, `clean` should not alter its output further if it is
+run twice ("clean->clean" should be equivalent to "clean"), and
+multiple `smudge` commands should not alter `clean`'s output
+("smudge->smudge->clean" should be equivalent to "clean").  See the
+section on merging below.
+
+The "indent" filter is well-behaved in this regard: it will not modify
+input that is already correctly indented.  In this case, the lack of a
+smudge filter means that the clean filter _must_ accept its own output
+without modifying it.
+
 
 Interaction between checkin/checkout attributes
 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
