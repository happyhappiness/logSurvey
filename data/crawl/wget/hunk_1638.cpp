 msgid "Length: %s"
 msgstr "Даўжыня: %s"
 
-#: src/ftp.c:220 src/http.c:2174
+#: src/ftp.c:220 src/http.c:2199
 #, c-format
 msgid ", %s (%s) remaining"
-msgstr ""
+msgstr ", %s (%s) засталося"
 
-#: src/ftp.c:224 src/http.c:2178
+#: src/ftp.c:224 src/http.c:2203
 #, c-format
 msgid ", %s remaining"
-msgstr ""
+msgstr ", %s засталося"
 
 #: src/ftp.c:227
 msgid " (unauthoritative)\n"
 msgstr " (неаўтарытэтны)\n"
 
-#. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:303
+#: src/ftp.c:305
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Уваходжу як %s ... "
 
-#: src/ftp.c:316 src/ftp.c:362 src/ftp.c:391 src/ftp.c:443 src/ftp.c:555
-#: src/ftp.c:601 src/ftp.c:630 src/ftp.c:687 src/ftp.c:748 src/ftp.c:808
-#: src/ftp.c:855
+#: src/ftp.c:319 src/ftp.c:365 src/ftp.c:394 src/ftp.c:446 src/ftp.c:559
+#: src/ftp.c:606 src/ftp.c:635 src/ftp.c:692 src/ftp.c:753 src/ftp.c:839
+#: src/ftp.c:886
 msgid "Error in server response, closing control connection.\n"
 msgstr "Памылка ў адказе паслужніка; кантрольнае далучэньне зачынена.\n"
 
-#: src/ftp.c:323
+#: src/ftp.c:326
 msgid "Error in server greeting.\n"
 msgstr "Памылка ў вітаньні сэрвэра.\n"
 
-#: src/ftp.c:330 src/ftp.c:451 src/ftp.c:563 src/ftp.c:638 src/ftp.c:697
-#: src/ftp.c:758 src/ftp.c:818 src/ftp.c:865
+#: src/ftp.c:333 src/ftp.c:454 src/ftp.c:567 src/ftp.c:643 src/ftp.c:702
+#: src/ftp.c:763 src/ftp.c:849 src/ftp.c:896
 msgid "Write failed, closing control connection.\n"
 msgstr "Памылка запісу, закрыю кіроўнае злучэньне.\n"
 
-#: src/ftp.c:336
+#: src/ftp.c:339
 msgid "The server refuses login.\n"
 msgstr "Сэрвэр адмаўляе ва ўваходзе.\n"
 
-#: src/ftp.c:342
+#: src/ftp.c:345
 msgid "Login incorrect.\n"
 msgstr "Уваход не карэктны.\n"
 
-#: src/ftp.c:348
+#: src/ftp.c:351
 msgid "Logged in!\n"
 msgstr "Увайшоў!\n"
 
-#: src/ftp.c:370
+#: src/ftp.c:373
 msgid "Server error, can't determine system type.\n"
 msgstr "Памылка сэрвэра, немагчыма вызначыць тып сыстэмы.\n"
 
-#: src/ftp.c:379 src/ftp.c:674 src/ftp.c:731 src/ftp.c:774
+#: src/ftp.c:382 src/ftp.c:679 src/ftp.c:736 src/ftp.c:779
 msgid "done.    "
 msgstr "зроблена."
 
-#: src/ftp.c:431 src/ftp.c:580 src/ftp.c:613 src/ftp.c:838 src/ftp.c:884
+#: src/ftp.c:434 src/ftp.c:584 src/ftp.c:618 src/ftp.c:869 src/ftp.c:915
 msgid "done.\n"
 msgstr "зроблена.\n"
 
-#: src/ftp.c:458
+#: src/ftp.c:461
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Невядомы тып `%c', закрыю кіроўнае злучэньне.\n"
 
-#: src/ftp.c:470
+#: src/ftp.c:473
 msgid "done.  "
 msgstr "зроблена."
 
-#: src/ftp.c:476
+#: src/ftp.c:479
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD непатрэбнае.\n"
 
-#: src/ftp.c:569
-#, c-format
+#: src/ftp.c:573
+#, fuzzy, c-format
 msgid ""
-"No such directory `%s'.\n"
+"No such directory %s.\n"
 "\n"
 msgstr ""
 "Няма такой дырэкторыи \"%s\".\n"
 "\n"
 
-#. do not CWD
-#: src/ftp.c:584
+#: src/ftp.c:588
 msgid "==> CWD not required.\n"
 msgstr "==> CWD непатрэбнае.\n"
 
-#: src/ftp.c:644
+#: src/ftp.c:649
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Немагчыма ініцыялізаваць PASV-перадачу.\n"
 
-#: src/ftp.c:648
+#: src/ftp.c:653
 msgid "Cannot parse PASV response.\n"
 msgstr "Немагчыма зрабіць разбор PASV адказу.\n"
 
-#: src/ftp.c:665
+#: src/ftp.c:670
 #, c-format
 msgid "couldn't connect to %s port %d: %s\n"
 msgstr "немагчыма далучыцца да %s, порт %d: %s\n"
 
