﻿#ifndef NAVLISTVIEW_H
#define NAVLISTVIEW_H

/**
 * 树状导航栏控件 作者:feiyangqingyun(QQ:517216493) 2016-10-28
 * 本控件来源于网络(原作者:sssooonnnggg(http://www.qtcn.org/bbs/read-htm-tid-58274-ds-1-page-1.html#163557))
 * 1:合并成一个文件
 * 2:隐藏多余接口,只保留readData函数接口
 * 3:修正重复加载数据BUG及关闭时有时候崩溃的BUG
 * 4:修正当范围值中最小值为负数时的bug
 * 5:增加默认支持鼠标悬停
 * 6:增加一些完整性校验
 * 7:增加设置各种颜色
 * 8:+-伸缩图形改成绘制,同时支持+-图形及三角形图形
 * 9:增加setData数据接口,使之同时支持字符串链表作为数据源
 * 10:增加设置分割线条是否可见
 * 11:增加设置伸缩图片采用何种颜色
 * 12:改进分割线条高度
 * 13:将显示未读条数部分改成提示信息,可以是字符串
 * 14:可设置为单击或者双击展开父节点
 */

#include <QStyledItemDelegate>
#include <QAbstractListModel>
#include <QListView>

class NavListView;

class NavDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    NavDelegate(QObject *parent);
    ~NavDelegate();

protected:
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const ;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    NavListView *nav;
    QFont iconFont;
};


class NavModel : public QAbstractListModel
{
    Q_OBJECT
public:
    NavModel(QObject *parent);
    ~NavModel();

public:
    struct TreeNode {
        QString label;
        int level;
        bool collapse;
        bool theLast;
        QString info;
        QList<TreeNode *> children;
    };

    struct ListNode {
        QString label;
        TreeNode *treeNode;
    };

protected:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QList<TreeNode *> treeNode;
    QList<ListNode> listNode;

public Q_SLOTS:
    void readData(const QString &path);
    void setData(const QStringList &listItem);
    void collapse(const QModelIndex &index);

private:
    void refreshList();
};

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT NavListView : public QListView
#else
class NavListView : public QListView
#endif

{
    Q_OBJECT
    Q_ENUMS(IcoStyle)

    Q_PROPERTY(bool infoVisible READ getInfoVisible WRITE setInfoVisible)
    Q_PROPERTY(bool lineVisible READ getLineVisible WRITE setLineVisible)
    Q_PROPERTY(bool icoColorBg READ getIcoColorBg WRITE setIcoColorBg)

    Q_PROPERTY(IcoStyle icoStyle READ getIcoStyle WRITE setIcoStyle)
    Q_PROPERTY(FoldMode foldMode READ getFoldMode WRITE setFoldMode)

    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor bgNormalColor READ getBgNormalColor WRITE setBgNormalColor)
    Q_PROPERTY(QColor bgSelectedColor READ getBgSelectedColor WRITE setBgSelectedColor)
    Q_PROPERTY(QColor bgHoverColor READ getBgHoverColor WRITE setBgHoverColor)

    Q_PROPERTY(QColor textNormalColor READ getTextNormalColor WRITE setTextNormalColor)
    Q_PROPERTY(QColor textSelectedColor READ getTextSelectedColor WRITE setTextSelectedColor)
    Q_PROPERTY(QColor textHoverColor READ getTextHoverColor WRITE setTextHoverColor)

public:
    enum IcoStyle {
        IcoStyle_Cross = 0,         //十字形状
        IcoStyle_Triangle = 1       //三角形状
    };

    enum FoldMode {
        FoldMode_SingleClick = 0,   //单击模式
        FoldMode_DoubleClick = 1    //双击模式
    };

    NavListView(QWidget *parent = 0);
    ~NavListView();

private:
    NavModel *model;
    NavDelegate *delegate;

    bool infoVisible;               //是否显示提示信息
    bool lineVisible;               //是否显示分割线条
    bool icoColorBg;                //伸缩图片是否使用颜色

    IcoStyle icoStyle;              //图标样式
    FoldMode foldMode;              //父节点展开模式 单击/双击

    QColor lineColor;               //线条颜色
    QColor bgNormalColor;           //正常背景色
    QColor bgSelectedColor;         //选中背景色
    QColor bgHoverColor;            //悬停背景色

    QColor textNormalColor;         //正常文字颜色
    QColor textSelectedColor;       //选中文字颜色
    QColor textHoverColor;          //悬停文字颜色

public:
    bool getInfoVisible()           const;
    bool getLineVisible()           const;
    bool getIcoColorBg()            const;

    IcoStyle getIcoStyle()          const;
    FoldMode getFoldMode()          const;

    QColor getLineColor()           const;
    QColor getBgNormalColor()       const;
    QColor getBgSelectedColor()     const;
    QColor getBgHoverColor()        const;

    QColor getTextNormalColor()     const;
    QColor getTextSelectedColor()   const;
    QColor getTextHoverColor()      const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //读取xml文件数据
    void readData(const QString &xmlPath);
    //设置数据集合
    void setData(const QStringList &listItem);

    //设置是否显示提示信息
    void setInfoVisible(bool infoVisible);

    //设置是否显示间隔线条
    void setLineVisible(bool lineVisible);

    //设置伸缩图片是否采用背景色
    void setIcoColorBg(bool icoColorBg);

    //设置伸缩图片样式
    void setIcoStyle(const IcoStyle &icoStyle);

    //设置父节点展开模式
    void setFoldMode(const FoldMode &foldMode);

    //设置各种前景色背景色选中色
    void setLineColor(const QColor &lineColor);

    void setBgNormalColor(const QColor &bgNormalColor);
    void setBgSelectedColor(const QColor &bgSelectedColor);
    void setBgHoverColor(const QColor &bgHoverColor);

    void setTextNormalColor(const QColor &textNormalColor);
    void setTextSelectedColor(const QColor &textSelectedColor);
    void setTextHoverColor(const QColor &textHoverColor);
};

#endif // NAVLISTVIEW_H
