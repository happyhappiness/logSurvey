    return sfilenoMax;
}

size_t
Rock::DirMap::Shared::MemSize(int limit)
{
    return sizeof(Shared) + limit*sizeof(DbCellHeader);
}
