#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    isDarkTheme(true)
{
    ui->setupUi(this);
    
    // Create theme toggle button and place it next to 'Waveform Analysis' menu
    QPushButton *themeButton = new QPushButton("Switch Theme", this);
    themeButton->setObjectName("themeButton");
    ui->menubar->setCornerWidget(themeButton, Qt::TopRightCorner);
    
    connect(themeButton, &QPushButton::clicked, this, &MainWindow::toggleTheme);
    
    // Apply initial dark theme
    applyTheme(isDarkTheme);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleTheme()
{
    isDarkTheme = !isDarkTheme;
    applyTheme(isDarkTheme);
}

void MainWindow::applyTheme(bool dark)
{
    QString styleSheet;
    
    if (dark) {
        // Dark theme with black background
        styleSheet = 
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
            "QPushButton { background-color: #404040; color: #ffffff; padding: 5px 15px; border: 1px solid #505050; border-radius: 3px; }"
            "QPushButton:hover { background-color: #505050; }"
            "QPushButton:pressed { background-color: #606060; }";
    } else {
        // Light theme with white background
        styleSheet = 
            "QMainWindow { background-color: #ffffff; }"
            "QMenuBar { background-color: #f0f0f0; color: #000000; }"
            "QMenuBar::item { background-color: transparent; padding: 4px 12px; }"
            "QMenuBar::item:selected { background-color: #d0d0d0; }"
            "QMenuBar::item:pressed { background-color: #c0c0c0; }"
            "QMenu { background-color: #f0f0f0; color: #000000; border: 1px solid #c0c0c0; }"
            "QMenu::item { padding: 6px 25px 6px 20px; }"
            "QMenu::item:selected { background-color: #d0d0d0; }"
            "QMenu::separator { height: 1px; background: #c0c0c0; margin: 4px 10px; }"
            "QToolBar { background-color: #f0f0f0; border: none; spacing: 3px; padding: 2px; }"
            "QToolButton { background-color: transparent; color: #000000; padding: 5px; }"
            "QToolButton:hover { background-color: #d0d0d0; border-radius: 3px; }"
            "QToolButton:pressed { background-color: #c0c0c0; }"
            "QStatusBar { background-color: #f0f0f0; color: #000000; }"
            "QWidget { background-color: #ffffff; color: #000000; }"
            "QPushButton { background-color: #e0e0e0; color: #000000; padding: 5px 15px; border: 1px solid #c0c0c0; border-radius: 3px; }"
            "QPushButton:hover { background-color: #d0d0d0; }"
            "QPushButton:pressed { background-color: #c0c0c0; }";
    }
    
    qApp->setStyleSheet(styleSheet);
}
