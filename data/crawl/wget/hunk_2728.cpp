 "Content-Type: text/plain; charset=ISO-8859-8\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
-#: src/connect.c:199
-#, c-format
-msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
-msgstr ""
-
-# FIXME: this is lame!  The method of printing "Frobbing...done" etc.
-# does not lend itself to good translations into languages where
-# such sentences have a different structure, and should be rethought.
-#: src/connect.c:271
-#, fuzzy, c-format
-msgid "Connecting to %s|%s|:%d... "
-msgstr "%s:%hu-ל תורשקתה ןויסנ"
-
-# FIXME: this is lame!  The method of printing "Frobbing...done" etc.
-# does not lend itself to good translations into languages where
-# such sentences have a different structure, and should be rethought.
-#: src/connect.c:274
-#, fuzzy, c-format
-msgid "Connecting to %s:%d... "
-msgstr "%s:%hu-ל תורשקתה ןויסנ"
-
-# Pay attention: this is written to the RIGHT of "Connecting.." !!
-#: src/connect.c:335
-#, fuzzy
-msgid "connected.\n"
-msgstr "ב החלצה\n"
-
-#: src/convert.c:176
-#, c-format
-msgid "Converted %d files in %.*f seconds.\n"
-msgstr ""
-
-# Note: the following 5 messages are all written on the same line!
-#: src/convert.c:202
-#, c-format
-msgid "Converting %s... "
-msgstr "%s תרמה"
-
-#: src/convert.c:215
-msgid "nothing to do.\n"
-msgstr "ב ךרוצ ןיא\n"
-
-#: src/convert.c:223 src/convert.c:247
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "ב (%s: %s) םירושיק תרמה תלקת\n"
-
-#: src/convert.c:238
-#, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "`%s' קוחמל ןויסנב (%s) הלקת\n"
-
-#: src/convert.c:447
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "%s-ל יוביגכ %s תביתכב (%s) הלקת\n"
-
-#: src/cookies.c:619
+#: src/cookies.c:588
 #, c-format
 msgid "Error in Set-Cookie, field `%s'"
 msgstr "יוגש Set-Cookie תרתוכ לש `%s' הדש"
 
-#: src/cookies.c:643
-#, fuzzy, c-format
-msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+#: src/cookies.c:612
+#, c-format
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
+msgstr ".`%c' ות תברקב Set-Cookie תרתוכ לש יוגש ריבחת\n"
+
+#: src/cookies.c:620
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
 msgstr ".ידמ םדקומ תמייתסמ תזורחמה :Set-Cookie תרתוכ לש יוגש ריבחת\n"
 
-#: src/cookies.c:1469
+#: src/cookies.c:1352
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "`%s' תויגוע ץבוק תחיתפ תעב (%s) הלקת העריא\n"
 
-#: src/cookies.c:1481
+#: src/cookies.c:1364
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "`%s'-ל הביתכב (%s) הלקת\n"
 
-#: src/cookies.c:1484
+#: src/cookies.c:1368
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "`%s' תריגסב (%s) הלקת\n"
 
-#: src/ftp-ls.c:841
+#: src/ftp-ls.c:787
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr ".Unix טמרופ ומכ שרפל הסנמ ,רכומ-יתלב גוסמ םיצבק תמישר\n"
 
-#: src/ftp-ls.c:887 src/ftp-ls.c:889
+#: src/ftp-ls.c:832 src/ftp-ls.c:834
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "/%s היקיתב %s:%d-ב םיצבק תמישר"
 
-#: src/ftp-ls.c:912
-#, c-format
+#: src/ftp-ls.c:856
 msgid "time unknown       "
 msgstr "  עודי אל ןוכדע ןמז"
 
-#: src/ftp-ls.c:916
-#, c-format
+#: src/ftp-ls.c:860
 msgid "File        "
 msgstr "        ץבוק"
 
-#: src/ftp-ls.c:919
-#, c-format
+#: src/ftp-ls.c:863
 msgid "Directory   "
 msgstr "       היקית"
 
