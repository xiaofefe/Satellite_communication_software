#pragma execution_character_set("utf-8")

#include "navlistview.h"
#include "qfontdatabase.h"
#include "qpainter.h"
#include "qfile.h"
#include "qdom.h"
#include "qdebug.h"

NavDelegate::NavDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    nav = (NavListView *)parent;

    //引入图形字体
    int fontId = QFontDatabase::addApplicationFont(":/images/fontawesome-webfont.ttf");
    QStringList fontName = QFontDatabase::applicationFontFamilies(fontId);

    if (fontName.count() > 0) {
        iconFont = QFont(fontName.at(0));
    } else {
        qDebug() << "load fontawesome-webfont.ttf error";
    }
}

NavDelegate::~NavDelegate()
{

}

QSize NavDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //QSize size(50, 28);
    QSize size(50, 28);
    NavModel::TreeNode *node = (NavModel::TreeNode *)index.data(Qt::UserRole).toUInt();

    if (node->level == 1) {
        size = QSize(50, 35);
    } else {
        size = QSize(50, 28);
    }

    return size;
}

void NavDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->setRenderHint(QPainter::Antialiasing);
    NavModel::TreeNode *node = (NavModel::TreeNode *)index.data(Qt::UserRole).toUInt();

    //绘制背景
    QColor colorBg;

    if (option.state & QStyle::State_Selected) {
        colorBg = nav->getBgSelectedColor();
    } else if (option.state & QStyle::State_MouseOver) {
        colorBg = nav->getBgHoverColor();
    } else {
        colorBg = nav->getBgNormalColor();
    }

    painter->fillRect(option.rect, colorBg);

    //绘制指示器
    if (node->children.size() != 0) {
        QPixmap pix(16, 16);
        pix.fill(Qt::transparent);
        QPainter p(&pix);
        p.setRenderHint(QPainter::Antialiasing);
        p.setFont(iconFont);

        //根据采用的背景色判断
        QColor icoColorSelected;
        QColor icoColorNormal;
        QColor icoColorHover;

        if (nav->getIcoColorBg()) {
            icoColorSelected = nav->getBgNormalColor();
            icoColorNormal = nav->getBgSelectedColor();
            icoColorHover = nav->getBgNormalColor();
        } else {
            icoColorSelected = nav->getTextSelectedColor();
            icoColorNormal = nav->getTextNormalColor();
            icoColorHover = nav->getTextHoverColor();
        }

        if (option.state & QStyle::State_Selected) {
            p.setPen(icoColorSelected);
        } else if (option.state & QStyle::State_MouseOver) {
            p.setPen(icoColorHover);
        } else {
            p.setPen(icoColorNormal);
        }

        QFont font = p.font();
        if (nav->getIcoStyle() == NavListView::IcoStyle_Cross) {
            font.setPixelSize(13);
            p.setFont(font);

            //绘制 + - 指示器
            if (node->collapse) {
                p.drawText(pix.rect(), Qt::AlignCenter, QChar(0xf067));
            } else {
                p.drawText(pix.rect(), Qt::AlignCenter, QChar(0xf068));
            }
        } else if (nav->getIcoStyle() == NavListView::IcoStyle_Triangle) {
            font.setPixelSize(18);
            p.setFont(font);

            //绘制三角形指示器
            if (node->collapse) {
                p.drawText(pix.rect(), Qt::AlignCenter, QChar(0xf0da));
            } else {
                p.drawText(pix.rect(), Qt::AlignCenter, QChar(0xf0d7));
            }
        }

        QPixmap img(pix);
        QRect targetRect = option.rect;
        targetRect.setWidth(16);
        targetRect.setHeight(16);
        QPoint c = option.rect.center();
        c.setX(12);
        targetRect.moveCenter(c);
        painter->drawPixmap(targetRect, img, img.rect());
    }

    //绘制条目文字
    QColor colorText;

    if (option.state & QStyle::State_Selected) {
        colorText = nav->getTextSelectedColor();
    } else if (option.state & QStyle::State_MouseOver) {
        colorText = nav->getTextHoverColor();
    } else {
        colorText = nav->getTextNormalColor();
    }

    painter->setPen(QPen(colorText));

    //绘制文字离左边的距离
    int margin = 25;

    if (node->level == 2) {
        margin = 45;
    }

    QRect rect = option.rect;
    rect.setWidth(rect.width() - margin);
    rect.setX(rect.x() + margin);

    QFont font;
    font.setPixelSize(12);
    painter->setFont(font);
    painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, index.data(Qt::DisplayRole).toString());

    //绘制分隔符线条
    if (nav->getLineVisible()) {
        painter->setPen(QPen(nav->getLineColor(), 1));

        if (node->level == 1 || (node->level == 2 && node->theLast)) {
            painter->drawLine(QPointF(option.rect.x(), option.rect.y() + option.rect.height()),
                              QPointF(option.rect.x() + option.rect.width(), option.rect.y() + option.rect.height()));
        }
    }

    //绘制提示信息
    QString recordInfo = node->info;

    //如果不需要显示提示信息或者提示信息为空则返回
    if (!nav->getInfoVisible() || recordInfo.isEmpty()) {
        return;
    }

    QPen decorationPen(option.state & QStyle::State_Selected ? nav->getBgSelectedColor() : nav->getTextSelectedColor());
    QBrush decorationBrush(option.state & QStyle::State_Selected ? nav->getTextSelectedColor() : nav->getBgSelectedColor());

    font.setPixelSize(11);
    painter->setFont(font);

    //绘制提示信息背景
    QRect decoration = option.rect;
    decoration.setHeight(15);
    decoration.moveCenter(option.rect.center());
    decoration.setLeft(option.rect.right() - 45);
    decoration.setRight(option.rect.right() - 5);

    painter->setPen(decorationPen);
    QPainterPath path;
    path.addRoundedRect(decoration, 7, 7);
    painter->fillPath(path, decorationBrush);

    //如果是数字则将超过999的数字显示成 999+
    if (recordInfo.toInt() > 999) {
        recordInfo = "999+";
    }

    //如果显示的提示信息长度超过4则将多余显示成省略号..
    if (recordInfo.length() > 4) {
        recordInfo = recordInfo.mid(0, 4) + "..";
    }

    painter->drawText(decoration, Qt::AlignCenter, recordInfo);
}


