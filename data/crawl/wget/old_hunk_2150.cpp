"Content-Type: text/plain; charset=utf-8\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/connect.c:195
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr ""

#: src/connect.c:267
#, fuzzy, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "Σύνδεση με %s[%s]:%hu... "

#: src/connect.c:270
#, fuzzy, c-format
msgid "Connecting to %s:%d... "
msgstr "Σύνδεση με %s:%hu... "

#: src/connect.c:330
msgid "connected.\n"
msgstr "συνδέθηκε.\n"

#: src/connect.c:342 src/host.c:752 src/host.c:781
#, c-format
msgid "failed: %s.\n"
msgstr "απέτυχε: %s.\n"

#: src/convert.c:171
#, fuzzy, c-format
msgid "Converted %d files in %s seconds.\n"
msgstr "Μετατράπηκαν %d αρχεία σε %.2f δευτερόλεπτα.\n"

#: src/convert.c:196
#, c-format
msgid "Converting %s... "
msgstr "Μετατροπή του %s... "

#: src/convert.c:209
msgid "nothing to do.\n"
msgstr "τίποτα να κάνω.\n"

#: src/convert.c:217 src/convert.c:241
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Αδυναμία μετατροπής συνδέσμων στο %s: %s\n"

#: src/convert.c:232
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Αποτυχία διαγραφής του `%s': %s\n"

#: src/convert.c:441
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Αδύνατη η λήψη αντιγράγου ασφαλείας του %s ως %s: %s\n"

#: src/cookies.c:443
#, fuzzy, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "Συντακτικό σφάλμα στο Set-Cookie: πρόωρο τέλος αλφαριθμητικού.\n"

#: src/cookies.c:685
#, c-format
msgid "Cookie coming from %s attempted to set domain to %s\n"
msgstr ""

#: src/cookies.c:1132 src/cookies.c:1250
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Αδύνατο το άνοιγμα του αρχείου cookies `%s': %s\n"

#: src/cookies.c:1287
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Σφάλμα στην εγγραφή στο `%s': %s\n"

#: src/cookies.c:1290
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Σφάλμα στο κλείσιμο του `%s': %s\n"

#: src/ftp-ls.c:836
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr ""
"Μη υποστηριζόμενος τύπος καταλόγου, δοκιμάζω να τον διαβάσω σαν Unix "
"κατάλογο.\n"

#: src/ftp-ls.c:882 src/ftp-ls.c:884
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Κατάλογος του /%s στο %s:%d"

#: src/ftp-ls.c:907
#, c-format
msgid "time unknown       "
msgstr "ώρα άγνωστη        "

#: src/ftp-ls.c:911
#, c-format
msgid "File        "
msgstr "Αρχείο      "

#: src/ftp-ls.c:914
#, c-format
msgid "Directory   "
msgstr "Κατάλογος   "

#: src/ftp-ls.c:917
#, c-format
msgid "Link        "
msgstr "Σύνδεση     "

#: src/ftp-ls.c:920
#, c-format
msgid "Not sure    "
msgstr "Όχι απόλυτα σίγουρος   "

#: src/ftp-ls.c:938
#, c-format
msgid " (%s bytes)"
msgstr " (%s byte)"

#: src/ftp.c:209
#, c-format
msgid "Length: %s"
msgstr "Μήκος: %s"

#: src/ftp.c:215 src/http.c:2174
#, c-format
msgid ", %s (%s) remaining"
msgstr ""

#: src/ftp.c:219 src/http.c:2178
#, c-format
msgid ", %s remaining"
msgstr ""

#: src/ftp.c:222
msgid " (unauthoritative)\n"
msgstr " (ανεπίσημο)\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:298
#, c-format
msgid "Logging in as %s ... "
msgstr "Αυθεντικοποίηση ως %s ... "

#: src/ftp.c:311 src/ftp.c:357 src/ftp.c:386 src/ftp.c:438 src/ftp.c:550
#: src/ftp.c:596 src/ftp.c:625 src/ftp.c:682 src/ftp.c:743 src/ftp.c:803
#: src/ftp.c:850
msgid "Error in server response, closing control connection.\n"
msgstr "Σφάλμα στην απάντηση του διακομιστή, κλείνει η σύνδεση ελέγχου.\n"

#: src/ftp.c:318
msgid "Error in server greeting.\n"
msgstr "Σφάλμα στο μήνυμα αποδοχής του διακομιστή.\n"

#: src/ftp.c:325 src/ftp.c:446 src/ftp.c:558 src/ftp.c:633 src/ftp.c:692
#: src/ftp.c:753 src/ftp.c:813 src/ftp.c:860
msgid "Write failed, closing control connection.\n"
msgstr "Αποτυχία στην εγγραφή δεδομένων, κλείνει η σύνδεση ελέγχου.\n"

#: src/ftp.c:331
msgid "The server refuses login.\n"
msgstr "Ο διακομιστής απαγορεύει τη σύνδεση.\n"

#: src/ftp.c:337
msgid "Login incorrect.\n"
msgstr "Σφάλμα στην αυθεντικοποίηση.\n"

#: src/ftp.c:343
msgid "Logged in!\n"
msgstr "Επιτυχής σύνδεση!\n"

#: src/ftp.c:365
msgid "Server error, can't determine system type.\n"
msgstr "Σφάλμα διακομιστή, δεν μπορώ να συμπεράνω τον τύπο του συστήματος.\n"

#: src/ftp.c:374 src/ftp.c:669 src/ftp.c:726 src/ftp.c:769
msgid "done.    "
msgstr "έγινε.    "

#: src/ftp.c:426 src/ftp.c:575 src/ftp.c:608 src/ftp.c:833 src/ftp.c:879
msgid "done.\n"
msgstr "έγινε.\n"

#: src/ftp.c:453
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Άγνωστος τύπος `%c', διακοπή της σύνδεσης.\n"

#: src/ftp.c:465
msgid "done.  "
msgstr "έγινε.  "

#: src/ftp.c:471
msgid "==> CWD not needed.\n"
msgstr "==> CWD δεν απαιτήται.\n"

#: src/ftp.c:564
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr "Δεν υπάρχει τέτοιος κατάλογος `%s'.\n"

#. do not CWD
#: src/ftp.c:579
msgid "==> CWD not required.\n"
msgstr "==> CWD δεν απαιτείται.\n"

#: src/ftp.c:639
msgid "Cannot initiate PASV transfer.\n"
msgstr "Δεν είναι δυνατή να ξεκινήσει μεταφορά τύπου PASV.\n"

#: src/ftp.c:643
msgid "Cannot parse PASV response.\n"
msgstr "Δεν είναι δυνατή η μετάφραση της απάντησης PASV.\n"

#: src/ftp.c:660
#, fuzzy, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "αδύνατη η σύνδεση στο %s:%hu: %s\n"

#: src/ftp.c:708
#, c-format
msgid "Bind error (%s).\n"
msgstr "Σφάλμα στη σύνδεση (%s).\n"

#: src/ftp.c:714
msgid "Invalid PORT.\n"
msgstr "Μη έγκυρη ΘΥΡΑ.\n"

#: src/ftp.c:760
msgid ""
"\n"
"REST failed, starting from scratch.\n"