-#: src/ftp-ls.c:922
-#, c-format
+#: src/ftp-ls.c:866
 msgid "Link        "
 msgstr "       רושיק"
 
-#: src/ftp-ls.c:925
-#, c-format
+#: src/ftp-ls.c:869
 msgid "Not sure    "
 msgstr " עודי אל גוס"
 
-#: src/ftp-ls.c:943
+#: src/ftp-ls.c:887
 #, c-format
 msgid " (%s bytes)"
 msgstr "  (םיתב %s)"
 
-# FIXME: This 3-part message will look totally messed up in a
-# right-to-left language such as Hebrew!  The maintainers
-# should _really_ fix the code!
-#: src/ftp.c:226
-#, c-format
-msgid "Length: %s"
-msgstr "%s :ךרוא"
-
-#: src/ftp.c:232 src/http.c:1857
+# FIXME: this is lame!  The method of printing "Frobbing...done" etc.
+# does not lend itself to good translations into languages where
+# such sentences have a different structure, and should be rethought.
+#. Login to the server:
+#. First: Establish the control connection.
+#: src/ftp.c:150 src/http.c:624
 #, c-format
-msgid ", %s (%s) remaining"
-msgstr ""
+msgid "Connecting to %s:%hu... "
+msgstr "%s:%hu-ל תורשקתה ןויסנ"
 
-#: src/ftp.c:236 src/http.c:1861
+#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
 #, c-format
-msgid ", %s remaining"
-msgstr ""
-
-#: src/ftp.c:239
-msgid " (unauthoritative)\n"
-msgstr " (הכרעה)\n"
+msgid "Connection to %s:%hu refused.\n"
+msgstr ".החדנ %s:%hu-ל תורשקתה ןויסנ\n"
 
+# Pay attention: this is written to the RIGHT of "Connecting.." !!
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:314
+#: src/ftp.c:193 src/http.c:652
+msgid "connected!\n"
+msgstr "ב החלצה\n"
+
+#: src/ftp.c:194
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "%s-כ הסינכ ןויסנ"
 
-#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
-#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
-#: src/ftp.c:866
+#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
+#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
 msgid "Error in server response, closing control connection.\n"
 msgstr ".רגסנ הרקבה קיפא ,תרש לש יוגש הנעמ\n"
 
-#: src/ftp.c:334
+#: src/ftp.c:211
 msgid "Error in server greeting.\n"
 msgstr ".יוגש תרשה לש החיתפ רסמ\n"
 
-#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
-#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
+#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
+#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
 msgid "Write failed, closing control connection.\n"
 msgstr ".רגסנ הרקבה קיפא ,הביתכב הלקת\n"
 
-#: src/ftp.c:347
+#: src/ftp.c:226
 msgid "The server refuses login.\n"
 msgstr ".הסינכ השרמ וניא תרשה\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:233
 msgid "Login incorrect.\n"
 msgstr ".היוגש הסינכ\n"
 
 # Note: this is written to the right of "Logging in as", with no newline!
-#: src/ftp.c:359
+#: src/ftp.c:240
 msgid "Logged in!\n"
 msgstr "ב החלצה\n"
 
-#: src/ftp.c:381
+#: src/ftp.c:265
 msgid "Server error, can't determine system type.\n"
 msgstr ".תכרעמ גוס עובקל תורשפא ןיא ,תרש לש יוגש הנעמ\n"
 
-#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
+#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
 msgid "done.    "
 msgstr " <== החלצהב עצוב"
 
-#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
+#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
 msgid "done.\n"
 msgstr " <== החלצהב עצוב\n"
 
-#: src/ftp.c:469
+#: src/ftp.c:353
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr ".רגסנ הרקבה קיפא ,רכומ וניא `%c' הרבעה גוס\n"
 
-#: src/ftp.c:481
+#: src/ftp.c:366
 msgid "done.  "
 msgstr " <== החלצהב עצוב"
 
