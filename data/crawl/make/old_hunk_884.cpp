# volcado de `core' no significa nada, que te parece si mejor dejamos
# el core dumped, o bien volcado del n�cleo o algo as�. Por el momento
# no cambio nada. mm
#: job.c:199
msgid " (core dumped)"
msgstr " (core dumped) [N�cleo vaciado a un archivo]"

# Recibida o capturada, pero por Dios , no pongas
# 'se tiene' . En vez de hijo pon proceso hijo , y quita lo
# que tienes entre par�ntesis em+
# Lo del par�ntesis era para escoger. mm
#: job.c:234
#, c-format
msgid "Got a SIGCHLD; %d unreaped children.\n"
msgstr "Recib� una se�al SIGCHLD; %d proceso hijo descarriado.\n"

# �Y job -> trabajos? sv
# Si, pero no hablas de una computadora multi-trabajos sino multi-tareas.
# Por eso eleg� tareas. Lo platicamos con m�s calma? mm
#: job.c:265
msgid "*** Waiting for unfinished jobs...."
msgstr "*** Se espera a que terminen otras tareas...."

# �De verdad se dice "vivo"? Si es un proceso, se me ocurre "activo". sv
# Me gusta lo de activo. mm
#: job.c:290
#, c-format
msgid "Live child 0x%08lx PID %d%s\n"
msgstr "Hijo activo 0x%08lx PID %d%s\n"

#: job.c:292 job.c:427 job.c:514 job.c:919
msgid " (remote)"
msgstr " (remoto)"

# Protestar al autor. No hay forma de poner trabajo(s) desconocido(s)
# con coherencia. sv
# Si, si no tienen identificado a su padre. Ni modo. mm
# Pongo /s em+
# Ok. mm
#: job.c:414
#, c-format
msgid "Unknown%s job %d"
msgstr "Trabajo%s desconocido/s %d"

#: job.c:414
msgid " remote"
msgstr " remoto"

#: job.c:419
#, c-format
msgid "%s finished."
msgstr "%s terminado."

# Lo mismo, pon Proceso hijo, y quita lo que hay
# entre par�ntesis em+
#: job.c:424
#, c-format
msgid "Reaping %s child 0x%08lx PID %d%s\n"
msgstr "Proceso hijo %s descarriado 0x%08lx PID %d%s\n"

#: job.c:425
msgid "losing"
msgstr "se pierde"

#: job.c:425
msgid "winning"
msgstr "se gana"

# Proceso hijo em+
# Ok.
#: job.c:512
#, c-format
msgid "Removing child 0x%08lx PID %d%s from chain.\n"
msgstr "Se elimina al proceso hijo 0x%08lx PID %d%s de la cadena.\n"

# Proceso hijo em+
# Ok.
#: job.c:917
#, c-format
msgid "Putting child 0x%08lx PID %05d%s on the chain.\n"
msgstr "Se pone al proceso hijo 0x%08lx PID %05d%s en la cadena.\n"

#: job.c:1140
msgid "cannot enforce load limits on this operating system"
msgstr "no se pueden forzar los l�mites de carga en este sistema operativo"

#: job.c:1142
msgid "cannot enforce load limit: "
msgstr "no se puede forzar la carga l�mite: "

#: job.c:1244
#, c-format
msgid "internal error: `%s' command_state %d in child_handler"
msgstr "error interno: `%s' command_state %d en el child_handler"

# "en sustituto" me suena muy raro. Propongo: "en su lugar" en su lugar :-) sv
# Ok. mm
#: job.c:1350
#, c-format
msgid "Executing %s instead\n"
msgstr "En su lugar, se ejecuta %s\n"

#: job.c:1381
#, c-format
msgid "Error spawning, %d\n"
msgstr "Error al lanzar el proceso %d\n"

#: job.c:1442
#, c-format
msgid "%s: Command not found"
msgstr "%s: No se encontr� el programa"
