/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevaTarea;
    QAction *actionNuevaCateg;
    QAction *actionNuevaEtiq;
    QAction *actionSalir;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QTabWidget *TabTareas;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboEtiqueta;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QComboBox *comboCategoria;
    QTableWidget *tblTareas;
    QTextEdit *txtTareaDescr;
    QWidget *TabCategorias;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QTableWidget *tblCateg;
    QTextEdit *txtCategDescr;
    QWidget *TabEtiquetas;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QTableWidget *tblEtiq;
    QMenuBar *menubar;
    QMenu *menuTareas;
    QMenu *menuCategorias;
    QMenu *menuEtiquetas;
    QMenu *menuArchivo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionNuevaTarea = new QAction(MainWindow);
        actionNuevaTarea->setObjectName(QStringLiteral("actionNuevaTarea"));
        actionNuevaCateg = new QAction(MainWindow);
        actionNuevaCateg->setObjectName(QStringLiteral("actionNuevaCateg"));
        actionNuevaEtiq = new QAction(MainWindow);
        actionNuevaEtiq->setObjectName(QStringLiteral("actionNuevaEtiq"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        TabTareas = new QTabWidget(centralwidget);
        TabTareas->setObjectName(QStringLiteral("TabTareas"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        comboEtiqueta = new QComboBox(groupBox_2);
        comboEtiqueta->setObjectName(QStringLiteral("comboEtiqueta"));

        verticalLayout_4->addWidget(comboEtiqueta);


        verticalLayout_5->addLayout(verticalLayout_4);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboCategoria = new QComboBox(groupBox);
        comboCategoria->setObjectName(QStringLiteral("comboCategoria"));

        verticalLayout->addWidget(comboCategoria);


        verticalLayout_3->addLayout(verticalLayout);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        tblTareas = new QTableWidget(tab);
        if (tblTareas->columnCount() < 4)
            tblTareas->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblTareas->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblTareas->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblTareas->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblTareas->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblTareas->setObjectName(QStringLiteral("tblTareas"));

        gridLayout->addWidget(tblTareas, 1, 0, 1, 2);

        txtTareaDescr = new QTextEdit(tab);
        txtTareaDescr->setObjectName(QStringLiteral("txtTareaDescr"));
        txtTareaDescr->setMaximumSize(QSize(16777215, 200));

        gridLayout->addWidget(txtTareaDescr, 2, 0, 1, 2);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        TabTareas->addTab(tab, QString());
        TabCategorias = new QWidget();
        TabCategorias->setObjectName(QStringLiteral("TabCategorias"));
        gridLayout_4 = new QGridLayout(TabCategorias);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tblCateg = new QTableWidget(TabCategorias);
        if (tblCateg->columnCount() < 1)
            tblCateg->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblCateg->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        tblCateg->setObjectName(QStringLiteral("tblCateg"));

        gridLayout_2->addWidget(tblCateg, 0, 0, 1, 1);

        txtCategDescr = new QTextEdit(TabCategorias);
        txtCategDescr->setObjectName(QStringLiteral("txtCategDescr"));
        txtCategDescr->setMaximumSize(QSize(16777215, 200));

        gridLayout_2->addWidget(txtCategDescr, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        TabTareas->addTab(TabCategorias, QString());
        TabEtiquetas = new QWidget();
        TabEtiquetas->setObjectName(QStringLiteral("TabEtiquetas"));
        gridLayout_7 = new QGridLayout(TabEtiquetas);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tblEtiq = new QTableWidget(TabEtiquetas);
        if (tblEtiq->columnCount() < 1)
            tblEtiq->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblEtiq->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        tblEtiq->setObjectName(QStringLiteral("tblEtiq"));

        gridLayout_6->addWidget(tblEtiq, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        TabTareas->addTab(TabEtiquetas, QString());

        gridLayout_3->addWidget(TabTareas, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuTareas = new QMenu(menubar);
        menuTareas->setObjectName(QStringLiteral("menuTareas"));
        menuCategorias = new QMenu(menubar);
        menuCategorias->setObjectName(QStringLiteral("menuCategorias"));
        menuEtiquetas = new QMenu(menubar);
        menuEtiquetas->setObjectName(QStringLiteral("menuEtiquetas"));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuTareas->menuAction());
        menubar->addAction(menuCategorias->menuAction());
        menubar->addAction(menuEtiquetas->menuAction());
        menuTareas->addAction(actionNuevaTarea);
        menuCategorias->addAction(actionNuevaCateg);
        menuEtiquetas->addAction(actionNuevaEtiq);
        menuArchivo->addAction(actionSalir);

        retranslateUi(MainWindow);
        QObject::connect(actionSalir, SIGNAL(triggered()), MainWindow, SLOT(close()));

        TabTareas->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNuevaTarea->setText(QApplication::translate("MainWindow", "Nueva", 0));
        actionNuevaCateg->setText(QApplication::translate("MainWindow", "Nueva", 0));
        actionNuevaEtiq->setText(QApplication::translate("MainWindow", "Nueva", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Etiqueta", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Categoria", 0));
        QTableWidgetItem *___qtablewidgetitem = tblTareas->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Tarea", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tblTareas->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Fecha", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tblTareas->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Hecho", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tblTareas->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Categor\303\255a", 0));
        TabTareas->setTabText(TabTareas->indexOf(tab), QApplication::translate("MainWindow", "Tareas", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tblCateg->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Categoria", 0));
        TabTareas->setTabText(TabTareas->indexOf(TabCategorias), QApplication::translate("MainWindow", "Categorias", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tblEtiq->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Etiqueta", 0));
        TabTareas->setTabText(TabTareas->indexOf(TabEtiquetas), QApplication::translate("MainWindow", "Etiquetas", 0));
        menuTareas->setTitle(QApplication::translate("MainWindow", "Tareas", 0));
        menuCategorias->setTitle(QApplication::translate("MainWindow", "Categorias", 0));
        menuEtiquetas->setTitle(QApplication::translate("MainWindow", "Etiquetas", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