-#: src/ftp.c:487
+#: src/ftp.c:372
 msgid "==> CWD not needed.\n"
 msgstr "==> .תשרדנ הניא CWD תדוקפ\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:445
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-".תמייק הניא `%s' היקית\n"
-"\n"
+msgid "No such directory `%s'.\n\n"
+msgstr ".תמייק הניא `%s' היקית\n\n"
 
 #. do not CWD
-#: src/ftp.c:595
+#: src/ftp.c:463
 msgid "==> CWD not required.\n"
 msgstr "==> .CWD תדוקפב ךרוצ ןיא\n"
 
-#: src/ftp.c:654
+#: src/ftp.c:497
 msgid "Cannot initiate PASV transfer.\n"
 msgstr ".PASV תטישב הרבעה עינתהל ןתינ אל\n"
 
-#: src/ftp.c:658
+#: src/ftp.c:501
 msgid "Cannot parse PASV response.\n"
 msgstr ".PASV תדוקפל הנעמ שרפל ןתינ אל\n"
 
-#: src/ftp.c:676
+#: src/ftp.c:515
 #, c-format
-msgid "couldn't connect to %s port %d: %s\n"
-msgstr ""
+msgid "Will try connecting to %s:%hu.\n"
+msgstr ".%s:%hu-ל רשקתהל הסנמ\n"
 
-#: src/ftp.c:724
+#: src/ftp.c:602
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr ".(%s) תורשקתה תלקת\n"
 
-#: src/ftp.c:730
+#: src/ftp.c:618
 msgid "Invalid PORT.\n"
 msgstr ".PORT תלקת\n"
 
-#: src/ftp.c:776
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
-msgstr ""
-"\n"
-".הלחתהמ ליחתמ ;הלשכנ REST תדוקפ\n"
+#: src/ftp.c:671
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
+msgstr "\n.`%s' לש םדוק ןכות קוחמל יאשר ינניא ;הלשכנ REST תדוקפ\n"
+
+#: src/ftp.c:678
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\n.הלחתהמ ליחתמ ;הלשכנ REST תדוקפ\n"
 
-#: src/ftp.c:837
+#: src/ftp.c:727
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-".םייק וניא `%s' ץבוק\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr ".םייק וניא `%s' ץבוק\n\n"
 
-#: src/ftp.c:884
+#: src/ftp.c:775
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-".םימייק היקית וא ץבוק וניא `%s'\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr ".םימייק היקית וא ץבוק וניא `%s'\n\n"
 
-#. We cannot just invent a new name and use it (which is
-#. what functions like unique_create typically do)
-#. because we told the user we'd use this name.
-#. Instead, return and retry the download.
-#: src/ftp.c:946 src/http.c:1913
+# FIXME: This 3-part message will look totally messed up in a
+# right-to-left language such as Hebrew!  The maintainers
+# should _really_ fix the code!
+#: src/ftp.c:859 src/ftp.c:867
 #, c-format
-msgid "%s has sprung into existence.\n"
-msgstr ""
+msgid "Length: %s"
+msgstr "%s :ךרוא"
+
+#: src/ftp.c:861 src/ftp.c:869
+#, c-format
+msgid " [%s to go]"
+msgstr " [%s דוע ראשנ]"
 
-#: src/ftp.c:1008
+#: src/ftp.c:871
+msgid " (unauthoritative)\n"
+msgstr " (הכרעה)\n"
+
+#: src/ftp.c:898
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr ".רגסנ הרקבה קיפא ,%s-ב (%s) הלקת\n"
 
 # Note: the rightmost colon is for the message that will be printed
 # later.
-#: src/ftp.c:1016
+#: src/ftp.c:906
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "(%s :העש  %s :בצק) םינותנה קיפאב (%s) הלקת :"
 
 # Note: this and the next one don't have the period because they get
 # printed to the right of the previous message.
-#: src/ftp.c:1031
+#: src/ftp.c:923
 msgid "Control connection closed.\n"
 msgstr "רגסנ הרקבה קיפא\n"
 
-#: src/ftp.c:1049
+#: src/ftp.c:941
 msgid "Data transfer aborted.\n"
 msgstr "הקספוה םינותנ תרבעה\n"
 
