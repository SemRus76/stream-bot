#pragma once

#include <QPointer>

#include <QWidget>
#include <QList>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>

namespace Ui {
class MediaPlayer;
}

class MediaPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

protected:
    virtual void keyReleaseEvent(QKeyEvent* event) override;

private slots:
    void trackDurationChanged(quint64);
    void trackPositionChanged(quint64);

    void on_btnPlay_clicked();
    void on_btnStop_clicked();
    void on_btnPause_clicked();
    void on_btnAddTrack_clicked();
    void on_btnRemoveTrack_clicked();
    void on_playlist_currentRowChanged(int currentRow);
    void on_btnNextTrack_clicked();
    void on_btnPrevTrack_clicked();
    void on_btnRepeatMode_clicked();
    void on_btnShuffleMode_clicked();

private:
    void refreshPlaylistView();

private:
    Ui::MediaPlayer *ui;
    QPointer<QMediaPlayer> _player;
    QMediaPlaylist* _mediaPlaylist = nullptr;
    QList<QString> _playlist;

    int _repeatStatus = {0};
    bool _shuffleStatus = {false};
};

