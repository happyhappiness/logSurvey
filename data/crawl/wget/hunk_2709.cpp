 # Greek messages for GNU wget.
-# Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
-# Simos Xenitellis <simos@hellug.gr>, 1999, 2000, 2001, 2002.
+# Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
+# Simos Xenitellis <simos@hellug.gr>, 1999, 2000, 2001, 2002, 2003, 2004.
 #
 msgid ""
 msgstr ""
-"Project-Id-Version: wget 1.8.1\n"
+"Project-Id-Version: wget 1.9.1\n"
 "Report-Msgid-Bugs-To: \n"
-"POT-Creation-Date: 2005-06-06 09:11-0400\n"
-"PO-Revision-Date: 2002-03-05 17:50+0000\n"
-"Last-Translator: Simos Xenitellis <simos@hellug.gr>\n"
+"POT-Creation-Date: 2003-10-11 16:21+0200\n"
+"PO-Revision-Date: 2004-12-15 19:46+0000\n"
+"Last-Translator: Simos Xenitellis <simos74@gmx.net>\n"
 "Language-Team: Greek <nls@tux.hellug.gr>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=ISO-8859-7\n"
+"Content-Type: text/plain; charset=utf-8\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
-#: src/connect.c:199
+#: src/connect.c:88
 #, c-format
-msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
+msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
 msgstr ""
 
-#: src/connect.c:271
-#, fuzzy, c-format
-msgid "Connecting to %s|%s|:%d... "
-msgstr "Σύνδεση με %s[%s]:%hu... "
+#: src/connect.c:165
+#, c-format
+msgid "Connecting to %s[%s]:%hu... "
+msgstr "Ξ£ΟΞ½Ξ΄ΞµΟƒΞ· ΞΌΞµ %s[%s]:%hu... "
 
-#: src/connect.c:274
-#, fuzzy, c-format
-msgid "Connecting to %s:%d... "
-msgstr "Σύνδεση με %s:%hu... "
+#: src/connect.c:168
+#, c-format
+msgid "Connecting to %s:%hu... "
+msgstr "Ξ£ΟΞ½Ξ΄ΞµΟƒΞ· ΞΌΞµ %s:%hu... "
 
-#: src/connect.c:335
+#: src/connect.c:222
 msgid "connected.\n"
-msgstr "συνδέθηκε.\n"
+msgstr "ΟƒΟ…Ξ½Ξ΄Ξ­ΞΈΞ·ΞΊΞµ.\n"
 
-#: src/convert.c:176
-#, fuzzy, c-format
-msgid "Converted %d files in %.*f seconds.\n"
-msgstr "Μετατράπηκαν %d αρχεία σε %.2f δευτερόλεπτα.\n"
+#: src/convert.c:171
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "ΞΞµΟ„Ξ±Ο„ΟΞ¬Ο€Ξ·ΞΊΞ±Ξ½ %d Ξ±ΟΟ‡ΞµΞ―Ξ± ΟƒΞµ %.2f Ξ΄ΞµΟ…Ο„ΞµΟΟΞ»ΞµΟ€Ο„Ξ±.\n"
 
-#: src/convert.c:202
+#: src/convert.c:197
 #, c-format
 msgid "Converting %s... "
-msgstr "Μετατροπή του %s... "
+msgstr "ΞΞµΟ„Ξ±Ο„ΟΞΏΟ€Ξ® Ο„ΞΏΟ… %s... "
 
-#: src/convert.c:215
+#: src/convert.c:210
 msgid "nothing to do.\n"
-msgstr "τίποτα να κάνω.\n"
+msgstr "Ο„Ξ―Ο€ΞΏΟ„Ξ± Ξ½Ξ± ΞΊΞ¬Ξ½Ο‰.\n"
 
-#: src/convert.c:223 src/convert.c:247
+#: src/convert.c:218 src/convert.c:242
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "Αδυναμία μετατροπής συνδέσμων στο %s: %s\n"
+msgstr "Ξ‘Ξ΄Ο…Ξ½Ξ±ΞΌΞ―Ξ± ΞΌΞµΟ„Ξ±Ο„ΟΞΏΟ€Ξ®Ο‚ ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΟ‰Ξ½ ΟƒΟ„ΞΏ %s: %s\n"
 
-#: src/convert.c:238
+#: src/convert.c:233
 #, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "Αποτυχία διαγραφής του `%s': %s\n"
+msgstr "Ξ‘Ο€ΞΏΟ„Ο…Ο‡Ξ―Ξ± Ξ΄ΞΉΞ±Ξ³ΟΞ±Ο†Ξ®Ο‚ Ο„ΞΏΟ… `%s': %s\n"
 
-#: src/convert.c:447
+#: src/convert.c:439
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Αδύνατη η λήψη αντιγράγου ασφαλείας του %s ως %s: %s\n"
+msgstr "Ξ‘Ξ΄ΟΞ½Ξ±Ο„Ξ· Ξ· Ξ»Ξ®ΟΞ· Ξ±Ξ½Ο„ΞΉΞ³ΟΞ¬Ξ³ΞΏΟ… Ξ±ΟƒΟ†Ξ±Ξ»ΞµΞ―Ξ±Ο‚ Ο„ΞΏΟ… %s Ο‰Ο‚ %s: %s\n"
 
-#: src/cookies.c:619
+#: src/cookies.c:606
 #, c-format
 msgid "Error in Set-Cookie, field `%s'"
-msgstr "Σφάλμα στο Set-Cookie, πεδίο `%s'"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„ΞΏ Set-Cookie, Ο€ΞµΞ΄Ξ―ΞΏ `%s'"
 
-#: src/cookies.c:643
+#: src/cookies.c:629
 #, fuzzy, c-format
 msgid "Syntax error in Set-Cookie: %s at position %d.\n"
-msgstr "Συντακτικό σφάλμα στο Set-Cookie: πρόωρο τέλος αλφαριθμητικού.\n"
+msgstr "Ξ£Ο…Ξ½Ο„Ξ±ΞΊΟ„ΞΉΞΊΟ ΟƒΟ†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„ΞΏ Set-Cookie: Ο€ΟΟΟ‰ΟΞΏ Ο„Ξ­Ξ»ΞΏΟ‚ Ξ±Ξ»Ο†Ξ±ΟΞΉΞΈΞΌΞ·Ο„ΞΉΞΊΞΏΟ.\n"
 
-#: src/cookies.c:1469
+#: src/cookies.c:1426
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
-msgstr "Αδύνατο το άνοιγμα του αρχείου cookies `%s': %s\n"
+msgstr "Ξ‘Ξ΄ΟΞ½Ξ±Ο„ΞΏ Ο„ΞΏ Ξ¬Ξ½ΞΏΞΉΞ³ΞΌΞ± Ο„ΞΏΟ… Ξ±ΟΟ‡ΞµΞ―ΞΏΟ… cookies `%s': %s\n"
 
-#: src/cookies.c:1481
+#: src/cookies.c:1438
 #, c-format
 msgid "Error writing to `%s': %s\n"
-msgstr "Σφάλμα στην εγγραφή στο `%s': %s\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„Ξ·Ξ½ ΞµΞ³Ξ³ΟΞ±Ο†Ξ® ΟƒΟ„ΞΏ `%s': %s\n"
 
-#: src/cookies.c:1484
+#: src/cookies.c:1442
 #, c-format
 msgid "Error closing `%s': %s\n"
-msgstr "Σφάλμα στο κλείσιμο του `%s': %s\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„ΞΏ ΞΊΞ»ΞµΞ―ΟƒΞΉΞΌΞΏ Ο„ΞΏΟ… `%s': %s\n"
 
-#: src/ftp-ls.c:841
+#: src/ftp-ls.c:812
 msgid "Unsupported listing type, trying Unix listing parser.\n"
-msgstr ""
-"Μη υποστηριζόμενος τύπος καταλόγου, δοκιμάζω να τον διαβάσω σαν Unix "
-"κατάλογο.\n"
+msgstr "ΞΞ· Ο…Ο€ΞΏΟƒΟ„Ξ·ΟΞΉΞ¶ΟΞΌΞµΞ½ΞΏΟ‚ Ο„ΟΟ€ΞΏΟ‚ ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³ΞΏΟ…, Ξ΄ΞΏΞΊΞΉΞΌΞ¬Ξ¶Ο‰ Ξ½Ξ± Ο„ΞΏΞ½ Ξ΄ΞΉΞ±Ξ²Ξ¬ΟƒΟ‰ ΟƒΞ±Ξ½ Unix ΞΊΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏ.\n"
 
-#: src/ftp-ls.c:887 src/ftp-ls.c:889
+#: src/ftp-ls.c:857 src/ftp-ls.c:859
 #, c-format
 msgid "Index of /%s on %s:%d"
-msgstr "Κατάλογος του /%s στο %s:%d"
+msgstr "ΞΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏΟ‚ Ο„ΞΏΟ… /%s ΟƒΟ„ΞΏ %s:%d"
 
-#: src/ftp-ls.c:912
-#, c-format
+#: src/ftp-ls.c:882
 msgid "time unknown       "
-msgstr "ώρα άγνωστη        "
+msgstr "ΟΟΞ± Ξ¬Ξ³Ξ½Ο‰ΟƒΟ„Ξ·        "
 
-#: src/ftp-ls.c:916
-#, c-format
+#: src/ftp-ls.c:886
 msgid "File        "
-msgstr "Αρχείο      "
+msgstr "Ξ‘ΟΟ‡ΞµΞ―ΞΏ      "
 
-#: src/ftp-ls.c:919
-#, c-format
+#: src/ftp-ls.c:889
 msgid "Directory   "
-msgstr "Κατάλογος   "
+msgstr "ΞΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏΟ‚   "
 
-#: src/ftp-ls.c:922
-#, c-format
+#: src/ftp-ls.c:892
 msgid "Link        "
-msgstr "Σύνδεση     "
+msgstr "Ξ£ΟΞ½Ξ΄ΞµΟƒΞ·     "
 
-#: src/ftp-ls.c:925
-#, c-format
+#: src/ftp-ls.c:895
 msgid "Not sure    "
-msgstr "Όχι απόλυτα σίγουρος   "
+msgstr "ΞΟ‡ΞΉ Ξ±Ο€ΟΞ»Ο…Ο„Ξ± ΟƒΞ―Ξ³ΞΏΟ…ΟΞΏΟ‚   "
 
-#: src/ftp-ls.c:943
+#: src/ftp-ls.c:913
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s byte)"
 
-#: src/ftp.c:226
-#, c-format
-msgid "Length: %s"
-msgstr "Μήκος: %s"
-
-#: src/ftp.c:232 src/http.c:1857
-#, c-format
-msgid ", %s (%s) remaining"
-msgstr ""
-
-#: src/ftp.c:236 src/http.c:1861
-#, c-format
-msgid ", %s remaining"
-msgstr ""
-
-#: src/ftp.c:239
-msgid " (unauthoritative)\n"
-msgstr " (ανεπίσημο)\n"
-
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:314
+#: src/ftp.c:202
 #, c-format
 msgid "Logging in as %s ... "
-msgstr "Αυθεντικοποίηση ως %s ... "
+msgstr "Ξ‘Ο…ΞΈΞµΞ½Ο„ΞΉΞΊΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ· Ο‰Ο‚ %s ... "
 
-#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
-#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
-#: src/ftp.c:866
+#: src/ftp.c:215 src/ftp.c:268 src/ftp.c:299 src/ftp.c:353 src/ftp.c:468
+#: src/ftp.c:519 src/ftp.c:551 src/ftp.c:611 src/ftp.c:675 src/ftp.c:748
+#: src/ftp.c:796
 msgid "Error in server response, closing control connection.\n"
-msgstr "Σφάλμα στην απάντηση του διακομιστή, κλείνει η σύνδεση ελέγχου.\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„Ξ·Ξ½ Ξ±Ο€Ξ¬Ξ½Ο„Ξ·ΟƒΞ· Ο„ΞΏΟ… Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ®, ΞΊΞ»ΞµΞ―Ξ½ΞµΞΉ Ξ· ΟƒΟΞ½Ξ΄ΞµΟƒΞ· ΞµΞ»Ξ­Ξ³Ο‡ΞΏΟ….\n"
 
-#: src/ftp.c:334
+#: src/ftp.c:223
 msgid "Error in server greeting.\n"
-msgstr "Σφάλμα στο μήνυμα αποδοχής του διακομιστή.\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„ΞΏ ΞΌΞ®Ξ½Ο…ΞΌΞ± Ξ±Ο€ΞΏΞ΄ΞΏΟ‡Ξ®Ο‚ Ο„ΞΏΟ… Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ®.\n"
 
-#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
-#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
+#: src/ftp.c:231 src/ftp.c:362 src/ftp.c:477 src/ftp.c:560 src/ftp.c:621
+#: src/ftp.c:685 src/ftp.c:758 src/ftp.c:806
 msgid "Write failed, closing control connection.\n"
-msgstr "Αποτυχία στην εγγραφή δεδομένων, κλείνει η σύνδεση ελέγχου.\n"
+msgstr "Ξ‘Ο€ΞΏΟ„Ο…Ο‡Ξ―Ξ± ΟƒΟ„Ξ·Ξ½ ΞµΞ³Ξ³ΟΞ±Ο†Ξ® Ξ΄ΞµΞ΄ΞΏΞΌΞ­Ξ½Ο‰Ξ½, ΞΊΞ»ΞµΞ―Ξ½ΞµΞΉ Ξ· ΟƒΟΞ½Ξ΄ΞµΟƒΞ· ΞµΞ»Ξ­Ξ³Ο‡ΞΏΟ….\n"
 
-#: src/ftp.c:347
+#: src/ftp.c:238
 msgid "The server refuses login.\n"
-msgstr "Ο διακομιστής απαγορεύει τη σύνδεση.\n"
+msgstr "Ξ Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ®Ο‚ Ξ±Ο€Ξ±Ξ³ΞΏΟΞµΟΞµΞΉ Ο„Ξ· ΟƒΟΞ½Ξ΄ΞµΟƒΞ·.\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:245
 msgid "Login incorrect.\n"
-msgstr "Σφάλμα στην αυθεντικοποίηση.\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„Ξ·Ξ½ Ξ±Ο…ΞΈΞµΞ½Ο„ΞΉΞΊΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ·.\n"
 
-#: src/ftp.c:359
+#: src/ftp.c:252
 msgid "Logged in!\n"
-msgstr "Επιτυχής σύνδεση!\n"
+msgstr "Ξ•Ο€ΞΉΟ„Ο…Ο‡Ξ®Ο‚ ΟƒΟΞ½Ξ΄ΞµΟƒΞ·!\n"
 
-#: src/ftp.c:381
+#: src/ftp.c:277
 msgid "Server error, can't determine system type.\n"
-msgstr "Σφάλμα διακομιστή, δεν μπορώ να συμπεράνω τον τύπο του συστήματος.\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ®, Ξ΄ΞµΞ½ ΞΌΟ€ΞΏΟΟ Ξ½Ξ± ΟƒΟ…ΞΌΟ€ΞµΟΞ¬Ξ½Ο‰ Ο„ΞΏΞ½ Ο„ΟΟ€ΞΏ Ο„ΞΏΟ… ΟƒΟ…ΟƒΟ„Ξ®ΞΌΞ±Ο„ΞΏΟ‚.\n"
 
-#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
+#: src/ftp.c:287 src/ftp.c:596 src/ftp.c:659 src/ftp.c:716
 msgid "done.    "
-msgstr "έγινε.    "
+msgstr "Ξ­Ξ³ΞΉΞ½Ξµ.    "
 
-#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
+#: src/ftp.c:341 src/ftp.c:498 src/ftp.c:533 src/ftp.c:779 src/ftp.c:827
 msgid "done.\n"
-msgstr "έγινε.\n"
+msgstr "Ξ­Ξ³ΞΉΞ½Ξµ.\n"
 
-#: src/ftp.c:469
+#: src/ftp.c:370
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "¶γνωστος τύπος `%c', διακοπή της σύνδεσης.\n"
+msgstr "Ξ†Ξ³Ξ½Ο‰ΟƒΟ„ΞΏΟ‚ Ο„ΟΟ€ΞΏΟ‚ `%c', Ξ΄ΞΉΞ±ΞΊΞΏΟ€Ξ® Ο„Ξ·Ο‚ ΟƒΟΞ½Ξ΄ΞµΟƒΞ·Ο‚.\n"
 
-#: src/ftp.c:481
+#: src/ftp.c:383
 msgid "done.  "
-msgstr "έγινε.  "
+msgstr "Ξ­Ξ³ΞΉΞ½Ξµ.  "
 
-#: src/ftp.c:487
+#: src/ftp.c:389
 msgid "==> CWD not needed.\n"
-msgstr "==> CWD δεν απαιτήται.\n"
+msgstr "==> CWD Ξ΄ΞµΞ½ Ξ±Ο€Ξ±ΞΉΟ„Ξ®Ο„Ξ±ΞΉ.\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:484
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
-msgstr "Δεν υπάρχει τέτοιος κατάλογος `%s'.\n"
+msgstr "Ξ”ΞµΞ½ Ο…Ο€Ξ¬ΟΟ‡ΞµΞΉ Ο„Ξ­Ο„ΞΏΞΉΞΏΟ‚ ΞΊΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏΟ‚ `%s'.\n"
 
 #. do not CWD
