GXX34 = 1 
CXX = g++
VERSION=
CXXFLAG = -Wall -ggdb3 -O2 
CXXFLAG_R = -Wall -O2 -O3

DBCXXFLAG = $(CXXFLAG) -pthread

LINK_CXXFLAG = $(CXXFLAG) -Wl,-rpath,../../bin
LINK_CXXFLAG_R = $(CXXFLAG_R) -Wl,-rpath,../../bin

MCXXFLAG = -pthread $(LINK_CXXFLAG) $(DEFINE_SEL)

SRC_COMM = ImageHelper.cpp GraphicsMagickHelper.cpp OpenCvHelper.cpp ImageHelperFactory.cpp Worker.cpp ImageBenchmarker.cpp main.cpp

OBJ_COMM = $(SRC_COMM:.cpp=.o)
OBJ_COMM_M = $(SRC_COMM:.cpp=.mo)

INCLUDE += -I../include/GraphicsMagick -I../include/opencv2
LIB +=../bin/libGraphicsMagick.so ../bin/libGraphicsMagick++.so ../bin/libopencv_core.so.3.2 ../bin/libopencv_calib3d.so.3.2 ../bin/libopencv_features2d.so.3.2 ../bin/libopencv_flann.so.3.2 ../bin/libopencv_highgui.so.3.2 ../bin/libopencv_imgcodecs.so.3.2 ../bin/libopencv_imgproc.so.3.2 ../bin/libopencv_ml.so.3.2 ../bin/libopencv_objdetect.so.3.2 ../bin/libopencv_photo.so.3.2 ../bin/libopencv_shape.so.3.2 ../bin/libopencv_stitching.so.3.2 ../bin/libopencv_superres.so.3.2 ../bin/libopencv_videoio.so.3.2 ../bin/libopencv_video.so.3.2 ../bin/libopencv_videostab.so.3.2 -lrt

.SUFFIXES: .o .cpp
.cpp.o:
	$(CXX) $(DBCXXFLAG) $(INCLUDE) -c -o $@ $<

.SUFFIXES: .mo .cpp
.cpp.mo:
	$(CXX) $(DBCXXFLAG) -DMOCK $(INCLUDE) -c -o $@ $<

PROGRAM=imagebenchmarker

all: imagebenchmarker

Debug: imagebenchmarker

cleanDebug: imagebenchmarker
	rm -rf *.o

imagebenchmarker: $(OBJ_COMM) $(LIB) $(DLIB) 
	$(CXX) -Wl,-rpath ../lib -o ../bin/$@ $(MCXXFLAG) $(INCLUDE) -D__DEBUG $(OBJ_COMM) $(LIB) $(DLIB) `pkg-config opencv --cflags --libs`


depend:
	mkdep $(INCLUDE) $(SRC_COMM) $(CXXFLAG)

install:
	install $(PROGRAM) ../bin/

clean: 
	rm -f *.o
	rm -f *.ro
	rm -f $(PROGRAM)
	rm -f ../bin/$(PROGRAM)