-#: src/ftp.c:1114
+#: src/ftp.c:1005
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr ".ותוא ךושמל ךרוצ ןיא ,ןאכ רבכ `%s' ץבוק\n"
 
-#: src/ftp.c:1182 src/http.c:2130
+#: src/ftp.c:1075 src/http.c:1502
 #, c-format
 msgid "(try:%2d)"
 msgstr "(%2d 'סמ ןויסנ)"
 
 # I give up!
-#: src/ftp.c:1252 src/http.c:2409
-#, fuzzy, c-format
-msgid ""
-"%s (%s) - `%s' saved [%s]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' saved [%ld]\n"
-"\n"
+#: src/ftp.c:1139 src/http.c:1753
+#, c-format
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
+msgstr "%s (%s) - `%s' saved [%ld]\n\n"
 
-#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
+#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
 #, c-format
 msgid "Removing %s.\n"
 msgstr ".%s קחומ\n"
 
-#: src/ftp.c:1336
+#: src/ftp.c:1221
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr ".םיצבק תמישר תלבקל ינמז ץבוקכ `%s'-ב שמתשמ\n"
 
-#: src/ftp.c:1351
+#: src/ftp.c:1233
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr ".קחמנ `%s' ץבוק\n"
 
-#: src/ftp.c:1386
+#: src/ftp.c:1269
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr ".וילע הלוע %d לעופב קמוע ךא ,%d אוה יברימ היסרוקר קמוע\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1456
+#: src/ftp.c:1330
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
 msgstr ".ךשמיי אל ץבוקה -- `%s' ימוקמ ץבוקמ רתוי ינכדע וניא קחורמ ץבוק\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1463
+#: src/ftp.c:1337
 #, c-format
-msgid ""
-"Remote file is newer than local file `%s' -- retrieving.\n"
-"\n"
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
 msgstr ".ךשמיי ץבוקה -- `%s' ימוקמ ץבוקמ רתוי ינכדע קחורמ ץבוק\n"
 
 #. Sizes do not match
-#: src/ftp.c:1470
-#, fuzzy, c-format
-msgid ""
-"The sizes do not match (local %s) -- retrieving.\n"
-"\n"
+#: src/ftp.c:1344
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
 msgstr ".ךשמיי ץבוקה -- (%ld :ימוקמ ץבוק) ההז וניא לדוג\n"
 
-#: src/ftp.c:1488
+#: src/ftp.c:1361
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr ".טמשוי ץבוקה ,רכומ וניא ילובמיס רושיק ץבוק לש ומש\n"
 
-#: src/ftp.c:1505
+#: src/ftp.c:1378
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
 msgstr ".םייק רבכ %s -> %s ילובמיס רושיק\n"
 
-#: src/ftp.c:1513
+#: src/ftp.c:1386
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr ".%s -> %s ילובמיס רושיק רצוי\n"
 
-#: src/ftp.c:1523
+#: src/ftp.c:1397
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr ".`%s' ץבוק טימשמ ,םיכמתנ םניא ילובמיס רושיק יצבק\n"
 
-#: src/ftp.c:1535
+#: src/ftp.c:1409
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr ".`%s' היקית טימשמ\n"
 
-#: src/ftp.c:1544
+#: src/ftp.c:1418
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr ".ךמתנ וניא וא רכומ-יתלב גוסמ וניה `%s' ץבוק\n"
 
-#: src/ftp.c:1571
+#: src/ftp.c:1445
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr ".היוגש ןמז תמיתח לעב אוה `%s' ץבוק\n"
 
-#: src/ftp.c:1599
+#: src/ftp.c:1466
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ".רתוי בר %d ןקמוע ןכש וכשמיי אל תויקית ;%d יברימ קמוע\n"
 
-#: src/ftp.c:1649
+#: src/ftp.c:1512
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr ".המישרהמ האצוה וא הללכנ אלש םושמ `%s'-ל סנכיהלמ ענמנ\n"
 
-#: src/ftp.c:1715 src/ftp.c:1729
+#: src/ftp.c:1559
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr ".החדנ `%s'\n"