-#: src/ftp.c:595
+#: src/ftp.c:502
 msgid "==> CWD not required.\n"
-msgstr "==> CWD δεν απαιτείται.\n"
+msgstr "==> CWD Ξ΄ΞµΞ½ Ξ±Ο€Ξ±ΞΉΟ„ΞµΞ―Ο„Ξ±ΞΉ.\n"
 
-#: src/ftp.c:654
+#: src/ftp.c:567
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "Δεν είναι δυνατή να ξεκινήσει μεταφορά τύπου PASV.\n"
+msgstr "Ξ”ΞµΞ½ ΞµΞ―Ξ½Ξ±ΞΉ Ξ΄Ο…Ξ½Ξ±Ο„Ξ® Ξ½Ξ± ΞΎΞµΞΊΞΉΞ½Ξ®ΟƒΞµΞΉ ΞΌΞµΟ„Ξ±Ο†ΞΏΟΞ¬ Ο„ΟΟ€ΞΏΟ… PASV.\n"
 
-#: src/ftp.c:658
+#: src/ftp.c:571
 msgid "Cannot parse PASV response.\n"
-msgstr "Δεν είναι δυνατή η μετάφραση της απάντησης PASV.\n"
+msgstr "Ξ”ΞµΞ½ ΞµΞ―Ξ½Ξ±ΞΉ Ξ΄Ο…Ξ½Ξ±Ο„Ξ® Ξ· ΞΌΞµΟ„Ξ¬Ο†ΟΞ±ΟƒΞ· Ο„Ξ·Ο‚ Ξ±Ο€Ξ¬Ξ½Ο„Ξ·ΟƒΞ·Ο‚ PASV.\n"
 
-#: src/ftp.c:676
-#, fuzzy, c-format
-msgid "couldn't connect to %s port %d: %s\n"
-msgstr "αδύνατη η σύνδεση στο %s:%hu: %s\n"
+#: src/ftp.c:588
+#, c-format
+msgid "couldn't connect to %s:%hu: %s\n"
+msgstr "Ξ±Ξ΄ΟΞ½Ξ±Ο„Ξ· Ξ· ΟƒΟΞ½Ξ΄ΞµΟƒΞ· ΟƒΟ„ΞΏ %s:%hu: %s\n"
 
-#: src/ftp.c:724
+#: src/ftp.c:638
 #, c-format
 msgid "Bind error (%s).\n"
-msgstr "Σφάλμα στη σύνδεση (%s).\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„Ξ· ΟƒΟΞ½Ξ΄ΞµΟƒΞ· (%s).\n"
 
-#: src/ftp.c:730
+#: src/ftp.c:645
 msgid "Invalid PORT.\n"
-msgstr "Μη έγκυρη ΘΥΡΑ.\n"
+msgstr "ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞ· ΞΞ¥Ξ΅Ξ‘.\n"
+
+#: src/ftp.c:698
+#, c-format
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
+msgstr ""
+"\n"
+"Ξ‘Ο€ΞΏΟ„Ο…Ο‡Ξ―Ξ± Ο„Ξ·Ο‚ RESTΒ· Ξ΄Ξµ ΞΈΞ± ΞµΟ€Ξ±Ξ½Ξ±ΞΊΟ„Ξ·ΞΈΞµΞ― Ο„ΞΏ `%s'.\n"
 
-#: src/ftp.c:776
+#: src/ftp.c:705
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 "\n"
-"Αποτυχία στην εντολή REST, εκκίνηση από την αρχή.\n"
+"Ξ‘Ο€ΞΏΟ„Ο…Ο‡Ξ―Ξ± ΟƒΟ„Ξ·Ξ½ ΞµΞ½Ο„ΞΏΞ»Ξ® REST, ΞµΞΊΞΊΞ―Ξ½Ξ·ΟƒΞ· Ξ±Ο€Ο Ο„Ξ·Ξ½ Ξ±ΟΟ‡Ξ®.\n"
 
-#: src/ftp.c:837
+#: src/ftp.c:766
 #, c-format
 msgid ""
 "No such file `%s'.\n"
 "\n"
 msgstr ""
-"Δεν υπάρχει αρχείο `%s'.\n"
+"Ξ”ΞµΞ½ Ο…Ο€Ξ¬ΟΟ‡ΞµΞΉ Ξ±ΟΟ‡ΞµΞ―ΞΏ `%s'.\n"
 "\n"
 
-#: src/ftp.c:884
+#: src/ftp.c:814
 #, c-format
 msgid ""
 "No such file or directory `%s'.\n"
 "\n"
 msgstr ""
-"Δεν υπάρχει αρχείο ή κατάλογος `%s'.\n"
+"Ξ”ΞµΞ½ Ο…Ο€Ξ¬ΟΟ‡ΞµΞΉ Ξ±ΟΟ‡ΞµΞ―ΞΏ Ξ® ΞΊΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏΟ‚ `%s'.\n"
 "\n"
 
-#. We cannot just invent a new name and use it (which is
-#. what functions like unique_create typically do)
-#. because we told the user we'd use this name.
-#. Instead, return and retry the download.
-#: src/ftp.c:946 src/http.c:1913
+#: src/ftp.c:898 src/ftp.c:906
 #, c-format
-msgid "%s has sprung into existence.\n"
-msgstr ""
+msgid "Length: %s"
+msgstr "ΞΞ®ΞΊΞΏΟ‚: %s"
+
+#: src/ftp.c:900 src/ftp.c:908
+#, c-format
+msgid " [%s to go]"
+msgstr " [%s Ξ³ΞΉΞ± Ο€Ξ­ΟΞ±Ο‚]"
+
+#: src/ftp.c:910
+msgid " (unauthoritative)\n"
+msgstr " (Ξ±Ξ½ΞµΟ€Ξ―ΟƒΞ·ΞΌΞΏ)\n"
 
-#: src/ftp.c:1008
+#: src/ftp.c:936
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, κλείσιμο σύνδεσης ελέγχου.\n"
+msgstr "%s: %s, ΞΊΞ»ΞµΞ―ΟƒΞΉΞΌΞΏ ΟƒΟΞ½Ξ΄ΞµΟƒΞ·Ο‚ ΞµΞ»Ξ­Ξ³Ο‡ΞΏΟ….\n"
 
-#: src/ftp.c:1016
+#: src/ftp.c:944
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
-msgstr "%s (%s) - Σύνδεση δεδομένων: %s; "
+msgstr "%s (%s) - Ξ£ΟΞ½Ξ΄ΞµΟƒΞ· Ξ΄ΞµΞ΄ΞΏΞΌΞ­Ξ½Ο‰Ξ½: %s; "
 
-#: src/ftp.c:1031
+#: src/ftp.c:961
 msgid "Control connection closed.\n"
-msgstr "Η σύνδεση ελέγχου έκλεισε.\n"
+msgstr "Ξ— ΟƒΟΞ½Ξ΄ΞµΟƒΞ· ΞµΞ»Ξ­Ξ³Ο‡ΞΏΟ… Ξ­ΞΊΞ»ΞµΞΉΟƒΞµ.\n"
 
-#: src/ftp.c:1049
+#: src/ftp.c:979
 msgid "Data transfer aborted.\n"
-msgstr "Η μεταφορά δεδομένων διακόπηκε ανώμαλα.\n"
+msgstr "Ξ— ΞΌΞµΟ„Ξ±Ο†ΞΏΟΞ¬ Ξ΄ΞµΞ΄ΞΏΞΌΞ­Ξ½Ο‰Ξ½ Ξ΄ΞΉΞ±ΞΊΟΟ€Ξ·ΞΊΞµ Ξ±Ξ½ΟΞΌΞ±Ξ»Ξ±.\n"
 
-#: src/ftp.c:1114
+#: src/ftp.c:1044
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr "Το αρχείο `%s' υπάρχει ήδη, δεν επανακτάται.\n"
+msgstr "Ξ¤ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ `%s' Ο…Ο€Ξ¬ΟΟ‡ΞµΞΉ Ξ®Ξ΄Ξ·, Ξ΄ΞµΞ½ ΞµΟ€Ξ±Ξ½Ξ±ΞΊΟ„Ξ¬Ο„Ξ±ΞΉ.\n"
 
-#: src/ftp.c:1182 src/http.c:2130
+#: src/ftp.c:1114 src/http.c:1716
 #, c-format
 msgid "(try:%2d)"
-msgstr "(προσπάθεια:%2d)"
+msgstr "(Ο€ΟΞΏΟƒΟ€Ξ¬ΞΈΞµΞΉΞ±:%2d)"
 
-#: src/ftp.c:1252 src/http.c:2409
-#, fuzzy, c-format
+#: src/ftp.c:1180 src/http.c:1975
+#, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s]\n"
+"%s (%s) - `%s' saved [%ld]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' αποθηκεύτηκε [%ld]\n"
+"%s (%s) - `%s' Ξ±Ο€ΞΏΞΈΞ·ΞΊΞµΟΟ„Ξ·ΞΊΞµ [%ld]\n"
 "\n"
 
-#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
+#: src/ftp.c:1222 src/main.c:890 src/recur.c:377 src/retr.c:596
 #, c-format
 msgid "Removing %s.\n"
-msgstr "Διαγραφή του %s.\n"
+msgstr "Ξ”ΞΉΞ±Ξ³ΟΞ±Ο†Ξ® Ο„ΞΏΟ… %s.\n"
 
-#: src/ftp.c:1336
+#: src/ftp.c:1264
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "Χρήση του `%s' για προσωρινό αρχείο περιεχομένων καταλόγου.\n"
+msgstr "Ξ§ΟΞ®ΟƒΞ· Ο„ΞΏΟ… `%s' Ξ³ΞΉΞ± Ο€ΟΞΏΟƒΟ‰ΟΞΉΞ½Ο Ξ±ΟΟ‡ΞµΞ―ΞΏ Ο€ΞµΟΞΉΞµΟ‡ΞΏΞΌΞ­Ξ½Ο‰Ξ½ ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³ΞΏΟ….\n"
 
-#: src/ftp.c:1351
+#: src/ftp.c:1279
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr "Διαγραφή του `%s'.\n"
+msgstr "Ξ”ΞΉΞ±Ξ³ΟΞ±Ο†Ξ® Ο„ΞΏΟ… `%s'.\n"
 
-#: src/ftp.c:1386
+#: src/ftp.c:1314
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr "Το επίπεδο αναδρομής %d ξεπέρασε το μέγιστο επίπεδο αναδρομής %d.\n"
+msgstr "Ξ¤ΞΏ ΞµΟ€Ξ―Ο€ΞµΞ΄ΞΏ Ξ±Ξ½Ξ±Ξ΄ΟΞΏΞΌΞ®Ο‚ %d ΞΎΞµΟ€Ξ­ΟΞ±ΟƒΞµ Ο„ΞΏ ΞΌΞ­Ξ³ΞΉΟƒΟ„ΞΏ ΞµΟ€Ξ―Ο€ΞµΞ΄ΞΏ Ξ±Ξ½Ξ±Ξ΄ΟΞΏΞΌΞ®Ο‚ %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1456
+#: src/ftp.c:1384
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
 msgstr ""
-"Το αρχείο στο διακομιστή δεν είναι νεώτερο του τοπικού `%s' -- δε γίνεται "
-"ανάκτηση.\n"
+"Ξ¤ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ ΟƒΟ„ΞΏ Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ® Ξ΄ΞµΞ½ ΞµΞ―Ξ½Ξ±ΞΉ Ξ½ΞµΟΟ„ΞµΟΞΏ Ο„ΞΏΟ… Ο„ΞΏΟ€ΞΉΞΊΞΏΟ `%s' -- Ξ΄Ξµ Ξ³Ξ―Ξ½ΞµΟ„Ξ±ΞΉ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·.\n"
 "\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1463
+#: src/ftp.c:1391
 #, c-format
 msgid ""
 "Remote file is newer than local file `%s' -- retrieving.\n"
 "\n"
 msgstr ""
-"Το αρχείο στο διακομιστή είναι νεώτερο του τοπικού `%s' -- γίνεται "
-"ανάκτηση.\n"
+"Ξ¤ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ ΟƒΟ„ΞΏ Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ® ΞµΞ―Ξ½Ξ±ΞΉ Ξ½ΞµΟΟ„ΞµΟΞΏ Ο„ΞΏΟ… Ο„ΞΏΟ€ΞΉΞΊΞΏΟ `%s' -- Ξ³Ξ―Ξ½ΞµΟ„Ξ±ΞΉ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·.\n"
 "\n"
 
 #. Sizes do not match
-#: src/ftp.c:1470
-#, fuzzy, c-format
+#: src/ftp.c:1398
+#, c-format
 msgid ""
-"The sizes do not match (local %s) -- retrieving.\n"
+"The sizes do not match (local %ld) -- retrieving.\n"
 "\n"
-msgstr "Τα μεγέθη δεν είναι ίσα (τοπικό %ld) -- γίνεται ανάκτηση.\n"
+msgstr "Ξ¤Ξ± ΞΌΞµΞ³Ξ­ΞΈΞ· Ξ΄ΞµΞ½ ΞµΞ―Ξ½Ξ±ΞΉ Ξ―ΟƒΞ± (Ο„ΞΏΟ€ΞΉΞΊΟ %ld) -- Ξ³Ξ―Ξ½ΞµΟ„Ξ±ΞΉ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·.\n"
 
-#: src/ftp.c:1488
+#: src/ftp.c:1415
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "Μη έγκυρο όνομα συμβολικού συνδέσμου, παρακάμπτεται.\n"
+msgstr "ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞΏ ΟΞ½ΞΏΞΌΞ± ΟƒΟ…ΞΌΞ²ΞΏΞ»ΞΉΞΊΞΏΟ ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΞΏΟ…, Ο€Ξ±ΟΞ±ΞΊΞ¬ΞΌΟ€Ο„ΞµΟ„Ξ±ΞΉ.\n"
 
-#: src/ftp.c:1505
+#: src/ftp.c:1432
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr ""
-"Υπάρχει ήδη ο ορθός σύνδεσμος %s -> %s\n"
+"Ξ¥Ο€Ξ¬ΟΟ‡ΞµΞΉ Ξ®Ξ΄Ξ· ΞΏ ΞΏΟΞΈΟΟ‚ ΟƒΟΞ½Ξ΄ΞµΟƒΞΌΞΏΟ‚ %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1513
+#: src/ftp.c:1440
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "Δημιουργία συνδέσμου %s -> %s\n"
+msgstr "Ξ”Ξ·ΞΌΞΉΞΏΟ…ΟΞ³Ξ―Ξ± ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΞΏΟ… %s -> %s\n"
 
-#: src/ftp.c:1523
+#: src/ftp.c:1451
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Δεν υποστηρίζονται σύνδεσμοι, παράκαμψη συνδέσμου `%s'.\n"
+msgstr "Ξ”ΞµΞ½ Ο…Ο€ΞΏΟƒΟ„Ξ·ΟΞ―Ξ¶ΞΏΞ½Ο„Ξ±ΞΉ ΟƒΟΞ½Ξ΄ΞµΟƒΞΌΞΏΞΉ, Ο€Ξ±ΟΞ¬ΞΊΞ±ΞΌΟΞ· ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΞΏΟ… `%s'.\n"
 
-#: src/ftp.c:1535
+#: src/ftp.c:1463
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "Παράκαμψη καταλόγου `%s'.\n"
+msgstr "Ξ Ξ±ΟΞ¬ΞΊΞ±ΞΌΟΞ· ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³ΞΏΟ… `%s'.\n"
 
-#: src/ftp.c:1544
+#: src/ftp.c:1472
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: άγνωστο/μη υποστηριζόμενο είδος αρχείου.\n"
+msgstr "%s: Ξ¬Ξ³Ξ½Ο‰ΟƒΟ„ΞΏ/ΞΌΞ· Ο…Ο€ΞΏΟƒΟ„Ξ·ΟΞΉΞ¶ΟΞΌΞµΞ½ΞΏ ΞµΞ―Ξ΄ΞΏΟ‚ Ξ±ΟΟ‡ΞµΞ―ΞΏΟ….\n"
 
-#: src/ftp.c:1571
+#: src/ftp.c:1499
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: εσφαλμένη ημερομηνία αρχείου.\n"
+msgstr "%s: ΞµΟƒΟ†Ξ±Ξ»ΞΌΞ­Ξ½Ξ· Ξ·ΞΌΞµΟΞΏΞΌΞ·Ξ½Ξ―Ξ± Ξ±ΟΟ‡ΞµΞ―ΞΏΟ….\n"
 
-#: src/ftp.c:1599
+#: src/ftp.c:1524
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr "Δεν θα ανακτηθούν κατάλογοι διότι το βάθος είναι %d (μέγιστο %d).\n"
+msgstr "Ξ”ΞµΞ½ ΞΈΞ± Ξ±Ξ½Ξ±ΞΊΟ„Ξ·ΞΈΞΏΟΞ½ ΞΊΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏΞΉ Ξ΄ΞΉΟΟ„ΞΉ Ο„ΞΏ Ξ²Ξ¬ΞΈΞΏΟ‚ ΞµΞ―Ξ½Ξ±ΞΉ %d (ΞΌΞ­Ξ³ΞΉΟƒΟ„ΞΏ %d).\n"
 
