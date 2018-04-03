# Mensajes en espa�ol para GNU wget.
# Copyright (C) 2001 Free Software Foundation, Inc.
# Salvador Gimeno Zan�n <salgiza@jazzfree.com>, 2001
#
# Traducido con la ayuda de:
# Juan Jos� Rodr�guez <jcnsoft@jal1.telmex.net.mx>
#
# Revisado por:
# Carlos Linares L�pez <clinares@delicias.dia.fi.upm.es; carlosl@acm.org>
# Santiago Vila <sanvila@unex.es>
# Nicol�s Lichtmaier <nick@feedback.net.ar>
#
# Notas:
#
# 1. Los comentarios que empiezan por "Duda:" se refieren a mensajes que
#    debieran ser revisados.
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.7-pre1\n"
"POT-Creation-Date: 2001-05-26 11:07+0200\n"
"PO-Revision-Date: 2001-06-02 16:16GMT+0200\n"
"Last-Translator: Salvador Gimeno Zan�n <salgiza@jazzfree.com>\n"
"Language-Team: Spanish <es@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"
"X-Generator: KBabel 0.8\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Error al asignar cookie, en el campo `%s'"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Error de sintaxis al asignar cookie, en el car�cter `%c'.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Error de sintaxis al asignar cookie: fin de cadena inesperado.\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "No se pudo abrir el fichero de cookies `%s': %s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Error escribiendo a `%s': %s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Error cerrando `%s': %s\n"

#: src/ftp-ls.c:787
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr "Tipo de listado no soportado, se intenar� con el parseador de listados de Unix.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "�ndice de /%s en %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "hora desconocida   "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Fichero     "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Directorio  "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Enlace      "

# creo que se refiere al tipo (fichero/directorio/enlace)
#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Ni idea     "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

# Me temo que nadie se "conecta a" sino que se "conecta con", ... �no te
# suena mejor? - cll
# sip - Salva
#
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:149 src/http.c:623
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Conectando con %s:%hu... "

#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Conexi�n con %s:%hu rechazada.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:192 src/http.c:651
msgid "connected!\n"
msgstr "�Conectado!\n"

# mmmm... no estoy seguro de esto...
# �As� no es mejor? (nl)
#: src/ftp.c:193
#, c-format
msgid "Logging in as %s ... "
msgstr "Identific�ndose como %s ... "

# Me parece m�s `humanoide' a�adir el art�culo a las cosas, ... Los
# angloparlantes suelen evitarlo (�ser� porque no son humanos? :) pero
# eso no significa que nosotros nos lo ahorremos, pues eso es contrario
# a nuestra costumbre - cll
# einch! que tengo familiares g�iris ;-) , pero tienes raz�n -Salva
#
#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
msgid "Error in server response, closing control connection.\n"
msgstr "Error en la respuesta del servidor, cerrando la conexi�n de control.\n"

# `greeting' tambi�n puede traducirse como `recepci�n' que, en este
# caso, me parece m�s apropiado. -cll
# bien - Salva
# No est� bien, es confuso. Recepci�n suena a recibir... (nl)
#
#: src/ftp.c:210
msgid "Error in server greeting.\n"
msgstr "Error en el saludo del servidor.\n"

# En ingl�s suele resultar muy adecuada la utilizaci�n de participios,
# puesto que esa es una forma de adjetivaci�n muy com�n. Sin embargo, en
# espa�ol crea un efecto "computadora" muy desagradable, ...
#
# Por ejemplo, "Fallo de escritura" me parece much�simo m�s apropiado
# que "Escritura fallida"
#
# Adem�s, he a�adido el art�culo a `conexi�n' - cll
#
#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
msgid "Write failed, closing control connection.\n"
msgstr "Fallo de escritura, cerrando la conexi�n de control.\n"

# Es una regla de oro intentar evitar las expresiones en ingl�s tanto
# como sea posible. Esta ha sido una cuesti�n harto discutida en
# es@li.org y, al final, se decidi�, por consenso adoptar siempre la
# siguiente norma:
#
# "Siempre que sea posible debe sustituirse el t�rmino en ingl�s por
# otro equivalente en espa�ol. Solo si el t�rmino espa�ol no resulta
# suficientemente descriptivo puede acompa�arse entre par�ntesis del
# t�rmino en ingl�s. Por ejemplo: `pipe' se debe traducir por `tuber�a',
# pero como este t�rmino puede resultar extra�o para muchos
# programadores, se admite: `tuberia (pipe)'.
#
# A prop�sito de esta norma, `login' puede parecer un t�rmino muy
# extendido que todo el mundo conoce y entiende, �pero no es
# espa�ol!.
#
# Me he permitido sustituirte `login' por `acceso', o una expresi�n
# equivalente, en todos los mensajes del fichero. Espero que te parezca
# oportuno - cll
#
#: src/ftp.c:225
msgid "The server refuses login.\n"
msgstr "El servidor ha rechazado el acceso.\n"

