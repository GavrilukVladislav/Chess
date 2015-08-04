#-------------------------------------------------
#
# Project created by QtCreator 2015-07-07T21:18:43
#
#-------------------------------------------------

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChessGame
TEMPLATE = app


CONFIG += c++11

SOURCES += \
    src/boardmapper.cpp \
    src/chessboard.cpp \
    src/game.cpp \
    src/main.cpp \
    src/menuwidget.cpp \
    src/figurefactory.cpp \
    src/figures/pawn.cpp \
    src/figures/figure.cpp \
    src/figures/rook.cpp \
    src/figures/knight.cpp \
    src/figures/bishop.cpp \
    src/figures/queen.cpp \
    src/figures/king.cpp \
    src/figures/figurecontainer.cpp \
    src/chesscontext.cpp \
    src/savedataprovider.cpp

HEADERS  += \
    src/boardmapper.h \
    src/chessboard.h \
    src/defines.h \
    src/figure.h \
    src/game.h \
    src/menuwidget.h \
    src/figurefactory.h \
    src/figurelogic.h \
    src/figures/pawn.h \
    src/figures/figure.h \
    src/figures/rook.h \
    src/figures/knight.h \
    src/figures/bishop.h \
    src/figures/queen.h \
    src/figures/king.h \
    src/figures/figurecontainer.h \
    src/chesscontext.h \
    src/figures/chess_defines.h \
    src/savedataprovider.h

RESOURCES += \
    chessicon.qrc
