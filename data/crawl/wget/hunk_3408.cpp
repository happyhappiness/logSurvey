 "Προσπάθεια ξανά.\n"
 "\n"
 
-#
-#: src/url.c:1332
+#: src/url.c:1875
 #, c-format
 msgid "Converting %s... "
 msgstr "Μετατροπή του %s... "
 
-#: src/url.c:1345
+#: src/url.c:1888
 msgid "nothing to do.\n"
-msgstr ""
+msgstr "τίποτα να κάνω.\n"
 
-#
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1896 src/url.c:1920
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "Αδυναμία μετατροπής τοποθεσίας στο %s: %s\n"
+msgstr "Αδυναμία μετατροπής συνδέσμων στο %s: %s\n"
 
-#
-#: src/url.c:1368
-#, fuzzy, c-format
+#: src/url.c:1911
+#, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "Αποτυχία διαγραφής συμβολικού συνδέσμου `%s': %s\n"
+msgstr "Αποτυχία διαγραφής του `%s': %s\n"
 
-#
-#: src/url.c:1558
-#, fuzzy, c-format
+#: src/url.c:2117
+#, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Αδυναμία μετατροπής τοποθεσίας στο %s: %s\n"
+msgstr "Αδύνατη η λήψη αντιγράγου ασφαλείας του %s ως %s: %s\n"
 
-#
-#: src/utils.c:94
+#: src/utils.c:90
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Δεν υπάρχει αρκετή μνήμη.\n"
 
-#
-#: src/utils.c:386
-msgid "Unknown/unsupported protocol"
-msgstr "¶γνωστο/μη υποστηριζόμενο πρωτόκολλο"
-
-#
-#: src/utils.c:389
-msgid "Invalid port specification"
-msgstr "Μη έγκυρη ρύθμιση θύρας (port)"
-
-#
-#: src/utils.c:392
-msgid "Invalid host name"
-msgstr "Μη έγκυρο όνομα εξυπηρετητή"
+#. parent, no error
+#: src/utils.c:455
+#, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr ""
+"Συνέχιση στο παρασκήνιο, ταυτότητα διεργασίας (pid) %d.\n"
+"\n"
 
-#
-#: src/utils.c:613
+#: src/utils.c:499
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Αποτυχία διαγραφής συμβολικού συνδέσμου `%s': %s\n"
 
-#
-#, fuzzy
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr "Σύνδεση με %s:%hu δεν επετράπει.\n"
+
+#~ msgid "%s: Cannot determine user-id.\n"
+#~ msgstr "%s: Δεν είναι δυνατή η αναγνώριση της ταυτότητας χρήστη.\n"
+
+#~ msgid "%s: Warning: uname failed: %s\n"
+#~ msgstr "%s: Προειδοποίηση: η uname απέτυχε: %s\n"
+
+#~ msgid "%s: Warning: gethostname failed\n"
+#~ msgstr "%s: Προειδοποίηση: η gethostname απέτυχε\n"
+
+#~ msgid "%s: Warning: cannot determine local IP address.\n"
+#~ msgstr "%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
+
+#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
+#~ msgstr "%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
+
+#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
+#~ msgstr "%s: Προειδοποίηση: η ανάστροφη αναζήτηση της τοπικής διεύθυνσης δεν παρήγαγε το FDQN!\n"
+
 #~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: Δεν υπάρχει αρκετή μνήμη.\n"
+#~ msgstr "%s: Η μνήμη εξαντλήθηκε.\n"
 
-#
 #~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
 #~ "\n"
+#~ "CTRL+Break received, redirecting output to `%s'.\n"
+#~ "Execution continued in background.\n"
+#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
 #~ msgstr ""
-#~ "Το τοπικό αρχείο `%s' είναι πιο πρόσφατο, αποφεύγετε η ανάκτηση.\n"
 #~ "\n"
+#~ "CTRL+Break πατήθηκε, ανακατεύθυνση εξόδου στο `%s'.\n"
+#~ "Η εκτέλεση συνεχίζεται στο παρασκήνιο.\n"
+#~ "Μπορείτε να διακόψετε το Wget πατώντας CTRL+ALT+DELETE.\n"
+
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: Ανακατεύθυνση στον εαυτό του.\n"
 
-#
 #~ msgid "Error (%s): Link %s without a base provided.\n"
 #~ msgstr "Σφάλμα (%s): Δόθηκε τοποθεσία %s χωρίς βάση.\n"
 
-#
 #~ msgid "Error (%s): Base %s relative, without referer URL.\n"
 #~ msgstr "Σφάλμα (%s): Η βάση %s είναι σχετική, χωρίς URL αναφοράς.\n"
 
-#
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "¶γνωστο/μη υποστηριζόμενο πρωτόκολλο"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "Μη έγκυρη ρύθμιση θύρας (port)"
+
+#~ msgid "Invalid host name"
+#~ msgstr "Μη έγκυρο όνομα εξυπηρετητή"
+
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Το τοπικό αρχείο `%s' είναι πιο πρόσφατο, αποφεύγεται η ανάκτηση.\n"
+#~ "\n"
+
 #~ msgid "%s: unrecognized option, character code 0%o\n"
 #~ msgstr "%s: μη αναγνωρίσιμη επιλογή, κωδικός χαρακτήρα 0%o\n"
 
-#
 #~ msgid "%s: unrecognized option `-%c'\n"
 #~ msgstr "%s: μη αναγνωρίσημη επιλογή `-%c'\n"
 
-#
 #~ msgid "%s: option `-%c' requires an argument\n"
 #~ msgstr "%s: η επιλογή `-%c' απαιτεί ένα όρισμα\n"
