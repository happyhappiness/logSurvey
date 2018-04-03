# Russian messages for GNU Wget.
# Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
# Const Kaplinsky <const@ce.cctpu.edu.ru>, 1998, 1999, 2000, 2001.
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.8\n"
"POT-Creation-Date: 2001-12-08 23:28+0100\n"
"PO-Revision-Date: 2001-12-10 22:22+07:00\n"
"Last-Translator: Const Kaplinsky <const@ce.cctpu.edu.ru>\n"
"Language-Team: Russian <ru@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=koi8-r\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:94
#, c-format
msgid "Connecting to %s[%s]:%hu... "
msgstr "Установка соединения с %s[%s]:%hu... "

#: src/connect.c:97
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Установка соединения с %s:%hu... "

#: src/connect.c:131
msgid "connected.\n"
msgstr "соединились.\n"

#: src/cookies.c:595
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Ошибка в Set-Cookie, поле `%s'"

#: src/cookies.c:619
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Синтаксическая ошибка в Set-Cookie, символ `%c'.\n"

#: src/cookies.c:627
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Синтаксическая ошибка в Set-Cookie: преждевременный конец строки.\n"

#: src/cookies.c:1329
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Не удается открыть файл с \"cookies\", `%s': %s\n"

#: src/cookies.c:1341
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Ошибка записи в `%s': %s\n"

#: src/cookies.c:1345
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Ошибка закрытия `%s': %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Формат листинга не поддерживается, попытка использования Unix-формата.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Листинг каталога /%s на %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "время неизвестно   "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Файл        "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Каталог     "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Ссылка      "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Неизвестно  "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s байт)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:179
#, c-format
msgid "Logging in as %s ... "
msgstr "Регистрация под именем %s ... "

#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
#: src/ftp.c:737
msgid "Error in server response, closing control connection.\n"
msgstr "Ошибка в реакции сервера, закрытие управляющего соединения.\n"

#: src/ftp.c:196
msgid "Error in server greeting.\n"
msgstr "Ошибка в приветствии сервера.\n"

#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
msgid "Write failed, closing control connection.\n"
msgstr "Ошибка записи, закрытие управляющего соединения.\n"

#: src/ftp.c:211
msgid "The server refuses login.\n"
msgstr "Сервер отклонил регистрацию.\n"

#: src/ftp.c:218
msgid "Login incorrect.\n"
msgstr "Недопустимое имя или пароль.\n"

#: src/ftp.c:225
msgid "Logged in!\n"
msgstr "Регистрация прошла успешно!\n"

#: src/ftp.c:250
msgid "Server error, can't determine system type.\n"
msgstr "Ошибка на сервере, не удается определить тип системы.\n"

#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
msgid "done.    "
msgstr "сделано.    "

#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
#: src/host.c:280
msgid "done.\n"
msgstr "сделано.\n"

#: src/ftp.c:343
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Неизвестный тип `%c', закрытие управляющего соединения.\n"

#: src/ftp.c:356
msgid "done.  "
msgstr "сделано.  "

#: src/ftp.c:362
msgid "==> CWD not needed.\n"
msgstr "==> CWD не нужна.\n"

#: src/ftp.c:435
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Отсутствует каталог `%s'.\n\n"

#. do not CWD
#: src/ftp.c:453
msgid "==> CWD not required.\n"
msgstr "==> CWD не требуется.\n"

#: src/ftp.c:516
msgid "Cannot initiate PASV transfer.\n"
msgstr "Не удается начать PASV-передачу.\n"

#: src/ftp.c:520
msgid "Cannot parse PASV response.\n"
msgstr "Ошибка синтаксического разбора ответа PASV.\n"

#: src/ftp.c:541
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "не удалось соединиться с %s:%hu: %s\n"

#: src/ftp.c:591
#, c-format
msgid "Bind error (%s).\n"
msgstr "Ошибка bind (%s).\n"

#: src/ftp.c:598
msgid "Invalid PORT.\n"
msgstr "Недопустимый PORT.\n"

#: src/ftp.c:651
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nКоманда REST не выполнена; усечение `%s' не производится.\n"

#: src/ftp.c:658
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nКоманда REST не выполнена, повтор с нулевой позиции.\n"

#: src/ftp.c:707
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Отсутствует файл `%s'.\n\n"

#: src/ftp.c:755
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Отсутствует файл или каталог `%s'.\n\n"

#: src/ftp.c:839 src/ftp.c:847
#, c-format
msgid "Length: %s"
msgstr "Длина: %s"

#: src/ftp.c:841 src/ftp.c:849
#, c-format
msgid " [%s to go]"
msgstr " [осталось %s]"

#: src/ftp.c:851
msgid " (unauthoritative)\n"
msgstr " (не достоверно)\n"

#: src/ftp.c:877
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, закрытие управляющего соединения.\n"

#: src/ftp.c:885
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Соединение: %s; "

#: src/ftp.c:902
msgid "Control connection closed.\n"
msgstr "Управляющее соединение закрыто.\n"

#: src/ftp.c:920
msgid "Data transfer aborted.\n"
msgstr "Передача данных прервана.\n"

#: src/ftp.c:984
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Файл `%s' уже существует, получать не требуется.\n"

