 "Content-Type: text/plain; charset=big5\n"
 "Content-Transfer-Encoding: 8bit\n"
 
+#: src/ftp-ls.c:698 src/ftp-ls.c:700
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "/%s �����ަb %s:%d"
+
+#: src/ftp-ls.c:722
+msgid "time unknown       "
+msgstr "�ɶ�����           "
+
+#: src/ftp-ls.c:726
+msgid "File        "
+msgstr "�ɮ�        "
+
+#: src/ftp-ls.c:729
+msgid "Directory   "
+msgstr "�ؿ�        "
+
+#: src/ftp-ls.c:732
+msgid "Link        "
+msgstr "�s��        "
+
+#: src/ftp-ls.c:735
+msgid "Not sure    "
+msgstr "�S���T�w    "
+
+#: src/ftp-ls.c:753
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s �줸��)"
+
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:146 src/http.c:337
+#: src/ftp.c:152 src/http.c:582
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "���s�� %s: %hu... "
 
-#: src/ftp.c:168 src/ftp.c:409 src/http.c:354
+#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "�s�u�� %s: %hu �Q�ڵ�. \n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:189 src/http.c:365
+#: src/ftp.c:195 src/http.c:610
 msgid "connected!\n"
 msgstr "�s�W�F!\n"
 
-#: src/ftp.c:190
+#: src/ftp.c:196
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "�ϥ� %s ñ�J... "
 
-#: src/ftp.c:199 src/ftp.c:251 src/ftp.c:299 src/ftp.c:351 src/ftp.c:445
-#: src/ftp.c:518 src/ftp.c:566 src/ftp.c:614
+#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
+#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
 msgid "Error in server response, closing control connection.\n"
 msgstr "���A���ݦ^���ɵo�Ϳ��~�A���b�����s�u����.\n"
 
-#: src/ftp.c:207
+#: src/ftp.c:213
 msgid "Error in server greeting.\n"
 msgstr "�P���A���s�u�ɵo�Ϳ��~.\n"
 
-#: src/ftp.c:214 src/ftp.c:260 src/ftp.c:308 src/ftp.c:360 src/ftp.c:455
-#: src/ftp.c:528 src/ftp.c:576 src/ftp.c:624
+#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
+#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
 msgid "Write failed, closing control connection.\n"
 msgstr "�g�J����, ���b�����s�u����.\n"
 
-#: src/ftp.c:221
+#: src/ftp.c:228
 msgid "The server refuses login.\n"
 msgstr "���A���ڵ�ñ�J.\n"
 
-#: src/ftp.c:228
+#: src/ftp.c:235
 msgid "Login incorrect.\n"
 msgstr "ñ�J�����T.\n"
 
-#: src/ftp.c:235
+#: src/ftp.c:242
 msgid "Logged in!\n"
 msgstr "�w�gñ�J�F!\n"
 
-#: src/ftp.c:268
+#: src/ftp.c:267
+msgid "Server error, can't determine system type.\n"
+msgstr ""
+
+#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
+msgid "done.    "
+msgstr "����.    "
+
+#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
+msgid "done.\n"
+msgstr "����.\n"
+
+#: src/ftp.c:331
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "�������Φ� `%c', ���b�����s�u����.\n"
 
-#: src/ftp.c:281
+#: src/ftp.c:344
 msgid "done.  "
 msgstr "����.  "
 
-#: src/ftp.c:287
+#: src/ftp.c:350
 msgid "==> CWD not needed.\n"
 msgstr "==> ���ݭn CWD.\n"
 
-#: src/ftp.c:315
+#: src/ftp.c:426
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr "�S�� `%s' �o�ӥؿ�.\n\n"
-
-#: src/ftp.c:329 src/ftp.c:597 src/ftp.c:645 src/url.c:1421
-msgid "done.\n"
-msgstr "����.\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+"�S�� `%s' �o�ӥؿ�.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:333
+#: src/ftp.c:444
 msgid "==> CWD not required.\n"
 msgstr "==> ���ݭn CWD.\n"
 
-#: src/ftp.c:367
+#: src/ftp.c:478
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "�L�k�Ұ� PASV �ǿ�.\n"
 
-#: src/ftp.c:371
+#: src/ftp.c:482
 msgid "Cannot parse PASV response.\n"
 msgstr "�L�k���R PASV �^�����e.\n"
 
-#: src/ftp.c:385
+#: src/ftp.c:496
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "�N�|�~����ջP %s �s�u: %hu.\n"
 
-#: src/ftp.c:472
+#: src/ftp.c:583
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "BIND ���~ (%s).\n"
 
-#: src/ftp.c:488
+#: src/ftp.c:599
 msgid "Invalid PORT.\n"
 msgstr "�L�Ī� PORT.\n"
 
-#: src/ftp.c:502 src/ftp.c:546
-msgid "done.    "
-msgstr "����.    "
-
-#: src/ftp.c:535
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nRSET ���ѡA���ѿ��ä��}�l��.\n"
+#: src/ftp.c:646
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"RSET ���ѡA���ѿ��ä��}�l��.\n"
 
-#: src/ftp.c:584
+#: src/ftp.c:695
 #, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "�S�� `%s' �o���ɮ�.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"�S�� `%s' �o���ɮ�.\n"
