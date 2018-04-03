 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU Wget 1.7-dev\n"
-"POT-Creation-Date: 2001-02-23 13:23-0800\n"
-"PO-Revision-Date: 2000-11-16 17:57+07:00\n"
+"Project-Id-Version: wget 1.7-pre1\n"
+"POT-Creation-Date: 2001-05-26 11:07+0200\n"
+"PO-Revision-Date: 2001-05-31 20:18+08:00\n"
 "Last-Translator: Const Kaplinsky <const@ce.cctpu.edu.ru>\n"
 "Language-Team: Russian <ru@li.org>\n"
 "MIME-Version: 1.0\n"
 "Content-Type: text/plain; charset=koi8-r\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#: src/ftp-ls.c:779
+#: src/cookies.c:588
+#, c-format
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "Ошибка в Set-Cookie, поле `%s'"
+
+#: src/cookies.c:612
+#, c-format
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
+msgstr "Синтаксическая ошибка в Set-Cookie, символ `%c'.\n"
+
+#: src/cookies.c:620
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
+msgstr "Синтаксическая ошибка в Set-Cookie: преждевременный конец строки.\n"
+
+#: src/cookies.c:1352
+#, c-format
+msgid "Cannot open cookies file `%s': %s\n"
+msgstr "Не удается открыть файл с \"cookies\", `%s': %s\n"
+
+#: src/cookies.c:1364
+#, c-format
+msgid "Error writing to `%s': %s\n"
+msgstr "Ошибка записи в `%s': %s\n"
+
+#: src/cookies.c:1368
+#, c-format
+msgid "Error closing `%s': %s\n"
+msgstr "Ошибка закрытия `%s': %s\n"
+
+#: src/ftp-ls.c:787
 msgid "Usupported listing type, trying Unix listing parser.\n"
-msgstr ""
+msgstr "Формат листинга не поддерживается, попытка использования Unix-формата.\n"
 
-#: src/ftp-ls.c:824 src/ftp-ls.c:826
+#: src/ftp-ls.c:832 src/ftp-ls.c:834
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Листинг каталога /%s на %s:%d"
 
-#: src/ftp-ls.c:848
+#: src/ftp-ls.c:856
 msgid "time unknown       "
 msgstr "время неизвестно   "
 
-#: src/ftp-ls.c:852
+#: src/ftp-ls.c:860
 msgid "File        "
 msgstr "Файл        "
 
-#: src/ftp-ls.c:855
+#: src/ftp-ls.c:863
 msgid "Directory   "
 msgstr "Каталог     "
 
-#: src/ftp-ls.c:858
+#: src/ftp-ls.c:866
 msgid "Link        "
 msgstr "Ссылка      "
 
-#: src/ftp-ls.c:861
+#: src/ftp-ls.c:869
 msgid "Not sure    "
 msgstr "Неизвестно  "
 
-#: src/ftp-ls.c:879
+#: src/ftp-ls.c:887
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s байт)"
 
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:151 src/http.c:618
+#: src/ftp.c:149 src/http.c:623
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "Установка соединения с %s:%hu... "
 
-#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
+#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "Сервер %s:%hu отклонил соединение.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:194 src/http.c:646
+#: src/ftp.c:192 src/http.c:651
 msgid "connected!\n"
 msgstr "соединились!\n"
 
-#: src/ftp.c:195
+#: src/ftp.c:193
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Регистрация под именем %s ... "
 
-#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
-#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
+#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
+#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
 msgid "Error in server response, closing control connection.\n"
 msgstr "Ошибка в реакции сервера, закрытие управляющего соединения.\n"
 
-#: src/ftp.c:212
+#: src/ftp.c:210
 msgid "Error in server greeting.\n"
 msgstr "Ошибка в приветствии сервера.\n"
 
-#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
-#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
+#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
+#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
 msgid "Write failed, closing control connection.\n"
 msgstr "Ошибка записи, закрытие управляющего соединения.\n"
 
