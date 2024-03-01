#include "../header/prop_modif.h"

/** 
 * @brief This function will set to " " all the metadata of the audio files in the folder
 * 
 * @param folder_path The path of the folder
 * 
 * @param str_to_find The string to find in the metadatas
 * 
 * @return 0 if the function was successful, 1 if the directory could not be opened, 2 if the directory could not be read, 
 * 3 if memory could not be allocated, 4 if the full path could not be created, 5 if the file status could not be obtained
*/
int prop_modif(const char* folder_path, const char* str_to_find) {
    // open the directory
    DIR* dir = opendir(folder_path);

    if (dir == NULL) {
        if (DEBUG) {
            perror("Error: could not open directory\n");
        }

        return 1; 
    }

    // read the directory until the end
    struct dirent* item;
    while((item = readdir(dir))) {
        // if the item is NULL, then there was an error reading the directory
        if (item == NULL) {
            if (DEBUG) {
                perror("Error: could not read directory\n");
            }

            return 2; 
        } 
        
        // if the item is not a hidden file, we will process it
        if (item->d_name[0] != '.') {
            // create the full path and check for errors
            char full_path[PATH_MAX];
            int full_path_err = snprintf(full_path, sizeof(full_path), "%s/%s", folder_path, item->d_name);

            if (full_path_err < 0) {
                if (DEBUG) {
                    perror("Error: could not create full path\n");
                }

                return 4; 
            }

            // get the file status to know if it's a directory or a file
            struct stat *st = (struct stat*) malloc(sizeof(struct stat));
            if (st == NULL) {
                if (DEBUG) {
                    perror("Error: could not allocate memory\n");
                }

                return 3; 
            }

            int stat_err = stat(full_path, st);
            if (stat_err < 0) {
                if (DEBUG) {
                    perror("Error: could not get file status\n");
                }

                return 5; 
            }

            // if it's a directory, we will call the function recursively, if it's a file, we will process it
            if(S_ISDIR(st->st_mode)) {
                //before call the function, check if the name of the folder contains str_to_find and if it does, call modify_title
                prop_modif(full_path, str_to_find);
            } else {
                

            }
        }
    }

    return 0;
}

int modify_title(const char* file_path, const char* str_to_delete) {
    
}