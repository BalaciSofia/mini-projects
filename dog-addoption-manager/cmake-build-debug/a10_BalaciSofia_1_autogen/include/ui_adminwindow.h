/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminwindow
{
public:
    QTableWidget *tableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *updateButton;
    QPushButton *undoButton;
    QPushButton *redoButton;

    void setupUi(QDialog *adminwindow)
    {
        if (adminwindow->objectName().isEmpty())
            adminwindow->setObjectName("adminwindow");
        adminwindow->resize(700, 500);
        tableWidget = new QTableWidget(adminwindow);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setBackground(QColor(255, 194, 203));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QBrush brush(QColor(255, 194, 203, 255));
        brush.setStyle(Qt::BrushStyle::NoBrush);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        __qtablewidgetitem1->setBackground(QColor(255, 255, 255));
        __qtablewidgetitem1->setForeground(brush);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        __qtablewidgetitem2->setBackground(QColor(255, 194, 203));
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QBrush brush1(QColor(255, 194, 203, 255));
        brush1.setStyle(Qt::BrushStyle::NoBrush);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        __qtablewidgetitem3->setForeground(brush1);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(-1, 9, 691, 431));
        tableWidget->setAutoFillBackground(false);
        tableWidget->setLineWidth(5);
        tableWidget->setDragEnabled(false);
        tableWidget->setSortingEnabled(false);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);
        widget = new QWidget(adminwindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(9, 430, 681, 61));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(widget);
        addButton->setObjectName("addButton");
        addButton->setFont(font);

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(widget);
        removeButton->setObjectName("removeButton");
        removeButton->setFont(font);

        horizontalLayout->addWidget(removeButton);

        updateButton = new QPushButton(widget);
        updateButton->setObjectName("updateButton");
        updateButton->setFont(font);

        horizontalLayout->addWidget(updateButton);

        undoButton = new QPushButton(widget);
        undoButton->setObjectName("undoButton");
        undoButton->setFont(font);

        horizontalLayout->addWidget(undoButton);

        redoButton = new QPushButton(widget);
        redoButton->setObjectName("redoButton");
        redoButton->setFont(font);

        horizontalLayout->addWidget(redoButton);


        retranslateUi(adminwindow);

        QMetaObject::connectSlotsByName(adminwindow);
    } // setupUi

    void retranslateUi(QDialog *adminwindow)
    {
        adminwindow->setWindowTitle(QCoreApplication::translate("adminwindow", "Admin", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("adminwindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("adminwindow", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("adminwindow", "Breed", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("adminwindow", "Photograph", nullptr));
        addButton->setText(QCoreApplication::translate("adminwindow", "Add dog", nullptr));
        removeButton->setText(QCoreApplication::translate("adminwindow", "Remove dog", nullptr));
        updateButton->setText(QCoreApplication::translate("adminwindow", "Update dog", nullptr));
        undoButton->setText(QCoreApplication::translate("adminwindow", "Undo", nullptr));
        redoButton->setText(QCoreApplication::translate("adminwindow", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminwindow: public Ui_adminwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
