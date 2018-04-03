-# Translation of wget messages to Catalan.
-# Copyright (C) 2001, 2002 Free Software Foundation, Inc.
-# Jordi Valverde Sivilla <jordi@eclipsi.net>, 2001, 2002.
+# Missatges del `wget' en Català
+# Copyright (C) 2002 Free Software Foundation, Inc.
+# Jordi Valverde Sivilla <jordi@eclipsi.net>, 2002.
 #
 msgid ""
 msgstr ""
-"Project-Id-Version: wget 1.8\n"
-"POT-Creation-Date: 2001-12-08 23:28+0100\n"
-"PO-Revision-Date: 2002-01-13 21:29+0100\n"
+"Project-Id-Version: wget 1.9\n"
+"POT-Creation-Date: 2003-10-11 16:21+0200\n"
+"PO-Revision-Date: 2003-10-30 01:00+0100\n"
 "Last-Translator: Jordi Valverde Sivilla <jordi@eclipsi.net>\n"
 "Language-Team: Catalan <ca@dodds.net>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=iso-8859-1\n"
+"Content-Type: text/plain; charset=ISO-8859-1\n"
 "Content-Transfer-Encoding: 8bit\n"
+"X-Generator: KBabel 0.9.5\n"
 
-#: src/connect.c:94
+#: src/connect.c:88
+#, c-format
+msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
+msgstr "No s'ha pogut convertir `%s' en una adreça vàlida. S'utilitza `ANY'.\n"
+
+#: src/connect.c:165
 #, c-format
 msgid "Connecting to %s[%s]:%hu... "
-msgstr "Conectant a %s[%s]:%hu... "
+msgstr "Connectant amb %s[%s]:%hu... "
 
-#: src/connect.c:97
+#: src/connect.c:168
 #, c-format
 msgid "Connecting to %s:%hu... "
-msgstr "Conectant a %s:%hu... "
+msgstr "Connectant amb %s:%hu... "
 
-#: src/connect.c:131
+#: src/connect.c:222
 msgid "connected.\n"
-msgstr "conectat.\n"
+msgstr "connexió establerta.\n"
 
-#: src/cookies.c:595
+#: src/convert.c:171
 #, c-format
-msgid "Error in Set-Cookie, field `%s'"
-msgstr "Error al fixar a la secció de la cookie `%s'"
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "S'han convertit %d arxius en %.2f segons.\n"
+
+#: src/convert.c:197
+#, c-format
+msgid "Converting %s... "
+msgstr "Convertint %s... "
+
+#: src/convert.c:210
+msgid "nothing to do.\n"
+msgstr "res a fer.\n"
+
+#: src/convert.c:218 src/convert.c:242
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "No s'han pogut convertir els enllaços de `%s': %s\n"
+
+#: src/convert.c:233
+#, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "No s'ha pogut esborrar `%s': %s\n"
+
+#: src/convert.c:439
+#, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "No s'ha pogut fer una còpia de %s com a %s: %s\n"
 
-#: src/cookies.c:619
+#: src/cookies.c:606
 #, c-format
-msgid "Syntax error in Set-Cookie at character `%c'.\n"
-msgstr "Error de sintaxi al fixar la cookie al caracter `%c'.\n"
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "Error a la capçalera Set-Cockie, camp `%s'"
 
-#: src/cookies.c:627
-msgid "Syntax error in Set-Cookie: premature end of string.\n"
-msgstr "Error de sintaxi al fixar la cookie: final inesperat.\n"
+#: src/cookies.c:629
+#, c-format
+msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+msgstr "Error de sintaxi a la capçalera Set-Cookie: %s a la posició %d.\n"
 
-#: src/cookies.c:1329
+#: src/cookies.c:1426
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
-msgstr "No es pot obrir el arxiu de cookies `%s': %s\n"
+msgstr "No s'ha pogut obrir el fitxer de cookies `%s': %s\n"
 
-#: src/cookies.c:1341
+#: src/cookies.c:1438
 #, c-format
 msgid "Error writing to `%s': %s\n"
-msgstr "Error d'escriptura a `%s': %s\n"
+msgstr "Error quan s'escrivia `%s': %s\n"
 
-#: src/cookies.c:1345
+#: src/cookies.c:1442
 #, c-format
 msgid "Error closing `%s': %s\n"
-msgstr "Error tancant `%s': %s\n"
+msgstr "Error quan es tancava `%s': %s\n"
 
-#: src/ftp-ls.c:787
+#: src/ftp-ls.c:812
 msgid "Unsupported listing type, trying Unix listing parser.\n"