-#: src/ftp.c:227
+#: src/ftp.c:225
 msgid "The server refuses login.\n"
 msgstr "Сервер отклонил регистрацию.\n"
 
-#: src/ftp.c:234
+#: src/ftp.c:232
 msgid "Login incorrect.\n"
 msgstr "Недопустимое имя или пароль.\n"
 
-#: src/ftp.c:241
+#: src/ftp.c:239
 msgid "Logged in!\n"
 msgstr "Регистрация прошла успешно!\n"
 
-#: src/ftp.c:266
+#: src/ftp.c:264
 msgid "Server error, can't determine system type.\n"
-msgstr ""
+msgstr "Ошибка на сервере, не удается определить тип системы.\n"
 
-#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
+#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
 msgid "done.    "
 msgstr "сделано.    "
 
-#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
+#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
 msgid "done.\n"
 msgstr "сделано.\n"
 
-#: src/ftp.c:330
+#: src/ftp.c:352
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Неизвестный тип `%c', закрытие управляющего соединения.\n"
 
-#: src/ftp.c:343
+#: src/ftp.c:365
 msgid "done.  "
 msgstr "сделано.  "
 
-#: src/ftp.c:349
+#: src/ftp.c:371
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD не нужна.\n"
 
-#: src/ftp.c:423
+#: src/ftp.c:444
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-"Отсутствует каталог `%s'.\n"
-"\n"
+msgid "No such directory `%s'.\n\n"
+msgstr "Отсутствует каталог `%s'.\n\n"
 
 #. do not CWD
-#: src/ftp.c:441
+#: src/ftp.c:462
 msgid "==> CWD not required.\n"
 msgstr "==> CWD не требуется.\n"
 
-#: src/ftp.c:475
+#: src/ftp.c:496
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Не удается начать PASV-передачу.\n"
 
-#: src/ftp.c:479
+#: src/ftp.c:500
 msgid "Cannot parse PASV response.\n"
 msgstr "Ошибка синтаксического разбора ответа PASV.\n"
 
-#: src/ftp.c:493
+#: src/ftp.c:514
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "Попытки соединения с %s:%hu будут продолжены.\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:601
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Ошибка bind (%s).\n"
 
-#: src/ftp.c:596
+#: src/ftp.c:617
 msgid "Invalid PORT.\n"
 msgstr "Недопустимый PORT.\n"
 
-#: src/ftp.c:643
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
-msgstr ""
-"\n"
-"Команда REST не выполнена, повтор с нулевой позиции.\n"
+#: src/ftp.c:670
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
+msgstr "\nКоманда REST не выполнена; усечение `%s' не производится.\n"
 
-#: src/ftp.c:692
+#: src/ftp.c:677
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\nКоманда REST не выполнена, повтор с нулевой позиции.\n"
+
+#: src/ftp.c:726
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-"Отсутствует файл `%s'.\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr "Отсутствует файл `%s'.\n\n"
 
-#: src/ftp.c:740
+#: src/ftp.c:774
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-"Отсутствует файл или каталог `%s'.\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr "Отсутствует файл или каталог `%s'.\n\n"
 
-#: src/ftp.c:816 src/ftp.c:823
+#: src/ftp.c:858 src/ftp.c:866
 #, c-format
 msgid "Length: %s"
 msgstr "Длина: %s"
 
-#: src/ftp.c:818 src/ftp.c:825
+#: src/ftp.c:860 src/ftp.c:868
 #, c-format
 msgid " [%s to go]"
 msgstr " [осталось %s]"
 
-#: src/ftp.c:827
+#: src/ftp.c:870
 msgid " (unauthoritative)\n"
 msgstr " (не достоверно)\n"
 
-#: src/ftp.c:853
+#: src/ftp.c:897
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, закрытие управляющего соединения.\n"
 