-#: src/ftp.c:1649
+#: src/ftp.c:1574
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr ""
-"Δεν επεκτεινόμαστε στο `%s' διότι είναι εξαιρούμενο/μη-συμπεριλαμβανόμενο\n"
+msgstr "Ξ”ΞµΞ½ ΞµΟ€ΞµΞΊΟ„ΞµΞΉΞ½ΟΞΌΞ±ΟƒΟ„Ξµ ΟƒΟ„ΞΏ `%s' Ξ΄ΞΉΟΟ„ΞΉ ΞµΞ―Ξ½Ξ±ΞΉ ΞµΞΎΞ±ΞΉΟΞΏΟΞΌΞµΞ½ΞΏ/ΞΌΞ·-ΟƒΟ…ΞΌΟ€ΞµΟΞΉΞ»Ξ±ΞΌΞ²Ξ±Ξ½ΟΞΌΞµΞ½ΞΏ\n"
 
-#: src/ftp.c:1715 src/ftp.c:1729
+#: src/ftp.c:1639 src/ftp.c:1652
 #, c-format
 msgid "Rejecting `%s'.\n"
-msgstr "Απόρριψη του `%s'.\n"
+msgstr "Ξ‘Ο€ΟΟΟΞΉΟΞ· Ο„ΞΏΟ… `%s'.\n"
 
 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1775
+#: src/ftp.c:1698
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "Δεν βρέθηκαν ταιριάσματα στη μορφή `%s'.\n"
+msgstr "Ξ”ΞµΞ½ Ξ²ΟΞ­ΞΈΞ·ΞΊΞ±Ξ½ Ο„Ξ±ΞΉΟΞΉΞ¬ΟƒΞΌΞ±Ο„Ξ± ΟƒΟ„Ξ· ΞΌΞΏΟΟ†Ξ® `%s'.\n"
 
-#: src/ftp.c:1841
-#, fuzzy, c-format
-msgid "Wrote HTML-ized index to `%s' [%s].\n"
-msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s' [%ld].\n"
+#: src/ftp.c:1764
+#, c-format
+msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+msgstr "Ξ“ΟΞ¬Ο†Ο„Ξ·ΞΊΞµ Ξ±ΟΟ‡ΞµΞ―ΞΏ ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³ΞΏΟ… ΟƒΞµ HTML ΟƒΟ„ΞΏ `%s' [%ld].\n"
 
-#: src/ftp.c:1846
+#: src/ftp.c:1769
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s'.\n"
+msgstr "Ξ“ΟΞ¬Ο†Ο„Ξ·ΞΊΞµ Ξ±ΟΟ‡ΞµΞ―ΞΏ ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³ΞΏΟ… ΟƒΞµ HTML ΟƒΟ„ΞΏ `%s'.\n"
+
+#: src/gen_sslfunc.c:117
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr "Ξ‘Ξ΄ΟΞ½Ξ±Ο„Ξ· Ξ· Ξ±ΟΟ‡ΞΉΞΊΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ· Ο„Ξ·Ο‚ PRNG Ο„Ξ·Ο‚ OpenSSLΒ· Ξ±Ο€ΞµΞ½ΞµΟΞ³ΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ· Ο„ΞΏΟ… SSL.\n"
 
 #: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: η επιλογή `%s' είναι αόριστη\n"
+msgstr "%s: Ξ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® `%s' ΞµΞ―Ξ½Ξ±ΞΉ Ξ±ΟΟΞΉΟƒΟ„Ξ·\n"
 
 #: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: η επιλογή `--%s' δεν επιδέχεται όρισμα\n"
+msgstr "%s: Ξ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® `--%s' Ξ΄ΞµΞ½ ΞµΟ€ΞΉΞ΄Ξ­Ο‡ΞµΟ„Ξ±ΞΉ ΟΟΞΉΟƒΞΌΞ±\n"
 
 #: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: η επιλογή `%c%s' δεν επιδέχεται όρισμα\n"
+msgstr "%s: Ξ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® `%c%s' Ξ΄ΞµΞ½ ΞµΟ€ΞΉΞ΄Ξ­Ο‡ΞµΟ„Ξ±ΞΉ ΟΟΞΉΟƒΞΌΞ±\n"
 
 #: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: η επιλογή `%s' απαιτεί όρισμα\n"
+msgstr "%s: Ξ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® `%s' Ξ±Ο€Ξ±ΞΉΟ„ΞµΞ― ΟΟΞΉΟƒΞΌΞ±\n"
 
 #. --option
 #: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
-msgstr "%s: μη αναγνωρίσημη επιλογή `--%s'\n"
+msgstr "%s: ΞΌΞ· Ξ±Ξ½Ξ±Ξ³Ξ½Ο‰ΟΞ―ΟƒΞ·ΞΌΞ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® `--%s'\n"
 
 #. +option or -option
 #: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
-msgstr "%s: μη αναγνωρίσιμη επιλογή `%c%s'\n"
+msgstr "%s: ΞΌΞ· Ξ±Ξ½Ξ±Ξ³Ξ½Ο‰ΟΞ―ΟƒΞΉΞΌΞ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: μη αποδεκτή επιλογή -- %c\n"
+msgstr "%s: ΞΌΞ· Ξ±Ο€ΞΏΞ΄ΞµΞΊΟ„Ξ® ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® -- %c\n"
 
 #: src/getopt.c:785
 #, fuzzy, c-format
 msgid "%s: invalid option -- %c\n"
-msgstr "%s: μη αποδεκτή επιλογή -- %c\n"
+msgstr "%s: ΞΌΞ· Ξ±Ο€ΞΏΞ΄ΞµΞΊΟ„Ξ® ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® -- %c\n"
 
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: η επιλογή απαιτεί μια παράμετρο -- %c\n"
+msgstr "%s: Ξ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® Ξ±Ο€Ξ±ΞΉΟ„ΞµΞ― ΞΌΞΉΞ± Ο€Ξ±ΟΞ¬ΞΌΞµΟ„ΟΞΏ -- %c\n"
 
 #: src/getopt.c:862
 #, fuzzy, c-format
 msgid "%s: option `-W %s' is ambiguous\n"
-msgstr "%s: η επιλογή `%s' είναι αόριστη\n"
+msgstr "%s: Ξ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® `%s' ΞµΞ―Ξ½Ξ±ΞΉ Ξ±ΟΟΞΉΟƒΟ„Ξ·\n"
 
 #: src/getopt.c:880
 #, fuzzy, c-format
 msgid "%s: option `-W %s' doesn't allow an argument\n"
-msgstr "%s: η επιλογή `--%s' δεν επιδέχεται όρισμα\n"
-
-#: src/host.c:371
-#, fuzzy
-msgid "Unknown host"
-msgstr "¶γνωστο σφάλμα"
-
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
-#: src/host.c:375
-msgid "Temporary failure in name resolution"
-msgstr ""
-
-#: src/host.c:377
-msgid "Unknown error"
-msgstr "¶γνωστο σφάλμα"
+msgstr "%s: Ξ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® `--%s' Ξ΄ΞµΞ½ ΞµΟ€ΞΉΞ΄Ξ­Ο‡ΞµΟ„Ξ±ΞΉ ΟΟΞΉΟƒΞΌΞ±\n"
 
-#: src/host.c:756
+#: src/host.c:636
 #, c-format
 msgid "Resolving %s... "
-msgstr "Εύρεση του %s... "
+msgstr "Ξ•ΟΟΞµΟƒΞ· Ο„ΞΏΟ… %s... "
 
-#: src/host.c:800 src/host.c:829
+#: src/host.c:656 src/host.c:672
 #, c-format
 msgid "failed: %s.\n"
-msgstr "απέτυχε: %s.\n"
-
-#: src/host.c:809
-msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
+msgstr "Ξ±Ο€Ξ­Ο„Ο…Ο‡Ξµ: %s.\n"
 
-#: src/host.c:832
+#: src/host.c:674
 #, fuzzy
 msgid "failed: timed out.\n"
-msgstr "απέτυχε: %s.\n"
+msgstr "Ξ±Ο€Ξ­Ο„Ο…Ο‡Ξµ: %s.\n"
+
+#: src/host.c:762
+msgid "Host not found"
+msgstr "Ξ Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ®Ο‚ Ξ΄Ξµ Ξ²ΟΞ­ΞΈΞ·ΞΊΞµ"
 
-#: src/html-url.c:298
+#: src/host.c:764
+msgid "Unknown error"
+msgstr "Ξ†Ξ³Ξ½Ο‰ΟƒΟ„ΞΏ ΟƒΟ†Ξ¬Ξ»ΞΌΞ±"
+
+#: src/html-url.c:293
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
-msgstr "%s: Αδύνατη η ανάλυση μη ολοκληρωμένου συνδέσμου %s.\n"
+msgstr "%s: Ξ‘Ξ΄ΟΞ½Ξ±Ο„Ξ· Ξ· Ξ±Ξ½Ξ¬Ξ»Ο…ΟƒΞ· ΞΌΞ· ΞΏΞ»ΞΏΞΊΞ»Ξ·ΟΟ‰ΞΌΞ­Ξ½ΞΏΟ… ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΞΏΟ… %s.\n"
 
-#: src/http.c:373 src/http.c:1549
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
-msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"
+#. this is fatal
+#: src/http.c:674
+msgid "Failed to set up an SSL context\n"
+msgstr "Ξ‘Ο€ΞΏΟ„Ο…Ο‡Ξ―Ξ± Ξ΄Ξ·ΞΌΞΉΞΏΟ…ΟΞ³Ξ―Ξ±Ο‚ Ο€ΞµΟΞΉΞ²Ξ¬Ξ»Ξ»ΞΏΞ½Ο„ΞΏΟ‚ SSL\n"
 
-#: src/http.c:687
-msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+#: src/http.c:680
+#, c-format
+msgid "Failed to load certificates from %s\n"
+msgstr "Ξ‘Ο€ΞΏΟ„Ο…Ο‡Ξ―Ξ± Ο†ΟΟΟ„Ο‰ΟƒΞ·Ο‚ Ο€ΞΉΟƒΟ„ΞΏΟ€ΞΏΞΉΞ·Ο„ΞΉΞΊΟΞ½ Ξ±Ο€Ο %s\n"
 
-#: src/http.c:1198
-msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+#: src/http.c:684 src/http.c:692
+msgid "Trying without the specified certificate\n"
+msgstr "Ξ ΟΞΏΟƒΟ€Ξ¬ΞΈΞµΞΉΞ± Ο‡Ο‰ΟΞ―Ο‚ Ο„ΞΏ ΞΊΞ±ΞΈΞΏΟΞΉΟƒΞΌΞ­Ξ½ΞΏ Ο€ΞΉΟƒΟ„ΞΏΟ€ΞΏΞΉΞ·Ο„ΞΉΞΊΟ\n"
 
-#: src/http.c:1417
-#, fuzzy, c-format
-msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Χρήση ξανά της σύνδεσης στο %s:%hu.\n"
+#: src/http.c:688
+#, c-format
+msgid "Failed to get certificate key from %s\n"
+msgstr "Ξ‘Ο€ΞΏΟ„Ο…Ο‡Ξ―Ξ± Ξ»Ξ®ΟΞ·Ο‚ ΞΊΞ»ΞµΞΉΞ΄ΞΉΞΏΟ Ο€ΞΉΟƒΟ„ΞΏΟ€ΞΏΞΉΞ·Ο„ΞΉΞΊΞΏΟ Ξ±Ο€Ο %s\n"
 
-#: src/http.c:1479
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"
+#: src/http.c:761 src/http.c:1809
+msgid "Unable to establish SSL connection.\n"
+msgstr "Ξ‘Ξ΄ΟΞ½Ξ±Ο„Ξ· Ξ· ΟƒΟΟƒΟ„Ξ±ΟƒΞ· ΟƒΟΞ½Ξ΄ΞµΟƒΞ·Ο‚ SSL.\n"
 
-#: src/http.c:1488
-#, fuzzy, c-format
-msgid "Failed reading proxy response: %s\n"
-msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"
+#: src/http.c:770
+#, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Ξ§ΟΞ®ΟƒΞ· ΞΎΞ±Ξ½Ξ¬ Ο„Ξ·Ο‚ ΟƒΟΞ½Ξ΄ΞµΟƒΞ·Ο‚ ΟƒΟ„ΞΏ %s:%hu.\n"
 
-#: src/http.c:1508
+#: src/http.c:1034
 #, c-format
-msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„Ξ·Ξ½ ΞµΞ³Ξ³ΟΞ±Ο†Ξ® Ο„Ξ·Ο‚ Ξ±Ξ―Ο„Ξ·ΟƒΞ·Ο‚ HTTP: %s.\n"
 
-#: src/http.c:1555
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "Η αίτηση για %s στάλθηκε, αναμονή απάντησης... "
+msgstr "Ξ— Ξ±Ξ―Ο„Ξ·ΟƒΞ· Ξ³ΞΉΞ± %s ΟƒΟ„Ξ¬Ξ»ΞΈΞ·ΞΊΞµ, Ξ±Ξ½Ξ±ΞΌΞΏΞ½Ξ® Ξ±Ο€Ξ¬Ξ½Ο„Ξ·ΟƒΞ·Ο‚... "
 
-#: src/http.c:1566
-#, fuzzy
-msgid "No data received.\n"
-msgstr "Δεν ελήφθησαν δεδομένα"
+#: src/http.c:1083
+msgid "End of file while parsing headers.\n"
+msgstr "Ξ¤Ξ­Ξ»ΞΏΟ‚ Ξ±ΟΟ‡ΞµΞ―ΞΏΟ… ΞµΞ½Ο Ξ³ΞΉΞ½ΟΟ„Ξ±Ξ½ ΞµΟ€ΞµΞΎΞµΟΞ³Ξ±ΟƒΞ―Ξ± Ο„Ο‰Ξ½ ΞΊΞµΟ†Ξ±Ξ»Ξ―Ξ΄Ο‰Ξ½.\n"
 
-#: src/http.c:1573
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
-msgstr "Σφάλμα ανάγνωσης (%s) στις κεφαλίδες.\n"
+msgstr "Ξ£Ο†Ξ¬Ξ»ΞΌΞ± Ξ±Ξ½Ξ¬Ξ³Ξ½Ο‰ΟƒΞ·Ο‚ (%s) ΟƒΟ„ΞΉΟ‚ ΞΊΞµΟ†Ξ±Ξ»Ξ―Ξ΄ΞµΟ‚.\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
-msgid "Unknown authentication scheme.\n"
-msgstr "¶γνωστο σχήμα αυθεντικοποίησης.\n"
-
-#: src/http.c:1682
-msgid "Authorization failed.\n"
-msgstr "Η αυθεντικοποίηση απέτυχε.\n"
+#: src/http.c:1128
+msgid "No data received"
+msgstr "Ξ”ΞµΞ½ ΞµΞ»Ξ®Ο†ΞΈΞ·ΟƒΞ±Ξ½ Ξ΄ΞµΞ΄ΞΏΞΌΞ­Ξ½Ξ±"
 
-#: src/http.c:1696
+#: src/http.c:1130
 msgid "Malformed status line"
-msgstr "Εσφαλμένη γραμμή κατάστασης"
+msgstr "Ξ•ΟƒΟ†Ξ±Ξ»ΞΌΞ­Ξ½Ξ· Ξ³ΟΞ±ΞΌΞΌΞ® ΞΊΞ±Ο„Ξ¬ΟƒΟ„Ξ±ΟƒΞ·Ο‚"
 
-#: src/http.c:1698
+#: src/http.c:1135
 msgid "(no description)"
-msgstr "(χωρίς περιγραφή)"
+msgstr "(Ο‡Ο‰ΟΞ―Ο‚ Ο€ΞµΟΞΉΞ³ΟΞ±Ο†Ξ®)"
+
+#: src/http.c:1267
+msgid "Authorization failed.\n"
+msgstr "Ξ— Ξ±Ο…ΞΈΞµΞ½Ο„ΞΉΞΊΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ· Ξ±Ο€Ξ­Ο„Ο…Ο‡Ξµ.\n"
+
+#: src/http.c:1274
+msgid "Unknown authentication scheme.\n"
+msgstr "Ξ†Ξ³Ξ½Ο‰ΟƒΟ„ΞΏ ΟƒΟ‡Ξ®ΞΌΞ± Ξ±Ο…ΞΈΞµΞ½Ο„ΞΉΞΊΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ·Ο‚.\n"
 
-#: src/http.c:1769
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
-msgstr "Τοποθεσία: %s%s\n"
+msgstr "Ξ¤ΞΏΟ€ΞΏΞΈΞµΟƒΞ―Ξ±: %s%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
-msgstr "μη ορισμένο"
+msgstr "ΞΌΞ· ΞΏΟΞΉΟƒΞΌΞ­Ξ½ΞΏ"
 
-#: src/http.c:1771
+#: src/http.c:1316
 msgid " [following]"
