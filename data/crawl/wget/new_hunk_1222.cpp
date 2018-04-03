msgid "Length: %s"
msgstr "Даўжыня: %s"

#: src/ftp.c:220 src/http.c:2199
#, c-format
msgid ", %s (%s) remaining"
msgstr ", %s (%s) засталося"

#: src/ftp.c:224 src/http.c:2203
#, c-format
msgid ", %s remaining"
msgstr ", %s засталося"

#: src/ftp.c:227
msgid " (unauthoritative)\n"
msgstr " (неаўтарытэтны)\n"

#: src/ftp.c:305
#, c-format
msgid "Logging in as %s ... "
msgstr "Уваходжу як %s ... "

#: src/ftp.c:319 src/ftp.c:365 src/ftp.c:394 src/ftp.c:446 src/ftp.c:559
#: src/ftp.c:606 src/ftp.c:635 src/ftp.c:692 src/ftp.c:753 src/ftp.c:839
#: src/ftp.c:886
msgid "Error in server response, closing control connection.\n"
msgstr "Памылка ў адказе паслужніка; кантрольнае далучэньне зачынена.\n"

#: src/ftp.c:326
msgid "Error in server greeting.\n"
msgstr "Памылка ў вітаньні сэрвэра.\n"

#: src/ftp.c:333 src/ftp.c:454 src/ftp.c:567 src/ftp.c:643 src/ftp.c:702
#: src/ftp.c:763 src/ftp.c:849 src/ftp.c:896
msgid "Write failed, closing control connection.\n"
msgstr "Памылка запісу, закрыю кіроўнае злучэньне.\n"

#: src/ftp.c:339
msgid "The server refuses login.\n"
msgstr "Сэрвэр адмаўляе ва ўваходзе.\n"

#: src/ftp.c:345
msgid "Login incorrect.\n"
msgstr "Уваход не карэктны.\n"

#: src/ftp.c:351
msgid "Logged in!\n"
msgstr "Увайшоў!\n"

#: src/ftp.c:373
msgid "Server error, can't determine system type.\n"
msgstr "Памылка сэрвэра, немагчыма вызначыць тып сыстэмы.\n"

#: src/ftp.c:382 src/ftp.c:679 src/ftp.c:736 src/ftp.c:779
msgid "done.    "
msgstr "зроблена."

#: src/ftp.c:434 src/ftp.c:584 src/ftp.c:618 src/ftp.c:869 src/ftp.c:915
msgid "done.\n"
msgstr "зроблена.\n"

#: src/ftp.c:461
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Невядомы тып `%c', закрыю кіроўнае злучэньне.\n"

#: src/ftp.c:473
msgid "done.  "
msgstr "зроблена."

#: src/ftp.c:479
msgid "==> CWD not needed.\n"
msgstr "==> CWD непатрэбнае.\n"

#: src/ftp.c:573
#, fuzzy, c-format
msgid ""
"No such directory %s.\n"
"\n"
msgstr ""
"Няма такой дырэкторыи \"%s\".\n"
"\n"

#: src/ftp.c:588
msgid "==> CWD not required.\n"
msgstr "==> CWD непатрэбнае.\n"

#: src/ftp.c:649
msgid "Cannot initiate PASV transfer.\n"
msgstr "Немагчыма ініцыялізаваць PASV-перадачу.\n"

#: src/ftp.c:653
msgid "Cannot parse PASV response.\n"
msgstr "Немагчыма зрабіць разбор PASV адказу.\n"

#: src/ftp.c:670
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "немагчыма далучыцца да %s, порт %d: %s\n"

#: src/ftp.c:718
#, c-format
msgid "Bind error (%s).\n"
msgstr "Памылка bind (%s).\n"

#: src/ftp.c:724
msgid "Invalid PORT.\n"
msgstr "Нерэчаісны порт.\n"

#: src/ftp.c:770
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""

#: src/ftp.c:811
#, fuzzy, c-format
msgid "No such file %s.\n"
msgstr ""
"Файл \"%s\" адсутнічае.\n"
"\n"

#: src/ftp.c:857
#, fuzzy, c-format
msgid ""
"No such file %s.\n"
"\n"
msgstr ""
"Файл \"%s\" адсутнічае.\n"
"\n"

#: src/ftp.c:904
#, fuzzy, c-format
msgid ""
"No such file or directory %s.\n"
"\n"
msgstr ""
"Файл ці тэчка \"%s'\" адсутнічае.\n"
"\n"

#: src/ftp.c:966 src/http.c:2261
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

#: src/ftp.c:1018
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, закрыцьцё кантрольнага далучэньня.\n"

#: src/ftp.c:1027
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr ""

#: src/ftp.c:1042
msgid "Control connection closed.\n"
msgstr "Кантрольнае далучэньне зачынена.\n"

#: src/ftp.c:1060
msgid "Data transfer aborted.\n"
msgstr "Абарваная перадача даньняў.\n"

#: src/ftp.c:1131
#, fuzzy, c-format
msgid "File %s already there; not retrieving.\n"
msgstr "Файл \"%s\" ужо тут і ня будзе выцягвацца.\n"

#: src/ftp.c:1201 src/http.c:2441
#, c-format
msgid "(try:%2d)"
msgstr "(спроба: %2d)"

#: src/ftp.c:1271 src/http.c:2774
#, fuzzy, c-format
msgid ""
"%s (%s) - %s saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - \"%s\" захавана [%s]\n"
"\n"

#: src/ftp.c:1313 src/main.c:1060 src/recur.c:378 src/retr.c:860
#, c-format
msgid "Removing %s.\n"
msgstr "Выдаленьне %s.\n"

#: src/ftp.c:1355
#, fuzzy, c-format
msgid "Using %s as listing tmp file.\n"
msgstr "Выкарыстаньне \"%s\" у якасьці лістынгу tmp-файла\n"

#: src/ftp.c:1369
#, fuzzy, c-format
msgid "Removed %s.\n"
msgstr "Выдалены \"%s\".\n"

#: src/ftp.c:1405
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr ""
"Значэньне рэкурсыўнае глыбіні %d большае за найбольшую дазволеную глыбіню %"
"d.\n"

#: src/ftp.c:1475
#, fuzzy, c-format
msgid "Remote file no newer than local file %s -- not retrieving.\n"
msgstr "Аддалены файл не навейшы за мясцовы файл \"%s\" -- не выцягваецца.\n"

#: src/ftp.c:1482
#, fuzzy, c-format
msgid ""
"Remote file is newer than local file %s -- retrieving.\n"
"\n"
msgstr "Аддалены файл навейшы за мясцовы файл \"%s\" -- выцягваецца.\n"

#: src/ftp.c:1489
#, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
