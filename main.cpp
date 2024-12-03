#include "masterview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

// #include <QApplication>
// #include <QMainWindow>
// #include <QToolBar>
// #include <QAction>
// #include <QWidget>
// #include <QWidgetAction>

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);

//     QMainWindow mainWindow;
//     QToolBar *toolBar = new QToolBar("Toolbar");

//     // 创建前进和后退按钮
//     QAction *backAction = new QAction("后退", &mainWindow);
//     QAction *forwardAction = new QAction("前进", &mainWindow);

//     // 添加后退按钮到工具栏
//     toolBar->addAction(backAction);

//     // 创建一个弹性 QWidget
//     QWidget *spacer = new QWidget();
//     spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

//     // 用 QWidgetAction 包装弹性 QWidget
//     QWidgetAction *spacerAction = new QWidgetAction(toolBar);
//     spacerAction->setDefaultWidget(spacer);

//     // 将弹性 QWidgetAction 添加到工具栏
//     toolBar->addAction(spacerAction);

//     // 添加前进按钮到工具栏
//     toolBar->addAction(forwardAction);

//     mainWindow.addToolBar(toolBar);
//     mainWindow.show();

//     return app.exec();
// }
