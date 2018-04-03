
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:149 src/http.c:623
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "%s e baðlanýlýyor:%hu..."

#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "%s e baðlanýlýyor:%hu reddedildi.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:192 src/http.c:651
msgid "connected!\n"
msgstr "baðlantý kuruldu!\n"

#: src/ftp.c:193
#, c-format
msgid "Logging in as %s ... "
msgstr "%s olarak oturuma giriliyor ... "

#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
msgid "Error in server response, closing control connection.\n"
msgstr "Sunucu cevabýnda hata, kontrol baðlantýsý kapatýlýyor.\n"

#: src/ftp.c:210
msgid "Error in server greeting.\n"
msgstr "Sunucu karþýlama iletisinde hata.\n"

#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
msgid "Write failed, closing control connection.\n"
msgstr "Yazma baþarýsýz, kontrol baðlantýsý kapatýlýyor.\n"

#: src/ftp.c:225
msgid "The server refuses login.\n"
msgstr "Sunucu oturum açmayý reddetti.\n"

#: src/ftp.c:232
msgid "Login incorrect.\n"
msgstr "Oturum açma baþarýsýz.\n"

#: src/ftp.c:239
msgid "Logged in!\n"
msgstr "Oturum açýldý!\n"

#: src/ftp.c:264
msgid "Server error, can't determine system type.\n"
msgstr "Sunucu hatasý, sistem türü saptanamadý.\n"

#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
msgid "done.    "
msgstr "tamam.   "

#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
msgid "done.\n"
msgstr "tamam.\n"

#: src/ftp.c:352
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tür `%c' bilinmiyor, kontrol baðlantýsý kapatýlýyor.\n"

#: src/ftp.c:365
msgid "done.  "
msgstr "tamam.  "

#: src/ftp.c:371
msgid "==> CWD not needed.\n"
msgstr "==> CWD kullanýlmadý.\n"

#: src/ftp.c:444
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "`%s' diye bir dizin yok.\n\n"

#. do not CWD
#: src/ftp.c:462
msgid "==> CWD not required.\n"
msgstr "==> CWD gerekli deðil.\n"

#: src/ftp.c:496
msgid "Cannot initiate PASV transfer.\n"
msgstr "PASV aktarýmý baþlatýlamadý.\n"

#: src/ftp.c:500
msgid "Cannot parse PASV response.\n"
msgstr "PASV cevabý çözümlenemedi.\n"

#: src/ftp.c:514
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "%s e baðlantý denenecek:%hu.\n"

#: src/ftp.c:601
#, c-format
msgid "Bind error (%s).\n"
msgstr "Baðlanma hatasý (%s).\n"

#: src/ftp.c:617
msgid "Invalid PORT.\n"
msgstr "PORT geçersiz.\n"

#: src/ftp.c:670
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST baþarýsýz; `%s' devam etmeyecek.\n"

#: src/ftp.c:677
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST baþarýsýz, baþtan baþlanýyor.\n"

#: src/ftp.c:726
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "`%s' diye bir dosya yok.\n\n"

#: src/ftp.c:774
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "`%s' diye bir dosya ya da dizin yok.\n\n"

#: src/ftp.c:858 src/ftp.c:866
#, c-format
msgid "Length: %s"
msgstr "Uzunluk: %s"

#: src/ftp.c:860 src/ftp.c:868
#, c-format
msgid " [%s to go]"
msgstr " [%s gider]"

#: src/ftp.c:870
msgid " (unauthoritative)\n"
msgstr " (yetkin deðil)\n"

#: src/ftp.c:897
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, kontrol baðlantýsý kapatýlýyor.\n"

#: src/ftp.c:905
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Veri baðlantýsý: %s; "

#: src/ftp.c:922
msgid "Control connection closed.\n"
msgstr "Kontrol baðlantýsý kapatýldý.\n"

#: src/ftp.c:940
msgid "Data transfer aborted.\n"
msgstr "Veri aktarýmý kesildi.\n"

#: src/ftp.c:1004
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "`%s' dosyasý zaten var, alýnmayacak.\n"

#: src/ftp.c:1074 src/http.c:1501
#, c-format
msgid "(try:%2d)"
msgstr "(deneme:%2d)"

#: src/ftp.c:1138 src/http.c:1752
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' kaydedildi [%ld]\n\n"

#: src/ftp.c:1180 src/main.c:809 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "%s kaldýrýlýyor.\n"

#: src/ftp.c:1220
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Listeleme geçici dosyasý olarak `%s' kullanýlýyor.\n"

#: src/ftp.c:1232
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' kaldýrýldý.\n"

#: src/ftp.c:1268
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Yineleme derinliði %d aþýldý. En fazla derinlik %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1329
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Uzak dosya yerel dosya %s'den daha yeni deðil -- alýnmayacak.\n\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1336
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Uzak dosya yerel dosya %s'den daha yeni  -- alýnýyor.\n\n"

#. Sizes do not match
#: src/ftp.c:1343
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Uzunluklarý ayný deðil (yerel %ld), -- alýnýyor.\n"

#: src/ftp.c:1360
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Sembolik baðýn ismi geçersiz, atlanýyor.\n"

#: src/ftp.c:1377
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Zaten doðru sembolik bað var: %s -> %s\n\n"

#: src/ftp.c:1385
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Sembolik bað oluþturuluyor: %s -> %s\n"

#: src/ftp.c:1396
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Sembolik bað desteklenmiyor. `%s' sembolik baðý atlanýyor.\n"

#: src/ftp.c:1408
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "`%s' dizini atlanýyor.\n"

#: src/ftp.c:1417
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: bilinmeyen/desteklenmeyen dosya türü.\n"

#: src/ftp.c:1444
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: zaman damgasý bozuk.\n"

#: src/ftp.c:1465
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "%d derinliðindeki dizinler alýnamayacak (en çok %d)\n"

#: src/ftp.c:1511
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Dýþlanan/içerilmeyen olduðundan dolayý `%s' e inilmiyor.\n"

#: src/ftp.c:1558
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' reddediliyor.\n"
