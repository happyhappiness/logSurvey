 "%s (%s) - `%s' αποθηκεύτηκε [%ld]\n"
 "\n"
 
-#
-#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
+#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Διαγραφή του %s.\n"
 
-#
-#: src/ftp.c:1168
+#: src/ftp.c:1202
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Χρήση του `%s' για προσωρινό αρχείο περιεχομένων καταλόγου.\n"
 
-#
-#: src/ftp.c:1180
+#: src/ftp.c:1217
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Διαγραφή του `%s'.\n"
 
-#
-#: src/ftp.c:1216
+#: src/ftp.c:1252
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Το επίπεδο αναδρομής %d ξεπέρασε το μέγιστο επίπεδο αναδρομής %d.\n"
 
-#
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1277
-#, fuzzy, c-format
+#: src/ftp.c:1317
+#, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "Απομακρυσμένο αρχείο είναι νεότερο, έναρξη ανάκτησης.\n"
+msgstr ""
+"Το αρχείο στο διακομιστή δεν είναι νεώτερο του τοπικού `%s' -- δε γίνεται ανάκτηση.\n"
+"\n"
 
-#
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1284
-#, fuzzy, c-format
+#: src/ftp.c:1324
+#, c-format
 msgid ""
 "Remote file is newer than local file `%s' -- retrieving.\n"
 "\n"
-msgstr "Απομακρυσμένο αρχείο είναι νεότερο, έναρξη ανάκτησης.\n"
+msgstr ""
+"Το αρχείο στο διακομιστή είναι νεώτερο του τοπικού `%s' -- γίνεται ανάκτηση.\n"
+"\n"
 
-#
 #. Sizes do not match
-#: src/ftp.c:1291
-#, fuzzy, c-format
+#: src/ftp.c:1331
+#, c-format
 msgid ""
 "The sizes do not match (local %ld) -- retrieving.\n"
 "\n"
-msgstr "Τα μεγέθη δεν είναι ίσα (τοπικό %ld), γίνεται ανάκτηση.\n"
+msgstr "Τα μεγέθη δεν είναι ίσα (τοπικό %ld) -- γίνεται ανάκτηση.\n"
 
-#
-#: src/ftp.c:1308
+#: src/ftp.c:1348
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Μη έγκυρο όνομα συμβολικού συνδέσμου, παρακάμπτεται.\n"
 
-#
-#: src/ftp.c:1325
+#: src/ftp.c:1365
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr ""
-"Υπάρχει ήδη το ορθό αρχείο σύνδεσης %s -> %s\n"
+"Υπάρχει ήδη ο ορθός σύνδεσμος %s -> %s\n"
 "\n"
 
-#
-#: src/ftp.c:1333
+#: src/ftp.c:1373
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "Δημιουργία αρχείου σύνδεσης %s -> %s\n"
+msgstr "Δημιουργία συνδέσμου %s -> %s\n"
 
-#
-#: src/ftp.c:1344
+#: src/ftp.c:1384
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Αρχεία σύνδεσης δεν υποστηρίζονται, παράκαμψη αρχείου σύνδεσης `%s'.\n"
+msgstr "Δεν υποστηρίζονται σύνδεσμοι, παράκαμψη συνδέσμου `%s'.\n"
 
-#
-#: src/ftp.c:1356
+#: src/ftp.c:1396
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Παράκαμψη καταλόγου `%s'.\n"
 
-#
-#: src/ftp.c:1365
+#: src/ftp.c:1405
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: άγνωστο/μη υποστηριζόμενο είδος αρχείου.\n"
 
-#
-#: src/ftp.c:1392
+#: src/ftp.c:1432
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: εσφαλμένη ημερομηνία αρχείου.\n"
 
-#
-#: src/ftp.c:1413
+#: src/ftp.c:1457
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Δεν θα ανακτηθούν κατάλογοι διότι το βάθος είναι %d (μέγιστο %d).\n"
 
-#
-#: src/ftp.c:1449
+#: src/ftp.c:1507
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr ""
-"Δεν επεκτεινόμαστε στο `%s' διότι είναι εξαιρούμενο/μη-συμπεριλαμβανόμενο\n"
+msgstr "Δεν επεκτεινόμαστε στο `%s' διότι είναι εξαιρούμενο/μη-συμπεριλαμβανόμενο\n"
 
-#
-#: src/ftp.c:1494
+#: src/ftp.c:1561
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Απόρριψη του `%s'.\n"
 
-#
 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1541
+#: src/ftp.c:1608
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Δεν βρέθηκαν ταιριάσματα στη μορφή `%s'.\n"
 
-#
-#: src/ftp.c:1605
+#: src/ftp.c:1673
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
 msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s' [%ld].\n"
 
-#
-#: src/ftp.c:1610
+#: src/ftp.c:1678
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s'.\n"
 
