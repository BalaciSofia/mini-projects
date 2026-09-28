#include "adminwindow.h"

#include <iostream>

#include "ui_adminwindow.h"
#include "updatedialog.h"
#include "adddialog.h"
#include "QMessageBox"
#include <QDebug>
#include <QShortcut>

adminwindow::adminwindow(Controller_admin &controller_admin,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminwindow)
    ,controller_admin(controller_admin)
{
    ui->setupUi(this);
    populateTable();
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z) , this, SLOT(on_undoButton_clicked()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y) , this, SLOT(on_redoButton_clicked()));
}

adminwindow::~adminwindow()
{
    delete ui;
}
void adminwindow::populateTable() {
        std::vector<Dog> dogs = this->controller_admin.get_dogs_controller();
        ui->tableWidget->setRowCount(dogs.size());
        for (int i = 0; i < dogs.size(); ++i) {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(dogs[i].get_name())));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(dogs[i].get_age())));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(dogs[i].get_breed())));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(dogs[i].get_photograph())));
        }

}

void adminwindow::on_addButton_clicked() {
    adddialog* dialog= new adddialog(this->controller_admin, this);
    dialog->exec();
    populateTable();
}

void adminwindow::on_removeButton_clicked() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        QString qName = ui->tableWidget->item(row, 0)->text();
        std::string name = qName.toStdString();
        try {
            std::cout << name << std::endl;
            this->controller_admin.Remove_Dog(name);
            populateTable();
        } catch (RepositoryError& e) {
            QMessageBox::critical(this, "Error", QString("Failed to remove dog: ") + e.what());
        }
    } else {
        QMessageBox::warning(this, "Warning", "Please select a row to remove.");
    }
}

void adminwindow::on_updateButton_clicked() {
    updatedialog* dialog = new updatedialog(this->controller_admin, this);
    dialog->exec();
    populateTable();
}

void adminwindow::on_undoButton_clicked() {
    this->controller_admin.undo();
    populateTable();
}

void adminwindow::on_redoButton_clicked() {
    this->controller_admin.redo();
    populateTable();
}