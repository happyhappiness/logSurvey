 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU Wget 1.7-dev\n"
-"POT-Creation-Date: 2001-02-23 13:23-0800\n"
-"PO-Revision-Date: 2000-05-30 17:52+02:00\n"
+"Project-Id-Version: wget 1.7-pre1\n"
+"POT-Creation-Date: 2001-05-26 11:07+0200\n"
+"PO-Revision-Date: 2001-06-03 23:09+0200\n"
 "Last-Translator: Jacobo Tarrío Barreiro <jtarrio@iname.com>\n"
 "Language-Team: Galician <gpul-traduccion@ceu.fi.udc.es>\n"
 "MIME-Version: 1.0\n"
 "Content-Type: text/plain; charset=iso-8859-1\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#: src/ftp-ls.c:779
+#: src/cookies.c:588
+#, c-format
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "Erro en Set-Cookie, campo `%s'"
+
+#: src/cookies.c:612
+#, c-format
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
+msgstr "Erro de sintaxe en Set-Cookie no carácter `%c'.\n"
+
+#: src/cookies.c:620
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
+msgstr "Erro de sintaxe en Set-Cookie: fin de cadea prematura.\n"
+
+#: src/cookies.c:1352
+#, c-format
+msgid "Cannot open cookies file `%s': %s\n"
+msgstr "Non se pode abri-lo ficheiro de cookies `%s': %s\n"
+
+#: src/cookies.c:1364
+#, c-format
+msgid "Error writing to `%s': %s\n"
+msgstr "Non se pode escribir en `%s': %s\n"
+
+#: src/cookies.c:1368
+#, c-format
+msgid "Error closing `%s': %s\n"
+msgstr "Erro ao pechar `%s': %s\n"
+
+#: src/ftp-ls.c:787
 msgid "Usupported listing type, trying Unix listing parser.\n"
-msgstr ""
+msgstr "Tipo de listado non soportado, probando o analizador de listados Unix.\n"
 
-#: src/ftp-ls.c:824 src/ftp-ls.c:826
+#: src/ftp-ls.c:832 src/ftp-ls.c:834
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Índice de /%s en %s:%d"
 
-#: src/ftp-ls.c:848
+#: src/ftp-ls.c:856
 msgid "time unknown       "
 msgstr "data descoñecida   "
 
-#: src/ftp-ls.c:852
+#: src/ftp-ls.c:860
 msgid "File        "
 msgstr "Ficheiro    "
 
-#: src/ftp-ls.c:855
+#: src/ftp-ls.c:863
 msgid "Directory   "
 msgstr "Directorio  "
 
-#: src/ftp-ls.c:858
+#: src/ftp-ls.c:866
 msgid "Link        "
 msgstr "Ligazón     "
 
-#: src/ftp-ls.c:861
+#: src/ftp-ls.c:869
 msgid "Not sure    "
 msgstr "Non seguro  "
 
-#: src/ftp-ls.c:879
+#: src/ftp-ls.c:887
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s bytes)"
 
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:151 src/http.c:618
+#: src/ftp.c:149 src/http.c:623
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "Conectando con %s:%hu... "
 
-#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
+#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "A conexión a %s:%hu foi rexeitada.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:194 src/http.c:646
+#: src/ftp.c:192 src/http.c:651
 msgid "connected!\n"
 msgstr "¡conectado!\n"
 
-#: src/ftp.c:195
+#: src/ftp.c:193
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Identificándome coma %s ... "
 
-#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
-#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
+#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
+#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
 msgid "Error in server response, closing control connection.\n"
 msgstr "Erro na resposta do servidor, pechando a conexión de control.\n"
 
-#: src/ftp.c:212
+#: src/ftp.c:210
 msgid "Error in server greeting.\n"
 msgstr "Erro no saúdo do servidor.\n"
 
-#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
-#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
+#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
+#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
 msgid "Write failed, closing control connection.\n"
 msgstr "Erro escribindo, pechando a conexión de control.\n"
 
-#: src/ftp.c:227
+#: src/ftp.c:225
 msgid "The server refuses login.\n"
 msgstr "O servidor rexeita o login.\n"
 