# Duda: en este caso, sospecho que el `login' se refiere al nombre de
# usuario, �verdad? - cll
# s� -Salva
#
#: src/ftp.c:232
msgid "Login incorrect.\n"
msgstr "Nombre de usuario incorrecto.\n"

# �Una excelente traducci�n! :) - cll
# gracias! :) -Salva
#
# Preferir�a algo como "Conectado" o algo as�. sv
#: src/ftp.c:239
msgid "Logged in!\n"
msgstr "�Dentro!\n"

#: src/ftp.c:264
msgid "Server error, can't determine system type.\n"
msgstr "Error del servidor, no se pudo determinar el tipo de sistema.\n"

#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
msgid "done.    "
msgstr "hecho.   "

#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
msgid "done.\n"
msgstr "hecho.\n"

# He a�adido el art�culo a `conexi�n' - cll
#
#: src/ftp.c:352
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo desconocido `%c', cerrando la conexi�n de control.\n"

#: src/ftp.c:365
msgid "done.  "
msgstr "hecho.  "

#: src/ftp.c:371
msgid "==> CWD not needed.\n"
msgstr "==> no se necesita CWD.\n"

#: src/ftp.c:444
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "No existe el directorio `%s'.\n\n"

#. do not CWD
#: src/ftp.c:462
msgid "==> CWD not required.\n"
msgstr "==> no se requiere CWD.\n"

#: src/ftp.c:496
msgid "Cannot initiate PASV transfer.\n"
msgstr "No se pudo iniciar la trasferencia PASV.\n"

#: src/ftp.c:500
msgid "Cannot parse PASV response.\n"
msgstr "No se pudo analizar la respuesta PASV.\n"

#: src/ftp.c:514
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Se intentar� conectar con %s:%hu.\n"

# Duda: no estoy muy seguro, pero ... �y `error de enlace' o algo
# parecido? Probablemente, este sea uno de los casos en los que debas
# incluir entre par�ntesis la palabra `bind'.
#
# Mientras tanto, te sugiero `error de enlace (bind)' - cll
# la verdad es que no tengo ni idea de qu� es esto :( - Salva
#
# Es la funci�n bind(2), que asigna una direcci�n a un socket.
# Me parece que decir lo de la funci�n es mejor. (nl)
#
#: src/ftp.c:601
#, c-format
msgid "Bind error (%s).\n"
msgstr "Error en la llamada `bind' (%s).\n"

# Ya no est� "prohibido" usar esta palabra. sv
#: src/ftp.c:617
msgid "Invalid PORT.\n"
msgstr "PUERTO inv�lido.\n"

#: src/ftp.c:670
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nEl comando REST no funcion�, no se truncar� `%s'.\n"

#: src/ftp.c:677
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nEl comando REST no funcion�, se empezar� desde el principio\n"

#: src/ftp.c:726
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "No existe el fichero `%s'.\n\n"

#: src/ftp.c:774
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "No existe el fichero o directorio `%s'.\n\n"

#: src/ftp.c:858 src/ftp.c:866
#, c-format
msgid "Length: %s"
msgstr "Longitud: %s"

#: src/ftp.c:860 src/ftp.c:868
#, c-format
msgid " [%s to go]"
msgstr " [%s para acabar]"

# nota jjrs: Se agrega este mensaje cuando el wget no ha obtenido
#   directamente el tama�o del archivo a transferir y esta usando la
#   longitud que reporta el inicio de la transferencia.
#
# �Dabuti! Si no lo llegas a decir, ... �Lo estaba flipando! :) Pero
# vamos, siendo como dices, a m� me suena perfect�simamente - cll
#
#: src/ftp.c:870
msgid " (unauthoritative)\n"
msgstr " (probablemente)\n"

# He a�adido el art�culo a `conexi�n' - cll
#
#: src/ftp.c:897
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, cerrando la conexi�n de control.\n"

