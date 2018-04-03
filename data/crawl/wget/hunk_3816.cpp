 "Content-Transfer-Encoding: 8-bit\n"
 
 #
-# File: src/ftp.c, line: 147
-# File: src/http.c, line: 346
+#: src/ftp-ls.c:698 src/ftp-ls.c:700
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "Κατάλογος του /%s στο %s:%d"
+
+#
+#: src/ftp-ls.c:722
+msgid "time unknown       "
+msgstr "ώρα άγνωστη        "
+
+#
+#: src/ftp-ls.c:726
+msgid "File        "
+msgstr "Αρχείο      "
+
+#
+#: src/ftp-ls.c:729
+msgid "Directory   "
+msgstr "Κατάλογος   "
+
+#
+#: src/ftp-ls.c:732
+msgid "Link        "
+msgstr "Σύνδεση     "
+
+#
+#: src/ftp-ls.c:735
+msgid "Not sure    "
+msgstr "Όχι απόλυτα σίγουρος   "
+
+#
+#: src/ftp-ls.c:753
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s bytes)"
+
+#
 #. Login to the server:
 #. First: Establish the control connection.
+#: src/ftp.c:152 src/http.c:582
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "Σύνδεση με %s:%hu... "
 
 #
-# File: src/ftp.c, line: 169
-# File: src/ftp.c, line: 411
-# File: src/http.c, line: 363
+#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "Σύνδεση με %s:%hu δεν επετράπει.\n"
 
 #
-# File: src/ftp.c, line: 190
-# File: src/http.c, line: 374
 #. Second: Login with proper USER/PASS sequence.
+#: src/ftp.c:195 src/http.c:610
 msgid "connected!\n"
 msgstr "συνδέθηκε!\n"
 
 #
-# File: src/ftp.c, line: 191
+#: src/ftp.c:196
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Αυθεντικοποίηση σαν %s ... "
 
 #
-# File: src/ftp.c, line: 200
-# File: src/ftp.c, line: 253
-# File: src/ftp.c, line: 301
-# File: src/ftp.c, line: 353
-# File: src/ftp.c, line: 447
-# File: src/ftp.c, line: 520
-# File: src/ftp.c, line: 568
-# File: src/ftp.c, line: 616
+#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
+#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
 msgid "Error in server response, closing control connection.\n"
 msgstr "Σφάλμα στην απάντηση του εξυπηρετητή, κλείνει η σύνδεση ελέγχου.\n"
 
 #
-# File: src/ftp.c, line: 208
+#: src/ftp.c:213
 msgid "Error in server greeting.\n"
 msgstr "Σφάλμα στο μύνημα αποδοχής του εξυπηρετητή.\n"
 
 #
-# File: src/ftp.c, line: 216
-# File: src/ftp.c, line: 262
-# File: src/ftp.c, line: 310
-# File: src/ftp.c, line: 362
-# File: src/ftp.c, line: 457
-# File: src/ftp.c, line: 530
-# File: src/ftp.c, line: 578
-# File: src/ftp.c, line: 626
+#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
+#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
 msgid "Write failed, closing control connection.\n"
 msgstr "Αποτυχία στην εγγραφή δεδομένων, κλείνει η σύνδεση ελέγχου.\n"
 
 #
-# File: src/ftp.c, line: 223
+#: src/ftp.c:228
 msgid "The server refuses login.\n"
 msgstr "Ο εξυπηρετητής απαγορεύει τη σύνδεση.\n"
 
 #
-# File: src/ftp.c, line: 230
+#: src/ftp.c:235
 msgid "Login incorrect.\n"
 msgstr "Λάθος όνομα πρόσβασης.\n"
 
 #
-# File: src/ftp.c, line: 237
+#: src/ftp.c:242
 msgid "Logged in!\n"
 msgstr "Επιτυχής σύνδεση!\n"
 