-msgstr "tipus de llistat no soportat, intentant fent servir el parsejador de Unix.\n"
+msgstr "Tipus de llista no suportat, provant amb l'analitzador de Unix.\n"
 
-#: src/ftp-ls.c:832 src/ftp-ls.c:834
+#: src/ftp-ls.c:857 src/ftp-ls.c:859
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Índex de /%s a %s:%d"
 
-#: src/ftp-ls.c:856
+#: src/ftp-ls.c:882
 msgid "time unknown       "
-msgstr "temps desconegut       "
+msgstr "data no disponible "
 
-#: src/ftp-ls.c:860
+#: src/ftp-ls.c:886
 msgid "File        "
-msgstr "Arxiu         "
+msgstr "Fitxer      "
 
-#: src/ftp-ls.c:863
+#: src/ftp-ls.c:889
 msgid "Directory   "
 msgstr "Directori   "
 
-#: src/ftp-ls.c:866
+#: src/ftp-ls.c:892
 msgid "Link        "
-msgstr "Enllaç        "
+msgstr "Enllaç      "
 
-#: src/ftp-ls.c:869
+#: src/ftp-ls.c:895
 msgid "Not sure    "
-msgstr "No segur    "
+msgstr "            "
 
-#: src/ftp-ls.c:887
+#: src/ftp-ls.c:913
 #, c-format
 msgid " (%s bytes)"
-msgstr " (%s bytes)"
+msgstr " (%s octets)"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:179
+#: src/ftp.c:202
 #, c-format
 msgid "Logging in as %s ... "
-msgstr "entrant com a %s ... "
+msgstr "Entrant com a `%s' ... "
 
-#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
-#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
-#: src/ftp.c:737
+#: src/ftp.c:215 src/ftp.c:268 src/ftp.c:299 src/ftp.c:353 src/ftp.c:468
+#: src/ftp.c:519 src/ftp.c:551 src/ftp.c:611 src/ftp.c:675 src/ftp.c:748
+#: src/ftp.c:796
 msgid "Error in server response, closing control connection.\n"
-msgstr "Error en el servidor, tancant la conexió de control.\n"
+msgstr "Resposta del servidor errònia, tancant la connexió de control.\n"
 
-#: src/ftp.c:196
+#: src/ftp.c:223
 msgid "Error in server greeting.\n"
-msgstr "Error en la benvinguda del servidor.\n"
+msgstr "Missatge de benvinguda del servidor erroni.\n"
 
-#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
-#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
+#: src/ftp.c:231 src/ftp.c:362 src/ftp.c:477 src/ftp.c:560 src/ftp.c:621
+#: src/ftp.c:685 src/ftp.c:758 src/ftp.c:806
 msgid "Write failed, closing control connection.\n"
-msgstr "Escritura fallada, tancant la conexió de control.\n"
+msgstr "Error d'escriptura, tancant la connexió de control.\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:238
 msgid "The server refuses login.\n"
-msgstr "El servidor refusa la entrada.\n"
+msgstr "El servidor refusa les peticions d'entrada.\n"
 
-#: src/ftp.c:218
+#: src/ftp.c:245
 msgid "Login incorrect.\n"
-msgstr "entrada incorrecte.\n"
+msgstr "Entrada incorrecta.\n"
 
-#: src/ftp.c:225
+#: src/ftp.c:252
 msgid "Logged in!\n"
-msgstr "entrada aconseguida!\n"
+msgstr "S'ha entrat amb èxit!\n"
 
-#: src/ftp.c:250
+#: src/ftp.c:277
 msgid "Server error, can't determine system type.\n"
-msgstr "Error de servidor, no es pot determinar el tipus de sistema.\n"
+msgstr "Error del servidor, no es pot determinar el tipus de sistema.\n"
 
-#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
+#: src/ftp.c:287 src/ftp.c:596 src/ftp.c:659 src/ftp.c:716
 msgid "done.    "
-msgstr "fet.    "
+msgstr "fet.     "
 
-#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
-#: src/host.c:280
+#: src/ftp.c:341 src/ftp.c:498 src/ftp.c:533 src/ftp.c:779 src/ftp.c:827
 msgid "done.\n"
 msgstr "fet.\n"
 
-#: src/ftp.c:343
+#: src/ftp.c:370
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "Tipus desconegut `%c', tancant la conexió de control.\n"
+msgstr "Tipus desconegut `%c', tancant la connexió de control.\n"
 
-#: src/ftp.c:356
+#: src/ftp.c:383
 msgid "done.  "
