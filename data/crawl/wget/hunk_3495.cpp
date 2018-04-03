 
 #: src/ftp-ls.c:866
 msgid "Link        "
-msgstr "Bağ         "
+msgstr "BaÄŸ         "
 
 #: src/ftp-ls.c:869
 msgid "Not sure    "
-msgstr "Kesin değil "
+msgstr "Kesin deÄŸil "
 
 #: src/ftp-ls.c:887
 #, c-format
 msgid " (%s bytes)"
-msgstr "  (%s bayt)"
-
-#. Login to the server:
-#. First: Establish the control connection.
-#: src/ftp.c:150 src/http.c:624
-#, c-format
-msgid "Connecting to %s:%hu... "
-msgstr "%s e bağlanılıyor:%hu..."
-
-#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
-#, c-format
-msgid "Connection to %s:%hu refused.\n"
-msgstr "%s e bağlanılıyor:%hu reddedildi.\n"
+msgstr " (%s bayt)"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:193 src/http.c:652
-msgid "connected!\n"
-msgstr "bağlantı kuruldu!\n"
-
-#: src/ftp.c:194
+#: src/ftp.c:187
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "%s olarak oturuma giriliyor ... "
 
-#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
-#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
+#: src/ftp.c:196 src/ftp.c:249 src/ftp.c:281 src/ftp.c:330 src/ftp.c:423
+#: src/ftp.c:474 src/ftp.c:504 src/ftp.c:568 src/ftp.c:641 src/ftp.c:702
+#: src/ftp.c:750
 msgid "Error in server response, closing control connection.\n"
-msgstr "Sunucu cevabında hata, kontrol bağlantısı kapatılıyor.\n"
+msgstr "Sunucu cevabÄ±nda hata, kontrol baÄŸlantÄ±sÄ± kapatÄ±lÄ±yor.\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:204
 msgid "Error in server greeting.\n"
-msgstr "Sunucu karşılama iletisinde hata.\n"
+msgstr "Sunucu karÅŸÄ±lama iletisinde hata.\n"
 
-#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
-#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
+#: src/ftp.c:212 src/ftp.c:339 src/ftp.c:432 src/ftp.c:513 src/ftp.c:578
+#: src/ftp.c:651 src/ftp.c:712 src/ftp.c:760
 msgid "Write failed, closing control connection.\n"
-msgstr "Yazma başarısız, kontrol bağlantısı kapatılıyor.\n"
+msgstr "Yazma baÅŸarÄ±sÄ±z, kontrol baÄŸlantÄ±sÄ± kapatÄ±lÄ±yor.\n"
 
-#: src/ftp.c:226
+#: src/ftp.c:219
 msgid "The server refuses login.\n"
-msgstr "Sunucu oturum açmayı reddetti.\n"
+msgstr "Sunucu oturum aÃ§mayÄ± reddetti.\n"
 
-#: src/ftp.c:233
+#: src/ftp.c:226
 msgid "Login incorrect.\n"
-msgstr "Oturum açma başarısız.\n"
+msgstr "Oturum aÃ§ma baÅŸarÄ±sÄ±z.\n"
 
-#: src/ftp.c:240
+#: src/ftp.c:233
 msgid "Logged in!\n"
-msgstr "Oturum açıldı!\n"
+msgstr "Oturum aÃ§Ä±ldÄ±!\n"
 
-#: src/ftp.c:265
+#: src/ftp.c:258
 msgid "Server error, can't determine system type.\n"
-msgstr "Sunucu hatası, sistem türü saptanamadı.\n"
+msgstr "Sunucu hatasÄ±, sistem tÃ¼rÃ¼ saptanamadÄ±.\n"
 
-#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
+#: src/ftp.c:268 src/ftp.c:553 src/ftp.c:625 src/ftp.c:682
 msgid "done.    "
 msgstr "tamam.   "
 
-#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
+#: src/ftp.c:318 src/ftp.c:453 src/ftp.c:488 src/ftp.c:733 src/ftp.c:781
+#: src/host.c:263
 msgid "done.\n"
 msgstr "tamam.\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:347
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "Tür `%c' bilinmiyor, kontrol bağlantısı kapatılıyor.\n"
+msgstr "TÃ¼r `%c' bilinmiyor, kontrol baÄŸlantÄ±sÄ± kapatÄ±lÄ±yor.\n"
 
-#: src/ftp.c:366
+#: src/ftp.c:360
 msgid "done.  "
 msgstr "tamam.  "
 
-#: src/ftp.c:372
+#: src/ftp.c:366
 msgid "==> CWD not needed.\n"
-msgstr "==> CWD kullanılmadı.\n"
+msgstr "==> CWD kullanÄ±lmadÄ±.\n"
 