NavModel::NavModel(QObject *parent)	: QAbstractListModel(parent)
{

}

NavModel::~NavModel()
{
    for (QList<TreeNode *>::iterator it = treeNode.begin(); it != treeNode.end();) {
        for (QList<TreeNode *>::iterator child = (*it)->children.begin(); child != (*it)->children.end();) {
            delete(*child);
            child = (*it)->children.erase(child);
        }

        delete(*it);
        it = treeNode.erase(it);
    }
}

void NavModel::readData(const QString &path)
{
    QFile xml(path);

    if (!xml.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QDomDocument doc;

    if (!doc.setContent(&xml, false)) {
        return;
    }

    treeNode.clear();
    listNode.clear();

    QDomNode root = doc.documentElement().firstChildElement("layout");
    QDomNodeList children = root.childNodes();

    for (int i = 0; i != children.count(); ++i) {
        QDomElement nodeInfo = children.at(i).toElement();
        TreeNode *node = new TreeNode;
        node->label = nodeInfo.attribute("label");
        node->collapse = nodeInfo.attribute("collapse").toInt();
        node->info = nodeInfo.attribute("info");
        node->level = 1;

        QDomNodeList secondLevel = nodeInfo.childNodes();

        for (int j = 0; j != secondLevel.count(); ++j) {
            QDomElement secNodeInfo = secondLevel.at(j).toElement();
            TreeNode *secNode = new TreeNode;
            secNode->label = secNodeInfo.attribute("label");
            secNode->info = secNodeInfo.attribute("info");
            secNode->collapse = false;
            secNode->level = 2;
            secNode->theLast = (j == secondLevel.count() - 1 && i != children.count() - 1);
            node->children.push_back(secNode);
        }

        treeNode.push_back(node);
    }

    refreshList();
    beginResetModel();
    endResetModel();
}

void NavModel::setData(const QStringList &listItem)
{
    int count = listItem.count();

    if (count == 0) {
        return;
    }

    treeNode.clear();
    listNode.clear();

    //listItem格式: 标题|父节点标题(父节点为空)|是否展开|提示信息
    for (int i = 0; i < count; i++) {
        QString item = listItem.at(i);
        QStringList list = item.split("|");

        if (list.count() < 4) {
            continue;
        }

        //首先先将父节点即父节点标题为空的元素加载完毕
        QString title = list.at(0);
        QString fatherTitle = list.at(1);
        QString collapse = list.at(2);
        QString info = list.at(3);

        if (fatherTitle.isEmpty()) {
            TreeNode *node = new TreeNode;
            node->label = title;
            node->collapse = collapse.toInt();
            node->info = info;
            node->level = 1;

            //查找该父节点是否有对应子节点,有则加载
            for (int j = 0; j < count; j++) {
                QString secItem = listItem.at(j);
                QStringList secList = secItem.split("|");

                if (secList.count() < 4) {
                    continue;
                }

                QString secTitle = secList.at(0);
                QString secFatherTitle = secList.at(1);
                QString secInfo = secList.at(3);

                if (secFatherTitle == title) {
                    TreeNode *secNode = new TreeNode;
                    secNode->label = secTitle;
                    secNode->info = secInfo;
                    secNode->collapse = false;
                    secNode->level = 2;
                    secNode->theLast = (j == count - 1);
                    node->children.push_back(secNode);
                }
            }

            treeNode.push_back(node);
        }
    }

    refreshList();
    beginResetModel();
    endResetModel();
}

int NavModel::rowCount(const QModelIndex &parent) const
{
    return listNode.size();
}

QVariant NavModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= listNode.size() || index.row() < 0) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        return listNode.at(index.row()).label;
    } else if (role == Qt::UserRole) {
        return (quint64)(listNode.at(index.row()).treeNode);
    }

    return QVariant();
}