-#: src/ftp.c:861
+#: src/ftp.c:905
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Соединение: %s; "
 
-#: src/ftp.c:878
+#: src/ftp.c:922
 msgid "Control connection closed.\n"
 msgstr "Управляющее соединение закрыто.\n"
 
-#: src/ftp.c:896
+#: src/ftp.c:940
 msgid "Data transfer aborted.\n"
 msgstr "Передача данных прервана.\n"
 
-#: src/ftp.c:960
+#: src/ftp.c:1004
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Файл `%s' уже существует, получать не требуется.\n"
 
-#: src/ftp.c:1021 src/http.c:1394
+#: src/ftp.c:1074 src/http.c:1501
 #, c-format
 msgid "(try:%2d)"
 msgstr "(попытка:%2d)"
 
-#: src/ftp.c:1085 src/http.c:1632
+#: src/ftp.c:1138 src/http.c:1752
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' сохранен [%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
+msgstr "%s (%s) - `%s' сохранен [%ld]\n\n"
 
-#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
+#: src/ftp.c:1180 src/main.c:809 src/recur.c:483 src/retr.c:566
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Удаление %s.\n"
 
-#: src/ftp.c:1168
+#: src/ftp.c:1220
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Листинг будет сохранен во временном файле `%s'.\n"
 
-#: src/ftp.c:1180
+#: src/ftp.c:1232
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Удален `%s'.\n"
 
-#: src/ftp.c:1216
+#: src/ftp.c:1268
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Глубина рекурсии %d превысила максимальную глубину %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1277
-#, fuzzy, c-format
+#: src/ftp.c:1329
+#, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
 msgstr "Файл на сервере не новее локального файла `%s' -- пропуск.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1284
-#, fuzzy, c-format
-msgid ""
-"Remote file is newer than local file `%s' -- retrieving.\n"
-"\n"
-msgstr "Файл на сервере не новее локального файла `%s' -- пропуск.\n"
+#: src/ftp.c:1336
+#, c-format
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
+msgstr "Файл на сервере новее локального файла `%s' -- получение.\n"
 
 #. Sizes do not match
-#: src/ftp.c:1291
-#, fuzzy, c-format
-msgid ""
-"The sizes do not match (local %ld) -- retrieving.\n"
-"\n"
-msgstr "Размеры файлов не совпадают (локальный размер %ld) -- получение.\n"
+#: src/ftp.c:1343
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
+msgstr "Размеры не совпадают (локальный размер %ld) -- получение.\n"
 
-#: src/ftp.c:1308
+#: src/ftp.c:1360
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Недопустимое имя символьной ссылки, пропущено.\n"
 
-#: src/ftp.c:1325
+#: src/ftp.c:1377
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
-msgstr ""
-"Корректная ссылка %s -> %s уже существует.\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
+msgstr "Корректная ссылка %s -> %s уже существует.\n\n"
 
-#: src/ftp.c:1333
+#: src/ftp.c:1385
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Создание символьной ссылки %s -> %s\n"
 
-#: src/ftp.c:1344
+#: src/ftp.c:1396
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Символьные ссылки не поддерживаются, пропуск `%s'.\n"
 
-#: src/ftp.c:1356
+#: src/ftp.c:1408
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Пропуск каталога `%s'.\n"
 
-#: src/ftp.c:1365
+#: src/ftp.c:1417
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: тип файла неизвестен или не поддерживается.\n"
 
-#: src/ftp.c:1392
+#: src/ftp.c:1444
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: неверное время изменения файла.\n"
 
-#: src/ftp.c:1413
+#: src/ftp.c:1465
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Каталоги не будут получены, глубина составляет %d (максимум %d).\n"
 
-#: src/ftp.c:1449
+#: src/ftp.c:1511
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Каталог `%s' пропущен, так как находится в списке исключенных.\n"
 
-#: src/ftp.c:1494
+#: src/ftp.c:1558
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Пропуск `%s'.\n"
