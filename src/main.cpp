
#include <cstring>
#include <stdint.h>
#include <stdio.h>
#include <iostream>  
#include <unistd.h>
#include <cstdlib>
#include <io.h>
#include <sys/stat.h>
#include "def.h"
#include "ImageBenchmarker.h"

using namespace std;

void printUsage()
{
    print_info("------ Image Benchmarker Usage ------\n");
    print_info(" imagebenchmarker: \n");
    print_info(" -h : print help infomation\n");
    print_info(" -n 50 -t 0 -s srcImage -c 960x640\n");
    print_info("\t \t -n 50：thread num\n");
    print_info("\t \t -t 0: the library to use (0: GraphicsMagick)\n");
    print_info("\t \t -s srcImage：source image path\n");
    print_info("\t \t -c 960x640：the operation is crop image to size 960x640\n");

    print_info( "----------------------------------\n");
}

bool isValidSize(char * sizeStr, uint32_t& width, uint32_t& height)
{
    int subStrNum = 0;
    int CORRECT_SUBSTR_NUM = 2;
    char *p[CORRECT_SUBSTR_NUM+1];
    char *buf = sizeStr;
    char *outer_ptr;

    while((p[subStrNum] = strtok_r(buf, "x", &outer_ptr))!=NULL)   
    {  
        subStrNum++; 
        if (subStrNum>CORRECT_SUBSTR_NUM) break; 
        buf = NULL;
    }

    if (subStrNum != CORRECT_SUBSTR_NUM) 
    {
        error_log("Invalid size str: %s", sizeStr);
        return false;
    }

    width = atoi(p[0]);
    height = atoi(p[1]);

    return true;
}

int main(int argc, char *argv[]) 
{
    if(argc<2)
    {
        printUsage();
        exit(1);
    }
    
    char temp;
    uint32_t threadNum = 0;
    ImageOperation imageOperation;
    ImageHelperType imageHelperType = INVALID_HELPER;

    while((temp=getopt(argc,argv,"n:t:s:c:h"))!=-1)   
    {   
        switch (temp)   
        {
            case 'c':    
            {
                if (!isValidSize(optarg,imageOperation.destImageWidth, imageOperation.destImageHeight))
                {
                    error_log("Invalid size str: %s", optarg);
                    exit(1);
                }

                imageOperation.opType = CROP_OP; 
                break; 
            }
            
            case 's':   
            {
                if (optarg == NULL)
                {
                    error_log("Image path can not be NULL");
                    exit(1);
                }

                imageOperation.srcImagePath = optarg; 
                struct stat info;
                stat(optarg, &info);
                imageOperation.srcImageSize = info.st_size;
                debug_log("Source file size: %u\n", imageOperation.srcImageSize);
                break;  
            }
            
            case 'n':   
            {
                threadNum = atoi(optarg);
                break; 
            }
            
            case 't':
            {
                int type = atoi(optarg);
                if (type<0 || type>=INVALID_HELPER)
                {
                    error_log("Invalid library: %d", type);
                    exit(1);
                }
                
                imageHelperType = (ImageHelperType)type;
                break;
            }

            case 'h':   
            {
                printUsage(); 
                exit(0); 
            } 
        }   
    }

    ImageBenchmarker *benchmarker = new ImageBenchmarker();
    if(!benchmarker->initWorkers(threadNum, imageHelperType, imageOperation))
    {
        error_log("init benchmarker workers failed, threadNum: %d, imageHelperType: %d", threadNum, imageHelperType);
        exit(1);
    }

    benchmarker->startBenchmarker();

    delete benchmarker;
    benchmarker = NULL;
    return 0;
}