void NavModel::refreshList()
{
    listNode.clear();

    for (QList<TreeNode *>::iterator it = treeNode.begin(); it != treeNode.end(); ++it) {
        ListNode node;
        node.label = (*it)->label;
        node.treeNode = *it;

        listNode.push_back(node);

        if ((*it)->collapse) {
            continue;
        }

        for (QList<TreeNode *>::iterator child = (*it)->children.begin(); child != (*it)->children.end(); ++child) {
            ListNode node;
            node.label = (*child)->label;
            node.treeNode = *child;
            node.treeNode->theLast = false;
            listNode.push_back(node);
        }

        if (!listNode.empty()) {
            listNode.back().treeNode->theLast = true;
        }
    }
}

void NavModel::collapse(const QModelIndex &index)
{
    TreeNode *node = listNode.at(index.row()).treeNode;

    if (node->children.size() == 0) {
        return;
    }

    node->collapse = !node->collapse;
    refreshList();

    if (!node->collapse) {
        beginInsertRows(QModelIndex(), index.row() + 1, index.row() + node->children.size());
        endInsertRows();
    } else {
        beginRemoveRows(QModelIndex(), index.row() + 1, index.row() + node->children.size());
        endRemoveRows();
    }
}

NavListView::NavListView(QWidget *parent) : QListView(parent)
{
    infoVisible = true;
    lineVisible = true;
    icoColorBg = false;

    icoStyle = NavListView::IcoStyle_Cross;
    foldMode = FoldMode_SingleClick;    

    lineColor = QColor(214, 216, 224);

    bgNormalColor = QColor(239, 241, 250);
    bgSelectedColor = QColor(133, 153, 216);
    bgHoverColor = QColor(209, 216, 240);

    textNormalColor = QColor(58, 58, 58);
    textSelectedColor = QColor(255, 255, 255);
    textHoverColor = QColor(59, 59, 59);

    this->setMouseTracking(true);
    model = new NavModel(this);
    delegate = new NavDelegate(this);
    connect(this, SIGNAL(clicked(QModelIndex)), model, SLOT(collapse(QModelIndex)));

    setFont(QFont("Microsoft Yahei", 10));
}

NavListView::~NavListView()
{
    delete model;
    delete delegate;
}

bool NavListView::getInfoVisible() const
{
    return this->infoVisible;
}

bool NavListView::getLineVisible() const
{
    return this->lineVisible;
}

