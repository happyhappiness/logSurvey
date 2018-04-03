
#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Bağ         "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Kesin değil "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s bayt)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:187
#, c-format
msgid "Logging in as %s ... "
msgstr "%s olarak oturuma giriliyor ... "

#: src/ftp.c:196 src/ftp.c:249 src/ftp.c:281 src/ftp.c:330 src/ftp.c:423
#: src/ftp.c:474 src/ftp.c:504 src/ftp.c:568 src/ftp.c:641 src/ftp.c:702
#: src/ftp.c:750
msgid "Error in server response, closing control connection.\n"
msgstr "Sunucu cevabında hata, kontrol bağlantısı kapatılıyor.\n"

#: src/ftp.c:204
msgid "Error in server greeting.\n"
msgstr "Sunucu karşılama iletisinde hata.\n"

#: src/ftp.c:212 src/ftp.c:339 src/ftp.c:432 src/ftp.c:513 src/ftp.c:578
#: src/ftp.c:651 src/ftp.c:712 src/ftp.c:760
msgid "Write failed, closing control connection.\n"
msgstr "Yazma başarısız, kontrol bağlantısı kapatılıyor.\n"

#: src/ftp.c:219
msgid "The server refuses login.\n"
msgstr "Sunucu oturum açmayı reddetti.\n"

#: src/ftp.c:226
msgid "Login incorrect.\n"
msgstr "Oturum açma başarısız.\n"

#: src/ftp.c:233
msgid "Logged in!\n"
msgstr "Oturum açıldı!\n"

#: src/ftp.c:258
msgid "Server error, can't determine system type.\n"
msgstr "Sunucu hatası, sistem türü saptanamadı.\n"

#: src/ftp.c:268 src/ftp.c:553 src/ftp.c:625 src/ftp.c:682
msgid "done.    "
msgstr "tamam.   "

#: src/ftp.c:318 src/ftp.c:453 src/ftp.c:488 src/ftp.c:733 src/ftp.c:781
#: src/host.c:263
msgid "done.\n"
msgstr "tamam.\n"

#: src/ftp.c:347
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tür `%c' bilinmiyor, kontrol bağlantısı kapatılıyor.\n"

#: src/ftp.c:360
msgid "done.  "
msgstr "tamam.  "

#: src/ftp.c:366
msgid "==> CWD not needed.\n"
msgstr "==> CWD kullanılmadı.\n"

#: src/ftp.c:439
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "`%s' diye bir dizin yok.\n\n"

#. do not CWD
#: src/ftp.c:457
msgid "==> CWD not required.\n"
msgstr "==> CWD gerekli değil.\n"

#: src/ftp.c:520
msgid "Cannot initiate PASV transfer.\n"
msgstr "PASV aktarımı başlatılamadı.\n"

#: src/ftp.c:524
msgid "Cannot parse PASV response.\n"
msgstr "PASV cevabı çözümlenemedi.\n"

#: src/ftp.c:545
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "bağlanılamadı: %s:%hu: %s\n"

#: src/ftp.c:595
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bağlanma hatası (%s).\n"

#: src/ftp.c:611
msgid "Invalid PORT.\n"
msgstr "PORT geçersiz.\n"

#: src/ftp.c:664
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST başarısız; `%s' devam etmeyecek.\n"

#: src/ftp.c:671
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST başarısız, baştan başlanıyor.\n"

#: src/ftp.c:720
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "`%s' diye bir dosya yok.\n\n"

#: src/ftp.c:768
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "`%s' diye bir dosya ya da dizin yok.\n\n"

#: src/ftp.c:852 src/ftp.c:860
#, c-format
msgid "Length: %s"
msgstr "Uzunluk: %s"

#: src/ftp.c:854 src/ftp.c:862
#, c-format
msgid " [%s to go]"
msgstr " [%s gider]"

#: src/ftp.c:864
msgid " (unauthoritative)\n"
msgstr " (yetkin değil)\n"

#: src/ftp.c:890
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, kontrol bağlantısı kapatılıyor.\n"

#: src/ftp.c:898
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Veri bağlantısı: %s; "

#: src/ftp.c:915
msgid "Control connection closed.\n"
msgstr "Kontrol bağlantısı kapatıldı.\n"

#: src/ftp.c:933
msgid "Data transfer aborted.\n"
msgstr "Veri aktarımı kesildi.\n"

#: src/ftp.c:997
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "`%s' dosyası zaten var, alınmayacak.\n"

#: src/ftp.c:1067 src/http.c:1538
#, c-format
msgid "(try:%2d)"
msgstr "(deneme:%2d)"

#: src/ftp.c:1131 src/http.c:1797
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' kaydedildi [%ld]\n\n"

#: src/ftp.c:1173 src/main.c:814 src/recur.c:336 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "%s kaldırılıyor.\n"

#: src/ftp.c:1215
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Listeleme geçici dosyası olarak `%s' kullanılıyor.\n"

#: src/ftp.c:1230
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' kaldırıldı.\n"

#: src/ftp.c:1265
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Yineleme derinliği %d aşıldı. En fazla derinlik %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Uzak dosya yerel dosya %s'den daha yeni değil -- alınmayacak.\n\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Uzak dosya yerel dosya %s'den daha yeni  -- alınıyor.\n\n"

#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Uzunlukları aynı değil (yerel %ld), -- alınıyor.\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Sembolik bağın ismi geçersiz, atlanıyor.\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Zaten doğru sembolik bağ var: %s -> %s\n\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Sembolik bağ oluşturuluyor: %s -> %s\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Sembolik bağ desteklenmiyor. `%s' sembolik bağı atlanıyor.\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "`%s' dizini atlanıyor.\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: bilinmeyen/desteklenmeyen dosya türü.\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: zaman damgası bozuk.\n"

#: src/ftp.c:1470
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "%d derinliğindeki dizinler alınamayacak (en çok %d)\n"

#: src/ftp.c:1520
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Dışlanan/içerilmeyen olduğundan dolayı `%s' e inilmiyor.\n"

#: src/ftp.c:1574
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' reddediliyor.\n"
