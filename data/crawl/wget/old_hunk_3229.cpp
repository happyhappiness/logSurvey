#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1608
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "No hi ha res que s'ajusti al patr� `%s'.\n"

#: src/ftp.c:1673
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "S'ha escrit un �ndex amb HTML a `%s' [%ld].\n"

#: src/ftp.c:1678
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "S'ha escrit un �ndex HTML a `%s'.\n"

#: src/gen_sslfunc.c:109
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "No es s'ha pogut alimentar el PRNG d'OpenSSL; deshabilitant SSL.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: la opci� `%s' �s ambigua\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: la opci� `--%s' no permet un argument\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: la opci� `%c%s' no permet un argument\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: la opci� `%s' requereix un argument\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opci� desconeguda `--%s'\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opci� desconeguda `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opci� no permesa -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: aquesta opci� requereix un argument -- %c\n"

#: src/host.c:268
#, c-format
msgid "Resolving %s... "
msgstr "Resolent %s... "

#: src/host.c:275
#, c-format
msgid "failed: %s.\n"
msgstr "Fallat: %s.\n"

#: src/host.c:345
msgid "Host not found"
msgstr "Oste no trobat"

#: src/host.c:347
msgid "Unknown error"
msgstr "Error desconegut"

#. this is fatal
#: src/http.c:573
msgid "Failed to set up an SSL context\n"
msgstr "S'ha fallat al intentar fixar un context SSL\n"

#: src/http.c:579
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "S'ha fallat al intentar carregar els certificats des de %s\n"

#: src/http.c:583 src/http.c:591
msgid "Trying without the specified certificate\n"
msgstr "Probant sense el certificat especificat\n"

#: src/http.c:587
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "S'ha fallat al intentar conseguir la clau del certificat des de %s\n"

#: src/http.c:657 src/http.c:1620
msgid "Unable to establish SSL connection.\n"
msgstr "No es pot establir una conexi� SSL.\n"

#: src/http.c:666
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "S'est� reutilitzant la conexi� a %s:%hu.\n"

#: src/http.c:868
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Ha fallat al escriure la petici� HTTP: %s.\n"

#: src/http.c:873
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s: Petici� enviada, esperant resposta... "

#: src/http.c:917
msgid "End of file while parsing headers.\n"
msgstr "Fi del arxiu al parsejar les cap�aleres.\n"

#: src/http.c:927
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) a les cap�aleres.\n"

#: src/http.c:962
msgid "No data received"
msgstr "No s'han rebut dades"

#: src/http.c:964
msgid "Malformed status line"
msgstr "l�nia de estat mal formada"

#: src/http.c:969
msgid "(no description)"
msgstr "(sense descripci�)"

#: src/http.c:1101
msgid "Authorization failed.\n"
msgstr "Autoritzaci� fallida.\n"

#: src/http.c:1108
msgid "Unknown authentication scheme.\n"
msgstr "M�tode de autentificaci� desconeguda.\n"

#: src/http.c:1148
#, c-format
msgid "Location: %s%s\n"
msgstr "Localitzaci�: %s%s\n"

#: src/http.c:1149 src/http.c:1282
msgid "unspecified"
msgstr "no especificat"

#: src/http.c:1150
msgid " [following]"
msgstr " [el seg�ent]"

#: src/http.c:1213
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    L'arxiu seg�ent est� descarregat totalment; res a fer.\n\n"

#: src/http.c:1229
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
