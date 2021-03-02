//Program by Bryce Standley
//Murdoch Student Number: 33046367
//Unit: ICT289
//Exercise: Lab01 Ex 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct vectorData
{
    float x, y, z;
};

struct faceData
{
    int x, y, z;
};
typedef struct vectorData vectorData;
typedef struct faceData faceData;

char fileName[32];
char line[32];
FILE *file;
int nVert, nFace;

int FindOFFVertAndFace()
{
    int vert, face;
    file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("File failed to open! now quitting!\n");
        return(0);
    }

    int i = 0;
    while(fgets(line, 32, file) != NULL)
    {
        switch (i)
        {
        case 0:
            i++;
            break;
        case 1:
        {
            char* token;
            char* rest = line;
            int count = 0;
            while((token = strtok_r(rest, " ", &rest)))
            {
                if(count == 0)
                {
                    nVert= atoi(token);
    
                }
                else if(count == 1)
                {
                    nFace = atoi(token);
                }
                count++;
            }  
            i++;    
        }     
            break;

        default:
            fclose(file);
            return(1);
            break;
        };
    } 
    return(1);
}

void readOFFFile(vectorData *openOffFileVectors, faceData *openOffFileFaces)
{
    int vert, face;
    file = fopen(fileName, "r");
    int i = 0;
    int lineCount = 0;
    while(fgets(line, 32, file) != NULL)
    {
        switch (i)
        {
        case 0:
        case 1:
            i++;
            break;
        default:
            char* token;
            char* rest = line;
            int count = 0;
            if(i > 1 && i < nVert + 3)
            {
                //vert line
                while((token = strtok_r(rest, " ", &rest)))
                {
                    switch (count)
                    {
                        case 0:
                            openOffFileVectors[lineCount].x = atof(token);
                            break;
                        case 1:
                            openOffFileVectors[lineCount].y = atof(token);
                            break;
                        case 2:
                            openOffFileVectors[lineCount].z = atof(token);
                            break;
                        default:
                            break;
                    }
                    count++;
                    
                }  
                lineCount++;
            }
            else if(i > nVert + 2)
            {
                // tri line
                if(i == nVert + 3)
                {
                    lineCount = 0;
                }
                while((token = strtok_r(rest, " ", &rest)))
                {
                    switch (count)
                    {
                        case 0:
                            //ignore the first value
                            break;
                        case 1:
                            openOffFileFaces[lineCount].x = atoi(token);
                            break;
                        case 2:
                            openOffFileFaces[lineCount].y = atoi(token);
                            break;
                        case 3:
                            openOffFileFaces[lineCount].z = atoi(token);
                            break;
                        default:
                            break;
                    }
                    count++;
                    
                } 
                lineCount++; 
            }
                i++;  
                break;  
            }
        };
    fclose(file);
    return;
}



int main ()
{
    printf("Please enter the OFF file to open: ");
    scanf("%s", fileName);

    if(FindOFFVertAndFace() == 0)
    {
        return(0);
    }

    const int vert = nVert;
    const int face = nFace;
    vectorData openOffFileVectors[vert];
    faceData openOffFileFaces[face];

    readOFFFile(openOffFileVectors, openOffFileFaces);
    char ch;
    printf("\n-------------------------------------------\n");
    printf("There is %d vectors and %d faces within %s\n", nVert, nFace, fileName);
    printf("-------------------------------------------\n");
    printf("Press enter to start to display each vector, continue to press enter to display each vector or f to start showing faces\n");
    scanf("%c", &ch);
    int i = 0;
    ch = tolower(ch);

    if(ch == '\n')
    {
        do
        {
            printf("\nVertex: X:%f, Y:%f, Z:%f\n", openOffFileVectors[i].x, openOffFileVectors[i].y, openOffFileVectors[i].z);
            i++;
            scanf("%c", &ch);
        }while(ch == '\n');
    }

    if(ch == 'f')
    {
        do
        {
            printf("\nFace: X:%d, Y:%d, Z:%d\n", openOffFileFaces[i].x, openOffFileFaces[i].y, openOffFileFaces[i].z);
            i++;
            scanf("%c", &ch);
        }while(ch == '\n');
    }

    if(ch == 'q')
    {
        return(0);
    }

    return 0;
}


