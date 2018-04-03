#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1819
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr ".`%s' תינבתל תומאתה ןיא\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "`%s'-ל הבתכנ םיתב %ld לדוגבו HTML טמרופב םיצבק תמישר\n"

#: src/ftp.c:1890
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "`%s'-ל הבתכנ HTML טמרופב םיצבק תמישר\n"

#. Still not enough randomness, most likely because neither
#. /dev/random nor EGD were available.  Resort to a simple and
#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
#. cryptographically weak, but people who care about strong
#. cryptography should install /dev/random (default on Linux) or
#. specify their own source of randomness anyway.
#: src/gen_sslfunc.c:109
msgid "Warning: using a weak random seed.\n"
msgstr ""

#: src/gen_sslfunc.c:166
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr ""

#: src/gen_sslfunc.c:223
msgid "Warning: validation of server certificate not possible!\n"
msgstr ""

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s תינכת רובע יעמשמ-דח וניא `%s' ןייפאמ\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s תינכת רובע טנמוגרא לבקמ וניא `--%s' ןייפאמ\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s תינכת רובע טנמוגרא לבקמ וניא `%c%s' ןייפאמ\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s תינכת רובע טנמוגרא בייחמ `%s' ןייפאמ\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s תינכת י\"ע רכומ וניא `--%s' ןייפאמ\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s תינכת י\"ע רכומ וניא `%c%s' ןייפאמ\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: יקוח-יתלב ןייפאמ -- %c\n"

#: src/getopt.c:785
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: יקוח-יתלב ןייפאמ -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: טנמוגרא בייחמ ןייפאמ -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s תינכת רובע יעמשמ-דח וניא `%s' ןייפאמ\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s תינכת רובע טנמוגרא לבקמ וניא `--%s' ןייפאמ\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "ההוזמ-יתלב הלקת"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "ההוזמ-יתלב הלקת"

#: src/host.c:748
#, fuzzy, c-format
msgid "Resolving %s... "
msgstr ".%s קחומ\n"

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr ""

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
msgid "failed: timed out.\n"
msgstr ""

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr ""

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr ".HTTP תיינפ לש החילשב (%s) הלקת\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "(SSL) חטבואמ רודיש תביבס תריציב הלקת\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "%s-מ (certificates) רושיא תויות תניעטב הלקת\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "תשרדנ רושיא תיות אלל ךישמהל ןויסנ\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "%s-מ רושיא חתפמ תלבקב הלקת\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr ".%s:%hu-ל רוביחב שמתשהל ךישממ\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr ".HTTP תיינפ לש החילשב (%s) הלקת\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ".HTTP תיינפ לש החילשב (%s) הלקת\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

# FIXME: This message can be followed by "%d %s", which prints
# the operation status code and error message.  I don't see how
# can I make this look right in Hebrew...
#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "...הבושת תלבקל ןיתממ ,החלשנ %s תיינפ "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "טלק ינותנ ולבקתה אל"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr ".תורתוכ תאירק תעב (%s) תלקת\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr ".תומיאה בלשב ןולשכ\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr ".תרכומ-יתלב תומיא תטיש\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "בצמה תרוש לש יוגש הנבמ"

#: src/http.c:1636
msgid "(no description)"
msgstr "(העודי-יתלב הביס)"

# Pay attention: the translation of "unspecified" goes to the
# left of this, the translation of "[following]" goes to the right.
#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "%s :רתאל בותינ יוניש%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "unspecified"

#: src/http.c:1702
msgid " [following]"
msgstr " רחא בקוע"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"  .יהשלכ הלועפב ךרצ ןיא ;ךשמנ זאמ הנתשה אל ץבוקה לש ולדוג\n"
"\n"

# The next 3 messages are printed in order on the same line, and
