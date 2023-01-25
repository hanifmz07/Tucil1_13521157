#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int main() {
    vector<char> op = {'+','+','+'};
    // 0+, 1-, 2*, 3/
    ofstream MyFile("script.txt");
    for (int a = 0; a < 11; a++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (i == 0) {
                        op[0] = '+';
                    }
                    if (i == 1) {
                        op[0] = '-';
                    }
                    if (i == 2) {
                        op[0] = '*';
                    }
                    if (i == 3) {
                        op[0] = '/';
                    }
                    if (j == 0) {
                        op[1] = '+';
                    }
                    if (j == 1) {
                        op[1] = '-';
                    }
                    if (j == 2) {
                        op[1] = '*';
                    }
                    if (j == 3) {
                        op[1] = '/';
                    }
                    if (k == 0) {
                        op[2] = '+';
                    }
                    if (k == 1) {
                        op[2] = '-';
                    }
                    if (k == 2) {
                        op[2] = '*';
                    }
                    if (k == 3) {
                        op[2] = '/';
                    }

                    switch (a) {
                        case 0:
                            // A B C D
                            MyFile << "\t\tif (input[0] " << op[0] << " input[1] " << op[1] << " input[2] " << op[2] << " input[3] == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += std::to_string((int) input[0]) + \" " <<
                            op[0] << " \" + std::to_string((int) input[1]) + \" " << op[1] <<
                            " \" + std::to_string((int) input[2]) + \" " << op[2] << " \" + std::to_string((int) input[3]) + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 1:
                            // (A B) C D
                            MyFile << "\t\tif ((input[0] " << op[0] << " input[1]) " << op[1] << " input[2] " << op[2] << " input[3] == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += \"(\" + std::to_string((int) input[0]) + \" " <<
                            op[0] << " \" + std::to_string((int) input[1]) + \")\" + \" " << op[1] <<
                            " \" + std::to_string((int) input[2]) + \" " << op[2] << " \" + std::to_string((int) input[3]) + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 2:
                            // A (B C) D
                            MyFile << "\t\tif (input[0] " << op[0] << " (input[1] " << op[1] << " input[2]) " << op[2] << " input[3] == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + \"(\" + std::to_string((int) input[1]) + \" " << op[1] <<
                            " \" + std::to_string((int) input[2]) + \")\" + \" " << op[2] << " \" + std::to_string((int) input[3]) + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 3:
                            // A B (C D)
                            MyFile << "\t\tif (input[0] " << op[0] << " input[1] " << op[1] << " (input[2] " << op[2] << " input[3]) == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + std::to_string((int) input[1]) + \" " << op[1] << " \" + \"(\" + std::to_string((int) input[2]) + \" " <<
                            op[2] << " \" + std::to_string((int) input[3]) + \")\" + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 4:
                            // (A B C) D
                            MyFile << "\t\tif ((input[0] " << op[0] << " input[1] " << op[1] << " input[2]) " << op[2] << " input[3] == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += \"(\" + std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + std::to_string((int) input[1]) + \" " << op[1] <<
                            " \" + std::to_string((int) input[2]) + \")\" + \" " << op[2] <<
                            " \" + std::to_string((int) input[3]) + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 5:
                            // A (B C D)
                            MyFile << "\t\tif (input[0] " << op[0] << " (input[1] " << op[1] << " input[2] " << op[2] << " input[3]) == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + \"(\" + std::to_string((int) input[1]) + \" " << op[1] <<
                            " \" + std::to_string((int) input[2]) + \" " << op[2] << " \" + std::to_string((int) input[3]) + \")\" + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 6:
                            // ((A B) C) D
                            MyFile << "\t\tif (((input[0] " << op[0] << " input[1]) " << op[1] << " input[2]) " << op[2] << " input[3] == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += \"((\" + std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + std::to_string((int) input[1]) + \")\"+ \" " << op[1] <<
                            " \" + std::to_string((int) input[2]) + \")\" + \" " << op[2] << " \" + std::to_string((int) input[3]) + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 7:
                            // (A (B C)) D
                            MyFile << "\t\tif ((input[0] " << op[0] << " (input[1] " << op[1] << " input[2])) " << op[2] << " input[3] == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += \"(\" + std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + \"(\" + std::to_string((int) input[1]) + \" " << op[1] <<
                            " \" + std::to_string((int) input[2]) + \"))\" + \" " << op[2] << " \" + std::to_string((int) input[3]) + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 8:
                            // A ((B C) D)
                            MyFile << "\t\tif (input[0] " << op[0] << " ((input[1] " << op[1] << " input[2]) " << op[2] << " input[3]) == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + \"((\" + std::to_string((int) input[1]) + \" " << op[1] <<
                            " \" + std::to_string((int) input[2]) + \")\" + \" " << op[2] << " \" + std::to_string((int) input[3]) + \")\" + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 9:
                            // A (B (C D))
                            MyFile << "\t\tif (input[0] " << op[0] << " (input[1] " << op[1] << " (input[2] " << op[2] << " input[3])) == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + \"(\" + std::to_string((int) input[1]) + \" " << op[1] <<
                            " \" + \"(\" + std::to_string((int) input[2]) + \" " << op[2] << " \" + std::to_string((int) input[3]) + \"))\" + \"\\n\";\n\t\t}" << endl;
                            break;
                        case 10:
                            // (A B) (C D)
                            MyFile << "\t\tif ((input[0] " << op[0] << " input[1]) " << op[1] << " (input[2] " << op[2] << " input[3]) == 24) {" << endl;
                            MyFile << "\t\t\tcount++;" << endl;
                            MyFile << "\t\t\tsolution += \"(\" + std::to_string((int) input[0]) + \" " << op[0] <<
                            " \" + std::to_string((int) input[1]) + \")\" + \" " << op[1] <<
                            " \" + \"(\" + std::to_string((int) input[2]) + \" " << op[2] << " \" + std::to_string((int) input[3]) + \")\" + \"\\n\";\n\t\t}" << endl;
                            break;
                    }
                }
            }
        }
    }
}