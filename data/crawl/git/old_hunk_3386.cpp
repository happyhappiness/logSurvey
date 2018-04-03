 */
#define TMP_RENAMED_LOG  "logs/refs/.tmp-renamed-log"

int rename_ref(const char *oldrefname, const char *newrefname, const char *logmsg)
{
	unsigned char sha1[20], orig_sha1[20];
