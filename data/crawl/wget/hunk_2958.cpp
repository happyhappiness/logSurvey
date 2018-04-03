 "Content-Type: text/plain; charset=ISO-8859-8\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
-#: src/cookies.c:588
+#: src/connect.c:200
 #, c-format
-msgid "Error in Set-Cookie, field `%s'"
-msgstr "���� Set-Cookie ����� �� `%s' ���"
+msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
+msgstr ""
+
+# FIXME: this is lame!  The method of printing "Frobbing...done" etc.
+# does not lend itself to good translations into languages where
+# such sentences have a different structure, and should be rethought.
+#: src/connect.c:272
+#, fuzzy, c-format
+msgid "Connecting to %s|%s|:%d... "
+msgstr "%s:%hu-� ������� �����"
+
+# FIXME: this is lame!  The method of printing "Frobbing...done" etc.
+# does not lend itself to good translations into languages where
+# such sentences have a different structure, and should be rethought.
+#: src/connect.c:275
+#, fuzzy, c-format
+msgid "Connecting to %s:%d... "
+msgstr "%s:%hu-� ������� �����"
+
+# Pay attention: this is written to the RIGHT of "Connecting.." !!
+#: src/connect.c:336
+#, fuzzy
+msgid "connected.\n"
+msgstr "� �����\n"
+
+#: src/convert.c:176
+#, c-format
+msgid "Converted %d files in %.*f seconds.\n"
+msgstr ""
+
+# Note: the following 5 messages are all written on the same line!
+#: src/convert.c:202
+#, c-format
+msgid "Converting %s... "
+msgstr "%s ����"
+
+#: src/convert.c:215
+msgid "nothing to do.\n"
+msgstr "� ���� ���\n"
+
+#: src/convert.c:223 src/convert.c:247
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "� (%s: %s) ������� ���� ����\n"
+
+#: src/convert.c:238
+#, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "`%s' ����� ������ (%s) ����\n"
+
+#: src/convert.c:447
+#, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "%s-� ������ %s ������ (%s) ����\n"
 
-#: src/cookies.c:612
+#: src/cookies.c:619
 #, c-format
-msgid "Syntax error in Set-Cookie at character `%c'.\n"
-msgstr ".`%c' �� ����� Set-Cookie ����� �� ���� �����\n"
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "���� Set-Cookie ����� �� `%s' ���"
 
-#: src/cookies.c:620
-msgid "Syntax error in Set-Cookie: premature end of string.\n"
+#: src/cookies.c:643
+#, fuzzy, c-format
+msgid "Syntax error in Set-Cookie: %s at position %d.\n"
 msgstr ".��� ����� ������� ������� :Set-Cookie ����� �� ���� �����\n"
 
-#: src/cookies.c:1352
+#: src/cookies.c:1456
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "`%s' ������ ���� ����� ��� (%s) ���� �����\n"
 
-#: src/cookies.c:1364
+#: src/cookies.c:1468
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "`%s'-� ������ (%s) ����\n"
 
-#: src/cookies.c:1368
+#: src/cookies.c:1471
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "`%s' ������ (%s) ����\n"
 
-#: src/ftp-ls.c:787
+#: src/ftp-ls.c:841
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr ".Unix ����� ��� ���� ���� ,����-���� ���� ����� �����\n"
 
-#: src/ftp-ls.c:832 src/ftp-ls.c:834
+#: src/ftp-ls.c:887 src/ftp-ls.c:889
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "/%s ������ %s:%d-� ����� �����"
 
-#: src/ftp-ls.c:856
+#: src/ftp-ls.c:912
+#, c-format
 msgid "time unknown       "
 msgstr "  ���� �� ����� ���"
 
-#: src/ftp-ls.c:860
+#: src/ftp-ls.c:916
+#, c-format
 msgid "File        "
 msgstr "        ����"
 