bool NavListView::getIcoColorBg() const
{
    return this->icoColorBg;
}

NavListView::IcoStyle NavListView::getIcoStyle() const
{
    return this->icoStyle;
}

NavListView::FoldMode NavListView::getFoldMode() const
{
    return this->foldMode;
}

QColor NavListView::getLineColor() const
{
    return this->lineColor;
}

QColor NavListView::getBgNormalColor() const
{
    return this->bgNormalColor;
}

QColor NavListView::getBgSelectedColor() const
{
    return this->bgSelectedColor;
}

QColor NavListView::getBgHoverColor() const
{
    return this->bgHoverColor;
}

QColor NavListView::getTextNormalColor() const
{
    return this->textNormalColor;
}

QColor NavListView::getTextSelectedColor() const
{
    return this->textSelectedColor;
}

QColor NavListView::getTextHoverColor() const
{
    return this->textHoverColor;
}

QSize NavListView::sizeHint() const
{
    return QSize(200, 300);
}

QSize NavListView::minimumSizeHint() const
{
    return QSize(20, 20);
}

void NavListView::readData(const QString &xmlPath)
{
    model->readData(xmlPath);
    this->setModel(model);
    this->setItemDelegate(delegate);
}

void NavListView::setData(const QStringList &listItem)
{
    model->setData(listItem);
    this->setModel(model);
    this->setItemDelegate(delegate);
}

void NavListView::setInfoVisible(bool infoVisible)
{
    if (this->infoVisible != infoVisible) {
        this->infoVisible = infoVisible;
    }
}

void NavListView::setLineVisible(bool lineVisible)
{
    if (this->lineVisible != lineVisible) {
        this->lineVisible = lineVisible;
    }
}

void NavListView::setIcoColorBg(bool icoColorBg)
{
    if (this->icoColorBg != icoColorBg) {
        this->icoColorBg = icoColorBg;
    }
}

void NavListView::setIcoStyle(const NavListView::IcoStyle &icoStyle)
{
    if (this->icoStyle != icoStyle) {
        this->icoStyle = icoStyle;
    }
}

void NavListView::setFoldMode(const NavListView::FoldMode &foldMode)
{
    if(this->foldMode != foldMode) {
        this->foldMode = foldMode;
        if(this->foldMode == FoldMode_SingleClick) {
            disconnect(this, SIGNAL(doubleClicked(QModelIndex)), model, SLOT(collapse(QModelIndex)));
            connect(this, SIGNAL(clicked(QModelIndex)), model, SLOT(collapse(QModelIndex)));
        } else {
            disconnect(this, SIGNAL(clicked(QModelIndex)), model, SLOT(collapse(QModelIndex)));
            connect(this, SIGNAL(doubleClicked(QModelIndex)), model, SLOT(collapse(QModelIndex)));
        }
    }
}

void NavListView::setLineColor(const QColor &lineColor)
{
    if (this->lineColor != lineColor) {
        this->lineColor = lineColor;
    }
}

void NavListView::setBgNormalColor(const QColor &bgNormalColor)
{
    if (this->bgNormalColor != bgNormalColor) {
        this->bgNormalColor = bgNormalColor;
    }
}

void NavListView::setBgSelectedColor(const QColor &bgSelectedColor)
{
    if (this->bgSelectedColor != bgSelectedColor) {
        this->bgSelectedColor = bgSelectedColor;
    }
}

void NavListView::setBgHoverColor(const QColor &bgHoverColor)
{
    if (this->bgHoverColor != bgHoverColor) {
        this->bgHoverColor = bgHoverColor;
    }
}

void NavListView::setTextNormalColor(const QColor &textNormalColor)
{
    if (this->textNormalColor != textNormalColor) {
        this->textNormalColor = textNormalColor;
    }
}

void NavListView::setTextSelectedColor(const QColor &textSelectedColor)
{
    if (this->textSelectedColor != textSelectedColor) {
        this->textSelectedColor = textSelectedColor;
    }
}

void NavListView::setTextHoverColor(const QColor &textHoverColor)
{
    if (this->textHoverColor != textHoverColor) {
        this->textHoverColor = textHoverColor;
    }
}
