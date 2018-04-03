msgid "Length: %s"
msgstr "Даўжыня: %s"

#: src/ftp.c:220 src/http.c:2174
#, c-format
msgid ", %s (%s) remaining"
msgstr ""

#: src/ftp.c:224 src/http.c:2178
#, c-format
msgid ", %s remaining"
msgstr ""

#: src/ftp.c:227
msgid " (unauthoritative)\n"
msgstr " (неаўтарытэтны)\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:303
#, c-format
msgid "Logging in as %s ... "
msgstr "Уваходжу як %s ... "

#: src/ftp.c:316 src/ftp.c:362 src/ftp.c:391 src/ftp.c:443 src/ftp.c:555
#: src/ftp.c:601 src/ftp.c:630 src/ftp.c:687 src/ftp.c:748 src/ftp.c:808
#: src/ftp.c:855
msgid "Error in server response, closing control connection.\n"
msgstr "Памылка ў адказе паслужніка; кантрольнае далучэньне зачынена.\n"

#: src/ftp.c:323
msgid "Error in server greeting.\n"
msgstr "Памылка ў вітаньні сэрвэра.\n"

#: src/ftp.c:330 src/ftp.c:451 src/ftp.c:563 src/ftp.c:638 src/ftp.c:697
#: src/ftp.c:758 src/ftp.c:818 src/ftp.c:865
msgid "Write failed, closing control connection.\n"
msgstr "Памылка запісу, закрыю кіроўнае злучэньне.\n"

#: src/ftp.c:336
msgid "The server refuses login.\n"
msgstr "Сэрвэр адмаўляе ва ўваходзе.\n"

#: src/ftp.c:342
msgid "Login incorrect.\n"
msgstr "Уваход не карэктны.\n"

#: src/ftp.c:348
msgid "Logged in!\n"
msgstr "Увайшоў!\n"

#: src/ftp.c:370
msgid "Server error, can't determine system type.\n"
msgstr "Памылка сэрвэра, немагчыма вызначыць тып сыстэмы.\n"

#: src/ftp.c:379 src/ftp.c:674 src/ftp.c:731 src/ftp.c:774
msgid "done.    "
msgstr "зроблена."

#: src/ftp.c:431 src/ftp.c:580 src/ftp.c:613 src/ftp.c:838 src/ftp.c:884
msgid "done.\n"
msgstr "зроблена.\n"

#: src/ftp.c:458
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Невядомы тып `%c', закрыю кіроўнае злучэньне.\n"

#: src/ftp.c:470
msgid "done.  "
msgstr "зроблена."

#: src/ftp.c:476
msgid "==> CWD not needed.\n"
msgstr "==> CWD непатрэбнае.\n"

#: src/ftp.c:569
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Няма такой дырэкторыи \"%s\".\n"
"\n"

#. do not CWD
#: src/ftp.c:584
msgid "==> CWD not required.\n"
msgstr "==> CWD непатрэбнае.\n"

#: src/ftp.c:644
msgid "Cannot initiate PASV transfer.\n"
msgstr "Немагчыма ініцыялізаваць PASV-перадачу.\n"

#: src/ftp.c:648
msgid "Cannot parse PASV response.\n"
msgstr "Немагчыма зрабіць разбор PASV адказу.\n"

#: src/ftp.c:665
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "немагчыма далучыцца да %s, порт %d: %s\n"

#: src/ftp.c:713
#, c-format
msgid "Bind error (%s).\n"
msgstr "Памылка bind (%s).\n"

#: src/ftp.c:719
msgid "Invalid PORT.\n"
msgstr "Нерэчаісны порт.\n"

#: src/ftp.c:765
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""

#: src/ftp.c:826
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Файл \"%s\" адсутнічае.\n"
"\n"

#: src/ftp.c:873
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Файл ці тэчка \"%s'\" адсутнічае.\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:935 src/http.c:2236
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

#: src/ftp.c:987
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, закрыцьцё кантрольнага далучэньня.\n"

#: src/ftp.c:996
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr ""

#: src/ftp.c:1011
msgid "Control connection closed.\n"
msgstr "Кантрольнае далучэньне зачынена.\n"

#: src/ftp.c:1029
msgid "Data transfer aborted.\n"
msgstr "Абарваная перадача даньняў.\n"

#: src/ftp.c:1097
#, c-format
msgid "File `%s' already there; not retrieving.\n"
msgstr "Файл \"%s\" ужо тут і ня будзе выцягвацца.\n"

#: src/ftp.c:1165 src/http.c:2394
#, c-format
msgid "(try:%2d)"
msgstr "(спроба: %2d)"

#: src/ftp.c:1235 src/http.c:2717
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - \"%s\" захавана [%s]\n"
"\n"

#: src/ftp.c:1277 src/main.c:1005 src/recur.c:378 src/retr.c:860
#, c-format
msgid "Removing %s.\n"
msgstr "Выдаленьне %s.\n"

#: src/ftp.c:1319
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Выкарыстаньне \"%s\" у якасьці лістынгу tmp-файла\n"

#: src/ftp.c:1334
#, c-format
msgid "Removed `%s'.\n"
msgstr "Выдалены \"%s\".\n"

#: src/ftp.c:1367
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Значэньне рэкурсыўнае глыбіні %d большае за найбольшую дазволеную глыбіню %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1437
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Аддалены файл не навейшы за мясцовы файл \"%s\" -- не выцягваецца.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1444
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr "Аддалены файл навейшы за мясцовы файл \"%s\" -- выцягваецца.\n"

#. Sizes do not match
#: src/ftp.c:1451
#, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