-msgstr "fet.  "
+msgstr "fet.   "
 
-#: src/ftp.c:362
+#: src/ftp.c:389
 msgid "==> CWD not needed.\n"
-msgstr "==> CWD no necessari.\n"
+msgstr "==> CWD innecessari.\n"
 
-#: src/ftp.c:435
+#: src/ftp.c:484
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr "No existeix el directori `%s'.\n\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+"El directori `%s' no existeix.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:453
+#: src/ftp.c:502
 msgid "==> CWD not required.\n"
 msgstr "==> CWD no requerit.\n"
 
-#: src/ftp.c:516
+#: src/ftp.c:567
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "No es pot iniciar la transferéncia en PASV.\n"
+msgstr "No s'ha pogut iniciar la transferència PASV.\n"
 
-#: src/ftp.c:520
+#: src/ftp.c:571
 msgid "Cannot parse PASV response.\n"
-msgstr "No es pot parsejar la resposta en PASV.\n"
+msgstr "No s'ha pogut analitzar la resposta PASV.\n"
 
-#: src/ftp.c:541
+#: src/ftp.c:588
 #, c-format
 msgid "couldn't connect to %s:%hu: %s\n"
-msgstr "no es pot conectar a `%s:%hu: %s\n"
+msgstr "no s'ha pogut connectar amb `%s:%hu: %s\n"
 
-#: src/ftp.c:591
-#, c-format
+#: src/ftp.c:638
+#, fuzzy, c-format
 msgid "Bind error (%s).\n"
-msgstr "Error a la trucada `bind' (%s).\n"
+msgstr "Error de la rutina `bind' (%s).\n"
 
-#: src/ftp.c:598
+#: src/ftp.c:645
 msgid "Invalid PORT.\n"
 msgstr "PORT incorrecte.\n"
 
-#: src/ftp.c:651
+#: src/ftp.c:698
 #, c-format
-msgid "\nREST failed; will not truncate `%s'.\n"
-msgstr "\nREST fallat; no es truncarà `%s'.\n"
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
+msgstr ""
+"\n"
+"REST ha fallat; `%s' no es truncarà.\n"
 
-#: src/ftp.c:658
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nREST ha fallat, començant des del inici.\n"
+#: src/ftp.c:705
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"REST ha fallat, començant des del principi.\n"
 
-#: src/ftp.c:707
+#: src/ftp.c:766
 #, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "No existeix el arxiu `%s'.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"El fitxer `%s' no existeix.\n"
+"\n"
 
-#: src/ftp.c:755
+#: src/ftp.c:814
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "No existeix el arxiu o directori `%s'.\n\n"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"El fitxer o directori `%s' no existeix.\n"
+"\n"
 
-#: src/ftp.c:839 src/ftp.c:847
+#: src/ftp.c:898 src/ftp.c:906
 #, c-format
 msgid "Length: %s"
-msgstr "Longitut: %s"
+msgstr "Mida: %s"
 
-#: src/ftp.c:841 src/ftp.c:849
+#: src/ftp.c:900 src/ftp.c:908
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s per acabar]"
 
-#: src/ftp.c:851
+#: src/ftp.c:910
+#, fuzzy
 msgid " (unauthoritative)\n"
-msgstr " (probablement)\n"
+msgstr " (no autoritariu)\n"
 
-#: src/ftp.c:877
+#: src/ftp.c:936
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, tancant la conexió de control.\n"
+msgstr "%s: %s, tancant la connexió de control.\n"
 
-#: src/ftp.c:885
+#: src/ftp.c:944
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
-msgstr "%s (%s)   Conexió de dades: %s; "
+msgstr "%s (%s) - Connexió de dades: %s; "
 
-#: src/ftp.c:902
+#: src/ftp.c:961
 msgid "Control connection closed.\n"
-msgstr "Conexió de control tancada.\n"
+msgstr "Connexió de control tancada.\n"
 
-#: src/ftp.c:920
+#: src/ftp.c:979
 msgid "Data transfer aborted.\n"
-msgstr "Transferéncia de dades cancel·lada.\n"
+msgstr "Transferència de dades cancel·lada.\n"
 
-#: src/ftp.c:984
-#, c-format
+#: src/ftp.c:1044
+#, fuzzy, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr "L'arxiu `%s' ja existeix, no es descarregarà.\n"
+msgstr "El fitxer `%s' ja existeix, no es descarrega.\n"
 
-#: src/ftp.c:1054 src/http.c:1527
+#: src/ftp.c:1114 src/http.c:1716
 #, c-format
 msgid "(try:%2d)"
