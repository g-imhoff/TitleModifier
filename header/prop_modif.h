#ifndef PROP_MODIF_H
#define PROP_MODIF_H

// include
#include "./base.h"
#include <string.h>

#ifdef __linux__
#include <linux/limits.h>
#elif _WIN32
#include <windows.h> // Inclure les fichiers d'en-tête Windows nécessaires
#endif

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

// function prototype
int prop_modif(const char* folder_path, const char* str_to_find);
int modify_title(const char* file_name,
                 const char* str_to_delete,
                 char* new_title);

#endif  // PROP_MODIF_H