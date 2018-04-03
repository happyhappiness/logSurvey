 # FIXME: This message can be followed by "%d %s", which prints
 # the operation status code and error message.  I don't see how
 # can I make this look right in Hebrew...
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "...הבושת תלבקל ןיתממ ,החלשנ %s תיינפ "
 
-#: src/http.c:1777
+#: src/http.c:1806
 #, fuzzy
 msgid "No data received.\n"
 msgstr "טלק ינותנ ולבקתה אל"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr ".תורתוכ תאירק תעב (%s) תלקת\n"
 
-#: src/http.c:1831 src/http.c:2385
-#, fuzzy, c-format
-msgid ""
-"File %s already there; not retrieving.\n"
-"\n"
-msgstr ".ותוא ךושמל ךרוצ ןיא ,ןאכ רבכ `%s' ץבוק\n"
-
-#: src/http.c:1985
+#: src/http.c:1884
 msgid "Unknown authentication scheme.\n"
 msgstr ".תרכומ-יתלב תומיא תטיש\n"
 
-#: src/http.c:2016
+#: src/http.c:1918
 msgid "Authorization failed.\n"
 msgstr ".תומיאה בלשב ןולשכ\n"
 
-#: src/http.c:2030
+#: src/http.c:1956 src/http.c:2466
+#, fuzzy, c-format
+msgid ""
+"File %s already there; not retrieving.\n"
+"\n"
+msgstr ".ותוא ךושמל ךרוצ ןיא ,ןאכ רבכ `%s' ץבוק\n"
+
+#: src/http.c:2070
 msgid "Malformed status line"
 msgstr "בצמה תרוש לש יוגש הנבמ"
 
-#: src/http.c:2032
+#: src/http.c:2072
 msgid "(no description)"
 msgstr "(העודי-יתלב הביס)"
 
 # Pay attention: the translation of "unspecified" goes to the
 # left of this, the translation of "[following]" goes to the right.
-#: src/http.c:2098
+#: src/http.c:2149
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "%s :רתאל בותינ יוניש%s\n"
 
-#: src/http.c:2099 src/http.c:2209
+#: src/http.c:2150 src/http.c:2258
 msgid "unspecified"
 msgstr "unspecified"
 
-#: src/http.c:2100
+#: src/http.c:2151
 msgid " [following]"
 msgstr " רחא בקוע"
 
-#: src/http.c:2156
+#: src/http.c:2203
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