+#: src/ftp.c:267
+msgid "Server error, can't determine system type.\n"
+msgstr ""
+
+#
+#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
+msgid "done.    "
+msgstr "έγινε.    "
+
+#
+#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
+msgid "done.\n"
+msgstr "έγινε.\n"
+
 #
-# File: src/ftp.c, line: 270
+#: src/ftp.c:331
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Άγνωστος τύπος `%c', διακοπή της σύνδεσης.\n"
 
 #
-# File: src/ftp.c, line: 283
+#: src/ftp.c:344
 msgid "done.  "
 msgstr "έγινε.  "
 
 #
-# File: src/ftp.c, line: 289
+#: src/ftp.c:350
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD δεν απαιτήται.\n"
 
 #
-# File: src/ftp.c, line: 317
+#: src/ftp.c:426
 #, c-format
-msgid "No such directory `%s'.\n\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
 msgstr "Δεν υπάρχει τέτοιος κατάλογος `%s'.\n"
 
 #
-# File: src/ftp.c, line: 331
-# File: src/ftp.c, line: 599
-# File: src/ftp.c, line: 647
-# File: src/url.c, line: 1431
-msgid "done.\n"
-msgstr "έγινε.\n"
-
-#
-# File: src/ftp.c, line: 335
 #. do not CWD
+#: src/ftp.c:444
 msgid "==> CWD not required.\n"
 msgstr "==> CWD δεν απαιτείται.\n"
 
 #
-# File: src/ftp.c, line: 369
+#: src/ftp.c:478
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Δεν είναι δυνατή να ξεκινήσει μεταφορά τύπου PASV.\n"
 
 #
-# File: src/ftp.c, line: 373
+#: src/ftp.c:482
 msgid "Cannot parse PASV response.\n"
 msgstr "Δεν είναι δυνατή η μετάφραση της απάντησης PASV.\n"
 
 #
-# File: src/ftp.c, line: 387
+#: src/ftp.c:496
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "Θα επιχειρηθεί σύνδεση στο %s:%hu.\n"
 
 #
-# File: src/ftp.c, line: 432
-# File: src/ftp.c, line: 504
-# File: src/ftp.c, line: 548
-msgid "done.    "
-msgstr "έγινε.    "
-
-#
-# File: src/ftp.c, line: 474
+#: src/ftp.c:583
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Σφάλμα στη σύνδεση (%s).\n"
 
 #
-# File: src/ftp.c, line: 490
+#: src/ftp.c:599
 msgid "Invalid PORT.\n"
 msgstr "Μη έγκυρο PORT.\n"
 
 #
-# File: src/ftp.c, line: 537
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nΑποτυχία στην εντολή REST, εκκίνηση από το μηδέν.\n"
+#: src/ftp.c:646
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"Αποτυχία στην εντολή REST, εκκίνηση από το μηδέν.\n"
 
 #
-# File: src/ftp.c, line: 586
+#: src/ftp.c:695
 #, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "Δεν υπάρχει αρχείο `%s'.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"Δεν υπάρχει αρχείο `%s'.\n"
+"\n"
 
 #
-# File: src/ftp.c, line: 634
+#: src/ftp.c:743
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "Δεν υπάρχει αρχείο ή κατάλογος `%s'.\n\n"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"Δεν υπάρχει αρχείο ή κατάλογος `%s'.\n"
+"\n"
 
 #
-# File: src/ftp.c, line: 692
-# File: src/ftp.c, line: 699
+#: src/ftp.c:819 src/ftp.c:826
 #, c-format
 msgid "Length: %s"
 msgstr "Μήκος: %s"
 
 #
-# File: src/ftp.c, line: 694
-# File: src/ftp.c, line: 701
+#: src/ftp.c:821 src/ftp.c:828
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s για πέρας]"
 
 #
-# File: src/ftp.c, line: 703
+#: src/ftp.c:830
 msgid " (unauthoritative)\n"
 msgstr " (ανεπίσημο)\n"
 
 #
