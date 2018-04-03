msgstr ""
"\n"
"ЗАВЕРШЕНО --%s--\n"
"Принято: %s байт в %d файлax\n"

#: src/main.c:854
#, c-format
msgid "Download quota (%s bytes) EXCEEDED!\n"
msgstr "ПРЕВЫШЕНО ограничение объема (%s байт)!\n"

#. Please note that the double `%' in `%%s' is intentional, because
#. redirect_output passes tmp through printf.
#: src/main.c:896
#, c-format
msgid "%s received, redirecting output to `%%s'.\n"
msgstr "Получен сигнал %s, вывод перенаправлен в `%%s'.\n"

#: src/mswindows.c:106
#, c-format
msgid ""
"\n"
"CTRL+Break received, redirecting output to `%s'.\n"
"Execution continued in background.\n"
"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
msgstr ""
"\n"
"Нажаты CTRL+Break, вывод перенаправляется в `%s'.\n"
"Выполнение программы будет продолжено в фоновом режиме.\n"
"Вы можете остановить работу Wget нажатием CTRL+ALT+DELETE.\n"

#. parent, no error
#: src/mswindows.c:123 src/utils.c:467
msgid "Continuing in background.\n"
msgstr "Продолжение работы в фоновом режиме.\n"

#: src/mswindows.c:125 src/utils.c:469
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "Выходная информация будет записана в файл `%s'.\n"

#: src/mswindows.c:205
#, c-format
msgid "Starting WinHelp %s\n"
msgstr "Запуск WinHelp %s\n"

#: src/mswindows.c:232 src/mswindows.c:239
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Не найден подходящий драйвер TCP/IP.\n"

#: src/netrc.c:365
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: предупреждение: лексема \"%s\" встречена ранее имени машины\n"

#: src/netrc.c:396
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: неизвестная лексема \"%s\"\n"

#: src/netrc.c:460
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Использование: %s NETRC [HOSTNAME]\n"

#: src/netrc.c:470
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: не удается выполнить stat для %s: %s\n"

#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:224
#, c-format
msgid "\n%*s[ skipping %dK ]"
msgstr "\n%*s[ пропуск %dK ]"

#: src/progress.c:391
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr "Недопустимое описание `%s'; стиль оставлен без изменений.\n"

#: src/recur.c:350
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Удаление %s, так как этот файл должен быть исключен.\n"

#: src/recur.c:916
#, c-format
msgid "Converted %d files in %.2f seconds.\n"
msgstr "Преобразовано %d файлов за %.2f секунд.\n"

#: src/res.c:541
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Загрузка robots.txt; не обращайте внимания на ошибки.\n"

#: src/retr.c:363
msgid "Could not find proxy host.\n"
msgstr "Не найден прокси-сервер.\n"

#: src/retr.c:375
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "Ошибка разбора URL прокси-сервера %s: %s\n"

#: src/retr.c:384
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "Ошибка в URL прокси-сервера %s: Допускается только HTTP.\n"

#: src/retr.c:476
#, c-format
msgid "%d redirections exceeded.\n"
msgstr "Более %d перенаправлений.\n"

#: src/retr.c:491
#, c-format
msgid "%s: Redirection cycle detected.\n"
msgstr "%s: Замкнутый цикл перенаправлений.\n"

#: src/retr.c:608
msgid "Giving up.\n\n"
msgstr "Завершение.\n\n"

#: src/retr.c:608
msgid "Retrying.\n\n"
msgstr "Продолжение попыток.\n\n"

#: src/url.c:1748
#, c-format
msgid "Converting %s... "
msgstr "Преобразование %s... "

#: src/url.c:1761
msgid "nothing to do.\n"
msgstr "действия не заданы.\n"

#: src/url.c:1769 src/url.c:1793
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Не удается преобразовать ссылки в %s: %s\n"

#: src/url.c:1784
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Ошибка удаления `%s': %s\n"

#: src/url.c:1990
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Не удается сохранить %s под именем %s: %s\n"

#: src/utils.c:102
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: Недостаточно памяти.\n"

#: src/utils.c:667
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "Ошибка удаления символьной ссылки `%s': %s\n"

#~ msgid "Connection to %s:%hu refused.\n"
#~ msgstr "Сервер %s:%hu отклонил соединение.\n"

#~ msgid "Will try connecting to %s:%hu.\n"
#~ msgstr "Попытки соединения с %s:%hu будут продолжены.\n"

#~ msgid "Unknown/unsupported protocol"
#~ msgstr "Протокол неизвестен или не поддерживается."

#~ msgid "Invalid port specification"
#~ msgstr "Недопустимое обозначение порта"

#~ msgid "Invalid host name"
#~ msgstr "Недопустимое имя машины"
