Ipc::Mem::Segment::checkSupport(const char *const context)
{
    if (!Enabled()) {
        debugs(54, 5, HERE << "True shared memory segments are not supported. "
               "Cannot fake shared segments in SMP config.");
        fatalf("%s failed", context);
    }
}