-# File: src/ftp.c, line: 721
+#: src/ftp.c:856
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, κλείσιμο σύνδεσης ελέγχου.\n"
 
 #
-# File: src/ftp.c, line: 729
+#: src/ftp.c:864
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Σύνδεση δεδομένων: %s; "
 
 #
-# File: src/ftp.c, line: 746
+#: src/ftp.c:881
 msgid "Control connection closed.\n"
 msgstr "Η σύνδεση ελέγχου έκλεισε.\n"
 
 #
-# File: src/ftp.c, line: 764
+#: src/ftp.c:899
 msgid "Data transfer aborted.\n"
 msgstr "Η μεταφορά δεδομένων διακόπηκε ανώμαλα.\n"
 
 #
-# File: src/ftp.c, line: 830
+#: src/ftp.c:963
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Το αρχείο `%s' υπάρχει ήδη, δεν επανακτάται.\n"
 
 #
-# File: src/ftp.c, line: 896
-# File: src/http.c, line: 922
-#, c-format
+#: src/ftp.c:1024 src/http.c:1358
+#, c-format, ycp-format
 msgid "(try:%2d)"
 msgstr "(προσπάθεια:%2d)"
 
 #
-# File: src/ftp.c, line: 955
-# File: src/http.c, line: 1116
+#: src/ftp.c:1088 src/http.c:1585
+#, c-format
+msgid ""
+"%s (%s) - `%s' saved [%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' αποθηκεύτηκε [%ld]\n"
+"\n"
+
+#
+#: src/ftp.c:1130 src/main.c:771 src/recur.c:505 src/retr.c:580
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - `%s' αποθηκεύτηκε [%ld]\n\n"
+msgid "Removing %s.\n"
+msgstr "Διαγραφή του %s.\n"
 
 #
-# File: src/ftp.c, line: 1001
+#: src/ftp.c:1171
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Χρήση του `%s' για προσωρινό αρχείο περιεχομένων καταλόγου.\n"
 
 #
-# File: src/ftp.c, line: 1013
+#: src/ftp.c:1183
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Διαγραφή του `%s'.\n"
 
 #
-# File: src/ftp.c, line: 1049
+#: src/ftp.c:1219
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Το επίπεδο αναδρομής %d ξεπέρασε το μέγιστο επίπεδο αναδρομής %d.\n"
 
-#
-# File: src/ftp.c, line: 1096
-# File: src/http.c, line: 1054
+#: src/ftp.c:1271 src/http.c:1512
 #, c-format
-msgid "Local file `%s' is more recent, not retrieving.\n\n"
-msgstr "Το τοπικό αρχείο `%s' είναι πιο πρόσφατο, αποφεύγετε η ανάκτηση.\n\n"
+msgid ""
+"Server file no newer than local file `%s' -- not retrieving.\n"
+"\n"
+msgstr ""
+
+#: src/ftp.c:1279
+msgid "Cannot compare sizes, remote system is VMS.\n"
+msgstr ""
 
 #
-# File: src/ftp.c, line: 1102
-# File: src/http.c, line: 1060
-#, c-format
-msgid "The sizes do not match (local %ld), retrieving.\n"
+#: src/ftp.c:1285 src/http.c:1520
+#, fuzzy, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr "Τα μεγέθη δεν είναι ίσα (τοπικό %ld), γίνεται ανάκτηση.\n"
 
 #
-# File: src/ftp.c, line: 1119
+#: src/ftp.c:1303
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Μη έγκυρο όνομα συμβολικού συνδέσμου, παρακάμπτεται.\n"
 
 #
-# File: src/ftp.c, line: 1136
+#: src/ftp.c:1320
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
-msgstr "Υπάρχει ήδη το ορθό αρχείο σύνδεσης %s -> %s\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
+msgstr ""
+"Υπάρχει ήδη το ορθό αρχείο σύνδεσης %s -> %s\n"
+"\n"
 
 #
