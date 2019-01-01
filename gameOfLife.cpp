#include<iostream>
#include<stdlib.h>
#define SIZE 25
class env
{
private:
	short arr[SIZE][SIZE];
	short neighbourArr[SIZE][SIZE];
	short neighbour(unsigned int row,unsigned int col) const{
		short count = 0;
		if (arr[row - 1][col]==1)
			count++;
		if (arr[row + 1][col]==1)
			count++;
		if (arr[row][col - 1]==1)
			count++;
		if (arr[row][col + 1]==1)
			count++;
		if (arr[row + 1][col + 1]==1)
			count++;
		if (arr[row + 1][col - 1]==1)
			count++;
		if (arr[row - 1][col + 1]==1)
			count++;
		if (arr[row - 1][col - 1]==1)
			count++;

		return count;
	}
	void kill(int row, int col) {
		arr[row][col] = 0;
	}
	void populate(int row, int col) {
		arr[row][col] = 1;
	}
	bool populated(int row, int col) {
		if (arr[row][col]==1) {
			return true;
		}
		else
			return false;
	}
	void updateEnvNeighbour() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				neighbourArr[i][j] = neighbour(i, j);
			}
		}
	}
public:
	env() {                                 
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				arr[i][j] = 0;
	}
	void getEnv() const {                              
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				std::cout << arr[i][j] << "  ";
			}
			std::cout<<"   " << std::endl;
		}
	}
	
	void updateMainEnv() {
		updateEnvNeighbour();
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (populated(i, j)) {
					if (neighbourArr[i][j] <= 1)
						kill(i, j);
					if (neighbourArr[i][j] >= 4)
						kill(i, j);
					else
						continue;
				}
				else {
					if (neighbourArr[i][j] == 3) {
						populate(i, j);
					}
				}
			}
		}
	}
	void insertEnv(unsigned int x,unsigned int y) {
		arr[x][y] = 1;
	}
	void removeEnv(unsigned int x, unsigned int y) {
		arr[x][y] = 0;
	}
	void reset() {
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				arr[i][j] = 0;
	}

};


int main()
{
	env Connway;
	short ch;
label:
	system("CLS");
	Connway.getEnv();
	std::cout << std::endl;
	std::cout <<" 1.View Current Environment "<< std::endl;
	std::cout <<" 2.Insert Cells! "<< std::endl;
	std::cout <<" 3.Simulate Next Step! "<< std::endl;
	std::cout <<" 4.Reset "<< std::endl;
	std::cout <<" 5.Exit "<< std::endl;
	std::cout << " 6.Remove a Cell manually! " << std::endl;
	std::cout << "SIZE:" << SIZE << "x" << SIZE << std::endl;
	std::cin >> ch;

	if (ch == 1) {
		Connway.getEnv();
		goto label;
	}
	if (ch == 2) {
		unsigned int xCoord, yCoord;
		std::cout << "Enter the X and Y Coord to Insert Life(start=0,0)";
		std::cin >> xCoord >> yCoord;
		Connway.insertEnv(xCoord,yCoord);
		goto label;
	}
	if (ch == 3) {
		Connway.updateMainEnv();
		goto label;
	}
	if (ch == 4) {

		Connway.reset();
		goto label;

	}
	if (ch == 5) {
		exit(0);
	}
	if (ch == 6) {
		unsigned int xCoordr, yCoordr;
		std::cout << "Enter the X and Y Coord to Remove Life(start=0,0)";
		std::cin >> xCoordr >> yCoordr;
		Connway.removeEnv(xCoordr, yCoordr);
		goto label;
		
	}
	
}
