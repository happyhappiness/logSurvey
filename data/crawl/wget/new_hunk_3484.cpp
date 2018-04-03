"gestoppt werden.\n"

#. parent, no error
#: src/mswindows.c:123 src/utils.c:462
msgid "Continuing in background.\n"
msgstr "Im Hintergrund geht's weiter.\n"

#: src/mswindows.c:125 src/utils.c:464
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "Ausgabe wird nach »%s« geschrieben.\n"

#: src/mswindows.c:205
#, c-format
msgid "Starting WinHelp %s\n"
msgstr "WinHelp %s wird gestartet\n"

#: src/mswindows.c:232 src/mswindows.c:239
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Kein benutzbar \"socket driver\" auffindbar.\n"

#: src/netrc.c:365
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: Warnung: »%s«-Wortteil erscheint vor einem Maschinennamen\n"

#: src/netrc.c:396
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: unbekannter Wortteil »%s«\n"

#: src/netrc.c:460
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Syntax: %s NETRC [HOSTNAME]\n"

# stat
#: src/netrc.c:470
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: kann nicht finden %s: %s\n"

#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:203
#, c-format
msgid "\n%*s[ skipping %dK ]"
msgstr "\n%*s[ überspringe %dK ]"

#: src/progress.c:370
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr "Ungültiger Stil für den Fortschrittsindikator »%s«; keine Änderung.\n"

#: src/recur.c:337
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Entferne »%s«, da dies zurückgewiesen werden soll.\n"

#: src/recur.c:747
#, c-format
msgid "Converted %d files in %.2f seconds.\n"
msgstr "%d Dateien in %.2f Sekunden konvertiert.\n"

#: src/res.c:541
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Lade »robots.txt«; bitte Fehler ignorieren.\n"

#: src/retr.c:363
msgid "Could not find proxy host.\n"
msgstr "Proxy-Host nicht auffindbar.\n"

#: src/retr.c:375
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "Fehler beim Parsen der Proxy-URL »%s«: %s.\n"

#: src/retr.c:384
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "Fehler in der Proxy-URL »%s«: Es muss eine HTTP-URL sein.\n"

#: src/retr.c:476
#, c-format
msgid "%d redirections exceeded.\n"
msgstr "%d: Die Anzahl der Verweise ist zu groß.\n"

#: src/retr.c:491
#, c-format
msgid "%s: Redirection cycle detected.\n"
msgstr "%s: Zyklischer Verweis festgestellt.\n"

#: src/retr.c:608
msgid "Giving up.\n\n"
msgstr "Aufgegeben.\n\n"

#: src/retr.c:608
msgid "Retrying.\n\n"
msgstr "Erneuter Versuch.\n\n"

#: src/url.c:1725
#, c-format
msgid "Converting %s... "
msgstr "Umwandlung von »%s«... "

#: src/url.c:1738
msgid "nothing to do.\n"
msgstr "kein Download notwendig.\n"

#: src/url.c:1746 src/url.c:1770
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Verweise nicht umwandelbar in »%s«: %s\n"

#: src/url.c:1761
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Es ist nicht möglich, »%s« zu löschen: %s\n"

#: src/url.c:1967
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Anlegen eines Backups von »%s« als »%s« nicht möglich: %s\n"

#: src/utils.c:97
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: Nicht genügend Speicher.\n"

#: src/utils.c:634
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "Entfernen des symbolischen Verweises »%s« fehlgeschlagen: %s\n"