-# File: src/ftp.c, line: 1144
+#: src/ftp.c:1328
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Δημιουργία αρχείου σύνδεσης %s -> %s\n"
 
 #
-# File: src/ftp.c, line: 1155
+#: src/ftp.c:1339
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Αρχεία σύνδεσης δεν υποστηρίζονται, παράκαμψη αρχείου σύνδεσης `%s'.\n"
 
 #
-# File: src/ftp.c, line: 1167
+#: src/ftp.c:1351
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Παράκαμψη καταλόγου `%s'.\n"
 
 #
-# File: src/ftp.c, line: 1176
+#: src/ftp.c:1360
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: άγνωστο/μη υποστηριζόμενο είδος αρχείου.\n"
 
 #
-# File: src/ftp.c, line: 1193
+#: src/ftp.c:1377
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: εσφαλμένη ημερομηνία αρχείου.\n"
 
 #
-# File: src/ftp.c, line: 1213
+#: src/ftp.c:1398
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Δεν θα ανακτηθούν κατάλογοι διότι το βάθος είναι %d (μέγιστο %d).\n"
 
 #
-# File: src/ftp.c, line: 1252
+#: src/ftp.c:1437
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr "Δεν επεκτεινόμαστε στο `%s' διότι είναι εξαιρούμενο/μη-συμπεριλαμβανόμενο\n"
+msgstr ""
+"Δεν επεκτεινόμαστε στο `%s' διότι είναι εξαιρούμενο/μη-συμπεριλαμβανόμενο\n"
 
 #
-# File: src/ftp.c, line: 1297
+#: src/ftp.c:1482
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Απόρριψη του `%s'.\n"
 
 #
-# File: src/ftp.c, line: 1344
 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
+#: src/ftp.c:1529
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Δεν βρέθηκαν ταιριάσματα στη μορφή `%s'.\n"
 
 #
-# File: src/ftp.c, line: 1404
+#: src/ftp.c:1589
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
 msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s' [%ld].\n"
 
 #
-# File: src/ftp.c, line: 1409
+#: src/ftp.c:1594
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s'.\n"
 
 #
-# File: src/getopt.c, line: 454
+#: src/getopt.c:454
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: η επιλογή `%s' είναι αόριστη\n"
 
 #
-# File: src/getopt.c, line: 478
+#: src/getopt.c:478
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: η επιλογή `--%s' δεν επιδέχεται όρισμα\n"
 
 #
-# File: src/getopt.c, line: 483
+#: src/getopt.c:483
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: η επιλογή `%c%s' δεν επιδέχεται όρισμα\n"
 
 #
-# File: src/getopt.c, line: 498
+#: src/getopt.c:498
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: η επιλογή `%s' απαιτεί όρισμα\n"
 
 #
-# File: src/getopt.c, line: 528
 #. --option
+#: src/getopt.c:528
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: μη αναγνωρίσημη επιλογή `--%s'\n"
 
 #
-# File: src/getopt.c, line: 532
 #. +option or -option
+#: src/getopt.c:532
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: μη αναγνωρίσιμη επιλογή `%c%s'\n"
 
 #
-# File: src/getopt.c, line: 563
 #. 1003.2 specifies the format of this message.
+#: src/getopt.c:563
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: μη αποδεκτή επιλογή -- %c\n"
 
 #
-# File: src/getopt.c, line: 602
 #. 1003.2 specifies the format of this message.
+#: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: η επιλογή απαιτεί μια παράμετρο -- %c\n"
 
 #
-# File: src/host.c, line: 432
+#: src/host.c:394
 #, c-format
 msgid "%s: Cannot determine user-id.\n"
 msgstr "%s: Δεν είναι δυνατή η αναγνώριση της ταυτότητας χρήστη.\n"
 
 #
-# File: src/host.c, line: 444
+#: src/host.c:406
 #, c-format
 msgid "%s: Warning: uname failed: %s\n"
 msgstr "%s: Προειδοποίηση: η uname απέτυχε: %s\n"
 
 #
