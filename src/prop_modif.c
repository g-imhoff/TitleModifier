#include "../header/prop_modif.h"

/**
 * @brief This function will modify the title of the audio file, by deleting
 * str_to_delete if it's present
 *
 * @param file_name The name of the file
 * @param str_to_delete The string to delete from the title
 *
 * @return 0 if the function was successful, 1 if the string was not found
 */

int modify_title(const char* file_name,
                 const char* str_to_delete,
                 char* new_title) {
    // search for the string in the title
    char* sub_str = strstr(file_name, str_to_delete);
    if (sub_str == NULL) {
        // if the string is not found, we stop the function and return 1
        return 1;
    }
    // if the string is found, we will create the new title
    int len_file_name = strlen(file_name);
    int len_str_to_delete = strlen(str_to_delete);
    int i_for_new_title = 0;

    // we will copy the characters of the title to the new title, except for the
    // ones that are in the string to delete
    for (int i = 0; i < len_file_name; i++) {
        if (!(i >= sub_str - file_name &&
              i < sub_str - file_name + len_str_to_delete)) {
            new_title[i_for_new_title] = file_name[i];
            i_for_new_title++;
        }
    }
    // we will add the null character at the end of the new title and return 0
    // to say that the function was successful
    new_title[i_for_new_title] = '\0';

    return 0;
}

/**
 * @brief This function will modify the path of the audio file or folder, by
 * replacing old_title with new_title
 *
 * @param path The path of the file or folder
 * @param old_title The old title
 * @param new_title The new title
 *
 * @return 0 if the function was successful, 4 if the full path could not be
 * created, 6 if the file could not be renamed
 */

int modify_path(const char* path,
                const char* old_title,
                const char* new_title) {
    // create the full path for the old and new title variable
    char* old_full_path = (char*)malloc(PATH_MAX);
    char* new_full_path = (char*)malloc(PATH_MAX);

    // create the old_full_path and check for errors
    int old_full_path_err =
        snprintf(old_full_path, PATH_MAX, "%s/%s", path, old_title);
    if (old_full_path_err < 0) {
        if (DEBUG) {
            perror("Error: could not create old full path\n");
        }
        free(old_full_path);
        free(new_full_path);

        return 4;
    }

    // create the new_full_path and check for errors
    int new_full_path_err =
        snprintf(new_full_path, PATH_MAX, "%s/%s", path, new_title);
    if (new_full_path_err < 0) {
        if (DEBUG) {
            perror("Error: could not create new full path\n");
        }
        free(old_full_path);
        free(new_full_path);
        return 4;
    }

    if (DEBUG) {
        printf("Old title: %s\n-> ", old_full_path);
        printf("New title: %s\n", new_full_path);
    }

    // rename the file or folder and check for errors
    int result = rename(old_full_path, new_full_path);
    if (result != 0) {
        if (DEBUG) {
            perror("Error: could not rename file\n");
        }
        free(old_full_path);
        free(new_full_path);
        return 6;
    }

    // if everything was successful, we will free the memory and return 0
    free(old_full_path);
    free(new_full_path);

    return 0;
}

/**
 * @brief This function will modify the title of the file or folder, by deleting
 * str_to_delete if it's present
 *
 * @param path The path of the file or folder
 * @param title The actual title of the file or folder
 * @param str_to_delete The string to delete from the title
 *
 * @return 0 if the function was successful, 1 if the string was not found
 */

int file_title_modifier(const char* path,
                        const char* title,
                        const char* str_to_delete) {
    // call the function to modify the title
    char* new_title = (char*)malloc(strlen(title) + 1);
    int error_modify_title = modify_title(title, str_to_delete, new_title);
    if (error_modify_title != 0) {
        // if (DEBUG) {
        //     printf("Error: the string was not found\n");
        // }
        free(new_title);
        return 1;
    } else {
        // call the function to modify the path if the title need to be modified
        // and free the memory
        modify_path(path, title, new_title);
    }
    free(new_title);

    return 0;
}

/**
 * @brief This function will set to " " all the metadata of the audio files in
 * the folder
 *
 * @param folder_path The path of the folder
 * @param str_to_find The string to find in the metadatas
 *
 * @return 0 if the function was successful, 1 if the directory could not be
 * opened, 2 if the directory could not be read, 3 if memory could not be
 * allocated, 4 if the full path could not be created, 5 if the file status
 * could not be obtained
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
    while ((item = readdir(dir))) {
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
            char* full_path = (char*)malloc(PATH_MAX);
            int full_path_err = snprintf(full_path, PATH_MAX, "%s/%s",
                                         folder_path, item->d_name);

            if (full_path_err < 0) {
                if (DEBUG) {
                    perror("Error: could not create full path\n");
                }

                return 4;
            }

            // get the file status to know if it's a directory or a file
            struct stat* st = (struct stat*)malloc(sizeof(struct stat));
            if (st == NULL) {
                if (DEBUG) {
                    perror("Error: could not allocate memory\n");
                }

                return 3;
            }

            // if the file status could not be obtained, we will stop the function
            int stat_err = stat(full_path, st);
            if (stat_err < 0) {
                if (DEBUG) {
                    perror("Error: could not get file status\n");
                    printf("The file is: %s\n", full_path);
                }

                return 5;
            }

            char* new_title = (char*)malloc(strlen(item->d_name) + 1);

            // if it's a directory, we will call the function recursively, if
            // it's a file, we will process it
            if (S_ISDIR(st->st_mode)) {
                // before call the function, check if the name of the folder
                // contains str_to_find and if it does, call modify_title
                prop_modif(full_path, str_to_find);
                file_title_modifier(folder_path, item->d_name, str_to_find);
            } else {
                file_title_modifier(folder_path, item->d_name, str_to_find);
            }
            free(full_path);
            free(new_title);
        }
    }

    return 0;
}
