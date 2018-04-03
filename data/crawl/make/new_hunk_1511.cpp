    case 0:
      DEBUGPR ("Successfully remade target file `%s'.\n");
      break;
    default:
      assert (file->update_status == 0 || file->update_status == 1);
      break;
    }

  file->updated = 1;
