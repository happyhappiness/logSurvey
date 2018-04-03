 "Content-Type: text/plain; charset=CHARSET\n"
 "Content-Transfer-Encoding: ENCODING\n"
 
+#: src/ftp-ls.c:698 src/ftp-ls.c:700
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr ""
+
+#: src/ftp-ls.c:722
+msgid "time unknown       "
+msgstr ""
+
+#: src/ftp-ls.c:726
+msgid "File        "
+msgstr ""
+
+#: src/ftp-ls.c:729
+msgid "Directory   "
+msgstr ""
+
+#: src/ftp-ls.c:732
+msgid "Link        "
+msgstr ""
+
+#: src/ftp-ls.c:735
+msgid "Not sure    "
+msgstr ""
+
+#: src/ftp-ls.c:753
+#, c-format
+msgid " (%s bytes)"
+msgstr ""
+
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:147 src/http.c:348
+#: src/ftp.c:157 src/http.c:586
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr ""
 
-#: src/ftp.c:169 src/ftp.c:411 src/http.c:365
+#: src/ftp.c:179 src/ftp.c:525 src/http.c:603
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr ""
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:190 src/http.c:376
+#: src/ftp.c:200 src/http.c:614
 msgid "connected!\n"
 msgstr ""
 
-#: src/ftp.c:191
+#: src/ftp.c:201
 #, c-format
 msgid "Logging in as %s ... "
 msgstr ""
 
-#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
-#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
+#: src/ftp.c:210 src/ftp.c:263 src/ftp.c:294 src/ftp.c:319 src/ftp.c:415
+#: src/ftp.c:467 src/ftp.c:561 src/ftp.c:634 src/ftp.c:682 src/ftp.c:730
 msgid "Error in server response, closing control connection.\n"
 msgstr ""
 
-#: src/ftp.c:208
+#: src/ftp.c:218
 msgid "Error in server greeting.\n"
 msgstr ""
 
-#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
-#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
+#: src/ftp.c:226 src/ftp.c:328 src/ftp.c:424 src/ftp.c:476 src/ftp.c:571
+#: src/ftp.c:644 src/ftp.c:692 src/ftp.c:740
 msgid "Write failed, closing control connection.\n"
 msgstr ""
 
-#: src/ftp.c:223
+#: src/ftp.c:233
 msgid "The server refuses login.\n"
 msgstr ""
 
-#: src/ftp.c:230
+#: src/ftp.c:240
 msgid "Login incorrect.\n"
 msgstr ""
 
-#: src/ftp.c:237
+#: src/ftp.c:247
 msgid "Logged in!\n"
 msgstr ""
 
-#: src/ftp.c:270
+#: src/ftp.c:272
+msgid "Server error, can't determine system type.\n"
+msgstr ""
+
+#: src/ftp.c:282 src/ftp.c:546 src/ftp.c:618 src/ftp.c:662
+msgid "done.    "
+msgstr ""
+
+#: src/ftp.c:308 src/ftp.c:445 src/ftp.c:713 src/ftp.c:761 src/url.c:1429
+msgid "done.\n"
+msgstr ""
+
+#: src/ftp.c:336
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr ""
 
-#: src/ftp.c:283
+#: src/ftp.c:349
 msgid "done.  "
 msgstr ""
 
-#: src/ftp.c:289
+#: src/ftp.c:355
 msgid "==> CWD not needed.\n"
 msgstr ""
 
-#: src/ftp.c:317
+#: src/ftp.c:431
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
 msgstr ""
 
-#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1671
-msgid "done.\n"
-msgstr ""
-
 #. do not CWD
-#: src/ftp.c:335
+#: src/ftp.c:449
 msgid "==> CWD not required.\n"
 msgstr ""
 
-#: src/ftp.c:369
+#: src/ftp.c:483
 msgid "Cannot initiate PASV transfer.\n"
 msgstr ""
 
-#: src/ftp.c:373
+#: src/ftp.c:487
 msgid "Cannot parse PASV response.\n"
 msgstr ""
 