-#
+#: src/gen_sslfunc.c:109
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr "Αδύνατη η αρχικοποίηση της PRNG της OpenSSL· απενεργοποίηση του SSL.\n"
+
 #: src/getopt.c:454
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: η επιλογή `%s' είναι αόριστη\n"
 
-#
 #: src/getopt.c:478
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: η επιλογή `--%s' δεν επιδέχεται όρισμα\n"
 
-#
 #: src/getopt.c:483
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: η επιλογή `%c%s' δεν επιδέχεται όρισμα\n"
 
-#
 #: src/getopt.c:498
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: η επιλογή `%s' απαιτεί όρισμα\n"
 
-#
 #. --option
 #: src/getopt.c:528
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: μη αναγνωρίσημη επιλογή `--%s'\n"
 
-#
 #. +option or -option
 #: src/getopt.c:532
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: μη αναγνωρίσιμη επιλογή `%c%s'\n"
 
-#
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:563
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: μη αποδεκτή επιλογή -- %c\n"
 
-#
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: η επιλογή απαιτεί μια παράμετρο -- %c\n"
 
-#
-#: src/host.c:394
-#, c-format
-msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: Δεν είναι δυνατή η αναγνώριση της ταυτότητας χρήστη.\n"
-
-#
-#: src/host.c:406
-#, c-format
-msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: Προειδοποίηση: η uname απέτυχε: %s\n"
-
-#
-#: src/host.c:418
-#, c-format
-msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: Προειδοποίηση: η gethostname απέτυχε\n"
-
-#
-#: src/host.c:446
-#, c-format
-msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr ""
-"%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
-
-#
-#: src/host.c:460
+#: src/host.c:271
 #, c-format
-msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr ""
-"%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης IP.\n"
+msgid "Resolving %s... "
+msgstr "Εύρεση του %s... "
 
-#
-#. This gets ticked pretty often.  Karl Berry reports
-#. that there can be valid reasons for the local host
-#. name not to be an FQDN, so I've decided to remove the
-#. annoying warning.
-#: src/host.c:473
+#: src/host.c:278
 #, c-format
-msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr ""
-"%s: Προειδοποίηση: η ανάστροφη αναζήτηση της τοπικής διεύθυνσης δεν παρήγαγε "
-"το FDQN!\n"
+msgid "failed: %s.\n"
+msgstr "απέτυχε: %s.\n"
 
-#
-#: src/host.c:501
+#: src/host.c:348
 msgid "Host not found"
-msgstr "Ο εξυπηρετητής δεν βρέθηκε"
+msgstr "Ο διακομιστής δε βρέθηκε"
 
-#
-#: src/host.c:503
+#: src/host.c:350
 msgid "Unknown error"
 msgstr "Άγνωστο σφάλμα"
 
+#: src/html-url.c:336
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: Αδύνατη η ανάλυση μη ολοκληρωμένου συνδέσμου %s.\n"
+
 #. this is fatal
-#: src/http.c:549
+#: src/http.c:573
 msgid "Failed to set up an SSL context\n"
-msgstr ""
+msgstr "Αποτυχία δημιουργίας περιβάλλοντος SSL\n"
 
-#: src/http.c:555
+#: src/http.c:579
 #, c-format
 msgid "Failed to load certificates from %s\n"
-msgstr ""
+msgstr "Αποτυχία φόρτωσης πιστοποιητικών από %s\n"
 
-#: src/http.c:559 src/http.c:567
+#: src/http.c:583 src/http.c:591
 msgid "Trying without the specified certificate\n"
-msgstr ""
+msgstr "Προσπάθεια χωρίς το καθορισμένο πιστοποιητικό\n"
 
-#: src/http.c:563
+#: src/http.c:587
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr ""
+msgstr "Αποτυχία λήψης κλειδιού πιστοποιητικού από %s\n"
 
-#: src/http.c:657 src/http.c:1470
+#: src/http.c:657 src/http.c:1620
 msgid "Unable to establish SSL connection.\n"
-msgstr ""
+msgstr "Αδύνατη η σύσταση σύνδεσης SSL.\n"
 
-#
-#: src/http.c:665
-#, fuzzy, c-format
+#: src/http.c:666
+#, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "Θα επιχειρηθεί σύνδεση στο %s:%hu.\n"
+msgstr "Χρήση ξανά της σύνδεσης στο %s:%hu.\n"
 
-#
-#: src/http.c:841
-#, fuzzy, c-format
+#: src/http.c:868
+#, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "Σφάλμα στην καταγραφή της HTTP αίτησης.\n"
+msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"
 
-#
-#: src/http.c:846
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Η αίτηση για %s στάλθηκε, αναμονή απάντησης... "
 
-#
-#: src/http.c:890
+#: src/http.c:917
 msgid "End of file while parsing headers.\n"
 msgstr "Τέλος αρχείου ενώ γινόταν επεξεργασία των κεφαλίδων.\n"
 
-#
-#: src/http.c:901
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Σφάλμα ανάγνωσης (%s) στις κεφαλίδες.\n"
 
