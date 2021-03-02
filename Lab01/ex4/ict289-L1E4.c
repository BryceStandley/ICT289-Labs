#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct offVert
{
    float x, y, z;
};

struct offTri
{
    int triX, triY, triZ;
};

typedef struct offVert offVert;
typedef struct offTri offTri;

char fileName[32];
char line[32];
FILE *file;
int nVert, nFace;




void readOFFFile(offVert openFileVert[], offTri openFileTri[]);
void FindOFFVertAndFace();

void FindOFFVertAndFace()
{
    int vert, face;
    file = fopen(fileName, "r");
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
            return;
            break;
        };
    } 
}

void readOFFFile(offVert openFileVert[], offTri openFileTri[])
{
    int vert, face;
    file = fopen(fileName, "r");
    int i = 0;
    int lineCount = 0;
    while(fgets(line, 32, file) != NULL)
    {
        printf("%d   %s \n", i, line);
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
                            openFileVert[lineCount].x = atof(token);
                            break;
                        case 1:
                            openFileVert[lineCount].y = atof(token);
                            break;
                        case 2:
                            openFileVert[lineCount].z = atof(token);
                            break;
                        default:
                            break;
                    }
                    count++;
                    lineCount++;
                }  
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
                            openFileTri[lineCount].triX = atoi(token);
                            break;
                        case 2:
                            openFileTri[lineCount].triY = atoi(token);
                            break;
                        case 3:
                            openFileTri[lineCount].triZ = atoi(token);
                            break;
                        default:
                            break;
                    }
                    count++;
                    lineCount++;
                }  
            }
                i++;  
                break;  
            }
        };
        printf("File Closed");
    fclose(file);
    return;
}

int main ()
{
    printf("Please enter the OFF file to open: ");
    scanf("%s%*c", &fileName);

    FindOFFVertAndFace();
    const int vert = nVert;
    const int face = nFace;
    offVert openFileVert[vert];
    offTri openFileTri[face];
    printf("Got to here");
    readOFFFile(openFileVert, openFileTri);
    char ch;
    printf("There is %d vertices and %d faces within this off file\n", nVert, nFace);
    printf("Press enter to start to display each vertice, continue to press enter to display each vertice or f to start showing faces\n");
    scanf("%c*%c", &ch);
    int i = 0;
    ch = tolower(ch);
    if(ch == 'f')
    {
        printf("Press enter to start to display each face, continue to press enter to display each face or q to quit\n");
        if(tolower(ch) == 'q')
        {
            return(0);
        }
        else
        {
            do
            {
                printf("Face: X:%d, Y:%d, Z:%d\n", openFileTri[i].triX, openFileTri[i].triY, openFileTri[i].triZ);
                i++;
                scanf("%c*%c", &ch);
            }while(ch == '\n');
        }
    }
    else
    {
        i = 0;
        do
        {
            printf("Vertex: X:%f, Y:%f, Z:%f\n", openFileVert[i].x, openFileVert[i].y, openFileVert[i].z);
            i++;
            scanf("%c*%c", &ch);
        } while (ch == '\n');
        
    }
    return 0;
}


