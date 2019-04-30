#############################################################################
# Makefile for building: app
# Generated by qmake (2.01a) (Qt 4.8.7) on: ?? 4? 30 20:32:00 2019
# Project:  traffic_light.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -o Makefile traffic_light.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -fno-plt -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -fno-plt -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		myqt.cpp \
		led.c \
		card_ctrl.c \
		tty.c \
		drv-v4l.c \
		grab-ng.c \
		struct-dump.c \
		struct-v4l.c \
		v4l.c moc_myqt.cpp
OBJECTS       = main.o \
		myqt.o \
		led.o \
		card_ctrl.o \
		tty.o \
		drv-v4l.o \
		grab-ng.o \
		struct-dump.o \
		struct-v4l.o \
		v4l.o \
		moc_myqt.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		traffic_light.pro
QMAKE_TARGET  = app
DESTDIR       = 
TARGET        = app

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_traffic_light.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: traffic_light.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -o Makefile traffic_light.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile traffic_light.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/app1.0.0 || $(MKDIR) .tmp/app1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/app1.0.0/ && $(COPY_FILE) --parents myqt.h led.h card_ctrl.h tty.h fb.h grab-ng.h struct-dump.h struct-v4l.h v4l.h frame_handler.h .tmp/app1.0.0/ && $(COPY_FILE) --parents main.cpp myqt.cpp led.c card_ctrl.c tty.c drv-v4l.c grab-ng.c struct-dump.c struct-v4l.c v4l.c .tmp/app1.0.0/ && $(COPY_FILE) --parents traffic_light.ui .tmp/app1.0.0/ && (cd `dirname .tmp/app1.0.0` && $(TAR) app1.0.0.tar app1.0.0 && $(COMPRESS) app1.0.0.tar) && $(MOVE) `dirname .tmp/app1.0.0`/app1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/app1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_myqt.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_myqt.cpp
moc_myqt.cpp: ui_traffic_light.h \
		frame_handler.h \
		grab-ng.h \
		myqt.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) myqt.h -o moc_myqt.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_traffic_light.h
compiler_uic_clean:
	-$(DEL_FILE) ui_traffic_light.h
ui_traffic_light.h: traffic_light.ui
	/usr/lib/qt4/bin/uic traffic_light.ui -o ui_traffic_light.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp myqt.h \
		ui_traffic_light.h \
		frame_handler.h \
		grab-ng.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

myqt.o: myqt.cpp myqt.h \
		ui_traffic_light.h \
		frame_handler.h \
		grab-ng.h \
		led.h \
		tty.h \
		card_ctrl.h \
		v4l.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o myqt.o myqt.cpp

led.o: led.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o led.o led.c

card_ctrl.o: card_ctrl.c card_ctrl.h \
		tty.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o card_ctrl.o card_ctrl.c

tty.o: tty.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o tty.o tty.c

drv-v4l.o: drv-v4l.c grab-ng.h \
		struct-dump.h \
		struct-v4l.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o drv-v4l.o drv-v4l.c

grab-ng.o: grab-ng.c grab-ng.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o grab-ng.o grab-ng.c

struct-dump.o: struct-dump.c struct-dump.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o struct-dump.o struct-dump.c

struct-v4l.o: struct-v4l.c struct-dump.h \
		struct-v4l.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o struct-v4l.o struct-v4l.c

v4l.o: v4l.c v4l.h \
		frame_handler.h \
		grab-ng.h \
		fb.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o v4l.o v4l.c

moc_myqt.o: moc_myqt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_myqt.o moc_myqt.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

