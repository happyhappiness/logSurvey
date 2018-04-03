msgstr "Ok�nt fel"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "Misslyckades med att st�lla in ett SSL-sammanhang\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Misslyckades med att l�sa in certifikat fr�n %s\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "F�rs�ker utan det angivna certifikatet\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Misslyckades med att f� tag i certifikatnyckel fr�n %s\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "Kan inte etablera en SSL-anslutning.\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "�teranv�nder anslutning till %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Misslyckades med att skriva HTTP-beg�ran: %s.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-beg�ran skickad, v�ntar p� svar... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Filslut vid genoms�kning av huvuden.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "L�sfel (%s) i huvuden.\n"

#: src/http.c:959
msgid "No data received"
msgstr "Ingen data mottagen"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Felaktig statusrad"

#: src/http.c:966
msgid "(no description)"
msgstr "(ingen beskrivning)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Auktorisering misslyckades.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Ok�nd autentiseringsmetod.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Adress: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "ospecifierat"

#: src/http.c:1138
msgid " [following]"
msgstr " [f�ljande]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Filen �r redan fullst�ndigt h�mtad, inget att g�ra.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"�terupptagen h�mtning av denna fil misslyckades, vilket �r i konflikt\n"
"med \"-c\".\n"
"V�grar att klippa existerande filen \"%s\".\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "L�ngd: "

#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (%s kvar)"

#: src/http.c:1269
msgid "ignored"
msgstr "ignorerad"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varning: jokertecken st�ds inte i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen \"%s\" finns redan d�r, h�mtar inte.\n"

#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan inte skriva till \"%s\" (%s).\n"

#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEL: Omdirigering (%d) utan adress.\n"

#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEL %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "\"Last-modified\"-huvud saknas -- tidsst�mplar avst�ngda.\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "\"Last-modified\"-huvudet ogiltigt -- tidsst�mpel ignorerad.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "Filen p� servern �r inte nyare �n lokala filen \"%s\" -- h�mtar inte.\n\n"

#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Storlekarna st�mmer inte �verens (lokal %ld) -- h�mtar.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "Filen p� fj�rrsystemet �r nyare, h�mtar.\n"

#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld/%ld]\n\n"

#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - F�rbindelse st�ngd vid byte %ld. "

#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld/%ld])\n\n"

#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - F�rbindelsen st�ngd vid byte %ld/%ld. "

#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - L�sfel vid byte %ld (%s)."

#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - L�sfel vid byte %ld/%ld (%s). "

#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan inte l�sa %s (%s).\n"

#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fel i %s vid rad %d.\n"

#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Varning: B�de systemets och anv�ndarens wgetrc pekar till \"%s\".\n"

#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: PROGRAMFEL: kommandot \"%s\" �r ok�nt, v�rde \"%s\".\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: Kan inte konvertera \"%s\" till en IP-adress.\n"

#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Ange \"on\" eller \"off\".\n"

#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Ange \"always\", \"on\", \"off\" eller \"never\".\n"

#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Specifikationen \"%s\" �r ogiltig.\n"

#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Specifikationen \"%s\" �r ogiltig\n"

#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Anv�ndning: %s [FLAGGA]... [URL]...\n"

#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, en icke-interaktiv n�tverksh�mtare.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr "\nObligatoriska argument till l�nga flaggor �r obligatoriska �ven f�r de korta.\n\n"

#: src/main.c:137
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
