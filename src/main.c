#include "../header/base.h"
#include "../header/prop_modif.h"

int main() {
    printf("Enter the name of the folder that you want to scan: ");
    char file_name[PATH_MAX];
    scanf("%s", file_name);

    printf("Enter the string to delete from the title: ");
    char str_to_delete[PATH_MAX];
    scanf("%s", str_to_delete);

    int error_chk = prop_modif(file_name, str_to_delete);

    if (DEBUG) {
        if (error_chk == 0) {
            printf("the function was successful\n");
        } else if (error_chk == 1) {
            printf("the directory could not be opened\n");
        } else if (error_chk == 2) {
            printf("the directory could not be read\n");
        } else if (error_chk == 3) {
            printf("memory could not be allocated\n");
        } else if (error_chk == 4) {
            printf("the full path could not be created\n");
        } else if (error_chk == 5) {
            printf("the file status could not be obtained\n");
        } else if (error_chk == 6) {
            printf("the file could not be renamed\n");
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