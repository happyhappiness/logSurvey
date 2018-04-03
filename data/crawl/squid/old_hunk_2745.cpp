/// prepares and initiates entry loading sequence
void
Rock::Rebuild::start() {
    debugs(47, DBG_IMPORTANT, "Loading cache_dir #" << sd->index <<
           " from " << sd->filePath);