-msgstr " [ακολουθεί]"
+msgstr " [Ξ±ΞΊΞΏΞ»ΞΏΟ…ΞΈΞµΞ―]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1383
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-"    Το αρχείο έχει ήδη ανακτηθεί πλήρως· τίποτα να κάνω.\n"
+"    Ξ¤ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ Ξ­Ο‡ΞµΞΉ Ξ®Ξ΄Ξ· Ξ±Ξ½Ξ±ΞΊΟ„Ξ·ΞΈΞµΞ― Ο€Ξ»Ξ®ΟΟ‰Ο‚Β· Ο„Ξ―Ο€ΞΏΟ„Ξ± Ξ½Ξ± ΞΊΞ¬Ξ½Ο‰.\n"
+
+#: src/http.c:1401
+#, c-format
+msgid ""
+"\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"Ξ— ΟƒΟ…Ξ½Ξ­Ο‡ΞΉΟƒΞ· Ο„Ξ·Ο‚ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚ Ξ±Ο€Ξ­Ο„Ο…Ο‡Ξµ Ξ³ΞΉΞ± Ξ±Ο…Ο„Ο Ο„ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ, Ο€ΞΏΟ… ΟƒΟ…Ξ³ΞΊΟΞΏΟΞµΟ„Ξ±ΞΉ ΞΌΞµ Ο„ΞΏ `-c'.\n"
+"Ξ†ΟΞ½Ξ·ΟƒΞ· ΞµΞ³Ξ³ΟΞ±Ο†Ξ®Ο‚ Ο€Ξ¬Ξ½Ο‰ ΟƒΟ„ΞΏ Ο…Ο€Ξ¬ΟΟ‡ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ `%s'.\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1847
+#: src/http.c:1444
 msgid "Length: "
-msgstr "Μήκος: "
+msgstr "ΞΞ®ΞΊΞΏΟ‚: "
+
+#: src/http.c:1449
+#, c-format
+msgid " (%s to go)"
+msgstr " (%s ΞΌΞ­Ο‡ΟΞΉ Ο€Ξ­ΟΞ±Ο‚)"
 
-#: src/http.c:1867
+#: src/http.c:1454
 msgid "ignored"
-msgstr "αγνοείται"
+msgstr "Ξ±Ξ³Ξ½ΞΏΞµΞ―Ο„Ξ±ΞΉ"
 
-#: src/http.c:2007
+#: src/http.c:1598
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr ""
-"Προειδοποίηση: μεταχαρακτήρες (wildcards) δεν υποστηρίζονται στο HTTP.\n"
+msgstr "Ξ ΟΞΏΞµΞΉΞ΄ΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ·: ΞΌΞµΟ„Ξ±Ο‡Ξ±ΟΞ±ΞΊΟ„Ξ®ΟΞµΟ‚ (wildcards) Ξ΄ΞµΞ½ Ο…Ο€ΞΏΟƒΟ„Ξ·ΟΞ―Ξ¶ΞΏΞ½Ο„Ξ±ΞΉ ΟƒΟ„ΞΏ HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:2042
+#: src/http.c:1628
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
-msgstr "Το αρχείο `%s' είναι ήδη εδώ, δε θα ανακτηθεί.\n"
+msgstr "Ξ¤ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ `%s' ΞµΞ―Ξ½Ξ±ΞΉ Ξ®Ξ΄Ξ· ΞµΞ΄Ο, Ξ΄Ξµ ΞΈΞ± Ξ±Ξ½Ξ±ΞΊΟ„Ξ·ΞΈΞµΞ―.\n"
 
-#: src/http.c:2232
+#: src/http.c:1800
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
-msgstr "Αδυναμία στην εγγραφή στο `%s' (%s).\n"
-
-#. Another fatal error.
-#: src/http.c:2239
-msgid "Unable to establish SSL connection.\n"
-msgstr "Αδύνατη η σύσταση σύνδεσης SSL.\n"
+msgstr "Ξ‘Ξ΄Ο…Ξ½Ξ±ΞΌΞ―Ξ± ΟƒΟ„Ξ·Ξ½ ΞµΞ³Ξ³ΟΞ±Ο†Ξ® ΟƒΟ„ΞΏ `%s' (%s).\n"
 
-#: src/http.c:2248
+#: src/http.c:1819
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
-msgstr "ΣΦΑΛΜΑ: Μετάσταση (%d) χωρίς τοποθεσία.\n"
+msgstr "Ξ£Ξ¦Ξ‘Ξ›ΞΞ‘: ΞΞµΟ„Ξ¬ΟƒΟ„Ξ±ΟƒΞ· (%d) Ο‡Ο‰ΟΞ―Ο‚ Ο„ΞΏΟ€ΞΏΞΈΞµΟƒΞ―Ξ±.\n"
 
-#: src/http.c:2278
+#: src/http.c:1851
 #, c-format
 msgid "%s ERROR %d: %s.\n"
-msgstr "%s ΣΦΑΛΜΑ %d: %s.\n"
+msgstr "%s Ξ£Ξ¦Ξ‘Ξ›ΞΞ‘ %d: %s.\n"
 
-#: src/http.c:2291
+#: src/http.c:1864
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr ""
-"Κεφαλίδα Last-modified δεν υπάρχει -- χρονικές αναφορές απενεργοποιήθηκαν.\n"
+msgstr "ΞΞµΟ†Ξ±Ξ»Ξ―Ξ΄Ξ± Last-modified Ξ΄ΞµΞ½ Ο…Ο€Ξ¬ΟΟ‡ΞµΞΉ -- Ο‡ΟΞΏΞ½ΞΉΞΊΞ­Ο‚ Ξ±Ξ½Ξ±Ο†ΞΏΟΞ­Ο‚ Ξ±Ο€ΞµΞ½ΞµΟΞ³ΞΏΟ€ΞΏΞΉΞ®ΞΈΞ·ΞΊΞ±Ξ½.\n"
 
-#: src/http.c:2299
+#: src/http.c:1872
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr ""
-"Κεφαλίδα Last-modified δεν είναι έγκυρη -- χρονικές αναφορές αγνοούνται.\n"
+msgstr "ΞΞµΟ†Ξ±Ξ»Ξ―Ξ΄Ξ± Last-modified Ξ΄ΞµΞ½ ΞµΞ―Ξ½Ξ±ΞΉ Ξ­Ξ³ΞΊΟ…ΟΞ· -- Ο‡ΟΞΏΞ½ΞΉΞΊΞ­Ο‚ Ξ±Ξ½Ξ±Ο†ΞΏΟΞ­Ο‚ Ξ±Ξ³Ξ½ΞΏΞΏΟΞ½Ο„Ξ±ΞΉ.\n"
 
-#: src/http.c:2322
+#: src/http.c:1895
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
 msgstr ""
-"Το αρχείο του διακομιστή δεν είναι νεώτερο από το τοπικό αρχείο `%s' -- δε "
-"γίνεται ανάκτηση.\n"
+"Ξ¤ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ Ο„ΞΏΟ… Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ® Ξ΄ΞµΞ½ ΞµΞ―Ξ½Ξ±ΞΉ Ξ½ΞµΟΟ„ΞµΟΞΏ Ξ±Ο€Ο Ο„ΞΏ Ο„ΞΏΟ€ΞΉΞΊΟ Ξ±ΟΟ‡ΞµΞ―ΞΏ `%s' -- Ξ΄Ξµ Ξ³Ξ―Ξ½ΞµΟ„Ξ±ΞΉ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·.\n"
 "\n"
 
-#: src/http.c:2330
-#, fuzzy, c-format
-msgid "The sizes do not match (local %s) -- retrieving.\n"
-msgstr "Τα μεγέθη δεν είναι ίσα (τοπικό %ld) -- γίνεται ανάκτηση ξανά.\n"
+#: src/http.c:1903
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
+msgstr "Ξ¤Ξ± ΞΌΞµΞ³Ξ­ΞΈΞ· Ξ΄ΞµΞ½ ΞµΞ―Ξ½Ξ±ΞΉ Ξ―ΟƒΞ± (Ο„ΞΏΟ€ΞΉΞΊΟ %ld) -- Ξ³Ξ―Ξ½ΞµΟ„Ξ±ΞΉ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ· ΞΎΞ±Ξ½Ξ¬.\n"
 
-#: src/http.c:2335
+#: src/http.c:1907
 msgid "Remote file is newer, retrieving.\n"
-msgstr "Απομακρυσμένο αρχείο είναι νεότερο, έναρξη ανάκτησης.\n"
+msgstr "Ξ‘Ο€ΞΏΞΌΞ±ΞΊΟΟ…ΟƒΞΌΞ­Ξ½ΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ ΞµΞ―Ξ½Ξ±ΞΉ Ξ½ΞµΟΟ„ΞµΟΞΏ, Ξ­Ξ½Ξ±ΟΞΎΞ· Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚.\n"
 
-#: src/http.c:2377
-#, fuzzy, c-format
+#: src/http.c:1948
+#, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s/%s]\n"
+"%s (%s) - `%s' saved [%ld/%ld]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' αποθηκεύτηκε [%ld/%ld]\n"
+"%s (%s) - `%s' Ξ±Ο€ΞΏΞΈΞ·ΞΊΞµΟΟ„Ξ·ΞΊΞµ [%ld/%ld]\n"
 "\n"
 
-#: src/http.c:2434
-#, fuzzy, c-format
-msgid "%s (%s) - Connection closed at byte %s. "
-msgstr "%s (%s) - Η σύνδεση διακόπηκε στο byte %ld. "
+#: src/http.c:1998
+#, c-format
+msgid "%s (%s) - Connection closed at byte %ld. "
+msgstr "%s (%s) - Ξ— ΟƒΟΞ½Ξ΄ΞµΟƒΞ· Ξ΄ΞΉΞ±ΞΊΟΟ€Ξ·ΞΊΞµ ΟƒΟ„ΞΏ byte %ld. "
 
-#: src/http.c:2443
-#, fuzzy, c-format
+#: src/http.c:2007
+#, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s/%s])\n"
+"%s (%s) - `%s' saved [%ld/%ld])\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' αποθηκεύτηκε [%ld/%ld])\n"
+"%s (%s) - `%s' Ξ±Ο€ΞΏΞΈΞ·ΞΊΞµΟΟ„Ξ·ΞΊΞµ [%ld/%ld])\n"
 "\n"
 
-#: src/http.c:2469
-#, fuzzy, c-format
-msgid "%s (%s) - Connection closed at byte %s/%s. "
-msgstr "%s (%s) - Η σύνδεση διακόπηκε στο byte %ld/%ld. "
+#: src/http.c:2028
+#, c-format
+msgid "%s (%s) - Connection closed at byte %ld/%ld. "
+msgstr "%s (%s) - Ξ— ΟƒΟΞ½Ξ΄ΞµΟƒΞ· Ξ΄ΞΉΞ±ΞΊΟΟ€Ξ·ΞΊΞµ ΟƒΟ„ΞΏ byte %ld/%ld. "
 
-#: src/http.c:2483
-#, fuzzy, c-format
-msgid "%s (%s) - Read error at byte %s (%s)."
-msgstr "%s (%s) - Σφάλμα ανάγνωσης στο byte %ld (%s)."
+#: src/http.c:2040
+#, c-format
+msgid "%s (%s) - Read error at byte %ld (%s)."
+msgstr "%s (%s) - Ξ£Ο†Ξ¬Ξ»ΞΌΞ± Ξ±Ξ½Ξ¬Ξ³Ξ½Ο‰ΟƒΞ·Ο‚ ΟƒΟ„ΞΏ byte %ld (%s)."
 
-#: src/http.c:2493
-#, fuzzy, c-format
-msgid "%s (%s) - Read error at byte %s/%s (%s). "
-msgstr "%s (%s) - Σφάλμα ανάγνωσης στο byte %ld/%ld (%s). "
+#: src/http.c:2049
+#, c-format
+msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
+msgstr "%s (%s) - Ξ£Ο†Ξ¬Ξ»ΞΌΞ± Ξ±Ξ½Ξ¬Ξ³Ξ½Ο‰ΟƒΞ·Ο‚ ΟƒΟ„ΞΏ byte %ld/%ld (%s). "
 
-#: src/init.c:369
+#: src/init.c:342
 #, c-format
 msgid "%s: WGETRC points to %s, which doesn't exist.\n"
 msgstr ""
 
-#: src/init.c:433 src/netrc.c:277
+#: src/init.c:398 src/netrc.c:276
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
-msgstr "%s: Αδυναμία ανάγνωσης %s (%s).\n"
+msgstr "%s: Ξ‘Ξ΄Ο…Ξ½Ξ±ΞΌΞ―Ξ± Ξ±Ξ½Ξ¬Ξ³Ξ½Ο‰ΟƒΞ·Ο‚ %s (%s).\n"
 
-#: src/init.c:451
+#: src/init.c:416 src/init.c:422
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
-msgstr "%s: Σφάλμα στο %s στη γραμμή %d.\n"
-
-#: src/init.c:457
-#, fuzzy, c-format
-msgid "%s: Syntax error in %s at line %d.\n"
-msgstr "%s: Σφάλμα στο %s στη γραμμή %d.\n"
-
-#: src/init.c:462
-#, fuzzy, c-format
-msgid "%s: Unknown command `%s' in %s at line %d.\n"
-msgstr "%s: ΣΦΑΛΜΑ: ¶γνωστη εντολή `%s', τιμή `%s'.\n"
+msgstr "%s: Ξ£Ο†Ξ¬Ξ»ΞΌΞ± ΟƒΟ„ΞΏ %s ΟƒΟ„Ξ· Ξ³ΟΞ±ΞΌΞΌΞ® %d.\n"
 
-#: src/init.c:507
+#: src/init.c:454
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr ""
-"%s: Προειδοποίηση: Το wgetrc του συστήματος και του χρήστη δείχνουν στο ίδιο "
-"αρχείο `%s'.\n"
+msgstr "%s: Ξ ΟΞΏΞµΞΉΞ΄ΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ·: Ξ¤ΞΏ wgetrc Ο„ΞΏΟ… ΟƒΟ…ΟƒΟ„Ξ®ΞΌΞ±Ο„ΞΏΟ‚ ΞΊΞ±ΞΉ Ο„ΞΏΟ… Ο‡ΟΞ®ΟƒΟ„Ξ· Ξ΄ΞµΞ―Ο‡Ξ½ΞΏΟ…Ξ½ ΟƒΟ„ΞΏ Ξ―Ξ΄ΞΉΞΏ Ξ±ΟΟ‡ΞµΞ―ΞΏ `%s'.\n"
 
-#: src/init.c:661
+#: src/init.c:594
 #, fuzzy, c-format
 msgid "%s: Invalid --execute command `%s'\n"
-msgstr "%s: Μη έγκυρη ρύθμιση `%s'.\n"
+msgstr "%s: ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞ· ΟΟΞΈΞΌΞΉΟƒΞ· `%s'.\n"
 
-#: src/init.c:707
+#: src/init.c:630
 #, fuzzy, c-format
 msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
-msgstr "%s: %s: Παρακαλώ ορίστε on ή off.\n"
+msgstr "%s: %s: Ξ Ξ±ΟΞ±ΞΊΞ±Ξ»Ο ΞΏΟΞ―ΟƒΟ„Ξµ on Ξ® off.\n"
 
-#: src/init.c:750
+#: src/init.c:673
 #, fuzzy, c-format
 msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
-msgstr ""
-"%s: %s: Παρακαλώ καθορίστε πάντα(always), ενεργό(on), ανενεργό(off) ή ποτέ"
-"(never).\n"
+msgstr "%s: %s: Ξ Ξ±ΟΞ±ΞΊΞ±Ξ»Ο ΞΊΞ±ΞΈΞΏΟΞ―ΟƒΟ„Ξµ Ο€Ξ¬Ξ½Ο„Ξ±(always), ΞµΞ½ΞµΟΞ³Ο(on), Ξ±Ξ½ΞµΞ½ΞµΟΞ³Ο(off) Ξ® Ο€ΞΏΟ„Ξ­(never).\n"
 
-#: src/init.c:767
+#: src/init.c:691
 #, fuzzy, c-format
 msgid "%s: %s: Invalid number `%s'.\n"
-msgstr "%s: %s: Μη έγκυρη ρύθμιση `%s'.\n"
+msgstr "%s: %s: ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞ· ΟΟΞΈΞΌΞΉΟƒΞ· `%s'.\n"
 
-#: src/init.c:998 src/init.c:1017
+#: src/init.c:930 src/init.c:949
 #, fuzzy, c-format
 msgid "%s: %s: Invalid byte value `%s'\n"
-msgstr "%s: %s: Μη έγκυρος τύπος προόδου `%s'.\n"
+msgstr "%s: %s: ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞΏΟ‚ Ο„ΟΟ€ΞΏΟ‚ Ο€ΟΞΏΟΞ΄ΞΏΟ… `%s'.\n"
 
-#: src/init.c:1042
+#: src/init.c:974
 #, fuzzy, c-format
 msgid "%s: %s: Invalid time period `%s'\n"
