  else
    {
      if (file->parent == 0)
        fatal (msg_noparent, "", file->name, "");
      else
        fatal (msg_parent, "", file->name, file->parent->name, "");
    }
}