-# File: src/host.c, line: 456
+#: src/host.c:418
 #, c-format
 msgid "%s: Warning: gethostname failed\n"
 msgstr "%s: Προειδοποίηση: η gethostname απέτυχε\n"
 
 #
-# File: src/host.c, line: 484
+#: src/host.c:446
 #, c-format
 msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
+msgstr ""
+"%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
 
 #
-# File: src/host.c, line: 498
+#: src/host.c:460
 #, c-format
 msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr "%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
+msgstr ""
+"%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
 
 #
-# File: src/host.c, line: 511
 #. This gets ticked pretty often.  Karl Berry reports
 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr "%s: Προειδοποίηση: η ανάστροφη αναζήτηση της τοπικής διεύθυνσης δεν παρήγαγε το FDQN!\n"
+msgstr ""
+"%s: Προειδοποίηση: η ανάστροφη αναζήτηση της τοπικής διεύθυνσης δεν παρήγαγε "
+"το FDQN!\n"
 
 #
-# File: src/host.c, line: 539
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Ο εξυπηρετητής δεν βρέθηκε"
 
 #
-# File: src/host.c, line: 541
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "Άγνωστο σφάλμα"
 
-#
-# File: src/html.c, line: 439
-# File: src/html.c, line: 441
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Κατάλογος του /%s στο %s:%d"
-
-#
-# File: src/html.c, line: 463
-msgid "time unknown       "
-msgstr "ώρα άγνωστη        "
-
-#
-# File: src/html.c, line: 467
-msgid "File        "
-msgstr "Αρχείο      "
-
-#
-# File: src/html.c, line: 470
-msgid "Directory   "
-msgstr "Κατάλογος   "
-
-#
-# File: src/html.c, line: 473
-msgid "Link        "
-msgstr "Σύνδεση     "
-
-#
-# File: src/html.c, line: 476
-msgid "Not sure    "
-msgstr "Όχι απόλυτα σίγουρος   "
+#: src/http.c:621 src/http.c:1433
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
 
 #
-# File: src/html.c, line: 494
-#, c-format
-msgid " (%s bytes)"
-msgstr " (%s bytes)"
+#: src/http.c:629
+#, fuzzy, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Θα επιχειρηθεί σύνδεση στο %s:%hu.\n"
 
 #
-# File: src/http.c, line: 492
-msgid "Failed writing HTTP request.\n"
+#: src/http.c:805
+#, fuzzy, c-format
+msgid "Failed writing HTTP request: %s.\n"
 msgstr "Σφάλμα στην καταγραφή της HTTP αίτησης.\n"
 
 #
-# File: src/http.c, line: 497
+#: src/http.c:810
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Η αίτηση για %s στάλθηκε, αναμονή απάντησης... "
 
 #
-# File: src/http.c, line: 536
+#: src/http.c:854
 msgid "End of file while parsing headers.\n"
 msgstr "Τέλος αρχείου ενώ γινόταν επεξεργασία των κεφαλίδων.\n"
 
 #
-# File: src/http.c, line: 547
+#: src/http.c:865
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Σφάλμα ανάγνωσης (%s) στις κεφαλίδες.\n"
 
 #
-# File: src/http.c, line: 587
+#: src/http.c:905
 msgid "No data received"
 msgstr "Δεν ελήφθησαν δεδομένα"
 
 #
-# File: src/http.c, line: 589
+#: src/http.c:907
 msgid "Malformed status line"
 msgstr "Εσφαλμένη γραμμή κατάστασης"
 
 #
-# File: src/http.c, line: 594
+#: src/http.c:912
 msgid "(no description)"
 msgstr "(χωρίς περιγραφή)"
 
 #
-# File: src/http.c, line: 678
-#. If we have tried it already, then there is not point
-#. retrying it.
+#: src/http.c:1030
 msgid "Authorization failed.\n"
 msgstr "Η αυθεντικοποίηση απέτυχε.\n"
 
 #