-msgstr "%s: %s: Μη έγκυρη ρύθμιση `%s'.\n"
-
-#: src/init.c:1096 src/init.c:1186 src/init.c:1281 src/init.c:1306
-#, fuzzy, c-format
-msgid "%s: %s: Invalid value `%s'.\n"
-msgstr "%s: %s: Μη έγκυρη ρύθμιση `%s'.\n"
+msgstr "%s: %s: ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞ· ΟΟΞΈΞΌΞΉΟƒΞ· `%s'.\n"
 
-#: src/init.c:1133
+#: src/init.c:1051
 #, fuzzy, c-format
 msgid "%s: %s: Invalid header `%s'.\n"
-msgstr "%s: %s: Μη έγκυρη ρύθμιση `%s'.\n"
+msgstr "%s: %s: ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞ· ΟΟΞΈΞΌΞΉΟƒΞ· `%s'.\n"
 
-#: src/init.c:1198
+#: src/init.c:1106
 #, c-format
 msgid "%s: %s: Invalid progress type `%s'.\n"
-msgstr "%s: %s: Μη έγκυρος τύπος προόδου `%s'.\n"
+msgstr "%s: %s: ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞΏΟ‚ Ο„ΟΟ€ΞΏΟ‚ Ο€ΟΞΏΟΞ΄ΞΏΟ… `%s'.\n"
 
-#: src/init.c:1249
+#: src/init.c:1157
 #, fuzzy, c-format
 msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
-msgstr "%s: %s: Μη έγκυρη ρύθμιση `%s'.\n"
+msgstr "%s: %s: ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞ· ΟΟΞΈΞΌΞΉΟƒΞ· `%s'.\n"
+
+#: src/init.c:1198
+#, fuzzy, c-format
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr "%s: %s: ΞΞ· Ξ­Ξ³ΞΊΟ…ΟΞ· ΟΟΞΈΞΌΞΉΟƒΞ· `%s'.\n"
 
-#: src/log.c:806
+#: src/log.c:636
 #, c-format
 msgid ""
 "\n"
 "%s received, redirecting output to `%s'.\n"
 msgstr ""
 "\n"
-"%s λήφθηκε, ανακατεύθυνση εξόδου στο `%s'.\n"
+"%s Ξ»Ξ®Ο†ΞΈΞ·ΞΊΞµ, Ξ±Ξ½Ξ±ΞΊΞ±Ο„ΞµΟΞΈΟ…Ξ½ΟƒΞ· ΞµΞΎΟΞ΄ΞΏΟ… ΟƒΟ„ΞΏ `%s'.\n"
 
 #. Eek!  Opening the alternate log file has failed.  Nothing we
 #. can do but disable printing completely.
-#: src/log.c:816
-#, fuzzy, c-format
-msgid ""
-"\n"
-"%s received.\n"
-msgstr "Δεν ελήφθησαν δεδομένα"
-
-#: src/log.c:817
+#: src/log.c:643
 #, c-format
 msgid "%s: %s; disabling logging.\n"
-msgstr "%s: %s; απενεργοποίηση λήψης καταγραφών.\n"
+msgstr "%s: %s; Ξ±Ο€ΞµΞ½ΞµΟΞ³ΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ· Ξ»Ξ®ΟΞ·Ο‚ ΞΊΞ±Ο„Ξ±Ξ³ΟΞ±Ο†ΟΞ½.\n"
 
-#: src/main.c:375
+#: src/main.c:127
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "Χρήση: %s [ΕΠΙΛΟΓΗ]... [URL]...\n"
+msgstr "Ξ§ΟΞ®ΟƒΞ·: %s [Ξ•Ξ Ξ™Ξ›ΞΞ“Ξ—]... [URL]...\n"
 
-#: src/main.c:387
-#, fuzzy
+#: src/main.c:135
+#, c-format
+msgid "GNU Wget %s, a non-interactive network retriever.\n"
+msgstr "GNU Wget %s, Ξ­Ξ½Ξ± ΞΌΞ·-Ξ΄ΞΉΞ±Ξ»ΞΏΞ³ΞΉΞΊΟ Ξ΄ΞΉΞΊΟ„Ο…Ξ±ΞΊΟ Ο€ΟΟΞ³ΟΞ±ΞΌΞΌΞ± Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚ Ξ±ΟΟ‡ΞµΞ―Ο‰Ξ½.\n"
+
+#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
+#. don't bitch.  Also, it makes translation much easier.
+#: src/main.c:140
 msgid ""
+"\n"
 "Mandatory arguments to long options are mandatory for short options too.\n"
 "\n"
 msgstr ""
 "\n"
-"Οι υποχρεωτικοί παράμετροι στα λεκτικά ορίσματα είναι υποχρεωτικοί και για "
-"τα σύντομα ορίσματα.\n"
+"ΞΞΉ Ο…Ο€ΞΏΟ‡ΟΞµΟ‰Ο„ΞΉΞΊΞΏΞ― Ο€Ξ±ΟΞ¬ΞΌΞµΟ„ΟΞΏΞΉ ΟƒΟ„Ξ± Ξ»ΞµΞΊΟ„ΞΉΞΊΞ¬ ΞΏΟΞ―ΟƒΞΌΞ±Ο„Ξ± ΞµΞ―Ξ½Ξ±ΞΉ Ο…Ο€ΞΏΟ‡ΟΞµΟ‰Ο„ΞΉΞΊΞΏΞ― ΞΊΞ±ΞΉ Ξ³ΞΉΞ± Ο„Ξ± ΟƒΟΞ½Ο„ΞΏΞΌΞ± ΞΏΟΞ―ΟƒΞΌΞ±Ο„Ξ±.\n"
 "\n"
 
-#: src/main.c:389
-msgid "Startup:\n"
-msgstr ""
-
-#: src/main.c:391
-msgid "  -V,  --version           display the version of Wget and exit.\n"
-msgstr ""
-
-#: src/main.c:393
-msgid "  -h,  --help              print this help.\n"
-msgstr ""
-
-#: src/main.c:395
-msgid "  -b,  --background        go to background after startup.\n"
-msgstr ""
-
-#: src/main.c:397
-msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
-msgstr ""
-
-#: src/main.c:401
-msgid "Logging and input file:\n"
-msgstr ""
-
-#: src/main.c:403
-msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
-msgstr ""
-
-#: src/main.c:405
-msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
-msgstr ""
-
-#: src/main.c:408
-msgid "  -d,  --debug               print lots of debugging information.\n"
-msgstr ""
-
-#: src/main.c:411
-msgid "  -q,  --quiet               quiet (no output).\n"
-msgstr ""
-
-#: src/main.c:413
-msgid "  -v,  --verbose             be verbose (this is the default).\n"
-msgstr ""
-
-#: src/main.c:415
-msgid ""
-"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
-msgstr ""
-
-#: src/main.c:417
-msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
-msgstr ""
-
-#: src/main.c:419
-msgid "  -F,  --force-html          treat input file as HTML.\n"
-msgstr ""
-
-#: src/main.c:421
-msgid ""
-"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
-msgstr ""
-
-#: src/main.c:425
-msgid "Download:\n"
-msgstr ""
-
-#: src/main.c:427
-msgid ""
-"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
-"unlimits).\n"
-msgstr ""
-
-#: src/main.c:429
-msgid "       --retry-connrefused       retry even if connection is refused.\n"
-msgstr ""
-
-#: src/main.c:431
-msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
-msgstr ""
-
-#: src/main.c:433
-msgid ""
-"  -nc, --no-clobber              skip downloads that would download to\n"
-"                                 existing files.\n"
-msgstr ""
-
-#: src/main.c:436
+#: src/main.c:144
 msgid ""
-"  -c,  --continue                resume getting a partially-downloaded "
-"file.\n"
-msgstr ""
-
-#: src/main.c:438
-msgid "       --progress=TYPE           select progress gauge type.\n"
-msgstr ""
-
-#: src/main.c:440
-msgid ""
-"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
-"                                 local.\n"
-msgstr ""
-
-#: src/main.c:443
-msgid "  -S,  --server-response         print server response.\n"
-msgstr ""
-
-#: src/main.c:445
-msgid "       --spider                  don't download anything.\n"
-msgstr ""
-
-#: src/main.c:447
-msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
-msgstr ""
-
-#: src/main.c:449
-msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
-msgstr ""
-
-#: src/main.c:451
-msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
-msgstr ""
-
-#: src/main.c:453
-msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
-msgstr ""
-
-#: src/main.c:455
-msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
-msgstr ""
-
-#: src/main.c:457
-msgid ""
-"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
-"retrieval.\n"
-msgstr ""
-
-#: src/main.c:459
-msgid ""
-"       --random-wait             wait from 0...2*WAIT secs between "
-"retrievals.\n"
-msgstr ""
-
-#: src/main.c:461
-msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
-msgstr ""
-
-#: src/main.c:463
-msgid "       --no-proxy                explicitly turn off proxy.\n"
-msgstr ""
-
-#: src/main.c:465
-msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
-msgstr ""
-
-#: src/main.c:467
-msgid ""
-"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
-"host.\n"
-msgstr ""
-
-#: src/main.c:469
-msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
-msgstr ""
-
-#: src/main.c:471
-msgid "       --no-dns-cache            disable caching DNS lookups.\n"
-msgstr ""
-
-#: src/main.c:473
-msgid ""
-"       --restrict-file-names=OS  restrict chars in file names to ones OS "
-"allows.\n"
-msgstr ""
-
-#: src/main.c:476
-msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
-msgstr ""
-
-#: src/main.c:478
-msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
-msgstr ""
-
-#: src/main.c:480
-msgid ""
-"       --prefer-family=FAMILY    connect first to addresses of specified "
-"family,\n"
-"                                 one of IPv6, IPv4, or none.\n"
-msgstr ""
-
-#: src/main.c:484
-msgid "       --user=USER               set both ftp and http user to USER.\n"
-msgstr ""
-
-#: src/main.c:486
-msgid ""
-"       --password=PASS           set both ftp and http password to PASS.\n"
+"Startup:\n"
+"  -V,  --version           display the version of Wget and exit.\n"
+"  -h,  --help              print this help.\n"
+"  -b,  --background        go to background after startup.\n"
+"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+"\n"
 msgstr ""
+"ΞΞ½Ξ±ΟΞΎΞ·:\n"
+"  -V,  --version           ΞµΞΌΟ†Ξ¬Ξ½ΞΉΟƒΞ· Ο„Ξ·Ο‚ Ξ­ΞΊΞ΄ΞΏΟƒΞ·Ο‚ Ο„ΞΏΟ… Wget ΞΊΞ±ΞΉ Ξ­ΞΎΞΏΞ΄ΞΏΟ‚.\n"
+"  -h,  --help              ΞµΞΌΟ†Ξ¬Ξ½ΞΉΟƒΞ· Ο„Ξ·Ο‚ Ξ²ΞΏΞ®ΞΈΞµΞΉΞ±Ο‚ Ξ±Ο…Ο„Ξ®Ο‚.\n"
+"  -b,  --background        Ξ±Ο€ΞΏΟƒΟ„ΞΏΞ»Ξ® ΟƒΟ„ΞΏ Ο€Ξ±ΟΞ±ΟƒΞΊΞ®Ξ½ΞΉΞΏ ΞΌΞµΟ„Ξ¬ Ο„Ξ·Ξ½ Ξ­Ξ½Ξ±ΟΞΎΞ·.\n"
+"  -e,  --execute=Ξ•ΞΞ¤ΞΞ›Ξ—    ΞµΞΊΟ„Ξ­Ξ»ΞµΟƒΞ· ΞΌΞΉΞ±Ο‚ ΞµΞ½Ο„ΞΏΞ»Ξ®Ο‚ ΞΌΞΏΟΟ†Ξ®Ο‚ `.wgetrc'.\n"
+"\n"
 
-#: src/main.c:490
+#: src/main.c:151
 #, fuzzy
-msgid "Directories:\n"
-msgstr "Κατάλογος   "
-
-#: src/main.c:492
-msgid "  -nd, --no-directories           don't create directories.\n"
-msgstr ""
-
-#: src/main.c:494
-msgid "  -x,  --force-directories        force creation of directories.\n"
-msgstr ""
-
-#: src/main.c:496
-msgid "  -nH, --no-host-directories      don't create host directories.\n"
-msgstr ""
-
-#: src/main.c:498
-msgid "       --protocol-directories     use protocol name in directories.\n"
-msgstr ""
-
-#: src/main.c:500
-msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
-msgstr ""
-
-#: src/main.c:502
 msgid ""
-"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
-"components.\n"
-msgstr ""
-
-#: src/main.c:506
-msgid "HTTP options:\n"
-msgstr ""
-
-#: src/main.c:508
-msgid "       --http-user=USER        set http user to USER.\n"
-msgstr ""
-
-#: src/main.c:510
-msgid "       --http-password=PASS    set http password to PASS.\n"
-msgstr ""
-
-#: src/main.c:512
-msgid "       --no-cache              disallow server-cached data.\n"
-msgstr ""
-
-#: src/main.c:514
-msgid ""
-"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
-msgstr ""
-
-#: src/main.c:516
-msgid "       --ignore-length         ignore `Content-Length' header field.\n"
-msgstr ""
-
-#: src/main.c:518
-msgid "       --header=STRING         insert STRING among the headers.\n"
-msgstr ""
-
-#: src/main.c:520
-msgid "       --proxy-user=USER       set USER as proxy username.\n"
-msgstr ""
-
-#: src/main.c:522
-msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
-msgstr ""
-
-#: src/main.c:524
-msgid ""
-"       --referer=URL           include `Referer: URL' header in HTTP "
-"request.\n"
-msgstr ""
-
-#: src/main.c:526
-msgid "       --save-headers          save the HTTP headers to file.\n"
-msgstr ""
-
-#: src/main.c:528
-msgid ""
-"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
-msgstr ""
-
-#: src/main.c:530
-msgid ""
-"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
-"connections).\n"
-msgstr ""
-
-#: src/main.c:532
-msgid "       --no-cookies            don't use cookies.\n"
-msgstr ""
-
-#: src/main.c:534
-msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
-msgstr ""
-
-#: src/main.c:536
-msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
-msgstr ""
-
-#: src/main.c:538
-msgid ""
-"       --keep-session-cookies  load and save session (non-permanent) "
-"cookies.\n"
-msgstr ""
-
-#: src/main.c:540
-msgid ""
-"       --post-data=STRING      use the POST method; send STRING as the "
-"data.\n"
-msgstr ""
-
-#: src/main.c:542
-msgid ""
-"       --post-file=FILE        use the POST method; send contents of FILE.\n"
-msgstr ""
-
-#: src/main.c:547
-msgid "HTTPS (SSL/TLS) options:\n"
-msgstr ""
-
-#: src/main.c:549
-msgid ""
-"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
-"                                SSLv3, and TLSv1.\n"
-msgstr ""
-
-#: src/main.c:552
-msgid ""
-"       --no-check-certificate   don't validate the server's certificate.\n"
-msgstr ""
-
-#: src/main.c:554
-msgid "       --certificate=FILE       client certificate file.\n"
-msgstr ""
-
-#: src/main.c:556
-msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
-msgstr ""
-
-#: src/main.c:558
-msgid "       --private-key=FILE       private key file.\n"
-msgstr ""
-
-#: src/main.c:560
-msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
-msgstr ""
-
-#: src/main.c:562
-msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
-msgstr ""
-
-#: src/main.c:564
-msgid ""
-"       --ca-directory=DIR       directory where hash list of CA's is "
-"stored.\n"
+"Logging and input file:\n"
+"  -o,  --output-file=FILE     log messages to FILE.\n"
+"  -a,  --append-output=FILE   append messages to FILE.\n"
+"  -d,  --debug                print debug output.\n"
+"  -q,  --quiet                quiet (no output).\n"
+"  -v,  --verbose              be verbose (this is the default).\n"
+"  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
+"  -i,  --input-file=FILE      download URLs found in FILE.\n"
+"  -F,  --force-html           treat input file as HTML.\n"
+"  -B,  --base=URL             prepends URL to relative links in -F -i file.\n"
+"\n"
 msgstr ""
