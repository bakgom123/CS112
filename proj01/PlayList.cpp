/* PlayList.cpp defines the PlayList methods.
 *
 * Student 1 Name and UserId: David Yoo (gy24)
 * Date: Sep 4, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "PlayList.h"
#include <fstream>      // ifstream
#include <cassert>      // assert()
using namespace std;

/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */
PlayList::PlayList() {}
PlayList::PlayList(const string& fileName) {
	// open a stream to the playlist file
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	// read each song and append it to mySongs
	Song s;
	string separator;
	while (true) {
		s.readFrom(fin);
		if ( !fin ) { break; }
		getline(fin, separator);
		mySongs.push_back(s);
	}

	// close the stream
	fin.close();

}

/* Retrieve length of the playlist
 * Return: the number of songs in the playlist.
 */
unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}

/* Search by artist
 * @param: artist, a string.
 * Return: a vector containing all the Songs in mySongs by artist.
 */
vector<Song> PlayList::searchByArtist(const string& artist) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); ++i) {
		if ( mySongs[i].getArtist().find(artist) != string::npos ) {
			v.push_back( mySongs[i] );
		}
	}

	return v;
}


/* Search by year
 * @param: year, unsigned.
 * Return: a vector containing all the Songs in mySongs by year.
 */
vector<Song> PlayList::searchByYear(const unsigned &year) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); ++i) {
		if ( mySongs[i].getYear() == year ) {
			v.push_back( mySongs[i] );
		}
	}

	return v;
}


/* Search by title phrase
 * @param: phrase, string.
 * Return: a vector containing all the Songs in the playlist that have phrase anywhere in their title.
 */
vector<Song> PlayList::searchByTitlePhrase(const string &phrase) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); ++i) {
			if ( mySongs[i].getTitle().find(phrase) != string::npos ) {
				v.push_back( mySongs[i] );
			}
		}
	return v;
}


/* Add new songs to the playlist
 * @param: newSong, a Song
 * Return: None
 */
void PlayList::addSong(const Song& newSong){
	mySongs.push_back(newSong);
}


/* Remove the first instance of a given song from the playlist. If the
 * song isn't in the play list, the play list is unchanged.
 * @param: song, a Song
 * Return: None
 */
void PlayList::removeSong(const Song &song) {
	for (unsigned i = 0; i < mySongs.size(); i++) {
		if (mySongs[i]==song) {
			mySongs.erase(mySongs.begin() + i);
			break;
		}
	}
}

/* Save songs to the text file.
 * param: None
 * Return: None
 */

void PlayList::save() const{
	// write the playlist back to the file that was used to construct the collection.
	ofstream fout("testSongs.txt");
	assert( fout.is_open() );

	for (unsigned i = 0; i < mySongs.size(); i++) {
		mySongs[i].writeTo( fout );
		fout << "---" << endl;
	}

	// close the stream
	fout.close();
}





