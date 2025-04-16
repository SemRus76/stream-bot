#include "media_player.h"
#include "ui_media_player.h"

MediaPlayer::MediaPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayer)
{
    ui->setupUi(this);
    _mediaPlaylist = new QMediaPlaylist;
    _player = new QMediaPlayer;
//    _player->setMedia(QUrl::fromLocalFile(u8"/home/semrus/Music/Arcane_MaMeilleure.mp3"));
    _player->setPlaylist(_mediaPlaylist);

    connect(_player, &QMediaPlayer::positionChanged,
            this, &MediaPlayer::trackPositionChanged);
    connect(_player, &QMediaPlayer::durationChanged,
            this, &MediaPlayer::trackDurationChanged);
}

MediaPlayer::~MediaPlayer()
{
    delete ui;
}

void MediaPlayer::keyReleaseEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key::Key_Escape && ui->playlist->currentRow() > 0)
    {
        ui->playlist->setCurrentRow(-1);
        return;
    }
    QWidget::keyReleaseEvent(event);
}

void MediaPlayer::trackDurationChanged(quint64 duration)
{
    ui->trackPosition->setMaximum(duration / 1000/*сек*/);
    ui->trackPosition->setMinimum(0);
    ui->trackPosition->setValue(0);
}

void MediaPlayer::trackPositionChanged(quint64 position)
{
    ui->trackPosition->setValue(position / 1000 /*сек*/);
    ui->trackPosition->setSliderPosition(position / 1000 /*сек*/);
}

void MediaPlayer::on_btnPlay_clicked()
{
    ui->btnPause->setEnabled(true);
    ui->btnStop->setEnabled(true);
    ui->btnPlay->setEnabled(false);
    _player->play();
}


void MediaPlayer::on_btnStop_clicked()
{
    ui->btnPause->setEnabled(false);
    ui->btnStop->setEnabled(false);
    ui->btnPlay->setEnabled(true);
    _player->stop();
}


void MediaPlayer::on_btnPause_clicked()
{
    ui->btnPause->setEnabled(false);
    ui->btnStop->setEnabled(false);
    ui->btnPlay->setEnabled(true);
    _player->pause();
}


void MediaPlayer::on_btnAddTrack_clicked()
{
    QString track = QFileDialog::getOpenFileName(this,
                                                 u8"Выберете файл трека",
                                                 "/home",
                                                 "Music(*.mp3 *.wav);;Video(*.mp4);;All Files(*)");

    QString nameTrack = track.mid(track.lastIndexOf("/") + 1,
                                  track.lastIndexOf(".") - track.lastIndexOf("/") - 1);

    _playlist.append(nameTrack);
//    QUrl trackURL = QUrl::fromLocalFile(track);
//    _player->playlist()->addMedia(trackURL);
    _mediaPlaylist->addMedia(QUrl::fromLocalFile(track));

    refreshPlaylistView();
}

void MediaPlayer::on_btnRemoveTrack_clicked()
{
    if (ui->playlist->currentRow() < 0)
        return;

    int row = ui->playlist->currentRow();

    int indexPlaying = _player->playlist()->currentIndex();
    if (indexPlaying == row)
        _player->stop();
    _player->playlist()->removeMedia(row);
    _playlist.removeAt(row);
    refreshPlaylistView();
}


void MediaPlayer::refreshPlaylistView()
{
    ui->playlist->clear();
    if (_playlist.empty())
        return;
    // TODO: Сделать дешевле
    // TODO: Сделать статусы
    for (int i = 0; i < _playlist.size(); ++i)
    {
        ui->playlist->addItem(_playlist[i]);
    }
    // TODO: Подумать над перезапуском проигрывания
}

void MediaPlayer::on_playlist_currentRowChanged(int currentRow)
{
    if (currentRow < 0)
    {
        ui->btnRemoveTrack->setEnabled(false);
        return;
    }
    ui->btnRemoveTrack->setEnabled(true);

}

