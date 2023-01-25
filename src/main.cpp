#include "24game.hpp"
#include <sstream>
#include <cstdlib>

int main() {

    // Inisiasi variabel
    int n;
    std::string card = "";
    std::vector<double> input;
    std::cout << "Welcome to 24 Game Solver." << std::endl;
    std::cout << "Choose input:" << std::endl;
    std::cout << "1. User input" << std::endl;
    std::cout << "2. Random" << std::endl;
    while (true) {
        std::cin >> n;
        if (n == 1) {   // Input dari pengguna
            std::cin.clear();
            fflush(stdin);
            std::cout << "Type in the input with the format below.\nX X X X" << std::endl;
            while (true) {
                
                std::getline(std::cin, card);
                std::stringstream ss(card);
                std::string str_num;
                
                bool valid = true;
                while (ss >> str_num) {
                    if (str_num == "A") {
                        input.push_back(1);
                    } else if (str_num == "J") {
                        input.push_back(11);
                    } else if (str_num == "Q") {
                        input.push_back(12);
                    } else if (str_num == "K") {
                        input.push_back(13);
                    } else if (str_num == "2" || str_num == "3" || str_num == "4" || 
                               str_num == "5" || str_num == "6" || str_num == "7" || 
                               str_num == "8" || str_num == "9" || str_num == "10") {
                        input.push_back(stoi(str_num));
                    } else {
                        std::cout << "Input not valid, please try again." << std::endl;
                        valid = false;
                        ss.clear();
                        input.clear();
                        break;
                    }
                }

                if (!valid) {
                    continue;
                }

                if (input.size() != 4) {
                    std::cout << "Input not valid, please try again." << std::endl;
                    ss.clear();
                    input.clear();
                    continue;
                }

                break;
            }
            break;

        } else if (n == 2) { // Input random
            
            srand(time(0));
            for (int i = 0; i < 4; i++) {
                input.push_back((rand() % 13) + 1);
                if (input[i] == 1) {
                    card += "A ";
                } else if (input[i] == 11) {
                    card += "J ";
                } else if (input[i] == 12) {
                    card += "Q ";
                } else if (input[i] == 13) {
                    card += "K ";
                } else {
                    card += std::to_string((int)input[i]) + " ";
                }
            }
            card += "\n";
            std::cout << card;
            break;

        } else {
            std::cout << "Input not valid, please try again." << std::endl;
        }

    }
    
    // Waktu awal
    auto time1 = std::chrono::high_resolution_clock::now();
    
	selectionSort(input);
    int count = 0;
	std::string solution = "";

    // Pencarian solusi
    do {
		computeSolution(input, count, solution);
    } while (nextPermutation(input));

    // Waktu akhir
    auto time2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1);

    // Pencetakan solusi, jumlah solusi, dan waktu ke layar
    if (count == 0) {
        std::cout << "No solution found." << std::endl;
    } else {
        std::cout << count << " solution(s) found." << std::endl;
    }
	std::cout << solution;
    std::cout << "Time (microseconds): " << duration.count() << std::endl;

    // Penyimpanan solusi dalam file
    char save;
    std::cout << "Store the solution in a .txt file?(y/n) ";
    while (true) {
        std::cin >> save;
		if (save == 'y') {
			
            std::string name;
			std::cout << "Input solution file name: ";
			std::cin >> name;
			std::ofstream FileSolution("test/" + name + ".txt");

            FileSolution << card;
            if (count == 0) {
                FileSolution << "No solution found." << std::endl;
            } else {
                FileSolution << count << " solution(s) found." << std::endl;
            }
			FileSolution << "Time (microseconds): " << duration.count() << std::endl;
			FileSolution << solution;
			std::cout << "Success." << std::endl;
			break;
		} else if (save != 'y' && save != 'n') {
			
            std::cout << "Input not valid, please try again." << std::endl;
			continue;
		}
		break;
	}

    std::cout << "Program Finished." << std::endl;
}