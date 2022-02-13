/* PlayListTester.cpp defines the PlayList test-methods.
 *
 * Student 1 Name and UserId: David Yoo (gy24)
 * Date: Sep 4, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "PlayListTester.h"
#include "PlayList.h"
#include <iostream>
#include <cassert>
using namespace std;

/*
 * Run all the tests that we built.
 */
void PlayListTester::runTests() {
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	testSearchByYear();
	testSearchByTitlePhrase();
	testAddRemoveSong();
	testSaveSong();
	cout << "All tests passed!" << endl;
}

void PlayListTester::testConstructors() {
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );
	cout << " 0 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByArtist() {
	cout << "- searchByArtist()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// case if there is no songs for this artist in the playlist.
	vector<Song> searchResult = pList.searchByArtist("Cream");
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// case if there is one song from an artist in the playlist
	searchResult = pList.searchByArtist("Baez");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	cout << " 1 " << flush;

	// case of multiple songs from an artist in the playlist
	searchResult = pList.searchByArtist("Beatles");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Penny Lane" );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByYear() {
	cout << "- searchByYear()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// case if there is no songs are released in the year in the playlist.
	vector<Song> searchResult = pList.searchByYear(2015);
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// case if there is one song this is released in the year in the playlist.
	searchResult = pList.searchByYear(2012);
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Call Me Maybe" );
	cout << " 1 " << flush;

	// case if there are multiple songs that are released in the year in the playlist.
	searchResult = pList.searchByYear(1967);
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Penny Lane" );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByTitlePhrase() {
	cout << "- searchByTitlePhrase()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// case for phrase that is not in the title
	vector<Song> searchResult;
	searchResult = pList.searchByTitlePhrase("Badge");
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// case if there is a song that has phrase in the title.
	searchResult = pList.searchByTitlePhrase("Call");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Call Me Maybe" );
	cout << " 1 " << flush;

	// case if there are more than one song that have same phrase in the titles.
	searchResult = pList.searchByTitlePhrase("Let");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Let It Be" );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}


void PlayListTester::testAddRemoveSong() {
	cout << "- addRemoveSong()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// declare a song
	Song s1("Wish", "Jukjae", 2020);

	pList.addSong(s1);
	// case for phrase that is not in the title
	vector<Song> searchResult = pList.searchByArtist("Jukjae");
	assert( searchResult.size() == 1 );
	cout << " 0 " << flush;

	pList.removeSong(s1);
	searchResult = pList.searchByArtist("Jukjae");
	assert( searchResult.size() == 0 );
	cout << " 1 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testSaveSong() {
	cout << "- saveSong()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// declare a song
	Song s1("Wish", "Jukjae", 2020);

	pList.addSong(s1);
	// Check if it added the song and saved in our file.
	assert( pList.getNumSongs() == 5 );
	cout << " 0 " << flush;

	pList.removeSong(s1);
	// Check if it removed the song and saved in our file.
	assert( pList.getNumSongs() == 4 );
	cout << " 1 " << flush;

	cout << " Passed!" << endl;
}

