#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }

    //Check if card is opened
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open the file \n");
        return 1;
    }

    FILE *image;
    char newFile[7];
    unsigned char *byte = malloc(512);
    int count = 0;

    while (fread(byte, 512, 1, file))
    {
        // JPG found
        if (byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff && (byte[3] & 0xf0) == 0xe0) //4th byte definitely starts with 0xe
        {
            //Close previous file
            if (count > 0)
            {
                fclose(image);
            }

            sprintf(newFile, "%03i.jpg", count); //Save file
            //Open the new file
            image = fopen(newFile, "w");

            if (image == NULL)
            {
                fclose(file);
                free(byte);
                printf("Couldn't create the file");
                return 1;
            }
            count++;
        }

        if (count > 0)
        {
            fwrite(byte, 512, 1, image);
        }
    }

    //Free the memory
    fclose(image);
    fclose(file);
    free(byte);
    return 0;
}
