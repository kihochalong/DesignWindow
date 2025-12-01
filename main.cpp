#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Set dark theme with black background
    a.setStyleSheet(
        "QMainWindow { background-color: #1a1a1a; }"
        "QMenuBar { background-color: #2d2d2d; color: #ffffff; }"
        "QMenuBar::item { background-color: transparent; padding: 4px 12px; }"
        "QMenuBar::item:selected { background-color: #404040; }"
        "QMenuBar::item:pressed { background-color: #505050; }"
        "QMenu { background-color: #2d2d2d; color: #ffffff; border: 1px solid #404040; }"
        "QMenu::item { padding: 6px 25px 6px 20px; }"
        "QMenu::item:selected { background-color: #404040; }"
        "QMenu::separator { height: 1px; background: #404040; margin: 4px 10px; }"
        "QToolBar { background-color: #2d2d2d; border: none; spacing: 3px; padding: 2px; }"
        "QToolButton { background-color: transparent; color: #ffffff; padding: 5px; }"
        "QToolButton:hover { background-color: #404040; border-radius: 3px; }"
        "QToolButton:pressed { background-color: #505050; }"
        "QStatusBar { background-color: #2d2d2d; color: #ffffff; }"
        "QWidget { background-color: #1a1a1a; color: #ffffff; }"
    );
    
    MainWindow w;
    w.show();
    return a.exec();
}