-#: src/ftp-ls.c:863
+#: src/ftp-ls.c:919
+#, c-format
 msgid "Directory   "
 msgstr "       �����"
 
-#: src/ftp-ls.c:866
+#: src/ftp-ls.c:922
+#, c-format
 msgid "Link        "
 msgstr "       �����"
 
-#: src/ftp-ls.c:869
+#: src/ftp-ls.c:925
+#, c-format
 msgid "Not sure    "
 msgstr " ���� �� ���"
 
-#: src/ftp-ls.c:887
+#: src/ftp-ls.c:943
 #, c-format
 msgid " (%s bytes)"
 msgstr "  (���� %s)"
 
-# FIXME: this is lame!  The method of printing "Frobbing...done" etc.
-# does not lend itself to good translations into languages where
-# such sentences have a different structure, and should be rethought.
-#. Login to the server:
-#. First: Establish the control connection.
-#: src/ftp.c:150 src/http.c:624
+# FIXME: This 3-part message will look totally messed up in a
+# right-to-left language such as Hebrew!  The maintainers
+# should _really_ fix the code!
+#: src/ftp.c:226
 #, c-format
-msgid "Connecting to %s:%hu... "
-msgstr "%s:%hu-� ������� �����"
+msgid "Length: %s"
+msgstr "%s :����"
 
-#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
+#: src/ftp.c:232 src/http.c:1791
 #, c-format
-msgid "Connection to %s:%hu refused.\n"
-msgstr ".���� %s:%hu-� ������� �����\n"
+msgid ", %s (%s) remaining"
+msgstr ""
 
-# Pay attention: this is written to the RIGHT of "Connecting.." !!
-#. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:193 src/http.c:652
-msgid "connected!\n"
-msgstr "� �����\n"
+#: src/ftp.c:236 src/http.c:1795
+#, c-format
+msgid ", %s remaining"
+msgstr ""
+
+#: src/ftp.c:240
+msgid " (unauthoritative)\n"
+msgstr " (�����)\n"
 
-#: src/ftp.c:194
+#. Second: Login with proper USER/PASS sequence.
+#: src/ftp.c:314
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "%s-� ����� �����"
 
-#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
-#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
+#: src/ftp.c:327 src/ftp.c:380 src/ftp.c:411 src/ftp.c:465 src/ftp.c:580
+#: src/ftp.c:631 src/ftp.c:661 src/ftp.c:723 src/ftp.c:791 src/ftp.c:855
+#: src/ftp.c:907
 msgid "Error in server response, closing control connection.\n"
 msgstr ".���� ����� ���� ,��� �� ���� ����\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:335
 msgid "Error in server greeting.\n"
 msgstr ".���� ���� �� ����� ���\n"
 
-#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
-#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
+#: src/ftp.c:343 src/ftp.c:474 src/ftp.c:589 src/ftp.c:670 src/ftp.c:734
+#: src/ftp.c:802 src/ftp.c:866 src/ftp.c:918
 msgid "Write failed, closing control connection.\n"
 msgstr ".���� ����� ���� ,������ ����\n"
 
-#: src/ftp.c:226
+#: src/ftp.c:350
 msgid "The server refuses login.\n"
 msgstr ".����� ���� ���� ����\n"
 
-#: src/ftp.c:233
+#: src/ftp.c:357
 msgid "Login incorrect.\n"
 msgstr ".����� �����\n"
 
 # Note: this is written to the right of "Logging in as", with no newline!
-#: src/ftp.c:240
+#: src/ftp.c:364
 msgid "Logged in!\n"
 msgstr "� �����\n"
 
-#: src/ftp.c:265
+#: src/ftp.c:389
 msgid "Server error, can't determine system type.\n"
 msgstr ".����� ��� ����� ������ ��� ,��� �� ���� ����\n"
 
-#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
+#: src/ftp.c:399 src/ftp.c:710 src/ftp.c:774 src/ftp.c:821
 msgid "done.    "
 msgstr " <== ������ ����"
 
