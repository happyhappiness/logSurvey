# Es la función bind(2), que asigna una dirección a un socket.
# Me parece que decir lo de la función es mejor. (nl)
#
#: src/ftp.c:708
#, c-format
msgid "Bind error (%s).\n"
msgstr "Error en la llamada `bind' (%s).\n"

# Ya no está "prohibido" usar esta palabra. sv
#: src/ftp.c:714
msgid "Invalid PORT.\n"
msgstr "PUERTO inválido.\n"

#: src/ftp.c:760
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"El comando REST no funcionó, se empezará desde el principio\n"

#: src/ftp.c:821
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"No existe el fichero `%s'.\n"
"\n"

#: src/ftp.c:868
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
#: src/ftp.c:930 src/http.c:2236
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

# He añadido el artículo a `conexión' - cll
#
#: src/ftp.c:982
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, cerrando la conexión de control.\n"

#: src/ftp.c:991
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexión de datos: %s; "

#: src/ftp.c:1006
msgid "Control connection closed.\n"
msgstr "Conexión de control cerrada.\n"

#: src/ftp.c:1024
msgid "Data transfer aborted.\n"
msgstr "Trasferencia de datos abortada.\n"

# `no recuperando' no me suena muy español, te propongo la alternativa
# más "humanizada", `no se recupera' - cll
#
#: src/ftp.c:1092
#, fuzzy, c-format
msgid "File `%s' already there; not retrieving.\n"
msgstr "El fichero `%s' ya está ahí, no se recupera.\n"

# nota jjrs: no sería mejor intento?
# pues sí - Salva
# decididamente si - cll
#: src/ftp.c:1160 src/http.c:2375
#, c-format
msgid "(try:%2d)"
msgstr "(intento:%2d)"

#: src/ftp.c:1230 src/http.c:2683
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' guardado [%ld]\n"
"\n"

#: src/ftp.c:1272 src/main.c:990 src/recur.c:376 src/retr.c:859
#, c-format
msgid "Removing %s.\n"
msgstr "Eliminando %s.\n"

#: src/ftp.c:1314
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Usando `%s' como fichero temporal de listado.\n"
