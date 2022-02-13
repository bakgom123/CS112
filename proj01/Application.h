/* Application.h declares the application class for our PlayList class.
 *
 * Student 1 Name and UserId: David Yoo (gy24)
 * Date: Sep 12, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "PlayList.h"
#include <vector>

class Application {
public:
	Application();
	void run();

private:
	void displayMenu() const;
	char getChoice() const;
	void processChoice(char choice);
	Song getSong();
	void displaySongs(vector<Song> songs) const;

	PlayList myPlayList;
};

#endif /* APPLICATION_H_ */