-#: src/ftp.c:387
+#: src/ftp.c:501
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr ""
 
-#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
-msgid "done.    "
-msgstr ""
-
-#: src/ftp.c:474
+#: src/ftp.c:588
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr ""
 
-#: src/ftp.c:490
+#: src/ftp.c:604
 msgid "Invalid PORT.\n"
 msgstr ""
 
-#: src/ftp.c:537
+#: src/ftp.c:651
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 
-#: src/ftp.c:586
+#: src/ftp.c:700
 #, c-format
 msgid ""
 "No such file `%s'.\n"
 "\n"
 msgstr ""
 
-#: src/ftp.c:634
+#: src/ftp.c:748
 #, c-format
 msgid ""
 "No such file or directory `%s'.\n"
 "\n"
 msgstr ""
 
-#: src/ftp.c:710 src/ftp.c:717
+#: src/ftp.c:824 src/ftp.c:831
 #, c-format
 msgid "Length: %s"
 msgstr ""
 
-#: src/ftp.c:712 src/ftp.c:719
+#: src/ftp.c:826 src/ftp.c:833
 #, c-format
 msgid " [%s to go]"
 msgstr ""
 
-#: src/ftp.c:721
+#: src/ftp.c:835
 msgid " (unauthoritative)\n"
 msgstr ""
 
-#: src/ftp.c:747
+#: src/ftp.c:861
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr ""
 
-#: src/ftp.c:755
+#: src/ftp.c:869
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr ""
 
-#: src/ftp.c:772
+#: src/ftp.c:886
 msgid "Control connection closed.\n"
 msgstr ""
 
-#: src/ftp.c:790
+#: src/ftp.c:904
 msgid "Data transfer aborted.\n"
 msgstr ""
 
-#: src/ftp.c:856
+#: src/ftp.c:968
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr ""
 
-#: src/ftp.c:933 src/http.c:1032
-#, c-format, ycp-format
+#: src/ftp.c:1029 src/http.c:1362
+#, c-format
 msgid "(try:%2d)"
 msgstr ""
 
-#: src/ftp.c:997 src/http.c:1252
+#: src/ftp.c:1093 src/http.c:1599
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld]\n"
 "\n"
 msgstr ""
 
-#: src/ftp.c:1039 src/main.c:749 src/recur.c:468 src/retr.c:560
+#: src/ftp.c:1135 src/main.c:775 src/recur.c:509 src/retr.c:584
 #, c-format
 msgid "Removing %s.\n"
 msgstr ""
 
-#: src/ftp.c:1080
+#: src/ftp.c:1176
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr ""
 
-#: src/ftp.c:1092
+#: src/ftp.c:1188
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr ""
 
-#: src/ftp.c:1128
+#: src/ftp.c:1224
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr ""
 
-#: src/ftp.c:1180 src/http.c:1179
+#: src/ftp.c:1276 src/http.c:1516
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/ftp.c:1186 src/http.c:1187
+#: src/ftp.c:1284
+msgid "Cannot compare sizes, remote system is VMS.\n"
+msgstr ""
+
+#: src/ftp.c:1290 src/http.c:1524
 #, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr ""
 
-#: src/ftp.c:1203
+#: src/ftp.c:1308
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr ""
 
-#: src/ftp.c:1220
+#: src/ftp.c:1325
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr ""
 
-#: src/ftp.c:1228
+#: src/ftp.c:1333
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr ""
 
-#: src/ftp.c:1239
+#: src/ftp.c:1344
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr ""
 
-#: src/ftp.c:1251
+#: src/ftp.c:1356
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr ""
 
-#: src/ftp.c:1260
+#: src/ftp.c:1365
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr ""
 
-#: src/ftp.c:1277
+#: src/ftp.c:1392
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr ""
 
-#: src/ftp.c:1298
+#: src/ftp.c:1413
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ""
 
-#: src/ftp.c:1337
+#: src/ftp.c:1449
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr ""
 
-#: src/ftp.c:1382
+#: src/ftp.c:1494
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr ""
