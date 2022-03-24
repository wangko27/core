QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Widgets/CFileTreeWidget.cpp \
    Widgets/CFileViewWidget.cpp \
    Widgets/CRecordCreator.cpp \
    Widgets/CStatisticsWidget.cpp \
    Widgets/Common/CCustomItem.cpp \
    Widgets/Common/CEditItemWidget.cpp \
    Widgets/Common/CFileTreeView.cpp \
    Widgets/Common/CItemWidget.cpp \
    Widgets/Common/CMapModel.cpp \
    Widgets/Common/CTextEditDelegate.cpp \
    Widgets/Common/CXMLHighlighter.cpp \
    Widgets/RecordWidgets/CCIEXYZTripleWidget.cpp \
    Widgets/RecordWidgets/CColorWidget.cpp \
    Widgets/RecordWidgets/CEmptyWidget.cpp \
    Widgets/RecordWidgets/CExtSelectClipRgnWidget.cpp \
    Widgets/RecordWidgets/CExtTextOutWidget.cpp \
    Widgets/RecordWidgets/CFillRgnWidget.cpp \
    Widgets/RecordWidgets/CFormWidget.cpp \
    Widgets/RecordWidgets/CFrameRgnWidget.cpp \
    Widgets/RecordWidgets/CGradientFillWidget.cpp \
    Widgets/RecordWidgets/CInvertRgnWidget.cpp \
    Widgets/RecordWidgets/CLogBrushExWidget.cpp \
    Widgets/RecordWidgets/CLogColorSpaceWidget.cpp \
    Widgets/RecordWidgets/CLogFontExDvWidget.cpp \
    Widgets/RecordWidgets/CLogPaletteWidget.cpp \
    Widgets/RecordWidgets/CLogPenWidget.cpp \
    Widgets/RecordWidgets/CPaintRgnWidget.cpp \
    Widgets/RecordWidgets/CPaletteEntriesWidget.cpp \
    Widgets/RecordWidgets/CPixelFormatDescriptorWidget.cpp \
    Widgets/RecordWidgets/CPointWidget.cpp \
    Widgets/RecordWidgets/CPointsWidget.cpp \
    Widgets/RecordWidgets/CPolyDrawWidget.cpp \
    Widgets/RecordWidgets/CPolyTextOutWidget.cpp \
    Widgets/RecordWidgets/CPolyWidget.cpp \
    Widgets/RecordWidgets/CRectangleWidget.cpp \
    Widgets/RecordWidgets/CSizeWidget.cpp \
    Widgets/RecordWidgets/CSmallTextOutWidget.cpp \
    Widgets/RecordWidgets/CXFormWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    Widgets/CFileTreeWidget.h \
    Widgets/CFileViewWidget.h \
    Widgets/CRecordCreator.h \
    Widgets/CStatisticsWidget.h \
    Widgets/Common/CCustomItem.h \
    Widgets/Common/CEditItemWidget.h \
    Widgets/Common/CFileTreeView.h \
    Widgets/Common/CItemWidget.h \
    Widgets/Common/CMapModel.h \
    Widgets/Common/CTextEditDelegate.h \
    Widgets/Common/CXMLHighlighter.h \
    Widgets/RecordWidgets/CCIEXYZTripleWidget.h \
    Widgets/RecordWidgets/CColorWidget.h \
    Widgets/RecordWidgets/CEmptyWidget.h \
    Widgets/RecordWidgets/CExtSelectClipRgnWidget.h \
    Widgets/RecordWidgets/CExtTextOutWidget.h \
    Widgets/RecordWidgets/CFillRgnWidget.h \
    Widgets/RecordWidgets/CFormWidget.h \
    Widgets/RecordWidgets/CFrameRgnWidget.h \
    Widgets/RecordWidgets/CGradientFillWidget.h \
    Widgets/RecordWidgets/CInvertRgnWidget.h \
    Widgets/RecordWidgets/CLogBrushExWidget.h \
    Widgets/RecordWidgets/CLogColorSpaceWidget.h \
    Widgets/RecordWidgets/CLogFontExDvWidget.h \
    Widgets/RecordWidgets/CLogPaletteWidget.h \
    Widgets/RecordWidgets/CLogPenWidget.h \
    Widgets/RecordWidgets/CPaintRgnWidget.h \
    Widgets/RecordWidgets/CPaletteEntriesWidget.h \
    Widgets/RecordWidgets/CPixelFormatDescriptorWidget.h \
    Widgets/RecordWidgets/CPointWidget.h \
    Widgets/RecordWidgets/CPointsWidget.h \
    Widgets/RecordWidgets/CPolyDrawWidget.h \
    Widgets/RecordWidgets/CPolyTextOutWidget.h \
    Widgets/RecordWidgets/CPolyWidget.h \
    Widgets/RecordWidgets/CRectangleWidget.h \
    Widgets/RecordWidgets/CSharedWidget.h \
    Widgets/RecordWidgets/CSizeWidget.h \
    Widgets/RecordWidgets/CSmallTextOutWidget.h \
    Widgets/RecordWidgets/CXFormWidget.h \
    Widgets/RecordWidgets/Common.h

FORMS += \
    Ui/EditItem.ui \
    Ui/MainWindow.ui \
    Ui/RecordCreator.ui \
    Ui/Statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CORE_ROOT_DIR = $$PWD/../../../../..
PWD_ROOT_DIR = $$PWD
include($$CORE_ROOT_DIR/Common/base.pri)
include($$CORE_ROOT_DIR/Common/3dParty/icu/icu.pri)

ADD_DEPENDENCY(kernel, graphics, UnicodeConverter)

SOURCES += ../../../../fontengine/ApplicationFontsWorker.cpp

DESTDIR = $$PWD_ROOT_DIR/build/$$CORE_BUILDS_PLATFORM_PREFIX/$$CORE_BUILDS_CONFIGURATION_PREFIX
