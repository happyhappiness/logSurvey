#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:799
msgid "Length: "
msgstr "Länge: "

#: src/http.c:804
#, c-format
msgid " (%s to go)"
msgstr " (noch %s)"

#: src/http.c:809
msgid "ignored"
msgstr "übergangen"

#: src/http.c:903
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Warnung: Joker-Zeichen werden bei HTTP nicht unterstützt.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:924
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Datei »%s« schon vorhanden, kein Hol-Versuch.\n"

#: src/http.c:1083
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kann nicht nach »%s« schreiben (%s).\n"

# Was meint hier location?
#: src/http.c:1094
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEHLER: Redirektion (%d) ohne Ziel(?).\n"

#: src/http.c:1119
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEHLER %d: %s.\n"

#: src/http.c:1132
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "»Last-modified«-Kopfzeile fehlt -- Zeitstempel abgeschaltet.\n"

#: src/http.c:1140
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "»Last-modified«-Kopfzeile ungültig -- Zeitstempeln übergangen.\n"

#: src/http.c:1175
msgid "Remote file is newer, retrieving.\n"
msgstr "Entfernte Datei ist neuer, Hol-Versuch.\n"

#: src/http.c:1210
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
