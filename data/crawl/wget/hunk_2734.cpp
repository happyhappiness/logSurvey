 "\n"
 
 #. do not CWD
-#: src/ftp.c:595
+#: src/ftp.c:502
 msgid "==> CWD not required.\n"
 msgstr "==> CWD nem sz�ks�ges.\n"
 
-#: src/ftp.c:654
+#: src/ftp.c:567
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Nem tudok kezdem�nyezni PASV �tvitelt.\n"
 
-#: src/ftp.c:658
+#: src/ftp.c:571
 msgid "Cannot parse PASV response.\n"
-msgstr "Nem tudom �rtelmezni a PASV v�laszt.\n"
+msgstr "Nem lehet �rtelmezni a PASV v�laszt.\n"
 
-#: src/ftp.c:676
-#, fuzzy, c-format
-msgid "couldn't connect to %s port %d: %s\n"
+#: src/ftp.c:588
+#, c-format
+msgid "couldn't connect to %s:%hu: %s\n"
 msgstr "nem tudok csatlakozni %s:%hu-hoz: %s\n"
 
-#: src/ftp.c:724
+#: src/ftp.c:638
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Hozz�rendel�si hiba (%s).\n"
 
-#: src/ftp.c:730
+#: src/ftp.c:645
 msgid "Invalid PORT.\n"
 msgstr "Hib�s PORT.\n"
 
-#: src/ftp.c:776
+#: src/ftp.c:698
+#, c-format
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
+msgstr ""
+"\n"
+"REST sikertelen; nem fogom t�rdelni `%s'-t.\n"
+
+#: src/ftp.c:705
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 "\n"
-"REST nem siker�lt, kezd�s el�lr�l.\n"
+"REST sikertelen, kezd�s el�lr�l.\n"
 
-#: src/ftp.c:837
+#: src/ftp.c:766
 #, c-format
 msgid ""
 "No such file `%s'.\n"
 "\n"
 msgstr ""
-"Nincs ilyen �llom�ny `%s'.\n"
+"Nincs ilyen f�jl `%s'.\n"
 "\n"
 
-#: src/ftp.c:884
+#: src/ftp.c:814
 #, c-format
 msgid ""
 "No such file or directory `%s'.\n"
 "\n"
 msgstr ""
-"Nincs ilyen �llom�ny vagy k�nyvt�r `%s'.\n"
+"Nincs ilyen f�jl vagy k�nyvt�r `%s'.\n"
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
+msgstr "Hossz: %s"
 
-#: src/ftp.c:1008
+#: src/ftp.c:900 src/ftp.c:908
+#, c-format
+msgid " [%s to go]"
+msgstr " [m�g %s]"
+
+#: src/ftp.c:910
+msgid " (unauthoritative)\n"
+msgstr " (nem hiteles)\n"
+
+#: src/ftp.c:936
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, vez�rl� kapcsolat bez�rva.\n"
 
-#: src/ftp.c:1016
+#: src/ftp.c:944
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Adat kapcsolat: %s; "
 
-#: src/ftp.c:1031
+#: src/ftp.c:961
 msgid "Control connection closed.\n"
 msgstr "Vez�rl� kapcsolat bez�rva.\n"
 
-#: src/ftp.c:1049
+#: src/ftp.c:979
 msgid "Data transfer aborted.\n"
 msgstr "Adat�tvitel megszak�tva.\n"
 
-#: src/ftp.c:1114
+#: src/ftp.c:1044
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr "Az `%s' �llom�ny m�r l�tezik, nem t�lt�m le.\n"
+msgstr "A(z) `%s' f�jl m�r l�tezik, nem t�lt�m le.\n"
 
-#: src/ftp.c:1182 src/http.c:2130
+#: src/ftp.c:1114 src/http.c:1716
 #, c-format
 msgid "(try:%2d)"
 msgstr "(pr�ba:%2d)"
 
