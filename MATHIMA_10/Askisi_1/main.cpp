#include <iostream>
#include <string>
using namespace std;

class Video{
public:
//    Video(string in_artist_name, string in_song_name, double in_xronikh_diarkeia_tragoudiou);
//    Video();
    friend ostream &operator<< (ostream &left, const Video &right);
    double getXronikhDiarkeiaTragoudiou() const;
    string getArtistName() const;
    string getSongName() const;
    void set_Video(string in_artist_name, string in_song_name, int in_getXronikhDiarkeiaTragoudiou);
private:
    string artist_name;
    string song_name;
    double xronikh_diarkeia_tragoudiou;
public:
};


class PlayList{
private:
    string playlist_name;
    string playlist_description;
    double xronikh_diarkeia_playlist;
    Video Videos[100];
    int Videos_Size;
public:
    PlayList(string in_playlist_name, string in_playlist_description);
    void add_video(Video in_video);
    friend ostream &operator<< (ostream &left, const PlayList &right);
};



double Video::getXronikhDiarkeiaTragoudiou() const {
    return xronikh_diarkeia_tragoudiou;
}

string Video::getArtistName() const {
    return artist_name;
}

string Video::getSongName() const {
    return song_name;
}

void Video::set_Video(std::string in_artist_name, std::string in_song_name, int in_getXronikhDiarkeiaTragoudiou) {
    artist_name=in_artist_name;
    song_name=in_song_name;
    xronikh_diarkeia_tragoudiou=in_getXronikhDiarkeiaTragoudiou;
}

ostream &operator<< (ostream &left, const Video &right){
    left<<"( "<<right.getArtistName()<<", "<<right.getSongName()<<", "<<right.getXronikhDiarkeiaTragoudiou()<<" )";
    return left;
}


PlayList::PlayList(string in_playlist_name, string in_playlist_description) {
    playlist_name=in_playlist_name;
    playlist_description=in_playlist_description;
    xronikh_diarkeia_playlist=0;
    Videos_Size=0;
}

void PlayList::add_video(Video in_video) {

    Videos[Videos_Size]=in_video;
    Videos_Size++;
    xronikh_diarkeia_playlist+=in_video.getXronikhDiarkeiaTragoudiou();
}

ostream &operator<< (ostream &left, const PlayList &right){
    left<<"["<<right.playlist_name<<", "<<right.playlist_description<<", "<<right.xronikh_diarkeia_playlist<<" : "<<endl;
    for(int i=0; i<right.Videos_Size; i++){
        left<<endl<<right.Videos[i];
    }
    left<<endl<<endl<<"]";
    return left;
}

int main() {

    PlayList playlist("My PlayList", "The Best Songs");

    Video video;

    video.set_Video("Sin Boy","Cherry",207); //207 = defterolepta
    playlist.add_video(video);

    video.set_Video("Snik","Medusa",190); //190 = defterolepta
    playlist.add_video(video);

    video.set_Video("Light","Primo",220); //220 = defterolepta
    playlist.add_video(video);


    cout<<playlist;


    return 0;
}