-#: src/ftp.c:445
+#: src/ftp.c:439
 #, c-format
 msgid "No such directory `%s'.\n\n"
 msgstr "`%s' diye bir dizin yok.\n\n"
 
 #. do not CWD
-#: src/ftp.c:463
+#: src/ftp.c:457
 msgid "==> CWD not required.\n"
-msgstr "==> CWD gerekli değil.\n"
+msgstr "==> CWD gerekli deÄŸil.\n"
 
-#: src/ftp.c:497
+#: src/ftp.c:520
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "PASV aktarımı başlatılamadı.\n"
+msgstr "PASV aktarÄ±mÄ± baÅŸlatÄ±lamadÄ±.\n"
 
-#: src/ftp.c:501
+#: src/ftp.c:524
 msgid "Cannot parse PASV response.\n"
-msgstr "PASV cevabı çözümlenemedi.\n"
+msgstr "PASV cevabÄ± Ã§Ã¶zÃ¼mlenemedi.\n"
 
-#: src/ftp.c:515
+#: src/ftp.c:545
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr "%s e bağlantı denenecek:%hu.\n"
+msgid "couldn't connect to %s:%hu: %s\n"
+msgstr "baÄŸlanÄ±lamadÄ±: %s:%hu: %s\n"
 
-#: src/ftp.c:602
+#: src/ftp.c:595
 #, c-format
 msgid "Bind error (%s).\n"
-msgstr "Bağlanma hatası (%s).\n"
+msgstr "BaÄŸlanma hatasÄ± (%s).\n"
 
-#: src/ftp.c:618
+#: src/ftp.c:611
 msgid "Invalid PORT.\n"
-msgstr "PORT geçersiz.\n"
+msgstr "PORT geÃ§ersiz.\n"
 
-#: src/ftp.c:671
+#: src/ftp.c:664
 #, c-format
 msgid "\nREST failed; will not truncate `%s'.\n"
-msgstr "\nREST başarısız; `%s' devam etmeyecek.\n"
+msgstr "\nREST baÅŸarÄ±sÄ±z; `%s' devam etmeyecek.\n"
 
-#: src/ftp.c:678
+#: src/ftp.c:671
 msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nREST başarısız, baştan başlanıyor.\n"
+msgstr "\nREST baÅŸarÄ±sÄ±z, baÅŸtan baÅŸlanÄ±yor.\n"
 
-#: src/ftp.c:727
+#: src/ftp.c:720
 #, c-format
 msgid "No such file `%s'.\n\n"
 msgstr "`%s' diye bir dosya yok.\n\n"
 
-#: src/ftp.c:775
+#: src/ftp.c:768
 #, c-format
 msgid "No such file or directory `%s'.\n\n"
 msgstr "`%s' diye bir dosya ya da dizin yok.\n\n"
 
-#: src/ftp.c:859 src/ftp.c:867
+#: src/ftp.c:852 src/ftp.c:860
 #, c-format
 msgid "Length: %s"
 msgstr "Uzunluk: %s"
 
-#: src/ftp.c:861 src/ftp.c:869
+#: src/ftp.c:854 src/ftp.c:862
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s gider]"
 
-#: src/ftp.c:871
+#: src/ftp.c:864
 msgid " (unauthoritative)\n"
-msgstr " (yetkin değil)\n"
+msgstr " (yetkin deÄŸil)\n"
 
-#: src/ftp.c:898
+#: src/ftp.c:890
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, kontrol bağlantısı kapatılıyor.\n"
+msgstr "%s: %s, kontrol baÄŸlantÄ±sÄ± kapatÄ±lÄ±yor.\n"
 
-#: src/ftp.c:906
+#: src/ftp.c:898
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
-msgstr "%s (%s) - Veri bağlantısı: %s; "
+msgstr "%s (%s) - Veri baÄŸlantÄ±sÄ±: %s; "
 
-#: src/ftp.c:923
+#: src/ftp.c:915
 msgid "Control connection closed.\n"
-msgstr "Kontrol bağlantısı kapatıldı.\n"
+msgstr "Kontrol baÄŸlantÄ±sÄ± kapatÄ±ldÄ±.\n"
 
-#: src/ftp.c:941
+#: src/ftp.c:933
 msgid "Data transfer aborted.\n"
-msgstr "Veri aktarımı kesildi.\n"
+msgstr "Veri aktarÄ±mÄ± kesildi.\n"
 
-#: src/ftp.c:1005
+#: src/ftp.c:997
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr "`%s' dosyası zaten var, alınmayacak.\n"
+msgstr "`%s' dosyasÄ± zaten var, alÄ±nmayacak.\n"
 
-#: src/ftp.c:1075 src/http.c:1502
+#: src/ftp.c:1067 src/http.c:1538
 #, c-format
 msgid "(try:%2d)"
 msgstr "(deneme:%2d)"
 
