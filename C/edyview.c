#include <stdio.h>
#include <stdlib.h>
#include <libpafe/libpafe.h>

int main(int argc, char* argv[])
{
    pasori *p;
    felica *f;
    uint8 data[16];

    p = pasori_open();
    if (!p)
    {
        fprintf(stderr, "Failed to open PaSoLi.\n");
        return EXIT_FAILURE;
    }
    pasori_init(p);
    f = felica_polling(p, FELICA_POLLING_EDY, 0, 0);

    if (f && !felica_read_single(f, FELICA_SERVICE_EDY_HISTORY, 0, 0, data))
    {
        printf("%5d Yen\n", (data[14] << 8) + data[15]);
    }
    else
    {
        fprintf(stderr, "Edy not found.\n");
        return EXIT_FAILURE;
    }

    free(f);
    pasori_close(p);

    return EXIT_SUCCESS;
}
