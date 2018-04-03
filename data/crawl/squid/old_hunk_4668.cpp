static STDIRSELECT storeDirSelectSwapDirRoundRobin;
static STDIRSELECT storeDirSelectSwapDirLeastLoad;

int StoreController::store_dirs_rebuilding = 0;

StoreController::StoreController() : swapDir (new StoreHashIndex())
{}
