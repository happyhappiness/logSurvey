  else
    {
      if (file->parent == 0)
        fatal (NILF, msg_noparent, "", file->name, "");
      else
        fatal (NILF, msg_parent, "", file->name, file->parent->name, "");
    }
}

