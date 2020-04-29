#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

bool line_data_started = false;
bool bus_data_started = false;

std::string extract_from_string(std::string str, int m, int n){	// m: start column number, n: end column number
	std::string ans = "";
	for(int i = m-1; i < n; i++){
		ans = ans + str[i];
	}
	return(ans);
}

void get_data_from_file(){
	std::ifstream input_file;
	std::ofstream output_file_1, output_file_2;

	input_file.open("data_files/ieee118psp.txt");
	output_file_1.open("data_files/ieee118_line_data.csv");
	output_file_2.open("data_files/ieee118_bus_data.csv");

	output_file_1 << "Start bus,Change code,Tranformers,End bus,Circuit number,Loss (T/F),Line Resistance,Line Reactance,Line Charging (MVAr),Transformer Tap,Min tap,Max tap,Phase shift angle,Remote voltage control bus number,Normal MVA rating,Emergency MVA rating,MVA base\n";
	output_file_2 << "Bus,Change code,Continue code,Regulated code,Name,Bus voltage,Bus angle,Generation MW,Generation MVAr (from solution),Generation MVAr (low limit),Generation MVAr (high limit),Bus at which generation controls voltage,Load MW,Load MVAR,Shunt MVAR,Load flow area\n";

	if(input_file.is_open() && output_file_1.is_open()){
		std::string line;
		while(getline(input_file, line)){
			std::istringstream iss(line);
			std::string str = iss.str();
			
			if(!bus_data_started && !line_data_started && std::atoi(str.c_str()) == 4){
				line_data_started = true;
			}
			else if(line_data_started && std::atoi(str.c_str()) == 9999){
				bus_data_started = true;
				line_data_started = false;
				getline(input_file, line);
			}
			else if(bus_data_started && std::atoi(str.c_str()) == 9999){
				bus_data_started = false;
			}
			else if(line_data_started){
				output_file_1 << extract_from_string(str, 1, 4) << ",";
				output_file_1 << extract_from_string(str, 6, 6) << ",";
				output_file_1 << extract_from_string(str, 7, 7) << ",";
				output_file_1 << extract_from_string(str, 9, 12) << ",";
				output_file_1 << extract_from_string(str, 14, 14) << ",";
				output_file_1 << extract_from_string(str, 16, 16) << ",";
				output_file_1 << extract_from_string(str, 18, 23) << ",";
				output_file_1 << extract_from_string(str, 24, 29) << ",";
				output_file_1 << extract_from_string(str, 30, 35) << ",";
				output_file_1 << extract_from_string(str, 36, 40) << ",";
				output_file_1 << extract_from_string(str, 41, 45) << ",";
				output_file_1 << extract_from_string(str, 46, 50) << ",";
				output_file_1 << extract_from_string(str, 51, 55) << ",";
				output_file_1 << extract_from_string(str, 56, 60) << ",";
				output_file_1 << extract_from_string(str, 61, 64) << ",";
				output_file_1 << extract_from_string(str, 65, 68) << ",";
				output_file_1 << extract_from_string(str, 69, 72) << ",";

				output_file_1 << "\n";
			}
			else if(bus_data_started){
				output_file_2 << extract_from_string(str, 1, 4) << ",";
				output_file_2 << extract_from_string(str, 6, 6) << ",";
				output_file_2 << extract_from_string(str, 7, 7) << ",";
				output_file_2 << extract_from_string(str, 8, 8) << ",";
				output_file_2 << extract_from_string(str, 10, 21) << ",";
				output_file_2 << extract_from_string(str, 23, 26) << ",";
				output_file_2 << extract_from_string(str, 27, 30) << ",";
				output_file_2 << extract_from_string(str, 31, 35) << ",";
				output_file_2 << extract_from_string(str, 36, 40) << ",";
				output_file_2 << extract_from_string(str, 41, 45) << ",";
				output_file_2 << extract_from_string(str, 46, 50) << ",";
				output_file_2 << extract_from_string(str, 51, 55) << ",";
				output_file_2 << extract_from_string(str, 56, 60) << ",";
				output_file_2 << extract_from_string(str, 61, 65) << ",";
				output_file_2 << extract_from_string(str, 66, 70) << ",";
				output_file_2 << extract_from_string(str, 71, 72) << ",";

				output_file_2 << "\n";
			}
		}
		input_file.close();
		output_file_1.close();
	}
	else{
		std::cout << "File not found" << std::endl;
	}
}

int main(int argc, char const *argv[]){
	get_data_from_file();
}