-# File: src/http.c, line: 685
+#: src/http.c:1037
 msgid "Unknown authentication scheme.\n"
 msgstr "Άγνωστο σχήμα αυθεντικοποίησης.\n"
 
 #
-# File: src/http.c, line: 748
+#: src/http.c:1127
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Τοποθεσία: %s%s\n"
 
 #
-# File: src/http.c, line: 749
-# File: src/http.c, line: 774
+#: src/http.c:1128 src/http.c:1153
 msgid "unspecified"
 msgstr "μη ορισμένο"
 
 #
-# File: src/http.c, line: 750
+#: src/http.c:1129
 msgid " [following]"
 msgstr " [ακολουθεί]"
 
 #
-# File: src/http.c, line: 764
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
+#: src/http.c:1143
 msgid "Length: "
 msgstr "Μήκος: "
 
 #
-# File: src/http.c, line: 769
+#: src/http.c:1148
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s μέχρι πέρας)"
 
 #
-# File: src/http.c, line: 774
+#: src/http.c:1153
 msgid "ignored"
 msgstr "αγνοείται"
 
 #
-# File: src/http.c, line: 857
+#: src/http.c:1254
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr "Προειδοποίηση: μεταχαρακτήρες (wildcards) δεν υποστηρίζονται στο HTTP.\n"
+msgstr ""
+"Προειδοποίηση: μεταχαρακτήρες (wildcards) δεν υποστηρίζονται στο HTTP.\n"
 
 #
-# File: src/http.c, line: 872
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
+#: src/http.c:1275
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Το αρχείο `%s' είναι ήδη εδώ, δεν θα ανακτηθεί.\n"
 
 #
-# File: src/http.c, line: 978
+#: src/http.c:1425
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Αδυναμία στην εγγραφή στο `%s' (%s).\n"
 
 #
-# File: src/http.c, line: 988
+#: src/http.c:1443
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "ΣΦΑΛΜΑ: Μετάσταση (%d) χωρίς τοποθεσία.\n"
 
 #
-# File: src/http.c, line: 1011
+#: src/http.c:1468
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ΣΦΑΛΜΑ %d: %s.\n"
 
 #
-# File: src/http.c, line: 1023
+#: src/http.c:1481
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr "Κεφαλίδα Last-modified δεν υπάρχει -- χρονικές αναφορές απενεργοποιήθηκαν.\n"
+msgstr ""
+"Κεφαλίδα Last-modified δεν υπάρχει -- χρονικές αναφορές απενεργοποιήθηκαν.\n"
 
 #
-# File: src/http.c, line: 1031
+#: src/http.c:1489
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr "Κεφαλίδα Last-modified δεν είναι έγκυρη -- χρονικές αναφορές αγνοούνται.\n"
+msgstr ""
+"Κεφαλίδα Last-modified δεν είναι έγκυρη -- χρονικές αναφορές αγνοούνται.\n"
 
 #
-# File: src/http.c, line: 1064
+#: src/http.c:1524
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Απομακρυσμένο αρχείο είναι νεότερο, έναρξη ανάκτησης.\n"
 
 #
-# File: src/http.c, line: 1098
+#: src/http.c:1559
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - `%s' αποθηκεύτηκε [%ld/%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld/%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' αποθηκεύτηκε [%ld/%ld]\n"
+"\n"
 
 #
-# File: src/http.c, line: 1130
+#: src/http.c:1607
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - Η σύνδεση διακόπηκε στο byte %ld. "
 
 #
-# File: src/http.c, line: 1138
+#: src/http.c:1615
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - `%s' αποθηκεύτηκε [%ld/%ld])\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld/%ld])\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' αποθηκεύτηκε [%ld/%ld])\n"
+"\n"
 
 #
