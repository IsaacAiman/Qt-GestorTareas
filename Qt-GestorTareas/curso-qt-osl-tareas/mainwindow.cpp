#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   combo = new QComboBox;
    ui->setupUi(this);


    //typeComboBox = new QComboBox();

    //Setup database
    ConecToDb(db_, "tareas");

    db_.exec("CREATE TABLE IF NOT EXISTS tareas ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
              "name TEXT,"
              "descripcion TEXT,"
              "date TEXT,"
              "done INTEGER,"
              "id_categ INTEGER"
              ");");

    db_.exec("CREATE TABLE IF NOT EXISTS categorias ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
              "name TEXT,"
              "descripcion TEXT"
              ");");

    db_.exec("CREATE TABLE IF NOT EXISTS etiquetas ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
              "name TEXT"
              ");");

    db_.exec("CREATE TABLE IF NOT EXISTS tareas_etiq ("
              "id_tarea INTEGER,"
              "id_etiq INTEGER"
              ");");



    connect(ui->actionNuevaTarea,   SIGNAL(triggered()),                this, SLOT(onAddTarea()));
    connect(ui->tblTareas,          SIGNAL(cellChanged(int,int)),       this, SLOT(onTareasCellChanged(int,int)));
    connect(ui->tblCateg,           SIGNAL(cellChanged(int,int)),       this, SLOT(onCategCellChanged(int,int)));
    connect(ui->comboCategoria,     SIGNAL(currentIndexChanged(int)),   this, SLOT(onLoadTareas()));
    connect(combo,                  SIGNAL(currentIndexChanged(int)),   this, SLOT(onLoadTareas()));
    connect(ui->actionNuevaCateg,   SIGNAL(triggered()),                this, SLOT(onAddCategoria()));

    addingTarea_ = false;

    //Obtenemos las categorias
    QSqlQuery q = db_.exec("SELECT * "
                           "FROM categorias;");


    while (q.next()) {
        //Añadimos la categoria al combo y como userData su ID
        ui->comboCategoria->addItem(GetField(q,"name").toString(), GetField(q,"id").toInt());

        //Añadimos la categoria a la tabla de categorias
        int rowNumber = ui->tblCateg->rowCount();
        ui->tblCateg->insertRow(rowNumber);
        QTableWidgetItem* item = new QTableWidgetItem(GetField(q, "name").toString());
        ui->tblCateg->setItem(rowNumber, 0, item);
        ui->tblCateg->item(rowNumber, 0)->setData(Qt::UserRole, GetField(q, "id"));
    }
    //Activamos el sorting en la tabla de categorias
    addingCateg_=false;
    ui->tblCateg->setSortingEnabled(true);

    ui->comboCategoria->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddTarea()
{
    qDebug() <<"asdasd";
    addingTarea_ = true;
    combo = new QComboBox;
    updateCombo(combo);


    ui->tblTareas->insertRow(ui->tblTareas->rowCount()); //rowCount cuenta el número de filas que tiene la tabla.
    QTableWidgetItem* item = new QTableWidgetItem("");
   // QWidget* item;
    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    item->setCheckState(Qt::Unchecked);
    ui->tblTareas->setItem(ui->tblTareas->rowCount()-1, 2, item);
    ui->tblTareas->setItem(ui->tblTareas->rowCount()-1, 0, new QTableWidgetItem(""));
    ui->tblTareas->setItem(ui->tblTareas->rowCount()-1, 1, new QTableWidgetItem(""));
    ui->tblTareas->setCellWidget(ui->tblTareas->rowCount()-1, 3, combo);
    //ui->tblCateg->item(row, 0)->setData(Qt::UserRole, query.lastInsertId());




    addingTarea_ = false;

}

void MainWindow::onAddCategoria()
{
    addingCateg_ = true;

    ui->tblCateg->insertRow(ui->tblCateg->rowCount()); //rowCount cuenta el número de filas que tiene la tabla.
    QTableWidgetItem* item = new QTableWidgetItem("");
    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    item->setCheckState(Qt::Unchecked);
    ui->tblCateg->setItem(ui->tblCateg->rowCount()-1, 0, new QTableWidgetItem(""));
    //txtCategDescr

    addingCateg_ = false;
}


