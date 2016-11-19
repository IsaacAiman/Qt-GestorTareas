#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "dbconnection.h"
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateCombo(QComboBox* combo);
    void onAddTarea();
    void onAddCategoria();
    void onTareasCellChanged(int row, int column);
    void onCategCellChanged(int row ,int column);
    void onLoadTareas();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db_;
    bool addingTarea_;
    bool addingCateg_;

};

#endif // MAINWINDOW_H