-#: src/ftp.c:234
+#: src/ftp.c:232
 msgid "Login incorrect.\n"
 msgstr "Login incorrecto.\n"
 
-#: src/ftp.c:241
+#: src/ftp.c:239
 msgid "Logged in!\n"
 msgstr "¡Conectado!\n"
 
-#: src/ftp.c:266
+#: src/ftp.c:264
 msgid "Server error, can't determine system type.\n"
-msgstr ""
+msgstr "Erro no servidor, non se pode determina-lo tipo do sistema.\n"
 
-#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
+#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
 msgid "done.    "
 msgstr "feito.   "
 
-#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
+#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
 msgid "done.\n"
 msgstr "feito.\n"
 
-#: src/ftp.c:330
+#: src/ftp.c:352
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Tipo `%c' descoñecido, pechando a conexión de control.\n"
 
-#: src/ftp.c:343
+#: src/ftp.c:365
 msgid "done.  "
 msgstr "feito.  "
 
-#: src/ftp.c:349
+#: src/ftp.c:371
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD non foi necesario.\n"
 
-#: src/ftp.c:423
+#: src/ftp.c:444
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-"Non existe tal ficheiro ou directorio `%s'.\n"
-"\n"
+msgid "No such directory `%s'.\n\n"
+msgstr "Non existe tal ficheiro ou directorio `%s'.\n\n"
 
 #. do not CWD
-#: src/ftp.c:441
+#: src/ftp.c:462
 msgid "==> CWD not required.\n"
 msgstr "==> CWD non foi preciso.\n"
 
-#: src/ftp.c:475
+#: src/ftp.c:496
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "Non puiden comeza-la transferencia PASV.\n"
+msgstr "Non se puido comeza-la transferencia PASV.\n"
 
-#: src/ftp.c:479
+#: src/ftp.c:500
 msgid "Cannot parse PASV response.\n"
-msgstr "Non se pode entende-la resposta PASV.\n"
+msgstr "Non se puido analiza-la resposta PASV.\n"
 
-#: src/ftp.c:493
+#: src/ftp.c:514
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "Tentarase conectar con %s:%hu.\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:601
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Erro facendo bind (%s).\n"
 
-#: src/ftp.c:596
+#: src/ftp.c:617
 msgid "Invalid PORT.\n"
 msgstr "PORT incorrecto.\n"
 
-#: src/ftp.c:643
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
-msgstr ""
-"\n"
-"REST fallou, comezando dende o principio.\n"
+#: src/ftp.c:670
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
+msgstr "\nREST fallou; non se ha truncar `%s'.\n"
+
+#: src/ftp.c:677
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\nREST fallou, comezando dende o principio.\n"
 
-#: src/ftp.c:692
+#: src/ftp.c:726
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-"Non hai tal ficheiro `%s'.\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr "Non hai tal ficheiro `%s'.\n\n"
 
-#: src/ftp.c:740
+#: src/ftp.c:774
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-"Non hai tal ficheiro ou directorio `%s'.\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr "Non hai tal ficheiro ou directorio `%s'.\n\n"
 
-#: src/ftp.c:816 src/ftp.c:823
+#: src/ftp.c:858 src/ftp.c:866
 #, c-format
 msgid "Length: %s"
 msgstr "Lonxitude: %s"
 
-#: src/ftp.c:818 src/ftp.c:825
+#: src/ftp.c:860 src/ftp.c:868
 #, c-format
 msgid " [%s to go]"
-msgstr " [%s para rematar]"
+msgstr " [quedan %s por descargar]"
 
-#: src/ftp.c:827
+#: src/ftp.c:870
 msgid " (unauthoritative)\n"
 msgstr " (dato non fidedigno)\n"
 
-#: src/ftp.c:853
+#: src/ftp.c:897
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, pechando a conexión de control.\n"
 
-#: src/ftp.c:861
+#: src/ftp.c:905
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Conexión de datos: %s; "
 
-#: src/ftp.c:878
+#: src/ftp.c:922
 msgid "Control connection closed.\n"
 msgstr "Conexión de control pechada.\n"
 
