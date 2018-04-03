msgid "Unknown error"
msgstr "Okänt fel"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Försöker ansluta till %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Misslyckades med att skriva HTTP-begäran.\n"

#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s begäran skickad, väntar på svar... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Filslut vid genomsökning av huvuden.\n"

#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Läsfel (%s) i huvuden.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Ingen data mottagen"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Missbildad statusrad"

#: src/http.c:912
msgid "(no description)"
msgstr "(ingen beskrivning)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Auktorisering misslyckades.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Okänd auktoriseringsmetod.\n"

#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Adress: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "ospecificerat"

#: src/http.c:1129
msgid " [following]"
msgstr " [följande]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Längd: "

#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (%s kvar)"

#: src/http.c:1153
msgid "ignored"
msgstr "ignorerad"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varning: jokertecken understöds inte i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen \"%s\" finns redan där, hämtar inte.\n"

#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan inte skriva till \"%s\" (%s).\n"

#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEL: Omdirigering (%d) utan adress.\n"

#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEL %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "\"Last-modified\"-huvud saknas -- tidsstämplar avstängda.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "\"Last-modified\"-huvudet ogiltigt -- tidsstämpel ignorerad.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Filen på fjärrsystemet är nyare, hämtar.\n"

#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