-#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
+#: src/ftp.c:453 src/ftp.c:610 src/ftp.c:645 src/ftp.c:890 src/ftp.c:941
 msgid "done.\n"
 msgstr " <== ������ ����\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:482
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr ".���� ����� ���� ,���� ���� `%c' ����� ���\n"
 
-#: src/ftp.c:366
+#: src/ftp.c:495
 msgid "done.  "
 msgstr " <== ������ ����"
 
-#: src/ftp.c:372
+#: src/ftp.c:501
 msgid "==> CWD not needed.\n"
 msgstr "==> .����� ���� CWD �����\n"
 
-#: src/ftp.c:445
+#: src/ftp.c:596
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr ".����� ���� `%s' �����\n\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+".����� ���� `%s' �����\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:463
+#: src/ftp.c:614
 msgid "==> CWD not required.\n"
 msgstr "==> .CWD ������ ���� ���\n"
 
-#: src/ftp.c:497
+#: src/ftp.c:677
 msgid "Cannot initiate PASV transfer.\n"
 msgstr ".PASV ����� ����� ������ ���� ��\n"
 
-#: src/ftp.c:501
+#: src/ftp.c:681
 msgid "Cannot parse PASV response.\n"
 msgstr ".PASV ������ ���� ���� ���� ��\n"
 
-#: src/ftp.c:515
+#: src/ftp.c:701
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr ".%s:%hu-� ������ ����\n"
+msgid "couldn't connect to %s port %d: %s\n"
+msgstr ""
 
-#: src/ftp.c:602
+#: src/ftp.c:752
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr ".(%s) ������� ����\n"
 
-#: src/ftp.c:618
+#: src/ftp.c:759
 msgid "Invalid PORT.\n"
 msgstr ".PORT ����\n"
 
-#: src/ftp.c:671
-#, c-format
-msgid "\nREST failed; will not truncate `%s'.\n"
-msgstr "\n.`%s' �� ���� ���� ����� ���� ����� ;����� REST �����\n"
-
-#: src/ftp.c:678
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\n.������ ����� ;����� REST �����\n"
-
-#: src/ftp.c:727
-#, c-format
-msgid "No such file `%s'.\n\n"
-msgstr ".���� ���� `%s' ����\n\n"
+#: src/ftp.c:810
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+".������ ����� ;����� REST �����\n"
 
-#: src/ftp.c:775
+#: src/ftp.c:875
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr ".������ ����� �� ���� ���� `%s'\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+".���� ���� `%s' ����\n"
+"\n"
 
-# FIXME: This 3-part message will look totally messed up in a
-# right-to-left language such as Hebrew!  The maintainers
-# should _really_ fix the code!
-#: src/ftp.c:859 src/ftp.c:867
+#: src/ftp.c:927
 #, c-format
-msgid "Length: %s"
-msgstr "%s :����"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+".������ ����� �� ���� ���� `%s'\n"
+"\n"
 
-#: src/ftp.c:861 src/ftp.c:869
+#. We cannot just invent a new name and use it (which is
+#. what functions like unique_create typically do)
+#. because we told the user we'd use this name.
+#. Instead, return and retry the download.
+#: src/ftp.c:992 src/http.c:1847
 #, c-format
-msgid " [%s to go]"
-msgstr " [%s ��� ����]"
-
-#: src/ftp.c:871
-msgid " (unauthoritative)\n"
-msgstr " (�����)\n"
+msgid "%s has sprung into existence.\n"
+msgstr ""
 
-#: src/ftp.c:898
+#: src/ftp.c:1054
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr ".���� ����� ���� ,%s-� (%s) ����\n"
 
 # Note: the rightmost colon is for the message that will be printed
 # later.
-#: src/ftp.c:906
+#: src/ftp.c:1062
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "(%s :���  %s :���) ������� ����� (%s) ���� :"
 
 # Note: this and the next one don't have the period because they get
 # printed to the right of the previous message.
