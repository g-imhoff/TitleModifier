#include "../header/base.h"
#include "../header/prop_modif.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <folder_path> <str_to_find>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int error_chk = prop_modif(argv[1], argv[2]);

    if (DEBUG) {
        if (error_chk == 0) {
            printf("the function was successful");
        } else if (error_chk == 1) {
            printf("the directory could not be opened");
        } else if (error_chk == 2) {
            printf("the directory could not be read");
        } else if (error_chk == 3) {
            printf("memory could not be allocated");
        } else if (error_chk == 4) {
            printf("the full path could not be created");
        } else if (error_chk == 5) {
            printf("the file status could not be obtained");
        } else if (error_chk == 6) {
            printf("the file could not be renamed");
        }
    }

    return EXIT_SUCCESS;
}

/*
SF_INFO* sfi = (SF_INFO*)malloc(sizeof(SF_INFO));
SNDFILE* sf = sf_open("./❊ 808 • army.wav", SFM_RDWR, sfi);

if (sf == NULL) {
    printf("Error: could not open file\n");
    return EXIT_FAILURE;
}

chmod("./❊ 808 • army.wav", 0664);
int error_chk = sf_set_string(sf, SF_STR_TITLE, " ");
if (error_chk != 0) {
    const char* error = sf_error_number(error_chk);
    printf("%s\n", error);
    return EXIT_FAILURE;
}

printf("%s\n", sf_get_string(sf, SF_STR_TITLE));

sf_close(sf);
*/