#ifndef COLORQUEUEMODEL_H
#define COLORQUEUEMODEL_H

#include <QAbstractListModel>

#include <QPixmap>

struct Swatch {
    QString description;
    QColor color;

    Swatch(QString description, QColor color) : description(description), color(color)
    {}
};

class ColorQueueModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ColorQueueModel(QObject *parent, const QColor& backgroundColor = QColor());
    ~ColorQueueModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addColor(const Swatch& swatch);

    QList<Swatch> swatches() { return mSwatches; }

private:

    QList<Swatch> mSwatches;
    QColor mBaseBackgroundColor;

    constexpr static int MAXSWATCHES = 5;
};

#endif // COLORQUEUEMODEL_H