-#: src/ftp.c:713
+#: src/ftp.c:718
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Памылка bind (%s).\n"
 
-#: src/ftp.c:719
+#: src/ftp.c:724
 msgid "Invalid PORT.\n"
 msgstr "Нерэчаісны порт.\n"
 
-#: src/ftp.c:765
+#: src/ftp.c:770
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 
-#: src/ftp.c:826
-#, c-format
+#: src/ftp.c:811
+#, fuzzy, c-format
+msgid "No such file %s.\n"
+msgstr ""
+"Файл \"%s\" адсутнічае.\n"
+"\n"
+
+#: src/ftp.c:857
+#, fuzzy, c-format
 msgid ""
-"No such file `%s'.\n"
+"No such file %s.\n"
 "\n"
 msgstr ""
 "Файл \"%s\" адсутнічае.\n"
 "\n"
 
-#: src/ftp.c:873
-#, c-format
+#: src/ftp.c:904
+#, fuzzy, c-format
 msgid ""
-"No such file or directory `%s'.\n"
+"No such file or directory %s.\n"
 "\n"
 msgstr ""
 "Файл ці тэчка \"%s'\" адсутнічае.\n"
 "\n"
 
-#. We cannot just invent a new name and use it (which is
-#. what functions like unique_create typically do)
-#. because we told the user we'd use this name.
-#. Instead, return and retry the download.
-#: src/ftp.c:935 src/http.c:2236
+#: src/ftp.c:966 src/http.c:2261
 #, c-format
 msgid "%s has sprung into existence.\n"
 msgstr ""
 
-#: src/ftp.c:987
+#: src/ftp.c:1018
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, закрыцьцё кантрольнага далучэньня.\n"
 
-#: src/ftp.c:996
+#: src/ftp.c:1027
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr ""
 
-#: src/ftp.c:1011
+#: src/ftp.c:1042
 msgid "Control connection closed.\n"
 msgstr "Кантрольнае далучэньне зачынена.\n"
 
-#: src/ftp.c:1029
+#: src/ftp.c:1060
 msgid "Data transfer aborted.\n"
 msgstr "Абарваная перадача даньняў.\n"
 
-#: src/ftp.c:1097
-#, c-format
-msgid "File `%s' already there; not retrieving.\n"
+#: src/ftp.c:1131
+#, fuzzy, c-format
+msgid "File %s already there; not retrieving.\n"
 msgstr "Файл \"%s\" ужо тут і ня будзе выцягвацца.\n"
 
-#: src/ftp.c:1165 src/http.c:2394
+#: src/ftp.c:1201 src/http.c:2441
 #, c-format
 msgid "(try:%2d)"
 msgstr "(спроба: %2d)"
 
-#: src/ftp.c:1235 src/http.c:2717
-#, c-format
+#: src/ftp.c:1271 src/http.c:2774
+#, fuzzy, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s]\n"
+"%s (%s) - %s saved [%s]\n"
 "\n"
 msgstr ""
 "%s (%s) - \"%s\" захавана [%s]\n"
 "\n"
 
-#: src/ftp.c:1277 src/main.c:1005 src/recur.c:378 src/retr.c:860
+#: src/ftp.c:1313 src/main.c:1060 src/recur.c:378 src/retr.c:860
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Выдаленьне %s.\n"
 
-#: src/ftp.c:1319
-#, c-format
-msgid "Using `%s' as listing tmp file.\n"
+#: src/ftp.c:1355
+#, fuzzy, c-format
+msgid "Using %s as listing tmp file.\n"
 msgstr "Выкарыстаньне \"%s\" у якасьці лістынгу tmp-файла\n"
 
-#: src/ftp.c:1334
-#, c-format
-msgid "Removed `%s'.\n"
+#: src/ftp.c:1369
+#, fuzzy, c-format
+msgid "Removed %s.\n"
 msgstr "Выдалены \"%s\".\n"
 
-#: src/ftp.c:1367
+#: src/ftp.c:1405
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr "Значэньне рэкурсыўнае глыбіні %d большае за найбольшую дазволеную глыбіню %d.\n"
+msgstr ""
+"Значэньне рэкурсыўнае глыбіні %d большае за найбольшую дазволеную глыбіню %"
+"d.\n"
 
-#. Remote file is older, file sizes can be compared and
-#. are both equal.
-#: src/ftp.c:1437
-#, c-format
-msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
+#: src/ftp.c:1475
+#, fuzzy, c-format
+msgid "Remote file no newer than local file %s -- not retrieving.\n"
 msgstr "Аддалены файл не навейшы за мясцовы файл \"%s\" -- не выцягваецца.\n"
 
-#. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1444
-#, c-format
+#: src/ftp.c:1482
+#, fuzzy, c-format
 msgid ""
-"Remote file is newer than local file `%s' -- retrieving.\n"
+"Remote file is newer than local file %s -- retrieving.\n"
 "\n"
 msgstr "Аддалены файл навейшы за мясцовы файл \"%s\" -- выцягваецца.\n"
 
-#. Sizes do not match
-#: src/ftp.c:1451
+#: src/ftp.c:1489
 #, c-format
 msgid ""
 "The sizes do not match (local %s) -- retrieving.\n"