-# File: src/http.c, line: 1150
+#: src/http.c:1635
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - Η σύνδεση διακόπηκε στο byte %ld/%ld. "
 
 #
-# File: src/http.c, line: 1161
+#: src/http.c:1646
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - Σφάλμα ανάγνωσης στο byte %ld (%s)."
 
 #
-# File: src/http.c, line: 1169
+#: src/http.c:1654
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr "%s (%s) - Σφάλμα ανάγνωσης στο byte %ld/%ld (%s). "
 
 #
-# File: src/init.c, line: 312
-# File: src/netrc.c, line: 250
+#: src/init.c:332 src/netrc.c:261
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Αδυναμία ανάγνωσης %s (%s).\n"
 
 #
-# File: src/init.c, line: 333
-# File: src/init.c, line: 339
+#: src/init.c:350 src/init.c:356
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Σφάλμα στο %s στη γραμμή %d.\n"
 
 #
-# File: src/init.c, line: 370
+#: src/init.c:387
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr "%s: Προειδοποίηση: Το wgetrc του συστήματος και του χρήστη δείχνουν στο ίδιο αρχείο `%s'.\n"
+msgstr ""
+"%s: Προειδοποίηση: Το wgetrc του συστήματος και του χρήστη δείχνουν στο ίδιο "
+"αρχείο `%s'.\n"
 
 #
-# File: src/init.c, line: 458
+#: src/init.c:479
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr "%s: Άγνωστη εντολή `%s', τιμή `%s'.\n"
 
 #
-# File: src/init.c, line: 485
+#: src/init.c:501
+#, fuzzy, c-format
+msgid "%s: Out of memory.\n"
+msgstr "%s: %s: Δεν υπάρχει αρκετή μνήμη.\n"
+
+#
+#: src/init.c:507
+#, fuzzy, c-format
+msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+msgstr ""
+"%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
+
+#
+#: src/init.c:535
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
 msgstr "%s: %s: Παρακαλώ ορίστε on ή off.\n"
 
 #
-# File: src/init.c, line: 503
-# File: src/init.c, line: 760
-# File: src/init.c, line: 782
-# File: src/init.c, line: 855
+#: src/init.c:579
+#, fuzzy, c-format
+msgid "%s: %s: Please specify always, on, off, or never.\n"
+msgstr "%s: %s: Παρακαλώ ορίστε on ή off.\n"
+
+#
+#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: Μη έγκυρη ρύθμιση `%s'.\n"
 
 #
-# File: src/init.c, line: 616
-# File: src/init.c, line: 638
-# File: src/init.c, line: 660
-# File: src/init.c, line: 686
+#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr "%s: Μη έγκυρη ρύθμιση `%s'.\n"
 
 #
-# File: src/main.c, line: 101
+#: src/main.c:119
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "Χρήση: %s [ΕΠΙΛΟΓΗ]... [URL]...\n"
 
 #
-# File: src/main.c, line: 109
+#: src/main.c:127
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
 msgstr "GNU Wget %s, ένα μη-διαλογικό δικτυακό πρόγραμμα ανάκτησης αρχείων.\n"
 
 #
-# File: src/main.c, line: 114
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
-msgstr "\nΟι υποχρεωτικοί παράμετροι στα λεκτικά ορίσματα είναι υποχρεωτικοί και για τα σύντομα ορίσματα.\n\n"
+#: src/main.c:132
+msgid ""
+"\n"
+"Mandatory arguments to long options are mandatory for short options too.\n"
+"\n"
+msgstr ""
+"\n"
+"Οι υποχρεωτικοί παράμετροι στα λεκτικά ορίσματα είναι υποχρεωτικοί και για "
+"τα σύντομα ορίσματα.\n"
+"\n"
 
 #
-# File: src/main.c, line: 117
+#: src/main.c:135
+#, fuzzy
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
 "  -h,  --help              print this help.\n"
 "  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
+"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
 "\n"
 msgstr ""
 "Έναρξη:\n"
