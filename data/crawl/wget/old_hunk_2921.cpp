msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: l'opció `-W %s' no admet arguments\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "S'està resolguent %s... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "error: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "error: temps esgotat.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "No s'ha trobat el host"

#: src/host.c:764
msgid "Unknown error"
msgstr "Error no identificat"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: No s'ha pogut resoldre l'enllaç incomplet %s.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "No s'ha pogut establir un context SSL\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "No s'han pogut carregar els certificats de %s\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "S'intenta sense el certificat especificat\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "No s'ha pogut obtenir la clau del certificat de %s\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "No s'ha pogut establir la connexió SSL.\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "S'està reutilitzant la connexió amb %s:%hu.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Error escrivint la petició HTTP: %s.\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s: petició enviada, esperant resposta... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Final de fitxer mentre s'analitzaven les capçaleres.\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "S'ha produït un error de lectura (%s) a les capçaleres.\n"

#: src/http.c:1128
msgid "No data received"
msgstr "No s'ha rebut cap dada"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Línia d'estat mal formada"

#: src/http.c:1135
msgid "(no description)"
msgstr "(sense descripció)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Autorització fallida.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Mètode d'autentificació desconegut.\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Ubicació: %s%s\n"

# és femení: ubicació/mida. eac
#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "no especificada"

#: src/http.c:1316
msgid " [following]"
msgstr " [es segueix]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