-#: src/ftp.c:923
+#: src/ftp.c:1077
 msgid "Control connection closed.\n"
 msgstr "���� ����� ����\n"
 
-#: src/ftp.c:941
+#: src/ftp.c:1095
 msgid "Data transfer aborted.\n"
 msgstr "������ ������ �����\n"
 
-#: src/ftp.c:1005
+#: src/ftp.c:1160
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr ".���� ����� ���� ��� ,��� ��� `%s' ����\n"
 
-#: src/ftp.c:1075 src/http.c:1502
+#: src/ftp.c:1224 src/http.c:2066
 #, c-format
 msgid "(try:%2d)"
 msgstr "(%2d '�� �����)"
 
 # I give up!
-#: src/ftp.c:1139 src/http.c:1753
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - `%s' saved [%ld]\n\n"
+#: src/ftp.c:1296 src/http.c:2347
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' saved [%ld]\n"
+"\n"
 
-#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
+#: src/ftp.c:1338 src/main.c:921 src/recur.c:376 src/retr.c:835
 #, c-format
 msgid "Removing %s.\n"
 msgstr ".%s ����\n"
 
-#: src/ftp.c:1221
+#: src/ftp.c:1380
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr ".����� ����� ����� ���� ����� `%s'-� �����\n"
 
-#: src/ftp.c:1233
+#: src/ftp.c:1395
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr ".���� `%s' ����\n"
 
-#: src/ftp.c:1269
+#: src/ftp.c:1430
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr ".���� ���� %d ����� ���� �� ,%d ��� ����� ������� ����\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1330
+#: src/ftp.c:1500
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
 msgstr ".����� �� ����� -- `%s' ����� ����� ���� ����� ���� ����� ����\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1337
+#: src/ftp.c:1507
 #, c-format
-msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
+msgid ""
+"Remote file is newer than local file `%s' -- retrieving.\n"
+"\n"
 msgstr ".����� ����� -- `%s' ����� ����� ���� ����� ����� ����\n"
 
 #. Sizes do not match
-#: src/ftp.c:1344
-#, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
+#: src/ftp.c:1514
+#, fuzzy, c-format
+msgid ""
+"The sizes do not match (local %s) -- retrieving.\n"
+"\n"
 msgstr ".����� ����� -- (%ld :����� ����) ��� ���� ����\n"
 
-#: src/ftp.c:1361
+#: src/ftp.c:1532
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr ".����� ����� ,���� ���� ������� ����� ���� �� ���\n"
 
-#: src/ftp.c:1378
+#: src/ftp.c:1549
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
 msgstr ".���� ��� %s -> %s ������� �����\n"
 
-#: src/ftp.c:1386
+#: src/ftp.c:1557
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr ".%s -> %s ������� ����� ����\n"
 
-#: src/ftp.c:1397
+#: src/ftp.c:1567
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr ".`%s' ���� ����� ,������ ���� ������� ����� ����\n"
 
-#: src/ftp.c:1409
+#: src/ftp.c:1579
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr ".`%s' ����� �����\n"
 
-#: src/ftp.c:1418
+#: src/ftp.c:1588
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr ".���� ���� �� ����-���� ���� ���� `%s' ����\n"
 
-#: src/ftp.c:1445
+#: src/ftp.c:1615
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr ".����� ��� ����� ��� ��� `%s' ����\n"
 
-#: src/ftp.c:1466
+#: src/ftp.c:1643
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ".���� �� %d ����� ��� ������ �� ������ ;%d ����� ����\n"
 
-#: src/ftp.c:1512
+#: src/ftp.c:1693
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr ".������� ����� �� ����� ��� ���� `%s'-� ������� ����\n"
 
-#: src/ftp.c:1559
+#: src/ftp.c:1759 src/ftp.c:1773
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr ".���� `%s'\n"
