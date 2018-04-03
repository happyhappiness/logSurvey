#     ... Kontroll-Verbindung wird geschlossen
# oder
#     ... Schließen der Kontroll-Verbindung
#: src/ftp.c:316 src/ftp.c:362 src/ftp.c:391 src/ftp.c:443 src/ftp.c:555
#: src/ftp.c:601 src/ftp.c:630 src/ftp.c:687 src/ftp.c:748 src/ftp.c:808
#: src/ftp.c:855
msgid "Error in server response, closing control connection.\n"
msgstr "Fehler in der Antwort des Servers; schließe Kontroll-Verbindung.\n"

#: src/ftp.c:323
msgid "Error in server greeting.\n"
msgstr "Fehler bei der Begrüßung des Servers.\n"

#: src/ftp.c:330 src/ftp.c:451 src/ftp.c:563 src/ftp.c:638 src/ftp.c:697
#: src/ftp.c:758 src/ftp.c:818 src/ftp.c:865
msgid "Write failed, closing control connection.\n"
msgstr "Schreiben schlug fehl; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:336
msgid "The server refuses login.\n"
msgstr "Der Server verweigert die Anmeldung.\n"

#: src/ftp.c:342
msgid "Login incorrect.\n"
msgstr "Fehler bei der Anmeldung.\n"

#: src/ftp.c:348
msgid "Logged in!\n"
msgstr "Angemeldet!\n"

#: src/ftp.c:370
msgid "Server error, can't determine system type.\n"
msgstr ""
"Fehler beim Server; es ist nicht möglich, die Art des Systems "
"festzustellen.\n"

#: src/ftp.c:379 src/ftp.c:674 src/ftp.c:731 src/ftp.c:774
msgid "done.    "
msgstr "fertig.    "

#: src/ftp.c:431 src/ftp.c:580 src/ftp.c:613 src/ftp.c:838 src/ftp.c:884
msgid "done.\n"
msgstr "fertig.\n"

#: src/ftp.c:458
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Unbekannte Art »%c«, schließe Kontroll-Verbindung.\n"

#: src/ftp.c:470
msgid "done.  "
msgstr "fertig.  "

#: src/ftp.c:476
msgid "==> CWD not needed.\n"
msgstr "==> CWD nicht notwendig.\n"

#: src/ftp.c:569
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Das Verzeichnis »%s« gibt es nicht.\n"
"\n"

#: src/ftp.c:584
msgid "==> CWD not required.\n"
msgstr "==> CWD nicht erforderlich.\n"

#: src/ftp.c:644
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kann PASV-Übertragung nicht beginnen.\n"

#: src/ftp.c:648
msgid "Cannot parse PASV response.\n"
msgstr "Kann PASV-Antwort nicht auswerten.\n"

#: src/ftp.c:665
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "Konnte keine Verbindung zu »%s«, Port »%d« herstellen: %s\n"

#: src/ftp.c:713
#, c-format
msgid "Bind error (%s).\n"
msgstr "Verbindungsfehler (%s).\n"

#: src/ftp.c:719
msgid "Invalid PORT.\n"
msgstr "Ungültiger PORT.\n"

# Wieder das mit der 1. Person :)
#: src/ftp.c:765
msgid ""
"\n"
"REST failed, starting from scratch.\n"