+"ΞΞ±Ο„Ξ±Ξ³ΟΞ±Ο†Ξ®Β·ΞΊΞ±ΞΉΒ·Ξ±ΟΟ‡ΞµΞ―ΞΏΒ·ΞµΞΉΟƒΟΞ΄ΞΏΟ…:\n"
+"  -o,  --output-file=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ   ΞΊΞ±Ο„Ξ±Ξ³ΟΞ±Ο†Ξ®Β·ΞΌΞ·Ξ½Ο…ΞΌΞ¬Ο„Ο‰Ξ½Β·ΟƒΟ„ΞΏΒ·Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ.\n"
+"  -a,  --append-output=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ Ο€ΟΞΏΟƒΞΈΞ®ΞΊΞ·Β·ΞΌΞ·Ξ½Ο…ΞΌΞ¬Ο„Ο‰Ξ½Β·ΟƒΟ„ΞΏΒ·Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ.\n"
+"  -d,  --debug                ΞµΞΌΟ†Ξ¬Ξ½ΞΉΟƒΞ·Β·Ο€Ξ»Ξ·ΟΞΏΟ†ΞΏΟΞΉΟΞ½Β·ΞµΞΊΟƒΟ†Ξ±Ξ»ΞΌΞ¬Ο„Ο‰ΟƒΞ·Ο‚.\n"
+"  -q,  --quiet                ΟƒΞΉΟ‰Ο€Ξ·Ξ»Ξ¬Β·(Ο‡Ο‰ΟΞ―Ο‚Β·Ξ­ΞΎΞΏΞ΄ΞΏ).\n"
+"  -v,  --verbose              Ο€ΞµΟΞΉΟ†ΟΞ±ΟƒΟ„ΞΉΞΊΞ¬Β·(ΞµΞΎ'Β·ΞΏΟΞΉΟƒΞΌΞΏΟΒ·ΟΟΞΈΞΌΞΉΟƒΞ·).\n"
+"  -nv, --non-verbose          Ξ±Ο€ΞµΞ½ΞµΟΞ³ΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ·Β·Ο€ΞµΟΞΉΟ†ΟΞ±ΟƒΟ„ΞΉΞΊΟΟ„Ξ·Ο„Ξ±Ο‚,Β·Ο‡Ο‰ΟΞ―Ο‚Β·Ξ½Ξ±Β·ΞµΞ―Ξ½Ξ±ΞΉΒ·ΞΊΞ±ΞΉΒ·ΟƒΞΉΟ‰Ο€Ξ·Ξ»Ο.\n"
+"  -i,  --input-file=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ    Ξ±Ξ½Ξ¬Ξ³Ξ½Ο‰ΟƒΞ·Β·URLΒ·Ξ±Ο€ΟΒ·Ο„ΞΏΒ·Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ.\n"
+"  -F,  --force-html           ΞΌΞµΟ„Ξ±Ο‡ΞµΞ―ΟΞΉΟƒΞ·Β·Ξ±ΟΟ‡ΞµΞ―ΞΏΟ…Β·ΞµΞΉΟƒΟΞ΄ΞΏΟ…Β·Ο‰Ο‚Β·Ξ±ΟΟ‡ΞµΞ―ΞΏΒ·HTML.\n"
+"  -B,  --base=URL             Ο€ΟΞΏΟƒΞΈΞ­Ο„ΞµΞΉΒ·Ο„ΞΏΒ·URLΒ·ΟƒΟ„ΞΏΟ…Ο‚Β·ΟƒΟ‡ΞµΟ„ΞΉΞΊΞΏΟΟ‚Β·ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΞΏΟ…Ο‚Β·ΟƒΟ„ΞΏΒ·-FΒ·-iΒ·Ξ±ΟΟ‡ΞµΞ―ΞΏ.\n"
+"       --sslcertfile=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ   Ο€ΟΞΏΞ±ΞΉΟΞµΟ„ΞΉΞΊΟΒ·Ο€ΞΉΟƒΟ„ΞΏΟ€ΞΏΞΉΞ·Ο„ΞΉΞΊΟΒ·Ο€ΞµΞ»Ξ¬Ο„Ξ·.\n"
+"       --sslcertkey=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ    Ο€ΟΞΏΞ±ΞΉΟΞµΟ„ΞΉΞΊΟ Ξ±ΟΟ‡ΞµΞ―ΞΏ ΞΊΞ»ΞµΞΉΞ΄ΞΉΞΏΟ Ξ³ΞΉΞ± Ξ±Ο…Ο„Ο Ο„ΞΏ Ο€ΞΉΟƒΟ„ΞΏΟ€ΞΏΞΉΞ·Ο„ΞΉΞΊΟ.\n"
+"       --egd-file=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ      ΟΞ½ΞΏΞΌΞ± Ξ±ΟΟ‡ΞµΞ―ΞΏΟ… Ξ³ΞΉΞ± Ο„ΞΏΞ½ Ο…Ο€ΞΏΞ΄ΞΏΟ‡Ξ­Ξ± EGD.\n"
+"\n"
 
-#: src/main.c:566
+#: src/main.c:163
+#, fuzzy
 msgid ""
-"       --random-file=FILE       file with random data for seeding the SSL "
-"PRNG.\n"
+"Download:\n"
+"  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n"
+"       --retry-connrefused      retry even if connection is refused.\n"
+"  -O   --output-document=FILE   write documents to FILE.\n"
+"  -nc, --no-clobber             don't clobber existing files or use .# suffixes.\n"
+"  -c,  --continue               resume getting a partially-downloaded file.\n"
+"       --progress=TYPE          select progress gauge type.\n"
+"  -N,  --timestamping           don't re-retrieve files unless newer than local.\n"
+"  -S,  --server-response        print server response.\n"
+"       --spider                 don't download anything.\n"
+"  -T,  --timeout=SECONDS        set all timeout values to SECONDS.\n"
+"       --dns-timeout=SECS       set the DNS lookup timeout to SECS.\n"
+"       --connect-timeout=SECS   set the connect timeout to SECS.\n"
+"       --read-timeout=SECS      set the read timeout to SECS.\n"
+"  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
+"       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n"
+"       --random-wait            wait from 0...2*WAIT secs between retrievals.\n"
+"  -Y,  --proxy=on/off           turn proxy on or off.\n"
+"  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+"       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n"
+"       --limit-rate=RATE        limit download rate to RATE.\n"
+"       --dns-cache=off          disable caching DNS lookups.\n"
+"       --restrict-file-names=OS restrict chars in file names to ones OS allows.\n"
+"\n"
 msgstr ""
+"ΞΞµΟ„Ξ±Ο†ΟΟΟ„Ο‰ΟƒΞ·:\n"
+"       --bind-address=Ξ”Ξ™Ξ•Ξ¥ΞΞ¥ΞΞ£Ξ— ΟƒΟΞ½Ξ΄ΞµΟƒΞ· ΟƒΟ„Ξ· Ξ”Ξ™Ξ•Ξ¥ΞΞ¥ΞΞ£Ξ— (ΟΞ½ΞΏΞΌΞ± ΟƒΟ…ΟƒΟ„Ξ®ΞΌΞ±Ο„ΞΏΟ‚ Ξ® IP) ΟƒΟ„ΞΏ Ο„ΞΏΟ€ΞΉΞΊΟ ΟƒΟΟƒΟ„Ξ·ΞΌΞ±.\n"
+"  -t,  --tries=Ξ‘Ξ΅Ξ™ΞΞΞΞ£          ΞΏΟΞΉΟƒΞΌΟΟ‚ Ο„ΞΏΟ… Ξ±ΟΞΉΞΈΞΌΞΏΟ Ο„Ο‰Ξ½ Ο€ΟΞΏΟƒΟ€Ξ±ΞΈΞµΞΉΟΞ½ ΟƒΞµ Ξ‘Ξ΅Ξ™ΞΞΞΞ£ (0 Ξ³ΞΉΞ± Ο‡Ο‰ΟΞ―Ο‚ ΟΟΞΉΞΏ).\n"
+"  -O   --output-document=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ ΞµΞ³Ξ³ΟΞ±Ο†Ξ® ΞµΞ³Ξ³ΟΞ¬Ο†Ο‰Ξ½ ΟƒΟ„ΞΏ Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ.\n"
+"  -nc, --no-clobber             Ξ½Ξ± ΞΌΞ·Ξ½ Ξ±Ξ»Ξ»Ξ±Ο‡Ο„ΞΏΟΞ½ Ο„Ξ± ΞΏΞ½ΟΞΌΞ±Ο„Ξ± Ο…Ο€Ξ±ΟΟ‡ΟΞ½Ο„Ο‰Ξ½ Ξ±ΟΟ‡ΞµΞ―Ο‰Ξ½ Ξ® Ξ½Ξ± Ξ΄ΞΏΞΈΞΏΟΞ½ ΞΊΞ±Ο„Ξ±Ξ»Ξ®ΞΎΞµΞΉΟ‚ .#.\n"
+"  -c,  --continue               ΟƒΟ…Ξ½Ξ­Ο‡ΞΉΟƒΞ· Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚ Ο…Ο€Ξ¬ΟΟ‡ΞΏΞ½Ο„ΞΏΟ‚ Ξ±ΟΟ‡ΞµΞ―ΞΏΟ….\n"
+"       --progress=ΞΞΞ΅Ξ¦Ξ—         ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® Ο„Ξ·Ο‚ ΞΌΞΏΟΟ†Ξ®Ο‚ ΞµΞΌΟ†Ξ¬Ξ½ΞΉΟƒΞ·Ο‚ Ο„Ξ·Ο‚ Ο€ΟΞΏΟΞ΄ΞΏΟ… Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚.\n"
+"  -N,  --timestamping           Ξ±Ο€ΞΏΟ†Ο…Ξ³Ξ® Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚ Ξ±ΟΟ‡ΞµΞ―Ο‰Ξ½ Ο€Ξ±Ξ»Ξ±ΞΉΟΟ„ΞµΟΟ‰Ξ½ Ο„Ο‰Ξ½ Ο„ΞΏΟ€ΞΉΞΊΟΞ½.\n"
+"  -S,  --server-response        ΞµΞΌΟ†Ξ¬Ξ½ΞΉΟƒΞ· Ξ±Ο€ΞΏΞΊΟΞ―ΟƒΞµΟ‰Ξ½ Ο„ΞΏΟ… Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„Ξ®.\n"
+"       --spider                 Ξ±Ο€ΞΏΟ†Ο…Ξ³Ξ® Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚ ΞΏΟ€ΞΏΞΉΞΏΟ…Ξ΄Ξ®Ο€ΞΏΟ„Ξµ Ξ±ΟΟ‡ΞµΞ―ΞΏΟ….\n"
+"  -T,  --timeout=Ξ”Ξ•Ξ¥Ξ¤Ξ•Ξ΅ΞΞ›Ξ•Ξ Ξ¤Ξ‘   ΞΏΟΞΉΟƒΞΌΟΟ‚ Ο‡ΟΞΏΞ½ΞΉΞΊΞΏΟ ΞΏΟΞ―ΞΏΟ… Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚ ΟƒΞµ Ξ”Ξ•Ξ¥Ξ¤Ξ•Ξ΅ΞΞ›Ξ•Ξ Ξ¤Ξ‘.\n"
+"  -w,  --wait=Ξ”Ξ•Ξ¥Ξ¤Ξ•Ξ΅ΞΞ›Ξ•Ξ Ξ¤Ξ‘      Ξ±Ξ½Ξ±ΞΌΞΏΞ½Ξ® Ξ”Ξ•Ξ¥Ξ¤Ξ•Ξ΅ΞΞ›Ξ•Ξ Ξ¤Ξ‘ ΞΌΞµΟ„Ξ±ΞΎΟ Ξ±Ξ½Ξ±ΞΊΟ„Ξ®ΟƒΞµΟ‰Ξ½.\n"
+"       --waitretry=Ξ”Ξ•Ξ¥Ξ¤Ξ•Ξ΅ΞΞ›Ξ•Ξ Ξ¤Ξ‘ Ξ±Ξ½Ξ±ΞΌΞΏΞ½Ξ® 1...Ξ”Ξ•Ξ¥Ξ¤Ξ•Ξ΅ΞΞ›Ξ•Ξ Ξ¤Ξ‘ ΞΌΞµΟ„Ξ±ΞΎΟ Ο€ΟΞΏΟƒΟ€Ξ±ΞΈΞµΞΉΟΞ½ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚.\n"
+"       --random-wait            Ξ±Ξ½Ξ±ΞΌΞΏΞ½Ξ® Ξ±Ο€Ο 0...2*ΞΞ‘ΞΞ¥Ξ£Ξ¤Ξ•Ξ΅Ξ—Ξ£Ξ— Ξ΄ΞµΟ…Ο„ΞµΟΟΞ»ΞµΟ€Ο„Ξ± ΞΌΞµΟ„Ξ±ΞΎΟ Ξ±Ξ½Ξ±ΞΊΟ„Ξ®ΟƒΞµΟ‰Ξ½.\n"
+"  -Y,  --proxy=on/off           ΟΟΞΈΞΌΞΉΟƒΞ· Ο‡ΟΞ®ΟƒΞ·Ο‚ Ξ΄ΞΉΞ±ΞΌΞµΟƒΞΏΞ»Ξ±Ξ²Ξ·Ο„Ξ® ΟƒΞµ ΞµΞ½ΞµΟΞ³Ο (on) Ξ® Ξ±Ξ½ΞµΞ½ΞµΟΞ³Ο (off).\n"
+"  -Q,  --quota=Ξ‘Ξ΅Ξ™ΞΞΞΞ£          ΞΏΟΞΉΟƒΞΌΟΟ‚ ΞΏΟΞ―ΞΏΟ… ΟƒΟ…Ξ½ΞΏΞ»ΞΉΞΊΞΏΟ ΞΌΞµΞ³Ξ­ΞΈΞΏΟ…Ο‚ Ξ±ΟΟ‡ΞµΞ―Ο‰Ξ½ Ο€ΟΞΏΟ‚ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ· ΟƒΞµ Ξ‘Ξ΅Ξ™ΞΞΞ.\n"
+"       --limit-rate=Ξ΅Ξ¥ΞΞΞΞ£      Ο€ΞµΟΞΉΞΏΟΞΉΟƒΞΌΟΟ‚ Ο„ΞΏΟ… ΟΟ…ΞΈΞΌΞΏΟ Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·Ο‚ ΟƒΞµ Ξ΅Ξ¥ΞΞΞΞ£.\n"
+"\n"
 
-#: src/main.c:568
+#: src/main.c:188
+#, fuzzy
 msgid ""
-"       --egd-file=FILE          file naming the EGD socket with random "
-"data.\n"
-msgstr ""
-
-#: src/main.c:573
-msgid "FTP options:\n"
-msgstr ""
-
-#: src/main.c:575
-msgid "       --ftp-user=USER         set ftp user to USER.\n"
-msgstr ""
-
-#: src/main.c:577
-msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
-msgstr ""
-
-#: src/main.c:579
-msgid "       --no-remove-listing     don't remove `.listing' files.\n"
-msgstr ""
-
-#: src/main.c:581
-msgid "       --no-glob               turn off FTP file name globbing.\n"
-msgstr ""
-
-#: src/main.c:583
-msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
+"Directories:\n"
+"  -nd, --no-directories            don't create directories.\n"
+"  -x,  --force-directories         force creation of directories.\n"
+"  -nH, --no-host-directories       don't create host directories.\n"
+"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
+"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
+"\n"
 msgstr ""
+"ΞΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏΞΉ:\n"
+"  -nd  --no-directories            Ξ±Ο€ΞΏΟ†Ο…Ξ³Ξ® Ξ΄Ξ·ΞΌΞΉΞΏΟ…ΟΞ³Ξ―Ξ±Ο‚ ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³Ο‰Ξ½.\n"
+"  -x,  --force-directories         Ο…Ο€ΞΏΟ‡ΟΞµΟ‰Ο„ΞΉΞΊΞ® Ξ΄Ξ·ΞΌΞΉΞΏΟ…ΟΞ³Ξ―Ξ± ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³Ο‰Ξ½.\n"
+"  -nH, --no-host-directories       Ξ±Ο€ΞΏΟ†Ο…Ξ³Ξ® Ξ΄Ξ·ΞΌΞΉΞΏΟ…ΟΞ³Ξ―Ξ±Ο‚ host directories.\n"
+"  -P,  --directory-prefix=Ξ Ξ΅ΞΞΞ•ΞΞ‘  Ξ±Ο€ΞΏΞΈΞ®ΞΊΞµΟ…ΟƒΞ· Ξ±ΟΟ‡ΞµΞ―Ο‰Ξ½ ΟƒΟ„ΞΏ Ξ Ξ΅ΞΞΞ•ΞΞ‘/...\n"
+"       --cut-dirs=Ξ‘Ξ΅Ξ™ΞΞΞΞ£          Ξ±Ξ³Ξ½ΟΞ·ΟƒΞ· Ξ‘Ξ΅Ξ™ΞΞΞΞ£ ΟƒΟ„ΞΏΞΉΟ‡ΞµΞ―Ο‰Ξ½ Ξ±Ο€ΞΏΞΌΞ±ΞΊΟΟ…ΟƒΞΌΞ­Ξ½Ο‰Ξ½ ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³Ο‰Ξ½\n"
+"\n"
 
-#: src/main.c:585
+#: src/main.c:196
+#, fuzzy
 msgid ""
-"       --retr-symlinks         when recursing, get linked-to files (not "
-"dir).\n"
-msgstr ""
-
-#: src/main.c:587
-msgid "       --preserve-permissions  preserve remote file permissions.\n"
-msgstr ""
-
-#: src/main.c:591
-msgid "Recursive download:\n"
+"HTTP options:\n"
+"       --http-user=USER      set http user to USER.\n"
+"       --http-passwd=PASS    set http password to PASS.\n"
+"  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n"
+"  -E,  --html-extension      save all text/html documents with .html extension.\n"
+"       --ignore-length       ignore `Content-Length' header field.\n"
+"       --header=STRING       insert STRING among the headers.\n"
+"       --proxy-user=USER     set USER as proxy username.\n"
+"       --proxy-passwd=PASS   set PASS as proxy password.\n"
+"       --referer=URL         include `Referer: URL' header in HTTP request.\n"
+"  -s,  --save-headers        save the HTTP headers to file.\n"
+"  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
+"       --no-http-keep-alive  disable HTTP keep-alive (persistent connections).\n"
+"       --cookies=off         don't use cookies.\n"
+"       --load-cookies=FILE   load cookies from FILE before session.\n"
+"       --save-cookies=FILE   save cookies to FILE after session.\n"
+"       --post-data=STRING    use the POST method; send STRING as the data.\n"
+"       --post-file=FILE      use the POST method; send contents of FILE.\n"
+"\n"
 msgstr ""
