 msgstr ""
 "\n"
 "ΤΕΡΜΑΤΙΣΜΟΣ  --%s--\n"
-"Κατέβηκαν: %s bytes σε %d αρχεία\n"
-
-#
-#: src/main.c:821
-#, c-format
-msgid "Download quota (%s bytes) EXCEEDED!\n"
-msgstr ""
-"Το όριο χώρου στο δίσκο για αρχεία από κατέβασμα (%s bytes) έχει "
-"ΞΕΠΕΡΑΣΤΕΪ!\n"
+"Μεταφορτώθηκαν: %s byte σε %d αρχεία\n"
 
-#
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
 #: src/main.c:851
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s λήφθηκε, ανακατεύθυνση εξόδου στο `%%s'.\n"
-
-#
-#: src/mswindows.c:123
 #, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"CTRL+Break πατήθηκε, ανακατεύθυνση εξόδου στο `%s'.\n"
-"Η εκτέλεση συνεχίζεται στο παρασκήνιο.\n"
-"Μπορείτε να διακόψετε το Wget πατώντας CTRL+ALT+DELETE.\n"
+msgid "Download quota (%s bytes) EXCEEDED!\n"
+msgstr "Το όριο χώρου στο δίσκο για αρχεία από μεταφορτώσεις (%s bytes) έχει ΞΕΠΕΡΑΣΤΕΪ!\n"
 
-#
-#. parent, no error
-#: src/mswindows.c:140 src/utils.c:451
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
 msgstr "Εκτέλεση στο παρασκήνιο.\n"
 
-#
-#: src/mswindows.c:142 src/utils.c:453
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Η έξοδος θα γραφτεί στο `%s'.\n"
 
-#
-#: src/mswindows.c:232
+#: src/mswindows.c:202
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "Εκκίνηση του WinHelp %s\n"
 
-#
-#: src/mswindows.c:259 src/mswindows.c:267
+#: src/mswindows.c:229 src/mswindows.c:236
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Αδυναμία εύρεσης έγκυρου οδηγού δικτύου.\n"
 
-#
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr ""
-"%s: %s:%d: προειδοποίηση: το τμήμα \"%s\" εμφανίζεται πριν από τα ονόματα "
-"των μηχανημάτων\n"
+msgstr "%s: %s:%d: προειδοποίηση: το τμήμα \"%s\" εμφανίζεται πριν από τα ονόματα των μηχανημάτων\n"
 
-#
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: άγνωστος τελεσταίος \"%s\"\n"
 
-#
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Χρήση: %s NETRC [ΟΝΟΜΑ ΜΗΧΑΝΗΜΑΤΟΣ]\n"
 
-#
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: αδυναμία πρόσβασης στο %s: %s\n"
 
-#
-#: src/recur.c:510
-#, c-format
-msgid "Removing %s since it should be rejected.\n"
-msgstr "Διαγραφή του %s αφού θα πρέπει να απορριφθεί.\n"
-
-#
-#: src/recur.c:684
-msgid "Loading robots.txt; please ignore errors.\n"
-msgstr ""
-"Ανάγνωση του robots.txt; παρακαλώ αγνοείστε τυχόν μυνήματα σφαλμάτων.\n"
-
-#
-#: src/retr.c:229
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:224
 #, c-format
 msgid ""
 "\n"
-"          [ skipping %dK ]"
+"%*s[ skipping %dK ]"
 msgstr ""
 "\n"
-"          [ παράκαμψη %dK ]"
+"%*s[ παράκαμψη %dK ]"
 
-#
-#: src/retr.c:421
+#: src/progress.c:391
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Μη έγκυρη ρύθμιση στυλ τελείας `%s'· παραμένει χωρίς αλλαγή.\n"
+
+#: src/recur.c:350
+#, c-format
+msgid "Removing %s since it should be rejected.\n"
+msgstr "Διαγραφή του %s αφού θα έπρεπε να απορριφθεί.\n"
+
+#: src/recur.c:935
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Μετατράπηκαν %d αρχεία σε %.2f δευτερόλεπτα.\n"
+
+#: src/res.c:540
+msgid "Loading robots.txt; please ignore errors.\n"
+msgstr "Ανάγνωση του robots.txt; παρακαλώ αγνοείστε τυχόν μηνύματα σφαλμάτων.\n"
+
+#: src/retr.c:363
 msgid "Could not find proxy host.\n"
-msgstr "Αδυναμία εύρεσης εξυπηρετητή proxy.\n"
+msgstr "Αδυναμία εύρεσης διαμεσολαβητή.\n"
 
-#
-#: src/retr.c:435
+#: src/retr.c:375
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: Πρέπει να είναι HTTP.\n"
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Σφάλμα στην ανάλυση του URL του διαμεσολαβητή %s: %s.\n"
 
-#
-#: src/retr.c:529
-#, fuzzy, c-format
+#: src/retr.c:384
+#, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Σφάλμα στο URL διαμεσολαβητή %s: Πρέπει να είναι HTTP.\n"
+
+#: src/retr.c:476
+#, c-format
+msgid "%d redirections exceeded.\n"
+msgstr "Υπέρβαση %d επανακατευθύνσεων.\n"
+
+#: src/retr.c:491
+#, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Ανακατεύθυνση στον εαυτό του.\n"
+msgstr "%s: Ανιχνεύτηκε κυκλική επανακατεύθυνση.\n"
 
-#
-#: src/retr.c:623
+#: src/retr.c:608
 msgid ""
 "Giving up.\n"
 "\n"