-#: src/ftp.c:896
+#: src/ftp.c:940
 msgid "Data transfer aborted.\n"
 msgstr "Transferencia de datos abortada.\n"
 
-#: src/ftp.c:960
+#: src/ftp.c:1004
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "O ficheiro `%s' xa está aí, non se ha descargar.\n"
 
-#: src/ftp.c:1021 src/http.c:1394
+#: src/ftp.c:1074 src/http.c:1501
 #, c-format
 msgid "(try:%2d)"
 msgstr "(intento:%2d)"
 
-#: src/ftp.c:1085 src/http.c:1632
+#: src/ftp.c:1138 src/http.c:1752
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
 msgstr "%s (%s) - `%s' gardado [%ld]\n"
 
-#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
+#: src/ftp.c:1180 src/main.c:809 src/recur.c:483 src/retr.c:566
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Borrando %s.\n"
 
-#: src/ftp.c:1168
+#: src/ftp.c:1220
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Usando `%s' coma un ficheiro temporal de listado.\n"
 
-#: src/ftp.c:1180
+#: src/ftp.c:1232
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Borrado `%s'.\n"
 
-#: src/ftp.c:1216
+#: src/ftp.c:1268
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "A profundidade de recursión %d excedeu a máxima %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1277
-#, fuzzy, c-format
+#: src/ftp.c:1329
+#, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "O ficheiro remoto é máis novo, descargando.\n"
+msgstr "O ficheiro remoto non é máis novo có ficheiro local `%s' -- non se descarga.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1284
-#, fuzzy, c-format
-msgid ""
-"Remote file is newer than local file `%s' -- retrieving.\n"
-"\n"
-msgstr "O ficheiro remoto é máis novo, descargando.\n"
+#: src/ftp.c:1336
+#, c-format
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
+msgstr "O ficheiro remoto é máis novo có ficheiro local `%s' -- descargando.\n\n"
 
 #. Sizes do not match
-#: src/ftp.c:1291
-#, fuzzy, c-format
-msgid ""
-"The sizes do not match (local %ld) -- retrieving.\n"
-"\n"
-msgstr "Os tamaños non coinciden (local %ld), descargando.\n"
+#: src/ftp.c:1343
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
+msgstr "Os tamaños non coinciden (local %ld) -- descargando.\n\n"
 
-#: src/ftp.c:1308
+#: src/ftp.c:1360
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "O nome da ligazón simbólica é incorrecto, omitindo.\n"
 
-#: src/ftp.c:1325
+#: src/ftp.c:1377
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
-msgstr ""
-"Xa ten unha ligazón simbólica correcta %s -> %s\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
+msgstr "Xa ten unha ligazón simbólica correcta %s -> %s\n\n"
 
-#: src/ftp.c:1333
+#: src/ftp.c:1385
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Creando a ligazón simbólica %s -> %s\n"
 
-#: src/ftp.c:1344
+#: src/ftp.c:1396
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Ligazóns simbólicas non soportadas, omitindo `%s'.\n"
 
-#: src/ftp.c:1356
+#: src/ftp.c:1408
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Omitindo o directorio `%s'.\n"
 
-#: src/ftp.c:1365
+#: src/ftp.c:1417
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: tipo de ficheiro descoñecido ou non soportado.\n"
 
-#: src/ftp.c:1392
+#: src/ftp.c:1444
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: data e hora corrompidas.\n"
 
-#: src/ftp.c:1413
+#: src/ftp.c:1465
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr ""
-"Non hei descargar directorios, porque a profundidade chegou a %d (máximo "
-"%d).\n"
+msgstr "Non se han descargar directorios, porque a profundidade chegou a %d (máximo %d).\n"
 
-#: src/ftp.c:1449
+#: src/ftp.c:1511
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr "Non descendo a %s' porque está excluído ou non incluído.\n"
+msgstr "Non se ha descender a %s' porque está excluído ou non incluído.\n"
 
-#: src/ftp.c:1494
+#: src/ftp.c:1558
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Rexeitando `%s'.\n"