+"Ξ•Ο€ΞΉΞ»ΞΏΞ³Ξ­Ο‚ HTTP:\n"
+"       --http-user=Ξ§Ξ΅Ξ—Ξ£Ξ¤Ξ—Ξ£   ΞΏΟΞΉΟƒΞΌΟΟ‚ Ο‡ΟΞ®ΟƒΟ„Ξ· http ΟƒΞµ Ξ§Ξ΅Ξ—Ξ£Ξ¤Ξ—.\n"
+"       --http-passwd=ΞΞ©Ξ”Ξ™ΞΞΞ£ ΞΏΟΞΉΟƒΞΌΟΟ‚ ΞΊΟ‰Ξ΄ΞΉΞΊΞΏΟ Ο‡ΟΞ®ΟƒΟ„Ξ· http ΟƒΞµ ΞΞ©Ξ”Ξ™ΞΞΞ£.\n"
+"  -C,  --cache=on/off        Ξ±Ο€ΞΏΟ„ΟΞΏΟ€Ξ®/Ο‡ΟΞ®ΟƒΞ· Ξ΄ΞµΞ΄ΞΏΞΌΞ­Ξ½Ο‰Ξ½ Ο„ΞΏΟ… Ξ΄ΞΉΞ±ΞΌΞµΟƒΞΏΞ»Ξ±Ξ²Ξ·Ο„Ξ® (ΞΊΞ±Ξ½ΞΏΞ½ΞΉΞΊΞ¬ ΞµΟ€ΞΉΟ„ΟΞ­Ο€ΞµΟ„Ξ±ΞΉ).\n"
+"  -E,  --html-extension      Ξ±Ο€ΞΏΞΈΞ®ΞΊΞµΟ…ΟƒΞ· ΟΞ»Ο‰Ξ½ Ο„Ο‰Ξ½ ΞµΞ³Ξ³ΟΞ¬Ο†Ο‰Ξ½ text/html ΞΌΞµ ΞΊΞ±Ο„Ξ¬Ξ»Ξ·ΞΎΞ· .html.\n"
+"       --ignore-length       Ξ±Ξ³Ξ½ΟΞ·ΟƒΞ· Ο„ΞΏΟ… Ο€ΞµΞ΄Ξ―ΞΏΟ… `Content-Length' Ο„Ξ·Ο‚ ΞΊΞµΟ†Ξ±Ξ»Ξ―Ξ΄Ξ±Ο‚.\n"
+"       --header=Ξ‘Ξ›Ξ¦Ξ‘Ξ΅Ξ™ΞΞΞ—Ξ¤Ξ™ΞΞ  ΞµΞΉΟƒΞ±Ξ³Ο‰Ξ³Ξ® Ο„ΞΏΟ… Ξ‘Ξ›Ξ¦Ξ‘Ξ΅Ξ™ΞΞΞ—Ξ¤Ξ™ΞΞ ΟƒΟ„Ξ·Ξ½ ΞΊΞµΟ†Ξ±Ξ»Ξ―Ξ΄Ξ±.\n"
+"       --proxy-user=Ξ§Ξ΅Ξ—Ξ£Ξ¤Ξ—Ξ£  ΞΏΟΞΉΟƒΞΌΟΟ‚ Ο„ΞΏΟ… Ξ§Ξ΅Ξ—Ξ£Ξ¤Ξ—Ξ£ Ξ³ΞΉΞ± Ο‡ΟΞ®ΟƒΟ„Ξ· Ο„ΞΏΟ… Ξ΄ΞΉΞ±ΞΌΞµΟƒΞΏΞ»Ξ±Ξ²Ξ·Ο„Ξ®.\n"
+"       --proxy-passwd=ΞΞ©Ξ”Ξ™ΞΞΞ£  ΞΏΟΞΉΟƒΞΌΟΟ‚ Ο„ΞΏΟ… ΞΞ©Ξ”Ξ™ΞΞΞ£ Ξ³ΞΉΞ± ΞΊΟ‰Ξ΄ΞΉΞΊΟΟ‚ ΟƒΟ„ΞΏ Ξ΄ΞΉΞ±ΞΌΞµΟƒΞΏΞ»Ξ±Ξ²Ξ·Ο„Ξ®.\n"
+"       --referer=URL         Ο‡ΟΞ®ΟƒΞ· ΞΊΞµΟ†Ξ±Ξ»Ξ―Ξ΄Ξ±Ο‚ `Referer: URL' ΟƒΟ„Ξ·Ξ½ Ξ±Ξ―Ο„Ξ·ΟƒΞ· HTTP.\n"
+"  -s,  --save-headers        Ξ±Ο€ΞΏΞΈΞ®ΞΊΞµΟ…ΟƒΞ· Ο„Ο‰Ξ½ HTTP ΞΊΞµΟ†Ξ±Ξ»Ξ―Ξ΄Ο‰Ξ½ ΟƒΞµ Ξ±ΟΟ‡ΞµΞ―ΞΏ.\n"
+"  -U,  --user-agent=Ξ Ξ΅Ξ‘ΞΞ¤ΞΞ΅Ξ‘Ξ£ Ο‡ΟΞ®ΟƒΞ· Ο„ΞΏΟ… Ξ Ξ΅Ξ‘ΞΞ¤ΞΞ΅Ξ‘Ξ£ Ξ±Ξ½Ο„Ξ― Ο„ΞΏΟ… Wget/Ξ•ΞΞ”ΞΞ£Ξ—.\n"
+"       --no-http-keep-alive  Ξ±Ο€ΞµΞ½ΞµΟΞ³ΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ· Ο„ΞΏΟ… HTTP keep-alive (ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞµΞΉΟ‚ Ξ΄ΞΉΞ±ΟΞΊΞµΞ―Ξ±Ο‚).\n"
+"       --cookies=off         Ξ½Ξ± ΞΌΞ· Ξ³Ξ―Ξ½ΞµΞΉ Ο‡ΟΞ®ΟƒΞ· Ο„Ο‰Ξ½ cookies.\n"
+"       --load-cookies=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ Ο†ΟΟΟ„Ο‰ΟƒΞ· cookies Ξ±Ο€Ο Ο„ΞΏ Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ Ο€ΟΞΉΞ½ Ο„Ξ· ΟƒΟ…Ξ½ΞµΞ΄ΟΞ―Ξ±.\n"
+"       --save-cookies=Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ Ξ±Ο€ΞΏΞΈΞ®ΞΊΞµΟ…ΟƒΞ· Ο„Ο‰Ξ½ cookies ΟƒΟ„ΞΏ Ξ‘Ξ΅Ξ§Ξ•Ξ™Ξ ΞΌΞµΟ„Ξ¬ Ο„Ξ· ΟƒΟ…Ξ½ΞµΞ΄ΟΞ―Ξ±.\n"
+"\n"
 
-#: src/main.c:593
-msgid "  -r,  --recursive          specify recursive download.\n"
+#: src/main.c:217
+msgid ""
+"HTTPS (SSL) options:\n"
+"       --sslcertfile=FILE     optional client certificate.\n"
+"       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
+"       --egd-file=FILE        file name of the EGD socket.\n"
+"       --sslcadir=DIR         dir where hash list of CA's are stored.\n"
+"       --sslcafile=FILE       file with bundle of CA's\n"
+"       --sslcerttype=0/1      Client-Cert type 0=PEM (default) / 1=ASN1 (DER)\n"
+"       --sslcheckcert=0/1     Check the server cert agenst given CA\n"
+"       --sslprotocol=0-3      choose SSL protocol; 0=automatic,\n"
+"                              1=SSLv2 2=SSLv3 3=TLSv1\n"
+"\n"
 msgstr ""
 
-#: src/main.c:595
+#: src/main.c:230
 msgid ""
-"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
-"infinite).\n"
+"FTP options:\n"
+"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
+"  -g,  --glob=on/off           turn file name globbing on or off.\n"
+"       --passive-ftp           use the \"passive\" transfer mode.\n"
+"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
+"\n"
 msgstr ""
+"Ξ•Ο€ΞΉΞ»ΞΏΞ³Ξ­Ο‚ FTP:\n"
+"  -nr, --dont-remove-listing Ξ½Ξ± ΞΌΞ· Ξ΄ΞΉΞ±Ξ³ΟΞ±Ο†ΞΏΟΞ½ Ο„Ξ± Ξ±ΟΟ‡ΞµΞ―Ξ± `.listing'.\n"
+"  -g,  --glob=on/off         (Ξ±Ο€)ΞµΞ½ΞµΟΞ³ΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ· Ο„Ξ±ΞΉΟΞΉΞ¬ΟƒΞΌΞ±Ο„ΞΏΟ‚ ΞΏΞ½ΞΏΞΌΞ¬Ο„Ο‰Ξ½ Ξ±ΟΟ‡ΞµΞ―Ο‰Ξ½.\n"
+"       --passive-ftp         Ο‡ΟΞ®ΟƒΞ· ΞΊΞ±Ο„Ξ¬ΟƒΟ„Ξ±ΟƒΞ·Ο‚ ΞΌΞµΟ„Ξ±Ο†ΞΏΟΞ¬Ο‚ \"passive\" Ξ³ΞΉΞ± Ο„ΞΏ FTP.\n"
+"       --retr-symlinks       ΞΊΞ±Ο„Ξ¬ Ο„Ξ·Ξ½ Ξ±Ξ½Ξ±Ξ΄ΟΞΏΞΌΞΉΞΊΞ® Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·, Ξ»Ξ®ΟΞ· Ξ±Ξ½Ξ±Ο†ΞµΟΟΞΌΞµΞ½Ο‰Ξ½ Ξ±ΟΟ‡ΞµΞ―Ο‰Ξ½ (ΟΟ‡ΞΉ ΞΊΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏΞΉ).\n"
+"\n"
 
-#: src/main.c:597
+#: src/main.c:237
+#, fuzzy
 msgid ""
+"Recursive retrieval:\n"
+"  -r,  --recursive          recursive download.\n"
+"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for infinite).\n"
 "       --delete-after       delete files locally after downloading them.\n"
-msgstr ""
-
-#: src/main.c:599
-msgid ""
-"  -k,  --convert-links      make links in downloaded HTML point to local "
-"files.\n"
-msgstr ""
-
-#: src/main.c:601
-msgid ""
+"  -k,  --convert-links      convert non-relative links to relative.\n"
 "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
-msgstr ""
-
-#: src/main.c:603
-msgid ""
 "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
+"  -p,  --page-requisites    get all images, etc. needed to display HTML page.\n"
+"       --strict-comments    turn on strict (SGML) handling of HTML comments.\n"
+"\n"
 msgstr ""
+"Ξ‘Ξ½Ξ±Ξ΄ΟΞΏΞΌΞΉΞΊΞ® Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ·:\n"
+"  -r,  --recursive             Ξ±Ξ½Ξ±Ξ΄ΟΞΏΞΌΞΉΞΊΞ® Ξ±Ξ½Ξ¬ΞΊΟ„Ξ·ΟƒΞ· -- Ο‡ΟΞ®ΟƒΞ· ΞΌΞµ ΟƒΟΞ½ΞµΟƒΞ·!\n"
+"  -l,  --level=Ξ‘Ξ΅Ξ™ΞΞΞΞ£         ΞΌΞ­Ξ³ΞΉΟƒΟ„ΞΏ Ξ²Ξ¬ΞΈΞΏΟ‚ Ξ±Ξ½Ξ±Ξ΄ΟΞΏΞΌΞ®Ο‚ (`inf' Ξ® 0 Ξ³ΞΉΞ± Ξ±Ο€ΞµΟΞΉΟΟΞΉΟƒΟ„ΞΏ).\n"
+"       --delete-after          Ξ΄ΞΉΞ±Ξ³ΟΞ±Ο†Ξ® Ξ±ΟΟ‡ΞµΞ―Ο‰Ξ½ Ο„ΞΏΟ€ΞΉΞΊΞ¬ ΞΌΞµΟ„Ξ¬ Ο„Ξ· ΞΌΞµΟ„Ξ±Ο†ΟΟΟ„Ο‰ΟƒΞ® Ο„ΞΏΟ…Ο‚.\n"
+"  -k,  --convert-links         ΞΌΞµΟ„Ξ±Ο„ΟΞΏΟ€Ξ® ΞΌΞ·-ΟƒΟ‡ΞµΟ„ΞΉΞΊΟΞ½ ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΟ‰Ξ½ ΟƒΞµ ΟƒΟ‡ΞµΟ„ΞΉΞΊΞΏΟΟ‚.\n"
+"  -K,  --backup-converted      Ο€ΟΞΉΞ½ Ο„Ξ· ΞΌΞµΟ„Ξ±Ο„ΟΞΏΟ€Ξ® Ο„ΞΏΟ… Ξ±ΟΟ‡ΞµΞ―ΞΏΟ… Ξ§, Ξ΄ΞΉΞ±Ο„Ξ®ΟΞ·ΟƒΞ· Ξ±Ξ½Ο„ΞΉΞ³ΟΞ¬Ο†ΞΏΟ… Ξ±ΟƒΟ†Ξ±Ξ»ΞµΞ―Ξ±Ο‚ X.orig.\n"
+"  -m,  --mirror                ΟƒΟΞ½Ο„ΞΏΞΌΞ· ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ®, ΞΉΟƒΞΏΞ΄ΟΞ½Ξ±ΞΌΞ· ΞΌΞµ -r -N -l inf -nr.\n"
+"  -p,  --page-requisites       Ξ»Ξ®ΟΞ· ΟΞ»Ο‰Ξ½ Ο„Ο‰Ξ½ ΞµΞΉΞΊΟΞ½Ο‰Ξ½, ΞΊΞ»Ο€. Ο€ΞΏΟ… Ξ±Ο€Ξ±ΞΉΟ„ΞΏΟΞ½Ο„Ξ±ΞΉ Ξ³ΞΉΞ± Ο„Ξ·Ξ½ ΞµΞΌΟ†Ξ¬Ξ½ΞΉΟƒΞ· ΟƒΞµΞ»Ξ―Ξ΄Ξ±Ο‚ HTML.\n"
+"\n"
 
-#: src/main.c:605
-msgid ""
-"  -p,  --page-requisites    get all images, etc. needed to display HTML "
-"page.\n"
-msgstr ""
-
-#: src/main.c:607
-msgid ""
-"       --strict-comments    turn on strict (SGML) handling of HTML "
-"comments.\n"
-msgstr ""
-
-#: src/main.c:611
-msgid "Recursive accept/reject:\n"
-msgstr ""
-
-#: src/main.c:613
-msgid ""
-"  -A,  --accept=LIST               comma-separated list of accepted "
-"extensions.\n"
-msgstr ""
-
-#: src/main.c:615
-msgid ""
-"  -R,  --reject=LIST               comma-separated list of rejected "
-"extensions.\n"
-msgstr ""
-
-#: src/main.c:617
-msgid ""
-"  -D,  --domains=LIST              comma-separated list of accepted "
-"domains.\n"
-msgstr ""
-
-#: src/main.c:619
-msgid ""
-"       --exclude-domains=LIST      comma-separated list of rejected "
-"domains.\n"
-msgstr ""
-
-#: src/main.c:621
-msgid ""
-"       --follow-ftp                follow FTP links from HTML documents.\n"
-msgstr ""
-
-#: src/main.c:623
-msgid ""
-"       --follow-tags=LIST          comma-separated list of followed HTML "
-"tags.\n"
-msgstr ""
-
-#: src/main.c:625
-msgid ""
-"       --ignore-tags=LIST          comma-separated list of ignored HTML "
-"tags.\n"
-msgstr ""
-
-#: src/main.c:627
-msgid ""
-"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
-msgstr ""
-
-#: src/main.c:629
-msgid "  -L,  --relative                  follow relative links only.\n"
-msgstr ""
-
-#: src/main.c:631
-msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
-msgstr ""
-
-#: src/main.c:633
-msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
-msgstr ""
-
-#: src/main.c:635
-msgid ""
-"  -np, --no-parent                 don't ascend to the parent directory.\n"
+#: src/main.c:248
+msgid ""
+"Recursive accept/reject:\n"
+"  -A,  --accept=LIST                comma-separated list of accepted extensions.\n"
+"  -R,  --reject=LIST                comma-separated list of rejected extensions.\n"
+"  -D,  --domains=LIST               comma-separated list of accepted domains.\n"
+"       --exclude-domains=LIST       comma-separated list of rejected domains.\n"
+"       --follow-ftp                 follow FTP links from HTML documents.\n"
+"       --follow-tags=LIST           comma-separated list of followed HTML tags.\n"
+"  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML tags.\n"
+"  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
+"  -L,  --relative                   follow relative links only.\n"
+"  -I,  --include-directories=LIST   list of allowed directories.\n"
+"  -X,  --exclude-directories=LIST   list of excluded directories.\n"
+"  -np, --no-parent                  don't ascend to the parent directory.\n"
+"\n"
 msgstr ""
