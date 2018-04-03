#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1606
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr ".`%s' תינבתל תומאתה ןיא\n"

#: src/ftp.c:1671
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "`%s'-ל הבתכנ םיתב %ld לדוגבו HTML טמרופב םיצבק תמישר\n"

#: src/ftp.c:1676
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "`%s'-ל הבתכנ HTML טמרופב םיצבק תמישר\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s תינכת רובע יעמשמ-דח וניא `%s' ןייפאמ\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s תינכת רובע טנמוגרא לבקמ וניא `--%s' ןייפאמ\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s תינכת רובע טנמוגרא לבקמ וניא `%c%s' ןייפאמ\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s תינכת רובע טנמוגרא בייחמ `%s' ןייפאמ\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s תינכת י\"ע רכומ וניא `--%s' ןייפאמ\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s תינכת י\"ע רכומ וניא `%c%s' ןייפאמ\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: יקוח-יתלב ןייפאמ -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: טנמוגרא בייחמ ןייפאמ -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "אצמנ אל חראמ בשחמ"

#: src/host.c:376
msgid "Unknown error"
msgstr "ההוזמ-יתלב הלקת"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "(SSL) חטבואמ רודיש תביבס תריציב הלקת\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "%s-מ (certificates) רושיא תויות תניעטב הלקת\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "תשרדנ רושיא תיות אלל ךישמהל ןויסנ\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "%s-מ רושיא חתפמ תלבקב הלקת\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr ".(SSL) חטבואמ רשק ץורע םיקהל ןתינ אל\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr ".%s:%hu-ל רוביחב שמתשהל ךישממ\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr ".HTTP תיינפ לש החילשב (%s) הלקת\n"

# FIXME: This message can be followed by "%d %s", which prints
# the operation status code and error message.  I don't see how
# can I make this look right in Hebrew...
#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "...הבושת תלבקל ןיתממ ,החלשנ %s תיינפ "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr ".תורתוכה חותינ ידכ ךות טלק רמג\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr ".תורתוכ תאירק תעב (%s) תלקת\n"

#: src/http.c:959
msgid "No data received"
msgstr "טלק ינותנ ולבקתה אל"

#: src/http.c:961
msgid "Malformed status line"
msgstr "בצמה תרוש לש יוגש הנבמ"

#: src/http.c:966
msgid "(no description)"
msgstr "(העודי-יתלב הביס)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr ".תומיאה בלשב ןולשכ\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr ".תרכומ-יתלב תומיא תטיש\n"

# Pay attention: the translation of "unspecified" goes to the
# left of this, the translation of "[following]" goes to the right.
#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "%s :רתאל בותינ יוניש%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "unspecified"

#: src/http.c:1138
msgid " [following]"
msgstr " רחא בקוע"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n  .יהשלכ הלועפב ךרצ ןיא ;ךשמנ זאמ הנתשה אל ץבוקה לש ולדוג\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
",ףקותב `-c' ןייפאמו תויה .הלשכנ הז ץבוק לש ךשמה-תכישמ\n"
".`%s' םייק ץבוק בתכשל יתורשפאב ןיא\n"
"\n"

# The next 3 messages are printed in order on the same line, and
