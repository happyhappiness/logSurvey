 msgid "Length: %s"
 msgstr "Dol¾ina: %s"
 
-#: src/ftp.c:220 src/http.c:2183
+#: src/ftp.c:220 src/http.c:2199
 #, c-format
 msgid ", %s (%s) remaining"
-msgstr ""
+msgstr ", %s (%s) preostalo"
 
-#: src/ftp.c:224 src/http.c:2187
+#: src/ftp.c:224 src/http.c:2203
 #, c-format
 msgid ", %s remaining"
-msgstr ""
+msgstr ", %s preostalo"
 
 #: src/ftp.c:227
 msgid " (unauthoritative)\n"
 msgstr " (neavtorizirana)\n"
 
-#: src/ftp.c:303
+#: src/ftp.c:305
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Prijavljam se kot %s ... "
 
-#: src/ftp.c:316 src/ftp.c:362 src/ftp.c:391 src/ftp.c:443 src/ftp.c:555
-#: src/ftp.c:601 src/ftp.c:630 src/ftp.c:687 src/ftp.c:748 src/ftp.c:808
-#: src/ftp.c:855
+#: src/ftp.c:319 src/ftp.c:365 src/ftp.c:394 src/ftp.c:446 src/ftp.c:559
+#: src/ftp.c:606 src/ftp.c:635 src/ftp.c:692 src/ftp.c:753 src/ftp.c:839
+#: src/ftp.c:886
 msgid "Error in server response, closing control connection.\n"
 msgstr "Napaèen odgovor, zapiram nadzorno povezavo.\n"
 
-#: src/ftp.c:323
+#: src/ftp.c:326
 msgid "Error in server greeting.\n"
 msgstr "Napaka v pozdravu stre¾nika.\n"
 
-#: src/ftp.c:330 src/ftp.c:451 src/ftp.c:563 src/ftp.c:638 src/ftp.c:697
-#: src/ftp.c:758 src/ftp.c:818 src/ftp.c:865
+#: src/ftp.c:333 src/ftp.c:454 src/ftp.c:567 src/ftp.c:643 src/ftp.c:702
+#: src/ftp.c:763 src/ftp.c:849 src/ftp.c:896
 msgid "Write failed, closing control connection.\n"
 msgstr "Pisanje neuspe¹no, zapiram nadzorno povezavo.\n"
 
-#: src/ftp.c:336
+#: src/ftp.c:339
 msgid "The server refuses login.\n"
 msgstr "Stre¾nik zavraèa prijavo.\n"
 
-#: src/ftp.c:342
+#: src/ftp.c:345
 msgid "Login incorrect.\n"
 msgstr "Napaèna prijava.\n"
 
-#: src/ftp.c:348
+#: src/ftp.c:351
 msgid "Logged in!\n"
 msgstr "Prijavljen!\n"
 
-#: src/ftp.c:370
+#: src/ftp.c:373
 msgid "Server error, can't determine system type.\n"
 msgstr "Napaka v stre¾niku, vrste sistema ni moè ugotoviti.\n"
 
-#: src/ftp.c:379 src/ftp.c:674 src/ftp.c:731 src/ftp.c:774
+#: src/ftp.c:382 src/ftp.c:679 src/ftp.c:736 src/ftp.c:779
 msgid "done.    "
 msgstr "opravljeno. "
 
-#: src/ftp.c:431 src/ftp.c:580 src/ftp.c:613 src/ftp.c:838 src/ftp.c:884
+#: src/ftp.c:434 src/ftp.c:584 src/ftp.c:618 src/ftp.c:869 src/ftp.c:915
 msgid "done.\n"
 msgstr "konèano.\n"
 
-#: src/ftp.c:458
+#: src/ftp.c:461
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Neznan tip `%c', zapiram nadzorno zvezo.\n"
 
-#: src/ftp.c:470
+#: src/ftp.c:473
 msgid "done.  "
 msgstr "opravljeno."
 
-#: src/ftp.c:476
+#: src/ftp.c:479
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD ni potreben.\n"
 
-#: src/ftp.c:569
-#, c-format
+#: src/ftp.c:573
+#, fuzzy, c-format
 msgid ""
-"No such directory `%s'.\n"
+"No such directory %s.\n"
 "\n"
 msgstr ""
 "Ni imenika z imenom `%s'.\n"
 "\n"
 
-#: src/ftp.c:584
+#: src/ftp.c:588
 msgid "==> CWD not required.\n"
 msgstr "==> CWD ni zahtevan.\n"
 
-#: src/ftp.c:644
+#: src/ftp.c:649
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Ne morem zaèeti prenosa PASV.\n"
 
-#: src/ftp.c:648
+#: src/ftp.c:653
 msgid "Cannot parse PASV response.\n"
 msgstr "Ne morem razèleniti odgovora PASV.\n"
 
-#: src/ftp.c:665
-#, fuzzy, c-format
+#: src/ftp.c:670
+#, c-format
 msgid "couldn't connect to %s port %d: %s\n"
-msgstr "ni se bilo moè povezati z %s:%hu: %s.\n"
+msgstr "ni se bilo moè povezati z %s na vrata %d: %s.\n"
 
-#: src/ftp.c:713
+#: src/ftp.c:718
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Napaka pri povezovanju (%s).\n"
 
-#: src/ftp.c:719
+#: src/ftp.c:724
 msgid "Invalid PORT.\n"
 msgstr "Neveljaven PORT.\n"
 
-#: src/ftp.c:765
+#: src/ftp.c:770
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