void MainWindow::onTareasCellChanged(int row, int column)
{
    if (addingTarea_)
        return;

    ui->tblTareas->item(row, 2);
    //qDebug() << ui->tblTareas->cellWidget(row, 2);

    addingTarea_ = true;

    int checked = (ui->tblTareas->item(row, 2)->checkState() == Qt::Checked);

    QSqlQuery query;

    qDebug() << combo->currentData().toInt();


    if (ui->tblTareas->item(row, 0)->data(Qt::UserRole).isNull()) {
        query = db_.exec("INSERT INTO tareas (name, descripcion, date, done, id_categ) "
                 "VALUES ("+QString("'%1','%2','%3','%4','%5');" )\
                 .arg(ui->tblTareas->item(row, 0)->text())\
                 .arg(ui->txtTareaDescr->toPlainText())\
                 .arg(ui->tblTareas->item(row, 1)->text())\
                 .arg(checked)\
                 .arg(combo->currentData().toInt()));
       ui->tblTareas->item(row, 0)->setData(Qt::UserRole, query.lastInsertId());
    } else {
        query = db_.exec("UPDATE tareas "
                 "SET "+QString("name='%1',descripcion='%2',date='%3',done='%4',id_categ='%5' " )\
                 .arg(ui->tblTareas->item(row, 0)->text())\
                 .arg(ui->txtTareaDescr->toPlainText())\
                 .arg(ui->tblTareas->item(row, 1)->text())\
                 .arg(checked)\
                 .arg(combo->currentData().toInt()) +
                 "WHERE id = " + ui->tblTareas->item(row, 0)->data(Qt::UserRole).toString() + ";");
    }



    addingTarea_ = false;
}


void MainWindow::onCategCellChanged(int row, int column)
{
    if (addingCateg_)
        return;

    addingCateg_ = true;

    QSqlQuery query;

    if (ui->tblCateg->item(row, 0)->data(Qt::UserRole).isNull()) {
        query = db_.exec("INSERT INTO categorias (name, descripcion) "
                 "VALUES ("+QString("'%1','%2');" )\
                 .arg(ui->tblCateg->item(row, 0)->text())\
                 .arg(ui->txtCategDescr->toPlainText()));
        ui->tblCateg->item(row, 0)->setData(Qt::UserRole, query.lastInsertId());

    } else {
        query = db_.exec("UPDATE categorias "
                 "SET "+QString("name='%1',descripcion='%2'")\
                 .arg(ui->tblCateg->item(row, 0)->text())\
                 .arg(ui->txtCategDescr->toPlainText()) +
                 "WHERE id = " + ui->tblCateg->item(row, 0)->data(Qt::UserRole).toString() + ";");
    }

    //actualizamos el combo malpario
    ui->comboCategoria->clear();
    QSqlQuery q = db_.exec("SELECT * "
                           "FROM categorias;");

    while (q.next()) {
        //Añadimos la categoria al combo y como userData su ID
        ui->comboCategoria->addItem(GetField(q,"name").toString(), GetField(q,"id").toInt());
    }

 //   ui->comboCategoria->addItem(ui->tblCateg->item(row, 0)->text(), ui->tblCateg->item(row, 0)->data(Qt::UserRole).toString());
    addingCateg_ = false;
}




void MainWindow::onLoadTareas()
{
    addingTarea_ = true;

    while (ui->tblTareas->rowCount())
        ui->tblTareas->removeRow(0);

    //Obtenemos las tareas
    QSqlQuery q = db_.exec("SELECT * "
                 "FROM tareas "
                 "WHERE id_categ = " + ui->comboCategoria->currentData().toString());
    QSqlQuery h = db_.exec("SELECT * "
                           "FROM categorias"
                           "WHERE id = " + ui->comboCategoria->currentData().toString());

    while (q.next()) {
        //Añadimos la tarea a la tabla de categorias
        int rowNumber = ui->tblTareas->rowCount();
        int id = GetField(q, "id").toInt();
        ui->tblTareas->insertRow(rowNumber);

        QTableWidgetItem* item = new QTableWidgetItem(GetField(q, "name").toString());
        item->setData(Qt::UserRole, id);
        ui->tblTareas->setItem(rowNumber, 0, item);

        ui->tblTareas->setItem(rowNumber, 1, new QTableWidgetItem(GetField(q, "date").toString()));

        item = new QTableWidgetItem("");
        item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        if (GetField(q, "done").toInt())
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
        ui->tblTareas->setItem(rowNumber, 2, item);

        ui->tblTareas->setItem(rowNumber, 3, new QTableWidgetItem(GetField(h, "name").toString()));
    }
    //Activamos el sorting en la tabla de categorias.

    ui->tblTareas->setSortingEnabled(true);
    addingTarea_ = false;
}

void MainWindow::updateCombo(QComboBox *combo){

    QSqlQuery q = db_.exec("SELECT * "
                           "FROM categorias;");

    while (q.next()) {
        //Añadimos la categoria al combo y como userData su ID
        combo->addItem(GetField(q,"name").toString(), GetField(q,"id").toInt());
    }


}