#: src/ftp.c:1054 src/http.c:1527
#, c-format
msgid "(try:%2d)"
msgstr "(попытка:%2d)"

#: src/ftp.c:1118 src/http.c:1786
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' сохранен [%ld]\n\n"

#: src/ftp.c:1160 src/main.c:822 src/recur.c:349 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Удаление %s.\n"

#: src/ftp.c:1202
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Листинг будет сохранен во временном файле `%s'.\n"

#: src/ftp.c:1217
#, c-format
msgid "Removed `%s'.\n"
msgstr "Удален `%s'.\n"

#: src/ftp.c:1252
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Глубина рекурсии %d превысила максимальную глубину %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1317
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Файл на сервере не новее локального файла `%s' -- пропуск.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1324
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Файл на сервере новее локального файла `%s' -- получение.\n"

#. Sizes do not match
#: src/ftp.c:1331
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Размеры не совпадают (локальный размер %ld) -- получение.\n"

#: src/ftp.c:1348
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Недопустимое имя символьной ссылки, пропущено.\n"

#: src/ftp.c:1365
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Корректная ссылка %s -> %s уже существует.\n\n"

#: src/ftp.c:1373
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Создание символьной ссылки %s -> %s\n"

#: src/ftp.c:1384
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Символьные ссылки не поддерживаются, пропуск `%s'.\n"

#: src/ftp.c:1396
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Пропуск каталога `%s'.\n"

#: src/ftp.c:1405
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: тип файла неизвестен или не поддерживается.\n"

#: src/ftp.c:1432
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: неверное время изменения файла.\n"

#: src/ftp.c:1457
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Каталоги не будут получены, глубина составляет %d (максимум %d).\n"

#: src/ftp.c:1507
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Каталог `%s' пропущен, так как находится в списке исключенных.\n"

#: src/ftp.c:1561
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Пропуск `%s'.\n"

#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1608
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Нет совпадений с шаблоном `%s'.\n"

#: src/ftp.c:1673
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Листинг в формате HTML записан в файл `%s' [%ld].\n"

#: src/ftp.c:1678
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Листинг в формате HTML записан в файл `%s'.\n"

#: src/gen_sslfunc.c:109
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "Не удалось инициализировать PRNG в OpenSSL; протокол SSL запрещен.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: ключ `%s' недопустим в данном контексте\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: ключ `--%s' не позволяет задавать аргумент\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: ключ `%c%s' не позволяет задавать аргумент\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: ключ `%s' требует указания аргумента\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: нераспознанный ключ `--%s'\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: нераспознанный ключ `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: недопустимый ключ командной строки -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: ключ требует указания аргумента -- %c\n"

#: src/host.c:268
#, c-format
msgid "Resolving %s... "
msgstr "Преобразование адреса %s... "

#: src/host.c:275
#, c-format
msgid "failed: %s.\n"
msgstr "ошибка: %s.\n"

#: src/host.c:345
msgid "Host not found"
msgstr "Хост не найден"

#: src/host.c:347
msgid "Unknown error"
msgstr "Неизвестная ошибка"

#. this is fatal
#: src/http.c:573
msgid "Failed to set up an SSL context\n"
msgstr "Не удалось установить контекст SSL\n"

#: src/http.c:579
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Не удалось загрузить сертификаты с %s\n"

#: src/http.c:583 src/http.c:591
msgid "Trying without the specified certificate\n"
msgstr "Попытка продолжить без указанного сертификата\n"

#: src/http.c:587
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Не удалось получить ключ сертификата с %s\n"

#: src/http.c:657 src/http.c:1620
msgid "Unable to establish SSL connection.\n"
msgstr "Не удается установить соединение SSL.\n"

#: src/http.c:666
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Повторное использование соединения с %s:%hu.\n"

#: src/http.c:868
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Ошибка записи запроса HTTP: %s.\n"

#: src/http.c:873
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Запрос %s послан, ожидание ответа... "

#: src/http.c:917
msgid "End of file while parsing headers.\n"
msgstr "Конец файла во время разбора заголовков.\n"

#: src/http.c:927
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ошибка чтения (%s) в заголовках.\n"

#: src/http.c:962
msgid "No data received"
msgstr "Не получено никаких данных"

#: src/http.c:964
msgid "Malformed status line"
msgstr "Неполная строка статуса"

#: src/http.c:969
msgid "(no description)"
msgstr "(нет описания)"

#: src/http.c:1101
msgid "Authorization failed.\n"
msgstr "Авторизация прошла неудачно.\n"

#: src/http.c:1108
msgid "Unknown authentication scheme.\n"
msgstr "Неизвестная схема проверки полномочий.\n"

#: src/http.c:1148
#, c-format
msgid "Location: %s%s\n"
msgstr "Адрес: %s%s\n"

#: src/http.c:1149 src/http.c:1282
msgid "unspecified"
msgstr "нет информации"

#: src/http.c:1150
msgid " [following]"
msgstr " [переход]"

#: src/http.c:1213
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Файл уже получен полностью; нет действий.\n\n"

#: src/http.c:1229
#, c-format
msgid ""
"\n"