-#
-#: src/http.c:941
+#: src/http.c:962
 msgid "No data received"
 msgstr "Δεν ελήφθησαν δεδομένα"
 
-#
-#: src/http.c:943
+#: src/http.c:964
 msgid "Malformed status line"
 msgstr "Εσφαλμένη γραμμή κατάστασης"
 
-#
-#: src/http.c:948
+#: src/http.c:969
 msgid "(no description)"
 msgstr "(χωρίς περιγραφή)"
 
-#
-#: src/http.c:1066
+#: src/http.c:1101
 msgid "Authorization failed.\n"
 msgstr "Η αυθεντικοποίηση απέτυχε.\n"
 
-#
-#: src/http.c:1073
+#: src/http.c:1108
 msgid "Unknown authentication scheme.\n"
 msgstr "Άγνωστο σχήμα αυθεντικοποίησης.\n"
 
-#
-#: src/http.c:1163
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Τοποθεσία: %s%s\n"
 
-#
-#: src/http.c:1164 src/http.c:1189
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "μη ορισμένο"
 
-#
-#: src/http.c:1165
+#: src/http.c:1150
 msgid " [following]"
 msgstr " [ακολουθεί]"
 
-#
+#: src/http.c:1213
+msgid ""
+"\n"
+"    The file is already fully retrieved; nothing to do.\n"
+"\n"
+msgstr ""
+"\n"
+"    Το αρχείο έχει ήδη ανακτηθεί πλήρως· τίποτα να κάνω.\n"
+
+#: src/http.c:1229
+#, c-format
+msgid ""
+"\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"Η συνέχιση της ανάκτησης απέτυχε για αυτό το αρχείο, που συγκρούεται με το `-c'.\n"
+"Άρνηση εγγραφής πάνω στο υπάρχο αρχείο `%s'.\n"
+
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1179
+#: src/http.c:1272
 msgid "Length: "
 msgstr "Μήκος: "
 
-#
-#: src/http.c:1184
+#: src/http.c:1277
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s μέχρι πέρας)"
 
-#
-#: src/http.c:1189
+#: src/http.c:1282
 msgid "ignored"
 msgstr "αγνοείται"
 
-#
-#: src/http.c:1290
+#: src/http.c:1413
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr ""
-"Προειδοποίηση: μεταχαρακτήρες (wildcards) δεν υποστηρίζονται στο HTTP.\n"
+msgstr "Προειδοποίηση: μεταχαρακτήρες (wildcards) δεν υποστηρίζονται στο HTTP.\n"
 
-#
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1311
+#: src/http.c:1443
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
-msgstr "Το αρχείο `%s' είναι ήδη εδώ, δεν θα ανακτηθεί.\n"
+msgstr "Το αρχείο `%s' είναι ήδη εδώ, δε θα ανακτηθεί.\n"
 
-#
-#: src/http.c:1462
+#: src/http.c:1611
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Αδυναμία στην εγγραφή στο `%s' (%s).\n"
 
-#
-#: src/http.c:1480
+#: src/http.c:1630
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "ΣΦΑΛΜΑ: Μετάσταση (%d) χωρίς τοποθεσία.\n"
 
-#
-#: src/http.c:1505
+#: src/http.c:1662
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ΣΦΑΛΜΑ %d: %s.\n"
 
-#
-#: src/http.c:1518
+#: src/http.c:1675
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr ""
-"Κεφαλίδα Last-modified δεν υπάρχει -- χρονικές αναφορές απενεργοποιήθηκαν.\n"
+msgstr "Κεφαλίδα Last-modified δεν υπάρχει -- χρονικές αναφορές απενεργοποιήθηκαν.\n"
 
-#
-#: src/http.c:1526
+#: src/http.c:1683
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr ""
-"Κεφαλίδα Last-modified δεν είναι έγκυρη -- χρονικές αναφορές αγνοούνται.\n"
+msgstr "Κεφαλίδα Last-modified δεν είναι έγκυρη -- χρονικές αναφορές αγνοούνται.\n"
 
-#: src/http.c:1549
+#: src/http.c:1706
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
 msgstr ""
+"Το αρχείο του διακομιστή δεν είναι νεώτερο από το τοπικό αρχείο `%s' -- δε γίνεται ανάκτηση.\n"
+"\n"
 
-#
-#: src/http.c:1557
-#, fuzzy, c-format
+#: src/http.c:1714
+#, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n"
-msgstr "Τα μεγέθη δεν είναι ίσα (τοπικό %ld), γίνεται ανάκτηση.\n"
+msgstr "Τα μεγέθη δεν είναι ίσα (τοπικό %ld) -- γίνεται ανάκτηση ξανά.\n"
 
-#
-#: src/http.c:1561
+#: src/http.c:1718
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Απομακρυσμένο αρχείο είναι νεότερο, έναρξη ανάκτησης.\n"
 
-#
-#: src/http.c:1606
+#: src/http.c:1759
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
