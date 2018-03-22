+2004-07-09  Paul Eggert  <eggert@cs.ucla.edu>
+
+	* src/extract.c (extract_archive): Do not report an error
+	when hard-linking X to X when X exists.  Problem reported by
+	Toby Peterson.
+
 2004-06-29  Sergey Poznyakoff  <gray@Mirddin.farlep.net>
 
 	* NEWS: Updated
