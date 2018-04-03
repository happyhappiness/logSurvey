# Es la función bind(2), que asigna una dirección a un socket.
# Me parece que decir lo de la función es mejor. (nl)
#
#: src/ftp.c:752
#, c-format
msgid "Bind error (%s).\n"
msgstr "Error en la llamada `bind' (%s).\n"

# Ya no está "prohibido" usar esta palabra. sv
#: src/ftp.c:759
msgid "Invalid PORT.\n"
msgstr "PUERTO inválido.\n"

#: src/ftp.c:810
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"El comando REST no funcionó, se empezará desde el principio\n"

#: src/ftp.c:875
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"No existe el fichero `%s'.\n"
"\n"

#: src/ftp.c:927
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"No existe el fichero o directorio `%s'.\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:992 src/http.c:1847
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

# He añadido el artículo a `conexión' - cll
#
#: src/ftp.c:1054
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, cerrando la conexión de control.\n"

#: src/ftp.c:1062
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexión de datos: %s; "

#: src/ftp.c:1077
msgid "Control connection closed.\n"
msgstr "Conexión de control cerrada.\n"

#: src/ftp.c:1095
msgid "Data transfer aborted.\n"
msgstr "Trasferencia de datos abortada.\n"

# `no recuperando' no me suena muy español, te propongo la alternativa
# más "humanizada", `no se recupera' - cll
#
#: src/ftp.c:1160
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "El fichero `%s' ya está ahí, no se recupera.\n"