#: src/ftp.c:905
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexi�n de datos: %s; "

#: src/ftp.c:922
msgid "Control connection closed.\n"
msgstr "Conexi�n de control cerrada.\n"

#: src/ftp.c:940
msgid "Data transfer aborted.\n"
msgstr "Trasferencia de datos abortada.\n"

# `no recuperando' no me suena muy espa�ol, te propongo la alternativa
# m�s "humanizada", `no se recupera' - cll
#
#: src/ftp.c:1004
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "El fichero `%s' ya est� ah�, no se recupera.\n"

# nota jjrs: no ser�a mejor intento?
# pues s� - Salva
# decididamente si - cll
#: src/ftp.c:1074 src/http.c:1501
#, c-format
msgid "(try:%2d)"
msgstr "(intento:%2d)"

#: src/ftp.c:1138 src/http.c:1752
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' guardado [%ld]\n\n"

#: src/ftp.c:1180 src/main.c:809 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Eliminando %s.\n"

#: src/ftp.c:1220
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Usando `%s' como fichero temporal de listado.\n"

# Aqu� volvemos un poco a lo de siempre: en ingl�s, los participios se
# emplean con frecuencia para adjetivar un sustantivo, sin embargo, en
# espa�ol sirven para hacer referencia a una acci�n. Esto es, deben ir
# despu�s del sustantivo - cll
#
#: src/ftp.c:1232
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' eliminado.\n"

#: src/ftp.c:1268
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "La profundidad de recursi�n %d excede la m�xima de %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1329
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "El fichero remoto no es m�s moderno que el fichero local `%s' -- no se descargar�.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1336
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "El fichero remoto es m�s moderno que el fichero local `%s' -- descargando.\n\n"

#. Sizes do not match
#: src/ftp.c:1343
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Los tama�os no concuerdan (%ld local) -- recuperando.\n\n"

# Simplemente me suena mejor `omitir' que `saltar'. Adem�s, las acciones
# expresadas en gerundio, ..., prefiero una forma impersonal como `se
# omite' - cll
#
#: src/ftp.c:1360
msgid "Invalid name of the symlink, skipping.\n"
msgstr "El nombre del enlace simb�lico no es v�lido, se omite.\n"

#: src/ftp.c:1377
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Ya se tiene el enlace simb�lico correcto %s -> %s\n\n"

#: src/ftp.c:1385
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creando enlace simb�lico %s -> %s\n"

# Lo dicho de los gerundios por formas impersonales - cll
#
#: src/ftp.c:1396
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "No se admiten enlaces simb�licos, se omite el enlace simb�lico `%s'.\n"

#: src/ftp.c:1408
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Omitiendo el directorio `%s'.\n"

#: src/ftp.c:1417
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo de fichero desconocido/no soportado.\n"

# sigo las indicaciones del texto "pifias" para time-stamp.
#: src/ftp.c:1444
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: marca de tiempo corrupta.\n"

#: src/ftp.c:1465
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "No se recuperar�n directorios puesto que la profundidad es %d (m�x %d).\n"

# Los gerundios me parecen poco apropiados para construir predicados
# normales y corrientes como intentas en este mensaje. En su lugar, te
# propongo la forma alternativa `se desciende' - cll
#
#: src/ftp.c:1511
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "No se desciende hasta `%s' por estar excluido/no incluido.\n"

#: src/ftp.c:1558
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rechazando `%s'.\n"

# alguna idea mejor?
# nota jjrs: En el PO para el grep 2.1 pattern est� traducido como
#   patr�n por <melero@iprolink.ch> y <sanvila@unex.es>
#
# De hecho, `pattern' debiera traducirse como `patr�n' y casi siempre os
# saldr�n las traducciones perfectas con este t�rmino. A m�, de hecho el
# mensaje que habeis puesto me parece una traducci�n excelente - cll
#
# Algo no es *parecido* a un patr�n. Algo *cumple* con un patr�n. (nl)
# Bien, pero aceptar� la matizaci�n cd C.S. Suarez de 'se ajusta a...' -Salva
#
#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1605
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "No hay nada que se ajuste al patr�n `%s'.\n"

#: src/ftp.c:1670
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Se escribi� un �ndice en HTML a `%s' [%ld].\n"

#: src/ftp.c:1675
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Se escribi� un �ndice en HTML a `%s'.\n"

#: src/getopt.c:454
#, c-format
