/*
 * Application.cpp
 * This is an application lets people search the playlist by song title, artist, and/or year,
 * add a song to the playlist, remove a song from the playlist, and save the playlist.
 *
 *  Created on: Feb 14, 2020
 *      Author: vtn2
 *
 *  Student 1 Name and UserId: David Yoo (gy24)
 *  Date: Sep 12, 2021
 */

#include "Application.h"
#include "Song.h"
#include "PlayList.h"
#include <iostream>
using namespace std;


Application::Application() {
	string fname;
	cout << "Welcome to the PlayList Manager" << endl << endl;
	cout << "Please enter a file containing a play list: " << flush;
	getline(cin, fname);
	myPlayList = PlayList(fname);
}

/*
 * Run the application.
 */
void Application::run() {
	while (true) {
		displayMenu();
		char choice = getChoice();
		// cout << "got choice " << choice << endl;
		if (choice == 'q') {
			break;
		}
		processChoice(choice);
	}
}

void Application::displayMenu() const {
	cout << "Please enter:" << endl;
	cout << "a - to add a new song to the playlist" << endl;
	cout << "r - to remove a song from the playlist" << endl;
	cout << "s - to save the playlist" << endl;
	cout << "A - to search the playlist for songs by a given artist" << endl;
	cout << "Y - to search the playlist for songs in a given year" << endl;
	cout << "P - to search the playlist for songs with a given phrase in the title" << endl;
	cout << "q - to quit" << endl;
}

char Application::getChoice() const {
	cout << endl << "Please enter your choice: " << flush;
	char choice;
	cin >> choice;
	cin.get();
	return choice;
}

Song Application::getSong() {
	string artist;
	string title;
	unsigned year;
	string yearStr;

	cout << "  Enter artist: ";
	getline(cin, artist);
	cout << "  Enter title: ";
	getline(cin, title);
	cout << "  Enter year: ";
	cin >> year;
	cin.get();
	return Song(title, artist, year);
}

void Application::processChoice(char choice) {
	switch(choice) {
	case 'a': {
		cout << "Add an song to the playlist..." << endl;
		// TODO
		// Call addSong function to add the new song that the user wants to add to the playlist.
		Song newSong = getSong();
		myPlayList.addSong(newSong);
		break;
	}
	case 's': {
		myPlayList.save();
		break;
	}
	case 'r': {
		cout << "Remove a song from the playlist..." << endl;
		// TODO
		// Call removeSong function to remove the song that the user wants to remove to the playlist.
		Song theSong = getSong();
		myPlayList.removeSong(theSong);
		break;
	}
	case 'Y': {
		cout << "Searching playlist by year..." << endl;
		unsigned year;
		cout << "Enter year: ";
		cin >> year;
		cin.get();
		// TODO
		// Call searchByYear function to let the user search the song by year.
		vector <Song> songs = myPlayList.searchByYear(year);
		displaySongs(songs);
		break;
	}
	case 'P': {
		cout << "Searching playlist by title phrase..." << endl;
		string phrase;
		cout << "Enter phrase: ";
		cin >> phrase;
		// TODO
		// Call searchByTitlePhrase function to let the user search the song by the phrase.
		vector <Song> songs = myPlayList.searchByTitlePhrase(phrase);
		displaySongs(songs);
		break;
	}
	case 'A': {
		cout << "Searching playlist by artist..." << endl;
		string artist;
		cout << "Enter artist: ";
		cin >> artist;
		// TODO
		// Call searchByArtist function to let the user search the song by the artist.
		vector <Song> songs = myPlayList.searchByArtist(artist);
		displaySongs(songs);
		break;
	}
	}
}

void Application::displaySongs(vector<Song> songs) const {
	// TODO: call writeTo on each song, passing in cout.
	// Call writeTo function to display songs.
	for (unsigned i = 0; i < songs.size(); ++i) {
		songs[i].writeTo(cout);
	}

}