-#: src/ftp.c:1139 src/http.c:1753
+#: src/ftp.c:1131 src/http.c:1797
 #, c-format
 msgid "%s (%s) - `%s' saved [%ld]\n\n"
 msgstr "%s (%s) - `%s' kaydedildi [%ld]\n\n"
 
-#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
+#: src/ftp.c:1173 src/main.c:814 src/recur.c:336 src/retr.c:587
 #, c-format
 msgid "Removing %s.\n"
-msgstr "%s kaldırılıyor.\n"
+msgstr "%s kaldÄ±rÄ±lÄ±yor.\n"
 
-#: src/ftp.c:1221
+#: src/ftp.c:1215
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "Listeleme geçici dosyası olarak `%s' kullanılıyor.\n"
+msgstr "Listeleme geÃ§ici dosyasÄ± olarak `%s' kullanÄ±lÄ±yor.\n"
 
-#: src/ftp.c:1233
+#: src/ftp.c:1230
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr "`%s' kaldırıldı.\n"
+msgstr "`%s' kaldÄ±rÄ±ldÄ±.\n"
 
-#: src/ftp.c:1269
+#: src/ftp.c:1265
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr "Yineleme derinliği %d aşıldı. En fazla derinlik %d.\n"
+msgstr "Yineleme derinliÄŸi %d aÅŸÄ±ldÄ±. En fazla derinlik %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
 #: src/ftp.c:1330
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "Uzak dosya yerel dosya %s'den daha yeni değil -- alınmayacak.\n\n"
+msgstr "Uzak dosya yerel dosya %s'den daha yeni deÄŸil -- alÄ±nmayacak.\n\n"
 
 #. Remote file is newer or sizes cannot be matched
 #: src/ftp.c:1337
 #, c-format
 msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
-msgstr "Uzak dosya yerel dosya %s'den daha yeni  -- alınıyor.\n\n"
+msgstr "Uzak dosya yerel dosya %s'den daha yeni  -- alÄ±nÄ±yor.\n\n"
 
 #. Sizes do not match
 #: src/ftp.c:1344
 #, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
-msgstr "Uzunlukları aynı değil (yerel %ld), -- alınıyor.\n"
+msgstr "UzunluklarÄ± aynÄ± deÄŸil (yerel %ld), -- alÄ±nÄ±yor.\n"
 
 #: src/ftp.c:1361
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "Sembolik bağın ismi geçersiz, atlanıyor.\n"
+msgstr "Sembolik baÄŸÄ±n ismi geÃ§ersiz, atlanÄ±yor.\n"
 
 #: src/ftp.c:1378
 #, c-format
 msgid "Already have correct symlink %s -> %s\n\n"
-msgstr "Zaten doğru sembolik bağ var: %s -> %s\n\n"
+msgstr "Zaten doÄŸru sembolik baÄŸ var: %s -> %s\n\n"
 
 #: src/ftp.c:1386
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "Sembolik bağ oluşturuluyor: %s -> %s\n"
+msgstr "Sembolik baÄŸ oluÅŸturuluyor: %s -> %s\n"
 
 #: src/ftp.c:1397
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Sembolik bağ desteklenmiyor. `%s' sembolik bağı atlanıyor.\n"
+msgstr "Sembolik baÄŸ desteklenmiyor. `%s' sembolik baÄŸÄ± atlanÄ±yor.\n"
 
 #: src/ftp.c:1409
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "`%s' dizini atlanıyor.\n"
+msgstr "`%s' dizini atlanÄ±yor.\n"
 
 #: src/ftp.c:1418
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: bilinmeyen/desteklenmeyen dosya türü.\n"
+msgstr "%s: bilinmeyen/desteklenmeyen dosya tÃ¼rÃ¼.\n"
 
 #: src/ftp.c:1445
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: zaman damgası bozuk.\n"
+msgstr "%s: zaman damgasÄ± bozuk.\n"
 
-#: src/ftp.c:1466
+#: src/ftp.c:1470
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr "%d derinliğindeki dizinler alınamayacak (en çok %d)\n"
+msgstr "%d derinliÄŸindeki dizinler alÄ±namayacak (en Ã§ok %d)\n"
 
-#: src/ftp.c:1512
+#: src/ftp.c:1520
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr "Dışlanan/içerilmeyen olduğundan dolayı `%s' e inilmiyor.\n"
+msgstr "DÄ±ÅŸlanan/iÃ§erilmeyen olduÄŸundan dolayÄ±Â `%s' e inilmiyor.\n"
 
-#: src/ftp.c:1559
+#: src/ftp.c:1574
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "`%s' reddediliyor.\n"
