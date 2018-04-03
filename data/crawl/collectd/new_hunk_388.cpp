        CB_TYPE_SHUTDOWN));
} /* }}} jint cjni_api_register_shutdown */

static void JNICALL cjni_api_log (JNIEnv *jvm_env, /* {{{ */
    jobject this, jint severity, jobject o_message)
{
  const char *c_str;

  c_str = (*jvm_env)->GetStringUTFChars (jvm_env, o_message, 0);
  if (c_str == NULL)
  {
    ERROR ("java plugin: cjni_api_log: GetStringUTFChars failed.");
    return;
  }

  if (severity < LOG_ERR)
    severity = LOG_ERR;
  if (severity > LOG_DEBUG)
    severity = LOG_DEBUG;

  plugin_log (severity, "%s", c_str);

  (*jvm_env)->ReleaseStringUTFChars (jvm_env, o_message, c_str);
} /* }}} void cjni_api_log */

/* List of ``native'' functions, i. e. C-functions that can be called from
 * Java. */
static JNINativeMethod jni_api_functions[] = /* {{{ */