+"\n"
 
-#: src/ftp.c:632
+#: src/ftp.c:743
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "�S�� `%s' �o���ɮשΥؿ�.\n\n"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"�S�� `%s' �o���ɮשΥؿ�.\n"
+"\n"
 
-#: src/ftp.c:690 src/ftp.c:697
+#: src/ftp.c:819 src/ftp.c:826
 #, c-format
 msgid "Length: %s"
 msgstr "����: %s"
 
-#: src/ftp.c:692 src/ftp.c:699
+#: src/ftp.c:821 src/ftp.c:828
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s �}�l]"
 
-#: src/ftp.c:701
+#: src/ftp.c:830
 msgid " (unauthoritative)\n"
 msgstr " (����{�i��)\n"
 
-#: src/ftp.c:719
+#: src/ftp.c:856
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, ���b�����s�u����.\n"
 
-#: src/ftp.c:727
+#: src/ftp.c:864
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - ��Ƴs�u: %s; "
 
-#: src/ftp.c:744
+#: src/ftp.c:881
 msgid "Control connection closed.\n"
 msgstr "�s�u����w�g�Q�����F.\n"
 
-#: src/ftp.c:762
+#: src/ftp.c:899
 msgid "Data transfer aborted.\n"
 msgstr "��ƶǿ�w�g�Q���_�F.\n"
 
-#: src/ftp.c:828
+#: src/ftp.c:963
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "�ɮ� `%s' �w�g�s�b�A���|����.\n"
 
-#: src/ftp.c:894 src/http.c:913
-#, c-format
+#: src/ftp.c:1024 src/http.c:1358
+#, c-format, ycp-format
 msgid "(try:%2d)"
 msgstr "(����:%2d)"
 
-#: src/ftp.c:953 src/http.c:1099
+#: src/ftp.c:1088 src/http.c:1585
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - `%s' �Q�x�s [%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' �Q�x�s [%ld]\n"
+"\n"
+
+#: src/ftp.c:1130 src/main.c:771 src/recur.c:505 src/retr.c:580
+#, c-format
+msgid "Removing %s.\n"
+msgstr "���b���� %s.\n"
 
-#: src/ftp.c:999
+#: src/ftp.c:1171
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "�ϥ� `%s' �@���C���Ȧs��.\n"
 
-#: src/ftp.c:1011
+#: src/ftp.c:1183
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "���� `%s'.\n"
 
-#: src/ftp.c:1047
+#: src/ftp.c:1219
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "���j�h�� %d �w�g�W�L�̤j�� %d �h����. \n"
 
-#: src/ftp.c:1094 src/http.c:1037
+#: src/ftp.c:1271 src/http.c:1512
 #, c-format
-msgid "Local file `%s' is more recent, not retrieving.\n\n"
-msgstr "���a�� `%s' �ɮפ���s�A�ҥH�N�����^.\n\n"
+msgid ""
+"Server file no newer than local file `%s' -- not retrieving.\n"
+"\n"
+msgstr ""
 
-#: src/ftp.c:1100 src/http.c:1043
-#, c-format
-msgid "The sizes do not match (local %ld), retrieving.\n"
+#: src/ftp.c:1279
+msgid "Cannot compare sizes, remote system is VMS.\n"
+msgstr ""
+
+#: src/ftp.c:1285 src/http.c:1520
+#, fuzzy, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr "�ɮפj�p�ä��۲ŦX (���a���� %ld)�A���b���^��.\n"
 
-#: src/ftp.c:1117
+#: src/ftp.c:1303
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "�L�Ī��s���˸m�W�١A���b���L��.\n"
 
-#: src/ftp.c:1134
+#: src/ftp.c:1320
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
-msgstr "�w�g�s�b���T�� %s -> %s �H�x�s��\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
+msgstr ""
+"�w�g�s�b���T�� %s -> %s �H�x�s��\n"
+"\n"
 
-#: src/ftp.c:1141
+#: src/ftp.c:1328
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "���b�إ� %s -> %s ���H�x�s��\n"
 
-#: src/ftp.c:1152
+#: src/ftp.c:1339
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "���䴩�s���˸m�A���b���L `%s' �o�ӶH�x�s��.\n"
 
-#: src/ftp.c:1164
+#: src/ftp.c:1351
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "�����L `%s' �ؿ�.\n"
 
-#: src/ftp.c:1173
+#: src/ftp.c:1360
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: ������/���䴩���ɮ׮榡.\n"
 
-#: src/ftp.c:1189
+#: src/ftp.c:1377
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ���~���ɶ��W�O.\n"
 
-#: src/ftp.c:1209
+#: src/ftp.c:1398
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "�N�����^�q %d (�̤j�Ȭ� %d) �h�᪺�ؿ�.\n"
 
-#: src/ftp.c:1248
+#: src/ftp.c:1437
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "���U��� `%s' �]���L�O�Q�ư����άO�D�]�t�i�Ӫ�.\n"
 
-#: src/ftp.c:1293
+#: src/ftp.c:1482
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "����� `%s' ��.\n"
