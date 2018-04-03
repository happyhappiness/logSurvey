 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1608
+#: src/ftp.c:1819
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Δεν βρέθηκαν ταιριάσματα στη μορφή `%s'.\n"
 
-#: src/ftp.c:1673
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1885
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s' [%ld].\n"
 
-#: src/ftp.c:1678
+#: src/ftp.c:1890
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s'.\n"
 
+#. Still not enough randomness, most likely because neither
+#. /dev/random nor EGD were available.  Resort to a simple and
+#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
+#. cryptographically weak, but people who care about strong
+#. cryptography should install /dev/random (default on Linux) or
+#. specify their own source of randomness anyway.
 #: src/gen_sslfunc.c:109
+msgid "Warning: using a weak random seed.\n"
+msgstr ""
+
+#: src/gen_sslfunc.c:166
 msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
 msgstr "Αδύνατη η αρχικοποίηση της PRNG της OpenSSL· απενεργοποίηση του SSL.\n"
 
-#: src/getopt.c:454
+#: src/gen_sslfunc.c:223
+msgid "Warning: validation of server certificate not possible!\n"
+msgstr ""
+
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: η επιλογή `%s' είναι αόριστη\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: η επιλογή `--%s' δεν επιδέχεται όρισμα\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: η επιλογή `%c%s' δεν επιδέχεται όρισμα\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: η επιλογή `%s' απαιτεί όρισμα\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: μη αναγνωρίσημη επιλογή `--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: μη αναγνωρίσιμη επιλογή `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: μη αποδεκτή επιλογή -- %c\n"
 
+#: src/getopt.c:785
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: μη αποδεκτή επιλογή -- %c\n"
+
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: η επιλογή απαιτεί μια παράμετρο -- %c\n"
 
-#: src/host.c:271
+#: src/getopt.c:862
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: η επιλογή `%s' είναι αόριστη\n"
+
+#: src/getopt.c:880
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: η επιλογή `--%s' δεν επιδέχεται όρισμα\n"
+
+#: src/host.c:368
+#, fuzzy
+msgid "Unknown host"
+msgstr "¶γνωστο σφάλμα"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:372
+msgid "Temporary failure in name resolution"
+msgstr ""
+
+#: src/host.c:374
+msgid "Unknown error"
+msgstr "¶γνωστο σφάλμα"
+
+#: src/host.c:748
 #, c-format
 msgid "Resolving %s... "
 msgstr "Εύρεση του %s... "
 
-#: src/host.c:278
+#: src/host.c:792 src/host.c:839
 #, c-format
 msgid "failed: %s.\n"
 msgstr "απέτυχε: %s.\n"
 
-#: src/host.c:348
-msgid "Host not found"
-msgstr "Ο διακομιστής δε βρέθηκε"
+#: src/host.c:801
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
 
-#: src/host.c:350
-msgid "Unknown error"
-msgstr "¶γνωστο σφάλμα"
+#: src/host.c:842
+#, fuzzy
+msgid "failed: timed out.\n"
+msgstr "απέτυχε: %s.\n"
 
-#: src/html-url.c:336
+#: src/html-url.c:297
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Αδύνατη η ανάλυση μη ολοκληρωμένου συνδέσμου %s.\n"
 
+#: src/http.c:349 src/http.c:1504
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"
+
+#: src/http.c:663
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
 #. this is fatal
-#: src/http.c:573
+#: src/http.c:1151
 msgid "Failed to set up an SSL context\n"
 msgstr "Αποτυχία δημιουργίας περιβάλλοντος SSL\n"
 
-#: src/http.c:579
+#: src/http.c:1156
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Αποτυχία φόρτωσης πιστοποιητικών από %s\n"
 
-#: src/http.c:583 src/http.c:591
+#: src/http.c:1159 src/http.c:1166
 msgid "Trying without the specified certificate\n"
 msgstr "Προσπάθεια χωρίς το καθορισμένο πιστοποιητικό\n"
 
-#: src/http.c:587
+#: src/http.c:1163
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Αποτυχία λήψης κλειδιού πιστοποιητικού από %s\n"
 
-#: src/http.c:657 src/http.c:1620
-msgid "Unable to establish SSL connection.\n"
-msgstr "Αδύνατη η σύσταση σύνδεσης SSL.\n"
-
-#: src/http.c:666
-#, c-format
-msgid "Reusing connection to %s:%hu.\n"
+#: src/http.c:1382
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Χρήση ξανά της σύνδεσης στο %s:%hu.\n"
 
-#: src/http.c:868
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1434
+#, fuzzy, c-format
+msgid "Failed writing to proxy: %s.\n"
+msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"
+
+#: src/http.c:1443
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"
 
-#: src/http.c:873
+#: src/http.c:1463
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
+#: src/http.c:1510
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Η αίτηση για %s στάλθηκε, αναμονή απάντησης... "
 
-#: src/http.c:917
-msgid "End of file while parsing headers.\n"
-msgstr "Τέλος αρχείου ενώ γινόταν επεξεργασία των κεφαλίδων.\n"
+#: src/http.c:1521
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Δεν ελήφθησαν δεδομένα"
 
-#: src/http.c:927
+#: src/http.c:1528
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Σφάλμα ανάγνωσης (%s) στις κεφαλίδες.\n"
 
-#: src/http.c:962
-msgid "No data received"
-msgstr "Δεν ελήφθησαν δεδομένα"
+#. If we have tried it already, then there is not point
+#. retrying it.
+#: src/http.c:1595
+msgid "Authorization failed.\n"
+msgstr "Η αυθεντικοποίηση απέτυχε.\n"
+
+#: src/http.c:1609
+msgid "Unknown authentication scheme.\n"
+msgstr "¶γνωστο σχήμα αυθεντικοποίησης.\n"
 
-#: src/http.c:964
+#: src/http.c:1634
 msgid "Malformed status line"
 msgstr "Εσφαλμένη γραμμή κατάστασης"
 
-#: src/http.c:969
+#: src/http.c:1636
 msgid "(no description)"
 msgstr "(χωρίς περιγραφή)"
 
-#: src/http.c:1101
-msgid "Authorization failed.\n"
-msgstr "Η αυθεντικοποίηση απέτυχε.\n"
-
-#: src/http.c:1108
-msgid "Unknown authentication scheme.\n"
-msgstr "¶γνωστο σχήμα αυθεντικοποίησης.\n"
-
-#: src/http.c:1148
+#: src/http.c:1700
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Τοποθεσία: %s%s\n"
 
-#: src/http.c:1149 src/http.c:1282
+#: src/http.c:1701 src/http.c:1801
 msgid "unspecified"
 msgstr "μη ορισμένο"
 
-#: src/http.c:1150
+#: src/http.c:1702
 msgid " [following]"
 msgstr " [ακολουθεί]"
 
-#: src/http.c:1213
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:1751
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