-msgstr "(prova:%2d)"
+msgstr "(intent:%2d)"
 
-#: src/ftp.c:1118 src/http.c:1786
+#: src/ftp.c:1180 src/http.c:1975
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s)   `%s guardat [%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' desat [%ld]\n"
+"\n"
 
-#: src/ftp.c:1160 src/main.c:822 src/recur.c:349 src/retr.c:587
+#: src/ftp.c:1222 src/main.c:890 src/recur.c:377 src/retr.c:596
 #, c-format
 msgid "Removing %s.\n"
-msgstr "Esborrant %s.\n"
+msgstr "Eliminant %s.\n"
 
-#: src/ftp.c:1202
+#: src/ftp.c:1264
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "Utilitzant `%s' com a un arxiu de llistat temporal.\n"
+msgstr "S'utilitza `%s' com a fitxer temporal de llistat.\n"
 
-#: src/ftp.c:1217
+#: src/ftp.c:1279
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr "Esborrat `%s'.\n"
+msgstr "Eliminat `%s'.\n"
 
-#: src/ftp.c:1252
+#: src/ftp.c:1314
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr "La profunditat de recursió %d excedeix el màxim permés %d.\n"
+msgstr "La profunditat de recursió %d excedeix el màxim permès %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1317
+#: src/ftp.c:1384
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "L'arxiu remot no és més nou que l'arxiu local `%s' -- no es descarrega.\n"
+msgstr "El fitxer remot no és més nou que el local `%s' -- no es descarrega.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1324
+#: src/ftp.c:1391
 #, c-format
-msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
-msgstr "L'arxiu remot és més nou que l'arxiu local `%s' -- descarregant.\n\n"
+msgid ""
+"Remote file is newer than local file `%s' -- retrieving.\n"
+"\n"
+msgstr ""
+"El fitxer remot és més nou que el local `%s' -- es descarrega.\n"
+"\n"
 
 #. Sizes do not match
-#: src/ftp.c:1331
+#: src/ftp.c:1398
 #, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
-msgstr "Els tamanys no corresponen (local %ld) -- descarregant.\n"
+msgid ""
+"The sizes do not match (local %ld) -- retrieving.\n"
+"\n"
+msgstr ""
+"Els fitxers no tenen la mateixa mida (local %ld) -- es descarrega.\n"
+"\n"
 
-#: src/ftp.c:1348
+#: src/ftp.c:1415
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "El nom del enllaç és incorrecte; omitint.\n"
+msgstr "El nom de l'enllaç simbólic no és correcte; s'omet.\n"
 
-#: src/ftp.c:1365
-#, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
-msgstr "Ja té el enllaç correcte %s --> %s\n\n"
+#: src/ftp.c:1432
+#, fuzzy, c-format
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
+msgstr ""
+"Ja hi ha un enllaç simbòlic correcte %s -> %s\n"
+"\n"
 
-#: src/ftp.c:1373
+#: src/ftp.c:1440
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "Creant enllaç %s --> %s\n"
+msgstr "Creant l'enllaç simbólic %s -> %s\n"
 
-#: src/ftp.c:1384
+#: src/ftp.c:1451
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Els enllaços no estan suportats, omitint enllaç `%s'.\n"
+msgstr "No es suporten enllaços simbòlics; s'omet l'enllaç `%s'.\n"
 
-#: src/ftp.c:1396
+#: src/ftp.c:1463
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "omitint directori `%s'.\n"
+msgstr "Ometent el directori `%s'.\n"
 
-#: src/ftp.c:1405
+#: src/ftp.c:1472
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: tipus d'arxiu desconegut/no soportat.\n"
+msgstr "%s: tipus de fitxer desconegut, o no suportat.\n"
 
-#: src/ftp.c:1432
+#: src/ftp.c:1499
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: marca de temps corrupte.\n"
+msgstr "%s: informació horària corrupta.\n"
 
-#: src/ftp.c:1457
-#, c-format
+#: src/ftp.c:1524
+#, fuzzy, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr "No es descarregaran els directoris perquè la profunditat es %d (màx %d).\n"
+msgstr "No es descarregaran directoris ja que la profunditat és %d (max %d).\n"
 
-#: src/ftp.c:1507
+#: src/ftp.c:1574
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr "Es descén fins a `%s' per estar exclós/no inclós.\n"
+msgstr "No es descendeix a `%s' ja que està exclòs, o no inclòs.\n"
 
-#: src/ftp.c:1561
+#: src/ftp.c:1639 src/ftp.c:1652
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Rebutjant `%s'.\n"
