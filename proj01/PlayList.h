/* PlayList.h declares class PlayList.
 *
 * Student 1 Name and UserId: David Yoo (gy24)
 * Date: Sep 4, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector>   // STL vector
#include <string>
using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(const unsigned &year) const;
	vector<Song> searchByTitlePhrase(const string& phrase) const;
	void addSong(const Song &newsong);
	void removeSong(const Song &song);
	void save() const;
	PlayList();
private:
	vector<Song> mySongs;
};

#endif /*PLAYLIST_H_*/