-#: src/ftp.c:1252 src/http.c:2409
-#, fuzzy, c-format
+#: src/ftp.c:1180 src/http.c:1975
+#, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s]\n"
+"%s (%s) - `%s' saved [%ld]\n"
 "\n"
 msgstr ""
 "%s (%s) - `%s' lementve [%ld]\n"
 "\n"
 
-#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
+#: src/ftp.c:1222 src/main.c:890 src/recur.c:377 src/retr.c:596
 #, c-format
 msgid "Removing %s.\n"
 msgstr "T�rl�m %s.\n"
 
-#: src/ftp.c:1336
+#: src/ftp.c:1264
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "`%s'-t haszn�lom mint ideiglenes lista �llom�ny.\n"
+msgstr "`%s'-t haszn�lom mint ideiglenes listaf�jlt.\n"
 
-#: src/ftp.c:1351
+#: src/ftp.c:1279
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "T�r�lve `%s'.\n"
 
-#: src/ftp.c:1386
+#: src/ftp.c:1314
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Rekurzi�s hat�r %d t�ll�pte a maxim�lis %d m�lys�get.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1456
+#: src/ftp.c:1384
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr ""
-"A szerveren l�v� `%s' �llom�ny nem �jabb mint a helyi -- nem t�lt�m le.\n"
+msgstr "A szerveren l�v� `%s' f�jl nem �jabb mint a helyi -- nem t�lt�m le.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1463
+#: src/ftp.c:1391
 #, c-format
 msgid ""
 "Remote file is newer than local file `%s' -- retrieving.\n"
 "\n"
 msgstr ""
-"A szerveren l�v� `%s' �llom�ny �jabb mint a helyi -- let�lt�m.\n"
+"A szerveren l�v� `%s' f�jl �jabb mint a helyi -- let�lt�m.\n"
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
 msgstr ""
-"A m�retek nem eggyeznek (helyi %ld) -- let�lt�m.\n"
+"A m�retek nem egyeznek (helyi %ld) -- let�lt�m.\n"
 "\n"
 
-#: src/ftp.c:1488
+#: src/ftp.c:1415
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "Hib�s nev� szimb�likus link, kihagyom.\n"
+msgstr "Hib�s nev� szimbolikus link, kihagyom.\n"
 
-#: src/ftp.c:1505
+#: src/ftp.c:1432
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr ""
-"M�r l�tez� helyes szimb�likus link %s -> %s\n"
+"M�r l�tez� helyes szimbolikus link %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1513
+#: src/ftp.c:1440
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "L�trehozom a %s -> %s szimb�likus linket\n"
+msgstr "L�trehozom a(z) %s -> %s szimbolikus linket\n"
 
-#: src/ftp.c:1523
+#: src/ftp.c:1451
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "A `%s' szimb�likus linket kihagyom.\n"
+msgstr "A(z) `%s' szimbolikus linket kihagyom.\n"
 
-#: src/ftp.c:1535
+#: src/ftp.c:1463
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "A `%s' k�nyvt�rat kihagyom.\n"
+msgstr "A(z) `%s' k�nyvt�rat kihagyom.\n"
 
-#: src/ftp.c:1544
+#: src/ftp.c:1472
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: nem ismert/nem kezelhet� �llom�ny tipus.\n"
+msgstr "%s: nem ismert/nem t�mogatott f�jlt�pus.\n"
 
-#: src/ftp.c:1571
+#: src/ftp.c:1499
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: hib�s id�-bejegyz�s.\n"
+msgstr "%s: hib�s id�bejegyz�s.\n"
 
-#: src/ftp.c:1599
+#: src/ftp.c:1524
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "K�nyvt�rakat nem t�lt�m le, mivel a m�lys�g %d (max %d).\n"
 
-#: src/ftp.c:1649
+#: src/ftp.c:1574
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Nem l�pek be `%s'-be mert ki van z�rva/nincs kijel�lve.\n"
 
-#: src/ftp.c:1715 src/ftp.c:1729
+#: src/ftp.c:1639 src/ftp.c:1652
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Visszautas�tom `%s'-t.\n"