+"Ξ‘Ξ½Ξ±Ξ΄ΟΞΏΞΌΞΉΞΊΞ® Ξ±Ο€ΞΏΞ΄ΞΏΟ‡Ξ®/Ξ±Ο€ΟΟΟΞΉΟΞ·:\n"
+"  -A,  --accept=Ξ›Ξ™Ξ£Ξ¤Ξ‘               Ξ»Ξ―ΟƒΟ„Ξ± Ξ΄ΞΉΞ±Ο‡Ο‰ΟΞΉΞ¶ΟΞΌΞµΞ½Ξ· ΞΌΞµ ΞΊΟΞΌΞΌΞ± Ξ±Ο€Ο Ξ±Ο€ΞΏΞ΄ΞµΞΊΟ„Ξ­Ο‚ ΞΊΞ±Ο„Ξ±Ξ»Ξ®ΞΎΞµΞΉΟ‚.\n"
+"  -R,  --reject=Ξ›Ξ™Ξ£Ξ¤Ξ‘               Ξ»Ξ―ΟƒΟ„Ξ± Ξ΄ΞΉΞ±Ο‡Ο‰ΟΞΉΞ¶ΟΞΌΞµΞ½Ξ· ΞΌΞµ ΞΊΟΞΌΞΌΞ± Ξ±Ο€Ο ΞΌΞ·-Ξ±Ο€ΞΏΞ΄ΞµΞΊΟ„Ξ­Ο‚ ΞΊΞ±Ο„Ξ±Ξ»Ξ®ΞΎΞµΞΉΟ‚.\n"
+"  -D,  --domains=Ξ›Ξ™Ξ£Ξ¤Ξ‘              Ξ»Ξ―ΟƒΟ„Ξ± Ξ΄ΞΉΞ±Ο‡Ο‰ΟΞΉΞ¶ΟΞΌΞµΞ½Ξ· ΞΌΞµ ΞΊΟΞΌΞΌΞ± Ξ±Ο€Ο Ξ±Ο€ΞΏΞ΄ΞµΞΊΟ„Ξ¬ ΞµΟ€ΞΉΞΈΞ®ΞΌΞ±Ο„Ξ±.\n"
+"       --exclude-domains=Ξ›Ξ™Ξ£Ξ¤Ξ‘      Ξ»Ξ―ΟƒΟ„Ξ± Ξ΄ΞΉΞ±Ο‡Ο‰ΟΞΉΞ¶ΟΞΌΞµΞ½Ξ· ΞΌΞµ ΞΊΟΞΌΞΌΞ± Ξ±Ο€Ο ΞΌΞ·-Ξ±Ο€ΞΏΞ΄ΞµΞΊΟ„Ξ¬ ΞµΟ€ΞΉΞΈΞ®ΞΌΞ±Ο„Ξ±.\n"
+"       --follow-ftp                 Ξ±ΞΊΞΏΞ»ΞΏΟΞΈΞ·ΟƒΞ· ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΟ‰Ξ½ FTP Ξ±Ο€Ο Ξ­Ξ³Ξ³ΟΞ±Ο†Ξ± HTML.\n"
+"       --follow-tags=Ξ›Ξ™Ξ£Ξ¤Ξ‘          Ξ»Ξ―ΟƒΟ„Ξ± Ξ΄ΞΉΞ±Ο‡Ο‰ΟΞΉΞ¶ΟΞΌΞµΞ½Ξ· ΞΌΞµ ΞΊΟΞΌΞΌΞ± ΞΌΞµ ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΞΏΟ…Ο‚ Ο€ΞΏΟ… Ξ­Ο‡ΞΏΟ…Ξ½ Ξ±ΞΊΞΏΞ»ΞΏΟ…ΞΈΞ·ΞΈΞµΞ―.\n"
+"  -G,  --ignore-tags=Ξ›Ξ™Ξ£Ξ¤Ξ‘          Ξ»Ξ―ΟƒΟ„Ξ± Ξ΄ΞΉΞ±Ο‡Ο‰ΟΞΉΞ¶ΟΞΌΞµΞ½Ξ· ΞΌΞµ ΞΊΟΞΌΞΌΞ± ΞΌΞµ ΟƒΟ…Ξ½Ξ΄Ξ­ΟƒΞΌΞΏΟ…Ο‚ Ο€ΞΏΟ… Ξ­Ο‡ΞΏΟ…Ξ½ Ξ±Ξ³Ξ½ΞΏΞ·ΞΈΞµΞ―.\n"
+"  -H,  --span-hosts                 ΞµΟ€Ξ―ΟƒΞΊΞµΟΞ· ΞΊΞ±ΞΉ ΞΎΞ­Ξ½Ο‰Ξ½ Ξ΄ΞΉΞ±ΞΊΞΏΞΌΞΉΟƒΟ„ΟΞ½ ΞΊΞ±Ο„Ξ¬ Ο„Ξ·Ξ½ Ξ±Ξ½Ξ±Ξ΄ΟΞΏΞΌΞ®.\n"
+"  -L,  --relative                   Ξ±ΞΊΞΏΞ»ΞΏΟΞΈΞ·ΟƒΞ· ΞΌΟΞ½ΞΏ ΟƒΟ‡ΞµΟ„ΞΉΞΊΟΞ½ URL.\n"
+"  -I,  --include-directories=Ξ›Ξ™Ξ£Ξ¤Ξ‘  Ξ»Ξ―ΟƒΟ„Ξ± ΞµΟ€ΞΉΟ„ΟΞµΟ€Ο„ΟΞ½ ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³Ο‰Ξ½.\n"
+"  -X,  --exclude-directories=Ξ›Ξ™Ξ£Ξ¤Ξ‘  Ξ»Ξ―ΟƒΟ„Ξ± ΞΌΞ·-ΞµΟ€ΞΉΟ„ΟΞµΟ€Ο„ΟΞ½ ΞΊΞ±Ο„Ξ±Ξ»ΟΞ³Ο‰Ξ½.\n"
+"  -np, --no-parent                  Ξ±Ο€ΞµΞ½ΞµΟΞ³ΞΏΟ€ΞΏΞ―Ξ·ΟƒΞ· Ο€ΟΟΟƒΞ²Ξ±ΟƒΞ·Ο‚ ΞΊΞ±ΞΉ ΟƒΟ„ΞΏ Ξ³ΞΏΞ½ΞΉΞΊΟ ΞΊΞ±Ο„Ξ¬Ξ»ΞΏΞ³ΞΏ.\n"
+"\n"
 
-#: src/main.c:639
+#: src/main.c:263
 msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
-msgstr "Στείλτε αναφορές σφαλμάτων και προτάσεις στο <bug-wget@gnu.org>.\n"
+msgstr "Ξ£Ο„ΞµΞ―Ξ»Ο„Ξµ Ξ±Ξ½Ξ±Ο†ΞΏΟΞ­Ο‚ ΟƒΟ†Ξ±Ξ»ΞΌΞ¬Ο„Ο‰Ξ½ ΞΊΞ±ΞΉ Ο€ΟΞΏΟ„Ξ¬ΟƒΞµΞΉΟ‚ ΟƒΟ„ΞΏ <bug-wget@gnu.org>.\n"
 
-#: src/main.c:644
+#: src/main.c:465
 #, c-format
-msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, ένα μη-διαλογικό δικτυακό πρόγραμμα ανάκτησης αρχείων.\n"
+msgid "%s: debug support not compiled in.\n"
+msgstr "%s: Ξ· Ο…Ο€ΞΏΟƒΟ„Ξ®ΟΞΉΞΎΞ· ΞµΞΊΟƒΟ†Ξ±Ξ»ΞΌΞ¬Ο„Ο‰ΟƒΞ·Ο‚ Ξ΄ΞµΞ½ Ξ­Ο‡ΞµΞΉ ΟƒΟ…ΞΌΟ€ΞµΟΞΉΞ»Ξ·Ο†ΞΈΞµΞ― ΟƒΟ„Ξ· ΞΌΞµΟ„Ξ±Ξ³Ξ»ΟΟ„Ο„ΞΉΟƒΞ·.\n"
 
-#: src/main.c:658
+#: src/main.c:517
 #, fuzzy
-msgid "Copyright (C) 2005 Free Software Foundation, Inc.\n"
-msgstr ""
-"Πνευματικά Δικαιώματα (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software "
-"Foundation, Inc.\n"
+msgid "Copyright (C) 2003 Free Software Foundation, Inc.\n"
+msgstr "Ξ Ξ½ΞµΟ…ΞΌΞ±Ο„ΞΉΞΊΞ¬ Ξ”ΞΉΞΊΞ±ΞΉΟΞΌΞ±Ο„Ξ± (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
 
-#: src/main.c:660
+#: src/main.c:519
 msgid ""
 "This program is distributed in the hope that it will be useful,\n"
 "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
 "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
 "GNU General Public License for more details.\n"
 msgstr ""
-"Αυτό το πρόγραμμα διανέμεται με την ελπίδα ότι θα είναι χρήσιμο,\n"
-"αλλά ΧΩΡΙΣ ΚΑΜΙΑ ΕΓΓΫΗΣΗ· χωρίς ούτε έμμεση εγγύηση\n"
-"ΛΕΙΤΟΥΡΓΙΚΟΤΗΤΑΣ ή ΚΑΤΑΛΛΗΛΟΤΗΤΑΣ ΓΙΑ ΕΝΑ ΣΥΓΚΕΚΡΙΜΕΝΟ ΣΚΟΠΟ.\n"
-"Αναφερθείτε στη Γενική Δημόσια ¶δεια GNU για περισσότερες λεπτομέρειες.\n"
+"Ξ‘Ο…Ο„Ο Ο„ΞΏ Ο€ΟΟΞ³ΟΞ±ΞΌΞΌΞ± Ξ΄ΞΉΞ±Ξ½Ξ­ΞΌΞµΟ„Ξ±ΞΉ ΞΌΞµ Ο„Ξ·Ξ½ ΞµΞ»Ο€Ξ―Ξ΄Ξ± ΟΟ„ΞΉ ΞΈΞ± ΞµΞ―Ξ½Ξ±ΞΉ Ο‡ΟΞ®ΟƒΞΉΞΌΞΏ,\n"
+"Ξ±Ξ»Ξ»Ξ¬ Ξ§Ξ©Ξ΅Ξ™Ξ£ ΞΞ‘ΞΞ™Ξ‘ Ξ•Ξ“Ξ“Ξ«Ξ—Ξ£Ξ—Β· Ο‡Ο‰ΟΞ―Ο‚ ΞΏΟΟ„Ξµ Ξ­ΞΌΞΌΞµΟƒΞ· ΞµΞ³Ξ³ΟΞ·ΟƒΞ·\n"
+"Ξ›Ξ•Ξ™Ξ¤ΞΞ¥Ξ΅Ξ“Ξ™ΞΞΞ¤Ξ—Ξ¤Ξ‘Ξ£ Ξ® ΞΞ‘Ξ¤Ξ‘Ξ›Ξ›Ξ—Ξ›ΞΞ¤Ξ—Ξ¤Ξ‘Ξ£ Ξ“Ξ™Ξ‘ Ξ•ΞΞ‘ Ξ£Ξ¥Ξ“ΞΞ•ΞΞ΅Ξ™ΞΞ•ΞΞ Ξ£ΞΞΞ Ξ.\n"
+"Ξ‘Ξ½Ξ±Ο†ΞµΟΞΈΞµΞ―Ο„Ξµ ΟƒΟ„Ξ· Ξ“ΞµΞ½ΞΉΞΊΞ® Ξ”Ξ·ΞΌΟΟƒΞΉΞ± Ξ†Ξ΄ΞµΞΉΞ± GNU Ξ³ΞΉΞ± Ο€ΞµΟΞΉΟƒΟƒΟΟ„ΞµΟΞµΟ‚ Ξ»ΞµΟ€Ο„ΞΏΞΌΞ­ΟΞµΞΉΞµΟ‚.\n"
 
-#: src/main.c:665
+#: src/main.c:524
 #, fuzzy
 msgid ""
 "\n"
 "Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
 msgstr ""
 "\n"
-"Γράφτηκε αρχικά από τον Hrvoje Niksic <hniksic@arsdigita.com>.\n"
+"Ξ“ΟΞ¬Ο†Ο„Ξ·ΞΊΞµ Ξ±ΟΟ‡ΞΉΞΊΞ¬ Ξ±Ο€Ο Ο„ΞΏΞ½ Hrvoje Niksic <hniksic@arsdigita.com>.\n"
+
+#: src/main.c:703
+#, c-format
+msgid "%s: illegal option -- `-n%c'\n"
+msgstr "%s: ΞΌΞ· Ξ±Ο€ΞΏΞ΄ΞµΞΊΟ„Ξ® ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ® -- `-n%c'\n"
 
 #. #### Something nicer should be printed here -- similar to the
 #. pre-1.5 `--help' page.
-#: src/main.c:711 src/main.c:780 src/main.c:859
+#: src/main.c:706 src/main.c:748 src/main.c:794
 #, c-format
 msgid "Try `%s --help' for more options.\n"
-msgstr "Δοκιμάστε `%s --help' για περισσότερες επιλογές ρυθμίσεων.\n"
-
-#: src/main.c:777
-#, c-format
-msgid "%s: illegal option -- `-n%c'\n"
-msgstr "%s: μη αποδεκτή επιλογή -- `-n%c'\n"
+msgstr "Ξ”ΞΏΞΊΞΉΞΌΞ¬ΟƒΟ„Ξµ `%s --help' Ξ³ΞΉΞ± Ο€ΞµΟΞΉΟƒΟƒΟΟ„ΞµΟΞµΟ‚ ΞµΟ€ΞΉΞ»ΞΏΞ³Ξ­Ο‚ ΟΟ…ΞΈΞΌΞ―ΟƒΞµΟ‰Ξ½.\n"
 
-#: src/main.c:830
-#, c-format
+#: src/main.c:774
 msgid "Can't be verbose and quiet at the same time.\n"
-msgstr "Δεν μπορώ να είμαι επεξηγηματικός και ταυτόχρονα σιωπηλός.\n"
+msgstr "Ξ”ΞµΞ½ ΞΌΟ€ΞΏΟΟ Ξ½Ξ± ΞµΞ―ΞΌΞ±ΞΉ ΞµΟ€ΞµΞΎΞ·Ξ³Ξ·ΞΌΞ±Ο„ΞΉΞΊΟΟ‚ ΞΊΞ±ΞΉ Ο„Ξ±Ο…Ο„ΟΟ‡ΟΞΏΞ½Ξ± ΟƒΞΉΟ‰Ο€Ξ·Ξ»ΟΟ‚.\n"
 
-#: src/main.c:836
-#, c-format
+#: src/main.c:780
 msgid "Can't timestamp and not clobber old files at the same time.\n"
-msgstr ""
-"Δεν μπορώ να χρησιμοποιώ χρονικές αναφορές και ταυτόχρονα να μην υποκαθιστώ "
-"τα αρχεία βάση των αναφορών.\n"
-
-#: src/main.c:844
-#, c-format
-msgid "Cannot specify both --inet4-only and --inet6-only.\n"
-msgstr ""
+msgstr "Ξ”ΞµΞ½ ΞΌΟ€ΞΏΟΟ Ξ½Ξ± Ο‡ΟΞ·ΟƒΞΉΞΌΞΏΟ€ΞΏΞΉΟ Ο‡ΟΞΏΞ½ΞΉΞΊΞ­Ο‚ Ξ±Ξ½Ξ±Ο†ΞΏΟΞ­Ο‚ ΞΊΞ±ΞΉ Ο„Ξ±Ο…Ο„ΟΟ‡ΟΞΏΞ½Ξ± Ξ½Ξ± ΞΌΞ·Ξ½ Ο…Ο€ΞΏΞΊΞ±ΞΈΞΉΟƒΟ„Ο Ο„Ξ± Ξ±ΟΟ‡ΞµΞ―Ξ± Ξ²Ξ¬ΟƒΞ· Ο„Ο‰Ξ½ Ξ±Ξ½Ξ±Ο†ΞΏΟΟΞ½.\n"
 
 #. No URL specified.
-#: src/main.c:854
+#: src/main.c:789
 #, c-format
 msgid "%s: missing URL\n"
-msgstr "%s: παραλείφθηκε το URL\n"
+msgstr "%s: Ο€Ξ±ΟΞ±Ξ»ΞµΞ―Ο†ΞΈΞ·ΞΊΞµ Ο„ΞΏ URL\n"
 
-#: src/main.c:963
+#: src/main.c:905
 #, c-format
 msgid "No URLs found in %s.\n"
-msgstr "Δεν βρέθηκαν URL στο %s.\n"
+msgstr "Ξ”ΞµΞ½ Ξ²ΟΞ­ΞΈΞ·ΞΊΞ±Ξ½ URL ΟƒΟ„ΞΏ %s.\n"
 
-#: src/main.c:972
+#: src/main.c:914
 #, c-format
 msgid ""
 "\n"
