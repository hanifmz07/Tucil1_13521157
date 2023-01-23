#include "24game.hpp"
#include <sstream>

int main() {

    std::vector<double> input;
    std::string card;
    std::cout << "Welcome to 24 Game Solver. Type in the input with the format below.\nX X X X" << std::endl;
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
            } else if (str_num == "2" || str_num == "3" || str_num == "4" || str_num == "5" || str_num == "6" || str_num == "7" || str_num == "8" || str_num == "9" || str_num == "10") {
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
    
    auto time1 = std::chrono::high_resolution_clock::now();
    
	selectionSort(input);
    int count = 0;
	std::string solution = "";

    do {
		computeSolution(input, count, solution);
    } while (nextPermutation(input));

    auto time2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1);

    std::cout << count << " solution(s) found." << std::endl;
	std::cout << solution;
    std::cout << "Time (ms): " << duration.count() << std::endl;

    char save;
    std::cout << "Store the solution in a .txt file?(y/n) ";
    std::cin >> save;
    while (true) {
		if (save == 'y') {
			std::string name;
			std::cout << "Input solution file name: ";
			std::cin >> name;
			std::ofstream FileSolution("test/" + name + ".txt");

            FileSolution << card << std::endl;
			FileSolution << count << " solution(s) found." << std::endl;
			FileSolution << "Time (ms): " << duration.count() << std::endl;
			FileSolution << solution;
			std::cout << "Success." << std::endl;
			break;
		} else if (save != 'y' && save != 'n') {
			std::cout << "Input not valid." << std::endl;
			continue;
		}
		break;
	}

    std::cout << "Program Finished." << std::endl;
}