#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void toggleTheme();
    void openFile();
    void saveFile();

private:
    Ui::MainWindow *ui;
    bool isDarkTheme;
    void applyTheme(bool dark);
};

#endif // MAINWINDOW_H
