 def gittz(tz):
     return '%+03d%02d' % (tz / 3600, tz % 3600 / 60)
 
+def get_config(config):
+    cmd = ['git', 'config', '--get', config]
+    process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
+    output, _ = process.communicate()
+    return output
+
 class Marks:
 
     def __init__(self, path):
